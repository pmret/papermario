#include "gv_01.h"
#include "sprite.h"
#include "hud_element.h"
#include "game_modes.h"
#include "sprite/player.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

s32 N(DropLetterYCurve)[] = {
    200, 170, 140, 110, 80, 50, 20, 10,
    26, 29, 30, 29, 26, 10, 0, 12,
    15, 16, 15, 11, 6, 0, 4, 3,
    1, 0,
};

s32 N(DropLastLetterYCurve)[] = {
    200, 170, 140, 110, 80, 50, 20, 0,
    12, 15, 16, 15, 11, 6, 0, 4,
    3, 1, 0,
};

API_CALLABLE(N(FadeToTitleScreen));
API_CALLABLE(N(ChangeStateToTitleScreen));

EvtScript N(EVS_DropLetter) = {
    EVT_USE_BUF(N(DropLetterYCurve))
    EVT_LOOP(ARRAY_COUNT(N(DropLetterYCurve)))
        EVT_BUF_READ1(LVar1)
        EVT_CALL(TranslateGroup, LVar0, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    //@bug not terminated!
};

EvtScript N(EVS_DropLastLetter) = {
    EVT_USE_BUF(N(DropLastLetterYCurve))
    EVT_LOOP(ARRAY_COUNT(N(DropLastLetterYCurve)))
        EVT_BUF_READ1(LVar1)
        EVT_CALL(TranslateGroup, LVar0, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    //@bug not terminated!
};

#if VERSION_PAL
// TODO: define MODEL_ constants for PAL version of gv_01 map

EvtScript N(EVS_E8C6F8) = {
    EVT_CALL(EnableGroup, 20, 0)
    EVT_CALL(EnableGroup, 22, 0)
    EVT_CALL(EnableGroup, 24, 0)
    EVT_CALL(EnableGroup, 26, 0)
    EVT_CALL(EnableGroup, 28, 0)
    EVT_CALL(EnableGroup, 30, 0)
    EVT_CALL(EnableGroup, 32, 0)
    EVT_CALL(EnableGroup, 34, 0)
    EVT_CALL(EnableGroup, 36, 0)
    EVT_CALL(EnableGroup, 38, 0)
    EVT_CALL(EnableGroup, 40, 0)
    EVT_CALL(TranslateGroup, 4, 0, 200, 0)
    EVT_CALL(TranslateGroup, 6, 0, 200, 0)
    EVT_CALL(TranslateGroup, 8, 0, 200, 0)
    EVT_CALL(TranslateGroup, 10, 0, 200, 0)
    EVT_CALL(TranslateGroup, 12, 0, 200, 0)
    EVT_CALL(TranslateGroup, 14, 0, 200, 0)
    EVT_CALL(TranslateGroup, 16, 0, 200, 0)
    EVT_CALL(TranslateGroup, 18, 0, 200, 0)
    EVT_WAIT(5)
    EVT_SET(LVar0, 4)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(5)
    EVT_SET(LVar0, 6)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(10)
    EVT_SET(LVar0, 8)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(5)
    EVT_SET(LVar0, 10)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(5)
    EVT_SET(LVar0, 12)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(5)
    EVT_SET(LVar0, 14)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(5)
    EVT_SET(LVar0, 16)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(15)
    EVT_SET(LVar0, 18)
    EVT_EXEC(N(EVS_DropLastLetter))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_E8CA04) = {
    EVT_CALL(EnableGroup, 4, 0)
    EVT_CALL(EnableGroup, 6, 0)
    EVT_CALL(EnableGroup, 8, 0)
    EVT_CALL(EnableGroup, 10, 0)
    EVT_CALL(EnableGroup, 12, 0)
    EVT_CALL(EnableGroup, 14, 0)
    EVT_CALL(EnableGroup, 16, 0)
    EVT_CALL(EnableGroup, 18, 0)
    EVT_CALL(TranslateGroup, 20, 0, 200, 0)
    EVT_CALL(TranslateGroup, 22, 0, 200, 0)
    EVT_CALL(TranslateGroup, 24, 0, 200, 0)
    EVT_CALL(TranslateGroup, 26, 0, 200, 0)
    EVT_CALL(TranslateGroup, 28, 0, 200, 0)
    EVT_CALL(TranslateGroup, 30, 0, 200, 0)
    EVT_CALL(TranslateGroup, 32, 0, 200, 0)
    EVT_CALL(TranslateGroup, 34, 0, 200, 0)
    EVT_CALL(TranslateGroup, 36, 0, 200, 0)
    EVT_CALL(TranslateGroup, 38, 0, 200, 0)
    EVT_CALL(TranslateGroup, 40, 0, 200, 0)
    EVT_WAIT(5)
    EVT_SET(LVar0, 20)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 22)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(7)
    EVT_SET(LVar0, 24)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 26)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 28)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 30)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(7)
    EVT_SET(LVar0, 32)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 34)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 36)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(4)
    EVT_SET(LVar0, 38)
    EVT_EXEC(N(EVS_DropLetter))
    EVT_WAIT(12)
    EVT_SET(LVar0, 40)
    EVT_EXEC(N(EVS_DropLastLetter))
    EVT_RETURN
    EVT_END
};
#endif

