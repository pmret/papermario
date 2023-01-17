#include "nok_01.h"
#include "effects.h"

static char* N(exit_str_0) = "nok_13";
static char* N(exit_str_1) = "nok_02";

#define CHUCK_QUIZMO_NPC_ID 15

#include "world/common/enemy/ai/StationaryAI.inc.c"

#include "world/common/atomic/ToadHouse.inc.c"

extern s32 N(Quizmo_Worker);
extern s32 N(Quizmo_AnswerResult);
extern EffectInstance* N(Quizmo_StageEffect);
extern EffectInstance* N(Quizmo_AudienceEffect);
extern EffectInstance* N(Quizmo_VannaTEffect);

#include "world/common/atomic/Quizmo.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
#include "world/common/todo/ItemChoice_WaitForSelection.inc.c"

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 nok_01_D_80251C40[12]; // unused?
BSS s32 nok_01_D_80251C70[114];

ApiStatus func_802420B4_9C7494(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_01_D_80251C70[i] = ptr[i];
        }
        nok_01_D_80251C70[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            nok_01_D_80251C70[i] = i + 16;
            nok_01_D_80251C70[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

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

#include "common/CosInterpMinMax.inc.c"

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
    status_menu_ignore_changes();
    open_status_menu_long();
    return ApiStatus_DONE2;
}

ApiStatus func_80242790_9C7B70(Evt* script, s32 isInitialCall) {
    func_800E9900();
    status_menu_respond_to_changes();
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

extern s16 D_80250810_9D5BF0[];

ApiStatus func_80242804_9C7BE4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    snd_ambient_80055848(D_80250810_9D5BF0[idx]);
    au_ambience_set_volume(D_80250810_9D5BF0[idx], 1500, 127);
    return ApiStatus_DONE2;
}

ApiStatus func_80242858_9C7C38(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    au_ambience_set_volume(D_80250810_9D5BF0[idx], 1500, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80242898_9C7C78(Evt* script, s32 isInitialCall) {
    snd_ambient_80055848(4);
    return ApiStatus_DONE2;
}

ApiStatus func_802428B8_9C7C98(Evt* script, s32 isInitialCall) {
    snd_ambient_800557CC(100);
    return ApiStatus_DONE2;
}

ApiStatus func_802428D8_9C7CB8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    NOP_FIX // TODO: REMOVE WHEN DATA (D_80250810_9D5BF0) IS MIGRATED
    snd_ambient_80055848(D_80250810_9D5BF0[index]);
    return ApiStatus_DONE2;
}

ApiStatus func_80242910_9C7CF0(Evt* script, s32 isInitialCall) {
    gPlayerData.tradeEventStartTime = gPlayerData.frameCounter;
    return ApiStatus_DONE2;
}
