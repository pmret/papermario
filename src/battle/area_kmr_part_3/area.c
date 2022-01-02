#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_3

extern ActorDesc N(jrTroopa1);
extern ActorDesc N(jrTroopa2);
extern ActorDesc N(jrTroopa3);
extern ActorDesc N(jrTroopa4);
extern ActorDesc N(jrTroopa5);
extern ActorDesc N(jrTroopa6);
extern ActorDesc N(paragoomba1);
extern ActorDesc N(paragoomba2);
extern ActorDesc N(spiked_goomba);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);
extern Stage D_80233640_462A80;
extern Stage D_802336AC_462AEC;
extern Stage D_80234C80_4640C0;
extern Stage D_80233AC4_462F04;
extern Stage D_80234DAC_4641EC;

Formation N(formation_00) = {
    { &N(spiked_goomba), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_01) = {
    { &N(paragoomba2), .home = { .index = 5 }, .priority = 10 },
    { &N(paragoomba1), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_02) = {
    { &N(jrTroopa1), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_03) = {
    { &N(jrTroopa2), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_04) = {
    { &N(jrTroopa3), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_05) = {
    { &N(jrTroopa4), .home = { .index = 1 }, .priority = 0 },
};

Formation N(formation_06) = {
    { &N(jrTroopa5), .home = { .index = 2 }, .priority = 0 },
};

Formation N(formation_07) = {
    { &N(jrTroopa6), .home = { .index = 2 }, .priority = 0 },
};

BattleList N(formationTable) = {
    BATTLE("トゲクリボー（レクチャー）", N(formation_00), &N(kmr_03)),
    BATTLE("パタクリボー（レクチャー）", N(formation_01), &N(kmr_03)),
    BATTLE("コワッパ１", N(formation_02), &N(kmr_05)),
    BATTLE("コワッパ２", N(formation_03), &D_80233640_462A80),
    BATTLE("コワッパ４", N(formation_04), &D_802336AC_462AEC),
    BATTLE("コワッパ５", N(formation_05), &D_80234C80_4640C0),
    BATTLE("コワッパ６", N(formation_06), &D_80233AC4_462F04),
    BATTLE("コワッパ７", N(formation_07), &D_80234DAC_4641EC),
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
