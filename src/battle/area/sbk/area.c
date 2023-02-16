#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_sbk

extern ActorBlueprint N(pokey);
extern ActorBlueprint N(bandit);

extern Stage N(sbk_02);

Formation N(Formation_00) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(pokey), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(pokey), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_04) = {
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_05) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_06) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bandit), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_07) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey),  .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_09) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_0A) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0B) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0C) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bandit), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0D) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0E) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0F) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey),  .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_10) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(sbk_02), "サンボ"),
    BATTLE(N(Formation_01), &N(sbk_02), "サンボx2"),
    BATTLE(N(Formation_02), &N(sbk_02), "サンボx3"),
    BATTLE(N(Formation_03), &N(sbk_02), "きいろサンボx4"),
    BATTLE(N(Formation_04), &N(sbk_02), "サンボ,ボロドー"),
    BATTLE(N(Formation_05), &N(sbk_02), "サンボx2,ボロドー"),
    BATTLE(N(Formation_06), &N(sbk_02), "サンボx2,ボロドーx2"),
    BATTLE(N(Formation_07), &N(sbk_02), "サンボ,ボロドー,サンボ"),
    BATTLE(N(Formation_08), &N(sbk_02), "サンボx2,ボロドー,サンボ"),
    BATTLE(N(Formation_09), &N(sbk_02), "ボロドー"),
    BATTLE(N(Formation_0A), &N(sbk_02), "ボロドーx2"),
    BATTLE(N(Formation_0B), &N(sbk_02), "ボロドーx3"),
    BATTLE(N(Formation_0C), &N(sbk_02), "ボロドーx4"),
    BATTLE(N(Formation_0D), &N(sbk_02), "ボロドー,サンボ"),
    BATTLE(N(Formation_0E), &N(sbk_02), "ボロドーx2,サンボ"),
    BATTLE(N(Formation_0F), &N(sbk_02), "ボロドーx2,サンボx2"),
    BATTLE(N(Formation_10), &N(sbk_02), "ボロドー,サンボ,ボロドー"),
    {},
};

StageList N(Stages) = {
    { "sbk_01", &N(sbk_02) },
    {},
};
