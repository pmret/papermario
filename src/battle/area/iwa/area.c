#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_iwa

extern ActorBlueprint N(cleft);
extern ActorBlueprint N(monty_mole);
extern ActorBlueprint N(whacka);
extern ActorBlueprint N(buzzar);

extern Stage N(iwa_01);
extern Stage N(iwa_01b);
extern Stage N(iwa_02);

Formation N(Formation_00) = {
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(cleft), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(cleft), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(cleft),        .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { .actor = &N(cleft),        .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_05) = {
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_06) = {
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_07) = {
    { .actor = &N(monty_mole), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(monty_mole), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(monty_mole), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_09) = {
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(cleft),        .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(monty_mole), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(cleft),        .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(monty_mole), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(cleft),        .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(monty_mole), .home = { .index = 2 }, .priority = 8 },
};

Vec3i N(vector3D_8021853C) = { 90, 70, 0, };

Formation N(Formation_0C) = {
    { .actor = &N(buzzar), .home = { .vec = &N(vector3D_8021853C) }, .priority = 10 },
};

Formation N(Formation_0D) = {
    { .actor = &N(cleft),        .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(monty_mole), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(whacka),       .home = { .index = 2 }, .priority = 8 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(iwa_01), "シンエモン"),
    BATTLE(N(Formation_01), &N(iwa_01), "シンエモンx２"),
    BATTLE(N(Formation_02), &N(iwa_01), "シンエモンx３"),
    BATTLE(N(Formation_03), &N(iwa_01), "シンエモン,チョロプー"),
    BATTLE(N(Formation_04), &N(iwa_01), "シンエモン,チョロプーx２"),
    BATTLE(N(Formation_05), &N(iwa_01), "チョロプー"),
    BATTLE(N(Formation_06), &N(iwa_01), "チョロプーx２"),
    BATTLE(N(Formation_07), &N(iwa_01), "チョロプーx３"),
    BATTLE(N(Formation_08), &N(iwa_01), "チョロプーx４"),
    BATTLE(N(Formation_09), &N(iwa_01), "チョロプー,シンエモン"),
    BATTLE(N(Formation_0A), &N(iwa_01), "チョロプーx２,シンエモン"),
    BATTLE(N(Formation_0B), &N(iwa_01), "チョロプー,シンエモン,チョロプー"),
    BATTLE(N(Formation_0C), &N(iwa_02), "ゲーハー"),
    BATTLE(N(Formation_0D), &N(iwa_02), "コブロン"),
    {},
};

StageList N(Stages) = {
    { "iwa_01",  &N(iwa_01) },
    { "iwa_01b", &N(iwa_01b) },
    { "iwa_02",  &N(iwa_02) },
    {},
};
