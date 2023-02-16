#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_hos

extern ActorBlueprint N(goombario_tutor);
extern ActorBlueprint N(ember);
extern ActorBlueprint N(magikoopa_flying);

extern Stage N(hos_00);
extern Stage N(hos_01);
extern Stage N(hos_02);

Formation N(Formation_00) = {
    { .actor = &N(goombario_tutor), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(ember), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(ember), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(ember), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(magikoopa_flying), .home = { .index = 5 }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(hos_02), "クリオ（ＡＣヘルプ）"),
    BATTLE(N(Formation_01), &N(hos_01), "エルモスx２"),
    BATTLE(N(Formation_02), &N(hos_01), "エルモスx３"),
    BATTLE(N(Formation_03), &N(hos_02), "カメック（ＡＣヘルプご）"),
    {},
};

StageList N(Stages) = {
    { "hos_00", &N(hos_00) },
    { "hos_01", &N(hos_01) },
    { "hos_02", &N(hos_02) },
    {},
};
