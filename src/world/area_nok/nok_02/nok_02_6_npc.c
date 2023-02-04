#include "nok_02.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(D_80246E70_9DDE90) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Parakarry) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80246E70_9DDE90)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ParakarryA) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_Parakarry),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

s32 N(missing_80246EEC_6EEC)[] = {
    0x00000000, 0x002A0018, 0x00000000, 0x00000000, 0x80246EA0, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 
};

MobileAISettings N(AISettings_KoopaWithoutShell) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaWithoutShell) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_KoopaWithoutShell)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaWithoutShell) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_KoopaWithoutShell),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

s32 N(missing_80246F94_6F94)[] = {
    0x00000000, 0x002A0018, 0x00000000, 0x00000000, 0x80246F48, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00630000, 
};

NpcSettings N(NpcSettings_ParakarryB) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_Kolorado) = {
    .height = 40,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_KoloradoWife_02) = {
    .height = 38,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Bombette) = {
    .height = 20,
    .radius = 22,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_KoopaKoot) = {
    .height = 32,
    .radius = 24,
    .level = 99,
};

NpcSettings N(NpcSettings_Bombomb_01) = {
    .height = 23,
    .radius = 20,
    .level = 6,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/KeyItemChoice.inc.c"

EvtScript N(D_8024988C_9E08AC) = {
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_80007)
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList_Kolorado)[] = {
    ITEM_LETTER_TO_KOLORADO, ITEM_NONE 
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH1_0097, MSG_CH1_0098, MSG_CH1_0099, MSG_CH1_009A,
        EVT_PTR(N(LetterList_Kolorado)))
    EVT_EXEC_WAIT(N(EVS_DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    EVT_IF_EQ(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetBackIntoShell) = {
    EVT_CALL(GetNpcYaw, LVar4, LVar1)
    EVT_SET(LVar2, 30)
    EVT_IF_GT(LVar1, 151)
        EVT_IF_LE(LVar1, 331)
            EVT_SET(LVar2, -30)
        EVT_END_IF
    EVT_END_IF
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, LVar2)
        EVT_CALL(SetNpcRotation, LVar3, 0, 0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/SwitchToPartner.inc.c"


API_CALLABLE(N(func_80243010_9DA030)) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20;
    f32 temp_f22;
    f32 f3;

    temp_f22 = evt_get_variable(script, *args++);
    temp_f20 = evt_get_variable(script, *args++);
    f3 = evt_get_variable(script, *args++);

    fx_explosion(0, temp_f22, temp_f20 + 15.0f, f3);
    exec_ShakeCam1(0, 0, 20);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802430CC_9DA0EC)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Npc* npc1 = (Npc*) evt_get_variable(script, *args++);
    Npc* npc2 = (Npc*) evt_get_variable(script, *args++);
    s32 outVal = FALSE;
    f32 xDiff, zDiff;

    if (playerStatus->currentSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    do {
        xDiff = npc1->pos.x - playerStatus->position.x;
        zDiff = npc1->pos.z - playerStatus->position.z;
        if ((SQ(xDiff) + SQ(zDiff) < 6400.0f) && (script->varTable[2] >= 2)) {
            do {
                outVal = TRUE;
            } while (0); // TODO required to match
        }

        xDiff = npc1->pos.x - npc2->pos.x;
        zDiff = npc1->pos.z - npc2->pos.z;
        if (SQ(xDiff) + SQ(zDiff) < 1600.0f) {
            outVal = TRUE;
        }
    } while (0); // TODO required to match

    script->varTable[0] = outVal;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243214_9DA234)) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->currentSpeed >= 4.0f) {
        script->varTable[2]++;
        if (script->varTable[2] > 2) {
            script->varTable[2] = 2;
        }
    } else {
        script->varTable[2] = 0;
    }

    script->varTable[0] = 1;
    if (script->varTable[2] >= 2) {
        script->varTable[0] = 0;
    }
    if (playerStatus->currentSpeed == 0.0f) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243294_9DA2B4)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* npc1 = (Npc*) evt_get_variable(script, *args++);
    Npc* npc2 = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + npc1->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + npc1->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < 22500.0f) {
            xDiff = x - playerStatus->position.x;
            zDiff = z - playerStatus->position.z;
            if (SQ(xDiff) + SQ(zDiff) > 6400.0f) {
                xDiff = x - npc2->pos.x;
                zDiff = z - npc2->pos.z;
                if (SQ(xDiff) + SQ(zDiff) > 1600.0f) {
                    break;
                }
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - npc1->pos.x;
    zDiff = z - npc1->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_8024351C_9DA53C)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 randRange = 10000;
    Npc* npc = (Npc*) evt_get_variable(script, *args++);
    f32 xDiff, zDiff;
    f32 x, z;
    f32 dist;
    s32 rand;

    while (TRUE) {
        rand = rand_int(randRange);
        x = ((rand - (randRange / 2)) / 100) + npc->pos.x;
        rand = rand_int(randRange);
        z = ((rand - (randRange / 2)) / 100) + npc->pos.z;

        xDiff = x - -150.0f;
        zDiff = z - 250.0f;
        if (SQ(xDiff) + SQ(zDiff) < 22500.0f) {
            xDiff = x - playerStatus->position.x;
            zDiff = z - playerStatus->position.z;
            if (SQ(xDiff) + SQ(zDiff) > 6400.0f) {
                break;
            }
        }

        randRange += 5000;
        if (randRange > 30000) {
            randRange = 30000;
        }
    }
    xDiff = x - npc->pos.x;
    zDiff = z - npc->pos.z;
    dist = SQ(xDiff) + SQ(zDiff);
    if (dist != 0.0f) {
        dist = sqrtf(dist) / 10.0f;
    }
    script->varTable[10] = x;
    script->varTable[11] = z;
    script->varTable[12] = (s32) dist + 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80243754_9DA774)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;
    f32 yaw;

    if (isInitialCall) {
        script->functionTempPtr[1] = npc = (Npc*) evt_get_variable(script, *args++);
        npc->moveToPos.x = (evt_get_variable(script, *args++) + npc->pos.x) * 0.5f;
        npc->moveToPos.z = (evt_get_variable(script, *args++) + npc->pos.z) * 0.5f;
        npc->moveToPos.y = dist2D(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        script->functionTemp[2] = atan2(npc->moveToPos.x, npc->moveToPos.z, npc->pos.x, npc->pos.z);
        npc->duration = 0;
    }

    npc = script->functionTempPtr[1];
    npc->pos.x = npc->moveToPos.x;
    npc->pos.z = npc->moveToPos.z;

    npc->duration += 9;
    if (npc->duration >= 360) {
        npc->duration = 360;
    }
    yaw = script->functionTemp[2] + npc->duration;
    npc->yaw = clamp_angle(yaw + 90.0f);
    npc_move_heading(npc, npc->moveToPos.y, yaw);

    if (npc->duration == 360) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_NpcInteract_Kooper_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        EVT_SET(GB_StoryProgress, STORY_CH1_PROMISED_TO_HELP_KOOPER)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00B4, 160, 40)
        EVT_CALL(GetPlayerPos, LVarA, LVarB, LVarC)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVarA, LVarB, LVarC)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, -180)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 375)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 17, EVT_FLOAT(-5.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 4)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(SetGroupEnabled, MODEL_g111, 1)
        EVT_THREAD
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAt, SOUND_BASIC_DOOR_OPEN, 0, 0, 0, -180)
            EVT_CALL(MakeLerp, 0, 90, 15, EASING_COS_FAST_OVERSHOOT)
            EVT_LABEL(10)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(PlayerMoveTo, -25, -130, 10)
            EVT_CALL(PlayerFaceNpc, NPC_Kooper_01, FALSE)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(N(SwitchToPartner), 1)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(NpcMoveTo, NPC_PARTNER, -55, -130, 15)
            EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Kooper_01, 0)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_Kooper_01, NPC_FLAG_100, TRUE)
        EVT_CALL(SetNpcPos, NPC_Kooper_01, 0, 0, -207)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Idle)
        EVT_WAIT(35)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Run)
        EVT_THREAD
            EVT_LOOP(30)
                EVT_CALL(PlayerFaceNpc, NPC_Kooper_01, FALSE)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(NpcMoveTo, NPC_Kooper_01, 0, -148, 20)
        EVT_THREAD
            EVT_CALL(MakeLerp, 90, 0, 30, EASING_COS_IN_OUT)
            EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_o185, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_CALL(PlaySoundAt, SOUND_BASIC_DOOR_CLOSE, 0, 0, 0, -180)
            EVT_CALL(SetGroupEnabled, MODEL_g111, 0)
        EVT_END_THREAD
        EVT_CALL(NpcMoveTo, NPC_Kooper_01, 25, -130, 10)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(NpcFacePlayer, NPC_Kooper_01, 0)
        EVT_CALL(SetNpcFlagBits, NPC_Kooper_01, NPC_FLAG_100, FALSE)
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_01, ANIM_KooperWithoutShell_Celebrate, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B5)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_NodYes)
        EVT_WAIT(15)
        EVT_CALL(EndSpeech, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Celebrate)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(EndSpeech, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
        EVT_CALL(AdjustCam, CAM_DEFAULT, 6, 30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
        EVT_WAIT(5)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B6)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Bow)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Kooper_01, ANIM_KooperWithoutShell_Idle)
        EVT_CALL(EndSpeech, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0)
        EVT_CALL(AdjustCam, CAM_DEFAULT, 4, -30, EVT_FLOAT(225.0), EVT_FLOAT(17.0), EVT_FLOAT(-8.5))
        EVT_WAIT(10)
        EVT_THREAD
            EVT_WAIT(3)
            EVT_CALL(PlayerFaceNpc, NPC_PARTNER, FALSE)
        EVT_END_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, MSG_CH1_00B7)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 0, EVT_FLOAT(375.0), EVT_FLOAT(17.0), EVT_FLOAT(-5.5))
        EVT_WAIT(10)
        EVT_CALL(PlayerFaceNpc, NPC_Kooper_01, FALSE)
        EVT_WAIT(10)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00B8)
        EVT_CALL(BindNpcInteract, NPC_Kooper_01, EVT_PTR(N(EVS_NpcInteract_Kooper_01)))
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, 3)
        EVT_END_THREAD
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_HID_IN_TREE)
        EVT_CALL(SpeakToPlayer, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BA)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Kooper_01, ANIM_KooperWithoutShell_Talk, ANIM_KooperWithoutShell_Idle, 0, MSG_CH1_00BB)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A8EC) = {
    EVT_EXEC_WAIT(N(EVS_NpcInteract_Kooper_01))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024A908) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MF_Unk_00, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_Unk_00, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Fuzzy_01, ANIM_Fuzzy_Anim0C, ANIM_Fuzzy_Idle, 0, MSG_CH1_00B9)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Fuzzy_01, ANIM_Fuzzy_Walk)
    EVT_CALL(GetNpcPos, NPC_Fuzzy_01, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarA)
    EVT_ADD(LVarD, -5)
    EVT_LABEL(10)
        EVT_THREAD
            EVT_CALL(SetNpcJumpscale, NPC_Kooper_02, 2)
            EVT_CALL(NpcJump0, NPC_Kooper_02, LVarD, 0, LVarC, 12)
        EVT_END_THREAD
        EVT_WAIT(1)
        EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 2)
        EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
        EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarA, 0, LVarC, 12)
        EVT_CALL(IsPlayerWithin, 0, -400, 130, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_SET(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, -514)
    EVT_SET(LVarE, 15)
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Kooper_02, 2)
        EVT_CALL(NpcJump0, NPC_Kooper_02, LVarB, LVarC, LVarD, LVarE)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetNpcJumpscale, NPC_Fuzzy_01, 2)
    EVT_CALL(PlaySoundAtNpc, NPC_Fuzzy_01, SOUND_331, 0)
    EVT_CALL(NpcJump0, NPC_Fuzzy_01, LVarB, LVarC, LVarD, LVarE)
    EVT_CALL(SetNpcFlagBits, NPC_Fuzzy_01, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_Kooper_02, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_Fuzzy_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_Kooper_02, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

Vec2i N(FuzzyJumpPath1)[] = {
    { -466,  103 },
    { -441,  213 },
    { -385,  285 },
    { -302,  324 },
    { -250,  428 },
    { -158,  451 },
    {  -45,  485 },
    {   62,  428 },
    {  214,  424 },
    {  324,  295 },
    {  416,  193 },
    {  293,  123 },
    {  181,   63 },
    {   95,   57 },
    {  -14,   16 },
    { -161,   56 },
    { -317,   81 },
    { -401,   73 },
};

Vec2i N(FuzzyJumpPath2)[] = {
    {  416,  193 },
    {  324,  295 },
    {  214,  424 },
    {   62,  428 },
    {  -45,  485 },
    { -158,  451 },
    { -250,  428 },
    { -302,  324 },
    { -385,  285 },
    { -441,  213 },
    { -466,  103 },
    { -401,   73 },
    { -317,   81 },
    { -161,   56 },
    {  -14,   16 },
    {   95,   57 },
    {  181,   63 },
    {  293,  123 },
};

EvtScript N(D_8024AD54_9E1D74) = {
    EVT_LABEL(100)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_VILLAGE)
        EVT_WAIT(8)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath1)))
    EVT_SET(LVar1, 200)
    EVT_BUF_READ2(LVar0, LVar2)
    EVT_CALL(SetNpcPos, NPC_MiscFuzzy1, LVar0, LVar1, LVar2)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath1)))
    EVT_LOOP(18)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 15)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
        EVT_CALL(NpcJump0, NPC_MiscFuzzy1, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024AE9C_9E1EBC) = {
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MakeItemEntity, ITEM_COIN, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 25)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar2, -40)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Hurt)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_ADD(LVar0, 30)
    EVT_ADD(LVar2, -30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Anim09)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 13)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, -20)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 11)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar2, -10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 9)
    EVT_ADD(LVar0, 80)
    EVT_ADD(LVar2, -80)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Run)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_332, 0)
    EVT_CALL(NpcJump0, NPC_SELF, LVar0, 0, LVar2, 15)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B16C_9E218C) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(D_8024AE9C_9E1EBC)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B1A4_9E21C4) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_KOOPER_JOINED_PARTY)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(100)
    EVT_IF_EQ(AF_NOK_13, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, 438, 150, 155)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_333, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 438, 0, 150, 10)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_333, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 402, 0, 160, 15)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_333, 0)
    EVT_CALL(NpcJump0, NPC_SELF, 384, 0, 160, 7)
    EVT_LABEL(0)
    EVT_USE_BUF(EVT_PTR(N(FuzzyJumpPath2)))
    EVT_LOOP(18)
        EVT_SET(LVar1, 0)
        EVT_BUF_READ2(LVar0, LVar2)
        EVT_CALL(RandInt, 9, LVar3)
        EVT_ADD(LVar3, 13)
        EVT_MULF(LVar0, EVT_FLOAT(0.9))
        EVT_MULF(LVar2, EVT_FLOAT(0.9))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_333, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, LVar3)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B3A8_9E23C8) = {
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(D_8024AE9C_9E1EBC)))
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_8000000 | ENEMY_FLAG_10000000, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B3E0_9E2400) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024AD54_9E1D74)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(D_8024B16C_9E218C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B418_9E2438) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024B1A4_9E21C4)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(D_8024B3A8_9E23C8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B450_9E2470) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024B1A4_9E21C4)))
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(D_8024B3A8_9E23C8)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024B488) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_NOK02_RecoveredShellB, TRUE)
    EVT_CALL(BindNpcAI, NPC_KoopaWithoutShell, EVT_PTR(N(EVS_DoNothing)))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(NpcJump0, NPC_Koopa_01, 227, 0, 247, 20)
    EVT_CALL(PlaySoundAtNpc, NPC_Koopa_01, SOUND_21A, 0)
    EVT_CALL(PlayerFaceNpc, NPC_Koopa_01, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_KoopaWithoutShell, NPC_Koopa_01, 0)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell, NPC_FLAG_100, TRUE)
    EVT_ADD(LVar0, -1)
    EVT_ADD(LVar2, -1)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_Happy)
    EVT_CALL(NpcJump0, NPC_KoopaWithoutShell, LVar0, 0, LVar2, 15)
    EVT_CALL(GetNpcPos, NPC_Koopa_01, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_Run)
    EVT_CALL(NpcMoveTo, NPC_KoopaWithoutShell, LVar0, LVar2, 15)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_Idle)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(NpcJump0, NPC_Koopa_01, LVar0, LVar1, LVar2, 10)
    EVT_CALL(PlayerFaceNpc, NPC_KoopaWithoutShell, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_KoopaWithoutShell, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_Still)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_01, TRUE)
    EVT_CALL(GetNpcPos, NPC_KoopaWithoutShell, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 1)
    EVT_ADD(LVar2, 1)
    EVT_ADD(LVar1, 20)
    EVT_SET(LVar3, NPC_Koopa_01)
    EVT_SET(LVar4, NPC_KoopaWithoutShell)
    EVT_EXEC(N(EVS_GetBackIntoShell))
    EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
    EVT_CALL(NpcJump0, NPC_Koopa_01, LVar0, LVar1, LVar2, 30)
    EVT_CALL(SetNpcPos, NPC_Koopa_01, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell, ANIM_Koopa_Idle)
    EVT_CALL(SetNpcFlagBits, NPC_KoopaWithoutShell, NPC_FLAG_100, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_Koopa_Still)
    EVT_WAIT(4)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_01, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_Koopa_Happy)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_KoopaWithoutShell, ANIM_Koopa_Idle)
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell, ANIM_Koopa_Happy, ANIM_Koopa_Idle, 0, MSG_CH1_005E)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B8B0_9E28D0) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK02_StolenShellComplaintB, FALSE)
        EVT_SET(GF_NOK02_StolenShellComplaintB, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005C)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KoopaWithoutShell, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_005D)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B970_9E2990) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_NpcAI_Parakarry))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B9AC_9E29CC) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        EVT_RETURN
    EVT_END_IF
    EVT_SUSPEND_THREAD(MV_Unk_00)
    EVT_WAIT(1)
    EVT_IF_EQ(GF_NOK02_StolenShellComplaintA, FALSE)
        EVT_SET(GF_NOK02_StolenShellComplaintA, TRUE)
        EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0054)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_KoopaWithoutShell_CryTalk, ANIM_KoopaWithoutShell_CryIdle, 0, MSG_CH1_0055)
    EVT_END_IF
    EVT_RESUME_THREAD(MV_Unk_00)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BA90_9E2AB0) = {
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_Bombette, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetNpcPos, NPC_KoloradoWife_01, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BB0C_9E2B2C) = {
    EVT_CALL(GetNpcPointer, NPC_Bombette, LVarF)
    EVT_CALL(GetNpcPointer, NPC_Parakarry, LVarE)
    EVT_SET(LVar2, 0)
    EVT_LABEL(0)
    EVT_CALL(N(func_802430CC_9DA0EC), LVarF, LVarE)
    EVT_SET(MV_Unk_02, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_LABEL(1)
        EVT_CALL(N(func_80243294_9DA2B4), LVarF, LVarE)
        EVT_CALL(SetNpcFlagBits, NPC_Bombette, NPC_FLAG_100, TRUE)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
        EVT_CALL(NpcJump0, NPC_Bombette, LVarA, 0, LVarB, LVarC)
        EVT_CALL(SetNpcFlagBits, NPC_Bombette, NPC_FLAG_100, FALSE)
        EVT_CALL(N(func_802430CC_9DA0EC), LVarF, LVarE)
        EVT_SET(MV_Unk_02, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BC84_9E2CA4) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LABEL(0)
    EVT_CALL(GetNpcPos, NPC_KoloradoWife_01, LVar0, LVar1, LVar2)
    EVT_CALL(GetNpcAnimation, NPC_Parakarry, LVarF)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_CryRun)
    EVT_CALL(NpcMoveTo, NPC_Parakarry, LVar0, LVar2, 30)
    EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_CryIdle)
    EVT_CALL(RandInt, 20, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_WAIT(LVar0)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024BD64) = {
    EVT_LABEL(0)
    EVT_CALL(NpcFaceNpc, NPC_Parakarry, NPC_KoloradoWife_01, 0)
    EVT_WAIT(5)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BDB0_9E2DD0) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_SET(LVar3, 0)
    EVT_SET(LVar4, 0)
    EVT_LOOP(0)
        EVT_CALL(N(func_80243214_9DA234))
        EVT_CALL(IsPlayerWithin, -150, 250, 150, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET(LVar3, 1)
            EVT_ELSE
                EVT_SET(LVar3, 0)
                EVT_WAIT(20)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar3, 0)
        EVT_END_IF
        EVT_IF_NE(LVar3, LVar4)
            EVT_IF_EQ(LVar3, 0)
                EVT_EXEC_GET_TID(N(D_8024BC84_9E2CA4), MV_Unk_00)
            EVT_ELSE
                EVT_IF_NE(MV_Unk_00, -1)
                    EVT_KILL_THREAD(MV_Unk_00)
                    EVT_SET(MV_Unk_00, -1)
                EVT_END_IF
            EVT_END_IF
            EVT_SET(LVar4, LVar3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024BF3C_9E2F5C) = {
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_Bombette, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_KoloradoWife_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcSpeed, NPC_Parakarry, EVT_FLOAT(3.0))
        EVT_LABEL(5)
        EVT_CALL(GetNpcPointer, NPC_Parakarry, LVarF)
        EVT_CALL(N(func_8024351C_9DA53C), LVarF)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Koopa_Run)
        EVT_CALL(NpcMoveTo, NPC_Parakarry, LVarA, LVarB, 0)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Koopa_Talk)
        EVT_WAIT(10)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_EXEC_GET_TID(N(D_8024BA90_9E2AB0), LVar9)
    EVT_EXEC_GET_TID(N(D_8024BB0C_9E2B2C), LVar8)
    EVT_EXEC_GET_TID(N(D_8024BC84_9E2CA4), MV_Unk_00)
    EVT_EXEC_GET_TID(N(D_8024BDB0_9E2DD0), MV_Unk_01)
    EVT_LABEL(10)
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_ELSE
        EVT_KILL_THREAD(LVar9)
        EVT_KILL_THREAD(LVar8)
        EVT_IS_THREAD_RUNNING(MV_Unk_00, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_KILL_THREAD(MV_Unk_00)
        EVT_END_IF
        EVT_IS_THREAD_RUNNING(MV_Unk_01, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_KILL_THREAD(MV_Unk_01)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_THREAD
            EVT_CALL(SetNpcFlagBits, NPC_Bombette, NPC_FLAG_100, TRUE)
            EVT_CALL(GetNpcPos, NPC_KoloradoWife_01, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcAnimation, NPC_Bombette, ANIM_Fuzzy_Hurt)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 25)
            EVT_ADD(LVar0, 40)
            EVT_ADD(LVar2, -40)
            EVT_CALL(SetNpcAnimation, NPC_Bombette, ANIM_Fuzzy_Hurt)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 15)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetNpcAnimation, NPC_Bombette, ANIM_Fuzzy_Anim09)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 13)
            EVT_ADD(LVar0, 20)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 11)
            EVT_ADD(LVar0, 10)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 9)
            EVT_ADD(LVar0, 160)
            EVT_CALL(SetNpcAnimation, NPC_Bombette, ANIM_Fuzzy_Run)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_331, 0)
            EVT_CALL(NpcJump0, NPC_Bombette, LVar0, 0, LVar2, 15)
            EVT_CALL(SetNpcFlagBits, NPC_Bombette, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_Bombette, NPC_DISPOSE_LOCATION)
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_KoloradoWife_01, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_KoloradoWife_01, LVar0, 0, LVar2, 15)
        EVT_LOOP(70)
            EVT_CALL(PlayerFaceNpc, NPC_Bombette, FALSE)
            EVT_CALL(NpcFaceNpc, NPC_Parakarry, NPC_Bombette, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(PlayerFaceNpc, NPC_KoloradoWife_01, FALSE)
        EVT_CALL(NpcFaceNpc, NPC_Parakarry, NPC_KoloradoWife_01, 0)
        EVT_THREAD
            EVT_CALL(AdjustCam, CAM_DEFAULT, 4, 0, EVT_FLOAT(300.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_Happy)
        EVT_CALL(NpcJump0, NPC_Parakarry, LVar0, 0, LVar2, 15)
        EVT_CALL(GetNpcPos, NPC_KoloradoWife_01, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_Run)
        EVT_CALL(NpcMoveTo, NPC_Parakarry, LVar0, LVar2, 15)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_Idle)
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 10)
        EVT_CALL(NpcJump0, NPC_KoloradoWife_01, LVar0, LVar1, LVar2, 10)
        EVT_CALL(PlayerFaceNpc, NPC_Parakarry, FALSE)
        EVT_CALL(NpcFacePlayer, NPC_Parakarry, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_KoopaWithoutShell_Still)
        EVT_CALL(EnableNpcBlur, NPC_KoloradoWife_01, TRUE)
        EVT_CALL(GetNpcPos, NPC_Parakarry, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_ADD(LVar1, 20)
        EVT_SET(LVar3, NPC_KoloradoWife_01)
        EVT_SET(LVar4, NPC_Parakarry)
        EVT_EXEC(N(EVS_GetBackIntoShell))
        EVT_CALL(InterpNpcYaw, LVar3, 60, 0)
        EVT_CALL(NpcJump0, NPC_KoloradoWife_01, LVar0, LVar1, LVar2, 30)
        EVT_CALL(SetNpcPos, NPC_KoloradoWife_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcSprite, NPC_Parakarry, ANIM_Koopa_Idle)
        EVT_CALL(SetNpcFlagBits, NPC_Parakarry, NPC_FLAG_100, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Koopa_Still)
        EVT_WAIT(4)
        EVT_CALL(EnableNpcBlur, NPC_KoloradoWife_01, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Koopa_Happy)
        EVT_WAIT(30)
        EVT_CALL(SetNpcAnimation, NPC_Parakarry, ANIM_Koopa_Idle)
        EVT_CALL(SpeakToPlayer, NPC_Parakarry, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0056)
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, 4)
        EVT_END_THREAD
        EVT_WAIT(30)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(D_8024BF3C_9E2F5C)))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024C830_9E3850) = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_HAMMER)
            EVT_SET(GF_NOK02_RecoveredShellA, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_20, 1)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
            EVT_SET(GF_NOK02_RecoveredShellA, TRUE)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_20, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024C8C4_9E38E4) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024BF3C_9E2F5C)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024B9AC_9E29CC)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcSprite, NPC_SELF, ANIM_KoopaWithoutShell_CryIdle)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024C948_9E3968) = {
    EVT_CALL(BindNpcHit, NPC_SELF, EVT_PTR(N(D_8024C830_9E3850)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellA, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024C9A0_9E39C0) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024C9D8_9E39F8) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(D_8024B970_9E2990)))
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024B8B0_9E28D0)))
    EVT_IF_EQ(GF_NOK02_RecoveredShellB, FALSE)
        EVT_CALL(SetNpcPos, NPC_Koopa_01, 150, 106, 250)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcSprite, NPC_KoopaWithoutShell, ANIM_Koopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CA60_9E3A80) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Shell)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CA98_9E3AB8) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_PROMISED_TO_HELP_KOOPER)
            EVT_CALL(SetNpcPos, NPC_Kooper_01, NPC_DISPOSE_LOCATION)
        EVT_CASE_GE(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kooper_01)))
            EVT_CALL(SetNpcPos, NPC_Kooper_01, NPC_DISPOSE_LOCATION)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kooper_01)))
    EVT_END_SWITCH
    EVT_CALL(SetNpcSprite, NPC_Kooper_01, ANIM_KooperWithoutShell_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CB58_9E3B78) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_LEFT_TOWN)
        EVT_CALL(SetNpcPos, NPC_Fuzzy_01, NPC_DISPOSE_LOCATION)
        EVT_CALL(SetNpcPos, NPC_Kooper_02, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CBB8_9E3BD8) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CBF0_9E3C10) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0057)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0058)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0059)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005A)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005B)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CCF0_9E3D10) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024CBF0_9E3C10)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CD14_9E3D34) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_005F)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0060)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0061)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0062)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0063)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CE14_9E3E34) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024CD14_9E3D34)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CE38_9E3E58) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Run)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_02, TRUE)
    EVT_CALL(GetNpcPointer, NPC_Koopa_02, LVarF)
    EVT_CALL(N(func_80243754_9DA774), LVarF, -150, 15)
    EVT_CALL(EnableNpcBlur, NPC_Koopa_02, FALSE)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Koopa_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024CF14_9E3F34) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0064)
            EVT_EXEC_WAIT(N(D_8024CE38_9E3E58))
            EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0065)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0066)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0067)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0068)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_0069)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D040_9E4060) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024CF14_9E3F34)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D064_9E4084) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006A)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006C)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006D)
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Koopa_Talk, ANIM_Koopa_Idle, 0, MSG_CH1_006E)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D164_9E4184) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024D064_9E4084)))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D188_9E41A8) = {
    EVT_LABEL(10)
    EVT_IF_EQ(AF_NOK_10, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(AF_NOK_11, TRUE)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Run)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Idle)
    EVT_WAIT(3)
    EVT_CALL(GetNpcPos, NPC_Bombomb_02, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_Bombomb_02, SOUND_CANNON1, 0)
    EVT_CALL(N(func_80243010_9DA030), LVar0, LVar1, LVar2)
    EVT_WAIT(30)
    EVT_LABEL(20)
    EVT_IF_EQ(AF_NOK_10, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_IF_EQ(AF_NOK_11, TRUE)
        EVT_WAIT(1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Run)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Idle)
    EVT_WAIT(3)
    EVT_CALL(GetNpcPos, NPC_Bombomb_01, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtNpc, NPC_Bombomb_01, SOUND_CANNON1, 0)
    EVT_CALL(N(func_80243010_9DA030), LVar0, LVar1, LVar2)
    EVT_WAIT(30)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D3AC_9E43CC) = {
    EVT_IF_EQ(GB_KootFavor_Current, 12)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_007C)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007D)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bombomb_01, MSG_CH1_007E)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007F)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_0080)
            EVT_CALL(SetNpcAnimation, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Idle)
            EVT_CALL(SetNpcAnimation, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Idle)
            EVT_SET(GF_NOK02_ConfrontedBobombs, TRUE)
            EVT_SET(GF_MAC02_KootFavor_CurrentComplete, TRUE)
        EVT_ELSE
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007B)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_007C)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_0081)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_0082)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_PARTNER, MSG_CH1_0077)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_PARTNER, MSG_CH1_0078)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SpeakToNpc, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, NPC_Bombomb_01, MSG_CH1_0079)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 5, MSG_CH1_007A)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_ELSE
            EVT_SET(AF_NOK_11, TRUE)
            EVT_CALL(SpeakToPlayer, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0073)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bombomb_02, MSG_CH1_0074)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_02, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_0075)
            EVT_CALL(SpeakToNpc, NPC_Bombomb_01, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, NPC_Bombomb_02, MSG_CH1_0076)
            EVT_SET(AF_NOK_11, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D798_9E47B8) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(AF_NOK_0F, FALSE)
                EVT_CALL(GetCurrentPartnerID, LVar0)
                EVT_IF_EQ(LVar0, PARTNER_BOMBETTE)
                    EVT_SET(AF_NOK_0F, TRUE)
                    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
                    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_006F)
                    EVT_CALL(DisablePartnerAI, 0)
                    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_0070)
                    EVT_CALL(EnablePartnerAI)
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0071)
                EVT_ELSE
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_0072)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_EXEC_WAIT(N(D_8024D3AC_9E43CC))
            EVT_ELSE
                EVT_SET(AF_NOK_11, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_007F)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024D978_9E4998) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0083)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_EXEC_WAIT(N(D_8024D3AC_9E43CC))
            EVT_ELSE
                EVT_SET(AF_NOK_11, TRUE)
                EVT_CALL(SpeakToNpc, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, NPC_Bombomb_01, MSG_CH1_0080)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0084)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DA60_9E4A80) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0085)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0086)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_0087)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DB48_9E4B68) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024D798_9E47B8)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DBA0_9E4BC0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024D978_9E4998)))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_CASE_GE(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK02_ConfrontedBobombs, TRUE)
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC(N(D_8024D188_9E41A8))
            EVT_SET(AF_NOK_11, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DC48_9E4C68) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024DA60_9E4A80)))
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(ArtifactList)[] = {
    ITEM_ARTIFACT, ITEM_NONE
};

