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

Formation N(Formation_00) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_01) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_03) = {
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_05) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_06) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_08) = {
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 9 },
};

Formation N(Formation_09) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(paratroopa), .home = { .index = 5 }, .priority = 9 },
    { .actor = &N(paratroopa), .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0A) = {
    { .actor = &N(paratroopa),   .home = { .index = 5 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0B) = {
    { .actor = &N(paratroopa),   .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paratroopa),   .home = { .index = 6 }, .priority = 8 },
};

Formation N(Formation_0C) = {
    { .actor = &N(paratroopa),   .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(paratroopa),   .home = { .index = 6 }, .priority = 8 },
    { .actor = &N(koopa_troopa), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0D) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0E) = {
    { .actor = &N(paratroopa), .home = { .index = 4 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = 2 }, .priority = 9 },
    { .actor = &N(bob_omb),    .home = { .index = 3 }, .priority = 8 },
};

Formation N(Formation_0F) = {
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_10) = {
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_11) = {
    { .actor = &N(bob_omb), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_12) = {
    { .actor = &N(bob_omb), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(bob_omb), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_13) = {
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_14) = {
    { .actor = &N(bob_omb),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_15) = {
    { .actor = &N(bob_omb),      .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(koopa_troopa), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(koopa_troopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_16) = {
    { .actor = &N(koopa_troopa), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = 2 }, .priority = 8 },
};

Vec3i N(vector3D_80218B90) = { 50, 0, -20, };

Vec3i N(vector3D_80218B9C) = { 80, 0, 0, };

Vec3i N(vector3D_80218BA8) = { 110, 0, 20, };

Formation N(Formation_17) = {
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218B90) }, .priority = 10 },
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218B9C) }, .priority = 9 },
    { .actor = &N(bill_blaster), .home = { .vec = &N(vector3D_80218BA8) }, .priority = 9 },
};

Formation N(Formation_18) = {
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(bullet_bill), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_19) = {
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_1A) = {
    { .actor = &N(bullet_bill), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(bullet_bill), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(bullet_bill), .home = { .index = 2 }, .priority = 8 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(trd_01), "ノコノコ"),
    BATTLE(N(Formation_01), &N(trd_01), "ノコノコx2"),
    BATTLE(N(Formation_02), &N(trd_01), "ノコノコx3"),
    BATTLE(N(Formation_03), &N(trd_01), "ノコノコ,ボムへい"),
    BATTLE(N(Formation_04), &N(trd_01), "ノコノコ,ボムへいx2"),
    BATTLE(N(Formation_05), &N(trd_01), "ノコノコ,ボムへいx3"),
    BATTLE(N(Formation_06), &N(trd_01), "ノコノコx2,ボムへい"),
    BATTLE(N(Formation_07), &N(trd_01), "ノコノコx2,ボムへいx2"),
    BATTLE(N(Formation_08), &N(trd_01), "パタパタx２"),
    BATTLE(N(Formation_09), &N(trd_01), "パタパタx３"),
    BATTLE(N(Formation_0A), &N(trd_01), "パタパタ,ノコノコ"),
    BATTLE(N(Formation_0B), &N(trd_01), "パタパタ,ノコノコ,パタパタ"),
    BATTLE(N(Formation_0C), &N(trd_01), "パタパタ,ノコノコ,パタパタ,ノコノコ"),
    BATTLE(N(Formation_0D), &N(trd_01), "パタパタ,ボムヘイx２"),
    BATTLE(N(Formation_0E), &N(trd_01), "パタパタ,ボムヘイx３"),
    BATTLE(N(Formation_0F), &N(trd_01), "ボムへい"),
    BATTLE(N(Formation_10), &N(trd_01), "ボムへいx2"),
    BATTLE(N(Formation_11), &N(trd_01), "ボムへいx3"),
    BATTLE(N(Formation_12), &N(trd_01), "ボムへいx4"),
    BATTLE(N(Formation_13), &N(trd_01), "ボムへい,ノコノコ"),
    BATTLE(N(Formation_14), &N(trd_01), "ボムへいx2,ノコノコ"),
    BATTLE(N(Formation_15), &N(trd_01), "ボムへい,ノコノコx2"),
    BATTLE(N(Formation_16), &N(trd_01), "ノコノコ,ボムへいx2"),
    BATTLE(N(Formation_17), &N(trd_01), "キラーたいほうx３"),
    BATTLE(N(Formation_18), &N(trd_01), "キラーx２"),
    BATTLE(N(Formation_19), &N(trd_01), "キラー"),
    BATTLE(N(Formation_1A), &N(trd_01), "キラーx３"),
    {},
};

StageList N(Stages) = {
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
