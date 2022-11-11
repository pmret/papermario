#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"

#define NAMESPACE battle_star_star_beam

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_7974D8(Evt* script, s32 isInitialCall);
ApiStatus func_802A2468_798428(Evt* script, s32 isInitialCall);
ApiStatus func_802A247C_79843C(Evt* script, s32 isInitialCall);

EvtScript N(802A24F0) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
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
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
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

EvtScript N(802A2888) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
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
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
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
    EVT_CALL(PlaySound, 0x2041)
    EVT_CALL(CreateNpc, 100, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, ((NPC_FLAG_40000)), TRUE)
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
        EVT_CALL(PlaySound, 0x2047)
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
        EVT_CALL(PlaySound, 0x2045)
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

EvtScript N(802A327C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
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
        EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_IF_EQ(LVarA, 1)
            EVT_WAIT(5)
            EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlayEffect, 0x52, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

s32 D_802A3514_7994D4[] = { 35, 0, 5, 10, 15, 20, 25, 30 };
s32 D_802A3534_7994F4[] = { 35, 0, 5, 10, 15, 20, 25, 30 };

Vec3f D_802A3554_799514[] = {
    { 89.0f, 180.0f, 0.0f },
    { -36.0f, 180.0f, 0.0f },
    { 204.0f, 180.0f, 0.0f },
    { 30.0f, 97.0f, 477.0f },
    { 230.0f, 81.0f, 0.0f },
    { 129.0f, 180.0f, 0.0f },
    { -60.0f, 180.0f, 0.0f },
    { -234.0f, 39.0f, 0.0f },
};

EvtScript N(usePower) = {
    EVT_EXEC_WAIT(N(802A2888))
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(func_802A1518_7974D8, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(func_802A2468_798428)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemDamageEnemy, LVar0, 1077936128, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(func_802A2468_798428)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(func_802A247C_79843C)
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(802A327C))
    EVT_RETURN
    EVT_END
};

BSS EffectInstance* D_802A37F0;
BSS char D_802A37F4[4];
BSS s32 D_802A37F8[8];
BSS s32 D_802A3818[8];
BSS s32 D_802A3834[8];

// flots
#ifdef NON_MATCHING
ApiStatus func_802A1518_7974D8(Evt* script, s32 isInitialCall) {
    PeachStarBeamFXData* sp28;
    PeachStarBeamInner* part;
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* playerState = &player->state;
    s32 i;

    f32 playerX, playerY, playerZ;
    f32 playerGoalX, playerGoalY, playerGoalZ;
    f32 goalX, goalY, goalZ;
    f32 tx, ty, tz;
    s32 cond;
    Actor* target;
    Evt* script;
    f32 dist;
    f32 dist2;

    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f30;
    s32 var_a0;

    if (isInitialCall) {
        D_802A3838 = 0;
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
    }

    if (player->targetListLength == 1) {
        target = get_actor(player->targetActorID);
        if (target == NULL) {
            return ApiStatus_DONE2;
        }

        get_actor_part(target, player->targetPartIndex);
        goalX = target->currentPos.x + target->headOffset.x;
        if (target->flags & 0x800) {
            goalY = (target->currentPos.y + target->headOffset.y) - target->size.y;
        } else if (!(target->flags & 0x8000)) {
            goalY = target->size.y + (target->currentPos.y + target->headOffset.y);
        } else {
            goalY = target->currentPos.y + target->headOffset.y + (target->size.y * 2);
        }
        goalZ = target->currentPos.z + target->headOffset.z;
    } else {
        goalX = 64.0f;
        goalY = 80.0f;
        goalZ = 0.0f;
    }

    switch (script->functionTemp[0]) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            sp28 = D_802A37F0->data.peachStarBeam;

            for (i = 0; i < ARRAY_COUNT(sp28->parts); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    part = &sp28->parts[i];

                    if (D_802A37F8[i] != 0) {
                        D_802A37F8[i]--;
                    } else {
                        D_802A37F8[i] = 20;

                        if (D_802A3514_7994D4[i] <= 0) {
                                fx_misc_particles(4, part->unk_10.x, part->unk_10.y, part->unk_10.z, 20.0f, 20.0f, 1.0f, 10, 20);
                            } else {
                                fx_misc_particles(4, part->unk_04.x, part->unk_04.y, part->unk_04.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }
                    }
                }
            }
            break;
        case 10:
            sp28 = D_802A37F0->data.peachStarBeam;

            for (i = 0; i < ARRAY_COUNT(sp28->parts); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    part = &sp28->parts[i];

                    if (D_802A37F8[i] != 0) {
                        D_802A37F8[i]--;
                    } else {
                        D_802A37F8[i] = 20;

                        if (D_802A3534_7994F4[i] <= 0) {
                            fx_misc_particles(4, part->unk_10.x, part->unk_10.y, part->unk_10.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        } else {
                            fx_misc_particles(4, part->unk_04.x, part->unk_04.y, part->unk_04.z, 20.0f, 20.0f, 1.0f, 10, 20);
                        }

                    }
                }
            }
            break;
    }

    switch (script->functionTemp[0]) {
        case 0:
            temp_f20 = player->currentPos.x;
            temp_f30 = player->currentPos.z;
            playerState->currentPos.x = temp_f20;
            temp_f22 = player->currentPos.y + player->size.y + 30.0f;
            playerState->currentPos.z = temp_f30;
            playerState->goalPos.x = temp_f20;
            playerState->goalPos.z = temp_f30;
            playerState->goalPos.y = temp_f22;
            playerState->currentPos.y = playerState->goalPos.y + 150.0f;

            if (script->functionTemp[2] == 0) {
                D_802A37F0 = fx_peach_star_beam(0, temp_f20, temp_f22, temp_f30, 1.0f, 0);
            } else {
                D_802A37F0 = fx_peach_star_beam(1, temp_f20, temp_f22, temp_f30, 1.0f, 0);
            }

            playerState->distance = 48.0f;
            D_802A37F0->data.peachStarBeam->unk_3C = 0;
            D_802A37F0->data.peachStarBeam->unk_48 = playerState->distance;
            D_802A37F0->data.peachStarBeam->alpha = 0;
            D_802A37F0->data.peachStarBeam->unk_58 = 30.0f;
            D_802A37F0->data.peachStarBeam->unk_40 = 5.0f;

            for (i = 0; i < ARRAY_COUNT(D_802A37F8); i++) {
                D_802A37F8[i] = rand_int(20);
            }

            script->functionTemp[1] = 40;
            if (script->functionTemp[2] == 0) {
                sfx_play_sound(0x80000068);
            } else {
                sfx_play_sound(0x80000069);
            }
            script->functionTemp[0] = 1;
            break;
        case 1:
            playerState->currentPos.y += (playerState->goalPos.y - playerState->currentPos.y) / 10.0f;
            D_802A37F0->data.peachStarBeam->unk_4C = playerState->currentPos.x;
            D_802A37F0->data.peachStarBeam->unk_50 = playerState->currentPos.y;
            D_802A37F0->data.peachStarBeam->unk_54 = playerState->currentPos.z;
            D_802A37F0->data.peachStarBeam->unk_3C = 0;
            D_802A37F0->data.peachStarBeam->unk_48 = playerState->distance;
            D_802A37F0->data.peachStarBeam->alpha = 0;
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 20;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 2:
            if (script->functionTemp[1] == 0) {
                btl_cam_use_preset(2);
                btl_cam_move(10);
                script->functionTemp[1] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 3:
            playerState->distance += (24.0f - playerState->distance) * 0.125f;
            D_802A37F0->data.peachStarBeam->unk_48 = playerState->distance;
            if (script->functionTemp[1] == 0) {
                playerState->goalPos.x = goalX;
                playerState->goalPos.y = goalY;
                playerState->goalPos.z = goalZ;

                for (i = 0; i < ARRAY_COUNT(D_802A3834); i++) {
                    D_802A3834[i] = 30;
                }

                if (script->functionTemp[2] == 0) {
                    sfx_play_sound(0x648);
                } else {
                    sfx_play_sound(0x649);
                }
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 4:
            cond = FALSE;
            playerState->distance += (48.0f - playerState->distance) * 0.25f;
            D_802A37F0->data.peachStarBeam->unk_48 = playerState->distance;

            for (i = 0; i < 2; i++) {
                if (i != 0) {
                    if (D_802A3514_7994D4[i] < 0) {
                        playerState->currentPos.x += playerState->goalPos.x - playerState->currentPos.x;
                        playerState->currentPos.y += playerState->goalPos.y - playerState->currentPos.y;
                        playerState->currentPos.z += playerState->goalPos.z - playerState->currentPos.z;
                    } else {
                        cond = TRUE;
                        if (D_802A3514_7994D4[i] != 0) {
                            D_802A3514_7994D4[i]--;
                        } else {
                            playerX = playerState->currentPos.x;
                            playerY = playerState->currentPos.y;
                            playerZ = playerState->currentPos.z;
                            playerGoalX = playerState->goalPos.x;
                            playerGoalY = playerState->goalPos.y;
                            playerGoalZ = playerState->goalPos.z;
                            dist = dist2D(playerX, playerZ, playerGoalX, playerGoalZ);
                            playerState->currentPos.x += (playerGoalX - playerX) / D_802A3818[i];
                            playerState->currentPos.y += (playerGoalY - playerY) / D_802A3818[i];
                            playerState->currentPos.z += (playerGoalZ - playerZ) / D_802A3818[i];
                            if (D_802A3818[i] == 1) {
                                D_802A3514_7994D4[i] = -1;
                                playerState->currentPos.x = playerGoalX;
                                playerState->currentPos.y = playerGoalY;
                                playerState->currentPos.z = playerGoalZ;
                            } else {
                                playerState->currentPos.y += dist / 60.0f;
                            }
                            D_802A3818[i]--;
                        }
                    }
                }
            }

            D_802A37F0->data.peachStarBeam->unk_4C = playerState->currentPos.x;
            D_802A37F0->data.peachStarBeam->unk_50 = playerState->currentPos.y;
            D_802A37F0->data.peachStarBeam->unk_54 = playerState->currentPos.z;
            D_802A37F0->data.peachStarBeam->pos.x = playerState->currentPos.x;
            D_802A37F0->data.peachStarBeam->pos.y = 0.0f;
            D_802A37F0->data.peachStarBeam->pos.z = playerState->currentPos.z;

            if (!cond) {
                playerState->currentPos.x = playerState->goalPos.x;
                playerState->currentPos.y = playerState->goalPos.y;
                playerState->currentPos.z = playerState->goalPos.z;
                D_802A37F0->data.peachStarBeam->unk_4C = playerState->currentPos.x;
                D_802A37F0->data.peachStarBeam->unk_50 = playerState->currentPos.y;
                D_802A37F0->data.peachStarBeam->unk_54 = playerState->currentPos.z;
                D_802A37F0->data.peachStarBeam->pos.x = playerState->currentPos.x;
                D_802A37F0->data.peachStarBeam->pos.y = 0.0f;
                D_802A37F0->data.peachStarBeam->pos.z = playerState->currentPos.z;

                sp28 = D_802A37F0->data.peachStarBeam;
                for (i = 0; i < ARRAY_COUNT(sp28->parts); i++) {
                    if ((script->functionTemp[2] != 0) || (i != 0)) {
                        part = &sp28->parts[i];
                        D_802A3514_7994D4[i] = 1;
                        part->flags &= ~2;
                    }
                }
                btl_cam_use_preset(3);
                btl_cam_move(30);
                script->functionTemp[1] = 15;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[1] == 0) {
                playerState->moveTime = 0;
                D_802A37F0->data.peachStarBeam->unk_3C = 0;
                D_802A37F0->data.peachStarBeam->alpha = 0;
                if (script->functionTemp[2] != 0) {
                    D_802A37F0->data.peachStarBeam->primR = 240;
                    D_802A37F0->data.peachStarBeam->primG = 80;
                    D_802A37F0->data.peachStarBeam->primB = 200;
                    D_802A37F0->data.peachStarBeam->envR = 240;
                    D_802A37F0->data.peachStarBeam->envG = 240;
                    D_802A37F0->data.peachStarBeam->envB = 240;
                }
                script = start_script(battle_star_star_beam_802A33A8, 0xA, 0);
                script->varTable[0] = playerState->currentPos.x;
                script->varTable[1] = playerState->currentPos.y * 0.5f;
                script->varTable[2] = playerState->currentPos.z;
                script->varTable[10] = script->functionTemp[2];
                sfx_play_sound(0x24A);
                script->functionTemp[1] = 45;
                script->functionTemp[0] = 6;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 6:
            playerState->moveTime += 30;
            if (playerState->moveTime > 255) {
                playerState->moveTime = 255;
            }
            D_802A37F0->data.peachStarBeam->unk_3C = playerState->moveTime;
            D_802A37F0->data.peachStarBeam->alpha = playerState->moveTime;
            if (script->functionTemp[1] == 0) {
                D_802A3838 = 1;
                if (script->functionTemp[2] == 0 && player->targetListLength == 1) {
                    if (get_actor_part(get_actor(player->targetActorID), player->targetPartIndex)->eventFlags & 0x80000) {
                        script->functionTemp[0] = 20;
                    } else {
                        script->functionTemp[1] = 15;
                        script->functionTemp[0] = 7;
                    }
                } else {
                    script->functionTemp[1] = 15;
                    script->functionTemp[0] = 7;
                }
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 7:
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 10;
                script->functionTemp[0] = 8;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 8:
            playerState->moveTime -= 30;
            if (playerState->moveTime < 0) {
                playerState->moveTime = 0;
            }
            D_802A37F0->data.peachStarBeam->unk_3C = playerState->moveTime;
            D_802A37F0->data.peachStarBeam->alpha = playerState->moveTime;
            if (script->functionTemp[1] == 0) {
                script->functionTemp[1] = 10;
                script->functionTemp[0] = 9;
            } else {
                script->functionTemp[1]--;
            }
            break;
        case 9:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                break;
            }
            playerState->goalPos.x = goalX;
            playerState->goalPos.y = goalY + 170.0f;
            playerState->goalPos.z = goalZ;
            script->functionTemp[1] = 20;
            script->functionTemp[0] = 10;
            break;
        case 10:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
                if (script->functionTemp[1] == 0) {
                    if (script->functionTemp[2] == 0) {
                        func_80149A6C(0x248, 1);
                        sfx_play_sound(0x648);
                    } else {
                        func_80149A6C(0x249, 1);
                        sfx_play_sound(0x649);
                    }
                }
            }

            cond = FALSE;
            for (i = 0; i < ARRAY_COUNT(sp28->parts); i++) {
                if (script->functionTemp[2] != 0 || i != 0) {
                    part = &sp28->parts[i];

                    if (D_802A3534_7994F4[i] >= 0) {
                        cond = TRUE;
                        if (D_802A3534_7994F4[i] != 0) {
                            D_802A3534_7994F4[i]--;
                        } else {
                            part->flags |= 2;
                            part->unk_10.y += (playerState->goalPos.y - part->unk_10.y) / 10.0f;
                            if (fabsf(part->unk_10.y - playerState->goalPos.y) < 1.0) {
                                D_802A3534_7994F4[i] = -1;
                            }
                        }
                    }
                }
            }

            if (!cond) {
                D_802A3838 = 2;
                D_802A37F0->flags |= 0x10;
                return ApiStatus_DONE2;
            }
            break;
        case 20:
            D_802A37F0->data.peachStarBeam->unk_3C = 0;
            D_802A37F0->data.peachStarBeam->alpha = 0;

            for (i = 0; i < ARRAY_COUNT(D_802A3834); i++) {
                D_802A3834[i] = 15;
            }

            if (script->functionTemp[2] == 0) {
                func_80149A6C(0x248, 0);
            } else {
                func_80149A6C(0x249, 0);
            }
            script->functionTemp[0] = 0x15;
            break;
        case 21:
            cond = FALSE;
            sp28 = D_802A37F0->data.peachStarBeam;

            for (i = 0; i < ARRAY_COUNT(sp28->parts); i++) {
                if ((script->functionTemp[2] != 0) || (i != 0)) {
                    part = &sp28->parts[i];

                    if (D_802A3514_7994D4[i] < 0) {
                        part->unk_10.x += D_802A3554_799514[i].x - part->unk_10.x;
                        part->unk_10.y += D_802A3554_799514[i].y - part->unk_10.y;
                        part->unk_10.z += D_802A3554_799514[i].z - part->unk_10.z;
                    } else {
                        cond = TRUE;
                        if (D_802A3514_7994D4[i] != 0) {
                            D_802A3514_7994D4[i]--;
                        } else {
                            part->flags |= 2;
                            tx = D_802A3554_799514[i].x;
                            ty = D_802A3554_799514[i].y;
                            tz = D_802A3554_799514[i].z;
                            dist2 = dist2D(part->unk_10.x, part->unk_10.z, tx, tz);
                            part->unk_10.x += (tx - part->unk_10.x) / D_802A3818[i];
                            part->unk_10.y += (ty - part->unk_10.y) / D_802A3818[i];
                            part->unk_10.z += (tz - part->unk_10.z) / D_802A3818[i];
                            if (D_802A3818[i] == 1) {
                                D_802A3514_7994D4[i] = -1;
                                part->unk_10.x = tx;
                                part->unk_10.y = ty;
                                part->unk_10.z = tz;
                            } else {
                                part->unk_10.y = (part->unk_10.y + (dist2 / 60.0f));
                            }
                            D_802A3818[i]--;
                        }
                    }
                }
            }

            if (!cond) {
                D_802A3838 = 2;
                D_802A37F0->flags |= 0x10;
                return ApiStatus_DONE2;
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "battle/star/star_beam/796FC0", func_802A1518_7974D8);
#endif

ApiStatus func_802A2468_798428(Evt* script, s32 isInitialCall) {
    script->varTable[0] = D_802A3838;
    return ApiStatus_DONE2;
}

ApiStatus func_802A247C_79843C(Evt* script, s32 isInitialCall) {
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
