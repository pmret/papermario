#include "sam_01.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_sam_02_0) = EVT_EXIT_WALK(60, sam_01_ENTRY_0, "sam_02", sam_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sam_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_OpenAndCloseMayorsDoor) = {
    EVT_CALL(EnableGroup, MODEL_s_naisou, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, -80, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_s_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, -80, 0, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, MODEL_s_doa, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_CALL(EnableGroup, MODEL_s_naisou, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupHerringway) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        EVT_CALL(SetNpcPos, NPC_Herringway, -202, 0, 276)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_LT(LVar0, -40)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Walk)
        EVT_CALL(NpcMoveTo, NPC_Herringway, -265, 275, 20 * DT)
        EVT_EXEC(N(EVS_OpenAndCloseMayorsDoor))
        EVT_WAIT(20 * DT)
        EVT_CALL(NpcMoveTo, NPC_Herringway, -290, 157, 20 * DT)
        EVT_WAIT(20 * DT)
        EVT_THREAD
            EVT_CALL(NpcMoveTo, NPC_Herringway, -228, 91, 20 * DT)
            EVT_CALL(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Idle)
            EVT_CALL(InterpNpcYaw, NPC_Herringway, 270, 0)
            EVT_CALL(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_END_THREAD
        EVT_SET(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
        EVT_CALL(BindNpcInteract, NPC_Herringway, EVT_PTR(N(EVS_NpcInteract_Herringway)))
        EVT_EXEC_WAIT(N(EVS_SetupMayorRooms))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHIVER_CITY)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(BeforeNPCs)))
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(MysteryNPCs)))
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(AfterNPCs)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_ManageSnowfall))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o341, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_f_noki, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_m_noki, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o398, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o399, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o402, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o408, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o409, SURFACE_TYPE_SNOW)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupHerringway))
    EVT_RETURN
    EVT_END
};
