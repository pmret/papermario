#include "area.h"

extern ActorBlueprint A(cleft);
extern ActorBlueprint A(monty_mole);
extern ActorBlueprint A(whacka);
extern ActorBlueprint A(buzzar);

extern Stage A(iwa_01);
extern Stage A(iwa_01b);
extern Stage A(iwa_02);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_C, 8),
};

Vec3i A(BossPos) = { 90, 70, 0 };

Formation A(Formation_0C) = {
    ACTOR_BY_POS(A(buzzar), A(BossPos), 10),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(whacka), BTL_POS_GROUND_C, 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(iwa_01), "シンエモン"),
    BATTLE(A(Formation_01), A(iwa_01), "シンエモンx２"),
    BATTLE(A(Formation_02), A(iwa_01), "シンエモンx３"),
    BATTLE(A(Formation_03), A(iwa_01), "シンエモン,チョロプー"),
    BATTLE(A(Formation_04), A(iwa_01), "シンエモン,チョロプーx２"),
    BATTLE(A(Formation_05), A(iwa_01), "チョロプー"),
    BATTLE(A(Formation_06), A(iwa_01), "チョロプーx２"),
    BATTLE(A(Formation_07), A(iwa_01), "チョロプーx３"),
    BATTLE(A(Formation_08), A(iwa_01), "チョロプーx４"),
    BATTLE(A(Formation_09), A(iwa_01), "チョロプー,シンエモン"),
    BATTLE(A(Formation_0A), A(iwa_01), "チョロプーx２,シンエモン"),
    BATTLE(A(Formation_0B), A(iwa_01), "チョロプー,シンエモン,チョロプー"),
    BATTLE(A(Formation_0C), A(iwa_02), "ゲーハー"),
    BATTLE(A(Formation_0D), A(iwa_02), "コブロン"),
    {},
};

StageList A(Stages) = {
    STAGE("iwa_01", A(iwa_01)),
    STAGE("iwa_01b", A(iwa_01b)),
    STAGE("iwa_02", A(iwa_02)),
    {},
};
