#include "trd_02.h"
#include "effects.h"

extern EvtScript N(D_80242890_9A3870);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

EvtScript N(EVS_ExitDoors_trd_01_1) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_0, "trd_01", trd_01_ENTRY_1, COLLIDER_ttw, MODEL_o6, MODEL_o7);
EvtScript N(EVS_ExitDoors_trd_03_0) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_1, "trd_03", trd_03_ENTRY_0, COLLIDER_tte, MODEL_o9, MODEL_o8);
EvtScript N(EVS_ExitDoors_trd_01_2) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_2, "trd_01", trd_01_ENTRY_2, COLLIDER_ttw2, MODEL_o13, MODEL_o12);
EvtScript N(EVS_ExitDoors_trd_03_2) = EVT_EXIT_DOUBLE_DOOR(trd_02_ENTRY_3, "trd_03", trd_03_ENTRY_2, COLLIDER_tte2, MODEL_o10, MODEL_o11);
EvtScript N(EVS_ExitWalk_trd_03_4) = EVT_EXIT_WALK(40, trd_02_ENTRY_4, "trd_03", trd_03_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_03_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilia, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_02_ENTRY_0)
            EVT_SET(LVar2, MODEL_o6)
            EVT_SET(LVar3, MODEL_o7)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_02_ENTRY_1)
            EVT_SET(LVar2, MODEL_o9)
            EVT_SET(LVar3, MODEL_o8)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_02_ENTRY_2)
            EVT_SET(LVar2, MODEL_o13)
            EVT_SET(LVar3, MODEL_o12)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_02_ENTRY_3)
            EVT_SET(LVar2, MODEL_o10)
            EVT_SET(LVar3, MODEL_o11)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_02_ENTRY_4)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_LowerStairs) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30)
    EVT_CALL(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EVT_CALL(PlaySound, SOUND_LOOP_TRD_02_LOWER_STAIRS)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 320, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.7))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_LOOP(5)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 150)
            EVT_PLAY_EFFECT(EFFECT_DUST, 0, LVar0, LVar1, LVar2, 40)
            EVT_CALL(RandInt, 20, LVar0)
            EVT_ADD(LVar0, 20)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(7)
            EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
            EVT_CALL(RandInt, 200, LVar4)
            EVT_SUB(LVar4, 100)
            EVT_CALL(RandInt, 200, LVar5)
            EVT_SUB(LVar5, 100)
            EVT_ADD(LVar1, LVar4)
            EVT_ADD(LVar2, 200)
            EVT_ADD(LVar3, LVar5)
            EVT_PLAY_EFFECT(EFFECT_SHATTERING_STONES, 0, LVar1, LVar2, LVar3, 187)
            EVT_CALL(RandInt, 30, LVar0)
            EVT_ADD(LVar0, 30)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 187, 0, 300, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_dan, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_k_soku, 0, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_kusari, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(UpdateColliderTransform, COLLIDER_o54)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o55)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o65)
    EVT_CALL(StopSound, SOUND_LOOP_TRD_02_LOWER_STAIRS)
    EVT_CALL(PlaySound, SOUND_TRD_02_STAIRS_LOWERED)
    EVT_SET(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

BombTrigger N(D_8024240C_9A33EC) = {
    .pos = { 255.0f, 50.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(D_8024241C_9A33FC) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 17, 11, 1, 10, 30)
    EVT_CALL(EnableModel, MODEL_anaaki, TRUE)
    EVT_LOOP(10)
        EVT_CALL(SetGroupVisibility, MODEL_g14, MODEL_GROUP_VISIBLE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupVisibility, MODEL_g14, MODEL_GROUP_HIDDEN)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TRD02_BombedWall, TRUE)
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

s32 N(D_8024252C_9A350C)[] = {
    ITEM_KOOPA_FORTRESS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_IF_EQ(GF_TRD02_UnlockedDoor, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(D_80242890_9A3870)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(D_8024252C_9A350C)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_03_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_IF_EQ(GF_TRD02_BombedWall, FALSE)
        EVT_CALL(EnableModel, MODEL_anaaki, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(D_8024241C_9A33FC)), TRIGGER_POINT_BOMB, EVT_PTR(N(D_8024240C_9A33EC)), 1, 0)
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_g14, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tta, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(AF_TRD02_LowerStairs, FALSE)
    EVT_CALL(ParentColliderToModel, COLLIDER_o55, MODEL_dan)
    EVT_CALL(ParentColliderToModel, COLLIDER_o54, MODEL_k_soku)
    EVT_CALL(ParentColliderToModel, COLLIDER_o65, MODEL_kusari)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
        EVT_CALL(TranslateModel, MODEL_dan, 0, 187, 0)
        EVT_CALL(TranslateModel, MODEL_k_soku, 0, 187, 0)
        EVT_CALL(TranslateModel, MODEL_kusari, 0, 187, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o55)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o54)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o65)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Scene_LowerStairs)), TRIGGER_AREA_FLAG_SET, AF_TRD02_LowerStairs, 1, 0)
    EVT_ELSE
        EVT_CALL(UpdateColliderTransform, COLLIDER_o55)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o54)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o65)
        EVT_CALL(SetGroupVisibility, MODEL_move_saku, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
