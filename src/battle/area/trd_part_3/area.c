#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_trd_part_3

extern ActorBlueprint N(eldstar);

extern Stage N(nok_01);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(eldstar), BTL_POS_AIR_C, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(nok_01), "ほしのせい レクチャー"),
    {},
};

StageList N(Stages) = {
    STAGE("nok_01", N(nok_01)),
    {},
};
