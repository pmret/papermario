#include "flo_21.h"
#include "effects.h"
#include "message_ids.h"
#include "sprite/npc/huff_n_puff.h"
#include "sprite/npc/tuff_puff.h"

typedef struct {
    char unk_00[0x4];
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    char unk_14[0x4];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    X32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 unk_34;
    s32 unk_38;
    char unk_3C[0xC];
    EffectUnkStruct1* unk_48;
    char unk_4C[0x24];
    s32 unk_70;
    s32 unk_74;
} N(EffectStruct);

typedef struct N(temp) {
    char unk_00[0xC];
    N(EffectStruct)* unk_0C;
} N(temp);

typedef struct {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ Shadow* unk_40;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ struct N(temp)* unk_50;
    /* 0x54 */ struct N(temp)* unk_54;
} N(Unk_effect_struct); // size = 0x58

enum {
    NPC_HUFF_N_PUFF0,
    NPC_HUFF_N_PUFF1,
    NPC_HUFF_N_PUFF2,
    NPC_TUFF_PUFF0,
    NPC_TUFF_PUFF1,
    NPC_TUFF_PUFF2,
    NPC_TUFF_PUFF3,
    NPC_TUFF_PUFF4,
    NPC_TUFF_PUFF5,
    NPC_TUFF_PUFF6,
    NPC_TUFF_PUFF7,
    NPC_TUFF_PUFF8,
    NPC_TUFF_PUFF9,
    NPC_TUFF_PUFF10,
    NPC_TUFF_PUFF11,
    NPC_TUFF_PUFF12,
    NPC_TUFF_PUFF13,
    NPC_TUFF_PUFF14,
};

EntryList N(entryList) = {
    { -800.0f, -46.0f, 0.0f, 90.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_21_tattle },
};

EvtSource N(80240D40) = SCRIPT({
    if (SI_STORY_PROGRESS == STORY_CH6_DEFEATED_HUFF_N_PUFF) {
        FadeOutMusic(0, 500);
    } else {
        SetMusicTrack(0, SONG_CLOUDY_CLIMB, 0, 8);
    }
});

ApiStatus N(func_80240000_CE6700)(Evt* script, s32 isInitialCall) {
    N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)script->varTable[0];

    sfx_adjust_env_sound_pos(0xA2, 0, ptr->unk_00, ptr->unk_04, ptr->unk_08);
    return ((ptr->unk_44 < 2) == 0) * ApiStatus_DONE2;
}

