#include "omo_13.h"
#include "sprite/player.h"

#include "world/common/enemy/ShyGuy_Wander.inc.c"
#include "world/common/enemy/GrooveGuy.inc.c"

NpcSettings N(NpcSettings_AntiGuy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/complete/NormalItemChoice.inc.c"

s32 N(BribeItemList)[] = {
    ITEM_LEMON_CANDY,
    -1
};

EvtScript N(EVS_NpcInteract_AntiGuy) = {
    EVT_IF_EQ(GF_OMO13_Defeated_AntiGuy, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim15, ANIM_ShyGuy_Black_Anim15, 5, MSG_CH4_004D)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(5.0), 10, EVT_FLOAT(300.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
    EVT_CALL(FindItem, ITEM_LEMON_CANDY, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_TouchNose)
            EVT_WAIT(20)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0046)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim13, ANIM_ShyGuy_Black_Anim01, 0)
        EVT_CALL(ShowChoice, MSG_Choice_0044)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
        EVT_ELSE
            EVT_WAIT(5)
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0047)
            EVT_CALL(ShowChoice, MSG_Choice_0044)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
            EVT_ELSE
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0049)
                EVT_CALL(SetNpcVar, NPC_SELF, 0, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004A)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(30)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0)
        EVT_WAIT(15)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_JoltAwake)
        EVT_WAIT(15)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
        EVT_WAIT(15)
        EVT_CALL(EndSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0)
        EVT_SET(LVar0, EVT_PTR(N(BribeItemList)))
        EVT_SET(LVar1, -1)
        EVT_EXEC_WAIT(N(EVS_ChooseItem))
        EVT_IF_EQ(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004B)
            EVT_CALL(ShowChoice, MSG_Choice_0044)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
            EVT_ELSE
                EVT_WAIT(5)
                EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0047)
                EVT_CALL(ShowChoice, MSG_Choice_0044)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0048)
                EVT_ELSE
                    EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_0049)
                    EVT_CALL(SetNpcVar, NPC_SELF, 0, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim11, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH4_004C)
            EVT_WAIT(20)
            EVT_SET(GF_OMO13_Defeated_AntiGuy, TRUE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_he, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(SetNpcVar, NPC_SELF, 0, 2)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(UpdateAntiGuyPosition)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(NPC_AntiGuy);
    f32 theta;
    f32 x, y, z;

    dist2D(110.0f, -45.0f, playerStatus->pos.x, playerStatus->pos.z);
    theta = clamp_angle(atan2(110.0f, -45.0f, playerStatus->pos.x, playerStatus->pos.z));
    x = 110.0f + (sin_deg(theta) * 30.0f);
    if (script->varTable[11] != 0) {
        y = playerStatus->pos.y * 0.7f;
    } else {
        y = npc->pos.y;
    }
    z = -45.0f - (cos_deg(theta) * 30.0f);

    if (script->varTable[11] != 0 && npc->pos.y == 0.0f) {
        script->varTable[11] = 0;
    }

    if (npc->pos.x != x || npc->pos.y != y || npc->pos.z != z) {
        if (npc->curAnim != ANIM_ShyGuy_Black_Anim02 && script->varTable[10]++ >= 6) {
            npc->curAnim = ANIM_ShyGuy_Black_Anim02;
            script->varTable[10] = 0;
        }
        npc->pos.x = x;
        npc->pos.z = z;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.y = npc->pos.y;
        npc->colliderPos.z = npc->pos.z;
        npc->flags |= NPC_FLAG_DIRTY_SHADOW;
    } else if (npc->curAnim != ANIM_ShyGuy_Black_Anim01) {
        npc->curAnim = ANIM_ShyGuy_Black_Anim01;
    }
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_AntiGuy) = {
    EVT_LABEL(0)
        EVT_CALL(N(UpdateAntiGuyPosition))
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
            EVT_LABEL(1)
                EVT_CALL(GetSelfVar, 0, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_GOTO(0)
        EVT_ELSE
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Black_Anim02)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar2, -60)
                EVT_IF_LT(LVar0, 110)
                    EVT_ADD(LVar0, 60)
                EVT_ELSE
                    EVT_ADD(LVar0, -60)
                EVT_END_IF
            EVT_ELSE
                EVT_IF_LT(LVar0, 110)
                    EVT_ADD(LVar0, -60)
                EVT_ELSE
                    EVT_ADD(LVar0, 60)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
            EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, -100, 0)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Black_Anim15)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_LABEL(9)
                EVT_WAIT(1)
                EVT_GOTO(9)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_AntiGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_OMO13_Defeated_AntiGuy, TRUE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_he, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
            EVT_CALL(SetSelfVar, 0, 0)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_AntiGuy) = {
    EVT_IF_EQ(GF_OMO13_Defeated_AntiGuy, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_AntiGuy)))
        EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_AntiGuy)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_AntiGuy)))
    EVT_ELSE
        EVT_CALL(RemoveEncounter, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_AntiGuy) = {
    .id = NPC_AntiGuy,
    .pos = { 110.0f, 0.0f, -20.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_AntiGuy),
    .settings = &N(NpcSettings_AntiGuy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_ShyGuy_Black_Anim01,
        .walk   = ANIM_ShyGuy_Black_Anim02,
        .run    = ANIM_ShyGuy_Black_Anim03,
        .chase  = ANIM_ShyGuy_Black_Anim02,
        .anim_4 = ANIM_ShyGuy_Black_Anim01,
        .anim_5 = ANIM_ShyGuy_Black_Anim01,
        .death  = ANIM_ShyGuy_Black_Anim0C,
        .hit    = ANIM_ShyGuy_Black_Anim0C,
        .anim_8 = ANIM_ShyGuy_Black_Anim15,
        .anim_9 = ANIM_ShyGuy_Black_Anim12,
        .anim_A = ANIM_ShyGuy_Black_Anim11,
        .anim_B = ANIM_ShyGuy_Black_Anim10,
        .anim_C = ANIM_ShyGuy_Black_Anim05,
        .anim_D = ANIM_ShyGuy_Black_Anim01,
        .anim_E = ANIM_ShyGuy_Black_Anim01,
        .anim_F = ANIM_ShyGuy_Black_Anim01,
    },
    .tattle = MSG_NpcTattle_AntiGuy,
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { 300.0f, 0.0f, 50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 300, 0, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 300, 0, 50 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_ShyGuy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SHY_GUY_DROPS,
    .animations = YELLOW_SHY_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_GrooveGuy) = {
    .id = NPC_GrooveGuy,
    .pos = { -222.0f, 0.0f, 35.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -222, 0, 35 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -222, 0, 35 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_GrooveGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = GROOVE_GUY_DROPS_B,
    .animations = GROOVE_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_AntiGuy), BTL_OMO_FORMATION_2C, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_ShyGuy), BTL_OMO_FORMATION_03, BTL_OMO_STAGE_00),
    NPC_GROUP(N(NpcData_GrooveGuy), BTL_OMO_FORMATION_25, BTL_OMO_STAGE_00),
    {}
};
