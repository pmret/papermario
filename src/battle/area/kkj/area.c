#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kkj

extern ActorBlueprint N(kammy_koopa);

extern Stage N(kpa_05);

Formation N(Formation_00) = {
    { .actor = &N(kammy_koopa), .home = { .index = 6 }, .priority = 10, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_05), "カメックばば（ピーチ、ティンクせん）"),
    {},
};

StageList N(Stages) = {
    { "kpa_05", &N(kpa_05) },
    {},
};
