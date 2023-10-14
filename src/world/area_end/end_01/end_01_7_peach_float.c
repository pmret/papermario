#include "end_01.h"

EvtScript N(EVS_ParadePhase_Toads1) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_HornPlayer1, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_HornPlayer2, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Drummer1, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Drummer2, NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_StandardBearer1, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_StandardBearer2, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapping, NPC_HornPlayer1, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_HornPlayer2, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Drummer1, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Drummer2, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_StandardBearer1, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_StandardBearer2, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FinalFloat_MushroomTop) = {
    EVT_CALL(EnableTexPanning, MODEL_mp1, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x400)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_MAIN, LVar0, 0)
        EVT_ADD(LVar1, 0x4400)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_AUX, LVar0, 0)
        EVT_WAIT(12)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FinalFloat_MushroomRim) = {
    EVT_CALL(EnableTexPanning, MODEL_mp2, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FinalFloat_Front) = {
    EVT_CALL(EnableTexPanning, MODEL_mp3, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_AUX, LVar0, 0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FinalFloat_Star) = {
    EVT_CALL(EnableTexPanning, MODEL_mp4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, 0, LVar0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FinalFloat_Sides) = {
    EVT_CALL(EnableTexPanning, MODEL_mp6, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x3000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_EXIT)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30 * DT)
    EVT_CALL(LoadPath, 60 * DT, EVT_PTR(N(TwinkFlightPath)), ARRAY_COUNT(N(TwinkFlightPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(70 * DT)
    EVT_CALL(NpcFlyTo, NPC_Twink, -249, 120, 0, 10 * DT, -10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Twink, 0, -500, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Mario) = {
    EVT_LOOP(5)
        EVT_CALL(InterpNpcYaw, NPC_Mario, 90, 7 * DT)
        EVT_WAIT(45 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Mario, 270, 7 * DT)
        EVT_WAIT(45 * DT)
    EVT_END_LOOP
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Surprise)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_LookUp)
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Mario, 90, 0)
    EVT_WAIT(70 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_WaveUp)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_LookUp)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Idle)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_NodYes)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_Idle)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Mario, ANIM_ParadeMario_WalkBack)
    EVT_CALL(GetNpcPos, NPC_Mario, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar2, -30)
    EVT_CALL(NpcMoveTo, NPC_Mario, LVar0, LVar2, 20)
    EVT_LOOP(7)
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcPos, NPC_Mario, LVar0, LVar1, LVar2)
        EVT_WAIT(5 * DT)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Mario, LVar0, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Peach) = {
    EVT_LOOP(5)
        EVT_CALL(InterpNpcYaw, NPC_Peach, 90, 7 * DT)
        EVT_WAIT(45 * DT)
        EVT_CALL(InterpNpcYaw, NPC_Peach, 270, 7 * DT)
        EVT_WAIT(45 * DT)
    EVT_END_LOOP
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeRaiseArms)
    EVT_WAIT(60 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Peach, 90, 0)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeWaveFast)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeIdle)
    EVT_WAIT(60 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Peach, 270, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeRaiseArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeTalk)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeLowerArms)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeIdle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeSlightBow)
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_ParadePeach_ShadeWalkBack)
    EVT_CALL(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar2, -30)
    EVT_CALL(NpcMoveTo, NPC_Peach, LVar0, LVar2, 20)
    EVT_LOOP(7)
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
        EVT_WAIT(5 * DT)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Peach, LVar0, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_MarioPeach) = {
    EVT_EXEC(N(EVS_TexPan_FinalFloat_MushroomTop))
    EVT_EXEC(N(EVS_TexPan_FinalFloat_MushroomRim))
    EVT_EXEC(N(EVS_TexPan_FinalFloat_Front))
    EVT_EXEC(N(EVS_TexPan_FinalFloat_Star))
    EVT_EXEC(N(EVS_TexPan_FinalFloat_Sides))
    EVT_EXEC(N(EVS_Peach))
    EVT_EXEC(N(EVS_Twink))
    EVT_EXEC_WAIT(N(EVS_Mario))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twirler) = {
    EVT_CHILD_THREAD
        EVT_CALL(EnableNpcShadow, LVar1, FALSE)
        EVT_CALL(SetNpcJumpscale, LVar1, EVT_FLOAT(0.5))
        EVT_LOOP(0)
            EVT_WAIT(30)
            EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
            EVT_ADD(LVar2, -7)
            EVT_CALL(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            EVT_ADD(LVar2, -25)
            EVT_CALL(NpcJump0, LVar1, LVar2, LVar3, LVar4, 40)
            EVT_CALL(SetNpcPos, LVar1, 0, -500, 0)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Walk)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Toss)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Catch)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Spin)
            EVT_WAIT(21)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Toss)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeTwirler_Catch)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetNpcSpeed, LVar0, EVT_FLOAT(PARADE_SCROLL_RATE / DT))
    EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, -600)
    EVT_CALL(NpcMoveTo, LVar0, LVar2, LVar4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StandardBearer) = {
    EVT_CALL(SetNpcSpeed, LVar0, EVT_FLOAT(PARADE_SCROLL_RATE / DT))
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, -600)
    EVT_CALL(NpcMoveTo, LVar0, LVar1, LVar2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Toads2) = {
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Twirler1, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Twirler2, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_Twirler3, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_StandardBearer3, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_StandardBearer4, NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Twirler1, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Twirler2, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_Twirler3, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_StandardBearer3, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_StandardBearer4, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_SET(LVar0, NPC_Twirler1)
    EVT_SET(LVar1, NPC_Baton1)
    EVT_EXEC(N(EVS_Twirler))
    EVT_SET(LVar0, NPC_Twirler2)
    EVT_SET(LVar1, NPC_Baton2)
    EVT_EXEC(N(EVS_Twirler))
    EVT_SET(LVar0, NPC_Twirler3)
    EVT_SET(LVar1, NPC_Baton3)
    EVT_EXEC(N(EVS_Twirler))
    EVT_SET(LVar0, NPC_StandardBearer3)
    EVT_EXEC(N(EVS_StandardBearer))
    EVT_SET(LVar0, NPC_StandardBearer4)
    EVT_EXEC(N(EVS_StandardBearer))
    EVT_SETF(LVar0, 0)
    EVT_LOOP(500)
        EVT_SUBF(LVar0, EVT_FLOAT(PARADE_SCROLL_RATE / DT))
        EVT_CALL(TranslateGroup, MODEL_kinoko, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MarioPeachExit) = {
    // walk away into the distance
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Mario, -259, -150, 240 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_Peach, -229, -150, 240 * DT)
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    // slowly pan camera up
    EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_ADDF(LVar1, EVT_FLOAT(0.334))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
