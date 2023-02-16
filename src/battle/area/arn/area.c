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
    BATTLE("ハイパークリボー", N(Formation_00), &N(arn_01)),
    BATTLE("ハイパークリボーx２", N(Formation_01), &N(arn_01)),
    BATTLE("ハイパークリボーx３", N(Formation_02), &N(arn_01)),
    BATTLE("ハイパークリボーx2,ハイパーパタクリボー", N(Formation_03), &N(arn_01)),
    BATTLE("ハイパークリボーx3,ハイパーパタクリボー", N(Formation_04), &N(arn_01)),
    BATTLE("ハイパークリボーx2,ハイパーパタクリボー,ハイパークリボー", N(Formation_05), &N(arn_01)),
    BATTLE("ハイパーパタクリボー", N(Formation_06), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx2", N(Formation_07), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx3", N(Formation_08), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx4", N(Formation_09), &N(arn_01)),
    BATTLE("ハイパーシンエモン", N(Formation_0A), &N(arn_01)),
    BATTLE("ハイパーシンエモンx2", N(Formation_0B), &N(arn_01)),
    BATTLE("ハイパーシンエモンx3", N(Formation_0C), &N(arn_01)),
    BATTLE("ハイパーシンエモン,ハイパークリボーx2", N(Formation_0D), &N(arn_01)),
    BATTLE("ハイパーシンエモンx2,ハイパークリボーx2", N(Formation_0E), &N(arn_01)),
    BATTLE("ドガボンしんぞう", N(Formation_0F), &N(arn_06)),
    BATTLE("ドガボン", N(Formation_10), &N(arn_01)),
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
