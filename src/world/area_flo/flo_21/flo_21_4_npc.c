#include "flo_21.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/enemy/HuffNPuff.h"
#include "world/common/enemy/RuffPuff.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

NpcSettings N(NpcSettings_RuffPuff) = {
    .height = 24,
    .radius = 28,
    .level = 16,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_HuffNPuff) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/npc/StarSpirit.inc.c"

Vec3f N(Path_JumpOut)[] = {
    {  600.0,   104.0,    0.0 },
    {  575.0,   204.0,    0.0 },
    {  550.0,   104.0,    0.0 },
};

EvtScript N(EVS_PlayRumbleSounds) = {
    Label(0)
        Call(PlaySound, SOUND_HUFF_N_PUFF_JIGGLE)
        Call(ShakeCam, CAM_DEFAULT, 0, 15, Float(1.0))
        Wait(15)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_JumpOut) = {
    Call(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_HUFF_N_PUFF_EMERGE, SOUND_SPACE_DEFAULT)
    PlayEffect(EFFECT_SHOCKWAVE, 3, 650, 104, 0)
    Wait(15)
    Call(SetNpcJumpscale, NPC_HuffNPuff_02, Float(0.0))
    Call(NpcJump0, NPC_HuffNPuff_02, 650, 50, 0, 5)
    Call(SetNpcPos, NPC_HuffNPuff_01, 650, 50, 5)
    Call(SetNpcPos, NPC_HuffNPuff_02, 650, 50, 0)
    Call(SetNpcPos, NPC_HuffNPuff_03, 650, 50, 0)
    Call(SetNpcJumpscale, NPC_HuffNPuff_01, Float(0.0))
    Call(SetNpcJumpscale, NPC_HuffNPuff_02, Float(0.0))
    Call(SetNpcJumpscale, NPC_HuffNPuff_03, Float(0.0))
    Thread
        Call(NpcJump0, NPC_HuffNPuff_01, 650, 150, 5, 10)
    EndThread
    Thread
        Call(NpcJump0, NPC_HuffNPuff_02, 650, 150, 0, 10)
    EndThread
    Thread
        Call(NpcJump0, NPC_HuffNPuff_03, 650, 150, 0, 10)
    EndThread
    Thread
        Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
        Call(LoadPath, 30, Ref(N(Path_JumpOut)), ARRAY_COUNT(N(Path_JumpOut)), EASING_LINEAR)
        Label(0)
        Call(GetNextPathPos)
        Call(SetPlayerPos, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    EndThread
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Return
    End
};

EvtScript N(EVS_Scene_HuffNPuffAmbush) = {
    IfGe(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        Return
    EndIf
    Call(AwaitPlayerApproach, 650, 0, 30)
    Call(DisablePlayerInput, TRUE)
    Call(SetMusicTrack, 0, SONG_HUFF_N_PUFF_THEME, 0, 8)
    ExecGetTID(N(EVS_PlayRumbleSounds), LVar9)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(InterpPlayerYaw, 90, 1)
    Wait(5)
    Call(SetPlayerAnimation, ANIM_Mario1_Flail)
    Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar2, LVar3, LVar4)
    Call(SetPanTarget, CAM_DEFAULT, LVar2, LVar3, LVar4)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(MakeLerp, LVar2, 600, 20, EASING_LINEAR)
    Set(LVar2, LVar3)
    Set(LVar5, LVar3)
    Add(LVar5, 15)
    Loop(0)
        Call(UpdateLerp)
        Add(LVar3, 3)
        Call(SetPlayerPos, LVar0, LVar3, LVar4)
        IfGt(LVar3, LVar5)
            Set(LVar3, LVar2)
        EndIf
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar2, LVar4)
    EndLoop
    Call(func_802D2C14, 1)
    Call(SetPlayerPos, LVar0, LVar2, LVar4)
    Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Wait(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar0, 25)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(ShowMessageAtWorldPos, MSG_CH6_00CA, 630, 120, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(30.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10)
    Call(ShowMessageAtWorldPos, MSG_CH6_00CB, 630, 120, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(func_802D2C14, 0)
    Wait(10)
    Call(GetCurrentPartnerID, LVar0)
    IfNe(LVar0, PARTNER_LAKILESTER)
        Call(ShowMessageAtWorldPos, MSG_CH6_00CC, 630, 120, 0)
    Else
        Call(ShowMessageAtWorldPos, MSG_CH6_00CD, 630, 120, 0)
    EndIf
    ChildThread
        Wait(15)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 25)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
        Set(LVar3, 40)
        Loop(5)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar3)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Sub(LVar3, 10)
            Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar3)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Add(LVar3, 7)
        EndLoop
    EndChildThread
    ExecWait(N(EVS_HuffNPuff_JumpOut))
    KillThread(LVar9)
    Wait(30)
    Call(SetNpcVar, NPC_HuffNPuff_01, 0, 1)
    Call(DisablePlayerInput, FALSE)
    Wait(15)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_AnimateBodyScale) = {
    SetF(LVar0, Float(0.95))
    SetF(LVar1, Float(1.1))
    Label(0)
        Switch(MV_BossFightState)
            CaseEq(0)
                Set(LVar3, 10)
                Set(LVar2, 2)
            CaseEq(1)
                Set(LVar3, 5)
                Set(LVar2, 1)
            CaseDefault
                Return
        EndSwitch
        Set(LVar4, LVar3)
        Loop(LVar4)
            Call(SetNpcScale, NPC_HuffNPuff_01, LVar0, LVar1, 1)
            Call(SetNpcScale, NPC_HuffNPuff_02, LVar0, LVar1, 1)
            Call(SetNpcScale, NPC_HuffNPuff_03, LVar0, LVar1, 1)
            AddF(LVar0, Float(0.015))
            SubF(LVar1, Float(0.01))
            Wait(LVar2)
        EndLoop
        Set(LVar4, LVar3)
        Loop(LVar4)
            Call(SetNpcScale, NPC_HuffNPuff_01, LVar0, LVar1, 1)
            Call(SetNpcScale, NPC_HuffNPuff_02, LVar0, LVar1, 1)
            Call(SetNpcScale, NPC_HuffNPuff_03, LVar0, LVar1, 1)
            SubF(LVar0, Float(0.015))
            AddF(LVar1, Float(0.01))
            Wait(LVar2)
        EndLoop
        Goto(0)
    Return
    End
};

