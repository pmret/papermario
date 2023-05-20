#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo2

extern ActorBlueprint N(huff_n_puff);
extern ActorBlueprint N(monty_mole_boss);
extern ActorBlueprint N(spike);

extern Stage N(flo_01);
extern Stage N(flo_01b);
extern Stage N(flo_01c);
extern Stage N(flo_02);
extern Stage N(flo_02b);
extern Stage N(flo_02c);
extern Stage N(flo_03);
extern Stage N(flo_04);
extern Stage N(flo_05);
extern Stage N(flo_06);

Vec3i N(huff_n_puff_pos) = { 80, 80, 0 };

Formation N(Formation_01) = {
    ACTOR_BY_POS(N(huff_n_puff), N(huff_n_puff_pos), 10),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(monty_mole_boss), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(spike), BTL_POS_AIR_B, 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), N(flo_04), "オズモーン"),
    BATTLE(N(Formation_02), N(flo_01), "フラワーチョロプー"),
    BATTLE(N(Formation_03), N(flo_01), "フラワーチョロプーx２"),
    BATTLE(N(Formation_04), N(flo_01), "フラワーチョロプーx３"),
    BATTLE(N(Formation_05), N(flo_01), "フラワーチョロプーx４"),
    BATTLE(N(Formation_06), N(flo_01), "ジョナサン？"),
    {},
};

StageList N(Stages) = {
    STAGE("flo_01", N(flo_01)),
    STAGE("flo_01b", N(flo_01b)),
    STAGE("flo_01c", N(flo_01c)),
    STAGE("flo_02", N(flo_02)),
    STAGE("flo_02b", N(flo_02b)),
    STAGE("flo_02c", N(flo_02c)),
    STAGE("flo_03", N(flo_03)),
    STAGE("flo_04", N(flo_04)),
    STAGE("flo_05", N(flo_05)),
    STAGE("flo_06", N(flo_06)),
    {},
};
