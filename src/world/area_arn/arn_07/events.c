#include "arn_07.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/world_skolar.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/bootler.h"

EvtSource N(80243790) = {
    EVT_EXEC(N(802437AC))
    EVT_RETURN
    EVT_END
};

EvtSource N(802437AC) = {
    EVT_SETF(EVT_VAR(0), EVT_FIXED(0.0))
    EVT_SET(EVT_VAR(1), 30)
    EVT_CALL(PlaySoundAtModel, 23, 0x8000004A, 0)
    EVT_LABEL(0)
    EVT_ADDF(EVT_VAR(0), EVT_FIXED(1.0))
    EVT_CALL(N(func_80240800_BED5F0))
    EVT_CALL(RotateModel, 27, EVT_VAR(0), 0, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_SUB(EVT_VAR(1), 1)
    EVT_IF_GT(EVT_VAR(1), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(EVT_VAR(1), 30)
    EVT_CALL(RandInt, 100, EVT_VAR(2))
    EVT_IF_GT(EVT_VAR(2), 10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SETF(EVT_VAR(2), EVT_FIXED(1.0))
    EVT_LOOP(50)
        EVT_SUBF(EVT_VAR(2), EVT_FIXED(0.01))
        EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
        EVT_CALL(RotateModel, 27, EVT_VAR(0), 0, 0, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADDF(EVT_VAR(2), EVT_FIXED(0.01))
        EVT_ADDF(EVT_VAR(0), EVT_VAR(2))
        EVT_CALL(RotateModel, 27, EVT_VAR(0), 0, 0, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_SET(EVT_VAR(1), 30)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(802439B0) = {
    EVT_SET_GROUP(0)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00D8), 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_MYSTICAL_KEY, EVT_VAR(0))
    EVT_CALL(RemoveKeyItemAt, EVT_VAR(0))
    EVT_CALL(CloseChoicePopup)
    EVT_SET(EVT_SAVE_VAR(0), -24)
    EVT_CALL(N(GetEntityPosition), EVT_MAP_VAR(0), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PlaySoundAt, 0x269, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(0), EVT_MAP_VAR(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtSource N(80243B28) = {
    EVT_BIND_TRIGGER(N(exitSingleDoor_802428D4), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(makeEntities) = {
    EVT_IF_LT(EVT_SAVE_VAR(0), -24)
        EVT_CALL(MakeEntity, 0x802BCD68, 10, 30, -155, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80243B28)))
        EVT_SET(EVT_MAP_VAR(0), EVT_VAR(0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

f32 N(D_80243BC0_BF09B0)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

NpcAISettings N(npcAISettings_80243BD8) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .unk_14 = 3,
    .chaseSpeed = 4.0f,
    .unk_1C = { .s = 5 },
    .unk_20 = 1,
    .chaseRadius = 150.0f,
    .unk_2C = 1,
};

EvtSource N(npcAI_80243C08) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(func_80241C5C_BEEA4C), EVT_PTR(N(npcAISettings_80243BD8)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243C78) = {
    .height = 18,
    .radius = 20,
    .ai = &N(npcAI_80243C08),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 12,
    .unk_2A = 1,
};

EvtSource N(80243CA4) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(80243CB4) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(npcSettings_80243CC4) = {
    .height = 24,
    .radius = 24,
    .otherAI = &N(80243CA4),
    .onDefeat = &N(80243CB4),
    .level = 13,
};

NpcSettings N(npcSettings_80243CF0) = {
    .height = 90,
    .radius = 65,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 13,
};

NpcSettings N(npcSettings_80243D1C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80243D48) = {
    .height = 26,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_80243D74) = {
    .height = 20,
    .radius = 20,
    .level = 99,
};

NpcSettings N(npcSettings_80243DA0) = {
    .height = 22,
    .radius = 24,
    .level = 99,
};

EvtSource N(80243DCC) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, 1, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 3, EVT_FIXED(0.8))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80243E24) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetPanTarget, 0, 250, 0, -46)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_8)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 5, MESSAGE_ID(0x0E, 0x00CA))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 5, MESSAGE_ID(0x0E, 0x00CB))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(2.0))
    EVT_CALL(SetCamPitch, 0, EVT_FIXED(5.0), EVT_FIXED(-16.0))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_RETURN
    EVT_END
};

EvtSource N(80243FE8) = {
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_22)
    EVT_WAIT_FRAMES(15)
    EVT_LOOP(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 3, 0, 1)
        EVT_WAIT_FRAMES(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 6, 0, 1)
        EVT_WAIT_FRAMES(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 2, 0, 1)
        EVT_WAIT_FRAMES(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 4, 0, 1)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 5, 0, 1)
        EVT_WAIT_FRAMES(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 7, 0, 1)
        EVT_WAIT_FRAMES(6)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_23)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_22)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
    EVT_CALL(SetNpcVar, 3, 0, 1)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_21)
    EVT_WAIT_FRAMES(45)
    EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 50)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 0, MESSAGE_ID(0x0E, 0x00CC))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
        EVT_LOOP(40)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_802CF56C, 2)
        EVT_LOOP(45)
            EVT_CALL(PlayerFaceNpc, -1, 1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(80243DCC), EVT_VAR(10))
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 800)
    EVT_CALL(NpcMoveTo, NPC_SELF, EVT_VAR(0), EVT_VAR(2), 80)
    EVT_KILL_THREAD(EVT_VAR(10))
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_SET(EVT_SAVE_VAR(0), -16)
    EVT_CALL(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EVT_CALL(GetCurrentPartnerID, EVT_VAR(6))
    EVT_IF_EQ(EVT_VAR(6), 9)
        EVT_SET(EVT_VAR(5), -4)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 257, 25, 0)
    EVT_END_IF
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 30)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_WAIT_FRAMES(10)
    EVT_IF_NE(EVT_VAR(6), 9)
        EVT_SET(EVT_VAR(5), 8)
        EVT_CALL(SetNpcPos, 8, 257, 25, 0)
        EVT_CALL(func_802CFD30, 8, 7, 0, 0, 0, 0)
        EVT_CALL(NpcFacePlayer, 8, 0)
        EVT_CALL(MakeLerp, 0, 240, 20, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 8, 7, EVT_VAR(0), 0, 0, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_802CF56C, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 8, 0)
            EVT_WAIT_FRAMES(5)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00CD))
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetNpcPos, EVT_VAR(5), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), -20)
    EVT_CALL(SetCamProperties, 0, EVT_FIXED(2.0), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_FIXED(300.0), EVT_FIXED(15.0), EVT_FIXED(-7.0))
    EVT_CALL(PlayerFaceNpc, EVT_VAR(5), 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SpeakToPlayer, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00CE))
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(ContinueSpeech, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00CF))
    EVT_ELSE
        EVT_CALL(ContinueSpeech, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00D0))
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00D1))
    EVT_CALL(UseSettingsFrom, 0, 175, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(SetPanTarget, 0, 175, 0, 0)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(SetNpcPos, 9, 93, 160, -6)
    EVT_CALL(InterpNpcYaw, 9, 90, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 160, 31, 70, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, 9, 93, EVT_VAR(0), -6)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, EVT_VAR(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00D2))
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_EXEC(N(80242048))
    EVT_WAIT_FRAMES(20)
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(6), 9)
            EVT_CALL(MakeLerp, 240, 0, 20, 0)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 8, 7, EVT_VAR(0), 0, 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(EVT_VAR(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetNpcPos, 8, 0, -1000, 0)
            EVT_CALL(EnablePartnerAI)
        EVT_ELSE
            EVT_WAIT_FRAMES(20)
            EVT_CALL(ClearPartnerMoveHistory, -4)
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
        EVT_WAIT_FRAMES(8)
        EVT_CALL(func_802CF56C, 2)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80244C54) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(StartBossBattle, 11)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80244CC8) = {
    EVT_LABEL(10)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, EVT_VAR(0))
        EVT_IF_EQ(EVT_VAR(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SETF(EVT_VAR(0), EVT_FIXED(0.5))
        EVT_CALL(MakeLerp, 50, 80, 15, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(EVT_VAR(2), EVT_VAR(0))
            EVT_DIVF(EVT_VAR(2), 100)
            EVT_CALL(SetNpcScale, NPC_SELF, EVT_VAR(2), EVT_VAR(2), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(RandInt, 80, EVT_VAR(2))
        EVT_CALL(RandInt, 10, EVT_VAR(3))
        EVT_ADD(EVT_VAR(3), 5)
        EVT_CALL(MakeLerp, EVT_VAR(2), 240, EVT_VAR(3), 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, NPC_SELF, 7, EVT_VAR(0), 0, 0, 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_SELF, 293, 59, 21)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FIXED(-0.3))
    EVT_CALL(RandInt, 100, EVT_VAR(3))
    EVT_SUB(EVT_VAR(0), EVT_VAR(3))
    EVT_ADD(EVT_VAR(1), 100)
    EVT_CALL(NpcJump0, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 20)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(defeat_80244FB8) = {
    EVT_CALL(SetEncounterStatusFlags, 2, 1)
    EVT_CALL(GetBattleOutcome, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetMusicTrack, 0, SONG_TUBBAS_MANOR, 1, 8)
            EVT_EXEC_WAIT(N(80243E24))
            EVT_EXEC(N(80243FE8))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245058) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245090) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244C54)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244FB8)))
    EVT_IF_NE(EVT_SAVE_VAR(0), -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245104) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244CC8)))
    EVT_IF_NE(EVT_SAVE_VAR(0), -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245164) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8024519C) = {
    EVT_IF_NE(EVT_SAVE_VAR(0), -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(extraAnimationList_802451D4)[] = {
    NPC_ANIM_world_tubba_Palette_00_Anim_0,
    NPC_ANIM_world_tubba_Palette_00_Anim_22,
    NPC_ANIM_world_tubba_Palette_00_Anim_23,
    NPC_ANIM_world_tubba_Palette_00_Anim_6,
    NPC_ANIM_world_tubba_Palette_00_Anim_10,
    NPC_ANIM_world_tubba_Palette_00_Anim_8,
    NPC_ANIM_world_tubba_Palette_00_Anim_F,
    NPC_ANIM_world_tubba_Palette_00_Anim_12,
    ANIM_END,
};

s32 N(extraAnimationList_802451F8)[] = {
    NPC_ANIM_boo_Palette_00_Anim_0,
    ANIM_END,
};

s32 N(extraAnimationList_80245200)[] = {
    NPC_ANIM_boo_Palette_01_Anim_0,
    ANIM_END,
};

s32 N(extraAnimationList_80245208)[] = {
    NPC_ANIM_bootler_Palette_00_Anim_1,
    ANIM_END,
};

EvtSource N(idle_80245210) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtSource N(80245304) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), EVT_VAR(0))
    EVT_ADD(EVT_VAR(3), -50)
    EVT_SET(EVT_VAR(4), EVT_VAR(1))
    EVT_ADD(EVT_VAR(4), 26)
    EVT_CALL(SetNpcPos, 13, EVT_VAR(3), EVT_VAR(4), EVT_VAR(2))
    EVT_CALL(PlayerFaceNpc, 13, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 13, 0)
    EVT_ADD(EVT_VAR(0), -25)
    EVT_CALL(UseSettingsFrom, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(475.0))
    EVT_CALL(SetCamPitch, 0, 18, -8)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D3))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(300.0))
    EVT_CALL(SetCamPitch, 0, 18, -9)
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, 13, 0, EVT_VAR(0), 0)
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(EVT_VAR(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, 13, 0)
    EVT_CALL(SetNpcAnimation, 13, NPC_ANIM_world_skolar_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetPlayerAnimation, ANIM_GOT_ITEM)
    EVT_CALL(PlaySoundAtPlayer, 313, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SET(EVT_VAR(3), EVT_VAR(1))
    EVT_ADD(EVT_VAR(1), 50)
    EVT_ADD(EVT_VAR(2), 10)
    EVT_ADD(EVT_VAR(3), 30)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x11, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(6)
        EVT_CALL(PlayEffect, 0x11, 1, EVT_VAR(0), EVT_VAR(3), EVT_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(6)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySoundAtPlayer, 392, 0)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 20)
    EVT_CALL(PlayEffect, 0x52, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetNpcAnimation, 13, NPC_ANIM_world_skolar_Palette_00_Anim_1)
    EVT_CALL(EnableNpcAI, 13, 1)
    EVT_CALL(PostChapter3StatUpdate)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x0193), 160, 40)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetNpcPos, 13, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(250.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D4))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetPlayerPos, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), -25)
    EVT_CALL(SetPanTarget, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetCamDistance, 0, EVT_FIXED(300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FIXED(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FIXED(1.0))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D5))
    EVT_CALL(SetNpcFlagBits, 13, ((NPC_FLAG_40000)), TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, 13, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(PlayEffect, 0x11, 4, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_VAR(2), 0)
        EVT_SET(EVT_VAR(3), 1800)
        EVT_CALL(MakeLerp, EVT_VAR(2), EVT_VAR(3), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 13, 0, EVT_VAR(0), 0)
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, 13, EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
        EVT_SET(EVT_VAR(5), EVT_VAR(3))
        EVT_ADD(EVT_VAR(5), 180)
        EVT_CALL(MakeLerp, EVT_VAR(3), EVT_VAR(5), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, 13, EVT_VAR(2), EVT_VAR(0), EVT_VAR(4))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(EVT_VAR(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 13, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtNpc, 13, 0x2045, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPlayerAnimation, 65578)
    EVT_WAIT_FRAMES(90)
    EVT_CALL(ResetCam, 0, 3)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_SET(EVT_SAVE_VAR(0), -13)
    EVT_EXEC(N(80241F10))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_80245C9C) = {
    EVT_CALL(GetEntryID, EVT_VAR(0))
    EVT_IF_EQ(EVT_VAR(0), 3)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80245210)))
        EVT_EXEC(N(80245304))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80245D0C)[] = {
    {
        .id = NPC_WORLD_TUBBA,
        .settings = &N(npcSettings_80243CF0),
        .pos = { 309.0f, 0.0f, 11.0f },
        .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245090),
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
        .extraAnimations = N(extraAnimationList_802451D4),
    },
    {
        .id = NPC_TUBBAS_HEART,
        .settings = &N(npcSettings_80243CC4),
        .pos = { -10.0f, 50.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245058),
        .yaw = 90,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
            NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
        },
    },
};

