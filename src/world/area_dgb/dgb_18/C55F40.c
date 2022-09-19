#include "dgb_18.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/Yakkey.h"

enum {
    NPC_WORLD_TUBBA,
    NPC_YAKKEY,
};

EntryList N(entryList) = {
    { -120.0f, 0.0f, 180.0f, 90.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_18 },
};

EvtScript N(802412C0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1358)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitDoubleDoor_80241360) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 17)
    EVT_SET(LVar2, 8)
    EVT_SET(LVar3, 10)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_01"), 6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterDoubleDoor_80241414) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar2, 8)
            EVT_SET(LVar3, 10)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_802436B4)))
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802412C0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80241360), TRIGGER_WALL_PRESS_A, 17, 1, 0)
    EVT_EXEC(N(enterDoubleDoor_80241414))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_1578)[] = {
    0x00000000, 0x00000000,
};

MobileAISettings N(npcAISettings_80241580) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .alertOffsetDist = 90.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.9f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 170.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(802415B0) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_80241580)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802415D0) = {
    .height = 90,
    .radius = 65,
    .ai = &N(802415B0),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_802415FC) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80241628) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtScript N(idle_80241654) = {
    EVT_LABEL(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_IF_LT(LVar0, 700)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_GT(LVar2, 185)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_LOOP(3)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001E)
        EVT_CALL(PlaySoundAt, SOUND_20F6, 0, 382, 0, 218)
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(1.0))
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_LOOP(2)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, 0, -40, 0, 180)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, 0, -40, 0, 180)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetPlayerPos, 740, 0, 180)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 765, 0, 180)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8000C)
    EVT_CALL(PlaySoundAtCollider, 17, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 8, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, 10, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_BLUBBA_THEME, 0, 8)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim9)
    EVT_CALL(SetNpcPos, NPC_SELF, -210, 0, 180)
    EVT_CALL(NpcMoveTo, NPC_SELF, -60, 180, 30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim6)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 8, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, 10, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 17, 456, 0)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim6, 5, MSG_CH3_00F4)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim9)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(9)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(0.15))
            EVT_WAIT(12)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 45, 215, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 140, 245, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 615, 245, 0)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim6)
    EVT_WAIT(15)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim10, ANIM_WorldTubba_Anim6, 5, MSG_CH3_00F5)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim14)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim15)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim16)
        EVT_WAIT(5)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_SELF, 600, 50, 115, 20)
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim5)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.2), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.35), EVT_FLOAT(1.15), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.45), EVT_FLOAT(1.05), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.35), EVT_FLOAT(1.15), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.2), EVT_FLOAT(1.25))
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_SELF, LVar3, 30, LVar5, 23)
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 50, 18, 1)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CDE68, -1, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -90, 18, 1)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FLOAT(0.4))
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(func_802CDE68, -1, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim2)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 15)
            EVT_CALL(ShowSleepBubble, 0, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            EVT_WAIT(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetSleepBubbleTimeLeft, LVar0, LVar1)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(GB_StoryProgress, -30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80242494) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetNpcPos, NPC_SELF, 600, 50, 115)
    EVT_CALL(func_802CDE68, -1, 0)
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim2)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim24)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(SetSelfVar, 1, 0)
        EVT_LOOP(0)
            EVT_CALL(GetSelfVar, 1, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 15)
            EVT_CALL(ShowSleepBubble, 0, 0, 0, 2, 628, 121, 127, LVar1, LVar0)
            EVT_WAIT(48)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2038, 0)
            EVT_CALL(RandInt, 10, LVar1)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetSleepBubbleTimeLeft, LVar0, LVar1)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(npcAI_802426B0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2039, 0)
    EVT_CALL(ShowSleepBubble, 0, 0, 50, 2, 552, 111, 128, 30, LVar0)
    EVT_WAIT(360)
    EVT_CALL(SetSleepBubbleTimeLeft, LVar0, 20)
    EVT_CALL(SetNpcVar, -1, 1, 2)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2F1, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim19)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(NpcJump0, NPC_SELF, 650, 0, 250, 25)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1A)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1B)
    EVT_WAIT(12)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim1C)
    EVT_WAIT(5)
    EVT_CALL(BindNpcAI, 0, EVT_PTR(N(npcAI_80242834)))
    EVT_RETURN
    EVT_END
};

EvtScript N(npcAI_80242834) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldTubba_AnimD)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_80241580)))
    EVT_RETURN
    EVT_END
};

extern const char N(dgb_01_name_hack)[];

EvtScript N(defeat_802428E8) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_01_name_hack)), 6)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

const char N(pad_XXX)[] = { 0, 0 };

