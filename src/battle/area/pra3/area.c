#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra3

extern ActorBlueprint N(swoopula);
extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(red_magikoopa);
extern ActorBlueprint N(gray_magikoopa);
extern ActorBlueprint N(white_clubba);

extern Stage N(pra_01);
extern Stage N(pra_02);
extern Stage N(pra_03);
extern Stage N(pra_03b);
extern Stage N(pra_03c);
extern Stage N(pra_04);

Vec3i N(pos_swoopula)[] = {
    { 15, 133, -25 },
    { 55, 133, -25 },
    { 95, 133, -25 },
    { 135, 133, -25 },
};

Formation N(Formation_01) = {
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[0], 10),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[1], 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[2], 8),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[1], 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(red_magikoopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(red_magikoopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(gray_magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(red_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(duplighost), BTL_POS_GROUND_C, 8),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), N(pra_01), "バサバサチュルルx２,バケバケ"),
    BATTLE(N(Formation_02), N(pra_01), "バケバケ"),
    BATTLE(N(Formation_03), N(pra_01), "バケバケx2"),
    BATTLE(N(Formation_04), N(pra_01), "バケバケx3"),
    BATTLE(N(Formation_05), N(pra_01), "バケバケx4"),
    BATTLE(N(Formation_06), N(pra_01), "バケバケx２,バサバサチュルル"),
    BATTLE(N(Formation_07), N(pra_01), "バケバケ,バサバサチュルル,バケバケ"),
    BATTLE(N(Formation_08), N(pra_01), "バケバケ,レッドカメック"),
    BATTLE(N(Formation_09), N(pra_01), "バケバケx２,レッドカメック"),
    BATTLE(N(Formation_0A), N(pra_01), "バケバケ,ホワイトガボン,バケバケ"),
    BATTLE(N(Formation_0B), N(pra_01), "バケバケx２,グレイカメック,レッドカメック"),
    BATTLE(N(Formation_0C), N(pra_01), "ホワイトガボンx２,バケバケ"),
    {},
};

StageList N(Stages) = {
    STAGE("pra_01", N(pra_01)),
    STAGE("pra_02", N(pra_02)),
    STAGE("pra_03", N(pra_03)),
    STAGE("pra_03b", N(pra_03b)),
    STAGE("pra_03c", N(pra_03c)),
    STAGE("pra_04", N(pra_04)),
    {},
};
