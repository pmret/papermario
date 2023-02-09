#include "kzn_09.h"

#include "world/common/npc/Kolorado.inc.c"

#include "world/common/enemy/complete/PutridPiranha.inc.c"
#include "world/common/enemy/complete/SpikeTop.inc.c"

NpcSettings N(NpcSettings_Zipline) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Fallen, ANIM_Kolorado_Fallen,
    MSG_CH5_00E8, MSG_CH5_00E9, MSG_CH5_00EA, MSG_CH5_00EB,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_Scene_KoloradoFallsDown) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar6, LVar7, LVar8)
    EVT_IF_LT(LVar7, 800)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AwaitPlayerLeave, -455, -60, 85)
    EVT_CALL(GetPartnerInUse, LVar0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, SOUND_SPACE_MODE_0)
    EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(25)
    EVT_CALL(SetSelfVar, 0, 2)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
        EVT_LABEL(1)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 10)
    EVT_ADD(LVar3, 90)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Thrown)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_32C, SOUND_SPACE_MODE_0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_161, SOUND_SPACE_MODE_0)
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
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_162, SOUND_SPACE_MODE_0)
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
    EVT_LETTER_CHECK(Kolorado)
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

StaticNpc N(NpcData_PassiveNPCs)[] = {
    {
        .id = NPC_Kolorado,
        .settings = &N(NpcSettings_Kolorado),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
        .init = &N(EVS_Kolorado_Init),
        .drops = KOLORADO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy,
        .settings = &N(NpcSettings_Zipline),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
        .init = &N(EVS_Dummy_Init),
        .drops = KOLORADO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

StaticNpc N(NpcData_SpikeTop) = {
    .id = NPC_SpikeTop,
    .settings = &N(NpcSettings_SpikeTop),
    .pos = { -100.0f, 350.0f, 50.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = SPIKE_TOP_DROPS,
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
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_PutridPiranha)[] = {
    {
        .id = NPC_Piranha,
        .settings = &N(NpcSettings_PutridPiranha),
        .pos = { 200.0f, 350.0f, 100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400,
        .drops = PUTRID_PIRANHA_DROPS,
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
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox)
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PassiveNPCs)),
    NPC_GROUP(N(NpcData_SpikeTop), BTL_KZN_FORMATION_0B, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_PutridPiranha), BTL_KZN_FORMATION_0F, BTL_KZN_STAGE_01),
    {}
};