// start and end positions for each of the Ruff Puffs when HuffNPuff explodes
Vec2i N(BlowUpPositions)[] = {
    { 635, 165}, { 450, 120 },
    { 640, 170}, { 520, 270 },
    { 650, 175}, { 650, 275 },
    { 660, 170}, { 730, 275 },
    { 665, 165}, { 850, 120 },
    { 630, 150}, { 450, 155 },
    { 637, 150}, { 600, 275 },
    { 650, 150}, { 850, 155 },
    { 663, 150}, { 750, 270 },
    { 670, 150}, { 850, 195 },
    { 635, 135}, { 450, 195 },
    { 640, 130}, { 450, 235 },
    { 650, 125}, { 450, 270 },
    { 660, 130}, { 850, 270 },
    { 665, 135}, { 850, 235 },
};

Vec3i N(BeginAnimScaleX)[] = {
    { 10, 14, 7 },
    { 14,  5, 6 },
    {  5, 12, 6 },
    { 12,  5, 5 },
    {  5, 10, 5 },
    { 10,  5, 4 },
};

Vec2i N(LoopAnimScaleX)[] = {
    {  8, 10 },
    { 10,  8 },
};

Vec3i N(BeginAnimScaleY)[] = {
    { 10,  5, 7 },
    {  5, 14, 6 },
    { 14,  5, 6 },
    {  5, 12, 5 },
    { 12,  5, 5 },
    {  5, 10, 4 },
};

Vec2i N(LoopAnimScaleY)[] = {
    { 10,  6 },
    {  6, 10 },
};

