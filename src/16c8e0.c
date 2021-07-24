#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

f32 D_802809F0 = 0.0f;
s8 D_802809F4 = 0;
s8 D_802809F5 = 0;
s16 D_802809F6 = -1;
s16 D_802809F8 = 0;
u16 D_802809FA = 0;

void* D_802809FC[] = {
    D_80291FA8, D_80291FD0, D_80291FF8, D_80292020, D_80292048, D_80292070, D_80292098, D_802920C0, D_802920E8, D_80292110, NULL, NULL, NULL,
};

s32 D_80280A30 = 0xFF;

extern PartnerID D_8029DA33;
extern s32 D_8029DA34;
extern Camera D_8029DA50[ARRAY_COUNT(gCameras)];
extern f32 D_8029EFB0;
extern f32 D_8029EFB4;
extern f32 D_8029EFB8;

Script BtlPutPartnerAway = SCRIPT({
    DispatchEvent(ACTOR_PARTNER, 62);
    parallel {
        SI_VAR(0) = 1.0;
        loop 10 {
            SetActorScale(ACTOR_PARTNER, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) -= 0.1005859375;
            sleep 1;
        }
    }
    EnablePartnerBlur();
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_E);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SetActorJumpGravity(ACTOR_PARTNER, 1.0);
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(ACTOR_PARTNER, 10, 0, 0, 1);
    DisablePartnerBlur();
});

Script BtlBringPartnerOut = SCRIPT({
    parallel {
        SI_VAR(0) = 0.1005859375;
        loop 20 {
            SetActorScale(ACTOR_PARTNER, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) += 0.05078125;
            sleep 1;
        }
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_D);
    GetGoalPos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.0);
    if (SI_VAR(1) == 0) {
        JumpToGoal(ACTOR_PARTNER, 20, 0, 0, 1);
    } else {
        JumpToGoal(ACTOR_PARTNER, 20, 0, 0, 1);
    }
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ForceHomePos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
});

s8 D_80280CE0[] = { 0, 0, 0, 0 };
s32 D_80280CE4 = -1;

Script CamPreset_B = SCRIPT({
    func_80248DD0();
});

Script CamPreset_F = SCRIPT({
    func_80248DE4();
});

Script CamPreset_M = SCRIPT({
    func_80249804();
});

Script CamPreset_G = SCRIPT({
    func_8024A214();
});

Script CamPreset_I = SCRIPT({
    func_8024A990();
});

Script CamPreset_H = SCRIPT({
    func_8024AFE4();
});

Script CamPreset_N = SCRIPT({
    func_8024B5FC();
});

Script CamPreset_C = SCRIPT({
    func_8024B9A0();
});

Script CamPreset_D = SCRIPT({
    func_8024BDA4();
});

Script CamPreset_E = SCRIPT({
    func_8024C180();
});

Script CamPreset_J = SCRIPT({
    func_8024C570();
});

Script CamPreset_K = SCRIPT({
    func_8024C944();
});

Script CamPreset_L = SCRIPT({
    func_8024CB68();
});

Script CamPreset_A = SCRIPT({
    func_8024E9B0(0, 15, 0);
    func_8024E748(2, 550);
    func_8024E748(3, 100);
    func_8024E748(4, 8);
});

Script D_80280EB8 = SCRIPT({
    SetCamPerspective(CAM_BATTLE, 6, 25, 16, 1024);
    SetCamViewport(CAM_BATTLE, 12, 20, 296, 200);
    SetCamBGColor(CAM_BATTLE, 0, 0, 0);
    SetCamEnabled(CAM_BATTLE, TRUE);
    sleep 1;
    InitVirtualEntityList();
    InitAnimatedModels();
    func_802CABE8(CAM_BATTLE, 0, 240, 100, 8);
    func_802CAE50(CAM_BATTLE, -75, 35, 0);
    BattleCamTargetActor(ACTOR_PLAYER);
    func_8024CE9C();
});

