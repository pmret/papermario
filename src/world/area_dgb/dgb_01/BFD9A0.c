#include "dgb_01.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_tubba.h"
#include "message_ids.h"

EntryList N(entryList) = {
    {    0.0f,   0.0f, 485.0f,   0.0f },
    { -485.0f,   0.0f,   0.0f,  90.0f },
    {  485.0f,   0.0f,   0.0f, 270.0f },
    { -485.0f, 210.0f,   0.0f,  90.0f },
    {  485.0f, 210.0f,   0.0f, 270.0f },
    { -485.0f, 420.0f,   0.0f,  90.0f },
    {  485.0f, 420.0f,   0.0f, 270.0f },
};

MapConfig N(config) = {
    .main = &N(main),
    .entryList = &N(entryList),
    .entryCount = ENTRY_COUNT(N(entryList)),
    .tattle = { MSG_dgb_01_tattle },
};

EvtSource N(802434A0) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
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

EvtSource N(exitDoubleDoor_80243550) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 0)
    EVT_SET(EVT_VAR(1), 4)
    EVT_SET(EVT_VAR(2), 54)
    EVT_SET(EVT_VAR(3), 57)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_00", 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80243604) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 1)
    EVT_SET(EVT_VAR(1), 8)
    EVT_SET(EVT_VAR(2), 34)
    EVT_SET(EVT_VAR(3), 36)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_02", 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_802436B8) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 2)
    EVT_SET(EVT_VAR(1), 20)
    EVT_SET(EVT_VAR(2), 41)
    EVT_SET(EVT_VAR(3), 39)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_08", 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_8024376C) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 3)
    EVT_SET(EVT_VAR(1), 12)
    EVT_SET(EVT_VAR(2), 29)
    EVT_SET(EVT_VAR(3), 31)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_09", 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80243820) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 4)
    EVT_SET(EVT_VAR(1), 24)
    EVT_SET(EVT_VAR(2), 46)
    EVT_SET(EVT_VAR(3), 44)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_08", 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_802438D4) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 5)
    EVT_SET(EVT_VAR(1), 16)
    EVT_SET(EVT_VAR(2), 24)
    EVT_SET(EVT_VAR(3), 26)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_17", 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(exitDoubleDoor_80243988) = {
    EVT_SET_GROUP(27)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, 3)
    EVT_SET(EVT_VAR(0), 6)
    EVT_SET(EVT_VAR(1), 28)
    EVT_SET(EVT_VAR(2), 51)
    EVT_SET(EVT_VAR(3), 49)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT_FRAMES(17)
    EVT_CALL(GotoMap, "dgb_18", 0)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(enterDoubleDoor_80243A3C) = {
    EVT_CALL(UseDoorSounds, 3)
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_IF_EQ(EVT_SAVE_FLAG(1041), 0)
                EVT_SET(EVT_SAVE_FLAG(1041), 1)
                EVT_SET(EVT_SAVE_VAR(0), -32)
            EVT_END_IF
            EVT_SET(EVT_VAR(2), 54)
            EVT_SET(EVT_VAR(3), 57)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(1)
            EVT_SET(EVT_VAR(2), 34)
            EVT_SET(EVT_VAR(3), 36)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(2)
            EVT_SET(EVT_VAR(2), 41)
            EVT_SET(EVT_VAR(3), 39)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(3)
            EVT_SET(EVT_VAR(2), 29)
            EVT_SET(EVT_VAR(3), 31)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(4)
            EVT_SET(EVT_VAR(2), 46)
            EVT_SET(EVT_VAR(3), 44)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(5)
            EVT_SET(EVT_VAR(2), 24)
            EVT_SET(EVT_VAR(3), 26)
            EVT_EXEC_WAIT(EnterDoubleDoor)
        EVT_CASE_EQ(6)
            EVT_SET(EVT_VAR(2), 51)
            EVT_SET(EVT_VAR(3), 49)
            EVT_EXEC_WAIT(EnterDoubleDoor)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(itemList_80243C40)[] = {
    ITEM_TUBBA_CASTLE_KEY,
    ITEM_NONE,
};

EvtSource N(main) = {
    EVT_SET(EVT_SAVE_VAR(425), 15)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_SET(EVT_SAVE_FLAG(1978), 1)
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_EXEC(N(802449C4))
    EVT_EXEC(N(802434A0))
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243550), TRIGGER_WALL_PRESS_A, 4, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243604), TRIGGER_WALL_PRESS_A, 8, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_8024376C), TRIGGER_WALL_PRESS_A, 12, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243820), TRIGGER_WALL_PRESS_A, 24, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802438D4), TRIGGER_WALL_PRESS_A, 16, 1, 0)
    EVT_BIND_TRIGGER(N(exitDoubleDoor_80243988), TRIGGER_WALL_PRESS_A, 28, 1, 0)
    EVT_IF_EQ(EVT_SAVE_FLAG(1040), 0)
        EVT_BIND_PADLOCK(N(80244AD0), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(itemList_80243C40)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(N(exitDoubleDoor_802436B8), TRIGGER_WALL_PRESS_A, 20, 1, 0)
    EVT_END_IF
    EVT_SWITCH(EVT_SAVE_VAR(0))
        EVT_CASE_LT(-29)
            EVT_CALL(MakeNpcs, 1, EVT_PTR(N(npcGroupList_80246E50)))
        EVT_CASE_LT(-16)
            EVT_CALL(GetEntryID, EVT_VAR(0))
            EVT_SWITCH(EVT_VAR(0))
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

EvtSource N(80243EF0) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_IF_LT(EVT_VAR(0), 100)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(func_80240000_BFD880))
    EVT_CALL(InitAnimatedModels)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(SetPlayerAnimation, 524298)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_WAIT_FRAMES(5)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_THREAD
        EVT_LOOP(12)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_WAIT_FRAMES(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 0, 0, 60, EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, 0, 400, 420, 0)
    EVT_CALL(SetPanTarget, 0, 400, 420, 0)
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(450.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(20.0), EVT_FIXED(-11.0))
    EVT_CALL(SetCamPosB, 0, EVT_FIXED(500.0), EVT_FIXED(0.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(3.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_SET(EVT_SAVE_VAR(203), 1)
    EVT_CALL(SetNpcVar, 4, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcVar, 4, 0, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), -50)
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(750.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(0.0), EVT_FIXED(3.0))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FIXED(1.0))
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(D_80252F4C_C107CC)))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(N(D_802539A0_C11220)))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, 0, 1)
    EVT_THREAD
        EVT_CALL(PlaySound, 0x95)
        EVT_WAIT_FRAMES(60)
        EVT_CALL(PlaySound, 0x96)
        EVT_WAIT_FRAMES(25)
        EVT_CALL(PlaySound, 0x98)
        EVT_WAIT_FRAMES(70)
        EVT_CALL(PlaySound, 0x97)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(100)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT_FRAMES(50)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT_FRAMES(70)
        EVT_CALL(PlaySound, 0xA8)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySound, 0xA8)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetGroupEnabled, 100, 0)
        EVT_CALL(SetGroupEnabled, 111, 0)
        EVT_CALL(SetPlayerAnimation, 524307)
        EVT_CALL(SetPlayerJumpscale, EVT_FIXED(0.5))
        EVT_CALL(PlayerJump1, 121, 210, 0, 60)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetPlayerAnimation, 524319)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetPlayerAnimation, ANIM_RUN_PANIC)
        EVT_CALL(SetPlayerSpeed, EVT_FIXED(8.0))
        EVT_CALL(PlayerMoveTo, 412, -29, 0)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(SetPlayerAnimation, ANIM_10002)
        EVT_CALL(ModifyColliderFlags, 1, 50, 0x7FFFFE00)
        EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_SUB(EVT_VAR(1), 210)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FIXED(0.5))
        EVT_CALL(NpcJump1, NPC_PARTNER, 151, EVT_VAR(1), 0, 60)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(ShakeCam, 0, 0, 300, EVT_FIXED(1.0))
    EVT_CALL(StopSound, 0x8000005D)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_D)
        EVT_CALL(SetNpcSpeed, 4, EVT_FIXED(3.0))
        EVT_CALL(NpcMoveTo, 4, 176, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.3))
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.15))
        EVT_WAIT_FRAMES(8)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_SET(EVT_SAVE_VAR(0), -28)
    EVT_CALL(SetGroupEnabled, 210, 1)
    EVT_CALL(DeleteAnimatedModel, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_D)
        EVT_CALL(SetNpcPos, 4, 137, 244, 35)
        EVT_CALL(SetNpcSpeed, 4, EVT_FIXED(3.0))
        EVT_CALL(NpcMoveTo, 4, 470, 0, 0)
        EVT_CALL(ShakeCam, 0, 0, 10, EVT_FIXED(3.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(0.3))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtNpc, 4, SOUND_20F6, 0)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(0.15))
            EVT_WAIT_FRAMES(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerSpeed, EVT_FIXED(3.0))
    EVT_CALL(PlayerMoveTo, 470, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC(N(exitDoubleDoor_80243820))
    EVT_RETURN
    EVT_END
};

