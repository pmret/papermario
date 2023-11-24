#include "common.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite.h"
#include "effects.h"

f32 D_802809F0 = 0.0f;
s8 D_802809F4 = 0;
s8 D_802809F5 = 0;
s16 D_802809F6 = -1;
s16 DemoBattleBeginDelay = 0;
u16 gTattleBgTextureYOffset = 0;

BSS s32 bSavedPartner;
BSS s32 bSavedOverrideFlags;
BSS s32 D_8029DA38; // unused?
BSS s32 D_8029DA3C; // unused?
BSS s32 StarPointsBasePosX;
BSS s32 StarPointsBasePosY;
BSS s32 StarPointsMoveInterpAmt;
BSS s32 D_8029DA4C;
BSS Camera SavedWorldCameras[ARRAY_COUNT(gCameras)];
BSS f32 SavedWorldPlayerPosX;
BSS f32 SavedWorldPlayerPosY;
BSS f32 SavedWorldPlayerPosZ;
BSS s32 D_8029EFBC;
BSS s32 BtlStarPointTensHIDs[10];
BSS s32 BtlStarPointShinesHIDs[10];
BSS s32 BtlStarPointOnesHIDs[10];
BSS PAL_BIN gTattleBgPalette[0x100];

extern HudScript HES_HPDigit0;
extern HudScript HES_HPDigit1;
extern HudScript HES_HPDigit2;
extern HudScript HES_HPDigit3;
extern HudScript HES_HPDigit4;
extern HudScript HES_HPDigit5;
extern HudScript HES_HPDigit6;
extern HudScript HES_HPDigit7;
extern HudScript HES_HPDigit8;
extern HudScript HES_HPDigit9;

HudScript* bHPDigitHudScripts[] = {
    &HES_HPDigit0, &HES_HPDigit1, &HES_HPDigit2, &HES_HPDigit3, &HES_HPDigit4,
    &HES_HPDigit5, &HES_HPDigit6, &HES_HPDigit7, &HES_HPDigit8, &HES_HPDigit9,
    NULL, NULL, NULL,
};

s32 BattleScreenFadeAmt = 255;

EvtScript BtlPutPartnerAway = {
    EVT_CALL(DispatchEvent, ACTOR_PARTNER, EVENT_PUT_PARTNER_AWAY)
    EVT_CHILD_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(1.0))
        EVT_LOOP(10)
            EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, EVT_FLOAT(1.0))
            EVT_SUBF(LVar0, EVT_FLOAT(0.1))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(EnablePartnerBlur)
    EVT_CALL(PlaySoundAtActor, 0, SOUND_PARTNER_GET_OUT)
    EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, 0, 0, 1)
    EVT_CALL(DisablePartnerBlur)
    EVT_RETURN
    EVT_END
};

EvtScript BtlBringPartnerOut = {
    EVT_CHILD_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(0.1))
        EVT_LOOP(20)
            EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, EVT_FLOAT(1.0))
            EVT_ADDF(LVar0, EVT_FLOAT(0.05))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, 0, SOUND_PARTNER_PUT_AWAY)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, 0, 0, 1)
    EVT_ELSE
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, 0, 0, 1)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

extern HudScript HES_HPBar;
extern HudScript HES_Item_SmallStarPoint;
extern HudScript HES_Item_StarPoint;
extern HudScript HES_StatusSPShine;

void btl_render_actors(void);
void tattle_cam_pre_render(Camera*);
void tattle_cam_post_render(Camera*);
void btl_draw_enemy_health_bars(void);
void btl_update_starpoints_display(void);

