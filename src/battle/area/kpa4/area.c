#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa4

extern ActorBlueprint N(bombshell_bill_blaster);
extern ActorBlueprint N(bombshell_bill);
extern ActorBlueprint N(magikoopa);
extern ActorBlueprint N(koopatrol);

extern Stage N(kpa_01);
extern Stage N(kpa_01b);
extern Stage N(kpa_02);
extern Stage N(kpa_03);
extern Stage N(kpa_04);
extern Stage N(kpa_04b);
extern Stage N(kpa_04c);
extern Stage N(kpa_05);
extern Stage N(kpa_07);
extern Stage N(kpa_08);
extern Stage N(kpa_09);
extern Stage N(kpa_11);
extern Stage N(kpa_13);
extern Stage N(kpa_14);

Formation N(formation_00) = {
    { .actor = &N(bombshell_bill), .home = { .index = 1 }, .priority = 10, },
    { .actor = &N(bombshell_bill), .home = { .index = 2 }, .priority = 9, },
};

Formation N(formation_01) = {
    { .actor = &N(bombshell_bill), .home = { .index = 0 }, .priority = 10, },
    { .actor = &N(bombshell_bill), .home = { .index = 1 }, .priority = 9, },
    { .actor = &N(bombshell_bill), .home = { .index = 2 }, .priority = 8, },
};

Vec3i N(blaster_pos_1) = { 70, 0, -20 };

Vec3i N(blaster_pos_2) = { 100, 0, 0 };

Formation N(formation_02) = {
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_1) }, .priority = 10, },
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_2) }, .priority = 9, },
};

Vec3i N(pos_3) = { 130, 0, 25 };

Formation N(formation_03) = {
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_1) }, .priority = 10, },
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_2) }, .priority = 9, },
    { .actor = &N(koopatrol), .home = { .vec = &N(pos_3) }, .priority = 8, },
};

Formation N(formation_04) = {
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_1) }, .priority = 10, },
    { .actor = &N(bombshell_bill_blaster), .home = { .vec = &N(blaster_pos_2) }, .priority = 9, },
    { .actor = &N(magikoopa), .home = { .vec = &N(pos_3) }, .priority = 8, },
};

BattleList N(formationTable) = {
    BATTLE("スーパーキラーx２", N(formation_00), &N(kpa_01)),
    BATTLE("スーパーキラーx３", N(formation_01), &N(kpa_01)),
    BATTLE("スーパーキラーたいほうx２", N(formation_02), &N(kpa_01)),
    BATTLE("スーパーキラーたいほうx２,トゲノコ", N(formation_03), &N(kpa_01)),
    BATTLE("スーパーキラーたいほうx２,カメック", N(formation_04), &N(kpa_01)),
    {},
};

StageList N(stageTable) = {
    { "kpa_01", &N(kpa_01) },
    { "kpa_01b", &N(kpa_01b) },
    { "kpa_02", &N(kpa_02) },
    { "kpa_03", &N(kpa_04) }, // @bug should be &N(kpa_03)
    { "kpa_04", &N(kpa_04) },
    { "kpa_04b", &N(kpa_04b) },
    { "kpa_04c", &N(kpa_04c) },
    { "kpa_05", &N(kpa_05) },
    { "kpa_07", &N(kpa_07) },
    { "kpa_08", &N(kpa_08) },
    { "kpa_09", &N(kpa_09) },
    { "kpa_11", &N(kpa_11) },
    { "kpa_13", &N(kpa_13) },
    { "kpa_14", &N(kpa_14) },
    {},
};
