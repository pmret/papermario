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

ApiStatus func_802CCCB0(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D2B6C(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802CD348(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802CD3C0(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D6420(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D6954(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_80045838(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_80240000_BFD880)(void);
ApiStatus N(GetEntityPosition)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802422B0_BFFB30)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802430C0_C00940)(ScriptInstance* script, s32 isInitialCall);

Script N(802449C4);
Script N(80244AD0);
Script N(main);
Script N(makeEntities);
Script N(D_80252F4C_C107CC);
Script N(D_802539A0_C11220);
NpcGroupList N(npcGroupList_80246E50);
NpcGroupList N(npcGroupList_80246ED4);
NpcGroupList N(npcGroupList_80246E8C);
NpcGroupList N(npcGroupList_80246F1C);
