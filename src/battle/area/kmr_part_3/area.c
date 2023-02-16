#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3

extern ActorBlueprint N(jr_troopa);
extern ActorBlueprint N(egg_jr_troopa);
extern ActorBlueprint N(para_jr_troopa);
extern ActorBlueprint N(spiked_para_jr_troopa);
extern ActorBlueprint N(mage_jr_troopa);
extern ActorBlueprint N(final_jr_troopa);
extern ActorBlueprint N(paragoomba1);
extern ActorBlueprint N(paragoomba2);
extern ActorBlueprint N(spiked_goomba);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);
extern Stage N(nok_01);
extern Stage N(mim_01);
extern Stage N(sam_01);
extern Stage N(mac_01);
extern Stage N(kpa_01);

Formation N(formation_00) = {
    { .actor = &N(spiked_goomba), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_01) = {
    { .actor = &N(paragoomba2), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paragoomba1), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(jr_troopa), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_03) = {
    { .actor = &N(egg_jr_troopa), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_04) = {
    { .actor = &N(para_jr_troopa), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_05) = {
    { .actor = &N(spiked_para_jr_troopa), .home = { .index = 1 }, .priority = 0 },
};

Formation N(formation_06) = {
    { .actor = &N(mage_jr_troopa), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_07) = {
    { .actor = &N(final_jr_troopa), .home = { .index = 2 }, .priority = 0 },
};

BattleList N(formationTable) = {
    BATTLE("トゲクリボー（レクチャー）", N(formation_00), &N(kmr_03)),
    BATTLE("パタクリボー（レクチャー）", N(formation_01), &N(kmr_03)),
    BATTLE("コワッパ１", N(formation_02), &N(kmr_05)),
    BATTLE("コワッパ２", N(formation_03), &N(nok_01)),
    BATTLE("コワッパ４", N(formation_04), &N(mim_01)),
    BATTLE("コワッパ５", N(formation_05), &N(mac_01)),
    BATTLE("コワッパ６", N(formation_06), &N(sam_01)),
    BATTLE("コワッパ７", N(formation_07), &N(kpa_01)),
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
