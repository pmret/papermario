#include "omo_03.h"

#define INCLUDE_ALTERNATES 1
#include "../common/ToyTrain.inc.c"
#include "../common/TrainStationSwitches.inc.c"

Vec2i N(D_80246080_DAB2C0) = {
    170, -115
};

Vec2i N(D_80246088_DAB2C8) = {
    -383, -240
};

Vec2i N(D_80246090_DAB2D0)[] = {
    { -360, -195 },
    { -335, -215 },
};

s32 N(D_802460A0_DAB2E0)[] = {
    Float(-298.93), Float(-288.62), Float(140.0),
    Float(-262.5), Float(-245.336), Float(0.0),
    Float(-175.0), Float(169.89), Float(-220.49),
    -1, -1, -1
};

s32 N(D_802460D0_DAB310)[] = {
    Float(-298.93), Float(-288.62), Float(140.0),
    Float(-262.5), Float(-245.336), Float(0.0),
    Float(-175.0), Float(262.5), Float(-245.336),
    Float(479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(EVS_80246108) = {
    IfEq(GF_OMO03_BlueSwitchActivated, FALSE)
        Call(DisablePlayerInput, TRUE)
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0014)
        Call(DisablePlayerInput, FALSE)
        Return
    Else
        Call(DisablePlayerInput, TRUE)
        Call(DisablePlayerPhysics, TRUE)
        Call(DisablePartnerAI, 0)
        Thread
            Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(SetNpcJumpscale, NPC_Conductor, Float(1.0))
            Call(GetNpcPos, NPC_Conductor, LVar0, LVar1, LVar2)
            Loop(2)
                Call(NpcJump1, NPC_Conductor, LVar0, LVar1, LVar2, 15)
            EndLoop
            Call(SetNpcFlagBits, NPC_Conductor, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        EndThread
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0015)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
        ExecGetTID(N(EVS_TrainUnk_C), LVarB)
        Set(LVar0, Ref(N(D_802460A0_DAB2E0)))
        Set(LVar9, Ref(N(D_80246090_DAB2D0)))
        ExecWait(N(EVS_TrainUnk_AltD))
        IfEq(AB_OMO_6, 0)
            Set(MV_TrainUnk_00, 0)
            Set(MV_TrainUnk_01, Ref(N(D_802460A0_DAB2E0)))
            Set(MV_TrainUnk_02, 3)
            Set(MF_TrainUnk_00, TRUE)
            Label(20)
            IfEq(MF_TrainUnk_00, TRUE)
                Wait(1)
                Goto(20)
            EndIf
            Wait(20)
            KillThread(LVarB)
            Exec(N(EVS_TrainUnk_B))
            Call(N(EnableCameraFollowPlayerY))
            Set(LVar9, Ref(N(D_80246080_DAB2C0)))
            ExecWait(N(EVS_TrainUnk_E))
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
            Call(DisablePlayerPhysics, FALSE)
            Call(EnablePartnerAI)
            Call(DisablePlayerInput, FALSE)
        Else
            Set(MV_TrainUnk_00, 0)
            Set(MV_TrainUnk_01, Ref(N(D_802460D0_DAB310)))
            Set(MV_TrainUnk_02, 1)
            Set(MF_TrainUnk_00, TRUE)
            Wait(1)
            Exec(N(EVS_TrainUnk_H))
            Label(30)
            IfLt(MV_TrainPos, 350)
                Wait(1)
                Goto(30)
            EndIf
            Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
            Set(GB_OMO_TrainDestination, 0)
            Wait(100)
        EndIf
    EndIf
    Unbind
    Return
    End
};

s32 N(D_80246510_DAB750)[] = {
    Float(131.251), Float(-210.168), Float(74.997),
    Float(262.5), Float(-245.336), Float(479.165),
    Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246538_DAB778) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 0)
    Set(LVar0, Ref(N(D_80246510_DAB750)))
    ExecWait(N(EVS_TrainUnk_D))
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80246510_DAB750)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfLt(MV_TrainPos, 350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
    Set(GB_OMO_TrainDestination, 0)
    Wait(100)
    Return
    End
};

