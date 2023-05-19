#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo2

extern ActorBlueprint N(general_guy);
extern ActorBlueprint N(toy_tank);
extern ActorBlueprint N(light_bulb);

extern Stage N(omo_07);

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(general_guy), BTL_POS_GROUND_C, 70),
    ACTOR_BY_IDX(N(toy_tank), BTL_POS_GROUND_B, 80),
    ACTOR_BY_IDX(N(light_bulb), BTL_POS_AIR_D, 90),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), N(omo_07), "しょうぐんヘイホー"),
    {},
};

StageList N(Stages) = {
    STAGE("omo_07", N(omo_07)),
    {},
};
