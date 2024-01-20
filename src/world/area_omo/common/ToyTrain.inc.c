#include "common.h"
#include "sprite/player.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

#include "common/SetAngleClamped.inc.c"

#include "common/CompareFloats.inc.c"

#include "common/AdvanceBuffer.inc.c"

#include "common/SetPlayerStatusPosYaw.inc.c"

#include "common/SetNpcPosYaw.inc.c"

#include "common/CosInterpMinMax.inc.c"

#include "common/IsAOrBPressed.inc.c"

EvtScript N(EVS_Scene_RideTrain) = {
    MallocArray(20, LVar0)
    UseArray(LVar0)
    SetF(ArrayVar(2), Float(0.0))
    SetF(ArrayVar(3), Float(0.0))
    SetF(ArrayVar(7), Float(0.0))
    SetF(ArrayVar(8), Float(0.0))
    SetF(ArrayVar(14), Float(0.0))
    SetF(ArrayVar(15), Float(0.0))
    SetF(ArrayVar(16), Float(0.0))
    Set(AF_OMO_03, FALSE)
    Label(0)
        Switch(MV_TrainUnk_00)
            CaseEq(0)
                UseBuf(MV_TrainUnk_01)
                BufRead3(LVar0, LVar1, LVar2)
                SetF(ArrayVar(0), LVar0)
                SetF(ArrayVar(1), LVar1)
                Call(AddVectorPolar, ArrayVar(0), ArrayVar(1), Float(40.0), LVar2)
                SetF(ArrayVar(5), LVar0)
                SetF(ArrayVar(6), LVar1)
                SetF(LVar3, LVar2)
                AddF(LVar3, Float(180.0))
                Call(AddVectorPolar, ArrayVar(5), ArrayVar(6), Float(40.0), LVar3)
                SetF(ArrayVar(11), LVar0)
                SetF(ArrayVar(12), LVar1)
                SetF(MV_TrainPos, ArrayVar(11))
                SetF(MV_TrainUnk_0C, ArrayVar(12))
                SetF(MV_TrainUnk_0D, LVar2)
                SetF(ArrayVar(17), Float(0.0))
                Label(11)
                    BufRead2(LVar2, LVar3)
                    IfEq(LVar2, -1)
                        Goto(12)
                    EndIf
                    Call(GetDist2D, LVar4, LVar0, LVar1, LVar2, LVar3)
                    AddF(ArrayVar(17), LVar4)
                    SetF(LVar0, LVar2)
                    SetF(LVar1, LVar3)
                    Goto(11)
                Label(12)
                SubF(ArrayVar(17), Float(40.0))
                SetF(ArrayVar(10), Float(0.0))
                SetF(ArrayVar(13), Float(0.0))
                Set(ArrayVar(18), 0)
                IfEq(MF_TrainUnk_00, TRUE)
                    Set(MV_TrainUnk_00, 1)
                EndIf
            CaseEq(1)
                UseBuf(MV_TrainUnk_01)
                Call(N(AdvanceBuffer), 3, 0, 0)
                BufRead2(LVar0, LVar1)
                IfEq(LVar0, -1)
                    Set(MV_TrainUnk_00, 100)
                    Set(MF_TrainUnk_00, FALSE)
                Else
                    SetF(ArrayVar(2), LVar0)
                    SetF(ArrayVar(3), LVar1)
                    Set(ArrayVar(4), 1)
                    SetF(ArrayVar(7), LVar0)
                    SetF(ArrayVar(8), LVar1)
                    Set(ArrayVar(9), 1)
                    Set(MV_TrainUnk_00, 10)
                EndIf
            CaseEq(10)
                Switch(MV_TrainUnk_02)
                    CaseEq(0)
                        SetF(ArrayVar(10), Float(10.0))
                    CaseEq(1)
                        Call(N(CosInterpMinMax), ArrayVar(18), ArrayVar(10), Float(0.0), Float(10.0), 100, 1, Float(0.0))
                        Add(ArrayVar(18), 1)
                    CaseEq(2)
                        Set(LVar0, ArrayVar(13))
                        Set(LVar1, ArrayVar(17))
                        Call(N(CosInterpMinMax), LVar0, ArrayVar(10), Float(10.0), Float(2.0), LVar1, 0, Float(0.0))
                    CaseEq(3)
                        Set(LVar0, ArrayVar(13))
                        Set(LVar1, ArrayVar(17))
                        Div(LVar1, 2)
                        Call(N(CosInterpMinMax), LVar0, ArrayVar(10), Float(1.0), Float(10.0), LVar1, 0, Float(0.0))
                EndSwitch
                Call(GetDist2D, LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                Call(N(CompareFloats), LVar0, ArrayVar(10), LVar2)
                IfEq(LVar2, 1)
                    Call(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                    Call(AddVectorPolar, ArrayVar(0), ArrayVar(1), ArrayVar(10), LVar0)
                Else
                    SetF(LVar1, ArrayVar(10))
                    SubF(LVar1, LVar0)
                    SetF(ArrayVar(0), ArrayVar(2))
                    SetF(ArrayVar(1), ArrayVar(3))
                    UseBuf(MV_TrainUnk_01)
                    Call(N(AdvanceBuffer), 3, 2, ArrayVar(4))
                    BufRead2(ArrayVar(2), ArrayVar(3))
                    Add(ArrayVar(4), 1)
                    IfEq(ArrayVar(2), -1)
                        Set(MV_TrainUnk_00, 100)
                        Set(MF_TrainUnk_00, FALSE)
                        Set(LFlag1, TRUE)
                    Else
                        Call(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(2), ArrayVar(3))
                        Call(AddVectorPolar, ArrayVar(0), ArrayVar(1), LVar1, LVar0)
                    EndIf
                EndIf
                Call(GetDist2D, LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                Call(N(CompareFloats), LVar0, ArrayVar(10), LVar2)
                IfEq(LVar2, 1)
                    Call(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                    Call(AddVectorPolar, ArrayVar(5), ArrayVar(6), ArrayVar(10), LVar0)
                Else
                    SetF(LVar1, ArrayVar(10))
                    SubF(LVar1, LVar0)
                    SetF(ArrayVar(5), ArrayVar(7))
                    SetF(ArrayVar(6), ArrayVar(8))
                    UseBuf(MV_TrainUnk_01)
                    Call(N(AdvanceBuffer), 3, 2, ArrayVar(9))
                    BufRead2(ArrayVar(7), ArrayVar(8))
                    Add(ArrayVar(9), 1)
                    IfEq(ArrayVar(7), -1)
                        Set(MV_TrainUnk_00, 100)
                        Set(MF_TrainUnk_00, FALSE)
                        Set(LFlag1, FALSE)
                    Else
                        Call(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(7), ArrayVar(8))
                        Call(AddVectorPolar, ArrayVar(5), ArrayVar(6), LVar1, LVar0)
                    EndIf
                EndIf
                IfEq(MV_TrainUnk_00, 100)
                    IfEq(LFlag1, TRUE)
                        Call(N(SetAngleClamped), LVar0, ArrayVar(0), ArrayVar(1), ArrayVar(5), ArrayVar(6))
                        SetF(ArrayVar(5), ArrayVar(0))
                        SetF(ArrayVar(6), ArrayVar(1))
                        Call(AddVectorPolar, ArrayVar(5), ArrayVar(6), Float(80.0), LVar0)
                    Else
                        Call(N(SetAngleClamped), LVar0, ArrayVar(5), ArrayVar(6), ArrayVar(0), ArrayVar(1))
                        SetF(ArrayVar(0), ArrayVar(5))
                        SetF(ArrayVar(1), ArrayVar(6))
                        Call(AddVectorPolar, ArrayVar(0), ArrayVar(1), Float(80.0), LVar0)
                    EndIf
                EndIf
                SetF(LVar0, ArrayVar(0))
                SetF(LVar1, ArrayVar(1))
                AddF(LVar0, ArrayVar(5))
                AddF(LVar1, ArrayVar(6))
                DivF(LVar0, Float(2.0))
                DivF(LVar1, Float(2.0))
                Call(N(SetAngleClamped), LVar2, ArrayVar(5), ArrayVar(6), ArrayVar(0), ArrayVar(1))
                SetF(MV_TrainPos, LVar0)
                SetF(MV_TrainUnk_0C, LVar1)
                SetF(MV_TrainUnk_0D, LVar2)
                Call(GetDist2D, LVar3, LVar0, LVar1, ArrayVar(11), ArrayVar(12))
                AddF(ArrayVar(13), LVar3)
                SetF(ArrayVar(14), ArrayVar(13))
                MulF(ArrayVar(14), Float(1.432))
                IfEq(LFlag0, FALSE)
                    SetF(LVar0, ArrayVar(10))
                    IfLt(LVar0, 1)
                        SetF(LVar0, Float(1.0))
                    EndIf
                    DivF(LVar0, Float(3.0))
                    SubF(ArrayVar(15), LVar0)
                    IfLt(ArrayVar(15), -10)
                        SetF(ArrayVar(15), Float(-10.0))
                        Set(LFlag0, TRUE)
                        IfEq(AF_OMO_03, FALSE)
                            Call(PlaySound, SOUND_OMO_TOY_TRAIN_WHISTLE_A)
                        Else
                            Call(PlaySound, SOUND_OMO_TOY_TRAIN_WHISTLE_B)
                        EndIf
                    EndIf
                Else
                    SetF(LVar0, ArrayVar(10))
                    IfLt(LVar0, 1)
                        SetF(LVar0, Float(1.0))
                    EndIf
                    DivF(LVar0, Float(3.0))
                    AddF(ArrayVar(15), LVar0)
                    IfGt(ArrayVar(15), 10)
                        SetF(ArrayVar(15), Float(10.0))
                        Set(LFlag0, FALSE)
                        IfEq(AF_OMO_03, FALSE)
                            Call(PlaySound, SOUND_OMO_TOY_TRAIN_CLICK)
                            Set(AF_OMO_03, TRUE)
                        Else
                            Call(PlaySound, SOUND_OMO_TOY_TRAIN_CLICK)
                            Set(AF_OMO_03, FALSE)
                        EndIf
                    EndIf
                EndIf
                SetF(LVar0, MV_TrainPos)
                SetF(LVar1, MV_TrainUnk_0C)
                SetF(LVar2, MV_TrainUnk_0D)
                Call(AddVectorPolar, LVar0, LVar1, Float(15.0), LVar2)
                Call(N(SetPlayerStatusPosYaw), LVar0, 50, LVar1, MV_TrainUnk_0D)
                SetF(LVar0, MV_TrainPos)
                SetF(LVar1, MV_TrainUnk_0C)
                SetF(LVar2, MV_TrainUnk_0D)
                AddF(LVar2, Float(180.0))
                Call(AddVectorPolar, LVar0, LVar1, Float(15.0), LVar2)
                Call(N(SetNpcPosYaw), -4, LVar0, 50, LVar1, MV_TrainUnk_0D)
                SetF(LVar0, MV_TrainPos)
                SetF(LVar1, MV_TrainUnk_0C)
                SetF(LVar2, MV_TrainUnk_0D)
                IfLt(LVar2, 180)
                    AddF(LVar2, Float(90.0))
                Else
                    SubF(LVar2, Float(90.0))
                EndIf
                Call(AddVectorPolar, LVar0, LVar1, Float(20.0), LVar2)
                Call(N(SetNpcPosYaw), 0, LVar0, 50, LVar1, MV_TrainUnk_0D)
            CaseEq(100)
        EndSwitch
        Call(TranslateGroup, MODEL_p2, Float(79.1), Float(-27.93), Float(-29.53))
        Call(TranslateGroup, MODEL_p3, Float(-35.1), Float(-27.93), Float(-29.53))
        Call(RotateGroup, MODEL_p2, Float(-45.0), Float(0.0), Float(0.0), Float(1.0))
        Call(RotateGroup, MODEL_p3, Float(45.0), Float(0.0), Float(0.0), Float(1.0))
        Call(TranslateGroup, MODEL_p5, Float(40.5), Float(-20.0), Float(-0.4))
        Call(TranslateGroup, MODEL_p6, Float(-39.5), Float(-20.0), Float(-0.4))
        Call(TranslateGroup, MODEL_popo, MV_TrainPos, Float(10.0), MV_TrainUnk_0C)
        IfLt(MV_TrainUnk_0D, 180)
            SetF(LVar1, MV_TrainUnk_0D)
            SubF(LVar1, Float(90.0))
            Call(RotateGroup, MODEL_popo, LVar1, Float(0.0), Float(-1.0), Float(0.0))
        Else
            SetF(LVar1, MV_TrainUnk_0D)
            SubF(LVar1, Float(180.0))
            SubF(LVar1, Float(90.0))
            Call(RotateGroup, MODEL_popo, LVar1, Float(0.0), Float(-1.0), Float(0.0))
        EndIf
        Call(RotateGroup, MODEL_p2, Float(45.0), Float(0.0), Float(0.0), Float(1.0))
        Call(RotateGroup, MODEL_p3, Float(-45.0), Float(0.0), Float(0.0), Float(1.0))
        Call(TranslateGroup, MODEL_p2, Float(-79.1), Float(27.93), Float(29.53))
        Call(TranslateGroup, MODEL_p3, Float(35.1), Float(27.93), Float(29.53))
        Call(TranslateGroup, MODEL_p5, Float(-40.5), Float(20.0), Float(0.4))
        Call(TranslateGroup, MODEL_p6, Float(39.5), Float(20.0), Float(0.4))
        IfLt(MV_TrainUnk_0D, 180)
            Call(RotateGroup, MODEL_p5, ArrayVar(14), Float(0.0), Float(0.0), Float(-1.0))
            Call(RotateGroup, MODEL_p6, ArrayVar(14), Float(0.0), Float(0.0), Float(-1.0))
        Else
            Call(RotateGroup, MODEL_p5, ArrayVar(14), Float(0.0), Float(0.0), Float(1.0))
            Call(RotateGroup, MODEL_p6, ArrayVar(14), Float(0.0), Float(0.0), Float(1.0))
        EndIf
        Call(TranslateGroup, MODEL_p2, Float(0.0), ArrayVar(15), Float(0.0))
        SetF(LVar0, ArrayVar(15))
        MulF(LVar0, Float(-1.0))
        Call(TranslateGroup, MODEL_p3, Float(0.0), LVar0, Float(0.0))
        SetF(LVar0, ArrayVar(10))
        IfLt(LVar0, 1)
            SetF(LVar0, Float(1.0))
        EndIf
        AddF(ArrayVar(16), LVar0)
        IfGt(ArrayVar(16), 360)
            SubF(ArrayVar(16), Float(360.0))
        EndIf
        Call(RotateGroup, MODEL_p4, ArrayVar(16), Float(0.0), Float(1.0), Float(0.0))
        SetF(ArrayVar(11), MV_TrainPos)
        SetF(ArrayVar(12), MV_TrainUnk_0C)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_TrainUnk_A) = {
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_TrainUnk_B) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(MakeLerp, 0, LVar1, 45, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_TrainUnk_C) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(MakeLerp, LVar1, 0, 40, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(GetPlayerPos, LVar2, LVar3, LVar4)
        Call(SetCamTarget, CAM_DEFAULT, LVar2, LVar0, LVar4)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, 0, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TrainUnk_D) = {
    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Thread
        UseBuf(LVar0)
        BufRead3(LVar1, LVar2, LVar3)
        Call(AddVectorPolar, LVar1, LVar2, Float(15.0), LVar3)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(SetPlayerSpeed, Float(4.0))
        Call(PlayerMoveTo, LVar1, LVar2, 0)
        Call(SetPlayerSpeed, Float(0.7))
        Call(PlayerMoveTo, LVar1, LVar2, 0)
        Call(SetPlayerPos, LVar1, 50, LVar2)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(InterpPlayerYaw, LVar3, 0)
    EndThread
    Wait(5)
    UseBuf(LVar0)
    BufRead3(LVar1, LVar2, LVar3)
    SetF(LVarA, LVar3)
    AddF(LVar3, Float(180.0))
    Call(AddVectorPolar, LVar1, LVar2, Float(15.0), LVar3)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.7))
    Call(NpcJump0, NPC_PARTNER, LVar1, 50, LVar2, 10)
    Call(SetNpcSpeed, NPC_PARTNER, Float(0.5))
    Call(NpcMoveTo, NPC_PARTNER, LVar1, LVar2, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    Wait(5)
    UseBuf(LVar0)
    BufRead3(LVar1, LVar2, LVar3)
    SetF(LVarA, LVar3)
    IfLt(LVar3, 180)
        AddF(LVar3, Float(90.0))
    Else
        SubF(LVar3, Float(90.0))
    EndIf
    SetF(LVar4, LVar1)
    SetF(LVar5, LVar2)
    SetF(LVar6, LVar3)
    Call(AddVectorPolar, LVar1, LVar2, Float(100.0), LVar3)
    Call(SetNpcSpeed, NPC_Conductor, Float(3.0))
    Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
    Call(NpcMoveTo, NPC_Conductor, LVar1, LVar2, 0)
    Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    Call(AddVectorPolar, LVar4, LVar5, Float(20.0), LVar6)
    Call(SetNpcJumpscale, NPC_Conductor, Float(0.7))
    Call(NpcJump0, NPC_Conductor, LVar4, 50, LVar5, 10)
    Call(InterpNpcYaw, NPC_Conductor, LVarA, 0)
    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_0009)
    Call(PlaySound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    Wait(10)
    Return
    End
};

#ifdef INCLUDE_ALTERNATES
EvtScript N(EVS_TrainUnk_AltD) = {
    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Set(AF_OMO_06, FALSE)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLt(LVar2, 50)
        UseBuf(LVar9)
        BufRead4(LVar3, LVar4, LVar5, LVar6)
        Call(SetPlayerSpeed, Float(2.5))
        Call(PlayerMoveTo, LVar3, LVar4, 0)
        Call(SetPlayerJumpscale, Float(1.0))
        Call(PlayerJump, LVar5, 50, LVar6, 15)
    EndIf
    Thread
        UseBuf(LVar0)
        BufRead3(LVar1, LVar2, LVar3)
        Call(AddVectorPolar, LVar1, LVar2, Float(15.0), LVar3)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(SetPlayerSpeed, Float(4.0))
        Call(PlayerMoveTo, LVar1, LVar2, 0)
        Call(SetPlayerSpeed, Float(0.7))
        Call(PlayerMoveTo, LVar1, LVar2, 0)
        Call(SetPlayerPos, LVar1, 50, LVar2)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(InterpPlayerYaw, LVar3, 0)
    EndThread
    Wait(5)
    UseBuf(LVar0)
    BufRead3(LVar1, LVar2, LVar3)
    SetF(LVarA, LVar3)
    AddF(LVar3, Float(180.0))
    Call(AddVectorPolar, LVar1, LVar2, Float(15.0), LVar3)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.7))
    Call(NpcJump0, NPC_PARTNER, LVar1, 50, LVar2, 10)
    Call(SetNpcSpeed, NPC_PARTNER, Float(0.1))
    Call(NpcMoveTo, NPC_PARTNER, LVar1, LVar2, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(InterpNpcYaw, NPC_PARTNER, LVarA, 0)
    Wait(5)
    UseBuf(LVar0)
    BufRead3(LVar1, LVar2, LVar3)
    SetF(LVarA, LVar3)
    AddF(LVar3, Float(90.0))
    SetF(LVar4, LVar1)
    SetF(LVar5, LVar2)
    SetF(LVar6, LVar3)
    Call(AddVectorPolar, LVar1, LVar2, Float(60.0), LVar3)
    Call(SetNpcSpeed, NPC_Conductor, Float(3.0))
    Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
    Call(NpcMoveTo, NPC_Conductor, LVar1, LVar2, 0)
    Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    Call(AddVectorPolar, LVar4, LVar5, Float(20.0), LVar6)
    Call(SetNpcJumpscale, NPC_Conductor, Float(0.7))
    Call(NpcJump0, NPC_Conductor, LVar4, 50, LVar5, 10)
    Call(InterpNpcYaw, NPC_Conductor, LVarA, 0)
    Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 5, MSG_CH4_0009)
    Call(PlaySound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    Call(SetMusicTrack, 0, SONG_TOYBOX_TRAIN, 0, 8)
    Wait(10)
    Return
    End
};
#endif

EvtScript N(EVS_TrainUnk_E) = {
    Call(StopSound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    SetF(LVar0, MV_TrainPos)
    SetF(LVar1, MV_TrainUnk_0C)
    SetF(LVar2, MV_TrainUnk_0D)
    IfLt(LVar2, 180)
        AddF(LVar2, Float(90.0))
    Else
        SubF(LVar2, Float(90.0))
    EndIf
    Call(AddVectorPolar, LVar0, LVar1, Float(100.0), LVar2)
    Thread
        Call(SetNpcJumpscale, NPC_Conductor, Float(1.0))
        Call(NpcJump0, NPC_Conductor, LVar0, 50, LVar1, 10)
        Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
        Call(SetNpcSpeed, NPC_Conductor, Float(2.0))
        UseBuf(LVar9)
        BufRead2(LVar3, LVar4)
        Call(NpcMoveTo, NPC_Conductor, LVar3, LVar4, 0)
        Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
        Call(InterpNpcYaw, NPC_Conductor, 270, 15)
        Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(10)
    Thread
        AddF(LVar2, Float(60.0))
        Call(AddVectorPolar, LVar0, LVar1, Float(20.0), LVar2)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, LVar0, LVar1, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Wait(10)
    Sub(LVar1, 30)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(SetNpcSpeed, NPC_PARTNER, Float(2.5))
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};

#ifdef INCLUDE_ALTERNATES
EvtScript N(EVS_TrainUnk_AltE) = {
    Call(StopSound, SOUND_LRAW_TOYBOX_TRAIN_GEAR)
    Call(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
    Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Set(AF_OMO_06, TRUE)
    SetF(LVar0, MV_TrainPos)
    SetF(LVar1, MV_TrainUnk_0C)
    SetF(LVar2, MV_TrainUnk_0D)
    Thread
        Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Walk)
        Call(SetNpcSpeed, NPC_Conductor, Float(3.5))
        UseBuf(LVar9)
        BufRead2(LVar3, LVar4)
        Call(NpcMoveTo, NPC_Conductor, LVar3, LVar4, 0)
        Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_SadIdle)
        Call(InterpNpcYaw, NPC_Conductor, 90, 0)
        Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EndThread
    Wait(10)
    Thread
        AddF(LVar2, Float(85.0))
        Call(AddVectorPolar, LVar0, LVar1, Float(80.0), LVar2)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, LVar0, LVar1, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    EndThread
    Wait(10)
    AddF(LVar2, Float(50.0))
    Call(AddVectorPolar, LVar0, LVar1, Float(85.0), LVar2)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
    Call(SetNpcSpeed, NPC_PARTNER, Float(2.5))
    Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar1, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Return
    End
};
#endif

EvtScript N(EVS_TrainUnk_F) = {
    Switch(AB_OMO_6)
        CaseEq(0)
            Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_3, TRANSITION_TOY_TRAIN)
        CaseEq(1)
            Call(GotoMapSpecial, Ref("omo_06"), omo_06_ENTRY_3, TRANSITION_TOY_TRAIN)
        CaseEq(2)
            Call(GotoMapSpecial, Ref("omo_08"), omo_08_ENTRY_2, TRANSITION_TOY_TRAIN)
        CaseEq(3)
            Call(GotoMapSpecial, Ref("omo_10"), omo_10_ENTRY_3, TRANSITION_TOY_TRAIN)
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TrainUnk_G) = {
    Switch(AB_OMO_5)
        CaseRange(0, 1)
            Switch(AB_OMO_6)
                CaseEq(0)
                    Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                CaseEq(1)
                    Call(GotoMapSpecial, Ref("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                CaseEq(2)
                    Call(GotoMapSpecial, Ref("omo_08"), omo_08_ENTRY_1, TRANSITION_TOY_TRAIN)
                CaseEq(3)
                    Call(GotoMapSpecial, Ref("omo_10"), omo_10_ENTRY_2, TRANSITION_TOY_TRAIN)
            EndSwitch
        CaseEq(2)
            Switch(AB_OMO_6)
                CaseEq(0)
                    Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                CaseEq(1)
                    IfEq(GF_OMO03_BlueSwitchActivated, TRUE)
                        Call(GotoMapSpecial, Ref("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                    Else
                        Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EndIf
                CaseEq(3)
                    Call(GotoMapSpecial, Ref("omo_10"), omo_10_ENTRY_2, TRANSITION_TOY_TRAIN)
            EndSwitch
        CaseEq(3)
            Switch(AB_OMO_6)
                CaseEq(0)
                    Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                CaseEq(1)
                    IfEq(GF_OMO03_BlueSwitchActivated, TRUE)
                        Call(GotoMapSpecial, Ref("omo_06"), omo_06_ENTRY_2, TRANSITION_TOY_TRAIN)
                    Else
                        Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EndIf
                CaseEq(2)
                    IfEq(GF_OMO03_BlueSwitchActivated, TRUE)
                        Call(GotoMapSpecial, Ref("omo_08"), omo_08_ENTRY_1, TRANSITION_TOY_TRAIN)
                    Else
                        Call(GotoMapSpecial, Ref("omo_03"), omo_03_ENTRY_2, TRANSITION_TOY_TRAIN)
                    EndIf
            EndSwitch
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_TrainUnk_H) = {
    Label(10)
        Wait(1)
        Call(N(IsAOrBPressed))
        IfNe(LVar0, 1)
            Goto(10)
        EndIf
    IfEq(AF_OMO_UsingRightSwitch, FALSE)
        ExecWait(N(EVS_TrainUnk_F))
    Else
        ExecWait(N(EVS_TrainUnk_G))
    EndIf
    Return
    End
};
