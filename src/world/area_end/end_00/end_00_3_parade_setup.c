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

EvtScript N(EVS_SetNpcShadowScale) = {
    EVT_CALL(N(SetNpcShadowScale), LVar0, LVar2)
    EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OffsetNpcScroll) = {
    EVT_CALL(N(AddScrollToNpcPos), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTexPan_Ground) = {
    EVT_CALL(EnableTexPanning, MODEL_j1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j4, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j6, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j7, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j9, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j10, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j11, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j12, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j13, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j14, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j15, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j16, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j17, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j18, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j19, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j20, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j21, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j22, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j23, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j24, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j25, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j26, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_j27, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LOOP(0)
            EVT_ADD(LVar0, 300)
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

EvtScript N(EVS_TexPan_Clouds) = {
    EVT_CALL(EnableTexPanning, MODEL_cloud, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x8000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Water) = {
    EVT_CALL(EnableTexPanning, MODEL_umi, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 50)
        EVT_ADD(LVar1, 50)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_ADD(LVar2, -50)
        EVT_ADD(LVar3, -50)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_AUX, LVar2, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_CALL(N(CreateParadeNPC), NPC_Luigi)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x25000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_HornPlayer1)
    EVT_CALL(N(CreateParadeNPC), NPC_HornPlayer2)
    EVT_CALL(N(CreateParadeNPC), NPC_Drummer1)
    EVT_CALL(N(CreateParadeNPC), NPC_Drummer2)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer1)
    EVT_CALL(N(CreateParadeNPC), NPC_StandardBearer2)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_PARTNERS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Luigi)
    EVT_CALL(N(CreateParadeNPC), NPC_Goombario)
    EVT_CALL(N(CreateParadeNPC), NPC_Kooper)
    EVT_CALL(N(CreateParadeNPC), NPC_Bombette)
    EVT_CALL(N(CreateParadeNPC), NPC_Parakarry)
    EVT_CALL(N(CreateParadeNPC), NPC_Bow)
    EVT_CALL(N(CreateParadeNPC), NPC_Watt)
    EVT_CALL(N(CreateParadeNPC), NPC_Sushie)
    EVT_CALL(N(CreateParadeNPC), NPC_Lakilester)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_HornPlayer1)
    EVT_CALL(DeleteNpc, NPC_HornPlayer2)
    EVT_CALL(DeleteNpc, NPC_Drummer1)
    EVT_CALL(DeleteNpc, NPC_Drummer2)
    EVT_CALL(DeleteNpc, NPC_StandardBearer1)
    EVT_CALL(DeleteNpc, NPC_StandardBearer2)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x25000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler1)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler2)
    EVT_CALL(N(CreateParadeNPC), NPC_Twirler3)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton1)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton2)
    EVT_CALL(N(CreateParadeNPC), NPC_Baton3)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_WAIT(60)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN + 250)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Goombario)
    EVT_CALL(DeleteNpc, NPC_Kooper)
    EVT_CALL(DeleteNpc, NPC_Bombette)
    EVT_CALL(DeleteNpc, NPC_Parakarry)
    EVT_CALL(DeleteNpc, NPC_Bow)
    EVT_CALL(DeleteNpc, NPC_Watt)
    EVT_CALL(DeleteNpc, NPC_Sushie)
    EVT_CALL(DeleteNpc, NPC_Lakilester)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_ChuckQuizmo)
    EVT_CALL(N(CreateParadeNPC), NPC_VannaT)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOLORADO + 20)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Twirler1)
    EVT_CALL(DeleteNpc, NPC_Twirler2)
    EVT_CALL(DeleteNpc, NPC_Twirler3)
    EVT_CALL(DeleteNpc, NPC_Baton1)
    EVT_CALL(DeleteNpc, NPC_Baton2)
    EVT_CALL(DeleteNpc, NPC_Baton3)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0xB000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_KoopaBrosRed)
    EVT_CALL(N(CreateParadeNPC), NPC_KoopaBrosBlack)
    EVT_CALL(N(CreateParadeNPC), NPC_KoopaBrosYellow)
    EVT_CALL(N(CreateParadeNPC), NPC_KoopaBrosGreen)
    EVT_CALL(N(CreateParadeNPC), NPC_Bobomb1)
    EVT_CALL(N(CreateParadeNPC), NPC_Bobomb2)
    EVT_CALL(N(CreateParadeNPC), NPC_Bobomb3)
    EVT_CALL(N(CreateParadeNPC), NPC_Bobomb4)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOLORADO + 200)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_ChuckQuizmo)
    EVT_CALL(DeleteNpc, NPC_VannaT)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Kolorado)
    EVT_CALL(N(CreateParadeNPC), NPC_KoloradoWife)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CARAVAN)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_KoopaBrosRed)
    EVT_CALL(DeleteNpc, NPC_KoopaBrosBlack)
    EVT_CALL(DeleteNpc, NPC_KoopaBrosYellow)
    EVT_CALL(DeleteNpc, NPC_KoopaBrosGreen)
    EVT_CALL(DeleteNpc, NPC_Bobomb1)
    EVT_CALL(DeleteNpc, NPC_Bobomb2)
    EVT_CALL(DeleteNpc, NPC_Bobomb3)
    EVT_CALL(DeleteNpc, NPC_Bobomb4)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x19F00, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_Tutankoopa1)
    EVT_CALL(N(CreateParadeNPC), NPC_Rowf)
    EVT_CALL(N(CreateParadeNPC), NPC_Rhuff)
    EVT_CALL(N(CreateParadeNPC), NPC_Moustafa)
    EVT_CALL(N(CreateParadeNPC), NPC_Mouser1)
    EVT_CALL(N(CreateParadeNPC), NPC_Mouser2)
    EVT_CALL(N(CreateParadeNPC), NPC_ChainChomp1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x7000, LVarF)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BUZZAR + 175)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Kolorado)
    EVT_CALL(DeleteNpc, NPC_KoloradoWife)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Buzzar)
    EVT_CALL(N(CreateParadeNPC), NPC_VultureChick1)
    EVT_CALL(N(CreateParadeNPC), NPC_VultureChick2)
    EVT_CALL(N(CreateParadeNPC), NPC_VultureChick3)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOOS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Tutankoopa1)
    EVT_CALL(DeleteNpc, NPC_Rowf)
    EVT_CALL(DeleteNpc, NPC_Rhuff)
    EVT_CALL(DeleteNpc, NPC_Moustafa)
    EVT_CALL(DeleteNpc, NPC_Mouser1)
    EVT_CALL(DeleteNpc, NPC_Mouser2)
    EVT_CALL(DeleteNpc, NPC_ChainChomp1)
    EVT_CALL(N(ParadeSpriteHeapFree), LVarF)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x11F00, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_Tutankoopa2)
    EVT_CALL(N(CreateParadeNPC), NPC_ChainChomp2)
    EVT_CALL(N(CreateParadeNPC), NPC_ChainChomp3)
    EVT_CALL(N(CreateParadeNPC), NPC_ChainChomp4)
    EVT_CALL(N(CreateParadeNPC), NPC_Bootler)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0xA000, LVarF)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOOS + 420)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Buzzar)
    EVT_CALL(DeleteNpc, NPC_VultureChick1)
    EVT_CALL(DeleteNpc, NPC_VultureChick2)
    EVT_CALL(DeleteNpc, NPC_VultureChick3)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_TubbasHeart)
    EVT_CALL(N(CreateParadeNPC), NPC_Boo1)
    EVT_CALL(N(CreateParadeNPC), NPC_Boo2)
    EVT_CALL(N(CreateParadeNPC), NPC_Boo3)
    EVT_CALL(N(CreateParadeNPC), NPC_TubbasBody)
    EVT_CALL(N(SetNpcShadowScale), NPC_TubbasBody, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcFlagBits, NPC_TubbasBody, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_GOOMBA_KING)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Bootler)
    EVT_CALL(DeleteNpc, NPC_Tutankoopa2)
    EVT_CALL(DeleteNpc, NPC_ChainChomp2)
    EVT_CALL(DeleteNpc, NPC_ChainChomp3)
    EVT_CALL(DeleteNpc, NPC_ChainChomp4)
    EVT_CALL(N(ParadeSpriteHeapFree), LVarF)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0xF000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_GoombaKing)
    EVT_CALL(N(CreateParadeNPC), NPC_RedGoombaBros)
    EVT_CALL(N(CreateParadeNPC), NPC_BlueGoombaBros)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_CALL(N(SetNpcShadowScale), NPC_GoombaKing, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_GoombaKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_YOSHIS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_TubbasBody)
    EVT_CALL(DeleteNpc, NPC_Boo1)
    EVT_CALL(DeleteNpc, NPC_Boo2)
    EVT_CALL(DeleteNpc, NPC_Boo3)
    EVT_CALL(DeleteNpc, NPC_TubbasHeart)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_RaphaelRaven)
    EVT_CALL(N(CreateParadeNPC), NPC_LavaPiranha)
    EVT_CALL(N(CreateParadeNPC), NPC_Yoshi1)
    EVT_CALL(N(CreateParadeNPC), NPC_Yoshi2)
    EVT_CALL(N(CreateParadeNPC), NPC_Yoshi3)
    EVT_CALL(N(CreateParadeNPC), NPC_Yoshi4)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiChief)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_GoombaKing)
    EVT_CALL(DeleteNpc, NPC_RedGoombaBros)
    EVT_CALL(DeleteNpc, NPC_BlueGoombaBros)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x20000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiKidGreen)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiKidBlue)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiKidPurple)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiKidYellow)
    EVT_CALL(N(CreateParadeNPC), NPC_YoshiKidRed)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 50)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Yoshi1)
    EVT_CALL(DeleteNpc, NPC_Yoshi2)
    EVT_CALL(DeleteNpc, NPC_Yoshi3)
    EVT_CALL(DeleteNpc, NPC_Yoshi4)
    EVT_CALL(DeleteNpc, NPC_YoshiChief)
    EVT_CALL(DeleteNpc, NPC_RaphaelRaven)
    EVT_CALL(DeleteNpc, NPC_LavaPiranha)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_HuffNPuffBody)
    EVT_CALL(N(CreateParadeNPC), NPC_HuffNPuffFace)
    EVT_CALL(N(CreateParadeNPC), NPC_HuffNPuffArms)
    EVT_CALL(N(CreateParadeNPC), NPC_GourmetGuy)
    EVT_CALL(N(CreateParadeNPC), NPC_RuffPuff1)
    EVT_CALL(N(CreateParadeNPC), NPC_RuffPuff2)
    EVT_CALL(N(SetNpcShadowScale), 69, EVT_FLOAT(6.0))
    EVT_CALL(SetNpcFlagBits, NPC_HuffNPuffBody, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), 74, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_GourmetGuy, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CRYSTAL_KING)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_YoshiKidGreen)
    EVT_CALL(DeleteNpc, NPC_YoshiKidBlue)
    EVT_CALL(DeleteNpc, NPC_YoshiKidPurple)
    EVT_CALL(DeleteNpc, NPC_YoshiKidYellow)
    EVT_CALL(DeleteNpc, NPC_YoshiKidRed)
    EVT_WAIT(1)
    EVT_CALL(N(ParadeSpriteHeapMalloc), 0x2000, LVar0)
    EVT_CALL(N(CreateParadeNPC), NPC_TrueCrystalKing)
    EVT_CALL(N(CreateParadeNPC), NPC_FakeCrystalKing)
    EVT_CALL(N(CreateParadeNPC), NPC_CrystalBit1)
    EVT_CALL(N(CreateParadeNPC), NPC_CrystalBit2)
    EVT_CALL(N(CreateParadeNPC), NPC_CrystalBit3)
    EVT_CALL(N(ParadeSpriteHeapFree), LVar0)
    EVT_CALL(N(SetNpcShadowScale), NPC_TrueCrystalKing, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcFlagBits, NPC_TrueCrystalKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), NPC_FakeCrystalKing, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcFlagBits, NPC_FakeCrystalKing, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CRYSTAL_KING + 150)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_HuffNPuffBody)
    EVT_CALL(DeleteNpc, NPC_HuffNPuffFace)
    EVT_CALL(DeleteNpc, NPC_HuffNPuffArms)
    EVT_CALL(DeleteNpc, NPC_GourmetGuy)
    EVT_CALL(DeleteNpc, NPC_RuffPuff1)
    EVT_CALL(DeleteNpc, NPC_RuffPuff2)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Duplighost1)
    EVT_CALL(N(CreateParadeNPC), NPC_Duplighost2)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOWSER)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_TrueCrystalKing)
    EVT_CALL(DeleteNpc, NPC_FakeCrystalKing)
    EVT_CALL(DeleteNpc, NPC_CrystalBit1)
    EVT_CALL(DeleteNpc, NPC_CrystalBit2)
    EVT_CALL(DeleteNpc, NPC_CrystalBit3)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_JrTroopa)
    EVT_CALL(N(CreateParadeNPC), NPC_Kammy)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOWSER + 100)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_Duplighost1)
    EVT_CALL(DeleteNpc, NPC_Duplighost2)
    EVT_WAIT(1)
    EVT_CALL(N(CreateParadeNPC), NPC_Bowser)
    EVT_CALL(N(CreateParadeNPC), NPC_BowserPropeller)
    EVT_CALL(N(CreateParadeNPC), NPC_HammerBros1)
    EVT_CALL(N(CreateParadeNPC), NPC_HammerBros2)
    EVT_CALL(N(CreateParadeNPC), NPC_Koopatrol1)
    EVT_CALL(N(CreateParadeNPC), NPC_Koopatrol2)
    EVT_CALL(N(CreateParadeNPC), NPC_BurntBowser)
    EVT_CALL(N(CreateParadeNPC), NPC_BurntBowserPropeller)
    EVT_CALL(N(SetNpcShadowScale), NPC_Bowser, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_Bowser, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), NPC_BurntBowser, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_BurntBowser, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_BowserPropeller, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_BurntBowserPropeller, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_PlayCredits) = {
#if VERSION_PAL
    EVT_WAIT(180 * DT)
#else
    EVT_WAIT(240)
#endif
    EVT_EXEC(N(EVS_InitCredits))
    EVT_EXEC(N(EVS_ShowCredits_Title))
    EVT_EXEC(N(EVS_ShowCredits_Jobs))
    EVT_EXEC(N(EVS_ShowCredits_Names))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageParade) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_TexPan_Clouds))
    EVT_EXEC(N(EVS_TexPan_Water))
    EVT_EXEC(N(EVS_SetupInitialCamera))
    EVT_EXEC(N(EVS_ManageNpcPool))
    EVT_EXEC_GET_TID(N(EVS_ParadePhase_Luigi), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_PlayCredits))
    EVT_EXEC(N(EVS_UpdateScrollPos))
    EVT_EXEC(N(EVS_UpdateTexPan_Ground))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_PARTNERS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Partners))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Toads))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOOPA_BROS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_KoopaBros))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_KOLORADO)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Kolorado))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CARAVAN)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Caravan))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BUZZAR)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_BuzzarNest))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TUTANKOOPA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Tutankoopa))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOOS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Boos))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_GOOMBA_KING)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_GoombaKing))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_YOSHIS)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Yoshis))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_HuffNPuff))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CRYSTAL_KING)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_CrystalKing))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_BOWSER)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_Bowser))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_DONE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMap, EVT_PTR("end_01"), end_01_ENTRY_0)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
