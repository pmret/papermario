#include "common.h"
#include "map.h"
#include "../kmr.h"

#define NAMESPACE kmr_12

#define NPC_GOOMBA 0

#define GetGoomba N(GetGoomba)
ApiStatus GetGoomba(ScriptInstance* script, s32 isInitialCall);

extern MapConfig N(config);

extern Script N(Main);
extern Script N(PlayMusic);
extern Script N(MakeEntities);
extern Script N(ReadWestSign);

extern NpcGroupList N(npcGroupList);
