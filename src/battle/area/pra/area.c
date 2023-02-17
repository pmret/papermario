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
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[1] }, .priority = 10 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[2] }, .priority = 9 },
};

Formation N(Formation_02) = {
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[0] }, .priority = 10 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[1] }, .priority = 9 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[2] }, .priority = 8 },
};

Vec3i N(pos_swoopula_2)[] = {
    { 0, 133, -25 },
    { 40, 133, -25 },
    { 80, 133, -25 },
    { 120, 133, -25 },
};

Formation N(Formation_03) = {
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_2)[0] }, .priority = 10 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_2)[1] }, .priority = 9 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_2)[2] }, .priority = 8 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula_2)[3] }, .priority = 7 },
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
    { .actor = &N(yellow_magikoopa_flying), .home = { .vec = &N(pos_magikoopa) }, .priority = 7 },
};

Formation N(Formation_05) = {
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_06) = {
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_07) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[2] }, .priority = 8 },
};

Formation N(Formation_09) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(yellow_magikoopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0A) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_magikoopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0B) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_magikoopa), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(red_magikoopa), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0C) = {
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(gray_magikoopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_0D) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(white_clubba), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(green_magikoopa), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0E) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(green_magikoopa), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(white_magikoopa_flying), .home = { .index = 7 }, .priority = 7 },
};

Formation N(Formation_0F) = {
    { .actor = &N(albino_dino), .home = { .index = 1 }, .priority = 10, }
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
