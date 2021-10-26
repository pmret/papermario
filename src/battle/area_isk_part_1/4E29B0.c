#include "common.h"
#include "effects.h"

#define NAMESPACE b_area_isk_part_1

extern EffectInstance* D_80224D60;
extern EffectInstance* D_80224D64;
extern s32 D_80224920_4EF060;

#include "common/ChainChompChainInit.inc.c"

#include "common/ChainChompChainUpdateHelperFunc.inc.c"

#include "common/ChainChompChainUpdateHelperFunc2.inc.c"

INCLUDE_ASM(s32, "battle/area_isk_part_1/4E29B0", b_area_isk_part_1_ChainChompChainUpdate);
/*
ApiStatus N(ChainChompChainUpdate)(Evt* script, s32 isInitialCall) {
    f32 sp18;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    ChainAnimationState* struc;
    f64 temp_f0_4;
    s32 temp_s3;
    Actor* actor;
    ActorPart* temp_v1;
    ChainAnimationState* phi_s0;
    s32 phi_s3;
    f32 phi_f0;
    f32 phi_f22;
    ChainAnimationState* phi_s2;
    f32 phi_f20;
    f32 phi_a1;
    f64 phi_f0_2;
    f64 phi_f2;
    f32 phi_f0_3;

    actor = get_actor(script->owner1.actorID);
    if (actor == 0) {
        return ApiStatus_BLOCK;
    }
    struc = actor->state.unk_6C;
    phi_s2 = struc;
    if (actor->debuff == 0xA) {
        phi_f0_2 = (f64) actor->currentPos.y;
        phi_f2 = (f64) actor->currentPos.x + 6.0;
    } else {
        phi_f0_2 = (f64) actor->currentPos.y;
        phi_f2 = (f64) actor->currentPos.x + 12.0;
    }
    phi_s0 = struc + 4;
    phi_s3 = 0;
    phi_f22 = (f32) (phi_f0_2 + 0.0);
    phi_f20 = (f32) phi_f2;
    do {
        if (actor->debuff != 0xA) {
            phi_s0->unk_20 = 7.0f;
            phi_s0->unk_28 = 7.0f;
            phi_s0->unk_24 = 7.0f;
        } else {
            phi_s0->unk_20 = 3.5f;
            phi_s0->unk_28 = 3.5f;
            phi_s0->unk_24 = 3.5f;
        }
        temp_f0 = phi_s0->unk_10;
        temp_f2 = phi_s0->unk_14 - temp_f0;
        temp_f0_2 = 2.0f * -temp_f0;
        phi_s0->unk_14 = temp_f2;
        if (temp_f2 < temp_f0_2) {
            phi_s0->unk_14 = temp_f0_2;
            if ((actor->state.varTable[5] != 0) && (phi_s3 == 0)) {
                sfx_play_sound_at_position(0x2063, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
            }
        }
        temp_f0_3 = phi_s0->currentPos.x + phi_s0->unk_14;
        phi_s0->currentPos.x = temp_f0_3;
        temp_f0_4 = (f64) temp_f0_3;
        if (actor->debuff == 0xA) {
            if (temp_f0_4 < 2.5) {
                phi_s0->unk_14 = 0.0f;
                phi_f0 = 2.5f;
                goto block_20;
            }
        } else if (temp_f0_4 < 5.0) {
            phi_s0->unk_14 = 0.0f;
            phi_f0 = 5.0f;
block_20:
            phi_s0->currentPos.x = phi_f0;
        }
        temp_f20 = dist2D(phi_f20, phi_f22, *phi_s2, phi_s0->currentPos.x);
        temp_f0_5 = atan2(phi_f20, phi_f22, *phi_s2, phi_s0->currentPos.x);
        temp_f2_2 = phi_s0->unk_28;
        if (temp_f2_2 <= temp_f20) {
            N(ChainChompChainUpdateHelperFunc2)(&sp18, temp_f20 - temp_f2_2, temp_f0_5);
            phi_s0->unk_14 = (f32) ((f64) phi_s0->unk_14 + ((f64) sp18 * 0.5));
        }
        if (phi_s0->unk_24 <= temp_f20) {
            temp_f0_6 = phi_s0->unk_20;
            if (temp_f0_6 <= temp_f20) {
                phi_f0_3 = temp_f20 - temp_f0_6;
            } else {
                temp_f0_7 = phi_s0->unk_18 + phi_s0->unk_1C;
                phi_s0->unk_18 = temp_f0_7;
                phi_f0_3 = temp_f0_7;
            }
            phi_a1 = phi_f0_3;
        } else {
            temp_f0_8 = (f32) ((f64) phi_s0->unk_18 - ((f64) phi_s0->unk_1C * D_80224920_4EF060));
            phi_s0->unk_18 = temp_f0_8;
            if ((f64) temp_f0_8 < 0.0) {
                phi_s0->unk_18 = 0.0f;
            }
            phi_a1 = phi_s0->unk_18;
        }
        N(ChainChompChainUpdateHelperFunc)(phi_s2, phi_a1, temp_f0_5);
        if ((f64) phi_s0->unk_18 > 4.0) {
            phi_s0->unk_18 = 4.0f;
        }
        temp_v1 = get_actor_part(actor, phi_s3 + 3);
        temp_v1->absolutePosition.x = (f32) phi_s2->currentPos.x;
        temp_v1->absolutePosition.x = (f32) phi_s0.currentPos.y;
        temp_v1->absolutePosition.x = (f32) phi_s0.currentPos.z;
        if (actor->debuff != 0xA) {
            temp_v1->scale.x = 1.0f;
            temp_v1->scale.y = 1.0f;
            temp_v1->scale.z = 1.0f;
        } else {
            temp_v1->scale.x = 1.0f;
            temp_v1->scale.y = 0.5f;
            temp_v1->scale.z = 0.5f;
        }
        temp_s3 = phi_s3 + 1;
        phi_s0 += 0x30;
        phi_s3 = temp_s3;
        phi_f22 = phi_s0->currentPos.x;
        phi_s2 += 0x30;
        phi_f20 = *phi_s2;
    } while (temp_s3 < 8);
    return 2;
}
*/

// Clover's suggestion: isk_bt04_CreateTorchFX
// Reason: this sort of additional namespacing is required because the isk battle source includes the data for each of the stages
//   if these were regular maps, theyd have their own source files
ApiStatus func_802188B0_4E2FF0(Evt* script, s32 isInitialCall) {
    playFX_20(1, -133.0f, 72.0f, -143.0f, 0.3f, &D_80224D60);
    playFX_20(1, 129.0f, 72.0f, -143.0f, 0.3f, &D_80224D64);
    return ApiStatus_DONE2;
}

// Clover's suggestion: isk_bt04_DeleteTorchFX
// Reason: this sort of additional namespacing is required because the isk battle source includes the data for each of the stages
//   if these were regular maps, theyd have their own source files
ApiStatus func_80218944_4E3084(Evt* script, s32 isInitialCall) {
    remove_effect(D_80224D60);
    remove_effect(D_80224D64);
    return ApiStatus_DONE2;
}
