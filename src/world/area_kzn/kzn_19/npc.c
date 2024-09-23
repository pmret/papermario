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
    IfEq(GF_KZN19_KoloradoDeadEnd, FALSE)
        Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 300)
            Wait(1)
            Goto(0)
        EndIf
        Call(DisablePlayerInput, TRUE)
        Call(NpcFacePlayer, NPC_SELF, 4)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0100)
        Set(GF_KZN19_KoloradoDeadEnd, TRUE)
        Call(DisablePlayerInput, FALSE)
        Call(SetSelfVar, 0, 0)
        Label(5)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Wait(30 * DT)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Wait(30 * DT)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Goto(5)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Kolorado_Escape) = {
    Label(0)
        IfEq(MV_BossDefeated, FALSE)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(60 * DT)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcPos, NPC_SELF, 70, 25, 60)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0 / DT))
    Call(NpcMoveTo, NPC_SELF, 170, 0, 0)
    Call(NpcMoveTo, NPC_SELF, 280, 70, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 0, MSG_CH5_0107)
    Call(UseSettingsFrom, CAM_DEFAULT, 450, 25, -20)
    Call(SetPanTarget, CAM_DEFAULT, 450, 25, -20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(NpcMoveTo, NPC_SELF, 535, -60, 0)
    Wait(20 * DT)
    Call(SetPanTarget, CAM_DEFAULT, 304, 25, -35)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAux, NPC_LavaPiranhaHead, 0)
    Wait(10 * DT)
    Call(FadeOutMusic, 0, 1500)
    Exec(N(EVS_TrySpawningStarCard))
    Wait(30)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_0101)
    Call(SetSelfVar, 0, 1)
    EVT_LETTER_CHECK(Kolorado)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(kzn_19_ENTRY_0)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
            CaseEq(kzn_19_ENTRY_1)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Kolorado_Escape)))
        EndSwitch
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

Vec3f N(FlightPath)[] = {
    {  250.0,    40.0,  -35.0 },
    {  410.0,    30.0,    0.0 },
    {  460.0,    40.0,  -30.0 },
    {  510.0,    50.0,  -72.0 },
    {  540.0,    60.0, -115.0 },
};

