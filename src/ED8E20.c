#include "dead.h"
#include "common.h"

#define NAMESPACE ED8E20

extern GameStatus* D_80079430;
extern f32 D_800B8DEC;

typedef struct DokanModelInfo {
    /* 0x00 */ s32 no;
    /* 0x04 */ Vec3f position;
} DokanModelInfo;

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

ApiStatus func_80240020_ED8E40(Evt* script, s32 isInitialCall) {
    script->varTable[0] = dead_gCollisionStatus.pushingAgainstWall;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "ED8E20", func_80240034_ED8E54);

#ifdef NON_EQUIVALENT

// Something off with the pointers? Not sure if functionally equivalent.
ApiStatus func_802400F0_ED8F10(Evt* script, s32 isInitialCall) {
    s32 temp_s1;
    Model* temp_s2;

    temp_s2 = func_8005F128();
    temp_s1 = evt_get_variable(script, EVT_VAR(0)) * 0x10;
    evt_set_variable(script, EVT_VAR(1), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->no);
    evt_set_variable(script, EVT_VAR(2), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.x);
    evt_set_variable(script, EVT_VAR(3), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.y);
    evt_set_variable(script, EVT_VAR(4), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.z);
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11", D_80079430->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4]);
    return ApiStatus_DONE2;
}

#else
INCLUDE_ASM(s32, "ED8E20", func_802400F0_ED8F10);
#endif

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

ApiStatus func_80240318_ED9138(Evt* script, s32 isInitialCall) {
    dead_playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
