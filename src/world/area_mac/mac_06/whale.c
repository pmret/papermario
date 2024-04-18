#include "mac_06.h"

u32 N(unkAngle1) = 0;
s32 N(unkAngle2) = -1;
s32 N(unkAngle3) = -1;

#include "world/common/atomic/WhaleAnim.inc.c"

API_CALLABLE(N(UnkPlayerPosFunc)) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 70.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 70.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/WhaleGeyser.inc.c"

MAP_RODATA_PAD(2, unk);

EvtScript N(EVS_WhaleState_Still) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_2) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, 30, 30, 1, 0)
    SetF(LVar1, LVar0)
    DivF(LVar1, Float(3.0))
    Call(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, -5, -68, 0)
    Call(TranslateModel, MODEL_o183, -5, -68, 0)
    Call(TranslateModel, MODEL_o167, 60, 29, -51)
    Call(TranslateModel, MODEL_o168, 60, 29, 51)
    Call(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, 5, 68, 0)
    Call(TranslateModel, MODEL_o183, 5, 68, 0)
    Call(TranslateModel, MODEL_o167, -60, -29, 51)
    Call(TranslateModel, MODEL_o168, -60, -29, -51)
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, -40, 30, 1, 0)
    Call(TranslateModel, MODEL_bero, LVar0, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_IdleSad) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, -30, 8, 1, 0)
    AddF(LVar0, Float(30.0))
    SetF(LVar1, LVar0)
    DivF(LVar1, Float(3.0))
    Call(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, -5, -68, 0)
    Call(TranslateModel, MODEL_o183, -5, -68, 0)
    Call(TranslateModel, MODEL_o167, 60, 29, -51)
    Call(TranslateModel, MODEL_o168, 60, 29, 51)
    Call(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, 5, 68, 0)
    Call(TranslateModel, MODEL_o183, 5, 68, 0)
    Call(TranslateModel, MODEL_o167, -60, -29, 51)
    Call(TranslateModel, MODEL_o168, -60, -29, -51)
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, -40, 120, 1, 0)
    Call(TranslateModel, MODEL_bero, LVar0, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_WalkSad) = {
    Return
    End
};