ApiStatus N(func_8024004C_CE674C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)heap_malloc(sizeof(N(Unk_effect_struct)));
        script->varTable[0] = ptr;
        set_variable(NULL, SI_MAP_VAR(1), ptr);
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_3C = get_variable(script, *args++);
        ptr->unk_0C = get_float_variable(script, *args++);
        ptr->unk_10 = get_float_variable(script, *args++);
        ptr->unk_14 = get_float_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_1C = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_50 = (struct N(temp)*)playFX_83(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802401AC_CE68AC)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)script->varTable[0];

    switch (ptr->unk_44) {
        case 0:
            ptr->unk_04 = update_lerp(5, ptr->unk_10, ptr->unk_1C, ptr->unk_46, ptr->unk_3C);
            ptr->unk_00 = update_lerp(0, ptr->unk_0C, ptr->unk_18, ptr->unk_46, ptr->unk_3C);
            ptr->unk_08 = update_lerp(0, ptr->unk_14, ptr->unk_20, ptr->unk_46, ptr->unk_3C);
            ptr->unk_50->unk_0C->unk_08 = ptr->unk_00;
            ptr->unk_50->unk_0C->unk_0C = ptr->unk_04;
            ptr->unk_50->unk_0C->unk_10 = ptr->unk_08;
            ptr->unk_46++;
            if (ptr->unk_46 >= ptr->unk_3C) {
                ptr->unk_44 = 1;
                ptr->unk_46 = 0;
            }
            break;

        case 1:
            ptr->unk_46++;
            if (ptr->unk_46 >= 60) {
                ptr->unk_44 = 2;
                ptr->unk_46 = 0;
                ptr->unk_50->unk_0C->unk_70 = 1;
                ptr->unk_50->unk_0C->unk_74 = 0;
            }
            break;

        case 2:
            ptr->unk_46++;
            if (ptr->unk_46 >= 60) {
                ptr->unk_54 = playFX_7B(1, ptr->unk_18, ptr->unk_1C, ptr->unk_20, 1.0f, 0);
                *((s8*)ptr->unk_54->unk_0C + 0x34) = ptr->unk_38;
                ptr->unk_54->unk_0C->unk_20 = 0;
                ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
                ptr->unk_44 = 3;
                ptr->unk_46 = 0;
                ptr->unk_2C = 0.0f;
                ptr->unk_48 = 1;
                ptr->unk_30 = 36.0f;
            }
            break;

        case 3:
            ptr->unk_30 = update_lerp(0, 36.0f, 19.0f, ptr->unk_46, 120);
            ptr->unk_46++;
            if (ptr->unk_46 >= 120) {
                ptr->unk_4C = 0;
                ptr->unk_4A = 1;
                ptr->unk_48 = 2;
                ptr->unk_4E = 1;
                ptr->unk_44 = 4;
                ptr->unk_46 = 0;
                ptr->unk_34 = ptr->unk_2C;
            }
            break;

        case 4:
            break;
    }

    switch (ptr->unk_4A) {
        case 1:
            ptr->unk_2C = update_lerp(4, ptr->unk_34, 1440.0f, ptr->unk_4C, 120);
            ptr->unk_04 = update_lerp(0xA, ptr->unk_1C, ptr->unk_24, ptr->unk_4C, 120);
            ptr->unk_4C++;
            if (ptr->unk_4C >= 120) {
                ptr->unk_4C = 0x10E;
                ptr->unk_4A = 2;
                ptr->unk_4E = 2;
            }
            break;

        case 2:
            ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
            ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
            if (!(dist3D(playerStatus->position.x, playerStatus->position.y + 20.0f, playerStatus->position.z,
                         ptr->unk_00, ptr->unk_04, ptr->unk_08) > 30.0f)) {
                ptr->unk_4E = 3;
            }
            break;
    }

    switch (ptr->unk_48) {
        case 1:
            ptr->unk_2C = clamp_angle(ptr->unk_2C + ptr->unk_30);

        case 2:
            ptr->unk_54->unk_0C->unk_24.f = ptr->unk_2C;
            ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
            ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
            ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(func_802405BC_CE6CBC)(Evt* script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)script->varTable[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}

ApiStatus N(func_802405FC_CE6CFC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)heap_malloc(sizeof(N(Unk_effect_struct)));
        script->varTable[0] = ptr;
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_54 = playFX_7B(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        ptr->unk_54->unk_0C->unk_34 = ptr->unk_38;
        ptr->unk_54->unk_0C->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 0x10E;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240708_CE6E08)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    N(Unk_effect_struct)* ptr = (N(Unk_effect_struct)*)script->varTable[0];

    ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
    ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
    if (dist2D(playerStatus->position.x, playerStatus->position.z,
               ptr->unk_18, ptr->unk_20) <= 30.0f) {
        ptr->unk_4E = 3;
    }
    ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
    ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
    ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;

    return ApiStatus_BLOCK;
}

EvtSource N(80240DA0) = SCRIPT({
    group 0;
    if (SI_VAR(5) == 1) {
        if (SI_VAR(6) == 1) {
            if (SI_VAR(7) == 1) {
                if (SI_VAR(8) == 1) {
                    N(UnkTexturePanFunc)();
                    return;
                }
            }
        }
    }
    N(UnkTexturePanFunc2)();
});