void get_stick_input_radial(f32* angle, f32* magnitude) {
    BattleStatus* battleStatus = &gBattleStatus;
    f32 maxMagnitude = 60.0f;
    f32 stickX = battleStatus->stickX;
    f32 stickY = battleStatus->stickY;
    u16 currentButtonsDown = battleStatus->curButtonsDown;
    f32 mag;

    if (currentButtonsDown & (BUTTON_D_UP | BUTTON_D_DOWN | BUTTON_D_LEFT | BUTTON_D_RIGHT)) {
        stickY = 0.0f;
        stickX = 0.0f;
        if (currentButtonsDown & BUTTON_D_UP) {
            stickY = maxMagnitude;
        }
        if (currentButtonsDown & BUTTON_D_DOWN) {
            stickY = -maxMagnitude;
        }
        if (currentButtonsDown & BUTTON_D_LEFT) {
            stickX = -maxMagnitude;
        }
        if (currentButtonsDown & BUTTON_D_RIGHT) {
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

void initialize_battle(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Camera* tattleCam = &gCameras[CAM_TATTLE];
    s32 hudElemID;
    s32 i;

    gBattleStatus.flags1 = 0;
    gBattleStatus.flags2 = 0;
    gBattleStatus.flags1 = 0;
    bSavedOverrideFlags = gOverrideFlags;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    gBattleStatus.inputBitmask = -1;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;

    for (i = 0; i < 16; i++) {
        battleStatus->pushInputBuffer[i] = 0; // @bug? why just 16
    }

    battleStatus->inputBufferPos = 0;
    battleStatus->holdInputBufferPos = 0;
    battleStatus->waitForState = BATTLE_STATE_0;

    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        battleStatus->enemyActors[i] = NULL;
    }

    battleStatus->playerActor = NULL;
    battleStatus->partnerActor = NULL;

    for (i = 0; i < ARRAY_COUNT(battleStatus->lastPlayerMenuSelection); i++) {
        battleStatus->lastPlayerMenuSelection[i] = -1;
        battleStatus->lastPartnerMenuSelection[i] = -1;
    }

    for (i = 0; i < ARRAY_COUNT(battleStatus->tattleFlags); i++) {
        battleStatus->tattleFlags[i] = 0;
    }

    if (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH) {
        gBattleStatus.flags2 |= BS_FLAGS2_PEACH_BATTLE;
        increment_status_bar_disabled();
    } else {
        gBattleStatus.flags2 &= ~BS_FLAGS2_PEACH_BATTLE;
    }

    create_worker_world(NULL, btl_render_actors);
    btl_popup_messages_init();
    func_80268E88();
    set_windows_visible(WINDOW_GROUP_1);
    D_8029EFBC = hud_element_create(&HES_HPBar);
    hud_element_set_flags(D_8029EFBC, HUD_ELEMENT_FLAG_80);

    for (i = 0; i < ARRAY_COUNT(BtlStarPointTensHIDs); i++) {
        hudElemID = BtlStarPointTensHIDs[i] = hud_element_create(&HES_Item_StarPoint);
        hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
        hud_element_set_render_depth(hudElemID, 20);
    }

    for (i = 0; i < ARRAY_COUNT(BtlStarPointShinesHIDs); i++) {
        hudElemID = BtlStarPointShinesHIDs[i] = hud_element_create(&HES_StatusSPShine);
        hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
        hud_element_set_render_depth(hudElemID, 20);
    }

    for (i = 0; i < ARRAY_COUNT(BtlStarPointOnesHIDs); i++) {
        hudElemID = BtlStarPointOnesHIDs[i] = hud_element_create(&HES_Item_SmallStarPoint);
        hud_element_set_flags(hudElemID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
        hud_element_set_render_depth(hudElemID, 20);
    }

    tattleCam->fpDoPreRender = tattle_cam_pre_render;
    tattleCam->fpDoPostRender = tattle_cam_post_render;

    if (playerData->battlesCount < 9999) {
        playerData->battlesCount++;
    }

    bSavedPartner = playerData->curPartner;
    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
        playerData->curPartner = PARTNER_TWINK;
    }
}

void func_8023E3FC(void) {
}

void update_nonplayer_actor_shadows(void) {
    if (gBattleStatus.flags1 & BS_FLAGS1_ACTORS_VISIBLE) {
        update_enemy_shadows();
        update_hero_shadows();
    }
}

void btl_update(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* partner = battleStatus->partnerActor;
    f32 outAngle;
    f32 outMagnitude;
    s32 cond;

    if (battleStatus->inputBitmask != -1) {
        if ((battleStatus->flags1 & BS_FLAGS1_PARTNER_ACTING) && gGameStatusPtr->multiplayerEnabled) {
            s32 inputBitmask = battleStatus->inputBitmask;

            battleStatus->curButtonsDown = gGameStatusPtr->curButtons[1] & inputBitmask;
            battleStatus->curButtonsPressed = gGameStatusPtr->pressedButtons[1] & inputBitmask;
            battleStatus->curButtonsHeld = gGameStatusPtr->heldButtons[1] & inputBitmask;
            battleStatus->stickX = gGameStatusPtr->stickX[1];
            battleStatus->stickY = gGameStatusPtr->stickY[1];
        } else {
            s32 inputBitmask2 = battleStatus->inputBitmask;

            battleStatus->curButtonsDown = gGameStatusPtr->curButtons[0] & inputBitmask2;
            battleStatus->curButtonsPressed = gGameStatusPtr->pressedButtons[0] & inputBitmask2;
            battleStatus->curButtonsHeld = gGameStatusPtr->heldButtons[0] & inputBitmask2;
            battleStatus->stickX = gGameStatusPtr->stickX[0];
            battleStatus->stickY = gGameStatusPtr->stickY[0];
        }
    }

    get_stick_input_radial(&outAngle, &outMagnitude);
    battleStatus->stickAngle = outAngle;
    battleStatus->stickMagnitude = outMagnitude;
    battleStatus->pushInputBuffer[battleStatus->inputBufferPos] = battleStatus->curButtonsPressed;
    battleStatus->holdInputBuffer[battleStatus->inputBufferPos] = battleStatus->curButtonsDown;

    battleStatus->inputBufferPos++;
    if (battleStatus->inputBufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
        battleStatus->inputBufferPos = 0;
    }

    if (battleStatus->preUpdateCallback != NULL) {
        battleStatus->preUpdateCallback();
    }

    cond = TRUE;
    if (battleStatus->waitForState == BATTLE_STATE_0 || battleStatus->waitForState != gBattleState) {
        switch (gBattleState) {
            case BATTLE_STATE_NEGATIVE_1:
            case BATTLE_STATE_0:
                return;
            case BATTLE_STATE_NORMAL_START:
                btl_state_update_normal_start();
                cond = FALSE;
                break;
            case BATTLE_STATE_BEGIN_PLAYER_TURN:
                btl_state_update_begin_player_turn();
                break;
            case BATTLE_STATE_BEGIN_PARTNER_TURN:
                btl_state_update_begin_partner_turn();
                break;
            case BATTLE_STATE_9:
                btl_state_update_9();
                break;
            case BATTLE_STATE_BEGIN_TURN:
                btl_state_update_begin_turn();
                break;
            case BATTLE_STATE_END_TURN:
                btl_state_update_end_turn();
                break;
            case BATTLE_STATE_SWITCH_TO_PLAYER:
                btl_state_update_switch_to_player();
                break;
            case BATTLE_STATE_SWITCH_TO_PARTNER:
                btl_state_update_switch_to_partner();
                break;
            case BATTLE_STATE_PREPARE_MENU:
                btl_state_update_prepare_menu();
                break;
            case BATTLE_STATE_PLAYER_MENU:
                btl_state_update_player_menu();
                break;
            case BATTLE_STATE_PARTNER_MENU:
                btl_state_update_partner_menu();
                break;
            case BATTLE_STATE_TWINK_MENU:
                btl_state_update_twink_menu();
                break;
            case BATTLE_STATE_PEACH_MENU:
                btl_state_update_peach_menu();
                break;
            case BATTLE_STATE_SELECT_TARGET:
                btl_state_update_select_target();
                break;
            case BATTLE_STATE_PLAYER_MOVE:
                btl_state_update_player_move();
                break;
            case BATTLE_STATE_FIRST_STRIKE:
                btl_state_update_first_strike();
                break;
            case BATTLE_STATE_END_PLAYER_TURN:
                btl_state_update_end_player_turn();
                break;
            case BATTLE_STATE_END_PARTNER_TURN:
                btl_state_update_end_partner_turn();
                break;
            case BATTLE_STATE_ENEMY_MOVE:
                btl_state_update_enemy_move();
                break;
            case BATTLE_STATE_PARTNER_FIRST_STRIKE:
                btl_state_update_partner_striking_first();
                break;
            case BATTLE_STATE_NEXT_ENEMY:
                btl_state_update_next_enemy();
                break;
            case BATTLE_STATE_PARTNER_MOVE:
                btl_state_update_partner_move();
                break;
            case BATTLE_STATE_VICTORY:
                btl_state_update_victory();
                break;
            case BATTLE_STATE_END_BATTLE:
                btl_state_update_end_battle();
                break;
            case BATTLE_STATE_CHANGE_PARTNER:
                btl_state_update_change_partner();
                break;
            case BATTLE_STATE_RUN_AWAY:
                btl_state_update_run_away();
                break;
            case BATTLE_STATE_DEFEND:
                btl_state_update_defend();
                break;
            case BATTLE_STATE_DEFEAT:
                btl_state_update_defeat();
                break;
            case BATTLE_STATE_28:
                btl_state_update_1C();
                break;
            case BATTLE_STATE_END_TRAINING_BATTLE:
                btl_state_update_end_training_battle();
                break;
            case BATTLE_STATE_ENEMY_FIRST_STRIKE:
                btl_state_update_enemy_striking_first();
                break;
            case BATTLE_STATE_34:
                btl_state_update_22();
                break;
            case BATTLE_STATE_CELEBRATION:
                btl_state_update_celebration();
                break;
            case BATTLE_STATE_END_DEMO_BATTLE:
                btl_state_update_end_demo_battle();
                cond = FALSE;
                break;
        }
    }

    battleStatus->unk_90++;
    if (battleStatus->unk_90 == 40) {
        btl_bonk_cleanup();
    }

    update_damage_popups();
    update_action_ratings();
    update_health_bars();
    btl_popup_messages_update();
    update_nonplayer_actor_shadows();

    if (battleStatus->darknessMode != BTL_DARKNESS_STATE_LOCKED) {
        u8 paramType;
        f32 paramAmount;

        get_screen_overlay_params(SCREEN_LAYER_BACK, &paramType, &paramAmount);

        if (battleStatus->darknessMode > BTL_DARKNESS_STATE_NONE) {
            set_screen_overlay_color(SCREEN_LAYER_BACK, 0, 0, 0);
            if (partner == NULL) {
                set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, 215.0f);
            } else if (playerData->curPartner == PARTNER_WATT) {
                paramAmount -= 10.0f;
                if (paramAmount < 0.0f) {
                    paramAmount = 0.0f;
                }
                set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, paramAmount);
            } else {
                paramAmount += 10.0f;
                if (paramAmount > 215.0f) {
                    paramAmount = 215.0f;
                }
                set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, paramAmount);
            }
        } else if (battleStatus->darknessMode < BTL_DARKNESS_STATE_NONE) {
            paramAmount -= 10.0f;
            if (paramAmount < 0.0f) {
                paramAmount = 0.0f;
                set_screen_overlay_params_back(OVERLAY_NONE, -1.0f);
                battleStatus->darknessMode = BTL_DARKNESS_STATE_NONE;
            } else {
                set_screen_overlay_params_back(OVERLAY_SCREEN_COLOR, paramAmount);
            }
        }

        if (cond || D_802809F6 != -1) {
            if (D_802809F6 == -1) {
                if (gGameStatusPtr->demoState == DEMO_STATE_CHANGE_MAP) {
                    u8 paramType;
                    f32 paramAmount;

                    get_screen_overlay_params(SCREEN_LAYER_FRONT, &paramType, &paramAmount);
                    if (paramType == (u8) OVERLAY_NONE) {
                        D_802809F6 = 0;
                        set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, 0.0f);
                    }
                }
            } else if (D_802809F6 == 255) {
                if (gBattleState != BATTLE_STATE_END_DEMO_BATTLE) {
                    btl_set_state(BATTLE_STATE_END_DEMO_BATTLE);
                }
            } else {
                D_802809F6 += 10;
                if (D_802809F6 > 255) {
                    D_802809F6 = 255;
                }

                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, D_802809F6);
                set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
                startup_set_fade_screen_alpha(255);
                startup_set_fade_screen_color(224);
            }
        }
    }
}

