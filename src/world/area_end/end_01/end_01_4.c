#include "end_01.h"
#include "effects.h"

extern s32 N(D_80245D34_E0B094);

API_CALLABLE(N(func_802428C0_E07C20)) {
    func_8011B950(0x5B, -1, 1, 0);
    set_background_color_blend(0, 0, 0, 255);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242900_E07C60)) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }
    
    script->functionTemp[1] -= 10;
    if (script->functionTemp[1] < 0) {
        script->functionTemp[1] = 0;
    }
    
    set_background_color_blend(0, 0, 0, script->functionTemp[1]);
    
    if (script->functionTemp[1] == 0) {
        func_8011B950(0x5B, -1, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(func_80242978_E07CD8)) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTempPtr[2] = get_npc_safe(script->varTable[10]);
        script->functionTemp[0] = 0;
    }
    npc = script->functionTempPtr[2];
    npc->rotation.y = update_lerp(4, 810.0f, 0.0f, script->functionTemp[0], 45);
    npc->alpha = update_lerp(4, 0.0f, 255.0f, script->functionTemp[0], 45);

    script->functionTemp[0]++;
    if (script->functionTemp[0] < 0x2E) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE1;
    }
}

API_CALLABLE(N(func_80242A68_E07DC8)) {
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

API_CALLABLE(N(func_80242B68_E07EC8)) {
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

API_CALLABLE(N(func_80242C68_E07FC8)) {
    Bytecode* args = script->ptrReadPos;
    N(D_80245D34_E0B094) = evt_get_variable(script, *args++);
    
    return ApiStatus_DONE2;
}

void N(func_80242C94_E07FF4)(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, SHADE, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_80245D34_E0B094) & 0xFF);
}

EvtScript N(D_80245740_E0AAA0) = {
    EVT_CALL(SetNpcFlagBits, NPC_07, NPC_FLAG_40000, TRUE)
    EVT_CALL(GetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_SUB(LVar3, 120)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 15)
    EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LVar2, LVar5, LVar4, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, LVarA, LVar2, LVar3, LVar4)
    EVT_CALL(N(func_80242978_E07CD8))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245820_E0AB80) = {
    EVT_CALL(N(func_802428C0_E07C20))
    EVT_WAIT(20)
    EVT_SET(LVarA, 0)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(2)
    EVT_SET(LVarA, 1)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(2)
    EVT_SET(LVarA, 2)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(3)
    EVT_SET(LVarA, 4)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(5)
    EVT_SET(LVarA, 5)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(3)
    EVT_SET(LVarA, 3)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(7)
    EVT_SET(LVarA, 6)
    EVT_EXEC(N(D_80245740_E0AAA0))
    EVT_WAIT(30)
    EVT_CALL(N(func_80242900_E07C60))
    EVT_WAIT(60)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245978_E0ACD8) = {
    EVT_CALL(SetNpcFlagBits, NPC_07, NPC_FLAG_40000, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_07, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_07, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_07, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_07, LVar0, LVar2, 120)
    EVT_CALL(N(func_80242A68_E07DC8), 7)
    EVT_CALL(GetNpcPos, NPC_07, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_07, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245AA4_E0AE04) = {
    EVT_CALL(SetNpcFlagBits, NPC_08, NPC_FLAG_40000, TRUE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(SetNpcAnimation, NPC_08, ANIM_ParadeIceShow_Violin_SkateKickLeft)
            EVT_WAIT(30)
            EVT_CALL(SetNpcAnimation, NPC_08, ANIM_ParadeIceShow_Violin_SkateKickRight)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(GetNpcPos, NPC_08, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -210)
    EVT_CALL(NpcMoveTo, NPC_08, LVar0, LVar2, 140)
    EVT_CALL(N(func_80242B68_E07EC8), 8)
    EVT_CALL(GetNpcPos, NPC_08, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_08, LVar0, LVar2, 120)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245BD0_E0AF30) = {
    EVT_EXEC_GET_TID(N(D_80245978_E0ACD8), LVarA)
    EVT_EXEC_GET_TID(N(D_80245AA4_E0AE04), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2800)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245C74_E0AFD4) = {
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_09, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_09, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_0A, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -300)
        EVT_CALL(NpcMoveTo, NPC_0A, LVar0, LVar2, 500)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

s32 N(D_80245D34_E0B094) = 0;

EvtScript N(D_80245D38_E0B098) = {
    EVT_CALL(EnableTexPanning, MODEL_kino3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino6, TRUE)
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, 14, 0, LVar0, 0)
        EVT_WAIT(LVar1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245DF0_E0B150) = {
    EVT_CALL(EnableTexPanning, MODEL_kino4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, 12, 0, LVar0, 0)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245E70_E0B1D0) = {
    EVT_CALL(EnableModel, MODEL_kino7, TRUE)
    EVT_CALL(EnableModel, MODEL_kino8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_kino8, TRUE)
    EVT_CALL(SetModelCustomGfx, MODEL_kino7, 1, -1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_PTR(N(func_80242C94_E07FF4)), 0)
    EVT_CHILD_THREAD
        EVT_CALL(MakeLerp, 0, 255, 90, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(func_80242C68_E07FC8), LVar0)
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
        EVT_CALL(SetTexPanOffset, 15, 0, LVar0, LVar1)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245FF0_E0B350) = {
    EVT_CALL(EnableModel, MODEL_kino7, FALSE)
    EVT_CALL(EnableModel, MODEL_kino8, FALSE)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_EXEC_GET_TID(N(D_80245DF0_E0B150), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2610)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 1)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_EXEC_GET_TID(N(D_80245E70_E0B1D0), LVarC)
    EVT_CALL(SetNpcFlagBits, NPC_0F, NPC_FLAG_ENABLE_HIT_SCRIPT, TRUE)
    EVT_CALL(MakeLerp, 0, 55, 90, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_kino1, 0, LVar0, 0)
        EVT_ADD(LVar0, -19)
        EVT_CALL(SetNpcPos, NPC_0F, -2529, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 8)
    EVT_EXEC_GET_TID(N(D_80245D38_E0B098), LVarA)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_0F, ANIM_ParadeIceShow_Violin_ShadeDivaSing)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2345)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
