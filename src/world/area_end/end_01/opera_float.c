#include "end_01.h"
#include "effects.h"
#include "model.h"

extern s32 N(SpotlightsAlpha);

API_CALLABLE(N(SetWorldDark)) {
    mdl_group_set_custom_gfx(MODEL_Root, CUSTOM_GFX_NONE, ENV_TINT_SHROUD, FALSE);
    mdl_set_shroud_tint_params(0, 0, 0, 255);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FadeInWorld)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] < 0) {
        script->functionTemp[1] = 0;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        mdl_group_set_custom_gfx(MODEL_Root, CUSTOM_GFX_NONE, ENV_TINT_NONE, FALSE);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(UpdateStarSpiritRotation)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[2] = get_npc_safe(script->varTable[10]);
        script->functionTemp[0] = 0;
    }
    npc = script->functionTempPtr[2];
    npc->rot.y = update_lerp(EASING_QUADRATIC_OUT, 810.0f, 0.0f, script->functionTemp[0], 45);
    npc->alpha = update_lerp(EASING_QUADRATIC_OUT, 0.0f, 255.0f, script->functionTemp[0], 45);

    script->functionTemp[0]++;
    if (script->functionTemp[0] <= 45) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(SkateInCirclePenguin1)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[1] = resolve_npc(script, npcID);
        npc = script->functionTempPtr[1];
        script->functionTemp[2] = npc->pos.x;
        script->functionTempF[3] = 180.0f;
        script->functionTemp[0] = 72;
    }

    npc = script->functionTempPtr[1];
    script->functionTempF[3] = clamp_angle(script->functionTempF[3] - 5.0f);
    npc->pos.x = npc->pos.x + (cos_deg(script->functionTempF[3]) * 6.0f);
    npc->pos.z = npc->pos.z + (sin_deg(script->functionTempF[3]) * 2.5f);
    npc->renderYaw = clamp_angle(180.0f - script->functionTempF[3]);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(SkateInCirclePenguin2)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[1] = resolve_npc(script, npcID);
        npc = script->functionTempPtr[1];
        script->functionTemp[2] = npc->pos.x;
        script->functionTempF[3] = 180.0f;
        script->functionTemp[0] = 72;
    }

    npc = script->functionTempPtr[1];
    script->functionTempF[3] = clamp_angle(script->functionTempF[3] + 5.0f);
    npc->pos.x = npc->pos.x + (cos_deg(script->functionTempF[3]) * 6.0f);
    npc->pos.z = npc->pos.z + (sin_deg(script->functionTempF[3]) * 2.5f);
    npc->renderYaw = clamp_angle(180.0f - script->functionTempF[3]);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(SetSpotlightsAlpha)) {
    Bytecode* args = script->ptrReadPos;
    N(SpotlightsAlpha) = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

void N(gfx_build_set_spotlight_alpha)(void) {
    gDPSetCombineMode(gMainGfxPos++, PM_CC_3F, PM_CC_3F);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(SpotlightsAlpha));
}

