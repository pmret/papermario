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
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_takara00, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_takara01, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SetChestCollisionOpened) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_takara00, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_takara01, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SetupGiantChest_SuperHammer) = {
    IfEq(GF_ISK09_GiantChest, FALSE)
        ExecWait(N(EVS_SetChestCollisionClosed))
        Loop(0)
            IfEq(GF_ISK09_GiantChest, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(PartnerIsFlying, LVar0)
        IfEq(LVar0, FALSE)
            Thread
                Call(DisablePartnerAI, 0)
                Call(NpcFlyTo, NPC_PARTNER, -222, -347, -531, 20, 0, EASING_LINEAR)
                Call(InterpNpcYaw, NPC_PARTNER, 70, 0)
                Loop(0)
                    IfEq(GB_StoryProgress, STORY_CH2_GOT_SUPER_HAMMER)
                        BreakLoop
                    EndIf
                    Wait(1)
                EndLoop
                Call(EnablePartnerAI)
            EndThread
        EndIf
        Wait(60)
        Exec(N(EVS_PlayUpgradeSong))
        Call(ShowMessageAtScreenPos, MSG_Menus_017D, 160, 40)
        Call(N(DismissGotItem))
        Set(GB_StoryProgress, STORY_CH2_GOT_SUPER_HAMMER)
    EndIf
    ExecWait(N(EVS_SetChestCollisionOpened))
    Return
    End
};

EvtScript N(EVS_OpenChest_SlowGo) = EVT_OPEN_CHEST_BADGE(ITEM_SLOW_GO, GF_ISK09_Chest_SlowGo);

EvtScript N(EVS_SmashBlock_Stone) = {
    Set(GF_ISK09_Hammer2Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_GiantChest), -158, -358, -562, 283, ITEM_SUPER_HAMMER, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_ISK09_GiantChest)
    Exec(N(EVS_SetupGiantChest_SuperHammer))
    IfEq(GF_ISK09_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block), -274, -390, -517, 115, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_SmashBlock_Stone)))
    EndIf
    Call(MakeEntity, Ref(Entity_Chest), 50, -240, -535, 222, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_ISK09_Chest_SlowGo)
    Call(AssignScript, Ref(N(EVS_OpenChest_SlowGo)))
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -503, -323, -44, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -481, -323, -130, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -413, -323, -290, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -323, -358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -211, -323, -459, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -130, -323, -486, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -503, -193, -44, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -481, -193, -130, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -413, -193, -290, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -193, -358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -211, -193, -459, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -130, -193, -486, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -503, -63, -44, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -481, -63, -130, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -413, -63, -290, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -63, -358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -211, -63, -459, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -130, -63, -486, Float(0.3), LVar0)
    Return
    End
};
