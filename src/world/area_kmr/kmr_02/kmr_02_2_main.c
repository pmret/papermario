#include "kmr_02.h"

#include "world/common/entity/Pipe.inc.c"

#define NAME_SUFFIX _Main
#include "world/common/npc/GoombaFamily_Wander.inc.c"
#include "wander_territories.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_ExitWalk_kmr_05_1) = EVT_EXIT_WALK(60, kmr_02_ENTRY_2, "kmr_05", kmr_05_ENTRY_1);
EvtScript N(EVS_ExitWalk_kmr_00_0) = EVT_EXIT_WALK(60, kmr_02_ENTRY_1, "kmr_00", kmr_00_ENTRY_0);
EvtScript N(EVS_ExitWalk_kmr_09_0) = EVT_EXIT_WALK(60, kmr_02_ENTRY_0, "kmr_09", kmr_09_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_SetupGoombaRoadGate) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(RotateGroup, MODEL_g197, 120, 0, -1, 0)
        EVT_CALL(RotateGroup, MODEL_g196, 120, 0, 1, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_EXEC(N(EVS_SetupGoombaRoadGate))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kmr_02_ENTRY_0)
        EVT_EXEC(N(EVS_SetupGoombaRoadGate))
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kmr_02_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_IF_EQ(GF_KMR02_ReturnedWithGoompa, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_WAIT(20 * DT)
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 4, MSG_CH0_001C)
                EVT_CALL(EnablePartnerAI)
                EVT_SET(GF_KMR02_ReturnedWithGoompa, TRUE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
        EVT_CASE_EQ(kmr_02_ENTRY_3)
            EVT_IF_EQ(GF_KMR02_WarpPipe, FALSE)
                EVT_CALL(DisablePlayerInput, TRUE)
                EVT_CALL(DisablePlayerPhysics, TRUE)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                EVT_WAIT(30)
                EVT_CALL(PlaySound, SOUND_GROW)
                EVT_SET(GF_KMR02_WarpPipe, TRUE)
                EVT_WAIT(30)
                EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
                EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
                EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                EVT_CALL(DisablePlayerPhysics, FALSE)
                EVT_CALL(DisablePlayerInput, FALSE)
            EVT_END_IF
            EVT_SET(LVarA, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC_WAIT(N(EVS_Pipe_EnterVertical))
        EVT_CASE_EQ(kmr_02_ENTRY_5)
            EVT_EXEC(N(EVS_SetWallsDown_ToadHouse))
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kmr_02_ENTRY_A)
            // beta entrance for 'post' pipe
            EVT_EXEC(EnterPostPipe)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowMessage_ItsLocked) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenGoombaRoadGate) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tt2, SOUND_GOOMBA_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 120, 20, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_g197, LVar0, 0, -1, 0)
        EVT_CALL(RotateGroup, MODEL_g196, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetMapChangeFadeSlowest)) {
    set_map_change_fade_rate(1); //normally 20
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(GetLoadType, LVar0)
    EVT_IF_EQ(LVar0, LOAD_FROM_FILE_SELECT)
        EVT_GOTO(10)
    EVT_END_IF
    // check for cutscene entry
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, kmr_02_ENTRY_4)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(EpilogueNPCs)))
    EVT_EXEC(N(EVS_FadeOutMusic))
    EVT_RETURN
    EVT_LABEL(10)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_UNUSED_FFFFFF8C)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(NpcGroup1)))
        EVT_CASE_LT(STORY_UNUSED_FFFFFF8C)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(PrologueNPCs)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_END_SWITCH
    EVT_LABEL(20)
    EVT_CALL(ClearDefeatedEnemies)
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_EXEC_WAIT(N(EVS_SetupToadHouse))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupFoliage))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_FELL_OFF_CLIFF)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShowMessage_ItsLocked)), TRIGGER_WALL_PRESS_A, COLLIDER_mm1, 1, 0)
        EVT_CASE_LT(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CASE_DEFAULT
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenGoombaRoadGate)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_END_SWITCH
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
            EVT_CALL(EnableGroup, MODEL_2, FALSE)
            EVT_CALL(EnableGroup, MODEL_4, FALSE)
        EVT_CASE_LT(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
            EVT_CALL(EnableGroup, MODEL_1, FALSE)
            EVT_CALL(EnableGroup, MODEL_4, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableGroup, MODEL_1, FALSE)
            EVT_CALL(EnableGroup, MODEL_2, FALSE)
    EVT_END_SWITCH
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_IF_NE(GB_StoryProgress, STORY_CH0_WAKE_UP)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kmr_02_ENTRY_5)
        EVT_WAIT(30)
        EVT_CALL(N(SetMapChangeFadeSlowest))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
