#include "area.h"

extern ActorBlueprint A(kammy_koopa);

extern Stage A(kpa_05);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(kammy_koopa), BTL_POS_AIR_C, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kpa_05), "カメックばば（ピーチ、ティンクせん）"),
    {},
};

StageList A(Stages) = {
    STAGE("kpa_05", A(kpa_05)),
    {},
};
