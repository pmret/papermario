#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2

extern ActorBlueprint N(putrid_piranha);
extern ActorBlueprint N(white_magikoopa);

extern Stage N(jan_00);
extern Stage N(jan_01);
extern Stage N(jan_01b);
extern Stage N(jan_02);
extern Stage N(jan_03);
extern Stage N(jan_03b);
extern Stage N(jan_04);
extern Stage N(jan_04b);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(putrid_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(white_magikoopa), BTL_POS_GROUND_D, 7),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(jan_01), "ポイズンパックン"),
    BATTLE(N(Formation_01), N(jan_01), "ポイズンパックンx２"),
    BATTLE(N(Formation_02), N(jan_01), "ポイズンパックンx３"),
    BATTLE(N(Formation_03), N(jan_01), "ポイズンパックンx３,ホワイトカメック"),
    {},
};

StageList N(Stages) = {
    STAGE("jan_00", N(jan_00)),
    STAGE("jan_01", N(jan_01)),
    STAGE("jan_01b", N(jan_01b)),
    STAGE("jan_02", N(jan_02)),
    STAGE("jan_03", N(jan_03)),
    STAGE("jan_03b", N(jan_03b)),
    STAGE("jan_04", N(jan_04)),
    STAGE("jan_04b", N(jan_04b)),
    {},
};
