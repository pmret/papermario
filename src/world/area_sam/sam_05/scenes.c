#include "sam_05.h"
#include "effects.h"

EvtScript N(EVS_Scene_MonstarAppears) = {
    Set(LFlag0, false)
    Label(0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Wait(1)
    IfLt(LVar0, 450)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, true)
    Call(InterruptUsePartner)
    Call(SetMusic, 0, SONG_MONSTAR_THEME, 0, VOL_LEVEL_FULL)
    Call(ShowMessageAtScreenPos, MSG_CH7_00E0, 160, 40)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Idle1)
    Call(SetNpcPos, NPC_Monstar, 635, 85, 0)
    Call(NpcMoveTo, NPC_Monstar, 615, 0, 10 * DT)
    Label(2)
    Call(GetNpcPos, NPC_Monstar, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-15.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Add(LVar0, -25)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    IfEq(LFlag0, false)
        Call(SetNpcPos, NPC_Monstar, 615, 85, 0)
        Wait(1)
        Set(LFlag0, true)
    EndIf
    Call(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Talk, ANIM_Monstar_Idle1, 256, 50, 100, MSG_CH7_00E1)
    Call(SetPlayerPos, 495, 80, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Monstar, LVar3, LVar4, LVar5)
    AddF(LVar0, LVar3)
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    DivF(LVar0, Float(2.0))
    DivF(LVar1, Float(2.0))
    DivF(LVar2, Float(2.0))
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
#if VERSION_JP
    Call(SetCamDistance, CAM_DEFAULT, Float(375.0))
#else
    Call(SetCamDistance, CAM_DEFAULT, Float(425.0))
#endif
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5 * DT)
    Call(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Talk, ANIM_Monstar_Idle1, 256, 0, 100, MSG_CH7_00E2)
    Call(ShowChoice, MSG_Choice_0015)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_Monstar, ANIM_Monstar_HappyTalk, ANIM_Monstar_HappyTalk, 256, 0, 100, MSG_CH7_00E3)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-5.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Idle1)
        Exec(N(EVS_SetupMusic))
        Call(DisablePlayerInput, false)
        Label(4)
        Call(GetPlayerPos, LVar3, LVar4, LVar5)
        Wait(1)
        IfGt(LVar3, LVar0)
            Call(DisablePlayerInput, true)
            Call(InterruptUsePartner)
            Call(SetMusic, 0, SONG_MONSTAR_THEME, 0, VOL_LEVEL_FULL)
            Goto(2)
        EndIf
        IfGt(LVar3, 420)
            Goto(4)
        EndIf
        Call(SetNpcPos, NPC_Monstar, NPC_DISPOSE_LOCATION)
        Set(LFlag0, false)
        Goto(0)
    Else
        Call(CloseMessage)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Monstar_RearUp)
        Call(GetNpcPos, NPC_Monstar, LVar0, LVar1, LVar2)
        Add(LVar0, -35)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-12.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_RearUp, ANIM_Monstar_RearUp, 256, 0, 200, MSG_CH7_00E4)
        Call(SetNpcVar, NPC_Monstar, 0, 1)
    EndIf
    Return
    End
};

// npcID followed by initial pos Vec3i
s32 N(StarKidList)[] = {
    NPC_StarKid_01, 615, 129, 0,
    NPC_StarKid_02, 612, 157, 2,
    NPC_StarKid_03, 606, 146, 4,
    NPC_StarKid_04, 649, 140, 6,
    NPC_StarKid_05, 625, 145, 0,
    NPC_StarKid_06, 580, 131, 4,
    NPC_StarKid_07, 630,  88, 6,
    NPC_StarKid_08, 635, 134, 0,
    NPC_StarKid_09, 625, 121, 2,
    NPC_StarKid_10, 590, 122, 4,
    NPC_StarKid_11, 595, 108, 6,
    NPC_StarKid_12, 600, 132, 0,
    NPC_StarKid_13, 604,  99, 2,
    NPC_StarKid_14, 610, 114, 4,
    NPC_StarKid_15, 635, 112, 6,
    NPC_StarKid_16, 620,  96, 0,
    -1,
};

Vec3f N(RelativeFleePath)[] = {
    {    0.0,     0.0,    0.0 },
    {   40.0,    10.0,    0.0 },
    {   50.0,    15.0,    0.0 },
    {   70.0,    25.0,    0.0 },
    {   80.0,    30.0,    0.0 },
    {  100.0,    35.0,    0.0 },
    {  200.0,    45.0,    0.0 },
};

