#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kzn

extern ActorBlueprint N(medi_guy);
extern ActorBlueprint N(spike_top);
extern ActorBlueprint N(lava_bubble);
extern ActorBlueprint N(putrid_piranha);
extern ActorBlueprint N(red_magikoopa_flying);
extern ActorBlueprint N(white_magikoopa_flying);

extern Stage N(kzn_01);
extern Stage N(kzn_01b);
extern Stage N(kzn_02);
extern Stage N(kzn_04);
extern Stage N(kzn_04b);
extern Stage N(kzn_04c);
extern Stage N(kzn_05);

Formation N(Formation_00) = {
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_01) = {
    { .actor = &N(lava_bubble), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_02) = {
    { .actor = &N(lava_bubble), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(lava_bubble), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_03) = {
    { .actor = &N(lava_bubble), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),   .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spike_top),   .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spike_top),   .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_04) = {
    { .actor = &N(lava_bubble), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(medi_guy),    .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_05) = {
    { .actor = &N(lava_bubble),          .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble),          .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(red_magikoopa_flying), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_06) = {
    { .actor = &N(lava_bubble),            .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble),            .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_magikoopa_flying), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(lava_bubble), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spike_top),   .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_09) = {
    { .actor = &N(spike_top),   .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(spike_top),   .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),   .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(spike_top),      .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0C) = {
    { .actor = &N(spike_top),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0D) = {
    { .actor = &N(spike_top),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(putrid_piranha), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0E) = {
    { .actor = &N(spike_top),   .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(lava_bubble), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(lava_bubble), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0F) = {
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_10) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_11) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(lava_bubble),    .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_12) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(spike_top),      .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_13) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_14) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(spike_top),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(spike_top),      .home = { .index = 3 }, .priority = 7 },
};

BattleList N(Formations) = {
    BATTLE("バブルx2", N(Formation_00), &N(kzn_01)),
    BATTLE("バブルx3", N(Formation_01), &N(kzn_01)),
    BATTLE("バブルx4", N(Formation_02), &N(kzn_01)),
    BATTLE("バブル,トゲメットx３", N(Formation_03), &N(kzn_01)),
    BATTLE("バブルx2,かいふくヘイホー", N(Formation_04), &N(kzn_01)),
    BATTLE("バブルx2,レッドカメック", N(Formation_05), &N(kzn_01)),
    BATTLE("バブルx2,ホワイトカメック", N(Formation_06), &N(kzn_01)),
    BATTLE("バブルx2,トゲメット", N(Formation_07), &N(kzn_01)),
    BATTLE("トゲメットx２", N(Formation_08), &N(kzn_01)),
    BATTLE("トゲメット,バブル", N(Formation_09), &N(kzn_01)),
    BATTLE("トゲメットx２,バブル", N(Formation_0A), &N(kzn_01)),
    BATTLE("トゲメット,ポイズンパックン", N(Formation_0B), &N(kzn_01)),
    BATTLE("トゲメットx２,ポイズンパックン", N(Formation_0C), &N(kzn_01)),
    BATTLE("トゲメットx２,ポイズンパックンx２", N(Formation_0D), &N(kzn_01)),
    BATTLE("トゲメット,バブルx３", N(Formation_0E), &N(kzn_01)),
    BATTLE("ポイズンパックンx２", N(Formation_0F), &N(kzn_01)),
    BATTLE("ポイズンパックンx３", N(Formation_10), &N(kzn_01)),
    BATTLE("ポイズンパックン,バブル,ポイズンパックン", N(Formation_11), &N(kzn_01)),
    BATTLE("ポイズンパックンx２,トゲメット", N(Formation_12), &N(kzn_01)),
    BATTLE("ポイズンパックン,トゲメット,ポイズンパックン", N(Formation_13), &N(kzn_01)),
    BATTLE("ポイズンパックン,トゲメット,ポイズンパックン,トゲメット", N(Formation_14), &N(kzn_01)),
    {},
};

StageList N(Stages) = {
    { "kzn_01", &N(kzn_01) },
    { "kzn_01b", &N(kzn_01b) },
    { "kzn_02", &N(kzn_02) },
    { "kzn_04", &N(kzn_04) },
    { "kzn_04b", &N(kzn_04b) },
    { "kzn_04c", &N(kzn_04c) },
    { "kzn_05", &N(kzn_05) },
    {},
};
