#include "flo_16.h"
#include "message_ids.h"

extern s32 D_800F7F00[];
extern s32 D_800F7F40[];
extern s32 D_8008EF20[11][4];

EntryList N(entryList) = {
    { -720.0f,   0.0f, 0.0f,  90.0f },
    {  710.0f, 100.0f, 0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { MSG_flo_16_tattle },
};

Script N(802429D0) = SCRIPT({
    match STORY_PROGRESS {
        < STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8);
        } else {
            SetMusicTrack(0, SONG_FLOWER_FIELDS_SUNNY, 0, 8);
        }
    }
});

Script N(exitWalk_80242A40) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  4);

Script N(exitWalk_80242A9C) = EXIT_WALK_SCRIPT(60,  1, "flo_17",  0);

Script N(80242AF8) = SCRIPT({
    bind N(exitWalk_80242A40) to TRIGGER_FLOOR_ABOVE 0;
    bind N(exitWalk_80242A9C) to TRIGGER_FLOOR_ABOVE 4;
});

s32 N(lavaResetList_80242B40)[] = {
    0x0000000A, 0xC39B0000, 0x00000000, 0x00000000, 0x0000000B, 0x43988000, 0x42C80000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

Script N(main) = SCRIPT({
    WORLD_LOCATION = LOCATION_FLOWER_FIELDS;
    SetSpriteShading(-1);
    SetCamPerspective(0, 3, 25, 16, 4096);
    SetCamBGColor(0, 0, 0, 0);
    SetCamEnabled(0, 1);
    MakeNpcs(0, N(npcGroupList_802444D4));
    await N(makeEntities);
    spawn N(8024346C);
    ModifyColliderFlags(3, 9, 0x00000002);
    spawn {
        ResetFromLava(N(lavaResetList_80242B40));
    }
    EnableTexPanning(16, 1);
    EnableTexPanning(17, 1);
    EnableTexPanning(18, 1);
    EnableTexPanning(20, 1);
    EnableTexPanning(22, 1);
    EnableTexPanning(24, 1);
    EnableTexPanning(19, 1);
    EnableTexPanning(21, 1);
    EnableTexPanning(23, 1);
    EnableTexPanning(25, 1);
    spawn {
        SI_VAR(0) = 0;
        SI_VAR(1) = 0;
0:
        SI_VAR(0) += 140;
        if (SI_VAR(0) > 65536) {
            SI_VAR(0) += -65536;
        }
        SetTexPanOffset(1, 0, SI_VAR(0), 0);
        SI_VAR(1) += -200;
        if (SI_VAR(1) < 0) {
            SI_VAR(1) += 65536;
        }
        SetTexPanOffset(2, 0, SI_VAR(1), 0);
        sleep 1;
        goto 0;
    }
    spawn N(802451C4);
    ModifyColliderFlags(0, 1, 0x7FFFFE00);
    ModifyColliderFlags(0, 5, 0x7FFFFE00);
    SI_VAR(0) = N(80242AF8);
    spawn EnterWalk;
    await N(802429D0);
    if (STORY_PROGRESS >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
        N(func_80240000_CD1E30)();
    }
});

Script N(80242EA0) = SCRIPT({
    group 11;
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    SI_VAR(12) = SI_VAR(2);
    SI_VAR(13) = SI_VAR(3);
    SI_VAR(14) = SI_VAR(4);
    SI_VAR(12) -= SI_VAR(0);
    SI_VAR(13) -= SI_VAR(1);
    SI_VAR(0) = (float) SI_VAR(12);
    SI_VAR(0) /= 100.0;
    SI_VAR(15) = 100.0;
    SI_VAR(15) /= (float) SI_VAR(0);
    SI_VAR(15) += 11;
    SI_VAR(5) = 200;
    SI_VAR(5) /= SI_VAR(15);
    SI_VAR(5) += 1;
    loop SI_VAR(5) {
        RandInt(SI_VAR(12), SI_VAR(0));
        RandInt(SI_VAR(13), SI_VAR(1));
        RandInt(199, SI_VAR(2));
        SI_VAR(3) = 210;
        SI_VAR(3) -= SI_VAR(2);
        SI_VAR(0) += SI_VAR(10);
        SI_VAR(1) += SI_VAR(11);
        SI_VAR(2) += SI_VAR(14);
        PlayEffect(0xD, SI_VAR(0), SI_VAR(2), SI_VAR(1), SI_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    sleep SI_VAR(15);
0:
    RandInt(SI_VAR(12), SI_VAR(0));
    RandInt(SI_VAR(13), SI_VAR(1));
    SI_VAR(0) += SI_VAR(10);
    SI_VAR(1) += SI_VAR(11);
    PlayEffect(0xD, SI_VAR(0), SI_VAR(14), SI_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep SI_VAR(15);
    goto 0;
});

Script N(8024314C) = SCRIPT({
    SI_VAR(9) = SI_VAR(6);
    SI_VAR(8) = SI_VAR(5);
    SI_VAR(7) = SI_VAR(4);
    SI_VAR(6) = SI_VAR(3);
    SI_VAR(5) = SI_VAR(2);
    SI_VAR(4) = SI_VAR(1);
    SI_VAR(3) = SI_VAR(0);
    EnableModel(SI_VAR(6), 0);
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(UnkFunc43)();
    if (SI_VAR(0) == 0) {
        sleep 1;
        goto 0;
    }
    spawn {
        sleep 5;
        EnableModel(SI_VAR(6), 1);
    }
    if (SI_VAR(10) != 0) {
        spawn {
            sleep 5;
            SI_VAR(0) = SI_VAR(3);
            SI_VAR(1) = SI_VAR(4);
            SI_VAR(2) = SI_VAR(5);
            SI_VAR(1) += 10;
            SI_VAR(2) += 8;
            PlayEffect(0x11, 4, SI_VAR(0), SI_VAR(1), SI_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 15;
            SI_VAR(1) -= 10;
            MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 14, 0);
        }
    }
    spawn {
        sleep 10;
        PlaySoundAt(0xF8, 0, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    }
    MakeLerp(0, 180, 20, 2);
1:
    UpdateLerp();
    RotateModel(SI_VAR(8), SI_VAR(0), 1, 0, 0);
    RotateModel(SI_VAR(9), SI_VAR(0), 1, 0, 0);
    if (SI_VAR(1) == 1) {
        sleep 1;
        goto 1;
    }
    EnableModel(SI_VAR(7), 0);
});

Script N(8024346C) = SCRIPT({
    ModifyColliderFlags(3, 20, 0x00000006);
    SI_VAR(0) = -740;
    SI_VAR(1) = -140;
    SI_VAR(2) = -260;
    SI_VAR(3) = -55;
    SI_VAR(4) = 100;
    spawn N(80242EA0);
    SI_VAR(0) = 250;
    SI_VAR(1) = -140;
    SI_VAR(2) = 725;
    SI_VAR(3) = -55;
    SI_VAR(4) = 180;
    spawn N(80242EA0);
    GetModelCenter(65);
    SI_VAR(3) = 65;
    SI_VAR(4) = 66;
    SI_VAR(5) = 67;
    SI_VAR(6) = 68;
    SI_VAR(10) = 0;
    spawn N(8024314C);
    GetModelCenter(71);
    SI_VAR(3) = 71;
    SI_VAR(4) = 72;
    SI_VAR(5) = 73;
    SI_VAR(6) = 74;
    SI_VAR(10) = 174;
    spawn N(8024314C);
    GetModelCenter(79);
    SI_VAR(3) = 79;
    SI_VAR(4) = 80;
    SI_VAR(5) = 81;
    SI_VAR(6) = 82;
    SI_VAR(10) = 0;
    spawn N(8024314C);
    GetModelCenter(85);
    SI_VAR(3) = 85;
    SI_VAR(4) = 86;
    SI_VAR(5) = 87;
    SI_VAR(6) = 88;
    SI_VAR(10) = 0;
    spawn N(8024314C);
});

static s32 N(pad_36FC) = {
    0x00000000,
};

s32 N(D_80243700_CD5530)[] = {
    0x001D00F0, 0x001D00F1,
};

s16 N(D_80243708_CD5538)[] = {
    0x0001, 0x0002, 0x0003, 0x0004,
    0x0009, 0x0006, 0x0007, 0x0008
};

s32 N(D_80243718_CD5548)[8][2] = {
    { 0x001D00E0, 0x001D00E1 }, { 0x001D00E2, 0x001D00E3 },
    { 0x001D00E4, 0x001D00E5 }, { 0x001D00E6, 0x001D00E7 },
    { 0x001D00E8, 0x001D00E9 }, { 0x001D00EA, 0x001D00EB },
    { 0x001D00EC, 0x001D00ED }, { 0x001D00EE, 0x001D00EF }
};

f32 N(D_80243758_CD5588)[] = {
    140.0f, 180.0f, 220.0f,
};

Script N(80243764) = SCRIPT({
    sleep 10;
    PlaySound(0x212D);
    N(UnkFunc21)(SI_MAP_VAR(0));
    sleep 85;
    spawn {
        PlaySound(0x212E);
        N(UnkFunc23)(70, 70);
        sleep 27;
        PlaySound(SOUND_UNKNOWN_208E);
        N(UnkFunc23)(50, 50);
    }
    spawn {
        sleep 3;
        N(func_8024011C_CD1F4C)(SI_MAP_VAR(0));
    }
    spawn {
        sleep 47;
        N(UnkFunc22)();
        N(UnkPartnerPosFunc)();
        sleep 5;
        N(UnkPartnerPosFunc2)();
        sleep 5;
        N(UnkPartnerPosFunc)();
    }
    sleep 3;
    N(func_802406E0_CD2510)(SI_MAP_VAR(0));
    sleep 30;
});

Script N(802438C8) = SCRIPT({
    if (SI_SAVE_FLAG(1403) == 1) {
        return;
    }
    IsStartingConversation(SI_VAR(0));
    if (SI_VAR(0) == 1) {
        return;
    }
    N(UnkFunc24)();
    if (SI_VAR(0) == 1) {
        return;
    }
    ModifyGlobalOverrideFlags(1, 2097152);
    N(SetOverrideFlags_40)();
    DisablePlayerInput(TRUE);
    DisablePartnerAI(0);
    SetNpcFlagBits(NPC_PARTNER, ((NPC_FLAG_100)), TRUE);
    N(UnkFunc20)(SI_MAP_VAR(0), SI_VAR(9));
    FindKeyItem(ITEM_ULTRA_STONE, SI_VAR(12));
    N(UnkFunc38)();
    if (SI_VAR(0) == -1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DC), 160, 40);
        sleep 10;
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        ModifyGlobalOverrideFlags(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    if (SI_SAVE_FLAG(438) == 0) {
        SI_SAVE_FLAG(438) = 1;
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DA), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DB), 160, 40);
    }
    N(func_802402AC_CD20DC)();
    if (SI_VAR(0) == -1) {
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        ModifyGlobalOverrideFlags(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    SI_VAR(10) = SI_VAR(0);
    SI_VAR(11) = SI_VAR(1);
    EnablePartnerAI();
    GetCurrentPartnerID(SI_VAR(0));
    if (SI_VAR(0) != SI_VAR(11)) {
        N(SwitchToPartner)(SI_VAR(11));
    } else {
        func_802CF56C(2);
    }
    sleep 10;
    ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DF), 160, 40);
    ShowChoice(MESSAGE_ID(0x1E, 0x000D));
    CloseMessage();
    if (SI_VAR(0) != 0) {
        N(UnkFunc39)(SI_VAR(9));
        DisablePlayerInput(FALSE);
        EnablePartnerAI();
        ModifyGlobalOverrideFlags(0, 2097152);
        N(UnkFunc17)();
        return;
    }
    await N(80243764);
    N(UnkFunc18)(SI_VAR(11), SI_VAR(13));
    SI_SAVE_FLAG(1403) = 1;
    N(UnkFunc39)(SI_VAR(9));
    N(UnkFunc19)();
    if (SI_VAR(13) == 1) {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DD), 160, 40);
    } else {
        ShowMessageAtScreenPos(MESSAGE_ID(0x1D, 0x00DE), 160, 40);
    }
    DisablePlayerInput(FALSE);
    EnablePartnerAI();
    ModifyGlobalOverrideFlags(0, 2097152);
    N(UnkFunc17)();
});

