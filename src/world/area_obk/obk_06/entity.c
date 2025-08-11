#include "obk_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_OBK06_Item_BoosPortrait, false)
        Call(MakeItemEntity, ITEM_BOO_PORTRAIT, 230, 125, -215, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK06_Item_BoosPortrait)
        Thread
            Loop(0)
                IfNe(GF_OBK06_Item_BoosPortrait, false)
                    Set(GB_StoryProgress, STORY_CH3_GOT_BOO_PORTRAIT)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndThread
    EndIf
    Call(MakeEntity, Ref(Entity_WoodenCrate), -110, 30, 50, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -110, 0, 50, 0, ITEM_STAR_PIECE, MAKE_ENTITY_END)
    Call(AssignCrateFlag, GF_OBK06_Crate_StarPiece)
    Return
    End
};
