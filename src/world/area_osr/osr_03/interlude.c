#include "osr_03.h"
#include "effects.h"

API_CALLABLE(N(SetPlayerAsPeach)) {
    gGameStatusPtr->peachFlags |= PEACH_FLAG_IS_PEACH;
    script->varTable[0] = gPlayerData.curPartner;
    gPlayerData.curPartner = PARTNER_TWINK;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetKammyFlightEmitterPos)) {
    Npc* npc = get_npc_unsafe(NPC_Kammy);

    script->varTable[0] = npc->pos.x + (sin_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 20.0f);
    script->varTable[1] = npc->pos.y + 18.0f;
    script->varTable[2] = npc->pos.z - (cos_deg(npc->yaw + gCameras[CAM_DEFAULT].curYaw + 180.0f) * 20.0f);
    return ApiStatus_DONE2;
}

Vec3f N(KammyFlightPath1)[] = {
    { -700.0,  -370.0, 1600.0 },
    { -750.0,  -450.0, 1550.0 },
    { -700.0,  -530.0, 1550.0 },
    { -630.0,  -550.0, 1550.0 },
};

Vec3f N(KammyFlightPath2)[] = {
    { -630.0,  -550.0, 1550.0 },
    { -430.0,  -520.0, 1525.0 },
    { -350.0,  -430.0, 1500.0 },
    { -100.0,  -100.0, 1000.0 },
    {    0.0,     0.0,  500.0 },
    {    0.0,     0.0,    0.0 },
};

EvtScript N(EVS_PlayKammyFlightFX) = {
    ChildThread
        Set(LVar0, 110)
        Loop(0)
            Call(PlaySoundWithVolume, SOUND_FLIGHT, LVar0)
            Add(LVar0, -2)
            IfLt(LVar0, 10)
                Set(LVar0, 10)
            EndIf
            Wait(4)
        EndLoop
    EndChildThread
    Call(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    Loop(0)
        Call(N(GetKammyFlightEmitterPos))
        Call(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        Set(LVar3, LVar9)
        Set(LVar4, LVarA)
        Set(LVar5, LVarB)
        Sub(LVar3, LVar6)
        Sub(LVar4, LVar7)
        Sub(LVar5, LVar8)
        Set(LVar6, LVar9)
        Set(LVar7, LVarA)
        Set(LVar8, LVarB)
        IfEq(LVar3, 0)
            IfEq(LVar5, 0)
            Else
                PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
            EndIf
        Else
            PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
        EndIf
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_KammyReturnsToCastle) = {
    Wait(30)
    Thread
        Loop(0)
            Call(NpcFacePlayer, NPC_Kammy, 0)
            Wait(1)
        EndLoop
    EndThread
    ExecGetTID(N(EVS_PlayKammyFlightFX), LVar9)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim1A)
    Call(LoadPath, 30, Ref(N(KammyFlightPath1)), ARRAY_COUNT(N(KammyFlightPath1)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(LoadPath, 150, Ref(N(KammyFlightPath2)), ARRAY_COUNT(N(KammyFlightPath2)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Kammy, LVar1, LVar2, LVar3)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    KillThread(LVar9)
    Return
    End
};

EvtScript N(EVS_Scene_BeginInterlude) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(EnableGroup, MODEL_hiru, false)
    Call(EnableGroup, MODEL_niwa, false)
    Call(EnableGroup, MODEL_jimidori, false)
    Call(EnableGroup, MODEL_kumo, false)
    Call(EnableGroup, MODEL_ki1, false)
    Call(EnableGroup, MODEL_jimen, false)
    Call(EnableGroup, MODEL_kemuri, false)
    Call(EnableGroup, MODEL_obj, false)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 80, 16, 4096)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, -1, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, -1, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(-13.0), Float(18.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_CastleLiftDist, 0)
    Exec(N(EVS_AnimateSwingingChains))
    Exec(N(EVS_AnimateSpinningRing))
    Wait(30)
    IfLt(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        ExecWait(N(EVS_KammyReturnsToCastle))
    EndIf
    Wait(80)
    Call(N(SetPlayerAsPeach))
    Set(GB_KKJ_LastPartner, LVar0)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
            Call(GotoMap, Ref("kkj_15"), kkj_15_ENTRY_2)
        CaseLt(STORY_CH0_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_3)
        CaseLt(STORY_CH1_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_4)
        CaseLt(STORY_CH2_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_5)
        CaseLt(STORY_CH3_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_6)
        CaseLt(STORY_CH4_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_7)
        CaseLt(STORY_CH5_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_8)
        CaseLt(STORY_CH6_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_14"), kkj_14_ENTRY_9)
        CaseLt(STORY_CH7_BEGAN_PEACH_MISSION)
            Call(GotoMap, Ref("kkj_26"), kkj_26_ENTRY_1)
    EndSwitch
    Wait(100)
    Return
    End
};
