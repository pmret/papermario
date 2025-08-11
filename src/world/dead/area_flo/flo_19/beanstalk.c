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
    f32 temp = evt_get_variable(nullptr, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[9], script->varTable[11]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    gPlayerStatus.pos.x = (dist * temp) + 0.0f;
    gPlayerStatus.pos.y = evt_get_variable(nullptr, script->varTable[10]) + evt_get_variable(nullptr, script->varTable[3]);
    temp = cos_deg(clamped);
    gPlayerStatus.pos.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PartnerRideBeanstalk)) {
    Npc* npc = get_npc_by_index(NPC_Dummy_Partner);
    f32 temp = evt_get_variable(nullptr, script->varTable[2]);
    f32 dist = dist2D(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 angle = atan2(0.0f, 0.0f, script->varTable[12], script->varTable[14]);
    f32 clamped = clamp_angle(angle - temp);

    temp = sin_deg(clamped);
    npc->pos.x = (dist * temp) + 0.0f;
    npc->pos.y = evt_get_variable(nullptr, script->varTable[13]) + evt_get_variable(nullptr, script->varTable[3]);
    temp = cos_deg(clamped);
    npc->pos.z = 0.0f - (dist * temp);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetScreenFadeAmount)) {
    set_screen_overlay_params_back(OVERLAY_VIEWPORT_COLOR, script->varTable[0]);
    return ApiStatus_DONE2;
}

#include "common/CosInterpMinMax.inc.c"

// all data in this file is truncated in other versions
#if VERSION_JP
EvtScript N(EVS_FadeOutToBlack) = {
    Set(LVar0, 0)
    Label(10)
        Call(N(SetScreenFadeAmount))
        Add(LVar0, 25)
        Wait(1)
        IfLt(LVar0, 255)
            Goto(10)
        EndIf
    Set(LVar0, 255)
    Call(N(SetScreenFadeAmount))
    Wait(1)
    Return
    End
};

EvtScript N(EVS_FadeInFromBlack) = {
    Set(LVar0, 255)
    Label(10)
        Call(N(SetScreenFadeAmount))
        Sub(LVar0, 25)
        Wait(1)
        IfGt(LVar0, 0)
            Goto(10)
        EndIf
    Set(LVar0, 0)
    Call(N(SetScreenFadeAmount))
    Wait(1)
    Return
    End
};

