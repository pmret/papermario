#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

EvtScript N(EVS_PlayBeamFX) = {
    Thread
        PlayEffect(EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, Float(1.0), 100, 0)
        Wait(5)
        PlayEffect(EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, Float(1.0), 100, 0)
        IfEq(LVarA, 1)
            Wait(5)
            PlayEffect(EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, Float(1.0), 100, 0)
        EndIf
    EndThread
    Wait(20)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
    Return
    End
};

s32 N(SpiritsFlyDelay)[] = { 35, 0, 5, 10, 15, 20, 25, 30 };
s32 N(SpiritsFlyAwayDelay)[] = { 35, 0, 5, 10, 15, 20, 25, 30 };

f32 N(SpiritsScatterPos)[] = {
      89.0f, 180.0f,   0.0f,
     -36.0f, 180.0f,   0.0f,
     204.0f, 180.0f,   0.0f,
      30.0f,  97.0f, 477.0f,
     230.0f,  81.0f,   0.0f,
     129.0f, 180.0f,   0.0f,
     -60.0f, 180.0f,   0.0f,
    -234.0f,  39.0f,   0.0f,
};

enum {
    PEACH_STAR_BEAM_CREATE_EFFECT           = 0,
    PEACH_STAR_BEAM_SPIRITS_APPEAR          = 1,
    PEACH_STAR_BEAM_ZOOM_OUT                = 2,
    PEACH_STAR_BEAM_SHRINK_CIRCLE           = 3,
    PEACH_STAR_BEAM_FLY_TO_TARGET           = 4,
    PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS = 5,
    PEACH_STAR_BEAM_MAKE_BEAM               = 6,
    PEACH_STAR_BEAM_WAIT                    = 7,
    PEACH_STAR_BEAM_FADE_OUT_BEAM           = 8,
    PEACH_STAR_BEAM_START_FLY_AWAY          = 9,
    PEACH_STAR_BEAM_SPIRITS_FLY_AWAY        = 10,
    PEACH_STAR_BEAM_IMMUNE                  = 20,
    PEACH_STAR_BEAM_SPIRITS_SCATTER         = 21,
};

BSS EffectInstance* N(BeamEffect);
BSS char N(padding)[4];
BSS s32 N(MiscParticlesTimeLeft)[8];
BSS s32 N(SpiritsMoveTime)[8];
BSS s32 N(StarBeamStage);

