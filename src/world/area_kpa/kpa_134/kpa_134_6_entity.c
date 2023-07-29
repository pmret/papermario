#include "kpa_134.h"
#include "entity.h"

API_CALLABLE(N(UnusedSetEntityPosition)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    entity->pos.x = script->varTable[0];
    entity->pos.y = script->varTable[1];
    entity->pos.z = script->varTable[2];
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"
#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_BreakBlock_Brick) = {
    EVT_IF_EQ(GF_KPA134_BlueSwitch, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar5, -224)
    EVT_CALL(MakeLerp, 355, 370, 4, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_SwitchEntityID, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LVar0, 240, 16, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_SwitchEntityID, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(KeyList_BowsersCastle)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE,
};

EvtScript N(EVS_UnlockPrompt_Door) = {
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_KPA134_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_130_0)), TRIGGER_WALL_PRESS_A, COLLIDER_nno, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA134_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 743, 10, 115, 270, MAKE_ENTITY_END)
        EVT_SET(MV_PadlockEntityID, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_Door)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_BowsersCastle)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_130_0)), TRIGGER_WALL_PRESS_A, COLLIDER_nno, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_KPA134_BlueSwitch, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), -224, 355, -25, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_KPA134_HitWaterSwitch))
        EVT_SET(MV_SwitchEntityID, LVar0)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -224, 330, -25, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_Brick)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 475, 0, -20, 90, 60, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 195, 300, -75, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA134_HiddenItem_MapleSyrup)
    EVT_RETURN
    EVT_END
};
