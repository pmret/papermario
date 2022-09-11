#include "dgb_01.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_tubba.h"
#include "message_ids.h"
#include "effects.h"
#include "entity.h"
#include "world/partners.h"

EntryList N(entryList) = {
    {    0.0f,   0.0f, 485.0f,   0.0f },
    { -485.0f,   0.0f,   0.0f,  90.0f },
    {  485.0f,   0.0f,   0.0f, 270.0f },
    { -485.0f, 210.0f,   0.0f,  90.0f },
    {  485.0f, 210.0f,   0.0f, 270.0f },
    { -485.0f, 420.0f,   0.0f,  90.0f },
    {  485.0f, 420.0f,   0.0f, 270.0f },
};

MapSettings N(settings) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_MapTattle_dgb_01 },
};

EvtScript N(802434A0) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
        EVT_CASE_LT(-16)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBA_ESCAPE, 0, 8)
        EVT_CASE_DEFAULT
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 0, 8)
    EVT_END_SWITCH
    EVT_CALL(ClearAmbientSounds, 250)
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3548)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(exitDoubleDoor_80243550) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 4)
    EVT_SET(LVar2, 54)
    EVT_SET(LVar3, 57)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_00"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80243604) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 8)
    EVT_SET(LVar2, 34)
    EVT_SET(LVar3, 36)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_02"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802436B8) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, 20)
    EVT_SET(LVar2, 41)
    EVT_SET(LVar3, 39)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_08"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_8024376C) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 3)
    EVT_SET(LVar1, 12)
    EVT_SET(LVar2, 29)
    EVT_SET(LVar3, 31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_09"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80243820) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 4)
    EVT_SET(LVar1, 24)
    EVT_SET(LVar2, 46)
    EVT_SET(LVar3, 44)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_08"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_802438D4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 5)
    EVT_SET(LVar1, 16)
    EVT_SET(LVar2, 24)
    EVT_SET(LVar3, 26)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_17"), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitDoubleDoor_80243988) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(LVar0, 6)
    EVT_SET(LVar1, 28)
    EVT_SET(LVar2, 51)
    EVT_SET(LVar3, 49)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("dgb_18"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(enterDoubleDoor_80243A3C) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(GF_DGB01_Visited, 0)
                EVT_SET(GF_DGB01_Visited, 1)
                EVT_SET(GB_StoryProgress, -32)
            EVT_END_IF
            EVT_SET(LVar2, 54)
            EVT_SET(LVar3, 57)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_SET(LVar2, 34)
            EVT_SET(LVar3, 36)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(2)
            EVT_SET(LVar2, 41)
            EVT_SET(LVar3, 39)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(3)
            EVT_SET(LVar2, 29)
            EVT_SET(LVar3, 31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(4)
            EVT_SET(LVar2, 46)
            EVT_SET(LVar3, 44)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(5)
            EVT_SET(LVar2, 24)
            EVT_SET(LVar3, 26)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(6)
            EVT_SET(LVar2, 51)
            EVT_SET(LVar3, 49)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80243C40)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE,
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_SET(GF_MAP_TubbasManor, 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802449C4))
    EVT_EXEC(N(802434A0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243550), TRIGGER_WALL_PRESS_A, 4, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243604), TRIGGER_WALL_PRESS_A, 8, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_8024376C), TRIGGER_WALL_PRESS_A, 12, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243820), TRIGGER_WALL_PRESS_A, 24, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802438D4), TRIGGER_WALL_PRESS_A, 16, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243988), TRIGGER_WALL_PRESS_A, 28, 1, 0)
    EVT_IF_EQ(GF_DGB01_UnlockedEastWing, 0)
        EVT_BIND_PADLOCK(N(80244AD0), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(itemList_80243C40)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(N(exitDoubleDoor_802436B8), TRIGGER_WALL_PRESS_A, 20, 1, 0)
    EVT_END_IF
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246E50)))
        EVT_CASE_LT(-16)
            EVT_CALL(GetEntryID, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246F1C)))
                EVT_CASE_EQ(4)
                    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246ED4)))
                EVT_CASE_EQ(6)
                    EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246E8C)))
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_EXEC(N(enterDoubleDoor_80243A3C))
    EVT_RETURN
    EVT_END
};

static s32 N(pad_3EE4)[] = {
    0x00000000, 0x00000000, 0x00000000,
};

