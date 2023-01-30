#include "hos_05.h"
#include "effects.h"
#include "model.h"

extern s16 D_802D9D72; // something wrong with this / the next
extern u8 D_802D9D73;

#define NAME_SUFFIX _Unk7
#include "world/common/atomic/UnkFunc27.inc.c"
#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"
#define NAME_SUFFIX

BSS s32 D_8024F570[4];
BSS u8 N(oldPrimR), N(oldPrimG), N(oldPrimB);
BSS u8 N(oldEnvR), N(oldEnvG), N(oldEnvB);
BSS s32 N(newPrimR), N(newPrimG), N(newPrimB);
BSS s32 N(newEnvR), N(newEnvG), N(newEnvB);
BSS s32 N(duration), N(time);

API_CALLABLE(N(func_802452C4_A2F504)) {
    Bytecode* args;
    args = script->ptrReadPos;
    if (isInitialCall) {
        get_model_env_color_parameters(&N(oldPrimR), &N(oldPrimG), &N(oldPrimB), &N(oldEnvR), &N(oldEnvG), &N(oldEnvB));
        N(newPrimR) = evt_get_variable(script, *args++);
        N(newPrimG) = evt_get_variable(script, *args++);
        N(newPrimB) = evt_get_variable(script, *args++);
        N(newEnvR) = evt_get_variable(script, *args++);
        N(newEnvG) = evt_get_variable(script, *args++);
        N(newEnvB) = evt_get_variable(script, *args++);
        N(duration) = evt_get_variable(script, *args++);
        N(time) = 0;
    }

    if (N(duration) > 0) {
        N(time)++;
        set_model_env_color_parameters(
            (N(oldPrimR) + ((N(newPrimR) - N(oldPrimR)) * N(time)) / N(duration)),
            (N(oldPrimG) + ((N(newPrimG) - N(oldPrimG)) * N(time)) / N(duration)),
            (N(oldPrimB) + ((N(newPrimB) - N(oldPrimB)) * N(time)) / N(duration)),
            (N(oldEnvR)  + ( (N(newEnvR) - N(oldEnvR))  * N(time)) / N(duration)),
            (N(oldEnvG)  + ( (N(newEnvG) - N(oldEnvG))  * N(time)) / N(duration)),
            (N(oldEnvB)  + ( (N(newEnvB) - N(oldEnvB))  * N(time)) / N(duration)));
        if (N(time) >= N(duration)) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(N(newPrimR), N(newPrimG), N(newPrimB), N(newEnvR), N(newEnvG), N(newEnvB));
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

void N(func_8024564C_A2F88C)(void) {
    gDPSetCombineLERP(gMasterGfxPos++,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_802D9D73);
}

API_CALLABLE(N(func_8024569C_A2F8DC)) {
    Bytecode* args = script->ptrReadPos;

    D_802D9D72 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

s32 N(D_8024DCCC_A37F0C) = 255;

void N(func_802456C8_A2F908)(void) {
    gDPSetCombineLERP(gMasterGfxPos++,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_8024DCCC_A37F0C));
}

API_CALLABLE(N(func_80245718_A2F958)) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024DCCC_A37F0C) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

s32 N(D_8024DCD0_A37F10) = 255;

void N(func_80245744_A2F984)(void) {
    gDPSetCombineLERP(gMasterGfxPos++,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0,
        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, N(D_8024DCD0_A37F10));
}

API_CALLABLE(N(func_80245794_A2F9D4)) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024DCD0_A37F10) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802457C0_A2FA00)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        script->functionTemp[0] = 40;
    }
    script->functionTemp[0]--;
    if (camera->currentController != NULL) {
        camera->currentController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    } else if (camera->prevController != NULL) {
        camera->prevController->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(D_8024DCD4_A37F14) = {
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, 60, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_ADDF(LVar2, MV_Unk_0B)
            EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_g277, MV_Unk_0A, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 60, 0, 30, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_MULF(LVar2, EVT_FLOAT(0.1))
            EVT_ADDF(LVar2, MV_Unk_0B)
            EVT_CALL(TranslateGroup, MODEL_g279, 0, LVar2, 0)
            EVT_CALL(TranslateGroup, MODEL_g277, 0, LVar2, 0)
            EVT_CALL(RotateGroup, MODEL_g277, MV_Unk_0A, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DED8_A38118) = {
    EVT_LOOP(0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o630)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o627)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024DF28) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o630, MODEL_o637)
    EVT_CALL(ParentColliderToModel, COLLIDER_o627, MODEL_o637)
    EVT_IF_GE(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        EVT_EXEC(N(D_8024DED8_A38118))
        EVT_SET(MV_Unk_0A, -110)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, hos_05_ENTRY_3)
            EVT_SET(MV_Unk_0B, 900)
        EVT_ELSE
            EVT_SET(MV_Unk_0B, -85)
        EVT_END_IF
        EVT_EXEC(N(D_8024DCD4_A37F14))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(D_8024DFF0_A38230)[] = {
    8, 11, 12, 24, 114, 139, 0x0000FFFF 
};

