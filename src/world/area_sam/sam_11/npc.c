#include "sam_11.h"
#include "sprite/player.h"

#include "world/common/npc/Penguin_Wander.inc.c"
#include "world/common/npc/Penguin.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Kolorado.inc.c"

NpcSettings N(NpcSettings_Kooper) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

API_CALLABLE(N(SetInitialSentryPosition)) {
    Npc* npc = get_npc_safe(NPC_PenguinSentry);

    npc->pos.x = 470.0f;
    npc->pos.y = 0.0f;
    npc->pos.z = 5.0f;
    script->varTableF[10] = npc->pos.z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateSentryPosition)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(NPC_PenguinSentry);
    f32* posZ = &script->varTableF[10];
    f32 playerX;
    f32 var_f2;

    if (*posZ == npc->pos.z) {
        if(npc->curAnim != ANIM_Penguin_Idle) {
            npc->curAnim = ANIM_Penguin_Idle;
        }
    }

    if (*posZ != npc->pos.z) {
        if (npc->curAnim != ANIM_Penguin_Walk) {
            npc->curAnim = ANIM_Penguin_Walk;
        }
    }

    *posZ = npc->pos.z;

    if (!(dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) < 30.0f) &&
        !(dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) > 130.0f))
    {
        playerX = var_f2 = playerStatus->pos.z;
        if (playerX > 50.0f) {
            var_f2 = 50.0f;
        }
        if (playerX < -40.0f) {
            var_f2 = -40.0f;
        }
        if (npc->pos.z <= var_f2) {
            npc->pos.z += 4.0f;
            if (npc->pos.z > var_f2) {
                npc->pos.z = var_f2;
            }
        }
        if (npc->pos.z > var_f2) {
            npc->pos.z -= 4.0f;
            if (npc->pos.z <= var_f2) {
                npc->pos.z = var_f2;
            }
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetInvitationLetterScale)) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_PenguinPatrol) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Patrol)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B9)
                    Set(MV_DialogueState_Patrol, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BA)
                    Set(MV_DialogueState_Patrol, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseLt(STORY_CH7_DEFEATED_JR_TROOPA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BB)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BC)
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BD)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_PenguinPatrol) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_PenguinSentry) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C7)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C8)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            IfEq(GF_SAM11_LeftTown, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C9)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00CA)
            EndIf
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00CB)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_PenguinSentry) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(N(SetInitialSentryPosition))
            Loop(0)
                Call(N(UpdateSentryPosition))
                Wait(1)
            EndLoop
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Herringway) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Wait(30 * DT)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00CE)
            Wait(10 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Wait(5 * DT)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            AddF(LVar0, LVar3)
            AddF(LVar1, LVar4)
            AddF(LVar2, LVar5)
            DivF(LVar0, Float(2.0))
            DivF(LVar1, Float(2.0))
            DivF(LVar2, Float(2.0))
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.0))
            Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(SetCamPosA, CAM_DEFAULT, Float(-224.0), Float(-132.0))
            Call(SetCamPosB, CAM_DEFAULT, Float(-127.0), Float(-314.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(SetPlayerPos, -137, 150, -340)
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Call(SetNpcPos, NPC_PARTNER, -170, 150, -350)
            Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            Call(NpcFacePlayer, NPC_SELF, 0)
            Wait(10 * DT)
            Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            Wait(20 * DT)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00CF)
            Wait(5 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
            Wait(30 * DT)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D0)
            Wait(20 * DT)
            Thread
                Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                Loop(30)
                    Call(PlayerFaceNpc, NPC_Herringway, FALSE)
                    Wait(1)
                EndLoop
            EndThread
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcSpeed, NPC_SELF, Float(3.0 / DT))
            Call(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Walk)
            Call(NpcMoveTo, NPC_SELF, -235, -355, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Idle)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Wait(20 * DT)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D1)
            Wait(15 * DT)
            Call(ShakeCam, CAM_DEFAULT, 0, 20, Float(0.5))
            ExecWait(N(EVS_LowerStaircase))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D2)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Walk)
            Call(NpcMoveTo, NPC_SELF, -215, -245, 0)
            Thread
                Call(NpcMoveTo, NPC_SELF, -215, -184, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Idle)
                Call(SetNpcPos, NPC_SELF, -217, 0, -38)
            EndThread
            Call(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            Set(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D3)
        CaseLt(STORY_CH7_DEFEATED_JR_TROOPA)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D5)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D6)
        CaseGe(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D7)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Herringway) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0096)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0097)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin2)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0098)
                    Set(MV_DialogueState_Penguin2, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0099)
                    Set(MV_DialogueState_Penguin2, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009A)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009B)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009C)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin3)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009D)
                    Set(MV_DialogueState_Penguin3, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Celebrate, ANIM_Penguin_Idle, 0, MSG_CH7_009E)
                    Set(MV_DialogueState_Penguin3, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009F)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A0)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A1)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            IfEq(GF_SAM11_UnlockedDoor, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A2)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A3)
            EndIf
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin4)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A4)
                    Set(MV_DialogueState_Penguin4, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A5)
                    Set(MV_DialogueState_Penguin4, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A6)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A7)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A8)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A9)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AA)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AB)
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin5)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AC)
                    Set(MV_DialogueState_Penguin5, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AD)
                    Set(MV_DialogueState_Penguin5, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AF)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B0)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B1)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B2)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseLt(STORY_CH7_STAR_SPIRIT_RESCUED)
            Switch(MV_DialogueState_Penguin6)
                CaseEq(0)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B3)
                    Set(MV_DialogueState_Penguin6, 1)
                CaseEq(1)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B4)
                    Set(MV_DialogueState_Penguin6, 0)
            EndSwitch
        CaseGe(STORY_CH7_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B5)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SHATTERED_FROZEN_POND)
            Call(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00BE)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00BF)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C0)
        CaseLt(STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
            Call(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C1)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C2)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C3)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C4)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C5)
            Wait(10)
            Call(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C6)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_03) = {
    ExecWait(N(EVS_NpcInteract_Toadette_01))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    ExecWait(N(EVS_NpcInteract_Toadette_01))
    Return
    End
};

