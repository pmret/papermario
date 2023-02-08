#include "pra_34.h"
#include "entity.h"

EvtScript N(EVS_Interact_Padlock) = {
    EVT_SET(GF_PRA34_UnlockedDoor, TRUE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_31_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_31_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_PRA34_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 240, 8, -75, 270, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_Interact_Padlock)))
        EVT_SET(MV_FarPadlockEntityID, LVar0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 240, 8, 75, 270, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_Interact_Padlock)))
        EVT_SET(MV_NearPadlockEntityID, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