EvtScript N(80243EF0) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(func_80240000_BFD880))
    EVT_CALL(InitAnimatedModels)
    EVT_WAIT(1)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(SetPlayerAnimation, 524298)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_WAIT(5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_THREAD
        EVT_LOOP(12)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 60, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, 0, 400, 420, 0)
    EVT_CALL(SetPanTarget, 0, 400, 420, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(20.0), EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPosB, 0, EVT_FLOAT(500.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_CALL(SetNpcVar, 4, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcVar, 4, 0, LVar0)
        EVT_IF_EQ(LVar0, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -50)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(750.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(0.0), EVT_FLOAT(3.0))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(1.0))
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(D_80252F4C_C107CC)))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(N(D_802539A0_C11220)))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, 0, 1)
    EVT_THREAD
        EVT_CALL(PlaySound, 0x95)
        EVT_WAIT(60)
        EVT_CALL(PlaySound, 0x96)
        EVT_WAIT(25)
        EVT_CALL(PlaySound, 0x98)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, 0x97)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(100)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT(50)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT(30)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT(70)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT(30)
        EVT_CALL(PlaySound, 0xA8)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetGroupEnabled, 100, 0)
        EVT_CALL(SetGroupEnabled, 111, 0)
        EVT_CALL(SetPlayerAnimation, 524307)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.5))
        EVT_CALL(PlayerJump1, 121, 210, 0, 60)
        EVT_WAIT(10)
        EVT_CALL(SetPlayerAnimation, 524319)
        EVT_WAIT(20)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_RunPanic)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(8.0))
        EVT_CALL(PlayerMoveTo, 412, -29, 0)
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_CALL(ModifyColliderFlags, 1, 50, 0x7FFFFE00)
        EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 210)
        EVT_WAIT(1)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_PARTNER, 151, LVar1, 0, 60)
        EVT_WAIT(30)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ShakeCam, 0, 0, 300, EVT_FLOAT(1.0))
    EVT_CALL(StopSound, 0x8000005D)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_D)
        EVT_CALL(SetNpcSpeed, 4, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, 4, 176, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.3))
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(0.15))
        EVT_WAIT(8)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(GB_StoryProgress, -28)
    EVT_CALL(SetGroupEnabled, 210, 1)
    EVT_CALL(DeleteAnimatedModel, 0)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_D)
        EVT_CALL(SetNpcPos, 4, 137, 244, 35)
        EVT_CALL(SetNpcSpeed, 4, EVT_FLOAT(3.0))
        EVT_CALL(NpcMoveTo, 4, 470, 0, 0)
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(0.3))
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(0.15))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, 470, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC(N(exitDoubleDoor_80243820))
    EVT_RETURN
    EVT_END
};

EvtScript N(802449C4) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-29)
            EVT_CALL(SetGroupEnabled, 210, 0)
            EVT_CALL(ModifyColliderFlags, 0, 50, 0x7FFFFE00)
        EVT_CASE_EQ(-29)
            EVT_CALL(SetGroupEnabled, 210, 0)
            EVT_CALL(ModifyColliderFlags, 0, 50, 0x7FFFFE00)
            EVT_EXEC(N(80243EF0))
        EVT_CASE_LT(-16)
            EVT_CALL(SetGroupEnabled, 112, 0)
            EVT_CALL(ModifyColliderFlags, 0, 40, 0x7FFFFE00)
        EVT_CASE_DEFAULT
            EVT_CALL(SetGroupEnabled, 210, 0)
            EVT_CALL(ModifyColliderFlags, 0, 50, 0x7FFFFE00)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80244AD0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_DGB01_UnlockedEastWing, 1)
    EVT_CALL(N(GetEntityPosition), MapVar(0), LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, 0x269, 0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MapVar(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_RESUME_GROUP(1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80244C38) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802436B8), TRIGGER_WALL_PRESS_A, 20, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_IF_EQ(GF_DGB01_UnlockedEastWing, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 490, 8, 0, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80244C38)))
        EVT_SET(MapVar(0), LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtScript N(80244CE8) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING)), TRUE)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(npcAISettings_80244D24) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 5.3f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 1,
    .chaseRadius = 240.0f,
    .unk_AI_2C = 1,
};

#define AI_SENTINEL_FIRST_NPC 0
#define AI_SENTINEL_LAST_NPC  4
#include "world/common/enemy/SentinelAI.inc.c"

extern const char N(dgb_00_name_hack)[];

