#include "common.h"
#include "sprite/npc/WorldGoombario.h"
#include "goombario.h"
#include "../src/world/partners.h"
#include "message_ids.h"
#include "entity.h"

extern SpeechBubbleData* SpeechBubblePtr;

BSS s32 TattleHadSpeechPrompt;
BSS s32 TattleHadInteractPrompt;
BSS Npc* TattleInteractNpc;
BSS s32 D_802BDF3C; // unused (padding?)
BSS TweesterPhysics GoombarioTweesterPhysics;
BSS s32 D_802BDF5C; // unused (padding?)
BSS s32 GoombarioTattleInteractionID;
BSS s32 WorldGoombarioTattleActive;

s32 EntityTattles[] = {
    ENTITY_TYPE_HAMMER1_BLOCK,        MSG_EntityTattle_HammerBlock1_CanBreak,
    ENTITY_TYPE_HAMMER1_BLOCK_TINY,   MSG_EntityTattle_HammerBlock1_CanBreak,
    ENTITY_TYPE_HAMMER2_BLOCK,        MSG_EntityTattle_HammerBlock2_CantBreak,
    ENTITY_TYPE_HAMMER2_BLOCK_TINY,   MSG_EntityTattle_HammerBlock2_CantBreak,
    ENTITY_TYPE_HAMMER3_BLOCK,        MSG_EntityTattle_HammerBlock3_CantBreak,
    ENTITY_TYPE_HAMMER3_BLOCK_TINY,   MSG_EntityTattle_HammerBlock3_CantBreak,
    ENTITY_TYPE_BRICK_BLOCK,          MSG_EntityTattle_BrickBlock,
    ENTITY_TYPE_MULTI_COIN_BRICK,     MSG_EntityTattle_BrickBlock,
    ENTITY_TYPE_YELLOW_BLOCK,         MSG_EntityTattle_ItemBlock,
    ENTITY_TYPE_SINGLE_TRIGGER_BLOCK, MSG_EntityTattle_ItemBlock,
    ENTITY_TYPE_MULTI_TRIGGER_BLOCK,  MSG_EntityTattle_InertBlock,
    ENTITY_TYPE_PUSH_BLOCK,           MSG_EntityTattle_PushBlock,
    ENTITY_TYPE_RED_BLOCK,            MSG_EntityTattle_BadgeBlock,
    ENTITY_TYPE_SIMPLE_SPRING,        MSG_EntityTattle_Spring,
    ENTITY_TYPE_SCRIPT_SPRING,        MSG_EntityTattle_Spring,
    ENTITY_TYPE_BLUE_SWITCH,          MSG_EntityTattle_Switch,
    ENTITY_TYPE_RED_SWITCH,           MSG_EntityTattle_Switch,
    ENTITY_TYPE_HUGE_BLUE_SWITCH,     MSG_EntityTattle_BigSwitch_SpinJump,
    ENTITY_TYPE_GREEN_STOMP_SWITCH,   MSG_EntityTattle_FloorSwitch_SpinJump,
    ENTITY_TYPE_BLUE_WARP_PIPE,       MSG_EntityTattle_Pipe,
    ENTITY_TYPE_PADLOCK,              MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_RED_FRAME,    MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_RED_FACE,     MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_BLUE_FACE,    MSG_EntityTattle_PadLock,
    ENTITY_TYPE_SIGNPOST,             MSG_EntityTattle_SignPost,
    ENTITY_TYPE_RED_ARROW_SIGNS,      MSG_EntityTattle_ArrowSign,
    ENTITY_TYPE_BOMBABLE_ROCK,        MSG_EntityTattle_BombableRock,
    ENTITY_TYPE_CHEST,                MSG_EntityTattle_Chest,
    ENTITY_TYPE_WOODEN_CRATE,         MSG_EntityTattle_WoodenCrate_CantBreak,
    ENTITY_TYPE_BOARDED_FLOOR,        MSG_EntityTattle_BoardedFloor_CantBreak,
    ENTITY_TYPE_STAR_BOX_LAUCHER,     MSG_EntityTattle_JackInTheBox_SpinJump,
    ENTITY_TYPE_BELLBELL_PLANT,       MSG_EntityTattle_BellbellPlant,
    ENTITY_TYPE_TRUMPET_PLANT,        MSG_EntityTattle_TrumpetPlant,
    ENTITY_TYPE_CYMBAL_PLANT,         MSG_EntityTattle_CymbalBush,
    ENTITY_TYPE_MUNCHLESIA,           MSG_EntityTattle_Munchlesia,
    ENTITY_TYPE_SPINNING_FLOWER,      MSG_EntityTattle_SpinningFlower,
    ENTITY_TYPE_PINK_FLOWER,          MSG_EntityTattle_BulbBush,
    -1
};

