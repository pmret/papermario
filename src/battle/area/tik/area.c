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

Formation N(Formation_00) = {
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_01) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_02) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_koopa), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(dark_koopa), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_03) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_04) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_05) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_06) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_07) = {
    { .actor = &N(dark_koopa), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(dark_koopa), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_08) = {
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 9, },
};

Formation N(Formation_09) = {
    { .actor = &N(dark_paratroopa), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(dark_paratroopa), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(dark_paratroopa), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_0A) = {
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_0B) = {
    { .actor = &N(gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(gloomba), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_0C) = {
    { .actor = &N(paragloomba), .home = { .index = 4 }, .priority = 10, },
    { .actor = &N(paragloomba), .home = { .index = 5 }, .priority = 9, },
    { .actor = &N(paragloomba), .home = { .index = 6 }, .priority = 8, },
};

Formation N(Formation_0D) = {
    { .actor = &N(paragloomba), .home = { .index = 5 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_0E) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_0F) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(gloomba), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_10) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_11) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiked_gloomba), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_12) = {
    { .actor = &N(spiked_gloomba), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(buzzy_beetle), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(paragloomba), .home = { .index = 6 }, .priority = 8, },
    { .actor = &N(buzzy_beetle), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_13) = {
    { .actor = &N(spike_top), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spike_top), .home = { .index = 3 }, .priority = 7, },
};

Formation N(Formation_14) = {
    { .actor = &N(spike_top), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spike_top), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_15) = {
    { .actor = &N(buzzy_beetle), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiked_gloomba), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(buzzy_beetle), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_16) = {
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 9, },
};

Formation N(Formation_17) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
};

Formation N(Formation_18) = {
    { .actor = &N(spiny), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(spiny), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(spiny), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(spiny), .home = { .index = 3 }, .priority = 7, },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(tik_01), "ヤミノコノコx２"),
    BATTLE(N(Formation_01), &N(tik_01), "ヤミノコノコx３"),
    BATTLE(N(Formation_02), &N(tik_01), "ヤミノコノコx４"),
    BATTLE(N(Formation_03), &N(tik_01), "ヤミノコノコ,ヤミパタパタx２"),
    BATTLE(N(Formation_04), &N(tik_01), "ヤミノコノコ,トゲメットx２"),
    BATTLE(N(Formation_05), &N(tik_01), "ヤミノコノコ,トゲメット,ヤミノコノコ"),
    BATTLE(N(Formation_06), &N(tik_01), "ヤミノコノコ,トゲゾーx２"),
    BATTLE(N(Formation_07), &N(tik_01), "ヤミノコノコ,トゲゾー,ヤミノコノコ,トゲゾー"),
    BATTLE(N(Formation_08), &N(tik_01), "ヤミパタパタx２"),
    BATTLE(N(Formation_09), &N(tik_01), "ヤミパタパタx３"),
    BATTLE(N(Formation_0A), &N(tik_01), "ヤミクリボーx２"),
    BATTLE(N(Formation_0B), &N(tik_01), "ヤミクリボーx４"),
    BATTLE(N(Formation_0C), &N(tik_01), "ヤミパタクリx３"),
    BATTLE(N(Formation_0D), &N(tik_01), "ヤミパタクリ,ヤミトゲクリ"),
    BATTLE(N(Formation_0E), &N(tik_01), "ヤミトゲクリx２"),
    BATTLE(N(Formation_0F), &N(tik_01), "ヤミトゲクリ,ヤミクリボーx２"),
    BATTLE(N(Formation_10), &N(tik_01), "ヤミトゲクリ,メットx２"),
    BATTLE(N(Formation_11), &N(tik_01), "ヤミトゲクリ,メット,ヤミトゲクリ,メット"),
    BATTLE(N(Formation_12), &N(tik_01), "ヤミトゲクリ,メット,ヤミパタクリ,メット"),
    BATTLE(N(Formation_13), &N(tik_01), "トゲメットx４"),
    BATTLE(N(Formation_14), &N(tik_01), "トゲメットx２"),
    BATTLE(N(Formation_15), &N(tik_01), "メット,ヤミトゲクリ,メット"),
    BATTLE(N(Formation_16), &N(tik_01), "トゲゾーx２"),
    BATTLE(N(Formation_17), &N(tik_01), "トゲゾーx３"),
    BATTLE(N(Formation_18), &N(tik_01), "トゲゾーx４"),
    {},
};

StageList N(Stages) = {
    { "tik_01", &N(tik_01) },
    { "tik_02", &N(tik_02) },
    { "tik_03", &N(tik_03) },
    { "tik_04", &N(tik_04) },
    { "tik_05", &N(tik_05) },
    {},
};
