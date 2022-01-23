#ifndef _WORLD_PARTNER_SUSHIE_H_
#define _WORLD_PARTNER_SUSHIE_H_

#include "common.h"
#include "script_api/map.h"

void world_sushie_init(Npc*);
void world_sushie_pre_battle(Npc*);
void world_sushie_post_battle(Npc*);

extern EvtScript world_sushie_take_out;
extern EvtScript world_sushie_update;
extern EvtScript world_sushie_use_ability;
extern EvtScript world_sushie_put_away;
extern EvtScript world_sushie_while_riding;

#endif