EvtScript N(EVS_HuffNPuff_Defeat_Flashing) = {
    SetF(LVar0, 10)
    SetF(LVar1, 1)
    ChildThread
        Loop(8)
            Call(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_INVISIBLE, FALSE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_INVISIBLE, FALSE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_INVISIBLE, FALSE)
            Wait(LVar0)
            Call(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_INVISIBLE, TRUE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_INVISIBLE, TRUE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_INVISIBLE, TRUE)
            Wait(LVar1)
            SubF(LVar0, 0)
            AddF(LVar1, 0)
        EndLoop
        Loop(0)
            Call(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_INVISIBLE, FALSE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_INVISIBLE, FALSE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_INVISIBLE, FALSE)
            Wait(LVar0)
            Call(SetNpcFlagBits, NPC_HuffNPuff_01, NPC_FLAG_INVISIBLE, TRUE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_02, NPC_FLAG_INVISIBLE, TRUE)
            Call(SetNpcFlagBits, NPC_HuffNPuff_03, NPC_FLAG_INVISIBLE, TRUE)
            Wait(LVar1)
        EndLoop
    EndChildThread
    ChildThread
        Loop(0)
            Call(MakeLerp, 0, 255, 10, EASING_QUADRATIC_OUT)
            Loop(0)
                Call(UpdateLerp)
                Call(SetNpcImgFXParams, NPC_HuffNPuff_01, IMGFX_SET_WHITE_FADE, LVar0, LVar0, LVar0, 0)
                Call(SetNpcImgFXParams, NPC_HuffNPuff_02, IMGFX_SET_WHITE_FADE, LVar0, LVar0, LVar0, 0)
                Call(SetNpcImgFXParams, NPC_HuffNPuff_03, IMGFX_SET_WHITE_FADE, LVar0, LVar0, LVar0, 0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
        EndLoop
    EndChildThread
    Wait(100)
    Return
    End
};

EvtScript N(EVS_HuffNPuff_Defeat_AnimateScale) = {
    SetF(MV_HuffScaleX, Float(1.0))
    SetF(MV_HuffScaleY, Float(1.0))
    ChildThread
        UseBuf(Ref(N(BeginAnimScaleX)))
        Loop(ARRAY_COUNT(N(BeginAnimScaleX)))
            Call(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_HUFF_N_PUFF_JIGGLE, SOUND_SPACE_DEFAULT)
            BufRead3(LVar6, LVar7, LVar8)
            Call(MakeLerp, LVar6, LVar7, LVar8, EASING_SIN_OUT)
            Loop(0)
                Call(UpdateLerp)
                DivF(LVar0, 10)
                SetF(MV_HuffScaleX, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(1)
        EndLoop
        Loop(0)
            UseBuf(Ref(N(LoopAnimScaleX)))
            Loop(ARRAY_COUNT(N(LoopAnimScaleX)))
                Call(PlaySoundAtNpc, NPC_HuffNPuff_01, SOUND_HUFF_N_PUFF_JIGGLE, SOUND_SPACE_DEFAULT)
                BufRead2(LVar6, LVar7)
                Call(MakeLerp, LVar6, LVar7, 4, EASING_SIN_OUT)
                Loop(0)
                    Call(UpdateLerp)
                    DivF(LVar0, 10)
                    SetF(MV_HuffScaleX, LVar0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
            EndLoop
        EndLoop
    EndChildThread
    ChildThread
        UseBuf(Ref(N(BeginAnimScaleY)))
        Loop(ARRAY_COUNT(N(BeginAnimScaleY)))
            BufRead3(LVar6, LVar7, LVar8)
            Call(MakeLerp, LVar6, LVar7, LVar8, EASING_SIN_OUT)
            Loop(0)
                Call(UpdateLerp)
                DivF(LVar0, 10)
                SetF(MV_HuffScaleY, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(1)
        EndLoop
        Loop(0)
            UseBuf(Ref(N(LoopAnimScaleY)))
            Loop(ARRAY_COUNT(N(LoopAnimScaleY)))
                BufRead2(LVar6, LVar7)
                Call(MakeLerp, LVar6, LVar7, 4, EASING_SIN_OUT)
                Loop(0)
                    Call(UpdateLerp)
                    DivF(LVar0, 10)
                    SetF(MV_HuffScaleY, LVar0)
                    Wait(1)
                    IfEq(LVar1, 0)
                        BreakLoop
                    EndIf
                EndLoop
            EndLoop
        EndLoop
    EndChildThread
    Loop(100)
        Call(SetNpcScale, NPC_HuffNPuff_01, MV_HuffScaleX, MV_HuffScaleY, 1)
        Call(SetNpcScale, NPC_HuffNPuff_02, MV_HuffScaleX, MV_HuffScaleY, 1)
        Call(SetNpcScale, NPC_HuffNPuff_03, MV_HuffScaleX, MV_HuffScaleY, 1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HuffNPuff_Defeat_BlowUp) = {
    ChildThread
        Set(LVar1, 0)
        Loop(0)
            Set(LVar0, 3)
            Loop(15)
                Call(SetNpcRotation, LVar0, 0, LVar1, 0)
                Add(LVar0, 1)
            EndLoop
            Add(LVar1, 60)
            IfGt(LVar1, 360)
                Add(LVar1, -360)
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
    UseBuf(Ref(N(BlowUpPositions)))
    Set(LVar8, 3)
    // all except the last one
    Loop((ARRAY_COUNT(N(BlowUpPositions))/ 2) - 1)
        BufRead4(LVar1, LVar2, LVar3, LVar4)
        Thread
            Call(RandInt, 5, LVar5)
            Wait(LVar5)
            Call(SetNpcPos, LVar8, LVar1, LVar2, -30)
            Call(RandInt, 2, LVar5)
            Add(LVar5, 8)
            Call(PlaySoundAtNpc, LVar8, SOUND_RUFF_PUFF_FLY_A, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, LVar8, LVar3, LVar4, -15, LVar5)
            Call(SetNpcPos, LVar8, NPC_DISPOSE_LOCATION)
        EndThread
        Add(LVar8, 1)
    EndLoop
    Call(SetNpcPos, NPC_HuffNPuff_01, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_HuffNPuff_02, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_HuffNPuff_03, NPC_DISPOSE_LOCATION)
    // the last one
    BufRead4(LVar1, LVar2, LVar3, LVar4)
    Wait(5)
    Call(SetNpcPos, LVar8, LVar1, LVar2, -30)
    Call(PlaySoundAtNpc, LVar8, SOUND_RUFF_PUFF_FLY_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, LVar8, LVar3, LVar4, -15, 10)
    Call(SetNpcPos, LVar8, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_Scene_BossDefeated) = {
    Call(SetNpcAnimation, NPC_HuffNPuff_02, ANIM_HuffNPuff_Anim04)
    Call(SetNpcAnimation, NPC_HuffNPuff_01, ANIM_HuffNPuff_Anim05)
    Call(SetNpcAnimation, NPC_HuffNPuff_03, ANIM_HuffNPuff_Anim06)
    Call(GetNpcPos, NPC_HuffNPuff_01, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Add(LVar0, -15)
    Add(LVar2, 40)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-5.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_HuffNPuff_01, ANIM_HuffNPuff_Anim30, ANIM_HuffNPuff_Anim05, 256, -30, 30, MSG_CH6_00CE)
    Call(FadeOutMusic, 0, 1500)
    Set(MV_BossFightState, 2)
    Call(GetNpcPos, NPC_HuffNPuff_01, LVar0, LVar1, LVar2)
    Thread
        Set(LVar3, LVar0)
        Set(LVar4, LVar0)
        Add(LVar3, -35)
        Add(LVar4, 35)
        Loop(3)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2)
            Wait(12)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar3, LVar1, LVar2)
            Add(LVar3, 7)
            Wait(8)
            PlayEffect(EFFECT_EXPLOSION, 0, LVar4, LVar1, LVar2)
            Add(LVar4, -7)
            Wait(14)
        EndLoop
        PlayEffect(EFFECT_EXPLOSION, 2, LVar0, LVar1, LVar2)
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(1.5))
    EndThread
    Thread
        Wait(30)
        Loop(10)
            PlayEffect(EFFECT_SHIMMER_WAVE, 0, LVar0, LVar1, LVar2, 40, 65, 12, 15)
            Wait(7)
        EndLoop
    EndThread
    Exec(N(EVS_HuffNPuff_Defeat_Flashing))
    ExecWait(N(EVS_HuffNPuff_Defeat_AnimateScale))
    ExecWait(N(EVS_HuffNPuff_Defeat_BlowUp))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_NpcIdle_HuffNPuff_01) = {
    Label(0)
        Call(SetSelfVar, 0, 0)
        Loop(0)
            Call(GetSelfVar, 0, LVar0)
            IfNe(LVar0, 0)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Set(MV_BossFightState, 1)
        Call(StartBossBattle, SONG_HUFF_N_PUFF_BATTLE)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_HuffNPuff_Main) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_1, TRUE)
            Call(SetNpcYaw, NPC_PARTNER, 90)
            Call(GetPlayerPos, LVar0, LVar1, LVar3)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar3, -20)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar3)
            ExecWait(N(EVS_Scene_BossDefeated))
            Wait(50)
            Set(MV_BossDefeated, TRUE)
            Exec(N(EVS_TrySpawningStarCard))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_HuffNPuff_Aux) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Face) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_HuffNPuff_01)))
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_HuffNPuff_Main)))
        Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim02)
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Body) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_HuffNPuff_Aux)))
        Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim01)
        Exec(N(EVS_HuffNPuff_AnimateBodyScale))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_HuffNPuff_Arms) = {
    IfLt(GB_StoryProgress, STORY_CH6_DEFEATED_HUFF_N_PUFF)
        Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 1)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_HuffNPuff_Aux)))
        Call(SetNpcAnimation, NPC_SELF, ANIM_HuffNPuff_Anim19)
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_RuffPuff) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_RuffPuff_Dizzy)
    Call(SetNpcJumpscale, NPC_SELF, 0)
    Return
    End
};

