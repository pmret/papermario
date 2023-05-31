#include "area.h"

extern ActorBlueprint A(fuzzipede);

extern Stage A(kgr_01);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(fuzzipede), BTL_POS_GROUND_C, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kgr_01), "ケムシ"),
    {},
};

StageList A(Stages) = {
    STAGE("kgr_01", A(kgr_01)),
    {},
};
