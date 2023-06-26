#include "kmr_04.h"
#include "sprite/player.h"

#include "world/area_kmr/kmr_04/hammer_block_message.png.h"
#include "world/area_kmr/kmr_04/hammer_block_message.png.inc.c"
#include "world/area_kmr/kmr_04/hammer_block_message.pal.inc.c"

#include "common/foliage.inc.c"

#define NAMESPACE dup_kmr_04
#include "world/common/todo/CheckPartnerFlags1000.inc.c"
#define NAMESPACE kmr_04

#include "world/common/complete/GiveReward.inc.c"

static MessageImageData MessageImage;

API_CALLABLE(N(SetMessageImage_HammerBlock)) {
    MessageImage.raster = N(hammer_block_message_img);
    MessageImage.palette = N(hammer_block_message_pal);
    MessageImage.width = N(hammer_block_message_img_width);
    MessageImage.height = N(hammer_block_message_img_height);
    MessageImage.format = G_IM_FMT_CI;
    MessageImage.bitDepth = G_IM_SIZ_4b;
    set_message_images(&MessageImage);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GiveWoodenHammer)) {
    gPlayerData.hammerLevel = 0;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240444_8CAD44)) {
    exec_entity_commandlist(get_entity_by_index(script->varTable[0]));

    return ApiStatus_DONE2;
}

EvtScript N(EVS_GotHammer) = {
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW1_Lift)
    EVT_CALL(GetPlayerPos, LVar5, LVar6, LVar7)
    EVT_ADD(LVar6, 40)
    EVT_CALL(MakeItemEntity, ITEM_HAMMER, LVar5, LVar6, LVar7, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(LVarC, LVar0)
    EVT_ADD(LVar6, 16)
    EVT_PLAY_EFFECT(EFFECT_GOT_ITEM_OUTLINE, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.0), LVar8)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 9, LVar5, LVar6, LVar7, EVT_FLOAT(1.0), 100)
    EVT_EXEC(N(EVS_PlayUpgradeSong))
    EVT_THREAD
        EVT_WAIT(4 * DT)
        EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 50)
        EVT_ADD(LVar5, 2)
        EVT_ADD(LVar3, 8)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
        EVT_ADD(LVar3, -16)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_EQ(MF_Unk_12, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DismissItemOutline, LVar8)
    EVT_CALL(RemoveItemEntity, LVarC)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearch_HammerBush) = {
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(8.0), 0, EVT_FLOAT(300.0), EVT_FLOAT(19.0), EVT_FLOAT(-9.0))
    EVT_SET(MF_Unk_12, FALSE)
    EVT_EXEC(N(EVS_GotHammer))
    EVT_CALL(N(GiveWoodenHammer))
    EVT_WAIT(30 * DT)
    EVT_CALL(N(SetMessageImage_HammerBlock))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_FoundHammer, 160, 40)
    EVT_SET(MF_Unk_12, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00AA)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
    EVT_SET(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(EnablePartnerAI)
    EVT_THREAD
#if VERSION_PAL
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3 * DT))
#else
        EVT_CALL(ResetCam, CAM_DEFAULT, 3)
#endif
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush7) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_OnSearch_HammerBush))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSearchBush8) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 85, 20 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o213, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_OnSearch_HammerBush))
    EVT_CALL(MakeLerp, 85, 0, 20 * DT, EASING_COS_IN_OUT)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o213, LVar0, 1, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o181);

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 248, 17, 97 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Bush1_Coin,
            .spawnFlag = AF_JAN01_TreeDrop_StarPiece,
        },
    }
};

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { 248.0f, 17.0f, 97.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o212);

FoliageDropList N(Bush2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 99, 17, 237 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS,
            .pickupFlag = GF_KMR04_Bush2_Coin,
            .spawnFlag = MF_Unk_0B,
        },
    }
};

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { 100.0f, 19.0f, 246.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .drops = &N(Bush2_Drops),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o235);

FoliageDropList N(Bush3_Drops) = {
    .count = 2,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 50, 18, -200 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Bush3_CoinA,
            .spawnFlag = MF_Unk_0C,
        },
        {
            .itemID = ITEM_COIN,
            .pos = { 50, 18, -200 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Bush3_CoinB,
            .spawnFlag = MF_Unk_0D,
        },
    }
};

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { 50.0f, 18.0f, -200.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .drops = &N(Bush3_Drops),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o182);

FoliageDropList N(Bush4_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -49, 20, 146 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Bush4_Coin,
            .spawnFlag = MF_Unk_0E,
        },
    }
};

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -49.0f, 20.0f, 146.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .drops = &N(Bush4_Drops),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o205);

FoliageDropList N(Bush5_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -148, 16, -150 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Bush5_Coin,
            .spawnFlag = MF_Unk_0F,
        },
    }
};

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -148.0f, 16.0f, -150.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .drops = &N(Bush5_Drops),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o213);

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { -224.0f, 20.0f, 96.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
    .callback = &N(EVS_OnSearchBush7),
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
    .callback = &N(EVS_OnSearchBush8),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o213);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { -224.0f, 20.0f, 96.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o239);

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { -174.0f, 19.0f, 296.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o237);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o236);

FoliageDropList N(Tree1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -302, 128, 2 },
            .spawnMode = ITEM_SPAWN_MODE_FALL_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Tree1_Coin,
        },
    }
};

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -391.0f, 150.0f, 20.0f },
        { -267.0f, 150.0f, 22.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .drops = &N(Tree1_Drops),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -352.0f, 0.0f, 10.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o194);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o193);

FoliageDropList N(Tree2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -96, 132, -255 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_KMR04_Tree2_Coin,
        },
    }
};

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -156.0f, 150.0f, -255.0f },
        { -32.0f, 150.0f, -272.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .drops = &N(Tree2_Drops),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -92.0f, 0.0f, -295.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnShakeTree3) = {
    EVT_IF_EQ(GF_KMR04_Tree3_Dolly, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_KMR_09, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(MakeItemEntity, ITEM_DOLLY, 250, 132, -100, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_KMR04_Tree3_Dolly)
    EVT_SET(AF_KMR_09, TRUE)
    EVT_THREAD
        EVT_LABEL(10)
        EVT_IF_EQ(GF_KMR04_Tree3_Dolly, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_GOOMPA)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_WAIT(5)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00AB)
            EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Tree3_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o192);
FoliageModelList N(Tree3_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o191);

FoliageVectorList N(Tree3_Effects) = {
    .count = 2,
    .vectors = {
        { 190.0f, 150.0f, -124.0f },
        { 295.0f, 150.0f, -124.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree3) = {
    .leaves = &N(Tree3_LeafModels),
    .trunk = &N(Tree3_TrunkModels),
    .vectors = &N(Tree3_Effects),
    .callback = &N(EVS_OnShakeTree3),
};

BombTrigger N(BombPos_Tree3) = {
    .pos = { 248.0f, 0.0f, -122.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o402, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o415, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o409, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o412, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o399, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o410, 1, 0)
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o410_1, 1, 0)
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush7)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o410, 1, 0)
        EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush8)))
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o410_1, 1, 0)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush9)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o413, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o407, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree1)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o271, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree2)), 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(ShakeTree_Tree3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_WALL_HAMMER, COLLIDER_o341, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ShakeTree)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Tree3)), 1, 0)
    EVT_RETURN
    EVT_END
};
