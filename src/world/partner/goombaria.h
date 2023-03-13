#ifndef _WORLD_PARTNER_GOOMBARIA_H_
#define _WORLD_PARTNER_GOOMBARIA_H_

#include "common.h"
#include "script_api/map.h"

void world_goombaria_init(Npc* partner);

extern EvtScript EVS_WorldGoombaria_TakeOut;
extern EvtScript EVS_WorldGoombaria_Update;
extern EvtScript EVS_WorldGoombaria_UseAbility;
extern EvtScript EVS_WorldGoombaria_PutAway;

#endif