EvtSource N(80240E3C) = SCRIPT({
    match SI_STORY_PROGRESS {
        == STORY_CH6_GREW_MAGIC_BEANSTALK {
            SI_VAR(0) = 0;
            if (SI_MAP_VAR(10) == 0) {
                return;
            }
            SI_STORY_PROGRESS = STORY_CH6_DEFEATED_HUFF_N_PUFF;
        }
        == STORY_CH6_DEFEATED_HUFF_N_PUFF {
            SI_VAR(0) = 1;
        } else {
            return;
        }
    }
    if (SI_VAR(0) == 0) {
        DisablePlayerInput(TRUE);
        UseSettingsFrom(0, 650, 205, 0);
        SetCamSpeed(0, 0.6005859375);
        SetPanTarget(0, 650, 150, 0);
        GetCamDistance(0, SI_VAR(1));
        SI_VAR(1) -= 100;
        SetCamDistance(0, SI_VAR(1));
        if (-5.5 != 10000) {
            GetCamPitch(0, SI_VAR(2), SI_VAR(3));
            SetCamPitch(0, SI_VAR(2), -5.5);
        }
        PanToTarget(0, 0, 1);
        N(func_8024004C_CE674C)(5, 180, 650, 170, 0, 650, 205, 0, 150, 120);
        spawn {
            N(func_802401AC_CE68AC)();
        }
        spawn {
            sleep 1;
            PlaySound(0x80000067);
            N(func_80240000_CE6700)();
            StopSound(0x80000067);
            PlaySoundAt(0xB2, 0, 650, 205, 0);
        }
        spawn {
            sleep 45;
            SetPlayerAnimation(0x1002A);
        }
        spawn {
            sleep 180;
            sleep 115;
            PlaySoundAt(0x137, 0, 650, 205, 0);
        }
        N(func_802405BC_CE6CBC)(1);
        spawn {
            sleep 80;
            SetPlayerAnimation(ANIM_10002);
        }
        SI_VAR(1) += 100;
        SetCamDistance(0, SI_VAR(1));
        SetPanTarget(0, 650, 120, 0);
        N(func_802405BC_CE6CBC)(2);
        GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
        UseSettingsFrom(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        SetCamSpeed(0, 1.0);
        SetPanTarget(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    } else {
        N(func_802405FC_CE6CFC)(5, 650, 150, 0, 120);
        spawn {
            N(func_80240708_CE6E08)();
        }
        sleep 1;
    }
    N(func_802405BC_CE6CBC)(3);
    PlaySoundAtPlayer(312, 0);
    DisablePlayerInput(TRUE);
    SI_STORY_PROGRESS = STORY_CH6_STAR_SPIRIT_RESCUED;
    GotoMapSpecial("kmr_23", 5, 14);
    sleep 100;
});

EvtSource N(exitWalk_802412F4) = EXIT_WALK_SCRIPT(60,  0, "flo_19",  1);

EvtSource N(80241350) = SCRIPT({
    bind N(exitWalk_802412F4) TRIGGER_FLOOR_ABOVE 0;
});

EvtSource N(main) = SCRIPT({
    SI_WORLD_LOCATION = LOCATION_CLOUDY_CLIMB;
    SetSpriteShading(-1);
    SetCamLeadPlayer(0, 0);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_80245AEC));
    spawn N(80241B98);
    HidePlayerShadow(TRUE);
    spawn N(80241600);
    ModifyColliderFlags(3, 5, 0x00000007);
    ModifyColliderFlags(3, 7, 0x00000007);
    GetEntryID(SI_VAR(0));
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    SI_VAR(0) = N(80241350);
    spawn EnterWalk;
    await N(80240D40);
    if (SI_STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240B00_CE7200)();
    }
    spawn N(80240E3C);
});

s32 N(D_802414FC_CE7BFC)[] = {
    0,
    SI_FIXED(1), SI_FIXED(1), SI_FIXED(1),
    SI_FIXED(1), SI_FIXED(1), SI_FIXED(1),
    SI_FIXED(1.1005859375), SI_FIXED(1.1005859375), SI_FIXED(1.1005859375),
    SI_FIXED(1.1005859375), SI_FIXED(1.1005859375), SI_FIXED(1.1005859375),
    SI_FIXED(1), SI_FIXED(1), SI_FIXED(1),
    SI_FIXED(1), SI_FIXED(1), SI_FIXED(1),
    SI_FIXED(0.900390625), SI_FIXED(0.900390625), SI_FIXED(0.900390625),
    SI_FIXED(0.900390625), SI_FIXED(0.900390625), SI_FIXED(0.900390625),
};

EvtSource N(80241560) = SCRIPT({
    SI_MAP_VAR(0) += -1.5;
});

EvtSource N(80241580) = SCRIPT({
    SI_MAP_VAR(1) += -1.5;
});

EvtSource N(802415A0) = SCRIPT({
    SI_MAP_VAR(2) += -1.5;
});

EvtSource N(802415C0) = SCRIPT({
    SI_MAP_VAR(3) += -1.5;
});

EvtSource N(802415E0) = SCRIPT({
    SI_MAP_VAR(4) += -1.5;
});

EvtSource N(80241600) = SCRIPT({
    spawn {
        SI_VAR(15) = 0;
0:
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(0), 0.96875, 1.03125, 15, 0, 0);
        N(UnkFloatFunc)(SI_VAR(15), SI_VAR(1), 1.03125, 0.96875, 15, 0, 0);
        ScaleModel(88, SI_VAR(1), SI_VAR(0), 1);
        ScaleModel(90, SI_VAR(1), SI_VAR(0), 1);
        ScaleModel(92, SI_VAR(0), SI_VAR(1), 1);
        ScaleModel(94, SI_VAR(0), SI_VAR(1), 1);
        ScaleModel(96, SI_VAR(0), SI_VAR(1), 1);
        ScaleModel(98, SI_VAR(1), SI_VAR(0), 1);
        ScaleModel(100, SI_VAR(0), SI_VAR(1), 1);
        ScaleModel(102, SI_VAR(0), SI_VAR(1), 1);
        SI_VAR(15) += 1;
        if (SI_VAR(15) >= 30) {
            SI_VAR(15) = 0;
        }
        sleep 1;
        goto 0;
    }
});

