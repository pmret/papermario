#ifndef _WORLD_PARTNER_GOOMBARIA_H_
#define _WORLD_PARTNER_GOOMBARIA_H_

#include "common.h"
#include "script_api/map.h"

void world_goombaria_init(Npc* partner);

extern EvtScript world_goombaria_take_out;
extern EvtScript world_goombaria_update;
extern EvtScript world_goombaria_use_ability;
extern EvtScript world_goombaria_put_away;

#endif
