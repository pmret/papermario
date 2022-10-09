#include "iwa_00.h"
#include "effects.h"

EvtScript N(EVS_NpcAuxAI_MontyMole_01) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_02) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim12)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_802408AC_90D4EC) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_01) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
        EVT_ADD(LVar5, 30)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetNpcPos, LVar0, 0, -1000, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
        EVT_CALL(BasicAI_Main, EVT_PTR(N(D_802408AC_90D4EC)))
        EVT_RETURN
        EVT_END
};

NpcSettings N(NpcSettings_MontyMole_01) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_01),
    .ai = &N(EVS_NpcAI_MontyMole_01),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_02) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_02),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

EvtScript N(EVS_NpcAuxAI_MontyMole_03) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_04) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim13)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80240C9C_90D8DC) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_03) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 130)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_ADD(LVar3, 50)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_SUB(LVar2, 30)
        EVT_ADD(LVar3, 80)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar1, LVar2, LVar3, 20)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_END_IF
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80240C9C_90D8DC)))
    EVT_RETURN
    EVT_END
};

EvtScript N(missing_80240F64_F64) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/complete/MontyMole.inc.c"

NpcSettings N(NpcSettings_MontyMole_03) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_03),
    .ai = &N(EVS_NpcAI_MontyMole_03),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_04) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_04),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_Whacka_01) = {
    .height = 30,
    .radius = 26,
    .level = 99,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(func_80240118_90CD58)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 20;
    }
    if (script->functionTemp[1] & 1) {
        npc->flags &= ~NPC_FLAG_2;
    } else {
        npc->flags |= NPC_FLAG_2;
    }
    if (script->functionTemp[1] == 15) {
        sfx_play_sound_at_position(SOUND_DEATH, 0, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z);
        fx_damage_stars(1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0.0f, -1.0f, 0.0f, 10);
    }
    
    temp = script->functionTemp[1];
    if (script->functionTemp[1] == 10) {
        fx_big_smoke_puff(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        // odd logic needed to match
        if (script->functionTemp[1] == temp) {
            spawn_drops(enemy);
        }
    }
    
    script->functionTemp[1]--;
    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

StaticNpc N(NpcData_MontyMole_01)[] = {
    {
        .id = NPC_MontyMole_01,
        .settings = &N(NpcSettings_MontyMole_01),
        .pos = { 880.0f, 70.0f, 67.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = MONTY_MOLE_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 880, 70, 67 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 880, 70, 67 },
                .detectSize = { 120 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_02,
        .settings = &N(NpcSettings_MontyMole_02),
        .pos = { 880.0f, 70.0f, 67.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 880, 70, 67 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
    },
};

StaticNpc N(NpcData_MontyMole_03)[] = {
    {
        .id = NPC_MontyMole_03,
        .settings = &N(NpcSettings_MontyMole_03),
        .pos = { 1220.0f, -30.0f, 70.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = MONTY_MOLE_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 1220, -30, 70 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 1220, -30, 70 },
                .detectSize = { 120 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_04,
        .settings = &N(NpcSettings_MontyMole_04),
        .pos = { 1220.0f, -30.0f, 70.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 1220, -30, 70 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
    },
};

EvtScript N(EVS_NpcInteract_Whacka_01) = {
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar0, LVar3)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_ELSE
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_END_IF
    EVT_SWITCH(GB_IWA00_Whacka_HitCount)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(GF_IWA00_Met_Whacka, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0027)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0028)
            EVT_END_IF
        EVT_CASE_LE(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0028)
        EVT_CASE_LE(4)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_0029)
        EVT_CASE_LE(6)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002A)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002B)
    EVT_END_SWITCH
    EVT_SET(GF_IWA00_Met_Whacka, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Whacka_01) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Idle)
    EVT_CALL(GetNpcPos, NPC_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetNpcPos, NPC_Whacka_01, 0, -1000, 0)
    EVT_CALL(SetNpcPos, NPC_Whacka_02, 0, -1000, 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GE(LVar1, 20)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_LT(LVar0, 600)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_GT(LVar0, 850)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Whacka_01, LVarA, LVarB, LVarC)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Whacka_PopUp)
    EVT_WAIT(15)
    EVT_CALL(SetNpcPos, NPC_Whacka_02, LVarA, LVarB, LVarC)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Idle)
    EVT_WAIT(30)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, 900)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Whacka_Burrow)
    EVT_CALL(SetNpcPos, NPC_Whacka_02, 0, -1000, 0)
    EVT_WAIT(15)
    EVT_CALL(SetNpcPos, NPC_Whacka_01, 0, -1000, 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Whacka_02) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVarA, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVarA, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetCurrentPartnerID, LVar2)
            EVT_IF_EQ(LVar2, PARTNER_KOOPER)
                EVT_SET(LVarA, 2)
            EVT_ELSE
                EVT_SET(LVarA, 3)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_SET(LVarA, 0)
    EVT_END_SWITCH
    EVT_IF_EQ(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(BindNpcInteract, NPC_Whacka_01, 0)
    EVT_CALL(EnableNpcAI, NPC_Whacka_01, FALSE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar0, LVar3)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_SET(LVarB, 0)
    EVT_ELSE
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_SET(LVarB, 1)
    EVT_END_IF
    EVT_ADD(GB_IWA00_Whacka_HitCount, 1)
    EVT_IF_EQ(LVarA, 3)
        EVT_ADD(GB_IWA00_Whacka_HitCount, 1)
    EVT_END_IF
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(PlaySoundAtNpc, NPC_Whacka_01, SOUND_HIT_PLAYER_NORMAL, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(1)
            EVT_CALL(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Hurt)
            EVT_WAIT(15)
            EVT_CALL(GetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_IF_EQ(LVarB, 0)
                EVT_ADD(LVar0, 14)
            EVT_ELSE
                EVT_SUB(LVar0, 14)
            EVT_END_IF
            EVT_ADD(LVar1, 30)
            EVT_ADD(LVar2, 2)
            EVT_CALL(MakeItemEntity, ITEM_WHACKAS_BUMP, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, 0)
            EVT_CALL(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Idle)
            EVT_WAIT(5)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(3)
            EVT_CALL(GetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_SUB(LVar0, 2)
            EVT_CALL(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 2)
            EVT_CALL(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_SUB(LVar0, 1)
            EVT_CALL(SetNpcPos, NPC_Whacka_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_LT(GB_IWA00_Whacka_HitCount, 8)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(1)
                EVT_CALL(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002C)
            EVT_CASE_EQ(2)
                EVT_CALL(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002D)
            EVT_CASE_EQ(3)
                EVT_CALL(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002E)
        EVT_END_SWITCH
        EVT_CALL(SetNpcAnimation, NPC_Whacka_01, ANIM_Whacka_Burrow)
        EVT_WAIT(15)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Whacka_01, ANIM_Whacka_Talk, ANIM_Whacka_Idle, 0, MSG_CH2_002F)
        EVT_WAIT(2)
    EVT_END_IF
    EVT_IF_GE(GB_IWA00_Whacka_HitCount, 8)
        EVT_CALL(N(func_80240118_90CD58))
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_Whacka_01, 0, -1000, 0)
    EVT_CALL(SetNpcPos, NPC_Whacka_02, 0, -1000, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_Whacka_01)
    EVT_CALL(RemoveNpc, NPC_Whacka_02)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Whacka_01) = {
    EVT_CALL(SetNpcVar, NPC_Whacka_01, 8, 0)
    EVT_IF_LT(GB_IWA00_Whacka_HitCount, 8)
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Whacka_01)))
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Whacka_01)))
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_200000, TRUE)
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Whacka_02) = {
    EVT_IF_LT(GB_IWA00_Whacka_HitCount, 8)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Whacka_02)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Whacka_01)[] = {
    {
        .id = NPC_Whacka_01,
        .settings = &N(NpcSettings_Whacka_01),
        .pos = { 725.0f, -30.0f, 225.0f },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_400000,
        .init = &N(EVS_NpcInit_Whacka_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Whacka_Idle,
            .walk   = ANIM_Whacka_Idle,
            .run    = ANIM_Whacka_Idle,
            .chase  = ANIM_Whacka_Idle,
            .anim_4 = ANIM_Whacka_Idle,
            .anim_5 = ANIM_Whacka_Idle,
            .death  = ANIM_Whacka_Idle,
            .hit    = ANIM_Whacka_Idle,
            .anim_8 = ANIM_Whacka_Idle,
            .anim_9 = ANIM_Whacka_Idle,
            .anim_A = ANIM_Whacka_Idle,
            .anim_B = ANIM_Whacka_Idle,
            .anim_C = ANIM_Whacka_Idle,
            .anim_D = ANIM_Whacka_Idle,
            .anim_E = ANIM_Whacka_Idle,
            .anim_F = ANIM_Whacka_Idle,
        },
        .tattle = MSG_NpcTattle_Whacka,
    },
    {
        .id = NPC_Whacka_02,
        .settings = &N(NpcSettings_Whacka_01),
        .pos = { 725.0f, -30.0f, 225.0f },
        .yaw = 90,
        .flags = NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_4000 | NPC_FLAG_MOTION_BLUR | NPC_FLAG_200000 | NPC_FLAG_400000 | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS,
        .init = &N(EVS_NpcInit_Whacka_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Whacka_Idle,
            .walk   = ANIM_Whacka_Idle,
            .run    = ANIM_Whacka_Idle,
            .chase  = ANIM_Whacka_Idle,
            .anim_4 = ANIM_Whacka_Idle,
            .anim_5 = ANIM_Whacka_Idle,
            .death  = ANIM_Whacka_Idle,
            .hit    = ANIM_Whacka_Idle,
            .anim_8 = ANIM_Whacka_Idle,
            .anim_9 = ANIM_Whacka_Idle,
            .anim_A = ANIM_Whacka_Idle,
            .anim_B = ANIM_Whacka_Idle,
            .anim_C = ANIM_Whacka_Idle,
            .anim_D = ANIM_Whacka_Idle,
            .anim_E = ANIM_Whacka_Idle,
            .anim_F = ANIM_Whacka_Idle,
        },
        .tattle = MSG_NpcTattle_Whacka,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_IWA_FORMATION_06, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_03), BTL_IWA_FORMATION_07, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Whacka_01)),
    {}
};
