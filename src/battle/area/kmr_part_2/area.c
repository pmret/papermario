#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_kmr_part_2

extern ActorBlueprint N(blue_goomba);
extern ActorBlueprint N(red_goomba);
extern ActorBlueprint N(goomba_king);
extern ActorBlueprint N(red_goomba_2);
extern ActorBlueprint N(blue_goomba_2);
extern ActorBlueprint N(goomnut_tree);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

Vec3i N(pos00) = { 14, 0, -10 };
Vec3i N(pos01) = { 54, 0,  32 };

Formation N(Formation_00) = {
    { .actor = &N(blue_goomba), .home = { .vec = &N(pos00) }, .priority = 10 },
    { .actor = &N(red_goomba),  .home = { .vec = &N(pos01) }, .priority = 10 },
};

Vec3i N(pos02) = {  10, 0,  10 };
Vec3i N(pos03) = {  70, 0,  30 };
Vec3i N(pos04) = { 125, 0,  20 };
Vec3i N(pos05) = { -40, 0, -45 };

Formation N(Formation_01) = {
    { .actor = &N(goomba_king),   .home = { .vec = &N(pos02) }, .priority = 10 },
    { .actor = &N(red_goomba_2),  .home = { .vec = &N(pos03) }, .priority = 10 },
    { .actor = &N(blue_goomba_2), .home = { .vec = &N(pos04) }, .priority = 10 },
    { .actor = &N(goomnut_tree),  .home = { .vec = &N(pos05) }, .priority = 10 },
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), &N(kmr_03), "クリレッド,クリブルー"),
    BATTLE(N(Formation_01), &N(kmr_06), "クリキング,クリレッド,クリブルー"),
    {},
};

StageList N(Stages) = {
    { "kmr_02", &N(kmr_02), },
    { "kmr_03", &N(kmr_03), },
    { "kmr_04", &N(kmr_04), },
    { "kmr_05", &N(kmr_05), },
    { "kmr_06", &N(kmr_06), },
    {},
};