static s32 N(pad_17BC) = {
    0x00000000,
};

NpcSettings N(npcSettings_802417C0) = {
    .height = 24,
    .radius = 28,
    .onHit = EnemyNpcHit,
    .onDefeat = EnemyNpcDefeat,
    .level = 16,
};

NpcSettings N(npcSettings_802417EC) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80241818) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80241844) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80241870) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

Vec3f N(vectorList_8024189C)[] = {
    { 600.0, 104.0, 0.0 }, { 575.0, 204.0, 0.0 },
    { 550.0, 104.0, 0.0 },
};

EvtSource N(802418C0) = SCRIPT({
0:
    PlaySound(0x20B6);
    ShakeCam(0, 0, 15, 1.0);
    sleep 15;
    goto 0;
});

EvtSource N(80241920) = SCRIPT({
    PlaySoundAtNpc(NPC_HUFF_N_PUFF0, 0x3C0, 0);
    PlayEffect(0x25, 3, 650, 104, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 15;
    SetNpcJumpscale(NPC_HUFF_N_PUFF1, 0.0);
    NpcJump0(NPC_HUFF_N_PUFF1, 650, 50, 0, 5);
    SetNpcPos(NPC_HUFF_N_PUFF0, 650, 50, 5);
    SetNpcPos(NPC_HUFF_N_PUFF1, 650, 50, 0);
    SetNpcPos(NPC_HUFF_N_PUFF2, 650, 50, 0);
    SetNpcJumpscale(NPC_HUFF_N_PUFF0, 0.0);
    SetNpcJumpscale(NPC_HUFF_N_PUFF1, 0.0);
    SetNpcJumpscale(NPC_HUFF_N_PUFF2, 0.0);
    spawn {
        NpcJump0(NPC_HUFF_N_PUFF0, 650, 150, 5, 10);
    }
    spawn {
        NpcJump0(NPC_HUFF_N_PUFF1, 650, 150, 0, 10);
    }
    spawn {
        NpcJump0(NPC_HUFF_N_PUFF2, 650, 150, 0, 10);
    }
    spawn {
        SetPlayerAnimation(ANIM_80017);
        LoadPath(30, N(vectorList_8024189C), 3, 0);
0:
        GetNextPathPos();
        SetPlayerPos(SI_VAR(1), SI_VAR(2), SI_VAR(3));
        sleep 1;
        if (SI_VAR(0) == 1) {
            goto 0;
        }
    }
    SetPlayerAnimation(ANIM_1002B);
});

EvtSource N(80241B98) = SCRIPT({
    if (SI_STORY_PROGRESS >= STORY_CH6_DEFEATED_HUFF_N_PUFF) {
        return;
    }
    AwaitPlayerApproach(650, 0, 30);
    DisablePlayerInput(TRUE);
    SetMusicTrack(0, SONG_HUFF_N_PUFF_THEME, 0, 8);
    SI_VAR(9) = spawn N(802418C0);
    GetCurrentPartner(SI_VAR(0));
    if (SI_VAR(0) != 0) {
        func_802D2B6C();
        sleep 20;
    }
    DisablePlayerPhysics(TRUE);
    InterpPlayerYaw(90, 1);
    sleep 5;
    SetPlayerAnimation(ANIM_1002B);
    SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((NPC_FLAG_100)), TRUE);
    GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
    UseSettingsFrom(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
    SetPanTarget(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    MakeLerp(SI_VAR(2), 600, 20, 0);
    SI_VAR(2) = SI_VAR(3);
    SI_VAR(5) = SI_VAR(3);
    SI_VAR(5) += 15;
    loop {
        UpdateLerp();
        SI_VAR(3) += 3;
        SetPlayerPos(SI_VAR(0), SI_VAR(3), SI_VAR(4));
        if (SI_VAR(3) > SI_VAR(5)) {
            SI_VAR(3) = SI_VAR(2);
        }
        sleep 1;
        if (SI_VAR(1) == 0) {
            break loop;
        }
        SetPanTarget(0, SI_VAR(0), SI_VAR(2), SI_VAR(4));
    }
    func_802D2C14(1);
    SetPlayerPos(SI_VAR(0), SI_VAR(2), SI_VAR(4));
    SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((NPC_FLAG_100)), FALSE);
    DisablePlayerPhysics(FALSE);
    sleep 10;
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 25;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 300.0);
    SetCamPitch(0, 17.0, -9.0);
    SetCamSpeed(0, 4.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    sleep 10;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x00CA), 630, 120, 0);
    SetCamDistance(0, 600.0);
    SetCamPitch(0, 30.0, -9.0);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    sleep 10;
    ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x00CB), 630, 120, 0);
    SetCamDistance(0, 300.0);
    SetCamPitch(0, 17.0, -9.0);
    PanToTarget(0, 0, 1);
    func_802D2C14(0);
    sleep 10;
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != 8) {
        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x00CC), 630, 120, 0);
    } else {
        ShowMessageAtWorldPos(MESSAGE_ID(0x11, 0x00CD), 630, 120, 0);
    }
    parallel {
        sleep 15;
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 25;
        UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SetCamPitch(0, 17.0, -6.0);
        SI_VAR(3) = 40;
        loop 5 {
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 400.0);
            SetCamSpeed(0, SI_VAR(3));
            WaitForCam(0, 1.0);
            SI_VAR(3) -= 10;
            SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SetCamDistance(0, 600.0);
            SetCamSpeed(0, SI_VAR(3));
            WaitForCam(0, 1.0);
            SI_VAR(3) += 7;
        }
    }
    await N(80241920);
    kill SI_VAR(9);
    sleep 30;
    SetNpcVar(0, 0, 1);
    DisablePlayerInput(FALSE);
    sleep 15;
});

