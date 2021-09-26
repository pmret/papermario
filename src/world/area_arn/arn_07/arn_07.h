#include "common.h"
#include "map.h"
#include "../arn.h"

#define NAMESPACE arn_07

enum {
    NPC_TUBBAS_HEART,
    NPC_WORLD_TUBBA,
    NPC_BOO0,
    NPC_BOO1,
    NPC_BOO2,
    NPC_BOO3,
    NPC_BOO4,
    NPC_BOO5,
    NPC_WORLD_BOW,
    NPC_BOOTLER,
    NPC_PARAGOOMBA0,
    NPC_PARAGOOMBA1,
    NPC_PARAGOOMBA2,
    NPC_WORLD_SKOLAR,
};

ApiStatus N(arn_07_StarSpiritEffectFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(arn_07_StarSpiritEffectFunc2)(Evt* script, s32 isInitialCall);
ApiStatus N(arn_07_StarSpiritEffectFunc3)(Evt* script, s32 isInitialCall);
ApiStatus N(arn_07_StarSpiritEffectFunc4)(Evt* script, s32 isInitialCall);
ApiStatus N(arn_07_StarSpiritEffectFunc5)(Evt* script, s32 isInitialCall);
ApiStatus N(arn_07_StarSpiritEffectFunc6)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240800_BED5F0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241C5C_BEEA4C)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus PostChapter3StatUpdate(Evt* script, s32 isInitialCall);

extern EvtSource N(exitSingleDoor_802428D4);
extern NpcGroupList N(npcGroupList_8024787C);
extern NpcGroupList N(npcGroupList_802478B8);
extern NpcGroupList N(npcGroupList_802478E8);
extern EvtSource N(80243790);
extern EvtSource N(802437AC);
extern EvtSource N(802439B0);
extern EvtSource N(80242048);
extern EvtSource N(80241F10);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
