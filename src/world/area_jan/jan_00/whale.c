#include "jan_00.h"
#include "effects.h"

u32 N(unkAngle1) = 0;
s32 N(unkAngle2) = -1;
s32 N(unkAngle3) = -1;

#include "world/common/atomic/WhaleAnim.inc.c"

API_CALLABLE(N(UnkPlayerPosFunc)) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 170.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 170.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);
    return ApiStatus_DONE2;
}

EvtScript N(D_8024595C_B25E9C) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(D_802459D4_B25F14) = {
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

EvtScript N(D_80245C10_B26150) = {
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

EvtScript N(D_80245E5C_B2639C) = {
    Return
    End
};

EvtScript N(D_80245E6C_B263AC) = {
    Set(LVar1, LVarC)
    Mod(LVar1, 4)
    IfEq(LVar1, 0)
        Call(N(UnkPlayerPosFunc))
        PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_2, LVar0, LVar1, LVar2, 0, -1, 0, 5)
    EndIf
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(D_80245F6C_B264AC) = {
    Return
    End
};

EvtScript N(D_80245F7C_B264BC) = {
    IfGe(LVarC, 0)
        IfLe(LVarC, 2)
            Call(EnableModel, MODEL_o170, false)
            Call(EnableModel, MODEL_o183, true)
            Return
        EndIf
    EndIf
    IfEq(LVarC, 15)
        Call(EnableModel, MODEL_o170, false)
        Call(EnableModel, MODEL_o183, true)
        Return
    EndIf
    IfEq(LVarC, 22)
        Call(EnableModel, MODEL_o170, false)
        Call(EnableModel, MODEL_o183, true)
        Return
    EndIf
    Call(EnableModel, MODEL_o170, true)
    Call(EnableModel, MODEL_o183, false)
    Return
    End
};

EvtScript N(D_802460A4_B265E4) = {
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

EvtScript N(D_8024620C_B2674C) = {
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

EvtScript N(D_8024634C_B2688C) = {
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

EvtScript N(D_802464B4_B269F4) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 30, 60, 30, 0, 0)
    Call(RotateModel, MODEL_o167, LVar0, 1, 0, 0)
    Call(RotateModel, MODEL_o168, LVar0, -1, 0, 0)
    Return
    End
};

EvtScript N(D_8024652C_B26A6C) = {
    Call(N(UnkFloatFunc001), LVarC, LVar0, 0, 8, 3, 0, 0)
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

EvtScript N(EVS_802467AC) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(MakeLocalVertexCopy, VTX_COPY_1, MODEL_karada, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(unkAngleFunc002)), nullptr)
    Call(SetModelCustomGfx, MODEL_karada, CUSTOM_GFX_1, -1)
    Call(MakeLocalVertexCopy, VTX_COPY_2, MODEL_onaka, true)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_2, Ref(N(unkAngleFunc003)), nullptr)
    Call(SetModelCustomGfx, MODEL_onaka, CUSTOM_GFX_2, -1)
    Thread
        Label(0)
        Call(N(UnkAngleFunc001), 0, LVar0, LVar1, LVar2)
        SubF(LVar0, -80)
        SubF(LVar1, -18)
        SubF(LVar2, 420)
        AddF(LVar0, 55)
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
            Call(EnableModel, MODEL_o170, true)
            Call(EnableModel, MODEL_o183, false)
            Switch(LVarB)
                CaseEq(0x00B60003)
                    Set(LVarD, Ref(N(D_80245C10_B26150)))
                CaseEq(0x00B60000)
                    Set(LVarD, Ref(N(D_8024595C_B25E9C)))
                CaseEq(0x00B60002)
                    Set(LVarD, Ref(N(D_802459D4_B25F14)))
                CaseEq(0x00B60001)
                    Set(LVarD, Ref(N(D_802464B4_B269F4)))
                CaseEq(0x00B60004)
                    Set(LVarD, Ref(N(D_8024652C_B26A6C)))
                CaseEq(0x00B60005)
                    Set(LVarD, Ref(N(D_80245E5C_B2639C)))
                    Call(EnableModel, MODEL_o170, false)
                    Call(EnableModel, MODEL_o183, false)
                CaseEq(0x00B60006)
                    Set(LVarD, Ref(N(D_802460A4_B265E4)))
                    Call(EnableModel, MODEL_o170, false)
                    Call(EnableModel, MODEL_o183, false)
                CaseEq(0x00B60007)
                    Set(LVarD, Ref(N(D_8024620C_B2674C)))
                    Call(EnableModel, MODEL_o170, false)
                    Call(EnableModel, MODEL_o183, false)
                CaseEq(0x00B60008)
                    Set(LVarD, Ref(N(D_8024634C_B2688C)))
                CaseEq(0x00B60009)
                    Set(LVarD, Ref(N(D_80245E6C_B263AC)))
                CaseEq(0x00B6000A)
                    Set(LVarD, Ref(N(D_80245F6C_B264AC)))
                CaseEq(0x00B6000C)
                    Set(LVarD, Ref(N(D_80245F7C_B264BC)))
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

EvtScript N(EVS_80247040) = {
    Call(SetNpcAnimation, NPC_Whale, ANIM_Kolorado_IdleSad)
    Return
    End
};
