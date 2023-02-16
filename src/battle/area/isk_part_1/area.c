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

Formation N(formation_00) = {
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_01) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(pokey_mummy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_02) = {
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Vec3i N(vector3D_802241E8) = { 80, 133, -25 };

Vec3i N(vector3D_802241F4) = { 115, 133, -25 };

Formation N(formation_04) = {
    { .actor = &N(pokey_mummy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(pokey_mummy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241E8) }, .priority = 8 },
    { .actor = &N(swooper),     .home = { .vec = &N(vector3D_802241F4) }, .priority = 7 },
};

Formation N(formation_05) = {
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_8022407C) }, .priority = 10 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224088) }, .priority = 9 },
};

Formation N(formation_06) = {
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224070) }, .priority = 10 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_8022407C) }, .priority = 9 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_80224088) }, .priority = 8 },
};

Formation N(formation_07) = {
    { .actor = &N(stone_chomp), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(stone_chomp), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_08) = {
    { .actor = &N(stone_chomp), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(stone_chomp), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(stone_chomp), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_09) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0A) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0B) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 8 },
};

Formation N(formation_0C) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(swooper),      .home = { .vec = &N(vector3D_802240B8) }, .priority = 9 },
};

Formation N(formation_0D) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0E) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9, .var0 = 1 },
};

Formation N(formation_0F) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 9,  .var0 = 1 },
};

Formation N(formation_10) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8, .var0 = 1 },
};

Formation N(formation_11) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240A0) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9,  .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8,  .var0 = 1 },
};

Vec3i N(vector3D_8022460C) = { 0, 112, -25 };

Vec3i N(vector3D_80224618) = { 40, 112, -25 };

Vec3i N(vector3D_80224624) = { 80, 112, -25 };

Vec3i N(vector3D_80224630) = { 120, 112, -25 };

Formation N(formation_12) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_8022460C) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224618) }, .priority = 9, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224624) }, .priority = 8, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_80224630) }, .priority = 7, .var0 = 1 },
};

Formation N(formation_13) = {
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240A0) }, .priority = 10, .var0 = 1 },
    { .actor = &N(buzzy_beetle), .home = { .vec = &N(vector3D_802240AC) }, .priority = 9, .var0 = 1 },
    { .actor = &N(swooper), .home = { .vec = &N(vector3D_802240B8) }, .priority = 8 },
};

BattleList N(formationTable) = {
    BATTLE("サンボマミーx２", N(formation_00), &N(isk_02b)),
    BATTLE("サンボマミーx３", N(formation_01), &N(isk_02b)),
    BATTLE("サンボマミー,バサバサ", N(formation_02), &N(isk_04)),
    BATTLE("サンボマミーx２,バサバサ", N(formation_03), &N(isk_04)),
    BATTLE("サンボマミーx２,バサバサx２", N(formation_04), &N(isk_04)),
    BATTLE("バサバサx２", N(formation_05), &N(isk_04)),
    BATTLE("バサバサx３", N(formation_06), &N(isk_04)),
    BATTLE("ストーンワンワンx２", N(formation_07), &N(isk_02b)),
    BATTLE("ストーンワンワンx３", N(formation_08), &N(isk_02b)),
    BATTLE("メットx２", N(formation_09), &N(isk_02b)),
    BATTLE("メットx４", N(formation_0A), &N(isk_02b)),
    BATTLE("メット,メット（てんじょう）,バサバサ", N(formation_0B), &N(isk_05)),
    BATTLE("メット,バサバサ", N(formation_0C), &N(isk_05)),
    BATTLE("メット（てんじょう）,メット", N(formation_0D), &N(isk_05)),
    BATTLE("メット,メット(てんじょう)", N(formation_0E), &N(isk_05)),
    BATTLE("メット(てんじょう)x２", N(formation_0F), &N(isk_05)),
    BATTLE("メット,メット(てんじょう)x２", N(formation_10), &N(isk_05)),
    BATTLE("メット(てんじょう)x３", N(formation_11), &N(isk_05)),
    BATTLE("メット(てんじょう)x４", N(formation_12), &N(isk_05)),
    BATTLE("メット(てんじょう)x２,バサバサ", N(formation_13), &N(isk_05)),
    {},
};

StageList N(stageTable) = {
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