void get_dpad_input_radial(f32* angle, f32* magnitude) {
    BattleStatus* battleStatus = &gBattleStatus;
    u16 currentButtonsDown;
    f32 stickX;
    f32 stickY;
    f32 mag;
    f32 maxMagnitude = 60.0f;

    stickX = battleStatus->stickX;
    stickY = battleStatus->stickY;
    currentButtonsDown = battleStatus->currentButtonsDown;

    if (currentButtonsDown & 0xF00) {
        stickY = 0.0f;
        stickX = 0.0f;
        if (currentButtonsDown & 0x800) {
            stickY = maxMagnitude;
        }
        if (currentButtonsDown & 0x400) {
            stickY = -maxMagnitude;
        }
        if (currentButtonsDown & 0x200) {
            stickX = -maxMagnitude;
        }
        if (currentButtonsDown & 0x100) {
            stickX = maxMagnitude;
        }
    }

    mag = dist2D(0.0f, 0.0f, stickX, -stickY);
    if (mag >= maxMagnitude) {
        mag = maxMagnitude;
    }

    *angle = atan2(0.0f, 0.0f, stickX, -stickY);
    *magnitude = mag;
}

void func_8023E104(void) {
    D_802809F4 = 1;
    D_802809F5 = 0;
}

void func_8023E11C(void) {
    D_802809F4 = 0;
    D_802809F5 = 0;
}

INCLUDE_ASM(s32, "16c8e0", initialize_battle);

void func_8023E3FC(void) {
}

void update_actor_shadows(void) {
    if (gBattleStatus.flags1 & 1) {
        update_enemy_shadows();
        update_hero_shadows();
    }
}

