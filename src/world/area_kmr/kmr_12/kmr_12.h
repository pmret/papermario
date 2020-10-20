#include "common.h"
#include "map.h"

#define NpcId_GOOMBA 0

Script kmr_12_main;
Script kmr_12_play_music;
Script make_entities;
Script read_west_sign;
NpcGroupList npc_groups;

ApiStatus get_goomba_ref(ScriptInstance* script, s32 isInitialCall);
