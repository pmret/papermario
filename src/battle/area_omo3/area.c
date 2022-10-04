#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_omo3

extern Stage N(omo_01);
extern Stage N(omo_02);
extern Stage N(omo_03);
extern Stage N(omo_03b);
extern Stage N(omo_04);
extern Stage N(omo_05);
extern Stage N(omo_05b);
extern Stage N(omo_06);
extern Stage N(omo_07);

extern ActorBlueprint N(big_lantern_ghost);
extern ActorBlueprint N(goomba);
extern ActorBlueprint N(clubba);
extern ActorBlueprint N(fuzzy);
extern ActorBlueprint N(hammer_bro);
extern ActorBlueprint N(pokey);
extern ActorBlueprint N(koopatrol);
extern ActorBlueprint N(red_shy_guy);

Vec3i N(big_lantern_ghost_pos) = { 30, 0, 10 };

Formation N(formation_00) = {
    { .actor = &N(big_lantern_ghost), .home = { .vec = &N(big_lantern_ghost_pos) }, .priority = 10, },
};

Formation N(formation_01) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_02) = {
    { .actor = &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_03) = {
    { .actor = &N(clubba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(clubba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_04) = {
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_05) = {
    { .actor = &N(fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_06) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hammer_bro), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_07) = {
    { .actor = &N(hammer_bro), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_08) = {
    { .actor = &N(pokey), .home = { .index = 1 }, .priority = 10, .var1 = 1 },
    { .actor = &N(pokey), .home = { .index = 2 }, .priority = 9, .var1 = 1 },
};

Formation N(formation_09) = {
    { .actor = &N(koopatrol), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopatrol), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0A) = {
    { .actor = &N(red_shy_guy), .home = { .index = 1 }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("ビッグカンテラくん", N(formation_00), &N(omo_03)),
    BATTLE("クリボー（ピーチへん）", N(formation_01), &N(omo_04)),
    BATTLE("クリボーx２（ピーチへん）", N(formation_02), &N(omo_04)),
    BATTLE("ガボンへいx２（ピーチへん）", N(formation_03), &N(omo_04)),
    BATTLE("チョロボンx２（ピーチへん）", N(formation_04), &N(omo_04)),
    BATTLE("チョロボンx４（ピーチへん）", N(formation_05), &N(omo_04)),
    BATTLE("ハンマーブロスx２（ピーチへん）", N(formation_06), &N(omo_04)),
    BATTLE("ハンマーブロス（ピーチへん）", N(formation_07), &N(omo_04)),
    BATTLE("サンボx２（ピーチへん）", N(formation_08), &N(omo_04)),
    BATTLE("トゲノコx２（ピーチへん）", N(formation_09), &N(omo_04)),
    BATTLE("ヘイホー", N(formation_0A), &N(omo_01)),
    {},
};

StageList N(stageTable) = {
    { "omo_01", &N(omo_01) },
    { "omo_02", &N(omo_02) },
    { "omo_03", &N(omo_03) },
    { "omo_03b", &N(omo_03b) },
    { "omo_04", &N(omo_04) },
    { "omo_05", &N(omo_05) },
    { "omo_05b", &N(omo_05b) },
    { "omo_06", &N(omo_06) },
    { "omo_07", &N(omo_07) },
    {},
};