EvtScript N(EVS_Misstar_Escape) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, 185, 25, -35)
    Call(SetNpcPos, NPC_PARTNER, 155, 25, -35)
    Call(SetNpcPos, NPC_Misstar, 250, 40, -35)
    Call(UseSettingsFrom, CAM_DEFAULT, 217, 25, -35)
    Call(SetPanTarget, CAM_DEFAULT, 217, 25, -35)
    Call(SetCamDistance, CAM_DEFAULT, 380)
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Set(AF_KZN_BossRoomFloorBroken, TRUE)
    Call(PlaySound, SOUND_LOOP_RUMBLE)
    Loop(0)
        Wait(1)
        IfNe(AF_KZN_BossRoomFloorBroken, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(10)
    Call(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_CH5_0109)
    Wait(10)
    Call(SetPanTarget, CAM_DEFAULT, 370, 25, 70)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(InterpNpcYaw, NPC_Misstar, 90, 0)
    Call(LoadPath, 45, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_Misstar, NPC_DISPOSE_LOCATION)
    Wait(15)
    Call(ResetCam, CAM_DEFAULT, Float(3.0))
    Set(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

#include "world/common/lava_piranha/LoadAnimationFromTable.inc.c"

EvtScript N(EVS_PlayVinesAnim_Emerge) = {
    Thread
        Call(N(LoadAnimationFromTable), VINE_0, 15)
        Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
        Call(SetAnimatedModelRootPosition, VINE_0, 220, 20, -40)
        Call(N(LoadAnimationFromTable), VINE_3, 36)
        Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
        Call(SetAnimatedModelRootPosition, VINE_3, 220, 20, -40)
        Wait(59)
        Call(N(LoadAnimationFromTable), VINE_0, 0)
        Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
        Call(N(LoadAnimationFromTable), VINE_3, 34)
        Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EndThread
    Wait(5)
    Thread
        Call(N(LoadAnimationFromTable), VINE_1, 32)
        Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
        Call(SetAnimatedModelRootPosition, VINE_1, 220, 20, -40)
        Wait(59)
        Call(N(LoadAnimationFromTable), VINE_1, 31)
        Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EndThread
    Wait(7)
    Call(N(LoadAnimationFromTable), VINE_2, 32)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(SetAnimatedModelRootPosition, VINE_2, 270, 34, -20)
    Wait(62)
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Idle) = {
    Call(N(LoadAnimationFromTable), VINE_0, 0)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(N(LoadAnimationFromTable), VINE_1, 31)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(N(LoadAnimationFromTable), VINE_3, 34)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Wait(10)
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Talk) = {
    Call(N(LoadAnimationFromTable), VINE_0, 17)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Defeat) = {
    Call(N(LoadAnimationFromTable), VINE_0, 16)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(N(LoadAnimationFromTable), VINE_1, 33)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(N(LoadAnimationFromTable), VINE_2, 33)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(N(LoadAnimationFromTable), VINE_3, 35)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_LavaPiranha) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfGt(LVar0, 150)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(SetMusicTrack, 0, SONG_LAVA_PIRANHA_THEME, 0, 8)
    Call(LoadAnimatedModel, VINE_0, Ref(N(AnimModel_MainHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_0, 0)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(SetAnimatedModelRootPosition, VINE_0, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_1, Ref(N(AnimModel_SideHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_1, 31)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(SetAnimatedModelRootPosition, VINE_1, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_1, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_2, Ref(N(AnimModel_SideHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(SetAnimatedModelRootPosition, VINE_2, 270, -100, -20)
    Call(SetAnimatorFlags, VINE_2, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_3, Ref(N(AnimModel_ExtraVine)))
    Call(N(LoadAnimationFromTable), VINE_3, 34)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Call(SetAnimatedModelRootPosition, VINE_3, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_3, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(N(CreateVineRenderer))
    Call(SetSelfVar, 1, 1)
    Call(InterpPlayerYaw, 90, 0)
    Thread
        Wait(15 * DT)
        Call(UseSettingsFrom, CAM_DEFAULT, 300, 25, -20)
        Call(SetPanTarget, CAM_DEFAULT, 300, 25, -20)
        Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Call(MakeLerp, 0, 40, 80, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_poko, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(InterruptUsePartner)
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, 200, -30, 0)
        Call(InterpPlayerYaw, 90, 0)
    EndThread
    Call(PlaySoundAt, SOUND_LAVA_PIRANHA_EMERGE, SOUND_SPACE_DEFAULT, 330, 25, -50)
    Exec(N(EVS_PlayVinesAnim_Emerge))
    Wait(59)
    Thread
        Call(MakeLerp, 40, 0, 80, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_poko, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(40 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 235, 25, -20)
    Call(SetPanTarget, CAM_DEFAULT, 235, 25, -20)
    Call(SetCamDistance, CAM_DEFAULT, Float(420.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-10.7))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Exec(N(EVS_PlayVinesAnim_Talk))
    Call(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0102)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10 * DT)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 256, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Talk))
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0103)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10 * DT)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Talk))
    Wait(10 * DT)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10 * DT)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    ChildThread
        Set(LVar0, 20)
        Loop(3)
            Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar0)
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Sub(LVar0, 2)
            Call(SetCamDistance, CAM_DEFAULT, Float(440.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar0)
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Sub(LVar0, 2)
        EndLoop
    EndChildThread
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_LAVA_PIRANHA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcAux_LavaPiranha) = {
    Call(GetSelfVar, 0, LVar0)
    UseArray(LVar0)
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Label(0)
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        Call(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
        Call(N(MarkVineInterpolationDirty))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 0, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        Add(LVar2, 90)
        Call(N(SetVineBoneRot), VINE_0, 0, LVar0, 0, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 0, 1, 1, 1)
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 1, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 1, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 1, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 2, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 2, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 3, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 3, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 4, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 4, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 5, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 5, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 6, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 6, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 7, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 7, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_0, 8, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_0, 8, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_0, 8, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        Call(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 0, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        Add(LVar2, 90)
        Call(N(SetVineBoneRot), VINE_1, 0, LVar0, 0, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 0, 1, 1, 1)
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        Sub(LVar2, 2)
        Call(N(SetVineBonePos), VINE_1, 1, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 1, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 1, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 2, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 2, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 3, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 3, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 4, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 4, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 5, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 5, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_1, 6, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_1, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_1, 6, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        Call(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        Call(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 0, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        Add(LVar2, 90)
        Call(N(SetVineBoneRot), VINE_2, 0, LVar0, 0, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 0, 1, 1, 1)
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        Sub(LVar2, 2)
        Call(N(SetVineBonePos), VINE_2, 1, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 1, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 1, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 2, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 2, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 3, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 3, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 4, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 4, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 5, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 5, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_2, 6, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_2, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_2, 6, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_3, 0, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_3, 0, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_3, 0, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_3, 1, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_3, 1, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_3, 1, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_3, 2, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_3, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_3, 2, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_3, 3, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_3, 3, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_3, 3, Float(0.714), Float(0.714), Float(1.0))
        Call(GetAnimatedPositionByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBonePos), VINE_3, 4, LVar0, LVar1, LVar2)
        Call(GetAnimatedRotationByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneRot), VINE_3, 4, LVar0, LVar1, LVar2)
        Call(N(SetVineBoneScale), VINE_3, 4, Float(0.714), Float(0.714), Float(1.0))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_LavaPiranha) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
            Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
            Call(SetPlayerPos, 125, 25, -35)
            Call(SetNpcPos, NPC_PARTNER, 100, 25, -35)
            Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
            Call(UseSettingsFrom, CAM_DEFAULT, 125, 25, -35)
            Call(SetPanTarget, CAM_DEFAULT, 205, 25, -35)
            Call(SetCamDistance, CAM_DEFAULT, 470)
            Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-8.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
            Call(EnableGroup, MODEL_ato, TRUE)
            Call(EnableGroup, MODEL_naka, TRUE)
            Call(EnableGroup, MODEL_mae, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            Call(PlaySoundAt, SOUND_LAVA_PIRANHA_DEFEAT, SOUND_SPACE_DEFAULT, 330, 25, -50)
            Exec(N(EVS_PlayVinesAnim_Defeat))
            Wait(1)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_LavaPiranha)))
            Set(MV_BossDefeated, TRUE)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_LavaPiranha) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kzn_19_ENTRY_1)
        IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
            Call(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
            Call(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
            MallocArray(64, LVar0)
            Call(SetSelfVar, 0, LVar0)
            UseArray(LVar0)
            Call(SetSelfVar, 1, 0)
            Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_LavaPiranha)))
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_LavaPiranha)))
            Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_LavaPiranha)))
            Return
        EndIf
    EndIf
    Call(SetNpcPos, NPC_05, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_LavaBud) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_LavaBud) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_LavaBud)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
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
