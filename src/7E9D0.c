// this file and world/actions.c are candidates for merging

#include "common.h"
#include "world/partners.h"
#include "world/actions.h"
#include "npc.h"
#include "effects.h"
#include "ld_addrs.h"

#ifdef SHIFT
#define PLAYER_ACTION_VRAM_DEF texture_memory_VRAM_END
#else
#define PLAYER_ACTION_VRAM_DEF (void*) 0x802B6000
#endif

SHIFT_BSS void* D_8010C924;
SHIFT_BSS s32 D_8010C92C;
SHIFT_BSS s32 D_8010C964;
SHIFT_BSS s32 gSpinHistoryBufferPos;
SHIFT_BSS s16 D_8010C9B0;
SHIFT_BSS s32 gSpinHistoryPosY[5];
SHIFT_BSS s32 gSpinHistoryPosX[5];
SHIFT_BSS s32 gSpinHistoryPosZ[5];
SHIFT_BSS s16 gSpinHistoryPosAngle[5];

void func_800E5520(void) {
    D_8010C9B0 = 0;
}

s32 phys_adjust_cam_on_landing(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    GameStatus* gameStatus = gGameStatusPtr;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 ret = 1;

    //TODO hardcoded map IDs
    switch (gameStatus->areaID) {
        case AREA_OBK:
            ret = gameStatus->mapID != 4;
            break;
        case AREA_ISK:
            switch (gameStatus->mapID) {
                case 0:
                    ret = 2;
                    break;
                case 1:
                    if (D_8010C9B0 == 0) {
                        if (playerStatus->pos.y <= 0.0f) {
                            D_8010C9B0 = 1;
                        }
                        ret = 2;
                    } else if (playerStatus->pos.y > 0.0f) {
                        ret = 0;
                    }
                    break;
                case 3:
                    if (playerStatus->pos.y > 25.0f) {
                        ret = 0;
                    }
                    break;
                case 4:
                    if (playerStatus->pos.y > 50.0f) {
                        ret = 0;
                    }
                    break;
                case 7:
                    if (playerStatus->pos.y > -390.0f) {
                        ret = 0;
                    } else if (playerStatus->pos.y < -495.0f) {
                        ret = 0;
                    }
                    break;
                case 8:
                    if (playerStatus->pos.y > -90.0f) {
                        ret = 0;
                    } else if (playerStatus->pos.y < -370.0f) {
                        ret = 0;
                    }
                    break;
                case 2:
                    if (gGameStatusPtr->entryID == 0) {
                        if (D_8010C9B0 == 0) {
                            if (!(playerStatus->pos.y > 0.0f)) {
                                D_8010C9B0 = 1;
                            } else {
                                ret = 2;
                                break;
                            }
                        }

                        if (playerStatus->pos.y > 0.0f) {
                            ret = 0;
                        }
                    } else {
                        ret = 2;
                    }
                    break;
                case 5:
                    if (gGameStatusPtr->entryID == 0) {
                        if (D_8010C9B0 == 0) {
                            if (!(playerStatus->pos.y > -130.0f)) {
                                D_8010C9B0 = 1;
                            } else {
                                ret = 2;
                                break;
                            }

                        }

                        if (playerStatus->pos.y > -130.0f) {
                            ret = 0;
                        }
                    } else {
                        ret = 2;
                    }
                    break;
                case 10:
                    if (D_8010C9B0 == 0) {
                        if (!(playerStatus->pos.y > -520.0f)) {
                            D_8010C9B0 = 1;
                        } else {
                            ret = 2;
                            break;
                        }
                    }

                    if (playerStatus->pos.y > -520.0f) {
                        ret = 0;
                    }
                    break;
                case 11:
                    if (gGameStatusPtr->entryID == 0) {
                        if (D_8010C9B0 == 0) {
                            if (!(playerStatus->pos.y > -520.0f)) {
                                D_8010C9B0 = 1;
                            } else {
                                ret = 2;
                                break;
                            }

                        }

                        if (playerStatus->pos.y > -520.0f) {
                            ret = 0;
                        }
                    }

                    if (evt_get_variable(NULL, GB_StoryProgress) >= STORY_CH2_DRAINED_THIRD_SAND_ROOM) {
                        ret = 2;
                    }
                    break;
            }
            break;
    }

    if (ret == 1) {
        s32 surfaceType = get_collider_flags(gCollisionStatus.curFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;

        if (surfaceType == SURFACE_TYPE_LAVA) {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
            ret = 0;
        } else {
            gCameras[CAM_DEFAULT].moveFlags &= ~CAMERA_MOVE_IGNORE_PLAYER_Y;
        }
    } else if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE && partnerStatus->actingPartner == PARTNER_PARAKARRY) {
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAG_2;
    } else {
        gCameras[CAM_DEFAULT].moveFlags &= ~CAMERA_MOVE_FLAG_2;
    }

    return ret;
}

