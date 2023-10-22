#include "common.h"
#include "script_api/battle.h"
#include "camera.h"

#define NAMESPACE battle_item_dizzy_dial

static s32 ScreenBlurWorkerID;

#include "battle/common/move/ItemRefund.inc.c"

void N(worker_render_screen_blur)(void) {
    draw_prev_frame_buffer_at_screen_pos(0, 0, 320, 240, 160.0f);
}

API_CALLABLE(N(AnimateDizzyDialCameraFX)) {
    Camera* camera = &gCameras[CAM_BATTLE];
    f32 angle;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            sfx_play_sound(SOUND_DIZZY_DIAL);
            camera->auxPitch = 0;
            ScreenBlurWorkerID = create_worker_frontUI(NULL, N(worker_render_screen_blur));
            script->functionTemp[0] = 1;
        case 1:
            camera->flags |= CAMERA_FLAG_SHAKING;
            angle = script->functionTemp[1];
            guRotateF(camera->viewMtxShaking, angle, 0.0f, 0.0f, 1.0f);
            script->functionTemp[1] = 2.0 * ((1.0 - sin_rad(DEG_TO_RAD(script->functionTemp[2] + 90))) * 360.0);
            script->functionTemp[2]++;
            if (script->functionTemp[2] <= 90) {
                return ApiStatus_BLOCK;
            }
            camera->auxPitch = 0;
            camera->flags &= ~CAMERA_FLAG_SHAKING;
            free_worker(ScreenBlurWorkerID);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_DIZZY_DIAL)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(AddBattleCamZoom, -250)
        EVT_CALL(MoveBattleCamOver, 80)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
        EVT_WAIT(80)
        EVT_CALL(AddBattleCamZoom, 250)
        EVT_CALL(MoveBattleCamOver, 3)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    EVT_END_THREAD
    EVT_CALL(N(AnimateDizzyDialCameraFX))
    EVT_THREAD
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, FALSE)
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetItemPower, ITEM_DIZZY_DIAL, LVar0, LVar1)
        EVT_CALL(MakeStatusField, LVar0, STATUS_FLAG_DIZZY, 100, LVar0)
        EVT_CALL(ItemAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, LVar0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_LABEL(1)
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