EvtScript N(D_8024DCA8_9E4CC8) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009F)
    EVT_GIVE_STAR_PIECE()
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_00A0)
    EVT_SET(GF_SBK_GaveArtifactToKolorado, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DD44_9E4D64) = {
    EVT_IF_EQ(GF_SBK_GaveArtifactToKolorado, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_ARTIFACT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(AF_NOK_15, FALSE)
        EVT_SET(AF_NOK_15, TRUE)
        EVT_IF_EQ(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(GF_SBK_KeptArtifactFromKolorado, FALSE)
            EVT_SET(LVar0, MSG_CH1_009B)
        EVT_ELSE
            EVT_SET(LVar0, MSG_CH1_009C)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LVar0, MSG_CH1_009C)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, LVar0)
    EVT_SET(LVar0, EVT_PTR(N(ArtifactList)))
    EVT_SET(LVar1, 7)
    EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
    EVT_SWITCH(LVar0)
        EVT_CASE_GE(1)
            EVT_EXEC_WAIT(N(D_8024DCA8_9E4CC8))
            EVT_BREAK_SWITCH
        EVT_CASE_DEFAULT
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009D)
            EVT_SET(LVar0, EVT_PTR(N(ArtifactList)))
            EVT_SET(LVar1, 7)
            EVT_EXEC_WAIT(N(EVS_ChooseKeyItem))
            EVT_SWITCH(LVar0)
                EVT_CASE_GE(1)
                    EVT_EXEC_WAIT(N(D_8024DCA8_9E4CC8))
                EVT_CASE_DEFAULT
                    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_009E)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024DF60_9E4F80) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0093)
    EVT_CALL(NpcFaceNpc, NPC_KoloradoWife_02, NPC_SELF, 0)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 5, MSG_CH1_0094)
    EVT_CALL(NpcFaceNpc, NPC_SELF, NPC_KoloradoWife_02, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 5, MSG_CH1_0095)
    EVT_WAIT(15)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(15)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH1_0096)
    EVT_EXEC_WAIT(N(D_8024DD44_9E4D64))
    EVT_EXEC_WAIT(N(EVS_LetterPrompt_Kolorado))
    EVT_EXEC_WAIT(N(EVS_LetterReward_Kolorado))
    EVT_IF_NE(LVarC, DELIVERY_NOT_POSSIBLE)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E090_9E50B0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024DF60_9E4F80)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E110_9E5130) = {
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(20)
    EVT_CALL(MakeLerp, 80, 0, 15, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_BASIC_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E26C_9E528C) = {
    EVT_CALL(EnableModel, MODEL_g98, TRUE)
    EVT_CALL(EnableGroup, MODEL_g109, TRUE)
    EVT_CALL(EnableGroup, MODEL_g47, TRUE)
    EVT_SET(LVarA, 60)
    EVT_SET(LVar9, 39)
    EVT_EXEC(N(D_8024E110_9E5130))
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -314, -94, 10)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -304, -161, 20)
    EVT_WAIT(100)
    EVT_EXEC(N(D_8024E110_9E5130))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -308, -102, 20)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -338, -85, 20)
    EVT_CALL(NpcFacePlayer, NPC_KoloradoWife_02, 0)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife_02, ANIM_KoloradoWife_Idle)
    EVT_CALL(EnableModel, MODEL_g98, FALSE)
    EVT_CALL(EnableGroup, MODEL_g109, FALSE)
    EVT_CALL(EnableGroup, MODEL_g47, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E400_9E5420) = {
    EVT_SET(LVarA, 58)
    EVT_SET(LVar9, 42)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -277, -186, 20)
    EVT_EXEC(N(D_8024E110_9E5130))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -265, -261, 20)
    EVT_WAIT(100)
    EVT_EXEC(N(D_8024E110_9E5130))
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -277, -186, 20)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_KoloradoWife_02, -328, -180, 20)
    EVT_CALL(NpcFacePlayer, NPC_KoloradoWife_02, 0)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife_02, ANIM_KoloradoWife_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E51C_9E553C) = {
    EVT_CALL(SetNpcFlagBits, NPC_KoloradoWife_02, NPC_FLAG_100, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0090)
    EVT_CALL(SetNpcAnimation, NPC_KoloradoWife_02, ANIM_KoloradoWife_Walk)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_EXEC_WAIT(N(D_8024E26C_9E528C))
    EVT_ELSE
        EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
            EVT_EXEC_WAIT(N(D_8024E26C_9E528C))
        EVT_ELSE
            EVT_EXEC_WAIT(N(D_8024E400_9E5420))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0091)
    EVT_GIVE_KEY_REWARD(ITEM_KOOT_KOOPA_LEGENDS)
    EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0092)
    EVT_CALL(SetNpcFlagBits, NPC_KoloradoWife_02, NPC_FLAG_100, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E670_9E5690) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_IF_EQ(GF_NOK02_KoloradoWife_FuzzyComplaint, FALSE)
                EVT_SET(GF_NOK02_KoloradoWife_FuzzyComplaint, TRUE)
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0088)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_0089)
        EVT_CASE_LT(STORY_CH1_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008A)
        EVT_CASE_LT(STORY_CH2_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008B)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008C)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008D)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_IF_EQ(GF_NOK11_Defeated_KentC, FALSE)
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008E)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
            EVT_END_IF
        EVT_CASE_GE(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_CALL(SpeakToPlayer, NPC_KoloradoWife_02, ANIM_KoloradoWife_Talk, ANIM_KoloradoWife_Idle, 0, MSG_CH1_008F)
    EVT_END_SWITCH
    EVT_IF_EQ(GB_KootFavor_Current, 1)
        EVT_IF_EQ(GF_NOK02_Gift_KoopaLegends, FALSE)
            EVT_SET(GF_NOK02_Gift_KoopaLegends, TRUE)
            EVT_EXEC_WAIT(N(D_8024988C_9E08AC))
            EVT_EXEC_WAIT(N(D_8024E51C_9E553C))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E8B0_9E58D0) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(D_8024E670_9E5690)))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        EVT_CALL(SetNpcPos, NPC_SELF, -338, 0, -85)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_NOK11_Defeated_KentC, TRUE)
        EVT_CALL(SetNpcPos, NPC_SELF, -338, 0, -85)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaKoot) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_KoopaKoot)))
    EVT_EXEC(N(EVS_80253350))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E97C_9E599C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -25, 10, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E9BC_9E59DC) = {
    EVT_CALL(SetNpcPos, NPC_SELF, 25, 0, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 270)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024E9FC_9E5A1C) = {
    EVT_CALL(SetNpcPos, NPC_SELF, -150, 0, -50)
    EVT_CALL(SetNpcYaw, NPC_SELF, 90)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Parakarry_Crisis)[] = {
    {
        .id = NPC_Parakarry,
        .settings = &N(NpcSettings_ParakarryA),
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(D_8024C8C4_9E38E4),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -109, 0, 191 },
                .wanderSize = { 100 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -109, 0, 191 },
                .detectSize = { 500 },
            }
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_Bombette,
        .settings = &N(NpcSettings_Bombette),
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH,
        .init = &N(D_8024C948_9E3968),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_KoloradoWife_01,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(D_8024C9A0_9E39C0),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
    },
    {
        .id = NPC_KoopaWithoutShell,
        .settings = &N(NpcSettings_KoopaWithoutShell),
        .pos = { 192.0f, 0.0f, 152.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024C9D8_9E39F8),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 199, 0, 152 },
                    { 107, 0, 152 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 192, 0, 152 },
                .detectSize = { 500 },
            }
        },
        .animations = {
            .idle   = ANIM_KoopaWithoutShell_CryIdle,
            .walk   = ANIM_KoopaWithoutShell_CryRun,
            .run    = ANIM_KoopaWithoutShell_Walk,
            .chase  = ANIM_KoopaWithoutShell_CryRun,
            .anim_4 = ANIM_KoopaWithoutShell_Walk,
            .anim_5 = ANIM_KoopaWithoutShell_Walk,
            .death  = ANIM_KoopaWithoutShell_Still,
            .hit    = ANIM_KoopaWithoutShell_Still,
            .anim_8 = ANIM_KoopaWithoutShell_Still,
            .anim_9 = ANIM_KoopaWithoutShell_Still,
            .anim_A = ANIM_KoopaWithoutShell_Still,
            .anim_B = ANIM_KoopaWithoutShell_Still,
            .anim_C = ANIM_KoopaWithoutShell_Still,
            .anim_D = ANIM_KoopaWithoutShell_Still,
            .anim_E = ANIM_KoopaWithoutShell_Still,
            .anim_F = ANIM_KoopaWithoutShell_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_Koopa_01,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(D_8024CA60_9E3A80),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
    },
    {
        .id = NPC_Kooper_01,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { 20.0f, 0.0f, -145.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(D_8024CA98_9E3AB8),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
        .tattle = MSG_NpcTattle_NOK_Kooper,
    },
    {
        .id = NPC_Fuzzy_01,
        .settings = &N(NpcSettings_Bombette),
        .pos = { 12.0f, 10.0f, -351.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(D_8024CB58_9E3B78),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Fuzzy_Walk,
            .walk   = ANIM_Fuzzy_Walk,
            .run    = ANIM_Fuzzy_Run,
            .chase  = ANIM_Fuzzy_Run,
            .anim_4 = ANIM_Fuzzy_Idle,
            .anim_5 = ANIM_Fuzzy_Idle,
            .death  = ANIM_Fuzzy_Hurt,
            .hit    = ANIM_Fuzzy_Hurt,
            .anim_8 = ANIM_Fuzzy_Run,
            .anim_9 = ANIM_Fuzzy_Run,
            .anim_A = ANIM_Fuzzy_Run,
            .anim_B = ANIM_Fuzzy_Run,
            .anim_C = ANIM_Fuzzy_Run,
            .anim_D = ANIM_Fuzzy_Run,
            .anim_E = ANIM_Fuzzy_Run,
            .anim_F = ANIM_Fuzzy_Run,
        },
    },
    {
        .id = NPC_Kooper_02,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { 12.0f, 0.0f, -351.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
        .init = &N(D_8024CBB8_9E3BD8),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldKooper_Idle,
            .walk   = ANIM_WorldKooper_Walk,
            .run    = ANIM_WorldKooper_Walk,
            .chase  = ANIM_WorldKooper_Walk,
            .anim_4 = ANIM_WorldKooper_Walk,
            .anim_5 = ANIM_WorldKooper_Walk,
            .death  = ANIM_WorldKooper_Still,
            .hit    = ANIM_WorldKooper_Still,
            .anim_8 = ANIM_WorldKooper_Still,
            .anim_9 = ANIM_WorldKooper_Still,
            .anim_A = ANIM_WorldKooper_Still,
            .anim_B = ANIM_WorldKooper_Still,
            .anim_C = ANIM_WorldKooper_Still,
            .anim_D = ANIM_WorldKooper_Still,
            .anim_E = ANIM_WorldKooper_Still,
            .anim_F = ANIM_WorldKooper_Still,
        },
    },
};

