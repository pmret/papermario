#include "end_01.h"
#include "effects.h"

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo N(ParadeNpcsTable)[];

API_CALLABLE(N(InitCredits));
API_CALLABLE(N(ShowCreditList));

extern EvtScript N(EVS_80246A60);
extern EvtScript N(EVS_ParadePhase_ShyGuyDancing);
extern EvtScript N(EVS_ParadePhase_ShyGuyFormation);
extern EvtScript N(EVS_ParadePhase_Toads1);
extern EvtScript N(EVS_ParadePhase_MarioPeach);
extern EvtScript N(EVS_ParadePhase_Toads2);
extern EvtScript N(EVS_MarioPeachExit);
extern EvtScript N(EVS_ParadePhase_StarSpirits);
extern EvtScript N(EVS_ParadePhase_SkatingPenguins);
extern EvtScript N(D_80245FF0_E0B350);
extern EvtScript N(D_80245C74_E0AFD4);

extern EvtScript N(EVS_InitCredits);
extern EvtScript N(EVS_ShowCredits_Jobs);
extern EvtScript N(EVS_ShowCredits_Names);

API_CALLABLE(N(CreateParadeNPC)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    ParadeNpcInfo* npcInfo = &N(ParadeNpcsTable)[npcID];
    NpcBlueprint bp;
    Npc* npc;

    bp.flags = NPC_FLAG_100;
    bp.initialAnim = npcInfo->initialAnim;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    spr_allocateBtlComponentsOnWorldHeap = TRUE;

    npc = get_npc_by_index(_create_npc_standard(&bp, npcInfo->animList));
    npc->npcID = npcID;
    npc->flags &= ~NPC_FLAG_PARTICLE;
    npc->pos.x = npcInfo->pos.x;
    npc->pos.y = npcInfo->pos.y;
    npc->pos.z = npcInfo->pos.z;
    set_npc_yaw(npc, npcInfo->yaw);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ParadeSpriteHeapMalloc)) {
    Bytecode* args = script->ptrReadPos;
    s32 heapSize = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, (s32) _heap_malloc(&gSpriteHeapPtr, heapSize));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ParadeSpriteHeapFree)) {
    Bytecode* args = script->ptrReadPos;
    s32 pointer = *args++;

    _heap_free(&gSpriteHeapPtr, (void*) evt_get_variable(script, pointer));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateCameraScroll)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->panActive = TRUE;
    camera->movePos.x += PARADE_SCROLL_RATE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddScrollToNpcPos)) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTempPtr[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += PARADE_SCROLL_RATE;

    return ApiStatus_BLOCK;
}

// unused
API_CALLABLE(N(WaitForConfirmInput)) {
    if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_START)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_SetupInitialCamera) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -3135, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -3135, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateScrollPos) = {
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-3135.0), 0, 0)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(N(UpdateCameraScroll))
        EVT_CALL(TranslateGroup, MODEL_bg, LVar1, 0, 0)
        EVT_ADDF(LVar1, EVT_FLOAT(PARADE_SCROLL_RATE))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTexPan_Ground) = {
    EVT_CALL(EnableTexPanning, MODEL_o145, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o146, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o152, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o153, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o154, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o166, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o157, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o159, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o160, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o161, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o162, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o195, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o196, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o197, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o198, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o260, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o201, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o202, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o203, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o204, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o275, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o276, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o277, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o278, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 150)
            EVT_IF_GT(LVar0, 0x20000)
                EVT_ADD(LVar0, -0x20000)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OffsetNpcScroll) = {
    EVT_CALL(N(AddScrollToNpcPos), LVar0)
    EVT_RETURN
    EVT_END
};

AnimID N(ExtraAnims_Eldstar)[] = {
    ANIM_BattleEldstar_Idle,
    -1
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_BattleMamar_Idle,
    -1
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_BattleSkolar_Idle,
    -1
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_BattleMuskular_Idle,
    -1
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_BattleMisstar_Still,
    -1
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_BattleKlevar_Idle,
    -1
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_BattleKalmar_Idle,
    -1
};

AnimID N(ExtraAnims_PyroGuy)[] = {
    ANIM_PyroGuy_Anim03,
    -1
};

AnimID N(ExtraAnims_ShyGuy)[] = {
    ANIM_ShyGuy_Red_Anim04,
    ANIM_ShyGuy_Red_Anim10,
    ANIM_ShyGuy_Red_Anim01,
    -1
};