void phys_clear_spin_history(void) {
    s32 i;

    gSpinHistoryBufferPos = 0;

    for (i = 0; i < ARRAY_COUNT(gSpinHistoryPosY); i++) {
        gSpinHistoryPosAngle[i] = 180;
        gSpinHistoryPosY[i] = 0x80000000;
    }
}

f32 phys_get_spin_history(s32 lag, s32* x, s32* y, s32* z) {
    s32 idx = gSpinHistoryBufferPos;

    // Can't get this if/else to match otherwise...
    if (idx - lag >= 0) {
        idx -= lag;
    } else {
        idx = gSpinHistoryBufferPos - lag + 5;
    }

    *x = gSpinHistoryPosX[idx];
    *y = gSpinHistoryPosY[idx];
    *z = gSpinHistoryPosZ[idx];
    return gSpinHistoryPosAngle[idx];
}

void phys_reset_spin_history(void) {
    s32 i;

    mem_clear(&gPlayerSpinState, sizeof(PlayerSpinState));
    gSpinHistoryBufferPos = 0;

    for (i = 0; i < ARRAY_COUNT(gSpinHistoryPosAngle); i++) {
        gSpinHistoryPosAngle[i] = 0;
        gSpinHistoryPosX[i] = 0;
        gSpinHistoryPosY[i] = 0;
        gSpinHistoryPosZ[i] = 0;
    }

    D_8010C964 = 0;
    D_8010C924 = NULL;
}

void phys_update_action_state(void) {
    Camera* cameras = gCameras;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerSpinState* playerSpinState = &gPlayerSpinState;

    if (!(playerStatus->flags & PS_FLAG_ENTERING_BATTLE)) {
        playerStatus->flags &= ~PS_FLAG_TIME_STOPPED;
    }

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        phys_peach_update();
        return;
    }

    if (playerStatus->camResetDelay != 0) {
        playerStatus->camResetDelay--;
        if (playerStatus->camResetDelay == 0) {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAG_4;
        }
    }

    // if midair, look for velocity inflection
    if (playerStatus->timeInAir != 0) {
        if (playerStatus->gravityIntegrator[0] <= 0.0f && LastMidairPlayerVelY > 0.0f) {
            playerStatus->peakJumpTime = playerStatus->timeInAir;
        }
        LastMidairPlayerVelY = playerStatus->gravityIntegrator[0];
    }

    func_800E24F8();
    if (playerSpinState->stopSoundTimer != 0) {
        playerSpinState->stopSoundTimer--;
        if (playerSpinState->stopSoundTimer == 0) {
            playerStatus->animFlags &= ~PA_FLAG_SPINNING;
            if (playerSpinState->spinSoundID != 0) {
                sfx_stop_sound(playerSpinState->spinSoundID);
            }
        }
    }

    do {
        s32 actionState = playerStatus->actionState;

        if (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN) {
            s32 cond;

            if (!(playerStatus->flags & PS_FLAG_INPUT_DISABLED)) {
                cond = check_conversation_trigger();
            } else {
                cond = FALSE;
            }

            if ((partnerStatus->partnerActionState == PARTNER_ACTION_NONE) && !(playerStatus->flags & PS_FLAG_PAUSED) && cond) {
                set_action_state(ACTION_STATE_TALK);
            }
            check_input_spin();
        }

        if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
            void* dmaStart = PlayerActionsTable[playerStatus->actionState].dmaStart;

            if (dmaStart != NULL && dmaStart != D_8010C924) {
                D_8010C924 = dmaStart;
                dma_copy(dmaStart, PlayerActionsTable[playerStatus->actionState].dmaEnd, PLAYER_ACTION_VRAM_DEF);
            }
        }
        PlayerActionsTable[playerStatus->actionState].update();
    } while (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED);
}

