#include "area.h"

extern ActorBlueprint A(clubba);
extern ActorBlueprint A(tubba_blubba);

extern Stage A(dgb_01);
extern Stage A(dgb_02);
extern Stage A(dgb_03);
extern Stage A(dgb_04);
extern Stage A(dgb_05);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(clubba), BTL_POS_GROUND_D, 7),
};

Vec3i A(vector3D_8021B348) = { 75, 0, 10 };

Formation A(Formation_04) = {
    ACTOR_BY_POS(A(tubba_blubba), A(vector3D_8021B348), 10),
};

Formation A(Formation_05) = {
    ACTOR_BY_POS(A(tubba_blubba), A(vector3D_8021B348), 10, 1),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(dgb_01), "ガボンへい"),
    BATTLE(A(Formation_01), A(dgb_01), "ガボンへいx２"),
    BATTLE(A(Formation_02), A(dgb_01), "ガボンへいx３"),
    BATTLE(A(Formation_03), A(dgb_01), "ガボンへいx４"),
    BATTLE(A(Formation_04), A(dgb_01), "むてきドガボン"),
    BATTLE(A(Formation_05), A(dgb_01), "むてきドガボンせりふなし"),
    {},
};

StageList A(Stages) = {
    STAGE("dgb_01", A(dgb_01)),
    STAGE("dgb_02", A(dgb_02)),
    STAGE("dgb_03", A(dgb_03)),
    STAGE("dgb_04", A(dgb_04)),
    STAGE("dgb_05", A(dgb_05)),
    {},
};
