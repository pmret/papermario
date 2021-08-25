#include "common.h"
#include "map.h"

#define NAMESPACE dgb_01

enum {
    NPC_SENTINEL0,
    NPC_SENTINEL1,
    NPC_SENTINEL2,
    NPC_SENTINEL3,
    NPC_WORLD_TUBBA,
};

ApiStatus InitAnimatedModels(Evt* script, s32 isInitialCall);
ApiStatus SetAnimatedModelRenderMode(Evt* script, s32 isInitialCall);
ApiStatus DeleteAnimatedModel(Evt* script, s32 isInitialCall);

ApiStatus N(func_80240000_BFD880)(void);
ApiStatus N(GetEntityPosition)(Evt* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802422B0_BFFB30)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802430C0_C00940)(Evt* script, s32 isInitialCall);

extern EvtSource N(802449C4);
extern EvtSource N(80244AD0);
extern EvtSource N(main);
extern EvtSource N(makeEntities);
extern EvtSource N(D_80252F4C_C107CC);
extern EvtSource N(D_802539A0_C11220);
extern NpcGroupList N(npcGroupList_80246E50);
extern NpcGroupList N(npcGroupList_80246ED4);
extern NpcGroupList N(npcGroupList_80246E8C);
extern NpcGroupList N(npcGroupList_80246F1C);
