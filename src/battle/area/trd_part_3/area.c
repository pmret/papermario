#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_trd_part_3

extern ActorBlueprint N(eldstar);

extern Stage N(nok_01);

Formation N(Formation_00) = {
    { .actor = &N(eldstar), .home = { .index = 6 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(nok_01), "ほしのせい レクチャー"),
    {},
};

StageList N(Stages) = {
    { "nok_01", &N(nok_01) },
    {},
};
