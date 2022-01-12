#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_trd_part_3

extern ActorDesc N(eldstar);

extern Stage N(nok_01);

Formation N(formation_00) = {
    { .actor = &N(eldstar), .home = { .index = 6 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("ほしのせい レクチャー",  N(formation_00), &N(nok_01)),
    {},
};

StageList N(stageTable) = {
    { "nok_01", &N(nok_01) },
    {},
};
