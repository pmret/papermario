#include "mac_02.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Patrol.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Bootler.inc.c"
#include "world/common/npc/Bubulb.inc.c"
#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/enemy/ShyGuy.h"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,item_choice);
#include "world/common/complete/NormalItemChoice.inc.c"

#include "npc/tayce_t.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

#include "npc/fice_t.inc.c"
#include "npc/bootler.inc.c"
#include "npc/shyguy_thief.inc.c"
#include "npc/toad_1.inc.c"
#include "npc/cooking_apprentice.inc.c"
#include "npc/toad_2.inc.c"
#include "npc/toad_kid.inc.c"
#include "npc/toad_3.inc.c"
#include "npc/toad_4.inc.c"
#include "npc/bubulb.inc.c"

AnimID N(ExtraAnims_TayceT)[] = {
    ANIM_TayceT_Still,
    ANIM_TayceT_Idle,
    ANIM_TayceT_Walk,
    ANIM_TayceT_Idle,
    ANIM_TayceT_Talk,
    ANIM_TayceT_TalkHappy,
    ANIM_TayceT_IdleSad,
    ANIM_TayceT_Cooking,
    ANIM_TayceT_TurnBack,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Bubulb)[] = {
    ANIM_Bubulb_Pink_Still,
    ANIM_Bubulb_Pink_BuriedStill,
    ANIM_Bubulb_Pink_Idle,
    ANIM_Bubulb_Pink_Talk,
    ANIM_Bubulb_Pink_PopUp,
    ANIM_Bubulb_Pink_BuriedIdle,
    ANIM_LIST_END
};

NpcData N(NpcData_TayceT)[] = {
    {
        .id = NPC_TayceT,
        .pos = { -217.0f, 20.0f, -434.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TayceT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_TayceT_Idle,
        },
        .extraAnimations = N(ExtraAnims_TayceT),
        .tattle = MSG_NpcTattle_TayceT,
    },
    {
        .id = NPC_FiceT,
        .pos = { 389.0f, 0.0f, -90.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_FiceT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_FiceT_Idle,
        },
        .tattle = MSG_NpcTattle_FiceT,
    },
    {
        .id = NPC_Bubulb,
        .pos = { 150.0f, 20.0f, 500.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bubulb),
        .settings = &N(NpcSettings_Bubulb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BUBULB_PINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Bubulb),
        .tattle = MSG_NpcTattle_MAC_Bubulb_Revealed,
    },
    {
        .id = NPC_Toad_01,
        .pos = { 40.0f, 0.0f, -60.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -50, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_HardWorker,
    },
    {
        .id = NPC_CookingApprentice,
        .pos = { -26.0f, 0.0f, -220.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_CookingApprentice),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CookingApprentice,
    },
    {
        .id = NPC_Toad_02,
        .pos = { -350.0f, 20.0f, -140.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CantKeepQuiet,
    },
    {
        .id = NPC_ToadKid,
        .pos = { 180.0f, 20.0f, -435.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 180, 20, -435 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 180, 20, -435 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_ToadKid),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_FickleDreamer,
    },
    {
        .id = NPC_Toad_03,
        .pos = { -160.0f, 0.0f, 25.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -50, 0, 0 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_03),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_PrettySmart,
    },
    {
        .id = NPC_Toad_04,
        .pos = { -80.0f, 0.0f, 300.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_04),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_PetBoaster,
    },
};

NpcData N(NpcData_Bootler) = {
    .id = NPC_Bootler,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bootler),
    .settings = &N(NpcSettings_Bootler),
    .flags = COMMON_PASSIVE_FLAGS,
    .drops = NO_DROPS,
    .animations = BOOTLER_ANIMS,
};

AnimID N(ExtraAnims_ShyGuy)[] = {
    ANIM_ShyGuy_Red_Anim00,
    ANIM_ShyGuy_Red_Anim01,
    ANIM_ShyGuy_Red_Anim02,
    ANIM_ShyGuy_Red_Anim03,
    ANIM_ShyGuy_Red_Anim11,
    ANIM_ShyGuy_Red_Anim02,
    ANIM_ShyGuy_Red_Anim04,
    ANIM_LIST_END
};

NpcData N(NpcData_ShyGuy) = {
    .id = NPC_ShyGuy,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .init = &N(EVS_NpcInit_ShyGuy),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = RED_SHY_GUY_ANIMS,
    .extraAnimations = N(ExtraAnims_ShyGuy),
};

NpcGroupList N(NpcGroup4) = {
    NPC_GROUP(N(NpcData_TayceT)),
    {}
};

NpcGroupList N(NpcGroup1) = {
    NPC_GROUP(N(NpcData_TayceT)),
    NPC_GROUP(N(NpcData_Bootler)),
    {}
};

NpcGroupList N(NpcGroup3) = {
    NPC_GROUP(N(NpcData_ShyGuy)),
    NPC_GROUP(N(NpcData_TayceT)),
    {}
};
