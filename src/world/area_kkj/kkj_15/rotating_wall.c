#include "kkj_15.h"
#include "sprite/player.h"

API_CALLABLE(N(UpdateRotatingPartyPositions)) {
    Npc* partner = get_npc_safe(NPC_PARTNER);
    f32 var = EVT_FIXED_TO_FLOAT(script->varTable[2]);
    f32 angle;
    f32 mag;

    mag = dist2D(50.0f, -200.0f, script->varTable[7], script->varTable[8]);
    angle = atan2(50.0f, -200.0f, script->varTable[7], script->varTable[8]);
    angle = clamp_angle(angle - var);
    gPlayerStatus.pos.x = 50.0f + mag * sin_deg(angle);
    gPlayerStatus.pos.z = -200.0f - mag * cos_deg(angle);

    mag = dist2D(50.0f, -200.0f, script->varTable[9], script->varTable[10]);
    angle = atan2(50.0f, -200.0f, script->varTable[9], script->varTable[10]);
    angle = clamp_angle(angle - var);
    partner->pos.x = 50.0f + mag * sin_deg(angle);
    partner->pos.z = -200.0f - mag * cos_deg(angle);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateRotatingWall_AlmostCaught) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g22, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetPlayerPos, LVar7, LVar0, LVar8)
    Call(GetNpcPos, NPC_PARTNER, LVar9, LVar0, LVarA)
    Thread
        Wait(180 * DT)
        Call(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EndThread
    Call(PlaySoundAt, SOUND_KKJ_ROTATING_WALL, SOUND_SPACE_DEFAULT, 50, 5, -200)
    Call(MakeLerp, 0, -1800, 360 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(RotateGroup, MODEL_g28, LVar2, 0, 1, 0)
        Call(N(UpdateRotatingPartyPositions))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_KKJ_ROTATING_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g25, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_AnimateRotatingWall_Default) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g22, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetPlayerPos, LVar7, LVar0, LVar8)
    Call(GetNpcPos, NPC_PARTNER, LVar9, LVar0, LVarA)
    Call(MakeLerp, -1350, -1800, 90 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, 10)
        Call(RotateGroup, MODEL_g28, LVar2, 0, 1, 0)
        Call(N(UpdateRotatingPartyPositions))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_KKJ_ROTATING_WALL)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g25, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_RotatingWall_Default) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 10, -35)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetPanTarget, CAM_DEFAULT, 50, 10, -35)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    ExecWait(N(EVS_AnimateRotatingWall_Default))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Return
    End
};

// used during chapter 1, adds an extra camera move and a remark by twink
EvtScript N(EVS_RotatingWall_FirstTime) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 10, -35)
    Call(SetPanTarget, CAM_DEFAULT, 50, 35, -35)
    Call(SetCamDistance, CAM_DEFAULT, 200)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(SetPanTarget, CAM_DEFAULT, 50, 10, -35)
        Call(SetCamDistance, CAM_DEFAULT, 400)
#if VERSION_PAL
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.961))
#else
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.8 / DT))
#endif
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    ExecWait(N(EVS_AnimateRotatingWall_Default))
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0049)
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Return
    End
};

EvtScript N(EVS_EnterRotatingWall) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerPos, 50, 10, -250)
    Call(SetNpcPos, NPC_PARTNER, 10, 30, -250)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(InterpPlayerYaw, 270, 0)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH1_BEGAN_PEACH_MISSION)
            ExecWait(N(EVS_RotatingWall_FirstTime))
        CaseDefault
            ExecWait(N(EVS_RotatingWall_Default))
    EndSwitch
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, false)
    Call(DisablePlayerInput, false)
    Return
    End
};
