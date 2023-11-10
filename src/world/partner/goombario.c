#include "common.h"
#include "sprite/npc/WorldGoombario.h"
#include "goombario.h"
#include "../src/world/partners.h"
#include "message_ids.h"
#include "entity.h"

#define NAMESPACE world_goombario

extern SpeechBubbleData* SpeechBubblePtr;

BSS s32 N(HadSpeechPrompt);
BSS s32 N(HadInteractPrompt);
BSS Npc* N(InteractNpc);
BSS s32 N(D_802BDF3C); // unused (padding?)
BSS TweesterPhysics N(TweesterPhysicsData);
BSS s32 N(D_802BDF5C); // unused (padding?)
BSS s32 WorldTattleInteractionID;
BSS s32 N(IsTattleActive);

s32 N(EntityTattles)[] = {
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
    ENTITY_TYPE_STAR_BOX_LAUNCHER,    MSG_EntityTattle_JackInTheBox_SpinJump,
    ENTITY_TYPE_BELLBELL_PLANT,       MSG_EntityTattle_BellbellPlant,
    ENTITY_TYPE_TRUMPET_PLANT,        MSG_EntityTattle_TrumpetPlant,
    ENTITY_TYPE_CYMBAL_PLANT,         MSG_EntityTattle_CymbalBush,
    ENTITY_TYPE_MUNCHLESIA,           MSG_EntityTattle_Munchlesia,
    ENTITY_TYPE_SPINNING_FLOWER,      MSG_EntityTattle_SpinningFlower,
    ENTITY_TYPE_PINK_FLOWER,          MSG_EntityTattle_BulbBush,
    -1
};

s32 N(get_trigger_tattle)(s32 tattleColliderID) {
    s32 i;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL
            && trigger->flags & TRIGGER_WALL_PRESS_A
            && trigger->location.colliderID == tattleColliderID
        ) {
            return trigger->tattleMsg;
        }
    }
    return 0;
}

void N(init)(Npc* goombario) {
    goombario->collisionHeight = 24;
    goombario->collisionDiameter = 20;
}

API_CALLABLE(N(TakeOut)) {
    Npc* goombario = script->owner2.npc;
    WorldTattleInteractionID = -1;

    if (isInitialCall) {
        partner_init_get_out(goombario);
    }

    if (partner_get_out(goombario)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldGoombario_TakeOut = {
    EVT_CALL(N(TakeOut))
    EVT_RETURN
    EVT_END
};

TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_GOOMBARIO]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case 0:
            N(TweesterPhysicsPtr)->state = 1;
            N(TweesterPhysicsPtr)->prevFlags = npc->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z, npc->pos.x, npc->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            npc->flags |= NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
            npc->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);

            npc->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            npc->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
            N(TweesterPhysicsPtr)->angle = clamp_angle(N(TweesterPhysicsPtr)->angle - N(TweesterPhysicsPtr)->angularVel);

            if (N(TweesterPhysicsPtr)->radius > 20.0f) {
                N(TweesterPhysicsPtr)->radius--;
            } else if (N(TweesterPhysicsPtr)->radius < 19.0f) {
                N(TweesterPhysicsPtr)->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->liftoffVelPhase)) * 3.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase += 3.0f;

            if (N(TweesterPhysicsPtr)->liftoffVelPhase > 150.0f) {
                N(TweesterPhysicsPtr)->liftoffVelPhase = 150.0f;
            }

            npc->pos.y += liftoffVelocity;

            npc->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case 2:
            npc->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return 0;
}

void N(try_cancel_tweester)(Npc* goombario) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        goombario->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking (goombario);
    }
}

EvtScript EVS_WorldGoombario_Update = {
    EVT_CALL(N(Update))
    EVT_RETURN
    EVT_END
};

s32 N(can_open_menus)(Npc* goombario) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s32 new_var;

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        return FALSE;
    }

    if ((goombario->flags & (NPC_FLAG_GROUNDED | NPC_FLAG_JUMPING)) != NPC_FLAG_GROUNDED) {
        return new_var = 0;
        do {} while (new_var); // why though
    }

    return TRUE;
}

