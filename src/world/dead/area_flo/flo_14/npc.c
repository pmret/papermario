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
    IfEq(AF_FLO_BigBubbleReady, TRUE)
        Set(AF_FLO_PauseBlowingBubbles, TRUE)
        Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0063)
        Set(AF_FLO_PauseBlowingBubbles, FALSE)
        Return
    EndIf
    Set(AF_FLO_PauseBlowingBubbles, TRUE)
    IfEq(GF_FLO14_GaveBerryToBubblePlant, FALSE)
        Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_005F)
    Else
        Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0060)
    EndIf
    Call(FindItem, ITEM_BUBBLE_BERRY, LVar0)
    IfNe(LVar0, -1)
        EVT_CHOOSE_CONSUMABLE_FROM(N(KeyList), 0)
        IfEq(LVar0, -1)
            Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0064)
        Else
            Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0061)
            Set(AF_FLO_BlowingBigBubble, TRUE)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(PlayerMoveTo, 555, 110, 20)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(InterpPlayerYaw, 90, 0)
            Call(func_802CF56C, 2)
            Wait(5)
            Call(AdjustCam, CAM_DEFAULT, Float(1.0), 0, 350, Float(17.0), Float(-6.0))
            Exec(N(EVS_BlowBigBubble))
            Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH6_0062)
            Thread
                Wait(40)
                Call(InterpPlayerYaw, 315, 0)
            EndThread
            Label(10)
            IfEq(AF_FLO_BigBubbleReady, FALSE)
                Wait(1)
                Goto(10)
            EndIf
            Call(ResetCam, CAM_DEFAULT, Float(4.0))
            Call(SpeakToPlayer, NPC_SELF, -1, -1, 5, MSG_CH6_0063)
            Set(GF_FLO14_GaveBerryToBubblePlant, TRUE)
            BindTrigger(Ref(N(EVS_RideBigBubble)), TRIGGER_FLOOR_PRESS_A, COLLIDER_o154, 1, 0)
        EndIf
    EndIf
    Set(AF_FLO_PauseBlowingBubbles, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_BubbleFlower) = {
    Set(AF_FLO_BlowingBigBubble, FALSE)
    Set(AF_FLO_BigBubbleReady, FALSE)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_BubbleFlower)))
    Return
    End
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
