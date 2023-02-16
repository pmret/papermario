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

Formation N(Formation_00) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(goomba), .home = { .index = 1 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
    { &N(goomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_05) = {
    { &N(goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(spiked_goomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_06) = {
    { &N(goomba), .home = { .index = 0 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { &N(goomba), .home = { .index = 2 }, .priority = 8 },
    { &N(paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_07) = {
    { &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
};

Formation N(Formation_08) = {
    { &N(paragoomba), .home = { .index = 5 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_09) = {
    { &N(paragoomba), .home = { .index = 4 }, .priority = 10 },
    { &N(paragoomba), .home = { .index = 5 }, .priority = 9 },
    { &N(paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0A) = {
    { &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_0B) = {
    { &N(spiked_goomba), .home = { .index = 1 }, .priority = 10 },
    { &N(goomba), .home = { .index = 2 }, .priority = 9 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kmr_04), "クリボー"),
    BATTLE(N(Formation_01), &N(kmr_04), "クリボーx２"),
    BATTLE(N(Formation_02), &N(kmr_04), "クリボーx３"),
    BATTLE(N(Formation_03), &N(kmr_04), "クリボー、パタクリボー"),
    BATTLE(N(Formation_04), &N(kmr_04), "クリボーx４"),
    BATTLE(N(Formation_05), &N(kmr_04), "クリボー,トゲクリボー"),
    BATTLE(N(Formation_06), &N(kmr_04), "クリボー,パタクリボー,クリボー,パタクリボー"),
    BATTLE(N(Formation_07), &N(kmr_04), "パタクリボー"),
    BATTLE(N(Formation_08), &N(kmr_04), "パタクリボーx２"),
    BATTLE(N(Formation_09), &N(kmr_04), "パタクリボーx３"),
    BATTLE(N(Formation_0A), &N(kmr_04), "トゲクリボー"),
    BATTLE(N(Formation_0B), &N(kmr_04), "トゲクリボー、クリボー"),
    {},
};

StageList N(Stages) = {
    { "kmr_02", &N(kmr_02) },
    { "kmr_03", &N(kmr_03) },
    { "kmr_04", &N(kmr_04) },
    { "kmr_05", &N(kmr_05) },
    { "kmr_06", &N(kmr_06) },
    {},
};
