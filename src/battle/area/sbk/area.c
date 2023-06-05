#include "area.h"

extern ActorBlueprint A(pokey);
extern ActorBlueprint A(bandit);

extern Stage A(sbk_02);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bandit), BTL_POS_GROUND_C, 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(sbk_02), "サンボ"),
    BATTLE(A(Formation_01), A(sbk_02), "サンボx2"),
    BATTLE(A(Formation_02), A(sbk_02), "サンボx3"),
    BATTLE(A(Formation_03), A(sbk_02), "きいろサンボx4"),
    BATTLE(A(Formation_04), A(sbk_02), "サンボ,ボロドー"),
    BATTLE(A(Formation_05), A(sbk_02), "サンボx2,ボロドー"),
    BATTLE(A(Formation_06), A(sbk_02), "サンボx2,ボロドーx2"),
    BATTLE(A(Formation_07), A(sbk_02), "サンボ,ボロドー,サンボ"),
    BATTLE(A(Formation_08), A(sbk_02), "サンボx2,ボロドー,サンボ"),
    BATTLE(A(Formation_09), A(sbk_02), "ボロドー"),
    BATTLE(A(Formation_0A), A(sbk_02), "ボロドーx2"),
    BATTLE(A(Formation_0B), A(sbk_02), "ボロドーx3"),
    BATTLE(A(Formation_0C), A(sbk_02), "ボロドーx4"),
    BATTLE(A(Formation_0D), A(sbk_02), "ボロドー,サンボ"),
    BATTLE(A(Formation_0E), A(sbk_02), "ボロドーx2,サンボ"),
    BATTLE(A(Formation_0F), A(sbk_02), "ボロドーx2,サンボx2"),
    BATTLE(A(Formation_10), A(sbk_02), "ボロドー,サンボ,ボロドー"),
    {},
};

StageList A(Stages) = {
    STAGE("sbk_01", A(sbk_02)),
    {},
};
