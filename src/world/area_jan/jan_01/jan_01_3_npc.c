#include "jan_01.h"
#include "effects.h"

#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/enemy/JungleFuzzy.inc.c"
#include "world/common/npc/Kolorado.inc.c"
#include "world/common/DisableCameraLeadingPlayer.inc.c"
#include "world/common/EnableCameraLeadingPlayer.inc.c"

EvtScript N(EVS_PlayerWatchKolorado) = {
    EVT_LOOP(0)
        EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_RunToVillage) = {
    EVT_EXEC_GET_TID(N(EVS_PlayerWatchKolorado), LVar9)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.5 / DT))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 150)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, 60, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(N(EnableCameraLeadingPlayer))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
    EVT_CALL(SetSelfVar, 0, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Fallen)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -600)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_000D, 320, 60)
    EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 25, EMOTER_PLAYER, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 25, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_GT(LVar0, 430)
                    EVT_CALL(GetPartnerInUse, LVar0)
                    EVT_IF_NE(LVar0, PARTNER_NONE)
                        EVT_CALL(InterruptUsePartner)
                    EVT_END_IF
                    EVT_CALL(DisablePlayerInput, TRUE)
                    EVT_CALL(RemoveNpc, NPC_JungleFuzzy_01)
                    EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_0010, 0, 60)
                    EVT_CALL(InterpPlayerYaw, 270, 4)
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
                    EVT_CALL(NpcMoveTo, NPC_SELF, 250, 90, 5 * DT)
                    EVT_CALL(func_802CF56C, 2)
                    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                    EVT_SET(LVar3, LVar0)
                    EVT_ADD(LVar3, -50)
                    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0 / DT))
                    EVT_CALL(NpcMoveTo, NPC_SELF, LVar3, LVar2, 0)
                    EVT_ADD(LVar0, LVar3)
                    EVT_DIV(LVar0, 2)
                    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
                    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
                    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(5.0 / DT))
                    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                    EVT_CALL(N(DisableCameraLeadingPlayer))
                    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
                    EVT_WAIT(10 * DT)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0011)
                    EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
                    EVT_EXEC_WAIT(N(EVS_Kolorado_RunToVillage))
                    EVT_CALL(DisablePlayerInput, FALSE)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_SET_GROUP(EVT_GROUP_00)
                EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
                EVT_CALL(func_802D2C14, 1)
                EVT_WAIT(10 * DT)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Idle, 0, MSG_CH5_000F)
                EVT_SET(GF_JAN01_SavedKolorado, TRUE)
                EVT_CALL(SetSelfVar, 0, 2)
                EVT_SET(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
                EVT_EXEC_WAIT(N(EVS_Kolorado_RunToVillage))
                EVT_CALL(func_802D2C14, 0)
                EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
                EVT_SET_GROUP(EVT_GROUP_0B)
                EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_SWITCH
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 3)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcHit_Kolorado) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(LVar1, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_SET(LVar1, 1)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, 0)
    EVT_END_SWITCH
    EVT_IF_NE(LVar1, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_WAIT(5)
        EVT_SET(AF_JAN01_KoloradoShouting, TRUE)
        EVT_WAIT(10)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Yell, 0, MSG_CH5_000E)
        EVT_SET(AF_JAN01_KoloradoShouting, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
        EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(EVS_NpcHit_Kolorado)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_JungleFuzzy_01) = {
    EVT_CHILD_THREAD
        EVT_CALL(GetNpcPos, NPC_Kolorado, LVar3, LVar1, LVar2)
        EVT_SET(LVar4, LVar3)
        EVT_ADD(LVar3, -200)
        EVT_ADD(LVar4, 200)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar0)
                EVT_CASE_RANGE(LVar3, LVar4)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 0)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 0)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
                    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
            EVT_END_SWITCH
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(AF_JAN01_KoloradoShouting, FALSE)
    EVT_CALL(GetNpcPos, NPC_Kolorado, LVar7, LVar8, LVar9)
    EVT_ADD(LVar8, 20)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(4.0))
    EVT_SET(LVar4, 40)
    EVT_SET(LVar5, 90)
    EVT_SET(LVar6, 45)
    EVT_LOOP(0)
        EVT_MUL(LVar4, -1)
        EVT_MUL(LVar5, -1)
        EVT_MUL(LVar6, -1)
        EVT_ADD(LVar0, LVar4)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, 18, LVar2, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_Kolorado, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT)
        EVT_IF_NE(AF_JAN01_KoloradoShouting, TRUE)
            EVT_CHILD_THREAD
                EVT_CALL(InterpNpcYaw, NPC_Kolorado, LVar5, 2)
                EVT_PLAY_EFFECT(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_3, LVar7, LVar8, LVar9, 0, -1, 0, 3)
            EVT_END_CHILD_THREAD
        EVT_END_IF
        EVT_ADD(LVar0, LVar4)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, -12, LVar2, 15)
        EVT_LABEL(1)
            EVT_WAIT(1)
            EVT_IF_EQ(AF_JAN01_KoloradoShouting, TRUE)
                EVT_GOTO(1)
            EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_JungleFuzzyBoss) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
            EVT_CALL(GetPartnerInUse, LVar0)
            EVT_IF_NE(LVar0, PARTNER_NONE)
                EVT_CALL(InterruptUsePartner)
            EVT_END_IF
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(GetNpcPos, NPC_Kolorado, LVar3, LVar1, LVar2)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SET(LVar4, LVar0)
                EVT_IF_LT(LVar3, LVar0)
                    EVT_CALL(InterpPlayerYaw, 270, 0)
                    EVT_ADD(LVar4, -30)
                EVT_ELSE
                    EVT_CALL(InterpPlayerYaw, 90, 0)
                    EVT_ADD(LVar4, 30)
                EVT_END_IF
                EVT_ADD(LVar0, LVar4)
                EVT_DIV(LVar0, 2)
                EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
                EVT_CALL(N(DisableCameraLeadingPlayer))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_CALL(SetNpcFlagBits, NPC_Kolorado, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Run)
                EVT_CALL(SetNpcSpeed, NPC_Kolorado, EVT_FLOAT(3.0))
                EVT_IF_LT(LVar2, -45)
                    EVT_SET(LVar2, -45)
                EVT_END_IF
                EVT_CALL(NpcMoveTo, NPC_Kolorado, LVar4, LVar2, 0)
                EVT_CALL(SetNpcAnimation, NPC_Kolorado, ANIM_Kolorado_Idle)
                EVT_CALL(NpcFacePlayer, NPC_Kolorado, 0)
                EVT_CALL(SetNpcVar, NPC_Kolorado, 0, 1)
            EVT_END_THREAD
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JungleFuzzy_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Anim04)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JungleFuzzy_01)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_JungleFuzzyBoss)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -70.0f, -9.0f, 90.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_JungleFuzzy_01) = {
    .id = NPC_JungleFuzzy_01,
    .pos = { -30.0f, 0.0f, 90.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_JungleFuzzy_01),
    .settings = &N(NpcSettings_JungleFuzzy),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
};

EvtScript N(EVS_NpcInit_JungleFuzzy_02) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_KOLORADO_ESCAPED_FUZZIES)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_JungleFuzzy_02) = {
    .id = NPC_JungleFuzzy_02,
    .pos = { -350.0f, 3.0f, 40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -350, 3, 40 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 3, 40 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_JungleFuzzy_03) = {
    .id = NPC_JungleFuzzy_03,
    .pos = { 0.0f, -10.0f, 110.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, -10, 110 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, -10, 110 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_JungleFuzzy_04) = {
    .id = NPC_JungleFuzzy_04,
    .pos = { 350.0f, 3.0f, 40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 350, 3, 40 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 350, 3, 75 },
            .detectSize = { 200, 125 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy_02),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_JungleFuzzy_01), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_02), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_03), BTL_JAN_FORMATION_0B, BTL_JAN_STAGE_00),
    NPC_GROUP(N(NpcData_JungleFuzzy_04), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_00),
    {}
};
