#include "MBush.h"
#include "sprite/player.h"

EvtScript N(EVS_NpcAI_MBush) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim00)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SEARCH_BUSH, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetSelfVar, 10, LVar0)
    EVT_CALL(SetSelfVar, 11, LVar1)
    EVT_CALL(SetSelfVar, 12, LVar2)
    EVT_ADD(LVar0, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar0, 3)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar0, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SUB(LVar0, 3)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_ADD(LVar0, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim03)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(6)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 25)
    EVT_SUB(LVar2, 5)
    EVT_CALL(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 15)
    EVT_WAIT(4)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim07)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBattle)
}; // fallthrough :(

EvtScript N(EVS_NpcInteract_MBush) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_MBush) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim05)
            EVT_CALL(GetSelfVar, 10, LVar0)
            EVT_CALL(GetSelfVar, 11, LVar1)
            EVT_CALL(GetSelfVar, 12, LVar2)
            EVT_CALL(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 8)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim00)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MBush)))
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_MBush) = {
    .height = 30,
    .radius = 30,
    .level = ACTOR_LEVEL_M_BUSH,
    .onInteract = &N(EVS_NpcInteract_MBush),
    .ai = &N(EVS_NpcAI_MBush),
    .onDefeat = &N(EVS_NpcDefeat_MBush),
};

#define MBUSH_NPC_DATA \
    .settings = &N(NpcSettings_MBush), \
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000, \
    .drops = MBUSH_DROPS, \
    .animations = MBUSH_ANIMS, \
    .tattle = MSG_NpcTattle_MBush, \
