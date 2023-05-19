#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa3

extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(anti_guy);

extern Stage N(kpa_01);

Formation N(Formation_00) = {
    { .actor = &N(anti_guy), .home = { .index = BTL_POS_GROUND_A }, .priority = 10, },
    { .actor = &N(anti_guy), .home = { .index = BTL_POS_GROUND_B }, .priority = 9, },
    { .actor = &N(anti_guy), .home = { .index = BTL_POS_GROUND_C }, .priority = 8, },
};

Formation N(Formation_01) = {
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_B }, .priority = 10, },
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_C }, .priority = 9, },
};

Formation N(Formation_02) = {
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_A }, .priority = 10, },
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_B }, .priority = 9, },
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_C }, .priority = 8, },
    { .actor = &N(duplighost), .home = { .index = BTL_POS_GROUND_D }, .priority = 7, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_01), "ブラックヘイホーx３"),
    BATTLE(N(Formation_01), &N(kpa_01), "バケバケx２"),
    BATTLE(N(Formation_02), &N(kpa_01), "バケバケx４"),
    {},
};

StageList N(Stages) = {
    { "kpa_01", &N(kpa_01) },
    {},
};
