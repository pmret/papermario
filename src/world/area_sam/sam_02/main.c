#include "sam_02.h"
#include "sprite/player.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

#include "common/foliage.inc.c"

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o494, MODEL_o495);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_miki2);

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { 230.0f, 20.0f, -370.0f },
    .radius = 0.0f
};

//@bug model count is 2, but only one is supplied. the extra comma is needed.
// incidentally, the following word is 80243478, which is not a valid modelID.
FoliageModelList N(Tree2_LeafModels) = FOLIAGE_MODEL_LIST(MODEL_o186,);

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { 264.0f, 24.0f, 316.0f },
    .radius = 0.0f
};

EvtScript N(EVS_ExitWalk_sam_01_0) = EVT_EXIT_WALK(60, sam_02_ENTRY_0, "sam_01", sam_01_ENTRY_0);
EvtScript N(EVS_ExitWalk_sam_11_0) = EVT_EXIT_WALK(60, sam_02_ENTRY_1, "sam_11", sam_11_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_17_1) = {
    Call(GotoMap, Ref("tik_17"), tik_17_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_tik_17_1) = EVT_EXIT_PIPE_VERTICAL(sam_02_ENTRY_2, COLLIDER_ttd, N(EVS_GotoMap_tik_17_1));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        BindTrigger(Ref(N(EVS_ExitPipe_tik_17_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_ttd, 1, 0)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        BindTrigger(Ref(N(EVS_ExitPipe_tik_17_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_ttd, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(sam_02_ENTRY_2)
            IfEq(GF_SAM01_Visited, FALSE)
                Set(GF_SAM01_Visited, TRUE)
                Set(GB_StoryProgress, STORY_CH7_ARRIVED_AT_SHIVER_CITY)
            EndIf
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
            Wait(1)
        CaseEq(sam_02_ENTRY_3)
            Call(DisablePlayerInput, TRUE)
            Call(DisablePlayerPhysics, TRUE)
            Call(SetPlayerJumpscale, Float(1.0))
            Call(SetPlayerPos, 650, 0, 50)
            Wait(1)
            Thread
                Call(PlaySoundAtPlayer, SOUND_FALL_LONG, SOUND_SPACE_DEFAULT)
                Call(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                Call(PlayerJump1, 450, 0, 50, 30)
                Call(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
                Call(PlayerJump1, 440, 0, 50, 5)
                Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(1.0))
                Wait(30)
                Call(SetPlayerAnimation, ANIM_Mario1_DustOff)
                Wait(7)
                Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
                Wait(8)
                Call(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
                Wait(15)
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Wait(1)
                ExecWait(N(EVS_BindExitTriggers))
                Call(DisablePlayerInput, FALSE)
                Call(DisablePlayerPhysics, FALSE)
            EndThread
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_TexPan_Fire) = {
    Call(EnableTexPanning, MODEL_hi1, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   50,   50,  -70,  300)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_CITY)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_ShiverCity, TRUE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(MysteryNPCs)))
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_ManageSnowfall))
    Exec(N(EVS_TexPan_Fire))
    ExecWait(N(EVS_SetupRooms))
    ExecWait(N(EVS_SetupShop))
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_ki, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o505, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_kabe, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_tumori, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o506, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o507, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o508, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o523, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o524, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
