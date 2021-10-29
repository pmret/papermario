#include "common.h"
#include "../partners.h"
#include "npc.h"

typedef struct unkTweesterStruct{
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ char unk_04[8];
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
}unkTweesterStruct;

extern s8* D_8010C934;
extern struct unkTweesterStruct* D_802B6350_E2A690;

void func_802B6000_E2A340(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    entity = D_8010C934;
    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000000;
        disable_player_static_collisions();
        disable_player_input();
        playerStatus->flags |= 0x100008;
        suggest_player_anim_clearUnkFlag(0x8001F);
        playerStatus->fallState = 0;
        mem_clear(D_802B6350_E2A690, sizeof(*D_802B6350_E2A690));
        D_802B6350_E2A690->unk_0C = fabsf(dist2D(playerStatus->position.x, playerStatus->position.z, entity->position.x, entity->position.z));
        D_802B6350_E2A690->unk_10 = atan2(entity->position.x, entity->position.z, playerStatus->position.x, playerStatus->position.z);
        D_802B6350_E2A690->unk_14 = 6.0f;
        D_802B6350_E2A690->unk_18 = 50.0f;
        D_802B6350_E2A690->unk_00 = 0x78;
        sfx_play_sound_at_player(SOUND_UNKNOWN_2F6, 0);
    }

    switch (playerStatus->fallState) {
        case 0:
            sin_cos_rad((D_802B6350_E2A690->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            playerStatus->position.x = entity->position.x + (sp10 * D_802B6350_E2A690->unk_0C);
            playerStatus->position.z = entity->position.z - (sp14 * D_802B6350_E2A690->unk_0C);

            D_802B6350_E2A690->unk_10 = clamp_angle(D_802B6350_E2A690->unk_10 - D_802B6350_E2A690->unk_14);

            if (D_802B6350_E2A690->unk_0C > 20.0f) {
                D_802B6350_E2A690->unk_0C--;
            } else if (D_802B6350_E2A690->unk_0C < 19.0f) {
                D_802B6350_E2A690->unk_0C++;
            }

            tempY = sin_rad((D_802B6350_E2A690->unk_18 * TAU) / 360.0f)  * 3.0f;
            D_802B6350_E2A690->unk_18 += 3.0f;
            if (D_802B6350_E2A690->unk_18 > 150.0f) {
                D_802B6350_E2A690->unk_18 = 150.0f;
            }

            playerStatus->position.y += tempY;
            playerStatus->spriteFacingAngle = clamp_angle(360.0f - D_802B6350_E2A690->unk_10);
            D_802B6350_E2A690->unk_14 += 0.6;
            if (D_802B6350_E2A690->unk_14 > 40.0f) {
                D_802B6350_E2A690->unk_14 = 40.0f;
            }
            if (--D_802B6350_E2A690->unk_00 == 0) {
                playerStatus->fallState++;
                entity_start_script(entity);
            }
            break;
        case 1:
            disable_player_shadow();
            disable_npc_shadow(wPartnerNpc);
            playerStatus->unk_10 = 0x32;
            enable_player_static_collisions();
            enable_player_input();
            playerStatus->flags &= ~0x100008;
            set_action_state(ACTION_STATE_IDLE);
            break;
    }
}

