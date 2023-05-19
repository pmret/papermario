#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mim

extern ActorBlueprint N(forest_fuzzy);
extern ActorBlueprint N(piranha_plant);
extern ActorBlueprint N(bzzap);

extern Stage N(mim_01);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(forest_fuzzy), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(piranha_plant), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 9),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(bzzap), BTL_POS_AIR_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(mim_01), "グリーンチョロボンx2"),
    BATTLE(N(Formation_01), &N(mim_01), "グリーンチョロボンx3"),
    BATTLE(N(Formation_02), &N(mim_01), "グリーンチョロボンx4"),
    BATTLE(N(Formation_03), &N(mim_01), "グリーンチョロボン,パックンフラワー"),
    BATTLE(N(Formation_04), &N(mim_01), "グリーンチョロボンx2,パックンフラワー"),
    BATTLE(N(Formation_05), &N(mim_01), "グリーンチョロボンx2,パックンフラワーx2"),
    BATTLE(N(Formation_06), &N(mim_01), "グリーンチョロボンx3,パックンフラワー"),
    BATTLE(N(Formation_07), &N(mim_01), "グリーンチョロボン,パックンフラワー,グリーンチョロボン,パックンフラワー"),
    BATTLE(N(Formation_08), &N(mim_01), "パックンフラワー"),
    BATTLE(N(Formation_09), &N(mim_01), "パックンフラワーx2"),
    BATTLE(N(Formation_0A), &N(mim_01), "パックンフラワーx3"),
    BATTLE(N(Formation_0B), &N(mim_01), "パックンフラワーx4"),
    BATTLE(N(Formation_0C), &N(mim_01), "パックンフラワー,グリーンチョロボン"),
    BATTLE(N(Formation_0D), &N(mim_01), "パックンフラワーx2,グリーンチョロボン"),
    BATTLE(N(Formation_0E), &N(mim_01), "パックンフラワー,グリーンチョロボンx2"),
    BATTLE(N(Formation_0F), &N(mim_01), "パックンフラワー,グリーンチョロボン,パックンフラワー"),
    BATTLE(N(Formation_10), &N(mim_01), "ハッチーx2"),
    BATTLE(N(Formation_11), &N(mim_01), "ハッチーx3"),
    {},
};

StageList N(Stages) = {
    { "mim_01", &N(mim_01) },
    {},
};