EvtScript N(npcAI_80244D54) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(SentinelAI_Main), EVT_PTR(N(npcAISettings_80244D24)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar4, LVar2)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80017)
    EVT_WAIT(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(8024517C) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, LVar0)
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80245208) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_8024526C) = {
    .height = 38,
    .radius = 32,
    .otherAI = &N(80244CE8),
    .ai = &N(npcAI_80244D54),
    .level = 99,
};

MobileAISettings N(npcAISettings_80245298) = {
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

EvtScript N(npcAI_802452C8) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_80245298)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_802452E8) = {
    .height = 90,
    .radius = 65,
    .ai = &N(npcAI_802452C8),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80245314) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80245340) = {
    .height = 24,
    .radius = 24,
    .level = 13,
};

EvtScript N(idle_8024536C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_CALL(PlaySoundAtCollider, 28, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 49, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, 51, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_A)
    EVT_CALL(SetNpcPos, NPC_SELF, 520, 420, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(NpcMoveTo, NPC_SELF, 390, 0, 30)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_7)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 49, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, 51, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 28, 456, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 0, MSG_CH3_0101)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_19)
        EVT_WAIT(4)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1A)
        EVT_WAIT(17)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1B)
        EVT_WAIT(11)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1C)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1D)
    EVT_END_THREAD
    EVT_WAIT(4)
    EVT_CALL(SetNpcJumpscale, 4, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, 4, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, 4, LVar0, LVar1, LVar2, 30)
    EVT_CALL(PlaySoundAtNpc, 4, 0x20A0, 0)
    EVT_CALL(PlaySound, 0x8000005D)
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FLOAT(4.0))
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FLOAT(2.0))
    EVT_CALL(SetSelfVar, 0, 3)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245784) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024536C)))
    EVT_RETURN
    EVT_END
};

const char N(dgb_00_name_hack)[] = "dgb_00";

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#include "world/common/UnkFunc1.inc.c"

extern const char N(dgb_08_name_hack)[];

EvtScript N(defeat_802457D8) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_08_name_hack)), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245814) = {
    EVT_IF_NE(GB_ARN_Tubba_MapID, 1)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(GB_StoryProgress, -27)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, 4, 137, 244, 35)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802457D8)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8024598C) = {
    EVT_CALL(AwaitPlayerApproach, 0, 420, 400)
    EVT_SET(GB_ARN_Tubba_MapID, 1)
    EVT_SET(GB_StoryProgress, -26)
    EVT_CALL(PlaySoundAtCollider, 20, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 39, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, 41, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_SELF, 555, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_A)
    EVT_CALL(NpcMoveTo, NPC_SELF, 426, 0, 30)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 39, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, 41, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 20, 456, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FLOAT(2.0))
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FLOAT(1.0))
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 259, 167, 0)
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(npcAISettings_80245298)))
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80245CB4) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, EVT_PTR(N(dgb_00_name_hack)), 1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245CF0) = {
    EVT_IF_NE(GB_ARN_Tubba_MapID, 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024598C)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 136, 0, -330)
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80245CB4)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245D80) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, -29)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40)), TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_1)
        EVT_CALL(SetNpcPos, NPC_SELF, -33, -3, 8)
        EVT_CALL(SetNpcRotation, NPC_SELF, -50, 30, 10)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245E44) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, -29)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40)), TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_1)
        EVT_CALL(SetNpcPos, NPC_SELF, -486, 182, 28)
        EVT_CALL(SetNpcRotation, NPC_SELF, -10, 50, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245F08) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, -29)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40)), TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_1)
        EVT_CALL(SetNpcPos, NPC_SELF, -201, 0, -143)
        EVT_CALL(SetNpcRotation, NPC_SELF, -50, 0, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245FCC) = {
    EVT_SET(LVar0, GB_StoryProgress)
    EVT_IF_GE(LVar0, -29)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40)), TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_1)
        EVT_CALL(SetNpcPos, NPC_SELF, -305, -1, -80)
        EVT_CALL(SetNpcRotation, NPC_SELF, -65, -30, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80246090) = {
    .id = NPC_SENTINEL0,
    .settings = &N(npcSettings_8024526C),
    .pos = { -180.0f, 100.0f, 230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80245D80),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { -180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 }},
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80246280) = {
    .id = NPC_SENTINEL1,
    .settings = &N(npcSettings_8024526C),
    .pos = { 180.0f, 100.0f, 230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80245E44),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 }},
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80246470) = {
    .id = NPC_SENTINEL2,
    .settings = &N(npcSettings_8024526C),
    .pos = { -180.0f, 100.0f, -230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80245F08),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { -180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 }},
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

