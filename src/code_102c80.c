#include "common.h"

typedef struct substruct802E176C {
    /* 0x000 */ Vec3f unk_00;
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ s8 unk_10;
    /* 0x011 */ s8 unk_11;
    /* 0x014 */ Vec3f unk_14;
    /* 0x020 */ u16 unk_20;
    /* 0x022 */ s16 unk_22;
    /* 0x024 */ char unk_24[4];
    /* 0x028 */ struct struct802E176C* unk_28;
    /* 0x02C */ char unk_2C[12];
    /* 0x038 */ f32 unk_38;
} substruct802E176C;

typedef struct struct802E176C {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char unk_07[0x39];
    /* 0x40 */ substruct802E176C* unk_40;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f unk_54;
} struct802E176C;

void func_802E246C(struct802E176C* arg0, void* arg1, void* arg2);

void func_802E1400(struct802E176C* arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    substruct802E176C* temp = arg0->unk_40;

    if (arg0->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND) || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            func_8010FD68(arg0);
            temp->unk_22 = 8;
        }
    }
}

void func_802E1460(struct802E176C* arg0) {
    substruct802E176C* temp = arg0->unk_40;
    u16 var = temp->unk_22--;

    if (var) {
        arg0->unk_48.y -= D_802EB000;
        return;
    }
    func_80110678(arg0);
    func_8010FD68(arg0);
    temp->unk_22 = 8;
}

void func_802E14D8(struct802E176C* arg0) {
    substruct802E176C* temp = arg0->unk_40;
    u16 var = temp->unk_22--;

    if (var) {
        arg0->unk_48.y += D_802EB008;
        return;
    }
    func_8010FD68(arg0);
    temp->unk_22 = 8;
}

INCLUDE_ASM(s32, "code_102c80", func_802E153C);

void func_802E1614(struct802E176C* arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (arg0->unk_06 & 1) {
        if ((playerStatus->actionState == ActionState_GROUND_POUND) || (playerStatus->actionState == ActionState_ULTRA_POUND)) {
            func_8010FD68(arg0);
        }
    }
}

void func_802E1660(struct802E176C* arg0) {
    substruct802E176C* temp = arg0->unk_40;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s8* temp2 = D_8010EBB0;

    func_802E153C(arg0);

    if(arg0->unk_06 & 0x40) {
        if(playerStatus->actionState == ActionState_HAMMER) {
            if(gPlayerData.hammerLevel < 0) {
                return;
            }
            goto label;
        }
    }

    if(playerStatus->actionState == ActionState_SPIN_JUMP) {
        return;
    }

    if(temp2[3] == 4) {
        if(temp2[0] != 0) {
            return;
        }
    }

    if(!(arg0->unk_06 & 1)) {
        if(!(arg0->unk_06 & 0x80)) {
            return;
        }
    }

label:
    func_8010FD68(arg0);

    if(temp->unk_28 == NULL) {
        return;
    }

    func_8010FD68(temp->unk_28);
}

void func_802E1740(struct802E176C* arg0) {
    if (!(arg0->unk_06 & 1)) {
        func_8010FD68(arg0);
    }
}

void func_802E176C(struct802E176C* arg0) {
    substruct802E176C* temp = arg0->unk_40;

    temp->unk_00.x = 1.0f;
    temp->unk_00.y = 0.1f;
    temp->unk_00.z = -0.1f;
    temp->unk_10 = 0;
    temp->unk_11 = 0;
}

INCLUDE_ASM(s32, "code_102c80", func_802E17A8);

void func_802E1EA8(struct802E176C* arg0) {
    set_area_flag(arg0->unk_40->unk_20);
    func_80110678(arg0);
}

INCLUDE_ASM(s32, "code_102c80", func_802E1EDC);

void func_802E234C(struct802E176C* arg0) {
    PlayerStatus* playerStatus = &gPlayerStatus; 
    substruct802E176C* temp = arg0->unk_40;

    playerStatus->animFlags |= 0x1000000;
    temp->unk_14.x = 1.0f;
    temp->unk_14.y = 1.0f;
    temp->unk_14.z = 1.0f;
}

extern struct802E176C* D_802EB3A0;
extern s32 D_8015C7D0;

