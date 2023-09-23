#include "isk_04.h"
#include "entity.h"
#include "effects.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_ISK04_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 600, -330, 100, 160, MAKE_ENTITY_END)
        EVT_SET(MV_RuinsLockEntityID, LVar0)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 504, -193, 43, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_RED, 486, -193, -128, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};
