#ifndef _WORLD_PARTNER_KOOPER_H_
#define _WORLD_PARTNER_KOOPER_H_

#include "common.h"
#include "script_api/map.h"

void world_kooper_init(Npc*);
void world_kooper_test_first_strike(Npc*);
void world_kooper_pre_battle(Npc*);
void world_kooper_post_battle(Npc*);

extern EvtSource world_kooper_take_out;

#endif
