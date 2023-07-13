#include "common.h"
#include "sprite/npc/Toad.h"

// to use this include, you must also define these
extern EvtScript N(EVS_ToadHouse_SetDialogue);
extern EvtScript N(EVS_ToadHouse_ReturnFromRest);
extern EvtScript N(EVS_ToadHouse_GetInBed);

EvtScript N(EVS_ToadHouse_Unk1) = {
    EVT_CALL(EnableModel, LVar4, FALSE)
    EVT_CALL(EnableModel, LVar5, TRUE)
    EVT_CALL(RotateModel, LVar6, 0, 0, 0, 1)
    EVT_CALL(RotateModel, LVar7, 0, 0, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_Unk2) = {
    EVT_SET(LVar9, LVar7)
    EVT_SET(LVar8, LVar6)
    EVT_SET(LVar7, LVar5)
    EVT_SET(LVar6, LVar4)
    EVT_WAIT(70)
    EVT_CALL(EnableModel, LVar6, FALSE)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnableModel, LVar6, TRUE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, EASING_CUBIC_IN)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, LVar8, LVar0, 0, 0, -1)
    EVT_CALL(RotateModel, LVar9, LVar0, 0, 0, -1)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, LVar7, FALSE)
    EVT_RETURN
    EVT_END
};

#ifndef TOADHOUSE_ANIM_TALK
#define TOADHOUSE_ANIM_TALK ANIM_Toad_Red_Talk
#endif

#ifndef TOADHOUSE_ANIM_IDLE
#define TOADHOUSE_ANIM_IDLE ANIM_Toad_Red_Idle
#endif

EvtScript N(EVS_NpcInteract_ToadHouseKeeper) = {
    EVT_CALL(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_ToadHouse_SetDialogue))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVarA, LVar2)
    EVT_SET(LVarB, LVar3)
    EVT_CALL(N(ToadHouse_DoesPlayerNeedSleep))
    EVT_IF_EQ(LVar1, 0)
        EVT_SET(LVar8, LVar0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVar8)
    EVT_CALL(ShowChoice, MSG_Choice_0006)
    EVT_WAIT(3)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ContinueSpeech, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVar9)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ContinueSpeech, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVarA)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(N(ToadHouse_DisableStatusBar))
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC(N(EVS_ToadHouse_Unk2))
    EVT_END_IF
    EVT_CALL(N(ToadHouse_PutPartnerAway), LVarA)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(EVS_ToadHouse_GetInBed))
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(FullyRestoreHPandFP)
        EVT_CALL(FullyRestoreSP)
        EVT_IF_NE(LVar4, 0)
            EVT_EXEC(N(EVS_ToadHouse_Unk1))
        EVT_END_IF
        EVT_CALL(N(ToadHouse_GetPartnerBackOut), LVarA)
        EVT_WAIT(45)
        EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(105)
    EVT_EXEC_WAIT(N(EVS_ToadHouse_ReturnFromRest))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_SELF, TOADHOUSE_ANIM_TALK, TOADHOUSE_ANIM_IDLE, 0, LVarB)
    EVT_CALL(N(ToadHouse_ShowWorldStatusBar))
    EVT_RETURN
    EVT_END
};
