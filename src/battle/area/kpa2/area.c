#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kpa2

extern ActorBlueprint N(bowser);
extern ActorBlueprint N(bowser_intro);
extern ActorBlueprint N(bowser_phase_1);
extern ActorBlueprint N(bowser_phase_2);
extern ActorBlueprint N(bowser_phase_3);

extern Stage N(kpa_01);
extern Stage N(kpa_02);
extern Stage N(kpa_03);

Vec3i N(bowser_pos) = { 80, 0, -10 };

Formation N(formation_00) = {
    { .actor = &N(bowser), .home = { .index = 2 }, .priority = 10, },
};

Formation N(formation_01) = {
    { .actor = &N(bowser_intro), .home = { .index = 2 }, .priority = 10, },
};

Formation N(formation_02) = {
    { .actor = &N(bowser_phase_1), .home = { .index = 2 }, .priority = 10, },
};

Formation N(formation_03) = {
    { .actor = &N(bowser_phase_2), .home = { .vec = &N(bowser_pos) }, .priority = 10, },
};

Formation N(formation_04) = {
    { .actor = &N(bowser_phase_3), .home = { .vec = &N(bowser_pos) }, .priority = 10, },
};

BattleList N(formationTable) = {
    BATTLE("クッパ", N(formation_00), &N(kpa_01)),
    BATTLE("クッパ(オープニング)", N(formation_01), &N(kpa_02)),
    BATTLE("クッパ(ラストバトル１)", N(formation_02), &N(kpa_02)),
    BATTLE("クッパ(ラストバトル２)", N(formation_03), &N(kpa_03)),
    BATTLE("クッパ(ラストバトル３)", N(formation_04), &N(kpa_03)),
    {},
};

StageList N(stageTable) = {
    { "kpa_01", &N(kpa_01) },
    { "kpa_02", &N(kpa_02) },
    { "kpa_03", &N(kpa_03) },
    {},
};