StaticNpc N(NpcData_Fuzzy_02) = {
    .id = NPC_MiscFuzzy1,
    .settings = &N(NpcSettings_Bombette),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_10000000,
    .init = &N(D_8024B3E0_9E2400),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

StaticNpc N(NpcData_Fuzzy_03) = {
    .id = NPC_Fuzzy_03,
    .settings = &N(NpcSettings_Bombette),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_10000000,
    .init = &N(D_8024B418_9E2438),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

StaticNpc N(NpcData_Parakarry_Normal)[] = {
    {
        .id = NPC_Parakarry,
        .settings = &N(NpcSettings_ParakarryA),
        .pos = { -109.0f, 0.0f, 191.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024CCF0_9E3D10),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -124, 0, 250 },
                .wanderSize = { 80 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -85, 0, 260 },
                .detectSize = { 500 },
            }
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaC,
    },
    {
        .id = NPC_KoopaWithoutShell,
        .settings = &N(NpcSettings_ParakarryA),
        .pos = { 200.0f, 0.0f, 117.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024CE14_9E3E34),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 200, 0, 117 },
                .wanderSize = { 50, 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 170 },
                .detectSize = { 500 },
            }
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_GenericKoopaD,
    },
    {
        .id = NPC_Bombomb_01,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 0.0f, 0.0f, -333.0f },
        .yaw = 180,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(D_8024DB48_9E4B68),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Blue_Idle,
            .walk   = ANIM_WorldBobomb_Blue_Walk,
            .run    = ANIM_WorldBobomb_Blue_Run,
            .chase  = ANIM_WorldBobomb_Blue_Run,
            .anim_4 = ANIM_WorldBobomb_Blue_Idle,
            .anim_5 = ANIM_WorldBobomb_Blue_Idle,
            .death  = ANIM_WorldBobomb_Blue_Still,
            .hit    = ANIM_WorldBobomb_Blue_Still,
            .anim_8 = ANIM_WorldBobomb_Blue_Still,
            .anim_9 = ANIM_WorldBobomb_Blue_Still,
            .anim_A = ANIM_WorldBobomb_Blue_Still,
            .anim_B = ANIM_WorldBobomb_Blue_Still,
            .anim_C = ANIM_WorldBobomb_Blue_Still,
            .anim_D = ANIM_WorldBobomb_Blue_Still,
            .anim_E = ANIM_WorldBobomb_Blue_Still,
            .anim_F = ANIM_WorldBobomb_Blue_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombD,
    },
    {
        .id = NPC_Bombomb_02,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { -7.0f, 0.0f, -285.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
        .init = &N(D_8024DBA0_9E4BC0),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombE,
    },
    {
        .id = NPC_Bombomb_03,
        .settings = &N(NpcSettings_Bombomb_01),
        .pos = { 47.0f, 0.0f, -140.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024DC48_9E4C68),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_NOK_BobombF,
    },
    {
        .id = NPC_Kolorado,
        .settings = &N(NpcSettings_Kolorado),
        .pos = { -240.0f, 0.0f, -70.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024E090_9E50B0),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Kolorado_Idle,
            .walk   = ANIM_Kolorado_Walk,
            .run    = ANIM_Kolorado_Run,
            .chase  = ANIM_Kolorado_Run,
            .anim_4 = ANIM_Kolorado_Idle,
            .anim_5 = ANIM_Kolorado_Idle,
            .death  = ANIM_Kolorado_Idle,
            .hit    = ANIM_Kolorado_Idle,
            .anim_8 = ANIM_Kolorado_Idle,
            .anim_9 = ANIM_Kolorado_Idle,
            .anim_A = ANIM_Kolorado_Idle,
            .anim_B = ANIM_Kolorado_Idle,
            .anim_C = ANIM_Kolorado_Idle,
            .anim_D = ANIM_Kolorado_Idle,
            .anim_E = ANIM_Kolorado_Idle,
            .anim_F = ANIM_Kolorado_Idle,
        },
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

StaticNpc N(NpcData_Fuzzy_04) = {
    .id = NPC_Fuzzy_04,
    .settings = &N(NpcSettings_Bombette),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_100000 | ENEMY_FLAG_200000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_10000000,
    .init = &N(D_8024B450_9E2470),
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Fuzzy_Walk,
        .walk   = ANIM_Fuzzy_Walk,
        .run    = ANIM_Fuzzy_Run,
        .chase  = ANIM_Fuzzy_Run,
        .anim_4 = ANIM_Fuzzy_Idle,
        .anim_5 = ANIM_Fuzzy_Idle,
        .death  = ANIM_Fuzzy_Hurt,
        .hit    = ANIM_Fuzzy_Hurt,
        .anim_8 = ANIM_Fuzzy_Run,
        .anim_9 = ANIM_Fuzzy_Run,
        .anim_A = ANIM_Fuzzy_Run,
        .anim_B = ANIM_Fuzzy_Run,
        .anim_C = ANIM_Fuzzy_Run,
        .anim_D = ANIM_Fuzzy_Run,
        .anim_E = ANIM_Fuzzy_Run,
        .anim_F = ANIM_Fuzzy_Run,
    },
};

