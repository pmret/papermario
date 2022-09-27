#include "gv_01.h"
#include "sprite.h"
#include "hud_element.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(D_80241030_E1F490);
void reset_battle_status(void);

#define MAIN_OFFSET_B8 0xB8

EntryList N(Entrances) = {
    {    0.0,    0.0,    0.0,   90.0 },  /* gv_01_ENTRY_0 */
};

MapSettings N(settings) = {
    .main = &N(EVS_Main) + MAIN_OFFSET_B8,
    .entryList = &N(Entrances),
    .entryCount = ENTRY_COUNT(N(Entrances)),
};

#include "world/common/atomic/Pipe.inc.c"

EvtScript N(EVS_80240810) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SUB(LVar2, 40)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(func_802D286C, 0x100)
    EVT_CALL(func_802D2520, 0x00010000, 5, 2, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(40)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(3)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_2, FALSE)
            EVT_CALL(EnablePartnerAI)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(func_802D2520, 0x00010000, 0, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_LABEL(0)
    EVT_CALL(N(Pipe_GetCurrentFloor))
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80240B64) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_SET(LVar7, LVar3)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(InterpPlayerYaw, LVar4, 0)
    EVT_IF_EQ(LVar4, 90)
        EVT_ADD(LVar5, 40)
    EVT_ELSE
        EVT_SUB(LVar5, 40)
    EVT_END_IF
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar5, LVar6, LVar7)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar5, LVar6, LVar7)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(EnableNpcShadow, NPC_PARTNER, FALSE)
        EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, LVar0, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(HidePlayerShadow, FALSE)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x00000900)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 3, 1, 1, 0)
    EVT_LOOP(40)
        EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_THREAD
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_CALL(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            EVT_CALL(EnableNpcShadow, NPC_PARTNER, TRUE)
            EVT_CALL(EnablePartnerAI)
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 0, 0, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 1, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_EXEC(LVarA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80240F54) = {
    EVT_CALL(N(Pipe_AwaitDownInput))
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_EXEC_WAIT(N(D_80241030_E1F490))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241030_E1F490) = {
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(PlayerMoveTo, LVar1, LVar3, 3)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_CALL(SetPlayerPos, LVar1, LVar2, LVar3)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_200000, TRUE)
    EVT_CALL(N(Pipe_GetCameraYaw))
    EVT_CALL(InterpPlayerYaw, LVar0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetPlayerFlagBits, PS_FLAGS_200000, FALSE)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_LOOP(40)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x00000800)
    EVT_CALL(func_802D2520, ANIM_Mario_10002, 5, 2, 1, 1, 0)
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024120C) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_EQ(LVar0, ACTION_STATE_SPIN)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetCurrentPartner, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(GetCurrentPartnerID, LVar1)
        EVT_IF_NE(LVar1, PARTNER_WATT)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(func_802D2B6C)
            EVT_CALL(DisablePlayerInput, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(DisablePlayerInput, TRUE)
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(N(Pipe_SetAnimFlag))
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(ModifyColliderFlags, 0, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, LVarA)
    EVT_CALL(N(Pipe_GetEntryPos))
    EVT_SET(LVar5, LVar1)
    EVT_SET(LVar6, LVar2)
    EVT_ADD(LVar6, 2)
    EVT_SET(LVar7, LVar3)
    EVT_SET(LVar8, LVar4)
    EVT_ADD(LVar8, 180)
    EVT_IF_GE(LVar4, 360)
        EVT_SUB(LVar4, 360)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, LVar8, 1)
    EVT_WAIT(1)
    EVT_CALL(PlaySound, SOUND_ENTER_PIPE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, LVar6, LVar7)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
    EVT_CALL(func_802D286C, 0x00000800)
    EVT_CALL(func_802D2520, 0x00010000, 5, 3, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(HidePlayerShadow, TRUE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_LOOP(40)
            EVT_CALL(N(Pipe_GetPointAheadOfPlayer), EVT_FLOAT(1.0))
            EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(25)
    EVT_EXEC_WAIT(LVarC)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_80241540) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};

