#include "arn_07.h"
#include "entity.h"
#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/Paragoomba.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/Boo.h"
#include "sprite/npc/Bootler.h"

EvtScript N(80243790) = {
    EVT_EXEC(N(802437AC))
    EVT_RETURN
    EVT_END
};

EvtScript N(802437AC) = {
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_SET(LVar1, 30)
    EVT_CALL(PlaySoundAtModel, 23, 0x8000004A, 0)
    EVT_LABEL(0)
    EVT_ADDF(LVar0, EVT_FLOAT(1.0))
    EVT_CALL(N(func_80240800_BED5F0))
    EVT_CALL(RotateModel, 27, LVar0, 0, 0, 1)
    EVT_WAIT(1)
    EVT_SUB(LVar1, 1)
    EVT_IF_GT(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LVar1, 30)
    EVT_CALL(RandInt, 100, LVar2)
    EVT_IF_GT(LVar2, 10)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SETF(LVar2, EVT_FLOAT(1.0))
    EVT_LOOP(50)
        EVT_SUBF(LVar2, EVT_FLOAT(0.01))
        EVT_ADDF(LVar0, LVar2)
        EVT_CALL(RotateModel, 27, LVar0, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADDF(LVar2, EVT_FLOAT(0.01))
        EVT_ADDF(LVar0, LVar2)
        EVT_CALL(RotateModel, 27, LVar0, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar1, 30)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802439B0) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_MYSTICAL_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, -24)
    EVT_CALL(N(GetEntityPosition), MapVar(0), LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, 0x269, 0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MapVar(0))
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
        EVT_SET(MapVar(0), LVar0)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim08)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CA)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 5, MSG_CH3_00CB)
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(2.0))
    EVT_CALL(SetCamPitch, 0, EVT_FLOAT(5.0), EVT_FLOAT(-16.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(80243FE8) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
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
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim23)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim22)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xB0000010, 0)
    EVT_CALL(SetNpcVar, 3, 0, 1)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim21)
    EVT_WAIT(45)
    EVT_CALL(UseSettingsFrom, 0, 236, 0, -46)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldTubba_Anim0F)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldTubba_Anim12, ANIM_WorldTubba_Anim08, 0, MSG_CH3_00CC)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
        EVT_LOOP(40)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
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
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 800)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar0, LVar2, 80)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_SET(GB_StoryProgress, -16)
    EVT_CALL(SetMusicTrack, 0, SONG_CHEERFUL_BOOS_MANSION, 0, 8)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_IF_EQ(LVar6, 9)
        EVT_SET(LVar5, -4)
        EVT_CALL(func_802CF56C, 0)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 257, 25, 0)
    EVT_END_IF
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, 0, 300)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_WAIT(10)
    EVT_IF_NE(LVar6, 9)
        EVT_SET(LVar5, 8)
        EVT_CALL(SetNpcPos, 8, 257, 25, 0)
        EVT_CALL(func_802CFD30, 8, 7, 0, 0, 0, 0)
        EVT_CALL(NpcFacePlayer, 8, 0)
        EVT_CALL(MakeLerp, 0, 240, 20, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, 8, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_802CF56C, 0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_THREAD
        EVT_IF_NE(LVar6, 9)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_WAIT(1)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, 8, 0)
            EVT_WAIT(5)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CD)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, LVar5, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, -20)
    EVT_CALL(SetCamProperties, 0, EVT_FLOAT(2.0), LVar0, LVar1, LVar2, EVT_FLOAT(300.0), EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(PlayerFaceNpc, LVar5, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00CE)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00CF)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, LVar5, ANIM_WorldBow_Celebrate, ANIM_WorldBow_Celebrate, 0, MSG_CH3_00D0)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D1)
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
        EVT_IF_NE(LVar6, 9)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 160, 31, 70, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, 9, 93, LVar0, -6)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_IF_NE(LVar6, 9)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, LVar5, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_00D2)
    EVT_THREAD
        EVT_IF_NE(LVar6, 9)
            EVT_WAIT(12)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_EXEC(N(80242048))
    EVT_WAIT(20)
    EVT_THREAD
        EVT_IF_NE(LVar6, 9)
            EVT_CALL(MakeLerp, 240, 0, 20, 0)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(func_802CFD30, 8, 7, LVar0, 0, 0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
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
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
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
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(0.5))
        EVT_CALL(MakeLerp, 50, 80, 15, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 100)
            EVT_CALL(SetNpcScale, NPC_SELF, LVar2, LVar2, LVar2)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(RandInt, 80, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 5)
        EVT_CALL(MakeLerp, LVar2, 240, LVar3, 0)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(func_802CFD30, NPC_SELF, 7, LVar0, 0, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_SELF, 293, 59, 21)
    EVT_WAIT(1)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(-0.3))
    EVT_CALL(RandInt, 100, LVar3)
    EVT_SUB(LVar0, LVar3)
    EVT_ADD(LVar1, 100)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(defeat_80244FB8) = {
    EVT_CALL(SetEncounterStatusFlags, 2, 1)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
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
    ANIM_WorldTubba_Anim00,
    ANIM_WorldTubba_Anim22,
    ANIM_WorldTubba_Anim23,
    ANIM_WorldTubba_Anim06,
    ANIM_WorldTubba_Anim10,
    ANIM_WorldTubba_Anim08,
    ANIM_WorldTubba_Anim0F,
    ANIM_WorldTubba_Anim12,
    ANIM_LIST_END,
};

