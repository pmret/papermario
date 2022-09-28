#include "kzn_03.h"
#include "entity.h"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

API_CALLABLE(func_80242D38_C63A48);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C63A10", func_80242D38_C63A48);


EvtScript N(D_802462B0_C66FC0) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246314_C67024) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_EXEC_GET_TID(N(D_802462B0_C66FC0), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, 335, 290, 360, 40)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_FLYING, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_FALLING)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(N(SetCamera0MoveFlag1))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246410_C67120) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_EXEC_GET_TID(N(D_802462B0_C66FC0), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
    EVT_CALL(PlayerJump, 350, 470, 210, 40)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(N(SetCamera0MoveFlag1))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802464F8_C67208) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_JUMP)
    EVT_WAIT(1)
    EVT_CALL(N(UnsetCamera0MoveFlag1))
    EVT_EXEC_GET_TID(N(D_802462B0_C66FC0), LVarA)
    EVT_IF_EQ(MV_Unk_09, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.4))
        EVT_CALL(PlayerJump, -470, 670, 71, 18)
    EVT_ELSE
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, -384, 870, -22, 40)
    EVT_END_IF
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(N(SetCamera0MoveFlag1))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024663C_C6734C) = {
    EVT_SET(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 365, 530, 135, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_FIRE_SHIELD, 75, 290, 235, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KZN03_Item_FireShield)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 215, 745, -105, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 85, 770, -105, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_P_O_W_BLOCK, 85, 795, -105, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_KZN03_Item_POWBlock)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 35, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN03_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -15, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN03_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -65, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN03_ItemBlock_CoinC)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -115, 730, -105, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN03_ItemBlock_CoinD)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), 490, 470, 210, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(D_8024663C_C6734C)))
        EVT_THREAD
            EVT_LOOP(0)
                EVT_IF_GE(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(ModifyColliderFlags, 0, COLLIDER_on_off, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_THREAD
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_on_off, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 160, 30, 350, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_80246314_C67024)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 335, 265, 360, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_80246410_C67120)))
    EVT_THREAD
        EVT_CALL(func_80242D38_C63A48)
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -410, 645, 120, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_802464F8_C67208)))
    EVT_RETURN
    EVT_END
};
