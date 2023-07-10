#include "area.h"

extern ActorBlueprint A(general_guy);
extern ActorBlueprint A(toy_tank);
extern ActorBlueprint A(light_bulb);

extern Stage A(omo_07);

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(general_guy), BTL_POS_GROUND_C, 70),
    ACTOR_BY_IDX(A(toy_tank), BTL_POS_GROUND_B, 80),
    ACTOR_BY_IDX(A(light_bulb), BTL_POS_AIR_D, 90),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(omo_07), "しょうぐんヘイホー"),
    {},
};

StageList A(Stages) = {
    STAGE("omo_07", A(omo_07)),
    {},
};
