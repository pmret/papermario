#include "kzn_19.h"
#include "sprite/player.h"

EvtScript N(EVS_CrackFloor) = {
    Call(EnableGroup, MODEL_naka, false)
    Call(EnableGroup, MODEL_g93, true)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
    SetF(LVar0, 0)
    Thread
        Loop(60)
            AddF(LVar0, Float(0.334))
            Call(RotateModel, MODEL_o2, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Loop(60)
            AddF(LVar0, Float(0.5))
            Call(RotateModel, MODEL_o3, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Loop(60)
            AddF(LVar0, Float(0.25))
            Call(RotateModel, MODEL_o4, LVar0, 0, 0, -1)
            Wait(1)
        EndLoop
    EndThread
    Loop(120)
        SubF(LVar0, Float(0.25))
        Call(TranslateModel, MODEL_o6, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Set(AF_KZN_BossRoomFloorBroken, false)
    Return
    End
};

EvtScript N(EVS_SetFloorCracked) = {
    Call(RotateModel, MODEL_o2, 20, 0, 0, -1)
    Call(RotateModel, MODEL_o3, 30, 0, 0, -1)
    Call(RotateModel, MODEL_o4, 15, 0, 0, -1)
    Call(TranslateModel, MODEL_o6, 0, -30, 0)
    Return
    End
};

EvtScript N(EVS_UpdateEruption) = {
    Set(AF_KZN_BossRoomFloorBroken, false)
    IfGe(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        // wait for card pickup
        Loop(0)
            Wait(1)
            IfNe(AF_KZN_BossRoomFloorBroken, false)
                BreakLoop
            EndIf
        EndLoop
        // begin eruption effects
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(2.0))
        Call(SetPanTarget, CAM_DEFAULT, 170, 25, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(ShakeCam, CAM_DEFAULT, 0, 25, Float(2.0))
        Call(InterpPlayerYaw, 270, 0)
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Flail)
        Exec(N(EVS_CrackFloor))
        Call(MakeLerp, 200, 50, 75, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            Call(ShakeCam, CAM_DEFAULT, 0, 1, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    Else
        // GB_StoryProgress == STORY_CH5_MT_LAVA_LAVA_ERUPTING
        Exec(N(EVS_SetFloorCracked))
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi, COLLIDER_FLAGS_UPPER_MASK)
    Loop(0)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.5))
    EndLoop
    Return
    End
};
