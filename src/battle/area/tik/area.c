#include "area.h"

extern ActorBlueprint A(dark_koopa);
extern ActorBlueprint A(dark_paratroopa);
extern ActorBlueprint A(gloomba);
extern ActorBlueprint A(spiked_gloomba);
extern ActorBlueprint A(paragloomba);
extern ActorBlueprint A(buzzy_beetle);
extern ActorBlueprint A(spike_top);
extern ActorBlueprint A(spiny);

extern Stage A(tik_01);
extern Stage A(tik_02);
extern Stage A(tik_03);
extern Stage A(tik_04);
extern Stage A(tik_05);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_C, 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(dark_koopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_C, 9),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(dark_paratroopa), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(paragloomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(paragloomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(paragloomba), BTL_POS_AIR_C, 8),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(paragloomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0F) = {
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(gloomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_10) = {
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_11) = {
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_12) = {
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(paragloomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_13) = {
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_14) = {
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spike_top), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_15) = {
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiked_gloomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(buzzy_beetle), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_16) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_17) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_18) = {
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(spiny), BTL_POS_GROUND_D, 7),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(tik_01), "ヤミノコノコx２"),
    BATTLE(A(Formation_01), A(tik_01), "ヤミノコノコx３"),
    BATTLE(A(Formation_02), A(tik_01), "ヤミノコノコx４"),
    BATTLE(A(Formation_03), A(tik_01), "ヤミノコノコ,ヤミパタパタx２"),
    BATTLE(A(Formation_04), A(tik_01), "ヤミノコノコ,トゲメットx２"),
    BATTLE(A(Formation_05), A(tik_01), "ヤミノコノコ,トゲメット,ヤミノコノコ"),
    BATTLE(A(Formation_06), A(tik_01), "ヤミノコノコ,トゲゾーx２"),
    BATTLE(A(Formation_07), A(tik_01), "ヤミノコノコ,トゲゾー,ヤミノコノコ,トゲゾー"),
    BATTLE(A(Formation_08), A(tik_01), "ヤミパタパタx２"),
    BATTLE(A(Formation_09), A(tik_01), "ヤミパタパタx３"),
    BATTLE(A(Formation_0A), A(tik_01), "ヤミクリボーx２"),
    BATTLE(A(Formation_0B), A(tik_01), "ヤミクリボーx４"),
    BATTLE(A(Formation_0C), A(tik_01), "ヤミパタクリx３"),
    BATTLE(A(Formation_0D), A(tik_01), "ヤミパタクリ,ヤミトゲクリ"),
    BATTLE(A(Formation_0E), A(tik_01), "ヤミトゲクリx２"),
    BATTLE(A(Formation_0F), A(tik_01), "ヤミトゲクリ,ヤミクリボーx２"),
    BATTLE(A(Formation_10), A(tik_01), "ヤミトゲクリ,メットx２"),
    BATTLE(A(Formation_11), A(tik_01), "ヤミトゲクリ,メット,ヤミトゲクリ,メット"),
    BATTLE(A(Formation_12), A(tik_01), "ヤミトゲクリ,メット,ヤミパタクリ,メット"),
    BATTLE(A(Formation_13), A(tik_01), "トゲメットx４"),
    BATTLE(A(Formation_14), A(tik_01), "トゲメットx２"),
    BATTLE(A(Formation_15), A(tik_01), "メット,ヤミトゲクリ,メット"),
    BATTLE(A(Formation_16), A(tik_01), "トゲゾーx２"),
    BATTLE(A(Formation_17), A(tik_01), "トゲゾーx３"),
    BATTLE(A(Formation_18), A(tik_01), "トゲゾーx４"),
    {},
};

StageList A(Stages) = {
    STAGE("tik_01", A(tik_01)),
    STAGE("tik_02", A(tik_02)),
    STAGE("tik_03", A(tik_03)),
    STAGE("tik_04", A(tik_04)),
    STAGE("tik_05", A(tik_05)),
    {},
};
