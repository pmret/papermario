#include "pra_34.h"
#include "entity.h"

EvtScript N(EVS_Interact_Padlock) = {
    Set(GF_PRA34_UnlockedDoor, true)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_31_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_31_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_PRA34_UnlockedDoor, false)
        Call(MakeEntity, Ref(Entity_Padlock), 240, 8, -75, 270, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_Interact_Padlock)))
        Set(MV_FarPadlockEntityID, LVar0)
        Call(MakeEntity, Ref(Entity_Padlock), 240, 8, 75, 270, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_Interact_Padlock)))
        Set(MV_NearPadlockEntityID, LVar0)
    EndIf
    Return
    End
};

