#include "common.h"
#include "map.h"

#define MAP_NAME kmr_12

#define NpcId_GOOMBA 0

#define GetGoomba M(GetGoomba)
ApiStatus GetGoomba(ScriptInstance* script, s32 isInitialCall);

MapConfig M(config);

Script M(Main);
Script M(PlayMusic);
Script M(MakeEntities);
Script M(ReadWestSign);

NpcGroupList M(npcGroupList);
