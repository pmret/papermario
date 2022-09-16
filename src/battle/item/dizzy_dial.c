#include "dizzy_dial.h"
#include "camera.h"

static s32* D_802A1CD0;

#include "ItemRefund.inc.c"

void func_802A123C_727B4C(void) {
    func_80138D88(0, 0, 0x140, 0xF0, 160.0f);
}

ApiStatus N(func_802A1270_727B80)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 a;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            sfx_play_sound(SOUND_2033);
            camera->unk_1C = 0;
            D_802A1CD0 = create_generic_entity_frontUI(NULL, func_802A123C_727B4C);
            script->functionTemp[0] = 1;
        case 1:
            camera->flags |= CAM_FLAG_SHAKING;
            a = script->functionTemp[1];
            guRotateF(camera->viewMtxShaking, a, 0.0f, 0.0f, 1.0f);
            script->functionTemp[1] = 2.0 * ((1.0 - sin_rad(DEG_TO_RAD(script->functionTemp[2] + 90))) * 360.0);
            script->functionTemp[2]++;
            if (script->functionTemp[2] <= 90) {
                return ApiStatus_BLOCK;
            }
            camera->unk_1C = 0;
            camera->flags &= ~CAM_FLAG_SHAKING;
            free_generic_entity(D_802A1CD0);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x0000009A)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(AddBattleCamZoom, -250)
        EVT_CALL(MoveBattleCamOver, 80)
        EVT_CALL(func_8024ECF8, 0, 0, 1)
        EVT_WAIT(80)
        EVT_CALL(AddBattleCamZoom, 250)
        EVT_CALL(MoveBattleCamOver, 3)
        EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(N(func_802A1270_727B80))
    EVT_THREAD
        EVT_CALL(StartRumble, 8)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LVar0, 268435456, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_DIZZY_DIAL, LVar0, LVar1)
    EVT_CALL(MakeStatusField, LVar0, 262144, 100, LVar0)
    EVT_CALL(func_80252B3C, LVar0, 1342177280, LVar0, 0, 32)
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
