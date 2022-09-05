#include "nok_01.h"
#include "effects.h"

extern s32 D_8024856C_9CD94C;
extern s32 D_80248570_9CD950;

static char* N(exit_str_0) = "nok_13";
static char* N(exit_str_1) = "nok_02";

#define CHUCK_QUIZMO_NPC_ID 15

#include "world/common/enemy/StationaryAI.inc.c"

#include "world/common/atomic/ToadHouse.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_80242028_9C7408(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_8024856C_9CD94C = FALSE;
    }

    if (D_8024856C_9CD94C) {
        D_8024856C_9CD94C = FALSE;
        evt_set_variable(script, *args++, D_80248570_9CD950);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242028_9C7408);
#endif

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024207C_9C745C);

extern s32 D_80251C70[];

ApiStatus func_802420B4_9C7494(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80251C70[i] = ptr[i];
        }
        D_80251C70[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80251C70[i] = i + 16;
            D_80251C70[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

ApiStatus func_8024243C_9C781C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    f32 angle = clamp_angle((get_npc_safe(npcID)->yaw + 180.0f) - gCameras[gCurrentCameraID].currentYaw);
    s32 outVal;

    outVal = FALSE;
    if (angle > 270.0f || angle < 90.0f) {
        outVal = TRUE;
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

#include "common/UnkFloatFunc.inc.c"

ApiStatus func_802426A4_9C7A84(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20;
    f32 temp_f22;
    f32 f3;

    temp_f22 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_variable(script, *args++);
    f3 = evt_get_variable(script, *args++);

    fx_explosion(0, temp_f22, temp_f20 + 15.0f, f3);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

ApiStatus func_80242760_9C7B40(Evt* script, s32 isInitialCall) {
    func_800E98EC();
    func_800E9894();
    open_status_menu_long();
    return ApiStatus_DONE2;
}

ApiStatus func_80242790_9C7B70(Evt* script, s32 isInitialCall) {
    func_800E9900();
    func_800E98C4();
    close_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus func_802427C0_9C7BA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, *args++);
    snd_ambient_80055448(16);
    snd_ambient_80055760(4);
    au_ambience_set_volume(0, 250, 1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242804_9C7BE4);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242858_9C7C38);

ApiStatus func_80242898_9C7C78(Evt* script, s32 isInitialCall) {
    snd_ambient_80055848(4);
    return ApiStatus_DONE2;
}

ApiStatus func_802428B8_9C7C98(Evt* script, s32 isInitialCall) {
    snd_ambient_800557CC(100);
    return ApiStatus_DONE2;
}

// Requires BSS
#ifdef NON_MATCHING
ApiStatus func_802428D8_9C7CB8(Evt* script, s32 isInitialCall) {
    static s16 D_80250810_9D5BF0[] = { 0, 2, 1, 4 };
    
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    
    snd_ambient_80055848(D_80250810_9D5BF0[index]);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428D8_9C7CB8);
#endif

ApiStatus func_80242910_9C7CF0(Evt* script, s32 isInitialCall) {
    gPlayerData.tradeEventStartTime = gPlayerData.frameCounter;
    return ApiStatus_DONE2;
}
