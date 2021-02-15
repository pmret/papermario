#include "common.h"
#include "battle/battle.h"

#include "goomba.h"
#include "paragoomba.h"
#include "spiked_goomba.h"

#define NAMESPACE b_area_kmr_part_1

Formation formation0 = {
    { &goomba, .position = 1, .priority = 10 },
};

Formation formation1 = {
    { &goomba, .position = 1, .priority = 10 },
    { &goomba, .position = 2, .priority = 9 },
};

Formation formation2 = {
    { &goomba, .position = 0, .priority = 10 },
    { &goomba, .position = 1, .priority = 9 },
    { &goomba, .position = 2, .priority = 8 },
};

Formation formation3 = {
    { &goomba, .position = 1, .priority = 10 },
    { &paragoomba, .position = 6, .priority = 9 },
};

Formation formation4 = {
    { &goomba, .position = 0, .priority = 10 },
    { &goomba, .position = 1, .priority = 9 },
    { &goomba, .position = 2, .priority = 8 },
    { &goomba, .position = 3, .priority = 7 },
};

Formation formation5 = {
    { &goomba, .position = 1, .priority = 10 },
    { &spiked_goomba, .position = 2, .priority = 9 },
};

Formation formation6 = {
    { &goomba, .position = 0, .priority = 10 },
    { &paragoomba, .position = 5, .priority = 9 },
    { &goomba, .position = 2, .priority = 8 },
    { &paragoomba, .position = 7, .priority = 7 },
};

Formation formation7 = {
    { &paragoomba, .position = 5, .priority = 10 },
};

Formation formation8 = {
    { &paragoomba, .position = 5, .priority = 10 },
    { &paragoomba, .position = 6, .priority = 9 },
};

Formation formation9 = {
    { &paragoomba, .position = 4, .priority = 10 },
    { &paragoomba, .position = 5, .priority = 9 },
    { &paragoomba, .position = 6, .priority = 8 },
};

Formation formation10 = {
    { &spiked_goomba, .position = 1, .priority = 10 },
};

Formation formation11 = {
    { &spiked_goomba, .position = 1, .priority = 10 },
    { &goomba, .position = 2, .priority = 9 },
};

BattleList area_kmr_part_1_battles = {
    BATTLE("クリボー", formation0, 0x8022066C),
    BATTLE("クリボーx２", formation1, 0x8022066C),
    BATTLE("クリボーx３", formation2, 0x8022066C),
    BATTLE("クリボー、パタクリボー", formation3, 0x8022066C),
    BATTLE("クリボーx４", formation4, 0x8022066C),
    BATTLE("クリボー,トゲクリボー", formation5, 0x8022066C),
    BATTLE("クリボー,パタクリボー,クリボー,パタクリボー", formation6, 0x8022066C),
    BATTLE("パタクリボー", formation7, 0x8022066C),
    BATTLE("パタクリボーx２", formation8, 0x8022066C),
    BATTLE("パタクリボーx３", formation9, 0x8022066C),
    BATTLE("トゲクリボー", formation10, 0x8022066C),
    BATTLE("トゲクリボー、クリボー", formation11, 0x8022066C),
    {},
};

StageList area_kmr_part_1_stages = {
    { "kmr_02", 0x8021FDD0 },
    { "kmr_03", 0x8022021C },
    { "kmr_04", 0x8022066C },
    { "kmr_05", 0x80220A78 },
    { "kmr_06", 0x80220ECC },
    {},
};
