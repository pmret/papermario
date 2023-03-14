#include "end_01.h"
#include "effects.h"

extern HeapNode heap_spriteHead;

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo N(ParadeNpcsTable)[];

extern EvtScript N(EVS_ParadePhase_Wizards);
extern EvtScript N(EVS_ParadePhase_ShyGuyDancing);
extern EvtScript N(EVS_ParadePhase_ShyGuyFormation);
extern EvtScript N(EVS_ParadePhase_Toads1);
extern EvtScript N(EVS_ParadePhase_MarioPeach);
extern EvtScript N(EVS_ParadePhase_Toads2);
extern EvtScript N(EVS_MarioPeachExit);
extern EvtScript N(EVS_ParadePhase_StarSpirits);
extern EvtScript N(EVS_ParadePhase_SkatingPenguins);
extern EvtScript N(EVS_ParadePhase_Opera);
extern EvtScript N(EVS_ParadePhase_MayorPenguin);

extern EvtScript N(EVS_InitCredits);
extern EvtScript N(EVS_ShowCredits_Jobs);
extern EvtScript N(EVS_ShowCredits_Names);

API_CALLABLE(N(CreateParadeNPC)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    ParadeNpcInfo* npcInfo = &N(ParadeNpcsTable)[npcID];
    NpcBlueprint bp;
    Npc* npc;

    bp.flags = NPC_FLAG_IGNORE_PLAYER_COLLISION;
    bp.initialAnim = npcInfo->initialAnim;
    bp.onUpdate = NULL;
    bp.onRender = NULL;

    spr_allocateBtlComponentsOnWorldHeap = TRUE;

    npc = get_npc_by_index(create_standard_npc(&bp, npcInfo->animList));
    npc->npcID = npcID;
    npc->flags &= ~NPC_FLAG_PARTNER;
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

    evt_set_variable(script, outVar, (s32) _heap_malloc(&heap_spriteHead, heapSize));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ParadeSpriteHeapFree)) {
    Bytecode* args = script->ptrReadPos;
    s32 pointer = *args++;

    _heap_free(&heap_spriteHead, (void*) evt_get_variable(script, pointer));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(UpdateCameraScroll)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->panActive = TRUE;
    camera->movePos.x += PARADE_SCROLL_RATE / DT;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddScrollToNpcPos)) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTempPtr[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += PARADE_SCROLL_RATE / DT;

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
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, PARADE_START, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, PARADE_START, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateScrollPos) = {
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(PARADE_START), 0, 0)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(N(UpdateCameraScroll))
        EVT_CALL(TranslateGroup, MODEL_bg, LVar1, 0, 0)
        EVT_ADDF(LVar1, EVT_FLOAT(PARADE_SCROLL_RATE / DT))
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
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mamar)[] = {
    ANIM_BattleMamar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Skolar)[] = {
    ANIM_BattleSkolar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Muskular)[] = {
    ANIM_BattleMuskular_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Misstar)[] = {
    ANIM_BattleMisstar_Still,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Klevar)[] = {
    ANIM_BattleKlevar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kalmar)[] = {
    ANIM_BattleKalmar_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_PyroGuy)[] = {
    ANIM_PyroGuy_Anim03,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_ShyGuy)[] = {
    ANIM_ShyGuy_Red_Anim04,
    ANIM_ShyGuy_Red_Anim10,
    ANIM_ShyGuy_Red_Anim01,
    ANIM_LIST_END
};

