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
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_04) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_05) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(hypergoomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_06) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 10 },
};

Formation N(Formation_07) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_08) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_09) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_0A) = {
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_0B) = {
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0C) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_cleft), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0D) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0E) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(hypergoomba), .home = { .index = 3 }, .priority = 7 },
};

Vec3i N(vector3D_802280C0) = { 90, 20, 0 };

Formation N(Formation_0F) = {
    { .actor = &N(tubbas_heart), .home = { .vec = &N(vector3D_802280C0) }, .priority = 10 },
};

Vec3i N(vector3D_802280E8) = { 75, 0, 10 };

Formation N(Formation_10) = {
    { .actor = &N(tubba_blubba), .home = { .vec = &N(vector3D_802280E8) }, .priority = 10 },
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
