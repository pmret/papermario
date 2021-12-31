#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2

extern ActorDesc N(blue_goomba);
extern ActorDesc N(red_goomba);
extern ActorDesc D_80220A10_4424A0;
extern ActorDesc N(red_goomba_2);
extern ActorDesc N(blue_goomba_2);
extern ActorDesc D_80223450_444EE0;

extern Stage N(kmr_02);
extern Stage N(kmr_03);
extern Stage N(kmr_04);
extern Stage N(kmr_05);
extern Stage N(kmr_06);

extern s32 D_80224B7C_44660C[];
extern s32 D_8022582C_4472BC[];
extern s32 D_80224730_4461C0[];
extern s32 D_80224FCC_446A5C[];
extern s32 D_802253D8_446E68[];

Vec3i N(pos00) = { 14, 0, -10 };
Vec3i N(pos01) = { 54, 0,  32 };

Formation N(formation_00) = {
    { .actor = &N(blue_goomba), .position = &N(pos00), .priority = 10 },
    { .actor = &N(red_goomba),  .position = &N(pos01), .priority = 10 },
};

Vec3i N(pos02) = {  10, 0,  10 };
Vec3i N(pos03) = {  70, 0,  30 };
Vec3i N(pos04) = { 125, 0,  20 };
Vec3i N(pos05) = { -40, 0, -45 };

Formation N(formation_01) = {
    { .actor = &D_80220A10_4424A0, .position = &N(pos02), .priority = 10 },
    { .actor = &N(red_goomba_2), .position = &N(pos03), .priority = 10 },
    { .actor = &N(blue_goomba_2), .position = &N(pos04), .priority = 10 },
    { .actor = &D_80223450_444EE0, .position = &N(pos05), .priority = 10 },
};

BattleList N(formationTable) = {
    BATTLE("クリレッド,クリブルー",           N(formation_00), D_80224B7C_44660C),
    BATTLE("クリキング,クリレッド,クリブルー", N(formation_01), D_8022582C_4472BC),
    {},
};

StageList N(stageTable) = {
    { "kmr_02", D_80224730_4461C0, },
    { "kmr_03", D_80224B7C_44660C, },
    { "kmr_04", D_80224FCC_446A5C, },
    { "kmr_05", D_802253D8_446E68, },
    { "kmr_06", D_8022582C_4472BC, },
    {},
};
