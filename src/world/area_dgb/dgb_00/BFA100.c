#include "dgb_00.h"
#include "entity.h"
#include "sprite/npc/boo.h"
#include "sprite/npc/sentinel.h"
#include "sprite/npc/world_bombette.h"
#include "sprite/npc/world_bow.h"
#include "sprite/npc/world_goombario.h"
#include "sprite/npc/world_kooper.h"
#include "sprite/npc/world_parakarry.h"


enum {
    NPC_BOO0,
    NPC_BOO1,
    NPC_BOO2,
    NPC_BOO3,
    NPC_BOO4,
    NPC_BOO5,
    NPC_SENTINEL,
};

NpcSettings N(npcSettings_80240640) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

NpcSettings N(npcSettings_8024066C) = {
    .height = 24,
    .radius = 24,
    .level = 99,
};

EvtScript N(80240698) = {
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(ModifyColliderFlags, 0, 18, 0x7FFFFE00)
    EVT_CALL(PlaySoundAtCollider, 18, 455, 0)
    EVT_CALL(MakeLerp, 0, 80, 30, 0)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 7, LVar0, 0, LVar2, 0)
    EVT_CALL(RotateModel, 5, LVar0, 0, LVar3, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8024079C) = {
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(MakeLerp, 80, 0, 12, 0)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, 7, LVar0, 0, LVar2, 0)
    EVT_CALL(RotateModel, 5, LVar0, 0, LVar3, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, 1, 18, 0x7FFFFE00)
    EVT_CALL(PlaySoundAtCollider, 18, 456, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802408A0) = {
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 0, LVar0, LVar2, 46)
    EVT_RETURN
    EVT_END
};

