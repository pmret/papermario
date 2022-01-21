#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kgr

extern ActorBlueprint N(fuzzipede);

extern Stage N(kgr_01);

Formation N(formation_00) = {
    { .actor = &N(fuzzipede), .home = { .index = 2 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("ケムシ", N(formation_00), &N(kgr_01)),
    {},
};

StageList N(stageTable) = {
    { "kgr_01", &N(kgr_01) },
    {},
};
