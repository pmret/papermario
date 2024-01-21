#include "end_00.h"
#include "effects.h"

extern HeapNode heap_spriteHead;

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo N(ParadeNpcsTable)[];

extern EvtScript N(EVS_ParadePhase_Luigi);
extern EvtScript N(EVS_ParadePhase_Partners);
extern EvtScript N(EVS_ParadePhase_Toads);
extern EvtScript N(EVS_ParadePhase_KoopaBros);
extern EvtScript N(EVS_ParadePhase_Kolorado);
extern EvtScript N(EVS_ParadePhase_Caravan);
extern EvtScript N(EVS_ParadePhase_BuzzarNest);
extern EvtScript N(EVS_ParadePhase_Tutankoopa);
extern EvtScript N(EVS_ParadePhase_Boos);
extern EvtScript N(EVS_ParadePhase_GoombaKing);
extern EvtScript N(EVS_ParadePhase_Yoshis);
extern EvtScript N(EVS_ParadePhase_HuffNPuff);
extern EvtScript N(EVS_ParadePhase_CrystalKing);
extern EvtScript N(EVS_ParadePhase_Bowser);

extern EvtScript N(EVS_InitCredits);
extern EvtScript N(EVS_ShowCredits_Title);
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

API_CALLABLE(N(SetNpcShadowScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
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

EvtScript N(EVS_SetupInitialCamera) = {
    Call(UseSettingsFrom, CAM_DEFAULT, PARADE_START, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, PARADE_START, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
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

EvtScript N(EVS_SetNpcShadowScale) = {
    Call(N(SetNpcShadowScale), LVar0, LVar2)
    Call(SetNpcFlagBits, LVar0, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Return
    End
};

EvtScript N(EVS_OffsetNpcScroll) = {
    Call(N(AddScrollToNpcPos), LVar0)
    Return
    End
};

EvtScript N(EVS_UpdateTexPan_Ground) = {
    Call(EnableTexPanning, MODEL_j1, TRUE)
    Call(EnableTexPanning, MODEL_j2, TRUE)
    Call(EnableTexPanning, MODEL_j3, TRUE)
    Call(EnableTexPanning, MODEL_j4, TRUE)
    Call(EnableTexPanning, MODEL_j5, TRUE)
    Call(EnableTexPanning, MODEL_j6, TRUE)
    Call(EnableTexPanning, MODEL_j7, TRUE)
    Call(EnableTexPanning, MODEL_j8, TRUE)
    Call(EnableTexPanning, MODEL_j9, TRUE)
    Call(EnableTexPanning, MODEL_j10, TRUE)
    Call(EnableTexPanning, MODEL_j11, TRUE)
    Call(EnableTexPanning, MODEL_j12, TRUE)
    Call(EnableTexPanning, MODEL_j13, TRUE)
    Call(EnableTexPanning, MODEL_j14, TRUE)
    Call(EnableTexPanning, MODEL_j15, TRUE)
    Call(EnableTexPanning, MODEL_j16, TRUE)
    Call(EnableTexPanning, MODEL_j17, TRUE)
    Call(EnableTexPanning, MODEL_j18, TRUE)
    Call(EnableTexPanning, MODEL_j19, TRUE)
    Call(EnableTexPanning, MODEL_j20, TRUE)
    Call(EnableTexPanning, MODEL_j21, TRUE)
    Call(EnableTexPanning, MODEL_j22, TRUE)
    Call(EnableTexPanning, MODEL_j23, TRUE)
    Call(EnableTexPanning, MODEL_j24, TRUE)
    Call(EnableTexPanning, MODEL_j25, TRUE)
    Call(EnableTexPanning, MODEL_j26, TRUE)
    Call(EnableTexPanning, MODEL_j27, TRUE)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Loop(0)
            Add(LVar0, 300)
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

EvtScript N(EVS_TexPan_Clouds) = {
    Call(EnableTexPanning, MODEL_cloud, TRUE)
    Set(LVar0, 0)
    Loop(0)
        Add(LVar0, 0x8000)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        Wait(16)
    EndLoop
    Return
    End
};

EvtScript N(EVS_TexPan_Water) = {
    Call(EnableTexPanning, MODEL_umi, TRUE)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Loop(0)
        Add(LVar0, 50)
        Add(LVar1, 50)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, LVar1)
        Add(LVar2, -50)
        Add(LVar3, -50)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX, LVar2, LVar3)
        Wait(1)
    EndLoop
    Return
    End
};

AnimID N(ExtraAnims_Tutankoopa)[] = {
    ANIM_Tutankoopa_Run,
    ANIM_Tutankoopa_Hurt,
    ANIM_Tutankoopa_LevitateStill,
    ANIM_Tutankoopa_Idle,
    ANIM_Tutankoopa_Lift,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Rowf)[] = {
    ANIM_Rowf_PackedStill,
    ANIM_Rowf_PackedIdle,
    ANIM_Rowf_PackedWalk,
    ANIM_Rowf_PackedRun,
    ANIM_Rowf_PackedTalk,
    ANIM_Rowf_PackedCheer,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Moustafa)[] = {
    ANIM_Moustafa_Run,
    ANIM_Moustafa_Shout,
    ANIM_Moustafa_Talk,
    ANIM_Moustafa_Toss,
    ANIM_Moustafa_Idle,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Mouser)[] = {
    ANIM_Mouser_Blue_Run,
    ANIM_Mouser_Blue_IdleOnlyBlink,
    ANIM_Mouser_Blue_Whisper,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Buzzar)[] = {
    ANIM_Buzzar_Anim05,
    ANIM_Buzzar_Anim03,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_GoombaKing)[] = {
    ANIM_GoombaKing_Still,
    ANIM_GoombaKing_Dead,
    ANIM_GoombaKing_Angry,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_RaphaelRaven)[] = {
    ANIM_RaphaelRaven_IdleNoFeet,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_LavaPiranha)[] = {
    ANIM_LavaPiranha_Anim04,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_HuffNPuff)[] = {
    ANIM_HuffNPuff_Anim01,
    ANIM_HuffNPuff_Anim02,
    ANIM_HuffNPuff_Anim03,
    ANIM_HuffNPuff_Anim07,
    ANIM_HuffNPuff_Anim08,
    ANIM_HuffNPuff_Anim09,
    ANIM_HuffNPuff_Anim26,
    ANIM_HuffNPuff_Anim27,
    ANIM_HuffNPuff_Anim28,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_RuffPuff)[] = {
    ANIM_RuffPuff_Idle,
    ANIM_RuffPuff_Hurt,
    ANIM_RuffPuff_Blush,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_GourmetGuy)[] = {
    ANIM_GourmetGuy_Walk,
    ANIM_GourmetGuy_Leap,
    ANIM_GourmetGuy_TalkSurprise,
    ANIM_GourmetGuy_Still,
    ANIM_GourmetGuy_Idle,
    ANIM_GourmetGuy_Inspect,
    ANIM_GourmetGuy_Panic,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_MageJrTroopa)[] = {
    ANIM_MageJrTroopa_Idle,
    ANIM_MageJrTroopa_Run,
    ANIM_MageJrTroopa_RaiseStaff,
    ANIM_MageJrTroopa_SwingStaff,
    ANIM_MageJrTroopa_BurnStill,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim14,
    ANIM_WorldKammy_Anim0C,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim12,
    ANIM_WorldKammy_Anim07,
    ANIM_LIST_END
};

ParadeNpcInfo N(ParadeNpcsTable)[] = {
    [NPC_Luigi] {
        .initialAnim = ANIM_ParadeLuigi_March,
        .pos = { -2880.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HornPlayer1] {
        .initialAnim = ANIM_ParadeToad_Red_HornWalk,
        .pos = { -2880.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_HornPlayer2] {
        .initialAnim = ANIM_ParadeToad_Red_HornWalk,
        .pos = { -2880.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Drummer1] {
        .initialAnim = ANIM_ParadeToad_Red_DrummerWalk,
        .pos = { -2830.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_Drummer2] {
        .initialAnim = ANIM_ParadeToad_Red_DrummerWalk,
        .pos = { -2830.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer1] {
        .initialAnim = ANIM_ParadeToad_Red_BannerWalk,
        .pos = { -2780.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_StandardBearer2] {
        .initialAnim = ANIM_ParadeToad_Red_BannerWalk,
        .pos = { -2780.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_Goombario] {
        .initialAnim = ANIM_ParadePartner_Goombario,
        .pos = { -2585.0f, 70.0f, 15.0f },
        .yaw = 270.0f
    },
    [NPC_Kooper] {
        .initialAnim = ANIM_ParadePartner_Kooper,
        .pos = { -2517.0f, 40.0f, 7.0f },
        .yaw = 90.0f
    },
    [NPC_Bombette] {
        .initialAnim = ANIM_ParadePartner_Bombette,
        .pos = { -2536.0f, 50.0f, 38.0f },
        .yaw = 270.0f
    },
    [NPC_Parakarry] {
        .initialAnim = ANIM_ParadePartner_Parakarry,
        .pos = { -2515.0f, 80.0f, 5.0f },
        .yaw = 270.0f
    },
    [NPC_Bow] {
        .initialAnim = ANIM_ParadePartner_Bow,
        .pos = { -2475.0f, 56.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Watt] {
        .initialAnim = ANIM_ParadePartner_Watt,
        .pos = { -2575.0f, 20.0f, 48.0f },
        .yaw = 270.0f
    },
    [NPC_Sushie] {
        .initialAnim = ANIM_ParadePartner_Sushie,
        .pos = { -2570.0f, 61.0f, 7.0f },
        .yaw = 90.0f
    },
    [NPC_Lakilester] {
        .initialAnim = ANIM_ParadePartner_Lakilester,
        .pos = { -2635.0f, 40.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twirler1] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2350.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twirler2] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2300.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Twirler3] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2250.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton1] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton2] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Baton3] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_ChuckQuizmo] {
        .initialAnim = ANIM_ChuckQuizmo_Walk,
        .pos = { -2120.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_VannaT] {
        .initialAnim = ANIM_VannaT_Walk,
        .pos = { -2070.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_KoopaBrosRed] {
        .initialAnim = ANIM_KoopaBros_Red_ThumbsUp,
        .pos = { -1860.0f, 65.0f, 10.0f },
        .yaw = 270.0f
    },
    [NPC_KoopaBrosBlack] {
        .initialAnim = ANIM_KoopaBros_Black_ThumbsUp,
        .pos = { -1840.0f, 65.0f, 10.0f },
        .yaw = 90.0f
    },
    [NPC_KoopaBrosYellow] {
        .initialAnim = ANIM_KoopaBros_Yellow_ThumbsUp,
        .pos = { -1870.0f, 12.0f, 37.0f },
        .yaw = 270.0f
    },
    [NPC_KoopaBrosGreen] {
        .initialAnim = ANIM_KoopaBros_Green_ThumbsUp,
        .pos = { -1830.0f, 12.0f, 37.0f },
        .yaw = 90.0f
    },
    [NPC_Bobomb1] {
        .initialAnim = ANIM_Bobomb_WalkLit,
        .pos = { -1750.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_Bobomb2] {
        .initialAnim = ANIM_Bobomb_WalkLit,
        .pos = { -1720.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_Bobomb3] {
        .initialAnim = ANIM_Bobomb_WalkLit,
        .pos = { -1690.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_Bobomb4] {
        .initialAnim = ANIM_Bobomb_WalkLit,
        .pos = { -1660.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_Kolorado] {
        .initialAnim = ANIM_ParadeKolorado_IdleFwd,
        .pos = { -1555.0f, 45.0f, -190.0f },
        .yaw = 270.0f
    },
    [NPC_KoloradoWife] {
        .initialAnim = ANIM_ParadeKolorado_WifeIdleFwd,
        .pos = { -1575.0f, 45.0f, -210.0f },
        .yaw = 270.0f
    },
    [NPC_Rowf] {
        .initialAnim = ANIM_Rowf_PackedWalk,
        .animList = N(ExtraAnims_Rowf),
        .pos = { -1775.0f, 0.0f, 2.0f },
        .yaw = 90.0f
    },
    [NPC_Rhuff] {
        .initialAnim = ANIM_Rowf_PackedWalk,
        .animList = N(ExtraAnims_Rowf),
        .pos = { -1740.0f, 0.0f, 2.0f },
        .yaw = 90.0f
    },
    [NPC_Moustafa] {
        .initialAnim = ANIM_Moustafa_Run,
        .animList = N(ExtraAnims_Moustafa),
        .pos = { -1240.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_Mouser1] {
        .initialAnim = ANIM_Mouser_Blue_Run,
        .animList = N(ExtraAnims_Mouser),
        .pos = { -1210.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_Mouser2] {
        .initialAnim = ANIM_Mouser_Blue_Run,
        .animList = N(ExtraAnims_Mouser),
        .pos = { -1180.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_Tutankoopa1] {
        .initialAnim = ANIM_Tutankoopa_Run,
        .animList = N(ExtraAnims_Tutankoopa),
        .pos = { -1040.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_ChainChomp1] {
        .initialAnim = ANIM_ChainChomp_QuickBite,
        .pos = { -1000.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_Buzzar] {
        .initialAnim = ANIM_Buzzar_Anim05,
        .animList = N(ExtraAnims_Buzzar),
        .pos = { -855.0f, 70.0f, -140.0f },
        .yaw = 270.0f
    },
    [NPC_VultureChick1] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -875.0f, 70.0f, -165.0f },
        .yaw = 270.0f
    },
    [NPC_VultureChick2] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -855.0f, 70.0f, -160.0f },
        .yaw = 90.0f
    },
    [NPC_VultureChick3] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -835.0f, 70.0f, -165.0f },
        .yaw = 90.0f
    },
    [NPC_Bootler] {
        .initialAnim = ANIM_Bootler_Idle,
        .pos = { -650.0f, 20.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Tutankoopa2] {
        .initialAnim = ANIM_Tutankoopa_Run,
        .animList = N(ExtraAnims_Tutankoopa),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_ChainChomp2] {
        .initialAnim = ANIM_ChainChomp_QuickBite,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_ChainChomp3] {
        .initialAnim = ANIM_ChainChomp_QuickBite,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_ChainChomp4] {
        .initialAnim = ANIM_ChainChomp_QuickBite,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_TubbasBody] {
        .initialAnim = ANIM_ParadeTubba_Still,
        .pos = { -310.0f, 35.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Boo1] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Boo2] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Boo3] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_TubbasHeart] {
        .initialAnim = ANIM_TubbasHeart_Anim01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_GoombaKing] {
        .initialAnim = ANIM_GoombaKing_Still,
        .animList = N(ExtraAnims_GoombaKing),
        .pos = { -70.0f, 130.0f, -60.0f },
        .yaw = 270.0f
    },
    [NPC_RedGoombaBros] {
        .initialAnim = ANIM_GoombaBros_Red_Walk,
        .pos = { -110.0f, 0.0f, -28.0f },
        .yaw = 90.0f
    },
    [NPC_BlueGoombaBros] {
        .initialAnim = ANIM_GoombaBros_Blue_Walk,
        .pos = { -30.0f, 0.0f, -32.0f },
        .yaw = 270.0f
    },
    [NPC_Yoshi1] {
        .initialAnim = ANIM_ParadeYoshi_IdleGreen,
        .pos = { 212.0f, 40.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_Yoshi2] {
        .initialAnim = ANIM_ParadeYoshi_IdleBlue,
        .pos = { 247.0f, 40.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_Yoshi3] {
        .initialAnim = ANIM_ParadeYoshi_IdleYellow,
        .pos = { 282.0f, 40.0f, 35.0f },
        .yaw = 90.0f
    },
    [NPC_Yoshi4] {
        .initialAnim = ANIM_ParadeYoshi_IdleBrown,
        .pos = { 272.0f, 50.0f, 25.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiChief] {
        .initialAnim = ANIM_ParadeYoshi_IdleLeader,
        .pos = { 232.0f, 50.0f, 25.0f },
        .yaw = 270.0f
    },
    [NPC_RaphaelRaven] {
        .initialAnim = ANIM_RaphaelRaven_IdleNoFeet,
        .animList = N(ExtraAnims_RaphaelRaven),
        .pos = { 357.0f, -120.0f, -30.0f },
        .yaw = 90.0f
    },
    [NPC_LavaPiranha] {
        .initialAnim = ANIM_LavaPiranha_Anim04,
        .animList = N(ExtraAnims_LavaPiranha),
        .pos = { 507.0f, 50.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiKidGreen] {
        .initialAnim = ANIM_YoshiKid_Green_Walk,
        .pos = { 570.0f, 50.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiKidBlue] {
        .initialAnim = ANIM_YoshiKid_Blue_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiKidPurple] {
        .initialAnim = ANIM_YoshiKid_Purple_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiKidYellow] {
        .initialAnim = ANIM_YoshiKid_Yellow_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_YoshiKidRed] {
        .initialAnim = ANIM_YoshiKid_Red_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_HuffNPuffBody] {
        .initialAnim = ANIM_HuffNPuff_Anim01,
        .animList = N(ExtraAnims_HuffNPuff),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HuffNPuffFace] {
        .initialAnim = ANIM_HuffNPuff_Anim02,
        .animList = N(ExtraAnims_HuffNPuff),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HuffNPuffArms] {
        .initialAnim = ANIM_HuffNPuff_Anim03,
        .animList = N(ExtraAnims_HuffNPuff),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_RuffPuff1] {
        .initialAnim = ANIM_RuffPuff_Idle,
        .animList = N(ExtraAnims_RuffPuff),
        .pos = { 980.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_RuffPuff2] {
        .initialAnim = ANIM_RuffPuff_Idle,
        .animList = N(ExtraAnims_RuffPuff),
        .pos = { 1140.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_GourmetGuy] {
        .initialAnim = ANIM_GourmetGuy_Walk,
        .animList = N(ExtraAnims_GourmetGuy),
        .pos = { 1270.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_Duplighost1] {
        .initialAnim = ANIM_Duplighost_Anim0A,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Duplighost2] {
        .initialAnim = ANIM_Duplighost_Anim0A,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_TrueCrystalKing] {
        .initialAnim = ANIM_CrystalKing_Anim0E,
        .pos = { 1440.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_FakeCrystalKing] {
        .initialAnim = ANIM_CrystalKing_Anim0E,
        .pos = { 1600.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_CrystalBit1] {
        .initialAnim = ANIM_CrystalKing_Anim0A,
        .pos = { 2000.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_CrystalBit2] {
        .initialAnim = ANIM_CrystalKing_Anim0B,
        .pos = { 2050.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_CrystalBit3] {
        .initialAnim = ANIM_CrystalKing_Anim0C,
        .pos = { 2100.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Kammy] {
        .initialAnim = ANIM_WorldKammy_Anim14,
        .animList = N(ExtraAnims_Kammy),
        .pos = { 2160.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_JrTroopa] {
        .initialAnim = ANIM_MageJrTroopa_RaiseStaff,
        .animList = N(ExtraAnims_MageJrTroopa),
        .pos = { 2060.0f, 0.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_Bowser] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_Bowser,
        .pos = { 2390.0f, 10.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_BowserPropeller] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_Propeller,
        .pos = { 2390.0f, 10.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HammerBros1] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_HammerBrosJuggle,
        .pos = { 2300.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_HammerBros2] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_HammerBrosJuggle,
        .pos = { 2260.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Koopatrol1] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_KoopatrolMarch,
        .pos = { 2480.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_Koopatrol2] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_KoopatrolMarch,
        .pos = { 2520.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_BurntBowser] {
        .initialAnim = ANIM_ParadeBurntBowser_BurntIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_BurntBowserPropeller] {
        .initialAnim = ANIM_ParadeBurntBowser_BurntPropeller,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
};

EvtScript N(EVS_ManageNpcPool) = {
    Call(N(CreateParadeNPC), NPC_Luigi)
    Call(N(ParadeSpriteHeapMalloc), 0x25000, LVar0)
    Call(N(CreateParadeNPC), NPC_HornPlayer1)
    Call(N(CreateParadeNPC), NPC_HornPlayer2)
    Call(N(CreateParadeNPC), NPC_Drummer1)
    Call(N(CreateParadeNPC), NPC_Drummer2)
    Call(N(CreateParadeNPC), NPC_StandardBearer1)
    Call(N(CreateParadeNPC), NPC_StandardBearer2)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_PARTNERS)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Luigi)
    Call(N(CreateParadeNPC), NPC_Goombario)
    Call(N(CreateParadeNPC), NPC_Kooper)
    Call(N(CreateParadeNPC), NPC_Bombette)
    Call(N(CreateParadeNPC), NPC_Parakarry)
    Call(N(CreateParadeNPC), NPC_Bow)
    Call(N(CreateParadeNPC), NPC_Watt)
    Call(N(CreateParadeNPC), NPC_Sushie)
    Call(N(CreateParadeNPC), NPC_Lakilester)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_HornPlayer1)
    Call(DeleteNpc, NPC_HornPlayer2)
    Call(DeleteNpc, NPC_Drummer1)
    Call(DeleteNpc, NPC_Drummer2)
    Call(DeleteNpc, NPC_StandardBearer1)
    Call(DeleteNpc, NPC_StandardBearer2)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x25000, LVar0)
    Call(N(CreateParadeNPC), NPC_Twirler1)
    Call(N(CreateParadeNPC), NPC_Twirler2)
    Call(N(CreateParadeNPC), NPC_Twirler3)
    Call(N(CreateParadeNPC), NPC_Baton1)
    Call(N(CreateParadeNPC), NPC_Baton2)
    Call(N(CreateParadeNPC), NPC_Baton3)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Wait(60)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN + 250)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Goombario)
    Call(DeleteNpc, NPC_Kooper)
    Call(DeleteNpc, NPC_Bombette)
    Call(DeleteNpc, NPC_Parakarry)
    Call(DeleteNpc, NPC_Bow)
    Call(DeleteNpc, NPC_Watt)
    Call(DeleteNpc, NPC_Sushie)
    Call(DeleteNpc, NPC_Lakilester)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_ChuckQuizmo)
    Call(N(CreateParadeNPC), NPC_VannaT)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOLORADO + 20)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Twirler1)
    Call(DeleteNpc, NPC_Twirler2)
    Call(DeleteNpc, NPC_Twirler3)
    Call(DeleteNpc, NPC_Baton1)
    Call(DeleteNpc, NPC_Baton2)
    Call(DeleteNpc, NPC_Baton3)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0xB000, LVar0)
    Call(N(CreateParadeNPC), NPC_KoopaBrosRed)
    Call(N(CreateParadeNPC), NPC_KoopaBrosBlack)
    Call(N(CreateParadeNPC), NPC_KoopaBrosYellow)
    Call(N(CreateParadeNPC), NPC_KoopaBrosGreen)
    Call(N(CreateParadeNPC), NPC_Bobomb1)
    Call(N(CreateParadeNPC), NPC_Bobomb2)
    Call(N(CreateParadeNPC), NPC_Bobomb3)
    Call(N(CreateParadeNPC), NPC_Bobomb4)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOLORADO + 200)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_ChuckQuizmo)
    Call(DeleteNpc, NPC_VannaT)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Kolorado)
    Call(N(CreateParadeNPC), NPC_KoloradoWife)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CARAVAN)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_KoopaBrosRed)
    Call(DeleteNpc, NPC_KoopaBrosBlack)
    Call(DeleteNpc, NPC_KoopaBrosYellow)
    Call(DeleteNpc, NPC_KoopaBrosGreen)
    Call(DeleteNpc, NPC_Bobomb1)
    Call(DeleteNpc, NPC_Bobomb2)
    Call(DeleteNpc, NPC_Bobomb3)
    Call(DeleteNpc, NPC_Bobomb4)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x19F00, LVar0)
    Call(N(CreateParadeNPC), NPC_Tutankoopa1)
    Call(N(CreateParadeNPC), NPC_Rowf)
    Call(N(CreateParadeNPC), NPC_Rhuff)
    Call(N(CreateParadeNPC), NPC_Moustafa)
    Call(N(CreateParadeNPC), NPC_Mouser1)
    Call(N(CreateParadeNPC), NPC_Mouser2)
    Call(N(CreateParadeNPC), NPC_ChainChomp1)
    Call(N(ParadeSpriteHeapMalloc), 0x7000, LVarF)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BUZZAR + 175)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Kolorado)
    Call(DeleteNpc, NPC_KoloradoWife)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Buzzar)
    Call(N(CreateParadeNPC), NPC_VultureChick1)
    Call(N(CreateParadeNPC), NPC_VultureChick2)
    Call(N(CreateParadeNPC), NPC_VultureChick3)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOOS)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Tutankoopa1)
    Call(DeleteNpc, NPC_Rowf)
    Call(DeleteNpc, NPC_Rhuff)
    Call(DeleteNpc, NPC_Moustafa)
    Call(DeleteNpc, NPC_Mouser1)
    Call(DeleteNpc, NPC_Mouser2)
    Call(DeleteNpc, NPC_ChainChomp1)
    Call(N(ParadeSpriteHeapFree), LVarF)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x11F00, LVar0)
    Call(N(CreateParadeNPC), NPC_Tutankoopa2)
    Call(N(CreateParadeNPC), NPC_ChainChomp2)
    Call(N(CreateParadeNPC), NPC_ChainChomp3)
    Call(N(CreateParadeNPC), NPC_ChainChomp4)
    Call(N(CreateParadeNPC), NPC_Bootler)
    Call(N(ParadeSpriteHeapMalloc), 0xA000, LVarF)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOOS + 420)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Buzzar)
    Call(DeleteNpc, NPC_VultureChick1)
    Call(DeleteNpc, NPC_VultureChick2)
    Call(DeleteNpc, NPC_VultureChick3)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_TubbasHeart)
    Call(N(CreateParadeNPC), NPC_Boo1)
    Call(N(CreateParadeNPC), NPC_Boo2)
    Call(N(CreateParadeNPC), NPC_Boo3)
    Call(N(CreateParadeNPC), NPC_TubbasBody)
    Call(N(SetNpcShadowScale), NPC_TubbasBody, Float(4.0))
    Call(SetNpcFlagBits, NPC_TubbasBody, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_GOOMBA_KING)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Bootler)
    Call(DeleteNpc, NPC_Tutankoopa2)
    Call(DeleteNpc, NPC_ChainChomp2)
    Call(DeleteNpc, NPC_ChainChomp3)
    Call(DeleteNpc, NPC_ChainChomp4)
    Call(N(ParadeSpriteHeapFree), LVarF)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0xF000, LVar0)
    Call(N(CreateParadeNPC), NPC_GoombaKing)
    Call(N(CreateParadeNPC), NPC_RedGoombaBros)
    Call(N(CreateParadeNPC), NPC_BlueGoombaBros)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Call(N(SetNpcShadowScale), NPC_GoombaKing, Float(3.0))
    Call(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_YOSHIS)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_TubbasBody)
    Call(DeleteNpc, NPC_Boo1)
    Call(DeleteNpc, NPC_Boo2)
    Call(DeleteNpc, NPC_Boo3)
    Call(DeleteNpc, NPC_TubbasHeart)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_RaphaelRaven)
    Call(N(CreateParadeNPC), NPC_LavaPiranha)
    Call(N(CreateParadeNPC), NPC_Yoshi1)
    Call(N(CreateParadeNPC), NPC_Yoshi2)
    Call(N(CreateParadeNPC), NPC_Yoshi3)
    Call(N(CreateParadeNPC), NPC_Yoshi4)
    Call(N(CreateParadeNPC), NPC_YoshiChief)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_HUFF_PUFF)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_GoombaKing)
    Call(DeleteNpc, NPC_RedGoombaBros)
    Call(DeleteNpc, NPC_BlueGoombaBros)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x20000, LVar0)
    Call(N(CreateParadeNPC), NPC_YoshiKidGreen)
    Call(N(CreateParadeNPC), NPC_YoshiKidBlue)
    Call(N(CreateParadeNPC), NPC_YoshiKidPurple)
    Call(N(CreateParadeNPC), NPC_YoshiKidYellow)
    Call(N(CreateParadeNPC), NPC_YoshiKidRed)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_HUFF_PUFF + 50)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Yoshi1)
    Call(DeleteNpc, NPC_Yoshi2)
    Call(DeleteNpc, NPC_Yoshi3)
    Call(DeleteNpc, NPC_Yoshi4)
    Call(DeleteNpc, NPC_YoshiChief)
    Call(DeleteNpc, NPC_RaphaelRaven)
    Call(DeleteNpc, NPC_LavaPiranha)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_HuffNPuffBody)
    Call(N(CreateParadeNPC), NPC_HuffNPuffFace)
    Call(N(CreateParadeNPC), NPC_HuffNPuffArms)
    Call(N(CreateParadeNPC), NPC_GourmetGuy)
    Call(N(CreateParadeNPC), NPC_RuffPuff1)
    Call(N(CreateParadeNPC), NPC_RuffPuff2)
    Call(N(SetNpcShadowScale), 69, Float(6.0))
    Call(SetNpcFlagBits, NPC_HuffNPuffBody, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Call(N(SetNpcShadowScale), 74, Float(3.0))
    Call(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CRYSTAL_KING)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_YoshiKidGreen)
    Call(DeleteNpc, NPC_YoshiKidBlue)
    Call(DeleteNpc, NPC_YoshiKidPurple)
    Call(DeleteNpc, NPC_YoshiKidYellow)
    Call(DeleteNpc, NPC_YoshiKidRed)
    Wait(1)
    Call(N(ParadeSpriteHeapMalloc), 0x2000, LVar0)
    Call(N(CreateParadeNPC), NPC_TrueCrystalKing)
    Call(N(CreateParadeNPC), NPC_FakeCrystalKing)
    Call(N(CreateParadeNPC), NPC_CrystalBit1)
    Call(N(CreateParadeNPC), NPC_CrystalBit2)
    Call(N(CreateParadeNPC), NPC_CrystalBit3)
    Call(N(ParadeSpriteHeapFree), LVar0)
    Call(N(SetNpcShadowScale), NPC_TrueCrystalKing, Float(2.0))
    Call(SetNpcFlagBits, NPC_TrueCrystalKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Call(N(SetNpcShadowScale), NPC_FakeCrystalKing, Float(2.0))
    Call(SetNpcFlagBits, NPC_FakeCrystalKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CRYSTAL_KING + 150)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_HuffNPuffBody)
    Call(DeleteNpc, NPC_HuffNPuffFace)
    Call(DeleteNpc, NPC_HuffNPuffArms)
    Call(DeleteNpc, NPC_GourmetGuy)
    Call(DeleteNpc, NPC_RuffPuff1)
    Call(DeleteNpc, NPC_RuffPuff2)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Duplighost1)
    Call(N(CreateParadeNPC), NPC_Duplighost2)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOWSER)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_TrueCrystalKing)
    Call(DeleteNpc, NPC_FakeCrystalKing)
    Call(DeleteNpc, NPC_CrystalBit1)
    Call(DeleteNpc, NPC_CrystalBit2)
    Call(DeleteNpc, NPC_CrystalBit3)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_JrTroopa)
    Call(N(CreateParadeNPC), NPC_Kammy)
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOWSER + 100)
            BreakLoop
        EndIf
    EndLoop
    Call(DeleteNpc, NPC_Duplighost1)
    Call(DeleteNpc, NPC_Duplighost2)
    Wait(1)
    Call(N(CreateParadeNPC), NPC_Bowser)
    Call(N(CreateParadeNPC), NPC_BowserPropeller)
    Call(N(CreateParadeNPC), NPC_HammerBros1)
    Call(N(CreateParadeNPC), NPC_HammerBros2)
    Call(N(CreateParadeNPC), NPC_Koopatrol1)
    Call(N(CreateParadeNPC), NPC_Koopatrol2)
    Call(N(CreateParadeNPC), NPC_BurntBowser)
    Call(N(CreateParadeNPC), NPC_BurntBowserPropeller)
    Call(N(SetNpcShadowScale), NPC_Bowser, Float(3.0))
    Call(SetNpcFlagBits, NPC_Bowser, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Call(N(SetNpcShadowScale), NPC_BurntBowser, Float(3.0))
    Call(SetNpcFlagBits, NPC_BurntBowser, NPC_FLAG_DIRTY_SHADOW, TRUE)
    Call(EnableNpcShadow, NPC_BowserPropeller, FALSE)
    Call(EnableNpcShadow, NPC_BurntBowserPropeller, FALSE)
    Return
    End
};

