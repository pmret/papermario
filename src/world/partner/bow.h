#ifndef _WORLD_PARTNER_BOW_H_
#define _WORLD_PARTNER_BOW_H_

#include "common.h"
#include "script_api/map.h"

void world_bow_init(Npc*);
void world_bow_pre_battle(Npc*);

extern EvtScript world_bow_take_out;
extern EvtScript world_bow_update;
extern EvtScript world_bow_use_ability;
extern EvtScript world_bow_put_away;

#endif
