#include <task.h>

#define GET_MOBILE() ((NJS_OBJECT*)work->counter.ptr)
NJS_OBJECT* GetMobileLandObject();

extern NJS_OBJECT lbl_0CA3FEB4;

extern Uint8 lbl_0CAD4AE8;

typedef struct elewk {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
} elewk;

typedef struct elewk2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
} elewk2;

void sub_C906760(taskwk* work, elewk* ele, elewk2* ele2) {
    if(work->btimer > 4) {
        lbl_0CAD4AE8 = 1;
        njPrintC(0x1B, (const char*)0x0C910900); /* "       <<ELE>>" */
    } else {
        lbl_0CAD4AE8 = 0;
        njPrintC(0x1B, (const char*)0x0C910910); /* "       <<    >>" */
    }

    if(work->btimer++ > 8) {
        work->btimer = 0;
    }

    njPrintC(0x1C, (const char*)0x0C910920); /* "   Xang  ->  NO USE      " */
    njPrintC(0x1D, (const char*)0x0C91093C); /* "   Yang  ->  START ANGLE " */
    njPrintC(0x1E, (const char*)0x0C910958); /* "   Zang  ->  AIM   ANGLE " */
    njPrintC(0x1F, (const char*)0x0C910974); /* "   Xscl  ->  NO USE      " */
    njPrintC(0x20, (const char*)0x0C910990); /* "   Yscl  ->  OFFSET      " */
    njPrintC(0x21, (const char*)0x0C9109AC); /* "   Zscl  ->  NO USE      " */
   
    njPushMatrix(NULL);
    
    SetObjectTexture();
    njTranslateV(NULL, &work->pos);

    njPushMatrix(NULL);
    ROTATE_Y(work->ang.y);
    ___dsDrawObject(&lbl_0CA3FEB4);
    njPopMatrix(1);

    if(lbl_0CAD4AE8) {
        njTranslate(NULL, 0, work->scl.y, 0);
        njPushMatrix(NULL);
        ROTATE_Y(work->ang.z);
        ___dsDrawObject(&lbl_0CA3FEB4);
        njPopMatrix(1);
    }
   
    njPopMatrix(1);

    DrawLine(
        work->pos.x, 
        work->pos.y, 
        work->pos.z,
        work->pos.x, 
        work->pos.y + work->scl.y,
        work->pos.z
    );
}

extern NJS_MODEL lbl_0CA3FE8C, lbl_0CA3E130;
extern CCL_INFO lbl_0CA56260;

void sub_C906872(task* tp) {
    taskwk* work = tp->twp;
    elewk* ele = (elewk*)tp->mwp;
    elewk2* ele2 = (elewk2*)tp->fwp;

    work->mode = 1;
    work->ang.x = work->ang.y;

    ele->field_10 = work->pos.x;
    ele->field_14 = work->pos.y;
    ele->field_18 = work->pos.z;

    ele2->field_10 = 0;
    ele2->field_14 = 0;
    ele2->field_18 = 0;

    ele2->field_4 = 0;
    ele2->field_8 = 0;
    ele2->field_C = 0;

    {
        
        NJS_OBJECT* mobile;
        work->counter.ptr = mobile = GetMobileLandObject();
        
        GET_MOBILE()->pos[0] = work->pos.x;
        GET_MOBILE()->pos[1] = work->pos.y;
        GET_MOBILE()->pos[2] = work->pos.z;

        GET_MOBILE()->scl[0] = work->scl.z + 1.f;
        GET_MOBILE()->scl[1] = work->scl.z + 1.f;
        GET_MOBILE()->scl[2] = work->scl.z + 1.f;

        GET_MOBILE()->ang[0] = 0;
        GET_MOBILE()->ang[1] = work->ang.y;
        GET_MOBILE()->ang[2] = 0;

        GET_MOBILE()->model = &lbl_0CA3FE8C;
        RegisterCollisionEntry(0, tp, GET_MOBILE());
    }
    {
        NJS_OBJECT* mobile;
        mobile = GetMobileLandObject();

        mobile->pos[0] = work->pos.x;
        mobile->pos[1] = work->pos.y;
        mobile->pos[2] = work->pos.z;

        mobile->scl[0] = work->scl.z + 1.f;
        mobile->scl[1] = work->scl.z + 1.f;
        mobile->scl[2] = work->scl.z + 1.f;

        mobile->ang[0] = 0;
        mobile->ang[1] = work->ang.y;
        mobile->ang[2] = 0;

        mobile->model = &lbl_0CA3E130;

        RegisterCollisionEntry(0, tp, mobile);
        work->value.ptr = mobile;
    }

    if(work->scl.x < 0) {
        work->scl.y = -0.6f;
    } else {
        work->scl.y = 0.6f;
    }

    work->flag |= 0x100;
    CCL_Init(tp, &lbl_0CA56260, 6, 0, 1);
}

