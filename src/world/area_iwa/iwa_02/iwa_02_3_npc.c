#include "iwa_02.h"

#include "world/common/enemy/MontyMole_GroundAmbush.inc.c"
#include "world/common/enemy/MontyMole_WallAmbush.inc.c"
#include "world/common/enemy/Cleft.inc.c"
#include "world/common/npc/Bubulb.inc.c"

#include "world/common/complete/GiveReward.inc.c"

NpcData N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .pos = { 526.0f, 238.0f, 69.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 526, 238, 69 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 526, 238, 69 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .pos = { 450.0f, 50.0f, 215.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 450, 50, 215 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 450, 50, 215 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Cleft_03) = {
    .id = NPC_Cleft_03,
    .pos = { 90.0f, 0.0f, 160.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 90, 0, 160 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 90, 0, 160 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_MontyMole_01)[] = {
    {
        .id = NPC_MontyMole,
        .pos = { 867.0f, 0.0f, 101.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 867, 0, 101 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 867, 0, 101 },
                .detectSize = { 150 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_WallAmbush),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = MONTY_MOLE_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_Hole,
        .pos = { 867.0f, 0.0f, 101.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_MontyMole_WallAmbush_Hole),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DISABLE_AI | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = MONTY_MOLE_AMBUSH_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

EvtScript N(EVS_Bubulb_Conversation) = {
    EVT_IF_EQ(AF_IWA_SpokeWithBubulb, FALSE)
        EVT_SET(LVar2, LVar0)
        EVT_SET(AF_IWA_SpokeWithBubulb, TRUE)
    EVT_ELSE
        EVT_SET(LVar2, LVar1)
        EVT_SET(AF_IWA_SpokeWithBubulb, FALSE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GF_IWA02_Gift_MagicalSeed2, FALSE)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, SOUND_SPACE_DEFAULT)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_PopUp)
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_Idle)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(10.0), 0, 350, EVT_FLOAT(15.0), EVT_FLOAT(-6.5))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH2_001F)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED2)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH2_0020)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(10.0))
        EVT_SET(GF_IWA02_Gift_MagicalSeed2, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_IWA_Bubulb_Revealed)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_CH2_0021)
                EVT_SET(LVar1, MSG_CH2_0022)
            EVT_CASE_LT(STORY_CH5_HIDDEN_PASSAGE_OPEN)
                EVT_SET(LVar0, MSG_CH2_0023)
                EVT_SET(LVar1, MSG_CH2_0024)
            EVT_CASE_DEFAULT
                EVT_SET(LVar0, MSG_CH2_0025)
                EVT_SET(LVar1, MSG_CH2_0026)
        EVT_END_SWITCH
        EVT_EXEC_WAIT(N(EVS_Bubulb_Conversation))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_EQ(GF_IWA02_Gift_MagicalSeed2, FALSE)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_BuriedIdle)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_IWA_Bubulb_Hidden)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Bubulb) = {
    .id = NPC_Bubulb,
    .pos = { 1075.0f, 50.0f, 230.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Bubulb),
    .settings = &N(NpcSettings_Bubulb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = BUBULB_PURPLE_ANIMS,
    .tattle = MSG_NpcTattle_IWA_Bubulb_Revealed,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft_01), BTL_IWA_FORMATION_03, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft_02), BTL_IWA_FORMATION_01, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft_03), BTL_IWA_FORMATION_00, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_IWA_FORMATION_05, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Bubulb)),
    {}
};
