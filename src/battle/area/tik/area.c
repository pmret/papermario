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
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_C, 8),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(dark_koopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_C, 9),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(dark_paratroopa), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(paragloomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(paragloomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(paragloomba), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(paragloomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(gloomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_12) = {
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(paragloomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_13) = {
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_14) = {
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_15) = {
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiked_gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(buzzy_beetle), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_16) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_17) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_18) = {
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(spiny), BTL_POS_GROUND_D, 7),
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
