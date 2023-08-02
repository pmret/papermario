#include "sam_11.h"
#include "sprite/player.h"

#include "world/common/npc/Penguin_Wander.inc.c"
#include "world/common/npc/Penguin.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Kolorado.inc.c"

NpcSettings N(NpcSettings_Kooper) = {
    .height = 35,
    .radius = 24,
    .level = 6,
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
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Patrol)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00B9)
                    EVT_SET(MV_DialogueState_Patrol, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BA)
                    EVT_SET(MV_DialogueState_Patrol, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_LT(STORY_CH7_DEFEATED_JR_TROOPA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BB)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BC)
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_PenguinPatrol_Talk, ANIM_PenguinPatrol_Idle, 0, MSG_CH7_00BD)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_PenguinPatrol) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_PenguinSentry) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C7)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C8)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_IF_EQ(GF_SAM11_LeftTown, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00C9)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00CA)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00CB)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_PenguinSentry) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(N(SetInitialSentryPosition))
            EVT_LOOP(0)
                EVT_CALL(N(UpdateSentryPosition))
                EVT_WAIT(1)
            EVT_END_LOOP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Herringway) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_WAIT(30 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00CE)
            EVT_WAIT(10 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_WAIT(5 * DT)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            EVT_ADDF(LVar0, LVar3)
            EVT_ADDF(LVar1, LVar4)
            EVT_ADDF(LVar2, LVar5)
            EVT_DIVF(LVar0, EVT_FLOAT(2.0))
            EVT_DIVF(LVar1, EVT_FLOAT(2.0))
            EVT_DIVF(LVar2, EVT_FLOAT(2.0))
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.0))
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-224.0), EVT_FLOAT(-132.0))
            EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-127.0), EVT_FLOAT(-314.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(SetPlayerPos, -137, 150, -340)
            EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
            EVT_CALL(SetNpcPos, NPC_PARTNER, -170, 150, -350)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
            EVT_WAIT(10 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(20 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00CF)
            EVT_WAIT(5 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
            EVT_WAIT(30 * DT)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D0)
            EVT_WAIT(20 * DT)
            EVT_THREAD
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_LOOP(30)
                    EVT_CALL(PlayerFaceNpc, NPC_Herringway, FALSE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0 / DT))
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Walk)
            EVT_CALL(NpcMoveTo, NPC_SELF, -235, -355, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Idle)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_WAIT(20 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D1)
            EVT_WAIT(15 * DT)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(0.5))
            EVT_EXEC_WAIT(N(EVS_LowerStaircase))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D2)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Walk)
            EVT_CALL(NpcMoveTo, NPC_SELF, -215, -245, 0)
            EVT_THREAD
                EVT_CALL(NpcMoveTo, NPC_SELF, -215, -184, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Herringway_Idle)
                EVT_CALL(SetNpcPos, NPC_SELF, -217, 0, -38)
            EVT_END_THREAD
            EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_ALPHA, 0, 0, 0, 0)
            EVT_SET(GB_StoryProgress, STORY_CH7_SPOKE_WITH_HERRINGWAY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D3)
        EVT_CASE_LT(STORY_CH7_DEFEATED_JR_TROOPA)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D5)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D6)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Herringway_Talk, ANIM_Herringway_Idle, 0, MSG_CH7_00D7)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Herringway) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_02) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0096)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0097)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin2)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0098)
                    EVT_SET(MV_DialogueState_Penguin2, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_0099)
                    EVT_SET(MV_DialogueState_Penguin2, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009A)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_03) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009B)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009C)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin3)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009D)
                    EVT_SET(MV_DialogueState_Penguin3, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Celebrate, ANIM_Penguin_Idle, 0, MSG_CH7_009E)
                    EVT_SET(MV_DialogueState_Penguin3, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_009F)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_04) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A0)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A1)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_IF_EQ(GF_SAM11_UnlockedDoor, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A2)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A3)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin4)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A4)
                    EVT_SET(MV_DialogueState_Penguin4, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A5)
                    EVT_SET(MV_DialogueState_Penguin4, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A6)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_05) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A7)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A8)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00A9)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AA)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AB)
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin5)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AC)
                    EVT_SET(MV_DialogueState_Penguin5, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AD)
                    EVT_SET(MV_DialogueState_Penguin5, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Penguin_06) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00AF)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B0)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B1)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B2)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_LT(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_SWITCH(MV_DialogueState_Penguin6)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B3)
                    EVT_SET(MV_DialogueState_Penguin6, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B4)
                    EVT_SET(MV_DialogueState_Penguin6, 0)
            EVT_END_SWITCH
        EVT_CASE_GE(STORY_CH7_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Penguin_Talk, ANIM_Penguin_Idle, 0, MSG_CH7_00B5)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_01) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SHATTERED_FROZEN_POND)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00BE)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00BF)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C0)
        EVT_CASE_LT(STORY_CH7_ARRIVED_AT_STARBORN_VALLEY)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C1)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C2)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C3)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_01, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C4)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_02, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C5)
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_Toadette_03, ANIM_Toadette_Pink_Talk, ANIM_Toadette_Pink_Idle, 5, MSG_CH7_00C6)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_03) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_Toadette_01))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Toadette_02) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_Toadette_01))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PenguinPatrol) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_PenguinPatrol)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PenguinPatrol)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PenguinSentry) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_PenguinSentry)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PenguinSentry)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, 420, 0, -51)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Herringway) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Herringway)))
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Herringway)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_SPOKE_WITH_HERRINGWAY)
            EVT_CALL(SetNpcPos, NPC_SELF, -110, 150, -323)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INACTIVE, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_GE(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_CALL(SetNpcPos, NPC_SELF, -110, 150, -323)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_02) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_02)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_SAM11_LeftTown, FALSE)
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_03) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_03)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_MYSTERY)
        EVT_CASE_DEFAULT
            EVT_IF_EQ(GF_SAM11_LeftTown, FALSE)
                EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_04) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_04)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_05) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_05)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Penguin_06) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Penguin_06)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_01)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_02) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_02)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Toadette_03) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Toadette_03)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
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
    EVT_CALL(SetNpcPos, NPC_Kolorado, 140, 0, -48)
    EVT_CALL(SetNpcPos, NPC_Kooper, 75, 0, -48)
    EVT_CALL(SetNpcPos, NPC_Archeologist_01, 103, 0, -87)
    EVT_CALL(SetNpcPos, NPC_Archeologist_02, 45, 0, -87)
    EVT_CALL(SetNpcSpeed, NPC_Kolorado, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcSpeed, NPC_Kooper, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcSpeed, NPC_Archeologist_01, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcSpeed, NPC_Archeologist_02, EVT_FLOAT(2.0))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Walk)
        EVT_CALL(NpcMoveTo, NPC_Kooper, 148, -48, 0)
        EVT_CALL(NpcMoveTo, NPC_Kooper, 263, 26, 0)
        EVT_CALL(NpcMoveTo, NPC_Kooper, 308, 26, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Walk)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_01, 148, -87, 0)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_01, 263, -13, 0)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_01, 331, -13, 0)
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Walk)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_02, 148, -87, 0)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_02, 263, -13, 0)
        EVT_CALL(NpcMoveTo, NPC_Archeologist_02, 283, -13, 0)
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Idle)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Walk)
    EVT_CALL(NpcMoveTo, NPC_Kolorado, 148, -48, 0)
    EVT_CALL(NpcMoveTo, NPC_Kolorado, 263, 26, 0)
    EVT_CALL(NpcMoveTo, NPC_Kolorado, 358, 26, 0)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_Kolorado, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_Outro_0017)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_0018)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(InterpNpcYaw, NPC_Kooper, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(28)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(32)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(InterpNpcYaw, NPC_Kolorado, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcPos, NPC_Parakarry, 140, 115, 26)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_0019)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 310, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 310, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-300.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
    EVT_CALL(NpcFlyTo, NPC_Parakarry, 270, 15, 26, 50, 0, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Idle)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001A)
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_001B)
    EVT_THREAD
        EVT_CALL(DropResizableItemEntity, ITEM_LETTER_TO_KOLORADO, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(SetInvitationLetterScale))
        EVT_LOOP(20)
            EVT_CALL(GetNpcPos, NPC_Parakarry, LVar1, LVar2, LVar3)
            EVT_ADD(LVar1, 16)
            EVT_ADD(LVar2, 4)
            EVT_ADD(LVar3, 10)
            EVT_CALL(SetItemPos, LVar0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(73)
        EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_THREAD
    EVT_CALL(NpcFlyTo, NPC_Parakarry, 280, 5, 26, 20, -5, EASING_LINEAR)
    EVT_WAIT(35)
    EVT_CALL(NpcFlyTo, NPC_Parakarry, 270, 15, 26, 20, -5, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Read)
    EVT_WAIT(50)
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_Idle)
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001C)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Kooper, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_Outro_001D)
    EVT_CALL(SpeakToPlayer, NPC_Kooper, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 5, MSG_Outro_001E)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Parakarry, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Kooper, ANIM_WorldKooper_CelebrateLoop)
    EVT_CALL(InterpNpcYaw, NPC_Kooper, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcSpeed, NPC_Kooper, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_Kooper, 75, -48, 0)
    EVT_CALL(SetNpcPos, NPC_Kooper, NPC_DISPOSE_LOCATION)
    EVT_CALL(InterpNpcYaw, NPC_Parakarry, 90, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_WorldParakarry_Talk, ANIM_WorldParakarry_Idle, 5, MSG_Outro_001F)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcJumpscale, NPC_Kolorado, EVT_FLOAT(2.0))
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_Kolorado, LVar0, LVar1, LVar2, 5)
    EVT_CALL(SpeakToPlayer, NPC_Kolorado, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 5, MSG_Outro_0020)
    EVT_WAIT(10)
    EVT_CALL(SetNpcSpeed, NPC_Kolorado, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_Kolorado, 75, -48, 0)
    EVT_CALL(SetNpcPos, NPC_Kolorado, NPC_DISPOSE_LOCATION)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 325, 0, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 325, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(-450.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_WorldParakarry_Walk)
        EVT_CALL(NpcFlyTo, NPC_Parakarry, 180, 115, 26, 50, 0, EASING_LINEAR)
        EVT_CALL(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        EVT_WAIT(18)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        EVT_WAIT(8)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        EVT_WAIT(8)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        EVT_WAIT(8)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        EVT_WAIT(8)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 90, 0)
        EVT_WAIT(8)
        EVT_CALL(InterpNpcYaw, NPC_Archeologist_01, 270, 0)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_01, ANIM_Archeologist_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Archeologist_01, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_Archeologist_01, 103, -87, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EVT_WAIT(18)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    EVT_WAIT(8)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EVT_WAIT(8)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    EVT_WAIT(8)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EVT_WAIT(8)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 270, 0)
    EVT_WAIT(8)
    EVT_CALL(InterpNpcYaw, NPC_Archeologist_02, 90, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Archeologist_02, ANIM_Archeologist_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Archeologist_02, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_Archeologist_02, 45, -87, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR("kmr_20"), kmr_20_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_CALL(SetNpcPos, NPC_Parakarry, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Kooper, 120, 0, 70)
    EVT_CALL(SetNpcPos, NPC_Kolorado, 120, 0, 70)
    EVT_CALL(SetNpcPos, NPC_Archeologist_01, 120, 0, 70)
    EVT_CALL(SetNpcPos, NPC_Archeologist_02, 120, 0, 70)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Archeologist_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Archeologist_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Kooper, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Archeologist_01, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Archeologist_02, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_EpilogueDelivery)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Archeologist_01) = {
    EVT_RETURN
    EVT_END
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
