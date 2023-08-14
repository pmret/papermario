#include "isk_12.h"

// switch for draining the sand into the lower chamber
EvtScript N(EVS_OnTouch_DrainSwitch) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(5)
        EVT_WAIT(1)
        EVT_CALL(PartnerCanUseAbility, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar1, -470)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(2.5))
            EVT_CALL(NpcJump0, NPC_PARTNER, 529, -470, 82, 10)
            EVT_WAIT(10)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2059, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_g367, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o2056)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o2059)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2059, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    EVT_SET(AF_ISK12_SandSwitchActivated, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

// switch for creating a staircase of bricks emerging from the wall
EvtScript N(EVS_OnTouch_StaircaseSwitch) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2090, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_B2, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o2090)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2090, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    EVT_CALL(InterpPlayerYaw, 260, 0)
    EVT_SET(AF_ISK12_StairSwitchActivated, TRUE)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 449, -822, 148)
        EVT_CALL(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g378, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 449, -822, 148)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 460, -806, 108)
        EVT_CALL(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        EVT_LABEL(22)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g379, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(22)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 460, -806, 108)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 432, -825, 189)
        EVT_CALL(MakeLerp, -50, 0, 60, EASING_QUADRATIC_IN)
        EVT_LABEL(24)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g376, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(24)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 432, -825, 189)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(0.1))
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_RUMBLE, SOUND_SPACE_DEFAULT, 451, -812, 137)
        EVT_CALL(MakeLerp, -50, 0, 50, EASING_QUADRATIC_IN)
        EVT_LABEL(26)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g373, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(26)
        EVT_END_IF
        EVT_CALL(PlaySoundAt, SOUND_ISK_STAIRS_EMERGE_THUD, SOUND_SPACE_DEFAULT, 451, -812, 137)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2080, COLLIDER_FLAGS_UPPER_MASK)
    EVT_WAIT(3)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSwitches) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o2056, MODEL_g367)
    EVT_CALL(ParentColliderToModel, COLLIDER_o2059, MODEL_g367)
    EVT_CALL(ParentColliderToModel, COLLIDER_o2090, MODEL_B2)
    EVT_IF_EQ(AF_ISK12_SandSwitchActivated, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_DrainSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2059, 1, 0)
    EVT_ELSE
        EVT_CALL(TranslateModel, MODEL_g367, 0, -14, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2056)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2059)
    EVT_END_IF
    EVT_IF_EQ(AF_ISK12_StairSwitchActivated, TRUE)
        EVT_CALL(TranslateModel, MODEL_B2, 0, -14, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2090)
    EVT_ELSE
        EVT_THREAD
            EVT_CALL(TranslateGroup, MODEL_g378, -52, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g379, -52, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g376, -52, 0, 0)
            EVT_CALL(TranslateGroup, MODEL_g373, -52, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2080, COLLIDER_FLAGS_UPPER_MASK)
            EVT_IF_EQ(GF_ISK12_Hammer2Block, FALSE)
                EVT_CALL(TranslateModel, MODEL_B2, 0, -14, 0)
                EVT_CALL(UpdateColliderTransform, COLLIDER_o2090)
                EVT_LABEL(10)
                EVT_IF_EQ(GF_ISK12_Hammer2Block, FALSE)
                    EVT_WAIT(1)
                    EVT_GOTO(10)
                EVT_END_IF
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(MakeLerp, -14, 0, 30, EASING_LINEAR)
                EVT_LABEL(20)
                EVT_CALL(UpdateLerp)
                EVT_CALL(TranslateModel, MODEL_B2, 0, LVar0, 0)
                EVT_CALL(UpdateColliderTransform, COLLIDER_o2090)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(20)
                EVT_END_IF
                EVT_WAIT(3)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_StaircaseSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2090, 1, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