AnimID N(ExtraAnims_HuffNPuff)[] = {
    ANIM_HuffNPuff_Anim00,
    ANIM_HuffNPuff_Anim01,
    ANIM_HuffNPuff_Anim02,
    ANIM_HuffNPuff_Anim04,
    ANIM_HuffNPuff_Anim05,
    ANIM_HuffNPuff_Anim31,
    ANIM_HuffNPuff_Anim19,
    ANIM_HuffNPuff_Anim2D,
    ANIM_LIST_END
};

NpcData N(NpcData_HuffNPuff)[] = {
    {
        .id = NPC_HuffNPuff_01,
        .pos = { 650.0f, NPC_DISPOSE_POS_Y, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Face),
        .settings = &N(NpcSettings_HuffNPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
    {
        .id = NPC_HuffNPuff_02,
        .pos = { 650.0f, 100.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Body),
        .settings = &N(NpcSettings_HuffNPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
    {
        .id = NPC_HuffNPuff_03,
        .pos = { 650.0f, NPC_DISPOSE_POS_Y, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_HuffNPuff_Arms),
        .settings = &N(NpcSettings_HuffNPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = HUFF_N_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_HuffNPuff),
    },
};

AnimID N(ExtraAnims_RuffPuff)[] = {
    ANIM_RuffPuff_Dizzy,
    ANIM_LIST_END
};

NpcData N(NpcData_RuffPuffs)[] = {
    {
        .id = NPC_RuffPuff_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_11,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_12,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_13,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_14,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
    {
        .id = NPC_RuffPuff_15,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RuffPuff),
        .settings = &N(NpcSettings_RuffPuff),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RUFF_PUFF_ANIMS,
        .extraAnimations = N(ExtraAnims_RuffPuff),
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HuffNPuff), BTL_FLO2_FORMATION_00, BTL_FLO2_STAGE_07),
    NPC_GROUP(N(NpcData_RuffPuffs), BTL_FLO_FORMATION_1F, BTL_FLO_STAGE_07),
    {}
};
