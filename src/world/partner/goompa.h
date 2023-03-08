#ifndef _WORLD_PARTNER_GOOMPA_H_
#define _WORLD_PARTNER_GOOMPA_H_

#include "common.h"
#include "script_api/map.h"

void world_goompa_init(Npc* partner);

extern EvtScript EVS_WorldGoompaTakeOut;
extern EvtScript EVS_WorldGoompaUpdate;
extern EvtScript EVS_WorldGoompaUseAbility;
extern EvtScript EVS_WorldGoompaPutAway;

#endif
