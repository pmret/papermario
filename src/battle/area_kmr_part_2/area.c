#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "message_ids.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2

extern ActorDesc D_8021998C_43B41C;
extern ActorDesc D_8021B79C_43D22C;
extern ActorDesc D_80220A10_4424A0;
extern ActorDesc D_8021EEDC_44096C;
extern ActorDesc D_8021D4DC_43EF6C;
extern ActorDesc D_80223450_444EE0;

// extern s32 D_80225860_4472F0[];
// extern s32 D_80225884_447314[];
// extern s32 D_8022589C_44732C[];
// extern s32 D_802258A4_447334[];
// extern s32 D_802258AC_44733C[];
// extern s32 D_802258B4_447344[];
// extern s32 D_802258BC_44734C[];

const s32 D_80225860_4472F0[] = {
    0x834E838A, 0x834C8393, 0x834F2C83, 0x4E838A83, 0x8C836283, 0x682C834E, 0x838A8375, 0x838B815B, 0x00000000
};

const s32 D_80225884_447314[] = {
    0x834E838A, 0x838C8362, 0x83682C83, 0x4E838A83, 0x75838B81, 0x5B000000
};

const s32 D_8022589C_44732C[] = {
    0x6B6D725F, 0x30360000
};

const s32 D_802258A4_447334[] = {
    0x6B6D725F, 0x30350000
};

const s32 D_802258AC_44733C[] = {
    0x6B6D725F, 0x30340000
};

const s32 D_802258B4_447344[] = {
    0x6B6D725F, 0x30330000
};

const s32 D_802258BC_44734C[] = {
    0x6B6D725F, 0x30320000
};

extern s32 D_80224B7C_44660C[];
extern s32 D_8022582C_4472BC[];
extern s32 D_80224730_4461C0[];
extern s32 D_80224FCC_446A5C[];
extern s32 D_802253D8_446E68[];

Vec3i D_80219750_43B1E0 = { 14, 0, -10 };

Vec3i D_8021975C_43B1EC = { 54, 0, 32 };

Formation D_80219768_43B1F8 = {
    { .actor = &D_8021998C_43B41C, .position = &D_80219750_43B1E0, .priority = 10 },
    { .actor = &D_8021B79C_43D22C, .position = &D_8021975C_43B1EC, .priority = 10 },
};

Vec3i D_802197A0_43B230 = { 10, 0, 10 };

Vec3i D_802197AC_43B23C = { 70, 0, 30 };

Vec3i D_802197B8_43B248 = { 125, 0, 20 };

Vec3i D_802197C4_43B254 = { -40, 0, -45 };

Formation D_802197D0_43B260 = {
    { .actor = &D_80220A10_4424A0, .position = &D_802197A0_43B230, .priority = 10 },
    { .actor = &D_8021EEDC_44096C, .position = &D_802197AC_43B23C, .priority = 10 },
    { .actor = &D_8021D4DC_43EF6C, .position = &D_802197B8_43B248, .priority = 10 },
    { .actor = &D_80223450_444EE0, .position = &D_802197C4_43B254, .priority = 10 },
};

s32 D_80219840_43B2E0[] = {
    D_80225884_447314, 0x00000002, D_80219768_43B1F8, D_80224B7C_44660C, 0x00000000,
    D_80225860_4472F0, 0x00000004, D_802197D0_43B260, D_8022582C_4472BC, 0x00000000,
    0x00000000,        0x00000000, 0x00000000,        0x00000000,        0x00000000, 
};

s32 D_8021987C[] = {
    D_802258BC_44734C, D_80224730_4461C0,
    D_802258B4_447344, D_80224B7C_44660C,
    D_802258AC_44733C, D_80224FCC_446A5C,
    D_802258A4_447334, D_802253D8_446E68,
    D_8022589C_44732C, D_8022582C_4472BC,
    0x00000000, 0x00000000,
};