s32 world_goombario_get_trigger_tattle(s32 arg0) {
    s32 i;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL
            && trigger->flags.flags & TRIGGER_WALL_PRESS_A
            && trigger->location.colliderID == arg0
        ) {
            return trigger->tattleMsg;
        }
    }
    return 0;
}

void world_goombario_init(Npc* goombario) {
    goombario->collisionHeight = 24;
    goombario->collisionRadius = 20;
}

API_CALLABLE(WorldGoombarioTakeOut) {
    Npc* goombario = script->owner2.npc;
    GoombarioTattleInteractionID = -1;

    if (isInitialCall) {
        partner_init_get_out(goombario);
    }

    if (partner_get_out(goombario)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_GoombarioTakeOut = {
    EVT_CALL(WorldGoombarioTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* GoombarioTweesterPhysicsPtr = &GoombarioTweesterPhysics;

API_CALLABLE(WorldGoombarioUpdate) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(GoombarioTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_GOOMBARIO]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (GoombarioTweesterPhysicsPtr->state) {
        case 0:
            GoombarioTweesterPhysicsPtr->state = 1;
            GoombarioTweesterPhysicsPtr->prevFlags = npc->flags;
            GoombarioTweesterPhysicsPtr->radius = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            GoombarioTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            GoombarioTweesterPhysicsPtr->angularVelocity = 6.0f;
            GoombarioTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            GoombarioTweesterPhysicsPtr->countdown = 120;
            npc->flags |= NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
            npc->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(GoombarioTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);

            npc->pos.x = entity->position.x + (sinAngle * GoombarioTweesterPhysicsPtr->radius);
            npc->pos.z = entity->position.z - (cosAngle * GoombarioTweesterPhysicsPtr->radius);
            GoombarioTweesterPhysicsPtr->angle = clamp_angle(GoombarioTweesterPhysicsPtr->angle - GoombarioTweesterPhysicsPtr->angularVelocity);

            if (GoombarioTweesterPhysicsPtr->radius > 20.0f) {
                GoombarioTweesterPhysicsPtr->radius--;
            } else if (GoombarioTweesterPhysicsPtr->radius < 19.0f) {
                GoombarioTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(GoombarioTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            GoombarioTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (GoombarioTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                GoombarioTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            npc->pos.y += liftoffVelocity;

            npc->renderYaw = clamp_angle(360.0f - GoombarioTweesterPhysicsPtr->angle);
            GoombarioTweesterPhysicsPtr->angularVelocity += 0.8;

            if (GoombarioTweesterPhysicsPtr->angularVelocity > 40.0f) {
                GoombarioTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--GoombarioTweesterPhysicsPtr->countdown == 0) {
                GoombarioTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            npc->flags = GoombarioTweesterPhysicsPtr->prevFlags;
            GoombarioTweesterPhysicsPtr->countdown = 30;
            GoombarioTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--GoombarioTweesterPhysicsPtr->countdown == 0) {
                GoombarioTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return 0;
}

EvtScript EVS_GoombarioUpdate = {
    EVT_CALL(WorldGoombarioUpdate)
    EVT_RETURN
    EVT_END
};

void goombario_try_cancel_tweester(Npc* goombario) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        goombario->flags = GoombarioTweesterPhysicsPtr->prevFlags;
        GoombarioTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking (goombario);
    }
}

s32 world_goombario_can_pause(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;
    s32 new_var;

    if (goombarioActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        return FALSE;
    }

    if ((goombario->flags & (NPC_FLAG_GROUNDED | NPC_FLAG_JUMPING)) != NPC_FLAG_GROUNDED) {
        return new_var = 0;
        do { } while (new_var); // why though
    }

    return TRUE;
}

API_CALLABLE(WorldGoombarioSelectTattleMsg) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* goombario = script->owner2.npc;
    s32 msgID;
    s32 temp; // TODO required to match (this temp needs to be used in two places for different things)
    s32 npcMsgID;
    s32 v0;
    s32 i;

    #define USE_STATE functionTemp[0]
    #define VAR_MSG   varTable[0]
    #define VAR_SKIP  varTable[1]
    enum {
        USE_TATTLE_INIT         = 40,
        USE_TATTLE_DELAY        = 41,
        USE_TATTLE_FACE_PLAYER  = 0,
        USE_TATTLE_CHOOSE       = 1,
        USE_TATTLE_FORCE_MAP    = 10,
        USE_TATTLE_FORCE_NPC    = 20,
    };

    if (isInitialCall) {
        goombario_try_cancel_tweester(goombario);
        WorldGoombarioTattleActive = FALSE;
        TattleHadSpeechPrompt = FALSE;
        TattleHadInteractPrompt = FALSE;
        if (playerStatus->animFlags & PA_FLAG_SPEECH_PROMPT_AVAILABLE) {
            TattleHadSpeechPrompt = TRUE;
            TattleInteractNpc = SpeechBubblePtr->encounteredNPC;
        }
        if (playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) {
            TattleHadInteractPrompt = TRUE;
        }
        script->USE_STATE = USE_TATTLE_INIT;
    }

    switch (script->USE_STATE) {
        case USE_TATTLE_INIT:
            if (!(goombario->flags & NPC_FLAG_GROUNDED) || playerStatus->inputDisabledCount != 0) {
                script->VAR_MSG = -1;
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] = 3;
            disable_player_input();
            WorldGoombarioTattleActive = TRUE;
            script->functionTemp[2] = playerStatus->inputDisabledCount;
            script->USE_STATE++;
            break;
        case USE_TATTLE_DELAY:
            if (script->functionTemp[1] != 0) {
                script->functionTemp[1]--;
            } else {
                if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                    script->VAR_MSG = -1;
                    enable_player_input();
                    WorldGoombarioTattleActive = FALSE;
                    return ApiStatus_DONE2;
                }
                script->USE_STATE = USE_TATTLE_FACE_PLAYER;
            }
            break;
        case USE_TATTLE_FACE_PLAYER:
            set_time_freeze_mode(1);
            playerStatus->flags &= ~PS_FLAG_HAS_CONVERSATION_NPC;
            goombario->currentAnim = ANIM_WorldGoombario_Idle;
            goombario->yaw = clamp_angle(gCameras[CAM_DEFAULT].currentYaw + playerStatus->spriteFacingAngle - 90.0f);
            gPartnerActionStatus.partnerActionState = PARTNER_ACTION_USE;
            close_status_menu();
            if (TattleHadSpeechPrompt) {
                script->VAR_MSG = 0;
                script->USE_STATE = USE_TATTLE_FORCE_NPC;
                break;
            }
            script->USE_STATE = USE_TATTLE_CHOOSE;
            // fallthrough
        case USE_TATTLE_CHOOSE:
            // check for entity tattle
            if (GoombarioTattleInteractionID >= 0 && (GoombarioTattleInteractionID & COLLISION_WITH_ENTITY_BIT)) {
                temp = get_entity_type(GoombarioTattleInteractionID);
                msgID = -1;
                do {} while (0);
                for (i = 0; EntityTattles[2 * i] != -1; i++) {
                    if (EntityTattles[2 * i] != temp) {
                        continue;
                    }
                    switch (temp) {
                        case ENTITY_TYPE_HAMMER2_BLOCK:
                        case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
                            if (gPlayerData.hammerLevel >= 1) {
                                msgID = MSG_EntityTattle_HammerBlock2_CanBreak;
                            }
                            break;
                        case ENTITY_TYPE_HAMMER3_BLOCK:
                        case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
                            if (gPlayerData.hammerLevel >= 2) {
                                msgID = MSG_EntityTattle_HammerBlock3_CanBreak;
                            }
                            break;
                        case ENTITY_TYPE_WOODEN_CRATE:
                            if (gPlayerData.bootsLevel == 1) {
                                msgID = MSG_EntityTattle_WoodenCrate_SpinJump;
                            } else if (gPlayerData.bootsLevel == 2) {
                                msgID = MSG_EntityTattle_WoodenCrate_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_BOARDED_FLOOR:
                            if (gPlayerData.bootsLevel == 1) {
                                msgID = MSG_EntityTattle_BoardedFloor_SpinJump;
                            } else if (gPlayerData.bootsLevel == 2) {
                                msgID = MSG_EntityTattle_BoardedFloor_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_HUGE_BLUE_SWITCH:
                            if (gPlayerData.bootsLevel >= 2) {
                                msgID = MSG_EntityTattle_BigSwitch_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_GREEN_STOMP_SWITCH:
                            if (gPlayerData.bootsLevel >= 2) {
                                msgID = MSG_EntityTattle_FloorSwitch_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_STAR_BOX_LAUCHER:
                            if (gPlayerData.bootsLevel >= 2) {
                                msgID = MSG_EntityTattle_JackInTheBox_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_CHEST:
                            if (get_entity_by_index(GoombarioTattleInteractionID & 0x3FFF)->dataBuf.chest->itemID == -1) {
                                msgID = MSG_EntityTattle_EmptyChest;
                            }
                            break;
                    }
                    if (msgID != -1) {
                        script->VAR_MSG = msgID;
                    } else {
                        script->VAR_MSG = EntityTattles[2 * i + 1];
                    }
                    script->VAR_SKIP = FALSE;
                    return ApiStatus_DONE2;
                }
            }

            // check for NPC tattle
            if (GoombarioTattleInteractionID >= 0 && (GoombarioTattleInteractionID & COLLISION_WITH_NPC_BIT)) {
                TattleInteractNpc = get_npc_unsafe(GoombarioTattleInteractionID & 0x1FFF);
                v0 = get_enemy(TattleInteractNpc->npcID)->tattleMsg;
                if (v0 != 0) {
                    msgID = v0;
                    if (msgID < EVT_LIMIT) {
                        script->VAR_MSG = ((s32(*)(void))msgID)();
                    } else {
                        script->VAR_MSG = msgID;
                        script->VAR_SKIP = FALSE;
                    }
                }
                return ApiStatus_DONE2;
            }

            // generic interact tattle
            if (TattleHadInteractPrompt) {
                script->VAR_MSG = MSG_EntityTattle_Interact;
                script->VAR_SKIP = FALSE;
                return ApiStatus_DONE2;
            }

            // check for custom trigger tattle
            temp = MSG_NONE;
            if (GoombarioTattleInteractionID >= 0) {
                temp = world_goombario_get_trigger_tattle(GoombarioTattleInteractionID);
            }

            // check map tattle
            if (temp == MSG_NONE) {
                msgID = get_current_map_settings()->tattle.msgID;
                if (msgID != 0) {
                    if (msgID < EVT_LIMIT) {
                        // map uses a get_tattle function
                        script->VAR_MSG = ((s32(*)(void))msgID)();
                    } else {
                        script->VAR_MSG = msgID;
                        script->VAR_SKIP = FALSE;
                    }
                }
            } else {
                script->VAR_MSG = temp;
                script->VAR_SKIP = TRUE;
            }
            return ApiStatus_DONE2;
    }

    switch (script->USE_STATE) {
        case USE_TATTLE_FORCE_MAP:
            msgID = get_current_map_settings()->tattle.msgID;
            if (msgID != 0) {
                if (msgID < EVT_LIMIT) {
                    script->VAR_MSG = ((s32(*)(void))msgID)();
                } else {
                    script->VAR_MSG = msgID;
                    script->VAR_SKIP = FALSE;
                }
                return ApiStatus_DONE2;
            }
            break;
        case USE_TATTLE_FORCE_NPC:
            npcMsgID = get_enemy(TattleInteractNpc->npcID)->tattleMsg;
            if (npcMsgID != MSG_NONE) {
                script->VAR_MSG = npcMsgID;
                script->VAR_SKIP = FALSE;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(WorldGoombarioTattleEnd) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    set_time_freeze_mode(TIME_FREEZE_NORMAL);

    if (WorldGoombarioTattleActive) {
        WorldGoombarioTattleActive = FALSE;
        enable_player_input();
    }

    goombarioActionStatus->partnerActionState = PARTNER_ACTION_NONE;
    goombarioActionStatus->actingPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

EvtScript EVS_GoombarioUseAbility = {
    EVT_CALL(WorldGoombarioSelectTattleMsg)
    // abort without cleanup if failed to init
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    // abort if no tattle message is available
    EVT_IF_EQ(LVar0, MSG_NONE)
        EVT_CALL(WorldGoombarioTattleEnd)
        EVT_RETURN
    EVT_END_IF
    // show message if VAR_SKIP is FALSE
    EVT_IF_EQ(LVar1, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, LVar0)
    EVT_END_IF
    EVT_WAIT(1)
    // cleanup
    EVT_CALL(WorldGoombarioTattleEnd)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(WorldGoombarioPutAway) {
    Npc* goombario = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goombario);
    }

    if (partner_put_away(goombario)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_GoombarioPutAway = {
    EVT_CALL(WorldGoombarioPutAway)
    EVT_RETURN
    EVT_END
};

void world_goombario_pre_battle(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    if (goombarioActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        enable_player_input();
        cancel_current_message();
        partner_clear_player_tracking(goombario);
        goombarioActionStatus->partnerActionState = PARTNER_ACTION_NONE;
        goombarioActionStatus->actingPartner = PARTNER_NONE;
        disable_npc_blur(goombario);
    }

    goombarioActionStatus->actingPartner = PARTNER_GOOMBARIO;
}
