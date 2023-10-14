#include "mac_04.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_ChetRippo) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/GoombaFamily.inc.c"
#include "world/common/npc/StarSpirit.inc.c"
#include "world/common/npc/Twink.inc.c"
#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_choice);
#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(EVS_TossTrainInToybox) = {
    EVT_CALL(FacePlayerTowardPoint, -440, -150, 0)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(7)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_ADD(LVar3, 50)
        EVT_SETF(LVar5, 3)
        EVT_CALL(MakeItemEntity, ITEM_TOY_TRAIN, LVar2, LVar3, LVar4, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(LVar7, LVar0)
        EVT_CALL(MakeLerp, LVar4, -150, 30, EASING_CUBIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetItemPos, LVar7, -440, LVar3, LVar0)
            EVT_ADDF(LVar5, EVT_FLOAT(-0.5))
            EVT_ADD(LVar3, LVar5)
            EVT_IF_LT(LVar3, 0)
                EVT_SET(LVar3, 0)
            EVT_END_IF
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LVar7)
    EVT_END_THREAD
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_TakeItem)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_ToyTrain) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SET(LVar2, LVar0)
    EVT_IF_LE(LVar2, 0)
        EVT_IF_EQ(LVar2, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_Toybox, 160, 40)
        EVT_END_IF
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_OMO_TOYBOX_LID, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, -90, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, 0)
        EVT_SUB(LVar2, LVar0)
        EVT_DIV(LVar2, 3)
        EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_WAIT(N(EVS_TossTrainInToybox))
    EVT_CALL(MakeLerp, -90, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, 0)
        EVT_SUB(LVar2, LVar0)
        EVT_DIV(LVar2, 3)
        EVT_CALL(RotateGroup, MODEL_box_top, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_OMO_TOYBOX_LID, SOUND_SPACE_DEFAULT)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_CALL(GotoMap, EVT_PTR("omo_03"), omo_03_ENTRY_6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(ItemList_ToyTrain)[] = {
    ITEM_TOY_TRAIN,
    ITEM_NONE
};

EvtScript N(EVS_Toybox_SetupTrainPrompt) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_ToyTrain)), TRIGGER_WALL_PRESS_A, COLLIDER_o468, EVT_PTR(N(ItemList_ToyTrain)), 0, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(get_total_equipped_bp_cost)(void) {
    s32 bpCost = 0;
    s32 i = 0;
    ItemData* itemTable = gItemTable;

    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        s16 badge = gPlayerData.equippedBadges[i];

        if (badge != 0) {
            bpCost += gMoveTable[itemTable[badge].moveID].costBP;
        }
    }
    return bpCost;
}

API_CALLABLE(N(EnforceNewStatLimits)) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 bpCost = N(get_total_equipped_bp_cost)();
    s32 i;

    if (gPlayerData.maxBP >= bpCost) {
        evt_set_variable(script, outVar, FALSE);
        return ApiStatus_DONE2;
    } else {
        s16* badges = gPlayerData.equippedBadges;
        // force unequip all badges if over the limit
        for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
            badges[i] = 0;
        }
        enforce_hpfp_limits();
        evt_set_variable(script, outVar, TRUE);
        return ApiStatus_DONE2;
    }
}

// npc scripts
#include "npc_muskular.inc.c"
#include "npc_twink.inc.c"
#include "npc_toybox_shyguy.inc.c"
#include "npc_harry_t.inc.c"
#include "npc_chet_rippo.inc.c"
#include "npc_new_residents.inc.c"
#include "npc_toad_01.inc.c"
#include "npc_toad_02.inc.c"
#include "npc_toad_kids.inc.c"
#include "npc_toadette_03.inc.c"
#include "npc_toad_03.inc.c"
#include "npc_gossip_trio.inc.c"
#include "npc_goomba_family.inc.c"

