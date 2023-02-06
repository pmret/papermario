#include "common.h"
#include "script_api/battle.h"

#include "common/StarPower.inc.c"

ApiStatus N(GetStage)(Evt* script, s32 isInitialCall);
ApiStatus N(starBeam2)(Evt* script, s32 isInitialCall);

EvtScript N(802A24F0) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_1002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeUsePower) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, ACTOR_PLAYER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_1002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2C20) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, 0)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, SOUND_2041)
    EVT_CALL(CreateNpc, 100, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, NPC_FLAG_40000, TRUE)
    EVT_CALL(SetNpcPos, 100, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, 100, 0, 5)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 1)
    EVT_SET(LVar0, 0)
    EVT_LOOP(8)
        EVT_ADD(LVar0, 67)
        EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 30, 0, 10)
    EVT_CALL(SetForegroundModelsVisible, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2E2C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, SOUND_2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, SOUND_2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(afterUsePower) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, ACTOR_PLAYER)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_ELSE
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(UnkStarFunc), 3)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A33A8) = {
    EVT_THREAD
        EVT_CALL(PlayEffect, EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_IF_EQ(LVarA, 1)
            EVT_WAIT(5)
            EVT_CALL(PlayEffect, EFFECT_SHIMMER_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlayEffect, EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

s32 N(spiritsFlyDelay)[] = { 35, 0, 5, 10, 15, 20, 25, 30 };
s32 N(spiritsFlyAwayDelay)[] = { 35, 0, 5, 10, 15, 20, 25, 30 };

f32 N(spiritsScatterPos)[] = {
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

static EffectInstance* N(effect);
static char N(padding)[4];
static s32 N(miscParticlesTimeLeft)[8];
static s32 N(spiritsMoveTime)[8];
static s32 N(starBeamStage);

ApiStatus N(ProcessPeachStarBeam)(Evt* script, s32 isInitialCall) {
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

    if (isInitialCall) {
        N(starBeamStage) = 0;
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[0] = PEACH_STAR_BEAM_CREATE_EFFECT;
    }

    if (player->targetListLength == 1) {
        Actor* target = get_actor(player->targetActorID);
        if (target == NULL) {
            return ApiStatus_DONE2;
        }
        get_actor_part(target, player->targetPartIndex);
        targetPosX = target->currentPos.x + target->headOffset.x;
        if (target->flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
            targetPosY = target->currentPos.y + target->headOffset.y - target->size.y;
        } else if (!(target->flags & ACTOR_FLAG_8000)) {
            targetPosY = target->currentPos.y + target->headOffset.y + target->size.y;
        } else {
            targetPosY = target->currentPos.y + target->headOffset.y + target->size.y * 2;
        }
        targetPosZ = target->currentPos.z + target->headOffset.z;
    } else {
        targetPosX = 64.0f;
        targetPosY = 80.0f;
        targetPosZ = 0.0f;
    }

    switch (script->functionTemp[0]) {
        case PEACH_STAR_BEAM_SPIRITS_APPEAR:
        case PEACH_STAR_BEAM_ZOOM_OUT:
        case PEACH_STAR_BEAM_SHRINK_CIRCLE:
        case PEACH_STAR_BEAM_FLY_TO_TARGET:
        case PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS:
        case PEACH_STAR_BEAM_MAKE_BEAM:
        case PEACH_STAR_BEAM_WAIT:
        case PEACH_STAR_BEAM_FADE_OUT_BEAM:
        case PEACH_STAR_BEAM_START_FLY_AWAY:
            effectData = N(effect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(miscParticlesTimeLeft)[i] != 0) {
                        N(miscParticlesTimeLeft)[i]--;
                    } else {
                        N(miscParticlesTimeLeft)[i] = 20;
                        if (N(spiritsFlyDelay)[i] <= 0) {
                            fx_misc_particles(4, spirit->lockedPos.x, spirit->lockedPos.y, spirit->lockedPos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        } else {
                            fx_misc_particles(4, spirit->pos.x, spirit->pos.y, spirit->pos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }
                    }
                }
            }
            break;
        case PEACH_STAR_BEAM_SPIRITS_FLY_AWAY:
            effectData = N(effect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(miscParticlesTimeLeft)[i] != 0) {
                        N(miscParticlesTimeLeft)[i]--;
                    } else {
                        N(miscParticlesTimeLeft)[i] = 20;
                        if (N(spiritsFlyAwayDelay)[i] <= 0) {
                            fx_misc_particles(4, spirit->lockedPos.x, spirit->lockedPos.y, spirit->lockedPos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        } else {
                            fx_misc_particles(4, spirit->pos.x, spirit->pos.y, spirit->pos.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }
                    }
                }
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case PEACH_STAR_BEAM_CREATE_EFFECT:
            currentPosX = player->currentPos.x;
            currentPosY = player->currentPos.y + player->size.y + 30.0f;
            currentPosZ = player->currentPos.z;

            playerState->currentPos.x = currentPosX;
            playerState->currentPos.y = currentPosY + 150.0f;
            playerState->currentPos.z = currentPosZ;

            playerState->goalPos.x = currentPosX;
            playerState->goalPos.y = currentPosY;
            playerState->goalPos.z = currentPosZ;

            if (script->functionTemp[2] == 0) {
                N(effect) = fx_peach_star_beam(0, currentPosX, currentPosY, currentPosZ, 1.0f, 0);
            } else {
                N(effect) = fx_peach_star_beam(1, currentPosX, currentPosY, currentPosZ, 1.0f, 0);
            }
            playerState->distance = 48.0f;
            N(effect)->data.peachStarBeam->unk_3C = 0;
            N(effect)->data.peachStarBeam->circleRadius = playerState->distance;
            N(effect)->data.peachStarBeam->beamAlpha = 0;
            N(effect)->data.peachStarBeam->twinkYOffset = 30.0f;
            N(effect)->data.peachStarBeam->rotationSpeed = 5.0f;
            for (i = 0; i < ARRAY_COUNT(N(miscParticlesTimeLeft)); i++) {
                N(miscParticlesTimeLeft)[i] = rand_int(20);
            }

            script->functionTemp[1] = 40;
            if (script->functionTemp[2] == 0) {
                sfx_play_sound(SOUND_80000068);
            } else {
                sfx_play_sound(SOUND_80000069);
            }
            script->functionTemp[0] = PEACH_STAR_BEAM_SPIRITS_APPEAR;
            break;
        case PEACH_STAR_BEAM_SPIRITS_APPEAR:
            playerState->currentPos.y += (playerState->goalPos.y - playerState->currentPos.y) / 10.0f;
            N(effect)->data.peachStarBeam->circleCenter.x = playerState->currentPos.x;
            N(effect)->data.peachStarBeam->circleCenter.y = playerState->currentPos.y;
            N(effect)->data.peachStarBeam->circleCenter.z = playerState->currentPos.z;
            N(effect)->data.peachStarBeam->unk_3C = 0;
            N(effect)->data.peachStarBeam->circleRadius = playerState->distance;
            N(effect)->data.peachStarBeam->beamAlpha = 0;
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 20;
                script->functionTemp[0] = PEACH_STAR_BEAM_ZOOM_OUT;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_ZOOM_OUT:
            if (script->functionTemp[1] == 0) {
                btl_cam_use_preset(BTL_CAM_PRESET_C);
                btl_cam_move(10);
                script->functionTemp[1] = 15;
                script->functionTemp[0] = PEACH_STAR_BEAM_SHRINK_CIRCLE;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_SHRINK_CIRCLE:
            playerState->distance += (24.0f - playerState->distance) * 0.125f;
            N(effect)->data.peachStarBeam->circleRadius = playerState->distance;
            if (script->functionTemp[1] == 0) {
                playerState->goalPos.x = targetPosX;
                playerState->goalPos.y = targetPosY;
                playerState->goalPos.z = targetPosZ;
                for (i = 0; i < ARRAY_COUNT(N(spiritsMoveTime)); i++) {
                    N(spiritsMoveTime)[i] = 30;
                }

                if (script->functionTemp[2] == 0) {
                    sfx_play_sound(SOUND_248 | SOUND_ID_TRIGGER_CHANGE_SOUND);
                } else {
                    sfx_play_sound(SOUND_249 | SOUND_ID_TRIGGER_CHANGE_SOUND);
                }
                script->functionTemp[0] = PEACH_STAR_BEAM_FLY_TO_TARGET;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_FLY_TO_TARGET:
            cond = FALSE;
            playerState->distance += (48.0f - playerState->distance) * 0.25f;
            N(effect)->data.peachStarBeam->circleRadius = playerState->distance;
            for (i = 0; i < 2; i++) {
                if (i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(spiritsFlyDelay)[i] < 0) {
                        currentPosX = playerState->currentPos.x;
                        currentPosY = playerState->currentPos.y;
                        currentPosZ = playerState->currentPos.z;

                        goalPosX = playerState->goalPos.x;
                        goalPosY = playerState->goalPos.y;
                        goalPosZ = playerState->goalPos.z;

                        playerState->currentPos.x += goalPosX - currentPosX;
                        playerState->currentPos.y += goalPosY - currentPosY;
                        playerState->currentPos.z += goalPosZ - currentPosZ;
                    } else {
                        cond = TRUE;
                        if (N(spiritsFlyDelay)[i] != 0) {
                            N(spiritsFlyDelay)[i]--;
                        } else {
                            currentPosX = playerState->currentPos.x;
                            currentPosY = playerState->currentPos.y;
                            currentPosZ = playerState->currentPos.z;
                            goalPosX = playerState->goalPos.x;
                            goalPosY = playerState->goalPos.y;
                            goalPosZ = playerState->goalPos.z;
                            dist = dist2D(currentPosX, currentPosZ, goalPosX, goalPosZ);
                            playerState->currentPos.x += (goalPosX - currentPosX) / N(spiritsMoveTime)[i];
                            playerState->currentPos.y += (goalPosY - currentPosY) / N(spiritsMoveTime)[i];
                            playerState->currentPos.z += (goalPosZ - currentPosZ) / N(spiritsMoveTime)[i];
                            if (N(spiritsMoveTime)[i] == 1) {
                                N(spiritsFlyDelay)[i] = -1;
                                playerState->currentPos.x = goalPosX;
                                playerState->currentPos.y = goalPosY;
                                playerState->currentPos.z = goalPosZ;
                            } else {
                                playerState->currentPos.y += dist / 60.0f;
                            }
                            N(spiritsMoveTime)[i]--;
                        }
                    }
                }
            }

            N(effect)->data.peachStarBeam->circleCenter.x = playerState->currentPos.x;
            N(effect)->data.peachStarBeam->circleCenter.y = playerState->currentPos.y;
            N(effect)->data.peachStarBeam->circleCenter.z = playerState->currentPos.z;
            N(effect)->data.peachStarBeam->pos.x = playerState->currentPos.x;
            N(effect)->data.peachStarBeam->pos.y = 0.0f;
            N(effect)->data.peachStarBeam->pos.z = playerState->currentPos.z;
            if (!cond) {
                playerState->currentPos.x = playerState->goalPos.x;
                playerState->currentPos.y = playerState->goalPos.y;
                playerState->currentPos.z = playerState->goalPos.z;
                N(effect)->data.peachStarBeam->circleCenter.x = playerState->currentPos.x;
                N(effect)->data.peachStarBeam->circleCenter.y = playerState->currentPos.y;
                N(effect)->data.peachStarBeam->circleCenter.z = playerState->currentPos.z;
                N(effect)->data.peachStarBeam->pos.x = playerState->currentPos.x;
                N(effect)->data.peachStarBeam->pos.y = 0.0f;
                N(effect)->data.peachStarBeam->pos.z = playerState->currentPos.z;
                effectData = N(effect)->data.peachStarBeam;
                for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                    if (script->functionTemp[2] != 0 || i != 0) {
                        spirit = &effectData->spirits[i];
                        N(spiritsFlyDelay)[i] = 1;
                        spirit->flags &= ~2;
                    }
                }

                btl_cam_use_preset(BTL_CAM_PRESET_D);
                btl_cam_move(30);
                script->functionTemp[1] = 15;
                script->functionTemp[0] = PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS;
            }
            break;
        case PEACH_STAR_BEAM_MAKE_ADDITIONAL_EFFECTS:
            if (script->functionTemp[1] == 0) {
                playerState->moveTime = 0;
                N(effect)->data.peachStarBeam->unk_3C = 0;
                N(effect)->data.peachStarBeam->beamAlpha = 0;
                if (script->functionTemp[2] != 0) {
                    N(effect)->data.peachStarBeam->primR = 240;
                    N(effect)->data.peachStarBeam->primG = 80;
                    N(effect)->data.peachStarBeam->primB = 200;
                    N(effect)->data.peachStarBeam->envR = 240;
                    N(effect)->data.peachStarBeam->envG = 240;
                    N(effect)->data.peachStarBeam->envB = 240;
                }
                newScript = start_script(&N(802A33A8), EVT_PRIORITY_A, 0);

                newScript->varTable[0] = playerState->currentPos.x;
                newScript->varTable[1] = playerState->currentPos.y * 0.5f;
                newScript->varTable[2] = playerState->currentPos.z;
                newScript->varTable[10] = script->functionTemp[2];

                do {} while (0); // required to match

                sfx_play_sound(SOUND_24A);
                script->functionTemp[1] = 45;
                script->functionTemp[0] = PEACH_STAR_BEAM_MAKE_BEAM;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_MAKE_BEAM:
            playerState->moveTime += 30;
            if (playerState->moveTime > 255) {
                playerState->moveTime = 255;
            }
            N(effect)->data.peachStarBeam->unk_3C = playerState->moveTime;
            N(effect)->data.peachStarBeam->beamAlpha = playerState->moveTime;
            if (script->functionTemp[1] == 0) {
                N(starBeamStage) = 1;
                if (script->functionTemp[2] == 0 && player->targetListLength == 1) {
                    if (get_actor_part(get_actor(player->targetActorID), player->targetPartIndex)->eventFlags & ACTOR_EVENT_FLAG_80000) {
                        script->functionTemp[0] = PEACH_STAR_BEAM_IMMUNE;
                    } else {
                        script->functionTemp[1] = 15;
                        script->functionTemp[0] = PEACH_STAR_BEAM_WAIT;
                    }
                } else {
                    script->functionTemp[1] = 15;
                    script->functionTemp[0] = PEACH_STAR_BEAM_WAIT;
                }
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_WAIT:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 10;
                script->functionTemp[0] = PEACH_STAR_BEAM_FADE_OUT_BEAM;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_FADE_OUT_BEAM:
            playerState->moveTime -= 30;
            if (playerState->moveTime < 0) {
                playerState->moveTime = 0;
            }
            N(effect)->data.peachStarBeam->unk_3C = playerState->moveTime;
            N(effect)->data.peachStarBeam->beamAlpha = playerState->moveTime;
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 10;
                script->functionTemp[0] = PEACH_STAR_BEAM_START_FLY_AWAY;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case PEACH_STAR_BEAM_START_FLY_AWAY:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            playerState->goalPos.x = targetPosX;
            playerState->goalPos.y = targetPosY + 170.0f;
            playerState->goalPos.z = targetPosZ;
            script->functionTemp[1] = 20;
            script->functionTemp[0] = PEACH_STAR_BEAM_SPIRITS_FLY_AWAY;
            break;
        case PEACH_STAR_BEAM_SPIRITS_FLY_AWAY:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                if (script->functionTemp[1] == 0) {
                    if (script->functionTemp[2] == 0) {
                        snd_stop_tracking_env_sound_pos(SOUND_248, TRUE);
                        sfx_play_sound(SOUND_248 | SOUND_ID_TRIGGER_CHANGE_SOUND);
                    } else {
                        snd_stop_tracking_env_sound_pos(SOUND_249, TRUE);
                        sfx_play_sound(SOUND_249 | SOUND_ID_TRIGGER_CHANGE_SOUND);
                    }
                }
            }
            cond = FALSE;
            effectData = N(effect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(spiritsFlyAwayDelay)[i] >= 0) {
                        cond = TRUE;
                        if (N(spiritsFlyAwayDelay)[i] != 0) {
                            N(spiritsFlyAwayDelay)[i]--;
                        } else {
                            spirit->flags |= 2;
                            currentPosY = spirit->lockedPos.y;
                            spirit->lockedPos.y += (playerState->goalPos.y - currentPosY) / 10.0f;
                            if (fabsf(spirit->lockedPos.y - playerState->goalPos.y) < 1.0) {
                                N(spiritsFlyAwayDelay)[i] = -1;
                            }
                        }
                    }
                }
            }

            if (!cond) {
                N(starBeamStage) = 2;
                N(effect)->flags |= EFFECT_INSTANCE_FLAG_10;
                return ApiStatus_DONE2;
            }
            break;
        case PEACH_STAR_BEAM_IMMUNE:
            N(effect)->data.peachStarBeam->unk_3C = 0;
            N(effect)->data.peachStarBeam->beamAlpha = 0;
            for (i = 0; i < ARRAY_COUNT(N(spiritsMoveTime)); i++) {
                N(spiritsMoveTime)[i] = 15;
            }

            if (script->functionTemp[2] == 0) {
                snd_stop_tracking_env_sound_pos(SOUND_248, FALSE);
            } else {
                snd_stop_tracking_env_sound_pos(SOUND_249, FALSE);
            }
            script->functionTemp[0] = PEACH_STAR_BEAM_SPIRITS_SCATTER;
            break;
        case PEACH_STAR_BEAM_SPIRITS_SCATTER:
            cond = FALSE;
            effectData = N(effect)->data.peachStarBeam;
            for (i = 0; i < ARRAY_COUNT(effectData->spirits);  i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    spirit = &effectData->spirits[i];
                    if (N(spiritsFlyDelay)[i] < 0) {
                        currentPosX = spirit->lockedPos.x;
                        currentPosY = spirit->lockedPos.y;
                        currentPosZ = spirit->lockedPos.z;

                        goalPosX = N(spiritsScatterPos)[3 * i + 0];
                        goalPosY = N(spiritsScatterPos)[3 * i + 1];
                        goalPosZ = N(spiritsScatterPos)[3 * i + 2];

                        spirit->lockedPos.x += goalPosX - currentPosX;
                        spirit->lockedPos.y += goalPosY - currentPosY;
                        spirit->lockedPos.z += goalPosZ - currentPosZ;
                    } else {
                        cond = TRUE;
                        if (N(spiritsFlyDelay)[i] != 0) {
                            N(spiritsFlyDelay)[i]--;
                        } else {
                            currentPosX = spirit->lockedPos.x;
                            currentPosY = spirit->lockedPos.y;
                            currentPosZ = spirit->lockedPos.z;

                            spirit->flags |= 2;

                            goalPosX = N(spiritsScatterPos)[3 * i + 0];
                            goalPosY = N(spiritsScatterPos)[3 * i + 1];
                            goalPosZ = N(spiritsScatterPos)[3 * i + 2];
                            dist = dist2D(currentPosX, currentPosZ, goalPosX, goalPosZ);
                            spirit->lockedPos.x += (goalPosX - currentPosX) / N(spiritsMoveTime)[i];
                            spirit->lockedPos.y += (goalPosY - currentPosY) / N(spiritsMoveTime)[i];
                            spirit->lockedPos.z += (goalPosZ - currentPosZ) / N(spiritsMoveTime)[i];
                            if (N(spiritsMoveTime)[i] == 1) {
                                N(spiritsFlyDelay)[i] = -1;
                                spirit->lockedPos.x = goalPosX;
                                spirit->lockedPos.y = goalPosY;
                                spirit->lockedPos.z = goalPosZ;
                            } else {
                                spirit->lockedPos.y += dist / 60.0f;
                            }
                            N(spiritsMoveTime)[i]--;
                        }
                    }
                }
            }

            if (!cond) {
                N(starBeamStage) = 2;
                N(effect)->flags |= EFFECT_INSTANCE_FLAG_10;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus N(GetStage)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = N(starBeamStage);
    return ApiStatus_DONE2;
}

ApiStatus N(unkStarBeamBgFunc)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 230;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] <= 200) {
        set_background_color_blend(0, 0, 0, 200);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
