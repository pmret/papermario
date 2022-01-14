#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_arn

extern ActorDesc N(hyper_cleft);
extern ActorDesc N(hypergoomba);
extern ActorDesc N(hyper_paragoomba);
extern ActorDesc N(tubba_blubba);
extern ActorDesc N(tubbas_heart);

extern Stage N(arn_01);
extern Stage N(arn_02);
extern Stage N(arn_03);
extern Stage N(arn_04);
extern Stage N(arn_05);
extern Stage N(arn_06);

Formation N(formation_00) = {
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_04) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_05) = {
    { .actor = &N(hypergoomba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(hypergoomba), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_06) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 10 },
};

Formation N(formation_07) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_08) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_09) = {
    { .actor = &N(hyper_paragoomba), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(hyper_paragoomba), .home = { .index = 7 }, .priority = 7 },
};

Formation N(formation_0A) = {
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_0B) = {
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0C) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hyper_cleft), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0D) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hypergoomba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_0E) = {
    { .actor = &N(hyper_cleft), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(hyper_cleft), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(hypergoomba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(hypergoomba), .home = { .index = 3 }, .priority = 7 },
};

Vec3i N(vector3D_802280C0) = { 90, 20, 0 };

Formation N(formation_0F) = {
    { .actor = &N(tubbas_heart), .home = { .vec = &N(vector3D_802280C0) }, .priority = 10 },
};

Vec3i N(vector3D_802280E8) = { 75, 0, 10 };

Formation N(formation_10) = {
    { .actor = &N(tubba_blubba), .home = { .vec = &N(vector3D_802280E8) }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("ハイパークリボー", N(formation_00), &N(arn_01)),
    BATTLE("ハイパークリボーx２", N(formation_01), &N(arn_01)),
    BATTLE("ハイパークリボーx３", N(formation_02), &N(arn_01)),
    BATTLE("ハイパークリボーx2,ハイパーパタクリボー", N(formation_03), &N(arn_01)),
    BATTLE("ハイパークリボーx3,ハイパーパタクリボー", N(formation_04), &N(arn_01)),
    BATTLE("ハイパークリボーx2,ハイパーパタクリボー,ハイパークリボー", N(formation_05), &N(arn_01)),
    BATTLE("ハイパーパタクリボー", N(formation_06), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx2", N(formation_07), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx3", N(formation_08), &N(arn_01)),
    BATTLE("ハイパーパタクリボーx4", N(formation_09), &N(arn_01)),
    BATTLE("ハイパーシンエモン", N(formation_0A), &N(arn_01)),
    BATTLE("ハイパーシンエモンx2", N(formation_0B), &N(arn_01)),
    BATTLE("ハイパーシンエモンx3", N(formation_0C), &N(arn_01)),
    BATTLE("ハイパーシンエモン,ハイパークリボーx2", N(formation_0D), &N(arn_01)),
    BATTLE("ハイパーシンエモンx2,ハイパークリボーx2", N(formation_0E), &N(arn_01)),
    BATTLE("ドガボンしんぞう", N(formation_0F), &N(arn_06)),
    BATTLE("ドガボン", N(formation_10), &N(arn_01)),
    {},
};

StageList N(stageTable) = {
    { "arn_01", &N(arn_01) },
    { "arn_02", &N(arn_02) },
    { "arn_03", &N(arn_03) },
    { "arn_04", &N(arn_04) },
    { "arn_05", &N(arn_05) },
    { "arn_06", &N(arn_06) },
    {},
};
