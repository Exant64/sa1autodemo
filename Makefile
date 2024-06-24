STG02_KEY := 0C900000
STG02_ROM := build/STG02.bin
STG02_ELF := $(STG02_ROM:.bin=.elf)

COMPARE ?= 1

SRC_DIRS := $(shell find src -type d)
ASM_DIRS := $(shell find asm -type d -not -path '*/nonmatching/*')

C_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES       := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.src))

#i use obj to "differentiate" between regular elf object files and the SYSROF thing that hitachi uses
O_FILES       := $(foreach f,$(S_FILES:.src=.obj),build/$f) \
                 $(foreach f,$(C_FILES:.c=.obj),build/$f) 

# path conversion for msys2 (msys2 doesnt seem to automatically convert foo/bar paths because windows apps are
# apparently supposed to support that, except SHC doesn't lol) (pls correct me if im wrong)
PATHHELP := tools/path_helper.sh

#using inline_asm automatically creates a .align 4, rts, and nop at the end of the function regardless of its contents
#we have to remove those to be able to include asm
#i guess this is sort of our equivalent of asm-processor
FIX_INLINE := tools/fix_inline_asm.py
FIX_INLINE_C := tools/inline_asm_c.py

DCSPLIT := tools/dcsplit/dcsplit.py
GENFSY := tools/genfsy.py

SHC_DIR := shc

MAKE = make
CC := $(SHC_DIR)/bin/shc.exe
AS := $(SHC_DIR)/bin/asmsh.exe
LD := $(SHC_DIR)/bin/lnk.exe
ELF2BIN := tools/elf2bin 
WINPATH := tools/winpath.sh

export SHC_LIB := $(abspath $(SHC_DIR)/bin)
export SHC_TMP := $(abspath $(SHC_DIR)/temp)

export WSLENV=SHC_LIB/p:SHC_TMP/p	

#the source dir (original layout was like that too) and katana includes
INCLUDEDIRS := src,Include,$(SHC_DIR)\\include

CFLAGS := -sub=shc.sub -include=$(INCLUDEDIRS)

ASFLAGS := -cpu=sh4 -sjis

LDFLAGS :=

$(shell mkdir -p build $(foreach dir, $(SRC_DIRS) $(ASM_DIRS), build/$(dir)))
$(shell mkdir -p shc/temp)

all: $(STG02_ROM)
ifeq ($(COMPARE),1)
	@md5sum -c checksum.md5
endif

setup: 
	$(MAKE) -C tools
	$(DCSPLIT) stg02.yaml
	$(GENFSY) symbols.stg02.txt > asm/stg02_1st_read_symbols.src

clean:
	$(RM) -r $(ROM) $(ELF) build

.PHONY: all clean setup

$(STG02_ROM): $(STG02_ELF) 
	$(ELF2BIN) -s $(STG02_KEY) $< $@

$(STG02_ELF): $(O_FILES)
	$(LD) $(LDFLAGS) -sub=stg02_lnk.sub

# wibo doesn't support envvar conversion so we use wine for shc
# wine crashes asmsh, and asmsh doesn't use the envvars
# so wibo works 
build/src/%.obj: src/%.c
	$(FIX_INLINE_C) $< build/$<
	$(PATHHELP) $(CC) build/$< $(CFLAGS) -objectfile=$(@:.obj=.src)
	$(FIX_INLINE) $(@:.obj=.src)
	$(PATHHELP) $(AS) $(@:.obj=.src) $(ASFLAGS) -object=$@

build/asm/%.obj: asm/%.src
	$(PATHHELP) $(AS) $< $(ASFLAGS) -object=$@