StaticNpc N(npcGroup_802460EC)[] = {
    {
        .id = NPC_BOO0,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO1,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO2,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO3,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_2,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_1,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_0,
            NPC_ANIM_boo_Palette_01_Anim_A,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
            NPC_ANIM_boo_Palette_01_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_80245200),
    },
    {
        .id = NPC_BOO4,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_2,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_0,
            NPC_ANIM_boo_Palette_00_Anim_0,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_802451F8),
    },
    {
        .id = NPC_BOO5,
        .settings = &N(npcSettings_80243D1C),
        .pos = { 0.0f, -1000.0f, 0.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
        .animations = {
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_2,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_1,
            NPC_ANIM_boo_Palette_00_Anim_0,
            NPC_ANIM_boo_Palette_00_Anim_0,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
            NPC_ANIM_boo_Palette_00_Anim_3,
        },
        .extraAnimations = N(extraAnimationList_802451F8),
    },
};

StaticNpc N(npcGroup_80246C8C) = {
    .id = NPC_WORLD_BOW,
    .settings = &N(npcSettings_80243D1C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
    .init = &N(init_80245164),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_world_bow_Palette_00_Anim_1,
        NPC_ANIM_world_bow_Palette_00_Anim_2,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_1,
        NPC_ANIM_world_bow_Palette_00_Anim_1,
        NPC_ANIM_world_bow_Palette_00_Anim_0,
        NPC_ANIM_world_bow_Palette_00_Anim_0,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
        NPC_ANIM_world_bow_Palette_00_Anim_3,
    },
};

