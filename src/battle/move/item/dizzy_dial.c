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
    SetConst(LVarA, ITEM_DIZZY_DIAL)
    ExecWait(N(UseItemWithEffect))
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(10)
    Thread
        Wait(5)
        Call(AddBattleCamZoom, -250)
        Call(MoveBattleCamOver, 80)
        Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
        Wait(80)
        Call(AddBattleCamZoom, 250)
        Call(MoveBattleCamOver, 3)
        Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    EndThread
    Call(N(AnimateDizzyDialCameraFX))
    Thread
        Call(StartRumble, BTL_RUMBLE_PLAYER_LIGHT)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(4.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Wait(10)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
        Call(MoveBattleCamOver, 10)
        Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, FALSE)
    EndThread
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetItemPower, ITEM_DIZZY_DIAL, LVar0, LVar1)
        Call(MakeStatusField, LVar0, STATUS_FLAG_DIZZY, 100, LVar0)
        Call(ItemAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, LVar0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Wait(30)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
