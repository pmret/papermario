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
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_01) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey_mummy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_02) = {
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Vec3i N(vector3D_802241E8) = { 80, 133, -25 };

Vec3i N(vector3D_802241F4) = { 115, 133, -25 };

Formation N(Formation_04) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241E8) }, .priority = 8 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241F4) }, .priority = 7 },
};

Formation N(Formation_05) = {
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_8022407C) }, .priority = 10 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224088) }, .priority = 9 },
};

Formation N(Formation_06) = {
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224070) }, .priority = 10 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_8022407C) }, .priority = 9 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(stone_chomp), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(stone_chomp), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_08) = {
    { .actor = &N(stone_chomp), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(stone_chomp), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(stone_chomp), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_09) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0B) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 8 },
};

Formation N(Formation_0C) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 9 },
};

Formation N(Formation_0D) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0E) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9, .var0 = 1 },
};

Formation N(Formation_0F) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9,  .var0 = 1 },
};

Formation N(Formation_10) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
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
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(isk_02b), "サンボマミーx２"),
    BATTLE(N(Formation_01), &N(isk_02b), "サンボマミーx３"),
    BATTLE(N(Formation_02), &N(isk_04), "サンボマミー,バサバサ"),
    BATTLE(N(Formation_03), &N(isk_04), "サンボマミーx２,バサバサ"),
    BATTLE(N(Formation_04), &N(isk_04), "サンボマミーx２,バサバサx２"),
    BATTLE(N(Formation_05), &N(isk_04), "バサバサx２"),
    BATTLE(N(Formation_06), &N(isk_04), "バサバサx３"),
    BATTLE(N(Formation_07), &N(isk_02b), "ストーンワンワンx２"),
    BATTLE(N(Formation_08), &N(isk_02b), "ストーンワンワンx３"),
    BATTLE(N(Formation_09), &N(isk_02b), "メットx２"),
    BATTLE(N(Formation_0A), &N(isk_02b), "メットx４"),
    BATTLE(N(Formation_0B), &N(isk_05), "メット,メット（てんじょう）,バサバサ"),
    BATTLE(N(Formation_0C), &N(isk_05), "メット,バサバサ"),
    BATTLE(N(Formation_0D), &N(isk_05), "メット（てんじょう）,メット"),
    BATTLE(N(Formation_0E), &N(isk_05), "メット,メット(てんじょう)"),
    BATTLE(N(Formation_0F), &N(isk_05), "メット(てんじょう)x２"),
    BATTLE(N(Formation_10), &N(isk_05), "メット,メット(てんじょう)x２"),
    BATTLE(N(Formation_11), &N(isk_05), "メット(てんじょう)x３"),
    BATTLE(N(Formation_12), &N(isk_05), "メット(てんじょう)x４"),
    BATTLE(N(Formation_13), &N(isk_05), "メット(てんじょう)x２,バサバサ"),
    {},
};

StageList N(Stages) = {
    { "isk_00",  &N(isk_00) },
    { "isk_01",  &N(isk_01) },
    { "isk_02",  &N(isk_02) },
    { "isk_02b", &N(isk_02b) },
    { "isk_02c", &N(isk_02c) },
    { "isk_03",  &N(isk_03) },
    { "isk_03b", &N(isk_03b) },
    { "isk_04",  &N(isk_04) },
    { "isk_05",  &N(isk_05) },
    { "isk_06",  &N(isk_06) },
    { "isk_06b", &N(isk_06b) },
    { "isk_07",  &N(isk_07) },
    { "isk_08",  &N(isk_08) },
    {},
};
