#include "end_00.h"

#include "world/common/atomic/WhaleGeyser.inc.c"

EvtScript N(EVS_FakeBowserFloat) = {
    Call(EnableModel, MODEL_o81, FALSE)
    Loop(0)
        Call(MakeLerp, 15, -15, 30, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -15, 15, 30, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateGroup, MODEL_g13, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_KoopaBros_Red) = {
    Call(EnableNpcShadow, NPC_KoopaBrosRed, FALSE)
    Wait(150)
    Call(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
    Add(LVar0, 5)
    Add(LVar1, 30)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    Wait(100)
    Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_ExitShell)
    Wait(60)
    Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_BurnHurt)
    Call(SetNpcJumpscale, NPC_KoopaBrosRed, Float(1.0))
    Call(GetNpcPos, NPC_KoopaBrosRed, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBrosRed, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_KoopaBrosRed, ANIM_KoopaBros_Red_BurnStill)
    Return
    End
};

EvtScript N(EVS_KoopaBros_Black) = {
    Call(EnableNpcShadow, NPC_KoopaBrosBlack, FALSE)
    Wait(155)
    Call(GetNpcPos, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2)
    Add(LVar0, -5)
    Add(LVar1, 30)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    Wait(95)
    Call(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_ExitShell)
    Wait(60)
    Call(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_BurnHurt)
    Call(SetNpcJumpscale, NPC_KoopaBrosBlack, Float(1.0))
    Call(GetNpcPos, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBrosBlack, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_KoopaBrosBlack, ANIM_KoopaBros_Black_BurnStill)
    Return
    End
};

EvtScript N(EVS_KoopaBros_Yellow) = {
    Call(EnableNpcShadow, NPC_KoopaBrosYellow, FALSE)
    Wait(160)
    Call(GetNpcPos, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2)
    Add(LVar0, 5)
    Add(LVar1, 30)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    Wait(90)
    Call(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_ExitShell)
    Wait(60)
    Call(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_BurnHurt)
    Call(SetNpcJumpscale, NPC_KoopaBrosYellow, Float(1.0))
    Call(GetNpcPos, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBrosYellow, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_KoopaBrosYellow, ANIM_KoopaBros_Yellow_BurnStill)
    Return
    End
};

EvtScript N(EVS_KoopaBros_Green) = {
    Call(EnableNpcShadow, NPC_KoopaBrosGreen, FALSE)
    Wait(165)
    Call(GetNpcPos, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2)
    Add(LVar0, -5)
    Add(LVar1, 30)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 40)
    Wait(85)
    Call(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_ExitShell)
    Wait(60)
    Call(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_BurnHurt)
    Call(SetNpcJumpscale, NPC_KoopaBrosGreen, Float(1.0))
    Call(GetNpcPos, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_KoopaBrosGreen, LVar0, LVar1, LVar2, 20)
    Call(SetNpcAnimation, NPC_KoopaBrosGreen, ANIM_KoopaBros_Green_BurnStill)
    Return
    End
};

