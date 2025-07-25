#include "kkj_25.h"

EvtScript N(EVS_ExitDoors_kkj_24_1) = EVT_EXIT_DOUBLE_DOOR(kkj_25_ENTRY_0, "kkj_24", kkj_24_ENTRY_1, COLLIDER_ttw, MODEL_o84, MODEL_o85);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_24_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_25_ENTRY_0)
            IfEq(GF_KKJ25_Visited, false)
                Call(DisablePlayerInput, true)
                Call(SetPlayerPos, -645, 0, 0)
#if VERSION_JP
                Call(SetNpcPos, NPC_PARTNER, -645, 0, 0)
#else
                Call(GetPartnerInUse, LVar0)
                IfEq(LVar0, 0)
                    Call(DisablePartnerAI, 0)
                    Call(SetNpcPos, NPC_PARTNER, -660, 0, 0)
                    Wait(1)
                    Call(EnablePartnerAI)
                EndIf
#endif
                Wait(150)
                Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_LARGE_DOOR_OPEN, 0)
                Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
                Loop(0)
                    Call(UpdateLerp)
                    Call(RotateModel, MODEL_o84, LVar0, 0, -1, 0)
                    Call(RotateModel, MODEL_o85, LVar0, 0, 1, 0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
                Call(SetPlayerPos, -605, 0, 0)
#if VERSION_JP
                Call(SetNpcPos, NPC_PARTNER, -605, 0, 0)
#endif
                Call(DisablePlayerInput, false)
                Call(SetZoneEnabled, ZONE_o15, false)
                Call(ResetCam, CAM_DEFAULT, Float(90.0))
                Set(GF_KKJ25_Visited, true)
            Else
                Call(SetZoneEnabled, ZONE_o15, false)
                Call(ResetCam, CAM_DEFAULT, Float(90.0))
            EndIf
            Set(LVar0, 0)
            Set(LVar2, MODEL_o84)
            Set(LVar3, MODEL_o85)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_Scene_BowserTrapsMario))
        CaseEq(kkj_25_ENTRY_1)
            Exec(N(EVS_Scene_KammyDefeated))
        CaseEq(kkj_25_ENTRY_2)
            Exec(N(EVS_Scene_BowserDefeated))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Rotate_Propellers) = {
    Thread
        Set(LVar2, 0)
        Loop(0)
            Add(LVar2, 10)
            Call(RotateGroup, MODEL_g3, LVar2, 0, 1, 0)
            Call(RotateGroup, MODEL_g12, LVar2, 0, 1, 0)
            Call(RotateGroup, MODEL_g14, LVar2, 0, 1, 0)
            Call(RotateGroup, MODEL_g16, LVar2, 0, 1, 0)
            Call(RotateGroup, MODEL_g18, LVar2, 0, 1, 0)
            Wait(1)
        EndLoop
    EndThread
    Set(LVar2, 90)
    Loop(0)
        Add(LVar2, 10)
        Call(RotateGroup, MODEL_g11, LVar2, 0, 1, 0)
        Call(RotateGroup, MODEL_g13, LVar2, 0, 1, 0)
        Call(RotateGroup, MODEL_g15, LVar2, 0, 1, 0)
        Call(RotateGroup, MODEL_g17, LVar2, 0, 1, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(1)
            Set(GF_KKJ25_Defeated_Kammy, true)
        CaseEq(2)
            Set(GF_KKJ25_Defeated_Kammy, true)
            Set(GF_KKJ25_Defeated_Bowser, true)
    EndSwitch
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_25)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.75))
    IfEq(GF_KKJ25_Defeated_Bowser, false)
        IfEq(GF_KKJ25_Defeated_Kammy, false)
            Call(MakeNpcs, false, Ref(N(InitialNpcs)))
        Else
            Call(MakeNpcs, false, Ref(N(MidpointNpcs)))
            Call(EnableGroup, MODEL_g30, false)
        EndIf
    Else
        Call(MakeNpcs, false, Ref(N(FinaleNpcs)))
        Call(EnableGroup, MODEL_g30, false)
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Exec(N(EVS_EnterMap))
    Call(ParentColliderToModel, COLLIDER_o128, MODEL_o1)
    Exec(N(EVS_Rotate_Propellers))
    Call(GetEntryID, LVar0)
    Thread
        Set(MV_ArenaState, ARENA_STATE_IDLE)
        IfEq(LVar0, kkj_25_ENTRY_0)
            Call(EnableModel, MODEL_o122, false)
            Loop(0)
                Wait(1)
                IfEq(MV_ArenaState, ARENA_STATE_ACTIVATING)
                    BreakLoop
                EndIf
            EndLoop
        Else
            Call(ScaleModel, MODEL_o122, 250, 1, 250)
        EndIf
        Exec(N(EVS_ManageArenaEffects))
    EndThread
    Return
    End
};
