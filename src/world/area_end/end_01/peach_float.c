#include "end_01.h"

EvtScript N(EVS_ParadePhase_Toads1) = {
    Wait(10)
    Call(SetNpcPaletteSwapMode, NPC_HornPlayer1, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_HornPlayer2, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Drummer1, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_Drummer2, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetNpcPaletteSwapMode, NPC_StandardBearer1, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapMode, NPC_StandardBearer2, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapping, NPC_HornPlayer1, 1, 2, 10, 5, 10, 5, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_HornPlayer2, 1, 2, 10, 5, 10, 5, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Drummer1, 1, 2, 10, 5, 10, 5, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_Drummer2, 1, 2, 10, 5, 10, 5, 0, 0)
    Call(SetNpcPaletteSwapping, NPC_StandardBearer1, 1, 2, 10, 5, 10, 5, 4, 5)
    Call(SetNpcPaletteSwapping, NPC_StandardBearer2, 1, 2, 10, 5, 10, 5, 4, 5)
    Return
    End
};

EvtScript N(EVS_TexPan_FinalFloat_MushroomTop) = {
    Call(EnableTexPanning, MODEL_mp1, true)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Add(LVar0, 0x400)
        Call(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_MAIN, LVar0, 0)
        Add(LVar1, 0x4400)
        Call(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_AUX, LVar0, 0)
        Wait(12)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FinalFloat_MushroomRim) = {
    Call(EnableTexPanning, MODEL_mp2, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x2000)
        Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        Wait(8)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FinalFloat_Front) = {
    Call(EnableTexPanning, MODEL_mp3, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x1000)
        Call(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_AUX, LVar0, 0)
        Wait(6)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FinalFloat_Star) = {
    Call(EnableTexPanning, MODEL_mp4, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x1000)
        Call(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, 0, LVar0)
        Wait(5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_FinalFloat_Sides) = {
    Call(EnableTexPanning, MODEL_mp6, true)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x3000)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
        Wait(8)
    EndLoop
    Return
    End
};

Vec3f N(TwinkFlightPath)[] = {
    { -389.0,   120.0,    0.0 },
    { -379.0,    90.0,    0.0 },
    { -349.0,    80.0,    0.0 },
    { -339.0,    90.0,    0.0 },
    { -349.0,   100.0,    0.0 },
    { -359.0,    90.0,    0.0 },
    { -349.0,    80.0,    0.0 },
    { -339.0,    80.0,    2.0 },
    { -329.0,    80.0,    2.0 },
    { -319.0,    90.0,    2.0 },
    { -329.0,   100.0,    2.0 },
    { -339.0,    90.0,    2.0 },
    { -329.0,    80.0,    2.0 },
    { -269.0,    90.0,    2.0 },
};

