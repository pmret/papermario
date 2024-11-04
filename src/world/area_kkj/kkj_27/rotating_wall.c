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
        gDPSetCombineMode(gMainGfxPos++, PM_CC_KKJ_SPILL_LIGHT, PM_CC_KKJ_SPILL_LIGHT);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, N(SpillLightAmount));
    }
}

EvtScript N(EVS_Scene_RotatingWall) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o124, COLLIDER_FLAGS_UPPER_MASK)
    Thread
        Call(PlaySoundAt, SOUND_KKJ_ROTATING_WALL, SOUND_SPACE_DEFAULT, -250, 5, 0)
        Call(GetPlayerPos, LVar9, LVar0, LVarA)
        Call(MakeLerp, 0, -450, 120 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 10)
            Call(RotateGroup, MODEL_g29, LVar2, 0, 1, 0)
            Call(N(UpdateRotatingPlayerPosition))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(EnableModel, MODEL_o182, TRUE)
        Call(EnableModel, MODEL_o184, TRUE)
        Call(EnableModel, MODEL_o186, TRUE)
        Call(MakeLerp, 8, 255, 40 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(N(SetSpillLightAmount), LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(80 * DT)
    Set(GF_KKJ14_SkipSecretPassage, TRUE)
    Call(GotoMap, Ref("kkj_15"), kkj_15_ENTRY_1)
    Wait(100 * DT)
    Return
    End
};

EvtScript N(EVS_UseRotatingWall) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, TRUE)
    Call(PlayerMoveTo, -205, -10, 15 * DT)
    Call(InterpPlayerYaw, 270, 5)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach3_ReachForButton)
    Wait(10 * DT)
    Call(PlaySoundAtCollider, COLLIDER_o193, SOUND_KKJ_PRESS_BUTTON, 0)
    Call(SetPlayerAnimation, ANIM_Peach3_PressButton)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach3_AfterPressButton)
    Wait(10 * DT)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    ExecWait(N(EVS_Scene_RotatingWall))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_UseRotatingWall_FirstTime) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    Call(DisablePlayerInput, TRUE)
    Call(FacePlayerTowardPoint, -222, 0, 5)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach3_ReachForButton)
    Wait(10 * DT)
    Call(PlaySoundAtCollider, COLLIDER_o193, SOUND_KKJ_PRESS_BUTTON, 0)
    Call(SetPlayerAnimation, ANIM_Peach3_PressButton)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach3_AfterPressButton)
    Wait(10 * DT)
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Cringe)
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 10)
        Call(EnablePartnerAI)
    EndThread
    Thread
        Call(InterpPlayerYaw, 270, 0)
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
        Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Gasp, ANIM_Peach2_GaspStill, 5, MSG_Peach_0048)
    EndThread
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    ExecWait(N(EVS_Scene_RotatingWall))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupRotatingWall) = {
    Call(EnableModel, MODEL_o182, FALSE)
    Call(EnableModel, MODEL_o184, FALSE)
    Call(EnableModel, MODEL_o186, FALSE)
    Call(SetModelCustomGfx, MODEL_o182, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o184, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetModelCustomGfx, MODEL_o186, CUSTOM_GFX_1, ENV_TINT_UNCHANGED)
    Call(SetCustomGfxBuilders, CUSTOM_GFX_1, Ref(N(setup_gfx_spill_light)), NULL)
    IfEq(GB_StoryProgress, STORY_CH1_BEGAN_PEACH_MISSION)
        BindTrigger(Ref(N(EVS_UseRotatingWall_FirstTime)), TRIGGER_WALL_PRESS_A, COLLIDER_o193, 1, 0)
    Else
        BindTrigger(Ref(N(EVS_UseRotatingWall)), TRIGGER_WALL_PRESS_A, COLLIDER_o193, 1, 0)
    EndIf
    Return
    End
};
