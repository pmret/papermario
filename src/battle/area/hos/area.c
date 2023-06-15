#include "area.h"

extern ActorBlueprint A(ember);
extern ActorBlueprint A(goombario_tutor);
extern ActorBlueprint A(magikoopa_flying);

extern Stage A(hos_00);
extern Stage A(hos_01);
extern Stage A(hos_02);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(goombario_tutor), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(ember), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(magikoopa_flying), BTL_POS_AIR_B, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(hos_02), "クリオ（ＡＣヘルプ）"),
    BATTLE(A(Formation_01), A(hos_01), "エルモスx２"),
    BATTLE(A(Formation_02), A(hos_01), "エルモスx３"),
    BATTLE(A(Formation_03), A(hos_02), "カメック（ＡＣヘルプご）"),
    {},
};

StageList A(Stages) = {
    STAGE("hos_00", A(hos_00)),
    STAGE("hos_01", A(hos_01)),
    STAGE("hos_02", A(hos_02)),
    {},
};
