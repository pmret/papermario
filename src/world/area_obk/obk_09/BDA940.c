#include "obk_09.h"
#include "effects.h"

typedef struct UnkObk09 {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ s32 shadowID;
    /* 0x1C */ EffectInstance* spiritCard;
} UnkObk09; // size = 0x20

ApiStatus func_80240190_BDA940(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);
    UnkObk09* data = heap_malloc(sizeof(*data));

    script->userData = data;
    data->pos.x = npc->pos.x;
    data->pos.y = npc->pos.y;
    data->pos.z = npc->pos.z;
    data->unk_10 = 0.0f;
    data->spiritCard = fx_spirit_card(1, data->pos.x, data->pos.y, data->pos.z, 1.0f, 0);
    data->spiritCard->data.spiritCard->chapter = 2;
    data->shadowID = create_shadow_type(0, data->pos.x, data->pos.y, data->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus func_80240248_BDA9F8(Evt* script, s32 isInitialCall) {
    UnkObk09* data = script->userData;
    Npc* npc = get_npc_safe(script->owner2.npcID);
    Shadow* shadow = get_shadow_by_index(data->shadowID);
    EffectInstance* effect;

    data->pos.x = npc->pos.x - 2.0f;
    data->pos.y = npc->pos.y + 12.0f;
    data->pos.z = npc->pos.z - 30.0f;

    effect = data->spiritCard;
    effect->data.spiritCard->pos.x = data->pos.x;
    effect->data.spiritCard->pos.y = data->pos.y;
    effect->data.spiritCard->pos.z = data->pos.z;
    data->unk_10 = clamp_angle(data->unk_10 + 6.6f);
    effect->data.spiritCard->yaw = data->unk_10;

    shadow->position.x = data->pos.x;
    shadow->position.y = data->pos.y - 40.0f;
    shadow->position.z = data->pos.z;
    return ApiStatus_BLOCK;
}