EvtSource N(802449C4) = {
    EVT_SWITCH(EVT_SAVE_VAR(0))
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

EvtSource N(80244AD0) = {
    EVT_SET_GROUP(0)
    EVT_SUSPEND_GROUP(1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00D8), 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, EVT_VAR(0))
    EVT_CALL(RemoveKeyItemAt, EVT_VAR(0))
    EVT_CALL(CloseChoicePopup)
    EVT_SET(EVT_SAVE_FLAG(1040), 1)
    EVT_CALL(N(GetEntityPosition), EVT_MAP_VAR(0), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PlaySoundAt, 0x269, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(0), EVT_MAP_VAR(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_RESUME_GROUP(1)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80244C38) = {
    EVT_BIND_TRIGGER(N(exitDoubleDoor_802436B8), TRIGGER_WALL_PRESS_A, 20, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_IF_EQ(EVT_SAVE_FLAG(1040), 0)
        EVT_CALL(MakeEntity, 0x802BCD68, 490, 8, 0, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80244C38)))
        EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

f32 N(D_80244CD0_C02550)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

EvtSource N(80244CE8) = {
    EVT_CALL(SetSelfEnemyFlagBits, ((NPC_FLAG_MOTION_BLUR | NPC_FLAG_1000000 | NPC_FLAG_SIMPLIFIED_PHYSICS | NPC_FLAG_PARTICLE | NPC_FLAG_8000000 | NPC_FLAG_10000000 | NPC_FLAG_20000000)), TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT)), TRUE)
    EVT_RETURN
    EVT_END
};