void phys_peach_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    func_800E24F8();

    do {
        if (!(playerStatus->flags & PS_FLAG_PAUSED) && check_conversation_trigger()) {
            set_action_state(ACTION_STATE_TALK);
        }

        if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
            Action* action = &PlayerActionsTable[playerStatus->actionState];

            if (action->flag) {
                if (action->dmaStart != NULL && action->dmaStart != D_8010C924) {
                    D_8010C924 = action->dmaStart;

                    dma_copy(D_8010C924, PlayerActionsTable[playerStatus->actionState].dmaEnd, PLAYER_ACTION_VRAM_DEF);
                }

                if (PlayerActionsTable[playerStatus->actionState].flag) {
                    PlayerActionsTable[playerStatus->actionState].update();
                }
            }
        } else {
            if (PlayerActionsTable[playerStatus->actionState].flag) {
                PlayerActionsTable[playerStatus->actionState].update();
            }
        }
    } while (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED);

    peach_check_for_parasol_input();
    if (playerStatus->animFlags & PA_FLAG_INVISIBLE) {
        peach_sync_disguise_npc();
    }
}

void set_action_state(s32 actionState) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    PlayerSpinState* spinState = &gPlayerSpinState;

    if (playerStatus->flags & PS_FLAG_SPECIAL_JUMP) {
        playerStatus->flags &= ~PS_FLAG_SPECIAL_JUMP;
        enable_player_input();
    }

    if (playerStatus->animFlags & PA_FLAG_8BIT_MARIO) {
        // TODO figure this out
#ifdef NON_EQUIVALENT
        if (
            actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK ||
            actionState == ACTION_STATE_RUN || actionState == ACTION_STATE_JUMP ||
            actionState == ACTION_STATE_BOUNCE || actionState == ACTION_STATE_HOP ||
            actionState == ACTION_STATE_LAUNCH || actionState == ACTION_STATE_LANDING_ON_SWITCH ||
            actionState == ACTION_STATE_FALLING || actionState == ACTION_STATE_STEP_DOWN ||
            actionState == ACTION_STATE_LAND || actionState == ACTION_STATE_STEP_DOWN_LAND
        ) {
#else
        if (actionState < ACTION_STATE_TALK)
            if (actionState >= 0) {
#endif
            playerStatus->prevActionState = playerStatus->actionState;
            playerStatus->actionState = actionState;
            playerStatus->flags |= PS_FLAG_ACTION_STATE_CHANGED;
        }
        return;
    }

    if (actionState == ACTION_STATE_HIT_FIRE || actionState == ACTION_STATE_HIT_LAVA) {
        s8 partner;

        if (playerStatus->hazardType == HAZARD_TYPE_FIRE_BAR) {
            actionState = ACTION_STATE_HIT_FIRE;
        }

        // Whilst Sushie, Lakilester, or Parakarry's ability is active, hazards have no effect.
        partner = playerData->curPartner;

        if (partner == PARTNER_SUSHIE || partner == PARTNER_LAKILESTER || partner == PARTNER_PARAKARRY) {
            if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
                playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
                playerStatus->flags |= PS_FLAG_HIT_FIRE;
                return;
            }
        }
    }

    if (actionState == ACTION_STATE_SLIDING) {
        playerStatus->flags |= PS_FLAG_SLIDING;
        playerStatus->moveFrames = 0;
        playerStatus->flags &= ~PS_FLAG_CUTSCENE_MOVEMENT;
    }

    playerStatus->prevActionState = playerStatus->actionState;
    if (actionState == ACTION_STATE_USE_TWEESTER) {
        playerStatus->prevActionState = ACTION_STATE_IDLE;
    }

    if (actionState == ACTION_STATE_ENEMY_FIRST_STRIKE) {
        playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
    }
    playerStatus->actionState = actionState;
    playerStatus->flags |= PS_FLAG_ACTION_STATE_CHANGED;

    if (playerStatus->actionState == ACTION_STATE_SPIN) {
        return;
    }

    playerStatus->flags &= ~PS_FLAG_SPINNING;
    playerStatus->animFlags &= ~PA_FLAG_SPINNING;

    if (spinState->spinSoundID != 0) {
        sfx_stop_sound(spinState->spinSoundID);
    }

    if (playerStatus->specialDecorationEffect != NULL) {
        playerStatus->specialDecorationEffect->data.spin->timeLeft = 10;
        playerStatus->specialDecorationEffect = NULL;
    }
}

