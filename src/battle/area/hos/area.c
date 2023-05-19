#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_hos

extern ActorBlueprint N(goombario_tutor);
extern ActorBlueprint N(ember);
extern ActorBlueprint N(magikoopa_flying);

extern Stage N(hos_00);
extern Stage N(hos_01);
extern Stage N(hos_02);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(goombario_tutor), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(ember), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(ember), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(ember), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(ember), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(ember), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(magikoopa_flying), BTL_POS_AIR_B, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(hos_02), "クリオ（ＡＣヘルプ）"),
    BATTLE(N(Formation_01), &N(hos_01), "エルモスx２"),
    BATTLE(N(Formation_02), &N(hos_01), "エルモスx３"),
    BATTLE(N(Formation_03), &N(hos_02), "カメック（ＡＣヘルプご）"),
    {},
};

StageList N(Stages) = {
    { "hos_00", &N(hos_00) },
    { "hos_01", &N(hos_01) },
    { "hos_02", &N(hos_02) },
    {},
};
