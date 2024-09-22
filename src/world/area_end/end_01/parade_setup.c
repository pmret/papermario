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
    Call(UseSettingsFrom, CAM_DEFAULT, PARADE_START, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, PARADE_START, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Return
    End
};

EvtScript N(EVS_UpdateScrollPos) = {
    Call(SetPanTarget, CAM_DEFAULT, Float(PARADE_START), 0, 0)
    SetF(LVar1, Float(0.0))
    Loop(0)
        Call(N(UpdateCameraScroll))
        Call(TranslateGroup, MODEL_bg, LVar1, 0, 0)
        AddF(LVar1, Float(PARADE_SCROLL_RATE / DT))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateTexPan_Ground) = {
    Call(EnableTexPanning, MODEL_o145, TRUE)
    Call(EnableTexPanning, MODEL_o146, TRUE)
    Call(EnableTexPanning, MODEL_j2, TRUE)
    Call(EnableTexPanning, MODEL_o152, TRUE)
    Call(EnableTexPanning, MODEL_o153, TRUE)
    Call(EnableTexPanning, MODEL_o154, TRUE)
    Call(EnableTexPanning, MODEL_o166, TRUE)
    Call(EnableTexPanning, MODEL_o157, TRUE)
    Call(EnableTexPanning, MODEL_o159, TRUE)
    Call(EnableTexPanning, MODEL_o160, TRUE)
    Call(EnableTexPanning, MODEL_o161, TRUE)
    Call(EnableTexPanning, MODEL_o162, TRUE)
    Call(EnableTexPanning, MODEL_o195, TRUE)
    Call(EnableTexPanning, MODEL_o196, TRUE)
    Call(EnableTexPanning, MODEL_o197, TRUE)
    Call(EnableTexPanning, MODEL_o198, TRUE)
    Call(EnableTexPanning, MODEL_o260, TRUE)
    Call(EnableTexPanning, MODEL_o201, TRUE)
    Call(EnableTexPanning, MODEL_o202, TRUE)
    Call(EnableTexPanning, MODEL_o203, TRUE)
    Call(EnableTexPanning, MODEL_o204, TRUE)
    Call(EnableTexPanning, MODEL_o275, TRUE)
    Call(EnableTexPanning, MODEL_o276, TRUE)
    Call(EnableTexPanning, MODEL_o277, TRUE)
    Call(EnableTexPanning, MODEL_o278, TRUE)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Loop(0)
            Add(LVar0, 150)
            IfGt(LVar0, 0x20000)
                Add(LVar0, -0x20000)
            EndIf
            Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            Wait(1)
        EndLoop
    EndThread
    Return
    End
};

