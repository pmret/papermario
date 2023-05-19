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

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(bombshell_bill), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(bombshell_bill), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(bombshell_bill), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bombshell_bill), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bombshell_bill), BTL_POS_GROUND_C, 8),
};

Vec3i N(blaster_pos_1) = { 70, 0, -20 };

Vec3i N(blaster_pos_2) = { 100, 0, 0 };

Formation N(Formation_02) = {
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_1), 10),
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_2), 9),
};

Vec3i N(pos_3) = { 130, 0, 25 };

Formation N(Formation_03) = {
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_1), 10),
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_2), 9),
    ACTOR_BY_POS(N(koopatrol), N(pos_3), 8),
};

Formation N(Formation_04) = {
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_1), 10),
    ACTOR_BY_POS(N(bombshell_bill_blaster), N(blaster_pos_2), 9),
    ACTOR_BY_POS(N(magikoopa), N(pos_3), 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kpa_01), "スーパーキラーx２"),
    BATTLE(N(Formation_01), &N(kpa_01), "スーパーキラーx３"),
    BATTLE(N(Formation_02), &N(kpa_01), "スーパーキラーたいほうx２"),
    BATTLE(N(Formation_03), &N(kpa_01), "スーパーキラーたいほうx２,トゲノコ"),
    BATTLE(N(Formation_04), &N(kpa_01), "スーパーキラーたいほうx２,カメック"),
    {},
};

StageList N(Stages) = {
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
