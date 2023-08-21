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
    EVT_CALL(GotoMap, EVT_PTR("tik_17"), tik_17_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitPipe_tik_17_1) = EVT_EXIT_PIPE_VERTICAL(sam_02_ENTRY_2, COLLIDER_ttd, N(EVS_GotoMap_tik_17_1));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_17_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_ttd, 1, 0)
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitPipe_tik_17_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_ttd, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(sam_02_ENTRY_2)
            EVT_IF_EQ(GF_SAM01_Visited, FALSE)
                EVT_SET(GF_SAM01_Visited, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH7_ARRIVED_AT_SHIVER_CITY)
            EVT_END_IF
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
            EVT_WAIT(1)
        EVT_CASE_EQ(sam_02_ENTRY_3)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
            EVT_CALL(SetPlayerPos, 650, 0, 50)
            EVT_WAIT(1)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPlayer, SOUND_FALL_LONG, SOUND_SPACE_DEFAULT)
                EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                EVT_CALL(PlayerJump1, 450, 0, 50, 30)
                EVT_CALL(PlaySoundAtPlayer, SOUND_TRIP, SOUND_SPACE_DEFAULT)
                EVT_CALL(PlayerJump1, 440, 0, 50, 5)
                EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 3, EVT_FLOAT(1.0))
                EVT_WAIT(30)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_DustOff)
                EVT_WAIT(7)
                EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
                EVT_WAIT(8)
                EVT_CALL(PlaySoundAtPlayer, SOUND_DUST_OFF, SOUND_SPACE_DEFAULT)
                EVT_WAIT(15)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_WAIT(1)
                EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
                EVT_CALL(DisablePlayerInput, FALSE)
                EVT_CALL(DisablePlayerPhysics, FALSE)
            EVT_END_THREAD
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_TexPan_Fire) = {
    EVT_CALL(EnableTexPanning, MODEL_hi1, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   50,   50,  -70,  300)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHIVER_CITY)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_ShiverCity, TRUE)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(MysteryNPCs)))
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_ManageSnowfall))
    EVT_EXEC(N(EVS_TexPan_Fire))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_EXEC_WAIT(N(EVS_SetupShop))
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_ki, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o505, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_kabe, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_tumori, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o506, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o507, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o508, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o523, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o524, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
