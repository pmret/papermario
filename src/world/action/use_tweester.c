#include "common.h"
#include "../partners.h"
#include "npc.h"

typedef struct TweesterPhysicsState {
    /* 0x000 */ s32 countdown;
    /* 0x004 */ char unk_04[8];
    /* 0x00C */ f32 radius;
    /* 0x010 */ f32 angle;
    /* 0x014 */ f32 angularVelocity;
    /* 0x018 */ f32 liftoffVelocityPhase;
} TweesterPhysicsState;

extern Entity* TweesterTouchingPlayer;
extern struct TweesterPhysicsState* TweesterPhysics;

void func_802B6000_E2A340(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entity;
    f32 sinAngle;
    f32 cosAngle;
    f32 velY;

    entity = TweesterTouchingPlayer;
    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= (PLAYER_STATUS_FLAGS_100000 | PLAYER_STATUS_FLAGS_FLYING);
        suggest_player_anim_clearUnkFlag(0x8001F);
        playerStatus->fallState = 0;
        mem_clear(TweesterPhysics, sizeof(*TweesterPhysics));
        TweesterPhysics->radius = fabsf(dist2D(playerStatus->position.x, playerStatus->position.z, entity->position.x, entity->position.z));
        TweesterPhysics->angle = atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z);
        TweesterPhysics->angularVelocity = 6.0f;
        TweesterPhysics->liftoffVelocityPhase = 50.0f;
        TweesterPhysics->countdown = 0x78;
        sfx_play_sound_at_player(SOUND_2F6, 0);
    }

    switch (playerStatus->fallState) {
        case 0:
            sin_cos_rad((TweesterPhysics->angle * TAU) / 360.0f, &sinAngle, &cosAngle);

            playerStatus->position.x = entity->position.x + (sinAngle * TweesterPhysics->radius);
            playerStatus->position.z = entity->position.z - (cosAngle * TweesterPhysics->radius);

            TweesterPhysics->angle = clamp_angle(TweesterPhysics->angle - TweesterPhysics->angularVelocity);

            if (TweesterPhysics->radius > 20.0f) {
                TweesterPhysics->radius--;
            } else if (TweesterPhysics->radius < 19.0f) {
                TweesterPhysics->radius++;
            }

            velY = sin_rad((TweesterPhysics->liftoffVelocityPhase * TAU) / 360.0f)  * 3.0f;
            TweesterPhysics->liftoffVelocityPhase += 3.0f;
            if (TweesterPhysics->liftoffVelocityPhase > 150.0f) {
                TweesterPhysics->liftoffVelocityPhase = 150.0f;
            }

            playerStatus->position.y += velY;
            playerStatus->spriteFacingAngle = clamp_angle(360.0f - TweesterPhysics->angle);
            TweesterPhysics->angularVelocity += 0.6;
            if (TweesterPhysics->angularVelocity > 40.0f) {
                TweesterPhysics->angularVelocity = 40.0f;
            }
            if (--TweesterPhysics->countdown == 0) {
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

