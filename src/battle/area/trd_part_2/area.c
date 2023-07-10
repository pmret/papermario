#include "area.h"

extern ActorBlueprint A(green_ninja_koopa);
extern ActorBlueprint A(yellow_ninja_koopa);
extern ActorBlueprint A(black_ninja_koopa);
extern ActorBlueprint A(red_ninja_koopa);
extern ActorBlueprint A(fake_bowser);

extern Stage A(trd_00);
extern Stage A(trd_01);
extern Stage A(trd_02);
extern Stage A(trd_02b);
extern Stage A(trd_03);
extern Stage A(trd_04);
extern Stage A(trd_05);
extern Stage A(trd_05b);
extern Stage A(trd_05c);
extern Stage A(trd_05d);
extern Stage A(trd_05e);
extern Stage A(trd_05f);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(green_ninja_koopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(yellow_ninja_koopa), BTL_POS_GROUND_A, 9),
    ACTOR_BY_IDX(A(black_ninja_koopa), BTL_POS_GROUND_A, 8),
    ACTOR_BY_IDX(A(red_ninja_koopa), BTL_POS_GROUND_A, 7),
    ACTOR_BY_IDX(A(fake_bowser), BTL_POS_GROUND_D, 6),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(trd_00), "ノコブロス"),
    {},
};

StageList A(Stages) = {
    STAGE("trd_00",  A(trd_00)),
    STAGE("trd_01",  A(trd_01)),
    STAGE("trd_02",  A(trd_02)),
    STAGE("trd_02b", A(trd_02b)),
    STAGE("trd_03",  A(trd_03)),
    STAGE("trd_04",  A(trd_04)),
    STAGE("trd_05",  A(trd_05)),
    STAGE("trd_05b", A(trd_05b)),
    STAGE("trd_05c", A(trd_05c)),
    STAGE("trd_05d", A(trd_05d)),
    STAGE("trd_05e", A(trd_05e)),
    STAGE("trd_05f", A(trd_05f)),
    {},
};