NpcData N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_ChetRippo,
        .pos = { 410.0f, 20.0f, -200.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ChetRippo),
        .settings = &N(NpcSettings_ChetRippo),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ChetRippo_Idle,
        },
        .tattle = MSG_NpcTattle_ChetRippo,
    },
    {
        .id = NPC_HarryT,
        .pos = { 310.0f, 20.0f, -430.0f },
        .yaw = 230,
        .init = &N(EVS_NpcInit_HarryT),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_HarryT_Idle,
            .walk   = ANIM_HarryT_Walk,
            .run    = ANIM_HarryT_Run,
            .chase  = ANIM_HarryT_Run,
            .anim_4 = ANIM_HarryT_Idle,
        },
        .tattle = MSG_NpcTattle_HarryT_ShopOwner,
    },
    {
        .id = NPC_NewResident1,
        .pos = { -80.0f, 20.0f, -100.0f },
        .yaw = 133,
        .init = &N(EVS_NpcInit_NewResident1),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentA,
    },
    {
        .id = NPC_NewResident2,
        .pos = { -133.0f, 20.0f, -82.0f },
        .yaw = 133,
        .init = &N(EVS_NpcInit_NewResident2),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentB,
    },
    {
        .id = NPC_Toad_01,
        .pos = { 48.0f, 0.0f, 153.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 48, 0, 153 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 48, 0, 153 },
                .detectSize = { 10 },
            }
        },
        .init = &N(EVS_NpcInit_Toad_01),
        .settings = &N(NpcSettings_Toad_Wander),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_TalksAlot,
    },
    {
        .id = NPC_Toad_02,
        .pos = { -239.0f, 20.0f, 105.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toad_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_WaryListener,
    },
    {
        .id = NPC_ToadKid_01,
        .pos = { 254.0f, 20.0f, 436.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ToadKid_01),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CarefreeKids,
    },
    {
        .id = NPC_ToadKid_02,
        .pos = { 304.0f, 20.0f, 410.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadKid_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_OutdoorKids,
    },
    {
        .id = NPC_ToadKid_03,
        .pos = { 345.0f, 20.0f, 438.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ToadKid_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShyKid,
    },
    {
        .id = NPC_Toadette_03,
        .pos = { -274.0f, 0.0f, 400.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Toadette_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_ToadWhoWalks,
    },
    {
        .id = NPC_Toad_03,
        .pos = { 500.0f, 20.0f, -160.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Toad_03),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GuideToad,
    },
    {
        .id = NPC_GossipTrio1,
        .pos = { -110.0f, 0.0f, 568.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GossipTrio1),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioA,
    },
    {
        .id = NPC_GossipTrio2,
        .pos = { -114.0f, 0.0f, 498.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_GossipTrio2),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioB,
    },
    {
        .id = NPC_GossipTrio3,
        .pos = { -52.0f, 0.0f, 525.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_GossipTrio3),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioC,
    },
};

AnimID N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Chapter4)[] = {
    {
        .id = NPC_Twink,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TwinkStartCh4),
        .settings = &N(NpcSettings_Twink),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_ShyGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
};

NpcData N(NpcData_PostChapter4)[] = {
    {
        .id = NPC_Muskular,
        .pos = { -486.0f, 20.0f, 259.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Muskular),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Twink,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .init = &N(EVS_NpcInit_TwinkEndCh4),
        .settings = &N(NpcSettings_StarSpirit),
        .flags = COMMON_PASSIVE_FLAGS,
        .drops = NO_DROPS,
        .animations = TWINK_ANIMS,
    },
};

NpcData N(NpcData_GoombaFamily)[] = {
    {
        .id = NPC_Goomama,
        .pos = { -126.0f, 0.0f, 329.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Goomama),
        .settings = &N(NpcSettings_GoombaFamily),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMAMA_ANIMS,
        .tattle = MSG_NpcTattle_Goomama,
    },
    {
        .id = NPC_Goombaria,
        .pos = { -117.0f, 0.0f, 305.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Goombaria),
        .settings = &N(NpcSettings_GoombaFamily),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = GOOMBARIA_ANIMS,
        .tattle = MSG_NpcTattle_Goombaria,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 57.0f, 20.0f, -114.0f },
    .yaw = 270,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_04 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_HAS_NO_SPRITE,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(Chapter4NPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_Chapter4)),
    {}
};

NpcGroupList N(PostChapter4NPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_PostChapter4)),
    {}
};

NpcGroupList N(Chapter7NPCs) = {
    NPC_GROUP(N(NpcData_Townsfolk)),
    NPC_GROUP(N(NpcData_GoombaFamily)),
    {}
};