ParadeNpcInfo N(ParadeNpcsTable)[] = {
    [NPC_Eldstar] {
        .initialAnim = ANIM_BattleEldstar_Idle,
        .animList = N(ExtraAnims_Eldstar),
        .pos = { -3135.0f, 210.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_Mamar] {
        .initialAnim = ANIM_BattleMamar_Idle,
        .animList = N(ExtraAnims_Mamar),
        .pos = { -3195.0f, 200.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_Skolar] {
        .initialAnim = ANIM_BattleSkolar_Idle,
        .animList = N(ExtraAnims_Skolar),
        .pos = { -3075.0f, 195.0f, -120.0f },
        .yaw = 270.0f
    },
    [NPC_Muskular] {
        .initialAnim = ANIM_BattleMuskular_Idle,
        .animList = N(ExtraAnims_Muskular),
        .pos = { -3045.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_Misstar] {
        .initialAnim = ANIM_BattleMisstar_Still,
        .animList = N(ExtraAnims_Misstar),
        .pos = { -3105.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_Klevar] {
        .initialAnim = ANIM_BattleKlevar_Idle,
        .animList = N(ExtraAnims_Klevar),
        .pos = { -3165.0f, 158.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_Kalmar] {
        .initialAnim = ANIM_BattleKalmar_Idle,
        .animList = N(ExtraAnims_Kalmar),
        .pos = { -3225.0f, 148.0f, -104.0f },
        .yaw = 270.0f
    },
    [NPC_PenguinSkater1] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, -37.0f },
        .yaw = 270.0f
    },
    [NPC_PenguinSkater2] {
        .initialAnim = ANIM_ParadeIceShow_Violin_SkateStill,
        .pos = { -2700.0f, 0.0f, 37.0f },
        .yaw = 270.0f
    },
    [NPC_PenguinMayor] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWalk,
        .pos = { -2650.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_PenguinMayorWife] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeMayorWifeWalk,
        .pos = { -2610.0f, 0.0f, -77.0f },
        .yaw = 270.0f
    },
    [NPC_ViolinPlayer1] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2555.0f, 5.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_ViolinPlayer2] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlayUpright,
        .pos = { -2527.0f, 5.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_ViolinPlayer3] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ViolinPlay,
        .pos = { -2495.0f, 5.0f, 30.0f },
        .yaw = 90.0f
    },
    [NPC_Conductor] {
        .initialAnim = ANIM_Musician_Poet_Dark_ConductSlow,
        .pos = { -2624.0f, 20.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Singer] {
        .initialAnim = ANIM_ParadeIceShow_Violin_ShadeDivaIdle,
        .pos = { -2529.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_AmayzeDayzee1] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_AmayzeDayzee2] {
        .initialAnim = ANIM_Dayzee_Amazy_Anim02,
        .pos = { -2210.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Merle] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleGather,
        .pos = { -2025.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_Merlee] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerleeGather,
        .pos = { -1995.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Merlon] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlonGather,
        .pos = { -2055.0f, 20.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_Merluvlee] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerluvleeGather,
        .pos = { -2085.0f, 20.0f, 28.0f },
        .yaw = 270.0f
    },
    [NPC_Merlow] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlowGather,
        .pos = { -2110.0f, 20.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Merlar] {
        .initialAnim = ANIM_ParadeWizard_Merle_MerlarGather,
        .pos = { -1980.0f, 60.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_SunSad] {
        .initialAnim = ANIM_Sun_TalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_SunHappy] {
        .initialAnim = ANIM_Sun_FireTalkSad,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Bubulb1] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_Bubulb2] {
        .initialAnim = ANIM_Bubulb_Pink_DarkWalk,
        .pos = { -1850.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyMarshall] {
        .initialAnim = ANIM_ParadeShyGuy_MarshallWalk,
        .pos = { -1548.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_GeneralGuy] {
        .initialAnim = ANIM_ParadeShyGuy_GeneralPoint,
        .pos = { -1448.0f, 57.0f, -25.0f },
        .yaw = 270.0f
    },
    [NPC_BackupDancer1] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1483.0f, 24.0f, -40.0f },
        .yaw = 90.0f
    },
    [NPC_BackupDancer2] {
        .initialAnim = ANIM_ParadeShyGuy_StackHold,
        .pos = { -1413.0f, 24.0f, -40.0f },
        .yaw = 270.0f
    },
    [NPC_GrooveGuy1] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1468.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_GrooveGuy2] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1458.0f, 24.0f, -5.0f },
        .yaw = 270.0f
    },
    [NPC_GrooveGuy3] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1438.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_GrooveGuy4] {
        .initialAnim = ANIM_ParadeShyGuy_GroovePivot,
        .pos = { -1428.0f, 24.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_PyroGuy1] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(ExtraAnims_PyroGuy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_PyroGuy2] {
        .initialAnim = ANIM_PyroGuy_Anim03,
        .animList = N(ExtraAnims_PyroGuy),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation11] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation12] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation13] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1048.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation21] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation22] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation23] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -1018.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation31] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation32] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation33] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -988.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation41] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, -30.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation42] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ShyGuyFormation43] {
        .initialAnim = ANIM_ParadeShyGuy_ShadeWalk,
        .pos = { -958.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_Pratfaller] {
        .initialAnim = ANIM_ShyGuy_Red_Anim04,
        .animList = N(ExtraAnims_ShyGuy),
        .pos = { -788.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HornPlayer1] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_HornPlayer2] {
        .initialAnim = ANIM_ParadeHorn_Walk,
        .pos = { -689.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Drummer1] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_Drummer2] {
        .initialAnim = ANIM_ParadeDrummer_Walk,
        .pos = { -639.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer1] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer2] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { -589.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Mario] {
        .initialAnim = ANIM_ParadeMario_Wave,
        .pos = { -329.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Peach] {
        .initialAnim = ANIM_ParadePeach_ShadeWaveSlow,
        .pos = { -289.0f, 37.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twink] {
        .initialAnim = ANIM_ParadeTwink_Idle,
        .pos = { -389.0f, 120.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Twirler1] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -109.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twirler2] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -69.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twirler3] {
        .initialAnim = ANIM_ParadeTwirler_Walk,
        .pos = { -29.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton1] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton2] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton3] {
        .initialAnim = ANIM_ParadeTwirler_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer3] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer4] {
        .initialAnim = ANIM_ParadeBanner_Walk,
        .pos = { 41.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
};

EvtScript N(EVS_ManageNpcPool) = {
    EVT_CALL(N(CreateParadeNPC), NPC_Eldstar)
    EVT_CALL(N(CreateParadeNPC), NPC_Mamar)
    EVT_CALL(N(CreateParadeNPC), NPC_Skolar)
    EVT_CALL(N(CreateParadeNPC), NPC_Muskular)
    EVT_CALL(N(CreateParadeNPC), NPC_Misstar)
    EVT_CALL(N(CreateParadeNPC), NPC_Klevar)
    EVT_CALL(N(CreateParadeNPC), NPC_Kalmar)
    EVT_CALL(N(CreateParadeNPC), NPC_PenguinMayor)
    EVT_CALL(N(CreateParadeNPC), NPC_PenguinMayorWife)
    EVT_CALL(N(CreateParadeNPC), NPC_PenguinSkater1)
    EVT_CALL(N(CreateParadeNPC), NPC_PenguinSkater2)
    EVT_CALL(N(CreateParadeNPC), NPC_ViolinPlayer1)
    EVT_CALL(N(CreateParadeNPC), NPC_ViolinPlayer2)
    EVT_CALL(N(CreateParadeNPC), NPC_ViolinPlayer3)
    EVT_CALL(N(CreateParadeNPC), NPC_Conductor)
    EVT_CALL(N(CreateParadeNPC), NPC_Singer)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x13400, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_AmayzeDayzee1)
    EVT_CALL(N(CreateParadeNPC), NPC_AmayzeDayzee2)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_WIZARDS + 100)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Eldstar)
    EVT_CALL(DeleteNpc, NPC_Mamar)
    EVT_CALL(DeleteNpc, NPC_Skolar)
    EVT_CALL(DeleteNpc, NPC_Muskular)
    EVT_CALL(DeleteNpc, NPC_Misstar)
    EVT_CALL(DeleteNpc, NPC_Klevar)
    EVT_CALL(DeleteNpc, NPC_Kalmar)
    EVT_CALL(DeleteNpc, NPC_PenguinMayor)
    EVT_CALL(DeleteNpc, NPC_PenguinMayorWife)
    EVT_CALL(DeleteNpc, NPC_PenguinSkater1)
    EVT_CALL(DeleteNpc, NPC_PenguinSkater2)
    EVT_CALL(DeleteNpc, NPC_ViolinPlayer1)
    EVT_CALL(DeleteNpc, NPC_ViolinPlayer2)
    EVT_CALL(DeleteNpc, NPC_ViolinPlayer3)
    EVT_CALL(DeleteNpc, NPC_Conductor)
    EVT_CALL(DeleteNpc, NPC_Singer)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Merle)
    EVT_CALL(N(CreateParadeNPC), NPC_Merlee)
    EVT_CALL(N(CreateParadeNPC), NPC_Merlon)
    EVT_CALL(N(CreateParadeNPC), NPC_Merluvlee)
    EVT_CALL(N(CreateParadeNPC), NPC_Merlow)
    EVT_CALL(N(CreateParadeNPC), NPC_Merlar)
    EVT_CALL(N(CreateParadeNPC), NPC_SunSad)
    EVT_CALL(N(CreateParadeNPC), NPC_SunHappy)
    EVT_CALL(N(CreateParadeNPC), NPC_Bubulb1)
    EVT_CALL(N(CreateParadeNPC), NPC_Bubulb2)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_AmayzeDayzee1)
    EVT_CALL(DeleteNpc, NPC_AmayzeDayzee2)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x4700, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_PyroGuy1)
    EVT_CALL(N(CreateParadeNPC), NPC_PyroGuy2)
    EVT_CALL(N(CreateParadeNPC), NPC_Pratfaller)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyMarshall)
    EVT_CALL(N(CreateParadeNPC), NPC_GeneralGuy)
    EVT_CALL(N(CreateParadeNPC), NPC_BackupDancer1)
    EVT_CALL(N(CreateParadeNPC), NPC_BackupDancer2)
    EVT_CALL(N(CreateParadeNPC), NPC_GrooveGuy1)
    EVT_CALL(N(CreateParadeNPC), NPC_GrooveGuy2)
    EVT_CALL(N(CreateParadeNPC), NPC_GrooveGuy3)
    EVT_CALL(N(CreateParadeNPC), NPC_GrooveGuy4)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation11)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation12)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation13)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation21)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation22)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation23)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation31)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation32)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation33)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation41)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation42)
    EVT_CALL(N(CreateParadeNPC), NPC_ShyGuyFormation43)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOADS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Merle)
    EVT_CALL(DeleteNpc, NPC_Merlee)
    EVT_CALL(DeleteNpc, NPC_Merlon)
    EVT_CALL(DeleteNpc, NPC_Merluvlee)
    EVT_CALL(DeleteNpc, NPC_Merlow)
    EVT_CALL(DeleteNpc, NPC_Merlar)
    EVT_CALL(DeleteNpc, NPC_SunSad)
    EVT_CALL(DeleteNpc, NPC_SunHappy)
    EVT_CALL(DeleteNpc, NPC_Bubulb1)
    EVT_CALL(DeleteNpc, NPC_Bubulb2)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_HornPlayer1)
    EVT_CALL(N(CreateParadeNPC), NPC_HornPlayer2)
    EVT_CALL(N(CreateParadeNPC), NPC_Drummer1)
    EVT_CALL(N(CreateParadeNPC), NPC_Drummer2)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer1)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer2)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_PEACH)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_PyroGuy1)
    EVT_CALL(DeleteNpc, NPC_PyroGuy2)
    EVT_CALL(DeleteNpc, NPC_Pratfaller)
    EVT_CALL(DeleteNpc, NPC_ShyGuyMarshall)
    EVT_CALL(DeleteNpc, NPC_GeneralGuy)
    EVT_CALL(DeleteNpc, NPC_BackupDancer1)
    EVT_CALL(DeleteNpc, NPC_BackupDancer2)
    EVT_CALL(DeleteNpc, NPC_GrooveGuy1)
    EVT_CALL(DeleteNpc, NPC_GrooveGuy2)
    EVT_CALL(DeleteNpc, NPC_GrooveGuy3)
    EVT_CALL(DeleteNpc, NPC_GrooveGuy4)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation11)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation12)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation13)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation21)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation22)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation23)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation31)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation32)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation33)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation41)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation42)
    EVT_CALL(DeleteNpc, NPC_ShyGuyFormation43)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Mario)
    EVT_CALL(N(CreateParadeNPC), NPC_Peach)
    EVT_CALL(N(CreateParadeNPC), NPC_Twink)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler1)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler2)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler3)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton1)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton2)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton3)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer3)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer4)
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
        EVT_IF_GT(LVar0, PARADE_PHASE_SKATERS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_SkatingPenguins))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_MAYOR)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_MayorPenguin))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_OPERA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Opera))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_WIZARDS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Wizards))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_ShyGuyDancing))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_SHYGUY_MARCH)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_ShyGuyFormation))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOADS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Toads1))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_PEACH)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(EVS_ParadePhase_MarioPeach), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_EXIT)
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