EvtScript N(EVS_WhaleState_Shout) = {
    Call(GetNpcVar, NPC_Whale, 0, LVar3)
    IfEq(LVar3, 0)
        Call(N(UnkPlayerPosFunc))
        Call(PlaySoundAt, SOUND_LOOP_WHALE_GEYSER, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        Call(N(CreateWhaleGeyser), 0, LVar0, LVar1, LVar2, 0, -1, 0, 30)
        Call(SetNpcVar, NPC_Whale, 0, LVar0)
    EndIf
    Call(GetNpcVar, NPC_Whale, 0, LVar3)
    Call(N(UnkPlayerPosFunc))
    Call(N(SetWhaleGeyserPos), LVar3, LVar0, LVar1, LVar2)
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 25, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_TalkSad) = {
    Return
    End
};

EvtScript N(EVS_WhaleState_HurtStill) = {
    IfGe(LVarC, 0)
        IfLe(LVarC, 2)
            Call(EnableModel, MODEL_o170, FALSE)
            Call(EnableModel, MODEL_o183, TRUE)
            Return
        EndIf
    EndIf
    IfEq(LVarC, 15)
        Call(EnableModel, MODEL_o170, FALSE)
        Call(EnableModel, MODEL_o183, TRUE)
        Return
    EndIf
    IfEq(LVarC, 22)
        Call(EnableModel, MODEL_o170, FALSE)
        Call(EnableModel, MODEL_o183, TRUE)
        Return
    EndIf
    Call(EnableModel, MODEL_o170, TRUE)
    Call(EnableModel, MODEL_o183, FALSE)
    Return
    End
};

EvtScript N(EVS_WhaleState_Run) = {
    Set(LVar0, LVarC)
    Div(LVar0, 20)
    Mod(LVar0, 2)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(N(UnkFloatFunc001), LVarC, LVar0, Float(-1.0), Float(1.0), 3, 0, 0)
    Call(TranslateModel, MODEL_o173, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o170, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o183, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o167, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o168, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o167, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o168, LVar0, 0, 0)
    Return
    End
};

EvtScript N(D_80242474_866FB4) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, Float(-6.0), Float(6.0), 3, 0, 0)
    Call(N(UnkFloatFunc001), LVarC, LVar1, Float(6.0), Float(-6.0), 2, 0, 0)
    Call(TranslateModel, MODEL_o173, LVar0, LVar1, 0)
    Call(TranslateGroup, MODEL_dou, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o170, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o183, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o167, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o168, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o167, LVar0, LVar1, 0)
    Call(TranslateModel, MODEL_o168, LVar0, LVar1, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_Talk) = {
    Set(LVar0, LVarC)
    Div(LVar0, 20)
    Mod(LVar0, 2)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(N(UnkFloatFunc001), LVarC, LVar0, Float(-1.0), Float(1.0), 3, 0, 0)
    Call(TranslateModel, MODEL_o173, LVar0, 0, 0)
    Call(TranslateGroup, MODEL_dou, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o170, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o183, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o167, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o168, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o167, LVar0, 0, 0)
    Call(TranslateModel, MODEL_o168, LVar0, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_Idle) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleState_Walk) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, 30, 3, 0, 0)
    Set(LVar1, LVar0)
    Div(LVar1, 3)
    Call(RotateModel, MODEL_o173, LVar0, 0, 0, 1)
    Call(RotateGroup, MODEL_dou, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, -5, -68, 0)
    Call(TranslateModel, MODEL_o183, -5, -68, 0)
    Call(TranslateModel, MODEL_o167, 60, 29, -51)
    Call(TranslateModel, MODEL_o168, 60, 29, 51)
    Call(RotateModel, MODEL_o170, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o183, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o167, LVar1, 0, 0, -1)
    Call(RotateModel, MODEL_o168, LVar1, 0, 0, -1)
    Call(TranslateModel, MODEL_o170, 5, 68, 0)
    Call(TranslateModel, MODEL_o183, 5, 68, 0)
    Call(TranslateModel, MODEL_o167, -60, -29, 51)
    Call(TranslateModel, MODEL_o168, -60, -29, -51)
    Set(LVar0, LVarC)
    Mul(LVar0, 2)
    Call(N(UnkFloatFunc001), LVar0, LVar0, 30, 60, 3, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(EVS_WhaleMain) = {
    SetGroup(EVT_GROUP_00)
    Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_karada, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(unkAngleFunc002)), NULL)
    Call(SetModelCustomGfx, MODEL_karada, CUSTOM_GFX_1, -1)
    Call(MakeLocalVertexCopy, VTX_COPY_2, MODEL_onaka, TRUE)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_2, Ref(N(unkAngleFunc003)), NULL)
    Call(SetModelCustomGfx, MODEL_onaka, CUSTOM_GFX_2, -1)
    Call(SetNpcVar, NPC_Whale, 0, 0)
    Thread
        Label(0)
        Call(N(UnkAngleFunc001), 0, LVar0, LVar1, LVar2)
        SubF(LVar0, -80)
        SubF(LVar1, -18)
        SubF(LVar2, 420)
        AddF(LVar0, 130)
        AddF(LVar1, -20)
        AddF(LVar2, 0)
        Call(TranslateModel, MODEL_bero, LVar0, LVar1, LVar2)
        Call(TranslateModel, MODEL_o170, LVar0, LVar1, LVar2)
        Call(TranslateModel, MODEL_o183, LVar0, LVar1, LVar2)
        Call(TranslateModel, MODEL_o173, LVar0, LVar1, LVar2)
        Call(TranslateModel, MODEL_o167, LVar0, LVar1, LVar2)
        Call(TranslateModel, MODEL_o168, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_dou, LVar0, LVar1, LVar2)
        Call(GetNpcYaw, NPC_Whale, LVar0)
        MulF(LVar0, -1)
        AddF(LVar0, -90)
        Call(TranslateModel, MODEL_bero, -100, 0, 0)
        Call(TranslateModel, MODEL_o170, -100, 0, 0)
        Call(TranslateModel, MODEL_o183, -100, 0, 0)
        Call(TranslateModel, MODEL_o173, -100, 0, 0)
        Call(TranslateModel, MODEL_o167, -100, 0, 0)
        Call(TranslateModel, MODEL_o168, -100, 0, 0)
        Call(TranslateGroup, MODEL_dou, -100, 0, 0)
        Call(TranslateModel, MODEL_bero, 100, -1, 0)
        Call(TranslateModel, MODEL_o170, -5, -68, 0)
        Call(TranslateModel, MODEL_o183, -5, -68, 0)
        Call(TranslateModel, MODEL_o173, 102, 4, 0)
        Call(TranslateModel, MODEL_o167, 60, 29, -51)
        Call(TranslateModel, MODEL_o168, 60, 29, 51)
        Call(RotateModel, MODEL_bero, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o170, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o183, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o173, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o167, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_dou, LVar0, 0, 1, 0)
        Call(TranslateModel, MODEL_bero, -100, 1, 0)
        Call(TranslateModel, MODEL_o170, 5, 68, 0)
        Call(TranslateModel, MODEL_o183, 5, 68, 0)
        Call(TranslateModel, MODEL_o173, -102, -4, 0)
        Call(TranslateModel, MODEL_o167, -60, -29, 51)
        Call(TranslateModel, MODEL_o168, -60, -29, -51)
        Call(TranslateModel, MODEL_bero, 100, 0, 0)
        Call(TranslateModel, MODEL_o170, 100, 0, 0)
        Call(TranslateModel, MODEL_o183, 100, 0, 0)
        Call(TranslateModel, MODEL_o173, 100, 0, 0)
        Call(TranslateModel, MODEL_o167, 100, 0, 0)
        Call(TranslateModel, MODEL_o168, 100, 0, 0)
        Call(TranslateGroup, MODEL_dou, 100, 0, 0)
        Call(GetNpcAnimation, NPC_Whale, LVar0)
        IfNe(LVar0, LVarB)
            Set(LVarB, LVar0)
            Set(LVarC, 0)
            Call(EnableModel, MODEL_o170, TRUE)
            Call(EnableModel, MODEL_o183, FALSE)
            IfNe(LVarB, ANIM_Kolorado_Shout)
                Call(GetNpcVar, NPC_Whale, 0, LVar0)
                IfNe(LVar0, 0)
                    Call(PlaySound, SOUND_LRAW_WHALE_GEYSER | SOUND_ID_TRIGGER_CHANGE_SOUND)
                    Call(StopTrackingSoundPos, SOUND_LRAW_WHALE_GEYSER)
                    Call(N(DisposeWhaleGeyser), LVar0)
                    Call(SetNpcVar, NPC_Whale, 0, 0)
                EndIf
            EndIf
            Switch(LVarB)
                CaseEq(ANIM_Kolorado_IdleSad)
                    Call(PlaySoundAtNpc, NPC_Whale, SOUND_WHALE_CLOSE_MOUTH, SOUND_SPACE_DEFAULT)
                    Set(LVarD, Ref(N(EVS_WhaleState_IdleSad)))
                CaseEq(ANIM_Kolorado_Still)
                    Set(LVarD, Ref(N(EVS_WhaleState_Still)))
                CaseEq(ANIM_Kolorado_Yell)
                    Call(PlaySoundAtNpc, NPC_Whale, SOUND_WHALE_OPEN_MOUTH, SOUND_SPACE_DEFAULT)
                    Set(LVarD, Ref(N(EVS_WhaleState_2)))
                CaseEq(ANIM_Kolorado_Idle)
                    Set(LVarD, Ref(N(EVS_WhaleState_Idle)))
                CaseEq(ANIM_Kolorado_Walk)
                    Set(LVarD, Ref(N(EVS_WhaleState_Walk)))
                CaseEq(ANIM_Kolorado_WalkSad)
                    Set(LVarD, Ref(N(EVS_WhaleState_WalkSad)))
                    Call(EnableModel, MODEL_o170, FALSE)
                    Call(EnableModel, MODEL_o183, FALSE)
                CaseEq(ANIM_Kolorado_Run)
                    Set(LVarD, Ref(N(EVS_WhaleState_Run)))
                    Call(EnableModel, MODEL_o170, FALSE)
                    Call(EnableModel, MODEL_o183, FALSE)
                CaseEq(ANIM_Kolorado_Panic)
                    Set(LVarD, Ref(N(D_80242474_866FB4)))
                    Call(EnableModel, MODEL_o170, FALSE)
                    Call(EnableModel, MODEL_o183, FALSE)
                CaseEq(ANIM_Kolorado_Talk)
                    Set(LVarD, Ref(N(EVS_WhaleState_Talk)))
                CaseEq(ANIM_Kolorado_Shout)
                    Set(LVarD, Ref(N(EVS_WhaleState_Shout)))
                CaseEq(ANIM_Kolorado_TalkSad)
                    Set(LVarD, Ref(N(EVS_WhaleState_TalkSad)))
                CaseEq(ANIM_Kolorado_HurtStill)
                    Set(LVarD, Ref(N(EVS_WhaleState_HurtStill)))
            EndSwitch
        EndIf
        ExecWait(LVarD)
        Add(LVarC, 1)
        IfGt(LVarC, 1000)
            Set(LVarC, 0)
        EndIf
        Goto(0)
    EndThread
    Return
    End
};

EvtScript N(EVS_80243380) = {
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
    Return
    End
};