StaticNpc N(npcGroup_80246E7C) = {
    .id = NPC_BOOTLER,
    .settings = &N(npcSettings_80243D1C),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT | NPC_FLAG_200000,
    .init = &N(init_8024519C),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_bootler_Palette_00_Anim_1,
        NPC_ANIM_bootler_Palette_00_Anim_2,
        NPC_ANIM_bootler_Palette_00_Anim_3,
        NPC_ANIM_bootler_Palette_00_Anim_3,
        NPC_ANIM_bootler_Palette_00_Anim_1,
        NPC_ANIM_bootler_Palette_00_Anim_1,
        NPC_ANIM_bootler_Palette_00_Anim_0,
        NPC_ANIM_bootler_Palette_00_Anim_0,
        NPC_ANIM_bootler_Palette_00_Anim_5,
        NPC_ANIM_bootler_Palette_00_Anim_6,
        NPC_ANIM_bootler_Palette_00_Anim_7,
        NPC_ANIM_bootler_Palette_00_Anim_8,
        NPC_ANIM_bootler_Palette_00_Anim_5,
        NPC_ANIM_bootler_Palette_00_Anim_6,
        NPC_ANIM_bootler_Palette_00_Anim_7,
        NPC_ANIM_bootler_Palette_00_Anim_8,
    },
    .extraAnimations = N(extraAnimationList_80245208),
};