EvtScript N(802408F8) = {
    EVT_CALL(GetNpcPos, 1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 1, LVar0, LVar2, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240950) = {
    EVT_CALL(GetNpcPos, 2, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 2, LVar0, LVar2, 53)
    EVT_RETURN
    EVT_END
};

EvtScript N(802409A8) = {
    EVT_CALL(GetNpcPos, 3, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 3, LVar0, LVar2, 46)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240A00) = {
    EVT_CALL(GetNpcPos, 4, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 4, LVar0, LVar2, 50)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240A58) = {
    EVT_CALL(GetNpcPos, 5, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(NpcMoveTo, 5, LVar0, LVar2, 53)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240AB0) = {
    EVT_EXEC(N(802408A0))
    EVT_EXEC(N(802408F8))
    EVT_EXEC(N(80240950))
    EVT_EXEC(N(802409A8))
    EVT_EXEC(N(80240A00))
    EVT_EXEC(N(80240A58))
    EVT_RETURN
    EVT_END
};

EvtScript N(80240B08) = {
    EVT_CALL(SetNpcJumpscale, 0, EVT_FLOAT(-0.2))
    EVT_CALL(NpcJump0, 0, 257, 30, -90, 5)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240B74) = {
    EVT_CALL(SetNpcJumpscale, 1, EVT_FLOAT(-0.3))
    EVT_CALL(NpcJump0, 1, 272, 112, -81, 12)
    EVT_CALL(EnableNpcShadow, 1, FALSE)
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240BE0) = {
    EVT_CALL(SetNpcJumpscale, 2, EVT_FLOAT(-0.4))
    EVT_CALL(NpcJump0, 2, 237, 120, -118, 10)
    EVT_CALL(EnableNpcShadow, 2, FALSE)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240C4C) = {
    EVT_CALL(SetNpcJumpscale, 3, EVT_FLOAT(-0.3))
    EVT_CALL(NpcJump0, 3, 280, 60, -79, 8)
    EVT_CALL(EnableNpcShadow, 3, FALSE)
    EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240CB8) = {
    EVT_CALL(SetNpcJumpscale, 4, EVT_FLOAT(-0.4))
    EVT_CALL(NpcJump0, 4, 250, 81, -97, 9)
    EVT_CALL(EnableNpcShadow, 4, FALSE)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240D24) = {
    EVT_CALL(SetNpcJumpscale, 5, EVT_FLOAT(-0.5))
    EVT_CALL(NpcJump0, 5, 227, 43, -123, 15)
    EVT_CALL(EnableNpcShadow, 5, FALSE)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_RETURN
    EVT_END
};

EvtScript N(80240D90) = {
    EVT_EXEC(N(80240B74))
    EVT_EXEC(N(80240BE0))
    EVT_EXEC(N(80240C4C))
    EVT_EXEC(N(80240CB8))
    EVT_EXEC(N(80240D24))
    EVT_RETURN
    EVT_END
};

EvtScript N(80240DDC) = {
    EVT_CALL(GetNpcPos, 0, LVar0, LVar1, LVar2)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 5, LVarA)
        EVT_ADD(LVarA, 2)
        EVT_SET(LVarB, 0)
        EVT_LABEL(10)
        EVT_SET(LVar3, LVar0)
        EVT_ADD(LVar3, 1)
        EVT_CALL(SetNpcPos, 0, LVar3, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_SET(LVar3, LVar0)
        EVT_ADD(LVar3, -1)
        EVT_CALL(SetNpcPos, 0, LVar3, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVarB, 1)
        EVT_IF_LT(LVarB, LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(RandInt, 10, LVarA)
        EVT_ADD(LVarA, 10)
        EVT_WAIT(LVarA)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80240F50) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 50, LVar0)
        EVT_ADD(LVar0, 80)
        EVT_WAIT(LVar0)
        EVT_IF_EQ(MapVar(0), 0)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(PlaySoundAt, SOUND_B4, 0, 240, 10, -125)
            EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
            EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x0E, 0x00EF), 160, 40)
            EVT_CALL(DisablePlayerInput, FALSE)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(8024103C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, 350, 10, -150)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamType, 0, 4, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 175)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -75)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(40)
    EVT_CALL(SetNpcPos, 0, -60, 10, -70)
    EVT_CALL(SetNpcPos, 1, -100, 10, -110)
    EVT_CALL(SetNpcPos, 2, -140, 10, -150)
    EVT_CALL(SetNpcPos, 3, -100, 10, -30)
    EVT_CALL(SetNpcPos, 4, -140, 10, -70)
    EVT_CALL(SetNpcPos, 5, -180, 10, -100)
    EVT_EXEC_WAIT(N(80240AB0))
    EVT_WAIT(60)
    EVT_CALL(InterpNpcYaw, 0, 270, 1)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DB))
    EVT_CALL(SpeakToPlayer, 4, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DC))
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 5, MESSAGE_ID(0x0E, 0x00DD))
    EVT_CALL(PlaySoundAt, SOUND_B4, 0, 240, 10, -125)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAt, SOUND_B4, 0, 240, 10, -125)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
    EVT_CALL(InterpNpcYaw, 0, 90, 1)
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x0E, 0x00DE), 160, 40)
    EVT_CALL(SetPlayerPos, 350, 10, -150)
    EVT_CALL(InterpPlayerYaw, 270, 1)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 350, 10, -150)
    EVT_SET(LVar2, 1)
    EVT_EXEC_WAIT(N(80240698))
    EVT_RETURN
    EVT_END
};

