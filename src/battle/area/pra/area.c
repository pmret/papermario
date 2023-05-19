#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra

extern ActorBlueprint N(swoopula);
extern ActorBlueprint N(red_magikoopa);
extern ActorBlueprint N(gray_magikoopa);
extern ActorBlueprint N(white_magikoopa);
extern ActorBlueprint N(white_magikoopa_flying);
extern ActorBlueprint N(green_magikoopa);
extern ActorBlueprint N(yellow_magikoopa);
extern ActorBlueprint N(yellow_magikoopa_flying);
extern ActorBlueprint N(white_clubba);
extern ActorBlueprint N(albino_dino);

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
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[1], 10),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[2], 9),
};

Formation N(Formation_02) = {
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[0], 10),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[1], 9),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[2], 8),
};

Vec3i N(pos_swoopula_2)[] = {
    { 0, 133, -25 },
    { 40, 133, -25 },
    { 80, 133, -25 },
    { 120, 133, -25 },
};

Formation N(Formation_03) = {
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula_2)[0], 10),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula_2)[1], 9),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula_2)[2], 8),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula_2)[3], 7),
};

Vec3i N(pos_swoopula_3)[] = {
    { 0, 133, -25 },
    { 40, 133, -25 },
    { 80, 133, -25 },
};

Vec3i N(pos_magikoopa) = { 120, 55, 25 };

Formation N(Formation_04) = {
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_3)[0] }, .priority = 10, .var0 = 0xFFFFFFFF },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_3)[1] }, .priority = 9, .var0 = 0xFFFFFFFF },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_3)[2] }, .priority = 8, .var0 = 0xFFFFFFFF },
    ACTOR_BY_POS(N(yellow_magikoopa_flying), N(pos_magikoopa), 7),
};

Formation N(Formation_05) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 10),
};

Formation N(Formation_06) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_07) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 8),
};

Formation N(Formation_08) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_POS(N(swoopula), N(pos_swoopula)[2], 8),
};

Formation N(Formation_09) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(yellow_magikoopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0A) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_magikoopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0B) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(red_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0C) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 10),
    ACTOR_BY_IDX(N(gray_magikoopa), BTL_POS_GROUND_C, 9),
};

Formation N(Formation_0D) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(green_magikoopa), BTL_POS_GROUND_D, 7),
};

Formation N(Formation_0E) = {
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_A, 10),
    ACTOR_BY_IDX(N(white_clubba), BTL_POS_GROUND_B, 9),
    ACTOR_BY_IDX(N(green_magikoopa), BTL_POS_GROUND_C, 8),
    ACTOR_BY_IDX(N(white_magikoopa_flying), BTL_POS_AIR_D, 7),
};

Formation N(Formation_0F) = {
    ACTOR_BY_IDX(N(albino_dino), BTL_POS_GROUND_B, 10)
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), &N(pra_01), "バサバサチュルルx2"),
    BATTLE(N(Formation_02), &N(pra_01), "バサバサチュルルx3"),
    BATTLE(N(Formation_03), &N(pra_01), "バサバサチュルルx4"),
    BATTLE(N(Formation_04), &N(pra_01), "バサバサチュルルx3,イエローカメック（そら）"),
    BATTLE(N(Formation_05), &N(pra_01), "ホワイトガボン"),
    BATTLE(N(Formation_06), &N(pra_01), "ホワイトガボンx２"),
    BATTLE(N(Formation_07), &N(pra_01), "ホワイトガボンx３"),
    BATTLE(N(Formation_08), &N(pra_01), "ホワイトガボンx２,バサバサチュルル"),
    BATTLE(N(Formation_09), &N(pra_01), "ホワイトガボンx２,イエローカメック"),
    BATTLE(N(Formation_0A), &N(pra_01), "ホワイトガボンx２,ホワイトカメック"),
    BATTLE(N(Formation_0B), &N(pra_01), "ホワイトガボンx２,ホワイトカメック,レッドカメック"),
    BATTLE(N(Formation_0C), &N(pra_01), "ホワイトガボン,グレイカメック"),
    BATTLE(N(Formation_0D), &N(pra_01), "ホワイトガボンx３,グリーンカメック"),
    BATTLE(N(Formation_0E), &N(pra_01), "ホワイトガボンx２,グリーンカメック,ホワイトカメック（そら）"),
    BATTLE(N(Formation_0F), &N(pra_01), "セキゾー"),
    {},
};

StageList N(Stages) = {
    { "pra_01", &N(pra_01) },
    { "pra_02", &N(pra_02) },
    { "pra_03", &N(pra_03) },
    { "pra_03b", &N(pra_03b) },
    { "pra_03c", &N(pra_03c) },
    { "pra_04", &N(pra_04) },
    {},
};