extern NJS_OBJECT lbl_0CA3E8AC, lbl_0CA3F4EC, lbl_0CA3FEB4;
extern NJS_MODEL lbl_0CA3F4C4;

void sub_C906A32(taskwk* work, elewk* ele) {
    (&lbl_0CA3E8AC)->ang[1] += 0x100;
    (&lbl_0CA3F4EC)->ang[2] += 0x100;

    njPushMatrix(NULL);
    SetObjectTexture();
    njTranslate(NULL, ele->field_10, ele->field_14, ele->field_18);
    ROTATE_Y(work->ang.x);
    ___dsDrawObject(&lbl_0CA3FEB4);
    njTranslate(NULL, 0, -23, 0);
    ROTATE_Y((&lbl_0CA3E8AC)->ang[1]);
    ___dsDrawModel(&lbl_0CA3F4C4);
    njPopMatrix(1);
}

void sub_C906B00(taskwk* work, elewk* ele, elewk2* ele2) {
    NJS_OBJECT* mobile2 = (NJS_OBJECT*)work->value.ptr;

    ele->field_10 += ele2->field_10;
    ele->field_14 += ele2->field_14;
    ele->field_18 += ele2->field_18;

    if(ele->field_14 < -467) {
        work->mode = 6;
        ele->field_14 = -467;
    }

    GET_MOBILE()->pos[0] = ele->field_10;
    GET_MOBILE()->pos[1] = ele->field_14;
    GET_MOBILE()->pos[2] = ele->field_18;
    GET_MOBILE()->ang[1] = work->ang.x;

    mobile2->pos[0] = ele->field_10;
    mobile2->pos[1] = ele->field_14;
    mobile2->pos[2] = ele->field_18;
    mobile2->ang[1] = work->ang.x;
}

void sub_C906B7E(taskwk* work, elewk* ele, elewk2* ele2) {
    ele2->field_14 = -work->scl.y;
    ele2->field_8 = 0x100;
}

void sub_C906B8E(taskwk* work, elewk* ele, elewk2* ele2) {
    ele2->field_14 = -work->scl.y;
    ele2->field_8 = NJM_DEG_ANG(180.f / (376.f / ele2->field_14));
    work->ang.x -= ele2->field_8;
}

void sub_C906BE0(taskwk* work) {
    if(work->flag & 8 || work->cwp->flag & 2) {
        work->mode = 3;
    }
}

void sub_C906BF8(task* tp, taskwk* work, elewk2* ele) {
    NJS_OBJECT* mobile = work->counter.ptr;
    ReleaseMobileLandObject(mobile);
    WithdrawCollisionEntry(tp, mobile);
    DeadOut(tp);
}

extern Uint16 CheckEditMode;
void sub_C906C1C(task* tp) {
    taskwk* work = tp->twp;
    elewk* ele = (elewk*)tp->mwp;
    elewk2* ele2 = (elewk2*)tp->fwp;

    if(CheckEditMode) {
        njPrintC(0x19, (const char*)0x0C9109C8); /* "EDIT" */
        sub_C906760(work, ele, NULL);
        return;
    }

    switch(work->mode) {
        case 0:
            sub_C906872(tp);
            break;
        case 1:
            ele2->field_14 = 0;
            ele2->field_8 = 0;
            sub_C906BE0(work);
            break;
        case 2:
            sub_C906B7E(work, ele, ele2);
            break;
        case 3:
            sub_C906B8E(work, ele, ele2);
            break;
        /* well this is probably a fake match but i dont know how to fix it */
        /* it always merges the cases if i don't do it like this, maybe it's a wrong compiler version or something? */
        case 4:
            ele2->field_14 = 0;
            if(1)ele2->field_8 = 0;
            break;
        case 5:
            ele2->field_14 = 0;
            if(2)ele2->field_8 = 0;
            break;
        case 6:
            ele2->field_14 = 0;
            if(3)ele2->field_8 = 0;
            break;
        case 7:
            sub_C906BF8(tp, work, ele2);
            break;
    }    

    sub_C906A32(work, ele);
    sub_C906B00(work, ele, ele2);

    EntryColliList(work);

    if(CheckRangeOut(tp)) {
        ReleaseMobileLandObject(GET_MOBILE());
        WithdrawCollisionEntry(tp, GET_MOBILE());
        work->counter.ptr = work->value.ptr;
        ReleaseMobileLandObject(GET_MOBILE());
        WithdrawCollisionEntry(tp, GET_MOBILE());
    }
}
