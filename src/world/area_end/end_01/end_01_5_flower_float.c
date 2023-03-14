#include "end_01.h"
#include "effects.h"

EvtScript N(EVS_TexPan_FlowerFloat_Base) = {
    EVT_CALL(EnableTexPanning, MODEL_flo1, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x2000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FlowerFloat_WisterwoodBody) = {
    EVT_CALL(EnableTexPanning, MODEL_flo2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_flo4, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x400)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_AUX, LVar0, LVar0)
        EVT_WAIT(4)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_FlowerFloat_WisterwoodBlink) = {
    EVT_CALL(EnableTexPanning, MODEL_flo3, TRUE)
    EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0x8000, 0)
    EVT_LOOP(0)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 10)
        EVT_WAIT(LVar0)
        EVT_CALL(RandInt, 1, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_LOOP(LVar0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0, 0)
            EVT_CALL(RandInt, 5, LVar1)
            EVT_ADD(LVar1, 2)
            EVT_WAIT(LVar1)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, 0x8000, 0)
            EVT_CALL(RandInt, 5, LVar1)
            EVT_ADD(LVar1, 2)
            EVT_WAIT(LVar1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Amayze_Dayzees) = {
    EVT_CALL(GetNpcPos, NPC_AmayzeDayzee1, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_SUB(LVar2, 2)
    EVT_CALL(GetNpcPos, NPC_AmayzeDayzee2, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 30)
    EVT_SUB(LVar5, 2)
    EVT_LOOP(0)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30)
        EVT_WAIT(15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Sun) = {
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_SunSad, -2185, 130, -30)
        EVT_CALL(NpcFlyTo, NPC_SunSad, -2185, 50, -30, 10 * DT, 0, EASING_LINEAR)
        EVT_CALL(NpcFlyTo, NPC_SunSad, -2045, 50, -30, 70 * DT, 0, EASING_LINEAR)
        EVT_CALL(SetNpcAnimation, NPC_SunSad, ANIM_Sun_TalkPleased)
        EVT_CALL(NpcFlyTo, NPC_SunSad, -1645, 50, -30, 200 * DT, 0, EASING_LINEAR)
        EVT_CALL(SetNpcPos, NPC_SunSad, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_SunHappy, -2185, 130, -30)
        EVT_CALL(NpcFlyTo, NPC_SunHappy, -2185, 50, -30, 10 * DT, 0, EASING_LINEAR)
        EVT_CALL(NpcFlyTo, NPC_SunHappy, -2045, 50, -30, 70 * DT, 0, EASING_LINEAR)
        EVT_CALL(SetNpcAnimation, NPC_SunHappy, ANIM_Sun_FireTalkPleased)
        EVT_CALL(NpcFlyTo, NPC_SunHappy, -1645, 50, -30, 200 * DT, 0, EASING_LINEAR)
        EVT_CALL(SetNpcPos, NPC_SunHappy, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Bubulbs) = {
    EVT_CALL(GetNpcPos, NPC_Bubulb1, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, -120)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Bubulb1, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Bubulb2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_Bubulb1, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, 100)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, LVar3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Bubulb1, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_Bubulb2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Wizards) = {
    EVT_EXEC_GET_TID(N(EVS_Amayze_Dayzees), LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_WIZARDS + 100)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TexPan_FlowerFloat_Base), LVarA)
    EVT_EXEC(N(EVS_Bubulbs))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_WIZARDS + 365)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Merle, ANIM_ParadeWizard_Merle_MerleRelease)
    EVT_CALL(SetNpcAnimation, NPC_Merlee, ANIM_ParadeWizard_Merle_MerleeRelease)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_ParadeWizard_Merle_MerlonRelease)
    EVT_CALL(SetNpcAnimation, NPC_Merluvlee, ANIM_ParadeWizard_Merle_MerluvleeRelease)
    EVT_CALL(SetNpcAnimation, NPC_Merlow, ANIM_ParadeWizard_Merle_MerlowRelease)
    EVT_CALL(SetNpcAnimation, NPC_Merlar, ANIM_ParadeWizard_Merle_MerlarRelease)
    EVT_CALL(GetNpcPos, NPC_Merlon, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_EXEC(N(EVS_Sun))
    EVT_EXEC_GET_TID(N(EVS_TexPan_FlowerFloat_WisterwoodBody), LVarB)
    EVT_EXEC_GET_TID(N(EVS_TexPan_FlowerFloat_WisterwoodBlink), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_WIZARDS + 600)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
