#include "mim_12.h"
#include "sprite/player.h"

API_CALLABLE(N(InitializeGustyFogProperties)) {
    enable_world_fog();
    set_world_fog_dist(990, 1000);
    set_world_fog_color(0, 8, 24, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 24;
    gCameras[CAM_DEFAULT].bgColor[1] = 24;
    gCameras[CAM_DEFAULT].bgColor[2] = 24;
    gGameStatusPtr->backgroundDarkness = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InitializeForestFogProperties)) {
    enable_world_fog();
    set_world_fog_dist(980, 1000);
    set_world_fog_color(0, 8, 24, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 24;
    gCameras[CAM_DEFAULT].bgColor[1] = 24;
    gCameras[CAM_DEFAULT].bgColor[2] = 24;
    gGameStatusPtr->backgroundDarkness = 232;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(InterpFogDistance)) {
    Bytecode* args = script->ptrReadPos;
    s32 retVal = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[0] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
    }

    script->functionTemp[1] += script->functionTemp[3];

    if (script->functionTemp[3] >= 0) {
        if (script->functionTemp[1] >= script->functionTemp[2]) {
            script->functionTemp[1] = script->functionTemp[2];
            retVal = ApiStatus_DONE2;
        }
    } else {
        if (script->functionTemp[2] >= script->functionTemp[1] ) {
            script->functionTemp[1] = script->functionTemp[2];
            retVal = ApiStatus_DONE2;
        }
    }

    set_world_fog_dist(script->functionTemp[1], script->functionTemp[0]);
    return retVal;
}

API_CALLABLE(N(InterpBackgroundDarkness)) {
    Bytecode* args = script->ptrReadPos;
    s32 retVal = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
    }

    script->functionTemp[1] += script->functionTemp[3];

    if (script->functionTemp[3] >= 0) {
        if (script->functionTemp[1] >= script->functionTemp[2]) {
            script->functionTemp[1] = script->functionTemp[2];
            retVal = ApiStatus_DONE2;
        }
    } else {
        if (script->functionTemp[2] >= script->functionTemp[1]) {
            script->functionTemp[1] = script->functionTemp[2];
            retVal = ApiStatus_DONE2;
        }
    }

    gGameStatusPtr->backgroundDarkness = script->functionTemp[1];
    return retVal;
}

