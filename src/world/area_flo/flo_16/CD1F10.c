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

EvtSource N(802429D0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(53)
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(exitWalk_80242A40) = EXIT_WALK_SCRIPT(60,  0, "flo_00",  4);

EvtSource N(exitWalk_80242A9C) = EXIT_WALK_SCRIPT(60,  1, "flo_17",  0);

EvtSource N(80242AF8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242A40), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_80242A9C), TRIGGER_FLOOR_ABOVE, 4, 1, 0)
    EVT_RETURN
    EVT_END
};

s32 N(lavaResetList_80242B40)[] = {
    0x0000000A, 0xC39B0000, 0x00000000, 0x00000000, 0x0000000B, 0x43988000, 0x42C80000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802444D4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(8024346C))
    EVT_CALL(ModifyColliderFlags, 3, 9, 0x00000002)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(lavaResetList_80242B40)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, 16, 1)
    EVT_CALL(EnableTexPanning, 17, 1)
    EVT_CALL(EnableTexPanning, 18, 1)
    EVT_CALL(EnableTexPanning, 20, 1)
    EVT_CALL(EnableTexPanning, 22, 1)
    EVT_CALL(EnableTexPanning, 24, 1)
    EVT_CALL(EnableTexPanning, 19, 1)
    EVT_CALL(EnableTexPanning, 21, 1)
    EVT_CALL(EnableTexPanning, 23, 1)
    EVT_CALL(EnableTexPanning, 25, 1)
    EVT_THREAD
        EVT_SET(EVT_VAR(0), 0)
        EVT_SET(EVT_VAR(1), 0)
        EVT_LABEL(0)
        EVT_ADD(EVT_VAR(0), 140)
        EVT_IF_GT(EVT_VAR(0), 65536)
            EVT_ADD(EVT_VAR(0), -65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, EVT_VAR(0), 0)
        EVT_ADD(EVT_VAR(1), -200)
        EVT_IF_LT(EVT_VAR(1), 0)
            EVT_ADD(EVT_VAR(1), 65536)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, EVT_VAR(1), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(802451C4))
    EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
    EVT_CALL(ModifyColliderFlags, 0, 5, 0x7FFFFE00)
    EVT_SET(EVT_VAR(0), EVT_PTR(N(80242AF8)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(802429D0))
    EVT_IF_GE(EVT_SAVE_VAR(0), 53)
        EVT_CALL(N(func_80240000_CD1E30))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(80242EA0) = {
    EVT_SET_GROUP(11)
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_SET(EVT_VAR(12), EVT_VAR(2))
    EVT_SET(EVT_VAR(13), EVT_VAR(3))
    EVT_SET(EVT_VAR(14), EVT_VAR(4))
    EVT_SUB(EVT_VAR(12), EVT_VAR(0))
    EVT_SUB(EVT_VAR(13), EVT_VAR(1))
    EVT_SETF(EVT_VAR(0), EVT_VAR(12))
    EVT_DIVF(EVT_VAR(0), EVT_FIXED(100.0))
    EVT_SETF(EVT_VAR(15), EVT_FIXED(100.0))
    EVT_DIVF(EVT_VAR(15), EVT_VAR(0))
    EVT_ADD(EVT_VAR(15), 11)
    EVT_SET(EVT_VAR(5), 200)
    EVT_DIV(EVT_VAR(5), EVT_VAR(15))
    EVT_ADD(EVT_VAR(5), 1)
    EVT_LOOP(EVT_VAR(5))
        EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
        EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
        EVT_CALL(RandInt, 199, EVT_VAR(2))
        EVT_SET(EVT_VAR(3), 210)
        EVT_SUB(EVT_VAR(3), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), EVT_VAR(10))
        EVT_ADD(EVT_VAR(1), EVT_VAR(11))
        EVT_ADD(EVT_VAR(2), EVT_VAR(14))
        EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(2), EVT_VAR(1), EVT_VAR(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_LABEL(0)
    EVT_CALL(RandInt, EVT_VAR(12), EVT_VAR(0))
    EVT_CALL(RandInt, EVT_VAR(13), EVT_VAR(1))
    EVT_ADD(EVT_VAR(0), EVT_VAR(10))
    EVT_ADD(EVT_VAR(1), EVT_VAR(11))
    EVT_CALL(PlayEffect, 0xD, EVT_VAR(0), EVT_VAR(14), EVT_VAR(1), 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(EVT_VAR(15))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024314C) = {
    EVT_SET(EVT_VAR(9), EVT_VAR(6))
    EVT_SET(EVT_VAR(8), EVT_VAR(5))
    EVT_SET(EVT_VAR(7), EVT_VAR(4))
    EVT_SET(EVT_VAR(6), EVT_VAR(3))
    EVT_SET(EVT_VAR(5), EVT_VAR(2))
    EVT_SET(EVT_VAR(4), EVT_VAR(1))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_CALL(EnableModel, EVT_VAR(6), 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(N(UnkFunc43))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(EnableModel, EVT_VAR(6), 1)
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(10), 0)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_SET(EVT_VAR(0), EVT_VAR(3))
            EVT_SET(EVT_VAR(1), EVT_VAR(4))
            EVT_SET(EVT_VAR(2), EVT_VAR(5))
            EVT_ADD(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 8)
            EVT_CALL(PlayEffect, 0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 15, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(15)
            EVT_SUB(EVT_VAR(1), 10)
            EVT_CALL(MakeItemEntity, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 14, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAt, 0xF8, 0, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 180, 20, 2)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, EVT_VAR(8), EVT_VAR(0), 1, 0, 0)
    EVT_CALL(RotateModel, EVT_VAR(9), EVT_VAR(0), 1, 0, 0)
    EVT_IF_EQ(EVT_VAR(1), 1)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnableModel, EVT_VAR(7), 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024346C) = {
    EVT_CALL(ModifyColliderFlags, 3, 20, 0x00000006)
    EVT_SET(EVT_VAR(0), -740)
    EVT_SET(EVT_VAR(1), -140)
    EVT_SET(EVT_VAR(2), -260)
    EVT_SET(EVT_VAR(3), -55)
    EVT_SET(EVT_VAR(4), 100)
    EVT_EXEC(N(80242EA0))
    EVT_SET(EVT_VAR(0), 250)
    EVT_SET(EVT_VAR(1), -140)
    EVT_SET(EVT_VAR(2), 725)
    EVT_SET(EVT_VAR(3), -55)
    EVT_SET(EVT_VAR(4), 180)
    EVT_EXEC(N(80242EA0))
    EVT_CALL(GetModelCenter, 65)
    EVT_SET(EVT_VAR(3), 65)
    EVT_SET(EVT_VAR(4), 66)
    EVT_SET(EVT_VAR(5), 67)
    EVT_SET(EVT_VAR(6), 68)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 71)
    EVT_SET(EVT_VAR(3), 71)
    EVT_SET(EVT_VAR(4), 72)
    EVT_SET(EVT_VAR(5), 73)
    EVT_SET(EVT_VAR(6), 74)
    EVT_SET(EVT_VAR(10), 174)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 79)
    EVT_SET(EVT_VAR(3), 79)
    EVT_SET(EVT_VAR(4), 80)
    EVT_SET(EVT_VAR(5), 81)
    EVT_SET(EVT_VAR(6), 82)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_CALL(GetModelCenter, 85)
    EVT_SET(EVT_VAR(3), 85)
    EVT_SET(EVT_VAR(4), 86)
    EVT_SET(EVT_VAR(5), 87)
    EVT_SET(EVT_VAR(6), 88)
    EVT_SET(EVT_VAR(10), 0)
    EVT_EXEC(N(8024314C))
    EVT_RETURN
    EVT_END
};

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