void entity_init_BlueSwitch(struct802E176C* arg0) {
    struct802E176C* temp_v0_2;
    substruct802E176C* temp = arg0->unk_40;

    func_802E234C(arg0);
    if (D_8015C7D0 == 2) {
        D_802EB3A0 = arg0;
        return;
    }
    if (D_8015C7D0 == 1) {
        temp_v0_2 = D_802EB3A0;
        if (temp_v0_2 != NULL) {
            temp->unk_28 = temp_v0_2;
            arg0->flags |= 1;
            return;
        }
    } else {
        D_802EB3A0 = NULL;
    }
}

void entity_init_HugeBlueSwitch(struct802E176C* arg0) {
    substruct802E176C* temp_v0;

    func_802E234C(arg0);
    temp_v0 = arg0->unk_40;
    arg0->unk_54.x = 3.0f;
    arg0->unk_54.y = 3.0f;
    arg0->unk_54.z = 3.0f;
    temp_v0->unk_14.x = 3.0f;
    temp_v0->unk_14.y = 3.0f;
    temp_v0->unk_14.z = 3.0f;
}

void func_802E2450(void) {
    func_802E3650();
}


INCLUDE_ASM(void, "code_102c80", func_802E246C, struct802E176C* arg0, void* arg1, void* arg2);

INCLUDE_ASM(s32, "code_102c80", func_802E263C);

INCLUDE_ASM(s32, "code_102c80", func_802E2BA4);

#ifdef NON_MATCHING
// Needs rodata support
void func_802E2EB0(struct802E176C* arg0) {
    u32 type;
    void* a2 = NULL;
    void* a1 = NULL;

    arg0->unk_40->unk_38 = arg0->unk_48.y;
    type = get_entity_type(arg0->unk_04);

    if((type - 24) < 3) {
        arg0->unk_54.x = 0.5f;
        arg0->unk_54.y = 0.5f;
        arg0->unk_54.z = 0.5f;
    }

    switch(type) {
        case 21:
        case 24:
            a1 = &D_0A0031E0;
            a2 = &D_0A001508;
            break;
        case 22:
        case 25:
            a1 = &D_0A0031B0;
            a2 = &D_0A0014D8;
            break;
        case 23:
        case 26:
            a1 = &D_0A002F78;
            a2 = &D_0A001218;
            break;
        case 13:
            play_sound_at_position(0x158, 0, arg0->unk_48.x, arg0->unk_48.y, arg0->unk_48.z);
            a1 = &D_0A003F70;
            a2 = &D_0A002318;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }

    if(a2 == NULL) {
        return;
    }

    func_802E246C(arg0, a1, a2);
}
#else
INCLUDE_ASM(void, "code_102c80", func_802E2EB0, struct802E176C* arg0);
#endif

s32 D_802E9C8C = 0 ; // TODO: correct data here.
s32 D_802E9CF8 = 0 ; // TODO: correct data here.
s32 D_802E9CB0 = 0 ; // TODO: correct data here.
s32 D_802E9D1C = 0 ; // TODO: correct data here.
s32 D_802E9CD4 = 0 ; // TODO: correct data here.
s32 D_802E9D40 = 0 ; // TODO: correct data here.
s32 D_802E9D64 = 0 ; // TODO: correct data here.

#ifdef NON_MATCHING
//Needs rodata support
void func_802E2FD0(struct802E176C* arg0) {
    u32 type;
    void *addr = NULL;

    type = get_entity_type(arg0->unk_04);

    switch(type) {
        case 21:
            addr = D_802E9C8C;
            break;
        case 24:
            addr = D_802E9CF8;
            break;
        case 22:
            addr = D_802E9CB0;
            break;
        case 25:
            addr = D_802E9D1C;
            break;
        case 23:
            addr = D_802E9CD4;
            break;
        case 26:
            addr = D_802E9D40;
            break;
        case 13:
            addr = D_802E9D64;
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }

    if(addr == NULL) {
        return;
    }

    create_entity(addr, arg0->unk_48.x, arg0->unk_48.y, arg0->unk_48.z, 0, 0x80000000);
}
#else
INCLUDE_ASM(s32, "code_102c80", func_802E2FD0);
#endif