void btl_update(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* partner = battleStatus->partnerActor;
    f32 dpadAngle;
    f32 dpadMagnitude;
    s32 cond;

    if (battleStatus->inputBitmask != -1) {
        if (battleStatus->flags1 & 0x80000 && gGameStatusPtr->unk_81 != 0) {
            s32 inputBitmask = battleStatus->inputBitmask;

            battleStatus->currentButtonsDown = gGameStatusPtr->altCurrentButtons & inputBitmask;
            battleStatus->currentButtonsPressed = gGameStatusPtr->altPressedButtons & inputBitmask;
            battleStatus->currentButtonsHeld = gGameStatusPtr->altHeldButtons & inputBitmask;
            battleStatus->stickX = gGameStatusPtr->altStickX;
            battleStatus->stickY = gGameStatusPtr->altStickY;
        } else {
            s32 inputBitmask2 = battleStatus->inputBitmask;

            battleStatus->currentButtonsDown = gGameStatusPtr->currentButtons & inputBitmask2;
            battleStatus->currentButtonsPressed = gGameStatusPtr->pressedButtons & inputBitmask2;
            battleStatus->currentButtonsHeld = gGameStatusPtr->heldButtons & inputBitmask2;
            battleStatus->stickX = gGameStatusPtr->stickX;
            battleStatus->stickY = gGameStatusPtr->stickY;
        }
    }

    get_dpad_input_radial(&dpadAngle, &dpadMagnitude);
    battleStatus->dpadX = dpadAngle;
    battleStatus->dpadY = dpadMagnitude;
    battleStatus->pushInputBuffer[battleStatus->inputBufferPos] = battleStatus->currentButtonsPressed;
    battleStatus->holdInputBuffer[battleStatus->inputBufferPos] = battleStatus->currentButtonsDown;

    battleStatus->inputBufferPos++;
    if (battleStatus->inputBufferPos >= 64) {
        battleStatus->inputBufferPos = 0;
    }

    if (battleStatus->preUpdateCallback != NULL) {
        battleStatus->preUpdateCallback();
    }

    cond = TRUE;
    if (battleStatus->unk_95 == 0 || battleStatus->unk_95 != gBattleState) {
        switch (gBattleState) {
            case -1:
            case 0:
                return;
            case 1:
                btl_state_update_normal_start();
                cond = FALSE;
                break;
            case 7:
                btl_state_update_begin_player_turn();
                break;
            case 8:
                btl_state_update_begin_partner_turn();
                break;
            case 9:
                func_80242FE0();
                break;
            case 5:
                btl_state_update_begin_turn();
                break;
            case 6:
                btl_state_update_end_turn();
                break;
            case 10:
                btl_state_update_switch_to_player();
                break;
            case 11:
                btl_state_update_switch_to_partner();
                break;
            case 12:
                btl_state_update_prepare_menu();
                break;
            case 13:
                btl_state_update_player_menu();
                break;
            case 14:
                btl_state_update_partner_menu();
                break;
            case 16:
                btl_state_update_twink_menu();
                break;
            case 15:
                btl_state_update_peach_menu();
                break;
            case 17:
                btl_state_update_select_target();
                break;
            case 18:
                btl_state_update_player_move();
                break;
            case 2:
                btl_state_update_first_strike();
                break;
            case 22:
                btl_state_update_end_player_turn();
                break;
            case 23:
                btl_state_update_end_partner_turn();
                break;
            case 21:
                btl_state_update_enemy_move();
                break;
            case 3:
                btl_state_update_partner_striking_first();
                break;
            case 20:
                btl_state_update_next_enemy();
                break;
            case 19:
                btl_state_update_partner_move();
                break;
            case 26:
                btl_state_update_victory();
                break;
            case 32:
                btl_state_update_end_battle();
                break;
            case 29:
                btl_state_update_change_partner();
                break;
            case 24:
                btl_state_update_run_away();
                break;
            case 25:
                btl_state_update_defend();
                break;
            case 27:
                btl_state_update_defeat();
                break;
            case 28:
                btl_state_update_1C();
                break;
            case 30:
                btl_state_update_end_training_battle();
                break;
            case 4:
                btl_state_update_enemy_striking_first();
                break;
            case 34:
                btl_state_update_22();
                break;
            case 33:
                btl_state_update_celebration();
                break;
            case 35:
                btl_state_update_end_demo_battle();
                cond = FALSE;
                break;
        }
    }

    battleStatus->unk_90++;
    if (battleStatus->unk_90 == 40) {
        func_8024F7C8();
    }

    func_80266684();
    func_80266978();
    func_80266B14();
    func_8024EE48();
    update_actor_shadows();

    if (battleStatus->unk_432 != -2) {
        u8 paramType;
        f32 paramAmount;

        get_screen_overlay_params(1, &paramType, &paramAmount);

        if (battleStatus->unk_432 > 0) {
            set_screen_overlay_color(1, 0, 0, 0);
            if (partner == NULL) {
                set_screen_overlay_params_back(0, 215.0f);
            } else if (playerData->currentPartner == 6) {
                paramAmount -= 10.0f;
                if (paramAmount < 0.0f) {
                    paramAmount = 0.0f;
                }
                set_screen_overlay_params_back(0, paramAmount);
            } else {
                paramAmount += 10.0f;
                if (paramAmount > 215.0f) {
                    paramAmount = 215.0f;
                }
                set_screen_overlay_params_back(0, paramAmount);
            }
        } else if (battleStatus->unk_432 < 0) {
            paramAmount -= 10.0f;
            if (paramAmount < 0.0f) {
                paramAmount = 0.0f;
                set_screen_overlay_params_back(0xFF, -1.0f);
                battleStatus->unk_432 = 0;
            } else {
                set_screen_overlay_params_back(0, paramAmount);
            }
        }

        if (cond || D_802809F6 != -1) {
            if (D_802809F6 == -1) {
                if (gGameStatusPtr->demoState == 2) {
                    u8 paramType;
                    f32 paramAmount;

                    get_screen_overlay_params(0, &paramType, &paramAmount);
                    if (paramType == 0xFF) {
                        D_802809F6 = 0;
                        set_screen_overlay_params_front(0, 0.0f);
                    }
                }
            } else if (D_802809F6 == 0xFF) {
                if (gBattleState != 0x23) {
                    btl_set_state(0x23, 0xFF);
                }
            } else {
                D_802809F6 += 10;
                if (D_802809F6 > 0xFF) {
                    D_802809F6 = 0xFF;
                }

                set_screen_overlay_params_front(0, D_802809F6);
                set_screen_overlay_color(0, 208, 208, 208);
                intro_logos_set_fade_alpha(255);
                intro_logos_set_fade_color(224);
            }
        }
    }
}

