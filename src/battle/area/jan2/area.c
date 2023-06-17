#include "area.h"

extern ActorBlueprint A(putrid_piranha);
extern ActorBlueprint A(white_magikoopa);

extern Stage A(jan_00);
extern Stage A(jan_01);
extern Stage A(jan_01b);
extern Stage A(jan_02);
extern Stage A(jan_03);
extern Stage A(jan_03b);
extern Stage A(jan_04);
extern Stage A(jan_04b);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(putrid_piranha), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(white_magikoopa), BTL_POS_GROUND_D, 7),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(jan_01), "ポイズンパックン"),
    BATTLE(A(Formation_01), A(jan_01), "ポイズンパックンx２"),
    BATTLE(A(Formation_02), A(jan_01), "ポイズンパックンx３"),
    BATTLE(A(Formation_03), A(jan_01), "ポイズンパックンx３,ホワイトカメック"),
    {},
};

StageList A(Stages) = {
    STAGE("jan_00", A(jan_00)),
    STAGE("jan_01", A(jan_01)),
    STAGE("jan_01b", A(jan_01b)),
    STAGE("jan_02", A(jan_02)),
    STAGE("jan_03", A(jan_03)),
    STAGE("jan_03b", A(jan_03b)),
    STAGE("jan_04", A(jan_04)),
    STAGE("jan_04b", A(jan_04b)),
    {},
};