NpcAISettings N(npcAISettings_80244D24) = {
    .moveSpeed = 1.5f,
    .moveTime = 90,
    .waitTime = 30,
    .alertRadius = 240.0f,
    .unk_14 = 1,
    .chaseSpeed = 5.3f,
    .unk_1C = { .s = 180 },
    .unk_20 = 1,
    .chaseRadius = 240.0f,
    .unk_2C = 1,
};

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_EQUIVALENT
// second npc_raycast_down_sides call
void N(func_802402D0_BFDB50)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f24;
    f32 posX, posY, posZ, posW;
    s32 var;
    f32 temp_f0;
    f32 phi_f4;
    s32 phi_v0;
    s32 phi_s4 = 0;

    f32 a = enemy->varTable[7];
    f32 temp_f2  = a / 100.0;
    f32 b = enemy->varTable[3];
    f32 temp_f26 = b / 100.0;
    f32 c = enemy->varTable[4];
    f32 temp_f20 = c / 100.0;
    f32 d = enemy->varTable[1];
    f32 temp_f22 = d / 100.0;

    enemy->varTable[4] = npc->pos.y * 100.0;
    temp_f24 = temp_f26 + temp_f2;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & 8) {
            if (temp_f22 < (temp_f24 - npc->pos.y)) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            if (temp_f22 < (temp_f26 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        if (npc->flags & 8) {
            phi_f4 = temp_f24;
            test = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            npc->pos.y = test;
        } else {
            posX = npc->pos.x;
            posY = temp_f20;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
            phi_f4 = posY;
            phi_f4 += temp_f26;
            d = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
            test = d;
            npc->pos.y = test;
            //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);
        }
        //npc->pos.y = temp_f20 + ((phi_f4 - temp_f20) * 0.09);

        if (fabsf(phi_f4 - npc->pos.y) < 1.0) {
            npc->pos.y = phi_f4;
            enemy->varTable[0] &= ~0x10;
        }
    } else if (enemy->varTable[1] > 0) {
        temp_f0 = sin_deg(enemy->varTable[2]);
        if (npc->flags & 8) {
            phi_v0 = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            phi_v0 = npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        }
        if (phi_v0) {
            npc->pos.y = posY + temp_f26 + (temp_f0 * temp_f22);
        } else {
            npc->pos.y = temp_f24 + (temp_f0 * temp_f22);
        }
        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->unk_14 >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->unk_14;
                if ((gPlayerStatusPtr->position.y < ((npc->pos.y + npc->collisionHeight) + 10.0)) &&
                    func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                    fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    if (enemy->npcSettings->unk_2A & 1) {
                        script->functionTemp[0] = 10;
                    } else {
                        script->functionTemp[0] = 12;
                    }
                    return;
                }
            }
            script->functionTemp[1]--;
        }
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.point.x, enemy->territory->wander.point.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        posW = dist2D(enemy->territory->wander.point.x, enemy->territory->wander.point.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
            phi_s4 = 1;
        }
    }

    if (enemy->territory->wander.wanderSizeX | enemy->territory->wander.wanderSizeZ | phi_s4) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            return;
        }
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->functionTemp[0] = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->waitTime <= 0) || (script->functionTemp[1] < 3)) {
                script->functionTemp[0] = 0;
            }
        }
    }
}
#else
INCLUDE_ASM(void, "world/area_dgb/dgb_01/BFD9A0", dgb_01_func_802402D0_BFDB50, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_80240D74_BFE5F4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80244CD0_C02550)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_8024142C_BFECAC)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
        case 1:
            N(func_802402D0_BFDB50)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240D74_BFE5F4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

