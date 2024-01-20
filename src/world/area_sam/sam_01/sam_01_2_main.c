#include "sam_01.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_sam_02_0) = EVT_EXIT_WALK(60, sam_01_ENTRY_0, "sam_02", sam_02_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_02_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

#include "../common/ManageSnowfall.inc.c"

EvtScript N(EVS_OpenAndCloseMayorsDoor) = {
    Call(EnableGroup, MODEL_s_naisou, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, -80, 15, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_s_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(MakeLerp, -80, 0, 15, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_s_doa, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_BASIC_DOOR_CLOSE, 0)
    Call(EnableGroup, MODEL_s_naisou, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupHerringway) = {
    IfEq(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        Call(SetNpcPos, NPC_Herringway, -202, 0, 276)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
            IfLt(LVar0, -40)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Walk)
        Call(NpcMoveTo, NPC_Herringway, -265, 275, 20 * DT)
        Exec(N(EVS_OpenAndCloseMayorsDoor))
        Wait(20 * DT)
        Call(NpcMoveTo, NPC_Herringway, -290, 157, 20 * DT)
        Wait(20 * DT)
        Thread
            Call(NpcMoveTo, NPC_Herringway, -228, 91, 20 * DT)
            Call(SetNpcAnimation, NPC_Herringway, ANIM_Herringway_Idle)
            Call(InterpNpcYaw, NPC_Herringway, 270, 0)
            Call(SetNpcFlagBits, NPC_Herringway, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EndThread
        Set(GB_StoryProgress, STORY_CH7_HERRINGWAY_AT_MAYORS_HOUSE)
        Call(BindNpcInteract, NPC_Herringway, Ref(N(EVS_NpcInteract_Herringway)))
        ExecWait(N(EVS_SetupMayorRooms))
    EndIf
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_CITY)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(MakeNpcs, FALSE, Ref(N(BeforeNPCs)))
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(MysteryNPCs)))
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(MakeNpcs, FALSE, Ref(N(AfterNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_ManageSnowfall))
    ExecWait(N(EVS_SetupRooms))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o341, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_f_noki, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_m_noki, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o398, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o399, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o402, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o408, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o409, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupHerringway))
    Return
    End
};
