#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kgr

extern ActorBlueprint N(fuzzipede);

extern Stage N(kgr_01);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(fuzzipede), BTL_POS_GROUND_C, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(kgr_01), "ケムシ"),
    {},
};

StageList N(Stages) = {
    STAGE("kgr_01", N(kgr_01)),
    {},
};
