#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra2

extern ActorBlueprint N(crystal_king);
extern ActorBlueprint N(crystal_bit_1);
extern ActorBlueprint N(crystal_bit_2);
extern ActorBlueprint N(crystal_bit_3);

extern Stage N(sam_04);

Vec3i N(pos_crystal_king) = { 70, 0, 5 };

Vec3i N(pos_crystal_bit_1) = { 10, 35, -5 };

Vec3i N(pos_crystal_bit_2) = { 112, 52, -5 };

Vec3i N(pos_crystal_bit_3) = { 42, 85, -10 };

Formation N(Formation_01) = {
    ACTOR_BY_POS(N(crystal_king), N(pos_crystal_king), 10),
    ACTOR_BY_POS(N(crystal_bit_1), N(pos_crystal_bit_1), 9),
    ACTOR_BY_POS(N(crystal_bit_2), N(pos_crystal_bit_2), 8),
    ACTOR_BY_POS(N(crystal_bit_3), N(pos_crystal_bit_3), 7),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), N(sam_04), "パラレラー"),
    {},
};

StageList N(Stages) = {
    STAGE("sam_04", N(sam_04)),
    {},
};
