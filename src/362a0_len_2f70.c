#include "common.h"

extern s16 D_800D91DC;

typedef struct {
    UNK_PTR collision;
    UNK_PTR unk_08;
} HitAsset;

void load_hit_data(s32 idx, HitAsset* hit);

INCLUDE_ASM(s32, "362a0_len_2f70", allocate_hit_tables);

void func_8005AF84(void) {
}

void func_8005AF8C(void) {
}

void initialize_collision(void) {
    gCollisionData.numColliders = 0;
    D_800D91DC = 0;
    collision_heap_create();
}

void load_hit_asset(void) {
    u32 assetSize;
    MapConfig* map = get_current_map_header();
    void* compressedData = load_asset_by_name(&mapHitName, &assetSize);
    HitAsset* uncompressedData = heap_malloc(assetSize);

    decode_yay0(compressedData, uncompressedData);
    general_heap_free(compressedData);

    map->collision = uncompressedData->collision;
    map->unk_08 = uncompressedData->unk_08;

    load_hit_data(0, uncompressedData);
    load_hit_data(1, uncompressedData);

    heap_free(uncompressedData);
}

INCLUDE_ASM(s32, "362a0_len_2f70", load_collision);

void load_stage_collision(const char* hitName) {
    if (hitName == NULL) {
        gCollisionData.numColliders = 0;
    } else {
        u32 assetSize;
        MapConfig* map = get_current_map_header();
        void* compressedData = load_asset_by_name(hitName, &assetSize);
        HitAsset* uncompressedData = heap_malloc(assetSize);

        decode_yay0(compressedData, uncompressedData);
        general_heap_free(compressedData);

        map->collision = uncompressedData->collision;

        load_hit_data(0, uncompressedData);

        heap_free(uncompressedData);
    }
}

INCLUDE_ASM(void, "362a0_len_2f70", load_hit_data, s32 idx, HitAsset* hit);

INCLUDE_ASM(void, "362a0_len_2f70", parent_collider_to_model, s32 colliderID, s16 modelIndex);

INCLUDE_ASM(s32, "362a0_len_2f70", _add_hit_vert_to_buffer);

s32 _get_hit_vert_index_from_buffer(f32** buffer, f32* vert, s32* bufferSize) {
    s32 i;

    for (i = 0; i < *bufferSize; i++) {
        if (*buffer == vert) {
            break;
        }
        buffer++;
    }

    return i;
}

INCLUDE_ASM(void, "362a0_len_2f70", update_collider_transform, s16 colliderID);

// Simon says there's a struct size issue here which is causing the subu/addu issue
#ifdef NON_MATCHING
s32 get_collider_type_by_id(s32 colliderID) {
    if (colliderID & 0x4000) {
        return 0;
    } else {
        return gCollisionData.collider_list[colliderID].flags;
    }
}
#else
INCLUDE_ASM(s32, "362a0_len_2f70", get_collider_type_by_id);
#endif

INCLUDE_ASM(s32, "362a0_len_2f70", get_flat_collider_normal);

INCLUDE_ASM(void, "362a0_len_2f70", get_collider_center, s32 colliderID, f32* x, f32* y, f32* z);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_triangle_general);

INCLUDE_ASM(s32, "362a0_len_2f70", test_down_ray_triangle);

INCLUDE_ASM(s32, "362a0_len_2f70", test_up_ray_triangle);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_colliders);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_zones, f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6, f32* arg7, f32* arg8, f32* arg9);

INCLUDE_ASM(s32, "362a0_len_2f70", test_up_ray_collider);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_entities);

INCLUDE_ASM(s32, "362a0_len_2f70", func_8005DB00);

INCLUDE_ASM(s32, "362a0_len_2f70", func_8005DD54);

s32 func_8005DDF0(void) {
    return ~gCurrentEncounter.unk_08 != 0;
}
