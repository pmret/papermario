#include "mac_01.h"
#include "entity.h"

EvtScript N(EVS_Inspect_StreetSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0170, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 280, 80, -130, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_o406, 1, 0)
    EVT_RETURN
    EVT_END
};
