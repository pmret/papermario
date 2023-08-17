#include "tik_15.h"

#define RIP_CHEATO_COST 64

enum {
    CHEATO_TYPE_STAR_PIECE  = 0,
    CHEATO_TYPE_BADGE       = 1,
    CHEATO_TYPE_CONSUMABLE  = 2,
};

NpcSettings N(NpcSettings_RipCheato) = {
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

NpcSettings N(NpcSettings_Unused1) = {
    .height = 23,
    .radius = 19,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/complete/GiveReward.inc.c"

s32 N(CheatoItems)[][2] = {
    { CHEATO_TYPE_STAR_PIECE, ITEM_NONE },
    { CHEATO_TYPE_CONSUMABLE, ITEM_LIFE_SHROOM },
    { CHEATO_TYPE_BADGE,      ITEM_BUMP_ATTACK },
    { CHEATO_TYPE_CONSUMABLE, ITEM_REPEL_GEL },
    { CHEATO_TYPE_STAR_PIECE, ITEM_NONE },
    { CHEATO_TYPE_CONSUMABLE, ITEM_SUPER_SHROOM },
    { CHEATO_TYPE_CONSUMABLE, ITEM_MUSHROOM },
    { CHEATO_TYPE_CONSUMABLE, ITEM_DRIED_SHROOM },
    { CHEATO_TYPE_CONSUMABLE, ITEM_DRIED_SHROOM },
    { CHEATO_TYPE_STAR_PIECE, ITEM_NONE },
    { CHEATO_TYPE_CONSUMABLE, ITEM_DRIED_SHROOM },
    { CHEATO_TYPE_CONSUMABLE, ITEM_DRIED_SHROOM },
    { CHEATO_TYPE_CONSUMABLE, ITEM_DRIED_SHROOM },
};

API_CALLABLE(N(GetNextCheatoItem)) {
    s32* purchase = N(CheatoItems)[script->varTable[0]];

    script->varTable[10] = purchase[0];
    script->varTable[11] = purchase[1];
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckPlayerHasEnoughRoom)) {
    script->varTable[0] = get_item_empty_count();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CheckPlayerHasEnoughCoins)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.coins >= RIP_CHEATO_COST);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcInteract_RipCheato) = {
    EVT_IF_EQ(AF_TIK_02, FALSE)
        EVT_IF_EQ(GF_TIK15_Met_RipCheato, FALSE)
            EVT_SET(LVar0, MSG_MGM_0001)
            EVT_SET(GF_TIK15_Met_RipCheato, TRUE)
        EVT_ELSE
            EVT_SET(LVar0, MSG_MGM_0002)
        EVT_END_IF
        EVT_SET(AF_TIK_02, TRUE)
    EVT_ELSE
        EVT_SET(LVar0, MSG_MGM_0003)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0, LVar0)
    EVT_LABEL(0)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_0001)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0, MSG_MGM_0005)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(CheckPlayerHasEnoughCoins), LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0, MSG_MGM_0006)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, GB_TIK15_RipCheato_PurchaseCount)
    EVT_CALL(N(GetNextCheatoItem))
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(CHEATO_TYPE_STAR_PIECE)
            EVT_CALL(AddCoin, -RIP_CHEATO_COST)
            EVT_CALL(ShowCoinCounter, FALSE)
            EVT_CALL(EndSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0)
            EVT_GIVE_STAR_PIECE()
        EVT_CASE_EQ(CHEATO_TYPE_BADGE)
            EVT_CALL(AddCoin, -RIP_CHEATO_COST)
            EVT_CALL(ShowCoinCounter, FALSE)
            EVT_CALL(EndSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0)
            EVT_GIVE_BADGE_REWARD(ITEM_BUMP_ATTACK)
        EVT_CASE_EQ(CHEATO_TYPE_CONSUMABLE)
            EVT_CALL(N(CheckPlayerHasEnoughRoom))
            EVT_IF_LE(LVar0, 0)
                EVT_CALL(ShowCoinCounter, FALSE)
                EVT_CALL(ContinueSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0, MSG_MGM_0007)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(AddCoin, -RIP_CHEATO_COST)
            EVT_CALL(ShowCoinCounter, FALSE)
            EVT_CALL(EndSpeech, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0)
            EVT_GIVE_CONSUMABLE_REWARD_ALT(LVarB)
    EVT_END_SWITCH
    EVT_IF_LT(GB_TIK15_RipCheato_PurchaseCount, 10)
        EVT_ADD(GB_TIK15_RipCheato_PurchaseCount, 1)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_RipCheato, ANIM_RipCheato_Talk, ANIM_RipCheato_Idle, 0, MSG_MGM_0004)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_RipCheato) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_RipCheato)))
    EVT_SET(AF_TIK_02, FALSE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_RipCheato) = {
    .id = NPC_RipCheato,
    .pos = { -80.0f, -10.0f, 0.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_RipCheato),
    .settings = &N(NpcSettings_RipCheato),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_RipCheato_Idle,
        .walk   = ANIM_RipCheato_Idle,
        .run    = ANIM_RipCheato_Idle,
        .chase  = ANIM_RipCheato_Idle,
        .anim_4 = ANIM_RipCheato_Idle,
        .anim_5 = ANIM_RipCheato_Idle,
        .death  = ANIM_RipCheato_Idle,
        .hit    = ANIM_RipCheato_Idle,
        .anim_8 = ANIM_RipCheato_Idle,
        .anim_9 = ANIM_RipCheato_Idle,
        .anim_A = ANIM_RipCheato_Idle,
        .anim_B = ANIM_RipCheato_Idle,
        .anim_C = ANIM_RipCheato_Idle,
        .anim_D = ANIM_RipCheato_Idle,
        .anim_E = ANIM_RipCheato_Idle,
        .anim_F = ANIM_RipCheato_Idle,
    },
    .tattle = MSG_NpcTattle_RipCheato,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RipCheato), BTL_KMR_1_FORMATION_06),
    {}
};