EvtScript N(EVS_ParadePhase_PlayCredits) = {
#if VERSION_PAL
    Wait(180 * DT)
#else
    Wait(240)
#endif
    Exec(N(EVS_InitCredits))
    Exec(N(EVS_ShowCredits_Title))
    Exec(N(EVS_ShowCredits_Jobs))
    Exec(N(EVS_ShowCredits_Names))
    Return
    End
};

EvtScript N(EVS_ManageParade) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Thread
        Label(0)
        Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
        Wait(1)
        Goto(0)
    EndThread
    Exec(N(EVS_TexPan_Clouds))
    Exec(N(EVS_TexPan_Water))
    Exec(N(EVS_SetupInitialCamera))
    Exec(N(EVS_ManageNpcPool))
    ExecGetTID(N(EVS_ParadePhase_Luigi), LVarA)
    Loop(0)
        Wait(1)
        IsThreadRunning(LVarA, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_PlayCredits))
    Exec(N(EVS_UpdateScrollPos))
    Exec(N(EVS_UpdateTexPan_Ground))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_PARTNERS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Partners))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TOAD_TOWN)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Toads))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOOPA_BROS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_KoopaBros))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_KOLORADO)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Kolorado))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CARAVAN)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Caravan))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BUZZAR)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_BuzzarNest))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_TUTANKOOPA)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Tutankoopa))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOOS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Boos))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_GOOMBA_KING)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_GoombaKing))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_YOSHIS)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Yoshis))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_HUFF_PUFF)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_HuffNPuff))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_CRYSTAL_KING)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_CrystalKing))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_BOWSER)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_ParadePhase_Bowser))
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_DONE)
            BreakLoop
        EndIf
    EndLoop
    Call(GotoMap, Ref("end_01"), end_01_ENTRY_0)
    Call(FadeOutMusic, 0, 500)
    Wait(100)
    Return
    End
};
