#include "area.h"

extern ActorBlueprint A(goomba);
extern ActorBlueprint A(paragoomba);
extern ActorBlueprint A(spiked_goomba);

extern Stage A(kmr_02);
extern Stage A(kmr_03);
extern Stage A(kmr_04);
extern Stage A(kmr_05);
extern Stage A(kmr_06);

Formation A(Formation_00) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
};

Formation A(Formation_01) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

Formation A(Formation_02) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Formation A(Formation_03) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_C }, .priority = 9 },
};

Formation A(Formation_04) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_D }, .priority = 7 },
};

Formation A(Formation_05) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { &A(spiked_goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

Formation A(Formation_06) = {
    { &A(goomba), .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_B }, .priority = 9 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_D }, .priority = 7 },
};

Formation A(Formation_07) = {
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_B }, .priority = 10 },
};

Formation A(Formation_08) = {
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_B }, .priority = 10 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_C }, .priority = 9 },
};

Formation A(Formation_09) = {
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_A }, .priority = 10 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_B }, .priority = 9 },
    { &A(paragoomba), .home = { .index = BTL_POS_AIR_C }, .priority = 8 },
};

Formation A(Formation_0A) = {
    { &A(spiked_goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
};

Formation A(Formation_0B) = {
    { &A(spiked_goomba), .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { &A(goomba), .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kmr_04), "クリボー"),
    BATTLE(A(Formation_01), A(kmr_04), "クリボーx２"),
    BATTLE(A(Formation_02), A(kmr_04), "クリボーx３"),
    BATTLE(A(Formation_03), A(kmr_04), "クリボー、パタクリボー"),
    BATTLE(A(Formation_04), A(kmr_04), "クリボーx４"),
    BATTLE(A(Formation_05), A(kmr_04), "クリボー,トゲクリボー"),
    BATTLE(A(Formation_06), A(kmr_04), "クリボー,パタクリボー,クリボー,パタクリボー"),
    BATTLE(A(Formation_07), A(kmr_04), "パタクリボー"),
    BATTLE(A(Formation_08), A(kmr_04), "パタクリボーx２"),
    BATTLE(A(Formation_09), A(kmr_04), "パタクリボーx３"),
    BATTLE(A(Formation_0A), A(kmr_04), "トゲクリボー"),
    BATTLE(A(Formation_0B), A(kmr_04), "トゲクリボー、クリボー"),
    {},
};

StageList A(Stages) = {
    STAGE("kmr_02", A(kmr_02)),
    STAGE("kmr_03", A(kmr_03)),
    STAGE("kmr_04", A(kmr_04)),
    STAGE("kmr_05", A(kmr_05)),
    STAGE("kmr_06", A(kmr_06)),
    {},
};