INCLUDE_ASM(s32, "16c8e0", btl_draw_ui);

void func_8023ED5C(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    Actor* actor;
    s32 i;

    if (gBattleState != 0) {
        func_8024EEA8();
        if (battleStatus->unk_B8 != NULL) {
            battleStatus->unk_B8();
        }
        if (battleStatus->flags1 & 1) {
            func_80255FD8();

            if (gCurrentCamID == 1 || gCurrentCamID == 2) {
                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    actor = battleStatus->enemyActors[i];

                    if (actor != NULL && !(actor->flags & 1)) {
                        renderTaskPtr->appendGfxArg = i;
                        renderTaskPtr->appendGfx = func_80257B28;
                        renderTaskPtr->distance = actor->currentPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);

                        if (actor->flags & 0x10000000) {
                            renderTaskPtr->appendGfxArg = actor;
                            renderTaskPtr->appendGfx = func_8025595C;
                            renderTaskPtr->distance = actor->currentPos.z;
                            renderTaskPtr->renderMode = 0x22;
                            queue_render_task(renderTaskPtr);
                        }

                        if (battleStatus->unk_92 & 1) {
                            renderTaskPtr->appendGfxArg = actor;
                            renderTaskPtr->appendGfx = func_80257B68;
                            renderTaskPtr->distance = actor->currentPos.z;
                            renderTaskPtr->renderMode = actor->renderMode;
                            queue_render_task(renderTaskPtr);
                        }
                    }
                }

                actor = battleStatus->partnerActor;
                if (actor != NULL && !(actor->flags & 1)) {
                    renderTaskPtr->appendGfxArg = NULL;
                    renderTaskPtr->appendGfx = func_80257B48;
                    renderTaskPtr->distance = actor->currentPos.z;
                    renderTaskPtr->renderMode = actor->renderMode;
                    queue_render_task(renderTaskPtr);

                    if (actor->flags & 0x10000000) {
                        renderTaskPtr->appendGfxArg = actor;
                        renderTaskPtr->appendGfx = func_8025599C;
                        renderTaskPtr->distance = actor->currentPos.z;
                        renderTaskPtr->renderMode = 0x22;
                        queue_render_task(renderTaskPtr);
                    }

                    if (battleStatus->unk_92 & 1) {
                        renderTaskPtr->appendGfxArg = NULL;
                        renderTaskPtr->appendGfx = func_80257B88;
                        renderTaskPtr->distance = actor->currentPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);
                    }
                }

                actor = battleStatus->playerActor;
                if (actor != NULL && !(actor->flags & 1)) {
                    renderTaskPtr->appendGfxArg = NULL;
                    renderTaskPtr->appendGfx = func_80257DA4;
                    renderTaskPtr->distance = actor->currentPos.z;
                    renderTaskPtr->renderMode = actor->renderMode;
                    queue_render_task(renderTaskPtr);

                    if (actor->flags & 0x10000000) {
                        renderTaskPtr->appendGfxArg = actor;
                        renderTaskPtr->appendGfx = func_80254C50;
                        renderTaskPtr->distance = actor->currentPos.z;
                        renderTaskPtr->renderMode = 0x22;
                        queue_render_task(renderTaskPtr);
                    }

                    if (battleStatus->unk_92 & 1) {
                        renderTaskPtr->appendGfxArg = NULL;
                        renderTaskPtr->appendGfx = func_80258E14;
                        renderTaskPtr->distance = actor->currentPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);
                    }
                }
            }
        }
    }
}

INCLUDE_ASM(s32, "16c8e0", func_8023F060);

INCLUDE_ASM(s32, "16c8e0", func_8023F088);