void N(func_80241618_BFEE98)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 temp_f0;
    f32 phi_f20;

    npc->duration--;
    if (npc->duration <= 0) {
        npc->flags &= ~0x00200000;
        npc->duration = aiSettings->unk_20 / 2 + rand_int(aiSettings->unk_20 / 2 + 1);
        npc->currentAnim.w = enemy->animList[8];
        npc->moveSpeed = aiSettings->chaseSpeed;
        phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        temp_f0 = get_clamped_angle_diff(npc->yaw, phi_f20);
        if (aiSettings->unk_1C.s < fabsf(temp_f0)) {
            phi_f20 = npc->yaw;
            if (temp_f0 < 0.0f) {
                phi_f20 += -aiSettings->unk_1C.s;
            } else {
                phi_f20 += aiSettings->unk_1C.s;
            }
        }
        npc->yaw = clamp_angle(phi_f20);
        script->functionTemp[0] = 13;
    }
}

void N(func_80241770_BFEFF0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                   gPlayerStatusPtr->position.z) <= (npc->moveSpeed * 2.5)) {
            npc->duration = 0;
            script->functionTemp[0] = 14;
        } else {
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags |= 0x200000;
                script->functionTemp[0] = 12;
            }
        }
    } else {
        script->functionTemp[0] = 16;
    }

}

void N(func_80241874_BFF0F4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i != npc->npcID && (get_enemy(i)->varTable[0] & 0x100)) {
            return;
        }
    }

    enemy->varTable[0] |= 0x100;
    npc->pos.x = gPlayerStatusPtr->position.x;
    npc->pos.z = gPlayerStatusPtr->position.z;
    if (!(enemy->varTable[0] & 0x1000)) {
        enemy->varTable[0] |= 0x1000;
    }

    sfx_play_sound_at_position(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->duration = 0;
    script->functionTemp[0] = 15;
}