StaticNpc N(NpcData_KoopaKoot)[] = {
    {
        .id = NPC_KoopaKoot,
        .settings = &N(NpcSettings_KoopaKoot),
        .pos = { 330.0f, 0.0f, -100.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(EVS_NpcInit_KoopaKoot),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoopaKoot_Idle,
            .walk   = ANIM_KoopaKoot_Idle,
            .run    = ANIM_KoopaKoot_Idle,
            .chase  = ANIM_KoopaKoot_Idle,
            .anim_4 = ANIM_KoopaKoot_Idle,
            .anim_5 = ANIM_KoopaKoot_Idle,
            .death  = ANIM_KoopaKoot_Idle,
            .hit    = ANIM_KoopaKoot_Idle,
            .anim_8 = ANIM_KoopaKoot_Idle,
            .anim_9 = ANIM_KoopaKoot_Idle,
            .anim_A = ANIM_KoopaKoot_Idle,
            .anim_B = ANIM_KoopaKoot_Idle,
            .anim_C = ANIM_KoopaKoot_Idle,
            .anim_D = ANIM_KoopaKoot_Idle,
            .anim_E = ANIM_KoopaKoot_Idle,
            .anim_F = ANIM_KoopaKoot_Idle,
        },
        .tattle = MSG_NpcTattle_KoopaKoot,
    },
    {
        .id = NPC_KoloradoWife_02,
        .settings = &N(NpcSettings_KoloradoWife_02),
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024E8B0_9E58D0),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoloradoWife_Idle,
            .walk   = ANIM_KoloradoWife_Walk,
            .run    = ANIM_KoloradoWife_Run,
            .chase  = ANIM_KoloradoWife_Run,
            .anim_4 = ANIM_KoloradoWife_Idle,
            .anim_5 = ANIM_KoloradoWife_Idle,
            .death  = ANIM_KoloradoWife_Idle,
            .hit    = ANIM_KoloradoWife_Idle,
            .anim_8 = ANIM_KoloradoWife_Idle,
            .anim_9 = ANIM_KoloradoWife_Idle,
            .anim_A = ANIM_KoloradoWife_Idle,
            .anim_B = ANIM_KoloradoWife_Idle,
            .anim_C = ANIM_KoloradoWife_Idle,
            .anim_D = ANIM_KoloradoWife_Idle,
            .anim_E = ANIM_KoloradoWife_Idle,
            .anim_F = ANIM_KoloradoWife_Idle,
        },
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
    {
        .id = NPC_Koopa_02,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { -307.0f, 0.0f, 97.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024D040_9E4060),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_SenseOfJustice,
    },
    {
        .id = NPC_Koopa_03,
        .settings = &N(NpcSettings_KoopaWithoutShell),
        .pos = { 285.0f, 0.0f, 223.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
        .init = &N(D_8024D164_9E4184),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { 240, 0, 175 },
                    { 350, 0, 250 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = {
            .idle   = ANIM_Koopa_Idle,
            .walk   = ANIM_Koopa_Walk,
            .run    = ANIM_Koopa_Run,
            .chase  = ANIM_Koopa_Run,
            .anim_4 = ANIM_Koopa_Idle,
            .anim_5 = ANIM_Koopa_Idle,
            .death  = ANIM_Koopa_Still,
            .hit    = ANIM_Koopa_Still,
            .anim_8 = ANIM_Koopa_Still,
            .anim_9 = ANIM_Koopa_Still,
            .anim_A = ANIM_Koopa_Still,
            .anim_B = ANIM_Koopa_Still,
            .anim_C = ANIM_Koopa_Still,
            .anim_D = ANIM_Koopa_Still,
            .anim_E = ANIM_Koopa_Still,
            .anim_F = ANIM_Koopa_Still,
        },
        .tattle = MSG_NpcTattle_NOK_PrettyMellow,
    },
};

StaticNpc N(NpcData_Parakarry)[] = {
    {
        .id = NPC_Parakarry,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(D_8024E97C_9E599C),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldParakarry_Idle,
            .walk   = ANIM_WorldParakarry_Walk,
            .run    = ANIM_WorldParakarry_Run,
            .chase  = ANIM_WorldParakarry_Run,
            .anim_4 = ANIM_WorldParakarry_Idle,
            .anim_5 = ANIM_WorldParakarry_Idle,
            .death  = ANIM_WorldParakarry_Still,
            .hit    = ANIM_WorldParakarry_Still,
            .anim_8 = ANIM_WorldParakarry_Idle,
            .anim_9 = ANIM_WorldParakarry_Idle,
            .anim_A = ANIM_WorldParakarry_Idle,
            .anim_B = ANIM_WorldParakarry_Idle,
            .anim_C = ANIM_WorldParakarry_Idle,
            .anim_D = ANIM_WorldParakarry_Idle,
            .anim_E = ANIM_WorldParakarry_Idle,
            .anim_F = ANIM_WorldParakarry_Idle,
        },
    },
    {
        .id = NPC_Bombette,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(D_8024E9BC_9E59DC),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_WorldBombette_Idle,
            .walk   = ANIM_WorldBombette_Walk,
            .run    = ANIM_WorldBombette_Walk,
            .chase  = ANIM_WorldBombette_Walk,
            .anim_4 = ANIM_WorldBombette_Walk,
            .anim_5 = ANIM_WorldBombette_Walk,
            .death  = ANIM_WorldBombette_Still,
            .hit    = ANIM_WorldBombette_Still,
            .anim_8 = ANIM_WorldBombette_Still,
            .anim_9 = ANIM_WorldBombette_Still,
            .anim_A = ANIM_WorldBombette_Still,
            .anim_B = ANIM_WorldBombette_Still,
            .anim_C = ANIM_WorldBombette_Still,
            .anim_D = ANIM_WorldBombette_Still,
            .anim_E = ANIM_WorldBombette_Still,
            .anim_F = ANIM_WorldBombette_Still,
        },
    },
    {
        .id = NPC_KoloradoWife_01,
        .settings = &N(NpcSettings_ParakarryB),
        .pos = { -328.0f, 0.0f, -180.0f },
        .yaw = 0,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .init = &N(D_8024E9FC_9E5A1C),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_KoloradoWife_Idle,
            .walk   = ANIM_KoloradoWife_Walk,
            .run    = ANIM_KoloradoWife_Run,
            .chase  = ANIM_KoloradoWife_Run,
            .anim_4 = ANIM_KoloradoWife_Idle,
            .anim_5 = ANIM_KoloradoWife_Idle,
            .death  = ANIM_KoloradoWife_Idle,
            .hit    = ANIM_KoloradoWife_Idle,
            .anim_8 = ANIM_KoloradoWife_Idle,
            .anim_9 = ANIM_KoloradoWife_Idle,
            .anim_A = ANIM_KoloradoWife_Idle,
            .anim_B = ANIM_KoloradoWife_Idle,
            .anim_C = ANIM_KoloradoWife_Idle,
            .anim_D = ANIM_KoloradoWife_Idle,
            .anim_E = ANIM_KoloradoWife_Idle,
            .anim_F = ANIM_KoloradoWife_Idle,
        },
        .tattle = MSG_NpcTattle_KoloradoWife,
    },
};

