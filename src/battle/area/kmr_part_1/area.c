#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1

extern ActorBlueprint N(goomba);
extern ActorBlueprint N(paragoomba);
extern ActorBlueprint N(spiked_goomba);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

Formation N(formation_00) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_04) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
    { &N(goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_05) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_06) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
    { &N(paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_07) = {
    { &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
};

Formation N(formation_08) = {
    { &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_09) = {
    { &N(paragoomba), .home = { .index = 4 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0A) = {
    { &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_0B) = {
    { &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

BattleList N(formationTable) = {
    BATTLE("クリボー", N(formation_00), &N(kmr_04)),
    BATTLE("クリボーx２", N(formation_01), &N(kmr_04)),
    BATTLE("クリボーx３", N(formation_02), &N(kmr_04)),
    BATTLE("クリボー、パタクリボー", N(formation_03), &N(kmr_04)),
    BATTLE("クリボーx４", N(formation_04), &N(kmr_04)),
    BATTLE("クリボー,トゲクリボー", N(formation_05), &N(kmr_04)),
    BATTLE("クリボー,パタクリボー,クリボー,パタクリボー", N(formation_06), &N(kmr_04)),
    BATTLE("パタクリボー", N(formation_07), &N(kmr_04)),
    BATTLE("パタクリボーx２", N(formation_08), &N(kmr_04)),
    BATTLE("パタクリボーx３", N(formation_09), &N(kmr_04)),
    BATTLE("トゲクリボー", N(formation_0A), &N(kmr_04)),
    BATTLE("トゲクリボー、クリボー", N(formation_0B), &N(kmr_04)),
    {},
};

StageList N(stageTable) = {
    { "kmr_02", &N(kmr_02) },
    { "kmr_03", &N(kmr_03) },
    { "kmr_04", &N(kmr_04) },
    { "kmr_05", &N(kmr_05) },
    { "kmr_06", &N(kmr_06) },
    {},
};
