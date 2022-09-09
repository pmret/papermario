#include "arn_07.h"
#include "entity.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/paragoomba.h"
#include "sprite/npc/world_skolar.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/tubbas_heart.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/bootler.h"

EvtScript N(80243790) = {
    EVT_EXEC(N(802437AC))
    EVT_RETURN
    EVT_END
};

EvtScript N(802437AC) = {
    EVT_SETF(LocalVar(0), EVT_FLOAT(0.0))
    EVT_SET(LocalVar(1), 30)
    EVT_CALL(PlaySoundAtModel, 23, 0x8000004A, 0)
    EVT_LABEL(0)
    EVT_ADDF(LocalVar(0), EVT_FLOAT(1.0))
    EVT_CALL(N(func_80240800_BED5F0))
    EVT_CALL(RotateModel, 27, LocalVar(0), 0, 0, 1)
    EVT_WAIT(1)
    EVT_SUB(LocalVar(1), 1)
    EVT_IF_GT(LocalVar(1), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LocalVar(1), 30)
    EVT_CALL(RandInt, 100, LocalVar(2))
    EVT_IF_GT(LocalVar(2), 10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SETF(LocalVar(2), EVT_FLOAT(1.0))
    EVT_LOOP(50)
        EVT_SUBF(LocalVar(2), EVT_FLOAT(0.01))
        EVT_ADDF(LocalVar(0), LocalVar(2))
        EVT_CALL(RotateModel, 27, LocalVar(0), 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADDF(LocalVar(2), EVT_FLOAT(0.01))
        EVT_ADDF(LocalVar(0), LocalVar(2))
        EVT_CALL(RotateModel, 27, LocalVar(0), 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LocalVar(1), 30)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802439B0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x00D8), 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LocalVar(0), -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_MYSTICAL_KEY, LocalVar(0))
    EVT_CALL(RemoveKeyItemAt, LocalVar(0))
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, -24)
    EVT_CALL(N(GetEntityPosition), MapVar(0), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PlaySoundAt, 0x269, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(0), MapVar(0))
    EVT_CALL(N(SetEntityFlags100000))
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(80243B28) = {
    EVT_BIND_TRIGGER(N(exitSingleDoor_802428D4), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(makeEntities) = {
    EVT_IF_LT(GB_StoryProgress, -24)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 10, 30, -155, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(80243B28)))
        EVT_SET(MapVar(0), LocalVar(0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5f, 3.5f, 2.6f, 2.0f,
    1.5f, 20.0f,
};

MobileAISettings N(npcAISettings_80243BD8) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 4.0f,
    .chaseTurnRate= 5,
    .chaseUpdateInterval = 1,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(npcAI_80243C08) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(npcAISettings_80243BD8)))
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
    .actionFlags = 1,
};

