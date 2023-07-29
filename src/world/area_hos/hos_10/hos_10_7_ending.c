#include "hos_10.h"
#include "effects.h"

API_CALLABLE(N(NpcOrbitPlayerPos)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->varTable[15] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        script->functionTemp[3] = 0;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    switch (script->functionTemp[0]) {
        case 0:
            npc->pos.x = playerStatus->pos.x;
            npc->pos.y = playerStatus->pos.y;
            npc->pos.z = playerStatus->pos.z;
            npc->moveToPos.x =  script->functionTemp[3] * 3;
            npc->moveToPos.y = 3.0f;
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, 70.0f, npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f);
            if ((script->functionTemp[3] + script->functionTemp[2]) % 13 == 0)  {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->functionTemp[3] > 350) {
                script->functionTemp[0] = 1;
                script->functionTemp[3] = 0;
            }
            break;
        case 1:
            npc->pos.x = playerStatus->pos.x;
            npc->pos.y = playerStatus->pos.y;
            npc->pos.z = playerStatus->pos.z;
            npc->moveToPos.x = script->functionTemp[3] * 3;
            npc->moveToPos.y = 3.0f;
            add_vec2D_polar(
                &npc->pos.x,
                &npc->pos.z,
                (((190 - script->functionTemp[3]) / 190.0f) * 67.0f) + 3.0f,
                npc->moveToPos.x + (script->functionTemp[2] * 51) + 153.0f
            );
            if ((script->functionTemp[3] + script->functionTemp[2]) % 13 == 0) {
                fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
            }
            if (script->functionTemp[3] > 190) {
                return ApiStatus_DONE2;
            }
            break;
    }

    script->functionTemp[3]++;
    npc->moveToPos.x += npc->moveToPos.y;
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SetHaloPos)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    f32 x, y, z;

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    effect->data.endingDecals->pos.x = x;
    effect->data.endingDecals->pos.y = y;
    effect->data.endingDecals->pos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetHaloScale)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.endingDecals->scale = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetHaloAlpha)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    effect->data.endingDecals->haloAlpha = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearCurrentPartner)) {
    gPlayerData.curPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FadeScreenToWhite)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 7;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}

Vec3f N(PlayerPath)[] = {
    { -130.0,     0.0, 1300.0 },
    {   20.0,  -100.0, 1250.0 },
    {  170.0,    50.0, 1000.0 },
    {  120.0,   100.0,  400.0 },
    {    0.0,     0.0, -450.0 },
};

Vec3f N(EldstarPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -150.0,    70.0,  500.0 },
    {    0.0,    30.0, 1200.0 },
    {  200.0,    30.0, 1800.0 },
};

Vec3f N(MisstarPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -200.0,  -100.0,  300.0 },
    {  -50.0,   -50.0,  800.0 },
    {   30.0,    80.0, 1900.0 },
};

Vec3f N(SkolarPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -300.0,   -60.0,  300.0 },
    {    0.0,   -20.0, 1000.0 },
    {  -50.0,    40.0, 1800.0 },
};

Vec3f N(MamarPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -170.0,   -20.0,  200.0 },
    {  170.0,    60.0,  500.0 },
    { -120.0,   -20.0, 1000.0 },
    {   50.0,    50.0, 1800.0 },
};

Vec3f N(KalmarPath)[] = {
    {    0.0,     0.0, -350.0 },
    {  300.0,   200.0,  350.0 },
    {  100.0,   120.0, 1000.0 },
    {  -30.0,    10.0, 1800.0 },
};

Vec3f N(MuskularPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -100.0,     0.0,  200.0 },
    {    0.0,  -150.0,  500.0 },
    {  200.0,     0.0, 1000.0 },
    {    0.0,   100.0, 1800.0 },
};

Vec3f N(KlevarPath)[] = {
    {    0.0,     0.0, -350.0 },
    {  200.0,   -60.0,  200.0 },
    {  500.0,  -150.0,  500.0 },
    {  180.0,   -50.0, 1000.0 },
    {  -60.0,    75.0, 1800.0 },
};

Vec3f N(TwinkPath)[] = {
    {    0.0,     0.0, -350.0 },
    { -150.0,    70.0,  500.0 },
    {    0.0,    30.0, 1200.0 },
    {   40.0,    30.0, 1600.0 },
};

