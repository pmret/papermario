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
    EVT_CALL(SetNpcFlagBits, NPC_PenguinSkater1, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_SUB(LVar3, 120)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar2, LVar5, LVar4, 30)
    EVT_CALL(SetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_CALL(N(UpdateStarSpiritRotation))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_StarSpirits) = {
    EVT_CALL(N(SetWorldDark))
    EVT_WAIT(20)
    EVT_SET(LVarA, NPC_Eldstar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(2)
    EVT_SET(LVarA, NPC_Mamar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(2)
    EVT_SET(LVarA, NPC_Skolar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(3)
    EVT_SET(LVarA, NPC_Misstar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(5)
    EVT_SET(LVarA, NPC_Klevar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(3)
    EVT_SET(LVarA, NPC_Muskular)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(7)
    EVT_SET(LVarA, NPC_Kalmar)
    EVT_EXEC(N(EVS_MakeSpiritAppear))
    EVT_WAIT(30)
    EVT_CALL(N(FadeInWorld))
    EVT_WAIT(60)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SkatingPenguin1) = {
    EVT_CALL(SetNpcFlagBits, NPC_PenguinSkater1, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_PenguinSkater1, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_PenguinSkater1, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_PenguinSkater1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_PenguinSkater1, LVar0, LVar2, 120)
    EVT_CALL(N(SkateInCirclePenguin1), NPC_PenguinSkater1)
    EVT_CALL(GetNpcPos, NPC_PenguinSkater1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_PenguinSkater1, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SkatingPenguin2) = {
    EVT_CALL(SetNpcFlagBits, NPC_PenguinSkater2, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_PenguinSkater2, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_PenguinSkater2, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_PenguinSkater2, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -210)
    EVT_CALL(NpcMoveTo, NPC_PenguinSkater2, LVar0, LVar2, 140)
    EVT_CALL(N(SkateInCirclePenguin2), NPC_PenguinSkater2)
    EVT_CALL(GetNpcPos, NPC_PenguinSkater2, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_PenguinSkater2, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_SkatingPenguins) = {
    EVT_EXEC_GET_TID(N(EVS_SkatingPenguin1), LVarA)
    EVT_EXEC_GET_TID(N(EVS_SkatingPenguin2), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SKATERS + 200)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_MayorPenguin) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_PenguinMayor, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_PenguinMayor, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_PenguinMayorWife, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_PenguinMayorWife, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

s32 N(SpotlightsAlpha) = 0;

EvtScript N(EVS_TexPan_OperaFloat_MainStageLights) = {
    EVT_CALL(EnableTexPanning, MODEL_kino3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino6, TRUE)
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(LVar1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_OperaFloat_StageLights) = {
    EVT_CALL(EnableTexPanning, MODEL_kino4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateLightshow) = {
    EVT_CALL(EnableModel, MODEL_kino7, TRUE)
    EVT_CALL(EnableModel, MODEL_kino8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino8, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_kino7, CUSTOM_GFX_1, -1)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(gfx_build_set_spotlight_alpha)), NULL)
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetSpotlightsAlpha), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_ADD(LVar1, 0x400)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Opera) = {
    EVT_CALL(EnableModel, MODEL_kino7, FALSE)
    EVT_CALL(EnableModel, MODEL_kino8, FALSE)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    EVT_EXEC_GET_TID(N(EVS_TexPan_OperaFloat_StageLights), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_OPERA + 335)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    EVT_EXEC_GET_TID(N(EVS_UpdateLightshow), LVarC)
    EVT_CALL(SetNpcFlagBits, NPC_Singer, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(MakeLerp, 0, 55, 90 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_kino1, 0, LVar0, 0)
        EVT_ADD(LVar0, -19)
        EVT_CALL(SetNpcPos, NPC_Singer, -2529, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(EVS_TexPan_OperaFloat_MainStageLights), LVarA)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Singer, ANIM_ParadeIceShow_Violin_ShadeDivaSing)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_OPERA + 600)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