s32 N(D_802466C0_DAB900)[] = {
    Float(131.251), Float(-210.168), Float(254.997),
    Float(0.0), Float(-175.0), Float(-262.5),
    Float(-245.336), Float(-353.418), Float(-353.688),
    Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_802466F8_DAB938) = {
    Call(FadeOutMusic, 0, 3000)
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Wait(10)
    Call(DisablePlayerPhysics, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_TrainUnk_C))
    Set(AB_OMO_5, 0)
    Set(LVar0, Ref(N(D_802466C0_DAB900)))
    ExecWait(N(EVS_TrainUnk_D))
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_802466C0_DAB900)))
    Set(MV_TrainUnk_02, 1)
    Set(MF_TrainUnk_00, TRUE)
    Label(10)
    IfGt(MV_TrainPos, -350)
        Wait(1)
        Goto(10)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
    Set(GB_OMO_TrainDestination, 3)
    Wait(100)
    Return
    End
};

s32 N(D_80246880_DABAC0)[] = {
    Float(414.885), Float(-426.942), Float(219.92),
    Float(353.553), Float(-353.553), Float(262.5),
    Float(-245.336), Float(92.61), Float(-199.49),
    -1, -1, -1
};

s32 N(D_802468B0_DABAF0)[] = {
    Float(414.885), Float(-426.942), Float(219.92),
    Float(353.553), Float(-353.553), Float(262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(-262.5), Float(-245.336), Float(-353.418),
    Float(-353.688), Float(-479.165), Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_802468F8_DABB38) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(AB_OMO_6, 0)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80246880_DABAC0)))
        Set(MV_TrainUnk_02, 2)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        ExecGetTID(N(EVS_TrainUnk_A), LVarB)
        Label(10)
        IfEq(MF_TrainUnk_00, TRUE)
            Wait(1)
            Goto(10)
        EndIf
        Wait(20)
        KillThread(LVarB)
        Exec(N(EVS_TrainUnk_B))
        Call(N(EnableCameraFollowPlayerY))
        Set(LVar9, Ref(N(D_80246080_DAB2C0)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, FALSE)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, FALSE)
    Else
        Exec(N(EVS_TrainUnk_A))
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_802468B0_DABAF0)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
        Wait(1)
        Exec(N(EVS_TrainUnk_H))
        Label(20)
        IfGt(MV_TrainPos, -350)
            Wait(1)
            Goto(20)
        EndIf
        Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_1)
        Set(GB_OMO_TrainDestination, 3)
        Wait(100)
    EndIf
    Return
    End
};

s32 N(D_80246BE0_DABE20)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(169.89), Float(-220.49),
    -1, -1, -1
};

s32 N(D_80246C18_DABE58)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-273.25),
    Float(-257.95),
    -1, -1, -1
};

s32 N(D_80246C40_DABE80)[] = {
    Float(-414.885), Float(-426.942), Float(140.075),
    Float(-353.418), Float(-353.688), Float(-262.5),
    Float(-245.336), Float(0.0), Float(-175.0),
    Float(262.5), Float(-245.336), Float(479.165),
    Float(-503.546),
    -1, -1, -1
};

EvtScript N(D_80246C80_DABEC0) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    IfEq(GF_OMO03_BlueSwitchActivated, FALSE)
        Set(MV_TrainUnk_01, Ref(N(D_80246C18_DABE58)))
    Else
        IfEq(AB_OMO_6, 0)
            Set(MV_TrainUnk_01, Ref(N(D_80246BE0_DABE20)))
        Else
            Goto(15)
        EndIf
    EndIf
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_02, 2)
    Exec(N(EVS_Scene_RideTrain))
    Set(MF_TrainUnk_00, TRUE)
    Wait(1)
    ExecGetTID(N(EVS_TrainUnk_A), LVarB)
    Label(10)
    IfEq(MF_TrainUnk_00, TRUE)
        Wait(1)
        Goto(10)
    EndIf
    Wait(20)
    KillThread(LVarB)
    Exec(N(EVS_TrainUnk_B))
    Call(N(EnableCameraFollowPlayerY))
    IfEq(GF_OMO03_BlueSwitchActivated, TRUE)
        Set(LVar9, Ref(N(D_80246080_DAB2C0)))
        ExecWait(N(EVS_TrainUnk_E))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_000E)
    Else
        Set(LVar9, Ref(N(D_80246088_DAB2C8)))
        ExecWait(N(EVS_TrainUnk_AltE))
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 0, MSG_CH4_0013)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o939, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o941, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(DisablePlayerPhysics, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    Label(15)
    Exec(N(EVS_TrainUnk_A))
    Set(MV_TrainUnk_00, 0)
    Set(MV_TrainUnk_01, Ref(N(D_80246C40_DABE80)))
    Set(MV_TrainUnk_02, 0)
    Exec(N(EVS_Scene_RideTrain))
    Set(MF_TrainUnk_00, TRUE)
    Wait(1)
    Exec(N(EVS_TrainUnk_H))
    Label(20)
    IfLt(MV_TrainPos, 350)
        Wait(1)
        Goto(20)
    EndIf
    Call(GotoMap, Ref("omo_16"), omo_16_ENTRY_0)
    Set(GB_OMO_TrainDestination, 0)
    Wait(100)
    Return
    End
};

