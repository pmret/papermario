#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik3

extern ActorBlueprint N(swooper);
extern ActorBlueprint N(swoopula);

extern Stage N(tik_01);
extern Stage N(tik_02);
extern Stage N(tik_03);
extern Stage N(tik_04);
extern Stage N(tik_05);

Formation N(formation_00) = {
    { .actor = &N(swooper), .home = { .index = 13 }, .priority = 10, },
    { .actor = &N(swooper), .home = { .index = 14 }, .priority = 9, },
};

Formation N(formation_01) = {
    { .actor = &N(swooper), .home = { .index = 12 }, .priority = 10, },
    { .actor = &N(swooper), .home = { .index = 13 }, .priority = 9, },
    { .actor = &N(swooper), .home = { .index = 14 }, .priority = 8, },
};

Formation N(formation_02) = {
    { .actor = &N(swoopula), .home = { .index = 13 }, .priority = 10, },
    { .actor = &N(swoopula), .home = { .index = 14 }, .priority = 9, },
};

Formation N(formation_03) = {
    { .actor = &N(swoopula), .home = { .index = 12 }, .priority = 10, },
    { .actor = &N(swoopula), .home = { .index = 13 }, .priority = 9, },
    { .actor = &N(swoopula), .home = { .index = 14 }, .priority = 8, },
};

BattleList N(formationTable) = {
    BATTLE("バサバサx２", N(formation_00), &N(tik_01)),
    BATTLE("バサバサx３", N(formation_01), &N(tik_01)),
    BATTLE("バサバサチュルルx２", N(formation_02), &N(tik_01)),
    BATTLE("バサバサチュルルx３", N(formation_03), &N(tik_01)),
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
