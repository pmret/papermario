#include "common.h"

// controls the large arrow hovering in front of the train station
EvtScript N(EVS_UpdateDirectionArrow) = {
    EVT_CALL(SetTexPanner, MODEL_y_a, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_y_a, TRUE)
    // adjust color with a UV offset into a color palette texture
    EVT_SET(MV_ArrowTexUOffset, 0x4000 * 2)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, MV_ArrowTexUOffset, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar5, 0)
    // slowly rotate the arrow
    EVT_LABEL(0)
        EVT_ADD(LVar5, 2)
        EVT_IF_GT(LVar5, 360)
            EVT_SUB(LVar5, 360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_y_a, LVar5, 0, 0, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_EitherSwitchPressed, TRUE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_LABEL(10)
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_SET(LVar2, 270)
            EVT_CALL(EnableTexPanning, MODEL_y_c2, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_y_b2, TRUE)
        EVT_ELSE
            EVT_SET(LVar2, 90)
            EVT_CALL(EnableTexPanning, MODEL_y_b2, FALSE)
            EVT_CALL(EnableTexPanning, MODEL_y_c2, TRUE)
        EVT_END_IF
        EVT_IF_LT(LVar2, LVar5)
            EVT_ADD(LVar2, 360)
        EVT_END_IF
        EVT_SET(LVar6, AF_OMO_UsingRightSwitch)
        EVT_CALL(MakeLerp, LVar5, LVar2, 60, EASING_COS_FAST_OVERSHOOT)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar4, -1)
        EVT_LABEL(11)
        EVT_CALL(UpdateLerp)
        EVT_IF_LT(LVar2, LVar0)
            EVT_SET(LVar3, 0)
        EVT_ELSE
            EVT_SET(LVar3, 1)
        EVT_END_IF
        EVT_IF_NE(LVar4, -1)
            EVT_IF_NE(LVar3, LVar4)
                EVT_CALL(PlaySound, SOUND_OMO_TRAIN_SWITCH_RATTLE)
            EVT_END_IF
        EVT_END_IF
        EVT_SET(LVar4, LVar3)
        EVT_CALL(RotateModel, MODEL_y_a, LVar0, 0, 0, -1)
        EVT_WAIT(1)
        EVT_IF_NE(AF_OMO_UsingRightSwitch, LVar6)
            EVT_GOTO(21)
        EVT_END_IF
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(PlaySound, SOUND_OMO_TRAIN_SWITCH_SELECT)
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_SET(MV_ArrowTexUOffset, 0x4000)
        EVT_ELSE
            EVT_SET(MV_ArrowTexUOffset, 0x4000 * 3)
        EVT_END_IF
        EVT_LABEL(20)
            EVT_WAIT(1)
            EVT_IF_EQ(AF_OMO_UsingRightSwitch, LVar6)
                EVT_GOTO(20)
            EVT_END_IF
        EVT_LABEL(21)
        EVT_SET(LVar5, LVar0)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PressSwitch_Left) = {
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_PARAKARRY)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(MF_EitherSwitchPressed, TRUE)
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, FALSE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SET(MF_EitherSwitchPressed, TRUE)
    EVT_SET(AF_OMO_UsingRightSwitch, FALSE)
    EVT_CALL(MakeLerp, 0, -18, 15, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_y_b1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_y_b2, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o920)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o921)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(MakeLerp, -18, 0, 15, EASING_LINEAR)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_y_b1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_y_b2, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o920)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o921)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PressSwitch_Right) = {
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_PARAKARRY)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(MF_EitherSwitchPressed, TRUE)
        EVT_IF_EQ(AF_OMO_UsingRightSwitch, TRUE)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_SET(MF_EitherSwitchPressed, TRUE)
    EVT_SET(AF_OMO_UsingRightSwitch, TRUE)
    EVT_CALL(MakeLerp, 0, -18, 15, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_y_c1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_y_c2, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o923)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o924)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(MakeLerp, -18, 0, 15, EASING_LINEAR)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_y_c1, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_y_c2, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o923)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o924)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_SetupSwitches) = {
    EVT_SET(MF_EitherSwitchPressed, FALSE)
    EVT_SET(AF_JAN01_TreeDrop_StarPiece, FALSE)
    EVT_EXEC(N(EVS_UpdateDirectionArrow))
    EVT_CALL(ParentColliderToModel, COLLIDER_o920, MODEL_y_b1)
    EVT_CALL(ParentColliderToModel, COLLIDER_o921, MODEL_y_b2)
    EVT_CALL(ParentColliderToModel, COLLIDER_o923, MODEL_y_c1)
    EVT_CALL(ParentColliderToModel, COLLIDER_o924, MODEL_y_c2)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PressSwitch_Left)), TRIGGER_FLOOR_TOUCH, COLLIDER_o920, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PressSwitch_Left)), TRIGGER_WALL_HAMMER, COLLIDER_o921, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PressSwitch_Right)), TRIGGER_FLOOR_TOUCH, COLLIDER_o923, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PressSwitch_Right)), TRIGGER_WALL_HAMMER, COLLIDER_o924, 1, 0)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(-1100,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