EvtSource N(80243764) = {
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySound, 0x212D)
    EVT_CALL(N(UnkFunc21), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(85)
    EVT_THREAD
        EVT_CALL(PlaySound, 0x212E)
        EVT_CALL(N(UnkFunc23), 70, 70)
        EVT_WAIT_FRAMES(27)
        EVT_CALL(PlaySound, SOUND_208E)
        EVT_CALL(N(UnkFunc23), 50, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(N(func_8024011C_CD1F4C), EVT_MAP_VAR(0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(47)
        EVT_CALL(N(UnkFunc22))
        EVT_CALL(N(UnkPartnerPosFunc))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc2))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(N(UnkPartnerPosFunc))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(3)
    EVT_CALL(N(func_802406E0_CD2510), EVT_MAP_VAR(0))
    EVT_WAIT_FRAMES(30)
    EVT_RETURN
    EVT_END
};

EvtSource N(802438C8) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1403), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsStartingConversation, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(UnkFunc24))
    EVT_IF_EQ(EVT_VAR(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, 2097152)
    EVT_CALL(N(SetOverrideFlags_40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(N(UnkFunc20), EVT_MAP_VAR(0), EVT_VAR(9))
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, EVT_VAR(12))
    EVT_CALL(N(UnkFunc38))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DC), 160, 40)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_SAVE_FLAG(438), 0)
        EVT_SET(EVT_SAVE_FLAG(438), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DA), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DB), 160, 40)
    EVT_END_IF
    EVT_CALL(N(func_802402AC_CD20DC))
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(EVT_VAR(10), EVT_VAR(0))
    EVT_SET(EVT_VAR(11), EVT_VAR(1))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), EVT_VAR(11))
        EVT_CALL(N(SwitchToPartner), EVT_VAR(11))
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DF), 160, 40)
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_CALL(CloseMessage)
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_CALL(N(UnkFunc39), EVT_VAR(9))
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
        EVT_CALL(N(UnkFunc17))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(80243764))
    EVT_CALL(N(UnkFunc18), EVT_VAR(11), EVT_VAR(13))
    EVT_SET(EVT_SAVE_FLAG(1403), 1)
    EVT_CALL(N(UnkFunc39), EVT_VAR(9))
    EVT_CALL(N(UnkFunc19))
    EVT_IF_EQ(EVT_VAR(13), 1)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DD), 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00DE), 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, 2097152)
    EVT_CALL(N(UnkFunc17))
    EVT_RETURN
    EVT_END
};

