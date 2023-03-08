#ifndef _WORLD_PARTNER_GOOMBARIA_H_
#define _WORLD_PARTNER_GOOMBARIA_H_

#include "common.h"
#include "script_api/map.h"

void world_goombaria_init(Npc* partner);

extern EvtScript EVS_WorldGoombariaTakeOut;
extern EvtScript EVS_WorldGoombariaUpdate;
extern EvtScript EVS_WorldGoombariaUseAbility;
extern EvtScript EVS_WorldGoombariaPutAway;

#endif
