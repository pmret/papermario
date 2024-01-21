API_CALLABLE(N(func_802440FC_80497C)) {
    if (isInitialCall) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o283)), CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o279)), CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_dr_yuka)), CUSTOM_GFX_NONE, ENV_TINT_REMAP);
        mdl_set_remap_tint_params(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }
    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    mdl_set_remap_tint_params(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 64) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802441EC_804A6C)) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
        script->functionTemp[2] = 64;
        script->functionTemp[1] = 0;
    }
    if (script->functionTemp[1] == 0) {
        script->functionTemp[0] += 4;
        script->functionTemp[2] += 4;
        if (script->functionTemp[0] > 127) {
            script->functionTemp[0] = 127;
        }
        if (script->functionTemp[2] > 127) {
            script->functionTemp[2] = 127;
        }
        if (script->functionTemp[0] == 127 && (script->functionTemp[2] == script->functionTemp[0])) {
            script->functionTemp[1] = 1;
        }
    } else {
        script->functionTemp[0] -= 4;
        script->functionTemp[2] -= 4;
        if (script->functionTemp[0] < 64) {
            script->functionTemp[0] = 64;
        }
        if (script->functionTemp[2] < 0) {
            script->functionTemp[2] = 0;
        }
    }
    mdl_set_remap_tint_params(
        script->functionTemp[0], script->functionTemp[0], script->functionTemp[0],
        script->functionTemp[2], script->functionTemp[2], script->functionTemp[2]
    );
    if (script->functionTemp[0] == 64 && script->functionTemp[2] == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_80244308_804B88)) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
    }
    script->functionTemp[0] += 4;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    mdl_set_remap_tint_params(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o283)), CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o279)), CUSTOM_GFX_NONE, ENV_TINT_NONE);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_dr_yuka)), CUSTOM_GFX_NONE, ENV_TINT_NONE);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// identical to hos_06 func
// TODO may not be motionBlurFlame
API_CALLABLE(N(func_802443E0_804C60)) {
    EffectInstance* effects[3];
    Matrix4f sp28, sp68;
    f32 tx;
    f32 ty;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 180;
        script->functionTempPtr[1] = (EffectInstance*) evt_get_variable(script, ArrayVar(3));
        script->functionTempPtr[2] = (EffectInstance*) evt_get_variable(script, ArrayVar(4));
        script->functionTempPtr[3] = (EffectInstance*) evt_get_variable(script, ArrayVar(5));
    }

    effects[0] = script->functionTempPtr[1];
    effects[1] = script->functionTempPtr[2];
    effects[2] = script->functionTempPtr[3];
    temp_f30 = (sin_deg(script->functionTemp[0]) * 10.0f) + 10.0f;
    temp_f28 = (sin_deg(script->functionTemp[0]) * 25.0f) + 10.0f;
    temp_f24 = script->functionTemp[0] * 10;

    for (i = 0; i < ARRAY_COUNT(effects); i++) {
        guRotateF(sp28, -gCameras[gCurrentCameraID].curYaw, 0.0f, 1.0f, 0.0f);
        guRotateF(sp68, i * 120, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp68, sp28, sp28);
        tx = temp_f30 * sin_deg(temp_f24);
        ty = temp_f28 * cos_deg(temp_f24);
        guTranslateF(sp68, tx, ty, 0.0f);
        guMtxCatF(sp68, sp28, sp28);
        effects[i]->data.motionBlurFlame->pos.x = sp28[3][0];
        effects[i]->data.motionBlurFlame->pos.y = sp28[3][1];
        effects[i]->data.motionBlurFlame->pos.z = sp28[3][2];
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 16) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            effects[i]->data.motionBlurFlame->unk_4C = script->functionTemp[0];
        }
    }

    if (script->functionTemp[0] < 0) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            remove_effect(effects[i]);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// identical to hos_06 func
