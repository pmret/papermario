#include "end_01.h"
#include "effects.h"

EvtScript N(D_80246290_E0B5F0) = {
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

EvtScript N(D_80246310_E0B670) = {
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

EvtScript N(D_802463A4_E0B704) = {
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

EvtScript N(D_802464F8_E0B858) = {
    EVT_CALL(GetNpcPos, NPC_10, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_SUB(LVar2, 2)
    EVT_CALL(GetNpcPos, NPC_11, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 30)
    EVT_SUB(LVar5, 2)
    EVT_LOOP(0)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(15)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246628_E0B988) = {
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_18, -2185, 130, -30)
        EVT_CALL(NpcFlyTo, NPC_18, -2185, 50, -30, 10, 0, EASING_LINEAR)
        EVT_CALL(NpcFlyTo, NPC_18, -2045, 50, -30, 70, 0, EASING_LINEAR)
        EVT_CALL(SetNpcAnimation, NPC_18, ANIM_Sun_TalkPleased)
        EVT_CALL(NpcFlyTo, NPC_18, -1645, 50, -30, 200, 0, EASING_LINEAR)
        EVT_CALL(SetNpcPos, NPC_18, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_19, -2185, 130, -30)
        EVT_CALL(NpcFlyTo, NPC_19, -2185, 50, -30, 10, 0, EASING_LINEAR)
        EVT_CALL(NpcFlyTo, NPC_19, -2045, 50, -30, 70, 0, EASING_LINEAR)
        EVT_CALL(SetNpcAnimation, NPC_19, ANIM_Sun_FireTalkPleased)
        EVT_CALL(NpcFlyTo, NPC_19, -1645, 50, -30, 200, 0, EASING_LINEAR)
        EVT_CALL(SetNpcPos, NPC_19, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802467E0_E0BB40) = {
    EVT_CALL(GetNpcPos, NPC_1A, LVar0, LVar1, LVar2)
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
        EVT_CALL(SetNpcRotation, NPC_1A, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_1B, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_1A, LVar0, LVar1, LVar2)
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
        EVT_CALL(SetNpcRotation, NPC_1A, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_1B, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80246A60) = {
    EVT_EXEC_GET_TID(N(D_802464F8_E0B858), LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2350)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(D_80246290_E0B5F0), LVarA)
    EVT_EXEC(N(D_802467E0_E0BB40))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2085)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_12, ANIM_ParadeWizard_Merle_MerleRelease)
    EVT_CALL(SetNpcAnimation, NPC_13, ANIM_ParadeWizard_Merle_MerleeRelease)
    EVT_CALL(SetNpcAnimation, NPC_14, ANIM_ParadeWizard_Merle_MerlonRelease)
    EVT_CALL(SetNpcAnimation, NPC_15, ANIM_ParadeWizard_Merle_MerluvleeRelease)
    EVT_CALL(SetNpcAnimation, NPC_16, ANIM_ParadeWizard_Merle_MerlowRelease)
    EVT_CALL(SetNpcAnimation, NPC_17, ANIM_ParadeWizard_Merle_MerlarRelease)
    EVT_CALL(GetNpcPos, NPC_14, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_ENERGY_ORB_WAVE, 6, LVar0, LVar1, LVar2, 1, 20, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_EXEC(N(D_80246628_E0B988))
    EVT_EXEC_GET_TID(N(D_80246310_E0B670), LVarB)
    EVT_EXEC_GET_TID(N(D_802463A4_E0B704), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_5)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -1850)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
