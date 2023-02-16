#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2

extern ActorBlueprint N(putrid_piranha);
extern ActorBlueprint N(white_magikoopa);

extern Stage N(jan_00);
extern Stage N(jan_01);
extern Stage N(jan_01b);
extern Stage N(jan_02);
extern Stage N(jan_03);
extern Stage N(jan_03b);
extern Stage N(jan_04);
extern Stage N(jan_04b);

Formation N(formation_00) = {
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(putrid_piranha), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(putrid_piranha), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(putrid_piranha), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(white_magikoopa), .home = { .index = 3 }, .priority = 7 },
};

BattleList N(formationTable) = {
    BATTLE("ポイズンパックン", N(formation_00), &N(jan_01)),
    BATTLE("ポイズンパックンx２", N(formation_01), &N(jan_01)),
    BATTLE("ポイズンパックンx３", N(formation_02), &N(jan_01)),
    BATTLE("ポイズンパックンx３,ホワイトカメック", N(formation_03), &N(jan_01)),
    {},
};

StageList N(stageTable) = {
    { "jan_00", &N(jan_00) },
    { "jan_01", &N(jan_01) },
    { "jan_01b", &N(jan_01b) },
    { "jan_02", &N(jan_02) },
    { "jan_03", &N(jan_03) },
    { "jan_03b", &N(jan_03b) },
    { "jan_04", &N(jan_04) },
    { "jan_04b", &N(jan_04b) },
    {},
};
