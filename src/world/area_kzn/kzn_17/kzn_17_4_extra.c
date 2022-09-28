#include "kzn_17.h"
#include "effects.h"

extern API_CALLABLE(N(D_80244AC8_C8A578));
extern API_CALLABLE(N(D_80244B1C_C8A5CC));

#define UNK_FUNC_50_LVar1 -583.0
#define UNK_FUNC_50_LVar2 165.0

#include "world/common/atomic/kzn_SpinyTromp.inc.c"

EvtScript N(D_80245AE0_C8B590) = {
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar3, LVar4, LVar5)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(10.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_LOOP(0)
        EVT_IF_EQ(AF_KZN_06, FALSE)
            EVT_IF_LT(MV_Unk_00, 550)
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_IF_LT(MV_Unk_00, LVar0)
                    EVT_ADD(LVar0, MV_Unk_00)
                    EVT_DIV(LVar0, 2)
                EVT_ELSE
                    EVT_SET(LVar0, MV_Unk_00)
                EVT_END_IF
                EVT_ADD(LVar1, 55)
                EVT_SET(LVar2, LVar1)
                EVT_CALL(N(UnkFunc46))
                EVT_SUB(LVar2, 55)
                EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar2, 30)
                EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80245CA8_C8B758) = {
    EVT_LOOP(0)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSpinyTromp) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_IF_GE(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
        EVT_CALL(SetGroupEnabled, MODEL_goron, 0)
        EVT_CALL(EnableModel, MODEL_me, FALSE)
        EVT_CALL(EnableModel, MODEL_mae, FALSE)
        EVT_CALL(ModifyColliderFlags, 0, COLLIDER_gogo, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableModel, MODEL_ato, FALSE)
    EVT_SET(AF_KZN_05, FALSE)
    EVT_SET(AF_KZN_06, FALSE)
    EVT_SET(AF_KZN_03, FALSE)
    EVT_SET(AF_KZN_02, FALSE)
    EVT_SET(AF_KZN_07, FALSE)
    EVT_SET(LVar0, -583)
    EVT_SET(LVar2, 165)
    EVT_CALL(TranslateGroup, MODEL_goron, LVar0, LVar2, 30)
    EVT_CALL(TranslateModel, MODEL_me, LVar0, LVar2, 30)
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_IF_EQ(GF_KZN17_Hammer3BlockG, FALSE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(D_80245AE0_C8B590), LVarA)
    EVT_EXEC(N(D_80244AC8_C8A578))
    EVT_EXEC_GET_TID(N(D_80245CA8_C8B758), MV_Unk_0A)
    EVT_CALL(PlaySound, SOUND_8000001B)
    EVT_SET(LVar3, 0)
    EVT_CALL(MakeLerp, -583, 750, 270, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(UnkFunc46))
        EVT_CALL(N(UnkFunc51), LVar0, LVar1, LVar2)
        EVT_SET(MV_Unk_00, LVar0)
        EVT_ADD(MV_Unk_00, 20)
        EVT_CALL(TranslateGroup, MODEL_goron, LVar0, LVar2, 30)
        EVT_CALL(TranslateModel, MODEL_me, LVar0, LVar2, 30)
        EVT_CALL(RotateGroup, MODEL_goron, LVar3, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_me, LVar3, 0, 0, 1)
        EVT_CALL(N(UnkFunc49))
        EVT_CALL(TranslateModel, MODEL_me, LVar5, LVar6, 30)
        EVT_CALL(N(UnkFunc50))
        EVT_IF_EQ(AF_KZN_07, FALSE)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar3, LVar1, LVar2)
                EVT_SUB(LVar3, 20)
                EVT_IF_LT(LVar3, LVar0)
                    EVT_CALL(DisablePlayerInput, TRUE)
                    EVT_SET(AF_KZN_07, TRUE)
                    EVT_LABEL(12)
                    EVT_WAIT(1)
                    EVT_IF_NE(AF_KZN_07, FALSE)
                        EVT_GOTO(12)
                    EVT_END_IF
                    EVT_CALL(DisablePlayerInput, FALSE)
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
        EVT_IF_EQ(AF_KZN_05, FALSE)
            EVT_IF_GT(LVar0, 430)
                EVT_EXEC(N(D_80244B1C_C8A5CC))
                EVT_SET(AF_KZN_05, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(AF_KZN_06, FALSE)
            EVT_IF_GT(LVar0, 630)
                EVT_KILL_THREAD(MV_Unk_0A)
                EVT_CALL(ModifyColliderFlags, 0, COLLIDER_gogo, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(PlaySoundAtCollider, COLLIDER_gogo, SOUND_1E4, 0)
                EVT_CALL(PlayEffect, EFFECT_BOMBETTE_BREAKING, 2, 32, 32, 1, 10, 45, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(EnableModel, MODEL_mae, FALSE)
                EVT_CALL(EnableModel, MODEL_ato, TRUE)
                EVT_THREAD
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(3.0))
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.7))
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.5))
                EVT_END_THREAD
                EVT_SET(AF_KZN_06, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_CALL(N(UnkFunc47))
        EVT_IF_LT(LVar4, 80)
            EVT_IF_EQ(AF_KZN_03, FALSE)
                EVT_CALL(N(SpinyTromp_GetActingPartner))
                EVT_IF_NE(LVar0, PARTNER_BOW)
                    EVT_SET(AF_KZN_03, TRUE)
                    EVT_EXEC(N(D_80240D10_C7EE90))
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(GB_StoryProgress, STORY_CH5_HIDDEN_PASSAGE_OPEN)
    EVT_WAIT(50)
    EVT_CALL(StopSound, SOUND_8000001B)
    EVT_CALL(SetGroupEnabled, MODEL_goron, 0)
    EVT_CALL(EnableModel, MODEL_me, FALSE)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_SET(AF_KZN_07, FALSE)
    EVT_SET(AF_KZN_02, TRUE)
    EVT_RETURN
    EVT_END
};
