#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kkj

extern ActorBlueprint N(kammy_koopa);

extern Stage N(kpa_05);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(kammy_koopa), BTL_POS_AIR_C, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_05), "カメックばば（ピーチ、ティンクせん）"),
    {},
};

StageList N(Stages) = {
    { "kpa_05", &N(kpa_05) },
    {},
};
