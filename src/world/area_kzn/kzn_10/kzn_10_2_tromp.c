#include "kzn_10.h"
#include "effects.h"
#include "sprite/player.h"

#define UNK_FUNC_50_LVar1 -469.0
#define UNK_FUNC_50_LVar2 46.0

#include "../common/SpinyTromp.inc.c"

EvtScript N(EVS_SpinyTromp_ManageCamera) = {
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LOOP(0)
        EVT_IF_EQ(AF_KZN_TrompHitPlayer, FALSE)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, MV_TrompPosX)
            EVT_DIV(LVar0, 2)
        EVT_ELSE
            EVT_SET(LVar0, MV_TrompPosX)
        EVT_END_IF
        EVT_SET(LVar3, LVar0)
        EVT_SWITCH(LVar3)
            EVT_CASE_LT(-350)
                EVT_SET(LVar6, 500)
            EVT_CASE_LT(-200)
                EVT_SET(LVar6, LVar3)
                EVT_ADD(LVar6, 850)
            EVT_CASE_LT(150)
                EVT_SET(LVar6, 650)
            EVT_CASE_LT(300)
                EVT_SET(LVar0, LVar3)
                EVT_SET(LVar6, 800)
                EVT_SUB(LVar6, LVar0)
            EVT_CASE_DEFAULT
                EVT_SET(LVar6, 500)
        EVT_END_SWITCH
        EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar6)
        EVT_SET(LVar0, LVar3)
        EVT_SET(LVar2, 0)
        EVT_CALL(N(UnkFunc46))
        EVT_SUB(LVar2, 55)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar2, 0)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241224_C7F3A4) = {
    EVT_SET_GROUP(EVT_GROUP_0A)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_DUST, 1, -430, 100, 0, 30)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 100)
    EVT_PLAY_EFFECT(EFFECT_DUST, 1, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(20)
    EVT_SUB(LVar0, 100)
    EVT_ADD(LVar1, 50)
    EVT_PLAY_EFFECT(EFFECT_DUST, 1, LVar0, LVar1, LVar2, 40)
    EVT_WAIT(20)
    EVT_IF_EQ(AF_KZN_Tromp1_ShakingDone, FALSE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LOOP(8)
        EVT_PLAY_EFFECT(EFFECT_DUST, 1, 400, -80, 0, 40)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinyTromp_ShakeCam) = {
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSpinyTromp) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
    EVT_CALL(EnableModel, MODEL_me, FALSE)
    EVT_CALL(TranslateGroup, MODEL_goron, 0, 0, 0)
    EVT_CALL(RotateGroup, MODEL_goron, 0, 0, 0, 1)
    EVT_SET(AF_KZN_Tromp1_ShakingDone, FALSE)
    EVT_SET(AF_KZN_TrompHitPlayer, FALSE)
    EVT_SET(AF_KZN_TrompRollingDone, FALSE)
    EVT_CALL(GetEntryID, LVar3)
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar3, kzn_10_ENTRY_0)
            EVT_IF_GE(LVar0, -400)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_ELSE
            EVT_IF_LE(LVar0, -400)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(InterruptUsePartner)
    EVT_CALL(SetGroupVisibility, MODEL_goron, MODEL_GROUP_VISIBLE)
    EVT_CALL(EnableModel, MODEL_me, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, UNK_FUNC_50_LVar1)
    EVT_SET(LVar2, 0)
    EVT_CALL(N(UnkFunc46))
    EVT_CALL(MakeLerp, 200, LVar2, 20, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_SET(MV_TrompPosX, UNK_FUNC_50_LVar1)
    EVT_CALL(TranslateGroup, MODEL_goron, UNK_FUNC_50_LVar1, LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_me, UNK_FUNC_50_LVar1, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SUB(LVar2, 55)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, UNK_FUNC_50_LVar1, LVar2, 0)
    EVT_EXEC(N(D_80241224_C7F3A4))
    EVT_THREAD
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(PARTNER_PARAKARRY)
            EVT_CASE_EQ(PARTNER_BOW)
            EVT_CASE_DEFAULT
                EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
                EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.5))
                EVT_CALL(PlayerJump1, LVar1, LVar2, LVar3, 8)
                EVT_CALL(InterpPlayerYaw, 270, 0)
                EVT_IF_NE(LVar0, PARTNER_LAKILESTER)
                    EVT_WAIT(3)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Flail)
                    EVT_WAIT(10)
                    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
                EVT_END_IF
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_TROMP_DROP, SOUND_SPACE_DEFAULT, -465, 0, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(2.5))
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.2))
    EVT_WAIT(15)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC_GET_TID(N(EVS_SpinyTromp_ManageCamera), LVarA)
    EVT_EXEC_GET_TID(N(EVS_SpinyTromp_ShakeCam), MV_ScreenShakeTID)
    EVT_CALL(PlaySoundAt, SOUND_LOOP_TROMP_ROLL, SOUND_SPACE_DEFAULT, -465, 0, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_CALL(MakeLerp, UNK_FUNC_50_LVar1, 418, 180, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(UnkFunc46))
        EVT_CALL(N(UnkFunc51), LVar0, LVar1, LVar2)
        EVT_SET(MV_TrompPosX, LVar0)
        EVT_CALL(TranslateGroup, MODEL_goron, LVar0, LVar2, 0)
        EVT_CALL(TranslateModel, MODEL_me, LVar0, LVar2, 0)
        EVT_SET(LVar8, LVar0)
        EVT_SET(LVar9, LVar2)
        EVT_CALL(RotateGroup, MODEL_goron, LVar3, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_me, LVar3, 0, 0, 1)
        EVT_CALL(N(UnkFunc49))
        EVT_CALL(TranslateModel, MODEL_me, LVar5, LVar6, 0)
        EVT_CALL(N(UnkFunc50))
        EVT_WAIT(1)
        EVT_CALL(N(SpinyTromp_CheckDist))
        EVT_IF_LT(LVar4, 80)
            EVT_IF_EQ(AF_KZN_TrompHitPlayer, FALSE)
                EVT_CALL(N(SpinyTromp_GetActingPartner))
                EVT_IF_NE(LVar0, PARTNER_BOW)
                    EVT_EXEC(N(D_80240D10_C7EE90))
                    EVT_IF_EQ(AF_KZN_TrompHitPlayer, FALSE)
                        EVT_KILL_THREAD(LVarA)
                        EVT_SET(AF_KZN_TrompHitPlayer, TRUE)
                    EVT_END_IF
                    EVT_THREAD
                        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.0))
                        EVT_WAIT(45)
                        EVT_SET(AF_KZN_TrompRollingDone, TRUE)
                    EVT_END_THREAD
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(AF_KZN_Tromp1_ShakingDone, TRUE)
    EVT_KILL_THREAD(MV_ScreenShakeTID)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 35, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(StopSound, SOUND_LOOP_TROMP_ROLL)
    EVT_CALL(PlaySoundAt, SOUND_TROMP_CRASH, SOUND_SPACE_DEFAULT, 415, -240, 0)
    EVT_CALL(EnableModel, MODEL_me, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, 418)
        EVT_SET(LVar2, 0)
        EVT_CALL(N(UnkFunc46))
        EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar2, 0, 1, 20, 3, 8)
    EVT_END_THREAD
    EVT_SET(LVar0, LVar8)
    EVT_SET(LVar1, LVar9)
    EVT_SET(LVar2, LVar8)
    EVT_SET(LVar3, LVar9)
    EVT_SET(LVar4, LVar8)
    EVT_SET(LVar5, LVar9)
    EVT_SET(LVar6, LVar8)
    EVT_SET(LVar7, LVar9)
    EVT_LOOP(90)
        EVT_CALL(TranslateModel, MODEL_o70, LVar6, LVar1, 0)
        EVT_CALL(TranslateModel, MODEL_o72, LVar6, LVar3, 0)
        EVT_CALL(TranslateModel, MODEL_o73, LVar4, LVar5, 0)
        EVT_CALL(TranslateModel, MODEL_o74, LVar4, LVar7, 0)
        EVT_CALL(TranslateModel, MODEL_2_1, LVar2, LVar3, 0)
        EVT_CALL(TranslateModel, MODEL_2_2, LVar2, LVar1, 0)
        EVT_CALL(TranslateModel, MODEL_2_3, LVar0, LVar7, 0)
        EVT_CALL(TranslateModel, MODEL_2_4, LVar0, LVar5, 0)
        EVT_CALL(TranslateModel, MODEL_3_1, LVar0, LVar5, 0)
        EVT_CALL(TranslateModel, MODEL_3_2, LVar0, LVar7, 0)
        EVT_CALL(TranslateModel, MODEL_3_3, LVar2, LVar1, 0)
        EVT_CALL(TranslateModel, MODEL_3_4, LVar2, LVar3, 0)
        EVT_CALL(TranslateModel, MODEL_4_1, LVar4, LVar7, 0)
        EVT_CALL(TranslateModel, MODEL_4_2, LVar4, LVar5, 0)
        EVT_CALL(TranslateModel, MODEL_4_3, LVar6, LVar3, 0)
        EVT_CALL(TranslateModel, MODEL_4_4, LVar6, LVar1, 0)
        EVT_ADD(LVar0, 2)
        EVT_ADD(LVar1, -7)
        EVT_ADD(LVar2, -5)
        EVT_ADD(LVar3, 7)
        EVT_ADD(LVar4, 9)
        EVT_ADD(LVar5, -3)
        EVT_ADD(LVar6, -6)
        EVT_ADD(LVar7, 7)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetGroupVisibility, MODEL_goron, MODEL_GROUP_HIDDEN)
    EVT_CALL(EnableModel, MODEL_me, FALSE)
    EVT_WAIT(10)
    EVT_IF_EQ(AF_KZN_TrompHitPlayer, FALSE)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_SET(AF_KZN_TrompRollingDone, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