void btl_draw_ui(void) {
    s32 changed = FALSE;
    s32 state;

    do {} while (0); // TODO required to match (probably can be removed with some sort of control flow inversion)

    // do not draw UI during the frame of a state change
    state = gBattleState;
    if (gBattleState != gLastDrawBattleState) {
        state = gLastDrawBattleState;
        gLastDrawBattleState = gBattleState;
        changed = TRUE;
    } else {
        switch (state) {
            case BATTLE_STATE_NEGATIVE_1:
                btl_update_starpoints_display();
                btl_draw_enemy_health_bars();
                draw_status_ui();
                return;
            case BATTLE_STATE_0:
                return;
        }
    }

    btl_update_starpoints_display();
    btl_draw_enemy_health_bars();

    if (!changed) {
        switch (state) {
            case BATTLE_STATE_NORMAL_START:
                btl_state_draw_normal_start();
                break;
            case BATTLE_STATE_BEGIN_PLAYER_TURN:
                btl_state_draw_begin_player_turn();
                break;
            case BATTLE_STATE_BEGIN_PARTNER_TURN:
                btl_state_draw_begin_partner_turn();
                break;
            case BATTLE_STATE_9:
                btl_state_draw_9();
                break;
            case BATTLE_STATE_BEGIN_TURN:
                btl_state_draw_begin_turn();
                break;
            case BATTLE_STATE_END_TURN:
                btl_state_draw_end_turn();
                break;
            case BATTLE_STATE_SWITCH_TO_PLAYER:
                btl_state_draw_switch_to_player();
                break;
            case BATTLE_STATE_SWITCH_TO_PARTNER:
                btl_state_draw_switch_to_partner();
                break;
            case BATTLE_STATE_PREPARE_MENU:
                btl_state_draw_prepare_menu();
                break;
            case BATTLE_STATE_PLAYER_MENU:
                btl_state_draw_player_menu();
                break;
            case BATTLE_STATE_PARTNER_MENU:
                btl_state_draw_partner_menu();
                break;
            case BATTLE_STATE_TWINK_MENU:
                btl_state_draw_twink_menu();
                break;
            case BATTLE_STATE_PEACH_MENU:
                btl_state_draw_peach_menu();
                break;
            case BATTLE_STATE_SELECT_TARGET:
                btl_state_draw_select_target();
                break;
            case BATTLE_STATE_PLAYER_MOVE:
                btl_state_draw_player_move();
                break;
            case BATTLE_STATE_FIRST_STRIKE:
                btl_state_draw_first_stike();
                break;
            case BATTLE_STATE_END_PLAYER_TURN:
                btl_state_draw_end_player_turn();
                break;
            case BATTLE_STATE_END_PARTNER_TURN:
                btl_state_draw_end_partner_turn();
                break;
            case BATTLE_STATE_PARTNER_FIRST_STRIKE:
                btl_state_draw_partner_striking_first();
                break;
            case BATTLE_STATE_ENEMY_MOVE:
                btl_state_draw_enemy_move();
                break;
            case BATTLE_STATE_NEXT_ENEMY:
                btl_state_draw_next_enemy();
                break;
            case BATTLE_STATE_PARTNER_MOVE:
                btl_state_draw_partner_move();
                break;
            case BATTLE_STATE_VICTORY:
                btl_state_draw_victory();
                break;
            case BATTLE_STATE_END_BATTLE:
                btl_state_draw_end_battle();
                break;
            case BATTLE_STATE_CHANGE_PARTNER:
                btl_state_draw_change_partner();
                break;
            case BATTLE_STATE_RUN_AWAY:
                btl_state_draw_run_away();
                break;
            case BATTLE_STATE_DEFEND:
                btl_state_draw_defend();
                break;
            case BATTLE_STATE_DEFEAT:
                btl_state_draw_defeat();
                break;
            case BATTLE_STATE_28:
                btl_state_draw_1C();
                break;
            case BATTLE_STATE_END_TRAINING_BATTLE:
                btl_state_draw_end_training_battle();
                break;
            case BATTLE_STATE_ENEMY_FIRST_STRIKE:
                btl_state_draw_enemy_striking_first();
                break;
            case BATTLE_STATE_34:
                btl_state_draw_22();
                break;
            case BATTLE_STATE_CELEBRATION:
                btl_state_draw_celebration();
                break;
            case BATTLE_STATE_END_DEMO_BATTLE:
                btl_state_draw_end_demo_battle();
                break;
        }
    }
    btl_popup_messages_draw_ui();
    draw_status_ui();
}

