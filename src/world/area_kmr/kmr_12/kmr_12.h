/// @file kmr_12.h
/// @brief Goomba Region - Goomba Road 4

#include "common.h"
#include "map.h"
#include "../kmr.h"

#define NAMESPACE kmr_12

#define NPC_GOOMBA 0

#define GetGoomba N(GetGoomba)
ApiStatus GetGoomba(Evt* script, s32 isInitialCall);

extern EvtScript N(main);
extern EvtScript N(PlayMusic);
extern EvtScript N(MakeEntities);
extern EvtScript N(ReadWestSign);
extern NpcGroupList N(npcGroupList);

extern s32 Entity_SignPost;
