#include "kzn_19.h"
#include "sprite/player.h"

EvtScript N(EVS_CrackFloor) = {
    EVT_CALL(EnableGroup, MODEL_naka, FALSE)
    EVT_CALL(EnableGroup, MODEL_g93, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_hoshi_ato, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SETF(LVar0, 0)
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.334))
            EVT_CALL(RotateModel, MODEL_o2, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.5))
            EVT_CALL(RotateModel, MODEL_o3, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(60)
            EVT_ADDF(LVar0, EVT_FLOAT(0.25))
            EVT_CALL(RotateModel, MODEL_o4, LVar0, 0, 0, -1)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(120)
        EVT_SUBF(LVar0, EVT_FLOAT(0.25))
        EVT_CALL(TranslateModel, MODEL_o6, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(AF_KZN_BossRoomFloorBroken, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetFloorCracked) = {
    EVT_CALL(RotateModel, MODEL_o2, 20, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o3, 30, 0, 0, -1)
    EVT_CALL(RotateModel, MODEL_o4, 15, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o6, 0, -30, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateEruption) = {
    EVT_SET(AF_KZN_BossRoomFloorBroken, FALSE)
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
        // wait for card pickup
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_IF_NE(AF_KZN_BossRoomFloorBroken, FALSE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        // begin eruption effects
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(2.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 170, 25, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 25, EVT_FLOAT(2.0))
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
        EVT_EXEC(N(EVS_CrackFloor))
        EVT_CALL(MakeLerp, 200, 50, 75, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, EVT_FLOAT(100.0))
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 1, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_ELSE
        // GB_StoryProgress == STORY_CH5_MT_LAVA_LAVA_ERUPTING
        EVT_EXEC(N(EVS_SetFloorCracked))
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_hoshi, COLLIDER_FLAGS_UPPER_MASK)
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