StaticNpc N(npcGroup_80246660) = {
    .id = NPC_SENTINEL3,
    .settings = &N(npcSettings_8024526C),
    .pos = { 180.0f, 100.0f, -230.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80245FCC),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.territory = { .temp = { 180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 }},
    .animations = {
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_2,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_3,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_5,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_8,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
        NPC_ANIM_sentinel_Palette_00_Anim_1,
    },
};

s32 N(extraAnimationList_80246850)[] = {
    NPC_ANIM_world_tubba_Palette_00_Anim_6,
    NPC_ANIM_world_tubba_Palette_00_Anim_10,
    NPC_ANIM_world_tubba_Palette_00_Anim_9,
    NPC_ANIM_world_tubba_Palette_00_Anim_7,
    NPC_ANIM_world_tubba_Palette_00_Anim_A,
    NPC_ANIM_world_tubba_Palette_00_Anim_D,
    NPC_ANIM_world_tubba_Palette_00_Anim_19,
    NPC_ANIM_world_tubba_Palette_00_Anim_1A,
    NPC_ANIM_world_tubba_Palette_00_Anim_1B,
    NPC_ANIM_world_tubba_Palette_00_Anim_1C,
    NPC_ANIM_world_tubba_Palette_00_Anim_1D,
    ANIM_LIST_END,
};

StaticNpc N(npcGroup_80246880) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_80245314),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245784),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
	.animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_6,
        NPC_ANIM_world_tubba_Palette_00_Anim_9,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_C,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
        NPC_ANIM_world_tubba_Palette_00_Anim_0,
    },
    .extraAnimations = N(extraAnimationList_80246850),
};

StaticNpc N(npcGroup_80246A70) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802452E8),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245814),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { 2, 320, 210, 0, 370, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 350, 210, 0, 1000, 250, 1 }},
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_A,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_19,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
    },
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    .extraAnimations = N(extraAnimationList_80246850),
};

StaticNpc N(npcGroup_80246C60) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802452E8),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245CF0),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 2,
        .maxCoinBonus = 3,
    },
	.territory = { .temp = { 8, 156, 0, 187, -36, 0, 290, -159, 0, 50, -80, 0, -218, 66, 0, -362, 196, 0, -268, 280, 0, -124, 250, 0, 100, 0, 0, 0, 0, 0, 0, -32767, 250, 0, 100, 1000, 250, 1 }},
    .animations = {
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_A,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_D,
        NPC_ANIM_world_tubba_Palette_00_Anim_19,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
        NPC_ANIM_world_tubba_Palette_00_Anim_7,
    },
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    .extraAnimations = N(extraAnimationList_80246850),
};

NpcGroupList N(npcGroupList_80246E50) = {
    NPC_GROUP(N(npcGroup_80246090)),
    NPC_GROUP(N(npcGroup_80246280)),
    NPC_GROUP(N(npcGroup_80246470)),
    NPC_GROUP(N(npcGroup_80246660)),
    {},
};

NpcGroupList N(npcGroupList_80246E8C) = {
    NPC_GROUP(N(npcGroup_80246090)),
    NPC_GROUP(N(npcGroup_80246280)),
    NPC_GROUP(N(npcGroup_80246470)),
    NPC_GROUP(N(npcGroup_80246660)),
    NPC_GROUP(N(npcGroup_80246880), 0x0F04, BTL_DEFAULT_STAGE),
    {},
};

NpcGroupList N(npcGroupList_80246ED4) = {
    NPC_GROUP(N(npcGroup_80246090)),
    NPC_GROUP(N(npcGroup_80246280)),
    NPC_GROUP(N(npcGroup_80246470)),
    NPC_GROUP(N(npcGroup_80246660)),
    NPC_GROUP(N(npcGroup_80246A70), 0x0F04, 0x00),
    {},
};

NpcGroupList N(npcGroupList_80246F1C) = {
    NPC_GROUP(N(npcGroup_80246090)),
    NPC_GROUP(N(npcGroup_80246280)),
    NPC_GROUP(N(npcGroup_80246470)),
    NPC_GROUP(N(npcGroup_80246660)),
    NPC_GROUP(N(npcGroup_80246C60), 0x0F04, 0x00),
    {},
};

const char N(dgb_08_name_hack)[] = "dgb_08";
