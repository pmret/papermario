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
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g22, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetPlayerPos, LVar7, LVar0, LVar8)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar9, LVar0, LVarA)
    EVT_THREAD
        EVT_WAIT(180 * DT)
        EVT_CALL(SetPlayerAnimation, ANIM_Peach2_LookAround)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_KKJ_ROTATING_WALL, SOUND_SPACE_DEFAULT, 50, 5, -200)
    EVT_CALL(MakeLerp, 0, -1800, 360 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(RotateGroup, MODEL_g28, LVar2, 0, 1, 0)
        EVT_CALL(N(UpdateRotatingPartyPositions))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_KKJ_ROTATING_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g25, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateRotatingWall_Default) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g22, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetPlayerPos, LVar7, LVar0, LVar8)
    EVT_CALL(GetNpcPos, NPC_PARTNER, LVar9, LVar0, LVarA)
    EVT_CALL(MakeLerp, -1350, -1800, 90 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, 10)
        EVT_CALL(RotateGroup, MODEL_g28, LVar2, 0, 1, 0)
        EVT_CALL(N(UpdateRotatingPartyPositions))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_KKJ_ROTATING_WALL)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_g25, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RotatingWall_Default) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 10, -35)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 10, -35)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_EXEC_WAIT(N(EVS_AnimateRotatingWall_Default))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

// used during chapter 1, adds an extra camera move and a remark by twink
EvtScript N(EVS_RotatingWall_FirstTime) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 10, -35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 35, -35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 200)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 10, -35)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
#if VERSION_PAL
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.961))
#else
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8 / DT))
#endif
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(EVS_AnimateRotatingWall_Default))
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0049)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterRotatingWall) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, 50, 10, -250)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 10, 30, -250)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(InterpPlayerYaw, 270, 0)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_EQ(STORY_CH1_BEGAN_PEACH_MISSION)
            EVT_EXEC_WAIT(N(EVS_RotatingWall_FirstTime))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_RotatingWall_Default))
    EVT_END_SWITCH
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
