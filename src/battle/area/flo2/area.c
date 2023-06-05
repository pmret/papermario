#include "area.h"

extern ActorBlueprint A(huff_n_puff);
extern ActorBlueprint A(monty_mole_boss);
extern ActorBlueprint A(spike);

extern Stage A(flo_01);
extern Stage A(flo_01b);
extern Stage A(flo_01c);
extern Stage A(flo_02);
extern Stage A(flo_02b);
extern Stage A(flo_02c);
extern Stage A(flo_03);
extern Stage A(flo_04);
extern Stage A(flo_05);
extern Stage A(flo_06);

Vec3i A(huff_n_puff_pos) = { 80, 80, 0 };

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(huff_n_puff), A(huff_n_puff_pos), 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(monty_mole_boss), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(spike), BTL_POS_AIR_B, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(flo_04), "オズモーン"),
    BATTLE(A(Formation_02), A(flo_01), "フラワーチョロプー"),
    BATTLE(A(Formation_03), A(flo_01), "フラワーチョロプーx２"),
    BATTLE(A(Formation_04), A(flo_01), "フラワーチョロプーx３"),
    BATTLE(A(Formation_05), A(flo_01), "フラワーチョロプーx４"),
    BATTLE(A(Formation_06), A(flo_01), "ジョナサン？"),
    {},
};

StageList A(Stages) = {
    STAGE("flo_01", A(flo_01)),
    STAGE("flo_01b", A(flo_01b)),
    STAGE("flo_01c", A(flo_01c)),
    STAGE("flo_02", A(flo_02)),
    STAGE("flo_02b", A(flo_02b)),
    STAGE("flo_02c", A(flo_02c)),
    STAGE("flo_03", A(flo_03)),
    STAGE("flo_04", A(flo_04)),
    STAGE("flo_05", A(flo_05)),
    STAGE("flo_06", A(flo_06)),
    {},
};