EvtSource N(init_8024706C) = {
    EVT_IF_GE(EVT_SAVE_VAR(0), -26)
        EVT_IF_LT(EVT_SAVE_VAR(0), -15)
            EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802470BC) = {
    .id = NPC_PARAGOOMBA0,
    .settings = &N(npcSettings_80243C78),
    .pos = { -216.0f, 60.0f, -10.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { -216, 60, -10, 30, 0, -32767, 0, -216, 60, -10, 250 },
    .animations = {
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_walk,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_attack,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_802472AC) = {
    .id = NPC_PARAGOOMBA1,
    .settings = &N(npcSettings_80243C78),
    .pos = { 0.0f, 60.0f, 150.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 270,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 0, 60, 150, 30, 0, -32767, 0, 0, 60, 150, 250 },
    .animations = {
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_walk,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_attack,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_8024749C) = {
    .id = NPC_PARAGOOMBA2,
    .settings = &N(npcSettings_80243C78),
    .pos = { 260.0f, 60.0f, 30.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_8024706C),
    .yaw = 90,
    .dropFlags = NPC_DROP_FLAGS_80,
    .itemDropChance = 20,
    .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
    .heartDrops = STANDARD_HEART_DROPS(2),
    .flowerDrops = STANDARD_FLOWER_DROPS(2),
    .maxCoinBonus = 2,
    .movement = { 260, 60, 30, 30, 0, -32767, 0, 260, 60, 30, 250 },
    .animations = {
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_walk,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_idle,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_pain,
        NPC_ANIM_paragoomba_hyper_attack,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
        NPC_ANIM_paragoomba_hyper_run,
    },
    .unk_1E0 = { 00, 00, 00, 01, 00, 00, 00, 00},
};

StaticNpc N(npcGroup_8024768C) = {
    .id = NPC_WORLD_SKOLAR,
    .settings = &N(npcSettings_80243D48),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_Y_MOVEMENT,
    .init = &N(init_80245C9C),
    .yaw = 0,
    .dropFlags = NPC_DROP_FLAGS_80,
    .heartDrops = NO_DROPS,
    .flowerDrops = NO_DROPS,
    .animations = {
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_0,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
        NPC_ANIM_world_skolar_Palette_00_Anim_1,
    },
};

NpcGroupList N(npcGroupList_8024787C) = {
    NPC_GROUP(N(npcGroup_80245D0C), BATTLE_ID(14, 16, 0, 2)),
    NPC_GROUP(N(npcGroup_802460EC), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246C8C), BATTLE_ID(0, 0, 0, 0)),
    NPC_GROUP(N(npcGroup_80246E7C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

NpcGroupList N(npcGroupList_802478B8) = {
    NPC_GROUP(N(npcGroup_802470BC), BATTLE_ID(14, 6, 0, 2)),
    NPC_GROUP(N(npcGroup_802472AC), BATTLE_ID(14, 7, 0, 2)),
    NPC_GROUP(N(npcGroup_8024749C), BATTLE_ID(14, 8, 0, 2)),
    {},
};

NpcGroupList N(npcGroupList_802478E8) = {
    NPC_GROUP(N(npcGroup_8024768C), BATTLE_ID(0, 0, 0, 0)),
    {},
};

#include "world/common/UnkNpcAIFunc23.inc.c"

#ifdef NON_EQUIVALENT
void N(func_80240B00_BED8F0)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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
INCLUDE_ASM(void, "world/area_arn/arn_07/events", arn_07_func_80240B00_BED8F0, Evt* script,
            NpcAISettings* aiSettings, EnemyTerritoryThing* territory);
#endif

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void N(func_802415A4_BEE394)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80243BC0_BF09B0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

ApiStatus N(func_80241C5C_BEEA4C)(Evt* script, s32 isInitialCall) {
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
            N(func_80240B00_BED8F0)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_802415A4_BEE394)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
        case 14:
            N(UnkFunc6)(script, aiSettings, territoryPtr);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus PostChapter3StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(3);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
