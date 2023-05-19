#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan

extern ActorBlueprint N(spear_guy);
extern ActorBlueprint N(jungle_fuzzy);
extern ActorBlueprint N(medi_guy);
extern ActorBlueprint N(spike_top);
extern ActorBlueprint N(hurt_plant);
extern ActorBlueprint N(m_bush);

extern Stage N(jan_00);
extern Stage N(jan_01);
extern Stage N(jan_01b);
extern Stage N(jan_02);
extern Stage N(jan_03);
extern Stage N(jan_03b);
extern Stage N(jan_04);
extern Stage N(jan_04b);

Formation N(Formation_00) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_B, 10, 0),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_C, 9, 1),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_B, 9, 1),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_C, 8, 1),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_B, 10, 0),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_C, 8, 1),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_C, 8, 1),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_A, 10, 0),
    ACTOR_BY_IDX(N(medi_guy), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(spike_top), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(hurt_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(hurt_plant), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(hurt_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hurt_plant), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hurt_plant), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX_INIT_1(N(spear_guy), BTL_POS_GROUND_B, 9, 1),
    ACTOR_BY_IDX(N(jungle_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(m_bush), BTL_POS_GROUND_D, 7),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(jan_01), "ヤリダンサーx2"),
    BATTLE(N(Formation_01), N(jan_01), "ヤリダンサーx3"),
    BATTLE(N(Formation_02), N(jan_01), "ヤリダンサー,トロピカル"),
    BATTLE(N(Formation_03), N(jan_01), "ヤリダンサー,トロピカルx３"),
    BATTLE(N(Formation_04), N(jan_01), "ヤリダンサー,トロピカルx２"),
    BATTLE(N(Formation_05), N(jan_01), "ヤリダンサー,トロピカル,ヤリダンサー"),
    BATTLE(N(Formation_06), N(jan_01), "ヤリダンサー,トロピカル,ヤリダンサー,トロピカル"),
    BATTLE(N(Formation_07), N(jan_01), "ヤリダンサー,かいふくヘイホー,トゲメット"),
    BATTLE(N(Formation_08), N(jan_01), "ピロリンそうだましx2"),
    BATTLE(N(Formation_09), N(jan_01), "ピロリンそうだましx3"),
    BATTLE(N(Formation_0A), N(jan_01), "トロピカルx2"),
    BATTLE(N(Formation_0B), N(jan_01), "トロピカルx3"),
    BATTLE(N(Formation_0C), N(jan_01), "トロピカルx4"),
    BATTLE(N(Formation_0D), N(jan_01), "トロピカル,ヤリダンサー,トロピカル"),
    BATTLE(N(Formation_0E), N(jan_01), "ぎたいそうx2"),
    BATTLE(N(Formation_0F), N(jan_01), "ぎたいそうx3"),
    BATTLE(N(Formation_10), N(jan_01), "ぎたいそうx4"),
    {},
};

StageList N(Stages) = {
    STAGE("jan_00", N(jan_00)),
    STAGE("jan_01", N(jan_01)),
    STAGE("jan_01b", N(jan_01b)),
    STAGE("jan_02", N(jan_02)),
    STAGE("jan_03", N(jan_03)),
    STAGE("jan_03b", N(jan_03b)),
    STAGE("jan_04", N(jan_04)),
    STAGE("jan_04b", N(jan_04b)),
    {},
};
