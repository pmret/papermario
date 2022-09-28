#include "kzn_09.h"

extern EvtScript D_800936DC;

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

EvtScript N(D_80244B7C_C7B85C) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(func_80045900, 1)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80244C38_C7B918) = {
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 150.0f,
    .playerSearchInterval = 1,
};

EvtScript N(D_80244C68_C7B948) = {
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(SetSelfVar, 8, 10)
    EVT_CALL(SetSelfVar, 9, 9)
    EVT_CALL(SetSelfVar, 10, 12)
    EVT_CALL(SetSelfVar, 11, 7)
    EVT_CALL(SetSelfVar, 12, 30)
    EVT_CALL(SetSelfVar, 13, 15)
    EVT_CALL(SetSelfVar, 14, 18)
    EVT_CALL(SetSelfVar, 15, 15)
    EVT_CALL(N(PiranhaPlantAI_Main), EVT_PTR(N(D_80244C38_C7B918)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(D_80244D3C_C7BA1C) = {
    .height = 50,
    .radius = 36,
    .level = 17,
    .ai = &N(D_80244C68_C7B948),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(D_80244D68_C7BA48) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfVar, 0, 14)
    EVT_CALL(SetSelfVar, 1, 28)
    EVT_CALL(SetSelfVar, 4, 3)
    EVT_CALL(SetSelfVar, 15, SOUND_20DE)
    EVT_CALL(N(MeleeHitbox_Main))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80244DE8) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(D_800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(D_80244E74_C7BB54) = {
    .height = 20,
    .radius = 28,
    .level = 17,
    .ai = &N(D_80244D68_C7BA48),
    .onDefeat = &N(D_80244B7C_C7B85C),
};

MobileAISettings N(D_80244EA0_C7BB80) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 4.5f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80244ED0_C7BBB0) = {
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80244EA0_C7BB80)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80244F40_C7BC20) = {
    .moveSpeed = 1.0f,
    .moveTime = 60,
    .waitTime = 60,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 7.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80244F70_C7BC50) = {
    EVT_CALL(SetSelfVar, 2, 4)
    EVT_CALL(SetSelfVar, 3, 10)
    EVT_CALL(SetSelfVar, 5, 4)
    EVT_CALL(SetSelfVar, 7, 3)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80244F40_C7BC20)))
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_80244FE0_C7BCC0) = {
    .moveSpeed = 1.0f,
    .moveTime = 20,
    .waitTime = 5,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80245010_C7BCF0) = {
    EVT_CALL(SetSelfVar, 2, 3)
    EVT_CALL(SetSelfVar, 3, 8)
    EVT_CALL(SetSelfVar, 5, 6)
    EVT_CALL(SetSelfVar, 7, 6)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80244FE0_C7BCC0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245080_C7BD60) = {
    EVT_CALL(N(func_80240814_97BE44))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim0F)
    EVT_CALL(N(AwaitPlayerNearNpc))
    EVT_CALL(SyncOverrideEnemyPos, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_BuzzyBeetle_Anim00)
    EVT_CALL(N(func_802408B4_97BEE4))
    EVT_CALL(SyncOverrideEnemyPos, 0)
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 2)
    EVT_CALL(SetSelfVar, 5, 5)
    EVT_CALL(SetSelfVar, 7, 2)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(D_80244EA0_C7BB80)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(80245174) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(D_80244ED0_C7BBB0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(802451A0) = {
    .height = 20,
    .radius = 22,
    .level = 10,
    .ai = &N(D_80245080_C7BD60),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(D_802451CC_C7BEAC) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(D_80244F70_C7BC50),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(802451F8) = {
    .height = 24,
    .radius = 24,
    .level = 25,
    .ai = &N(D_80245010_C7BCF0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_Dummy) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/atomic/LetterChoice.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER25,
    ITEM_NONE 
};

EvtScript N(D_80245B64_C7C844) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Fallen, ANIM_Kolorado_Fallen,
        ITEM_LETTER25, 0,
        MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BB4_C7C894) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_SET(LVar0, ITEM_STAR_PIECE)
        EVT_SET(LVar1, 3)
        EVT_EXEC_WAIT(N(Delivery_ShowGotStarPiece))
        EVT_CALL(AddStarPieces, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

// END LETTER DELIVERY?

EvtScript N(EVS_Scene_KoloradoFallsDown) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar6, LVar7, LVar8)
    EVT_IF_LT(LVar7, 800)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerLeave, -455, -60, 85)
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, TRUE)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.0), 0, 400, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetSelfVar, 1, 1)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
            EVT_CALL(GetSelfVar, 1, LVar0)
            EVT_IF_NE(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_WAIT(30)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.0))
        EVT_ADD(LVar0, 20)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, FALSE)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 0)
        EVT_CALL(NpcFacePlayer, NPC_PARTNER, 0)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_SELF, -500, 870, -15)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -425, -15, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 3)
    EVT_WAIT(5)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 3)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, TRUE, 0, 0, 0, 0)
    EVT_WAIT(25)
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
        EVT_LABEL(1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
        EVT_CALL(NpcJump0, NPC_SELF, -410, 870, -15, 10)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 1)
            EVT_WAIT(15)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_00F4)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_LABEL(2)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -310, 870, -15)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -310, 870, -15)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, -390, -15, 0)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.5))
    EVT_SET(LVar3, -350)
    EVT_SET(LVar4, 870)
    EVT_SET(LVar5, -15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
    EVT_ADD(LVar3, 90)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Thrown)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_THREAD
        EVT_LABEL(3)
        EVT_CALL(ShowSweat, NPC_SELF, 1, -45, 1, 0, 0, 0, 0, 20)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(25)
            EVT_GOTO(3)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_LOOP(10)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_SUB(LVar4, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(20)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_SUBF(LVar3, EVT_FLOAT(0.6))
        EVT_ADDF(LVar4, EVT_FLOAT(1.5))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(10)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_SUBF(LVar3, EVT_FLOAT(1.0))
        EVT_SUB(LVar4, 2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(3.0))
    EVT_CALL(NpcJump0, NPC_SELF, LVar3, 700, LVar5, 5)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_161, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 1, 0)
    EVT_WAIT(5)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_THREAD
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_ShockStill)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_Running)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4.0))
        EVT_CALL(PlayerMoveTo, -360, 0, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_1000C)
        EVT_LABEL(5)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_END_THREAD
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00F5, 160, 40)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_162, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(7.0))
    EVT_WAIT(10)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_FELL_IN_PIT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_Interact) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Fallen, ANIM_Kolorado_Fallen, 0, MSG_CH5_00F6)
    EVT_EXEC_WAIT(N(D_80245B64_C7C844))
    EVT_EXEC_WAIT(N(D_80245BB4_C7C894))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_Init) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_KOLORADO_FELL_IN_PIT)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Scene_KoloradoFallsDown)))
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_Kolorado_Interact)))
            EVT_RETURN
        EVT_CASE_LT(STORY_CH5_KOLORADO_AT_DEAD_END)
            EVT_CALL(SetNpcPos, NPC_SELF, -270, 375, -15)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_Kolorado_Interact)))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncZiplineDummyNPC) = {
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_kassya_koma)
        EVT_CALL(SetNpcPos, NPC_ZiplineDummy, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dummy_Init) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2, TRUE)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.3), 1, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

