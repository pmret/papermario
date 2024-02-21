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
    Wait(15)
    IfEq(GF_KMR10_KnockedSpringOutOfTree, FALSE)
        Set(GF_KMR10_KnockedSpringOutOfTree, TRUE)
        Call(DisablePlayerInput, TRUE)
        Call(SetNpcPos, NPC_Dummy, 370, 115, -20)
        Thread
            Loop(17)
                Call(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
                Call(N(SetSpringPosition), MV_SpringEntityIndex, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            Call(SetNpcPos, NPC_Dummy, NPC_DISPOSE_LOCATION)
        EndThread
        Call(SetNpcJumpscale, NPC_Dummy, Float(0.8))
        Call(NpcJump0, NPC_Dummy, 370, 10, 20, 15)
        Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, 370, 10, 20)
        Call(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, 370, 10, 20)
        Call(N(PlaySpringReboundAnimation), MV_SpringEntityIndex)
        IfEq(GF_KMR10_UnreadFlagForSpring, FALSE)
            Add(GF_KMR10_UnreadFlagForSpring, 1)
        EndIf
        Call(DisablePlayerInput, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_Spring_TetherCameraToPlayer) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    ExecGetTID(N(EVS_Spring_TetherCameraToPlayer), LVarA)
    Call(SetPlayerJumpscale, Float(1.2))
    Call(PlayerJump, 456, 142, 99, 30)
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OpenChest_HammerThrow) = EVT_OPEN_CHEST_BADGE(ITEM_HAMMER_THROW, GF_KMR10_Chest_HammerThrow);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -190, 75, 220, 0, ITEM_SLEEPY_SHEEP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR10_ItemBlock_SleepySheep)
    Call(MakeEntity, Ref(Entity_Chest), 633, 142, 119, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_KMR10_Chest_HammerThrow)
    Call(AssignScript, Ref(N(EVS_OpenChest_HammerThrow)))
    IfEq(GF_KMR10_KnockedSpringOutOfTree, FALSE)
        Call(MakeEntity, Ref(Entity_ScriptSpring), 370, 115, -20, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UseSpring)))
        Set(MV_SpringEntityIndex, LVar0)
    Else
        Call(MakeEntity, Ref(Entity_ScriptSpring), 370, 10, 20, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UseSpring)))
    EndIf
    Return
    End
};
