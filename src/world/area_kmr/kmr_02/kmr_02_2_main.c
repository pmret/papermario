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
    IfGe(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        Call(RotateGroup, MODEL_g197, 120, 0, -1, 0)
        Call(RotateGroup, MODEL_g196, 120, 0, 1, 0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_05_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Exec(N(EVS_SetupGoombaRoadGate))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_02_ENTRY_0)
        Exec(N(EVS_SetupGoombaRoadGate))
    EndIf
    Switch(LVar0)
        CaseEq(kmr_02_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            IfEq(GF_KMR02_ReturnedWithGoompa, FALSE)
                Call(DisablePlayerInput, TRUE)
                Wait(20 * DT)
                Call(DisablePartnerAI, 0)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 4, MSG_CH0_001C)
                Call(EnablePartnerAI)
                Set(GF_KMR02_ReturnedWithGoompa, TRUE)
                Call(DisablePlayerInput, FALSE)
            EndIf
        CaseEq(kmr_02_ENTRY_3)
            IfEq(GF_KMR02_WarpPipe, FALSE)
                Call(DisablePlayerInput, TRUE)
                Call(DisablePlayerPhysics, TRUE)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
                Wait(30)
                Call(PlaySound, SOUND_GROW)
                Set(GF_KMR02_WarpPipe, TRUE)
                Wait(30)
                Call(SetPlayerActionState, ACTION_STATE_IDLE)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
                Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
                Call(DisablePlayerPhysics, FALSE)
                Call(DisablePlayerInput, FALSE)
            EndIf
            Set(LVarA, Ref(N(EVS_BindExitTriggers)))
            ExecWait(N(EVS_Pipe_EnterVertical))
        CaseEq(kmr_02_ENTRY_5)
            Exec(N(EVS_SetWallsDown_ToadHouse))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kmr_02_ENTRY_A)
            // beta entrance for 'post' pipe
            Exec(EnterPostPipe)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ShowMessage_ItsLocked) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OpenGoombaRoadGate) = {
    Call(DisablePlayerInput, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_tt2, SOUND_GOOMBA_GATE_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 120, 20, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g197, LVar0, 0, -1, 0)
        Call(RotateGroup, MODEL_g196, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

API_CALLABLE(N(SetMapChangeFadeSlowest)) {
    set_map_change_fade_rate(1); //normally 20
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(GetLoadType, LVar0)
    IfEq(LVar0, LOAD_FROM_FILE_SELECT)
        Goto(10)
    EndIf
    // check for cutscene entry
    Call(GetEntryID, LVar0)
    IfNe(LVar0, kmr_02_ENTRY_4)
        Goto(10)
    EndIf
    Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
    Exec(N(EVS_FadeOutMusic))
    Return
    Label(10)
    Switch(GB_StoryProgress)
        CaseEq(STORY_UNUSED_FFFFFF8C)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup1)))
        CaseLt(STORY_UNUSED_FFFFFF8C)
            Call(MakeNpcs, FALSE, Ref(N(PrologueNPCs)))
        CaseDefault
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndSwitch
    Label(20)
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_SetupRooms))
    ExecWait(N(EVS_SetupToadHouse))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupFoliage))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_FELL_OFF_CLIFF)
            BindTrigger(Ref(N(EVS_ShowMessage_ItsLocked)), TRIGGER_WALL_PRESS_A, COLLIDER_mm1, 1, 0)
        CaseLt(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        CaseDefault
            BindTrigger(Ref(N(EVS_OpenGoombaRoadGate)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EndSwitch
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_GATE_CRUSHED)
            Call(EnableGroup, MODEL_2, FALSE)
            Call(EnableGroup, MODEL_4, FALSE)
        CaseLt(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
            Call(EnableGroup, MODEL_1, FALSE)
            Call(EnableGroup, MODEL_4, FALSE)
        CaseDefault
            Call(EnableGroup, MODEL_1, FALSE)
            Call(EnableGroup, MODEL_2, FALSE)
    EndSwitch
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o757, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Wait(1)
    IfNe(GB_StoryProgress, STORY_CH0_WAKE_UP)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_02_ENTRY_5)
        Wait(30)
        Call(N(SetMapChangeFadeSlowest))
    EndIf
    Return
    End
};
