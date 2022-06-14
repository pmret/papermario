#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo2

extern ActorBlueprint N(general_guy);
extern ActorBlueprint N(toy_tank);
extern ActorBlueprint N(light_bulb);

extern Stage N(omo_07);

Formation N(formation_01) = {
    { .actor = &N(general_guy), .home = { .index = 2 }, .priority = 70, },
    { .actor = &N(toy_tank), .home = { .index = 1 }, .priority = 80, },
    { .actor = &N(light_bulb), .home = { .index = 7 }, .priority = 90, },
};

BattleList N(formationTable) = {
    BATTLE("しょうぐんヘイホー", N(formation_01), &N(omo_07)),
    {},
};

StageList N(stageTable) = {
    { "omo_07", &N(omo_07) },
    {},
};