EvtScript N(EVS_8024E00C) = {
    EVT_CALL(EnableGroup, MODEL_g268, FALSE)
    EVT_CALL(EnableGroup, MODEL_g178, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH8_STAR_SHIP_ACTIVATED)
        EVT_CALL(EnableModel, MODEL_o8, FALSE)
    EVT_ELSE
        EVT_CALL(SetModelCustomGfx, MODEL_o8, 0, -1)
        EVT_CALL(SetCustomGfxBuilders, 0, EVT_PTR(N(func_8024564C_A2F88C)), 0)
        EVT_CALL(EnableModel, MODEL_o8, TRUE)
        EVT_CALL(N(func_8024569C_A2F8DC), 127)
        EVT_CALL(EnableGroup, MODEL_g277, TRUE)
        EVT_CALL(EnableModel, MODEL_o362, FALSE)
        EVT_CALL(EnableModel, MODEL_o397, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o616, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetZoneEnabled, ZONE_o622, FALSE)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024E148) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(N(UnkFunc27_Unk7), 2, 0, 3)
        EVT_CALL(N(UnkFunc27_Unk7), 1, EVT_PTR(N(D_8024DFF0_A38230)), 3)
        EVT_CALL(N(func_802452C4_A2F504), 255, 255, 255, 0, 0, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(N(func_802452C4_A2F504), 102, 102, 102, 0, 0, 0, 60)
    EVT_END_THREAD
    EVT_EXEC(N(D_8024DED8_A38118))
    EVT_SET(MV_Unk_0A, 0)
    EVT_SET(MV_Unk_0B, 0)
    EVT_EXEC(N(D_8024DCD4_A37F14))
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_9)
        TEX_PAN_PARAMS_STEP(  -90,   70,  -60,   90)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan_Unk7))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o646, 9)
    EVT_CALL(PlaySoundAt, SOUND_A3, 0, 0, 250, 0)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, 0, 250, 0, 10, LVar9)
    EVT_WAIT(20)
    EVT_CALL(SetModelCustomGfx, MODEL_o646, 1, -1)
    EVT_CALL(SetCustomGfxBuilders, 1, EVT_PTR(N(func_802456C8_A2F908)), 0)
    EVT_CALL(EnableGroup, MODEL_g279, TRUE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 200, 75, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(func_80245718_A2F958), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(SetModelCustomGfx, MODEL_o8, 0, -1)
    EVT_CALL(SetCustomGfxBuilders, 0, EVT_PTR(N(func_8024564C_A2F88C)), 0)
    EVT_CALL(EnableModel, MODEL_o8, TRUE)
    EVT_CALL(MakeLerp, 0, 127, 60, EASING_COS_IN_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_8024569C_A2F8DC), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_4A3, 0, 0, 250, 0)
    EVT_CALL(func_802D7B10, LVar9)
    EVT_CALL(EnableGroup, MODEL_g277, TRUE)
    EVT_CALL(MakeLerp, 200, 0, 45, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(func_80245718_A2F958), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableGroup, MODEL_g279, FALSE)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -110, 90, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SET(MV_Unk_0A, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -85, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Unk_0B, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(N(func_802452C4_A2F504), 255, 255, 255, 0, 0, 0, 60)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E760_A389A0) = {
    EVT_LABEL(0)
    EVT_CALL(GetModelCenter, MODEL_o637)
    EVT_ADD(LVar0, -5)
    EVT_IF_EQ(MV_Unk_0C, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_ADD(LVar0, 10)
    EVT_IF_EQ(MV_Unk_0D, 1)
        EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024E828) = {
    EVT_CALL(GetPartnerInUse, LVar9)
    EVT_IF_NE(LVar9, PARTNER_NONE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, TRUE)
    EVT_EXEC_GET_TID(N(D_8024E760_A389A0), LVar9)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(GetModelCenter, MODEL_o637)
    EVT_ADD(LVar0, -5)
    EVT_CALL(SetPlayerJumpscale, 0)
    EVT_CALL(PlayerJump2, LVar0, LVar1, LVar2, 2)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_SET(MV_Unk_0C, 1)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(1.5))
    EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 12)
    EVT_CALL(SetNpcAnimation, NPC_PARTNER, 0x00000106)
    EVT_SET(MV_Unk_0D, 1)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_WAIT(10)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0188, 160, 40)
    EVT_CALL(ShowChoice, MSG_Choice_000C)
    EVT_CALL(CloseMessage)
    EVT_IF_EQ(LVar0, 1)
        EVT_KILL_THREAD(LVar9)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_SET(MV_Unk_0C, 0)
        EVT_THREAD
            EVT_SET(MV_Unk_0D, 0)
            EVT_CALL(PartnerIsFlying, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_WAIT(10)
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 1)
                EVT_CALL(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
            EVT_END_IF
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, FALSE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
        EVT_CALL(SetPlayerJumpscale, 1)
        EVT_CALL(PlayerJump, 25, 162, 45, 10)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
        EVT_CALL(HidePlayerShadow, FALSE)
        EVT_WAIT(10)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(20)
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 0, 8)
    EVT_ELSE
        EVT_CALL(SetMusicTrack, 0, SONG_STARSHIP_THEME, 1, 8)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(N(func_802457C0_A2FA00))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_17D, 0)
    EVT_SET(LVar2, MV_Unk_0B)
    EVT_CALL(MakeLerp, 0, 1000, 100, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_ADD(LVar0, LVar2)
        EVT_SET(MV_Unk_0B, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_IF_LT(GB_StoryProgress, STORY_UNUSED_0000005D)
        EVT_CALL(GotoMap, EVT_PTR("hos_04"), hos_04_ENTRY_2)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("hos_20"), hos_20_ENTRY_0)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024ED24) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 180, -5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 180, -5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(550.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-35.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(MV_Unk_0C, 1)
    EVT_SET(MV_Unk_0D, 1)
    EVT_EXEC_GET_TID(N(D_8024E760_A389A0), LVar9)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(MakeLerp, -350, -70, 60, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 10)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), LVar2)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPlayer, SOUND_17F, 0)
    EVT_CALL(MakeLerp, 750, -85, 90, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_Unk_0B, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_SET(MV_Unk_0C, 0)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(PlayerJump, 25, 162, 45, 10)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_THREAD
        EVT_SET(MV_Unk_0D, 0)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CASE_EQ(PARTNER_BOW)
            EVT_CASE_EQ(PARTNER_WATT)
            EVT_CASE_EQ(PARTNER_LAKILESTER)
            EVT_CASE_DEFAULT
                EVT_WAIT(10)
                EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 1)
                EVT_CALL(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
        EVT_END_SWITCH
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_40, FALSE)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetMusicTrack, 0, SONG_STAR_SANCTUARY, 0, 8)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