EvtScript N(EVS_Main) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_THREAD
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
            EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        EVT_END_IF
        EVT_CALL(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(2)
        EVT_CALL(RandInt, 4, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_SpinLand)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Crouch)
            EVT_CASE_EQ(2)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_VacantStare)
            EVT_CASE_EQ(3)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Pray)
            EVT_CASE_EQ(4)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fallen)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_GAME_OVER, 0, 8)
    EVT_CALL(ClearAmbientSounds, 0)
    EVT_THREAD
        EVT_WAIT(200 * DT)
        EVT_CALL(N(FadeToTitleScreen))
        EVT_CALL(N(ChangeStateToTitleScreen))
        EVT_WAIT(100 * DT)
    EVT_END_THREAD
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 128, 10)
#if VERSION_PAL
    EVT_CALL(GetLanguage, LVar0)
    EVT_IF_EQ(LVar0, LANGUAGE_ES)
        EVT_EXEC(N(EVS_E8CA04))
    EVT_ELSE
        EVT_EXEC(N(EVS_E8C6F8))
    EVT_END_IF
#else
    EVT_CALL(TranslateGroup, MODEL_g,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_a,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_m,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_e,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_o,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_v,  0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_e2, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_r,  0, 200, 0)
    EVT_THREAD
#if VERSION_IQUE
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_g)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_m)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_o)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_e2)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(18)
#else
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_g)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_a)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(12)
        EVT_SET(LVar0, MODEL_m)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_e)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_o)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_v)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(6)
        EVT_SET(LVar0, MODEL_e2)
        EVT_EXEC(N(EVS_DropLetter))
        EVT_WAIT(18)
        EVT_SET(LVar0, MODEL_r)
        EVT_EXEC(N(EVS_DropLastLetter))
#endif
    EVT_END_THREAD
#endif
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 10, 0)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.3))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(94)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 1000)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(FadeToTitleScreen)) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        set_curtain_scale_goal(1.0);
        set_curtain_fade(0);
    }

    script->functionTemp[0] += (s32)(5 / DT);
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_screen_overlay_color(SCREEN_LAYER_BACK, 208, 208, 208);
    set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, script->functionTemp[0]);
    set_screen_overlay_alpha(SCREEN_LAYER_BACK, 0);
    return script->functionTemp[0] == 255;
}

API_CALLABLE(N(ChangeStateToTitleScreen)) {
    gGameStatusPtr->isBattle = FALSE;
    gGameStatusPtr->debugUnused1 = FALSE;
    gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;
    gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
    general_heap_create();
    clear_render_tasks();
    clear_worker_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    hud_element_clear_cache();
    clear_trigger_data();
    clear_printers();
    clear_entity_data(FALSE);
    clear_screen_overlays();
    clear_player_status();
    clear_npcs();
    clear_player_data();
    reset_battle_status();
    init_encounter_status();
    clear_effect_data();
    clear_item_entity_data();
    clear_saved_variables();
    initialize_collision();
    startup_set_fade_screen_alpha(255);
    startup_set_fade_screen_color(208);
    set_game_mode(GAME_MODE_TITLE_SCREEN);
    return ApiStatus_FINISH;
}