Script N(80243D48) = SCRIPT({
0:
    GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetCamTarget(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 1;
    goto 0;
});

Script N(80243DB0) = SCRIPT({
    DisablePlayerInput(TRUE);
    DisablePlayerPhysics(TRUE);
    SetPlayerActionState(6);
    sleep 2;
    GetPlayerPos(SI_VAR(7), SI_VAR(8), SI_VAR(9));
    SI_VAR(10) = spawn N(80243D48);
    SetPlayerJumpscale(0.7001953125);
    PlayerJump(450, 180, -120, 30);
    SetPlayerActionState(0);
    DisablePlayerPhysics(FALSE);
    DisablePlayerInput(FALSE);
});

Script N(80243E80) = SCRIPT({
    if (SI_AREA_FLAG(39) == 0) {
        N(UnkFunc44)();
        if (SI_VAR(0) == 0) {
            return;
        }
        GetPlayerPos(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        match SI_VAR(0) {
            620..660 {
                MakeItemEntity(ITEM_STAR_PIECE, 640, 145, -100, 13, SI_SAVE_FLAG(1388));
                SI_AREA_FLAG(39) = 1;
            }
        }
    }
});

Script N(makeEntities) = SCRIPT({
    SI_AREA_FLAG(39) = 0;
    bind N(80243E80) to TRIGGER_FLOOR_TOUCH 20;
    MakeEntity(0x802EA910, 350, 240, -100, 0, MAKE_ENTITY_END);
    SI_MAP_VAR(0) = SI_VAR(0);
    AssignBlockFlag(SI_SAVE_FLAG(1403));
    AssignScript(N(802438C8));
    MakeEntity(0x802EAA30, 472, 100, -100, 0, MAKE_ENTITY_END);
    AssignScript(N(80243DB0));
});

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus N(func_8024011C_CD1F4C)(ScriptInstance* script, s32 isInitialCall) {
    entity_upgrade_block_hide_content(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

#ifdef NON_MATCHING
typedef struct {
    s32 unk_00[8];
    char unk_20[0x64];
    s32 unk_84[8];
    char unk_A4[0x64];
    s32 unk_108[8];
    char unk_128[0x64];
    s32 unk_18C[8];
    char unk_1AC[0x64];
    s32 unk_210[8];
    char unk_230[0x64];
    s32 unk_294[8];
    char unk_2B4[0x64];
    s32 unk_318;
    char unk_31C[8];
    s32 unk_324;
    s32 unk_328;
    s16 unk_32C;
} N(UnkStruct);

ApiStatus N(func_802402AC_CD20DC)(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    N(UnkStruct)* ptr;
    s32 i;
    s32 partnerLevel;
    s32 var, partnerActiveCount;
    s32 idx;

    if (isInitialCall) {
        script->functionTemp[2].s = heap_malloc(0x330);
        ptr = script->functionTemp[2].s;

        partnerActiveCount = 0;
        var = script->varTable[12] >= 0;

        for (i = 0; i < 8; i++) {
            idx = N(D_80243708_CD5538)[i];

            if (playerData->partners[idx].enabled) {
                ptr->unk_108[i] = idx;
                ptr->unk_84[i] = *D_8008EF20[idx];
                partnerLevel = N(UnkFunc37)(idx, var);
                if (partnerLevel >= 0) {
                    ptr->unk_00[i] = D_800F7F00[idx];
                    ptr->unk_18C[i] = 1;
                    ptr->unk_294[i] = N(D_80243718_CD5548)[i][partnerLevel];
                } else {
                    ptr->unk_00[i] = D_800F7F40[idx];
                    ptr->unk_18C[i] = 0;
                    ptr->unk_294[i] = N(D_80243700_CD5530)[var];
                }
                ptr->unk_210[i] = playerData->partners[idx].level;
                partnerActiveCount++;
            }
        }

        ptr->unk_318 = 4;
        ptr->unk_324 = partnerActiveCount;
        ptr->unk_328 = 0;
        create_popup_menu(ptr);
        script->functionTemp[0].s = 0;
    }

    ptr = script->functionTemp[2].s;
    if (script->functionTemp[0].s == 0) {
        script->functionTemp[1].s = ptr->unk_32C;
        if (script->functionTemp[1].s != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0].s++;

    if (script->functionTemp[0].s < 15) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1].s != 0xFF) {
        script->varTable[0] = D_8008EF20[ptr->unk_108[script->functionTemp[1].s - 1]][0];
        script->varTable[1] = ptr->unk_108[script->functionTemp[1].s - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTemp[2].s);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_16/CD1F10", flo_16_func_802402AC_CD20DC, ScriptInstance* script,
            s32 isInitialCall);
#endif

#include "world/common/SwitchToPartner.inc.c"

#include "world/common/UnkFunc19.inc.c"

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    Effect* unk_08[3];
    f32 unk_14[3];
    f32 unk_20[3];
    f32 unk_2C[3];
    f32 unk_38[3];
    f32 unk_44[3];
    f32 unk_50[3];
    Entity* unk_5C;
    s32 unk_60;
    s32 unk_64;
} N(UserData);

ApiStatus N(func_802406E0_CD2510)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_safe(-4);
    f32 sinTheta, cosTheta;
    s32 i;
    f32 var;
    N(UserData)* userDataPtr;
    N(UserData)* scriptPtr;
    f32 save, save2;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (N(UserData)*)general_heap_malloc(0x68);
        scriptPtr = (N(UserData)*)script->userData;

        scriptPtr->unk_5C = get_entity_by_index(get_variable(script, *args));

        for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
            userDataPtr->unk_08[i] = playFX_51(0, scriptPtr->unk_5C->position.x, scriptPtr->unk_5C->position.y + 12.5f,
                                                   scriptPtr->unk_5C->position.z, 1.0f, -1);
            save = 0.0f;
            userDataPtr->unk_2C[i] = save;
            userDataPtr->unk_20[i] = save;
            userDataPtr->unk_14[i] = save;
            userDataPtr->unk_50[i] = save;
            userDataPtr->unk_44[i] = save;
            userDataPtr->unk_38[i] = save;
        }

        scriptPtr->unk_00 = 0;
        scriptPtr->unk_04 = 0;
        scriptPtr->unk_60 = 0;
        scriptPtr->unk_64 = 0;

        userDataPtr = scriptPtr;
        for (i = 0, save = 50.0f; i < 3; i++) {
            var = 0;
            add_vec2D_polar(&var, &scriptPtr->unk_44[i], save, N(D_80243758_CD5588)[i]);
            userDataPtr->unk_38[i] = cosTheta * var;
            userDataPtr->unk_50[i] = sinTheta * var;
            userDataPtr->unk_38[i] = npc->pos.x - (scriptPtr->unk_5C->position.x + userDataPtr->unk_38[i]);
            userDataPtr->unk_44[i] = npc->pos.y - (scriptPtr->unk_5C->position.y + userDataPtr->unk_44[i]);
            userDataPtr->unk_50[i] = npc->pos.z - (scriptPtr->unk_5C->position.z + userDataPtr->unk_50[i]);
        }
    }

    scriptPtr = (N(UserData)*)script->userData;
    switch (scriptPtr->unk_00) {
        case 0:
            save = update_lerp(5, 0.0f, 50.0f, scriptPtr->unk_60, 0x14);
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, N(D_80243758_CD5588)[i]);
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x15) {
                scriptPtr->unk_00 = 1;
                scriptPtr->unk_60 = 0;
            }
            break;

        case 1:
            save = 50.0f;
            save2 = 0.0f;
            for (i = 0; i < 3; i++) {
                scriptPtr->unk_20[i] = save2;
                var = save2;
                add_vec2D_polar(&var, &scriptPtr->unk_20[i], save, N(D_80243758_CD5588)[i]);
                scriptPtr->unk_14[i] = cosTheta * var;
                scriptPtr->unk_2C[i] = sinTheta * var;
            }

            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x10) {
                scriptPtr->unk_60 = 0xF;
                scriptPtr->unk_00 = 2;
            }
            break;

        case 2:
            scriptPtr->unk_60++;
            if (scriptPtr->unk_60 >= 0x1F) {
                for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                    userDataPtr->unk_08[i]->flags |= 0x10;
                }
                return ApiStatus_DONE2;
            }
    }

    switch (scriptPtr->unk_04) {
        case 0:
            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x10) {
                scriptPtr->unk_04 = 1;
                scriptPtr->unk_64 = 0;
            }
            break;

        case 1:
            for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
                userDataPtr->unk_14[i] = userDataPtr->unk_14[i] + update_lerp(1, 0.0f, userDataPtr->unk_38[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_20[i] = userDataPtr->unk_20[i] + update_lerp(1, 0.0f, userDataPtr->unk_44[i], scriptPtr->unk_64, 0x14);
                userDataPtr->unk_2C[i] = userDataPtr->unk_2C[i] + update_lerp(1, 0.0f, userDataPtr->unk_50[i], scriptPtr->unk_64, 0x14);
            }

            scriptPtr->unk_64++;
            if (scriptPtr->unk_64 >= 0x15) {
                scriptPtr->unk_04 = 2;
                scriptPtr->unk_64 = 0;
            }
            break;
    }

    for (i = 0, userDataPtr = scriptPtr; i < 3; i++) {
        ((EffectInstanceData*)userDataPtr->unk_08[i]->instanceData)->rotation.x = userDataPtr->unk_14[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->instanceData)->rotation.y = userDataPtr->unk_20[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->instanceData)->rotation.z = userDataPtr->unk_2C[i];
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc23.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc24.inc.c"

#include "world/common/UnkFunc44.inc.c"