EvtScript N(EVS_Twink) = {
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_EXIT)
            BreakLoop
        EndIf
    EndLoop
    Wait(30 * DT)
    Call(LoadPath, 60 * DT, Ref(N(TwinkFlightPath)), ARRAY_COUNT(N(TwinkFlightPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10 * DT)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Wait(70 * DT)
    Call(NpcFlyTo, NPC_Twink, -249, 120, 0, 10 * DT, -10, EASING_LINEAR)
    Call(SetNpcPos, NPC_Twink, 0, -500, 0)
    Return
    End
};

EvtScript N(EVS_Mario) = {
    Loop(5)
        Call(InterpNpcYaw, NPC_Mario, 90, 7 * DT)
        Wait(45 * DT)
        Call(InterpNpcYaw, NPC_Mario, 270, 7 * DT)
        Wait(45 * DT)
    EndLoop
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Surprise)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_LookUp)
    Wait(30 * DT)
    Call(InterpNpcYaw, NPC_Mario, 90, 0)
    Wait(70 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_WaveUp)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_LookUp)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Idle)
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_NodYes)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Idle)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_WalkBack)
    Call(GetNpcPos, NPC_Mario, LVar0, LVar1, LVar2)
    Add(LVar0, 5)
    Add(LVar2, -30)
    Call(NpcMoveTo, NPC_Mario, LVar0, LVar2, 20)
    Loop(7)
        Add(LVar1, -5)
        Call(SetNpcPos, NPC_Mario, LVar0, LVar1, LVar2)
        Wait(5 * DT)
    EndLoop
    Call(SetNpcPos, NPC_Mario, LVar0, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_Peach) = {
    Loop(5)
        Call(InterpNpcYaw, NPC_Peach, 90, 7 * DT)
        Wait(45 * DT)
        Call(InterpNpcYaw, NPC_Peach, 270, 7 * DT)
        Wait(45 * DT)
    EndLoop
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeRaiseArms)
    Wait(60 * DT)
    Call(InterpNpcYaw, NPC_Peach, 90, 0)
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeWaveFast)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeIdle)
    Wait(60 * DT)
    Call(InterpNpcYaw, NPC_Peach, 270, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeRaiseArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeTalk)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeLowerArms)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeIdle)
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeSlightBow)
    Wait(40 * DT)
    Call(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeWalkBack)
    Call(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
    Add(LVar0, -5)
    Add(LVar2, -30)
    Call(NpcMoveTo, NPC_Peach, LVar0, LVar2, 20)
    Loop(7)
        Add(LVar1, -5)
        Call(SetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
        Wait(5 * DT)
    EndLoop
    Call(SetNpcPos, NPC_Peach, LVar0, 0, LVar2)
    Return
    End
};

EvtScript N(EVS_ParadePhase_MarioPeach) = {
    Exec(N(EVS_TexPan_FinalFloat_MushroomTop))
    Exec(N(EVS_TexPan_FinalFloat_MushroomRim))
    Exec(N(EVS_TexPan_FinalFloat_Front))
    Exec(N(EVS_TexPan_FinalFloat_Star))
    Exec(N(EVS_TexPan_FinalFloat_Sides))
    Exec(N(EVS_Peach))
    Exec(N(EVS_Twink))
    ExecWait(N(EVS_Mario))
    Return
    End
};

EvtScript N(EVS_Twirler) = {
    ChildThread
        Call(EnableNpcShadow, LVar1, false)
        Call(SetNpcJumpscale, LVar1, Float(0.5))
        Loop(0)
            Wait(30)
            Call(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
            Add(LVar2, -7)
            Call(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            Add(LVar2, -25)
            Call(NpcJump0, LVar1, LVar2, LVar3, LVar4, 40)
            Call(SetNpcPos, LVar1, 0, -500, 0)
        EndLoop
    EndChildThread
    ChildThread
        Loop(0)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Walk)
            Wait(30)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Toss)
            Wait(5)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Catch)
            Wait(5)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Spin)
            Wait(21)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Toss)
            Wait(5)
            Call(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Catch)
            Wait(5)
        EndLoop
    EndChildThread
    Call(SetNpcSpeed, LVar0, Float(PARADE_SCROLL_RATE / DT))
    Call(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    Add(LVar2, -600)
    Call(NpcMoveTo, LVar0, LVar2, LVar4, 0)
    Return
    End
};

EvtScript N(EVS_StandardBearer) = {
    Call(SetNpcSpeed, LVar0, Float(PARADE_SCROLL_RATE / DT))
    Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    Add(LVar1, -600)
    Call(NpcMoveTo, LVar0, LVar1, LVar2, 0)
    Return
    End
};

EvtScript N(EVS_ParadePhase_Toads2) = {
    Call(SetNpcPaletteSwapMode, NPC_Twirler1, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapMode, NPC_Twirler2, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapMode, NPC_Twirler3, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapMode, NPC_StandardBearer3, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapMode, NPC_StandardBearer4, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    Call(SetNpcPaletteSwapping, NPC_Twirler1, 1, 2, 10, 5, 10, 5, 4, 5)
    Call(SetNpcPaletteSwapping, NPC_Twirler2, 1, 2, 10, 5, 10, 5, 4, 5)
    Call(SetNpcPaletteSwapping, NPC_Twirler3, 1, 2, 10, 5, 10, 5, 4, 5)
    Call(SetNpcPaletteSwapping, NPC_StandardBearer3, 1, 2, 10, 5, 10, 5, 4, 5)
    Call(SetNpcPaletteSwapping, NPC_StandardBearer4, 1, 2, 10, 5, 10, 5, 4, 5)
    Set(LVar0, NPC_Twirler1)
    Set(LVar1, NPC_Baton1)
    Exec(N(EVS_Twirler))
    Set(LVar0, NPC_Twirler2)
    Set(LVar1, NPC_Baton2)
    Exec(N(EVS_Twirler))
    Set(LVar0, NPC_Twirler3)
    Set(LVar1, NPC_Baton3)
    Exec(N(EVS_Twirler))
    Set(LVar0, NPC_StandardBearer3)
    Exec(N(EVS_StandardBearer))
    Set(LVar0, NPC_StandardBearer4)
    Exec(N(EVS_StandardBearer))
    SetF(LVar0, 0)
    Loop(500)
        SubF(LVar0, Float(PARADE_SCROLL_RATE / DT))
        Call(TranslateGroup, MODEL_kinoko, LVar0, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MarioPeachExit) = {
    // walk away into the distance
    Thread
        Call(NpcMoveTo, NPC_Mario, -259, -150, 240 * DT)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Peach, -229, -150, 240 * DT)
    EndThread
    Wait(60 * DT)
    // slowly pan camera up
    Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
    SetF(LVar1, Float(0.0))
    Loop(0)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        AddF(LVar1, Float(0.334))
        Wait(1)
    EndLoop
    Return
    End
};
