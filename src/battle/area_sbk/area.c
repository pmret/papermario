#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_sbk

extern ActorDesc N(pokey);
extern ActorDesc N(bandit);

extern Stage N(sbk_02);

Formation N(formation_00) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(pokey), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(pokey), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_04) = {
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_05) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_06) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bandit), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_07) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_08) = {
    { .actor = &N(pokey),  .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey),  .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_09) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_0A) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0B) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0C) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bandit), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0D) = {
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0E) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0F) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bandit), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey),  .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(pokey),  .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_10) = {
    { .actor = &N(bandit), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bandit), .home = { .index = 2 }, .priority = 8 },
};

BattleList N(formationTable) = {
    BATTLE("サンボ", N(formation_00), &N(sbk_02)),
    BATTLE("サンボx2", N(formation_01), &N(sbk_02)),
    BATTLE("サンボx3", N(formation_02), &N(sbk_02)),
    BATTLE("きいろサンボx4", N(formation_03), &N(sbk_02)),
    BATTLE("サンボ,ボロドー", N(formation_04), &N(sbk_02)),
    BATTLE("サンボx2,ボロドー", N(formation_05), &N(sbk_02)),
    BATTLE("サンボx2,ボロドーx2", N(formation_06), &N(sbk_02)),
    BATTLE("サンボ,ボロドー,サンボ", N(formation_07), &N(sbk_02)),
    BATTLE("サンボx2,ボロドー,サンボ", N(formation_08), &N(sbk_02)),
    BATTLE("ボロドー", N(formation_09), &N(sbk_02)),
    BATTLE("ボロドーx2", N(formation_0A), &N(sbk_02)),
    BATTLE("ボロドーx3", N(formation_0B), &N(sbk_02)),
    BATTLE("ボロドーx4", N(formation_0C), &N(sbk_02)),
    BATTLE("ボロドー,サンボ", N(formation_0D), &N(sbk_02)),
    BATTLE("ボロドーx2,サンボ", N(formation_0E), &N(sbk_02)),
    BATTLE("ボロドーx2,サンボx2", N(formation_0F), &N(sbk_02)),
    BATTLE("ボロドー,サンボ,ボロドー", N(formation_10), &N(sbk_02)),
    {},
};

StageList N(stageTable) = {
    { "sbk_01", &N(sbk_02) },
    {},
};