s32 N(D_802415DC_E1FA3C)[] = {
    200, 170, 140, 110, 80, 50, 20, 10, 
    26, 29, 30, 29, 26, 10, 0, 12, 
    15, 16, 15, 11, 6, 0, 4, 3, 
    1, 0, 
};

s32 N(D_80241644_E1FAA4)[] = {
    200, 170, 140, 110, 80, 50, 20, 0, 
    12, 15, 16, 15, 11, 6, 0, 4, 
    3, 1, 0, 
};

API_CALLABLE(N(func_802405EC_E1EA4C));
API_CALLABLE(N(func_80240688_E1EAE8));

EvtScript N(EVS_Main) = {
    EVT_USE_BUF(N(D_802415DC_E1FA3C))
    EVT_LOOP(26)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(TranslateGroup, LVar0, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_USE_BUF(N(D_80241644_E1FAA4))
    EVT_LOOP(19)
        EVT_BUF_READ1(LVar1)
        EVT_CALL(TranslateGroup, LVar0, 0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_20000)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_THREAD
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_CALL(DisablePartnerAI, 0)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, 512, FALSE)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 0, -1000, 0)
        EVT_END_IF
        EVT_CALL(SetPlayerFlagBits, 0x00200000, TRUE)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_WAIT(2)
        EVT_CALL(RandInt, 4, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_1000D)
            EVT_CASE_EQ(1)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_Crouch)
            EVT_CASE_EQ(2)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_ShockStill)
            EVT_CASE_EQ(3)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_AnimPray)
            EVT_CASE_EQ(4)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_DeadStill)
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(SetMusicTrack, 0, SONG_GAME_OVER, 0, 8)
    EVT_CALL(ClearAmbientSounds, 0)
    EVT_THREAD
        EVT_WAIT(200)
        EVT_CALL(N(func_802405EC_E1EA4C))
        EVT_CALL(N(func_80240688_E1EAE8))
        EVT_WAIT(100)
    EVT_END_THREAD
    EVT_CALL(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    EVT_CALL(TranslateGroup, MODEL_g, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_a, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_m, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_e, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_o, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_v, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_e2, 0, 200, 0)
    EVT_CALL(TranslateGroup, MODEL_r, 0, 200, 0)
    EVT_THREAD
        EVT_WAIT(6)
        EVT_SET(LVar0, 4)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(6)
        EVT_SET(LVar0, 6)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(12)
        EVT_SET(LVar0, 8)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(6)
        EVT_SET(LVar0, 10)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(6)
        EVT_SET(LVar0, 12)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(6)
        EVT_SET(LVar0, 14)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(6)
        EVT_SET(LVar0, 16)
        EVT_EXEC(N(EVS_Main))
        EVT_WAIT(18)
        EVT_SET(LVar0, 18)
        EVT_EXEC(N(EVS_Main) + 0x5C)
    EVT_END_THREAD
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

ApiStatus func_802405EC_E1EA4C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 0;
        set_curtain_scale_goal(1.0);
        set_curtain_fade(0);
    }

    script->functionTemp[0] += 5;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }

    set_screen_overlay_color(1, 208, 208, 208);
    set_screen_overlay_params_back(0, script->functionTemp[0]);
    set_screen_overlay_alpha(1, 0);
    return script->functionTemp[0] == 255;
}

ApiStatus func_80240688_E1EAE8(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->isBattle = FALSE;
    gGameStatusPtr->unk_76 = 0;
    gGameStatusPtr->disableScripts = 0;
    gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    general_heap_create();
    clear_render_tasks();
    clear_generic_entity_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(0);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    hud_element_clear_cache();
    clear_trigger_data();
    clear_printers();
    clear_entity_data(0);
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
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(208);
    set_game_mode(GAME_MODE_TITLE_SCREEN);
    return ApiStatus_FINISH;
}
