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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(PlaySound, SOUND_KPA_LIGHT_RAYS | SOUND_ID_TRIGGER_CHANGE_SOUND)
    Call(SetPlayerPos, -130, 200, 1300)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcPos, NPC_PARTNER, -150, 200, 1300)
    Call(SetNpcYaw, NPC_PARTNER, 90)
    Call(EnableModel, MODEL_o2, FALSE)
    Call(EnableGroup, MODEL_kumo, FALSE)
    Call(EnableModel, MODEL_nagare, FALSE)
    Call(TranslateGroup, MODEL_castle, 0, -2500, 0)
    Call(ScaleGroup, MODEL_castle, Float(0.4), Float(0.4), Float(0.4))
    PlayEffect(EFFECT_ENDING_DECALS, 2, 0, 35, 70, Float(7.0), MV_BubbleFXPtr)
    Call(N(SetHaloAlpha), MV_BubbleFXPtr, 128)
    ChildThread
        PlayEffect(EFFECT_ENDING_DECALS, 2, 0, 0, 0, Float(10.0), MV_Unk_01)
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar1, 12)
            Add(LVar2, 60)
            Call(N(SetHaloPos), MV_Unk_01, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndChildThread
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPitch, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        SetF(LVar0, -2250)
        Loop(1500)
            Call(TranslateModel, MODEL_o3, 0, LVar0, 0)
            AddF(LVar0, Float(1.0))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(SetPlayerJumpscale, Float(0.0))
        Call(PlayerJump1, -130, 0, 1300, 250)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_PARTNER, Float(0.0))
        Call(NpcJump0, NPC_PARTNER, -150, 0, 1300, 250)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_Peach, Float(0.0))
        Call(NpcJump0, NPC_Peach, -100, 0, 1300, 250)
    EndThread
    Thread
        Call(SetNpcJumpscale, NPC_Twink, Float(0.0))
        Call(NpcJump0, NPC_Twink, -130, 60, 1300, 250)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Eldstar, 0, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Mamar, 1, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Skolar, 2, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Muskular, 3, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Misstar, 4, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Klevar, 5, 0)
    EndThread
    Thread
        Call(N(NpcOrbitPlayerPos), NPC_Kalmar, 6, 0)
    EndThread
    Wait(350)
    Thread
        Call(LoadPath, 190, Ref(N(PlayerPath)), ARRAY_COUNT(N(PlayerPath)), EASING_LINEAR)
        Label(0)
            Call(GetNextPathPos)
            Call(SetPlayerPos, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 1)
                Goto(0)
            EndIf
    EndThread
    Thread
        Call(MakeLerp, 100, 20, 190, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            SetF(LVar1, -20)
            MulF(LVar1, LVar0)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            AddF(LVar2, LVar1)
            Call(SetNpcPos, NPC_PARTNER, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 100, 20, 190, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            SetF(LVar1, 30)
            MulF(LVar1, LVar0)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            AddF(LVar2, LVar1)
            Call(SetNpcPos, NPC_Peach, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 100, 20, 190, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            SetF(LVar1, 60)
            MulF(LVar1, LVar0)
            Call(GetPlayerPos, LVar2, LVar3, LVar4)
            AddF(LVar3, LVar1)
            Call(SetNpcPos, NPC_Twink, LVar2, LVar3, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 100, 5, 190, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            Call(SetNpcScale, NPC_PARTNER, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Peach, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Twink, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Eldstar, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Mamar, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Skolar, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Muskular, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Misstar, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Klevar, LVar0, LVar0, LVar0)
            Call(SetNpcScale, NPC_Kalmar, LVar0, LVar0, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(MakeLerp, 1000, 50, 190, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, 100)
            Call(N(SetHaloScale), MV_Unk_01, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(290)
    Call(GotoMap, Ref("osr_02"), osr_02_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeNpcSparkleTrail) = {
    ChildThread
        Loop(30)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            PlayEffect(EFFECT_SPARKLES, 3, LVar1, LVar2, LVar3, 20)
            Wait(6)
        EndLoop
    EndChildThread
    ChildThread
        Loop(30)
            Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
            Add(LVar1, 20)
            PlayEffect(EFFECT_SPARKLES, 4, LVar1, LVar2, LVar3, 40)
            Wait(8)
        EndLoop
    EndChildThread
    Loop(0)
        Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        IfGe(LVar3, 1800)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_SpiritsFlyingAway) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(EnableModel, MODEL_o2, FALSE)
    Call(EnableModel, MODEL_nagare, FALSE)
    Call(TranslateGroup, MODEL_castle, 0, -2500, 0)
    Call(ScaleGroup, MODEL_castle, Float(0.4), Float(0.4), Float(0.4))
    PlayEffect(EFFECT_ENDING_DECALS, 2, 0, 35, 70, Float(7.0), LVarA)
    Call(N(SetHaloAlpha), LVarA, 128)
    Call(EnableTexPanning, MODEL_k2, TRUE)
    Call(EnableTexPanning, MODEL_k7, TRUE)
    Call(EnableTexPanning, MODEL_k1, TRUE)
    Call(EnableTexPanning, MODEL_k5, TRUE)
    Call(EnableTexPanning, MODEL_k9, TRUE)
    Call(EnableTexPanning, MODEL_k12, TRUE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Set(LVar0, NPC_Eldstar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(EldstarPath)), ARRAY_COUNT(N(EldstarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Eldstar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(50)
        Set(LVar0, NPC_Misstar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(MisstarPath)), ARRAY_COUNT(N(MisstarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(100)
        Set(LVar0, NPC_Skolar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(SkolarPath)), ARRAY_COUNT(N(SkolarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Skolar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(150)
        Set(LVar0, NPC_Mamar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(MamarPath)), ARRAY_COUNT(N(MamarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Mamar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(200)
        Set(LVar0, NPC_Kalmar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(KalmarPath)), ARRAY_COUNT(N(KalmarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Kalmar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(250)
        Set(LVar0, NPC_Muskular)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(MuskularPath)), ARRAY_COUNT(N(MuskularPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Muskular, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(300)
        Set(LVar0, NPC_Klevar)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(KlevarPath)), ARRAY_COUNT(N(KlevarPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Klevar, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Wait(450)
        Set(LVar0, NPC_Twink)
        Exec(N(EVS_MakeNpcSparkleTrail))
        Call(LoadPath, 75, Ref(N(TwinkPath)), ARRAY_COUNT(N(TwinkPath)), EASING_LINEAR)
        Loop(0)
            Call(GetNextPathPos)
            Call(SetNpcPos, NPC_Twink, LVar1, LVar2, LVar3)
            Wait(1)
            IfEq(LVar0, 0)
                BreakLoop
            EndIf
        EndLoop
        Wait(20)
        Call(InterpNpcYaw, NPC_Twink, 270, 0)
        Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Back)
        Wait(50)
        Call(InterpNpcYaw, NPC_Twink, 90, 0)
        Call(SetNpcAnimation, NPC_Twink, ANIM_Twink_Idle)
        Wait(10)
        Call(NpcFlyTo, NPC_Twink, 100, 60, 1800, 20, -10, EASING_LINEAR)
    EndThread
    Thread
        SetF(LVar0, -2250)
        Loop(1500)
            Call(TranslateModel, MODEL_o3, 0, LVar0, 0)
            AddF(LVar0, Float(1.5))
            Wait(1)
        EndLoop
    EndThread
    Thread
        SetF(LVar0, -2700)
        Loop(1200)
            Call(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            AddF(LVar0, Float(2.5))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(840)
        Call(FadeOutMusic, 0, 3000)
    EndThread
    Wait(800)
    Call(N(FadeScreenToWhite))
    Wait(90)
    Call(N(ClearCurrentPartner))
    Call(GotoMapSpecial, Ref("kmr_20"), kmr_20_ENTRY_2, TRANSITION_OUTRO_END_SCENE)
    Wait(100)
    Return
    End
};