EvtSource N(80243D48) = {
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80243DB0) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, 6)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetPlayerPos, EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
    EVT_EXEC_GET_TID(N(80243D48), EVT_VAR(10))
    EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.7))
    EVT_CALL(PlayerJump, 450, 180, -120, 30)
    EVT_CALL(SetPlayerActionState, 0)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80243E80) = {
    EVT_IF_EQ(EVT_AREA_FLAG(39), 0)
        EVT_CALL(N(UnkFunc44))
        EVT_IF_EQ(EVT_VAR(0), 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SWITCH(EVT_VAR(0))
            EVT_CASE_RANGE(620, 660)
                EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 640, 145, -100, 13, EVT_SAVE_FLAG(1388))
                EVT_SET(EVT_AREA_FLAG(39), 1)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_SET(EVT_AREA_FLAG(39), 0)
    EVT_BIND_TRIGGER(N(80243E80), TRIGGER_FLOOR_TOUCH, 20, 1, 0)
    EVT_CALL(MakeEntity, 0x802EA910, 350, 240, -100, 0, MAKE_ENTITY_END)
    EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_CALL(AssignBlockFlag, EVT_SAVE_FLAG(1403))
    EVT_CALL(AssignScript, EVT_PTR(N(802438C8)))
    EVT_CALL(MakeEntity, 0x802EAA30, 472, 100, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(80243DB0)))
    EVT_RETURN
    EVT_END
};

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus N(func_8024011C_CD1F4C)(Evt* script, s32 isInitialCall) {
    entity_upgrade_block_hide_content(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

#ifdef NON_EQUIVALENT
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

ApiStatus N(func_802402AC_CD20DC)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    N(UnkStruct)* ptr;
    s32 i;
    s32 partnerLevel;
    s32 var, partnerActiveCount;
    s32 idx;

    if (isInitialCall) {
        script->functionTemp[2] = heap_malloc(0x330);
        ptr = script->functionTemp[2];

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
        script->functionTemp[0] = 0;
    }

    ptr = script->functionTemp[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = ptr->unk_32C;
        if (script->functionTemp[1] != 0) {
            hide_popup_menu();
        } else {
            return ApiStatus_BLOCK;
        }
    }

    script->functionTemp[0]++;

    if (script->functionTemp[0] < 15) {
        return ApiStatus_BLOCK;
    }

    destroy_popup_menu();
    if (script->functionTemp[1] != 0xFF) {
        script->varTable[0] = D_8008EF20[ptr->unk_108[script->functionTemp[1] - 1]][0];
        script->varTable[1] = ptr->unk_108[script->functionTemp[1] - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTemp[2]);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/area_flo/flo_16/CD1F10", flo_16_func_802402AC_CD20DC, Evt* script,
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
    EffectGraphics* unk_08[3]; // TODO this is wrong
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

ApiStatus N(func_802406E0_CD2510)(Evt* script, s32 isInitialCall) {
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

        scriptPtr->unk_5C = get_entity_by_index(evt_get_variable(script, *args));

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
        ((EffectInstanceData*)userDataPtr->unk_08[i]->freeDelay)->rotation.x = userDataPtr->unk_14[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->freeDelay)->rotation.y = userDataPtr->unk_20[i];
        ((EffectInstanceData*)userDataPtr->unk_08[i]->freeDelay)->rotation.z = userDataPtr->unk_2C[i];
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc23.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc24.inc.c"

#include "world/common/UnkFunc44.inc.c"
