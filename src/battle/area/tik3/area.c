#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_tik3

extern ActorBlueprint N(swooper);
extern ActorBlueprint N(swoopula);

extern Stage N(tik_01);
extern Stage N(tik_02);
extern Stage N(tik_03);
extern Stage N(tik_04);
extern Stage N(tik_05);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(swooper), BTL_POS_TOP_B, 10),
    ACTOR_BY_IDX(N(swooper), BTL_POS_TOP_C, 9),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(swooper), BTL_POS_TOP_A, 10),
    ACTOR_BY_IDX(N(swooper), BTL_POS_TOP_B, 9),
    ACTOR_BY_IDX(N(swooper), BTL_POS_TOP_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(swoopula), BTL_POS_TOP_B, 10),
    ACTOR_BY_IDX(N(swoopula), BTL_POS_TOP_C, 9),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(swoopula), BTL_POS_TOP_A, 10),
    ACTOR_BY_IDX(N(swoopula), BTL_POS_TOP_B, 9),
    ACTOR_BY_IDX(N(swoopula), BTL_POS_TOP_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(tik_01), "バサバサx２"),
    BATTLE(N(Formation_01), N(tik_01), "バサバサx３"),
    BATTLE(N(Formation_02), N(tik_01), "バサバサチュルルx２"),
    BATTLE(N(Formation_03), N(tik_01), "バサバサチュルルx３"),
    {},
};

StageList N(Stages) = {
    STAGE("tik_01", N(tik_01)),
    STAGE("tik_02", N(tik_02)),
    STAGE("tik_03", N(tik_03)),
    STAGE("tik_04", N(tik_04)),
    STAGE("tik_05", N(tik_05)),
    {},
};
