#include "dead.h"
#include "common.h"

#define NAMESPACE EB5130

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

extern s16 D_80169B12;

typedef struct arg8024030C_EB543C {
    /* 0x00 */ char unk_0[0xB];
    /* 0x0C */ Evt** unk_C;
} arg8024030C_EB543C;

s32 func_8024030C_EB543C(arg8024030C_EB543C* arg0) {
    evt_set_variable(arg0, *arg0->unk_C, D_80169B12);
    return 2;
}
