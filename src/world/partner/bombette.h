#ifndef _WORLD_BOMBETTE_KOOPER_H_
#define _WORLD_BOMBETTE_KOOPER_H_

#include "common.h"
#include "script_api/map.h"

void world_bombette_init(Npc*);
void world_bombette_test_first_strike(Npc*);
void world_bombette_can_use_ability(void);
s32 world_bombette_can_player_pause(void);
void world_bombette_pre_battle(Npc*);

extern EvtSource world_bombette_take_out;
extern EvtSource world_bombette_update;
extern EvtSource world_bombette_use_ability;
extern EvtSource world_bombette_put_away;

#endif
