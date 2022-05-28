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

Formation N(formation_01) = {
    { .actor = &N(crystal_king), .home = { .vec = &N(pos_crystal_king) }, .priority = 10 },
    { .actor = &N(crystal_bit_1), .home = { .vec = &N(pos_crystal_bit_1) }, .priority = 9 },
    { .actor = &N(crystal_bit_2), .home = { .vec = &N(pos_crystal_bit_2) }, .priority = 8 },
    { .actor = &N(crystal_bit_3), .home = { .vec = &N(pos_crystal_bit_3) }, .priority = 7 },
};

BattleList N(formationTable) = {
    BATTLE("パラレラー", N(formation_01), &N(sam_04)),
    {},
};

StageList N(stageTable) = {
    { "sam_04", &N(sam_04) },
    {},
};
