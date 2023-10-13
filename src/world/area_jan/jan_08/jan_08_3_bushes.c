#include "jan_08.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBush_Separate) = EVT_MOVE_BUSHES(COLLIDER_o70,
    MODEL_o67, MODEL_o68, MV_Unk_00, MV_Unk_01);

EvtScript N(EVS_Inspect_SeparateBushes) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o70, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_MoveBush_Separate))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_Unk_01, LVar0)
        EVT_SETF(MV_Unk_00, MV_Unk_01)
        EVT_MULF(MV_Unk_00, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Inspect_FlipBush) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o88, SOUND_SEARCH_BUSH, 0)
    EVT_LOOP(3)
        EVT_CALL(N(MoveBush_AnimateShearing), LVar1, 1)
        EVT_WAIT(1)
        EVT_CALL(N(MoveBush_AnimateShearing), LVar1, 0)
        EVT_WAIT(1)
        EVT_CALL(N(MoveBush_AnimateShearing), LVar1, -1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LVar1, 0, 0, 0)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_JAN08_SavedYoshi, FALSE)
            EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
            EVT_THREAD
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
                EVT_CALL(NpcMoveTo, NPC_PARTNER, -315, LVar5, 20)
                EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_YoshiKid, 0)
                EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
                EVT_CALL(EnablePartnerAI)
            EVT_END_THREAD
            EVT_CALL(PlayerMoveTo, -340, LVar5, 20)
            EVT_CALL(PlayerFaceNpc, NPC_YoshiKid, FALSE)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o88, SOUND_SEPARATE_BUSHES, 0)
            EVT_SET(LVar3, 0)
            EVT_LOOP(10)
                EVT_ADD(LVar3, 9)
                EVT_CALL(RotateModel, LVar1, LVar3, 0, 1, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_SET(LVar4, 270)
            EVT_CALL(SetNpcRotation, NPC_YoshiKid, 0, LVar4, 0)
            EVT_CALL(SetNpcPos, NPC_YoshiKid, -391, 0, -144)
            EVT_CALL(SetNpcFlagBits, NPC_YoshiKid, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_LOOP(10)
                EVT_ADD(LVar3, 9)
                EVT_CALL(RotateModel, LVar1, LVar3, 0, 1, 0)
                EVT_ADD(LVar4, 9)
                EVT_CALL(SetNpcRotation, NPC_YoshiKid, 0, LVar4, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(EnableNpcShadow, NPC_YoshiKid, TRUE)
            EVT_CALL(PlayerFaceNpc, NPC_YoshiKid, FALSE)
            EVT_WAIT(20)
            EVT_CALL(SetNpcVar, NPC_YoshiKid, 0, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o59);;

FoliageDropList N(Bush1_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { 117, 20, -424 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_JAN08_Bush1_Coin,
        },
    }
};

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { 117.0f, 20.0f, -424.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .drops = &N(Bush1_Drops),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o164);;

FoliageDropList N(Bush2_Drops) = {
    .count = 1,
    .drops = {
        {
            .itemID = ITEM_COIN,
            .pos = { -202, 20, 167 },
            .spawnMode = ITEM_SPAWN_MODE_TOSS_SPAWN_ONCE,
            .pickupFlag = GF_JAN08_Bush2_Coin,
        },
    }
};

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -202.0f, 20.0f, 167.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .drops = &N(Bush2_Drops),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o123);;

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -459.0f, 20.0f, 126.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o114);;

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { -461.0f, 20.0f, -39.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o156);;

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { -321.0f, 20.0f, -44.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o115);;

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { -279.0f, 20.0f, -55.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

FoliageModelList N(Bush7_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o113);;

FoliageVectorList N(Bush7_Effects) = {
    .count = 1,
    .vectors = {
        { -304.0f, 22.0f, -242.0f },
    }
};

SearchBushConfig N(SearchBush_Bush7) = {
    .bush = &N(Bush7_BushModels),
    .vectors = &N(Bush7_Effects),
};

FoliageModelList N(Bush8_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o158);;

FoliageVectorList N(Bush8_Effects) = {
    .count = 1,
    .vectors = {
        { -95.0f, 20.0f, -485.0f },
    }
};

SearchBushConfig N(SearchBush_Bush8) = {
    .bush = &N(Bush8_BushModels),
    .vectors = &N(Bush8_Effects),
};

FoliageModelList N(Bush9_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o159);;

FoliageVectorList N(Bush9_Effects) = {
    .count = 1,
    .vectors = {
        { 89.0f, 20.0f, -485.0f },
    }
};

SearchBushConfig N(SearchBush_Bush9) = {
    .bush = &N(Bush9_BushModels),
    .vectors = &N(Bush9_Effects),
};

FoliageModelList N(Bush10_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o160);;

FoliageVectorList N(Bush10_Effects) = {
    .count = 1,
    .vectors = {
        { 152.0f, 20.0f, -489.0f },
    }
};

SearchBushConfig N(SearchBush_Bush10) = {
    .bush = &N(Bush10_BushModels),
    .vectors = &N(Bush10_Effects),
};

FoliageModelList N(Bush11_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o163);;

FoliageVectorList N(Bush11_Effects) = {
    .count = 1,
    .vectors = {
        { 394.0f, 20.0f, 176.0f },
    }
};

SearchBushConfig N(SearchBush_Bush11) = {
    .bush = &N(Bush11_BushModels),
    .vectors = &N(Bush11_Effects),
};

FoliageModelList N(Bush12_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o161);;

FoliageVectorList N(Bush12_Effects) = {
    .count = 1,
    .vectors = {
        { 239.0f, 22.0f, 430.0f },
    }
};

SearchBushConfig N(SearchBush_Bush12) = {
    .bush = &N(Bush12_BushModels),
    .vectors = &N(Bush12_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_SeparateBushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o70, 1, 0)
    EVT_SET(LVar1, MODEL_o64)
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_Inspect_FlipBush)), TRIGGER_WALL_PRESS_A, COLLIDER_o88, 0, 0, 1)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o59, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o209, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o210, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o211, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o212, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o213, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush7)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o214, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush8)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o215, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush9)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o216, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush10)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o217, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush11)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o218, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush12)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o219, 1, 0)
    EVT_RETURN
    EVT_END
};
