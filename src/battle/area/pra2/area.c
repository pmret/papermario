#include "area.h"

extern ActorBlueprint A(crystal_king);
extern ActorBlueprint A(crystal_bit_cube);
extern ActorBlueprint A(crystal_bit_sphere);
extern ActorBlueprint A(crystal_bit_prism);

extern Stage A(sam_04);

Vec3i A(KingPos) = { 70, 0, 5 };

Vec3i A(CrystalBitPos1) = {  10, 35,  -5 };
Vec3i A(CrystalBitPos2) = { 112, 52,  -5 };
Vec3i A(CrystalBitPos3) = {  42, 85, -10 };

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(crystal_king), A(KingPos), 10),
    ACTOR_BY_POS(A(crystal_bit_cube), A(CrystalBitPos1), 9),
    ACTOR_BY_POS(A(crystal_bit_sphere), A(CrystalBitPos2), 8),
    ACTOR_BY_POS(A(crystal_bit_prism), A(CrystalBitPos3), 7),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(sam_04), "パラレラー"),
    {},
};

StageList A(Stages) = {
    STAGE("sam_04", A(sam_04)),
    {},
};
