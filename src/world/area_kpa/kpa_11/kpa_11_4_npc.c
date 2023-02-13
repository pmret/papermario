#include "kpa_11.h"

#include "world/common/enemy/Koopatrol_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcDefeat_Koopatrol) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_KPA11_Defeated_Guard, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA11_Item_CastleKey2)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_SET(GF_KPA11_Defeated_Guard, TRUE)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, GF_KPA11_Item_CastleKey2)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Koopatrol) = {
    EVT_IF_EQ(GF_KPA11_Defeated_Guard, FALSE)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Koopatrol)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { 550.0f, 30.0f, -145.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_40000 | ENEMY_FLAG_NO_DROPS,
    .init = &N(EVS_NpcInit_Koopatrol),
    .drops = NPC_NO_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 550, 30, -145 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 550, 30, -145 },
            .detectSize = { 200 },
        }
    },
    .animations = KOOPATROL_ANIMS,
};

EvtScript N(EVS_NpcInit_Prisoner) = {
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Prisoners)[] = {
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 845.0f, 30.0f, -285.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Prisoner),
        .drops = TOAD_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadA,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 872.0f, 30.0f, -315.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Prisoner),
        .drops = TOAD_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveToadB,
    },
    {
        .id = NPC_ToadGuard,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 900.0f, 30.0f, -285.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Prisoner),
        .drops = TOAD_DROPS,
        .animations = TOAD_GUARD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_KPA_CaptiveSoldierA,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Koopatrol), BTL_KPA_FORMATION_18, BTL_KPA_STAGE_02),
    NPC_GROUP(N(NpcData_Prisoners), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_02),
    {}
};
