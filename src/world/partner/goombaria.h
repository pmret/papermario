#ifndef _WORLD_PARTNER_GOOMBARIA_H_
#define _WORLD_PARTNER_GOOMBARIA_H_

#include "common.h"
#include "script_api/map.h"

void world_goombaria_init(Npc* partner);

extern Script world_goombaria_take_out;
extern Script world_goombaria_update;
extern Script world_goombaria_use_ability;
extern Script world_goombaria_put_away;

#endif
