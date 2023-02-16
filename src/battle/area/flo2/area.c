#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo2

extern ActorBlueprint N(huff_n_puff);
extern ActorBlueprint N(monty_mole_boss);
extern ActorBlueprint N(spike);

extern Stage N(flo_01);
extern Stage N(flo_01b);
extern Stage N(flo_01c);
extern Stage N(flo_02);
extern Stage N(flo_02b);
extern Stage N(flo_02c);
extern Stage N(flo_03);
extern Stage N(flo_04);
extern Stage N(flo_05);
extern Stage N(flo_06);

Vec3i N(huff_n_puff_pos) = { 80, 80, 0 };

Formation N(formation_01) = {
    { .actor = &N(huff_n_puff), .home = { .vec = &N(huff_n_puff_pos) }, .priority = 10, },
};

Formation N(formation_02) = {
    { .actor = &N(monty_mole_boss), .home = { .index = 1 }, .priority = 10, },
};

Formation N(formation_03) = {
    { .actor = &N(monty_mole_boss), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(monty_mole_boss), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_04) = {
    { .actor = &N(monty_mole_boss), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(monty_mole_boss), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(monty_mole_boss), .home = { .index = 2 }, .priority = 8, },
};

Formation N(formation_05) = {
    { .actor = &N(monty_mole_boss), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(monty_mole_boss), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(monty_mole_boss), .home = { .index = 2 }, .priority = 8, },
    { .actor = &N(monty_mole_boss), .home = { .index = 3 }, .priority = 7, },
};

Formation N(formation_06) = {
    { .actor = &N(spike), .home = { .index = 5 }, .priority = 10, },
};

BattleList N(formationTable) = {
    BATTLE("オズモーン", N(formation_01), &N(flo_04)),
    BATTLE("フラワーチョロプー", N(formation_02), &N(flo_01)),
    BATTLE("フラワーチョロプーx２", N(formation_03), &N(flo_01)),
    BATTLE("フラワーチョロプーx３", N(formation_04), &N(flo_01)),
    BATTLE("フラワーチョロプーx４", N(formation_05), &N(flo_01)),
    BATTLE("ジョナサン？", N(formation_06), &N(flo_01)),
    {},
};

StageList N(stageTable) = {
    { "flo_01", &N(flo_01) },
    { "flo_01b", &N(flo_01b) },
    { "flo_01c", &N(flo_01c) },
    { "flo_02", &N(flo_02) },
    { "flo_02b", &N(flo_02b) },
    { "flo_02c", &N(flo_02c) },
    { "flo_03", &N(flo_03) },
    { "flo_04", &N(flo_04) },
    { "flo_05", &N(flo_05) },
    { "flo_06", &N(flo_06) },
    {},
};
