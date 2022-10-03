#include "end_00.h"
#include "effects.h"

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern ParadeNpcInfo N(ParadeNpcsTable)[];

extern EvtScript N(D_80247230_DFDC30);
extern EvtScript N(D_80247418_DFDE18);
extern EvtScript N(D_802479C4_DFE3C4);
extern EvtScript N(EVS_80248928);
extern EvtScript N(EVS_80248BAC);
extern EvtScript N(EVS_80249040);
extern EvtScript N(EVS_80249A38);
extern EvtScript N(EVS_80249EA4);
extern EvtScript N(EVS_8024A044);
extern EvtScript N(EVS_8024A804);
extern EvtScript N(EVS_8024AD30);
extern EvtScript N(EVS_8024C38C);
extern EvtScript N(EVS_8024CC78);
extern EvtScript N(EVS_8024D834);

extern EvtScript N(EVS_InitCredits);
extern EvtScript N(EVS_ShowCredits_Title);
extern EvtScript N(EVS_ShowCredits_Jobs);
extern EvtScript N(EVS_ShowCredits_Names);

API_CALLABLE(N(func_80242680_DF9080)) {
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

API_CALLABLE(N(func_80242744_DF9144)) {
    Bytecode* args = script->ptrReadPos;
    s32 heapSize = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, (s32) _heap_malloc(&gSpriteHeapPtr, heapSize));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802427A4_DF91A4)) {
    Bytecode* args = script->ptrReadPos;
    s32 pointer = *args++;

    _heap_free(&gSpriteHeapPtr, (void*) evt_get_variable(script, pointer));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802427D8_DF91D8)) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->panActive = TRUE;
    camera->movePos.x += PARADE_SCROLL_RATE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetNpcShadowScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    f32 newShadowScale = evt_get_float_variable(script, *args++);

    resolve_npc(script, npcID)->shadowScale = newShadowScale;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80242898_DF9298)) {
    Bytecode* args = script->ptrReadPos;
    Npc** npc = (Npc**)&script->functionTempPtr[1];

    if (isInitialCall) {
        *npc = get_npc_unsafe(evt_get_variable(script, *args++));
    }

    (*npc)->pos.x += PARADE_SCROLL_RATE;

    return ApiStatus_BLOCK;
}

