#include "arn_07.h"
#include "effects.h"
#include "sprite/npc/world_tubba.h"
#include "sprite/npc/tubbas_heart.h"

#include "world/common/StarSpiritEffectFunc.inc.c"

s32 N(itemList_80242040)[] = {
    ITEM_MYSTICAL_KEY,
    ITEM_NONE,
};

EvtScript N(80242048) = {
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_SET(LVar0, 0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, 0, 145, 65, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, 0, 145, 30, 0)
        EVT_CALL(GetCamDistance, 0, LVar1)
        EVT_SUB(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_IF_NE(10000, 10000)
            EVT_CALL(GetCamPitch, 0, LVar2, LVar3)
            EVT_CALL(SetCamPitch, 0, LVar2, 10000)
        EVT_END_IF
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, 0x80000067)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, 0x80000067)
            EVT_CALL(PlaySoundAt, 0xB2, 0, 145, 65, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(SetPlayerAnimation, 65578)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(50)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, 0x137, 0, 145, 65, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_CALL(SetPanTarget, 0, 145, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, 0, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, 0, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, 0, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, 312, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, -15)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), 2, 14)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(80242498) = {
    EVT_SET(LVar0, 1)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(UseSettingsFrom, 0, 145, 65, 0)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.6))
        EVT_CALL(SetPanTarget, 0, 145, 30, 0)
        EVT_CALL(GetCamDistance, 0, LVar1)
        EVT_SUB(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_IF_NE(10000, 10000)
            EVT_CALL(GetCamPitch, 0, LVar2, LVar3)
            EVT_CALL(SetCamPitch, 0, LVar2, 10000)
        EVT_END_IF
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(N(StarSpiritEffectFunc2), 2, 50, 100, 31, -6, 145, 65, 0, 30, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc3))
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(1)
            EVT_CALL(PlaySound, 0x80000067)
            EVT_CALL(N(StarSpiritEffectFunc1))
            EVT_CALL(StopSound, 0x80000067)
            EVT_CALL(PlaySoundAt, 0xB2, 0, 145, 65, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(SetPlayerAnimation, 65578)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(50)
            EVT_WAIT(115)
            EVT_CALL(PlaySoundAt, 0x137, 0, 145, 65, 0)
        EVT_END_THREAD
        EVT_CALL(N(StarSpiritEffectFunc4), 1)
        EVT_THREAD
            EVT_WAIT(80)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
        EVT_END_THREAD
        EVT_ADD(LVar1, 100)
        EVT_CALL(SetCamDistance, 0, LVar1)
        EVT_CALL(SetPanTarget, 0, 145, 0, 0)
        EVT_CALL(N(StarSpiritEffectFunc4), 2)
        EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
        EVT_CALL(UseSettingsFrom, 0, LVar2, LVar3, LVar4)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, 0, LVar2, LVar3, LVar4)
        EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, 0, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(N(StarSpiritEffectFunc5), 2, 145, 30, 0, 0)
        EVT_THREAD
            EVT_CALL(N(StarSpiritEffectFunc6))
        EVT_END_THREAD
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(N(StarSpiritEffectFunc4), 3)
    EVT_CALL(PlaySoundAtPlayer, 312, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GB_StoryProgress, -15)
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_23"), 2, 14)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitSingleDoor_802428D4) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 10)
    EVT_SET(LVar2, 29)
    EVT_SET(LVar3, 1)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("arn_08"), 0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(exitWalk_80242978) = EXIT_WALK_SCRIPT(60,  1, "arn_03",  0);

EvtScript N(exitWalk_802429D4) = EXIT_WALK_SCRIPT(60,  2, "mim_12",  1);

static const f64 rodata_alignment = 0.0;