void update_locomotion_state(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (!is_ability_active(ABILITY_SLOW_GO) &&
        SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1]) > SQ(55))
    {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}

void start_falling(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_FALLING);
    LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
}

void start_bounce_a(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_BOUNCE);
    playerStatus->gravityIntegrator[0] = 10.0f;
    playerStatus->gravityIntegrator[1] = -2.0f;
    playerStatus->gravityIntegrator[2] = 0.8f;
    playerStatus->gravityIntegrator[3] = -0.75f;
}

void start_bounce_b(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    set_action_state(ACTION_STATE_BOUNCE);
    playerStatus->gravityIntegrator[0] = 8.0f;
    playerStatus->gravityIntegrator[1] = -1.0f;
    playerStatus->gravityIntegrator[2] = 0;
    playerStatus->gravityIntegrator[3] = 0;
    playerStatus->flags |= PS_FLAG_SCRIPTED_FALL;
}

s32 check_input_hammer(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (playerStatus->pressedButtons & BUTTON_B) {
        if (playerStatus->flags & PS_FLAG_FALLING) {
            return FALSE;
        }

        if (gPartnerStatus.partnerActionState == PARTNER_ACTION_USE && playerData->curPartner == PARTNER_WATT) {
            return FALSE;
        }

        if (playerData->hammerLevel == -1) {
            return FALSE;
        }

        set_action_state(ACTION_STATE_HAMMER);
        return TRUE;
    }
    return FALSE;
}

s32 check_input_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 surfaceType;

    if (!(playerStatus->pressedButtons & BUTTON_A)) {
        return FALSE;
    }

    // @bug? collider flags not properly masked with COLLIDER_FLAG_SURFACE_TYPE
    surfaceType = get_collider_flags((u16)gCollisionStatus.curFloor);
    if ((surfaceType == SURFACE_TYPE_SLIDE) && phys_should_player_be_sliding()) {
        return FALSE;
    }

    if (collisionStatus->touchingWallTrigger != 0 ||
        (playerStatus->animFlags & (PA_FLAG_SPEECH_PROMPT_AVAILABLE |
                                    PA_FLAG_INTERACT_PROMPT_AVAILABLE)))
    {
        return FALSE;
    }

    if ((collisionStatus->curInspect != -1) && (collisionStatus->curInspect & COLLISION_WITH_ENTITY_BIT)) {
        Entity* entity = get_entity_by_index(collisionStatus->curInspect);

        if (entity->flags & ENTITY_FLAG_SHOWS_INSPECT_PROMPT) {
            if ((entity->boundScriptBytecode == 0) || (entity->flags & ENTITY_FLAG_4000)) {
                if (entity->type == ENTITY_TYPE_PINK_FLOWER ||
                    entity->type == ENTITY_TYPE_BELLBELL_PLANT ||
                    entity->type == ENTITY_TYPE_TRUMPET_PLANT)
                {
                    return FALSE;
                }
            } else {
                return FALSE;
            }
        }
    }

    set_action_state(ACTION_STATE_JUMP);
    return TRUE;
}