EvtScript N(80243CA4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80243CB4) = {
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

EvtScript N(80243DCC) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, 1, SOUND_20F6, 0)
        EVT_CALL(ShakeCam, 0, 0, 3, EVT_FLOAT(0.8))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80243E24) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, 0, 250, 0, -46)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_8)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 5, MESSAGE_ID(0x0E, 0x00CA))
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 5, MESSAGE_ID(0x0E, 0x00CB))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(5.0), EVT_FLOAT(-16.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(80243FE8) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_22)
    EVT_WAIT(15)
    EVT_LOOP(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 3, 0, 1)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 6, 0, 1)
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 2, 0, 1)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 4, 0, 1)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 5, 0, 1)
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
        EVT_CALL(SetNpcVar, 7, 0, 1)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_23)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_22)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
    EVT_CALL(SetNpcVar, 3, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_21)
    EVT_WAIT(45)
    EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 50)
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_STAND_STILL)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, NPC_ANIM_world_tubba_Palette_00_Anim_12, NPC_ANIM_world_tubba_Palette_00_Anim_8, 0, MESSAGE_ID(0x0E, 0x00CC))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_LOOP(40)
            EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_802CF56C, 2)
        EVT_LOOP(45)
            EVT_CALL(PlayerFaceNpc, -1, 1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_GET_TID(N(80243DCC), LVarA)
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 800)
    EVT_CALL(NpcMoveTo, NPC_SELF, LocalVar(0), LocalVar(2), 80)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_SET(GB_StoryProgress, -16)
    EVT_CALL(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EVT_CALL(GetCurrentPartnerID, LocalVar(6))
    EVT_IF_EQ(LocalVar(6), 9)
        EVT_SET(LocalVar(5), -4)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 257, 25, 0)
    EVT_END_IF
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 30)
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(10)
    EVT_IF_NE(LocalVar(6), 9)
        EVT_SET(LocalVar(5), 8)
        EVT_CALL(SetNpcPos, 8, 257, 25, 0)
        EVT_CALL(func_802CFD30, 8, 7, 0, 0, 0, 0)
        EVT_CALL(NpcFacePlayer, 8, 0)
        EVT_CALL(MakeLerp, 0, 240, 20, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 8, 7, LocalVar(0), 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_802CF56C, 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_THREAD
        EVT_IF_NE(LocalVar(6), 9)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 8, 0)
            EVT_WAIT(5)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00CD))
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, LocalVar(5), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), -20)
    EVT_CALL(SetCamProperties, 0, EVT_FLOAT(2.0), LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(300.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(PlayerFaceNpc, LocalVar(5), 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00CE))
    EVT_CALL(ShowChoice, MESSAGE_ID(0x1E, 0x000D))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_CALL(ContinueSpeech, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00CF))
    EVT_ELSE
        EVT_CALL(ContinueSpeech, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_B, NPC_ANIM_world_bow_Palette_00_Anim_B, 0, MESSAGE_ID(0x0E, 0x00D0))
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00D1))
    EVT_CALL(UseSettingsFrom, 0, 175, 0, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(SetPanTarget, 0, 175, 0, 0)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcPos, 9, 93, 160, -6)
    EVT_CALL(InterpNpcYaw, 9, 90, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LocalVar(6), 9)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 160, 31, 70, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, 9, 93, LocalVar(0), -6)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_IF_NE(LocalVar(6), 9)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LocalVar(5), NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00D2))
    EVT_THREAD
        EVT_IF_NE(LocalVar(6), 9)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_EXEC(N(80242048))
    EVT_WAIT(20)
    EVT_THREAD
        EVT_IF_NE(LocalVar(6), 9)
            EVT_CALL(MakeLerp, 240, 0, 20, 0)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 8, 7, LocalVar(0), 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_CALL(SetNpcPos, 8, 0, -1000, 0)
            EVT_CALL(EnablePartnerAI)
        EVT_ELSE
            EVT_WAIT(20)
            EVT_CALL(ClearPartnerMoveHistory, -4)
            EVT_CALL(EnablePartnerAI)
        EVT_END_IF
        EVT_WAIT(8)
        EVT_CALL(func_802CF56C, 2)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244C54) = {
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(StartBossBattle, 11)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80244CC8) = {
    EVT_LABEL(10)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 0, LocalVar(0))
        EVT_IF_EQ(LocalVar(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SETF(LocalVar(0), EVT_FLOAT(0.5))
        EVT_CALL(MakeLerp, 50, 80, 15, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LocalVar(2), LocalVar(0))
            EVT_DIVF(LocalVar(2), 100)
            EVT_CALL(SetNpcScale, NPC_SELF, LocalVar(2), LocalVar(2), LocalVar(2))
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(RandInt, 80, LocalVar(2))
        EVT_CALL(RandInt, 10, LocalVar(3))
        EVT_ADD(LocalVar(3), 5)
        EVT_CALL(MakeLerp, LocalVar(2), 240, LocalVar(3), 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, NPC_SELF, 7, LocalVar(0), 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_SELF, 293, 59, 21)
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(-0.3))
    EVT_CALL(RandInt, 100, LocalVar(3))
    EVT_SUB(LocalVar(0), LocalVar(3))
    EVT_ADD(LocalVar(1), 100)
    EVT_CALL(NpcJump0, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2), 20)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80244FB8) = {
    EVT_CALL(SetEncounterStatusFlags, 2, 1)
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
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

EvtScript N(init_80245058) = {
    EVT_IF_NE(GB_StoryProgress, -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245090) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244C54)))
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(defeat_80244FB8)))
    EVT_IF_NE(GB_StoryProgress, -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245104) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(idle_80244CC8)))
    EVT_IF_NE(GB_StoryProgress, -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245164) = {
    EVT_IF_NE(GB_StoryProgress, -17)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8024519C) = {
    EVT_IF_NE(GB_StoryProgress, -17)
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

EvtScript N(idle_80245210) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SUB(LocalVar(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(1), 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80245304) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(3), LocalVar(0))
    EVT_ADD(LocalVar(3), -50)
    EVT_SET(LocalVar(4), LocalVar(1))
    EVT_ADD(LocalVar(4), 26)
    EVT_CALL(SetNpcPos, 13, LocalVar(3), LocalVar(4), LocalVar(2))
    EVT_CALL(PlayerFaceNpc, 13, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 13, 0)
    EVT_ADD(LocalVar(0), -25)
    EVT_CALL(UseSettingsFrom, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(475.0))
    EVT_CALL(SetCamPitch, 0, 18, -8)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D3))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, 0, 18, -9)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, 13, 0, LocalVar(0), 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, 13, 0)
    EVT_CALL(SetNpcAnimation, 13, NPC_ANIM_world_skolar_Palette_00_Anim_3)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_GOT_ITEM)
    EVT_CALL(PlaySoundAtPlayer, 313, 0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(3), LocalVar(1))
    EVT_ADD(LocalVar(1), 50)
    EVT_ADD(LocalVar(2), 10)
    EVT_ADD(LocalVar(3), 30)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x11, 3, LocalVar(0), LocalVar(1), LocalVar(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
        EVT_CALL(PlayEffect, 0x11, 1, LocalVar(0), LocalVar(3), LocalVar(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, 392, 0)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_CALL(PlayEffect, 0x52, 4, LocalVar(0), LocalVar(1), LocalVar(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(SetNpcAnimation, 13, NPC_ANIM_world_skolar_Palette_00_Anim_1)
    EVT_CALL(EnableNpcAI, 13, 1)
    EVT_CALL(PostChapter3StatUpdate)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x1D, 0x0193), 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, 13, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D4))
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), -25)
    EVT_CALL(SetPanTarget, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 13, NPC_ANIM_world_skolar_Palette_00_Anim_2, NPC_ANIM_world_skolar_Palette_00_Anim_1, 512, MESSAGE_ID(0x0E, 0x00D5))
    EVT_CALL(SetNpcFlagBits, 13, ((NPC_FLAG_40000)), TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, 13, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(PlayEffect, 0x11, 4, LocalVar(0), LocalVar(1), LocalVar(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(2), 0)
        EVT_SET(LocalVar(3), 1800)
        EVT_CALL(MakeLerp, LocalVar(2), LocalVar(3), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 13, 0, LocalVar(0), 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, 13, LocalVar(2), LocalVar(3), LocalVar(4))
        EVT_SET(LocalVar(5), LocalVar(3))
        EVT_ADD(LocalVar(5), 180)
        EVT_CALL(MakeLerp, LocalVar(3), LocalVar(5), 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, 13, LocalVar(2), LocalVar(0), LocalVar(4))
            EVT_WAIT(1)
            EVT_IF_EQ(LocalVar(1), 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, 13, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtNpc, 13, 0x2045, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, 65578)
    EVT_WAIT(90)
    EVT_CALL(ResetCam, 0, 3)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_SET(GB_StoryProgress, -13)
    EVT_EXEC(N(80241F10))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C9C) = {
    EVT_CALL(GetEntryID, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 3)
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
        .flags = NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245090),
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
        .extraAnimations = N(extraAnimationList_802451D4),
    },
    {
        .id = NPC_TUBBAS_HEART,
        .settings = &N(npcSettings_80243CC4),
        .pos = { -10.0f, 50.0f, -170.0f },
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_40000 | NPC_FLAG_200000,
        .init = &N(init_80245058),
        .yaw = 90,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
        .init = &N(init_80245104),
        .yaw = 270,
        .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
    .init = &N(init_80245164),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_200000,
    .init = &N(init_8024519C),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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

EvtScript N(init_8024706C) = {
    EVT_IF_GE(GB_StoryProgress, -26)
        EVT_IF_LT(GB_StoryProgress, -15)
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
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_8024706C),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { -216, 60, -10, 30, 0, -32767, 0, -216, 60, -10, 250 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_802472AC) = {
    .id = NPC_PARAGOOMBA1,
    .settings = &N(npcSettings_80243C78),
    .pos = { 0.0f, 60.0f, 150.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_8024706C),
    .yaw = 270,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 0, 60, 150, 30, 0, -32767, 0, 0, 60, 150, 250 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_8024749C) = {
    .id = NPC_PARAGOOMBA2,
    .settings = &N(npcSettings_80243C78),
    .pos = { 260.0f, 60.0f, 30.0f },
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_8024706C),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
        { ITEM_DRIED_SHROOM, 10, 0 },
    },
        .heartDrops = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .maxCoinBonus = 2,
    },
	.territory = { .temp = { 260, 60, 30, 30, 0, -32767, 0, 260, 60, 30, 250 }},
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
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(npcGroup_8024768C) = {
    .id = NPC_WORLD_SKOLAR,
    .settings = &N(npcSettings_80243D48),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .init = &N(init_80245C9C),
    .yaw = 0,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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
    NPC_GROUP(N(npcGroup_80245D0C), 0x0E10, 0x01),
    NPC_GROUP(N(npcGroup_802460EC)),
    NPC_GROUP(N(npcGroup_80246C8C)),
    NPC_GROUP(N(npcGroup_80246E7C)),
    {},
};

NpcGroupList N(npcGroupList_802478B8) = {
    NPC_GROUP(N(npcGroup_802470BC), 0x0E06, 0x01),
    NPC_GROUP(N(npcGroup_802472AC), 0x0E07, 0x01),
    NPC_GROUP(N(npcGroup_8024749C), 0x0E08, 0x01),
    {},
};

NpcGroupList N(npcGroupList_802478E8) = {
    NPC_GROUP(N(npcGroup_8024768C)),
    {},
};

#include "world/common/enemy/FlyingAI.inc.c"

ApiStatus PostChapter3StatUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    set_max_SP(3);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_menu();
    return ApiStatus_DONE2;
}