EvtScript N(EVS_MakeSpiritAppear) = {
    Call(SetNpcFlagBits, NPC_PenguinSkater1, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    Sub(LVar3, 120)
    Set(LVar5, LVar3)
    Add(LVar5, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar2, LVar5, LVar4, 30)
    Call(SetNpcPos, LVarA, LVar2, LVar3, LVar4)
    Call(N(UpdateStarSpiritRotation))
    Return
    End
};

EvtScript N(EVS_ParadePhase_StarSpirits) = {
    Call(N(SetWorldDark))
    Wait(20)
    Set(LVarA, NPC_Eldstar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(2)
    Set(LVarA, NPC_Mamar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(2)
    Set(LVarA, NPC_Skolar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(3)
    Set(LVarA, NPC_Misstar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(5)
    Set(LVarA, NPC_Klevar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(3)
    Set(LVarA, NPC_Muskular)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(7)
    Set(LVarA, NPC_Kalmar)
    Exec(N(EVS_MakeSpiritAppear))
    Wait(30)
    Call(N(FadeInWorld))
    Wait(60)
    Return
    End
};

EvtScript N(EVS_SkatingPenguin1) = {
    Call(SetNpcFlagBits, NPC_PenguinSkater1, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    ChildThread
        Loop(0)
            Call(SetNpcAnimation, NPC_PenguinSkater1, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            Wait(30)
            Call(SetNpcAnimation, NPC_PenguinSkater1, ANIM_ParadeIceShow_Violin_SkateKickRight)
            Wait(30)
        EndLoop
    EndChildThread
    Call(GetNpcPos, NPC_PenguinSkater1, LVar0, LVar1, LVar2)
    Add(LVar0, -180)
    Call(NpcMoveTo, NPC_PenguinSkater1, LVar0, LVar2, 120)
    Call(N(SkateInCirclePenguin1), NPC_PenguinSkater1)
    Call(GetNpcPos, NPC_PenguinSkater1, LVar0, LVar1, LVar2)
    Add(LVar0, -180)
    Call(NpcMoveTo, NPC_PenguinSkater1, LVar0, LVar2, 120)
    Return
    End
};

EvtScript N(EVS_SkatingPenguin2) = {
    Call(SetNpcFlagBits, NPC_PenguinSkater2, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    ChildThread
        Loop(0)
            Call(SetNpcAnimation, NPC_PenguinSkater2, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            Wait(30)
            Call(SetNpcAnimation, NPC_PenguinSkater2, ANIM_ParadeIceShow_Violin_SkateKickRight)
            Wait(30)
        EndLoop
    EndChildThread
    Call(GetNpcPos, NPC_PenguinSkater2, LVar0, LVar1, LVar2)
    Add(LVar0, -210)
    Call(NpcMoveTo, NPC_PenguinSkater2, LVar0, LVar2, 140)
    Call(N(SkateInCirclePenguin2), NPC_PenguinSkater2)
    Call(GetNpcPos, NPC_PenguinSkater2, LVar0, LVar1, LVar2)
    Add(LVar0, -180)
    Call(NpcMoveTo, NPC_PenguinSkater2, LVar0, LVar2, 120)
    Return
    End
};

EvtScript N(EVS_ParadePhase_SkatingPenguins) = {
    ExecGetTID(N(EVS_SkatingPenguin1), LVarA)
    ExecGetTID(N(EVS_SkatingPenguin2), LVarB)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SKATERS + 200)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    Return
    End
};

EvtScript N(EVS_ParadePhase_MayorPenguin) = {
    Thread
        Call(GetNpcPos, NPC_PenguinMayor, LVar0, LVar1, LVar2)
        Add(LVar0, -300)
        Call(NpcMoveTo, NPC_PenguinMayor, LVar0, LVar2, 500)
    EndThread
    Thread
        Call(GetNpcPos, NPC_PenguinMayorWife, LVar0, LVar1, LVar2)
        Add(LVar0, -300)
        Call(NpcMoveTo, NPC_PenguinMayorWife, LVar0, LVar2, 500)
    EndThread
    Return
    End
};

s32 N(SpotlightsAlpha) = 0;

EvtScript N(EVS_TexPan_OperaFloat_MainStageLights) = {
    Call(EnableTexPanning, MODEL_kino3, TRUE)
    Call(EnableTexPanning, MODEL_kino5, TRUE)
    Call(EnableTexPanning, MODEL_kino6, TRUE)
    Set(LVar1, LVar0)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x2000)
        Call(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        Wait(LVar1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_OperaFloat_StageLights) = {
    Call(EnableTexPanning, MODEL_kino4, TRUE)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x2000)
        Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        Wait(16)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateLightshow) = {
    Call(EnableModel, MODEL_kino7, TRUE)
    Call(EnableModel, MODEL_kino8, TRUE)
    Call(EnableTexPanning, MODEL_kino8, TRUE)
    Call(SetModelCustomGfx, MODEL_kino7, CUSTOM_GFX_1, -1)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(gfx_build_set_spotlight_alpha)), NULL)
    ChildThread
        Call(MakeLerp, 0, 255, 90, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetSpotlightsAlpha), LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndChildThread
    Set(LVar0, 0)
    Set(LVar1, 0)
    Loop(0)
        Add(LVar0, 0x1000)
        Add(LVar1, 0x400)
        Call(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar0, LVar1)
        Wait(4)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_Opera) = {
    Call(EnableModel, MODEL_kino7, FALSE)
    Call(EnableModel, MODEL_kino8, FALSE)
    Set(LVar0, 8)
    ExecGetTID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    ExecGetTID(N(EVS_TexPan_OperaFloat_StageLights), LVarB)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_OPERA + 335)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    Set(LVar0, 1)
    ExecGetTID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    ExecGetTID(N(EVS_UpdateLightshow), LVarC)
    Call(SetNpcFlagBits, NPC_Singer, NPC_FLAG_FLYING, TRUE)
    Call(MakeLerp, 0, 55, 90 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_kino1, 0, LVar0, 0)
        Add(LVar0, -19)
        Call(SetNpcPos, NPC_Singer, -2529, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    Set(LVar0, 8)
    ExecGetTID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    Wait(10)
    Call(SetNpcAnimation, NPC_Singer, ANIM_ParadeIceShow_Violin_ShadeDivaSing)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_OPERA + 600)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    KillThread(LVarC)
    Return
    End
};