EvtScript N(D_802446B0_DFB0B0) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -3080, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -3080, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244724_DFB124) = {
    EVT_CALL(SetPanTarget, CAM_DEFAULT, EVT_FLOAT(-3080.0), 0, 0)
    EVT_SETF(LVar1, EVT_FLOAT(0.0))
    EVT_LOOP(0)
        EVT_CALL(N(func_802427D8_DF91D8))
        EVT_CALL(TranslateGroup, MODEL_bg, LVar1, 0, 0)
        EVT_ADDF(LVar1, EVT_FLOAT(0.6669922))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802447B8) = {
    EVT_CALL(N(SetNpcShadowScale), LVar0, LVar2)
    EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_802447F4) = {
    EVT_CALL(N(func_80242898_DF9298), LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244814_DFB214) = {
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
            EVT_IF_GT(LVar0, 0x00020000)
                EVT_ADD(LVar0, 0xFFFE0000)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244AE4_DFB4E4) = {
    EVT_CALL(EnableTexPanning, MODEL_cloud, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x00008000)
        EVT_CALL(SetTexPanOffset, 2, 0, 0, LVar0)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80244B64_DFB564) = {
    EVT_CALL(EnableTexPanning, MODEL_umi, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 50)
        EVT_ADD(LVar1, 50)
        EVT_CALL(SetTexPanOffset, 3, 0, LVar0, LVar1)
        EVT_ADD(LVar2, -50)
        EVT_ADD(LVar3, -50)
        EVT_CALL(SetTexPanOffset, 3, 1, LVar2, LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_80244C60_DFB660)[] = {
    ANIM_Tutankoopa_Anim02,
    ANIM_Tutankoopa_Anim06,
    ANIM_Tutankoopa_Anim09,
    ANIM_Tutankoopa_Anim01,
    ANIM_Tutankoopa_Anim04,
    -1
};

s32 N(D_80244C78_DFB678)[] = {
    ANIM_Rowf_PackedStill,
    ANIM_Rowf_PackedIdle,
    ANIM_Rowf_PackedWalk,
    ANIM_Rowf_PackedRun,
    ANIM_Rowf_PackedTalk,
    ANIM_Rowf_PackedCheer,
    -1
};

s32 N(D_80244C94_DFB694)[] = {
    ANIM_Moustafa_Run,
    ANIM_Moustafa_Shout,
    ANIM_Moustafa_Talk,
    ANIM_Moustafa_Toss,
    ANIM_Moustafa_Idle,
    -1
};

s32 N(D_80244CAC_DFB6AC)[] = {
    ANIM_Mouser_Blue_Run,
    ANIM_Mouser_Blue_IdleOnlyBlink,
    ANIM_Mouser_Blue_Whisper,
    -1
};

s32 N(D_80244CBC_DFB6BC)[] = {
    ANIM_Buzzar_Anim05,
    ANIM_Buzzar_Anim03,
    -1
};

s32 N(D_80244CC8_DFB6C8)[] = {
    ANIM_GoombaKing_Still,
    ANIM_GoombaKing_Dead,
    ANIM_GoombaKing_Angry,
    -1
};

s32 N(D_80244CD8_DFB6D8)[] = {
    ANIM_RafaelRaven_IdleNoFeet,
    -1
};

s32 N(D_80244CE0_DFB6E0)[] = {
    ANIM_LavaPiranha_Anim04,
    -1
};

s32 N(D_80244CE8_DFB6E8)[] = {
    ANIM_HuffNPuff_Anim01,
    ANIM_HuffNPuff_Anim02,
    ANIM_HuffNPuff_Anim03,
    ANIM_HuffNPuff_Anim07,
    ANIM_HuffNPuff_Anim08,
    ANIM_HuffNPuff_Anim09,
    ANIM_HuffNPuff_Anim26,
    ANIM_HuffNPuff_Anim27,
    ANIM_HuffNPuff_Anim28,
    -1
};

s32 N(D_80244D10_DFB710)[] = {
    ANIM_TuffPuff_Idle,
    ANIM_TuffPuff_Hurt,
    ANIM_TuffPuff_Blush,
    -1
};

s32 N(D_80244D20_DFB720)[] = {
    ANIM_GourmetGuy_Walk,
    ANIM_GourmetGuy_Leap,
    ANIM_GourmetGuy_TalkSurprise,
    ANIM_GourmetGuy_Still,
    ANIM_GourmetGuy_Idle,
    ANIM_GourmetGuy_Inspect,
    ANIM_GourmetGuy_Panic,
    -1
};

s32 N(D_80244D40_DFB740)[] = {
    ANIM_MageJrTroopa_Idle,
    ANIM_MageJrTroopa_Run,
    ANIM_MageJrTroopa_RaiseStaff,
    ANIM_MageJrTroopa_SwingStaff,
    ANIM_MageJrTroopa_BurnStill,
    -1
};

s32 N(D_80244D58_DFB758)[] = {
    ANIM_WorldKammy_Anim14,
    ANIM_WorldKammy_Anim0C,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim12,
    ANIM_WorldKammy_Anim07,
    -1
};

ParadeNpcInfo N(ParadeNpcsTable)[] = {
    [NPC_00] {
        .initialAnim = ANIM_ParadeLuigi_March,
        .pos = { -2880.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_01] {
        .initialAnim = ANIM_ParadeToad_Red_HornWalk,
        .pos = { -2880.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_02] {
        .initialAnim = ANIM_ParadeToad_Red_HornWalk,
        .pos = { -2880.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_03] {
        .initialAnim = ANIM_ParadeToad_Red_DrummerWalk,
        .pos = { -2830.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_04] {
        .initialAnim = ANIM_ParadeToad_Red_DrummerWalk,
        .pos = { -2830.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_05] {
        .initialAnim = ANIM_ParadeToad_Red_BannerWalk,
        .pos = { -2780.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_06] {
        .initialAnim = ANIM_ParadeToad_Red_BannerWalk,
        .pos = { -2780.0f, 0.0f, 20.0f },
        .yaw = 270.0f
    },
    [NPC_07] {
        .initialAnim = ANIM_ParadePartner_Goombario_Goombario,
        .pos = { -2585.0f, 70.0f, 15.0f },
        .yaw = 270.0f
    },
    [NPC_08] {
        .initialAnim = ANIM_ParadePartner_Goombario_Kooper,
        .pos = { -2517.0f, 40.0f, 7.0f },
        .yaw = 90.0f
    },
    [NPC_09] {
        .initialAnim = ANIM_ParadePartner_Goombario_Bombette,
        .pos = { -2536.0f, 50.0f, 38.0f },
        .yaw = 270.0f
    },
    [NPC_0A] {
        .initialAnim = ANIM_ParadePartner_Goombario_Parakarry,
        .pos = { -2515.0f, 80.0f, 5.0f },
        .yaw = 270.0f
    },
    [NPC_0B] {
        .initialAnim = ANIM_ParadePartner_Goombario_Bow,
        .pos = { -2475.0f, 56.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_0C] {
        .initialAnim = ANIM_ParadePartner_Goombario_Watt,
        .pos = { -2575.0f, 20.0f, 48.0f },
        .yaw = 270.0f
    },
    [NPC_0D] {
        .initialAnim = ANIM_ParadePartner_Goombario_Sushie,
        .pos = { -2570.0f, 61.0f, 7.0f },
        .yaw = 90.0f
    },
    [NPC_0E] {
        .initialAnim = ANIM_ParadePartner_Goombario_Lakilester,
        .pos = { -2635.0f, 40.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_0F] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2350.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_10] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2300.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_11] {
        .initialAnim = ANIM_ParadeToad_Red_TwirlerWalk,
        .pos = { -2250.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_12] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_13] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_14] {
        .initialAnim = ANIM_ParadeToad_Red_BatonSpin,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_15] {
        .initialAnim = ANIM_ChuckQuizmo_Walk,
        .pos = { -2120.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_16] {
        .initialAnim = ANIM_VannaT_Walk,
        .pos = { -2070.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_17] {
        .initialAnim = ANIM_KoopaBros_Red_Anim1A,
        .pos = { -1860.0f, 65.0f, 10.0f },
        .yaw = 270.0f
    },
    [NPC_18] {
        .initialAnim = ANIM_KoopaBros_Black_Anim1A,
        .pos = { -1840.0f, 65.0f, 10.0f },
        .yaw = 90.0f
    },
    [NPC_19] {
        .initialAnim = ANIM_KoopaBros_Yellow_Anim1A,
        .pos = { -1870.0f, 12.0f, 37.0f },
        .yaw = 270.0f
    },
    [NPC_1A] {
        .initialAnim = ANIM_KoopaBros_Green_Anim1A,
        .pos = { -1830.0f, 12.0f, 37.0f },
        .yaw = 90.0f
    },
    [NPC_1B] {
        .initialAnim = ANIM_Bobomb_Anim05,
        .pos = { -1750.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_1C] {
        .initialAnim = ANIM_Bobomb_Anim05,
        .pos = { -1720.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_1D] {
        .initialAnim = ANIM_Bobomb_Anim05,
        .pos = { -1690.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_1E] {
        .initialAnim = ANIM_Bobomb_Anim05,
        .pos = { -1660.0f, 0.0f, 43.0f },
        .yaw = 270.0f
    },
    [NPC_1F] {
        .initialAnim = ANIM_ParadeKolorado_IdleFwd,
        .pos = { -1555.0f, 45.0f, -190.0f },
        .yaw = 270.0f
    },
    [NPC_20] {
        .initialAnim = ANIM_ParadeKolorado_WifeIdleFwd,
        .pos = { -1575.0f, 45.0f, -210.0f },
        .yaw = 270.0f
    },
    [NPC_21] {
        .initialAnim = ANIM_Rowf_PackedWalk,
        .animList = N(D_80244C78_DFB678),
        .pos = { -1775.0f, 0.0f, 2.0f },
        .yaw = 90.0f
    },
    [NPC_22] {
        .initialAnim = ANIM_Rowf_PackedWalk,
        .animList = N(D_80244C78_DFB678),
        .pos = { -1740.0f, 0.0f, 2.0f },
        .yaw = 90.0f
    },
    [NPC_23] {
        .initialAnim = ANIM_Moustafa_Run,
        .animList = N(D_80244C94_DFB694),
        .pos = { -1240.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_24] {
        .initialAnim = ANIM_Mouser_Blue_Run,
        .animList = N(D_80244CAC_DFB6AC),
        .pos = { -1210.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_25] {
        .initialAnim = ANIM_Mouser_Blue_Run,
        .animList = N(D_80244CAC_DFB6AC),
        .pos = { -1180.0f, 0.0f, -2.0f },
        .yaw = 270.0f
    },
    [NPC_26] {
        .initialAnim = ANIM_Tutankoopa_Anim02,
        .animList = N(D_80244C60_DFB660),
        .pos = { -1040.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_27] {
        .initialAnim = ANIM_ChainChomp_Anim03,
        .pos = { -1000.0f, 0.0f, 30.0f },
        .yaw = 270.0f
    },
    [NPC_28] {
        .initialAnim = ANIM_Buzzar_Anim05,
        .animList = N(D_80244CBC_DFB6BC),
        .pos = { -855.0f, 70.0f, -140.0f },
        .yaw = 270.0f
    },
    [NPC_29] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -875.0f, 70.0f, -165.0f },
        .yaw = 270.0f
    },
    [NPC_2A] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -855.0f, 70.0f, -160.0f },
        .yaw = 90.0f
    },
    [NPC_2B] {
        .initialAnim = ANIM_ParadeChick_Egg,
        .pos = { -835.0f, 70.0f, -165.0f },
        .yaw = 90.0f
    },
    [NPC_2C] {
        .initialAnim = ANIM_Bootler_Idle,
        .pos = { -650.0f, 20.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_2D] {
        .initialAnim = ANIM_Tutankoopa_Anim02,
        .animList = N(D_80244C60_DFB660),
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_2E] {
        .initialAnim = ANIM_ChainChomp_Anim03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_2F] {
        .initialAnim = ANIM_ChainChomp_Anim03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_30] {
        .initialAnim = ANIM_ChainChomp_Anim03,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_31] {
        .initialAnim = ANIM_ParadeTubbaBalloon_Still,
        .pos = { -310.0f, 35.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_32] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_33] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_34] {
        .initialAnim = ANIM_Boo_CarryIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_35] {
        .initialAnim = ANIM_TubbasHeart_Anim01,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_36] {
        .initialAnim = ANIM_GoombaKing_Still,
        .animList = N(D_80244CC8_DFB6C8),
        .pos = { -70.0f, 130.0f, -60.0f },
        .yaw = 270.0f
    },
    [NPC_37] {
        .initialAnim = ANIM_GoombaBros_Red_Walk,
        .pos = { -110.0f, 0.0f, -28.0f },
        .yaw = 90.0f
    },
    [NPC_38] {
        .initialAnim = ANIM_GoombaBros_Blue_Walk,
        .pos = { -30.0f, 0.0f, -32.0f },
        .yaw = 270.0f
    },
    [NPC_39] {
        .initialAnim = ANIM_ParadeYoshi_Brown_Idle,
        .pos = { 212.0f, 40.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_3A] {
        .initialAnim = ANIM_ParadeYoshi_Brown_IdleBlue,
        .pos = { 247.0f, 40.0f, 35.0f },
        .yaw = 270.0f
    },
    [NPC_3B] {
        .initialAnim = ANIM_ParadeYoshi_Brown_IdleYellow,
        .pos = { 282.0f, 40.0f, 35.0f },
        .yaw = 90.0f
    },
    [NPC_3C] {
        .initialAnim = ANIM_ParadeYoshi_Brown_IdleBrown,
        .pos = { 272.0f, 50.0f, 25.0f },
        .yaw = 90.0f
    },
    [NPC_3D] {
        .initialAnim = ANIM_ParadeYoshi_Brown_IdleLeader,
        .pos = { 232.0f, 50.0f, 25.0f },
        .yaw = 270.0f
    },
    [NPC_3E] {
        .initialAnim = ANIM_RafaelRaven_IdleNoFeet,
        .animList = N(D_80244CD8_DFB6D8),
        .pos = { 357.0f, -120.0f, -30.0f },
        .yaw = 90.0f
    },
    [NPC_3F] {
        .initialAnim = ANIM_LavaPiranha_Anim04,
        .animList = N(D_80244CE0_DFB6E0),
        .pos = { 507.0f, 50.0f, -5.0f },
        .yaw = 90.0f
    },
    [NPC_40] {
        .initialAnim = ANIM_YoshiKid_Green_Walk,
        .pos = { 570.0f, 50.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_41] {
        .initialAnim = ANIM_YoshiKid_Blue_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_42] {
        .initialAnim = ANIM_YoshiKid_Purple_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_43] {
        .initialAnim = ANIM_YoshiKid_Yellow_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_44] {
        .initialAnim = ANIM_YoshiKid_Red_Run,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_45] {
        .initialAnim = ANIM_HuffNPuff_Anim01,
        .animList = N(D_80244CE8_DFB6E8),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_46] {
        .initialAnim = ANIM_HuffNPuff_Anim02,
        .animList = N(D_80244CE8_DFB6E8),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_47] {
        .initialAnim = ANIM_HuffNPuff_Anim03,
        .animList = N(D_80244CE8_DFB6E8),
        .pos = { 1060.0f, 80.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_48] {
        .initialAnim = ANIM_TuffPuff_Idle,
        .animList = N(D_80244D10_DFB710),
        .pos = { 980.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_49] {
        .initialAnim = ANIM_TuffPuff_Idle,
        .animList = N(D_80244D10_DFB710),
        .pos = { 1140.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_4A] {
        .initialAnim = ANIM_GourmetGuy_Walk,
        .animList = N(D_80244D20_DFB720),
        .pos = { 1270.0f, 0.0f, -20.0f },
        .yaw = 270.0f
    },
    [NPC_4B] {
        .initialAnim = ANIM_Duplighost_Anim0A,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_4C] {
        .initialAnim = ANIM_Duplighost_Anim0A,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_4D] {
        .initialAnim = ANIM_CrystalKing_Anim0E,
        .pos = { 1440.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_4E] {
        .initialAnim = ANIM_CrystalKing_Anim0E,
        .pos = { 1600.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_4F] {
        .initialAnim = ANIM_CrystalKing_Anim0A,
        .pos = { 2000.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_50] {
        .initialAnim = ANIM_CrystalKing_Anim0B,
        .pos = { 2050.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_51] {
        .initialAnim = ANIM_CrystalKing_Anim0C,
        .pos = { 2100.0f, 100.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_52] {
        .initialAnim = ANIM_WorldKammy_Anim14,
        .animList = N(D_80244D58_DFB758),
        .pos = { 2160.0f, 60.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_53] {
        .initialAnim = ANIM_MageJrTroopa_RaiseStaff,
        .animList = N(D_80244D40_DFB740),
        .pos = { 2060.0f, 0.0f, 0.0f },
        .yaw = 90.0f
    },
    [NPC_54] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_Bowser,
        .pos = { 2390.0f, 10.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_55] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_Propeller,
        .pos = { 2390.0f, 10.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_56] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_HammerBrosJuggle,
        .pos = { 2300.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_57] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_HammerBrosJuggle,
        .pos = { 2260.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_58] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_KoopatrolMarch,
        .pos = { 2480.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_59] {
        .initialAnim = ANIM_ParadeKoopas_Bowser_KoopatrolMarch,
        .pos = { 2520.0f, 0.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_5A] {
        .initialAnim = ANIM_ParadeBurntBowser_BurntIdle,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
    [NPC_5B] {
        .initialAnim = ANIM_ParadeBurntBowser_BurntPropeller,
        .pos = { 0.0f, -500.0f, 0.0f },
        .yaw = 270.0f
    },
};

EvtScript N(D_80245614_DFC014) = {
    EVT_CALL(N(func_80242680_DF9080), 0)
    EVT_CALL(N(func_80242744_DF9144), 0x00025000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 1)
    EVT_CALL(N(func_80242680_DF9080), 2)
    EVT_CALL(N(func_80242680_DF9080), 3)
    EVT_CALL(N(func_80242680_DF9080), 4)
    EVT_CALL(N(func_80242680_DF9080), 5)
    EVT_CALL(N(func_80242680_DF9080), 6)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF4E3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_00)
    EVT_CALL(N(func_80242680_DF9080), 7)
    EVT_CALL(N(func_80242680_DF9080), 8)
    EVT_CALL(N(func_80242680_DF9080), 9)
    EVT_CALL(N(func_80242680_DF9080), 10)
    EVT_CALL(N(func_80242680_DF9080), 11)
    EVT_CALL(N(func_80242680_DF9080), 12)
    EVT_CALL(N(func_80242680_DF9080), 13)
    EVT_CALL(N(func_80242680_DF9080), 14)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF60A)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_01)
    EVT_CALL(DeleteNpc, NPC_02)
    EVT_CALL(DeleteNpc, NPC_03)
    EVT_CALL(DeleteNpc, NPC_04)
    EVT_CALL(DeleteNpc, NPC_05)
    EVT_CALL(DeleteNpc, NPC_06)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x00025000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 15)
    EVT_CALL(N(func_80242680_DF9080), 16)
    EVT_CALL(N(func_80242680_DF9080), 17)
    EVT_CALL(N(func_80242680_DF9080), 18)
    EVT_CALL(N(func_80242680_DF9080), 19)
    EVT_CALL(N(func_80242680_DF9080), 20)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_WAIT(60)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF704)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_07)
    EVT_CALL(DeleteNpc, NPC_08)
    EVT_CALL(DeleteNpc, NPC_09)
    EVT_CALL(DeleteNpc, NPC_0A)
    EVT_CALL(DeleteNpc, NPC_0B)
    EVT_CALL(DeleteNpc, NPC_0C)
    EVT_CALL(DeleteNpc, NPC_0D)
    EVT_CALL(DeleteNpc, NPC_0E)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 21)
    EVT_CALL(N(func_80242680_DF9080), 22)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF7EA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_0F)
    EVT_CALL(DeleteNpc, NPC_10)
    EVT_CALL(DeleteNpc, NPC_11)
    EVT_CALL(DeleteNpc, NPC_12)
    EVT_CALL(DeleteNpc, NPC_13)
    EVT_CALL(DeleteNpc, NPC_14)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x0000B000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 23)
    EVT_CALL(N(func_80242680_DF9080), 24)
    EVT_CALL(N(func_80242680_DF9080), 25)
    EVT_CALL(N(func_80242680_DF9080), 26)
    EVT_CALL(N(func_80242680_DF9080), 27)
    EVT_CALL(N(func_80242680_DF9080), 28)
    EVT_CALL(N(func_80242680_DF9080), 29)
    EVT_CALL(N(func_80242680_DF9080), 30)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF89E)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_15)
    EVT_CALL(DeleteNpc, NPC_16)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 31)
    EVT_CALL(N(func_80242680_DF9080), 32)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFA24)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_17)
    EVT_CALL(DeleteNpc, NPC_18)
    EVT_CALL(DeleteNpc, NPC_19)
    EVT_CALL(DeleteNpc, NPC_1A)
    EVT_CALL(DeleteNpc, NPC_1B)
    EVT_CALL(DeleteNpc, NPC_1C)
    EVT_CALL(DeleteNpc, NPC_1D)
    EVT_CALL(DeleteNpc, NPC_1E)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x00019F00, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 38)
    EVT_CALL(N(func_80242680_DF9080), 33)
    EVT_CALL(N(func_80242680_DF9080), 34)
    EVT_CALL(N(func_80242680_DF9080), 35)
    EVT_CALL(N(func_80242680_DF9080), 36)
    EVT_CALL(N(func_80242680_DF9080), 37)
    EVT_CALL(N(func_80242680_DF9080), 39)
    EVT_CALL(N(func_80242744_DF9144), 0x00007000, LVarF)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFB64)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_1F)
    EVT_CALL(DeleteNpc, NPC_20)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 40)
    EVT_CALL(N(func_80242680_DF9080), 41)
    EVT_CALL(N(func_80242680_DF9080), 42)
    EVT_CALL(N(func_80242680_DF9080), 43)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -960)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_26)
    EVT_CALL(DeleteNpc, NPC_21)
    EVT_CALL(DeleteNpc, NPC_22)
    EVT_CALL(DeleteNpc, NPC_23)
    EVT_CALL(DeleteNpc, NPC_24)
    EVT_CALL(DeleteNpc, NPC_25)
    EVT_CALL(DeleteNpc, NPC_27)
    EVT_CALL(N(func_802427A4_DF91A4), LVarF)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x00011F00, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 45)
    EVT_CALL(N(func_80242680_DF9080), 46)
    EVT_CALL(N(func_80242680_DF9080), 47)
    EVT_CALL(N(func_80242680_DF9080), 48)
    EVT_CALL(N(func_80242680_DF9080), 44)
    EVT_CALL(N(func_80242744_DF9144), 0x0000A000, LVarF)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -540)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_28)
    EVT_CALL(DeleteNpc, NPC_29)
    EVT_CALL(DeleteNpc, NPC_2A)
    EVT_CALL(DeleteNpc, NPC_2B)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 53)
    EVT_CALL(N(func_80242680_DF9080), 50)
    EVT_CALL(N(func_80242680_DF9080), 51)
    EVT_CALL(N(func_80242680_DF9080), 52)
    EVT_CALL(N(func_80242680_DF9080), 49)
    EVT_CALL(N(SetNpcShadowScale), 49, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcFlagBits, NPC_31, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_2C)
    EVT_CALL(DeleteNpc, NPC_2D)
    EVT_CALL(DeleteNpc, NPC_2E)
    EVT_CALL(DeleteNpc, NPC_2F)
    EVT_CALL(DeleteNpc, NPC_30)
    EVT_CALL(N(func_802427A4_DF91A4), LVarF)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x0000F000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 54)
    EVT_CALL(N(func_80242680_DF9080), 55)
    EVT_CALL(N(func_80242680_DF9080), 56)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_CALL(N(SetNpcShadowScale), 54, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_36, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -53)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_31)
    EVT_CALL(DeleteNpc, NPC_32)
    EVT_CALL(DeleteNpc, NPC_33)
    EVT_CALL(DeleteNpc, NPC_34)
    EVT_CALL(DeleteNpc, NPC_35)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 62)
    EVT_CALL(N(func_80242680_DF9080), 63)
    EVT_CALL(N(func_80242680_DF9080), 57)
    EVT_CALL(N(func_80242680_DF9080), 58)
    EVT_CALL(N(func_80242680_DF9080), 59)
    EVT_CALL(N(func_80242680_DF9080), 60)
    EVT_CALL(N(func_80242680_DF9080), 61)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 750)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_36)
    EVT_CALL(DeleteNpc, NPC_37)
    EVT_CALL(DeleteNpc, NPC_38)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x00020000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 64)
    EVT_CALL(N(func_80242680_DF9080), 65)
    EVT_CALL(N(func_80242680_DF9080), 66)
    EVT_CALL(N(func_80242680_DF9080), 67)
    EVT_CALL(N(func_80242680_DF9080), 68)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 800)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_39)
    EVT_CALL(DeleteNpc, NPC_3A)
    EVT_CALL(DeleteNpc, NPC_3B)
    EVT_CALL(DeleteNpc, NPC_3C)
    EVT_CALL(DeleteNpc, NPC_3D)
    EVT_CALL(DeleteNpc, NPC_3E)
    EVT_CALL(DeleteNpc, NPC_3F)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 69)
    EVT_CALL(N(func_80242680_DF9080), 70)
    EVT_CALL(N(func_80242680_DF9080), 71)
    EVT_CALL(N(func_80242680_DF9080), 74)
    EVT_CALL(N(func_80242680_DF9080), 72)
    EVT_CALL(N(func_80242680_DF9080), 73)
    EVT_CALL(N(SetNpcShadowScale), 69, EVT_FLOAT(6.0))
    EVT_CALL(SetNpcFlagBits, NPC_45, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), 74, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_4A, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x000004B0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_40)
    EVT_CALL(DeleteNpc, NPC_41)
    EVT_CALL(DeleteNpc, NPC_42)
    EVT_CALL(DeleteNpc, NPC_43)
    EVT_CALL(DeleteNpc, NPC_44)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242744_DF9144), 0x00002000, LVar0)
    EVT_CALL(N(func_80242680_DF9080), 77)
    EVT_CALL(N(func_80242680_DF9080), 78)
    EVT_CALL(N(func_80242680_DF9080), 79)
    EVT_CALL(N(func_80242680_DF9080), 80)
    EVT_CALL(N(func_80242680_DF9080), 81)
    EVT_CALL(N(func_802427A4_DF91A4), LVar0)
    EVT_CALL(N(SetNpcShadowScale), 77, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcFlagBits, NPC_4D, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), 78, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcFlagBits, NPC_4E, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000546)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_45)
    EVT_CALL(DeleteNpc, NPC_46)
    EVT_CALL(DeleteNpc, NPC_47)
    EVT_CALL(DeleteNpc, NPC_4A)
    EVT_CALL(DeleteNpc, NPC_48)
    EVT_CALL(DeleteNpc, NPC_49)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 75)
    EVT_CALL(N(func_80242680_DF9080), 76)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000744)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_4D)
    EVT_CALL(DeleteNpc, NPC_4E)
    EVT_CALL(DeleteNpc, NPC_4F)
    EVT_CALL(DeleteNpc, NPC_50)
    EVT_CALL(DeleteNpc, NPC_51)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 83)
    EVT_CALL(N(func_80242680_DF9080), 82)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x000007A8)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DeleteNpc, NPC_4B)
    EVT_CALL(DeleteNpc, NPC_4C)
    EVT_WAIT(1)
    EVT_CALL(N(func_80242680_DF9080), 84)
    EVT_CALL(N(func_80242680_DF9080), 85)
    EVT_CALL(N(func_80242680_DF9080), 86)
    EVT_CALL(N(func_80242680_DF9080), 87)
    EVT_CALL(N(func_80242680_DF9080), 88)
    EVT_CALL(N(func_80242680_DF9080), 89)
    EVT_CALL(N(func_80242680_DF9080), 90)
    EVT_CALL(N(func_80242680_DF9080), 91)
    EVT_CALL(N(SetNpcShadowScale), 84, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_54, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(N(SetNpcShadowScale), 90, EVT_FLOAT(3.0))
    EVT_CALL(SetNpcFlagBits, NPC_5A, NPC_FLAG_DIRTY_SHADOW, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_55, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_5B, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_PlayCredits) = {
    EVT_WAIT(240)
    EVT_EXEC(N(EVS_InitCredits))
    EVT_EXEC(N(EVS_ShowCredits_Title))
    EVT_EXEC(N(EVS_ShowCredits_Jobs))
    EVT_EXEC(N(EVS_ShowCredits_Names))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80246B28) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(SetPlayerPos, 0, -1000, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(D_80244AE4_DFB4E4))
    EVT_EXEC(N(D_80244B64_DFB564))
    EVT_EXEC(N(D_802446B0_DFB0B0))
    EVT_EXEC(N(D_80245614_DFC014))
    EVT_EXEC_GET_TID(N(D_80247230_DFDC30), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ParadePhase_PlayCredits))
    EVT_EXEC(N(D_80244724_DFB124))
    EVT_EXEC(N(D_80244814_DFB214))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF4E3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_80247418_DFDE18))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF60A)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_802479C4_DFE3C4))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF79A)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80248928))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF7D6)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80248BAC))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFA24)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80249040))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFAB5)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80249A38))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -760)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_80249EA4))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -960)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024A044))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024A804))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -53)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024AD30))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 750)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024C38C))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x000004B0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024CC78))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000744)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_8024D834))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000A14)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GotoMap, EVT_PTR("end_01"), end_01_ENTRY_0)
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