void btl_render_actors(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    Actor* actor;
    s32 i;

    if (gBattleState != BATTLE_STATE_0) {
        btl_popup_messages_draw_world_geometry();
        if (battleStatus->initBattleCallback != NULL) {
            battleStatus->initBattleCallback();
        }
        if (battleStatus->flags1 & BS_FLAGS1_ACTORS_VISIBLE) {
            func_80255FD8();

            if (gCurrentCamID == CAM_BATTLE || gCurrentCamID == CAM_TATTLE) {
                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    actor = battleStatus->enemyActors[i];

                    if (actor != NULL && !(actor->flags & ACTOR_FLAG_INVISIBLE)) {
                        renderTaskPtr->appendGfxArg = (void*)i;
                        renderTaskPtr->appendGfx = appendGfx_enemy_actor;
                        renderTaskPtr->dist = actor->curPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);

                        if (actor->flags & ACTOR_FLAG_BLUR_ENABLED) {
                            renderTaskPtr->appendGfxArg = actor;
                            renderTaskPtr->appendGfx = appendGfx_enemy_actor_blur;
                            renderTaskPtr->dist = actor->curPos.z;
                            renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
                            queue_render_task(renderTaskPtr);
                        }

                        if (battleStatus->reflectFlags & BS_REFLECT_FLOOR) {
                            renderTaskPtr->appendGfxArg = actor;
                            renderTaskPtr->appendGfx = appendGfx_enemy_actor_reflection;
                            renderTaskPtr->dist = actor->curPos.z;
                            renderTaskPtr->renderMode = actor->renderMode;
                            queue_render_task(renderTaskPtr);
                        }
                    }
                }

                actor = battleStatus->partnerActor;
                if (actor != NULL && !(actor->flags & ACTOR_FLAG_INVISIBLE)) {
                    renderTaskPtr->appendGfxArg = NULL;
                    renderTaskPtr->appendGfx = appendGfx_partner_actor;
                    renderTaskPtr->dist = actor->curPos.z;
                    renderTaskPtr->renderMode = actor->renderMode;
                    queue_render_task(renderTaskPtr);

                    if (actor->flags & ACTOR_FLAG_BLUR_ENABLED) {
                        renderTaskPtr->appendGfxArg = actor;
                        renderTaskPtr->appendGfx = appendGfx_partner_actor_blur;
                        renderTaskPtr->dist = actor->curPos.z;
                        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
                        queue_render_task(renderTaskPtr);
                    }

                    if (battleStatus->reflectFlags & BS_REFLECT_FLOOR) {
                        renderTaskPtr->appendGfxArg = NULL;
                        renderTaskPtr->appendGfx = appendGfx_partner_actor_reflection;
                        renderTaskPtr->dist = actor->curPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);
                    }
                }

                actor = battleStatus->playerActor;
                if (actor != NULL && !(actor->flags & ACTOR_FLAG_INVISIBLE)) {
                    renderTaskPtr->appendGfxArg = NULL;
                    renderTaskPtr->appendGfx = appendGfx_player_actor;
                    renderTaskPtr->dist = actor->curPos.z;
                    renderTaskPtr->renderMode = actor->renderMode;
                    queue_render_task(renderTaskPtr);

                    if (actor->flags & ACTOR_FLAG_BLUR_ENABLED) {
                        renderTaskPtr->appendGfxArg = actor;
                        renderTaskPtr->appendGfx = (void (*) (void*)) appendGfx_player_actor_blur;
                        renderTaskPtr->dist = actor->curPos.z;
                        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;
                        queue_render_task(renderTaskPtr);
                    }

                    if (battleStatus->reflectFlags & BS_REFLECT_FLOOR) {
                        renderTaskPtr->appendGfxArg = NULL;
                        renderTaskPtr->appendGfx = appendGfx_player_actor_reflection;
                        renderTaskPtr->dist = actor->curPos.z;
                        renderTaskPtr->renderMode = actor->renderMode;
                        queue_render_task(renderTaskPtr);
                    }
                }
            }
        }
    }
}

