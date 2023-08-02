API_CALLABLE(N(func_802440FC_80497C)) {
    if (isInitialCall) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o283)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o279)), -1, FOG_MODE_3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_dr_yuka)), -1, FOG_MODE_3);
        set_model_env_color_parameters(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }
    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
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
    set_model_env_color_parameters(
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
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o283)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_o279)), -1, FOG_MODE_0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(MODEL_dr_yuka)), -1, FOG_MODE_0);
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
    EVT_CALL(EnableModel, MODEL_mirrorball, TRUE)
    EVT_SET(LVar0, 328)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50)
        EVT_ADD(LVar0, -2)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(ArrayVar(6), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(150)
        EVT_ADD(LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 6)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(ArrayVar(6), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(50)
        EVT_ADD(LVar0, 2)
        EVT_CALL(TranslateModel, MODEL_mirrorball, -590, LVar0, -646)
        EVT_ADD(LVar1, 3)
        EVT_IF_GE(LVar1, 360)
            EVT_ADD(LVar1, -360)
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_mirrorball, LVar1, 0, 1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_mirrorball, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Merlon_ReadFortuneFX) = {
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_RaiseArms)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_207, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), -1)
    EVT_SET(ArrayVar(1), LVarF)
    EVT_WAIT(30)
    EVT_SET(ArrayVar(6), 0)
    EVT_EXEC(N(EVS_Merlon_AnimateDiscoBall))
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_802440FC_80497C))
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SETF(LVar0, EVT_FLOAT(284.6))
    EVT_ELSE
        EVT_SETF(LVar0, EVT_FLOAT(-284.6))
    EVT_END_IF
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar0)
    EVT_CALL(GetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_SETF(LVar1, EVT_FLOAT(-11.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, LVar0, LVar1)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_SET(ArrayVar(6), 1)
    EVT_PLAY_EFFECT(EFFECT_MERLIN_HOUSE_STARS, 0, -298, 21, -330)
    EVT_SET(ArrayVar(2), LVarF)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(3), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(4), LVarF)
    EVT_PLAY_EFFECT(EFFECT_MOTION_BLUR_FLAME, 0, LVar0, LVar1, LVar2, 1, -1)
    EVT_SET(ArrayVar(5), LVarF)
    EVT_THREAD
        EVT_CALL(N(func_802443E0_804C60))
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 3, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(N(func_802441EC_804A6C))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, MODEL_tama)
    EVT_CALL(PlaySoundAt, SOUND_208, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 20)
    EVT_WAIT(70)
    EVT_CALL(DismissEffect, ArrayVar(2))
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAt, SOUND_207 | SOUND_ID_TRIGGER_CHANGE_SOUND, 0, LVar0, LVar1, LVar2)
    EVT_CALL(N(func_802446AC_804F2C), ArrayVar(1))
    EVT_WAIT(15)
    EVT_CALL(DismissEffect, ArrayVar(1))
    EVT_THREAD
        EVT_CALL(N(func_80244308_804B88))
    EVT_END_THREAD
    EVT_WAIT(46)
    EVT_SET(ArrayVar(6), 2)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Merlon_GiveHint) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0036)
    EVT_CALL(ShowCoinCounter, TRUE)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0039)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(GetPlayerCoins))
    EVT_IF_LT(LVar0, 5)
        EVT_CALL(ShowCoinCounter, FALSE)
        EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_003A)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(AddCoin, -5)
    EVT_CALL(ShowCoinCounter, FALSE)
    EVT_CALL(ContinueSpeech, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, MSG_MAC_Plaza_0037)
    EVT_CALL(SetNpcAnimation, NPC_Merlon, ANIM_Merlon_Gather1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Gather1, ANIM_Merlon_Gather1, 0, MSG_MAC_Plaza_0038)
    EVT_EXEC(N(EVS_PlaySpellcastSong))
    EVT_WAIT(20)
    EVT_IF_EQ(MV_FortuneFXHandles, 0)
        EVT_MALLOC_ARRAY(20, MV_FortuneFXHandles)
    EVT_END_IF
    EVT_USE_ARRAY(MV_FortuneFXHandles)
    EVT_EXEC_WAIT(N(EVS_Merlon_ReadFortuneFX))
    EVT_WAIT(20)
    EVT_EXEC(N(EVS_ResetMusicAfterFortune))
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH1_MERLIN_REVEALED_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MerlonHint_0000)
        EVT_CASE_LT(STORY_CH1_KNOCKED_SWITCH_FROM_TREE)
            EVT_SET(LVar0, MSG_MerlonHint_0001)
        EVT_CASE_LT(STORY_CH1_KOOPER_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0002)
        EVT_CASE_LT(STORY_CH1_SPOTTED_BY_KOOPA_BROS)
            EVT_SET(LVar0, MSG_MerlonHint_0003)
        EVT_CASE_LT(STORY_CH1_BOMBETTE_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0004)
        EVT_CASE_LT(STORY_CH1_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_0005)
        EVT_CASE_LT(STORY_CH2_PARAKARRY_JOINED_PARTY)
            EVT_IF_EQ(GF_MAC03_BombedRock, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_0006)
            EVT_ELSE
                EVT_SET(LVar0, MSG_MerlonHint_0007)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH2_ARRIVED_AT_DRY_DRY_DESERT)
            EVT_SET(LVar0, MSG_MerlonHint_0008)
        EVT_CASE_LT(STORY_CH2_ARRIVED_AT_DRY_DRY_OUTPOST)
            EVT_SET(LVar0, MSG_MerlonHint_0009)
        EVT_CASE_LT(STORY_CH2_SHADY_MOUSE_ENTERED_SHOP)
            EVT_SET(LVar0, MSG_MerlonHint_000A)
        EVT_CASE_LT(STORY_CH2_BOUGHT_SECRET_ITEMS)
            EVT_SET(LVar0, MSG_MerlonHint_000B)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_SET(LVar0, MSG_MerlonHint_000C)
        EVT_CASE_LT(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            EVT_SET(LVar0, MSG_MerlonHint_000D)
        EVT_CASE_LT(STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_000E)
        EVT_CASE_LT(STORY_CH2_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_000F)
        EVT_CASE_LT(STORY_UNUSED_FFFFFFCC)
            EVT_SET(LVar0, MSG_MerlonHint_0010)
        EVT_CASE_LT(STORY_CH3_ALLOWED_INTO_FOREVER_FOREST)
            EVT_SET(LVar0, MSG_MerlonHint_0011)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_BOOS_MANSION)
            EVT_SET(LVar0, MSG_MerlonHint_0012)
        EVT_CASE_LT(STORY_CH3_ENTERED_BOOS_MANSION)
            EVT_SET(LVar0, MSG_MerlonHint_0013)
        EVT_CASE_LT(STORY_CH3_GOT_WEIGHT)
            EVT_SET(LVar0, MSG_MerlonHint_0014)
        EVT_CASE_LT(STORY_CH3_WEIGHED_DOWN_CHANDELIER)
            EVT_SET(LVar0, MSG_MerlonHint_0015)
        EVT_CASE_LT(STORY_CH3_GOT_BOO_PORTRAIT)
            EVT_SET(LVar0, MSG_MerlonHint_0016)
        EVT_CASE_LT(STORY_CH3_BOW_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0017)
        EVT_CASE_LT(STORY_CH3_ARRIVED_AT_TUBBAS_MANOR)
            EVT_SET(LVar0, MSG_MerlonHint_0018)
        EVT_CASE_LT(STORY_CH3_DEFEATED_TUBBA_BLUBBA)
            EVT_IF_EQ(GF_DGB06_Chest_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_0019)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_EQ(GF_DGB12_Chest_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_001A)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_EQ(GF_DGB16_Item_CastleKey1, FALSE)
                EVT_SET(LVar0, MSG_MerlonHint_001B)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LVar0, MSG_MerlonHint_001C)
        EVT_CASE_LT(STORY_CH3_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_001D)
        EVT_CASE_LT(STORY_CH4_FOUND_HIDDEN_DOOR)
            EVT_SET(LVar0, MSG_MerlonHint_001E)
        EVT_CASE_LT(STORY_CH4_GOT_STOREROOM_KEY)
            EVT_SET(LVar0, MSG_MerlonHint_001F)
        EVT_CASE_LT(STORY_CH4_GOT_TOY_TRAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0020)
        EVT_CASE_LT(STORY_CH4_RETURNED_TOY_TRAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0021)
        EVT_CASE_LT(STORY_CH4_GOT_FRYING_PAN)
            EVT_SET(LVar0, MSG_MerlonHint_0022)
        EVT_CASE_LT(STORY_CH4_GOT_TAYCE_TS_CAKE)
            EVT_SET(LVar0, MSG_MerlonHint_0023)
        EVT_CASE_LT(STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
            EVT_SET(LVar0, MSG_MerlonHint_0024)
        EVT_CASE_LT(STORY_CH4_SOLVED_COLOR_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_0025)
        EVT_CASE_LT(STORY_CH4_DEFEATED_LANTERN_GHOST)
            EVT_SET(LVar0, MSG_MerlonHint_0026)
        EVT_CASE_LT(STORY_CH4_WATT_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_0027)
        EVT_CASE_LT(STORY_CH4_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0028)
        EVT_CASE_LT(STORY_CH5_DEFEATED_FUZZIPEDE)
            EVT_SET(LVar0, MSG_MerlonHint_0029)
        EVT_CASE_LT(STORY_CH5_REACHED_LAVA_LAVA_ISLAND)
            EVT_SET(LVar0, MSG_MerlonHint_002A)
        EVT_CASE_LT(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            EVT_SET(LVar0, MSG_MerlonHint_002B)
        EVT_CASE_LT(STORY_CH5_SUSHIE_JOINED_PARTY)
            EVT_SET(LVar0, MSG_MerlonHint_002C)
        EVT_CASE_LT(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_002D)
        EVT_CASE_LT(STORY_CH5_MOVED_RAVEN_STATUE)
            EVT_SET(LVar0, MSG_MerlonHint_002E)
        EVT_CASE_LT(STORY_CH5_RAFAEL_LEFT_NEST)
            EVT_SET(LVar0, MSG_MerlonHint_002F)
        EVT_CASE_LT(STORY_CH5_ENTERED_MT_LAVA_LAVA)
            EVT_SET(LVar0, MSG_MerlonHint_0030)
        EVT_CASE_LT(STORY_CH5_GOT_ULTRA_HAMMER)
            EVT_SET(LVar0, MSG_MerlonHint_0031)
        EVT_CASE_LT(STORY_CH5_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0032)
        EVT_CASE_LT(STORY_CH5_TRADED_VASE_FOR_SEED)
            EVT_SET(LVar0, MSG_MerlonHint_0033)
        EVT_CASE_LT(STORY_CH6_ARRIVED_AT_FLOWER_FIELDS)
            EVT_SET(LVar0, MSG_MerlonHint_0034)
        EVT_CASE_LT(STORY_CH6_GOT_MAGICAL_BEAN)
            EVT_SET(LVar0, MSG_MerlonHint_0035)
        EVT_CASE_LT(STORY_CH6_GOT_FERTILE_SOIL)
            EVT_SET(LVar0, MSG_MerlonHint_0036)
        EVT_CASE_RANGE(STORY_CH6_GOT_FERTILE_SOIL, STORY_CH6_GOT_WATER_STONE)
            EVT_IF_EQ(GF_FLO07_Item_CrystalBerry, FALSE)
                EVT_IF_EQ(GF_FLO10_LilyRequestedWaterStone, FALSE)
                    EVT_SET(LVar0, MSG_MerlonHint_0037)
                EVT_ELSE
                    EVT_SET(LVar0, MSG_MerlonHint_0038)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar0, MSG_MerlonHint_0039)
            EVT_END_IF
        EVT_CASE_LT(STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_SET(LVar0, MSG_MerlonHint_003A)
        EVT_CASE_LT(STORY_CH6_GREW_MAGIC_BEANSTALK)
            EVT_SET(LVar0, MSG_MerlonHint_003B)
        EVT_CASE_LT(STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_SET(LVar0, MSG_MerlonHint_003C)
        EVT_CASE_LT(STORY_CH7_ARRIVED_AT_SHIVER_CITY)
            EVT_SET(LVar0, MSG_MerlonHint_003D)
        EVT_CASE_LT(STORY_CH7_MAYOR_MURDER_SOLVED)
            EVT_SET(LVar0, MSG_MerlonHint_003E)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_SCARF)
            EVT_SET(LVar0, MSG_MerlonHint_003F)
        EVT_CASE_LT(STORY_CH7_GOT_SNOWMAN_BUCKET)
            EVT_SET(LVar0, MSG_MerlonHint_0040)
        EVT_CASE_LT(STORY_CH7_UNLOCKED_SHIVER_MOUNTAIN)
            EVT_SET(LVar0, MSG_MerlonHint_0041)
        EVT_CASE_LT(STORY_CH7_GOT_STAR_STONE)
            EVT_SET(LVar0, MSG_MerlonHint_0042)
        EVT_CASE_LT(STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE)
            EVT_SET(LVar0, MSG_MerlonHint_0043)
        EVT_CASE_LT(STORY_CH7_DEFEATED_MIRROR_DUPLIGHOSTS)
            EVT_SET(LVar0, MSG_MerlonHint_0044)
        EVT_CASE_LT(STORY_CH7_DEFEATED_BOMBETTE_DUPLIGHOSTS)
            EVT_SET(LVar0, MSG_MerlonHint_0045)
        EVT_CASE_LT(STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
            EVT_SET(LVar0, MSG_MerlonHint_0046)
        EVT_CASE_LT(STORY_CH7_SOLVED_ALBINO_DINO_PUZZLE)
            EVT_SET(LVar0, MSG_MerlonHint_0047)
        EVT_CASE_LT(STORY_CH7_STAR_SPRIT_DEPARTED)
            EVT_SET(LVar0, MSG_MerlonHint_0048)
        EVT_CASE_LT(STORY_CH8_REACHED_STAR_HAVEN)
            EVT_SET(LVar0, MSG_MerlonHint_0049)
        EVT_CASE_LT(STORY_CH8_REACHED_BOWSERS_CASTLE)
            EVT_SET(LVar0, MSG_MerlonHint_004A)
        EVT_CASE_LT(STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_IF_NE(GB_KPA81_BowserDoorState, 2)
                EVT_SET(LVar0, MSG_MerlonHint_004B)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_IF_NE(GB_KPA82_BowserDoorState, 1)
                EVT_SET(LVar0, MSG_MerlonHint_004C)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LVar0, MSG_MerlonHint_004D)
        EVT_CASE_LT(STORY_EPILOGUE)
            EVT_SET(LVar0, MSG_MerlonHint_004E)
    EVT_END_SWITCH
    EVT_CALL(SpeakToPlayer, NPC_Merlon, ANIM_Merlon_Talk, ANIM_Merlon_Idle, 0, LVar0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
