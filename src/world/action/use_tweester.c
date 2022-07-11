#include "common.h"
#include "../partners.h"
#include "npc.h"

extern struct TweesterPhysics* PlayerTweesterPhysics;

void func_802B6000_E2A340(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    entity = TweesterTouchingPlayer;
    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= (PLAYER_STATUS_FLAGS_100000 | PLAYER_STATUS_FLAGS_FLYING);
        suggest_player_anim_clearUnkFlag(0x8001F);
        playerStatus->fallState = 0;
        mem_clear(PlayerTweesterPhysics, sizeof(TweesterPhysics));
        PlayerTweesterPhysics->radius = fabsf(dist2D(playerStatus->position.x, playerStatus->position.z, entity->position.x, entity->position.z));
        PlayerTweesterPhysics->angle = atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z);
        PlayerTweesterPhysics->angularVelocity = 6.0f;
        PlayerTweesterPhysics->liftoffVelocityPhase = 50.0f;
        PlayerTweesterPhysics->countdown = 0x78;
        sfx_play_sound_at_player(SOUND_2F6, 0);
    }

    switch (playerStatus->fallState) {
        case 0:
            sin_cos_rad((PlayerTweesterPhysics->angle * TAU) / 360.0f, &sinAngle, &cosAngle);

            playerStatus->position.x = entity->position.x + (sinAngle * PlayerTweesterPhysics->radius);
            playerStatus->position.z = entity->position.z - (cosAngle * PlayerTweesterPhysics->radius);

            PlayerTweesterPhysics->angle = clamp_angle(PlayerTweesterPhysics->angle - PlayerTweesterPhysics->angularVelocity);

            if (PlayerTweesterPhysics->radius > 20.0f) {
                PlayerTweesterPhysics->radius--;
            } else if (PlayerTweesterPhysics->radius < 19.0f) {
                PlayerTweesterPhysics->radius++;
            }

            liftoffVelocity = sin_rad((PlayerTweesterPhysics->liftoffVelocityPhase * TAU) / 360.0f)  * 3.0f;
            PlayerTweesterPhysics->liftoffVelocityPhase += 3.0f;
            if (PlayerTweesterPhysics->liftoffVelocityPhase > 150.0f) {
                PlayerTweesterPhysics->liftoffVelocityPhase = 150.0f;
            }

            playerStatus->position.y += liftoffVelocity;
            playerStatus->spriteFacingAngle = clamp_angle(360.0f - PlayerTweesterPhysics->angle);
            PlayerTweesterPhysics->angularVelocity += 0.6;
            if (PlayerTweesterPhysics->angularVelocity > 40.0f) {
                PlayerTweesterPhysics->angularVelocity = 40.0f;
            }
            if (--PlayerTweesterPhysics->countdown == 0) {
                playerStatus->fallState++;
                entity_start_script(entity);
            }
            break;
        case 1:
            disable_player_shadow();
            disable_npc_shadow(wPartnerNpc);
            playerStatus->blinkTimer = 0x32;
            enable_player_static_collisions();
            enable_player_input();
            playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_100000 | PLAYER_STATUS_FLAGS_FLYING);
            set_action_state(ACTION_STATE_IDLE);
            break;
    }
}