EvtScript N(init_80242924) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802428E8)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-30)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80241654)))
        EVT_CASE_LT(-29)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242494)))
        EVT_CASE_LT(-28)
            EVT_CALL(SetNpcPos, NPC_SELF, 245, 0, 250)
            EVT_CALL(SetNpcYaw, NPC_SELF, 270)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(npcAI_80242834)))
        EVT_CASE_LT(-26)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80242A24) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 845, 0, 140)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.8))
    EVT_CALL(NpcJump1, NPC_SELF, 845, 35, 145, 15)
    EVT_CALL(PlayerFaceNpc, -1, 0)
    EVT_WAIT(15)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamPosB, 0, 800, 245)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Anim2, ANIM_Yakkey_Anim1, 5, MSG_CH3_00F6)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Anim2, ANIM_Yakkey_Anim1, 5, MSG_CH3_00F7)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, -1, ANIM_Yakkey_Anim2, ANIM_Yakkey_Anim1, 0, MSG_CH3_00F8)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, -1, ANIM_Yakkey_Anim2, ANIM_Yakkey_Anim1, 0, MSG_CH3_00F9)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(UseSettingsFrom, 0, 740, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 600)
    EVT_CALL(SetCamPosB, 0, 800, 245)
    EVT_CALL(SetPanTarget, 0, 740, LVar1, LVar2)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_SET(MapFlag(0), 0)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Yakkey_Anim2, ANIM_Yakkey_Anim1, 517, MSG_CH3_00FA)
        EVT_SET(MapFlag(0), 1)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(SetCamDistance, 0, EVT_FLOAT(550.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(SetPanTarget, 0, 740, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(SetCamDistance, 0, EVT_FLOAT(600.0))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(SetPanTarget, 0, 740, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_EQ(MapFlag(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
    EVT_CALL(SetNpcVar, 0, 1, 1)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldTubba_Anim25)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetNpcVar, 0, 1, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(RandInt, 40, LVar0)
            EVT_CALL(RandInt, 40, LVar1)
            EVT_ADD(LVar0, 537)
            EVT_ADD(LVar1, 110)
            EVT_CALL(PlayEffect, 0x27, 2, LVar0, LVar1, 128, EVT_FLOAT(0.3), 24, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, 0, ANIM_WorldTubba_Anim5)
    EVT_CALL(SpeakToPlayer, 0, ANIM_WorldTubba_Anim13, ANIM_WorldTubba_Anim5, 5, MSG_CH3_00FB)
    EVT_WAIT(15)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH3_00FC)
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldKooper_Talk, ANIM_WorldKooper_Idle, 0, MSG_CH3_00FD)
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_AnimE, ANIM_WorldBombette_Anim3, 0, MSG_CH3_00FE)
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldParakarry_Anim6, ANIM_WorldParakarry_Anim1, 0, MSG_CH3_00FF)
        EVT_CASE_EQ(9)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Anim4, ANIM_WorldBow_Anim1, 0, MSG_CH3_0100)
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(15)
    EVT_CALL(BindNpcAI, 0, EVT_PTR(N(npcAI_802426B0)))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100)), TRUE)
    EVT_SUB(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_SET(GB_StoryProgress, -29)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024329C) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80242A24)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802432D4) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802415FC),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_200000 | NPC_FLAG_NO_DROPS,
    .init = &N(init_80242924),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 5, 0, 0, 240, 175, 0, 240, 350, 0, 240, 525, 0, 240, 700, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 300, 0, 240, 1000, 250, 1, 1 }},
    .animations = {
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_AnimA,
        ANIM_WorldTubba_AnimD,
        ANIM_WorldTubba_AnimD,
        ANIM_WorldTubba_Anim19,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
        ANIM_WorldTubba_Anim7,
    },
};

StaticNpc N(npcGroup_802434C4) = {
    .id = NPC_YAKKEY,
    .settings = &N(npcSettings_80241628),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
    .init = &N(init_8024329C),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
        ANIM_Yakkey_Anim1,
    },
};

NpcGroupList N(npcGroupList_802436B4) = {
    NPC_GROUP(N(npcGroup_802432D4), 0x0F04, BTL_DEFAULT_STAGE),
    NPC_GROUP(N(npcGroup_802434C4)),
    {},
};

static s32 N(pad_36D8)[] = {
    0x00000000, 0x00000000,
};

s32** N(varStash) = NULL; // StashVars.inc.c data

EvtScript N(802436E4) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 2)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, 0, 0)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8024374C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_IF_NE(LVarA, 0)
        EVT_EXEC_WAIT(N(802436E4))
    EVT_END_IF
    EVT_SWITCH(LVarB)
        EVT_CASE_EQ(0)
            EVT_CALL(AddItem, LVarA, LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(AddKeyItem, LVarA)
        EVT_CASE_EQ(2)
            EVT_CALL(AddBadge, LVarA, LVar0)
    EVT_END_SWITCH
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024382C) = {
    EVT_SET(GF_DGB18_Chest_MysticalKey, 1)
    EVT_CALL(AddKeyItem, ITEM_MYSTICAL_KEY)
    EVT_CALL(SetNpcVar, 1, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, &Entity_Chest, 845, 0, 145, -35, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_DGB18_Chest_MysticalKey)
    EVT_CALL(AssignScript, EVT_PTR(N(8024382C)))
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/UnkFunc1.inc.c"

ApiStatus N(func_80240EBC_C56DFC)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(0);
    f32 posX, posZ;

    if (isInitialCall) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        npc->moveSpeed = 3.7f;
        npc->yaw = atan2(posX, posZ, playerStatus->position.x, playerStatus->position.z);
        script->functionTemp[1] = 0;
        npc->duration = 15;
    }

    if (script->functionTemp[1] == 0) {
        if (npc->duration == 0) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            npc->duration = 15;
        }
        npc->duration--;
    }

    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    return ApiStatus_BLOCK;
}

const char N(dgb_01_name_hack)[] = "dgb_01";
