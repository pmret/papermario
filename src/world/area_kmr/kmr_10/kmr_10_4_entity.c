#include "kmr_10.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

#include "world/common/util/PlaySpringReboundAnimation.inc.c"

API_CALLABLE(N(SetSpringPosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIndex = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIndex);

    entity->pos.x = x;
    entity->pos.y = y;
    entity->pos.z = z;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnShakeTree1) = {
    EVT_WAIT(15)
    EVT_IF_EQ(GF_KMR10_KnockedSpringOutOfTree, FALSE)
        EVT_SET(GF_KMR10_KnockedSpringOutOfTree, TRUE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetNpcPos, NPC_Dummy, 370, 115, -20)
        EVT_THREAD
            EVT_LOOP(17)
                EVT_CALL(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
                EVT_CALL(N(SetSpringPosition), MV_SpringEntityIndex, LVar0, LVar1, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetNpcPos, NPC_Dummy, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Dummy, EVT_FLOAT(0.8))
        EVT_CALL(NpcJump0, NPC_Dummy, 370, 10, 20, 15)
        EVT_CALL(PlaySoundAt, SOUND_48, SOUND_SPACE_MODE_0, 370, 10, 20)
        EVT_CALL(PlaySoundAt, SOUND_2086, SOUND_SPACE_MODE_0, 370, 10, 20)
        EVT_CALL(N(PlaySpringReboundAnimation), MV_SpringEntityIndex)
        EVT_IF_EQ(GF_KMR10_UnreadFlagForSpring, FALSE)
            EVT_ADD(GF_KMR10_UnreadFlagForSpring, 1)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Spring_TetherCameraToPlayer) = {
    EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_EXEC_GET_TID(N(EVS_Spring_TetherCameraToPlayer), LVarA)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.2))
    EVT_CALL(PlayerJump, 456, 142, 99, 30)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest_HammerThrow) = EVT_OPEN_CHEST_BADGE(ITEM_HAMMER_THROW, GF_KMR10_Chest_HammerThrow);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -190, 75, 220, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KMR10_ItemBlock_SleepySheep)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 633, 142, 119, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_KMR10_Chest_HammerThrow)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_HammerThrow)))
    EVT_IF_EQ(GF_KMR10_KnockedSpringOutOfTree, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 370, 115, -20, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
        EVT_SET(MV_SpringEntityIndex, LVar0)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), 370, 10, 20, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
