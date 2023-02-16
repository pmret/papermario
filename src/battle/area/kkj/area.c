#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kkj

extern ActorBlueprint N(kammy_koopa);

extern Stage N(kpa_05);

Formation N(formation_00) = {
    { .actor = &N(kammy_koopa), .home = { .index = 6 }, .priority = 10, },
};

BattleList N(formationTable) = {
    BATTLE("カメックばば（ピーチ、ティンクせん）", N(formation_00), &N(kpa_05)),
    {},
};

StageList N(stageTable) = {
    { "kpa_05", &N(kpa_05) },
    {},
};
