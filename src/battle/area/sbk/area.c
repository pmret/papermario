#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_sbk

extern ActorBlueprint N(pokey);
extern ActorBlueprint N(bandit);

extern Stage N(sbk_02);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(pokey), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_04) = {
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_05) = {
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_06) = {
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_07) = {
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 9),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_D }, .priority = 7 },
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 10),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 9),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_B, 9),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_D }, .priority = 7 },
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_A, 10),
    { .actor = &N(pokey),  .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    ACTOR_BY_IDX(N(bandit), BTL_POS_GROUND_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(sbk_02), "サンボ"),
    BATTLE(N(Formation_01), N(sbk_02), "サンボx2"),
    BATTLE(N(Formation_02), N(sbk_02), "サンボx3"),
    BATTLE(N(Formation_03), N(sbk_02), "きいろサンボx4"),
    BATTLE(N(Formation_04), N(sbk_02), "サンボ,ボロドー"),
    BATTLE(N(Formation_05), N(sbk_02), "サンボx2,ボロドー"),
    BATTLE(N(Formation_06), N(sbk_02), "サンボx2,ボロドーx2"),
    BATTLE(N(Formation_07), N(sbk_02), "サンボ,ボロドー,サンボ"),
    BATTLE(N(Formation_08), N(sbk_02), "サンボx2,ボロドー,サンボ"),
    BATTLE(N(Formation_09), N(sbk_02), "ボロドー"),
    BATTLE(N(Formation_0A), N(sbk_02), "ボロドーx2"),
    BATTLE(N(Formation_0B), N(sbk_02), "ボロドーx3"),
    BATTLE(N(Formation_0C), N(sbk_02), "ボロドーx4"),
    BATTLE(N(Formation_0D), N(sbk_02), "ボロドー,サンボ"),
    BATTLE(N(Formation_0E), N(sbk_02), "ボロドーx2,サンボ"),
    BATTLE(N(Formation_0F), N(sbk_02), "ボロドーx2,サンボx2"),
    BATTLE(N(Formation_10), N(sbk_02), "ボロドー,サンボ,ボロドー"),
    {},
};

StageList N(Stages) = {
    STAGE("sbk_01", N(sbk_02)),
    {},
};
