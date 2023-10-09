
#include "common.h"
#include "battle/battle.h"
#include "ld_addrs.h"

extern ActorBlueprint battle_partner_goombario;
extern ActorBlueprint battle_partner_kooper;
extern ActorBlueprint battle_partner_bombette;
extern ActorBlueprint battle_partner_parakarry;
extern ActorBlueprint battle_partner_goompa;
extern ActorBlueprint battle_partner_watt;
extern ActorBlueprint battle_partner_sushie;
extern ActorBlueprint battle_partner_lakilester;
extern ActorBlueprint battle_partner_bow;
extern ActorBlueprint battle_partner_twink;

#define BATTLE_PARTNER_ENTRY(name, Y) \
    { \
        (u32)battle_partner_##name##_ROM_START, \
        (u32)battle_partner_##name##_ROM_END, \
        battle_partner_##name##_VRAM, \
        &battle_partner_##name, \
        Y \
    }

PartnerDMAData bPartnerDmaTable[] = {
    {},
    BATTLE_PARTNER_ENTRY(goombario, 0),
    BATTLE_PARTNER_ENTRY(kooper, 0),
    BATTLE_PARTNER_ENTRY(bombette, 0),
    BATTLE_PARTNER_ENTRY(parakarry, 30),
    BATTLE_PARTNER_ENTRY(goompa, 0),
    BATTLE_PARTNER_ENTRY(watt, 20),
    BATTLE_PARTNER_ENTRY(sushie, 0),
    BATTLE_PARTNER_ENTRY(lakilester, 10),
    BATTLE_PARTNER_ENTRY(bow, 20),
    {},
    BATTLE_PARTNER_ENTRY(twink, 30),
};
