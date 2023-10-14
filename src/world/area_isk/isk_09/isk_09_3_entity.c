#include "isk_09.h"
#include "entity.h"
#include "effects.h"

#include "world/common/entity/Chest.inc.c"

API_CALLABLE(N(DismissGotItem)) {
    Entity* bigChest = get_entity_by_index(script->varTable[0]);
    bigChest->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetChestCollisionClosed) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_takara00, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_takara01, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetChestCollisionOpened) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_takara00, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_takara01, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGiantChest_SuperHammer) = {
    EVT_IF_EQ(GF_ISK09_GiantChest, FALSE)
        EVT_EXEC_WAIT(N(EVS_SetChestCollisionClosed))
        EVT_LOOP(0)
            EVT_IF_EQ(GF_ISK09_GiantChest, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PartnerIsFlying, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_THREAD
                EVT_CALL(DisablePartnerAI, 0)
                EVT_CALL(NpcFlyTo, NPC_PARTNER, -222, -347, -531, 20, 0, EASING_LINEAR)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 70, 0)
                EVT_LOOP(0)
                    EVT_IF_EQ(GB_StoryProgress, STORY_CH2_GOT_SUPER_HAMMER)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(EnablePartnerAI)
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT(60)
        EVT_EXEC(N(EVS_PlayUpgradeSong))
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017D, 160, 40)
        EVT_CALL(N(DismissGotItem))
        EVT_SET(GB_StoryProgress, STORY_CH2_GOT_SUPER_HAMMER)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetChestCollisionOpened))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest_SlowGo) = EVT_OPEN_CHEST_BADGE(ITEM_SLOW_GO, GF_ISK09_Chest_SlowGo);

EvtScript N(EVS_SmashBlock_Stone) = {
    EVT_SET(GF_ISK09_Hammer2Block, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GiantChest), -158, -358, -562, 283, ITEM_SUPER_HAMMER, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_ISK09_GiantChest)
    EVT_EXEC(N(EVS_SetupGiantChest_SuperHammer))
    EVT_IF_EQ(GF_ISK09_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), -274, -390, -517, 115, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_SmashBlock_Stone)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 50, -240, -535, 222, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_ISK09_Chest_SlowGo)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_SlowGo)))
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -503, -323, -44, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -481, -323, -130, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -413, -323, -290, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -358, -323, -358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -211, -323, -459, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -130, -323, -486, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -503, -193, -44, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -481, -193, -130, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -413, -193, -290, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -358, -193, -358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -211, -193, -459, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -130, -193, -486, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -503, -63, -44, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -481, -63, -130, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -413, -63, -290, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -358, -63, -358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -211, -63, -459, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, -130, -63, -486, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