u16 blend_tattle_background_channel(u16 a, s32 b, s32 alpha) {
    return a + (b - a) * alpha / 256;
}

void tattle_cam_pre_render(Camera* camera) {
    Camera* cam = &gCameras[gCurrentCamID];
    s32 fogEnabled = FALSE;
    u8 r1, g1, b1, a1;
    s32 fogR, fogG, fogB, fogA;
    s32 i;

    s32 lineHeight;
    s32 numLines;
    s32 bgWidth, bgHeight;
    s32 posX, posY;
    s32 texOffsetX;
    s32 extraHeight;
    s16 texOffsetY;

    hide_foreground_models_unchecked();

    if (is_world_fog_enabled()) {
        fogEnabled = TRUE;
        get_world_fog_color(&fogR, &fogG, &fogB, &fogA);
        fogA = gGameStatusPtr->backgroundDarkness;
        mdl_get_shroud_tint_params(&r1, &g1, &b1, &a1);
        if (fogA == 255) {
            for (i = 0; i < ARRAY_COUNT(gTattleBgPalette); i++) {
                gTattleBgPalette[i] = 1;
            }
        } else {
            for (i = 0; i < ARRAY_COUNT(gTattleBgPalette); i++) {
                u16 palColor = gGameStatusPtr->backgroundPalette[i];
                u16 blendedB = blend_tattle_background_channel(UNPACK_PAL_B(palColor), fogB >> 3, fogA);
                u16 blendedG = blend_tattle_background_channel(UNPACK_PAL_G(palColor), fogG >> 3, fogA);
                u16 blendedR = blend_tattle_background_channel(UNPACK_PAL_R(palColor), fogR >> 3, fogA);
                gTattleBgPalette[i] = blendedB << 1 | blendedG << 6 | blendedR << 11 | 1;
            }
        }
    }

    if (gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_TEXTURE) {
        gDPPipeSync(gMainGfxPos++);
        gDPSetCycleType(gMainGfxPos++, G_CYC_COPY);
        gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
        gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
        gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, cam->viewportStartX, cam->viewportStartY, cam->viewportStartX + cam->viewportW - 1, cam->viewportStartY + cam->viewportH - 1);
        gDPPipeSync(gMainGfxPos++);
        if (!fogEnabled) {
            gDPLoadTLUT_pal256(gMainGfxPos++, gGameStatusPtr->backgroundPalette);
        } else {
            gDPLoadTLUT_pal256(gMainGfxPos++, gTattleBgPalette);
        }
        bgWidth = gGameStatusPtr->backgroundMaxX;
        bgHeight = gGameStatusPtr->backgroundMaxY;
        texOffsetX = 0;
        lineHeight = 2048 / bgWidth;
        numLines = gGameStatusPtr->backgroundMaxY / lineHeight;
        extraHeight = gGameStatusPtr->backgroundMaxY % lineHeight;
        posX = cam->viewportStartX;
        posY = cam->viewportStartY;
        for (i = 0; i < numLines; i++) {
            texOffsetY = gTattleBgTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgWidth * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgWidth, 6,
                               0, 0, 295, 5, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gMainGfxPos++, posX * 4, (lineHeight * i + posY) * 4,
                                                 (texOffsetX + posX - 1) * 4, (lineHeight * i + lineHeight - 1 + posY) * 4,
                                                 G_TX_RENDERTILE, bgWidth * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, (texOffsetX + posX) * 4, (lineHeight * i + posY) * 4,
                                                 (bgWidth + posX - 1) * 4, (lineHeight * i + lineHeight - 1 + posY) * 4,
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
        if (extraHeight != 0) {
            texOffsetY = gTattleBgTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgWidth * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgWidth, extraHeight,
                               0, 0, 295, extraHeight - 1, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++, posX * 4, (i * lineHeight + posY) * 4,
                                                 (texOffsetX + posX - 1) * 4, (bgHeight + - 1 + posY) * 4,
                                                 G_TX_RENDERTILE, bgWidth * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, (texOffsetX + posX) * 4, (i * lineHeight + posY) * 4,
                                                 (bgWidth + posX - 1) * 4, (bgHeight - 1 + posY) * 4,
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
    }

    gSPViewport(gMainGfxPos++, &cam->vp);
    gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPTexture(gMainGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPPipelineMode(gMainGfxPos++, G_PM_NPRIMITIVE);
    gDPSetScissorFrac(gMainGfxPos++, G_SC_NON_INTERLACE, cam->viewportStartX * 4.0f, cam->viewportStartY * 4.0f, (cam->viewportStartX + cam->viewportW) * 4.0f, (cam->viewportStartY + cam->viewportH) * 4.0f);
    gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
    gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
    gDPSetCombineMode(gMainGfxPos++, G_CC_SHADE, G_CC_SHADE);
    gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
    gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);
    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxZBuffer));
    gDPSetFillColor(gMainGfxPos++, PACK_FILL_DEPTH(G_MAXFBZ, 0));
    gDPFillRectangle(gMainGfxPos++, cam->viewportStartX, cam->viewportStartY, cam->viewportStartX + cam->viewportW - 1, cam->viewportStartY + cam->viewportH - 1);
    gDPPipeSync(gMainGfxPos++);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));

    if (!(gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_TEXTURE)) {
        gDPSetCycleType(gMainGfxPos++, G_CYC_FILL);
        gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(cam->bgColor[0], cam->bgColor[1], cam->bgColor[2], 1));
        gDPFillRectangle(gMainGfxPos++, cam->viewportStartX, cam->viewportStartY, cam->viewportStartX + cam->viewportW - 1, cam->viewportStartY + cam->viewportH - 1);
    }

    gDPPipeSync(gMainGfxPos++);
    gSPPerspNormalize(gMainGfxPos++, cam->perspNorm);
    guMtxF2L(cam->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
}

