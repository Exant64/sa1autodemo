#include <task.h>
#include <object.h>
#include <editor.h>

extern NJS_OBJECT lbl_0CA36FC8, lbl_0CA22784, lbl_0CA22C28, lbl_0CA23180, lbl_0CA236D4, lbl_0CA37624, lbl_0CA1F424, lbl_0CA128DC, lbl_0CA200B8, lbl_0CA37EF0, lbl_0CA0CF94;
extern CCL_INFO lbl_0CA55DF0, lbl_0CA55E24, lbl_0CA55E58, lbl_0CA55E8C, lbl_0CA55EC0, lbl_0CA55F28, lbl_0CA55F5C;

void _func_0C905100(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA36FC8;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55DF0, 4, 0, 1);
    }

    ObjectCCollision(tp);
}

void _func_0C905132(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA22784;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55E24, 4, 0, 1);
    }

    ObjectCCollision(tp);
}

void _func_0C905164(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA22C28;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55E58, 4, 0, 1);
    }

    ObjectCCollision(tp);
}

void _func_0C905196(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA23180;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55E8C, 4, 0, 1);
    }

    ObjectCCollision(tp);
}

void _func_0C9051C8(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA236D4;

    ObjectNormal(tp);
}

void _func_0C9051D2(task* tp) {
    taskwk* work = tp->twp;
    work->timer.ptr = &lbl_0CA37624;

    UnkWV14(tp);
}

void _func_0C9051DC(task* tp) {
    taskwk* work = tp->twp;
    work->timer.ptr = &lbl_0CA1F424;

    UnkWV14(tp);
}

void _func_0C9051E6(task* tp) {
    taskwk* work = tp->twp;
    work->timer.ptr = &lbl_0CA200B8;

    UnkWV14(tp);
}

void _func_0C905260(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA37EF0;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55EC0, 4, 0, 2);
    }

    ObjectCCollision(tp);
}

void _func_0C905292(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA128DC;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55F28, 4, 0, 1);
    }

    ObjectCCollision(tp);
}

void _func_0C9052C4(task* tp) {
    taskwk* work = tp->twp;
    work->counter.ptr = &lbl_0CA0CF94;
    if(!OnEdit(tp)) {
        CCL_Init(tp, &lbl_0CA55F5C, 4, 0, 2);
    }

    ObjectCCollision(tp);
}
