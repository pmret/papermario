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
    UseBuf(N(DropLetterYCurve))
    Loop(ARRAY_COUNT(N(DropLetterYCurve)))
        BufRead1(LVar1)
        Call(TranslateGroup, LVar0, 0, LVar1, 0)
        Wait(1)
    EndLoop
    Return
    //@bug not terminated!
};

EvtScript N(EVS_DropLastLetter) = {
    UseBuf(N(DropLastLetterYCurve))
    Loop(ARRAY_COUNT(N(DropLastLetterYCurve)))
        BufRead1(LVar1)
        Call(TranslateGroup, LVar0, 0, LVar1, 0)
        Wait(1)
    EndLoop
    Return
    //@bug not terminated!
};

#if VERSION_PAL
// TODO: define MODEL_ constants for PAL version of gv_01 map

EvtScript N(EVS_E8C6F8) = {
    Call(EnableGroup, 20, 0)
    Call(EnableGroup, 22, 0)
    Call(EnableGroup, 24, 0)
    Call(EnableGroup, 26, 0)
    Call(EnableGroup, 28, 0)
    Call(EnableGroup, 30, 0)
    Call(EnableGroup, 32, 0)
    Call(EnableGroup, 34, 0)
    Call(EnableGroup, 36, 0)
    Call(EnableGroup, 38, 0)
    Call(EnableGroup, 40, 0)
    Call(TranslateGroup, 4, 0, 200, 0)
    Call(TranslateGroup, 6, 0, 200, 0)
    Call(TranslateGroup, 8, 0, 200, 0)
    Call(TranslateGroup, 10, 0, 200, 0)
    Call(TranslateGroup, 12, 0, 200, 0)
    Call(TranslateGroup, 14, 0, 200, 0)
    Call(TranslateGroup, 16, 0, 200, 0)
    Call(TranslateGroup, 18, 0, 200, 0)
    Wait(5)
    Set(LVar0, 4)
    Exec(N(EVS_DropLetter))
    Wait(5)
    Set(LVar0, 6)
    Exec(N(EVS_DropLetter))
    Wait(10)
    Set(LVar0, 8)
    Exec(N(EVS_DropLetter))
    Wait(5)
    Set(LVar0, 10)
    Exec(N(EVS_DropLetter))
    Wait(5)
    Set(LVar0, 12)
    Exec(N(EVS_DropLetter))
    Wait(5)
    Set(LVar0, 14)
    Exec(N(EVS_DropLetter))
    Wait(5)
    Set(LVar0, 16)
    Exec(N(EVS_DropLetter))
    Wait(15)
    Set(LVar0, 18)
    Exec(N(EVS_DropLastLetter))
    Return
    End
};

EvtScript N(EVS_E8CA04) = {
    Call(EnableGroup, 4, 0)
    Call(EnableGroup, 6, 0)
    Call(EnableGroup, 8, 0)
    Call(EnableGroup, 10, 0)
    Call(EnableGroup, 12, 0)
    Call(EnableGroup, 14, 0)
    Call(EnableGroup, 16, 0)
    Call(EnableGroup, 18, 0)
    Call(TranslateGroup, 20, 0, 200, 0)
    Call(TranslateGroup, 22, 0, 200, 0)
    Call(TranslateGroup, 24, 0, 200, 0)
    Call(TranslateGroup, 26, 0, 200, 0)
    Call(TranslateGroup, 28, 0, 200, 0)
    Call(TranslateGroup, 30, 0, 200, 0)
    Call(TranslateGroup, 32, 0, 200, 0)
    Call(TranslateGroup, 34, 0, 200, 0)
    Call(TranslateGroup, 36, 0, 200, 0)
    Call(TranslateGroup, 38, 0, 200, 0)
    Call(TranslateGroup, 40, 0, 200, 0)
    Wait(5)
    Set(LVar0, 20)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 22)
    Exec(N(EVS_DropLetter))
    Wait(7)
    Set(LVar0, 24)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 26)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 28)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 30)
    Exec(N(EVS_DropLetter))
    Wait(7)
    Set(LVar0, 32)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 34)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 36)
    Exec(N(EVS_DropLetter))
    Wait(4)
    Set(LVar0, 38)
    Exec(N(EVS_DropLetter))
    Wait(12)
    Set(LVar0, 40)
    Exec(N(EVS_DropLastLetter))
    Return
    End
};
#endif

EvtScript N(EVS_Main) = {
    Call(DisablePlayerInput, TRUE)
    Call(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_DONT_RESUME_SONG_AFTER_BATTLE)
    SetUP_CAMERA_NO_LEAD()
    Thread
        Call(GetCurrentPartnerID, LVar0)
        IfNe(LVar0, PARTNER_NONE)
            Call(DisablePartnerAI, 0)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
            Call(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
        EndIf
        Call(SetPlayerFlagBits, PS_FLAG_NO_FLIPPING, TRUE)
        Call(InterpPlayerYaw, 90, 0)
        Wait(2)
        Call(RandInt, 4, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(SetPlayerAnimation, ANIM_Mario1_SpinLand)
            CaseEq(1)
                Call(SetPlayerAnimation, ANIM_Mario1_Crouch)
            CaseEq(2)
                Call(SetPlayerAnimation, ANIM_Mario1_VacantStare)
            CaseEq(3)
                Call(SetPlayerAnimation, ANIM_Mario1_Pray)
            CaseEq(4)
                Call(SetPlayerAnimation, ANIM_Mario1_Fallen)
        EndSwitch
    EndThread
    Call(SetMusicTrack, 0, SONG_GAME_OVER, 0, 8)
    Call(ClearAmbientSounds, 0)
    Thread
        Wait(200 * DT)
        Call(N(FadeToTitleScreen))
        Call(N(ChangeStateToTitleScreen))
        Wait(100 * DT)
    EndThread
    Call(SetMotionBlurParams, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 128, 10)
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    IfEq(LVar0, LANGUAGE_ES)
        Exec(N(EVS_E8CA04))
    Else
        Exec(N(EVS_E8C6F8))
    EndIf
#else
    Call(TranslateGroup, MODEL_g,  0, 200, 0)
    Call(TranslateGroup, MODEL_a,  0, 200, 0)
    Call(TranslateGroup, MODEL_m,  0, 200, 0)
    Call(TranslateGroup, MODEL_e,  0, 200, 0)
    Call(TranslateGroup, MODEL_o,  0, 200, 0)
    Call(TranslateGroup, MODEL_v,  0, 200, 0)
    Call(TranslateGroup, MODEL_e2, 0, 200, 0)
    Call(TranslateGroup, MODEL_r,  0, 200, 0)
    Thread
#if VERSION_IQUE
        Wait(6)
        Set(LVar0, MODEL_g)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_m)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_o)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_e2)
        Exec(N(EVS_DropLetter))
        Wait(18)
#else
        Wait(6)
        Set(LVar0, MODEL_g)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_a)
        Exec(N(EVS_DropLetter))
        Wait(12)
        Set(LVar0, MODEL_m)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_e)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_o)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_v)
        Exec(N(EVS_DropLetter))
        Wait(6)
        Set(LVar0, MODEL_e2)
        Exec(N(EVS_DropLetter))
        Wait(18)
        Set(LVar0, MODEL_r)
        Exec(N(EVS_DropLastLetter))
#endif
    EndThread
#endif
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 0, 10, 0)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.3))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(94)
        Call(SetPanTarget, CAM_DEFAULT, 0, 0, 1000)
    EndThread
    Return
    End
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
