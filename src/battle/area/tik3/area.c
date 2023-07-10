#include "area.h"

extern ActorBlueprint A(swooper);
extern ActorBlueprint A(swoopula);

extern Stage A(tik_01);
extern Stage A(tik_02);
extern Stage A(tik_03);
extern Stage A(tik_04);
extern Stage A(tik_05);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(swooper), BTL_POS_TOP_B, 10),
    ACTOR_BY_IDX(A(swooper), BTL_POS_TOP_C, 9),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(swooper), BTL_POS_TOP_A, 10),
    ACTOR_BY_IDX(A(swooper), BTL_POS_TOP_B, 9),
    ACTOR_BY_IDX(A(swooper), BTL_POS_TOP_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(swoopula), BTL_POS_TOP_B, 10),
    ACTOR_BY_IDX(A(swoopula), BTL_POS_TOP_C, 9),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(swoopula), BTL_POS_TOP_A, 10),
    ACTOR_BY_IDX(A(swoopula), BTL_POS_TOP_B, 9),
    ACTOR_BY_IDX(A(swoopula), BTL_POS_TOP_C, 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(tik_01), "バサバサx２"),
    BATTLE(A(Formation_01), A(tik_01), "バサバサx３"),
    BATTLE(A(Formation_02), A(tik_01), "バサバサチュルルx２"),
    BATTLE(A(Formation_03), A(tik_01), "バサバサチュルルx３"),
    {},
};

StageList A(Stages) = {
    STAGE("tik_01", A(tik_01)),
    STAGE("tik_02", A(tik_02)),
    STAGE("tik_03", A(tik_03)),
    STAGE("tik_04", A(tik_04)),
    STAGE("tik_05", A(tik_05)),
    {},
};