void tattle_cam_post_render(Camera* camera) {
    show_foreground_models_unchecked();
}

void btl_draw_enemy_health_bars(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (!gGameStatusPtr->healthBarsEnabled) {
        return;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_ACTORS_VISIBLE) {
        s32 i;

        for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
            Actor* enemy = battleStatus->enemyActors[i];

            if (enemy != NULL) {
                s32 currentHP;
                s32 temp;
                s32 ones;

                currentHP = enemy->curHP;
                temp = (currentHP * 25) / enemy->maxHP;

                if (temp < enemy->healthFraction) {
                    enemy->healthFraction -= 2;
                    if (enemy->healthFraction < temp) {
                        enemy->healthFraction = temp;
                    }
                }

                if (enemy->healthFraction < temp) {
                    enemy->healthFraction += 2;
                    if (enemy->healthFraction > temp) {
                        enemy->healthFraction = temp;
                    }
                }

                if (!(enemy->flags & (ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_TARGET_ONLY))
                    && ((gBattleStatus.flags1 & BS_FLAGS1_MENU_OPEN) || (enemy->flags & ACTOR_FLAG_HEALTH_BAR_HIDDEN))
                    && is_actor_health_bar_visible(enemy)
                ) {
                    f32 x = enemy->healthBarPos.x;
                    f32 y = enemy->healthBarPos.y;
                    f32 z = enemy->healthBarPos.z;

                    if (enemy->healthBarPos.y >= -500) {
                        s32 screenX, screenY, screenZ;
                        s32 id;

                        get_screen_coords(CAM_BATTLE, x, y, z, &screenX, &screenY, &screenZ);
                        screenY += 16;
                        id = D_8029EFBC;
                        hud_element_set_render_depth(id, 10);
                        hud_element_set_script(id, &HES_HPBar);
                        hud_element_set_render_pos(id, screenX, screenY);
                        hud_element_draw_clipped(id);

                        temp = currentHP / 10;
                        ones = currentHP % 10;

                        // tens digit
                        if (temp > 0) {
                            id = D_8029EFBC;
                            hud_element_set_render_depth(id, 10);
                            hud_element_set_script(id, bHPDigitHudScripts[temp]);
                            btl_draw_prim_quad(0, 0, 0, 0, screenX, screenY + 2, 8, 8);
                            hud_element_set_render_pos(id, screenX + 4, screenY + 6);
                            hud_element_draw_next(id);
                        }

                        // ones digit
                        id = D_8029EFBC;
                        hud_element_set_render_depth(id, 10);
                        hud_element_set_script(id, bHPDigitHudScripts[ones]);
                        btl_draw_prim_quad(0, 0, 0, 0, screenX + 6, screenY + 2, 8, 8);
                        hud_element_set_render_pos(id, screenX + 10, screenY + 6);
                        hud_element_draw_next(id);

                        temp = enemy->healthFraction;
                        temp = 25 - temp;
                        btl_draw_prim_quad(168, 0, 0, 255, screenX + 11 - temp, screenY - 7, temp, 1);
                        btl_draw_prim_quad(255, 0, 0, 255, screenX + 11 - temp, screenY - 6, temp, 4);
                    }
                }
            }
        }
    }
}