EvtScript N(EVS_OffsetNpcScroll) = {
    Call(N(AddScrollToNpcPos), LVar0)
    Return
    End
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
    Call(N(CreateParadeNPC), NPC_Eldstar)
    Call(N(CreateParadeNPC), NPC_Mamar)
    Call(N(CreateParadeNPC), NPC_Skolar)
    Call(N(CreateParadeNPC), NPC_Muskular)
    Call(N(CreateParadeNPC), NPC_Misstar)
    Call(N(CreateParadeNPC), NPC_Klevar)
    Call(N(CreateParadeNPC), NPC_Kalmar)
    Call(N(CreateParadeNPC), NPC_PenguinMayor)
    Call(N(CreateParadeNPC), NPC_PenguinMayorWife)
    Call(N(CreateParadeNPC), NPC_PenguinSkater1)
    Call(N(CreateParadeNPC), NPC_PenguinSkater2)
    Call(N(CreateParadeNPC), NPC_ViolinPlayer1)
    Call(N(CreateParadeNPC), NPC_ViolinPlayer2)
    Call(N(CreateParadeNPC), NPC_ViolinPlayer3)
    Call(N(CreateParadeNPC), NPC_Conductor)
    Call(N(CreateParadeNPC), NPC_Singer)
    Call(N(ParadeSpriteHeapMalloc), 0x13400, LVar0)
    Call(N(CreateParadeNPC), NPC_AmayzeDayzee1)
    Call(N(CreateParadeNPC), NPC_AmayzeDayzee2)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_WIZARDS + 100)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Eldstar)
    Call(DeleteNpc, NPC_Mamar)
    Call(DeleteNpc, NPC_Skolar)
    Call(DeleteNpc, NPC_Muskular)
    Call(DeleteNpc, NPC_Misstar)
    Call(DeleteNpc, NPC_Klevar)
    Call(DeleteNpc, NPC_Kalmar)
    Call(DeleteNpc, NPC_PenguinMayor)
    Call(DeleteNpc, NPC_PenguinMayorWife)
    Call(DeleteNpc, NPC_PenguinSkater1)
    Call(DeleteNpc, NPC_PenguinSkater2)
    Call(DeleteNpc, NPC_ViolinPlayer1)
    Call(DeleteNpc, NPC_ViolinPlayer2)
    Call(DeleteNpc, NPC_ViolinPlayer3)
    Call(DeleteNpc, NPC_Conductor)
    Call(DeleteNpc, NPC_Singer)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Merle)
    Call(N(CreateParadeNPC), NPC_Merlee)
    Call(N(CreateParadeNPC), NPC_Merlon)
    Call(N(CreateParadeNPC), NPC_Merluvlee)
    Call(N(CreateParadeNPC), NPC_Merlow)
    Call(N(CreateParadeNPC), NPC_Merlar)
    Call(N(CreateParadeNPC), NPC_SunSad)
    Call(N(CreateParadeNPC), NPC_SunHappy)
    Call(N(CreateParadeNPC), NPC_Bubulb1)
    Call(N(CreateParadeNPC), NPC_Bubulb2)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_AmayzeDayzee1)
    Call(DeleteNpc, NPC_AmayzeDayzee2)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x4700, LVar0)
    Call(N(CreateParadeNPC), NPC_PyroGuy1)
    Call(N(CreateParadeNPC), NPC_PyroGuy2)
    Call(N(CreateParadeNPC), NPC_Pratfaller)
    Call(N(CreateParadeNPC), NPC_ShyGuyMarshall)
    Call(N(CreateParadeNPC), NPC_GeneralGuy)
    Call(N(CreateParadeNPC), NPC_BackupDancer1)
    Call(N(CreateParadeNPC), NPC_BackupDancer2)
    Call(N(CreateParadeNPC), NPC_GrooveGuy1)
    Call(N(CreateParadeNPC), NPC_GrooveGuy2)
    Call(N(CreateParadeNPC), NPC_GrooveGuy3)
    Call(N(CreateParadeNPC), NPC_GrooveGuy4)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation11)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation12)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation13)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation21)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation22)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation23)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation31)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation32)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation33)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation41)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation42)
    Call(N(CreateParadeNPC), NPC_ShyGuyFormation43)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOADS)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Merle)
    Call(DeleteNpc, NPC_Merlee)
    Call(DeleteNpc, NPC_Merlon)
    Call(DeleteNpc, NPC_Merluvlee)
    Call(DeleteNpc, NPC_Merlow)
    Call(DeleteNpc, NPC_Merlar)
    Call(DeleteNpc, NPC_SunSad)
    Call(DeleteNpc, NPC_SunHappy)
    Call(DeleteNpc, NPC_Bubulb1)
    Call(DeleteNpc, NPC_Bubulb2)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_HornPlayer1)
    Call(N(CreateParadeNPC), NPC_HornPlayer2)
    Call(N(CreateParadeNPC), NPC_Drummer1)
    Call(N(CreateParadeNPC), NPC_Drummer2)
    Call(N(CreateParadeNPC), NPC_StandardBearer1)
    Call(N(CreateParadeNPC), NPC_StandardBearer2)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_PEACH)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_PyroGuy1)
    Call(DeleteNpc, NPC_PyroGuy2)
    Call(DeleteNpc, NPC_Pratfaller)
    Call(DeleteNpc, NPC_ShyGuyMarshall)
    Call(DeleteNpc, NPC_GeneralGuy)
    Call(DeleteNpc, NPC_BackupDancer1)
    Call(DeleteNpc, NPC_BackupDancer2)
    Call(DeleteNpc, NPC_GrooveGuy1)
    Call(DeleteNpc, NPC_GrooveGuy2)
    Call(DeleteNpc, NPC_GrooveGuy3)
    Call(DeleteNpc, NPC_GrooveGuy4)
    Call(DeleteNpc, NPC_ShyGuyFormation11)
    Call(DeleteNpc, NPC_ShyGuyFormation12)
    Call(DeleteNpc, NPC_ShyGuyFormation13)
    Call(DeleteNpc, NPC_ShyGuyFormation21)
    Call(DeleteNpc, NPC_ShyGuyFormation22)
    Call(DeleteNpc, NPC_ShyGuyFormation23)
    Call(DeleteNpc, NPC_ShyGuyFormation31)
    Call(DeleteNpc, NPC_ShyGuyFormation32)
    Call(DeleteNpc, NPC_ShyGuyFormation33)
    Call(DeleteNpc, NPC_ShyGuyFormation41)
    Call(DeleteNpc, NPC_ShyGuyFormation42)
    Call(DeleteNpc, NPC_ShyGuyFormation43)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Mario)
    Call(N(CreateParadeNPC), NPC_Peach)
    Call(N(CreateParadeNPC), NPC_Twink)
    Call(N(CreateParadeNPC), NPC_Twirler1)
    Call(N(CreateParadeNPC), NPC_Twirler2)
    Call(N(CreateParadeNPC), NPC_Twirler3)
    Call(N(CreateParadeNPC), NPC_Baton1)
    Call(N(CreateParadeNPC), NPC_Baton2)
    Call(N(CreateParadeNPC), NPC_Baton3)
    Call(N(CreateParadeNPC), NPC_StandardBearer3)
    Call(N(CreateParadeNPC), NPC_StandardBearer4)
    Return
    End
};

