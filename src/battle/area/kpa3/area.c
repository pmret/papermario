#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa3

extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(anti_guy);

extern Stage N(kpa_01);

Formation N(formation_00) = {
    { .actor = &N(anti_guy), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(anti_guy), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(anti_guy), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_01) = {
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_02) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(duplighost), .home = { .index = 3 }, .priority = 7, },
};

BattleList N(formationTable) = {
    BATTLE("ブラックヘイホーx３", N(formation_00), &N(kpa_01)),
    BATTLE("バケバケx２", N(formation_01), &N(kpa_01)),
    BATTLE("バケバケx４", N(formation_02), &N(kpa_01)),
    {},
};

StageList N(stageTable) = {
    { "kpa_01", &N(kpa_01) },
    {},
};
