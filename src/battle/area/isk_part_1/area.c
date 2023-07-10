#include "area.h"

extern ActorBlueprint A(pokey_mummy);
extern ActorBlueprint A(swooper);
extern ActorBlueprint A(stone_chomp);
extern ActorBlueprint A(buzzy_beetle);

extern Stage A(isk_00);
extern Stage A(isk_01);
extern Stage A(isk_02);
extern Stage A(isk_02b);
extern Stage A(isk_02c);
extern Stage A(isk_03);
extern Stage A(isk_03b);
extern Stage A(isk_04);
extern Stage A(isk_05);
extern Stage A(isk_06);
extern Stage A(isk_06b);
extern Stage A(isk_07);
extern Stage A(isk_08);

Vec3i A(vector3D_80224070) = { 15, 133, -25 };
Vec3i A(vector3D_8022407C) = { 55, 133, -25 };
Vec3i A(vector3D_80224088) = { 95, 133, -25 };
Vec3i A(vector3D_80224094) = { 135, 133, -25 };

Vec3i A(vector3D_802240A0) = { 15, 112, -25 };
Vec3i A(vector3D_802240AC) = { 55, 112, -25 };
Vec3i A(vector3D_802240B8) = { 95, 112, -25 };
Vec3i A(vector3D_802240C4) = { 135, 112, -25 };

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(A(swooper), A(vector3D_80224088), 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(A(swooper), A(vector3D_80224088), 8),
};

Vec3i A(vector3D_802241E8) = { 80, 133, -25 };
Vec3i A(vector3D_802241F4) = { 115, 133, -25 };

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(pokey_mummy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(A(swooper), A(vector3D_802241E8), 8),
    ACTOR_BY_POS(A(swooper), A(vector3D_802241F4), 7),
};

Formation A(Formation_05) = {
    ACTOR_BY_POS(A(swooper), A(vector3D_8022407C), 10),
    ACTOR_BY_POS(A(swooper), A(vector3D_80224088), 9),
};

Formation A(Formation_06) = {
    ACTOR_BY_POS(A(swooper), A(vector3D_80224070), 10),
    ACTOR_BY_POS(A(swooper), A(vector3D_8022407C), 9),
    ACTOR_BY_POS(A(swooper), A(vector3D_80224088), 8),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(stone_chomp), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(stone_chomp), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(stone_chomp), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(stone_chomp), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(stone_chomp), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 9, 1),
    ACTOR_BY_POS(A(swooper), A(vector3D_802240B8), 8),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 10),
    ACTOR_BY_POS(A(swooper), A(vector3D_802240B8), 9),
};

Formation A(Formation_0D) = {
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 10, 1),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 10),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240B8), 9, 1),
};

Formation A(Formation_0F) = {
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 10, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240B8), 9, 1),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 9, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240B8), 8, 1),
};

Formation A(Formation_11) = {
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240A0), 10, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 9, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240B8), 8, 1),
};

Vec3i A(vector3D_8022460C) = { 0, 112, -25 };

Vec3i A(vector3D_80224618) = { 40, 112, -25 };

Vec3i A(vector3D_80224624) = { 80, 112, -25 };

Vec3i A(vector3D_80224630) = { 120, 112, -25 };

Formation A(Formation_12) = {
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_8022460C), 10, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_80224618), 9, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_80224624), 8, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_80224630), 7, 1),
};

Formation A(Formation_13) = {
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240A0), 10, 1),
    ACTOR_BY_POS(A(buzzy_beetle), A(vector3D_802240AC), 9, 1),
    ACTOR_BY_POS(A(swooper), A(vector3D_802240B8), 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(isk_02b), "サンボマミーx２"),
    BATTLE(A(Formation_01), A(isk_02b), "サンボマミーx３"),
    BATTLE(A(Formation_02), A(isk_04), "サンボマミー,バサバサ"),
    BATTLE(A(Formation_03), A(isk_04), "サンボマミーx２,バサバサ"),
    BATTLE(A(Formation_04), A(isk_04), "サンボマミーx２,バサバサx２"),
    BATTLE(A(Formation_05), A(isk_04), "バサバサx２"),
    BATTLE(A(Formation_06), A(isk_04), "バサバサx３"),
    BATTLE(A(Formation_07), A(isk_02b), "ストーンワンワンx２"),
    BATTLE(A(Formation_08), A(isk_02b), "ストーンワンワンx３"),
    BATTLE(A(Formation_09), A(isk_02b), "メットx２"),
    BATTLE(A(Formation_0A), A(isk_02b), "メットx４"),
    BATTLE(A(Formation_0B), A(isk_05), "メット,メット（てんじょう）,バサバサ"),
    BATTLE(A(Formation_0C), A(isk_05), "メット,バサバサ"),
    BATTLE(A(Formation_0D), A(isk_05), "メット（てんじょう）,メット"),
    BATTLE(A(Formation_0E), A(isk_05), "メット,メット(てんじょう)"),
    BATTLE(A(Formation_0F), A(isk_05), "メット(てんじょう)x２"),
    BATTLE(A(Formation_10), A(isk_05), "メット,メット(てんじょう)x２"),
    BATTLE(A(Formation_11), A(isk_05), "メット(てんじょう)x３"),
    BATTLE(A(Formation_12), A(isk_05), "メット(てんじょう)x４"),
    BATTLE(A(Formation_13), A(isk_05), "メット(てんじょう)x２,バサバサ"),
    {},
};

StageList A(Stages) = {
    STAGE("isk_00", A(isk_00)),
    STAGE("isk_01", A(isk_01)),
    STAGE("isk_02", A(isk_02)),
    STAGE("isk_02b", A(isk_02b)),
    STAGE("isk_02c", A(isk_02c)),
    STAGE("isk_03", A(isk_03)),
    STAGE("isk_03b", A(isk_03b)),
    STAGE("isk_04", A(isk_04)),
    STAGE("isk_05", A(isk_05)),
    STAGE("isk_06", A(isk_06)),
    STAGE("isk_06b", A(isk_06b)),
    STAGE("isk_07", A(isk_07)),
    STAGE("isk_08", A(isk_08)),
    {},
};