NOP_FIX

void btl_update_starpoints_display(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 cond;
    s32 i;

    if (gBattleStatus.flags1 & BS_FLAGS1_ACTORS_VISIBLE) {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_AWARDING_STAR_POINTS)) {
            StarPointsBasePosX = 292;
            StarPointsBasePosY = 196;
            StarPointsMoveInterpAmt = 6;
            D_8029DA4C = battleStatus->totalStarPoints % 10;
        } else {
            StarPointsBasePosX += (202 - StarPointsBasePosX) / StarPointsMoveInterpAmt;
            StarPointsBasePosY += (120 - StarPointsBasePosY) / StarPointsMoveInterpAmt;
            StarPointsMoveInterpAmt--;
            if (StarPointsMoveInterpAmt < 1) {
                StarPointsMoveInterpAmt = 1;
            }
        }

        cond = TRUE;
        if (D_802809F4 != 0) {
            if (D_802809F5 > 8) {
                if (D_802809F5 <= 12) {
                    cond = FALSE;
                } else {
                    D_802809F5 = 0;
                }
            }
            D_802809F5++;
        }


        if (cond) {
            s32 posX, posY;
            s32 tens, ones;
            s32 id;
            f32 one = 1.0f;

            battleStatus->incrementStarPointDelay--;
            D_802809F0 -= 1.0;
            if (D_802809F0 <= 0.0f) {
                s32 pendingStarPoints;

                if (battleStatus->pendingStarPoints > 0) {
                    battleStatus->totalStarPoints++;
                    if (battleStatus->totalStarPoints > 100) {
                        battleStatus->totalStarPoints = 100;
                    }
                    battleStatus->pendingStarPoints--;
                }

                pendingStarPoints = battleStatus->pendingStarPoints;
                if (pendingStarPoints < 1) {
                    pendingStarPoints = 1;
                }

                D_802809F0 = (f32) battleStatus->incrementStarPointDelay / pendingStarPoints;
                if (D_802809F0 < 1.0) {
                    D_802809F0 = 1.0f;
                }
                if (D_802809F0 > 6.0) {
                    D_802809F0 = 6.0f;
                }
            }

            posX = StarPointsBasePosX;
            posY = StarPointsBasePosY;
            tens = battleStatus->totalStarPoints / 10;
            ones = battleStatus->totalStarPoints % 10;

            for (i = 0; i < tens; i++) {
                id = BtlStarPointTensHIDs[i];
                if (hud_element_get_script(id) != &HES_Item_StarPoint) {
                    hud_element_set_script(id, &HES_Item_StarPoint);
                }
                hud_element_clear_flags(id, 2);
                hud_element_set_render_pos(id, posX, posY);
                hud_element_draw_clipped(id);

                id = BtlStarPointShinesHIDs[i];
                if (hud_element_get_script(id) != &HES_StatusSPShine) {
                    hud_element_set_script(id, &HES_StatusSPShine);
                }
                hud_element_clear_flags(id, 2);
                hud_element_set_render_pos(id, posX, posY - 5);
                hud_element_draw_clipped(id);
                posX -= (one * 20.0f);
            }

           for (; i < ARRAY_COUNT(BtlStarPointTensHIDs); i++) {
                hud_element_set_flags(BtlStarPointTensHIDs[i], HUD_ELEMENT_FLAG_DISABLED);
                hud_element_set_flags(BtlStarPointShinesHIDs[i], HUD_ELEMENT_FLAG_DISABLED);
            }

            posX = StarPointsBasePosX;
            posY = StarPointsBasePosY + (one * 14.0f);
            if (gBattleStatus.flags2 & BS_FLAGS2_AWARDING_STAR_POINTS) {
                if (ones != 0) {
                    draw_box(0, WINDOW_STYLE_4, posX - 100, posY - 5, 0, 110, 12, 120, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL,
                             NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                }
            }

            for (i = 0; i < ones; i++) {
                id = BtlStarPointOnesHIDs[i];
                if (hud_element_get_script(id) != &HES_Item_SmallStarPoint) {
                    hud_element_set_script(id, &HES_Item_SmallStarPoint);
                }
                hud_element_clear_flags(id, 2);
                hud_element_set_render_pos(id, posX, posY);
                hud_element_draw_clipped(id);
                posX -= one * 10.0f;
            }

            for (; i < ARRAY_COUNT(BtlStarPointOnesHIDs); i++) {
                hud_element_set_flags(BtlStarPointOnesHIDs[i], HUD_ELEMENT_FLAG_DISABLED);
            }
        }
    }
}

