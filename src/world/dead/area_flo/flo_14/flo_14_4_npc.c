#include "flo_14.h"

#include "world/common/enemy/Bzzap.inc.c"

#include "world/common/npc/Bubulb.h"

NpcSettings N(NpcSettings_BubbleFlower) = {
    .height = 56,
    .radius = 40,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/Dummy.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

s32 N(KeyList)[] = {
    ITEM_BUBBLE_BERRY,
    ITEM_NONE
};

EvtScript N(EVS_NpcInteract_BubbleFlower) = {
    EVT_IF_EQ(AF_FLO_BigBubbleReady, TRUE)
        EVT_SET(AF_FLO_PauseBlowingBubbles, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0063)
        EVT_SET(AF_FLO_PauseBlowingBubbles, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_FLO_PauseBlowingBubbles, TRUE)
    EVT_IF_EQ(GF_FLO14_GaveBerryToBubblePlant, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_005F)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0060)
    EVT_END_IF
    EVT_CALL(FindItem, ITEM_BUBBLE_BERRY, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_CHOOSE_CONSUMABLE_FROM(N(KeyList), 0)
        EVT_IF_EQ(LVar0, -1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0064)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0061)
            EVT_SET(AF_FLO_BlowingBigBubble, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(PlayerMoveTo, 555, 110, 20)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(func_802CF56C, 2)
            EVT_WAIT(5)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(1.0), 0, 350, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
            EVT_EXEC(N(EVS_BlowBigBubble))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0062)
            EVT_THREAD
                EVT_WAIT(40)
                EVT_CALL(InterpPlayerYaw, 315, 0)
            EVT_END_THREAD
            EVT_LABEL(10)
            EVT_IF_EQ(AF_FLO_BigBubbleReady, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH6_0063)
            EVT_SET(GF_FLO14_GaveBerryToBubblePlant, TRUE)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_RideBigBubble)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o154, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(AF_FLO_PauseBlowingBubbles, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_BubbleFlower) = {
    EVT_SET(AF_FLO_BlowingBigBubble, FALSE)
    EVT_SET(AF_FLO_BigBubbleReady, FALSE)
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_BubbleFlower)))
    EVT_RETURN
    EVT_END
};

// uses a dummy bubulb for collision
NpcData N(NpcData_BubbleFlower) = {
    .id = NPC_BubbleFlower,
    .pos = { 617.0f, 0.0f, 108.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_BubbleFlower),
    .settings = &N(NpcSettings_BubbleFlower),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE,
    .drops = NO_DROPS,
    .animations = BUBULB_PINK_ANIMS,
    .tattle = MSG_NpcTattle_BubblePlant,
};

NpcData N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .pos = { -175.0f, 55.0f, 15.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -175, 55, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -175, 55, 15 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Bzzap),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = BZZAP_DROPS,
    .animations = BZZAP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BubbleFlower)),
    NPC_GROUP(N(NpcData_Bzzap), 0x1A19, BTL_FLO_STAGE_00),
    {}
};
