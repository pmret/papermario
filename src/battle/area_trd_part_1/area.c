#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_trd_part_1

extern ActorBlueprint N(koopa_troopa);
extern ActorBlueprint N(paratroopa);
extern ActorBlueprint N(bob_omb);
extern ActorBlueprint N(bill_blaster);
extern ActorBlueprint N(bullet_bill);

extern Stage N(trd_00);
extern Stage N(trd_01);
extern Stage N(trd_02);
extern Stage N(trd_02b);
extern Stage N(trd_02c);
extern Stage N(trd_02d);
extern Stage N(trd_03);
extern Stage N(trd_04);
extern Stage N(trd_05);
extern Stage N(trd_05b);
extern Stage N(trd_05c);
extern Stage N(trd_05d);
extern Stage N(trd_05e);
extern Stage N(trd_05f);

Formation N(formation_00) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_01) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_02) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_03) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_04) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_05) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_06) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_07) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_08) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 9 },
};

Formation N(formation_09) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0A) = {
    { .actor = &N(paratroopa),   .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0B) = {
    { .actor = &N(paratroopa),   .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paratroopa),   .home = { .index = 6 }, .priority = 8 },
};

Formation N(formation_0C) = {
    { .actor = &N(paratroopa),   .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paratroopa),   .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(koopa_troopa), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_0D) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_0E) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 2 }, .priority = 9 },
    { .actor = &N(bob_omb),    .home = { .index = 3 }, .priority = 8 },
};

Formation N(formation_0F) = {
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_10) = {
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_11) = {
    { .actor = &N(bob_omb), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_12) = {
    { .actor = &N(bob_omb), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb), .home = { .index = 3 }, .priority = 7 },
};

Formation N(formation_13) = {
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_14) = {
    { .actor = &N(bob_omb),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_15) = {
    { .actor = &N(bob_omb),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(formation_16) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Vec3i N(vector3D_80218B90) = { 50, 0, -20, };

Vec3i N(vector3D_80218B9C) = { 80, 0, 0, };

Vec3i N(vector3D_80218BA8) = { 110, 0, 20, };

Formation N(formation_17) = {
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218B90) }, .priority = 10 },
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218B9C) }, .priority = 9 },
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218BA8) }, .priority = 9 },
};

Formation N(formation_18) = {
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bullet_bill), .home = { .index = 2 }, .priority = 9 },
};

Formation N(formation_19) = {
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 10 },
};

Formation N(formation_1A) = {
    { .actor = &N(bullet_bill), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bullet_bill), .home = { .index = 2 }, .priority = 8 },
};

BattleList N(formationTable) = {
    BATTLE("ノコノコ", N(formation_00), &N(trd_01)),
    BATTLE("ノコノコx2", N(formation_01), &N(trd_01)),
    BATTLE("ノコノコx3", N(formation_02), &N(trd_01)),
    BATTLE("ノコノコ,ボムへい", N(formation_03), &N(trd_01)),
    BATTLE("ノコノコ,ボムへいx2", N(formation_04), &N(trd_01)),
    BATTLE("ノコノコ,ボムへいx3", N(formation_05), &N(trd_01)),
    BATTLE("ノコノコx2,ボムへい", N(formation_06), &N(trd_01)),
    BATTLE("ノコノコx2,ボムへいx2", N(formation_07), &N(trd_01)),
    BATTLE("パタパタx２", N(formation_08), &N(trd_01)),
    BATTLE("パタパタx３", N(formation_09), &N(trd_01)),
    BATTLE("パタパタ,ノコノコ", N(formation_0A), &N(trd_01)),
    BATTLE("パタパタ,ノコノコ,パタパタ", N(formation_0B), &N(trd_01)),
    BATTLE("パタパタ,ノコノコ,パタパタ,ノコノコ", N(formation_0C), &N(trd_01)),
    BATTLE("パタパタ,ボムヘイx２", N(formation_0D), &N(trd_01)),
    BATTLE("パタパタ,ボムヘイx３", N(formation_0E), &N(trd_01)),
    BATTLE("ボムへい", N(formation_0F), &N(trd_01)),
    BATTLE("ボムへいx2", N(formation_10), &N(trd_01)),
    BATTLE("ボムへいx3", N(formation_11), &N(trd_01)),
    BATTLE("ボムへいx4", N(formation_12), &N(trd_01)),
    BATTLE("ボムへい,ノコノコ", N(formation_13), &N(trd_01)),
    BATTLE("ボムへいx2,ノコノコ", N(formation_14), &N(trd_01)),
    BATTLE("ボムへい,ノコノコx2", N(formation_15), &N(trd_01)),
    BATTLE("ノコノコ,ボムへいx2", N(formation_16), &N(trd_01)),
    BATTLE("キラーたいほうx３", N(formation_17), &N(trd_01)),
    BATTLE("キラーx２", N(formation_18), &N(trd_01)),
    BATTLE("キラー", N(formation_19), &N(trd_01)),
    BATTLE("キラーx３", N(formation_1A), &N(trd_01)),
    {},
};

StageList N(stageTable) = {
    { "trd_00",  &N(trd_00) },
    { "trd_01",  &N(trd_01) },
    { "trd_02",  &N(trd_02) },
    { "trd_02b", &N(trd_02b) },
    { "trd_02c", &N(trd_02c) },
    { "trd_02d", &N(trd_02d) },
    { "trd_03",  &N(trd_03) },
    { "trd_04",  &N(trd_04) },
    { "trd_05",  &N(trd_05) },
    { "trd_05b", &N(trd_05b) },
    { "trd_05c", &N(trd_05c) },
    { "trd_05d", &N(trd_05d) },
    { "trd_05e", &N(trd_05e) },
    { "trd_05f", &N(trd_05f) },
    {},
};