void btl_save_world_cameras(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        SavedWorldCameras[i] = gCameras[i];
    }

    SavedWorldPlayerPosX = playerStatus->pos.x;
    SavedWorldPlayerPosY = playerStatus->pos.y;
    SavedWorldPlayerPosZ = playerStatus->pos.z;
    playerStatus->pos.x = NPC_DISPOSE_POS_X;
    playerStatus->pos.y = NPC_DISPOSE_POS_Y;
    playerStatus->pos.z = NPC_DISPOSE_POS_Z;
}

void btl_restore_world_cameras(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i] = SavedWorldCameras[i];
    }

    gCurrentCameraID = CAM_DEFAULT;
    playerStatus->pos.x = SavedWorldPlayerPosX;
    playerStatus->pos.y = SavedWorldPlayerPosY;
    playerStatus->pos.z = SavedWorldPlayerPosZ;

    if (bSavedOverrideFlags & GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION) {
        gOverrideFlags |= GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    }

    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
        playerData->curPartner = bSavedPartner;
    }
}

void btl_delete_actor(Actor* actor) {
    ActorPart* part;
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
    if (actor->handleEventScript != NULL) {
        kill_script_by_ID(actor->handleEventScriptID);
    }
    if (actor->takeTurnScript != NULL) {
        kill_script_by_ID(actor->takeTurnScriptID);
    }
    set_actor_glow_pal(actor, GLOW_PAL_OFF);

    part = actor->partsTable;

    while (part != NULL) {
        if (!(part->flags & ACTOR_PART_FLAG_NO_SHADOW)) {
            delete_shadow(part->shadowIndex);
        }

        if (part->idleAnimations != NULL) {
            set_npc_imgfx_all(part->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, 0);

            ASSERT(spr_free_sprite(part->spriteInstanceID) == 0);

            if (!(part->flags & ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC)) {
                heap_free(part->movement);
            }

            if (!(part->flags & ACTOR_PART_FLAG_NO_DECORATIONS)) {
                heap_free(part->decorationTable);
            }
        }
        actorPartTemp = part->nextPart;
        heap_free(part);
        part = actorPartTemp;
    }

    delete_shadow(actor->shadow.id);
    remove_all_status_icons(actor->hudElementDataIndex);
    remove_effect(actor->disableEffect);

    if (actor->attackResultEffect != NULL) {
        actor->attackResultEffect->data.attackResultText->isVisible = FALSE;
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
    ActorPart* partsTable;
    ActorPartMovement* movement;
    DecorationTable* decorations;
    s32 i;

    for (i = 0; i < 2; i++) {
        remove_actor_decoration(player, i);
    }

    if (player->idleScript != NULL) {
        kill_script_by_ID(player->idleScriptID);
    }
    if (player->handleEventScript != NULL) {
        kill_script_by_ID(player->handleEventScriptID);
    }
    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnScriptID);
    }

    partsTable = player->partsTable;
    decorations = partsTable->decorationTable;
    movement = partsTable->movement;

    delete_shadow(player->shadow.id);
    remove_all_status_icons(player->hudElementDataIndex);
    remove_effect(player->disableEffect);

    if (player->attackResultEffect != NULL) {
        player->attackResultEffect->data.attackResultText->isVisible = FALSE;
    }

    heap_free(movement);
    heap_free(decorations);
    heap_free(partsTable);
    heap_free(player);
}
