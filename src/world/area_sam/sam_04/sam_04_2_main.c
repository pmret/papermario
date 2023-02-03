#include "sam_04.h"

EvtScript N(EVS_ExitWalk_sam_03_1) = EVT_EXIT_WALK(60, sam_04_ENTRY_0, "sam_03", sam_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_sam_05_0) = EVT_EXIT_WALK(60, sam_04_ENTRY_1, "sam_05", sam_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_sam_07_0) = EVT_EXIT_WALK(60, sam_04_ENTRY_2, "sam_07", sam_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_LT(LVar0, sam_04_ENTRY_3)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common/foliage.inc.c"

EvtScript N(EVS_KnockAwayTreePart) = {
    EVT_CALL(MakeLerp, 0, 255, 20, EASING_QUARTIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVar2, FALSE)
    EVT_RETURN
    EVT_END
};

// script causes a crash if player picks up the item before it is killed
EvtScript N(EVS_TetherItemToDummyNpc) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_LetterDummy, LVar0, LVar1, LVar2)
        EVT_CALL(SetItemPos, MV_LetterItemID, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree2) = {
    EVT_SWITCH(MV_TreeHitCount)
        EVT_CASE_EQ(0)
            EVT_ADD(MV_TreeHitCount, 1)
            EVT_SET(LVar2, MODEL_ki2_1)
            EVT_EXEC_WAIT(N(EVS_KnockAwayTreePart))
        EVT_CASE_EQ(1)
            EVT_ADD(MV_TreeHitCount, 1)
            EVT_SET(LVar2, MODEL_ki2_2)
            EVT_EXEC_WAIT(N(EVS_KnockAwayTreePart))
        EVT_CASE_EQ(2)
            EVT_ADD(MV_TreeHitCount, 1)
            EVT_SET(LVar2, MODEL_ki2_3)
            EVT_EXEC_WAIT(N(EVS_KnockAwayTreePart))
        EVT_CASE_EQ(3)
            EVT_IF_EQ(GF_SAM04_Item_Letter05, FALSE)
                EVT_IF_EQ(MV_DroppedLetter, FALSE)
                    EVT_SET(MV_DroppedLetter, TRUE)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_CALL(SetNpcPos, NPC_LetterDummy, -290, 70, 110)
                    EVT_EXEC_GET_TID(N(EVS_TetherItemToDummyNpc), LVarA)
                    EVT_IF_LE(LVar0, -295)
                        EVT_SET(LVar0, -268)
                    EVT_ELSE
                        EVT_SET(LVar0, -316)
                    EVT_END_IF
                    EVT_CALL(SetNpcJumpscale, NPC_LetterDummy, EVT_FLOAT(2.0))
                    EVT_CALL(NpcJump0, NPC_LetterDummy, LVar0, 0, 141, 20)
                    EVT_KILL_THREAD(LVarA)
                    EVT_WAIT(1)
                    EVT_CALL(SetNpcPos, NPC_LetterDummy, NPC_DISPOSE_LOCATION)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki1);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki1);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -411.0f, 0.0f, 163.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki2);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .trunk = &N(Tree2_TrunkModels),
    .callback = &N(EVS_OnShakeTree2),
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki3);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki3);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 426.0f, 0.0f, -105.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree4_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki4);
FoliageModelList N(Tree4_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki4);

ShakeTreeConfig N(ShakeTree_Tree4) = {
    .leaves = &N(Tree4_LeafModels),
    .trunk = &N(Tree4_TrunkModels),
};

BombTrigger N(BombPos_Tree4) = {
    .pos = { 315.0f, 0.0f, -115.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree5_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki5);
FoliageModelList N(Tree5_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_mili5);

ShakeTreeConfig N(ShakeTree_Tree5) = {
    .leaves = &N(Tree5_LeafModels),
    .trunk = &N(Tree5_TrunkModels),
};

BombTrigger N(BombPos_Tree5) = {
    .pos = { 314.0f, 0.0f, -114.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree6_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_ki6);
FoliageModelList N(Tree6_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki6);

ShakeTreeConfig N(ShakeTree_Tree6) = {
    .leaves = &N(Tree6_LeafModels),
    .trunk = &N(Tree6_TrunkModels),
};

BombTrigger N(BombPos_Tree6) = {
    .pos = { -294.0f, 0.0f, -213.0f },
    .radius = 0.0f
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHIVER_SNOWFIELD)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_PLAY_EFFECT(EFFECT_SNOWFALL, 0, 40)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_ground, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_SNOW)
    EVT_EXEC_WAIT(N(EVS_SetupSnowmen))
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki2, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki4, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree4)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree5)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki6, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree6)), 1, 0)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
