#include "kkj_27.h"
#include "sprite/player.h"

s32 N(SpillLightAmount) = 0;

API_CALLABLE(N(UpdateRotatingPlayerPosition)) {
    f32 var = EVT_FIXED_TO_FLOAT(script->varTable[2]);
    f32 angle;
    f32 mag;

    mag = dist2D(-250.0f, 0.0f, script->varTable[9], script->varTable[10]);
    angle = atan2(-250.0f, 0.0f, script->varTable[9], script->varTable[10]);
    angle = clamp_angle(angle - var);
    gPlayerStatus.pos.x = -250.0f + mag * sin_deg(angle);
    gPlayerStatus.pos.z = 0.0f - mag * cos_deg(angle);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetSpillLightAmount)) {
    Bytecode* args = script->ptrReadPos;

    N(SpillLightAmount) = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

void N(setup_gfx_spill_light)(void) {
    if (N(SpillLightAmount) > 0) {
        gDPSetCombineLERP(gMainGfxPos++, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(SpillLightAmount));
    }
}

EvtScript N(EVS_Scene_RotatingWall) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_93, 0, -250, 5, 0)
        EVT_CALL(GetPlayerPos, LVar9, LVar0, LVarA)
        EVT_CALL(MakeLerp, 0, -450, 120 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 10)
            EVT_CALL(RotateGroup, MODEL_g29, LVar2, 0, 1, 0)
            EVT_CALL(N(UpdateRotatingPlayerPosition))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(EnableModel, MODEL_o182, TRUE)
        EVT_CALL(EnableModel, MODEL_o184, TRUE)
        EVT_CALL(EnableModel, MODEL_o186, TRUE)
        EVT_CALL(MakeLerp, 8, 255, 40 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetSpillLightAmount), LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(80 * DT)
    EVT_SET(GF_KKJ14_SkipSecretPassage, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("kkj_15"), kkj_15_ENTRY_1)
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseRotatingWall) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlayerMoveTo, -205, -10, 15 * DT)
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_ReachForButton)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o193, SOUND_FA, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_PressButton)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_AfterPressButton)
    EVT_WAIT(10 * DT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_Scene_RotatingWall))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseRotatingWall_FirstTime) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(FacePlayerTowardPoint, -222, 0, 5)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_ReachForButton)
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o193, SOUND_FA, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_PressButton)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Peach3_AfterPressButton)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        EVT_CALL(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
        EVT_CALL(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Gasp, ANIM_Peach2_GaspStill, 5, MSG_Peach_0048)
    EVT_END_THREAD
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_EXEC_WAIT(N(EVS_Scene_RotatingWall))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupRotatingWall) = {
    EVT_CALL(EnableModel, MODEL_o182, FALSE)
    EVT_CALL(EnableModel, MODEL_o184, FALSE)
    EVT_CALL(EnableModel, MODEL_o186, FALSE)
    EVT_CALL(SetModelCustomGfx, MODEL_o182, CUSTOM_GFX_1, FOG_MODE_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o184, CUSTOM_GFX_1, FOG_MODE_UNCHANGED)
    EVT_CALL(SetModelCustomGfx, MODEL_o186, CUSTOM_GFX_1, FOG_MODE_UNCHANGED)
    EVT_CALL(SetCustomGfxBuilders, CUSTOM_GFX_1, EVT_PTR(N(setup_gfx_spill_light)), NULL)
    EVT_IF_EQ(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseRotatingWall_FirstTime)), TRIGGER_WALL_PRESS_A, COLLIDER_o193, 1, 0)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseRotatingWall)), TRIGGER_WALL_PRESS_A, COLLIDER_o193, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
