#include "area.h"

extern ActorBlueprint A(eldstar);

extern Stage A(nok_01);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(eldstar), BTL_POS_AIR_C, 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(nok_01), "ほしのせい レクチャー"),
    {},
};

StageList A(Stages) = {
    STAGE("nok_01", A(nok_01)),
    {},
};
