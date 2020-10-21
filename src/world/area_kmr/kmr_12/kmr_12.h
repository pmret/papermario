#include "common.h"
#include "map.h"

#define M(sym) kmr_12 ## _ ## sym

#define NpcId_GOOMBA 0

ApiStatus M(GetGoomba)(ScriptInstance* script, s32 isInitialCall);

Script M(Main);
Script M(PlayMusic);
Script M(MakeEntities);
Script M(ReadWestSign);

NpcGroupList M(npcGroupList);
