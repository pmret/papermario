#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1

extern ActorBlueprint N(pokey_mummy);
extern ActorBlueprint N(swooper);
extern ActorBlueprint N(stone_chomp);
extern ActorBlueprint N(buzzy_beetle);

extern Stage N(isk_00);
extern Stage N(isk_01);
extern Stage N(isk_02);
extern Stage N(isk_02b);
extern Stage N(isk_02c);
extern Stage N(isk_03);
extern Stage N(isk_03b);
extern Stage N(isk_04);
extern Stage N(isk_05);
extern Stage N(isk_06);
extern Stage N(isk_06b);
extern Stage N(isk_07);
extern Stage N(isk_08);

Vec3i N(vector3D_80224070) = { 15, 133, -25 };
Vec3i N(vector3D_8022407C) = { 55, 133, -25 };
Vec3i N(vector3D_80224088) = { 95, 133, -25 };
Vec3i N(vector3D_80224094) = { 135, 133, -25 };

Vec3i N(vector3D_802240A0) = { 15, 112, -25 };
Vec3i N(vector3D_802240AC) = { 55, 112, -25 };
Vec3i N(vector3D_802240B8) = { 95, 112, -25 };
Vec3i N(vector3D_802240C4) = { 135, 112, -25 };

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_B, 9),
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_B, 9),
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Vec3i N(vector3D_802241E8) = { 80, 133, -25 };

Vec3i N(vector3D_802241F4) = { 115, 133, -25 };

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(pokey_mummy), BTL_POS_GROUND_B, 9),
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241E8) }, .priority = 8 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241F4) }, .priority = 7 },
};

Formation N(Formation_05) = {
    ACTOR_BY_POS(N(swooper), N(vector3D_8022407C), 10),
    ACTOR_BY_POS(N(swooper), N(vector3D_80224088), 9),
};

Formation N(Formation_06) = {
    ACTOR_BY_POS(N(swooper), N(vector3D_80224070), 10),
    ACTOR_BY_POS(N(swooper), N(vector3D_8022407C), 9),
    ACTOR_BY_POS(N(swooper), N(vector3D_80224088), 8),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(stone_chomp), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(stone_chomp), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(stone_chomp), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(stone_chomp), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(stone_chomp), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_A, 10),
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 8 },
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 10),
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 9 },
};

Formation N(Formation_0D) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 10),
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9, .var0 = 1 },
};

Formation N(Formation_0F) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9,  .var0 = 1 },
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_A, 10),
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8, .var0 = 1 },
};

Formation N(Formation_11) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240A0) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9,  .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8,  .var0 = 1 },
};

Vec3i N(vector3D_8022460C) = { 0, 112, -25 };

Vec3i N(vector3D_80224618) = { 40, 112, -25 };

Vec3i N(vector3D_80224624) = { 80, 112, -25 };

Vec3i N(vector3D_80224630) = { 120, 112, -25 };

Formation N(Formation_12) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_8022460C) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224618) }, .priority = 9, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224624) }, .priority = 8, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224630) }, .priority = 7, .var0 = 1 },
};

Formation N(Formation_13) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240A0) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    ACTOR_BY_POS(N(swooper), N(vector3D_802240B8), 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(isk_02b), "サンボマミーx２"),
    BATTLE(N(Formation_01), N(isk_02b), "サンボマミーx３"),
    BATTLE(N(Formation_02), N(isk_04), "サンボマミー,バサバサ"),
    BATTLE(N(Formation_03), N(isk_04), "サンボマミーx２,バサバサ"),
    BATTLE(N(Formation_04), N(isk_04), "サンボマミーx２,バサバサx２"),
    BATTLE(N(Formation_05), N(isk_04), "バサバサx２"),
    BATTLE(N(Formation_06), N(isk_04), "バサバサx３"),
    BATTLE(N(Formation_07), N(isk_02b), "ストーンワンワンx２"),
    BATTLE(N(Formation_08), N(isk_02b), "ストーンワンワンx３"),
    BATTLE(N(Formation_09), N(isk_02b), "メットx２"),
    BATTLE(N(Formation_0A), N(isk_02b), "メットx４"),
    BATTLE(N(Formation_0B), N(isk_05), "メット,メット（てんじょう）,バサバサ"),
    BATTLE(N(Formation_0C), N(isk_05), "メット,バサバサ"),
    BATTLE(N(Formation_0D), N(isk_05), "メット（てんじょう）,メット"),
    BATTLE(N(Formation_0E), N(isk_05), "メット,メット(てんじょう)"),
    BATTLE(N(Formation_0F), N(isk_05), "メット(てんじょう)x２"),
    BATTLE(N(Formation_10), N(isk_05), "メット,メット(てんじょう)x２"),
    BATTLE(N(Formation_11), N(isk_05), "メット(てんじょう)x３"),
    BATTLE(N(Formation_12), N(isk_05), "メット(てんじょう)x４"),
    BATTLE(N(Formation_13), N(isk_05), "メット(てんじょう)x２,バサバサ"),
    {},
};

StageList N(Stages) = {
    { "isk_00",  &N(isk_00) },
    { "isk_01",  &N(isk_01) },
    { "isk_02",  &N(isk_02) },
    STAGE("isk_02b", N(isk_02b)),
    STAGE("isk_02c", N(isk_02c)),
    { "isk_03",  &N(isk_03) },
    STAGE("isk_03b", N(isk_03b)),
    { "isk_04",  &N(isk_04) },
    { "isk_05",  &N(isk_05) },
    { "isk_06",  &N(isk_06) },
    STAGE("isk_06b", N(isk_06b)),
    { "isk_07",  &N(isk_07) },
    { "isk_08",  &N(isk_08) },
    {},
};
