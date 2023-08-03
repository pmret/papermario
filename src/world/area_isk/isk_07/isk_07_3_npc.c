#include "isk_07.h"

#include "world/common/enemy/PokeyMummy.inc.c"

API_CALLABLE(N(IsLastEnemy)) {
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    s32 livingEncounters;
    s32 i, j;

    script->varTable[1] = FALSE;
    livingEncounters = 0;
    for (i = 0; i < encounterStatus->numEncounters; i++) {
        Encounter* encounter = encounterStatus->encounterList[i];
        if (encounter != NULL) {
            s32 hasEnemy = FALSE;
            for (j = 0; j < encounter->count; j++) {
                if (encounter->enemy[j] != NULL) {
                    hasEnemy = TRUE;
                }
            }
            if (hasEnemy) {
                livingEncounters++;
            }
        }
    }

    if (livingEncounters != 1) {
        return ApiStatus_DONE2;
    } else {
        script->varTable[1] = TRUE;
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_NpcDefeat_Pokey_01) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_IF_EQ(GF_ISK07_Defeated_Mummies, FALSE)
                EVT_THREAD
                    EVT_CALL(N(IsLastEnemy))
                    EVT_IF_EQ(LVar1, TRUE)
                        EVT_CALL(DisablePlayerInput, TRUE)
                        EVT_CALL(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                        EVT_WAIT(30)
                        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
                        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
                        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -150, -390, 571)
                        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -251, -390, 553)
                        EVT_CALL(SetPanTarget, CAM_DEFAULT, -251, -390, 553)
                        EVT_WAIT(1)
                        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                        EVT_WAIT(45)
                        EVT_CALL(MakeItemEntity, ITEM_RUINS_KEY, -250, -240, 545, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_ISK07_Item_RuinsKey)
                        EVT_SET(GF_ISK07_Defeated_Mummies, TRUE)
                        EVT_EXEC_WAIT(N(EVS_OpenEntryDoor))
                        EVT_WAIT(60)
                        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        EVT_WAIT(1)
                        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
                        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                        EVT_CALL(DisablePlayerInput, FALSE)
                    EVT_END_IF
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey_01) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK07_MummiesReleased, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetNpcYaw, NPC_SELF, 105)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, -140, 528, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey_02) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK07_MummiesReleased, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 47, 543, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Pokey_03) = {
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_LABEL(1)
    EVT_IF_EQ(AF_ISK07_MummiesReleased, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(15)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 227, 489, 10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, 1)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_PokeyMummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_01) = {
    EVT_IF_EQ(GF_ISK07_Defeated_Mummies, FALSE)
        EVT_CALL(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_01)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Pokey_01)))
    EVT_CALL(InterpNpcYaw, NPC_SELF, 100, 0)
    EVT_CALL(SetOwnerInstigatorValue, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_02) = {
    EVT_IF_EQ(GF_ISK07_Defeated_Mummies, FALSE)
        EVT_CALL(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_02)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Pokey_01)))
    EVT_CALL(SetOwnerInstigatorValue, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Pokey_03) = {
    EVT_IF_EQ(GF_ISK07_Defeated_Mummies, FALSE)
        EVT_CALL(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EVT_END_IF
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Pokey_03)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Pokey_01)))
    EVT_CALL(SetOwnerInstigatorValue, 3)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Pokey_01) = {
    .id = NPC_Pokey_01,
    .pos = { -132.0f, -390.0f, 492.0f },
    .yaw = 304,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -301, 0, 427 },
            .wanderSize = { 200 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -301, 0, 427 },
            .detectSize = { 400 },
        }
    },
    .init = &N(EVS_NpcInit_Pokey_01),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_800,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcData N(NpcData_Pokey_02) = {
    .id = NPC_Pokey_02,
    .pos = { 45.0f, -390.0f, 507.0f },
    .yaw = 263,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 52, -390, 573 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 52, -390, 573 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Pokey_02),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_800,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcData N(NpcData_Pokey_03) = {
    .id = NPC_Pokey_03,
    .pos = { 220.0f, -389.0f, 467.0f },
    .yaw = 244,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 243, -390, 523 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 243, -390, 523 },
            .detectSize = { 150 },
        }
    },
    .init = &N(EVS_NpcInit_Pokey_03),
    .settings = &N(NpcSettings_PokeyMummy),
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_800,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey_01), BTL_ISK_1_FORMATION_00, BTL_ISK_1_STAGE_0C),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_ISK_1_FORMATION_02, BTL_ISK_1_STAGE_0C),
    NPC_GROUP(N(NpcData_Pokey_03), BTL_ISK_1_FORMATION_03, BTL_ISK_1_STAGE_0C),
    {}
};