EvtScript N(802413F4) = {
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(8.0))
    EVT_CALL(PlayerMoveTo, 184, -44, 0)
    EVT_CALL(PlaySoundAtNpc, 0, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 1, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 2, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 3, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 4, SOUND_262, 0)
    EVT_CALL(PlaySoundAtNpc, 5, SOUND_262, 0)
    EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 1, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 2, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 3, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 4, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_CALL(ShowEmote, 5, EMOTE_EXCLAMATION, 45, 20, 1, 0, 0, 0, 0)
    EVT_WAIT(50)
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(8024079C))
    EVT_EXEC(N(80240D90))
    EVT_WAIT(20)
    EVT_CALL(SetCamType, 0, 6, 1)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(6.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(15.0), EVT_FLOAT(-15.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_EXEC_GET_TID(N(80240DDC), LVarA)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00DF))
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerAnimation, ANIM_80007)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E0))
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_NOD_YES)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_4, NPC_ANIM_boo_Palette_01_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E1))
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk, NPC_ANIM_world_goombario_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E2))
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_kooper_normal_talk, NPC_ANIM_world_kooper_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E3))
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bombette_normal_idle_fast, NPC_ANIM_world_bombette_normal_idle, 0, MESSAGE_ID(0x0E, 0x00E4))
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E5))
        EVT_CASE_EQ(9)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00E6))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetCamType, 0, 4, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(6.0))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(PlaySoundAt, SOUND_B4, 0, 240, 10, -125)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAt, SOUND_B4, 0, 240, 10, -125)
    EVT_CALL(ShakeCam, 0, 0, 20, EVT_FLOAT(2.0))
    EVT_CALL(ShowMessageAtScreenPos, MESSAGE_ID(0x0E, 0x00E7), 160, 40)
    EVT_EXEC_WAIT(N(80240B08))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 5, MESSAGE_ID(0x0E, 0x00E8))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_EXEC(N(80240F50))
    EVT_SET(GB_StoryProgress, -25)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80241AA0) = {
    EVT_CALL(SetNpcPos, 0, 246, 30, -110)
    EVT_CALL(SetNpcPos, 1, 276, 120, -80)
    EVT_CALL(SetNpcPos, 2, 216, 120, -140)
    EVT_CALL(SetNpcPos, 3, 276, 60, -80)
    EVT_CALL(SetNpcPos, 4, 246, 90, -110)
    EVT_CALL(SetNpcPos, 5, 216, 60, -130)
    EVT_CALL(InterpNpcYaw, 0, 70, 1)
    EVT_CALL(InterpNpcYaw, 1, 99, 1)
    EVT_CALL(InterpNpcYaw, 2, 93, 1)
    EVT_CALL(InterpNpcYaw, 3, 74, 1)
    EVT_CALL(InterpNpcYaw, 4, 78, 1)
    EVT_CALL(InterpNpcYaw, 5, 81, 1)
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(SetNpcAnimation, 2, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(SetNpcAnimation, 3, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(SetNpcAnimation, 4, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(SetNpcAnimation, 5, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_CALL(EnableNpcShadow, 1, FALSE)
    EVT_CALL(EnableNpcShadow, 2, FALSE)
    EVT_CALL(EnableNpcShadow, 3, FALSE)
    EVT_CALL(EnableNpcShadow, 4, FALSE)
    EVT_CALL(EnableNpcShadow, 5, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(interact_80241CD8) = {
    EVT_SET(MapVar(0), 1)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_boo_Palette_01_Anim_6, NPC_ANIM_boo_Palette_01_Anim_6, 5, MESSAGE_ID(0x0E, 0x00E9))
    EVT_CALL(SetNpcAnimation, 0, NPC_ANIM_boo_Palette_01_Anim_6)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk, NPC_ANIM_world_goombario_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EA))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_CASE_EQ(2)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_kooper_normal_talk, NPC_ANIM_world_kooper_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EB))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_CASE_EQ(3)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bombette_normal_idle_fast, NPC_ANIM_world_bombette_normal_idle, 0, MESSAGE_ID(0x0E, 0x00EC))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_CASE_EQ(4)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_parakarry_Palette_00_Anim_6, NPC_ANIM_world_parakarry_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00ED))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
        EVT_CASE_EQ(9)
            EVT_CALL(AdjustCam, 0, EVT_FLOAT(6.0), 0, EVT_FLOAT(-275.0), EVT_FLOAT(15.0), EVT_FLOAT(-6.0))
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_bow_Palette_00_Anim_4, NPC_ANIM_world_bow_Palette_00_Anim_1, 0, MESSAGE_ID(0x0E, 0x00EE))
            EVT_CALL(ResetCam, 0, EVT_FLOAT(6.0))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_SET(MapVar(0), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241F70) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(interact_80241CD8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241F94) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241FA4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241FB4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241FC4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80241FD4) = {
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_80241FE4) = {
    .id = NPC_BOO0,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_400000,
    .init = &N(init_80241F70),
    .yaw = 90,
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
    .tattle = MESSAGE_ID(0x1A, 0x00B5),
};

StaticNpc N(npcGroup_802421D4) = {
    .id = NPC_BOO1,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241F94),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_802423C4) = {
    .id = NPC_BOO2,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FA4),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_802425B4) = {
    .id = NPC_BOO3,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FB4),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_802427A4) = {
    .id = NPC_BOO4,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FC4),
    .yaw = 90,
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
};

