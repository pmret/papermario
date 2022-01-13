#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_mim

extern ActorDesc N(forest_fuzzy);
extern ActorDesc N(piranha_plant);
extern ActorDesc N(bzzap);

extern Stage N(mim_01);

Formation N(formation_00) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_01) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_02) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(forest_fuzzy), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_03) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_04) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_05) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_06) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_07) = {
    { .actor = &N(forest_fuzzy), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_08) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_09) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0A) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0B) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(piranha_plant), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0C) = {
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0D) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(piranha_plant), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0E) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(forest_fuzzy), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0F) = {
    { .actor = &N(piranha_plant), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(forest_fuzzy), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(piranha_plant), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_10) = {
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_11) = {
    { .actor = &N(bzzap), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bzzap), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(bzzap), .home = { .index = 6 }, .priority = 8 },
};

BattleList N(formationTable) = {
    BATTLE("グリーンチョロボンx2", N(formation_00), &N(mim_01)),
    BATTLE("グリーンチョロボンx3", N(formation_01), &N(mim_01)),
    BATTLE("グリーンチョロボンx4", N(formation_02), &N(mim_01)),
    BATTLE("グリーンチョロボン,パックンフラワー", N(formation_03), &N(mim_01)),
    BATTLE("グリーンチョロボンx2,パックンフラワー", N(formation_04), &N(mim_01)),
    BATTLE("グリーンチョロボンx2,パックンフラワーx2", N(formation_05), &N(mim_01)),
    BATTLE("グリーンチョロボンx3,パックンフラワー", N(formation_06), &N(mim_01)),
    BATTLE("グリーンチョロボン,パックンフラワー,グリーンチョロボン,パックンフラワー", N(formation_07), &N(mim_01)),
    BATTLE("パックンフラワー", N(formation_08), &N(mim_01)),
    BATTLE("パックンフラワーx2", N(formation_09), &N(mim_01)),
    BATTLE("パックンフラワーx3", N(formation_0A), &N(mim_01)),
    BATTLE("パックンフラワーx4", N(formation_0B), &N(mim_01)),
    BATTLE("パックンフラワー,グリーンチョロボン", N(formation_0C), &N(mim_01)),
    BATTLE("パックンフラワーx2,グリーンチョロボン", N(formation_0D), &N(mim_01)),
    BATTLE("パックンフラワー,グリーンチョロボンx2", N(formation_0E), &N(mim_01)),
    BATTLE("パックンフラワー,グリーンチョロボン,パックンフラワー", N(formation_0F), &N(mim_01)),
    BATTLE("ハッチーx2", N(formation_10), &N(mim_01)),
    BATTLE("ハッチーx3", N(formation_11), &N(mim_01)),
    {},
};

StageList N(stageTable) = {
    { "mim_01", &N(mim_01) },
    {},
};
