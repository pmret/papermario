#include "arn_07.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/tubbas_heart.h"

void* func_800729B0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void* func_800726B0(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);

struct N(temp) {
    char unk_00[0xC];
    EffectInstanceDataThing* unk_0C;
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
} arn_07_struct; // size = 0x58

ApiStatus N(func_80240000_BECDF0)(ScriptInstance* script, s32 isInitialCall) {
    arn_07_struct* ptr = script->varTable[0];

    sfx_adjust_env_sound_pos(0xA2, 0, ptr->unk_00, ptr->unk_04, ptr->unk_08);
    return ((ptr->unk_44 < 2) == 0) * ApiStatus_DONE2;
}

ApiStatus N(func_8024004C_BECE3C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
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
        ptr->unk_50 = (struct N(temp)*)func_800729B0(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802401AC_BECF9C)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    arn_07_struct* ptr = script->varTable[0];

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
                ptr->unk_54 = func_800726B0(1, ptr->unk_18, ptr->unk_1C, ptr->unk_20, 1.0f, 0);
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

ApiStatus N(func_802405BC_BED3AC)(ScriptInstance* script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    arn_07_struct* ptr = script->varTable[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}

ApiStatus N(func_802405FC_BED3EC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        arn_07_struct* ptr = heap_malloc(sizeof(arn_07_struct));
        script->varTable[0] = ptr;
        ptr->unk_38 = get_variable(script, *args++);
        ptr->unk_18 = get_float_variable(script, *args++);
        ptr->unk_24 = get_float_variable(script, *args++);
        ptr->unk_20 = get_float_variable(script, *args++);
        ptr->unk_28 = get_float_variable(script, *args++);
        ptr->unk_54 = func_800726B0(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        *((s8*)ptr->unk_54->unk_0C + 0x34) = ptr->unk_38;
        ptr->unk_54->unk_0C->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 0x10E;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_80240708_BED4F8)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    arn_07_struct* ptr = script->varTable[0];

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

s32 N(itemList_80242040)[] = {
    ITEM_MYSTICAL_KEY,
    ITEM_NONE,
};

Script N(80242048) = SCRIPT({
    FadeOutMusic(0, 1000);
    SI_VAR(0) = 0;
    if (SI_VAR(0) == 0) {
        DisablePlayerInput(TRUE);
        UseSettingsFrom(0, 145, 65, 0);
        SetCamSpeed(0, 0.6005859375);
        SetPanTarget(0, 145, 30, 0);
        GetCamDistance(0, SI_VAR(1));
        SI_VAR(1) -= 100;
        SetCamDistance(0, SI_VAR(1));
        if (10000 != 10000) {
            GetCamPitch(0, SI_VAR(2), SI_VAR(3));
            SetCamPitch(0, SI_VAR(2), 10000);
        }
        PanToTarget(0, 0, 1);
        N(func_8024004C_BECE3C)(2, 50, 100, 31, -6, 145, 65, 0, 30, 0);
        spawn {
            N(func_802401AC_BECF9C)();
        }
        spawn {
            sleep 1;
            PlaySound(0x80000067);
            N(func_80240000_BECDF0)();
            StopSound(0x80000067);
            PlaySoundAt(0xB2, 0, 145, 65, 0);
        }
        spawn {
            sleep 12;
            SetPlayerAnimation(0x1002A);
        }
        spawn {
            sleep 50;
            sleep 115;
            PlaySoundAt(0x137, 0, 145, 65, 0);
        }
        N(func_802405BC_BED3AC)(1);
        spawn {
            sleep 80;
            SetPlayerAnimation(ANIM_10002);
        }
        SI_VAR(1) += 100;
        SetCamDistance(0, SI_VAR(1));
        SetPanTarget(0, 145, 0, 0);
        N(func_802405BC_BED3AC)(2);
        GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
        UseSettingsFrom(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        SetCamSpeed(0, 1.0);
        SetPanTarget(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    } else {
        N(func_802405FC_BED3EC)(2, 145, 30, 0, 0);
        spawn {
            N(func_80240708_BED4F8)();
        }
        sleep 1;
    }
    N(func_802405BC_BED3AC)(3);
    PlaySoundAtPlayer(312, 0);
    DisablePlayerInput(TRUE);
    STORY_PROGRESS = STORY_CH3_STAR_SPIRIT_RESCUED;
    GotoMapSpecial("kmr_23", 2, 14);
    sleep 100;
});

Script N(80242498) = SCRIPT({
    SI_VAR(0) = 1;
    if (SI_VAR(0) == 0) {
        DisablePlayerInput(TRUE);
        UseSettingsFrom(0, 145, 65, 0);
        SetCamSpeed(0, 0.6005859375);
        SetPanTarget(0, 145, 30, 0);
        GetCamDistance(0, SI_VAR(1));
        SI_VAR(1) -= 100;
        SetCamDistance(0, SI_VAR(1));
        if (10000 != 10000) {
            GetCamPitch(0, SI_VAR(2), SI_VAR(3));
            SetCamPitch(0, SI_VAR(2), 10000);
        }
        PanToTarget(0, 0, 1);
        N(func_8024004C_BECE3C)(2, 50, 100, 31, -6, 145, 65, 0, 30, 0);
        spawn {
            N(func_802401AC_BECF9C)();
        }
        spawn {
            sleep 1;
            PlaySound(0x80000067);
            N(func_80240000_BECDF0)();
            StopSound(0x80000067);
            PlaySoundAt(0xB2, 0, 145, 65, 0);
        }
        spawn {
            sleep 12;
            SetPlayerAnimation(0x1002A);
        }
        spawn {
            sleep 50;
            sleep 115;
            PlaySoundAt(0x137, 0, 145, 65, 0);
        }
        N(func_802405BC_BED3AC)(1);
        spawn {
            sleep 80;
            SetPlayerAnimation(ANIM_10002);
        }
        SI_VAR(1) += 100;
        SetCamDistance(0, SI_VAR(1));
        SetPanTarget(0, 145, 0, 0);
        N(func_802405BC_BED3AC)(2);
        GetPlayerPos(SI_VAR(2), SI_VAR(3), SI_VAR(4));
        UseSettingsFrom(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        SetCamSpeed(0, 1.0);
        SetPanTarget(0, SI_VAR(2), SI_VAR(3), SI_VAR(4));
        WaitForCam(0, 1.0);
        PanToTarget(0, 0, 0);
        DisablePlayerInput(FALSE);
    } else {
        N(func_802405FC_BED3EC)(2, 145, 30, 0, 0);
        spawn {
            N(func_80240708_BED4F8)();
        }
        sleep 1;
    }
    N(func_802405BC_BED3AC)(3);
    PlaySoundAtPlayer(312, 0);
    DisablePlayerInput(TRUE);
    STORY_PROGRESS = STORY_CH3_STAR_SPIRIT_RESCUED;
    GotoMapSpecial("kmr_23", 2, 14);
    sleep 100;
});

Script N(exitSingleDoor_802428D4) = SCRIPT({
    group 27;
    DisablePlayerInput(TRUE);
    SI_VAR(0) = 0;
    SI_VAR(1) = 10;
    SI_VAR(2) = 29;
    SI_VAR(3) = 1;
    spawn ExitSingleDoor;
    sleep 17;
    GotoMap("arn_08", 0);
    sleep 100;
});

Script N(exitWalk_80242978) = EXIT_WALK_SCRIPT(60,  1, "arn_03",  0);

Script N(exitWalk_802429D4) = EXIT_WALK_SCRIPT(60,  2, "mim_12",  1);

static const f64 rodata_alignment = 0.0;

Script N(80242A30) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetPlayerPos(-28, 0, -333);
    SetNpcPos(NPC_PARTNER, -28, 0, -333);
    SetCamSpeed(0, 90.0);
    SetCamType(0, 0, 0);
    SetCamPitch(0, 25.0, -4.0);
    SetCamDistance(0, 1100);
    SetCamPosA(0, 500, 0);
    SetCamPosB(0, 0, -500);
    SetCamPosC(0, 0, 0);
    SetPanTarget(0, 5, 0, -147);
    PanToTarget(0, 0, 1);
    RotateModel(29, 80, 0, -1, 0);
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    SetNpcJumpscale(NPC_TUBBAS_HEART, 2.5);
    NpcJump0(NPC_TUBBAS_HEART, 0, 20, -120, 8);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 0, 10, -60, 12);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 0, 0, 0, 12);
    sleep 1;
    SetNpcVar(0, 0, 0);
    spawn {
        loop {
            PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
            NpcJump0(NPC_TUBBAS_HEART, 0, 0, 0, 10);
            sleep 1;
            GetNpcVar(0, 0, SI_VAR(0));
            if (SI_VAR(0) == 1) {
                break loop;
            }
        }
        SetNpcVar(0, 0, 2);
    }
    spawn {
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, SI_VAR(0), 0, -1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(10, 450, 0);
    }
    NpcFaceNpc(NPC_TUBBAS_HEART, NPC_WORLD_TUBBA, 0);
    SpeakToPlayer(NPC_TUBBAS_HEART, NPC_ANIM(tubbas_heart, Palette_00, Anim_A), NPC_ANIM(tubbas_heart, Palette_00, Anim_1), 5, MESSAGE_ID(0x0E, 0x00C7));
    SetNpcVar(0, 0, 1);
    loop {
        GetNpcVar(0, 0, SI_VAR(0));
        if (SI_VAR(0) == 2) {
            break loop;
        }
        sleep 1;
    }
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 75, 0, 10, 12);
    sleep 1;
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 150, 0, 20, 12);
    sleep 1;
    spawn {
        sleep 4;
        SetCamSpeed(0, 90.0);
        SetCamPitch(0, 2.0, -9.0);
        SetCamDistance(0, 700);
        SetCamPosA(0, 500, 0);
        SetCamPosB(0, 0, -500);
        SetCamPosC(0, 0, 0);
        SetPanTarget(0, 65, 0, -137);
        PanToTarget(0, 0, 1);
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_22));
    }
    PlaySoundAtNpc(NPC_TUBBAS_HEART, 0x20C8, 0);
    NpcJump0(NPC_TUBBAS_HEART, 298, 56, 31, 18);
    SetNpcPos(NPC_TUBBAS_HEART, 0, -1000, 0);
    EnableNpcShadow(NPC_TUBBAS_HEART, FALSE);
    spawn {
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_23));
        sleep 20;
        SetNpcAnimation(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_6));
    }
    sleep 20;
    spawn {
        PlaySoundAtCollider(10, 449, 0);
        MakeLerp(0, 80, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, SI_VAR(0), 0, -1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
    }
    spawn {
        sleep 30;
        UseSettingsFrom(0, 236, 0, -46);
        SetCamSpeed(0, 4.0);
        SetCamPitch(0, 8.0, -9.0);
        SetCamDistance(0, 450);
        SetPanTarget(0, 250, 0, -46);
        PanToTarget(0, 0, 1);
    }
    ModifyColliderFlags(0, 10, 0x7FFFFE00);
    SetPlayerPos(0, 20, -195);
    SetNpcPos(NPC_PARTNER, 0, 20, -195);
    EnablePartnerAI();
    PlayerMoveTo(0, 0, 45);
    ModifyColliderFlags(1, 10, 0x7FFFFE00);
    spawn {
        MakeLerp(80, 0, 10, 0);
        loop {
            UpdateLerp();
            RotateModel(29, SI_VAR(0), 0, -1, 0);
            sleep 1;
            if (SI_VAR(1) == 0) {
                break loop;
            }
        }
        PlaySoundAtCollider(10, 450, 0);
    }
    PlayerMoveTo(200, 0, 35);
    sleep 5;
    SpeakToPlayer(NPC_WORLD_TUBBA, NPC_ANIM(world_tubba, Palette_00, Anim_10), NPC_ANIM(world_tubba, Palette_00, Anim_6), 0, MESSAGE_ID(0x0E, 0x00C8));
    SetNpcVar(1, 0, 1);
    sleep 30;
    DisablePlayerInput(FALSE);
});

