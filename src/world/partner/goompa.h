#ifndef _WORLD_PARTNER_GOOMPA_H_
#define _WORLD_PARTNER_GOOMPA_H_

#include "common.h"
#include "script_api/map.h"

void world_goompa_init(Npc* partner);

extern EvtScript EVS_WorldGoompa_TakeOut;
extern EvtScript EVS_WorldGoompa_Update;
extern EvtScript EVS_WorldGoompa_UseAbility;
extern EvtScript EVS_WorldGoompa_PutAway;

#endif
