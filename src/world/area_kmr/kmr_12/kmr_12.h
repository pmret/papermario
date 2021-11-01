/// @file kmr_12.h
/// @brief Goomba Region - Goomba Road 4

#include "common.h"
#include "map.h"
#include "../kmr.h"

#define NAMESPACE kmr_12

#define NPC_GOOMBA 0

#define GetGoomba N(GetGoomba)
ApiStatus GetGoomba(Evt* script, s32 isInitialCall);

extern  MapConfig N(config);
extern  EvtSource N(main);
extern  EvtSource N(PlayMusic);
extern  EvtSource N(MakeEntities);
extern  EvtSource N(ReadWestSign);
extern NpcGroupList N(npcGroupList);
