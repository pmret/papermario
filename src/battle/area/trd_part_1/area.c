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
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_01) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_03) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 10),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

Formation N(Formation_04) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_D }, .priority = 7 },
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_D }, .priority = 7 },
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_B, 10),
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_C, 9),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_A, 10),
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_B, 9),
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_C, 8),
};

Formation N(Formation_0A) = {
    { .actor = &N(paratroopa),   .home = { .index = BTL_POS_AIR_B }, .priority = 10 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0B) = {
    { .actor = &N(paratroopa),   .home = { .index = BTL_POS_AIR_A }, .priority = 10 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    { .actor = &N(paratroopa),   .home = { .index = BTL_POS_AIR_C }, .priority = 8 },
};

Formation N(Formation_0C) = {
    { .actor = &N(paratroopa),   .home = { .index = BTL_POS_AIR_A }, .priority = 10 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    { .actor = &N(paratroopa),   .home = { .index = BTL_POS_AIR_C }, .priority = 8 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_A, 10),
    { .actor = &N(bob_omb),    .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(paratroopa), BTL_POS_AIR_A, 10),
    { .actor = &N(bob_omb),    .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    { .actor = &N(bob_omb),    .home = { .index = BTL_POS_GROUND_C }, .priority = 9 },
    { .actor = &N(bob_omb),    .home = { .index = BTL_POS_GROUND_D }, .priority = 8 },
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_10) = {
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_11) = {
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_12) = {
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(bob_omb), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_13) = {
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_B }, .priority = 10 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_14) = {
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_15) = {
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_A }, .priority = 10 },
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_16) = {
    ACTOR_BY_IDX(N(koopa_troopa), BTL_POS_GROUND_A, 10),
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_B }, .priority = 9 },
    { .actor = &N(bob_omb),      .home = { .index = BTL_POS_GROUND_C }, .priority = 8 },
};

Vec3i N(vector3D_80218B90) = { 50, 0, -20, };

Vec3i N(vector3D_80218B9C) = { 80, 0, 0, };

Vec3i N(vector3D_80218BA8) = { 110, 0, 20, };

Formation N(Formation_17) = {
    ACTOR_BY_POS(N(bill_blaster), N(vector3D_80218B90), 10),
    ACTOR_BY_POS(N(bill_blaster), N(vector3D_80218B9C), 9),
    ACTOR_BY_POS(N(bill_blaster), N(vector3D_80218BA8), 9),
};

Formation N(Formation_18) = {
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_19) = {
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_1A) = {
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(bullet_bill), BTL_POS_GROUND_C, 8),
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
