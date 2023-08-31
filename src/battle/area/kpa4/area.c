#include "area.h"

extern ActorBlueprint A(bombshell_blaster);
extern ActorBlueprint A(bombshell_bill);
extern ActorBlueprint A(magikoopa);
extern ActorBlueprint A(koopatrol);

extern Stage A(kpa_01);
extern Stage A(kpa_01b);
extern Stage A(kpa_02);
extern Stage A(kpa_03);
extern Stage A(kpa_04);
extern Stage A(kpa_04b);
extern Stage A(kpa_04c);
extern Stage A(kpa_05);
extern Stage A(kpa_07);
extern Stage A(kpa_08);
extern Stage A(kpa_09);
extern Stage A(kpa_11);
extern Stage A(kpa_13);
extern Stage A(kpa_14);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(bombshell_bill), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(bombshell_bill), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(bombshell_bill), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(bombshell_bill), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(bombshell_bill), BTL_POS_GROUND_C, 8),
};

Vec3i A(blaster_pos_1) = { 70, 0, -20 };

Vec3i A(blaster_pos_2) = { 100, 0, 0 };

Formation A(Formation_02) = {
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_1), 10),
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_2), 9),
};

Vec3i A(pos_3) = { 130, 0, 25 };

Formation A(Formation_03) = {
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_1), 10),
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_2), 9),
    ACTOR_BY_POS(A(koopatrol), A(pos_3), 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_1), 10),
    ACTOR_BY_POS(A(bombshell_blaster), A(blaster_pos_2), 9),
    ACTOR_BY_POS(A(magikoopa), A(pos_3), 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kpa_01), "スーパーキラーx２"),
    BATTLE(A(Formation_01), A(kpa_01), "スーパーキラーx３"),
    BATTLE(A(Formation_02), A(kpa_01), "スーパーキラーたいほうx２"),
    BATTLE(A(Formation_03), A(kpa_01), "スーパーキラーたいほうx２,トゲノコ"),
    BATTLE(A(Formation_04), A(kpa_01), "スーパーキラーたいほうx２,カメック"),
    {},
};

StageList A(Stages) = {
    STAGE("kpa_01", A(kpa_01)),
    STAGE("kpa_01b", A(kpa_01b)),
    STAGE("kpa_02", A(kpa_02)),
    STAGE("kpa_03", A(kpa_04)), // @bug should be &A(kpa_03)
    STAGE("kpa_04", A(kpa_04)),
    STAGE("kpa_04b", A(kpa_04b)),
    STAGE("kpa_04c", A(kpa_04c)),
    STAGE("kpa_05", A(kpa_05)),
    STAGE("kpa_07", A(kpa_07)),
    STAGE("kpa_08", A(kpa_08)),
    STAGE("kpa_09", A(kpa_09)),
    STAGE("kpa_11", A(kpa_11)),
    STAGE("kpa_13", A(kpa_13)),
    STAGE("kpa_14", A(kpa_14)),
    {},
};
