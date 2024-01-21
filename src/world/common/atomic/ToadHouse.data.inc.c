#include "common.h"
#include "sprite/npc/Toad.h"

// to use this include, you must also define these
extern EvtScript N(EVS_ToadHouse_SetDialogue);
extern EvtScript N(EVS_ToadHouse_ReturnFromRest);
extern EvtScript N(EVS_ToadHouse_GetInBed);

EvtScript N(EVS_ToadHouse_Unk1) = {
    Call(EnableModel, LVar4, FALSE)
    Call(EnableModel, LVar5, TRUE)
    Call(RotateModel, LVar6, 0, 0, 0, 1)
    Call(RotateModel, LVar7, 0, 0, 0, 1)
    Return
    End
};

EvtScript N(EVS_ToadHouse_Unk2) = {
    Set(LVar9, LVar7)
    Set(LVar8, LVar6)
    Set(LVar7, LVar5)
    Set(LVar6, LVar4)
    Wait(70)
    Call(EnableModel, LVar6, FALSE)
    Thread
        Wait(5)
        Call(EnableModel, LVar6, TRUE)
    EndThread
    Call(MakeLerp, 0, 180, 20, EASING_CUBIC_IN)
    Label(1)
    Call(UpdateLerp)
    Call(RotateModel, LVar8, LVar0, 0, 0, -1)
    Call(RotateModel, LVar9, LVar0, 0, 0, -1)
    IfEq(LVar1, 1)
        Wait(1)
        Goto(1)
    EndIf
    Call(EnableModel, LVar7, FALSE)
    Return
    End
};

#ifndef TOADHOUSE_ANIM_TALK
#define TOADHOUSE_ANIM_TALK ANIM_Toad_Red_Talk
#endif

#ifndef TOADHOUSE_ANIM_IDLE
#define TOADHOUSE_ANIM_IDLE ANIM_Toad_Red_Idle
#endif

EvtScript N(EVS_NpcInteract_ToadHouseKeeper) = {
    Call(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    ExecWait(N(EVS_ToadHouse_SetDialogue))
    IfEq(LVar0, 0)
        Return
    EndIf
    Set(LVar9, LVar1)
    Set(LVarA, LVar2)
    Set(LVarB, LVar3)
    Call(N(ToadHouse_DoesPlayerNeedSleep))
    IfEq(LVar1, 0)
        Set(LVar8, LVar0)
    EndIf
    Call(SpeakToPlayer, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVar8)
    Call(ShowChoice, MSG_Choice_0006)
    Wait(3)
    IfEq(LVar0, 1)
        Call(ContinueSpeech, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVar9)
        Return
    EndIf
    Call(ContinueSpeech, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVarA)
    Call(SetPlayerJumpscale, 1)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(N(ToadHouse_DisableStatusBar))
    IfNe(LVar4, 0)
        Exec(N(EVS_ToadHouse_Unk2))
    EndIf
    Call(N(ToadHouse_PutPartnerAway), LVarA)
    Wait(20)
    ExecWait(N(EVS_ToadHouse_GetInBed))
    Thread
        Call(MakeLerp, 0, 255, 60, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        Call(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Call(FullyRestoreHPandFP)
        Call(FullyRestoreSP)
        IfNe(LVar4, 0)
            Exec(N(EVS_ToadHouse_Unk1))
        EndIf
        Call(N(ToadHouse_GetPartnerBackOut), LVarA)
        Wait(45)
        Call(MakeLerp, 255, 0, 30, EASING_LINEAR)
        Label(1)
        Call(UpdateLerp)
        Call(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    EndThread
    Wait(105)
    ExecWait(N(EVS_ToadHouse_ReturnFromRest))
    Call(DisablePlayerPhysics, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(SpeakToPlayer, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVarB)
    Call(N(ToadHouse_ShowWorldStatusBar))
    Return
    End
};
