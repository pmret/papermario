#include "sam_04.h"

EvtScript N(EVS_ExitWalk_sam_03_1) = EVT_EXIT_WALK(60, sam_04_ENTRY_0, "sam_03", sam_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_sam_05_0) = EVT_EXIT_WALK(60, sam_04_ENTRY_1, "sam_05", sam_05_ENTRY_0);
EvtScript N(EVS_ExitWalk_sam_07_0) = EVT_EXIT_WALK(60, sam_04_ENTRY_2, "sam_07", sam_07_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_07_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    IfLt(LVar0, sam_04_ENTRY_3)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
    EndIf
    Return
    End
};

#include "common/foliage.inc.c"

EvtScript N(EVS_KnockAwayTreePart) = {
    Call(MakeLerp, 0, 255, 20, EASING_QUARTIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, LVar2, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, LVar2, FALSE)
    Return
    End
};

// script causes a crash if player picks up the item before it is killed
EvtScript N(EVS_TetherItemToDummyNpc) = {
    Loop(0)
        Call(GetNpcPos, NPC_LetterDummy, LVar0, LVar1, LVar2)
        Call(SetItemPos, MV_LetterItemID, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_OnShakeTree2) = {
    Switch(MV_TreeHitCount)
        CaseEq(0)
            Add(MV_TreeHitCount, 1)
            Set(LVar2, MODEL_ki2_1)
            ExecWait(N(EVS_KnockAwayTreePart))
        CaseEq(1)
            Add(MV_TreeHitCount, 1)
            Set(LVar2, MODEL_ki2_2)
            ExecWait(N(EVS_KnockAwayTreePart))
        CaseEq(2)
            Add(MV_TreeHitCount, 1)
            Set(LVar2, MODEL_ki2_3)
            ExecWait(N(EVS_KnockAwayTreePart))
        CaseEq(3)
            IfEq(GF_SAM04_Item_Letter05, FALSE)
                IfEq(MV_DroppedLetter, FALSE)
                    Set(MV_DroppedLetter, TRUE)
                    Call(GetPlayerPos, LVar0, LVar1, LVar2)
                    Call(SetNpcPos, NPC_LetterDummy, -290, 70, 110)
                    ExecGetTID(N(EVS_TetherItemToDummyNpc), LVarA)
                    IfLe(LVar0, -295)
                        Set(LVar0, -268)
                    Else
                        Set(LVar0, -316)
                    EndIf
                    Call(SetNpcJumpscale, NPC_LetterDummy, Float(2.0))
                    Call(NpcJump0, NPC_LetterDummy, LVar0, 0, 141, 20)
                    KillThread(LVarA)
                    Wait(1)
                    Call(SetNpcPos, NPC_LetterDummy, NPC_DISPOSE_LOCATION)
                EndIf
            EndIf
    EndSwitch
    Return
    End
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
    Set(GB_WorldLocation, LOCATION_SHIVER_SNOWFIELD)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    PlayEffect(EFFECT_SNOWFALL, 0, 40)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_ground, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_SNOW)
    ExecWait(N(EVS_SetupSnowmen))
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki1, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki2, 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki3, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree4)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki4, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree4)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree5)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki5, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree5)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree6)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki6, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree6)), 1, 0)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
