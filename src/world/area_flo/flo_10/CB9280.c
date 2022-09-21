#include "flo_10.h"
#include "message_ids.h"
#include "effects.h"
#include "sprite/npc/Lily.h"

enum {
    NPC_LILY,
};

EntryList N(entryList) = {
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -360.0f,   0.0f,    0.0f,  90.0f },
    { -100.0f, -10.0f, -172.0f, 135.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .background = &gBackgroundImage,
    .tattle = { .get = N(get_tattle) },
};

EvtScript N(802414E0) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetMusicTrack, 0, SONG_SUNSHINE_RETURNS, 0, 8)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(53)
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_CLOUDY, 0, 8)
            EVT_CASE_DEFAULT
                EVT_CALL(SetMusicTrack, 0, SONG_FLOWER_FIELDS_SUNNY, 0, 8)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, 49)
        EVT_CALL(PlaySound, 0x80000022)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802415C4) = {
    EVT_CALL(PushSong, 137, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(802415E8) = {
    EVT_CALL(FadeOutMusic, 0, 250)
    EVT_WAIT(10)
    EVT_CALL(PopSong)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1624)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80241630) = {
    EVT_IF_GE(GB_StoryProgress, 49)
        EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_167C) = {
    0x00000000,
};

EvtScript N(80241680) = {
    EVT_SET_GROUP(11)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_SET(LVarE, LVar4)
    EVT_SUB(LVarC, LVar0)
    EVT_SUB(LVarD, LVar1)
    EVT_SETF(LVar0, LVarC)
    EVT_DIVF(LVar0, EVT_FLOAT(100.0))
    EVT_SETF(LVarF, EVT_FLOAT(100.0))
    EVT_DIVF(LVarF, LVar0)
    EVT_ADD(LVarF, 11)
    EVT_SET(LVar5, 200)
    EVT_DIV(LVar5, LVarF)
    EVT_ADD(LVar5, 1)
    EVT_LOOP(LVar5)
        EVT_CALL(RandInt, LVarC, LVar0)
        EVT_CALL(RandInt, LVarD, LVar1)
        EVT_CALL(RandInt, 199, LVar2)
        EVT_SET(LVar3, 210)
        EVT_SUB(LVar3, LVar2)
        EVT_ADD(LVar0, LVarA)
        EVT_ADD(LVar1, LVarB)
        EVT_ADD(LVar2, LVarE)
        EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LVar0, LVar2, LVar1, LVar3, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_WAIT(LVarF)
    EVT_LABEL(0)
    EVT_CALL(RandInt, LVarC, LVar0)
    EVT_CALL(RandInt, LVarD, LVar1)
    EVT_ADD(LVar0, LVarA)
    EVT_ADD(LVar1, LVarB)
    EVT_CALL(PlayEffect, EFFECT_FLOATING_FLOWER, LVar0, LVarE, LVar1, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(LVarF)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_8024192C) = EXIT_WALK_SCRIPT(60,  0, "flo_24",  1);

EvtScript N(80241988) = {
    EVT_BIND_TRIGGER(N(exitWalk_8024192C), TRIGGER_FLOOR_ABOVE, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 38)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_80244054)))
    EVT_EXEC_WAIT(N(80241630))
    EVT_EXEC(flo_10_80244A50)
    EVT_EXEC(flo_10_802435F8)
    EVT_EXEC(flo_10_80242AE8)
    EVT_EXEC(flo_10_80244074)
    EVT_CALL(ModifyColliderFlags, 3, 11, 0x00000006)
    EVT_CALL(ModifyColliderFlags, 3, 12, 0x00000006)
    EVT_SET(LVar0, -265)
    EVT_SET(LVar1, 247)
    EVT_SET(LVar2, 199)
    EVT_SET(LVar3, 313)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80241680))
    EVT_SET(LVar0, -300)
    EVT_SET(LVar1, -275)
    EVT_SET(LVar2, -140)
    EVT_SET(LVar3, -185)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80241680))
    EVT_SET(LVar0, 263)
    EVT_SET(LVar1, -248)
    EVT_SET(LVar2, 362)
    EVT_SET(LVar3, 146)
    EVT_SET(LVar4, 0)
    EVT_EXEC(N(80241680))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_EXEC(flo_10_8024324C)
        EVT_CASE_EQ(2)
            EVT_EXEC(flo_10_802427EC)
            EVT_EXEC(N(80241988))
        EVT_CASE_DEFAULT
            EVT_CALL(ModifyColliderFlags, 0, 1, 0x7FFFFE00)
            EVT_SET(LVar0, EVT_PTR(N(80241988)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(802414E0))
    EVT_IF_GE(GB_StoryProgress, 53)
        EVT_CALL(N(func_80240040_CB9240))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1CA8)[] = {
    0x00000000, 0x00000000,
};

