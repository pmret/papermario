#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mim

extern ActorBlueprint N(forest_fuzzy);
extern ActorBlueprint N(piranha_plant);
extern ActorBlueprint N(bzzap);

extern Stage N(mim_01);

Formation N(Formation_00) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_01) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_02) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(forest_fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_03) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_05) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_06) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_07) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_08) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_09) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0C) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0D) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0E) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0F) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_10) = {
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_11) = {
    { .actor = &N(bzzap), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8 },
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
