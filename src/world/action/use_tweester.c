#include "common.h"
#include "../partners.h"
#include "npc.h"
#include "sprite/player.h"

BSS TweesterPhysics PlayerTweesterPhysicsData;
TweesterPhysics* PlayerTweesterPhysicsPtr = &PlayerTweesterPhysicsData;

enum {
    SUBSTATE_LAUNCH     = 0,
    SUBSTATE_DONE       = 1
};

void action_update_use_tweester(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    entity = TweesterTouchingPlayer;
    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= (PS_FLAG_ROTATION_LOCKED | PS_FLAG_FLYING);
        suggest_player_anim_allow_backward(ANIM_MarioW2_FlailArms);
        playerStatus->actionSubstate = SUBSTATE_LAUNCH;
        mem_clear(PlayerTweesterPhysicsPtr, sizeof(*PlayerTweesterPhysicsPtr));
        PlayerTweesterPhysicsPtr->radius = fabsf(dist2D(playerStatus->pos.x, playerStatus->pos.z, entity->pos.x, entity->pos.z));
        PlayerTweesterPhysicsPtr->angle = atan2(entity->pos.x, entity->pos.z, playerStatus->pos.x, playerStatus->pos.z);
        PlayerTweesterPhysicsPtr->angularVel = 6.0f;
        PlayerTweesterPhysicsPtr->liftoffVelPhase = 50.0f;
        PlayerTweesterPhysicsPtr->countdown = 120;
        sfx_play_sound_at_player(SOUND_TWEESTER_LAUNCH, SOUND_SPACE_MODE_0);
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_LAUNCH:
            sin_cos_rad(DEG_TO_RAD(PlayerTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);

            playerStatus->pos.x = entity->pos.x + (sinAngle * PlayerTweesterPhysicsPtr->radius);
            playerStatus->pos.z = entity->pos.z - (cosAngle * PlayerTweesterPhysicsPtr->radius);

            PlayerTweesterPhysicsPtr->angle = clamp_angle(PlayerTweesterPhysicsPtr->angle - PlayerTweesterPhysicsPtr->angularVel);

            if (PlayerTweesterPhysicsPtr->radius > 20.0f) {
                PlayerTweesterPhysicsPtr->radius--;
            } else if (PlayerTweesterPhysicsPtr->radius < 19.0f) {
                PlayerTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(PlayerTweesterPhysicsPtr->liftoffVelPhase))  * 3.0f;
            PlayerTweesterPhysicsPtr->liftoffVelPhase += 3.0f;
            if (PlayerTweesterPhysicsPtr->liftoffVelPhase > 150.0f) {
                PlayerTweesterPhysicsPtr->liftoffVelPhase = 150.0f;
            }

            playerStatus->pos.y += liftoffVelocity;
            playerStatus->spriteFacingAngle = clamp_angle(360.0f - PlayerTweesterPhysicsPtr->angle);
            PlayerTweesterPhysicsPtr->angularVel += 0.6;
            if (PlayerTweesterPhysicsPtr->angularVel > 40.0f) {
                PlayerTweesterPhysicsPtr->angularVel = 40.0f;
            }
            if (--PlayerTweesterPhysicsPtr->countdown == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_DONE
                entity_start_script(entity);
            }
            break;
        case SUBSTATE_DONE:
            disable_player_shadow();
            disable_npc_shadow(wPartnerNpc);
            playerStatus->blinkTimer = 50;
            enable_player_static_collisions();
            enable_player_input();
            playerStatus->flags &= ~(PS_FLAG_ROTATION_LOCKED | PS_FLAG_FLYING);
            set_action_state(ACTION_STATE_IDLE);
            break;
    }
}