ParadeNpcInfo N(ParadeNpcsTable)[] = {
    [NPC_00] {
        .initialAnim = ANIM_BattleEldstar_Idle,
        .animList = N(ExtraAnims_Eldstar),
        .pos = { -3135.0f, 210.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_01] {
        .initialAnim = ANIM_BattleMamar_Idle,
        .animList = N(ExtraAnims_Mamar),
        .pos = { -3195.0f, 200.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_02] {
        .initialAnim = ANIM_BattleSkolar_Idle,
        .animList = N(ExtraAnims_Skolar),
        .pos = { -3075.0f, 195.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_03] {
        .initialAnim = ANIM_BattleMuskular_Idle,
        .animList = N(ExtraAnims_Muskular),
        .pos = { -3045.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_04] {
        .initialAnim = ANIM_BattleMisstar_Still,
        .animList = N(ExtraAnims_Misstar),
        .pos = { -3105.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_05] {
        .initialAnim = ANIM_BattleKlevar_Idle,
        .animList = N(ExtraAnims_Klevar),
        .pos = { -3165.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_06] {
        .initialAnim = ANIM_BattleKalmar_Idle,
        .animList = N(ExtraAnims_Kalmar),
        .pos = { -3225.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_07] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, -37.0f },
        .yaw = 270.0f
    },
    [NPC_08] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, 37.0f },
        .yaw = 270.0f
    },
    [NPC_09] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWalk,
        .pos = { -2650.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_0A] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWifeWalk,
        .pos = { -2610.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_0B] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2555.0f, 5.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_0C] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlayUpright,
        .pos = { -2527.0f, 5.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_0D] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2495.0f, 5.0f, 30.0f },
        .yaw = 90.0f
    },
    [NPC_0E] {
        .initialAnim = ANIM_Musician_Poet_Dark_ConductSlow,
        .pos = { -2624.0f, 20.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_0F] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeDivaIdle,
        .pos = { -2529.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_10] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_11] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_12] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleGather,
        .pos = { -2025.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_13] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleeGather,
        .pos = { -1995.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_14] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlonGather,
        .pos = { -2055.0f, 20.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_15] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerluvleeGather,
        .pos = { -2085.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_16] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlowGather,
        .pos = { -2110.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_17] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlarGather,
        .pos = { -1980.0f, 60.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_18] {
        .initialAnim = ANIM_Sun_TalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_19] {
        .initialAnim = ANIM_Sun_FireTalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_1A] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_1B] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_1C] {
        .initialAnim = ANIM_ParadeShyGuy_MarshallWalk,
        .pos = { -1548.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_1D] {
        .initialAnim = ANIM_ParadeShyGuy_GeneralPoint,
        .pos = { -1448.0f, 57.0f, -25.0f },
        .yaw = 270.0f
    },
    [NPC_1E] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1483.0f, 24.0f, -40.0f },
        .yaw = 90.0f
    },
    [NPC_1F] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1413.0f, 24.0f, -40.0f },
        .yaw = 270.0f
    },
    [NPC_20] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1468.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_21] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1458.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_22] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1438.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_23] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1428.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_24] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(ExtraAnims_PyroGuy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_25] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(ExtraAnims_PyroGuy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_26] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_27] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_28] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_29] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_2A] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_2B] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_2C] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_2D] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_2E] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_2F] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_30] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_31] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_32] {
        .initialAnim = ANIM_ShyGuy_Red_Anim04,
        .animList = N(ExtraAnims_ShyGuy),
        .pos = { -788.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_33] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_34] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_35] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_36] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_37] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_38] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_39] {
        .initialAnim = ANIM_ParadeMario_Wave,
        .pos = { -329.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3A] {
        .initialAnim = ANIM_ParadePeach_ShadeWaveSlow,
        .pos = { -289.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3B] {
        .initialAnim = ANIM_ParadeTwink_Idle,
        .pos = { -389.0f, 120.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_3C] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -109.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3D] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -69.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3E] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -29.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_3F] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_40] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_41] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_42] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_43] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
};