EvtScript N(80242A30) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, -28, 0, -333)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -28, 0, -333)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamType, 0, 0, 0)
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(25.0), EVT_FLOAT(-4.0))
    EVT_CALL(SetCamDistance, 0, 1100)
    EVT_CALL(SetCamPosA, 0, 500, 0)
    EVT_CALL(SetCamPosB, 0, 0, -500)
    EVT_CALL(SetCamPosC, 0, 0, 0)
    EVT_CALL(SetPanTarget, 0, 5, 0, -147)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(RotateModel, 29, 80, 0, -1, 0)
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(SetNpcJumpscale, 0, EVT_FLOAT(2.5))
    EVT_CALL(NpcJump0, 0, 0, 20, -120, 8)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(NpcJump0, 0, 0, 10, -60, 12)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(NpcJump0, 0, 0, 0, 0, 12)
    EVT_WAIT(1)
    EVT_CALL(SetNpcVar, 0, 0, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
            EVT_CALL(NpcJump0, 0, 0, 0, 0, 10)
            EVT_WAIT(1)
            EVT_CALL(GetNpcVar, 0, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcVar, 0, 0, 2)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 29, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 10, 450, 0)
    EVT_END_THREAD
    EVT_CALL(NpcFaceNpc, 0, 1, 0)
    EVT_CALL(SpeakToPlayer, 0, NPC_ANIM_tubbas_heart_Palette_00_Anim_A, NPC_ANIM_tubbas_heart_Palette_00_Anim_1, 5, MESSAGE_ID(0x0E00C7))
    EVT_CALL(SetNpcVar, 0, 0, 1)
    EVT_LOOP(0)
        EVT_CALL(GetNpcVar, 0, 0, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(NpcJump0, 0, 75, 0, 10, 12)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(NpcJump0, 0, 150, 0, 20, 12)
    EVT_WAIT(1)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(2.0), EVT_FLOAT(-9.0))
        EVT_CALL(SetCamDistance, 0, 700)
        EVT_CALL(SetCamPosA, 0, 500, 0)
        EVT_CALL(SetCamPosB, 0, 0, -500)
        EVT_CALL(SetCamPosC, 0, 0, 0)
        EVT_CALL(SetPanTarget, 0, 65, 0, -137)
        EVT_CALL(PanToTarget, 0, 0, 1)
        EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_world_tubba_Palette_00_Anim_22)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, 0, 0x20C8, 0)
    EVT_CALL(NpcJump0, 0, 298, 56, 31, 18)
    EVT_CALL(SetNpcPos, 0, 0, -1000, 0)
    EVT_CALL(EnableNpcShadow, 0, FALSE)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_world_tubba_Palette_00_Anim_23)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, 1, NPC_ANIM_world_tubba_Palette_00_Anim_6)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, 10, 449, 0)
        EVT_CALL(MakeLerp, 0, 80, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 29, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
        EVT_CALL(SetCamPitch, 0, EVT_FLOAT(8.0), EVT_FLOAT(-9.0))
        EVT_CALL(SetCamDistance, 0, 450)
        EVT_CALL(SetPanTarget, 0, 250, 0, -46)
        EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, 0, 10, 0x7FFFFE00)
    EVT_CALL(SetPlayerPos, 0, 20, -195)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 0, 20, -195)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PlayerMoveTo, 0, 0, 45)
    EVT_CALL(ModifyColliderFlags, 1, 10, 0x7FFFFE00)
    EVT_THREAD
        EVT_CALL(MakeLerp, 80, 0, 10, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, 29, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtCollider, 10, 450, 0)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, 200, 0, 35)
    EVT_WAIT(5)
    EVT_CALL(SpeakToPlayer, 1, NPC_ANIM_world_tubba_Palette_00_Anim_10, NPC_ANIM_world_tubba_Palette_00_Anim_6, 0, MESSAGE_ID(0x0E00C8))
    EVT_CALL(SetNpcVar, 1, 0, 1)
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802433C8) = {
    EVT_BIND_TRIGGER(N(exitWalk_80242978), TRIGGER_FLOOR_ABOVE, 5, 1, 0)
    EVT_BIND_TRIGGER(N(exitWalk_802429D4), TRIGGER_FLOOR_ABOVE, 1, 1, 0)
    EVT_IF_LT(GB_StoryProgress, -24)
        EVT_BIND_PADLOCK(N(802439B0), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(itemList_80242040)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(N(exitSingleDoor_802428D4), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(enterWalk_8024346C) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(GB_StoryProgress, -17)
                EVT_EXEC_WAIT(N(80242A30))
                EVT_EXEC(N(802433C8))
            EVT_ELSE
                EVT_SET(LVar2, 29)
                EVT_SET(LVar3, 1)
                EVT_EXEC_WAIT(EnterSingleDoor)
                EVT_EXEC(N(802433C8))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, EVT_PTR(N(802433C8)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, EVT_PTR(N(802433C8)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(3)
            EVT_EXEC(N(802433C8))
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, 34)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamLeadPlayer, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_SET(GF_MAP_GustyGulch, 1)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(-26)
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802478B8)))
        EVT_CASE_LT(-14)
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_8024787C)))
        EVT_CASE_EQ(-14)
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802478E8)))
        EVT_CASE_DEFAULT
            EVT_CALL(MakeNpcs, 0, EVT_PTR(N(npcGroupList_802478B8)))
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(makeEntities))
    EVT_IF_EQ(GB_StoryProgress, -16)
        EVT_EXEC(N(80242498))
    EVT_END_IF
    EVT_EXEC(N(enterWalk_8024346C))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 3)
        EVT_WAIT(65)
    EVT_END_IF
    EVT_EXEC(N(80243790))
    EVT_EXEC(N(80241F10))
    EVT_CALL(UseDoorSounds, 0)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};