API_CALLABLE(N(SelectTattleMsg)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* goombario = script->owner2.npc;
    s32 msgID;
    s32 temp; // TODO required to match (this temp needs to be used in two places for different things)
    s32 npcMsgID;
    s32 enemyTattleMsg;
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
        N(try_cancel_tweester)(goombario);
        N(IsTattleActive) = FALSE;
        N(HadSpeechPrompt) = FALSE;
        N(HadInteractPrompt) = FALSE;
        if (playerStatus->animFlags & PA_FLAG_SPEECH_PROMPT_AVAILABLE) {
            N(HadSpeechPrompt) = TRUE;
            N(InteractNpc) = SpeechBubblePtr->encounteredNPC;
        }
        if (playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) {
            N(HadInteractPrompt) = TRUE;
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
            N(IsTattleActive) = TRUE;
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
                    N(IsTattleActive) = FALSE;
                    return ApiStatus_DONE2;
                }
                script->USE_STATE = USE_TATTLE_FACE_PLAYER;
            }
            break;
        case USE_TATTLE_FACE_PLAYER:
            set_time_freeze_mode(1);
            playerStatus->flags &= ~PS_FLAG_HAS_CONVERSATION_NPC;
            goombario->curAnim = ANIM_WorldGoombario_Idle;
            goombario->yaw = clamp_angle(gCameras[CAM_DEFAULT].curYaw + playerStatus->spriteFacingAngle - 90.0f);
            gPartnerStatus.partnerActionState = PARTNER_ACTION_USE;
            close_status_bar();
            if (N(HadSpeechPrompt)) {
                script->VAR_MSG = 0;
                script->USE_STATE = USE_TATTLE_FORCE_NPC;
                break;
            }
            script->USE_STATE = USE_TATTLE_CHOOSE;
            // fallthrough
        case USE_TATTLE_CHOOSE:
            // check for entity tattle
            if (WorldTattleInteractionID >= 0 && (WorldTattleInteractionID & COLLISION_WITH_ENTITY_BIT)) {
                temp = get_entity_type(WorldTattleInteractionID);
                msgID = -1;
                do {} while (0);
                for (i = 0; N(EntityTattles)[2 * i] != -1; i++) {
                    if (N(EntityTattles)[2 * i] != temp) {
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
                        case ENTITY_TYPE_STAR_BOX_LAUNCHER:
                            if (gPlayerData.bootsLevel >= 2) {
                                msgID = MSG_EntityTattle_JackInTheBox_TornadoJump;
                            }
                            break;
                        case ENTITY_TYPE_CHEST:
                            if (get_entity_by_index(WorldTattleInteractionID & 0x3FFF)->dataBuf.chest->itemID == -1) {
                                msgID = MSG_EntityTattle_EmptyChest;
                            }
                            break;
                    }
                    if (msgID != -1) {
                        script->VAR_MSG = msgID;
                    } else {
                        script->VAR_MSG = N(EntityTattles)[2 * i + 1];
                    }
                    script->VAR_SKIP = FALSE;
                    return ApiStatus_DONE2;
                }
            }

            // check for NPC tattle
            if (WorldTattleInteractionID >= 0 && (WorldTattleInteractionID & COLLISION_WITH_NPC_BIT)) {
                N(InteractNpc) = get_npc_unsafe(WorldTattleInteractionID & 0x1FFF);
                enemyTattleMsg = get_enemy(N(InteractNpc)->npcID)->tattleMsg;
                if (enemyTattleMsg != 0) {
                    msgID = enemyTattleMsg;
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
            if (N(HadInteractPrompt)) {
                script->VAR_MSG = MSG_EntityTattle_Interact;
                script->VAR_SKIP = FALSE;
                return ApiStatus_DONE2;
            }

            // check for custom trigger tattle
            temp = MSG_NONE;
            if (WorldTattleInteractionID >= 0) {
                temp = N(get_trigger_tattle)(WorldTattleInteractionID);
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
            npcMsgID = get_enemy(N(InteractNpc)->npcID)->tattleMsg;
            if (npcMsgID != MSG_NONE) {
                script->VAR_MSG = npcMsgID;
                script->VAR_SKIP = FALSE;
                return ApiStatus_DONE2;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(TattleEnd)) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    set_time_freeze_mode(TIME_FREEZE_NORMAL);

    if (N(IsTattleActive)) {
        N(IsTattleActive) = FALSE;
        enable_player_input();
    }

    partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
    partnerStatus->actingPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

EvtScript EVS_WorldGoombario_UseAbility = {
    EVT_CALL(N(SelectTattleMsg))
    // abort without cleanup if failed to init
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    // abort if no tattle message is available
    EVT_IF_EQ(LVar0, MSG_NONE)
        EVT_CALL(N(TattleEnd))
        EVT_RETURN
    EVT_END_IF
    // show message if VAR_SKIP is FALSE
    EVT_IF_EQ(LVar1, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk, ANIM_WorldGoombario_Idle, 0, LVar0)
    EVT_END_IF
    EVT_WAIT(1)
    // cleanup
    EVT_CALL(N(TattleEnd))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(PutAway)) {
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

EvtScript EVS_WorldGoombario_PutAway = {
    EVT_CALL(N(PutAway))
    EVT_RETURN
    EVT_END
};

void N(pre_battle)(Npc* goombario) {
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        enable_player_input();
        cancel_current_message();
        partner_clear_player_tracking(goombario);
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        partnerStatus->actingPartner = PARTNER_NONE;
        disable_npc_blur(goombario);
    }

    partnerStatus->actingPartner = PARTNER_GOOMBARIO;
}
