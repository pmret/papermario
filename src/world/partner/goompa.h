#ifndef _WORLD_PARTNER_GOOMPA_H_
#define _WORLD_PARTNER_GOOMPA_H_

#include "common.h"
#include "script_api/map.h"

void world_goompa_init(Npc* partner);

extern Script world_goompa_take_out;
extern Script world_goompa_update;
extern Script world_goompa_use_ability;
extern Script world_goompa_put_away;

#endif
