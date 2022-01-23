#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb

extern ActorBlueprint N(clubba);
extern ActorBlueprint N(tubba_blubba);

extern Stage N(dgb_01);
extern Stage N(dgb_02);
extern Stage N(dgb_03);
extern Stage N(dgb_04);
extern Stage N(dgb_05);

Formation N(formation_00) = {
    { .actor = &N(clubba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(clubba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(clubba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(clubba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(clubba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(clubba), .home = { .index = 3 }, .priority = 7 },
};

Vec3i N(vector3D_8021B348) = { 75, 0, 10 };

Formation N(formation_04) = {
    { .actor = &N(tubba_blubba), .home = { .vec = &N(vector3D_8021B348) }, .priority = 10 },
};

Formation N(formation_05) = {
    { .actor = &N(tubba_blubba), .home = { .vec = &N(vector3D_8021B348) }, .priority = 10, .var0 = 1 },
};

BattleList N(formationTable) = {
    BATTLE("ガボンへい", N(formation_00), &N(dgb_01)),
    BATTLE("ガボンへいx２", N(formation_01), &N(dgb_01)),
    BATTLE("ガボンへいx３", N(formation_02), &N(dgb_01)),
    BATTLE("ガボンへいx４", N(formation_03), &N(dgb_01)),
    BATTLE("むてきドガボン", N(formation_04), &N(dgb_01)),
    BATTLE("むてきドガボンせりふなし", N(formation_05), &N(dgb_01)),
    {},
};

StageList N(stageTable) = {
    { "dgb_01", &N(dgb_01) },
    { "dgb_02", &N(dgb_02) },
    { "dgb_03", &N(dgb_03) },
    { "dgb_04", &N(dgb_04) },
    { "dgb_05", &N(dgb_05) },
    {},
};
