#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb

extern ActorBlueprint N(clubba);
extern ActorBlueprint N(tubba_blubba);

extern Stage N(dgb_01);
extern Stage N(dgb_02);
extern Stage N(dgb_03);
extern Stage N(dgb_04);
extern Stage N(dgb_05);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(clubba), BTL_POS_GROUND_D, 7),
};

Vec3i N(vector3D_8021B348) = { 75, 0, 10 };

Formation N(Formation_04) = {
    ACTOR_BY_POS(N(tubba_blubba), N(vector3D_8021B348), 10),
};

Formation N(Formation_05) = {
    ACTOR_BY_POS(N(tubba_blubba), N(vector3D_8021B348), 10, 1),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(dgb_01), "ガボンへい"),
    BATTLE(N(Formation_01), N(dgb_01), "ガボンへいx２"),
    BATTLE(N(Formation_02), N(dgb_01), "ガボンへいx３"),
    BATTLE(N(Formation_03), N(dgb_01), "ガボンへいx４"),
    BATTLE(N(Formation_04), N(dgb_01), "むてきドガボン"),
    BATTLE(N(Formation_05), N(dgb_01), "むてきドガボンせりふなし"),
    {},
};

StageList N(Stages) = {
    STAGE("dgb_01", N(dgb_01)),
    STAGE("dgb_02", N(dgb_02)),
    STAGE("dgb_03", N(dgb_03)),
    STAGE("dgb_04", N(dgb_04)),
    STAGE("dgb_05", N(dgb_05)),
    {},
};
