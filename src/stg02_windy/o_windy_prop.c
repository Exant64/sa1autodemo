#include <task.h>

extern NJS_OBJECT lbl_0CA2A864;
extern NJS_TEXLIST lbl_0C9FECB8;
extern NJS_OBJECT lbl_0CA29EDC, lbl_0CA2AFE0;

void sub_C9040F8(taskwk* work);
void sub_C904160(taskwk* work);

void ObjectPropA(task* tp) {
    taskwk* work = tp->twp;

    switch(work->mode) {
        case 0:
            sub_C9040F8(work);
            break;
        case 1:
            sub_C904160(work);
            break;
        default:
            work->mode = 0;
            break;
    }

    if(CheckRangeOut(tp));
}

void sub_C9040F8(taskwk* work) {
    work->ang.x = rand() / 1.5f;
    work->ang.z = rand() / 1.5f;
    work->mode = 1;
}

void sub_C904160(taskwk* work) {
    (&lbl_0CA2A864)->ang[1] = work->ang.z; 
    work->ang.z += 0x280;
    (&lbl_0CA29EDC)->ang[1] = work->ang.x;
    work->ang.x -= 0xB0;

    ___njSetTexture(&lbl_0C9FECB8);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    ROTATE_Y(work->ang.y);
    
    ds_DrawObjectClip(&lbl_0CA2AFE0);
    njPopMatrix(1);
}