EvtScript N(EVS_ParadePhase_PlayCredits) = {
    Wait(60)
    Exec(N(EVS_InitCredits))
    Exec(N(EVS_ShowCredits_Jobs))
    Exec(N(EVS_ShowCredits_Names))
    Return
    End
};

EvtScript N(EVS_ManageParade) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetMusicTrack, 0, SONG_PARADE_NIGHT, 0, 8)
    Exec(N(EVS_SetupInitialCamera))
    Exec(N(EVS_ManageNpcPool))
    ExecGetTID(N(EVS_ParadePhase_StarSpirits), LVarA)
    Loop(0)
        Wait(1)
        IsThreadRunning(LVarA, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_PlayCredits))
    ExecGetTID(N(EVS_UpdateScrollPos), LVarA)
    ExecGetTID(N(EVS_UpdateTexPan_Ground), LVarB)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SKATERS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_SkatingPenguins))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_MAYOR)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_MayorPenguin))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_OPERA)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Opera))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_WIZARDS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Wizards))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_DANCE)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_ShyGuyDancing))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_SHYGUY_MARCH)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_ShyGuyFormation))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOADS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Toads1))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_PEACH)
            BreakLoop
        EndIf
    EndLoop
    ExecGetTID(N(EVS_ParadePhase_MarioPeach), LVarC)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_EXIT)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVarA)
    KillThread(LVarB)
    Loop(0)
        Wait(1)
        IsThreadRunning(LVarC, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Toads2))
    Wait(150)
    Exec(N(EVS_MarioPeachExit))
    Wait(200)
    Call(GotoMap, Ref("kmr_30"), kmr_30_ENTRY_0)
    Wait(100)
    Return
    End
};
