#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa3

extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(anti_guy);

extern Stage N(kpa_01);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(anti_guy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(anti_guy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(anti_guy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_D, 7),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(kpa_01), "ブラックヘイホーx３"),
    BATTLE(N(Formation_01), N(kpa_01), "バケバケx２"),
    BATTLE(N(Formation_02), N(kpa_01), "バケバケx４"),
    {},
};

StageList N(Stages) = {
    STAGE("kpa_01", N(kpa_01)),
    {},
};
