#include "common.h"
#include "ld_addrs.h"
#include "actions.h"

void action_idle_update(void);
void func_802B6000_E24920(void);
void action_run_update(void);
void func_802B60B4_E240F4(void);
void func_802B6198_E241D8(void);
void func_802B6294_E242D4(void);
void func_802B6348_E24388(void);
void func_802B61C0_E24AE0(void);
void func_802B6638_E29068(void);
void func_802B6060_E27570(void);
void action_hammer_update(void);
void func_802B6350_E28D80(void);
void func_802B6508_E28F38(void);
void func_802B6230_E24800(void);
void func_802B6120_E2A7D0(void);
void func_802B63D4_E28E04(void);
void func_802B6478_E28EA8(void);
void func_802B60A4_E29514(void);
void func_802B609C_E28ACC(void);

s32 D_800F7B40 = 0;
s32 D_800F7B44 = 0;
f32 D_800F7B48 = 0.0f;
s32 D_800F7B4C = 0;

s32 GravityParamsStartJump[] = { 0x417C1B33, 0xC0EC5C14, 0x405C9AAA, 0xBF400000 };
f32 GravityParamsStartFall[] = { 0.154342994094f, -0.350080013275f, -0.182262003422f, 0.0115200001746f };
f32 DefaultMoveSpeeds[] = { 2.0f, 4.0f, 32.0f, -32.0f }; // walk, run, max jump, ???
s16 D_800F7B80 = 0;
s32 D_800F7B84[] = { 0, 0, 0};
f32 D_800F7B90 = 0.0;

s32 ClubbaDisguiseExtraAnims[] = { 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390008, 0x00390007, 0x00390013, 0x00390014, ANIM_END };

s32 HammerBroDisguiseExtraAnims[] = { 0x005A0000, 0x005A0002, 0x005A0003, 0x005A0004, 0x005A0006, 0x005A0007, 0x005A0009, 0x005A000A, 0x005A000B, 0x005A001A, ANIM_END };

s32 KoopatrolDisguiseExtraAnims[] = { 0x00580000, 0x00580001, 0x00580002, 0x00580004, 0x00580005, 0x00580006, 0x00580007, 0x00580008, 0x00580009, 0x00580012, 0x00580014, 0x0058001B, ANIM_END };

DisguiseAnims BasicPeachDisguiseAnims[] = {
    {0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B},
    {0x00580001, 0x00580004, 0x00580006, 0x00580008, 0x00580000, 0x0058001B},
    {0x005A0003, 0x005A0006, 0x005A0009, 0x005A000B, 0x005A0000, 0x005A001A},
    {0x00390002, 0x00390003, 0x00390004, 0x00390005, 0x00390000, 0x00390014},
};

s32* PeachDisguiseExtraAnims[] = { &KoopatrolDisguiseExtraAnims, &KoopatrolDisguiseExtraAnims, &HammerBroDisguiseExtraAnims, &ClubbaDisguiseExtraAnims };

Action PlayerActionsTable[] = {
    { action_idle_update, world_action_idle_ROM_START, world_action_idle_ROM_END, TRUE },
    { func_802B6000_E24920, world_action_walk_ROM_START, world_action_walk_ROM_END, TRUE },
    { action_run_update, world_action_walk_ROM_START, world_action_walk_ROM_END, TRUE },
    { func_802B60B4_E240F4, world_action_jump_ROM_START, world_action_jump_ROM_END, TRUE },
    { func_802B60B4_E240F4, world_action_jump_ROM_START, world_action_jump_ROM_END, TRUE },
    { func_802B60B4_E240F4, world_action_jump_ROM_START, world_action_jump_ROM_END, FALSE },
    { func_802B60B4_E240F4, world_action_jump_ROM_START, world_action_jump_ROM_END, FALSE },
    { func_802B6198_E241D8, world_action_jump_ROM_START, world_action_jump_ROM_END, FALSE },
    { func_802B6294_E242D4, world_action_jump_ROM_START, world_action_jump_ROM_END, TRUE },
    { func_802B6348_E24388, world_action_jump_ROM_START, world_action_jump_ROM_END, TRUE },
    { func_802B6000_E24920, world_action_land_ROM_START, world_action_land_ROM_END, TRUE },
    { func_802B61C0_E24AE0, world_action_land_ROM_START, world_action_land_ROM_END, TRUE },
    { func_802B6638_E29068, world_action_encounter_ROM_START, world_action_encounter_ROM_END, TRUE },
    { func_802B6000_E24920, world_action_super_boots_ROM_START, world_action_super_boots_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_super_boots_ROM_START, world_action_super_boots_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_ultra_boots_ROM_START, world_action_ultra_boots_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_ultra_boots_ROM_START, world_action_ultra_boots_ROM_END, FALSE },
    { func_802B6060_E27570, world_action_slide_ROM_START, world_action_slide_ROM_END, FALSE },
    { action_hammer_update, world_action_hammer_ROM_START, world_action_hammer_ROM_END, FALSE },
    { func_802B6350_E28D80, world_action_encounter_ROM_START, world_action_encounter_ROM_END, TRUE },
    { func_802B6508_E28F38, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_hit_fire_ROM_START, world_action_hit_fire_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_16_ROM_START, world_action_16_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_hit_lava_ROM_START, world_action_hit_lava_ROM_END, FALSE },
    { func_802B6230_E24800, world_action_18_ROM_START, world_action_18_ROM_END, TRUE },
    { func_802B6120_E2A7D0, world_action_sneaky_parasol_ROM_START, world_action_sneaky_parasol_ROM_END, TRUE },
    { func_802B6000_E24920, world_action_spin_ROM_START, world_action_spin_ROM_END, FALSE },
    { func_802B63D4_E28E04, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B6478_E28EA8, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B60A4_E29514, world_action_use_spinning_flower_ROM_START, world_action_use_spinning_flower_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_use_munchlesia_ROM_START, world_action_use_munchlesia_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_use_tweester_ROM_START, world_action_use_tweester_ROM_END, FALSE },
    { func_802B6350_E28D80, world_action_encounter_ROM_START, world_action_encounter_ROM_END, TRUE },
    { func_802B6000_E24920, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B6000_E24920, world_action_18_ROM_START, world_action_18_ROM_END, TRUE },
    { func_802B609C_E28ACC, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B6350_E28D80, world_action_encounter_ROM_START, world_action_encounter_ROM_END, FALSE },
    { func_802B6350_E28D80, world_action_walk_ROM_START, world_action_walk_ROM_END, FALSE },
    { func_802B6350_E28D80, world_action_encounter_ROM_START, world_action_encounter_ROM_END, TRUE },
};