s32** N(varStash) = NULL;

EvtScript N(80241CB4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80241CE4) = {
    EVT_CALL(ShowGotItem, LVar0, 1, 16)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(updateTexturePan_80241D14) = {
    EVT_SET_GROUP(0)
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};

EvtScript N(80241DB0) = {
    EVT_CALL(MakeLerp, -50, 170, 385, 0)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, 56, 0, LVar0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80241E40) = {
    EVT_CALL(MakeLerp, 0, 100, 90, 1)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_SETF(LVar2, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_DIVF(LVar2, EVT_FLOAT(333.0))
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_ADDF(LVar2, EVT_FLOAT(0.703125))
    EVT_CALL(ScaleGroup, 56, LVar2, LVar3, LVar2)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80241F20) = {
    EVT_CALL(EnableTexPanning, 53, 1)
    EVT_THREAD
        EVT_SET(LVar0, 10)
        EVT_SET(LVar1, -150)
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(80242030) = {
    EVT_WAIT(60)
    EVT_CALL(EnableModel, 53, 1)
    EVT_EXEC(N(80241F20))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024206C) = {
    EVT_WAIT(80)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_CALL(GetNpcPos, 0, LVar3, LVar4, LVar5)
    EVT_CALL(MakeLerp, 10, 55, 108, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar6, LVar4)
        EVT_ADD(LVar6, LVar0)
        EVT_ADD(LVar6, -10)
        EVT_CALL(SetNpcPos, 0, LVar3, LVar6, LVar5)
        EVT_CALL(TranslateGroup, 60, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80242188) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetPlayerAnimation, 524324)
    EVT_CALL(GetPlayerPos, LVar2, LVar0, LVar3)
    EVT_CALL(MakeLerp, -50, 90, 60, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar2, EVT_FLOAT(1.2))
        EVT_DIVF(LVar3, EVT_FLOAT(1.2))
        EVT_CALL(SetPlayerPos, LVar2, LVar0, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 90, 270, 280, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024230C) = {
    EVT_WAIT(80)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, 0, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, 0, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.7))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(25.0), EVT_FLOAT(-22.0))
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(802423E4) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_EXEC(N(80241DB0))
    EVT_EXEC(N(80241E40))
    EVT_EXEC(N(80242030))
    EVT_EXEC(N(8024206C))
    EVT_EXEC(N(80242188))
    EVT_EXEC(N(8024230C))
    EVT_RETURN
    EVT_END
};

EvtScript N(8024244C) = {
    EVT_CALL(MakeLerp, 170, 75, 150, 0)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, 56, 0, LVar0, 0)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802424DC) = {
    EVT_CALL(MakeLerp, 100, 15, 150, 1)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_SETF(LVar2, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_DIVF(LVar2, EVT_FLOAT(333.0))
    EVT_DIVF(LVar3, EVT_FLOAT(100.0))
    EVT_ADDF(LVar2, EVT_FLOAT(0.703125))
    EVT_CALL(ScaleGroup, 56, LVar2, LVar3, LVar2)
    EVT_IF_EQ(LVar1, 1)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802425BC) = {
    EVT_EXEC(N(8024244C))
    EVT_EXEC(N(802424DC))
    EVT_RETURN
    EVT_END
};

extern const char N(flo_24_name_hack)[];

EvtScript N(802425E4) = {
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, 0, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, 0, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(EnableGroup, 56, 1)
    EVT_CALL(TranslateGroup, 56, 0, -50, 0)
    EVT_CALL(ScaleGroup, 56, 0, 0, 0)
    EVT_CALL(EnableGroup, 60, 1)
    EVT_EXEC_WAIT(N(802423E4))
    EVT_WAIT(20)
    EVT_CALL(PlaySound, 0x80000024)
    EVT_WAIT(360)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.2))
    EVT_CALL(PlayerJump1, -100, -10, -172, 75)
    EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(802425BC))
    EVT_WAIT(60)
    EVT_CALL(GotoMap, EVT_PTR(N(flo_24_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(802427EC) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, -100, -10, -172)
    EVT_CALL(InterpPlayerYaw, 150, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_DeadStill)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -129, 9, -177)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, -4)
    EVT_CALL(EnableGroup, 52, 1)
    EVT_CALL(EnableGroup, 19, 0)
    EVT_CALL(EnableGroup, 61, 0)
    EVT_CALL(EnableGroup, 60, 0)
    EVT_CALL(SetNpcPos, 0, -57, -20, -105)
    EVT_CALL(InterpNpcYaw, 0, 90, 0)
    EVT_CALL(AdjustCam, 0, EVT_FLOAT(90.0), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GetUp)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(10)
    EVT_EXEC_WAIT(N(802415C4))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_0082)
    EVT_CALL(NpcFacePlayer, 0, 1)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0083)
    EVT_CALL(SetNpcAnimation, 0, ANIM_Lily_GiveItem)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, 0, ANIM_Lily_Idle)
    EVT_SET(LVar0, 90)
    EVT_SET(LVar1, 1)
    EVT_EXEC_WAIT(N(80241CB4))
    EVT_CALL(AddKeyItem, ITEM_MIRACLE_WATER)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0084)
    EVT_CALL(EndSpeech, 0, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
    EVT_CALL(SetNpcAnimation, 0, ANIM_Lily_Idle)
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(802415E8))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242AE8) = {
    EVT_IF_LT(GB_StoryProgress, 49)
        EVT_CALL(EnableGroup, 52, 0)
        EVT_CALL(EnableGroup, 61, 0)
        EVT_CALL(ModifyColliderFlags, 0, 21, 0x7FFFFE00)
    EVT_ELSE
        EVT_CALL(EnableGroup, 19, 0)
        EVT_CALL(EnableGroup, 61, 0)
        EVT_CALL(EnableGroup, 60, 0)
        EVT_CALL(ModifyColliderFlags, 0, 14, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 15, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 16, 0x7FFFFE00)
        EVT_CALL(ModifyColliderFlags, 0, 17, 0x7FFFFE00)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, 54, 1)
    EVT_CALL(EnableTexPanning, 48, 1)
    EVT_CALL(EnableTexPanning, 55, 1)
    EVT_CALL(EnableTexPanning, 59, 1)
    EVT_CALL(EnableTexPanning, 49, 1)
    EVT_CALL(EnableTexPanning, 51, 1)
    EVT_THREAD
        EVT_SET(LVar0, 1)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -2000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 3)
        EVT_SET(LVar1, -100)
        EVT_SET(LVar2, 80)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 5)
        EVT_SET(LVar1, -1000)
        EVT_SET(LVar2, 2000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 1)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 6)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -2000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 8)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -1500)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 9)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, -1000)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 0)
        EVT_SET(LVar6, 1)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
        EVT_SET(LVar9, 0)
        EVT_SET(LVarA, 0)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_EXEC(N(updateTexturePan_80241D14))
    EVT_END_THREAD
    EVT_IF_GE(GB_StoryProgress, 49)
        EVT_EXEC(N(80241F20))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3218)[] = {
    0x00000000, 0x00000000,
};

