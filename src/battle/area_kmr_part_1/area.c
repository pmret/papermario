#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/goomba.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/spiked_goomba.h"

#define NAMESPACE b_area_kmr_part_1

extern ActorDesc N(goomba);
extern ActorDesc N(paragoomba);
extern ActorDesc N(spiked_goomba);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

Formation N(formation_00) = {
    { &N(goomba), .position = 1, .priority = 10 },
};

Formation N(formation_01) = {
    { &N(goomba), .position = 1, .priority = 10 },
    { &N(goomba), .position = 2, .priority = 9 },
};

Formation N(formation_02) = {
    { &N(goomba), .position = 0, .priority = 10 },
    { &N(goomba), .position = 1, .priority = 9 },
    { &N(goomba), .position = 2, .priority = 8 },
};

Formation N(formation_03) = {
    { &N(goomba), .position = 1, .priority = 10 },
    { &N(paragoomba), .position = 6, .priority = 9 },
};

Formation N(formation_04) = {
    { &N(goomba), .position = 0, .priority = 10 },
    { &N(goomba), .position = 1, .priority = 9 },
    { &N(goomba), .position = 2, .priority = 8 },
    { &N(goomba), .position = 3, .priority = 7 },
};

Formation N(formation_05) = {
    { &N(goomba), .position = 1, .priority = 10 },
    { &N(spiked_goomba), .position = 2, .priority = 9 },
};

Formation N(formation_06) = {
    { &N(goomba), .position = 0, .priority = 10 },
    { &N(paragoomba), .position = 5, .priority = 9 },
    { &N(goomba), .position = 2, .priority = 8 },
    { &N(paragoomba), .position = 7, .priority = 7 },
};

Formation N(formation_07) = {
    { &N(paragoomba), .position = 5, .priority = 10 },
};

Formation N(formation_08) = {
    { &N(paragoomba), .position = 5, .priority = 10 },
    { &N(paragoomba), .position = 6, .priority = 9 },
};

Formation N(formation_09) = {
    { &N(paragoomba), .position = 4, .priority = 10 },
    { &N(paragoomba), .position = 5, .priority = 9 },
    { &N(paragoomba), .position = 6, .priority = 8 },
};

Formation N(formation_0A) = {
    { &N(spiked_goomba), .position = 1, .priority = 10 },
};

Formation N(formation_0B) = {
    { &N(spiked_goomba), .position = 1, .priority = 10 },
    { &N(goomba), .position = 2, .priority = 9 },
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
