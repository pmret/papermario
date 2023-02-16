#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik3

extern ActorBlueprint N(swooper);
extern ActorBlueprint N(swoopula);

extern Stage N(tik_01);
extern Stage N(tik_02);
extern Stage N(tik_03);
extern Stage N(tik_04);
extern Stage N(tik_05);

Formation N(Formation_00) = {
    { .actor = &N(swooper), .home = { .index = 13 }, .priority = 10, },
    { .actor = &N(swooper), .home = { .index = 14 }, .priority = 9, },
};

Formation N(Formation_01) = {
    { .actor = &N(swooper), .home = { .index = 12 }, .priority = 10, },
    { .actor = &N(swooper), .home = { .index = 13 }, .priority = 9, },
    { .actor = &N(swooper), .home = { .index = 14 }, .priority = 8, },
};

Formation N(Formation_02) = {
    { .actor = &N(swoopula), .home = { .index = 13 }, .priority = 10, },
    { .actor = &N(swoopula), .home = { .index = 14 }, .priority = 9, },
};

Formation N(Formation_03) = {
    { .actor = &N(swoopula), .home = { .index = 12 }, .priority = 10, },
    { .actor = &N(swoopula), .home = { .index = 13 }, .priority = 9, },
    { .actor = &N(swoopula), .home = { .index = 14 }, .priority = 8, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(tik_01), "バサバサx２"),
    BATTLE(N(Formation_01), &N(tik_01), "バサバサx３"),
    BATTLE(N(Formation_02), &N(tik_01), "バサバサチュルルx２"),
    BATTLE(N(Formation_03), &N(tik_01), "バサバサチュルルx３"),
    {},
};

StageList N(Stages) = {
    { "tik_01", &N(tik_01) },
    { "tik_02", &N(tik_02) },
    { "tik_03", &N(tik_03) },
    { "tik_04", &N(tik_04) },
    { "tik_05", &N(tik_05) },
    {},
};
