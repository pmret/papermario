#include "area.h"

extern ActorBlueprint A(swoopula);
extern ActorBlueprint A(duplighost);
extern ActorBlueprint A(red_magikoopa);
extern ActorBlueprint A(gray_magikoopa);
extern ActorBlueprint A(white_clubba);

extern Stage A(pra_01);
extern Stage A(pra_02);
extern Stage A(pra_03);
extern Stage A(pra_03b);
extern Stage A(pra_03c);
extern Stage A(pra_04);

Vec3i A(pos_swoopula)[] = {
    { 15, 133, -25 },
    { 55, 133, -25 },
    { 95, 133, -25 },
    { 135, 133, -25 },
};

Formation A(Formation_01) = {
    ACTOR_BY_POS(A(swoopula), A(pos_swoopula)[0], 10),
    ACTOR_BY_POS(A(swoopula), A(pos_swoopula)[1], 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(A(swoopula), A(pos_swoopula)[2], 8),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_POS(A(swoopula), A(pos_swoopula)[1], 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(red_magikoopa), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(red_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(gray_magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(red_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(duplighost), BTL_POS_GROUND_C, 8),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_01), A(pra_01), "バサバサチュルルx２,バケバケ"),
    BATTLE(A(Formation_02), A(pra_01), "バケバケ"),
    BATTLE(A(Formation_03), A(pra_01), "バケバケx2"),
    BATTLE(A(Formation_04), A(pra_01), "バケバケx3"),
    BATTLE(A(Formation_05), A(pra_01), "バケバケx4"),
    BATTLE(A(Formation_06), A(pra_01), "バケバケx２,バサバサチュルル"),
    BATTLE(A(Formation_07), A(pra_01), "バケバケ,バサバサチュルル,バケバケ"),
    BATTLE(A(Formation_08), A(pra_01), "バケバケ,レッドカメック"),
    BATTLE(A(Formation_09), A(pra_01), "バケバケx２,レッドカメック"),
    BATTLE(A(Formation_0A), A(pra_01), "バケバケ,ホワイトガボン,バケバケ"),
    BATTLE(A(Formation_0B), A(pra_01), "バケバケx２,グレイカメック,レッドカメック"),
    BATTLE(A(Formation_0C), A(pra_01), "ホワイトガボンx２,バケバケ"),
    {},
};

StageList A(Stages) = {
    STAGE("pra_01", A(pra_01)),
    STAGE("pra_02", A(pra_02)),
    STAGE("pra_03", A(pra_03)),
    STAGE("pra_03b", A(pra_03b)),
    STAGE("pra_03c", A(pra_03c)),
    STAGE("pra_04", A(pra_04)),
    {},
};