EvtScript N(EVS_Scene_CastleDescending) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(PlaySound, SOUND_A4 | SOUND_ID_TRIGGER_CHANGE_SOUND)
    EVT_CALL(SetPlayerPos, -130, 200, 1300)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -150, 200, 1300)
    EVT_CALL(SetNpcYaw, NPC_PARTNER, 90)
    EVT_CALL(EnableModel, MODEL_o2, FALSE)
    EVT_CALL(EnableGroup, MODEL_kumo, FALSE)
    EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_CALL(TranslateGroup, MODEL_castle, 0, -2500, 0)
    EVT_CALL(ScaleGroup, MODEL_castle, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_PLAY_EFFECT(EFFECT_ENDING_DECALS, 2, 0, 35, 70, EVT_FLOAT(7.0), MV_BubbleFXPtr)
    EVT_CALL(N(SetHaloAlpha), MV_BubbleFXPtr, 128)
    EVT_CHILD_THREAD
        EVT_PLAY_EFFECT(EFFECT_ENDING_DECALS, 2, 0, 0, 0, EVT_FLOAT(10.0), MV_Unk_01)
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 12)
            EVT_ADD(LVar2, 60)
            EVT_CALL(N(SetHaloPos), MV_Unk_01, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_SETF(LVar0, -2250)
        EVT_LOOP(1500)
            EVT_CALL(TranslateModel, MODEL_o3, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(1.0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.0))
        EVT_CALL(PlayerJump1, -130, 0, 1300, 250)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_PARTNER, -150, 0, 1300, 250)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Peach, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Peach, -100, 0, 1300, 250)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Twink, EVT_FLOAT(0.0))
        EVT_CALL(NpcJump0, NPC_Twink, -130, 60, 1300, 250)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Eldstar, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Mamar, 1, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Skolar, 2, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Muskular, 3, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Misstar, 4, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Klevar, 5, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(NpcOrbitPlayerPos), NPC_Kalmar, 6, 0)
    EVT_END_THREAD
    EVT_WAIT(350)
    EVT_THREAD
        EVT_CALL(LoadPath, 190, EVT_PTR(N(PlayerPath)), ARRAY_COUNT(N(PlayerPath)), EASING_LINEAR)
        EVT_LABEL(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 1)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 20, 190, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_SETF(LVar1, -20)
            EVT_MULF(LVar1, LVar0)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_ADDF(LVar2, LVar1)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 20, 190, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_SETF(LVar1, 30)
            EVT_MULF(LVar1, LVar0)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_ADDF(LVar2, LVar1)
            EVT_CALL(SetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 20, 190, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_SETF(LVar1, 60)
            EVT_MULF(LVar1, LVar0)
            EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
            EVT_ADDF(LVar3, LVar1)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar2, LVar3, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 5, 190, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_CALL(SetNpcScale, NPC_PARTNER, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Peach, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Twink, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Eldstar, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Mamar, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Skolar, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Muskular, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Misstar, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Klevar, LVar0, LVar0, LVar0)
            EVT_CALL(SetNpcScale, NPC_Kalmar, LVar0, LVar0, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 1000, 50, 190, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_DIVF(LVar0, 100)
            EVT_CALL(N(SetHaloScale), MV_Unk_01, LVar0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(290)
    EVT_CALL(GotoMap, EVT_PTR("osr_02"), osr_02_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeNpcSparkleTrail) = {
    EVT_CHILD_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar1, LVar2, LVar3, 20)
            EVT_WAIT(6)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar1, LVar2, LVar3, 40)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_IF_GE(LVar3, 1800)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_SpiritsFlyingAway) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(EnableModel, MODEL_o2, FALSE)
    EVT_CALL(EnableModel, MODEL_nagare, FALSE)
    EVT_CALL(TranslateGroup, MODEL_castle, 0, -2500, 0)
    EVT_CALL(ScaleGroup, MODEL_castle, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_PLAY_EFFECT(EFFECT_ENDING_DECALS, 2, 0, 35, 70, EVT_FLOAT(7.0), LVarA)
    EVT_CALL(N(SetHaloAlpha), LVarA, 128)
    EVT_CALL(EnableTexPanning, MODEL_k2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k7, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k5, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k9, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_k12, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_SET(LVar0, NPC_Eldstar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(EldstarPath)), ARRAY_COUNT(N(EldstarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Eldstar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(50)
        EVT_SET(LVar0, NPC_Misstar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(MisstarPath)), ARRAY_COUNT(N(MisstarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(100)
        EVT_SET(LVar0, NPC_Skolar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(SkolarPath)), ARRAY_COUNT(N(SkolarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Skolar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(150)
        EVT_SET(LVar0, NPC_Mamar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(MamarPath)), ARRAY_COUNT(N(MamarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Mamar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(200)
        EVT_SET(LVar0, NPC_Kalmar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(KalmarPath)), ARRAY_COUNT(N(KalmarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Kalmar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(250)
        EVT_SET(LVar0, NPC_Muskular)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(MuskularPath)), ARRAY_COUNT(N(MuskularPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Muskular, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(300)
        EVT_SET(LVar0, NPC_Klevar)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(KlevarPath)), ARRAY_COUNT(N(KlevarPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Klevar, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(450)
        EVT_SET(LVar0, NPC_Twink)
        EVT_EXEC(N(EVS_MakeNpcSparkleTrail))
        EVT_CALL(LoadPath, 75, EVT_PTR(N(TwinkPath)), ARRAY_COUNT(N(TwinkPath)), EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_CALL(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(20)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
        EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
        EVT_WAIT(50)
        EVT_CALL(InterpNpcYaw, NPC_Twink, 90, 0)
        EVT_CALL(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
        EVT_WAIT(10)
        EVT_CALL(NpcFlyTo, NPC_Twink, 100, 60, 1800, 20, -10, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SETF(LVar0, -2250)
        EVT_LOOP(1500)
            EVT_CALL(TranslateModel, MODEL_o3, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(1.5))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SETF(LVar0, -2700)
        EVT_LOOP(1200)
            EVT_CALL(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            EVT_ADDF(LVar0, EVT_FLOAT(2.5))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(840)
        EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_END_THREAD
    EVT_WAIT(800)
    EVT_CALL(N(FadeScreenToWhite))
    EVT_WAIT(90)
    EVT_CALL(N(ClearCurrentPartner))
    EVT_CALL(GotoMapSpecial, EVT_PTR("kmr_20"), kmr_20_ENTRY_2, TRANSITION_OUTRO_END_SCENE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