EvtScript N(EVS_NpcInit_PenguinPatrol) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_PenguinPatrol)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PenguinPatrol)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(RemoveNpc, NPC_SELF)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_PenguinSentry) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_PenguinSentry)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PenguinSentry)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, 420, 0, -51)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Herringway) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Herringway)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Herringway)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            Call(SetNpcPos, NPC_SELF, -110, 150, -323)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        CaseGe(STORY_CH7_MAYOR_MURDER_SOLVED)
            Call(SetNpcPos, NPC_SELF, -110, 150, -323)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_02)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseDefault
            IfEq(GF_SAM11_LeftTown, FALSE)
                Call(RemoveNpc, NPC_SELF)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_03)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH7_MAYOR_MURDER_MYSTERY)
        CaseDefault
            IfEq(GF_SAM11_LeftTown, FALSE)
                Call(RemoveNpc, NPC_SELF)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_05)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Penguin_06)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    IfLt(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_01)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    IfLt(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_02)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Toadette_03) = {
    IfLt(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toadette_03)))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_PenguinPatrol,
        .pos = { -275.0f, 0.0f, 100.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_PenguinPatrol),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_PATROL_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Patrol,
    },
    {
        .id = NPC_PenguinSentry,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 180,
        .init = &N(EVS_NpcInit_PenguinSentry),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Gatekeeper,
    },
    {
        .id = NPC_Herringway,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Herringway),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = HERRINGWAY_ANIMS,
        .tattle = MSG_NpcTattle_Herringway,
    },
    {
        .id = NPC_Penguin_04,
        .pos = { 200.0f, 0.0f, -110.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_04),
        .settings = &N(NpcSettings_Penguin),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_WarehouseGuard,
    },
    {
        .id = NPC_Penguin_05,
        .pos = { -200.0f, 0.0f, -110.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Penguin_05),
        .settings = &N(NpcSettings_Penguin),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_HerringwayLoiterer,
    },
    {
        .id = NPC_Penguin_06,
        .pos = { 330.0f, 0.0f, 300.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 320, 0, 280 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_06),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_TimidPenguin,
    },
};

NpcData N(NpcData_PondPenginsBefore)[] = {
    {
        .id = NPC_Penguin_02,
        .pos = { -100.0f, -10.0f, 180.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -100, -10, 180 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_02),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_SnowMaster,
    },
    {
        .id = NPC_Penguin_03,
        .pos = { 57.0f, -10.0f, 194.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 57, -10, 194 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_03),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Skater,
    },
};