void func_8023FF84(void) {
    show_foreground_models_unchecked();
}

INCLUDE_ASM(s32, "16c8e0", btl_draw_enemy_health_bars);

INCLUDE_ASM(s32, "16c8e0", btl_update_starpoints_display);

void btl_save_world_cameras(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        D_8029DA50[i] = gCameras[i];
    }

    D_8029EFB0 = playerStatus->position.x;
    D_8029EFB4 = playerStatus->position.y;
    D_8029EFB8 = playerStatus->position.z;
    playerStatus->position.x = 0.0f;
    playerStatus->position.y = -1000.0f;
    playerStatus->position.z = 0.0f;
}

void btl_restore_world_cameras(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i] = D_8029DA50[i];
    }

    gCurrentCameraID = 0;
    playerStatus->position.x = D_8029EFB0;
    playerStatus->position.y = D_8029EFB4;
    playerStatus->position.z = D_8029EFB8;

    if (D_8029DA34 & 0x80) {
        gOverrideFlags |= 0x80;
    } else {
        gOverrideFlags &= ~0x80;
    }

    if (gBattleStatus.flags2 & 0x40) {
        playerData->currentPartner = D_8029DA33;
    }
}

void btl_delete_actor(Actor* actor) {
    ActorPart* partsTable;
    ActorPart* actorPartTemp;
    BattleStatus* battleStatus;
    s32 i;

    // TODO hard-coded
    for (i = 0; i < 2; i++) {
        remove_actor_decoration(actor, i);
    }
    if (actor->idleScript != NULL) {
        kill_script_by_ID(actor->idleScriptID);
    }
    if (actor->onHitScript != NULL) {
        kill_script_by_ID(actor->onHitID);
    }
    if (actor->takeTurnScript != NULL) {
        kill_script_by_ID(actor->takeTurnID);
    }
    func_80266EE8(actor, 0);

    partsTable = actor->partsTable;

    while (partsTable != NULL) {
        if (!(partsTable->flags & 0x4)) {
            delete_shadow(partsTable->shadow);
        }

        if (partsTable->idleAnimations != NULL) {
            func_802DE894(partsTable->unk_84, 0, 0, 0, 0, 0, 0);

            ASSERT(spr_free_sprite(partsTable->unk_84) == 0);

            if (!(partsTable->flags & 0x80000000)) {
                heap_free(partsTable->movement);
            }

            if (!(partsTable->flags & 0x2)) {
                heap_free(partsTable->decorationTable);
            }
        }
        actorPartTemp = partsTable->nextPart;
        heap_free(partsTable);
        partsTable = actorPartTemp;
    }

    delete_shadow(actor->shadow);
    remove_all_status_icons(actor->unk_436);
    remove_effect(actor->ptrDefuffIcon);

    if (actor->unk_200 != NULL) {
        actor->unk_200[3][9] = 0;
    }

    battleStatus = &gBattleStatus;
    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        if (battleStatus->enemyActors[i] == actor) {
            battleStatus->enemyActors[i] = NULL;
            break;
        }
    }

    heap_free(actor);
}

void btl_delete_player_actor(Actor* player) {
    struct ActorPart* partsTable;
    struct ActorPartMovement* movement;
    struct DecorationTable* decorationTable;
    s32 i;

    for (i = 0; i < 2; i++) {
        remove_actor_decoration(player, i);
    }

    if (player->idleScript != NULL) {
        kill_script_by_ID(player->idleScriptID);
    }
    if (player->onHitScript != NULL) {
        kill_script_by_ID(player->onHitID);
    }
    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnID);
    }

    partsTable = player->partsTable;
    decorationTable = partsTable->decorationTable;
    movement = partsTable->movement;

    delete_shadow(player->shadow);
    remove_all_status_icons(player->unk_436);
    remove_effect(player->ptrDefuffIcon);

    if (player->unk_200 != NULL) {
        player->unk_200[3][9] = 0;
    }

    heap_free(movement);
    heap_free(decorationTable);
    heap_free(partsTable);
    heap_free(player);
}