EvtScript N(EVS_StarKid_LookAroundPanic) = {
    Call(RandInt, 4, LVar0)
    Wait(LVar0)
    Loop(0)
        Call(InterpNpcYaw, LVarA, 90, 0)
        Wait(7 * DT)
        Call(InterpNpcYaw, LVarA, 270, 0)
        Wait(7 * DT)
    EndLoop
    Return
    End
};

EvtScript N(EVS_StarKid_RunAway) = {
    IfEq(LVarA, NPC_StarKid_01)
        Add(LVarB, 40 * DT)
    EndIf
    ExecGetTID(N(EVS_StarKid_LookAroundPanic), LVar9)
    Add(LVarB, 20 * DT)
    Wait(LVarB)
    KillThread(LVar9)
    Call(PlaySoundAtNpc, LVarA, SOUND_STAR_KID_FLYING, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, LVarA, LVar7, LVar8, LVar9)
    Call(LoadPath, 60 * DT, Ref(N(RelativeFleePath)), ARRAY_COUNT(N(RelativeFleePath)), EASING_LINEAR)
    Label(0)
        Call(GetNextPathPos)
        Add(LVar1, LVar7)
        Add(LVar2, LVar8)
        Add(LVar3, LVar9)
        Call(SetNpcPos, LVarA, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(SetNpcPos, LVarA, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, LVar0, false)
    Return
    End
};

EvtScript N(EVS_StarKid_SpawnSparkles) = {
    Loop(20)
        Call(RandInt, 80, LVar0)
        Call(RandInt, 80, LVar1)
        Add(LVar0, 575)
        Add(LVar1, 89)
        Add(LVar2, 0)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 7)
        Wait(2)
        Call(RandInt, 80, LVar0)
        Call(RandInt, 80, LVar1)
        Add(LVar0, 575)
        Add(LVar1, 89)
        Add(LVar2, 0)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar1, LVar2, 7)
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_StarKidsFlee) = {
    UseBuf(Ref(N(StarKidList)))
    Loop(0)
        BufRead4(LVar0, LVar1, LVar2, LVar3)
        IfEq(LVar0, -1)
            BreakLoop
        EndIf
        Call(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
#if VERSION_JP
        Call(EnableNpcShadow, LVar0, true)
#endif
    EndLoop
    Call(PlaySoundAtNpc, NPC_Monstar, SOUND_MONSTAR_BREAKS_APART, SOUND_SPACE_DEFAULT)
    Thread
        Call(NpcMoveTo, NPC_Monstar, 615, -5, 10 * DT)
    EndThread
    Exec(N(EVS_StarKid_SpawnSparkles))
    Call(MakeLerp, 220, 0, 90, EASING_COS_IN_OUT)
    Label(0)
    Call(UpdateLerp)
    Call(SetNpcVar, NPC_Monstar, 3, LVar0)
    Set(LVar2, 255)
    Sub(LVar2, LVar0)
    UseBuf(Ref(N(StarKidList)))
    Loop(0)
        BufRead4(LVarA, LVar9, LVar9, LVar9)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Call(SetNpcImgFXParams, LVarA, IMGFX_SET_ALPHA, LVar2, 0, 0, 0)
    EndLoop
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(SetNpcPos, NPC_Monstar, NPC_DISPOSE_LOCATION)
    Wait(10 * DT)
    UseBuf(Ref(N(StarKidList)))
    Set(LVarB, 0)
    Loop(0)
        BufRead4(LVarA, LVar9, LVar9, LVar9)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        Exec(N(EVS_StarKid_RunAway))
        Add(LVarB, 1)
    EndLoop
    Wait(100 * DT)
    Return
    End
};

EvtScript N(EVS_Scene_MonstarDefeated) = {
    Call(ClearDefeatedEnemies)
#if !VERSION_JP
    Call(SetNpcFlagBits, NPC_Monstar, NPC_FLAG_GRAVITY, false)
    Call(SetNpcPos, NPC_Monstar, 615, 87, -4)
#endif
    Call(SetNpcAnimation, NPC_SELF, ANIM_Monstar_Flail)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Monstar, LVar3, LVar4, LVar5)
    AddF(LVar0, LVar3)
    AddF(LVar1, LVar4)
    AddF(LVar2, LVar5)
    DivF(LVar0, Float(2.0))
    DivF(LVar1, Float(2.0))
    DivF(LVar2, Float(2.0))
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(375.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Monstar, ANIM_Monstar_Flail, ANIM_Monstar_Flail, 256, 170, 150, MSG_CH7_00E8)
    ExecWait(N(EVS_StarKidsFlee))
    Set(GB_StoryProgress, STORY_CH7_DEFEATED_MONSTAR)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-5.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerInput, false)
    Return
    End
};