NpcData N(NpcData_PondPenginsAfter)[] = {
    {
        .id = NPC_Penguin_02,
        .pos = { -323.0f, 0.0f, 160.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -323, 0, 160 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_02),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_SnowMaster,
    },
    {
        .id = NPC_Penguin_03,
        .pos = { 363.0f, 0.0f, 213.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 363, 0, 213 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Penguin_03),
        .settings = &N(NpcSettings_Penguin_Wander),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = PENGUIN_ANIMS,
        .tattle = MSG_NpcTattle_SAM_Skater,
    },
};

NpcData N(NpcData_Tourists)[] = {
    {
        .id = NPC_Toadette_01,
        .pos = { -400.0f, 0.0f, 230.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidA,
    },
    {
        .id = NPC_Toadette_02,
        .pos = { -350.0f, 0.0f, 230.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidB,
    },
    {
        .id = NPC_Toadette_03,
        .pos = { -375.0f, 0.0f, 220.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = TOADETTE_PINK_ANIMS,
        .tattle = MSG_NpcTattle_TravelingMaidC,
    },
};

EvtScript N(EVS_Scene_EpilogueDelivery) = {
    Call(SetNpcPos, NPC_Kolorado, 140, 0, -48)
    Call(SetNpcPos, NPC_Kooper, 75, 0, -48)
    Call(SetNpcPos, NPC_Archeologist_01, 103, 0, -87)
    Call(SetNpcPos, NPC_Archeologist_02, 45, 0, -87)
    Call(SetNpcSpeed, NPC_Kolorado, Float(2.0))
    Call(SetNpcSpeed, NPC_Kooper, Float(2.0))
    Call(SetNpcSpeed, NPC_Archeologist_01, Float(2.0))
    Call(SetNpcSpeed, NPC_Archeologist_02, Float(2.0))
    Thread
        Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Walk)
        Call(NpcMoveTo, NPC_Kooper, 148, -48, 0)
        Call(NpcMoveTo, NPC_Kooper, 263, 26, 0)
        Call(NpcMoveTo, NPC_Kooper, 308, 26, 0)
        Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Walk)
        Call(NpcMoveTo, NPC_Archeologist_01, 148, -87, 0)
        Call(NpcMoveTo, NPC_Archeologist_01, 263, -13, 0)
        Call(NpcMoveTo, NPC_Archeologist_01, 331, -13, 0)
        Call(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Idle)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Walk)
        Call(NpcMoveTo, NPC_Archeologist_02, 148, -87, 0)
        Call(NpcMoveTo, NPC_Archeologist_02, 263, -13, 0)
        Call(NpcMoveTo, NPC_Archeologist_02, 283, -13, 0)
        Call(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Idle)
    EndThread
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Walk)
    Call(NpcMoveTo, NPC_Kolorado, 148, -48, 0)
    Call(NpcMoveTo, NPC_Kolorado, 263, 26, 0)
    Call(NpcMoveTo, NPC_Kolorado, 358, 26, 0)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
    Wait(30)
    Call(InterpNpcYaw, NPC_Kolorado, 270, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_Outro_0017)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_0018)
    Thread
        Wait(25)
        Call(InterpNpcYaw, NPC_Kooper, 270, 0)
    EndThread
    Thread
        Wait(28)
        Call(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
    EndThread
    Thread
        Wait(32)
        Call(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    EndThread
    Thread
        Wait(35)
        Call(InterpNpcYaw, NPC_Kolorado, 270, 0)
    EndThread
    Call(SetNpcSpeed, NPC_Parakarry, Float(3.0))
    Call(SetNpcPos, NPC_Parakarry, 140, 115, 26)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0019)
    Thread
        Wait(20)
        Call(UseSettingsFrom, CAM_DEFAULT, 310, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 310, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, Float(-300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    Call(NpcFlyTo, NPC_Parakarry, 270, 15, 26, 50, 0, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    Wait(20)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001A)
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_001B)
    Thread
        Call(DropResizableItemEntity, ITEM_LETTER_TO_KOLORADO, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        Call(N(SetInvitationLetterScale))
        Loop(20)
            Call(GetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
            Add(LVar1, 16)
            Add(LVar2, 4)
            Add(LVar3, 10)
            Call(SetItemPos, LVar0, LVar1, LVar2, LVar3)
            Wait(1)
        EndLoop
        Wait(73)
        Call(RemoveItemEntity, LVar0)
    EndThread
    Call(NpcFlyTo, NPC_Parakarry, 280, 5, 26, 20, -5, EASING_LINEAR)
    Wait(35)
    Call(NpcFlyTo, NPC_Parakarry, 270, 15, 26, 20, -5, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_Parakarry, 90, 0)
    Wait(30)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Read)
    Wait(50)
    Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    Wait(30)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001C)
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Kooper, 90, 0)
    EndThread
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_Outro_001D)
    Call(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001E)
    Wait(20)
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Parakarry, 270, 0)
    EndThread
    Call(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_CelebrateLoop)
    Call(InterpNpcYaw, NPC_Kooper, 270, 0)
    Wait(10)
    Call(SetNpcSpeed, NPC_Kooper, Float(8.0))
    Call(NpcMoveTo, NPC_Kooper, 75, -48, 0)
    Call(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
    Call(InterpNpcYaw, NPC_Parakarry, 90, 0)
    Wait(30)
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        Call(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EndThread
    Call(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_001F)
    Wait(10)
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    Call(SetNpcJumpscale, NPC_Kolorado, Float(2.0))
    Call(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 5)
    Call(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 5, MSG_Outro_0020)
    Wait(10)
    Call(SetNpcSpeed, NPC_Kolorado, Float(8.0))
    Call(NpcMoveTo, NPC_Kolorado, 75, -48, 0)
    Call(SetNpcPos, NPC_Kolorado, NPC_DISPOSE_LOCATION)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 325, 0, 0)
        Call(SetPanTarget, CAM_DEFAULT, 325, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, Float(-450.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
        Call(NpcFlyTo, NPC_Parakarry, 180, 115, 26, 50, 0, EASING_LINEAR)
        Call(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(10)
        Call(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        Wait(18)
        Call(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        Wait(8)
        Call(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        Wait(8)
        Call(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        Wait(8)
        Call(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        Wait(8)
        Call(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        Wait(8)
        Call(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        Wait(30)
        Call(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Walk)
        Call(SetNpcSpeed, NPC_Archeologist_01, Float(2.0))
        Call(NpcMoveTo, NPC_Archeologist_01, 103, -87, 0)
    EndThread
    Wait(10)
    Call(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    Wait(18)
    Call(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    Wait(8)
    Call(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    Wait(8)
    Call(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    Wait(8)
    Call(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    Wait(8)
    Call(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    Wait(8)
    Call(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    Wait(30)
    Thread
        Call(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Walk)
        Call(SetNpcSpeed, NPC_Archeologist_02, Float(2.0))
        Call(NpcMoveTo, NPC_Archeologist_02, 45, -87, 0)
    EndThread
    Wait(30)
    Call(FadeOutMusic, 0, 1000)
    Call(GotoMap, Ref("kmr_20"), kmr_20_ENTRY_3)
    Wait(100)
    Return
    End
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_NpcInit_Kolorado) = {
    Call(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_Kooper, 120, 0, 70)
    Call(SetNpcPos, NPC_Kolorado, 120, 0, 70)
    Call(SetNpcPos, NPC_Archeologist_01, 120, 0, 70)
    Call(SetNpcPos, NPC_Archeologist_02, 120, 0, 70)
    Call(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Archeologist_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Archeologist_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Archeologist_01, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_Archeologist_02, NPC_FLAG_GRAVITY, FALSE)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Scene_EpilogueDelivery)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Archeologist_01) = {
    Return
    End
};

NpcData N(NpcData_Epilogue)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
    },
    {
        .id = NPC_Archeologist_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Archeologist_01),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ARCHEOLOGIST_ANIMS,
    },
    {
        .id = NPC_Archeologist_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Archeologist_01),
        .settings = &N(NpcSettings_Kolorado),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = ARCHEOLOGIST_ANIMS,
    },
    {
        .id = NPC_Kooper,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Archeologist_01),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
    {
        .id = NPC_Parakarry,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Archeologist_01),
        .settings = &N(NpcSettings_Kooper),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 0.0f, 0.0f, -150.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_SAM, QUIZ_COUNT_SAM, QUIZ_MAP_SAM_11 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(BeforeNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_PondPenginsBefore), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Tourists), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(MysteryNPCs) = {
    //@bug loads 7 NPCs when the group only has 6
    NPC_GROUP_EXPLICIT_SIZE(N(NpcData_Townsfolk), NPC_PenguinPatrol, 7, BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Tourists), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_PondPenginsAfter), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_Tourists), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Epilogue), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
