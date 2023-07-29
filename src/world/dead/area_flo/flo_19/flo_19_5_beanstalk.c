#include "flo_19.h"
#include "effects.h"
#include "sprite/player.h"

API_CALLABLE(N(GetPlayerAngles)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;
    s32 var2 = *args++;

    evt_set_variable(script, var1, gPlayerStatus.spriteFacingAngle);
    evt_set_variable(script, var2, gPlayerStatus.targetYaw);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayerRideBeanstalk)) {
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    gPlayerStatus.pos.x = (dist * temp) + 0.0f;
    gPlayerStatus.pos.y = evt_get_variable(NULL, script->varTable[10]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    gPlayerStatus.pos.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PartnerRideBeanstalk)) {
    Npc* npc = get_npc_by_index(NPC_Dummy_Partner);
    f32 temp = evt_get_variable(NULL, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    npc->pos.x = (dist * temp) + 0.0f;
    npc->pos.y = evt_get_variable(NULL, script->varTable[13]) + evt_get_variable(NULL, script->varTable[3]);
    temp = cos_deg(clamped);
    npc->pos.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetScreenFadeAmount)) {
    set_screen_overlay_params_back(OVERLAY_VIEWPORT_COLOR, script->varTable[0]);
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

// all data in this file is truncated
/*
EvtScript N(EVS_FadeOutToBlack) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(10)
        EVT_CALL(N(SetScreenFadeAmount))
        EVT_ADD(LVar0, 25)
        EVT_WAIT(1)
        EVT_IF_LT(LVar0, 255)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(LVar0, 255)
    EVT_CALL(N(SetScreenFadeAmount))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FadeInFromBlack) = {
    EVT_SET(LVar0, 255)
    EVT_LABEL(10)
        EVT_CALL(N(SetScreenFadeAmount))
        EVT_SUB(LVar0, 25)
        EVT_WAIT(1)
        EVT_IF_GT(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_CALL(N(SetScreenFadeAmount))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetExteriorVineGrowth) = {
    EVT_CALL(TranslateGroup, MODEL_g83, 0, LVar0, 0)
    EVT_CALL(TranslateGroup, MODEL_ha, 0, LVar0, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, MODEL_g83, LVar1, 0, 1, 0)
    EVT_CALL(RotateGroup, MODEL_ha, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetInteriorVineGrowth) = {
    EVT_CALL(TranslateGroup, MODEL_g84, 0, LVar0, 0)
    EVT_SETF(LVar1, LVar0)
    EVT_MULF(LVar1, EVT_FLOAT(-12.0))
    EVT_CALL(RotateGroup, MODEL_g84, LVar1, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Enter_Beanstalk) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(11.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(EnableGroup, MODEL_g16, FALSE)
    EVT_CALL(EnableGroup, MODEL_g2, FALSE)
    EVT_CALL(EnableGroup, MODEL_g3, FALSE)
    EVT_CALL(EnableGroup, MODEL_g19, FALSE)
    EVT_CALL(EnableGroup, MODEL_g93, FALSE)
    EVT_CALL(EnableGroup, MODEL_g15, FALSE)
    EVT_CALL(EnableGroup, MODEL_g25, FALSE)
    EVT_SET(LVar9, EVT_FLOAT(45.0))
    EVT_SET(LVarA, EVT_FLOAT(28.0))
    EVT_SET(LVarB, EVT_FLOAT(5.0))
    EVT_SET(LVarC, EVT_FLOAT(60.0))
    EVT_SET(LVarD, EVT_FLOAT(28.0))
    EVT_SET(LVarE, EVT_FLOAT(10.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_SWITCH(AF_FLO_BeanstalkFacingRight)
            EVT_CASE_EQ(0)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_EQ(1)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(1.313), EVT_FLOAT(3.0), EVT_FLOAT(-0.56640625))
    EVT_CALL(UpdateColliderTransform, COLLIDER_o117)
    EVT_THREAD
        EVT_SET(AF_FLO_BeanstalkFadedOut, FALSE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_WAIT(200)
        EVT_EXEC_WAIT(N(EVS_FadeOutToBlack))
        EVT_SET(AF_FLO_BeanstalkFadedOut, TRUE)
        EVT_WAIT(10)
        EVT_CALL(EnableGroup, MODEL_g16, TRUE)
        EVT_CALL(EnableGroup, MODEL_g2, TRUE)
        EVT_CALL(EnableGroup, MODEL_g3, TRUE)
        EVT_CALL(EnableGroup, MODEL_g19, TRUE)
        EVT_CALL(EnableGroup, MODEL_g93, TRUE)
        EVT_CALL(EnableGroup, MODEL_g15, TRUE)
        EVT_CALL(EnableGroup, MODEL_g25, TRUE)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-6.0))
        EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC_WAIT(N(EVS_FadeInFromBlack))
        EVT_WAIT(20)
        EVT_SET(AF_FLO_BeanstalkFadedOut, FALSE)
    EVT_END_THREAD
    EVT_SET(LVarF, 0)
    EVT_LOOP(344)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, -210, 0, 344, 0, 0)
        EVT_SETF(LVar1, LVar0)
        EVT_MULF(LVar1, EVT_FLOAT(-3.0))
        EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(1.313), LVar0, EVT_FLOAT(-0.56640625))
        EVT_CALL(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o117)
        EVT_SETF(LVar2, LVar0)
        EVT_MULF(LVar2, EVT_FLOAT(-3.0))
        EVT_SETF(LVar3, LVar0)
        EVT_CALL(N(PlayerRideBeanstalk))
        EVT_CALL(N(PartnerRideBeanstalk))
        EVT_LABEL(11)
            EVT_WAIT(1)
            EVT_IF_EQ(AF_FLO_BeanstalkFadedOut, TRUE)
                EVT_GOTO(11)
            EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ClearPartnerMoveHistory, NPC_PARTNER)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, 100, 0, 60, 20)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(5)
    EVT_SET(AF_FLO_RidingBeanstalk, FALSE)
    EVT_CALL(StopSound, SOUND_19C)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Exit_Beanstalk) = {
    EVT_IF_EQ(AF_FLO_RidingBeanstalk, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(15)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_SET(AF_FLO_RidingBeanstalk, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(LVar9, EVT_FLOAT(45.0))
        EVT_SET(LVarA, EVT_FLOAT(28.0))
        EVT_SET(LVarB, EVT_FLOAT(5.0))
        EVT_SET(LVarC, EVT_FLOAT(60.0))
        EVT_SET(LVarD, EVT_FLOAT(28.0))
        EVT_SET(LVarE, EVT_FLOAT(10.0))
        EVT_CALL(PlayerMoveTo, LVar9, LVarB, 8)
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, LVarC, LVarD, LVarE, 5)
        EVT_CALL(PlaySound, SOUND_19D)
        EVT_CALL(SetMusicTrack, 0, SONG_MAGIC_BEANSTALK, 1, 8)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
        EVT_CALL(N(GetPlayerAngles), LVar3, LVar4)
        EVT_SWITCH(LVar4)
            EVT_CASE_LT(90)
                EVT_SET(AF_FLO_BeanstalkFacingRight, FALSE)
                EVT_CALL(InterpPlayerYaw, 90, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CASE_GE(270)
                EVT_SET(AF_FLO_BeanstalkFacingRight, TRUE)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_SWITCH
        EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(1.313), EVT_FLOAT(3.0), EVT_FLOAT(-0.56640625))
        EVT_CALL(UpdateColliderTransform, COLLIDER_o117)
        EVT_SET(MV_BeanstalkSceneSync, FALSE)
        EVT_THREAD
            EVT_SET(AF_FLO_BeanstalkFadedOut, FALSE)
            EVT_WAIT(120)
            EVT_SET(AF_FLO_BeanstalkFadedOut, TRUE)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(EVS_FadeOutToBlack))
            EVT_WAIT(10)
            EVT_CALL(EnableGroup, MODEL_g16, FALSE)
            EVT_CALL(EnableGroup, MODEL_g2, FALSE)
            EVT_CALL(EnableGroup, MODEL_g3, FALSE)
            EVT_CALL(EnableGroup, MODEL_g19, FALSE)
            EVT_CALL(EnableGroup, MODEL_g93, FALSE)
            EVT_CALL(EnableGroup, MODEL_g15, FALSE)
            EVT_CALL(EnableGroup, MODEL_g25, FALSE)
            EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(7.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SET(AF_FLO_BeanstalkFadedOut, FALSE)
            EVT_EXEC_WAIT(N(EVS_FadeInFromBlack))
        EVT_END_THREAD
        EVT_THREAD
            EVT_SET(LVarF, 0)
            EVT_LOOP(344)
                EVT_ADD(LVarF, 1)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, 0, -210, 344, 0, 0)
                EVT_SETF(LVar1, LVar0)
                EVT_MULF(LVar1, EVT_FLOAT(-3.0))
                EVT_CALL(TranslateModel, MODEL_o142, EVT_FLOAT(1.313), LVar0, EVT_FLOAT(-0.56640625))
                EVT_CALL(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, COLLIDER_o117)
                EVT_SETF(LVar2, LVar0)
                EVT_MULF(LVar2, EVT_FLOAT(-3.0))
                EVT_SETF(LVar3, LVar0)
                EVT_CALL(N(PlayerRideBeanstalk))
                EVT_CALL(N(PartnerRideBeanstalk))
                EVT_IF_EQ(LVarF, 300)
                    EVT_SET(MV_BeanstalkSceneSync, TRUE)
                EVT_END_IF
                EVT_LABEL(11)
                    EVT_WAIT(1)
                    EVT_IF_EQ(AF_FLO_BeanstalkFadedOut, TRUE)
                        EVT_GOTO(11)
                    EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_LABEL(10)
            EVT_IF_EQ(MV_BeanstalkSceneSync, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_8)
        EVT_WAIT(100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeanstalkGrowing) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(EnableModel, MODEL_o142, FALSE)
    EVT_CALL(EnableGroup, MODEL_g16, FALSE)
    EVT_CALL(EnableGroup, MODEL_g2, FALSE)
    EVT_CALL(EnableGroup, MODEL_g3, FALSE)
    EVT_CALL(EnableGroup, MODEL_g19, FALSE)
    EVT_CALL(EnableGroup, MODEL_g93, FALSE)
    EVT_CALL(EnableGroup, MODEL_g15, FALSE)
    EVT_CALL(EnableGroup, MODEL_g25, FALSE)
    EVT_CALL(SetCamType, CAM_DEFAULT, 1, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 800)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(-20.0), EVT_FLOAT(8.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_SET(LVarF, 100)
    EVT_SET(MV_BeanstalkGrowthProgress, LVarF)
    EVT_SET(AF_FLO_BeanstalkGrowing, FALSE)
    EVT_LOOP(400)
        EVT_IF_EQ(AF_FLO_BeanstalkGrowing, FALSE)
            EVT_IF_GT(MV_BeanstalkGrowthProgress, 400)
                EVT_CALL(EnableGroup, MODEL_tuta, FALSE)
                EVT_CALL(EnableGroup, MODEL_ha, FALSE)
                EVT_CALL(EnableGroup, MODEL_g16, TRUE)
                EVT_CALL(EnableGroup, MODEL_g2, TRUE)
                EVT_CALL(EnableGroup, MODEL_g3, TRUE)
                EVT_CALL(EnableGroup, MODEL_g19, TRUE)
                EVT_CALL(EnableGroup, MODEL_g93, TRUE)
                EVT_CALL(EnableGroup, MODEL_g15, TRUE)
                EVT_CALL(EnableGroup, MODEL_g25, TRUE)
                EVT_CALL(SetCamDistance, CAM_DEFAULT, 1000)
                EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(45.0), EVT_FLOAT(-3.0))
                EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
                EVT_CALL(SetCamPosB, CAM_DEFAULT, 0, 0)
                EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
                EVT_SET(LVarF, 150)
                EVT_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(EnableGroup, MODEL_tuta, TRUE)
                    EVT_CALL(EnableGroup, MODEL_ha, TRUE)
                    EVT_CALL(EnableModel, MODEL_o142, FALSE)
                    EVT_WAIT(48)
                    EVT_PLAY_EFFECT(EFFECT_CLOUD_PUFF, 0, 22, 15, 0)
                    EVT_WAIT(10)
                    EVT_PLAY_EFFECT(EFFECT_CLOUD_PUFF, 0, 22, 15, 0)
                EVT_END_THREAD
                EVT_SET(AF_FLO_BeanstalkGrowing, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, -350, 0, 400, 0, 0)
        EVT_SETF(MV_BeanstalkGrowthProgress, LVarF)
        EVT_MULF(MV_BeanstalkGrowthProgress, EVT_FLOAT(1.6))
        EVT_SETF(LVar2, LVar0)
        EVT_MULF(LVar2, EVT_FLOAT(1.0))
        EVT_SETF(LVar0, LVar2)
        EVT_EXEC(N(EVS_SetExteriorVineGrowth))
        EVT_SETF(LVar2, LVar0)
        EVT_MULF(LVar2, EVT_FLOAT(1.0))
        EVT_SETF(LVar0, LVar2)
        EVT_EXEC(N(EVS_SetInteriorVineGrowth))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_SET(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
    EVT_CALL(GotoMap, EVT_PTR("flo_00"), flo_00_ENTRY_7)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBeanstalk) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Exit_Beanstalk)), TRIGGER_FLOOR_TOUCH, COLLIDER_o117, 1, 0)
    EVT_RETURN
    EVT_END
};
*/