// *INDENT-OFF*
Script N(802433C8) = {
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitWalk_80242978), TRIGGER_FLOOR_ABOVE, 5, 1, 0),
    SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitWalk_802429D4), TRIGGER_FLOOR_ABOVE, 1, 1, 0),
    SI_CMD(ScriptOpcode_IF_LT, SI_SAVE_VAR(0), -24),
        SI_CMD(ScriptOpcode_BIND_PADLOCK, N(802439B0), TRIGGER_WALL_PRESS_A, 16384, N(itemList_80242040), 0, 1),
    SI_CMD(ScriptOpcode_ELSE),
        SI_CMD(ScriptOpcode_BIND_TRIGGER, N(exitSingleDoor_802428D4), TRIGGER_WALL_PRESS_A, 10, 1, 0),
    SI_CMD(ScriptOpcode_END_IF),
    SI_CMD(ScriptOpcode_RETURN),
    SI_CMD(ScriptOpcode_END)
};
// *INDENT-ON*

Script N(enterWalk_8024346C) = SCRIPT({
    GetEntryID(SI_VAR(0));
    match SI_VAR(0) {
        == 0 {
            if (STORY_PROGRESS == STORY_CH3_HEART_ESCAPED_WINDY_MILL) {
                await N(80242A30);
                spawn N(802433C8);
            } else {
                SI_VAR(2) = 29;
                SI_VAR(3) = 1;
                await EnterSingleDoor;
                spawn N(802433C8);
            }
        }
        == 1 {
            SI_VAR(0) = N(802433C8);
            spawn EnterWalk;
            sleep 1;
        }
        == 2 {
            SI_VAR(0) = N(802433C8);
            spawn EnterWalk;
            sleep 1;
        }
        == 3 {
            spawn N(802433C8);
            sleep 1;
        }
    }
});

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_GUSTY_GULCH;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamLeadPlayer(0, 0);
    SetCamEnabled(0, 1);
    SI_SAVE_FLAG(1977) = 1;
    match STORY_PROGRESS {
        < STORY_CH3_TUBBA_CHASED_MARIO_IN_FOYER {
            MakeNpcs(0, N(npcGroupList_802478B8));
        }
        < STORY_CH3_BEGAN_PEACH_MISSION {
            MakeNpcs(0, N(npcGroupList_8024787C));
        }
        == STORY_CH3_BEGAN_PEACH_MISSION {
            MakeNpcs(0, N(npcGroupList_802478E8));
        }
        else {
            MakeNpcs(0, N(npcGroupList_802478B8));
        }
    }
    await N(makeEntities);
    if (STORY_PROGRESS == STORY_CH3_DEFEATED_TUBBA_BLUBBA) {
        spawn N(80242498);
    }
    spawn N(enterWalk_8024346C);
    GetEntryID(SI_VAR(0));
    if (SI_VAR(0) == 3) {
        sleep 65;
    }
    spawn N(80243790);
    spawn N(80241F10);
    UseDoorSounds(0);
    SetCamSpeed(0, 0.30078125);
});