EvtScript N(EVS_ManageNpcPool) = {
    EVT_CALL(N(CreateParadeNPC), NPC_00)
    EVT_CALL(N(CreateParadeNPC), NPC_01)
    EVT_CALL(N(CreateParadeNPC), NPC_02)
    EVT_CALL(N(CreateParadeNPC), NPC_03)
    EVT_CALL(N(CreateParadeNPC), NPC_04)
    EVT_CALL(N(CreateParadeNPC), NPC_05)
    EVT_CALL(N(CreateParadeNPC), NPC_06)
    EVT_CALL(N(CreateParadeNPC), NPC_09)
    EVT_CALL(N(CreateParadeNPC), NPC_0A)
    EVT_CALL(N(CreateParadeNPC), NPC_07)
    EVT_CALL(N(CreateParadeNPC), NPC_08)
    EVT_CALL(N(CreateParadeNPC), NPC_0B)
    EVT_CALL(N(CreateParadeNPC), NPC_0C)
    EVT_CALL(N(CreateParadeNPC), NPC_0D)
    EVT_CALL(N(CreateParadeNPC), NPC_0E)
    EVT_CALL(N(CreateParadeNPC), NPC_0F)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x13400, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_10)
    EVT_CALL(N(CreateParadeNPC), NPC_11)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -2350)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_00)
    EVT_CALL(DeleteNpc, NPC_01)
    EVT_CALL(DeleteNpc, NPC_02)
    EVT_CALL(DeleteNpc, NPC_03)
    EVT_CALL(DeleteNpc, NPC_04)
    EVT_CALL(DeleteNpc, NPC_05)
    EVT_CALL(DeleteNpc, NPC_06)
    EVT_CALL(DeleteNpc, NPC_09)
    EVT_CALL(DeleteNpc, NPC_0A)
    EVT_CALL(DeleteNpc, NPC_07)
    EVT_CALL(DeleteNpc, NPC_08)
    EVT_CALL(DeleteNpc, NPC_0B)
    EVT_CALL(DeleteNpc, NPC_0C)
    EVT_CALL(DeleteNpc, NPC_0D)
    EVT_CALL(DeleteNpc, NPC_0E)
    EVT_CALL(DeleteNpc, NPC_0F)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_12)
    EVT_CALL(N(CreateParadeNPC), NPC_13)
    EVT_CALL(N(CreateParadeNPC), NPC_14)
    EVT_CALL(N(CreateParadeNPC), NPC_15)
    EVT_CALL(N(CreateParadeNPC), NPC_16)
    EVT_CALL(N(CreateParadeNPC), NPC_17)
    EVT_CALL(N(CreateParadeNPC), NPC_18)
    EVT_CALL(N(CreateParadeNPC), NPC_19)
    EVT_CALL(N(CreateParadeNPC), NPC_1A)
    EVT_CALL(N(CreateParadeNPC), NPC_1B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_5)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_10)
    EVT_CALL(DeleteNpc, NPC_11)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x4700, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_24)
    EVT_CALL(N(CreateParadeNPC), NPC_25)
    EVT_CALL(N(CreateParadeNPC), NPC_32)
    EVT_CALL(N(CreateParadeNPC), NPC_1C)
    EVT_CALL(N(CreateParadeNPC), NPC_1D)
    EVT_CALL(N(CreateParadeNPC), NPC_1E)
    EVT_CALL(N(CreateParadeNPC), NPC_1F)
    EVT_CALL(N(CreateParadeNPC), NPC_20)
    EVT_CALL(N(CreateParadeNPC), NPC_21)
    EVT_CALL(N(CreateParadeNPC), NPC_22)
    EVT_CALL(N(CreateParadeNPC), NPC_23)
    EVT_CALL(N(CreateParadeNPC), NPC_26)
    EVT_CALL(N(CreateParadeNPC), NPC_27)
    EVT_CALL(N(CreateParadeNPC), NPC_28)
    EVT_CALL(N(CreateParadeNPC), NPC_29)
    EVT_CALL(N(CreateParadeNPC), NPC_2A)
    EVT_CALL(N(CreateParadeNPC), NPC_2B)
    EVT_CALL(N(CreateParadeNPC), NPC_2C)
    EVT_CALL(N(CreateParadeNPC), NPC_2D)
    EVT_CALL(N(CreateParadeNPC), NPC_2E)
    EVT_CALL(N(CreateParadeNPC), NPC_2F)
    EVT_CALL(N(CreateParadeNPC), NPC_30)
    EVT_CALL(N(CreateParadeNPC), NPC_31)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_7)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_12)
    EVT_CALL(DeleteNpc, NPC_13)
    EVT_CALL(DeleteNpc, NPC_14)
    EVT_CALL(DeleteNpc, NPC_15)
    EVT_CALL(DeleteNpc, NPC_16)
    EVT_CALL(DeleteNpc, NPC_17)
    EVT_CALL(DeleteNpc, NPC_18)
    EVT_CALL(DeleteNpc, NPC_19)
    EVT_CALL(DeleteNpc, NPC_1A)
    EVT_CALL(DeleteNpc, NPC_1B)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_33)
    EVT_CALL(N(CreateParadeNPC), NPC_34)
    EVT_CALL(N(CreateParadeNPC), NPC_35)
    EVT_CALL(N(CreateParadeNPC), NPC_36)
    EVT_CALL(N(CreateParadeNPC), NPC_37)
    EVT_CALL(N(CreateParadeNPC), NPC_38)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_8)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_24)
    EVT_CALL(DeleteNpc, NPC_25)
    EVT_CALL(DeleteNpc, NPC_32)
    EVT_CALL(DeleteNpc, NPC_1C)
    EVT_CALL(DeleteNpc, NPC_1D)
    EVT_CALL(DeleteNpc, NPC_1E)
    EVT_CALL(DeleteNpc, NPC_1F)
    EVT_CALL(DeleteNpc, NPC_20)
    EVT_CALL(DeleteNpc, NPC_21)
    EVT_CALL(DeleteNpc, NPC_22)
    EVT_CALL(DeleteNpc, NPC_23)
    EVT_CALL(DeleteNpc, NPC_26)
    EVT_CALL(DeleteNpc, NPC_27)
    EVT_CALL(DeleteNpc, NPC_28)
    EVT_CALL(DeleteNpc, NPC_29)
    EVT_CALL(DeleteNpc, NPC_2A)
    EVT_CALL(DeleteNpc, NPC_2B)
    EVT_CALL(DeleteNpc, NPC_2C)
    EVT_CALL(DeleteNpc, NPC_2D)
    EVT_CALL(DeleteNpc, NPC_2E)
    EVT_CALL(DeleteNpc, NPC_2F)
    EVT_CALL(DeleteNpc, NPC_30)
    EVT_CALL(DeleteNpc, NPC_31)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_39)
    EVT_CALL(N(CreateParadeNPC), NPC_3A)
    EVT_CALL(N(CreateParadeNPC), NPC_3B)
    EVT_CALL(N(CreateParadeNPC), NPC_3C)
    EVT_CALL(N(CreateParadeNPC), NPC_3D)
    EVT_CALL(N(CreateParadeNPC), NPC_3E)
    EVT_CALL(N(CreateParadeNPC), NPC_3F)
    EVT_CALL(N(CreateParadeNPC), NPC_40)
    EVT_CALL(N(CreateParadeNPC), NPC_41)
    EVT_CALL(N(CreateParadeNPC), NPC_42)
    EVT_CALL(N(CreateParadeNPC), NPC_43)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_PlayCredits) = {
    EVT_WAIT(60)
    EVT_EXEC(N(EVS_InitCredits))
    EVT_EXEC(N(EVS_ShowCredits_Jobs))
    EVT_EXEC(N(EVS_ShowCredits_Names))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageParade) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_PARADE_NIGHT, 0, 8)
    EVT_EXEC(N(EVS_SetupInitialCamera))
    EVT_EXEC(N(EVS_ManageNpcPool))
    EVT_EXEC_GET_TID(N(EVS_ParadePhase_StarSpirits), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_PlayCredits))
    EVT_EXEC_GET_TID(N(EVS_UpdateScrollPos), LVarA)
    EVT_EXEC_GET_TID(N(EVS_UpdateTexPan_Ground), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_SkatingPenguins))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245C74_E0AFD4))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80245FF0_E0B350))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_4)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80246A60))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_5)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_ShyGuyDancing))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_6)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_ShyGuyFormation))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_7)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Toads1))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_8)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(EVS_ParadePhase_MarioPeach), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_9)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarC, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Toads2))
    EVT_WAIT(150)
    EVT_EXEC(N(EVS_MarioPeachExit))
    EVT_WAIT(200)
    EVT_CALL(GotoMap, EVT_PTR("kmr_30"), kmr_30_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
