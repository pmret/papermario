#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_hos

extern ActorDesc N(goombario_tutor);
extern ActorDesc N(ember);
extern ActorDesc N(magikoopa_flying);

extern Stage N(hos_00);
extern Stage N(hos_01);
extern Stage N(hos_02);

Formation N(formation_00) = {
    { .actor = &N(goombario_tutor), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(ember), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("クリオ（ＡＣヘルプ）", N(formation_00), &N(hos_02)),
    BATTLE("エルモスx２", N(formation_01), &N(hos_01)),
    BATTLE("エルモスx３", N(formation_02), &N(hos_01)),
    BATTLE("カメック（ＡＣヘルプご）", N(formation_03), &N(hos_02)),
    {},
};

StageList N(stageTable) = {
    { "hos_00", &N(hos_00) },
    { "hos_01", &N(hos_01) },
    { "hos_02", &N(hos_02) },
    {},
};