EvtScript N(EVS_Bobomb1) = {
    Call(SetNpcFlagBits, NPC_Bobomb1, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Wait(180)
    Call(NpcMoveTo, NPC_Bobomb1, -1900, 43, 70)
    Call(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_AngryIdle)
    Wait(40)
    Call(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_Buildup)
    Wait(20)
    Call(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_FaceFwd)
    Call(GetNpcPos, NPC_Bobomb1, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    Call(EnableNpcShadow, NPC_Bobomb1, FALSE)
    Call(NpcFlyTo, NPC_Bobomb1, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    Call(SetNpcPos, NPC_Bobomb1, -1870, 200, 40)
    Call(NpcFlyTo, NPC_Bobomb1, -1870, 12, 40, 20, 0, EASING_LINEAR)
    Call(SetNpcYaw, NPC_Bobomb1, 270)
    Wait(10)
    Call(SetNpcAnimation, NPC_Bobomb1, ANIM_Bobomb_WaveFwd)
    Return
    End
};

EvtScript N(EVS_Bobomb2) = {
    Call(SetNpcFlagBits, NPC_Bobomb2, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Wait(180)
    Call(NpcMoveTo, NPC_Bobomb2, -1870, 43, 70)
    Call(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_AngryIdle)
    Wait(40)
    Call(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_Buildup)
    Wait(20)
    Call(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_FaceFwd)
    Call(GetNpcPos, NPC_Bobomb2, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    Call(EnableNpcShadow, NPC_Bobomb2, FALSE)
    Call(NpcFlyTo, NPC_Bobomb2, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    Call(SetNpcPos, NPC_Bobomb2, -1860, 200, 13)
    Call(NpcFlyTo, NPC_Bobomb2, -1860, 65, 13, 20, 0, EASING_LINEAR)
    Call(SetNpcYaw, NPC_Bobomb2, 270)
    Wait(10)
    Call(SetNpcAnimation, NPC_Bobomb2, ANIM_Bobomb_WaveFwd)
    Return
    End
};

EvtScript N(EVS_Bobomb3) = {
    Call(SetNpcFlagBits, NPC_Bobomb3, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Wait(180)
    Call(NpcMoveTo, NPC_Bobomb3, -1840, 43, 70)
    Call(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_AngryIdle)
    Wait(40)
    Call(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_Buildup)
    Wait(20)
    Call(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_FaceFwd)
    Call(GetNpcPos, NPC_Bobomb3, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    Call(EnableNpcShadow, NPC_Bobomb3, FALSE)
    Call(NpcFlyTo, NPC_Bobomb3, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    Call(SetNpcPos, NPC_Bobomb3, -1840, 200, 13)
    Call(NpcFlyTo, NPC_Bobomb3, -1840, 65, 13, 20, 0, EASING_LINEAR)
    Call(SetNpcYaw, NPC_Bobomb3, 90)
    Wait(10)
    Call(SetNpcAnimation, NPC_Bobomb3, ANIM_Bobomb_WaveFwd)
    Return
    End
};

EvtScript N(EVS_Bobomb4) = {
    Call(SetNpcFlagBits, NPC_Bobomb4, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
    Wait(180)
    Call(NpcMoveTo, NPC_Bobomb4, -1810, 43, 70)
    Call(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_AngryIdle)
    Wait(40)
    Call(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_Buildup)
    Wait(20)
    Call(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_FaceFwd)
    Call(GetNpcPos, NPC_Bobomb4, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_00, LVar0, LVar1, LVar2, 1, 20, 3, 2)
    Call(EnableNpcShadow, NPC_Bobomb4, FALSE)
    Call(NpcFlyTo, NPC_Bobomb4, LVar0, 200, LVar2, 10, 0, EASING_LINEAR)
    Call(SetNpcPos, NPC_Bobomb4, -1830, 200, 40)
    Call(NpcFlyTo, NPC_Bobomb4, -1830, 12, 40, 20, 0, EASING_LINEAR)
    Call(SetNpcYaw, NPC_Bobomb4, 90)
    Wait(10)
    Call(SetNpcAnimation, NPC_Bobomb4, ANIM_Bobomb_WaveFwd)
    Return
    End
};

EvtScript N(EVS_ParadePhase_KoopaBros) = {
    ExecGetTID(N(EVS_FakeBowserFloat), LVarA)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOOPA_BROS + 80)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    Exec(N(EVS_KoopaBros_Red))
    Exec(N(EVS_KoopaBros_Black))
    Exec(N(EVS_KoopaBros_Yellow))
    Exec(N(EVS_KoopaBros_Green))
    Exec(N(EVS_Bobomb1))
    Exec(N(EVS_Bobomb2))
    Exec(N(EVS_Bobomb3))
    Exec(N(EVS_Bobomb4))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOOPA_BROS + 550)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    Return
    End
};

EvtScript N(EVS_Whale_WagTail) = {
    Loop(0)
        Call(MakeLerp, 20, -20, 40, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o88, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, -20, 20, 40, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_o88, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_Kolorado) = {
    ExecGetTID(N(EVS_Whale_WagTail), LVarA)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOLORADO + 500)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar1, 15)
    Call(N(CreateWhaleGeyser), 0, -1565, LVar1, -200, 0, -1, 0, 30)
    Call(GetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
    Call(GetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
    Loop(5)
        Add(LVar3, 8)
        Call(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
        Add(LVar6, 8)
        Call(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
        Wait(1)
    EndLoop
    Call(SetNpcAnimation, NPC_Kolorado, ANIM_ParadeKolorado_Wave)
    Call(SetNpcAnimation, NPC_KoloradoWife, ANIM_ParadeKolorado_WifeWave)
    ChildThread
        Loop(0)
            Loop(20)
                Sub(LVar1, 1)
                Call(N(SetWhaleGeyserPos), LVar0, -1565, LVar1, -200)
                Sub(LVar3, 1)
                Call(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
                Sub(LVar6, 1)
                Call(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
                Wait(1)
            EndLoop
            Loop(20)
                Add(LVar1, 1)
                Call(N(SetWhaleGeyserPos), LVar0, -1565, LVar1, -200)
                Add(LVar3, 1)
                Call(SetNpcPos, NPC_Kolorado, LVar2, LVar3, LVar4)
                Add(LVar6, 1)
                Call(SetNpcPos, NPC_KoloradoWife, LVar5, LVar6, LVar7)
                Wait(1)
            EndLoop
        EndLoop
    EndChildThread
    Set(LVar3, LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOLORADO + 900)
            BreakLoop
        EndIf
    EndLoop
    Call(N(DisposeWhaleGeyser), LVar3)
    KillThread(LVarA)
    Return
    End
};