API_CALLABLE(N(ProcessPeachStarBeam)) {
    PeachStarBeamFXData* effectData;
    PeachStarBeamSpirit* spirit;
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* playerState = &player->state;
    s32 i;
    f32 currentPosX, currentPosY, currentPosZ;
    f32 targetPosX, targetPosY, targetPosZ;
    f32 goalPosX, goalPosY, goalPosZ;
    s32 cond;
    Evt* newScript;
    f32 dist;

    enum {
        FT_STATE            = 0,
        FT_DELAY            = 1,
        FT_IS_PEACH_BEAM    = 2,
    };

    if (isInitialCall) {
        N(StarBeamStage) = 0;
        script->functionTemp[FT_IS_PEACH_BEAM] = evt_get_variable(script, *args++);
        script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_CREATE_EFFECT;
    }

    if (player->targetListLength == 1) {
        Actor* target = get_actor(player->targetActorID);
        if (target == NULL) {
            return ApiStatus_DONE2;
        }
        get_actor_part(target, player->targetPartID);
        targetPosX = target->curPos.x + target->headOffset.x;
        if (target->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            targetPosY = target->curPos.y + target->headOffset.y - target->size.y;
        } else if (!(target->flags & ACTOR_FLAG_HALF_HEIGHT)) {
            targetPosY = target->curPos.y + target->headOffset.y + target->size.y;
        } else {
            targetPosY = target->curPos.y + target->headOffset.y + target->size.y * 2;
        }
        targetPosZ = target->curPos.z + target->headOffset.z;
    } else {
        targetPosX = 64.0f;
        targetPosY = 80.0f;
        targetPosZ = 0.0f;
    }

    switch (script->functionTemp[FT_STATE]) {
        case PEACH_STAR_BEAM_SPIRITS_APPEAR:
        case PEACH_STAR_BEAM_ZOOM_OUT:
        case PEACH_STAR_BEAM_SHRINK_CIRCLE:
        case PEACH_STAR_BEAM_FLY_TO_TARGET:
        case PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS:
        case PEACH_STAR_BEAM_MAKE_BEAM:
        case PEACH_STAR_BEAM_WAIT:
        case PEACH_STAR_BEAM_FADE_OUT_BEAM:
        case PEACH_STAR_BEAM_START_FLY_AWAY:
            effectData = N(BeamEffect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[FT_IS_PEACH_BEAM] || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(MiscParticlesTimeLeft)[i] != 0) {
                        N(MiscParticlesTimeLeft)[i]--;
                    } else {
                        N(MiscParticlesTimeLeft)[i] = 20;
                        if (N(SpiritsFlyDelay)[i] <= 0) {
                            fx_misc_particles(4, spirit->lockedPos.x, spirit->lockedPos.y, spirit->lockedPos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        } else {
                            fx_misc_particles(4, spirit->pos.x, spirit->pos.y, spirit->pos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }
                    }
                }
            }
            break;
        case PEACH_STAR_BEAM_SPIRITS_FLY_AWAY:
            effectData = N(BeamEffect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[FT_IS_PEACH_BEAM] || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(MiscParticlesTimeLeft)[i] != 0) {
                        N(MiscParticlesTimeLeft)[i]--;
                    } else {
                        N(MiscParticlesTimeLeft)[i] = 20;
                        if (N(SpiritsFlyAwayDelay)[i] <= 0) {
                            fx_misc_particles(4, spirit->lockedPos.x, spirit->lockedPos.y, spirit->lockedPos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        } else {
                            fx_misc_particles(4, spirit->pos.x, spirit->pos.y, spirit->pos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }
                    }
                }
            }
            break;
    }

    switch (script->functionTemp[FT_STATE]) {
        case PEACH_STAR_BEAM_CREATE_EFFECT:
            currentPosX = player->curPos.x;
            currentPosY = player->curPos.y + player->size.y + 30.0f;
            currentPosZ = player->curPos.z;

            playerState->curPos.x = currentPosX;
            playerState->curPos.y = currentPosY + 150.0f;
            playerState->curPos.z = currentPosZ;

            playerState->goalPos.x = currentPosX;
            playerState->goalPos.y = currentPosY;
            playerState->goalPos.z = currentPosZ;

            if (!script->functionTemp[FT_IS_PEACH_BEAM]) {
                N(BeamEffect) = fx_peach_star_beam(0, currentPosX, currentPosY, currentPosZ, 1.0f, 0);
            } else {
                N(BeamEffect) = fx_peach_star_beam(1, currentPosX, currentPosY, currentPosZ, 1.0f, 0);
            }
            playerState->dist = 48.0f;
            N(BeamEffect)->data.peachStarBeam->unk_3C = 0;
            N(BeamEffect)->data.peachStarBeam->circleRadius = playerState->dist;
            N(BeamEffect)->data.peachStarBeam->beamAlpha = 0;
            N(BeamEffect)->data.peachStarBeam->twinkYOffset = 30.0f;
            N(BeamEffect)->data.peachStarBeam->rotSpeed = 5.0f;
            for (i = 0; i < ARRAY_COUNT(N(MiscParticlesTimeLeft)); i++) {
                N(MiscParticlesTimeLeft)[i] = rand_int(20);
            }

            script->functionTemp[FT_DELAY] = 40;
            if (!script->functionTemp[FT_IS_PEACH_BEAM]) {
                sfx_play_sound(SOUND_LOOP_USE_STAR_BEAM);
            } else {
                sfx_play_sound(SOUND_LOOP_USE_PEACH_BEAM);
            }
            script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_SPIRITS_APPEAR;
            break;
        case PEACH_STAR_BEAM_SPIRITS_APPEAR:
            playerState->curPos.y += (playerState->goalPos.y - playerState->curPos.y) / 10.0f;
            N(BeamEffect)->data.peachStarBeam->circleCenter.x = playerState->curPos.x;
            N(BeamEffect)->data.peachStarBeam->circleCenter.y = playerState->curPos.y;
            N(BeamEffect)->data.peachStarBeam->circleCenter.z = playerState->curPos.z;
            N(BeamEffect)->data.peachStarBeam->unk_3C = 0;
            N(BeamEffect)->data.peachStarBeam->circleRadius = playerState->dist;
            N(BeamEffect)->data.peachStarBeam->beamAlpha = 0;
            if (script->functionTemp[FT_DELAY] == 0) {
                script->functionTemp[FT_DELAY] = 20;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_ZOOM_OUT;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_ZOOM_OUT:
            if (script->functionTemp[FT_DELAY] == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(10);
                script->functionTemp[FT_DELAY] = 15;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_SHRINK_CIRCLE;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_SHRINK_CIRCLE:
            playerState->dist += (24.0f - playerState->dist) * 0.125f;
            N(BeamEffect)->data.peachStarBeam->circleRadius = playerState->dist;
            if (script->functionTemp[FT_DELAY] == 0) {
                playerState->goalPos.x = targetPosX;
                playerState->goalPos.y = targetPosY;
                playerState->goalPos.z = targetPosZ;
                for (i = 0; i < ARRAY_COUNT(N(SpiritsMoveTime)); i++) {
                    N(SpiritsMoveTime)[i] = 30;
                }

                if (!script->functionTemp[FT_IS_PEACH_BEAM]) {
                    sfx_play_sound(SOUND_LRAW_USE_STAR_BEAM | SOUND_ID_TRIGGER_CHANGE_SOUND);
                } else {
                    sfx_play_sound(SOUND_LRAW_USE_PEACH_BEAM | SOUND_ID_TRIGGER_CHANGE_SOUND);
                }
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_FLY_TO_TARGET;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_FLY_TO_TARGET:
            cond = FALSE;
            playerState->dist += (48.0f - playerState->dist) * 0.25f;
            N(BeamEffect)->data.peachStarBeam->circleRadius = playerState->dist;
            for (i = 0; i < 2; i++) {
                if (i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(SpiritsFlyDelay)[i] < 0) {
                        currentPosX = playerState->curPos.x;
                        currentPosY = playerState->curPos.y;
                        currentPosZ = playerState->curPos.z;

                        goalPosX = playerState->goalPos.x;
                        goalPosY = playerState->goalPos.y;
                        goalPosZ = playerState->goalPos.z;

                        playerState->curPos.x += goalPosX - currentPosX;
                        playerState->curPos.y += goalPosY - currentPosY;
                        playerState->curPos.z += goalPosZ - currentPosZ;
                    } else {
                        cond = TRUE;
                        if (N(SpiritsFlyDelay)[i] != 0) {
                            N(SpiritsFlyDelay)[i]--;
                        } else {
                            currentPosX = playerState->curPos.x;
                            currentPosY = playerState->curPos.y;
                            currentPosZ = playerState->curPos.z;
                            goalPosX = playerState->goalPos.x;
                            goalPosY = playerState->goalPos.y;
                            goalPosZ = playerState->goalPos.z;
                            dist = dist2D(currentPosX, currentPosZ, goalPosX, goalPosZ);
                            playerState->curPos.x += (goalPosX - currentPosX) / N(SpiritsMoveTime)[i];
                            playerState->curPos.y += (goalPosY - currentPosY) / N(SpiritsMoveTime)[i];
                            playerState->curPos.z += (goalPosZ - currentPosZ) / N(SpiritsMoveTime)[i];
                            if (N(SpiritsMoveTime)[i] == 1) {
                                N(SpiritsFlyDelay)[i] = -1;
                                playerState->curPos.x = goalPosX;
                                playerState->curPos.y = goalPosY;
                                playerState->curPos.z = goalPosZ;
                            } else {
                                playerState->curPos.y += dist / 60.0f;
                            }
                            N(SpiritsMoveTime)[i]--;
                        }
                    }
                }
            }

            N(BeamEffect)->data.peachStarBeam->circleCenter.x = playerState->curPos.x;
            N(BeamEffect)->data.peachStarBeam->circleCenter.y = playerState->curPos.y;
            N(BeamEffect)->data.peachStarBeam->circleCenter.z = playerState->curPos.z;
            N(BeamEffect)->data.peachStarBeam->pos.x = playerState->curPos.x;
            N(BeamEffect)->data.peachStarBeam->pos.y = 0.0f;
            N(BeamEffect)->data.peachStarBeam->pos.z = playerState->curPos.z;
            if (!cond) {
                playerState->curPos.x = playerState->goalPos.x;
                playerState->curPos.y = playerState->goalPos.y;
                playerState->curPos.z = playerState->goalPos.z;
                N(BeamEffect)->data.peachStarBeam->circleCenter.x = playerState->curPos.x;
                N(BeamEffect)->data.peachStarBeam->circleCenter.y = playerState->curPos.y;
                N(BeamEffect)->data.peachStarBeam->circleCenter.z = playerState->curPos.z;
                N(BeamEffect)->data.peachStarBeam->pos.x = playerState->curPos.x;
                N(BeamEffect)->data.peachStarBeam->pos.y = 0.0f;
                N(BeamEffect)->data.peachStarBeam->pos.z = playerState->curPos.z;
                effectData = N(BeamEffect)->data.peachStarBeam;
                for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                    if (script->functionTemp[FT_IS_PEACH_BEAM] || i != 0) {
                        spirit = &effectData->spirits[i];
                        N(SpiritsFlyDelay)[i] = 1;
                        spirit->flags &= ~2;
                    }
                }

                btl_cam_use_preset(BTL_CAM_PRESET_03);
                btl_cam_move(30);
                script->functionTemp[FT_DELAY] = 15;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS;
            }
            break;
        case PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS:
            if (script->functionTemp[FT_DELAY] == 0) {
                playerState->moveTime = 0;
                N(BeamEffect)->data.peachStarBeam->unk_3C = 0;
                N(BeamEffect)->data.peachStarBeam->beamAlpha = 0;
                if (script->functionTemp[FT_IS_PEACH_BEAM]) {
                    N(BeamEffect)->data.peachStarBeam->primR = 240;
                    N(BeamEffect)->data.peachStarBeam->primG = 80;
                    N(BeamEffect)->data.peachStarBeam->primB = 200;
                    N(BeamEffect)->data.peachStarBeam->envR = 240;
                    N(BeamEffect)->data.peachStarBeam->envG = 240;
                    N(BeamEffect)->data.peachStarBeam->envB = 240;
                }
                newScript = start_script(&N(EVS_PlayBeamFX), EVT_PRIORITY_A, 0);

                newScript->varTable[0] = playerState->curPos.x;
                newScript->varTable[1] = playerState->curPos.y * 0.5f;
                newScript->varTable[2] = playerState->curPos.z;
                newScript->varTable[10] = script->functionTemp[FT_IS_PEACH_BEAM];

                do {} while (0); // required to match

                sfx_play_sound(SOUND_STAR_BEAM_FIRE);
                script->functionTemp[FT_DELAY] = 45;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_MAKE_BEAM;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_MAKE_BEAM:
            playerState->moveTime += 30;
            if (playerState->moveTime > 255) {
                playerState->moveTime = 255;
            }
            N(BeamEffect)->data.peachStarBeam->unk_3C = playerState->moveTime;
            N(BeamEffect)->data.peachStarBeam->beamAlpha = playerState->moveTime;
            if (script->functionTemp[FT_DELAY] == 0) {
                N(StarBeamStage) = 1;
                if (!script->functionTemp[FT_IS_PEACH_BEAM] && player->targetListLength == 1) {
                    if (get_actor_part(get_actor(player->targetActorID), player->targetPartID)->eventFlags & ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) {
                        script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_IMMUNE;
                    } else {
                        script->functionTemp[FT_DELAY] = 15;
                        script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_WAIT;
                    }
                } else {
                    script->functionTemp[FT_DELAY] = 15;
                    script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_WAIT;
                }
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_WAIT:
            if (script->functionTemp[FT_DELAY] == 0) {
                script->functionTemp[FT_DELAY] = 10;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_FADE_OUT_BEAM;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_FADE_OUT_BEAM:
            playerState->moveTime -= 30;
            if (playerState->moveTime < 0) {
                playerState->moveTime = 0;
            }
            N(BeamEffect)->data.peachStarBeam->unk_3C = playerState->moveTime;
            N(BeamEffect)->data.peachStarBeam->beamAlpha = playerState->moveTime;
            if (script->functionTemp[FT_DELAY] == 0) {
                script->functionTemp[FT_DELAY] = 10;
                script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_START_FLY_AWAY;
            } else {
                script->functionTemp[FT_DELAY]--;
            }
            break;
        case PEACH_STAR_BEAM_START_FLY_AWAY:
            if (script->functionTemp[FT_DELAY] != 0) {
                script->functionTemp[FT_DELAY]--;
                break;
            }
            playerState->goalPos.x = targetPosX;
            playerState->goalPos.y = targetPosY + 170.0f;
            playerState->goalPos.z = targetPosZ;
            script->functionTemp[FT_DELAY] = 20;
            script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_SPIRITS_FLY_AWAY;
            break;
        case PEACH_STAR_BEAM_SPIRITS_FLY_AWAY:
            if (script->functionTemp[FT_DELAY] != 0) {
                script->functionTemp[FT_DELAY]--;
                if (script->functionTemp[FT_DELAY] == 0) {
                    if (!script->functionTemp[FT_IS_PEACH_BEAM]) {
                        snd_stop_tracking_env_sound_pos(SOUND_LRAW_USE_STAR_BEAM, TRUE);
                        sfx_play_sound(SOUND_LRAW_USE_STAR_BEAM | SOUND_ID_TRIGGER_CHANGE_SOUND);
                    } else {
                        snd_stop_tracking_env_sound_pos(SOUND_LRAW_USE_PEACH_BEAM, TRUE);
                        sfx_play_sound(SOUND_LRAW_USE_PEACH_BEAM | SOUND_ID_TRIGGER_CHANGE_SOUND);
                    }
                }
            }
            cond = FALSE;
            effectData = N(BeamEffect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[FT_IS_PEACH_BEAM] || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(SpiritsFlyAwayDelay)[i] >= 0) {
                        cond = TRUE;
                        if (N(SpiritsFlyAwayDelay)[i] != 0) {
                            N(SpiritsFlyAwayDelay)[i]--;
                        } else {
                            spirit->flags |= 2;
                            currentPosY = spirit->lockedPos.y;
                            spirit->lockedPos.y += (playerState->goalPos.y - currentPosY) / 10.0f;
                            if (fabsf(spirit->lockedPos.y - playerState->goalPos.y) < 1.0) {
                                N(SpiritsFlyAwayDelay)[i] = -1;
                            }
                        }
                    }
                }
            }

            if (!cond) {
                N(StarBeamStage) = 2;
                N(BeamEffect)->flags |= FX_INSTANCE_FLAG_DISMISS;
                return ApiStatus_DONE2;
            }
            break;
        case PEACH_STAR_BEAM_IMMUNE:
            N(BeamEffect)->data.peachStarBeam->unk_3C = 0;
            N(BeamEffect)->data.peachStarBeam->beamAlpha = 0;
            for (i = 0; i < ARRAY_COUNT(N(SpiritsMoveTime)); i++) {
                N(SpiritsMoveTime)[i] = 15;
            }

            if (!script->functionTemp[FT_IS_PEACH_BEAM]) {
                snd_stop_tracking_env_sound_pos(SOUND_LRAW_USE_STAR_BEAM, FALSE);
            } else {
                snd_stop_tracking_env_sound_pos(SOUND_LRAW_USE_PEACH_BEAM, FALSE);
            }
            script->functionTemp[FT_STATE] = PEACH_STAR_BEAM_SPIRITS_SCATTER;
            break;
        case PEACH_STAR_BEAM_SPIRITS_SCATTER:
            cond = FALSE;
            effectData = N(BeamEffect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits);  i++) {
                if (script->functionTemp[FT_IS_PEACH_BEAM] || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(SpiritsFlyDelay)[i] < 0) {
                        currentPosX = spirit->lockedPos.x;
                        currentPosY = spirit->lockedPos.y;
                        currentPosZ = spirit->lockedPos.z;

                        goalPosX = N(SpiritsScatterPos)[3 * i + 0];
                        goalPosY = N(SpiritsScatterPos)[3 * i + 1];
                        goalPosZ = N(SpiritsScatterPos)[3 * i + 2];

                        spirit->lockedPos.x += goalPosX - currentPosX;
                        spirit->lockedPos.y += goalPosY - currentPosY;
                        spirit->lockedPos.z += goalPosZ - currentPosZ;
                    } else {
                        cond = TRUE;
                        if (N(SpiritsFlyDelay)[i] != 0) {
                            N(SpiritsFlyDelay)[i]--;
                        } else {
                            currentPosX = spirit->lockedPos.x;
                            currentPosY = spirit->lockedPos.y;
                            currentPosZ = spirit->lockedPos.z;

                            spirit->flags |= 2;

                            goalPosX = N(SpiritsScatterPos)[3 * i + 0];
                            goalPosY = N(SpiritsScatterPos)[3 * i + 1];
                            goalPosZ = N(SpiritsScatterPos)[3 * i + 2];
                            dist = dist2D(currentPosX, currentPosZ, goalPosX, goalPosZ);
                            spirit->lockedPos.x += (goalPosX - currentPosX) / N(SpiritsMoveTime)[i];
                            spirit->lockedPos.y += (goalPosY - currentPosY) / N(SpiritsMoveTime)[i];
                            spirit->lockedPos.z += (goalPosZ - currentPosZ) / N(SpiritsMoveTime)[i];
                            if (N(SpiritsMoveTime)[i] == 1) {
                                N(SpiritsFlyDelay)[i] = -1;
                                spirit->lockedPos.x = goalPosX;
                                spirit->lockedPos.y = goalPosY;
                                spirit->lockedPos.z = goalPosZ;
                            } else {
                                spirit->lockedPos.y += dist / 60.0f;
                            }
                            N(SpiritsMoveTime)[i]--;
                        }
                    }
                }
            }

            if (!cond) {
                N(StarBeamStage) = 2;
                N(BeamEffect)->flags |= FX_INSTANCE_FLAG_DISMISS;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(GetStage)) {
    script->varTable[0] = N(StarBeamStage);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(unkStarBeamBgFunc)) {
    if (isInitialCall) {
        script->functionTemp[0] = 230;
    }

    mdl_set_shroud_tint_params(0, 0, 0, script->functionTemp[0]);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] <= 200) {
        mdl_set_shroud_tint_params(0, 0, 0, 200);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