void N(func_80241954_BFF1D4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    s32 temp_f8_2;

    sfx_adjust_env_sound_pos(0x80000011, 2, npc->pos.x, npc->pos.y, npc->pos.z);
    if (!func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1)) {
        enemy->varTable[0] &= ~0x100;
        npc->rotation.y = 0.0f;
        npc->flags &= ~0x00200000;
        script->functionTemp[0] = 16;
    } else {
        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z + 2.0f;
        npc->rotation.y += 25.0f;
        if (npc->rotation.y > 360.0) {
            npc->rotation.y -= 360.0;
        }
        temp_f8_2 = 255.0f - (cosine((s32)npc->rotation.y % 180) * 56.0f);
        func_802DE894(npc->spriteInstanceID, 6, temp_f8_2, temp_f8_2, temp_f8_2, 255, 0);

        posX = gPlayerStatusPtr->position.x;
        posY = gPlayerStatusPtr->position.y;
        posZ = gPlayerStatusPtr->position.z;
        posW = 1000.0f;
        npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
        if (fabsf(npc->pos.y - posY) > 24.0) {
            npc->pos.y -= 1.8;
        } else {
            npc->rotation.y = 0.0f;
            npc->flags &= ~0x00200000;
            if (gPartnerActionStatus.actionState.b[3]  != 9) {
                disable_player_input();
                partner_disable_input();
                npc->duration = 0;
                script->functionTemp[0] = 20;
            } else {
                script->functionTemp[0] = 16;
            }
        }
    }
}

void N(func_80241BF0_BFF470)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
    if (enemy->varTable[0] & 0x1000) {
        sfx_stop_sound(0x80000011);
        enemy->varTable[0] &= ~0x1000;
    }
    npc->currentAnim.w = enemy->animList[9];
    npc->duration = 20;
    script->functionTemp[0] = 17;
}

void N(func_80241CA8_BFF528)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 tmp = enemy->varTable[3];
    f32 temp_f20 = tmp / 100.0;
    s32 var;

    npc->pos.y += 2.5;
    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    posW = 1000.0f;
    npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW);
    if (!(npc->pos.y < (posY + temp_f20))) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc->pos.y = posY + temp_f20;
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &var);
        npc->duration = 10;
        script->functionTemp[0] = 18;
    }
}

void N(func_80241E28_BFF6A8)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 30;
    }
}

void N(func_80241E70_BFF6F0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration >= 3) {
        if (gPartnerActionStatus.actionState.b[3]  != 9) {
            npc->duration = 0;
            script->functionTemp[0] = 100;
        } else {
            enable_player_input();
            partner_enable_input();
            script->functionTemp[0] = 16;
        }
    }
}

void N(func_80241EF0_BFF770)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] &= ~0x100;
    npc->flags &= ~0x00200000;
    npc->moveSpeed = 2.0 * aiSettings->moveSpeed;
    enemy->varTable[2] = 0;
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[1] = 0x1E;
}

void N(func_80241F98_BFF818)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX = npc->pos.x;
    f32 posY = npc->pos.y;
    f32 posZ = npc->pos.z;
    f32 posW = 1000.0f;
    f32 temp_f26 = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f24 = temp_f26 + (f32)((f32)enemy->varTable[7] / 100.0);
    f32 temp_f22 = (f32)enemy->varTable[1] / 100.0;
    f32 temp_f20 = sin_deg(enemy->varTable[2]);
    s32 var;
    s32 var2;

    if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
        npc->pos.y = posY + temp_f26 + (temp_f20 * temp_f22);
    } else {
        npc->pos.y = temp_f24 + (temp_f20 * temp_f22);
    }

    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (func_800490B4(territory, enemy, aiSettings->alertRadius * 0.5, aiSettings->unk_10.f * 0.5, 0)) {
            fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            ai_enemy_play_sound(npc, 0x2F4, 0x200000);
            npc->moveToPos.y = npc->pos.y;
            script->functionTemp[0] = 12;
            return;
        }
    }

    script->functionTemp[1]--;
    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        posW = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        if (posW <= (2.0f * npc->moveSpeed)) {
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            script->functionTemp[0] = 2;
        }
    }
}

ApiStatus N(func_802422B0_BFFB30)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 125.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        N(UnkFunc5)(npc, enemy, script, aiSettings);
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc23)(script, aiSettings, territoryPtr);
            func_802DE894(npc->spriteInstanceID, 0, 0, 0, 0, 0, 0);
        case 1:
            N(func_802402D0_BFDB50)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] == 12) {
                npc->duration = 6;
            }
            break;
        case 12:
            N(func_80241618_BFEE98)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(func_80241770_BFEFF0)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241874_BFF0F4)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 15) {
                break;
            }
        case 15:
            N(func_80241954_BFF1D4)(script, aiSettings, territoryPtr);
            break;
        case 16:
            N(func_80241BF0_BFF470)(script, aiSettings, territoryPtr);
        case 17:
            N(func_80241CA8_BFF528)(script, aiSettings, territoryPtr);
            break;
        case 18:
            N(func_80241E28_BFF6A8)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(func_80241E70_BFF6F0)(script, aiSettings, territoryPtr);
            break;
        case 30:
            N(func_80241EF0_BFF770)(script, aiSettings, territoryPtr);
        case 31:
            N(func_80241F98_BFF818)(script, aiSettings, territoryPtr);
    }

    return (script->functionTemp[0] == 100) * ApiStatus_DONE2;
}