StaticNpc N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .settings = &N(NpcSettings_ChuckQuizmo),
    .pos = { 300.0f, 0.0f, 330.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .initVarCount = 1,
    .initVar = { .value = 0x00020201 },
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_ChuckQuizmo_Idle,
        .walk   = ANIM_ChuckQuizmo_Walk,
        .run    = ANIM_ChuckQuizmo_Run,
        .chase  = ANIM_ChuckQuizmo_Run,
        .anim_4 = ANIM_ChuckQuizmo_Idle,
        .anim_5 = ANIM_ChuckQuizmo_Idle,
        .death  = ANIM_ChuckQuizmo_Still,
        .hit    = ANIM_ChuckQuizmo_Still,
        .anim_8 = ANIM_ChuckQuizmo_Run,
        .anim_9 = ANIM_ChuckQuizmo_Run,
        .anim_A = ANIM_ChuckQuizmo_Run,
        .anim_B = ANIM_ChuckQuizmo_Run,
        .anim_C = ANIM_ChuckQuizmo_Run,
        .anim_D = ANIM_ChuckQuizmo_Run,
        .anim_E = ANIM_ChuckQuizmo_Run,
        .anim_F = ANIM_ChuckQuizmo_Run,
    },
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_Parakarry_Crisis)),
    NPC_GROUP(N(NpcData_KoopaKoot)),
    NPC_GROUP(N(NpcData_Fuzzy_02)),
    NPC_GROUP(N(NpcData_Fuzzy_03)),
    {}
};

NpcGroupList N(NormalNPCs) = {
    NPC_GROUP(N(NpcData_Parakarry_Normal)),
    NPC_GROUP(N(NpcData_KoopaKoot)),
    NPC_GROUP(N(NpcData_Fuzzy_04)),
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    {}
};

NpcGroupList N(EpilogueNPCs) = {
    NPC_GROUP(N(NpcData_Parakarry)),
    {}
};
