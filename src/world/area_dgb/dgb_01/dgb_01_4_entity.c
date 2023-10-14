#include "dgb_01.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockPrompt_Door) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_DGB01_UnlockedEastWing, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenLockedDoor) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_dgb_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_DGB01_UnlockedEastWing, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 490, 8, 0, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenLockedDoor)))
        EVT_SET(MV_PadlockEntityID, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
