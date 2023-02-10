#include "mac_04.h"

#include "world/common/npc/Toad_Wander.inc.c"
#include "world/common/npc/Toad_Stationary.inc.c"

NpcSettings N(NpcSettings_ChetRippo) = {
    .height = 24,
    .radius = 24,
    .level = 99,
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_60005)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, SOUND_SPACE_MODE_0)
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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_omo_ent, SOUND_1AA, SOUND_SPACE_MODE_0)
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

StaticNpc N(NpcData_Townsfolk)[] = {
    {
        .id = NPC_ChetRippo,
        .settings = &N(NpcSettings_ChetRippo),
        .pos = { 410.0f, 20.0f, -200.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS,
        .init = &N(EVS_NpcInit_ChetRippo),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ChetRippo_Idle,
        },
        .tattle = MSG_NpcTattle_ChetRippo,
    },
    {
        .id = NPC_HarryT,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 310.0f, 20.0f, -430.0f },
        .yaw = 230,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_HarryT),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -80.0f, 20.0f, -100.0f },
        .yaw = 133,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_NewResident1),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentA,
    },
    {
        .id = NPC_NewResident2,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -133.0f, 20.0f, -82.0f },
        .yaw = 133,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_NewResident2),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_NewResidentB,
    },
    {
        .id = NPC_Toad_01,
        .settings = &N(NpcSettings_Toad_Wander),
        .pos = { 48.0f, 0.0f, 153.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toad_01),
        .drops = TOAD_DROPS,
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
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_TalksAlot,
    },
    {
        .id = NPC_Toad_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -239.0f, 20.0f, 105.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toad_02),
        .drops = TOAD_DROPS,
        .animations = TOAD_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_MAC_WaryListener,
    },
    {
        .id = NPC_ToadKid_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 254.0f, 20.0f, 436.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ToadKid_01),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_MAC_CarefreeKids,
    },
    {
        .id = NPC_ToadKid_02,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 304.0f, 20.0f, 410.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ToadKid_02),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_MAC_OutdoorKids,
    },
    {
        .id = NPC_ToadKid_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 345.0f, 20.0f, 438.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ToadKid_03),
        .drops = TOAD_KID_DROPS,
        .animations = TOAD_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_MAC_ShyKid,
    },
    {
        .id = NPC_Toadette_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -274.0f, 0.0f, 400.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toadette_03),
        .drops = TOADETTE_DROPS,
        .animations = TOADETTE_ORANGE_ANIMS,
        .tattle = MSG_NpcTattle_ToadWhoWalks,
    },
    {
        .id = NPC_Toad_03,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { 500.0f, 20.0f, -160.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Toad_03),
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GuideToad,
    },
    {
        .id = NPC_GossipTrio1,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -110.0f, 0.0f, 568.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_GossipTrio1),
        .drops = TOAD_DROPS,
        .animations = TOAD_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioA,
    },
    {
        .id = NPC_GossipTrio2,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -114.0f, 0.0f, 498.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_GossipTrio2),
        .drops = TOAD_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioB,
    },
    {
        .id = NPC_GossipTrio3,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { -52.0f, 0.0f, 525.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_GossipTrio3),
        .drops = TOAD_DROPS,
        .animations = TOAD_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_GreatGossipTrioC,
    },
};

s32 N(ExtraAnims_Twink)[] = {
    ANIM_Twink_Idle,
    ANIM_Twink_Fly,
    ANIM_Twink_Talk,
    -1
};

StaticNpc N(NpcData_Chapter4)[] = {
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_Twink),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_TwinkStartCh4),
        .drops = TWINK_DROPS,
        .animations = TWINK_ANIMS,
        .extraAnimations = N(ExtraAnims_Twink),
    },
    {
        .id = NPC_ShyGuy_01,
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .settings = &N(NpcSettings_Toad_Stationary),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_ShyGuy_02),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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

StaticNpc N(NpcData_PostChapter4)[] = {
    {
        .id = NPC_Muskular,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { -486.0f, 20.0f, 259.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS,
        .init = &N(EVS_NpcInit_Muskular),
        .drops = MUSKULAR_DROPS,
        .animations = MUSKULAR_ANIMS,
    },
    {
        .id = NPC_Twink,
        .settings = &N(NpcSettings_StarSpirit),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS,
        .init = &N(EVS_NpcInit_TwinkEndCh4),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = TWINK_ANIMS,
    },
};

StaticNpc N(NpcData_GoombaFamily)[] = {
    {
        .id = NPC_Goomama,
        .settings = &N(NpcSettings_GoombaFamily),
        .pos = { -126.0f, 0.0f, 329.0f },
        .yaw = 90,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Goomama),
        .drops = GOOMAMA_DROPS,
        .animations = GOOMAMA_ANIMS,
        .tattle = MSG_NpcTattle_Goomama,
    },
    {
        .id = NPC_Goombaria,
        .settings = &N(NpcSettings_GoombaFamily),
        .pos = { -117.0f, 0.0f, 305.0f },
        .yaw = 270,
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_Goombaria),
        .drops = GOOMBARIA_DROPS,
        .animations = GOOMBARIA_ANIMS,
        .tattle = MSG_NpcTattle_Goombaria,
    },
};

StaticNpc N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .settings = &N(NpcSettings_ChuckQuizmo),
    .pos = { 57.0f, 20.0f, -114.0f },
    .yaw = 270,
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000 | ENEMY_FLAG_4000,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_MAC, QUIZ_COUNT_MAC, QUIZ_MAP_MAC_04 }},
    .drops = QUIZMO_DROPS,
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