API_CALLABLE(N(func_802446AC_804F2C)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO effect may be wrong
    effect->data.energyOrbWave->unk_1C++;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Merlon_AnimateDiscoBall) = {
    Call(EnableModel, MODEL_mirrorball, TRUE)
    Set(LVar0, 328)
    Set(LVar1, 0)
    Loop(50)
        Add(LVar0, -2)
        Call(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        Add(LVar1, 3)
        IfGe(LVar1, 360)
            Add(LVar1, -360)
        EndIf
        Call(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        Wait(1)
    EndLoop
    Loop(0)
        Call(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        Add(LVar1, 3)
        IfGe(LVar1, 360)
            Add(LVar1, -360)
        EndIf
        Call(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        Wait(1)
        IfEq(ArrayVar(6), 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(150)
        Add(LVar0, 0)
        Call(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        Add(LVar1, 6)
        IfGe(LVar1, 360)
            Add(LVar1, -360)
        EndIf
        Call(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        Wait(1)
    EndLoop
    Loop(0)
        Call(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        Add(LVar1, 3)
        IfGe(LVar1, 360)
            Add(LVar1, -360)
        EndIf
        Call(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        Wait(1)
        IfEq(ArrayVar(6), 2)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(50)
        Add(LVar0, 2)
        Call(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        Add(LVar1, 3)
        IfGe(LVar1, 360)
            Add(LVar1, -360)
        EndIf
        Call(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        Wait(1)
    EndLoop
    Call(EnableModel, MODEL_mirrorball, FALSE)
    Return
    End
};

EvtScript N(EVS_Merlon_ReadFortuneFX) = {
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    Call(GetModelCenter, MODEL_tama)
    Call(PlaySoundAt, SOUND_LRAW_CRYSTAL_BALL_GLOW, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 0, LVar0, LVar1, LVar2, Float(1.0), -1)
    Set(ArrayVar(1), LVarF)
    Wait(30)
    Set(ArrayVar(6), 0)
    Exec(N(EVS_Merlon_AnimateDiscoBall))
    Wait(30)
    Thread
        Call(N(func_802440FC_80497C))
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(GetCamDistance, CAM_DEFAULT, LVar0)
    IfGt(LVar0, 0)
        SetF(LVar0, Float(284.6))
    Else
        SetF(LVar0, Float(-284.6))
    EndIf
    Call(SetCamDistance, CAM_DEFAULT, LVar0)
    Call(GetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    SetF(LVar1, Float(-11.0))
    Call(SetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(ArrayVar(6), 1)
    PlayEffect(EFFECT_MERLIN_HOUSE_STARS, 0, -298, 21, -330)
    Set(ArrayVar(2), LVarF)
    Call(GetModelCenter, MODEL_tama)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(3), LVarF)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(4), LVarF)
    PlayEffect(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    Set(ArrayVar(5), LVarF)
    Thread
        Call(N(func_802443E0_804C60))
    EndThread
    Wait(50)
    Call(GetModelCenter, MODEL_tama)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(30)
    Call(GetModelCenter, MODEL_tama)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(30)
    Thread
        Call(N(func_802441EC_804A6C))
    EndThread
    Call(GetModelCenter, MODEL_tama)
    Call(PlaySoundAt, SOUND_CRYSTAL_BALL_WAVE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, Float(0.5), 20)
    Wait(70)
    Call(DismissEffect, ArrayVar(2))
    Wait(40)
    Call(PlaySoundAt, SOUND_LRAW_CRYSTAL_BALL_GLOW | SOUND_ID_TRIGGER_CHANGE_SOUND, 0, LVar0, LVar1, LVar2)
    Call(N(func_802446AC_804F2C), ArrayVar(1))
    Wait(15)
    Call(DismissEffect, ArrayVar(1))
    Thread
        Call(N(func_80244308_804B88))
    EndThread
    Wait(46)
    Set(ArrayVar(6), 2)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    Return
    End
};

EvtScript N(EVS_Merlon_GiveHint) = {
    Call(DisablePlayerInput, TRUE)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0036)
    Call(ShowCoinCounter, TRUE)
    Call(ShowChoice, MSG_Choice_000D)
    IfNe(LVar0, 0)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0039)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(N(GetPlayerCoins))
    IfLt(LVar0, 5)
        Call(ShowCoinCounter, FALSE)
        Call(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003A)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(AddCoin, -5)
    Call(ShowCoinCounter, FALSE)
    Call(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0037)
    Call(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    Wait(10)
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Gather1, ANIM_Merlon_Gather1, 0, MSG_MAC_Plaza_0038)
    Exec(N(EVS_PlaySpellcastSong))
    Wait(20)
    IfEq(MV_FortuneFXHandles, 0)
        MallocArray(20, MV_FortuneFXHandles)
    EndIf
    UseArray(MV_FortuneFXHandles)
    ExecWait(N(EVS_Merlon_ReadFortuneFX))
    Wait(20)
    Exec(N(EVS_ResetMusicAfterFortune))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            Set(LVar0, MSG_MerlonHint_0000)
        CaseLt(STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
            Set(LVar0, MSG_MerlonHint_0001)
        CaseLt(STORY_CH1_KOOPER_JOINED_PARTY)
            Set(LVar0, MSG_MerlonHint_0002)
        CaseLt(STORY_CH1_SPOTTED_BY_KOOPA_BROS)
            Set(LVar0, MSG_MerlonHint_0003)
        CaseLt(STORY_CH1_BOMBETTE_JOINED_PARTY)
            Set(LVar0, MSG_MerlonHint_0004)
        CaseLt(STORY_CH1_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MerlonHint_0005)
        CaseLt(STORY_CH2_PARAKARRY_JOINED_PARTY)
            IfEq(GF_MAC03_BombedRock, FALSE)
                Set(LVar0, MSG_MerlonHint_0006)
            Else
                Set(LVar0, MSG_MerlonHint_0007)
            EndIf
        CaseLt(STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT)
            Set(LVar0, MSG_MerlonHint_0008)
        CaseLt(STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
            Set(LVar0, MSG_MerlonHint_0009)
        CaseLt(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            Set(LVar0, MSG_MerlonHint_000A)
        CaseLt(STORY_CH2_BOUGHT_SECRET_ITEMS)
            Set(LVar0, MSG_MerlonHint_000B)
        CaseLt(STORY_CH2_GOT_PULSE_STONE)
            Set(LVar0, MSG_MerlonHint_000C)
        CaseLt(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            Set(LVar0, MSG_MerlonHint_000D)
        CaseLt(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            Set(LVar0, MSG_MerlonHint_000E)
        CaseLt(STORY_CH2_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MerlonHint_000F)
        CaseLt(STORY_UNUSED_FFFFFFCC)
            Set(LVar0, MSG_MerlonHint_0010)
        CaseLt(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            Set(LVar0, MSG_MerlonHint_0011)
        CaseLt(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            Set(LVar0, MSG_MerlonHint_0012)
        CaseLt(STORY_CH3_ENTERED_BOOS_MANSION)
            Set(LVar0, MSG_MerlonHint_0013)
        CaseLt(STORY_CH3_GOT_WEIGHT)
            Set(LVar0, MSG_MerlonHint_0014)
        CaseLt(STORY_CH3_WEIGHED_DOWN_CHANDELIER)
            Set(LVar0, MSG_MerlonHint_0015)
        CaseLt(STORY_CH3_GOT_BOO_PORTRAIT)
            Set(LVar0, MSG_MerlonHint_0016)
        CaseLt(STORY_CH3_BOW_JOINED_PARTY)
            Set(LVar0, MSG_MerlonHint_0017)
        CaseLt(STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
            Set(LVar0, MSG_MerlonHint_0018)
        CaseLt(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            IfEq(GF_DGB06_Chest_CastleKey1, FALSE)
                Set(LVar0, MSG_MerlonHint_0019)
                BreakSwitch
            EndIf
            IfEq(GF_DGB12_Chest_CastleKey1, FALSE)
                Set(LVar0, MSG_MerlonHint_001A)
                BreakSwitch
            EndIf
            IfEq(GF_DGB16_Item_CastleKey1, FALSE)
                Set(LVar0, MSG_MerlonHint_001B)
                BreakSwitch
            EndIf
            Set(LVar0, MSG_MerlonHint_001C)
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MerlonHint_001D)
        CaseLt(STORY_CH4_FOUND_HIDDEN_DOOR)
            Set(LVar0, MSG_MerlonHint_001E)
        CaseLt(STORY_CH4_GOT_STOREROOM_KEY)
            Set(LVar0, MSG_MerlonHint_001F)
        CaseLt(STORY_CH4_GOT_TOY_TRAIN)
            Set(LVar0, MSG_MerlonHint_0020)
        CaseLt(STORY_CH4_RETURNED_TOY_TRAIN)
            Set(LVar0, MSG_MerlonHint_0021)
        CaseLt(STORY_CH4_GOT_FRYING_PAN)
            Set(LVar0, MSG_MerlonHint_0022)
        CaseLt(STORY_CH4_GOT_TAYCE_TS_CAKE)
            Set(LVar0, MSG_MerlonHint_0023)
        CaseLt(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            Set(LVar0, MSG_MerlonHint_0024)
        CaseLt(STORY_CH4_SOLVED_COLOR_PUZZLE)
            Set(LVar0, MSG_MerlonHint_0025)
        CaseLt(STORY_CH4_DEFEATED_LANTERN_GHOST)
            Set(LVar0, MSG_MerlonHint_0026)
        CaseLt(STORY_CH4_WATT_JOINED_PARTY)
            Set(LVar0, MSG_MerlonHint_0027)
        CaseLt(STORY_CH4_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MerlonHint_0028)
        CaseLt(STORY_CH5_DEFEATED_FUZZIPEDE)
            Set(LVar0, MSG_MerlonHint_0029)
        CaseLt(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            Set(LVar0, MSG_MerlonHint_002A)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Set(LVar0, MSG_MerlonHint_002B)
        CaseLt(STORY_CH5_SUSHIE_JOINED_PARTY)
            Set(LVar0, MSG_MerlonHint_002C)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Set(LVar0, MSG_MerlonHint_002D)
        CaseLt(STORY_CH5_MOVED_RAVEN_STATUE)
            Set(LVar0, MSG_MerlonHint_002E)
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            Set(LVar0, MSG_MerlonHint_002F)
        CaseLt(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            Set(LVar0, MSG_MerlonHint_0030)
        CaseLt(STORY_CH5_GOT_ULTRA_HAMMER)
            Set(LVar0, MSG_MerlonHint_0031)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MerlonHint_0032)
        CaseLt(STORY_CH5_TRADED_VASE_FOR_SEED)
            Set(LVar0, MSG_MerlonHint_0033)
        CaseLt(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            Set(LVar0, MSG_MerlonHint_0034)
        CaseLt(STORY_CH6_GOT_MAGICAL_BEAN)
            Set(LVar0, MSG_MerlonHint_0035)
        CaseLt(STORY_CH6_GOT_FERTILE_SOIL)
            Set(LVar0, MSG_MerlonHint_0036)
        CaseRange(STORY_CH6_GOT_FERTILE_SOIL, STORY_CH6_GOT_WATER_STONE)
            IfEq(GF_FLO07_Item_CrystalBerry, FALSE)
                IfEq(GF_FLO10_LilyRequestedWaterStone, FALSE)
                    Set(LVar0, MSG_MerlonHint_0037)
                Else
                    Set(LVar0, MSG_MerlonHint_0038)
                EndIf
            Else
                Set(LVar0, MSG_MerlonHint_0039)
            EndIf
        CaseLt(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            Set(LVar0, MSG_MerlonHint_003A)
        CaseLt(STORY_CH6_GREW_MAGIC_BEANSTALK)
            Set(LVar0, MSG_MerlonHint_003B)
        CaseLt(STORY_CH6_STAR_SPIRIT_RESCUED)
            Set(LVar0, MSG_MerlonHint_003C)
        CaseLt(STORY_CH7_ARRIVED_AT_SHIVER_CITY)
            Set(LVar0, MSG_MerlonHint_003D)
        CaseLt(STORY_CH7_MAYOR_MURDER_SOLVED)
            Set(LVar0, MSG_MerlonHint_003E)
        CaseLt(STORY_CH7_GOT_SNOWMAN_SCARF)
            Set(LVar0, MSG_MerlonHint_003F)
        CaseLt(STORY_CH7_GOT_SNOWMAN_BUCKET)
            Set(LVar0, MSG_MerlonHint_0040)
        CaseLt(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            Set(LVar0, MSG_MerlonHint_0041)
        CaseLt(STORY_CH7_GOT_STAR_STONE)
            Set(LVar0, MSG_MerlonHint_0042)
        CaseLt(STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE)
            Set(LVar0, MSG_MerlonHint_0043)
        CaseLt(STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            Set(LVar0, MSG_MerlonHint_0044)
        CaseLt(STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
            Set(LVar0, MSG_MerlonHint_0045)
        CaseLt(STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
            Set(LVar0, MSG_MerlonHint_0046)
        CaseLt(STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
            Set(LVar0, MSG_MerlonHint_0047)
        CaseLt(STORY_CH7_STAR_SPRIT_DEPARTED)
            Set(LVar0, MSG_MerlonHint_0048)
        CaseLt(STORY_CH8_REACHED_STAR_HAVEN)
            Set(LVar0, MSG_MerlonHint_0049)
        CaseLt(STORY_CH8_REACHED_BOWSERS_CASTLE)
            Set(LVar0, MSG_MerlonHint_004A)
        CaseLt(STORY_CH8_REACHED_PEACHS_CASTLE)
            IfNe(GB_KPA81_BowserDoorState, 2)
                Set(LVar0, MSG_MerlonHint_004B)
                BreakSwitch
            EndIf
            IfNe(GB_KPA82_BowserDoorState, 1)
                Set(LVar0, MSG_MerlonHint_004C)
                BreakSwitch
            EndIf
            Set(LVar0, MSG_MerlonHint_004D)
        CaseLt(STORY_EPILOGUE)
            Set(LVar0, MSG_MerlonHint_004E)
    EndSwitch
    Call(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
