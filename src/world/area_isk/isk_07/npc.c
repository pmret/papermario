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
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            IfEq(GF_ISK07_Defeated_Mummies, FALSE)
                Thread
                    Call(N(IsLastEnemy))
                    IfEq(LVar1, TRUE)
                        Call(DisablePlayerInput, TRUE)
                        Call(PlaySound, SOUND_CHIME_SOLVED_PUZZLE)
                        Wait(30)
                        Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
                        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
                        Call(UseSettingsFrom, CAM_DEFAULT, -150, -390, 571)
                        Call(UseSettingsFrom, CAM_DEFAULT, -251, -390, 553)
                        Call(SetPanTarget, CAM_DEFAULT, -251, -390, 553)
                        Wait(1)
                        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
                        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                        Wait(45)
                        Call(MakeItemEntity, ITEM_RUINS_KEY, -250, -240, 545, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_ISK07_Item_RuinsKey)
                        Set(GF_ISK07_Defeated_Mummies, TRUE)
                        ExecWait(N(EVS_OpenEntryDoor))
                        Wait(60)
                        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                        Call(GetPlayerPos, LVar0, LVar1, LVar2)
                        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        Wait(1)
                        Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
                        Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
                        Call(DisablePlayerInput, FALSE)
                    EndIf
                EndThread
            EndIf
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(OnPlayerFled, 0)
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, TRUE)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey_01) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK07_MummiesReleased, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Call(SetNpcYaw, NPC_SELF, 105)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, FALSE)
    Call(NpcMoveTo, NPC_SELF, -140, 528, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey_02) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK07_MummiesReleased, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    Wait(15)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, FALSE)
    Call(NpcMoveTo, NPC_SELF, 47, 543, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Pokey_03) = {
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Label(1)
    IfEq(AF_ISK07_MummiesReleased, FALSE)
        Wait(1)
        Goto(1)
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, FALSE)
    Wait(15)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_IGNORE_PARTNER, FALSE)
    Call(NpcMoveTo, NPC_SELF, 227, 489, 10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_PokeyMummy)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_01) = {
    IfEq(GF_ISK07_Defeated_Mummies, FALSE)
        Call(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Pokey_01)))
    Call(InterpNpcYaw, NPC_SELF, 100, 0)
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_02) = {
    IfEq(GF_ISK07_Defeated_Mummies, FALSE)
        Call(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_02)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Pokey_01)))
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
};

EvtScript N(EVS_NpcInit_Pokey_03) = {
    IfEq(GF_ISK07_Defeated_Mummies, FALSE)
        Call(SetSelfEnemyFlags, ENEMY_FLAG_NO_DROPS)
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Pokey_03)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Pokey_01)))
    Call(SetOwnerInstigatorValue, 3)
    Return
    End
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
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
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
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
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
    .flags = ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING,
    .drops = POKEY_MUMMY_DROPS,
    .animations = POKEY_MUMMY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey_01), BTL_ISK_1_FORMATION_00, BTL_ISK_1_STAGE_0C),
    NPC_GROUP(N(NpcData_Pokey_02), BTL_ISK_1_FORMATION_02, BTL_ISK_1_STAGE_0C),
    NPC_GROUP(N(NpcData_Pokey_03), BTL_ISK_1_FORMATION_03, BTL_ISK_1_STAGE_0C),
    {}
};
