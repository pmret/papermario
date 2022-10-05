#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik

extern ActorBlueprint N(dark_koopa);
extern ActorBlueprint N(dark_paratroopa);
extern ActorBlueprint N(gloomba);
extern ActorBlueprint N(spiked_gloomba);
extern ActorBlueprint N(paragloomba);
extern ActorBlueprint N(buzzy_beetle);
extern ActorBlueprint N(spike_top);
extern ActorBlueprint N(spiny);

extern Stage N(tik_01);
extern Stage N(tik_02);
extern Stage N(tik_03);
extern Stage N(tik_04);
extern Stage N(tik_05);

Formation N(formation_00) = {
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_01) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_02) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(dark_koopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_03) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_04) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_05) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_06) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_07) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_08) = {
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 9, },
};

Formation N(formation_09) = {
    { .actor = &N(dark_paratroopa), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_0A) = {
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_0B) = {
    { .actor = &N(gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(gloomba), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_0C) = {
    { .actor = &N(paragloomba), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(paragloomba), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(paragloomba), .home = { .index = 6 }, .priority = 8, },
};

Formation N(formation_0D) = {
    { .actor = &N(paragloomba), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_0E) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_0F) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_10) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_11) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_12) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(paragloomba), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_13) = {
    { .actor = &N(spike_top), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spike_top), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_14) = {
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_15) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_16) = {
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_17) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_18) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

BattleList N(formationTable) = {
    BATTLE("ヤミノコノコx２", N(formation_00), &N(tik_01)),
    BATTLE("ヤミノコノコx３", N(formation_01), &N(tik_01)),
    BATTLE("ヤミノコノコx４", N(formation_02), &N(tik_01)),
    BATTLE("ヤミノコノコ,ヤミパタパタx２", N(formation_03), &N(tik_01)),
    BATTLE("ヤミノコノコ,トゲメットx２", N(formation_04), &N(tik_01)),
    BATTLE("ヤミノコノコ,トゲメット,ヤミノコノコ", N(formation_05), &N(tik_01)),
    BATTLE("ヤミノコノコ,トゲゾーx２", N(formation_06), &N(tik_01)),
    BATTLE("ヤミノコノコ,トゲゾー,ヤミノコノコ,トゲゾー", N(formation_07), &N(tik_01)),
    BATTLE("ヤミパタパタx２", N(formation_08), &N(tik_01)),
    BATTLE("ヤミパタパタx３", N(formation_09), &N(tik_01)),
    BATTLE("ヤミクリボーx２", N(formation_0A), &N(tik_01)),
    BATTLE("ヤミクリボーx４", N(formation_0B), &N(tik_01)),
    BATTLE("ヤミパタクリx３", N(formation_0C), &N(tik_01)),
    BATTLE("ヤミパタクリ,ヤミトゲクリ", N(formation_0D), &N(tik_01)),
    BATTLE("ヤミトゲクリx２", N(formation_0E), &N(tik_01)),
    BATTLE("ヤミトゲクリ,ヤミクリボーx２", N(formation_0F), &N(tik_01)),
    BATTLE("ヤミトゲクリ,メットx２", N(formation_10), &N(tik_01)),
    BATTLE("ヤミトゲクリ,メット,ヤミトゲクリ,メット", N(formation_11), &N(tik_01)),
    BATTLE("ヤミトゲクリ,メット,ヤミパタクリ,メット", N(formation_12), &N(tik_01)),
    BATTLE("トゲメットx４", N(formation_13), &N(tik_01)),
    BATTLE("トゲメットx２", N(formation_14), &N(tik_01)),
    BATTLE("メット,ヤミトゲクリ,メット", N(formation_15), &N(tik_01)),
    BATTLE("トゲゾーx２", N(formation_16), &N(tik_01)),
    BATTLE("トゲゾーx３", N(formation_17), &N(tik_01)),
    BATTLE("トゲゾーx４", N(formation_18), &N(tik_01)),
    {},
};

StageList N(stageTable) = {
    { "tik_01", &N(tik_01) },
    { "tik_02", &N(tik_02) },
    { "tik_03", &N(tik_03) },
    { "tik_04", &N(tik_04) },
    { "tik_05", &N(tik_05) },
    {},
};
