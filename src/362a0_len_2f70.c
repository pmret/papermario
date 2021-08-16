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
    void* compressedData = load_asset_by_name(&wMapHitName, &assetSize);
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

void _add_hit_vert_to_buffer(f32** buf, f32* vert, s32* bufSize) {
    s32 i;

    for (i = 0; i < *bufSize; i++) {
        if (buf[i] == vert) {
            break;
        }
    }

    if (i == *bufSize) {
        buf[i] = vert;
        (*bufSize)++;
    }
}

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

s32 get_collider_type_by_id(s32 colliderID) {
    if (colliderID & 0x4000) {
        return 0;
    } else {
        return gCollisionData.colliderList[colliderID].flags;
    }
}

void get_flat_collider_normal(s32 colliderID, f32* x, f32* y, f32* z) {
    ColliderTriangle* triangle = &gCollisionData.colliderList[colliderID].triangleTable[0];

    *x = triangle->normal.x;
    *y = triangle->normal.y;
    *z = triangle->normal.z;
}

void get_collider_center(s32 colliderID, f32* x, f32* y, f32* z) {
    ColliderBoundingBox* aabb = gCollisionData.colliderList[colliderID].aabb;

    *x = (aabb->min[0] + aabb->max[0]) * 0.5f;
    *y = (aabb->min[1] + aabb->max[1]) * 0.5f;
    *z = (aabb->min[2] + aabb->max[2]) * 0.5f;
}

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_triangle_general);

INCLUDE_ASM(s32, "362a0_len_2f70", test_down_ray_triangle);

s32 test_up_ray_triangle(ColliderTriangle* triangle, f32* vertices);
INCLUDE_ASM(s32, "362a0_len_2f70", test_up_ray_triangle, ColliderTriangle* triangle, f32* vertices);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_colliders, s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX,
            f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_zones, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
            f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* nx, f32* ny, f32* nz);

//s32 test_up_ray_collider(s32 ignoreFlags, s32 colliderID, f32 x, f32 y, f32 z, f32 length, f32 yaw);
// Close, but no cigar
extern f32 D_800A4230;
extern f32 D_800A4234;
extern f32 D_800A4238;
extern f32 D_800A423C;
extern s32 D_800A4240;
extern f32 D_800A4244;
extern f32 D_800A4254;

#ifdef NON_MATCHING
f32 test_up_ray_collider(s32 ignoreFlags, s32 colliderID, f32 x, f32 y, f32 z, f32 length, f32 yaw) {
    CollisionData* collisionData = &gCollisionData;
    f32 cosTheta;
    f32 sinTheta;
    Collider* collider;
    ColliderTriangle* triangleTable;
    s32 i;
    f32 ret;

    sin_cos_rad(yaw * TAU / 360.0f, &sinTheta, &cosTheta);
    collider = &collisionData->colliderList[colliderID];

    D_800A4240 = 0;
    D_800A4230 = x;
    D_800A4234 = y;
    D_800A4238 = z;
    D_800A4254 = length;
    D_800A423C = sinTheta;
    D_800A4244 = -cosTheta;
    ret = -1.0f;


    if (!(collider->flags & ignoreFlags)) {
        if (collider->numTriangles != 0) {
            triangleTable = collider->triangleTable;

            for (i = 0; i < collider->numTriangles; i++) {
                if (test_up_ray_triangle(&triangleTable[i], collisionData->vertices)) {
                    ret = D_800A4254;
                }
            }
        }
    }
    return ret;
}
#else
INCLUDE_ASM(s32, "362a0_len_2f70", test_up_ray_collider, s32 ignoreFlags, s32 colliderID, f32 x, f32 y, f32 z, f32 length, f32 yaw);
#endif

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_entities, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
            f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

INCLUDE_ASM(s32, "362a0_len_2f70", func_8005DB00);

ApiStatus func_8005DD54(ScriptInstance* script, s32 isInitialCall) {
    f32 angle = clamp_angle(script->varTable[0]);

    script->varTable[0] = angle;
    if (angle >= 180.0f) {
        angle -= 180.0f;
    }
    if (angle >= 90.0f) {
        angle = 180.0f - angle;
    }
    script->varTable[2] = (s32) (((90.0f - angle) * 95.0f) / 90.0f) + 160;
    return ApiStatus_DONE2;
}

s32 func_8005DDF0(void) {
    return ~gCurrentEncounter.unk_08 != 0;
}
