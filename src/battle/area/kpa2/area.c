#include "area.h"

extern ActorBlueprint A(unused_bowser);
extern ActorBlueprint A(intro_bowser);
extern ActorBlueprint A(hallway_bowser);
extern ActorBlueprint A(final_bowser_1);
extern ActorBlueprint A(final_bowser_2);

extern Stage A(kpa_01);
extern Stage A(kkj_01);
extern Stage A(kkj_02);

Vec3i A(bowser_pos) = { 80, 0, -10 };

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(unused_bowser), BTL_POS_GROUND_C, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(intro_bowser), BTL_POS_GROUND_C, 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(hallway_bowser), BTL_POS_GROUND_C, 10),
};

Formation A(Formation_03) = {
    ACTOR_BY_POS(A(final_bowser_1), A(bowser_pos), 10),
};

Formation A(Formation_04) = {
    ACTOR_BY_POS(A(final_bowser_2), A(bowser_pos), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kpa_01), "クッパ"),
    BATTLE(A(Formation_01), A(kkj_01), "クッパ(オープニング)"),
    BATTLE(A(Formation_02), A(kkj_01), "クッパ(ラストバトル１)"),
    BATTLE(A(Formation_03), A(kkj_02), "クッパ(ラストバトル２)"),
    BATTLE(A(Formation_04), A(kkj_02), "クッパ(ラストバトル３)"),
    {},
};

StageList A(Stages) = {
    STAGE("kpa_01", A(kpa_01)),
    STAGE("kpa_02", A(kkj_01)),
    STAGE("kpa_03", A(kkj_02)),
    {},
};
