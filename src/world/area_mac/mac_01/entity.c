#include "mac_01.h"
#include "entity.h"

EvtScript N(EVS_Inspect_StreetSign) = {
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0170, 160, 40)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_EPILOGUE)
        Call(MakeEntity, Ref(Entity_SavePoint), 280, 80, -130, 0, MAKE_ENTITY_END)
    EndIf
    BindTrigger(Ref(N(EVS_Inspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_o406, 1, 0)
    Return
    End
};