s32 N(D_80247044_DAC284)[] = {
    3, 2, 1,
};

s32 N(D_80247050_DAC290)[] = {
    1, 2, 3,
};

EvtScript N(EVS_8024705C) = {
    IfEq(MF_EitherSwitchPressed, FALSE)
        Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0006)
    Else
        IfEq(AF_OMO_UsingRightSwitch, FALSE)
            IfEq(GF_OMO03_BlueSwitchActivated, FALSE)
                Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_SadTalk, ANIM_TrainToad_SadIdle, 5, MSG_CH4_0012)
            Else
                Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
                Call(ShowChoice, MSG_Choice_003A)
                IfNe(LVar0, 3)
                    Call(CloseMessage)
                    UseBuf(Ref(N(D_80247044_DAC284)))
                    Add(LVar0, 1)
                    Loop(LVar0)
                        BufRead1(LVar1)
                    EndLoop
                    Set(AB_OMO_6, LVar1)
                    ExecWait(N(D_802466F8_DAB938))
                Else
                    Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                EndIf
            EndIf
        Else
            Call(SpeakToPlayer, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0007)
            Switch(GB_StoryProgress)
                CaseLt(STORY_CH4_PULLED_SWITCH_SWITCH)
                    Call(ShowChoice, MSG_Choice_0037)
                    IfNe(LVar0, 1)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_80247050_DAC290)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80246538_DAB778))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
                CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(ShowChoice, MSG_Choice_0038)
                    IfNe(LVar0, 2)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_80247050_DAC290)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80246538_DAB778))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
                CaseGe(STORY_CH4_SOLVED_COLOR_PUZZLE)
                    Call(ShowChoice, MSG_Choice_0039)
                    IfNe(LVar0, 3)
                        Call(CloseMessage)
                        UseBuf(Ref(N(D_80247050_DAC290)))
                        Add(LVar0, 1)
                        Loop(LVar0)
                            BufRead1(LVar1)
                        EndLoop
                        Set(AB_OMO_6, LVar1)
                        ExecWait(N(D_80246538_DAB778))
                    Else
                        Call(ContinueSpeech, NPC_Conductor, ANIM_TrainToad_Talk, ANIM_TrainToad_Idle, 0, MSG_CH4_0008)
                    EndIf
            EndSwitch
        EndIf
    EndIf
    Return
    End
};

s32 N(D_80247454_DAC694)[] = {
    Float(131.251), Float(-210.168), Float(74.997),
    -1, -1, -1
};

EvtScript N(EVS_8024746C) = {
    ExecWait(N(EVS_SetupSwitches))
    Call(EnableGroup, MODEL_po, FALSE)
    IfLt(GB_StoryProgress, STORY_CH4_RETURNED_TOY_TRAIN)
        Call(EnableGroup, MODEL_popo, FALSE)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_eki1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(GetLoadType, LVar1)
    IfEq(LVar1, 1)
        Set(MV_TrainUnk_00, 0)
        Set(MV_TrainUnk_01, Ref(N(D_80247454_DAC694)))
        Set(MV_TrainUnk_02, 0)
        Exec(N(EVS_Scene_RideTrain))
        Set(MF_TrainUnk_00, TRUE)
    Else
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(omo_03_ENTRY_2)
                Exec(N(D_80246C80_DABEC0))
            CaseEq(omo_03_ENTRY_3)
                Exec(N(D_802468F8_DABB38))
            CaseEq(omo_03_ENTRY_6)
                Call(EnableGroup, MODEL_popo, FALSE)
                Call(EnableGroup, MODEL_po, TRUE)
            CaseDefault
                Set(MV_TrainUnk_00, 0)
                Set(MV_TrainUnk_01, Ref(N(D_80247454_DAC694)))
                Set(MV_TrainUnk_02, 0)
                Exec(N(EVS_Scene_RideTrain))
                Set(MF_TrainUnk_00, TRUE)
        EndSwitch
    EndIf
    Return
    End
};
