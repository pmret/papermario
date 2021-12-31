#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2

extern ActorDesc N(blue_goomba);
extern ActorDesc N(red_goomba);
extern ActorDesc N(goomba_king);
extern ActorDesc N(red_goomba_2);
extern ActorDesc N(blue_goomba_2);
extern ActorDesc N(goomnut_tree);

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

Vec3i N(pos00) = { 14, 0, -10 };
Vec3i N(pos01) = { 54, 0,  32 };

Formation N(formation_00) = {
    { .actor = &N(blue_goomba), .pos = { .vec = &N(pos00) }, .priority = 10 },
    { .actor = &N(red_goomba),  .pos = { .vec = &N(pos01) }, .priority = 10 },
};

Vec3i N(pos02) = {  10, 0,  10 };
Vec3i N(pos03) = {  70, 0,  30 };
Vec3i N(pos04) = { 125, 0,  20 };
Vec3i N(pos05) = { -40, 0, -45 };

Formation N(formation_01) = {
    { .actor = &N(goomba_king),   .pos = { .vec = &N(pos02) }, .priority = 10 },
    { .actor = &N(red_goomba_2),  .pos = { .vec = &N(pos03) }, .priority = 10 },
    { .actor = &N(blue_goomba_2), .pos = { .vec = &N(pos04) }, .priority = 10 },
    { .actor = &N(goomnut_tree),  .pos = { .vec = &N(pos05) }, .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("クリレッド,クリブルー",           N(formation_00), &N(kmr_03)),
    BATTLE("クリキング,クリレッド,クリブルー", N(formation_01), &N(kmr_06)),
    {},
};

StageList N(stageTable) = {
    { "kmr_02", &N(kmr_02), },
    { "kmr_03", &N(kmr_03), },
    { "kmr_04", &N(kmr_04), },
    { "kmr_05", &N(kmr_05), },
    { "kmr_06", &N(kmr_06), },
    {},
};
