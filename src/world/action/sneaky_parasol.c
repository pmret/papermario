#include "common.h"
#include "npc.h"

typedef struct SneakyParasolUnk {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
} SneakyParasolUnk;

extern SneakyParasolUnk D_802B6E80;

f64 fabs(f64 f);

#ifdef NON_MATCHING
Npc* func_802B6000_E2A6B0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 angle;
    Npc* ret = NULL;

    if (playerStatus->unk_0D != 0) {
        if (gGameStatusPtr->peachFlags & 8) {
            gGameStatusPtr->peachFlags &= ~0x8;
        } else {
            ret = npc_find_near(playerStatus->position.x, playerStatus->position.y, playerStatus->position.z, 100.0f);

            if (ret != NULL) {
                if (fabs(ret->pos.y - playerStatus->position.y) - 1.0 > 0.0) {
                    ret = NULL;
                } else {
                    angle = clamp_angle(atan2(playerStatus->position.x, playerStatus->position.z, ret->pos.x, ret->pos.z));
                    if (fabs(angle - func_800E5348()) > 30.0) {
                         ret = NULL;
                     }
                }
            }
        }
    }

    return ret;
}
#else
INCLUDE_ASM(Npc*, "world/action/sneaky_parasol", func_802B6000_E2A6B0, void);
#endif

INCLUDE_ASM(s32, "world/action/sneaky_parasol", func_802B6120_E2A7D0);

void func_802B6CF0_E2B3A0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SneakyParasolUnk* temp = &D_802B6E80;

    temp->unk_20 += temp->unk_1C;
    if (temp->unk_20 > 50.0f) {
        temp->unk_20 = 50.0f;
    } else if (temp->unk_20 < -50.0f) {
        temp->unk_20 = -50.0f;
    }

    playerStatus->spriteFacingAngle = clamp_angle(playerStatus->spriteFacingAngle + temp->unk_20);
}