StaticNpc N(PassiveNPCs)[] = {
    {
        .id = NPC_Kolorado,
        .settings = &N(NpcSettings_Kolorado),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR | NPC_FLAG_400000,
        .init = &N(EVS_Kolorado_Init),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Kolorado_Idle,
            .walk   = ANIM_Kolorado_Walk,
            .run    = ANIM_Kolorado_Run,
            .chase  = ANIM_Kolorado_Run,
            .anim_4 = ANIM_Kolorado_Idle,
            .anim_5 = ANIM_Kolorado_Idle,
            .death  = ANIM_Kolorado_Idle,
            .hit    = ANIM_Kolorado_Idle,
            .anim_8 = ANIM_Kolorado_Idle,
            .anim_9 = ANIM_Kolorado_Idle,
            .anim_A = ANIM_Kolorado_Idle,
            .anim_B = ANIM_Kolorado_Idle,
            .anim_C = ANIM_Kolorado_Idle,
            .anim_D = ANIM_Kolorado_Idle,
            .anim_E = ANIM_Kolorado_Idle,
            .anim_F = ANIM_Kolorado_Idle,
        },
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy,
        .settings = &N(NpcSettings_Dummy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(EVS_Dummy_Init),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Kolorado_Idle,
            .walk   = ANIM_Kolorado_Walk,
            .run    = ANIM_Kolorado_Run,
            .chase  = ANIM_Kolorado_Run,
            .anim_4 = ANIM_Kolorado_Idle,
            .anim_5 = ANIM_Kolorado_Idle,
            .death  = ANIM_Kolorado_Idle,
            .hit    = ANIM_Kolorado_Idle,
            .anim_8 = ANIM_Kolorado_Idle,
            .anim_9 = ANIM_Kolorado_Idle,
            .anim_A = ANIM_Kolorado_Idle,
            .anim_B = ANIM_Kolorado_Idle,
            .anim_C = ANIM_Kolorado_Idle,
            .anim_D = ANIM_Kolorado_Idle,
            .anim_E = ANIM_Kolorado_Idle,
            .anim_F = ANIM_Kolorado_Idle,
        },
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

StaticNpc N(EnemyNPC_SpikeTop) = {
    .id = NPC_SpikeTop,
    .settings = &N(D_802451CC_C7BEAC),
    .pos = { -100.0f, 350.0f, 50.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SODA, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(4),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -100, 350, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -100, 350, 50 },
            .detectSize = { 200 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikeTop_Anim03,
        .walk   = ANIM_SpikeTop_Anim06,
        .run    = ANIM_SpikeTop_Anim08,
        .chase  = ANIM_SpikeTop_Anim08,
        .anim_4 = ANIM_SpikeTop_Anim03,
        .anim_5 = ANIM_SpikeTop_Anim03,
        .death  = ANIM_SpikeTop_Anim13,
        .hit    = ANIM_SpikeTop_Anim13,
        .anim_8 = ANIM_SpikeTop_Anim0B,
        .anim_9 = ANIM_SpikeTop_Anim0A,
        .anim_A = ANIM_SpikeTop_Anim0C,
        .anim_B = ANIM_SpikeTop_Anim03,
        .anim_C = ANIM_SpikeTop_Anim03,
        .anim_D = ANIM_SpikeTop_Anim03,
        .anim_E = ANIM_SpikeTop_Anim03,
        .anim_F = ANIM_SpikeTop_Anim03,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(EnemyNPC_PutridPiranha)[] = {
    {
        .id = NPC_PutridPiranha,
        .settings = &N(D_80244D3C_C7BA1C),
        .pos = { 200.0f, 350.0f, 100.0f },
        .yaw = 270,
        .flags = NPC_FLAG_LOCK_ANIMS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 200, 350, 100 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 10, 350, 25 },
                .detectSize = { 220, 165 },
            }
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_PutridPiranha_Hitbox,
        .settings = &N(D_80244E74_C7BB54),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_DROPS,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_LargePiranha_Putrid_Anim01,
            .walk   = ANIM_LargePiranha_Putrid_Anim02,
            .run    = ANIM_LargePiranha_Putrid_Anim03,
            .chase  = ANIM_LargePiranha_Putrid_Anim03,
            .anim_4 = ANIM_LargePiranha_Putrid_Anim01,
            .anim_5 = ANIM_LargePiranha_Putrid_Anim01,
            .death  = ANIM_LargePiranha_Putrid_Anim0E,
            .hit    = ANIM_LargePiranha_Putrid_Anim0E,
            .anim_8 = ANIM_LargePiranha_Putrid_Anim18,
            .anim_9 = ANIM_LargePiranha_Putrid_Anim17,
            .anim_A = ANIM_LargePiranha_Putrid_Anim05,
            .anim_B = ANIM_LargePiranha_Putrid_Anim06,
            .anim_C = ANIM_LargePiranha_Putrid_Anim07,
            .anim_D = ANIM_LargePiranha_Putrid_Anim01,
            .anim_E = ANIM_LargePiranha_Putrid_Anim01,
            .anim_F = ANIM_LargePiranha_Putrid_Anim01,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(PassiveNPCs)),
    NPC_GROUP(N(EnemyNPC_SpikeTop), BTL_KZN_FORMATION_0B, BTL_KZN_STAGE_01),
    NPC_GROUP(N(EnemyNPC_PutridPiranha), BTL_KZN_FORMATION_0F, BTL_KZN_STAGE_01),
    {}
};