const char N(dgb_00_name_hack)[];

EvtSource N(npcAI_80244D54) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(func_802422B0_BFFB30), EVT_PTR(N(npcAISettings_80244D24)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(2)
    EVT_LABEL(20)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(3), EVT_VAR(4), EVT_VAR(5))
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(4), EVT_VAR(2))
    EVT_CALL(GetPlayerActionState, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(func_802D2B6C)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_ADD(EVT_VAR(2), 2)
    EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80045838, -1, 759, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80045838, -1, 1838, 0)
    EVT_THREAD
        EVT_LOOP(100)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x108)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetNpcPos, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(NpcJump0, NPC_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GotoMap, N(dgb_00_name_hack), 2)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(8024517C) = {
    EVT_CALL(GetOwnerEncounterTrigger, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, EVT_VAR(0))
            EVT_EXEC_WAIT(0x800936DC)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(80245208) = {
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
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

NpcAISettings N(npcAISettings_80245298) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .unk_10 = { .f = 90.0f },
    .unk_14 = 1,
    .chaseSpeed = 3.9f,
    .unk_1C = { .s = 180 },
    .unk_20 = 2,
    .chaseRadius = 170.0f,
    .unk_28 = { .f = 90.0f },
    .unk_2C = 1,
};

EvtSource N(npcAI_802452C8) = {
    EVT_CALL(N(func_802430C0_C00940), EVT_PTR(N(npcAISettings_80245298)))
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

EvtSource N(idle_8024536C) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_SAVE_VAR(203), 1)
    EVT_CALL(PlaySoundAtCollider, 28, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 49, EVT_VAR(0), 0, 1, 0)
        EVT_CALL(RotateModel, 51, EVT_VAR(0), 0, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_A)
    EVT_CALL(SetNpcPos, NPC_SELF, 520, 420, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(NpcMoveTo, NPC_SELF, 390, 0, 30)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_7)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 49, EVT_VAR(0), 0, 1, 0)
            EVT_CALL(RotateModel, 51, EVT_VAR(0), 0, -1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 28, 456, 0)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 0, MESSAGE_ID(0x0E, 0x0101))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_19)
        EVT_WAIT_FRAMES(4)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1A)
        EVT_WAIT_FRAMES(17)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1B)
        EVT_WAIT_FRAMES(11)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1C)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_1D)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetNpcJumpscale, 4, EVT_FIXED(1.0))
    EVT_CALL(GetNpcPos, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(NpcJump0, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 30)
    EVT_CALL(PlaySoundAtNpc, 4, 0x20A0, 0)
    EVT_CALL(PlaySound, 0x8000005D)
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FIXED(4.0))
    EVT_CALL(ShakeCam, 0, 0, 15, EVT_FIXED(2.0))
    EVT_CALL(SetSelfVar, 0, 3)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245784) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024536C)))
    EVT_RETURN
    EVT_END
};

const char N(dgb_00_name_hack)[] = "dgb_00";

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1_copy.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

ApiStatus N(func_802430C0_C00940)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc24)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkFunc13)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1_copy)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc14)(script, aiSettings, territoryPtr);
            break;
        case 4:
            N(UnkNpcAIFunc25)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkFunc15)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(UnkFunc16)(script, aiSettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }

    return ApiStatus_BLOCK;
}

#include "world/common/UnkFunc1.inc.c"

const char N(dgb_08_name_hack)[];

