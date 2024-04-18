#include "jan_22.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Thread
        Label(0)
            IfLt(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                Wait(1)
                Goto(0)
            EndIf
        Call(MakeEntity, Ref(Entity_HeartBlock), 1075, 150, -50, 0, MAKE_ENTITY_END)
    EndThread
    Call(MakeItemEntity, ITEM_JAMMIN_JELLY, 340, 0, -75, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN22_Item_JamminJelly)
    Call(MakeEntity, Ref(Entity_PinkFlower), -107, 0, -97, -15, MAKE_ENTITY_END)
    Return
    End
};