StaticNpc N(npcGroup_80242994) = {
    .id = NPC_BOO5,
    .settings = &N(npcSettings_80240640),
    .pos = { 0.0f, -1000.0f, 0.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS,
    .init = &N(init_80241FD4),
    .yaw = 90,
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
};

EvtScript N(80242B84) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 320, 10, -160)
    EVT_CALL(PlaySound, SOUND_32E)
    EVT_THREAD
        EVT_LOOP(180)
            EVT_CALL(GetNpcPos, 6, LVar0, LVar1, LVar2)
            EVT_CALL(N(func_80240060_BFA100))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPlayerPos, 320, 50, -160)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_80017)
    EVT_CALL(SetNpcPos, 6, 320, 70, -158)
    EVT_CALL(InterpNpcYaw, 6, 270, 0)
    EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_sentinel_Palette_00_Anim_8)
    EVT_CALL(UseSettingsFrom, 0, 175, 0, -35)
    EVT_CALL(SetPanTarget, 0, 175, 0, -35)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(540.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_SET(LVar2, 1)
        EVT_EXEC(N(80240698))
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, 0)
        EVT_CALL(PlayerJump1, 175, 50, -35, 40)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_WAIT(1)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x107)
        EVT_WAIT(85)
        EVT_CALL(func_802CF56C, 2)
        EVT_WAIT(1)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, 6, 175, -33, 40)
    EVT_WAIT(20)
    EVT_CALL(SetNpcPos, 6, 175, 85, -33)
    EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_sentinel_Palette_00_Anim_9)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtNpc, 6, SOUND_2F7, 0)
    EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_sentinel_Palette_00_Anim_2)
    EVT_CALL(SetNpcPos, 6, 175, 70, -33)
    EVT_THREAD
        EVT_WAIT(40)
        EVT_CALL(SetNpcAnimation, 6, NPC_ANIM_sentinel_Palette_00_Anim_3)
        EVT_CALL(NpcMoveTo, 6, 270, -120, 30)
        EVT_CALL(StopSound, 814)
        EVT_CALL(SetNpcPos, 6, 0, -1000, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_SET(LVar2, 1)
        EVT_EXEC(N(8024079C))
    EVT_END_THREAD
    EVT_CALL(SetPlayerJumpscale, 0)
    EVT_CALL(PlayerJump1, 175, 0, -35, 10)
    EVT_CALL(PlaySoundAtNpc, 6, SOUND_162, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_80003)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, 0x10, 3, 0, 175, 0, -35, 20, -20, 30, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetCamDistance, 0, EVT_FLOAT(320.0))
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(15.0), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_WAIT(65)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
        EVT_CASE_EQ(2)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
        EVT_CASE_EQ(3)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, ((NPC_FLAG_GRAVITY)), TRUE)
    EVT_END_SWITCH
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D6))
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D7))
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D8))
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D9))
        EVT_CASE_EQ(9)
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00DA))
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_PARTNER, 0x108, 0x106, 5, MESSAGE_ID(0x0E, 0x00D6))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_GET_UP)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_DUST_OFF)
    EVT_WAIT(7)
    EVT_CALL(PlaySoundAtPlayer, 370, 0)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtPlayer, 370, 0)
    EVT_WAIT(15)
    EVT_CALL(SetPlayerAnimation, ANIM_8001B)
    EVT_WAIT(25)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(InterpPlayerYaw, 45, 0)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerAnimation, ANIM_MIDAIR_STILL)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerJump1, LVar0, 0, LVar2, 10)
    EVT_CALL(PlayerJump1, LVar0, 0, LVar2, 10)
    EVT_CALL(SetPlayerAnimation, ANIM_10002)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, 0, 0, 0)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_802434EC) = {
    EVT_RETURN
    EVT_END
};

StaticNpc N(npcGroup_802434FC) = {
    .id = NPC_SENTINEL,
    .settings = &N(npcSettings_8024066C),
    .pos = { 0.0f, 0.0f, -1000.0f },
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_400000,
    .init = &N(init_802434EC),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
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

NpcGroupList N(npcGroupList_802436EC) = {
    NPC_GROUP(N(npcGroup_80241FE4)),
    NPC_GROUP(N(npcGroup_802421D4)),
    NPC_GROUP(N(npcGroup_802423C4)),
    NPC_GROUP(N(npcGroup_802425B4)),
    NPC_GROUP(N(npcGroup_802427A4)),
    NPC_GROUP(N(npcGroup_80242994)),
    {},
};

NpcGroupList N(npcGroupList_80243740) = {
    NPC_GROUP(N(npcGroup_802434FC)),
    {},
};

static s32 N(pad_3758)[] = {
    0x00000000, 0x00000000,
};

EvtScript N(makeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -65, 60, -240, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};

ApiStatus N(func_80240060_BFA100)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(get_enemy(6)->npcID);

    sfx_adjust_env_sound_pos(SOUND_32E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}
