#include "kpa_53.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(UpdateFollowerPosition)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Npc* npc = resolve_npc(script, npcID);
    u32 animID;

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = (s32)(((s32)playerStatus->pos.x - 700) * 0.85) + 765;
    if (playerStatus->curSpeed == 0.0f) {
        animID = ANIM_Peach1_Idle;
    } else if (playerStatus->curSpeed < 2.0f) {
        animID = ANIM_Peach1_Walk;
    } else {
        animID = ANIM_Peach1_Run;
    }
    npc->curAnim = animID;
    evt_set_variable(script, outVar, playerStatus->targetYaw);
    return ApiStatus_DONE2;
}

#include "world/common/npc/Peach.inc.c"

NpcSettings N(NpcSettings_Duplighost) = {
    .height = 30,
    .radius = 45,
    .level = 99,
};

EvtScript N(EVS_NpcAI_Duplighost_Flee) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -130)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
        EVT_IF_GE(LVar1, LVar0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 45, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 150)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, -30, 20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim02)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Duplighost_Caught) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetNpcPos, NPC_Follower, LVar2, LVar3, LVar4)
    EVT_THREAD
        EVT_ADD(LVar4, 15)
        EVT_LOOP(8)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 1, 1, 1, 1)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_Follower, SOUND_20B8, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, 1440, 20, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Follower, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_Follower, SOUND_SMOKE_BURST, SOUND_SPACE_MODE_0)
    EVT_CALL(SetNpcPos, NPC_Guardian, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Follower, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableNpcShadow, NPC_Follower, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(MakeLerp, -1440, 0, 20, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Duplighost_Anim05, ANIM_Duplighost_Anim02, 0, MSG_CH8_002D)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 700)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Duplighost_Anim04)
        EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 35)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Duplighost) = {
    EVT_CALL(RemoveNpc, NPC_Follower)
    EVT_CALL(RemoveNpc, NPC_Guardian)
    EVT_SET(GF_KPA53_Defeated_PeachImposter, TRUE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_83_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DoNpcDefeat)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Duplighost) = {
    EVT_IF_EQ(GF_KPA53_Defeated_PeachImposter, FALSE)
        EVT_IF_EQ(GF_KPA53_Met_PeachImposter, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, -120, 0, -30)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcAI_Duplighost_Flee)))
        EVT_END_IF
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Duplighost)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Follower_FirstTime) = {
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0023)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
            EVT_WAIT(1)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
            EVT_WAIT(35)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0024)
            EVT_SET(GF_KPA53_Met_PeachImposter, TRUE)
            EVT_CALL(SetSelfVar, 0, 1)
            EVT_CALL(SetSelfVar, 1, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0025)
            EVT_CALL(SetSelfVar, 0, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0026)
            EVT_CALL(SetSelfVar, 0, 1)
    EVT_END_SWITCH
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Follower) = {
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0027)
        EVT_CALL(SetSelfVar, 0, 1)
        EVT_CALL(SetSelfVar, 1, 1)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0028)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Guardian_FirstTime) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcVar, NPC_Follower, 2, 1)
            EVT_CALL(InterpNpcYaw, NPC_Follower, 270, 0)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
            EVT_CALL(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_0029)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
            EVT_CALL(SetNpcVar, NPC_Follower, 2, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Guardian) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcVar, NPC_Follower, 2, 1)
            EVT_CALL(InterpNpcYaw, NPC_Follower, 270, 0)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_RaiseArms)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_TalkIdle)
            EVT_CALL(GetSelfVar, 0, LVar1)
            EVT_SWITCH(LVar1)
                EVT_CASE_EQ(0)
                    EVT_CALL(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002A)
                    EVT_CALL(SetSelfVar, 0, 1)
                EVT_CASE_EQ(1)
                    EVT_CALL(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002B)
                    EVT_CALL(SetSelfVar, 0, 2)
                EVT_CASE_EQ(2)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_IF_LT(LVar0, 270)
                        EVT_CALL(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002B)
                    EVT_ELSE
                        EVT_CALL(SpeakToPlayer, NPC_Follower, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_CH8_002C)
                        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_CANT_INTERACT, 1)
                        EVT_CALL(BindNpcAI, NPC_Duplighost, EVT_PTR(N(EVS_NpcAI_Duplighost_Caught)))
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach2_LowerArms)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_Follower, ANIM_Peach1_Idle)
            EVT_CALL(SetNpcVar, NPC_Follower, 2, 0)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Follower) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_SWITCH(LVarF)
            EVT_CASE_EQ(0)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_LE(LVar0, 700)
                    EVT_SET(LVarF, 1)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_CALL(GetSelfVar, 2, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_SWITCH
                EVT_END_IF
                EVT_CALL(N(UpdateFollowerPosition), 0, LVar0)
                EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 0)
                EVT_CALL(GetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(InterpNpcYaw, NPC_Guardian, LVar0, 0)
                EVT_CALL(SetNpcPos, NPC_Guardian, LVar1, LVar2, LVar3)
                EVT_IF_LE(LVar1, 100)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Peach1_Idle)
                    EVT_CALL(SetNpcPos, NPC_SELF, 765, 0, -30)
                    EVT_CALL(SetNpcPos, NPC_Guardian, 765, 0, -30)
                    EVT_CALL(SetNpcPos, NPC_Duplighost, 150, 0, -30)
                    EVT_CALL(SetNpcYaw, NPC_Duplighost, 270)
                    EVT_CALL(BindNpcAI, NPC_Duplighost, EVT_PTR(N(EVS_NpcAI_Duplighost_Flee)))
                    EVT_CALL(SetSelfVar, 0, 0)
                    EVT_CALL(BindNpcInteract, NPC_Follower, EVT_PTR(N(EVS_NpcInteract_Follower)))
                    EVT_CALL(SetNpcVar, NPC_Guardian, 0, 0)
                    EVT_CALL(BindNpcHit, NPC_Guardian, EVT_PTR(N(EVS_NpcHit_Guardian)))
                    EVT_SET(LVarF, 2)
                EVT_END_IF
                EVT_IF_GE(LVar1, 765)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Peach1_Idle)
                    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_CASE_EQ(2)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_GT(LVar0, 700)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Follower) = {
    EVT_IF_EQ(GF_KPA53_Defeated_PeachImposter, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, 765, 0, -30)
        EVT_IF_EQ(GF_KPA53_Met_PeachImposter, FALSE)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Follower_FirstTime)))
        EVT_ELSE
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Follower)))
        EVT_END_IF
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Follower)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Guardian) = {
    EVT_IF_EQ(GF_KPA53_Defeated_PeachImposter, FALSE)
        EVT_CALL(SetNpcPos, NPC_SELF, 765, 0, -30)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_IF_EQ(GF_KPA53_Met_PeachImposter, FALSE)
            EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Guardian_FirstTime)))
        EVT_ELSE
            EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Guardian)))
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Imposter)[] = {
    {
        .id = NPC_Follower,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Follower),
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_USE_PLAYER_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
        .tattle = MSG_NpcTattle_KPA_FakePrincessPeach,
    },
    {
        .id = NPC_Guardian,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Guardian),
        .settings = &N(NpcSettings_Peach),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH,
        .drops = NO_DROPS,
        .animations = PEACH_ANIMS,
        .tattle = MSG_NpcTattle_KPA_FakePrincessPeach,
    },
    {
        .id = NPC_Duplighost,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Duplighost),
        .settings = &N(NpcSettings_Duplighost),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 5, 0 },
                { ITEM_MAPLE_SYRUP, 5, 0 },
                { ITEM_THUNDER_RAGE, 5, 0 },
                { ITEM_STOP_WATCH, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(5),
            .minCoinBonus = 1,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_Duplighost_Anim02,
            .walk   = ANIM_Duplighost_Anim03,
            .run    = ANIM_Duplighost_Anim04,
            .chase  = ANIM_Duplighost_Anim04,
            .anim_4 = ANIM_Duplighost_Anim02,
            .anim_5 = ANIM_Duplighost_Anim02,
            .death  = ANIM_Duplighost_Anim0A,
            .hit    = ANIM_Duplighost_Anim0A,
            .anim_8 = ANIM_Duplighost_Anim02,
            .anim_9 = ANIM_Duplighost_Anim02,
            .anim_A = ANIM_Duplighost_Anim02,
            .anim_B = ANIM_Duplighost_Anim02,
            .anim_C = ANIM_Duplighost_Anim02,
            .anim_D = ANIM_Duplighost_Anim02,
            .anim_E = ANIM_Duplighost_Anim02,
            .anim_F = ANIM_Duplighost_Anim02,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Imposter), BTL_KPA3_FORMATION_02, BTL_KPA3_STAGE_00),
    {}
};
