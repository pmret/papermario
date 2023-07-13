#include "area.h"

extern ActorBlueprint A(hyper_cleft);
extern ActorBlueprint A(hyper_goomba);
extern ActorBlueprint A(hyper_paragoomba);
extern ActorBlueprint A(tubba_blubba);
extern ActorBlueprint A(tubbas_heart);

extern Stage A(arn_01);
extern Stage A(arn_02);
extern Stage A(arn_03);
extern Stage A(arn_04);
extern Stage A(arn_05);
extern Stage A(arn_06);

Formation A(Formation_00) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_01) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_02) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_03) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_C, 8),
};

Formation A(Formation_04) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_D, 7),
};

Formation A(Formation_05) = {
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_D, 7),
};

Formation A(Formation_06) = {
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_B, 10),
};

Formation A(Formation_07) = {
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_C, 9),
};

Formation A(Formation_08) = {
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_C, 8),
};

Formation A(Formation_09) = {
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_C, 8),
    ACTOR_BY_IDX(A(hyper_paragoomba), BTL_POS_AIR_D, 7),
};

Formation A(Formation_0A) = {
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_B, 10),
};

Formation A(Formation_0B) = {
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_C, 9),
};

Formation A(Formation_0C) = {
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0D) = {
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_C, 8),
};

Formation A(Formation_0E) = {
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(A(hyper_cleft), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(A(hyper_goomba), BTL_POS_GROUND_D, 7),
};

Vec3i A(vector3D_802280C0) = { 90, 20, 0 };

Formation A(Formation_0F) = {
    ACTOR_BY_POS(A(tubbas_heart), A(vector3D_802280C0), 10),
};

Vec3i A(vector3D_802280E8) = { 75, 0, 10 };

Formation A(Formation_10) = {
    ACTOR_BY_POS(A(tubba_blubba), A(vector3D_802280E8), 10),
};

BattleList A(Formations) = {
    BATTLE(A(Formation_00), A(arn_01), "ハイパークリボー"),
    BATTLE(A(Formation_01), A(arn_01), "ハイパークリボーx２"),
    BATTLE(A(Formation_02), A(arn_01), "ハイパークリボーx３"),
    BATTLE(A(Formation_03), A(arn_01), "ハイパークリボーx2,ハイパーパタクリボー"),
    BATTLE(A(Formation_04), A(arn_01), "ハイパークリボーx3,ハイパーパタクリボー"),
    BATTLE(A(Formation_05), A(arn_01), "ハイパークリボーx2,ハイパーパタクリボー,ハイパークリボー"),
    BATTLE(A(Formation_06), A(arn_01), "ハイパーパタクリボー"),
    BATTLE(A(Formation_07), A(arn_01), "ハイパーパタクリボーx2"),
    BATTLE(A(Formation_08), A(arn_01), "ハイパーパタクリボーx3"),
    BATTLE(A(Formation_09), A(arn_01), "ハイパーパタクリボーx4"),
    BATTLE(A(Formation_0A), A(arn_01), "ハイパーシンエモン"),
    BATTLE(A(Formation_0B), A(arn_01), "ハイパーシンエモンx2"),
    BATTLE(A(Formation_0C), A(arn_01), "ハイパーシンエモンx3"),
    BATTLE(A(Formation_0D), A(arn_01), "ハイパーシンエモン,ハイパークリボーx2"),
    BATTLE(A(Formation_0E), A(arn_01), "ハイパーシンエモンx2,ハイパークリボーx2"),
    BATTLE(A(Formation_0F), A(arn_06), "ドガボンしんぞう"),
    BATTLE(A(Formation_10), A(arn_01), "ドガボン"),
    {},
};

StageList A(Stages) = {
    STAGE("arn_01", A(arn_01)),
    STAGE("arn_02", A(arn_02)),
    STAGE("arn_03", A(arn_03)),
    STAGE("arn_04", A(arn_04)),
    STAGE("arn_05", A(arn_05)),
    STAGE("arn_06", A(arn_06)),
    {},
};