EvtSource N(defeat_802457D8) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, N(dgb_08_name_hack), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245814) = {
    EVT_IF_NE(EVT_SAVE_VAR(203), 1)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(EVT_SAVE_VAR(0), -27)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, ((NPC_FLAG_4)), TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, 4, 137, 244, 35)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_802457D8)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(2.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8024598C) = {
    EVT_CALL(AwaitPlayerApproach, 0, 420, 400)
    EVT_SET(EVT_SAVE_VAR(203), 1)
    EVT_SET(EVT_SAVE_VAR(0), -26)
    EVT_CALL(PlaySoundAtCollider, 20, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, 39, EVT_VAR(0), 0, -1, 0)
        EVT_CALL(RotateModel, 41, EVT_VAR(0), 0, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_SELF, 555, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_world_tubba_Palette_00_Anim_A)
    EVT_CALL(NpcMoveTo, NPC_SELF, 426, 0, 30)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 39, EVT_VAR(0), 0, -1, 0)
            EVT_CALL(RotateModel, 41, EVT_VAR(0), 0, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 20, 456, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 5, EVT_FIXED(2.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_20F6, 4194304)
            EVT_CALL(ShakeCam, 0, 0, 2, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FIXED(5.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 259, 167, 0)
    EVT_CALL(N(func_802430C0_C00940), EVT_PTR(N(npcAISettings_80245298)))
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_80245CB4) = {
    EVT_CALL(N(UnkFunc1))
    EVT_CALL(GotoMap, N(dgb_00_name_hack), 1)
    EVT_WAIT_FRAMES(100)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245CF0) = {
    EVT_IF_NE(EVT_SAVE_VAR(203), 1)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_8024598C)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, 136, 0, -330)
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80245CB4)))
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FIXED(1.25), EVT_FIXED(1.25), EVT_FIXED(1.25))
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245D80) = {
    EVT_SET(EVT_VAR(0), EVT_SAVE_VAR(0))
    EVT_IF_GE(EVT_VAR(0), -29)
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

EvtSource N(init_80245E44) = {
    EVT_SET(EVT_VAR(0), EVT_SAVE_VAR(0))
    EVT_IF_GE(EVT_VAR(0), -29)
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

EvtSource N(init_80245F08) = {
    EVT_SET(EVT_VAR(0), EVT_SAVE_VAR(0))
    EVT_IF_GE(EVT_VAR(0), -29)
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

EvtSource N(init_80245FCC) = {
    EVT_SET(EVT_VAR(0), EVT_SAVE_VAR(0))
    EVT_IF_GE(EVT_VAR(0), -29)
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245D80),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245E44),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 180, 100, 230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245F08),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { -180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245FCC),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .movement = { 180, 100, -230, 35, 0, -32767, 0, 0, 0, 0, 450, 1000, 1, 1 },
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
    ANIM_END,
};

StaticNpc N(npcGroup_80246880) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_80245314),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245784),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
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
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 2,
    .maxCoinBonus = 3,
    .movement = { 2, 320, 210, 0, 370, 210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -32767, 350, 210, 0, 1000, 250, 1 },
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
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    .extraAnimations = N(extraAnimationList_80246850),
};

StaticNpc N(npcGroup_80246C60) = {
    .id = NPC_WORLD_TUBBA,
    .settings = &N(npcSettings_802452E8),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_200000,
    .init = &N(init_80245CF0),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 5,
    .itemDrops = {
        { ITEM_SUPER_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(3),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .minCoinBonus = 2,
    .maxCoinBonus = 3,
    .movement = { 8, 156, 0, 187, -36, 0, 290, -159, 0, 50, -80, 0, -218, 66, 0, -362, 196, 0, -268, 280, 0, -124, 250, 0, 100, 0, 0, 0, 0, 0, 0, -32767, 250, 0, 100, 1000, 250, 1 },
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
    .unk_1E0 = { 00, 00, 00, 02, 00, 00, 00, 00},
    .extraAnimations = N(extraAnimationList_80246850),
};

NpcGroupList N(npcGroupList_80246E50) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80246E8C) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246880), BATTLE_ID(15, 4, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_80246ED4) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246A70), BATTLE_ID(15, 4, 0, 1)),
    {},
};

NpcGroupList N(npcGroupList_80246F1C) = {
    NPC_GROUP(N(npcGroup_80246090), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246280), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246470), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246660), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246C60), BATTLE_ID(15, 4, 0, 1)),
    {},
};

const char N(dgb_08_name_hack)[] = "dgb_08";
