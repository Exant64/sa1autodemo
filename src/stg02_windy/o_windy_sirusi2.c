#include <task.h>

void func_0C905378(taskwk* work);
void func_0C9053C0(taskwk* work);

bool func_0C905340(task* tp) {
    taskwk* work = tp->twp;
    switch(work->mode) {
        case 0:
            func_0C905378(work);
            break;
        case 1:
            func_0C9053C0(work);
            break;
        default:
            work->mode = 0;
            break;
    }

    if(CheckRangeOut(tp));
}

void func_0C905378(taskwk* work) {
    work->ang.z = 0;
    work->scl.x = 1;
    work->scl.y = 1;
    work->scl.z = 1;
    work->counter.ptr = NULL;    
    work->mode = 1;
}

extern NJS_MODEL* lbl_0CA2B824, *lbl_0CA2BD04;
extern NJS_TEXLIST lbl_0C9FECB8;
extern NJS_POINT3 lbl_0CA2B828;

void ___dsDrawModel(NJS_MODEL*);

void func_0C9053C0(taskwk* work) {
    work->ang.z += 0x400;

    njSetTexture(&lbl_0C9FECB8);

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);

    ROTATE_Y(work->ang.y);

    ___dsDrawModel(lbl_0CA2BD04);

    njTranslate(NULL, lbl_0CA2B828.x, lbl_0CA2B828.y, lbl_0CA2B828.z);
     
    if((Uint32)(njSin(work->ang.z) * 8192.f) != 0) {            
        njRotateX(NULL, (Uint32)(njSin(work->ang.z) * 8192.f));
    } else {}
    
    /* ROTATE_X(njSin(work->ang.z) * 8192.f); */
    
    ___dsDrawModel(lbl_0CA2B824);

    njPopMatrix(1);
}