s32 N(extraAnimationList_802451F8)[] = {
    ANIM_Boo_Still,
    ANIM_LIST_END,
};

s32 N(extraAnimationList_80245200)[] = {
    ANIM_Boo_Tan_Still,
    ANIM_LIST_END,
};

s32 N(extraAnimationList_80245208)[] = {
    ANIM_Bootler_Idle,
    ANIM_LIST_END,
};

EvtScript N(idle_80245210) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(80245304) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -50)
    EVT_SET(LVar4, LVar1)
    EVT_ADD(LVar4, 26)
    EVT_CALL(SetNpcPos, 13, LVar3, LVar4, LVar2)
    EVT_CALL(PlayerFaceNpc, 13, 0)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, 13, 0)
    EVT_ADD(LVar0, -25)
    EVT_CALL(UseSettingsFrom, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(475.0))
    EVT_CALL(SetCamPitch, 0, 18, -8)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SpeakToPlayer, 13, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D3)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamPitch, 0, 18, -9)
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10, 0)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, 13, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, 13, 0)
    EVT_CALL(SetNpcAnimation, 13, ANIM_WorldSkolar_Leap)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_GotItem)
    EVT_CALL(PlaySoundAtPlayer, 313, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_CALL(PlayEffect, 0x11, 3, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
        EVT_CALL(PlayEffect, 0x11, 1, LVar0, LVar3, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtPlayer, 392, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, 0x52, 4, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(SetNpcAnimation, 13, ANIM_WorldSkolar_Idle)
    EVT_CALL(EnableNpcAI, 13, 1)
    EVT_CALL(PostChapter3StatUpdate)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0193, 160, 40)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, 13, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(250.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 13, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D4)
    EVT_WAIT(10)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -25)
    EVT_CALL(SetPanTarget, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, 0, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, 0, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, 0, 0, 1)
    EVT_CALL(WaitForCam, 0, EVT_FLOAT(1.0))
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, 13, ANIM_WorldSkolar_TalkAngry, ANIM_WorldSkolar_Idle, 512, MSG_CH3_00D5)
    EVT_CALL(SetNpcFlagBits, 13, ((NPC_FLAG_40000)), TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, 13, LVar0, LVar1, LVar2)
            EVT_CALL(PlayEffect, 0x11, 4, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, 13, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, 13, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100, 2)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, 13, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_SET(GB_StoryProgress, -13)
    EVT_EXEC(N(80241F10))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80245C9C) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, 3)
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
            ANIM_WorldTubba_Anim06,
            ANIM_WorldTubba_Anim09,
            ANIM_WorldTubba_Anim0C,
            ANIM_WorldTubba_Anim0C,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
            ANIM_WorldTubba_Anim00,
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
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
            ANIM_TubbasHeart_Anim01,
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
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Walk,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Confused,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
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
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Walk,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Confused,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
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
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Walk,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Confused,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
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
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Walk,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Idle,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Still,
            ANIM_Boo_Tan_Confused,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
            ANIM_Boo_Tan_Run,
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
            ANIM_Boo_Idle,
            ANIM_Boo_Walk,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Idle,
            ANIM_Boo_Idle,
            ANIM_Boo_Still,
            ANIM_Boo_Still,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
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
            ANIM_Boo_Idle,
            ANIM_Boo_Walk,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Idle,
            ANIM_Boo_Idle,
            ANIM_Boo_Still,
            ANIM_Boo_Still,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
            ANIM_Boo_Run,
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
        ANIM_WorldBow_Idle,
        ANIM_WorldBow_Walk,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Idle,
        ANIM_WorldBow_Idle,
        ANIM_WorldBow_Still,
        ANIM_WorldBow_Still,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
        ANIM_WorldBow_Run,
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
        ANIM_Bootler_Idle,
        ANIM_Bootler_Walk,
        ANIM_Bootler_Run,
        ANIM_Bootler_Run,
        ANIM_Bootler_Idle,
        ANIM_Bootler_Idle,
        ANIM_Bootler_Still,
        ANIM_Bootler_Still,
        ANIM_Bootler_Shock,
        ANIM_Bootler_Panic,
        ANIM_Bootler_Dejected,
        ANIM_Bootler_Quaver,
        ANIM_Bootler_Shock,
        ANIM_Bootler_Panic,
        ANIM_Bootler_Dejected,
        ANIM_Bootler_Quaver,
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
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Walk,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Dive,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
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
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Walk,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Dive,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
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
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Walk,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Idle,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Hurt,
        ANIM_Paragoomba_Hyper_Dive,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
        ANIM_Paragoomba_Hyper_Run,
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
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Still,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
        ANIM_WorldSkolar_Idle,
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
