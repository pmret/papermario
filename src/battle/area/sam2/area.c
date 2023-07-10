#include "area.h"

extern ActorBlueprint A(monstar);
extern ActorBlueprint A(paragoomba);
extern ActorBlueprint A(gray_magikoopa);

extern Stage A(sam_01);
extern Stage A(sam_02);
extern Stage A(sam_02b);
extern Stage A(sam_02c);
extern Stage A(sam_02d);
extern Stage A(sam_03);

Vec3i A(MonstarPos) = { 75, 16, 5 };

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(monstar), A(MonstarPos), 10),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(paragoomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(gray_magikoopa), BTL_POS_GROUND_C, 9),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(sam_03), "かいぶつ"),
    BATTLE(A(Formation_02), A(sam_01), "パタクリ,グレイカメック（チェックよう）"),
    {},
};

StageList A(Stages) = {
    STAGE("sam_01", A(sam_01)),
    STAGE("sam_02", A(sam_02)),
    STAGE("sam_02b", A(sam_02b)),
    STAGE("sam_02c", A(sam_02c)),
    STAGE("sam_02d", A(sam_02d)),
    STAGE("sam_03", A(sam_03)),
    {},
};