API_CALLABLE(N(InterpSpriteShadingColor)) {
    SpriteShadingProfile* shadingProfile = gSpriteShadingProfile;
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        script->varTable[0] = evt_get_variable(script, *args++);
        script->varTable[1] = evt_get_variable(script, *args++);
        script->varTable[2] = evt_get_variable(script, *args++);
        script->varTable[3] = shadingProfile->ambientColor.r;
        script->varTable[4] = shadingProfile->ambientColor.g;
        script->varTable[5] = shadingProfile->ambientColor.b;
        script->varTable[6] = 0;
        gSpriteShadingProfile->flags |= 1;
    }

    script->varTable[6]++;
    shadingProfile->ambientColor.r = update_lerp(EASING_LINEAR, script->varTable[3], script->varTable[0], script->varTable[6], 20);
    shadingProfile->ambientColor.g = update_lerp(EASING_LINEAR, script->varTable[4], script->varTable[1], script->varTable[6], 20);
    shadingProfile->ambientColor.b = update_lerp(EASING_LINEAR, script->varTable[5], script->varTable[2], script->varTable[6], 20);

    if (script->varTable[6] == 20) {
        if (script->varTable[0] == 255) {
            gSpriteShadingProfile->flags &= ~1;
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(MoveNpcAlongArc)) {
    Npc* npc = resolve_npc(script, script->varTable[0]);
    f32 angle, sinAngle, cosAngle;

    if (isInitialCall) {
        script->varTable[6] = script->varTable[5];
        script->varTable[7] = dist2D(npc->pos.x, npc->pos.z, script->varTable[1], script->varTable[2]);
    }

    if (script->varTable[6] > 0) {
        angle = update_lerp(EASING_LINEAR, script->varTable[3], script->varTable[4], (f32) script->varTable[6], (f32) script->varTable[5]);
        sin_cos_deg(angle, &sinAngle, &cosAngle);
        npc->pos.x = script->varTable[1] + (script->varTable[7] * sinAngle);
        npc->pos.z = script->varTable[2] + (script->varTable[7] * cosAngle);
        script->varTable[6]--;
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_FadeToForestShading) = {
    EVT_CALL(N(InitializeGustyFogProperties))
    EVT_THREAD
        EVT_CALL(N(InterpFogDistance), 990, 980, 1000, -1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(InterpBackgroundDarkness), 0, 232, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(InterpSpriteShadingColor), 160, 160, 255)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FadeToGustyShading) = {
    EVT_CALL(N(InitializeGustyFogProperties))
    EVT_THREAD
        EVT_CALL(N(InterpFogDistance), 980, 990, 1000, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(InterpBackgroundDarkness), 232, 0, -20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(InterpSpriteShadingColor), 255, 255, 255)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenGate) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o67, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o67, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeLerp, 0, 80, 30, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o68, LVar0, 0, LVar2, 0)
    EVT_CALL(RotateModel, MODEL_o67, LVar0, 0, LVar3, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseGate) = {
    EVT_SET(LVar3, 0)
    EVT_SUB(LVar3, LVar2)
    EVT_CALL(MakeLerp, 80, 0, 30, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o68, LVar0, 0, LVar2, 0)
    EVT_CALL(RotateModel, MODEL_o67, LVar0, 0, LVar3, 0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar1, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o67, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o67, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterForest) = {
    EVT_EXEC(N(EVS_FadeToForestShading))
    EVT_SET(LVar2, -1)
    EVT_EXEC(N(EVS_OpenGate))
    EVT_WAIT(20)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -185, 0, 0)
    EVT_SET(LVar2, -1)
    EVT_EXEC(N(EVS_CloseGate))
    EVT_EXEC_WAIT(N(EVS_StartForestMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LeaveForest) = {
    EVT_EXEC(N(EVS_FadeToGustyShading))
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(EVS_OpenGate))
    EVT_WAIT(20)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -20, 0, 0)
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(EVS_CloseGate))
    EVT_EXEC_WAIT(N(EVS_StartGustyMusic))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CantOpenGateMessage) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D9, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseGate) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_IF_EQ(AF_MIM12_BackgroundLitUp, FALSE)
        EVT_EXEC_WAIT(N(EVS_LeaveForest))
        EVT_SET(AF_MIM12_BackgroundLitUp, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_EnterForest))
        EVT_SET(AF_MIM12_BackgroundLitUp, FALSE)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyDownToGate) = {
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_GateBoo_02, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump1, NPC_GateBoo_02, -66, 13, -15, 20)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_GateBoo_01, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump1, NPC_GateBoo_01, -89, 14, 28, 20)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HaveBoosOpenGate) = {
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_GateBoo_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_SET(LVar0, NPC_GateBoo_02)
        EVT_SET(LVar1, -66)
        EVT_SET(LVar2, -66)
        EVT_SET(LVar3, 80)
        EVT_SET(LVar4, 0)
        EVT_SET(LVar5, 30)
        EVT_CALL(N(MoveNpcAlongArc))
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_GateBoo_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(LVar0, NPC_GateBoo_01)
    EVT_SET(LVar1, -135)
    EVT_SET(LVar2, 59)
    EVT_SET(LVar3, 40)
    EVT_SET(LVar4, 120)
    EVT_SET(LVar5, 30)
    EVT_CALL(N(MoveNpcAlongArc))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HaveBoosCloseGate) = {
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_GateBoo_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_SET(LVar0, NPC_GateBoo_02)
        EVT_SET(LVar1, -66)
        EVT_SET(LVar2, -66)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 80)
        EVT_SET(LVar5, 30)
        EVT_CALL(N(MoveNpcAlongArc))
    EVT_END_THREAD
    EVT_CALL(SetNpcFlagBits, NPC_GateBoo_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_SET(LVar0, NPC_GateBoo_01)
    EVT_SET(LVar1, -135)
    EVT_SET(LVar2, 59)
    EVT_SET(LVar3, 120)
    EVT_SET(LVar4, 40)
    EVT_SET(LVar5, 30)
    EVT_CALL(N(MoveNpcAlongArc))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_UnlockGate) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(20 * DT)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_CALL(BringPartnerOut, PARTNER_BOW)
    EVT_IF_NE(LVar6, PARTNER_BOW)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBow_Walk)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_LOOP(10)
            EVT_ADD(LVar1, 2)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, SPEECH_FACE_SPEAKER_ONLY, MSG_CH3_006C)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(SetNpcPos, NPC_GateBoo_01, -103, 65, 64)
    EVT_CALL(SetNpcPos, NPC_GateBoo_02, -45, 65, -66)
    EVT_CALL(PlaySoundAtNpc, NPC_GateBoo_01, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(20 * DT)
        EVT_ADDF(LVar0, EVT_FLOAT(240.0 / (s32)(20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10 * DT)
    EVT_EXEC_WAIT(N(EVS_FlyDownToGate))
    EVT_EXEC(N(EVS_FadeToGustyShading))
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(EVS_OpenGate))
    EVT_EXEC_WAIT(N(EVS_HaveBoosOpenGate))
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, 25, 0, 60 * DT)
    EVT_END_THREAD
    EVT_WAIT(3 * DT)
    EVT_CALL(GetCurrentPartnerID, LVar6)
    EVT_IF_NE(LVar6, PARTNER_BOW)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -38, 23, 60 * DT)
    EVT_ELSE
        EVT_WAIT(60 * DT)
    EVT_END_IF
    EVT_SET(LVar2, 1)
    EVT_EXEC(N(EVS_CloseGate))
    EVT_EXEC_WAIT(N(EVS_StartGustyMusic))
    EVT_EXEC_WAIT(N(EVS_HaveBoosCloseGate))
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtNpc, NPC_GateBoo_01, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20 * DT)
        EVT_SUBF(LVar0, EVT_FLOAT(240.0 / (s32)(20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_01, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_GateBoo_02, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_GateBoo_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_GateBoo_02, NPC_DISPOSE_LOCATION)
    EVT_WAIT(10 * DT)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBow_Talk, ANIM_WorldBow_Idle, 0, MSG_CH3_006D)
    EVT_CALL(EnablePartnerAI)
    EVT_WAIT(5 * DT)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 14 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Land)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_WAIT(10 * DT)
    EVT_SET(GB_StoryProgress, STORY_CH3_UNLOCKED_GUSTY_GULCH)
    EVT_CALL(PutPartnerAway)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_SET(AF_MIM12_BackgroundLitUp, TRUE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate)), TRIGGER_WALL_PRESS_A, COLLIDER_o67, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupForestGate) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_BOW_JOINED_PARTY)
            EVT_CALL(N(InitializeForestFogProperties))
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_CantOpenGateMessage)), TRIGGER_WALL_PRESS_A, COLLIDER_o67, 1, 0)
        EVT_CASE_LT(STORY_CH3_UNLOCKED_GUSTY_GULCH)
            EVT_CALL(N(InitializeForestFogProperties))
            EVT_LOOP(0)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_GE(LVar0, -200)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_EXEC_WAIT(N(EVS_Scene_UnlockGate))
        EVT_CASE_GE(STORY_CH3_UNLOCKED_GUSTY_GULCH)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, mim_12_ENTRY_0)
                EVT_SET(AF_MIM12_BackgroundLitUp, FALSE)
                EVT_CALL(N(InitializeForestFogProperties))
            EVT_ELSE
                EVT_SET(AF_MIM12_BackgroundLitUp, TRUE)
                EVT_CALL(N(InitializeGustyFogProperties))
                EVT_CALL(EnableSpriteShading, FALSE)
            EVT_END_IF
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseGate)), TRIGGER_WALL_PRESS_A, COLLIDER_o67, 1, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
