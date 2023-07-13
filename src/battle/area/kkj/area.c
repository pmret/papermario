#include "area.h"

extern ActorBlueprint A(kammy_koopa);

extern Stage A(kkj_02);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(kammy_koopa), BTL_POS_AIR_C, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(kkj_02), "カメックばば（ピーチ、ティンクせん）"),
    {},
};

StageList A(Stages) = {
    STAGE("kpa_05", A(kkj_02)),
    {},
};
