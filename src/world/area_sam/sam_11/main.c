#include "sam_11.h"

EvtScript N(EVS_LoadPondAnimation) = {
    Call(LoadAnimatedModel, 0, Ref(N(ShatterPondSkeleton)))
    Call(PlayModelAnimation, 0, Ref(N(AS_ShatterPond)))
    Call(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    Return
    End
};

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o558);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki3);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 447.0f, 0.0f, -144.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o192);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki4);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -440.0f, 0.0f, -178.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree3_LeafModels) =  FOLIAGE_MODEL_LIST(MODEL_o190);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki5);

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { -450.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_ExitWalk_sam_02_1) = {
    IfEq(MV_ThrownOut, 1)
        Return
    EndIf
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, sam_11_ENTRY_0)
    Exec(ExitWalk)
    Call(GotoMap, Ref("sam_02"), sam_02_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_sam_03_0) = {
    SetGroup(EVT_GROUP_1B)
    IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        Return
    EndIf
    Set(GF_SAM11_LeftTown, TRUE)
    Call(UseExitHeading, 60, sam_11_ENTRY_1)
    Exec(ExitWalk)
    Call(GotoMap, Ref("sam_03"), sam_03_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_CITY)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetEntryID, LVar0)
    IfNe(LVar0, sam_11_ENTRY_2)
        Goto(10)
    EndIf
        Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
        Call(FadeInMusic, 0, SONG_SHIVER_CITY, 0, 3000, 0, 127)
        Return
    Label(10)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(MakeNpcs, FALSE, Ref(N(BeforeNPCs)))
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(MysteryNPCs)))
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(AfterNPCs)))
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o621, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    Call(SetRenderMode, MODEL_o583, RENDER_MODE_SURFACE_XLU_LAYER2)
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_ManageSnowfall))
    ExecWait(N(EVS_SetupRooms))
    ExecWait(N(EVS_SetupPond))
    ExecWait(N(EVS_SetupStaircase))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o595, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o653, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o664, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o677, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o678, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_tumori, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_g_yuki2, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suimen, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki4, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree3)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_miki5, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree3)), 1, 0)
    Call(InitAnimatedModels)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, sam_11_ENTRY_2)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Return
    End
};
