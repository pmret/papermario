#include "flo_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_EPILOGUE)
        Call(MakeEntity, Ref(Entity_SavePoint), 110, 60, -100, 0, MAKE_ENTITY_END)
    EndIf
    Return
    End
};
