#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra3

extern ActorBlueprint N(swoopula);
extern ActorBlueprint N(duplighost);
extern ActorBlueprint N(red_magikoopa);
extern ActorBlueprint N(gray_magikoopa);
extern ActorBlueprint N(white_clubba);

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
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[0] }, .priority = 10 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[1] }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_02) = {
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 10 },
};

Formation N(Formation_03) = {
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_04) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_05) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(duplighost), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_06) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[2] }, .priority = 8 },
};

Formation N(Formation_07) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(swoopula), .home = { .vec = &N(pos_swoopula)[1] }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_08) = {
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 10 },
    { .actor = &N(red_magikoopa), .home = { .index = 2 }, .priority = 9 },
};

Formation N(Formation_09) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(red_magikoopa), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0A) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
};

Formation N(Formation_0B) = {
    { .actor = &N(duplighost), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(duplighost), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(gray_magikoopa), .home = { .index = 2 }, .priority = 8 },
    { .actor = &N(red_magikoopa), .home = { .index = 3 }, .priority = 7 },
};

Formation N(Formation_0C) = {
    { .actor = &N(white_clubba), .home = { .index = 0 }, .priority = 10 },
    { .actor = &N(white_clubba), .home = { .index = 1 }, .priority = 9 },
    { .actor = &N(duplighost), .home = { .index = 2 }, .priority = 8 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_01), &N(pra_01), "バサバサチュルルx２,バケバケ"),
    BATTLE(N(Formation_02), &N(pra_01), "バケバケ"),
    BATTLE(N(Formation_03), &N(pra_01), "バケバケx2"),
    BATTLE(N(Formation_04), &N(pra_01), "バケバケx3"),
    BATTLE(N(Formation_05), &N(pra_01), "バケバケx4"),
    BATTLE(N(Formation_06), &N(pra_01), "バケバケx２,バサバサチュルル"),
    BATTLE(N(Formation_07), &N(pra_01), "バケバケ,バサバサチュルル,バケバケ"),
    BATTLE(N(Formation_08), &N(pra_01), "バケバケ,レッドカメック"),
    BATTLE(N(Formation_09), &N(pra_01), "バケバケx２,レッドカメック"),
    BATTLE(N(Formation_0A), &N(pra_01), "バケバケ,ホワイトガボン,バケバケ"),
    BATTLE(N(Formation_0B), &N(pra_01), "バケバケx２,グレイカメック,レッドカメック"),
    BATTLE(N(Formation_0C), &N(pra_01), "ホワイトガボンx２,バケバケ"),
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
