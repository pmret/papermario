#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_iwa

extern ActorBlueprint N(cleft);
extern ActorBlueprint N(monty_mole_1);
extern ActorBlueprint N(whacka);
extern ActorBlueprint N(buzzar);

extern Stage N(iwa_01);
extern Stage N(iwa_01b);
extern Stage N(iwa_02);

Formation N(formation_00) = {
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(cleft), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(cleft), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(cleft),        .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_04) = {
    { .actor = &N(cleft),        .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_05) = {
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_06) = {
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_07) = {
    { .actor = &N(monty_mole_1), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_08) = {
    { .actor = &N(monty_mole_1), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(monty_mole_1), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_09) = {
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(cleft),        .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0A) = {
    { .actor = &N(monty_mole_1), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(cleft),        .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0B) = {
    { .actor = &N(monty_mole_1), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(cleft),        .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole_1), .home = { .index = 2 }, .priority = 8 },
};

Vec3i N(vector3D_8021853C) = { 90, 70, 0, };

Formation N(formation_0C) = {
    { .actor = &N(buzzar), .home = { .vec = &N(vector3D_8021853C) }, .priority = 10 },
};

Formation N(formation_0D) = {
    { .actor = &N(cleft),        .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole_1), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(whacka),       .home = { .index = 2 }, .priority = 8 },
};

BattleList N(formationTable) = {
    BATTLE("シンエモン", N(formation_00), &N(iwa_01)),
    BATTLE("シンエモンx２", N(formation_01), &N(iwa_01)),
    BATTLE("シンエモンx３", N(formation_02), &N(iwa_01)),
    BATTLE("シンエモン,チョロプー", N(formation_03), &N(iwa_01)),
    BATTLE("シンエモン,チョロプーx２", N(formation_04), &N(iwa_01)),
    BATTLE("チョロプー", N(formation_05), &N(iwa_01)),
    BATTLE("チョロプーx２", N(formation_06), &N(iwa_01)),
    BATTLE("チョロプーx３", N(formation_07), &N(iwa_01)),
    BATTLE("チョロプーx４", N(formation_08), &N(iwa_01)),
    BATTLE("チョロプー,シンエモン", N(formation_09), &N(iwa_01)),
    BATTLE("チョロプーx２,シンエモン", N(formation_0A), &N(iwa_01)),
    BATTLE("チョロプー,シンエモン,チョロプー", N(formation_0B), &N(iwa_01)),
    BATTLE("ゲーハー", N(formation_0C), &N(iwa_02)),
    BATTLE("コブロン", N(formation_0D), &N(iwa_02)),
    {},
};

StageList N(stageTable) = {
    { "iwa_01",  &N(iwa_01) },
    { "iwa_01b", &N(iwa_01b) },
    { "iwa_02",  &N(iwa_02) },
    {},
};
