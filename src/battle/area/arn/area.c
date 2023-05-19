#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_arn

extern ActorBlueprint N(hyper_cleft);
extern ActorBlueprint N(hypergoomba);
extern ActorBlueprint N(hyper_paragoomba);
extern ActorBlueprint N(tubba_blubba);
extern ActorBlueprint N(tubbas_heart);

extern Stage N(arn_01);
extern Stage N(arn_02);
extern Stage N(arn_03);
extern Stage N(arn_04);
extern Stage N(arn_05);
extern Stage N(arn_06);

Formation N(Formation_00) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_C, 8),
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_D, 7),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_B, 10),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_C, 9),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_C, 8),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(N(hyper_paragoomba), BTL_POS_AIR_D, 7),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(hyper_cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(hypergoomba), BTL_POS_GROUND_D, 7),
};

Vec3i N(vector3D_802280C0) = { 90, 20, 0 };

Formation N(Formation_0F) = {
    ACTOR_BY_POS(N(tubbas_heart), N(vector3D_802280C0), 10),
};

Vec3i N(vector3D_802280E8) = { 75, 0, 10 };

Formation N(Formation_10) = {
    ACTOR_BY_POS(N(tubba_blubba), N(vector3D_802280E8), 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(arn_01), "ハイパークリボー"),
    BATTLE(N(Formation_01), &N(arn_01), "ハイパークリボーx２"),
    BATTLE(N(Formation_02), &N(arn_01), "ハイパークリボーx３"),
    BATTLE(N(Formation_03), &N(arn_01), "ハイパークリボーx2,ハイパーパタクリボー"),
    BATTLE(N(Formation_04), &N(arn_01), "ハイパークリボーx3,ハイパーパタクリボー"),
    BATTLE(N(Formation_05), &N(arn_01), "ハイパークリボーx2,ハイパーパタクリボー,ハイパークリボー"),
    BATTLE(N(Formation_06), &N(arn_01), "ハイパーパタクリボー"),
    BATTLE(N(Formation_07), &N(arn_01), "ハイパーパタクリボーx2"),
    BATTLE(N(Formation_08), &N(arn_01), "ハイパーパタクリボーx3"),
    BATTLE(N(Formation_09), &N(arn_01), "ハイパーパタクリボーx4"),
    BATTLE(N(Formation_0A), &N(arn_01), "ハイパーシンエモン"),
    BATTLE(N(Formation_0B), &N(arn_01), "ハイパーシンエモンx2"),
    BATTLE(N(Formation_0C), &N(arn_01), "ハイパーシンエモンx3"),
    BATTLE(N(Formation_0D), &N(arn_01), "ハイパーシンエモン,ハイパークリボーx2"),
    BATTLE(N(Formation_0E), &N(arn_01), "ハイパーシンエモンx2,ハイパークリボーx2"),
    BATTLE(N(Formation_0F), &N(arn_06), "ドガボンしんぞう"),
    BATTLE(N(Formation_10), &N(arn_01), "ドガボン"),
    {},
};

StageList N(Stages) = {
    { "arn_01", &N(arn_01) },
    { "arn_02", &N(arn_02) },
    { "arn_03", &N(arn_03) },
    { "arn_04", &N(arn_04) },
    { "arn_05", &N(arn_05) },
    { "arn_06", &N(arn_06) },
    {},
};