void check_input_spin(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerSpinState* spinState = &gPlayerSpinState;
    PlayerSpinState* temp2 = spinState;

    if (!((playerStatus->flags & (PS_FLAG_NO_STATIC_COLLISION | PS_FLAG_CUTSCENE_MOVEMENT)) ||
          (playerStatus->animFlags & PA_FLAG_USING_WATT) ||
          (playerStatus->curButtons & BUTTON_C_DOWN) ||
          is_ability_active(ABILITY_SLOW_GO))) {

        s32 actionState = playerStatus->actionState;
        s32 btnPressed = playerStatus->pressedButtons & Z_TRIG;

        // TODO
        if (actionState != ACTION_STATE_RIDE) {
            if (actionState < ACTION_STATE_STEP_UP) {
                if (actionState < ACTION_STATE_JUMP) {
                    if (actionState >= 0 && !(playerStatus->animFlags & PA_FLAG_SPINNING)) {
                        if (btnPressed || spinState->hasBufferedSpin) {
                            set_action_state(ACTION_STATE_SPIN);
                            if (spinState->hasBufferedSpin != FALSE) {
                                if (spinState->bufferedStickAxis.x != 0 || spinState->bufferedStickAxis.y != 0) {
                                    playerStatus->prevActionState = temp2->prevActionState;
                                } else {
                                    playerStatus->prevActionState = ACTION_STATE_IDLE;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void peach_set_disguise_anim(AnimID anim) {
    s32 listIndex = PeachDisguiseNpcIndex;

    if (listIndex >= 0) {
        get_npc_by_index(listIndex)->curAnim = anim;
    }
}

void peach_force_disguise_action(s32 useParasol) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (useParasol) {
        set_action_state(ACTION_STATE_USE_SNEAKY_PARASOL);
    } else {
        playerStatus->animFlags &= ~PA_FLAG_INVISIBLE;
        gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_DISGUISED;
        playerStatus->peachDisguise = PEACH_DISGUISE_NONE;
        free_npc_by_index(PeachDisguiseNpcIndex);
        set_action_state(ACTION_STATE_IDLE);
        playerStatus->colliderHeight = 55;
        playerStatus->colliderDiameter = 38;
    }
}

void peach_check_for_parasol_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;
    Npc* disguiseNpc;

    if (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN) {
        if (D_8010C92C != 0) {
            D_8010C92C--;
            if (D_8010C92C == 0) {
                if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_DISGUISED) {
                    playerStatus->animFlags |= PA_FLAG_INVISIBLE;
                    gGameStatusPtr->peachFlags |= PEACH_STATUS_FLAG_DISGUISED;

                    disguiseNpc = peach_make_disguise_npc(gGameStatusPtr->peachDisguise);
                    if (disguiseNpc != NULL) {
                        disguiseNpc->flags &= ~NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
                    }
                }
            }
        } else if (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_HAS_PARASOL && playerStatus->pressedButtons & BUTTON_B) {
            set_action_state(ACTION_STATE_USE_SNEAKY_PARASOL);
        }
    }
}

void peach_sync_disguise_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (PeachDisguiseNpcIndex >= 0) {
        Npc* npc = get_npc_by_index(PeachDisguiseNpcIndex);

        if (npc->flags & NPC_FLAG_IGNORE_CAMERA_FOR_YAW) {
            npc->renderYaw = playerStatus->spriteFacingAngle;
        } else {
            npc->yaw = playerStatus->targetYaw;
        }

        npc->pos.x = playerStatus->pos.x;
        npc->pos.y = playerStatus->pos.y;
        npc->pos.z = playerStatus->pos.z;
    }
}

Npc* peach_make_disguise_npc(s32 peachDisguise) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    NpcBlueprint bp;
    NpcBlueprint* bpPtr = &bp;
    Npc* npc;
    f32 yaw;

    if (peachDisguise == PEACH_DISGUISE_NONE) {
        return NULL;
    }

    playerStatus->colliderHeight = 37;
    playerStatus->colliderDiameter = 38;
    playerStatus->peachDisguise = peachDisguise;
    gGameStatusPtr->peachDisguise = peachDisguise;

    bpPtr->flags = NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
    bpPtr->initialAnim = BasicPeachDisguiseAnims[playerStatus->peachDisguise].idle;
    bpPtr->onUpdate = NULL;
    bpPtr->onRender = NULL;

    PeachDisguiseNpcIndex = create_standard_npc(bpPtr, PeachDisguiseExtraAnims[playerStatus->peachDisguise]);
    npc = get_npc_by_index(PeachDisguiseNpcIndex);

    disable_npc_shadow(npc);

    if (!(playerStatus->spriteFacingAngle >= 90.0f) || !(playerStatus->spriteFacingAngle < 270.0f)) {
        yaw = 180.0f;
    } else {
        yaw = 0.0f;
    }

    set_npc_yaw(npc, yaw);

    npc->pos.x = playerStatus->pos.x;
    npc->pos.y = playerStatus->pos.y;
    npc->pos.z = playerStatus->pos.z;

    return npc;
}

s32 peach_disguise_check_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 yaw, dx, dy;
    s32 radius;
    s32 hitID;
    s32 i;

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yaw = camera->curYaw - 270.0f;
    } else {
        yaw = camera->curYaw - 90.0f;
    }
    sin_cos_rad(DEG_TO_RAD(clamp_angle(yaw)), &dx, &dy);

    for (radius = 2, i = 2; i > 0; radius += 18, i--) {
        f32 x = playerStatus->pos.x + (dx * radius);
        f32 y = playerStatus->pos.y + 4.0f;
        f32 z = playerStatus->pos.z - (dy * radius);
        hitID = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
        if (hitID >= 0) {
            break;
        }
    }

    return hitID;
}
