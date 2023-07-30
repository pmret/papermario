#include "sam_10.h"
#include "effects.h"

Vec2i N(StaircaseStepsData)[] = {
    { MODEL_1,   -200 },
    { MODEL_2,   -230 },
    { MODEL_3,   -260 },
    { MODEL_4,   -290 },
    { MODEL_5,   -320 },
    { MODEL_6,   -350 },
    { MODEL_7,   -380 },
    { MODEL_8,   -410 },
    { MODEL_9,   -440 },
    { MODEL_10,  -470 },
    { MODEL_11,  -530 },
    { MODEL_12,  -560 },
    { MODEL_13,  -590 },
    { MODEL_14,  -620 },
    { MODEL_15,  -650 },
    { MODEL_16,  -680 },
    { MODEL_17,  -710 },
    { MODEL_18,  -740 },
    { MODEL_19,  -770 },
    { MODEL_20,  -800 },
    { MODEL_21,  -860 },
    { MODEL_22,  -890 },
    { MODEL_23,  -920 },
    { MODEL_24,  -950 },
    { MODEL_25,  -980 },
    { MODEL_26, -1010 },
    { MODEL_27, -1040 },
    { MODEL_28, -1070 },
    { MODEL_29, -1100 },
    { MODEL_30, -1130 },
};

API_CALLABLE(N(GetCamPointsNearPlayer)) {
    script->varTable[0] = gPlayerStatus.pos.x + (sin_deg(310.0f) * 100.0f);
    script->varTable[1] = gPlayerStatus.pos.z - (cos_deg(310.0f) * 100.0f);
    script->varTable[2] = gPlayerStatus.pos.x + (sin_deg(130.0f) * 100.0f);
    script->varTable[3] = gPlayerStatus.pos.z - (cos_deg(130.0f) * 100.0f);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ItemPrompt_StarStoneSocket) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FindKeyItem, ITEM_STAR_STONE, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_RETURN
            EVT_CASE_EQ(-1)
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_RETURN
            EVT_CASE_DEFAULT
                EVT_CALL(RemoveKeyItemAt, LVar1)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_SAM10_PlaceItemTip, 160, 40)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetItemPos, MV_StarStoneItemID, -117, 179, -32)
    EVT_CALL(PlaySoundAt, SOUND_1EB, 0, -117, 179, -32)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(MakeLerp, -32, -55, 100 * DT, EASING_COS_IN_OUT)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetItemPos, MV_StarStoneItemID, -117, 179, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o61, SOUND_39C, 0)
    EVT_CALL(MakeLerp, 0, -23, 100 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_g51, 0, 0, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(UpdateColliderTransform, COLLIDER_o61)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(600.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(2.0), EVT_FLOAT(5.0))
    EVT_CALL(N(GetCamPointsNearPlayer))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, LVar2, LVar3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_CALL(PlaySound, SOUND_39D)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(3.0))
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, -20, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 20, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 60, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 100, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 140, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 180, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 220, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 240, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 280, -20, -66, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, -20, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 20, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 60, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 100, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 140, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 180, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 220, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 240, -20, -166, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, 280, -20, -166, 0)
    EVT_WAIT(20)
    EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_move2, MODEL_GROUP_VISIBLE)
    EVT_CALL(SetGroupVisibility, MODEL_move3, MODEL_GROUP_HIDDEN)
    EVT_CALL(PlaySound, SOUND_80000040)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 600, EVT_FLOAT(0.15))
    EVT_END_THREAD
    EVT_SET(LVar2, 0)
    EVT_USE_BUF(EVT_PTR(N(StaircaseStepsData)))
    EVT_LOOP(30)
        EVT_ADD(LVar2, 1)
        EVT_BUF_READ2(LVar3, LVar4)
        EVT_THREAD
            EVT_SET(LVar5, LVar4)
            EVT_DIV(LVar5, -2)
            EVT_CALL(MakeLerp, LVar4, 0, LVar5, EASING_LINEAR)
            EVT_LABEL(3)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, LVar3, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(3)
            EVT_END_IF
            EVT_IF_EQ(LVar2, 30)
                EVT_CALL(PlaySound, SOUND_39F)
                EVT_CALL(StopSound, SOUND_80000040)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(3.0))
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(2.0))
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
                EVT_SET(LVarB, LVar0)
                EVT_CALL(GetModelCenter, LVar3)
                EVT_SET(LVarA, -20)
                EVT_SUB(LVarA, LVarB)
            EVT_ELSE
                EVT_CALL(PlaySoundAt, SOUND_1EC, 0, LVar0, LVarA, LVar2)
                EVT_MOD(LVar2, 3)
                EVT_IF_EQ(LVar2, 0)
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
                EVT_END_IF
            EVT_END_IF
        EVT_END_THREAD
    EVT_END_LOOP
    EVT_WAIT(150)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 140, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(400.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(MakeLerp, 150, 1050, 200, EASING_LINEAR)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 150, 150, -70)
        EVT_LABEL(100)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 150, LVar0, -70)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(750.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-14.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(100)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(480)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_m2_kabe, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_m2_yuka, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_move2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, MODEL_move3, MODEL_GROUP_VISIBLE)
    EVT_SET(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 337.0f, -20.0f, -103.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 2, 135, 11, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_a_oku, TRUE)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_a_kabe, TRUE)
        EVT_CALL(EnableModel, MODEL_a_hibi, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_a_kabe, FALSE)
        EVT_CALL(EnableModel, MODEL_a_hibi, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_SAM10_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(StarStoneList)[] = {
    ITEM_STAR_STONE,
    ITEM_NONE
};

EvtScript N(EVS_SetupStairs) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yuka, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o79, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o80, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o81, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o86, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    EVT_CALL(ParentColliderToModel, COLLIDER_o61, MODEL_kouri)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_RAISED_FROZEN_STAIRS)
        EVT_CALL(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_move3, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m2_kabe, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m2_yuka, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_move2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_m1_kabe, SURFACE_TYPE_SNOW)
        EVT_USE_BUF(EVT_PTR(N(StaircaseStepsData)))
        EVT_LOOP(30)
            EVT_BUF_READ2(LVarA, LVarB)
            EVT_CALL(TranslateGroup, LVarA, 0, LVarB, 0)
        EVT_END_LOOP
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_StarStoneSocket)), TRIGGER_WALL_PRESS_A, COLLIDER_o61, EVT_PTR(N(StarStoneList)), 0, 1)
    EVT_ELSE
        EVT_CALL(TranslateGroup, MODEL_g51, 0, 0, -23)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o61)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o89, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_move1, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_move2, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_m1_kabe, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_GOT_STAR_STONE)
        EVT_SET(GF_SAM10_BombedWall, TRUE)
    EVT_END_IF
    EVT_IF_EQ(GF_SAM10_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_a_oku, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_a_kabe, FALSE)
        EVT_CALL(EnableModel, MODEL_a_hibi, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