EvtSource N(80242290) = SCRIPT({
    SI_VAR(0) = 0.9501953125;
    SI_VAR(1) = 1.1005859375;
0:
    match SI_MAP_VAR(13) {
        == 0 {
            SI_VAR(3) = 10;
            SI_VAR(2) = 2;
        }
        == 1 {
            SI_VAR(3) = 5;
            SI_VAR(2) = 1;
        } else {
            return;
        }
    }
    SI_VAR(4) = SI_VAR(3);
    loop SI_VAR(4) {
        SetNpcScale(NPC_HUFF_N_PUFF0, SI_VAR(0), SI_VAR(1), 1);
        SetNpcScale(NPC_HUFF_N_PUFF1, SI_VAR(0), SI_VAR(1), 1);
        SetNpcScale(NPC_HUFF_N_PUFF2, SI_VAR(0), SI_VAR(1), 1);
        SI_VAR(0) += 0.015625;
        SI_VAR(1) -= 0.0107421875;
        sleep SI_VAR(2);
    }
    SI_VAR(4) = SI_VAR(3);
    loop SI_VAR(4) {
        SetNpcScale(NPC_HUFF_N_PUFF0, SI_VAR(0), SI_VAR(1), 1);
        SetNpcScale(NPC_HUFF_N_PUFF1, SI_VAR(0), SI_VAR(1), 1);
        SetNpcScale(NPC_HUFF_N_PUFF2, SI_VAR(0), SI_VAR(1), 1);
        SI_VAR(0) -= 0.015625;
        SI_VAR(1) += 0.0107421875;
        sleep SI_VAR(2);
    }
    goto 0;
});

s32 N(intTable_8024249C)[] = {
    0x0000027B, 0x000000A5, 0x000001C2, 0x00000078, 0x00000280, 0x000000AA, 0x00000208, 0x0000010E,
    0x0000028A, 0x000000AF, 0x0000028A, 0x00000113, 0x00000294, 0x000000AA, 0x000002DA, 0x00000113,
    0x00000299, 0x000000A5, 0x00000352, 0x00000078, 0x00000276, 0x00000096, 0x000001C2, 0x0000009B,
    0x0000027D, 0x00000096, 0x00000258, 0x00000113, 0x0000028A, 0x00000096, 0x00000352, 0x0000009B,
    0x00000297, 0x00000096, 0x000002EE, 0x0000010E, 0x0000029E, 0x00000096, 0x00000352, 0x000000C3,
    0x0000027B, 0x00000087, 0x000001C2, 0x000000C3, 0x00000280, 0x00000082, 0x000001C2, 0x000000EB,
    0x0000028A, 0x0000007D, 0x000001C2, 0x0000010E, 0x00000294, 0x00000082, 0x00000352, 0x0000010E,
    0x00000299, 0x00000087, 0x00000352, 0x000000EB,
};

s32 N(intTable_8024258C)[] = {
    0x0000000A, 0x0000000E, 0x00000007, 0x0000000E, 0x00000005, 0x00000006, 0x00000005, 0x0000000C,
    0x00000006, 0x0000000C, 0x00000005, 0x00000005, 0x00000005, 0x0000000A, 0x00000005, 0x0000000A,
    0x00000005, 0x00000004,
};

s32 N(intTable_802425D4)[] = {
    0x00000008, 0x0000000A, 0x0000000A, 0x00000008,
};

