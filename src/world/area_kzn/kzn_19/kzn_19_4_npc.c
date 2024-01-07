#include "kzn_19.h"
#include "ld_addrs.h"
#include "sprite/player.h"
#include "include_asset.h"

#include "world/common/npc/Kolorado.h"
#include "world/common/npc/StarSpirit.h"
#include "world/common/enemy/LavaPiranha.h"

#include "world/common/lava_piranha/part1.inc.c"

INCLUDE_IMG("world/lava_piranha/vine.png", kzn_19_lava_piranha_vine_img);
INCLUDE_PAL("world/lava_piranha/vine.pal", kzn_19_lava_piranha_vine_pal);
#include "world/lava_piranha/vine.gfx.inc.c"

#include "world/common/lava_piranha/part2.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_IF_EQ(GF_KZN19_KoloradoDeadEnd, FALSE)
        EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 300)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0100)
        EVT_SET(GF_KZN19_KoloradoDeadEnd, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_LABEL(5)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_WAIT(30 * DT)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_WAIT(30 * DT)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_Escape) = {
    EVT_LABEL(0)
        EVT_IF_EQ(MV_BossDefeated, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 70, 25, 60)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0 / DT))
    EVT_CALL(NpcMoveTo, NPC_SELF, 170, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 280, 70, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 0, MSG_CH5_0107)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(NpcMoveTo, NPC_SELF, 535, -60, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 304, 25, -35)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAux, NPC_LavaPiranhaHead, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_0101)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_LETTER_CHECK(Kolorado)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kzn_19_ENTRY_0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_CASE_EQ(kzn_19_ENTRY_1)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Kolorado_Escape)))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath)[] = {
    {  250.0,    40.0,  -35.0 },
    {  410.0,    30.0,    0.0 },
    {  460.0,    40.0,  -30.0 },
    {  510.0,    50.0,  -72.0 },
    {  540.0,    60.0, -115.0 },
};

EvtScript N(EVS_Misstar_Escape) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, 185, 25, -35)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 155, 25, -35)
    EVT_CALL(SetNpcPos, NPC_Misstar, 250, 40, -35)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 380)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_SET(AF_KZN_BossRoomFloorBroken, TRUE)
    EVT_CALL(PlaySound, SOUND_LOOP_RUMBLE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(AF_KZN_BossRoomFloorBroken, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_CH5_0109)
    EVT_WAIT(10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 370, 25, 70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Misstar, 90, 0)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Misstar, NPC_DISPOSE_LOCATION)
    EVT_WAIT(15)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "world/common/lava_piranha/LoadAnimationFromTable.inc.c"

EvtScript N(EVS_PlayVinesAnim_Emerge) = {
    EVT_THREAD
        EVT_CALL(N(LoadAnimationFromTable), VINE_0, 15)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 220, 20, -40)
        EVT_CALL(N(LoadAnimationFromTable), VINE_3, 36)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(N(LoadAnimationFromTable), VINE_1, 32)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_END_THREAD
    EVT_WAIT(7)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 32)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 270, 34, -20)
    EVT_WAIT(62)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Idle) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_WAIT(10)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Talk) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 17)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Defeat) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 16)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 33)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 33)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 35)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_LavaPiranha) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_GT(LVar0, 150)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_LAVA_PIRANHA_THEME, 0, 8)
    EVT_CALL(LoadAnimatedModel, VINE_0, EVT_PTR(N(AnimModel_MainHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_1, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_1, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_2, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 270, -100, -20)
    EVT_CALL(SetAnimatorFlags, VINE_2, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_3, EVT_PTR(N(AnimModel_ExtraVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_3, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(N(CreateVineRenderer))
    EVT_CALL(SetSelfVar, 1, 1)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 40, 80, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, 200, -30, 0)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_LAVA_PIRANHA_EMERGE, SOUND_SPACE_DEFAULT, 330, 25, -50)
    EVT_EXEC(N(EVS_PlayVinesAnim_Emerge))
    EVT_WAIT(59)
    EVT_THREAD
        EVT_CALL(MakeLerp, 40, 0, 80, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(420.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-10.7))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0102)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10 * DT)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 256, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0103)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10 * DT)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_WAIT(10 * DT)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10 * DT)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 20)
        EVT_LOOP(3)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(440.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_LAVA_PIRANHA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_LavaPiranha) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
        EVT_CALL(N(MarkVineInterpolationDirty))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 7, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 8, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_SUB(LVar2, 2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_SUB(LVar2, 2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 0, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 0, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_LavaPiranha) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
            EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
            EVT_CALL(SetPlayerPos, 125, 25, -35)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 100, 25, -35)
            EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 125, 25, -35)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 205, 25, -35)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 470)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(EnableGroup, MODEL_ato, TRUE)
            EVT_CALL(EnableGroup, MODEL_naka, TRUE)
            EVT_CALL(EnableGroup, MODEL_mae, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(PlaySoundAt, SOUND_LAVA_PIRANHA_DEFEAT, SOUND_SPACE_DEFAULT, 330, 25, -50)
            EVT_EXEC(N(EVS_PlayVinesAnim_Defeat))
            EVT_WAIT(1)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_LavaPiranha)))
            EVT_SET(MV_BossDefeated, TRUE)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaPiranha) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kzn_19_ENTRY_1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
            EVT_MALLOC_ARRAY(64, LVar0)
            EVT_CALL(SetSelfVar, 0, LVar0)
            EVT_USE_ARRAY(LVar0)
            EVT_CALL(SetSelfVar, 1, 0)
            EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_LavaPiranha)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_LavaPiranha)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_LavaPiranha)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_05, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_LavaBud) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaBud) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_LavaBud)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { 380.0f, 250.0f, -330.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

AnimID N(ExtraAnims_LavaPiranha)[] = {
    ANIM_LavaPiranha_Anim03,
    ANIM_LavaPiranha_Anim0E,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_LavaBud)[] = {
    ANIM_LavaBud_Anim03,
    ANIM_LIST_END
};

NpcData N(NpcData_LavaPiranha)[] = {
    {
        .id = NPC_LavaPiranhaHead,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaPiranha),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_HEAD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaPiranha),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_01,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_02,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
};

NpcGroupList N(BossNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_LavaPiranha), BTL_KZN2_FORMATION_00, BTL_KZN2_STAGE_06),
    {}
};

NpcGroupList N(EscapeNPCs) = {
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