NpcSettings N(npcSettings_80243220) = {
    .height = 45,
    .radius = 65,
    .level = 99,
};

const char N(flo_24_name_hack)[] = "flo_24";

EvtScript N(8024324C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetNpcPos, 0, 60, 0, 55)
    EVT_CALL(UseSettingsFrom, 0, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 0, 0, 0)
    EVT_CALL(SetCamDistance, 0, 450)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_00C6)
    EVT_WAIT(10)
    EVT_CALL(GotoMap, EVT_PTR("flo_12"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80243394)[] = {
    ITEM_WATER_STONE,
    ITEM_NONE,
};

EvtScript N(8024339C) = {
    EVT_IF_EQ(GF_FLO10_ShowedLilyTheWaterStone, 1)
        EVT_CALL(GetCurrentPartner, LVarA)
        EVT_IF_NE(LVarA, 0)
            EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_SET_GROUP(0)
        EVT_CALL(SetTimeFreezeMode, 1)
        EVT_CALL(ShowKeyChoicePopup)
        EVT_SET(LVar2, LVar0)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(-1)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, 0, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0081)
            EVT_CASE_DEFAULT
                EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
                EVT_CALL(PlayerMoveTo, -17, -17, 20)
                EVT_CALL(func_802CF56C, 2)
                EVT_CALL(InterpPlayerYaw, 100, 1)
                EVT_WAIT(10)
                EVT_CALL(AdjustCam, 0, EVT_FLOAT(1.0), 0, 450, EVT_FLOAT(25.0), EVT_FLOAT(-6.0))
                EVT_WAIT(10)
                EVT_CALL(SetPlayerAnimation, 393222)
                EVT_CALL(RemoveKeyItemAt, LVar1)
                EVT_CALL(MakeItemEntity, ITEM_WATER_STONE, 0, -60, 6, 1, 0)
                EVT_SET(LVarA, LVar0)
                EVT_CALL(CloseChoicePopup)
                EVT_CALL(SetTimeFreezeMode, 0)
                EVT_EXEC_WAIT(N(802425E4))
        EVT_END_SWITCH
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(AwaitPlayerLeave, 0, 0, 19)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802435F8) = {
    EVT_BIND_PADLOCK(N(8024339C), TRIGGER_FLOOR_TOUCH, 15, EVT_PTR(N(itemList_80243394)), 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80243628) = {
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar5, LVar2)
        EVT_SET(LVar6, 30)
    EVT_ELSE
        EVT_SET(LVar6, 20)
    EVT_END_IF
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar4, LVar0)
    EVT_SUB(LVar1, LVar6)
    EVT_ADD(LVar4, LVar6)
    EVT_SWITCH(LVar3)
        EVT_CASE_RANGE(LVar1, LVar4)
            EVT_THREAD
                EVT_IF_LT(LVar3, LVar0)
                    EVT_SUB(LVar0, 40)
                EVT_ELSE
                    EVT_ADD(LVar0, 40)
                EVT_END_IF
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
                EVT_CALL(PlayerMoveTo, LVar0, LVar5, 15)
                EVT_CALL(PlayerFaceNpc, 0, 1)
                EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
            EVT_END_THREAD
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_802437C8) = {
    EVT_EXEC_WAIT(N(802415C4))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(45)
            EVT_EXEC(N(80243628))
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_CALL(SetCamDistance, 0, 325)
            EVT_CALL(SetCamPitch, 0, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
            EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
            EVT_CALL(PanToTarget, 0, 0, 1)
            EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0078)
            EVT_CALL(EndSpeech, -1, ANIM_Lily_DreadLoop, ANIM_Lily_Dread, 5)
        EVT_CASE_LT(48)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 0)
                EVT_EXEC(N(80243628))
                EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
                EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
                EVT_CALL(SetCamDistance, 0, 325)
                EVT_CALL(SetCamPitch, 0, EVT_FLOAT(23.0), EVT_FLOAT(-9.0))
                EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
                EVT_CALL(PanToTarget, 0, 0, 1)
                EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
                EVT_WAIT(10)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_0079)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lily_Idle)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_262, 0)
                EVT_CALL(ShowEmote, -1, EMOTE_EXCLAMATION, 0, 15, 1, 0, 0, 0, 0)
                EVT_WAIT(15)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Idle, ANIM_Lily_Idle, 0, MSG_CH6_007A)
                EVT_CALL(EndSpeech, -1, ANIM_Lily_Dread, ANIM_Lily_Idle, 0)
                EVT_CALL(GetPlayerTargetYaw, LVar0)
                EVT_CALL(InterpNpcYaw, NPC_SELF, LVar0, 1)
                EVT_WAIT(20)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 5, MSG_CH6_007B)
                EVT_CALL(NpcFacePlayer, NPC_SELF, 1)
                EVT_WAIT(20)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_007C)
                EVT_CALL(ShowChoice, MSG_Choice_0011)
                EVT_WAIT(10)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(0)
                        EVT_CALL(ContinueSpeech, -1, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_007D)
                    EVT_CASE_EQ(1)
                        EVT_CALL(ContinueSpeech, -1, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_007E)
                EVT_END_SWITCH
                EVT_WAIT(10)
                EVT_SET(GF_FLO10_LilyRequestedWaterStone, 1)
                EVT_CALL(SetEnemyFlagBits, -1, 4194304, 0)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 5, MSG_CH6_007F)
            EVT_END_IF
        EVT_CASE_LT(49)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0080)
            EVT_SET(GF_FLO10_ShowedLilyTheWaterStone, 1)
        EVT_CASE_LT(53)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0, MSG_CH6_0085)
            EVT_CALL(EndSpeech, -1, ANIM_Lily_Talk, ANIM_Lily_Idle, 0)
            EVT_CALL(EndSpeech, -1, ANIM_Lily_TalkPlead, ANIM_Lily_IdlePlead, 0)
        EVT_CASE_LT(60)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_TalkHappy, ANIM_Lily_IdleHappy, 0, MSG_CH6_0086)
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Lily_Talk, ANIM_Lily_Idle, 0, MSG_CH6_0087)
    EVT_END_SWITCH
    EVT_CALL(ResetCam, 0, EVT_FLOAT(4.0))
    EVT_EXEC_WAIT(N(802415E8))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80243D78) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_802437C8)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(48)
            EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Lily_IdlePlead)
                EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 1)
                EVT_CALL(SetEnemyFlagBits, -1, 4194304, 1)
            EVT_END_IF
        EVT_CASE_EQ(48)
            EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 1)
        EVT_CASE_GE(49)
            EVT_CALL(SetNpcPos, NPC_SELF, -67, -20, -105)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80243E64) = {
    .id = NPC_LILY,
    .settings = &N(npcSettings_80243220),
    .pos = { 80.0f, -60.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80243D78),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
        ANIM_Lily_Idle,
    },
    .tattle = MSG_NpcTattle_Lily,
};

NpcGroupList N(npcGroupList_80244054) = {
    NPC_GROUP(N(npcGroup_80243E64)),
    {},
};

static s32 N(pad_406C) = {
    0x00000000,
};

s32 N(D_80244070_CBD270) = {
    0x00000000,
};

EvtScript N(80244074) = {
    EVT_RETURN
    EVT_END
};

static s32 N(pad_4084)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