s32 N(intTable_802425E4)[] = {
    0x0000000A, 0x00000005, 0x00000007, 0x00000005, 0x0000000E, 0x00000006, 0x0000000E, 0x00000005,
    0x00000006, 0x00000005, 0x0000000C, 0x00000005, 0x0000000C, 0x00000005, 0x00000005, 0x00000005,
    0x0000000A, 0x00000004,
};

s32 N(intTable_8024262C)[] = {
    0x0000000A, 0x00000006, 0x00000006, 0x0000000A,
};

EvtSource N(8024263C) = SCRIPT({
    SI_VAR(0) = (float) 10;
    SI_VAR(1) = (float) 1;
    parallel {
        loop 8 {
            SetNpcFlagBits(NPC_HUFF_N_PUFF0, ((0x00000002)), FALSE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((0x00000002)), FALSE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF2, ((0x00000002)), FALSE);
            sleep SI_VAR(0);
            SetNpcFlagBits(NPC_HUFF_N_PUFF0, ((0x00000002)), TRUE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((0x00000002)), TRUE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF2, ((0x00000002)), TRUE);
            sleep SI_VAR(1);
            SI_VAR(0) -= (float) 0;
            SI_VAR(1) += (float) 0;
        }
        loop {
            SetNpcFlagBits(NPC_HUFF_N_PUFF0, ((0x00000002)), FALSE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((0x00000002)), FALSE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF2, ((0x00000002)), FALSE);
            sleep SI_VAR(0);
            SetNpcFlagBits(NPC_HUFF_N_PUFF0, ((0x00000002)), TRUE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF1, ((0x00000002)), TRUE);
            SetNpcFlagBits(NPC_HUFF_N_PUFF2, ((0x00000002)), TRUE);
            sleep SI_VAR(1);
        }
    }
    parallel {
        loop {
            MakeLerp(0, 255, 10, 4);
            loop {
                UpdateLerp();
                func_802CFD30(NPC_HUFF_N_PUFF0, 9, SI_VAR(0), SI_VAR(0), SI_VAR(0), 0);
                func_802CFD30(NPC_HUFF_N_PUFF1, 9, SI_VAR(0), SI_VAR(0), SI_VAR(0), 0);
                func_802CFD30(NPC_HUFF_N_PUFF2, 9, SI_VAR(0), SI_VAR(0), SI_VAR(0), 0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
        }
    }
    sleep 100;
});

EvtSource N(80242918) = SCRIPT({
    SI_MAP_VAR(11) = 1.0;
    SI_MAP_VAR(12) = 1.0;
    parallel {
        buf_use N(intTable_8024258C);
        loop 6 {
            PlaySoundAtNpc(NPC_HUFF_N_PUFF0, 0x20B6, 0);
            buf_read SI_VAR(6) SI_VAR(7) SI_VAR(8);
            MakeLerp(SI_VAR(6), SI_VAR(7), SI_VAR(8), 11);
            loop {
                UpdateLerp();
                SI_VAR(0) /= (float) 10;
                SI_MAP_VAR(11) = (float) SI_VAR(0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            sleep 1;
        }
        loop {
            buf_use N(intTable_802425D4);
            loop 2 {
                PlaySoundAtNpc(NPC_HUFF_N_PUFF0, 0x20B6, 0);
                buf_read SI_VAR(6) SI_VAR(7);
                MakeLerp(SI_VAR(6), SI_VAR(7), 4, 11);
                loop {
                    UpdateLerp();
                    SI_VAR(0) /= (float) 10;
                    SI_MAP_VAR(11) = (float) SI_VAR(0);
                    sleep 1;
                    if (SI_VAR(1) == 0) {
                        break loop;
                    }
                }
            }
        }
    }
    parallel {
        buf_use N(intTable_802425E4);
        loop 6 {
            buf_read SI_VAR(6) SI_VAR(7) SI_VAR(8);
            MakeLerp(SI_VAR(6), SI_VAR(7), SI_VAR(8), 11);
            loop {
                UpdateLerp();
                SI_VAR(0) /= (float) 10;
                SI_MAP_VAR(12) = (float) SI_VAR(0);
                sleep 1;
                if (SI_VAR(1) == 0) {
                    break loop;
                }
            }
            sleep 1;
        }
        loop {
            buf_use N(intTable_8024262C);
            loop 2 {
                buf_read SI_VAR(6) SI_VAR(7);
                MakeLerp(SI_VAR(6), SI_VAR(7), 4, 11);
                loop {
                    UpdateLerp();
                    SI_VAR(0) /= (float) 10;
                    SI_MAP_VAR(12) = (float) SI_VAR(0);
                    sleep 1;
                    if (SI_VAR(1) == 0) {
                        break loop;
                    }
                }
            }
        }
    }
    loop 100 {
        SetNpcScale(NPC_HUFF_N_PUFF0, SI_MAP_VAR(11), SI_MAP_VAR(12), 1);
        SetNpcScale(NPC_HUFF_N_PUFF1, SI_MAP_VAR(11), SI_MAP_VAR(12), 1);
        SetNpcScale(NPC_HUFF_N_PUFF2, SI_MAP_VAR(11), SI_MAP_VAR(12), 1);
        sleep 1;
    }
});

EvtSource N(80242D34) = SCRIPT({
    parallel {
        SI_VAR(1) = 0;
        loop {
            SI_VAR(0) = 3;
            loop 15 {
                SetNpcRotation(SI_VAR(0), 0, SI_VAR(1), 0);
                SI_VAR(0) += 1;
            }
            SI_VAR(1) += 60;
            if (SI_VAR(1) > 360) {
                SI_VAR(1) += -360;
            }
            sleep 1;
        }
    }
    buf_use N(intTable_8024249C);
    SI_VAR(8) = 3;
    loop 14 {
        buf_read SI_VAR(1) SI_VAR(2) SI_VAR(3) SI_VAR(4);
        spawn {
            RandInt(5, SI_VAR(5));
            sleep SI_VAR(5);
            SetNpcPos(SI_VAR(8), SI_VAR(1), SI_VAR(2), -30);
            RandInt(2, SI_VAR(5));
            SI_VAR(5) += 8;
            PlaySoundAtNpc(SI_VAR(8), 0x3D5, 0);
            NpcJump0(SI_VAR(8), SI_VAR(3), SI_VAR(4), -15, SI_VAR(5));
            SetNpcPos(SI_VAR(8), 0, -1000, 0);
        }
        SI_VAR(8) += 1;
    }
    SetNpcPos(NPC_HUFF_N_PUFF0, 0, -1000, 0);
    SetNpcPos(NPC_HUFF_N_PUFF1, 0, -1000, 0);
    SetNpcPos(NPC_HUFF_N_PUFF2, 0, -1000, 0);
    buf_read SI_VAR(1) SI_VAR(2) SI_VAR(3) SI_VAR(4);
    sleep 5;
    SetNpcPos(SI_VAR(8), SI_VAR(1), SI_VAR(2), -30);
    PlaySoundAtNpc(SI_VAR(8), 0x3D6, 0);
    NpcJump0(SI_VAR(8), SI_VAR(3), SI_VAR(4), -15, 10);
    SetNpcPos(SI_VAR(8), 0, -1000, 0);
});

EvtSource N(80243010) = SCRIPT({
    SetNpcAnimation(NPC_HUFF_N_PUFF1, NPC_ANIM(huff_n_puff, Palette_00, Anim_4));
    SetNpcAnimation(NPC_HUFF_N_PUFF0, NPC_ANIM(huff_n_puff, Palette_00, Anim_5));
    SetNpcAnimation(NPC_HUFF_N_PUFF2, NPC_ANIM(huff_n_puff, Palette_00, Anim_6));
    GetNpcPos(NPC_HUFF_N_PUFF0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    UseSettingsFrom(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += -15;
    SI_VAR(2) += 40;
    SetPanTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamDistance(0, 350.0);
    SetCamPitch(0, 17.0, -5.5);
    SetCamSpeed(0, 90.0);
    PanToTarget(0, 0, 1);
    WaitForCam(0, 1.0);
    SpeakToPlayer(NPC_HUFF_N_PUFF0, NPC_ANIM(huff_n_puff, Palette_00, Anim_30), NPC_ANIM(huff_n_puff, Palette_00, Anim_5), 256, -30, 30, MESSAGE_ID(0x11, 0x00CE));
    FadeOutMusic(0, 1500);
    SI_MAP_VAR(13) = 2;
    GetNpcPos(NPC_HUFF_N_PUFF0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        SI_VAR(3) = SI_VAR(0);
        SI_VAR(4) = SI_VAR(0);
        SI_VAR(3) += -35;
        SI_VAR(4) += 35;
        loop 3 {
            PlayEffect(0x19, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 12;
            PlayEffect(0x19, 0, SI_VAR(3), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            SI_VAR(3) += 7;
            sleep 8;
            PlayEffect(0x19, 0, SI_VAR(4), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
            SI_VAR(4) += -7;
            sleep 14;
        }
        PlayEffect(0x19, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        ShakeCam(0, 0, 30, 1.5);
    }
    spawn {
        sleep 30;
        loop 10 {
            PlayEffect(0x3A, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 40, 65, 12, 15, 0, 0, 0, 0, 0);
            sleep 7;
        }
    }
    spawn N(8024263C);
    await N(80242918);
    await N(80242D34);
    sleep 10;
});

EvtSource N(idle_80243428) = SCRIPT({
0:
    SetSelfVar(0, 0);
    loop {
        GetSelfVar(0, SI_VAR(0));
        if (SI_VAR(0) != 0) {
            break loop;
        }
        sleep 1;
    }
    SI_MAP_VAR(13) = 1;
    StartBossBattle(14);
    goto 0;
});

EvtSource N(defeat_802434D8) = SCRIPT({
    GetBattleOutcome(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            SetEncounterStatusFlags(1, 1);
            SetNpcYaw(NPC_PARTNER, 90);
            GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(3));
            GetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
            SI_VAR(3) += -20;
            SetNpcPos(NPC_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(3));
            await N(80243010);
            sleep 50;
            SI_MAP_VAR(10) = 1;
            spawn N(80240E3C);
        }
    }
});

EvtSource N(defeat_802435D4) = SCRIPT({

});

EvtSource N(init_802435E4) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH6_DEFEATED_HUFF_N_PUFF) {
        SetEnemyFlagBits(-1, 4194304, 1);
        BindNpcIdle(NPC_SELF, N(idle_80243428));
        BindNpcDefeat(NPC_SELF, N(defeat_802434D8));
        SetNpcAnimation(NPC_SELF, NPC_ANIM(huff_n_puff, Palette_00, Anim_2));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_80243684) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH6_DEFEATED_HUFF_N_PUFF) {
        SetEnemyFlagBits(-1, 4194304, 1);
        BindNpcDefeat(NPC_SELF, N(defeat_802435D4));
        SetNpcAnimation(NPC_SELF, NPC_ANIM(huff_n_puff, Palette_00, Anim_1));
        spawn N(80242290);
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_8024371C) = SCRIPT({
    if (SI_STORY_PROGRESS < STORY_CH6_DEFEATED_HUFF_N_PUFF) {
        SetEnemyFlagBits(-1, 4194304, 1);
        BindNpcDefeat(NPC_SELF, N(defeat_802435D4));
        SetNpcAnimation(NPC_SELF, NPC_ANIM(huff_n_puff, Palette_00, Anim_19));
    } else {
        SetNpcPos(NPC_SELF, 0, -1000, 0);
    }
});

EvtSource N(init_802437A8) = SCRIPT({
    SetNpcAnimation(NPC_SELF, NPC_ANIM(tuff_puff, Palette_00, Anim_B));
    SetNpcJumpscale(NPC_SELF, 0);
});

NpcAnimID N(extraAnimationList_802437E0)[] = {
    NPC_ANIM(huff_n_puff, Palette_00, Anim_0),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_2),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_4),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_5),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_31),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_19),
    NPC_ANIM(huff_n_puff, Palette_00, Anim_2D),
    ANIM_END,
};

StaticNpc N(npcGroup_80243804)[] = {
    {
        .id = NPC_HUFF_N_PUFF0,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_802435E4),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
    {
        .id = NPC_HUFF_N_PUFF1,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, 100.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_80243684),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
    {
        .id = NPC_HUFF_N_PUFF2,
        .settings = &N(npcSettings_802417EC),
        .pos = { 650.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000,
        .init = &N(init_8024371C),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
            NPC_ANIM(huff_n_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_802437E0),
    },
};

NpcAnimID N(extraAnimationList_80243DD4)[] = {
    NPC_ANIM(tuff_puff, Palette_00, Anim_B),
    ANIM_END,
};

StaticNpc N(npcGroup_80243DDC)[] = {
    {
        .id = NPC_TUFF_PUFF0,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF1,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF2,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF3,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF4,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF5,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF6,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF7,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF8,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF9,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF10,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF11,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF12,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF13,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
    {
        .id = NPC_TUFF_PUFF14,
        .settings = &N(npcSettings_802417C0),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
        .init = &N(init_802437A8),
        .yaw = 270,
        .dropFlags = 0x80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_0),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_6),
            NPC_ANIM(tuff_puff, Palette_00, Anim_5),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
            NPC_ANIM(tuff_puff, Palette_00, Anim_1),
        },
        .extraAnimations = N(extraAnimationList_80243DD4),
    },
};

NpcGroupList N(npcGroupList_80245AEC) = {
    NPC_GROUP(N(npcGroup_80243804), BATTLE_ID(25, 0, 0, 8)),
    NPC_GROUP(N(npcGroup_80243DDC), BATTLE_ID(24, 31, 0, 8)),
    {},
};

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

EffectInstance* playFX_82();

ApiStatus N(func_80240B00_CE7200)(Evt* script, s32 isInitialCall) {
    playFX_82(1, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
