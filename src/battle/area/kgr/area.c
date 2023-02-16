#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kgr

extern ActorBlueprint N(fuzzipede);

extern Stage N(kgr_01);

Formation N(Formation_00) = {
    { .actor = &N(fuzzipede), .home = { .index = 2 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE("ケムシ", N(Formation_00), &N(kgr_01)),
    {},
};

StageList N(Stages) = {
    { "kgr_01", &N(kgr_01) },
    {},
};