EvtScript N(EVS_SetExteriorVineGrowth) = {
    Call(TranslateGroup, MODEL_g83, 0, LVar0, 0)
    Call(TranslateGroup, MODEL_ha, 0, LVar0, 0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(-12.0))
    Call(RotateGroup, MODEL_g83, LVar1, 0, 1, 0)
    Call(RotateGroup, MODEL_ha, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetInteriorVineGrowth) = {
    Call(TranslateGroup, MODEL_g84, 0, LVar0, 0)
    SetF(LVar1, LVar0)
    MulF(LVar1, Float(-12.0))
    Call(RotateGroup, MODEL_g84, LVar1, 0, 1, 0)
    Return
    End
};

EvtScript N(EVS_Enter_Beanstalk) = {
    Call(DisablePlayerInput, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    Call(SetCamType, CAM_DEFAULT, 1, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(11.0))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(EnableGroup, MODEL_g16, false)
    Call(EnableGroup, MODEL_g2, false)
    Call(EnableGroup, MODEL_g3, false)
    Call(EnableGroup, MODEL_g19, false)
    Call(EnableGroup, MODEL_g93, false)
    Call(EnableGroup, MODEL_g15, false)
    Call(EnableGroup, MODEL_g25, false)
    Set(LVar9, Float(45.0))
    Set(LVarA, Float(28.0))
    Set(LVarB, Float(5.0))
    Set(LVarC, Float(60.0))
    Set(LVarD, Float(28.0))
    Set(LVarE, Float(10.0))
    Thread
        Wait(5)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Switch(AF_FLO_BeanstalkFacingRight)
            CaseEq(0)
                Call(InterpPlayerYaw, 90, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
            CaseEq(1)
                Call(InterpPlayerYaw, 270, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndSwitch
    EndThread
    Call(TranslateModel, MODEL_o142, Float(1.313), Float(3.0), Float(-0.56640625))
    Call(UpdateColliderTransform, COLLIDER_o117)
    Thread
        Set(AF_FLO_BeanstalkFadedOut, false)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Wait(200)
        ExecWait(N(EVS_FadeOutToBlack))
        Set(AF_FLO_BeanstalkFadedOut, true)
        Wait(10)
        Call(EnableGroup, MODEL_g16, true)
        Call(EnableGroup, MODEL_g2, true)
        Call(EnableGroup, MODEL_g3, true)
        Call(EnableGroup, MODEL_g19, true)
        Call(EnableGroup, MODEL_g93, true)
        Call(EnableGroup, MODEL_g15, true)
        Call(EnableGroup, MODEL_g25, true)
        Call(SetCamDistance, CAM_DEFAULT, 450)
        Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-6.0))
        Call(SetCamPosA, CAM_DEFAULT, 0, 0)
        Call(SetCamPosB, CAM_DEFAULT, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        ExecWait(N(EVS_FadeInFromBlack))
        Wait(20)
        Set(AF_FLO_BeanstalkFadedOut, false)
    EndThread
    Set(LVarF, 0)
    Loop(344)
        Add(LVarF, 1)
        Call(N(CosInterpMinMax), LVarF, LVar0, -210, 0, 344, 0, 0)
        SetF(LVar1, LVar0)
        MulF(LVar1, Float(-3.0))
        Call(TranslateModel, MODEL_o142, Float(1.313), LVar0, Float(-0.56640625))
        Call(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
        Call(UpdateColliderTransform, COLLIDER_o117)
        SetF(LVar2, LVar0)
        MulF(LVar2, Float(-3.0))
        SetF(LVar3, LVar0)
        Call(N(PlayerRideBeanstalk))
        Call(N(PartnerRideBeanstalk))
        Label(11)
            Wait(1)
            IfEq(AF_FLO_BeanstalkFadedOut, true)
                Goto(11)
            EndIf
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnablePartnerAI)
    Call(ClearPartnerMoveHistory, NPC_PARTNER)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, 100, 0, 60, 20)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(InterpPlayerYaw, 90, 0)
    Wait(5)
    Set(AF_FLO_RidingBeanstalk, false)
    Call(StopSound, SOUND_FLO_RIDE_BEANSTALK_UP_LOOP)
    ExecWait(N(EVS_SetupMusic))
    Call(ResetCam, CAM_DEFAULT, Float(1.0))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_Exit_Beanstalk) = {
    IfEq(AF_FLO_RidingBeanstalk, false)
        Call(DisablePlayerInput, true)
        Call(InterruptUsePartner)
        Wait(15)
        Call(DisablePartnerAI, 0)
        Set(AF_FLO_RidingBeanstalk, true)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o108, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o122, COLLIDER_FLAGS_UPPER_MASK)
        Set(LVar9, Float(45.0))
        Set(LVarA, Float(28.0))
        Set(LVarB, Float(5.0))
        Set(LVarC, Float(60.0))
        Set(LVarD, Float(28.0))
        Set(LVarE, Float(10.0))
        Call(PlayerMoveTo, LVar9, LVarB, 8)
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(NpcJump0, NPC_PARTNER, LVarC, LVarD, LVarE, 5)
        Call(PlaySound, SOUND_FLO_RIDE_BEANSTALK_DOWN_LOOP)
        Call(SetMusic, 0, SONG_MAGIC_BEANSTALK, BGM_VARIATION_1, VOL_LEVEL_FULL)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(SetPlayerAnimation, ANIM_Mario1_Walk)
        Call(N(GetPlayerAngles), LVar3, LVar4)
        Switch(LVar4)
            CaseLt(90)
                Set(AF_FLO_BeanstalkFacingRight, false)
                Call(InterpPlayerYaw, 90, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
            CaseGe(270)
                Set(AF_FLO_BeanstalkFacingRight, true)
                Call(InterpPlayerYaw, 270, 0)
                Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndSwitch
        Call(TranslateModel, MODEL_o142, Float(1.313), Float(3.0), Float(-0.56640625))
        Call(UpdateColliderTransform, COLLIDER_o117)
        Set(MV_BeanstalkSceneSync, false)
        Thread
            Set(AF_FLO_BeanstalkFadedOut, false)
            Wait(120)
            Set(AF_FLO_BeanstalkFadedOut, true)
            Wait(20)
            ExecWait(N(EVS_FadeOutToBlack))
            Wait(10)
            Call(EnableGroup, MODEL_g16, false)
            Call(EnableGroup, MODEL_g2, false)
            Call(EnableGroup, MODEL_g3, false)
            Call(EnableGroup, MODEL_g19, false)
            Call(EnableGroup, MODEL_g93, false)
            Call(EnableGroup, MODEL_g15, false)
            Call(EnableGroup, MODEL_g25, false)
            Call(SetCamType, CAM_DEFAULT, 1, false)
            Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
            Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
            Call(SetCamDistance, CAM_DEFAULT, 350)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(7.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Set(AF_FLO_BeanstalkFadedOut, false)
            ExecWait(N(EVS_FadeInFromBlack))
        EndThread
        Thread
            Set(LVarF, 0)
            Loop(344)
                Add(LVarF, 1)
                Call(N(CosInterpMinMax), LVarF, LVar0, 0, -210, 344, 0, 0)
                SetF(LVar1, LVar0)
                MulF(LVar1, Float(-3.0))
                Call(TranslateModel, MODEL_o142, Float(1.313), LVar0, Float(-0.56640625))
                Call(RotateModel, MODEL_o142, LVar1, 0, 1, 0)
                Call(UpdateColliderTransform, COLLIDER_o117)
                SetF(LVar2, LVar0)
                MulF(LVar2, Float(-3.0))
                SetF(LVar3, LVar0)
                Call(N(PlayerRideBeanstalk))
                Call(N(PartnerRideBeanstalk))
                IfEq(LVarF, 300)
                    Set(MV_BeanstalkSceneSync, true)
                EndIf
                Label(11)
                    Wait(1)
                    IfEq(AF_FLO_BeanstalkFadedOut, true)
                        Goto(11)
                    EndIf
            EndLoop
        EndThread
        Label(10)
            IfEq(MV_BeanstalkSceneSync, false)
                Wait(1)
                Goto(10)
            EndIf
        Call(GotoMap, Ref("flo_00"), flo_00_ENTRY_8)
        Wait(100)
    EndIf
    Return
    End
};

EvtScript N(EVS_Scene_BeanstalkGrowing) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(EnableModel, MODEL_o142, false)
    Call(EnableGroup, MODEL_g16, false)
    Call(EnableGroup, MODEL_g2, false)
    Call(EnableGroup, MODEL_g3, false)
    Call(EnableGroup, MODEL_g19, false)
    Call(EnableGroup, MODEL_g93, false)
    Call(EnableGroup, MODEL_g15, false)
    Call(EnableGroup, MODEL_g25, false)
    Call(SetCamType, CAM_DEFAULT, 1, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 800)
    Call(SetCamPitch, CAM_DEFAULT, Float(-20.0), Float(8.5))
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(LVarF, 100)
    Set(MV_BeanstalkGrowthProgress, LVarF)
    Set(AF_FLO_BeanstalkGrowing, false)
    Loop(400)
        IfEq(AF_FLO_BeanstalkGrowing, false)
            IfGt(MV_BeanstalkGrowthProgress, 400)
                Call(EnableGroup, MODEL_tuta, false)
                Call(EnableGroup, MODEL_ha, false)
                Call(EnableGroup, MODEL_g16, true)
                Call(EnableGroup, MODEL_g2, true)
                Call(EnableGroup, MODEL_g3, true)
                Call(EnableGroup, MODEL_g19, true)
                Call(EnableGroup, MODEL_g93, true)
                Call(EnableGroup, MODEL_g15, true)
                Call(EnableGroup, MODEL_g25, true)
                Call(SetCamDistance, CAM_DEFAULT, 1000)
                Call(SetCamPitch, CAM_DEFAULT, Float(45.0), Float(-3.0))
                Call(SetCamPosA, CAM_DEFAULT, 0, 0)
                Call(SetCamPosB, CAM_DEFAULT, 0, 0)
                Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
                Call(PanToTarget, CAM_DEFAULT, 0, true)
                Set(LVarF, 150)
                Thread
                    Wait(5)
                    Call(EnableGroup, MODEL_tuta, true)
                    Call(EnableGroup, MODEL_ha, true)
                    Call(EnableModel, MODEL_o142, false)
                    Wait(48)
                    PlayEffect(EFFECT_CLOUD_PUFF, 0, 22, 15, 0)
                    Wait(10)
                    PlayEffect(EFFECT_CLOUD_PUFF, 0, 22, 15, 0)
                EndThread
                Set(AF_FLO_BeanstalkGrowing, true)
            EndIf
        EndIf
        Add(LVarF, 1)
        Call(N(CosInterpMinMax), LVarF, LVar0, -350, 0, 400, 0, 0)
        SetF(MV_BeanstalkGrowthProgress, LVarF)
        MulF(MV_BeanstalkGrowthProgress, Float(1.6))
        SetF(LVar2, LVar0)
        MulF(LVar2, Float(1.0))
        SetF(LVar0, LVar2)
        Exec(N(EVS_SetExteriorVineGrowth))
        SetF(LVar2, LVar0)
        MulF(LVar2, Float(1.0))
        SetF(LVar0, LVar2)
        Exec(N(EVS_SetInteriorVineGrowth))
        Wait(1)
    EndLoop
    Wait(15)
    Set(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
    Call(GotoMap, Ref("flo_00"), flo_00_ENTRY_7)
    Return
    End
};

EvtScript N(EVS_SetupBeanstalk) = {
    BindTrigger(Ref(N(EVS_Exit_Beanstalk)), TRIGGER_FLOOR_TOUCH, COLLIDER_o117, 1, 0)
    Return
    End
};
#endif
