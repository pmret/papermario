#ifndef _WORLD_PARTNER_GOOMPA_H_
#define _WORLD_PARTNER_GOOMPA_H_

#include "common.h"
#include "script_api/map.h"

void world_goompa_init(Npc* partner);

extern EvtScript world_goompa_take_out;
extern EvtScript world_goompa_update;
extern EvtScript world_goompa_use_ability;
extern EvtScript world_goompa_put_away;

#endif
