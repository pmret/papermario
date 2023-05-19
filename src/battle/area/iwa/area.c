#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_iwa

extern ActorBlueprint N(cleft);
extern ActorBlueprint N(monty_mole);
extern ActorBlueprint N(whacka);
extern ActorBlueprint N(buzzar);

extern Stage N(iwa_01);
extern Stage N(iwa_01b);
extern Stage N(iwa_02);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_C, 8),
};

Vec3i N(vector3D_8021853C) = { 90, 70, 0, };

Formation N(Formation_0C) = {
    ACTOR_BY_POS(N(buzzar), N(vector3D_8021853C), 10),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(monty_mole), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(whacka), BTL_POS_GROUND_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(iwa_01), "シンエモン"),
    BATTLE(N(Formation_01), N(iwa_01), "シンエモンx２"),
    BATTLE(N(Formation_02), N(iwa_01), "シンエモンx３"),
    BATTLE(N(Formation_03), N(iwa_01), "シンエモン,チョロプー"),
    BATTLE(N(Formation_04), N(iwa_01), "シンエモン,チョロプーx２"),
    BATTLE(N(Formation_05), N(iwa_01), "チョロプー"),
    BATTLE(N(Formation_06), N(iwa_01), "チョロプーx２"),
    BATTLE(N(Formation_07), N(iwa_01), "チョロプーx３"),
    BATTLE(N(Formation_08), N(iwa_01), "チョロプーx４"),
    BATTLE(N(Formation_09), N(iwa_01), "チョロプー,シンエモン"),
    BATTLE(N(Formation_0A), N(iwa_01), "チョロプーx２,シンエモン"),
    BATTLE(N(Formation_0B), N(iwa_01), "チョロプー,シンエモン,チョロプー"),
    BATTLE(N(Formation_0C), N(iwa_02), "ゲーハー"),
    BATTLE(N(Formation_0D), N(iwa_02), "コブロン"),
    {},
};

StageList N(Stages) = {
    { "iwa_01",  &N(iwa_01) },
    STAGE("iwa_01b", N(iwa_01b)),
    { "iwa_02",  &N(iwa_02) },
    {},
};
