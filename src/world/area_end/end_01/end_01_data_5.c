#include "end_01.h"

EvtScript N(D_802481B0_E0D510) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_33, 3)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_34, 3)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_35, 3)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_36, 3)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_37, 4)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_38, 4)
    EVT_CALL(SetNpcPaletteSwapping, NPC_33, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_34, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_35, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_36, 1, 2, 10, 5, 10, 5, 0, 0)
    EVT_CALL(SetNpcPaletteSwapping, NPC_37, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_38, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248364_E0D6C4) = {
    EVT_CALL(EnableTexPanning, MODEL_mp1, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x400)
        EVT_CALL(SetTexPanOffset, 7, 0, LVar0, 0)
        EVT_ADD(LVar1, 0x4400)
        EVT_CALL(SetTexPanOffset, 7, 1, LVar0, 0)
        EVT_WAIT(12)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248420_E0D780) = {
    EVT_CALL(EnableTexPanning, MODEL_mp2, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, 14, 0, LVar0, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802484A0_E0D800) = {
    EVT_CALL(EnableTexPanning, MODEL_mp3, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, 6, 1, LVar0, 0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248520_E0D880) = {
    EVT_CALL(EnableTexPanning, MODEL_mp4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, 5, 0, 0, LVar0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802485A0_E0D900) = {
    EVT_CALL(EnableTexPanning, MODEL_mp6, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x3000)
        EVT_CALL(SetTexPanOffset, 13, 0, LVar0, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

Vec3f N(D_80248620_E0D980)[] = {
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

EvtScript N(D_802486C8_E0DA28) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -330)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(LoadPath, 60, EVT_PTR(N(D_80248620_E0D980)), ARRAY_COUNT(N(D_80248620_E0D980)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_3B, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_3B, 270, 0)
    EVT_WAIT(70)
    EVT_CALL(NpcFlyTo, NPC_3B, -249, 120, 0, 10, -10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_3B, 0, -500, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Mario) = {
    EVT_LOOP(5)
        EVT_CALL(InterpNpcYaw, NPC_39, 90, 7)
        EVT_WAIT(45)
        EVT_CALL(InterpNpcYaw, NPC_39, 270, 7)
        EVT_WAIT(45)
    EVT_END_LOOP
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_Surprise)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_LookUp)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_39, 90, 0)
    EVT_WAIT(70)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_WaveUp)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_LookUp)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_Idle)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_NodYes)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_Idle)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_39, ANIM_ParadeMario_WalkBack)
    EVT_CALL(GetNpcPos, NPC_39, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_ADD(LVar2, -30)
    EVT_CALL(NpcMoveTo, NPC_39, LVar0, LVar2, 20)
    EVT_LOOP(7)
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcPos, NPC_39, LVar0, LVar1, LVar2)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_39, LVar0, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Peach) = {
    EVT_LOOP(5)
        EVT_CALL(InterpNpcYaw, NPC_3A, 90, 7)
        EVT_WAIT(45)
        EVT_CALL(InterpNpcYaw, NPC_3A, 270, 7)
        EVT_WAIT(45)
    EVT_END_LOOP
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeRaiseArms)
    EVT_WAIT(60)
    EVT_CALL(InterpNpcYaw, NPC_3A, 90, 0)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeWaveFast)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeIdle)
    EVT_WAIT(60)
    EVT_CALL(InterpNpcYaw, NPC_3A, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeRaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeTalk)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeLowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeIdle)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeSlightBow)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_3A, ANIM_ParadePeach_ShadeWalkBack)
    EVT_CALL(GetNpcPos, NPC_3A, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_ADD(LVar2, -30)
    EVT_CALL(NpcMoveTo, NPC_3A, LVar0, LVar2, 20)
    EVT_LOOP(7)
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetNpcPos, NPC_3A, LVar0, LVar1, LVar2)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_3A, LVar0, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80248D1C) = {
    EVT_EXEC(N(D_80248364_E0D6C4))
    EVT_EXEC(N(D_80248420_E0D780))
    EVT_EXEC(N(D_802484A0_E0D800))
    EVT_EXEC(N(D_80248520_E0D880))
    EVT_EXEC(N(D_802485A0_E0D900))
    EVT_EXEC(N(EVS_Peach))
    EVT_EXEC(N(D_802486C8_E0DA28))
    EVT_EXEC_WAIT(N(EVS_Mario))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248D8C_E0E0EC) = {
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
    EVT_CALL(SetNpcSpeed, LVar0, EVT_FLOAT(0.6669922))
    EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, -600)
    EVT_CALL(NpcMoveTo, LVar0, LVar2, LVar4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80248FC8_E0E328) = {
    EVT_CALL(SetNpcSpeed, LVar0, EVT_FLOAT(0.6669922))
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, -600)
    EVT_CALL(NpcMoveTo, LVar0, LVar1, LVar2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80249034) = {
    EVT_CALL(SetNpcPaletteSwapMode, NPC_3C, 4)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_3D, 4)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_3E, 4)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_42, 4)
    EVT_CALL(SetNpcPaletteSwapMode, NPC_43, 4)
    EVT_CALL(SetNpcPaletteSwapping, NPC_3C, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_3D, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_3E, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_42, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_CALL(SetNpcPaletteSwapping, NPC_43, 1, 2, 10, 5, 10, 5, 4, 5)
    EVT_SET(LVar0, 60)
    EVT_SET(LVar1, 63)
    EVT_EXEC(N(D_80248D8C_E0E0EC))
    EVT_SET(LVar0, 61)
    EVT_SET(LVar1, 64)
    EVT_EXEC(N(D_80248D8C_E0E0EC))
    EVT_SET(LVar0, 62)
    EVT_SET(LVar1, 65)
    EVT_EXEC(N(D_80248D8C_E0E0EC))
    EVT_SET(LVar0, 66)
    EVT_EXEC(N(D_80248FC8_E0E328))
    EVT_SET(LVar0, 67)
    EVT_EXEC(N(D_80248FC8_E0E328))
    EVT_SETF(LVar0, 0)
    EVT_LOOP(500)
        EVT_SUBF(LVar0, EVT_FLOAT(0.6669922))
        EVT_CALL(TranslateGroup, MODEL_kinoko, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802492B0) = {
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_39, -259, -150, 240)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_3A, -229, -150, 240)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_ADDF(LVar1, EVT_FLOAT(0.33398438))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
