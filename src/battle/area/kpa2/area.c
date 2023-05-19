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

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(bowser), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(bowser_intro), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(bowser_phase_1), BTL_POS_GROUND_C, 10),
};

Formation N(Formation_03) = {
    ACTOR_BY_POS(N(bowser_phase_2), N(bowser_pos), 10),
};

Formation N(Formation_04) = {
    ACTOR_BY_POS(N(bowser_phase_3), N(bowser_pos), 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_01), "クッパ"),
    BATTLE(N(Formation_01), &N(kpa_02), "クッパ(オープニング)"),
    BATTLE(N(Formation_02), &N(kpa_02), "クッパ(ラストバトル１)"),
    BATTLE(N(Formation_03), &N(kpa_03), "クッパ(ラストバトル２)"),
    BATTLE(N(Formation_04), &N(kpa_03), "クッパ(ラストバトル３)"),
    {},
};

StageList N(Stages) = {
    { "kpa_01", &N(kpa_01) },
    { "kpa_02", &N(kpa_02) },
    { "kpa_03", &N(kpa_03) },
    {},
};
