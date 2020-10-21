#include "common.h"
#include "map.h"

#define MAP_NAME kmr_12

#define NpcId_GOOMBA 0

#define entrances MAP_LOCAL(entrances)
EntryList entrances;

#define config MAP_LOCAL(config)
MapConfig config;

#define GetGoomba MAP_LOCAL(GetGoomba)
ApiStatus GetGoomba(ScriptInstance*, s32);

#define Main MAP_LOCAL(Main)
#define PlayMusic MAP_LOCAL(PlayMusic)
#define ExitWest MAP_LOCAL(ExitWest)
#define ExitEast MAP_LOCAL(ExitEast)
#define BindExits MAP_LOCAL(BindExits)
#define ReadWestSign MAP_LOCAL(ReadWestSign)
#define ReadEastSign MAP_LOCAL(ReadEastSign)
#define MakeEntities MAP_LOCAL(MakeEntities)
#define GoombaAI MAP_LOCAL(GoombaAI)
#define GoombaIdle MAP_LOCAL(GoombaIdle)
#define GoombaInit MAP_LOCAL(GoombaInit)
Script Main;
Script PlayMusic;
Script ExitWest;
Script ExitEast;
Script ReadWestSign;
Script ReadEastSign;
Script MakeEntities;
Script GoombaAI;
Script GoombaIdle;
Script GoombaInit;

#define goombaAISettings MAP_LOCAL(goombaAISettings)
NpcAISettings goombaAISettings;

#define goombaNpcSettings MAP_LOCAL(goombaNpcSettings)
NpcSettings goombaNpcSettings;

#define goombaNpc MAP_LOCAL(goombaNpc)
StaticNpc goombaNpc;

#define npcGroupList MAP_LOCAL(npcGroupList)
NpcGroupList npcGroupList;
