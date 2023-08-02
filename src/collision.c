#include "common.h"
#include "model.h"

typedef struct HitFile {
    /* 0x00 */ u32 collisionOffset;
    /* 0x04 */ u32 zoneOffset;
} HitFile; // size = 0x08

typedef struct ColliderBackupEntry {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 parentModelIndex;
    /* 0x06 */ char pad_06[2];
} ColliderBackupEntry; // size = 0x08

typedef struct HitFileHeader {
    /* 0x00 */ s16 numColliders;
    /* 0x02 */ char pad_02[2];
    /* 0x04 */ s32 collidersOffset;
    /* 0x08 */ s16 numVertices;
    /* 0x0A */ char pad_0A[2];
    /* 0x0C */ s32 verticesOffset;
    /* 0x10 */ s16 boundingBoxesDataSize;
    /* 0x12 */ char pad_12[2];
    /* 0x14 */ s32 boundingBoxesOffset;
} HitFileHeader; // size = 0x18

typedef struct HitAssetCollider {
    /* 0x00 */ s16 boundingBoxOffset;
    /* 0x02 */ s16 nextSibling;
    /* 0x04 */ s16 firstChild;
    /* 0x06 */ s16 numTriangles;
    /* 0x08 */ s32 trianglesOffset;
} HitAssetCollider; // size = 0x0C

SHIFT_BSS CollisionData gCollisionData;
SHIFT_BSS CollisionData gZoneCollisionData;
SHIFT_BSS f32 gCollisionRayStartX;
SHIFT_BSS f32 gCollisionRayStartY;
SHIFT_BSS f32 gCollisionRayStartZ;
SHIFT_BSS f32 gCollisionRayDirX;
SHIFT_BSS f32 gCollisionRayDirY;
SHIFT_BSS f32 gCollisionRayDirZ;
SHIFT_BSS f32 gCollisionPointX;
SHIFT_BSS f32 gCollisionPointY;
SHIFT_BSS f32 gCollisionPointZ;
SHIFT_BSS f32 gCollisionRayLength;
SHIFT_BSS f32 gCollisionNormalX;
SHIFT_BSS f32 gCollisionNormalY;
SHIFT_BSS f32 gCollisionNormalZ;
SHIFT_BSS ColliderBackupEntry* gCollisionDataBackup;
SHIFT_BSS ColliderBackupEntry* gCollisionDataZoneBackup;

extern Vec3s gEntityColliderFaces[];
extern Vec3f gEntityColliderNormals[];

s32 collision_heap_create(void);
void* collision_heap_malloc(s32 size);
void collision_heap_free(void*);

void load_hit_data(s32 idx, HitFile* hit);
void _add_hit_vert_to_buffer(Vec3f** buf, Vec3f* vert, s32* bufSize);
s32 _get_hit_vert_index_from_buffer(Vec3f** buffer, Vec3f* vert, s32* bufferSize);

void backup_map_collision_data(void) {
    CollisionData* collisionData;
    Collider* collider;
    ColliderBackupEntry* backupEntry;
    s32 i;

    collisionData = &gCollisionData;
    gCollisionDataBackup = general_heap_malloc(collisionData->numColliders * sizeof(ColliderBackupEntry));
    for (i = 0, backupEntry = gCollisionDataBackup; i < collisionData->numColliders; i++, backupEntry++) {
        collider = &collisionData->colliderList[i];
        backupEntry->flags = collider->flags;
        backupEntry->parentModelIndex = collider->parentModelIndex;
    }

    collisionData = &gZoneCollisionData;
    gCollisionDataZoneBackup = general_heap_malloc(collisionData->numColliders * sizeof(ColliderBackupEntry));
    for (i = 0, backupEntry = gCollisionDataZoneBackup; i < collisionData->numColliders; i++, backupEntry++) {
        collider = &collisionData->colliderList[i];
        backupEntry->flags = collider->flags;
        backupEntry->parentModelIndex = collider->parentModelIndex;
    }

    gZoneCollisionData.numColliders = 0;
}

void func_8005AF84(void) {
}

void func_8005AF8C(void) {
}

void initialize_collision(void) {
    gCollisionData.numColliders = 0;
    gZoneCollisionData.numColliders = 0;
    collision_heap_create();
}

void load_map_hit_asset(void) {
    u32 assetSize;
    MapSettings* map = get_current_map_settings();
    void* compressedData = load_asset_by_name(wMapHitName, &assetSize);
    HitFile* uncompressedData = heap_malloc(assetSize);

    decode_yay0(compressedData, uncompressedData);
    general_heap_free(compressedData);

    map->hitAssetCollisionOffset = uncompressedData->collisionOffset;
    map->hitAssetZoneOffset = uncompressedData->zoneOffset;

    load_hit_data(0, uncompressedData); // Colliders
    load_hit_data(1, uncompressedData); // Zones

    heap_free(uncompressedData);
}

void restore_map_collision_data(void) {
    CollisionData* collisionData;
    Collider* collider;
    ColliderBackupEntry* backupEntry;
    s32 i;

    load_map_hit_asset();

    collisionData = &gCollisionData;
    for (i = 0, backupEntry = gCollisionDataBackup; i < collisionData->numColliders; i++, backupEntry++) {
        collider = &collisionData->colliderList[i];
        collider->flags = backupEntry->flags;
        collider->parentModelIndex = backupEntry->parentModelIndex;

        if (collider->flags != -1 && collider->flags & COLLIDER_FLAG_HAS_MODEL_PARENT) {
            parent_collider_to_model(i, collider->parentModelIndex);
            update_collider_transform(i);
        }
    }

    collisionData = &gZoneCollisionData;
    for (i = 0, backupEntry = gCollisionDataZoneBackup; i < collisionData->numColliders; i++, backupEntry++) {
        collider = &collisionData->colliderList[i];
        collider->flags = backupEntry->flags;
        collider->parentModelIndex = backupEntry->parentModelIndex;
    }

    general_heap_free(gCollisionDataBackup);
    general_heap_free(gCollisionDataZoneBackup);
}

void load_battle_hit_asset(const char* hitName) {
    if (hitName == NULL) {
        gCollisionData.numColliders = 0;
    } else {
        u32 assetSize;
        MapSettings* map = get_current_map_settings();
        void* compressedData = load_asset_by_name(hitName, &assetSize);
        HitFile* uncompressedData = heap_malloc(assetSize);

        decode_yay0(compressedData, uncompressedData);
        general_heap_free(compressedData);

        map->hitAssetCollisionOffset = uncompressedData->collisionOffset;

        load_hit_data(0, uncompressedData);

        heap_free(uncompressedData);
    }
}

void load_hit_data(s32 idx, HitFile* hit) {
    s32 collisionOffset;
    MapSettings* map;
    CollisionData* collisionData;
    HitFileHeader* assetCollisionData;
    Vec3f* vertices;
    Vec3s* assetVertices;
    u32* boundingBox;
    u32* assetBoundingBox;
    Collider* collider;
    HitAssetCollider* assetCollider;
    ColliderTriangle* triangle;
    s32* trianglePacked;
    s16 numTriangles;
    s32 i,j;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    assetCollisionData = NULL;
    collisionData = NULL;

    map = get_current_map_settings();

    switch (idx) {
        case 0: // Colliders
            collisionOffset = map->hitAssetCollisionOffset;
            if (collisionOffset == 0) {
                return;
            }

            assetCollisionData = (HitFileHeader*)((void*)hit + collisionOffset);
            collisionData = &gCollisionData;
            break;
        case 1: // Zones
            collisionOffset = map->hitAssetZoneOffset;
            if (collisionOffset == 0) {
                return;
            }

            assetCollisionData = (HitFileHeader*)((void*)hit + collisionOffset);
            collisionData = &gZoneCollisionData;
            break;
    }

    assetBoundingBox = (u32*)((void*)hit + assetCollisionData->boundingBoxesOffset);
    collisionData->aabbs = collision_heap_malloc(assetCollisionData->boundingBoxesDataSize * 4);
    for (i = 0, boundingBox = (u32*)(collisionData->aabbs); i < assetCollisionData->boundingBoxesDataSize;
        assetBoundingBox++, boundingBox++, i++) {
        *boundingBox = *assetBoundingBox;
    }

    assetVertices = (Vec3s*)((void*)hit + assetCollisionData->verticesOffset);
    collisionData->vertices = collision_heap_malloc(assetCollisionData->numVertices * sizeof(Vec3f));
    for (i = 0, vertices = collisionData->vertices; i < assetCollisionData->numVertices;
        vertices++, assetVertices++, i++) {
        vertices->x = assetVertices->x;
        vertices->y = assetVertices->y;
        vertices->z = assetVertices->z;
    }

    assetCollider = (HitAssetCollider*)((void*)hit + assetCollisionData->collidersOffset);
    collider = collisionData->colliderList = collision_heap_malloc(assetCollisionData->numColliders * sizeof(Collider));
    collisionData->numColliders = assetCollisionData->numColliders;
    for (i = 0; i < assetCollisionData->numColliders; assetCollider++, collider++, i++) {
        collider->flags = 0;
        collider->nextSibling = assetCollider->nextSibling;
        collider->firstChild = assetCollider->firstChild;
        collider->numTriangles = assetCollider->numTriangles;

        numTriangles = collider->numTriangles;

        if (numTriangles) {
            collider->triangleTable = triangle = collision_heap_malloc(assetCollider->numTriangles * sizeof(ColliderTriangle));

            if (assetCollider->boundingBoxOffset < 0) {
                collider->aabb = NULL;
            } else {
                collider->aabb = (ColliderBoundingBox*)((u32*)(collisionData->aabbs) + assetCollider->boundingBoxOffset);

                if (idx == 0) {
                    collider->aabb->min.x -= 1;
                    collider->aabb->min.y -= 1;
                    collider->aabb->min.z -= 1;
                    collider->aabb->max.x += 1;
                    collider->aabb->max.y += 1;
                    collider->aabb->max.z += 1;
                    collider->flags = collider->aabb->flagsForCollider;
                }
            }

            trianglePacked = (s32*)((void*)hit + assetCollider->trianglesOffset);

            for (j = 0; j < assetCollider->numTriangles; trianglePacked++, triangle++, j++) {
                Vec3f* v1 = triangle->v1 = &collisionData->vertices[(*trianglePacked) & 0x3FF];
                Vec3f* v2 = triangle->v2 = &collisionData->vertices[(*trianglePacked >> 10) & 0x3FF];
                Vec3f* v3 = triangle->v3 = &collisionData->vertices[(*trianglePacked >> 20) & 0x3FF];
                triangle->oneSided = (*trianglePacked >> 30) & 1;

                triangle->e13.x = v3->x - v1->x;
                triangle->e13.y = v3->y - v1->y;
                triangle->e13.z = v3->z - v1->z;
                triangle->e21.x = v1->x - v2->x;
                triangle->e21.y = v1->y - v2->y;
                triangle->e21.z = v1->z - v2->z;
                triangle->e32.x = v2->x - v3->x;
                triangle->e32.y = v2->y - v3->y;
                triangle->e32.z = v2->z - v3->z;

                e13_x = triangle->e13.x;
                e13_y = triangle->e13.y;
                e13_z = triangle->e13.z;
                e21_x = triangle->e21.x;
                e21_y = triangle->e21.y;
                e21_z = triangle->e21.z;

                // cross product
                normalX = e13_y * e21_z - e13_z * e21_y;
                normalY = e13_z * e21_x - e13_x * e21_z;
                normalZ = e13_x * e21_y - e13_y * e21_x;
                coeff = SQ(normalX) + SQ(normalY) + SQ(normalZ);

                if (coeff != 0) {
                    coeff = 1.0f / sqrtf(coeff);
                } else {
                    coeff = 0.0f;
                }

                triangle->normal.x = normalX * coeff;
                triangle->normal.y = normalY * coeff;
                triangle->normal.z = normalZ * coeff;
            }
        }
    }
}

void parent_collider_to_model(s16 colliderID, s16 modelIndex) {
    Collider* collider;
    ColliderTriangle* triangle;
    s32 i;
    Vec3f** vertexBuffer;
    Vec3f** vertexPtr;
    s32 vertexBufferSize;
    Vec3f* vertexTable;
    Vec3f* vertex;

    collider = &gCollisionData.colliderList[colliderID];
    collider->parentModelIndex = modelIndex;
    collider->flags |= COLLIDER_FLAG_HAS_MODEL_PARENT;

    vertexBuffer = collision_heap_malloc(collider->numTriangles * sizeof(Vec3f));
    vertexBufferSize = 0;
    vertexPtr = vertexBuffer;

    for (i = 0, triangle = collider->triangleTable; i < collider->numTriangles; i++, triangle++) {
        _add_hit_vert_to_buffer(vertexBuffer, triangle->v1, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, triangle->v2, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, triangle->v3, &vertexBufferSize);
    }

    collider->numVertices = vertexBufferSize;
    collider->vertexTable = collision_heap_malloc(vertexBufferSize * 2 * sizeof(Vec3f));
    for (i = 0, vertexTable = collider->vertexTable; i < vertexBufferSize; vertexPtr++, vertexTable += 2, i++) {
        vertex = *vertexPtr;
        vertexTable[0].x = vertexTable[1].x = vertex->x;
        vertexTable[0].y = vertexTable[1].y = vertex->y;
        vertexTable[0].z = vertexTable[1].z = vertex->z;
    }

    vertexTable = collider->vertexTable;
    for (i = 0, triangle = collider->triangleTable; i < collider->numTriangles; triangle++, i++) {
        triangle->v1 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, triangle->v1, &vertexBufferSize) * 2];
        triangle->v2 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, triangle->v2, &vertexBufferSize) * 2];
        triangle->v3 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, triangle->v3, &vertexBufferSize) * 2];
    }

    collision_heap_free(vertexBuffer);
}

void _add_hit_vert_to_buffer(Vec3f** buf, Vec3f* vert, s32* bufSize) {
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

s32 _get_hit_vert_index_from_buffer(Vec3f** buffer, Vec3f* vert, s32* bufferSize) {
    s32 i;

    for (i = 0; i < *bufferSize; i++) {
        if (*buffer == vert) {
            break;
        }
        buffer++;
    }

    return i;
}

void update_collider_transform(s16 colliderID) {
    Collider* collider;
    struct Model* model;
    Matrix4f matrix;
    s32 i;
    Vec3f* vertexTable;
    f32 min_x, min_y, min_z, max_x, max_y, max_z;
    ColliderTriangle* triangle;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    collider = &gCollisionData.colliderList[colliderID];
    model = get_model_from_list_index(collider->parentModelIndex);

    if (model->bakedMtx == NULL) {
        copy_matrix(model->userTransformMtx, matrix);
    } else {
        guMtxL2F(matrix, (Mtx*)model->bakedMtx);
        guMtxCatF(model->userTransformMtx, matrix, matrix);
    }

    triangle = collider->triangleTable;
    vertexTable = collider->vertexTable;

    min_x = min_y = min_z = 999999.9f;
    max_x = max_y = max_z = -999999.9f;

    for (i = 0; i < collider->numVertices; vertexTable += 2, i++) {
        guMtxXFMF(matrix, vertexTable[1].x, vertexTable[1].y, vertexTable[1].z, &vertexTable[0].x, &vertexTable[0].y, &vertexTable[0].z);

        if (vertexTable[0].x < min_x)
            min_x = vertexTable[0].x;
        if (vertexTable[0].x > max_x)
            max_x = vertexTable[0].x;
        if (vertexTable[0].y < min_y)
            min_y = vertexTable[0].y;
        if (vertexTable[0].y > max_y)
            max_y = vertexTable[0].y;
        if (vertexTable[0].z < min_z)
            min_z = vertexTable[0].z;
        if (vertexTable[0].z > max_z)
            max_z = vertexTable[0].z;
    }

    collider->aabb->min.x = min_x;
    collider->aabb->min.y = min_y;
    collider->aabb->min.z = min_z;
    collider->aabb->max.x = max_x;
    collider->aabb->max.y = max_y;
    collider->aabb->max.z = max_z;

    for (i = 0; i < collider->numTriangles; triangle++, i++) {
        Vec3f* v1 = triangle->v1;
        Vec3f* v2 = triangle->v2;
        Vec3f* v3 = triangle->v3;

        triangle->e13.x = v3->x - v1->x;
        triangle->e13.y = v3->y - v1->y;
        triangle->e13.z = v3->z - v1->z;
        triangle->e21.x = v1->x - v2->x;
        triangle->e21.y = v1->y - v2->y;
        triangle->e21.z = v1->z - v2->z;
        triangle->e32.x = v2->x - v3->x;
        triangle->e32.y = v2->y - v3->y;
        triangle->e32.z = v2->z - v3->z;

        e13_x = triangle->e13.x;
        e13_y = triangle->e13.y;
        e13_z = triangle->e13.z;
        e21_x = triangle->e21.x;
        e21_y = triangle->e21.y;
        e21_z = triangle->e21.z;

        // vector product
        normalX = e13_y * e21_z - e13_z * e21_y;
        normalY = e13_z * e21_x - e13_x * e21_z;
        normalZ = e13_x * e21_y - e13_y * e21_x;
        coeff  = SQ(normalX) + SQ(normalY) + SQ(normalZ);

        if (coeff != 0) {
            coeff = 1.0f / sqrtf(coeff);
        } else {
            coeff = 0.0f;
        }

        triangle->normal.x = normalX * coeff;
        triangle->normal.y = normalY * coeff;
        triangle->normal.z = normalZ * coeff;
    }
}

s32 get_collider_flags(s32 colliderID) {
    if (colliderID & COLLISION_WITH_ENTITY_BIT) {
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

    *x = (aabb->min.x + aabb->max.x) * 0.5f;
    *y = (aabb->min.y + aabb->max.y) * 0.5f;
    *z = (aabb->min.z + aabb->max.z) * 0.5f;
}

s32 test_ray_triangle_general(ColliderTriangle* triangle, Vec3f* vertices) {
    f32 distToTrianglePlane;
    f32 cosAngle;
    Vec3f* v1;
    Vec3f* v2;
    Vec3f* v3;

    if (triangle->normal.x == 0 &&
        triangle->normal.y == 0 &&
        triangle->normal.z == 0)
        return FALSE;

    v1 = triangle->v1;
    v2 = triangle->v2;
    v3 = triangle->v3;

    distToTrianglePlane = triangle->normal.x * (gCollisionRayStartX - v1->x) +
                          triangle->normal.y * (gCollisionRayStartY - v1->y) +
                          triangle->normal.z * (gCollisionRayStartZ - v1->z);

    if (triangle->oneSided) {
        if (distToTrianglePlane < 0) {
            return FALSE;
        }

        if (triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ >= 0) {
            return FALSE;
        }

        if ((gCollisionRayStartX - v1->x) * (triangle->e13.z * gCollisionRayDirY - triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX - triangle->e13.x * gCollisionRayDirY) < 0)
        {
            return FALSE;
        }

        if ((gCollisionRayStartX - v2->x) * (triangle->e21.z * gCollisionRayDirY - triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX - triangle->e21.x * gCollisionRayDirY) < 0)
        {
            return FALSE;
        }

        if ((gCollisionRayStartX - v3->x) * (triangle->e32.z * gCollisionRayDirY - triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX - triangle->e32.x * gCollisionRayDirY) < 0)
        {
            return FALSE;
        }
    } else {
        if ((triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ) * distToTrianglePlane >= 0) {
            return FALSE;
        }

        if (((gCollisionRayStartX - v1->x) * (triangle->e13.z * gCollisionRayDirY - triangle->e13.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX - triangle->e13.x * gCollisionRayDirY)
            ) * distToTrianglePlane < 0)
        {
            return FALSE;
        }

        if (((gCollisionRayStartX - v2->x) * (triangle->e21.z * gCollisionRayDirY - triangle->e21.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX - triangle->e21.x * gCollisionRayDirY)
            ) * distToTrianglePlane < 0)
        {
            return FALSE;
        }

        if (((gCollisionRayStartX - v3->x) * (triangle->e32.z * gCollisionRayDirY - triangle->e32.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX - triangle->e32.x * gCollisionRayDirY)
            ) * distToTrianglePlane < 0)
        {
            return FALSE;
        }
    }

    cosAngle = triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle) {
        return FALSE;
    }

    gCollisionRayLength = -distToTrianglePlane  / cosAngle;

    gCollisionPointX = gCollisionRayStartX + gCollisionRayDirX * gCollisionRayLength;
    gCollisionPointY = gCollisionRayStartY + gCollisionRayDirY * gCollisionRayLength;
    gCollisionPointZ = gCollisionRayStartZ + gCollisionRayDirZ * gCollisionRayLength;

    gCollisionNormalX = triangle->normal.x;
    gCollisionNormalY = triangle->normal.y;
    gCollisionNormalZ = triangle->normal.z;

    return TRUE;
}

s32 test_ray_triangle_down(ColliderTriangle* triangle, Vec3f* vertices) {
    f32 distToTrianglePlane, cosAngle;
    Vec3f* v1;
    Vec3f* v2;
    Vec3f* v3;

    if (triangle->normal.x == 0 && triangle->normal.y == 0 && triangle->normal.z == 0) {
        return FALSE;
    }

    v1 = triangle->v1;
    v2 = triangle->v2;
    v3 = triangle->v3;

    distToTrianglePlane = triangle->normal.x * (gCollisionRayStartX - v1->x) +
                          triangle->normal.y * (gCollisionRayStartY - v1->y) +
                          triangle->normal.z * (gCollisionRayStartZ - v1->z);

    if (triangle->oneSided) {
        if (distToTrianglePlane < 0) {
            return FALSE;
        }

        if (triangle->normal.y <= 0)
            return FALSE;

        if ((gCollisionRayStartZ - v1->z) * triangle->e13.x - (gCollisionRayStartX - v1->x) * triangle->e13.z < 0) {
            return FALSE;
        }

        if ((gCollisionRayStartZ - v2->z) * triangle->e21.x - (gCollisionRayStartX - v2->x) * triangle->e21.z < 0) {
            return FALSE;
        }

        if ((gCollisionRayStartZ - v3->z) * triangle->e32.x - (gCollisionRayStartX - v3->x) * triangle->e32.z < 0) {
            return FALSE;
        }
    } else {
        if (triangle->normal.y * distToTrianglePlane <= 0) {
            return FALSE;
        }

        if (((gCollisionRayStartZ - v1->z) * triangle->e13.x - (gCollisionRayStartX - v1->x) * triangle->e13.z) * distToTrianglePlane < 0) {
            return FALSE;
        }

        if (((gCollisionRayStartZ - v2->z) * triangle->e21.x - (gCollisionRayStartX - v2->x) * triangle->e21.z) * distToTrianglePlane < 0) {
            return FALSE;
        }

        if (((gCollisionRayStartZ - v3->z) * triangle->e32.x - (gCollisionRayStartX - v3->x) * triangle->e32.z) * distToTrianglePlane < 0) {
            return FALSE;
        }
    }

    cosAngle = -triangle->normal.y;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle) {
        return FALSE;
    }

    gCollisionRayLength = -distToTrianglePlane  / cosAngle;

    gCollisionPointX = gCollisionRayStartX;
    gCollisionPointY = gCollisionRayStartY - gCollisionRayLength;
    gCollisionPointZ = gCollisionRayStartZ;

    gCollisionNormalX = triangle->normal.x;
    gCollisionNormalY = triangle->normal.y;
    gCollisionNormalZ = triangle->normal.z;

    return TRUE;
}

s32 test_ray_triangle_horizontal(ColliderTriangle* triangle, Vec3f *vertices) {
    f32 distToTrianglePlane, cosAngle;
    Vec3f* v1;
    Vec3f* v2;
    Vec3f* v3;

    if (triangle->normal.x == 0 && triangle->normal.y == 0 && triangle->normal.z == 0) {
        return FALSE;
    }

    v1 = triangle->v1;
    v2 = triangle->v2;
    v3 = triangle->v3;

    distToTrianglePlane = triangle->normal.x * (gCollisionRayStartX - v1->x) +
                          triangle->normal.y * (gCollisionRayStartY - v1->y) +
                          triangle->normal.z * (gCollisionRayStartZ - v1->z);

    if (triangle->oneSided) {
        if (distToTrianglePlane < 0) {
            return FALSE;
        }

        if (triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ >= 0) {
            return FALSE;
        }

        if ((gCollisionRayStartX - v1->x) * (-triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX) < 0)
        {
            return FALSE;
        }

        if ((gCollisionRayStartX - v2->x) * (-triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX) < 0)
        {
            return FALSE;
        }

        if ((gCollisionRayStartX - v3->x) * (-triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX) < 0)
        {
            return FALSE;
        }
    } else {
        if ((triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ) * distToTrianglePlane >= 0)
        {
            return FALSE;
        }

        if (((gCollisionRayStartX - v1->x) * (-triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
        {
            return FALSE;
        }

        if (((gCollisionRayStartX - v2->x) * (-triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
        {
            return FALSE;
        }

        if (((gCollisionRayStartX - v3->x) * (-triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
        {
            return FALSE;
        }
    }

    cosAngle = triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle) {
        return FALSE;
    }

    gCollisionRayLength = -distToTrianglePlane  / cosAngle;

    gCollisionPointX = gCollisionRayStartX + gCollisionRayDirX * gCollisionRayLength;
    gCollisionPointY = gCollisionRayStartY;
    gCollisionPointZ = gCollisionRayStartZ + gCollisionRayDirZ * gCollisionRayLength;

    gCollisionNormalX = triangle->normal.x;
    gCollisionNormalY = triangle->normal.y;
    gCollisionNormalZ = triangle->normal.z;

    return TRUE;
}

s32 test_ray_colliders(s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
                       f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    Collider* collider;
    CollisionData* collisionData;
    ColliderTriangle* triangle;
    s32 i, j;
    s32 colliderID;
    f32 min_x, min_y, min_z, max_x, max_y, max_z;

    if (dirX == 0 && dirY == 0 && dirZ == 0) {
        return 0;
    }

    collisionData = &gCollisionData;
    gCollisionRayDirX = dirX;
    gCollisionRayDirY = dirY;
    gCollisionRayDirZ = dirZ;
    gCollisionRayStartX = startX;
    gCollisionRayStartY = startY;
    gCollisionRayStartZ = startZ;
    gCollisionRayLength = *hitDepth;
    colliderID = NO_COLLIDER;

    if (dirX < 0) {
        min_x = startX + dirX * gCollisionRayLength;
        max_x = startX;
    } else {
        min_x = startX;
        max_x = startX + dirX * gCollisionRayLength;
    }

    if (dirY < 0) {
        min_y = startY + dirY * gCollisionRayLength;
        max_y = startY;
    } else {
        min_y = startY;
        max_y = startY + dirY * gCollisionRayLength;
    }

    if (dirZ < 0) {
        min_z = startZ + dirZ * gCollisionRayLength;
        max_z = startZ;
    } else {
        min_z = startZ;
        max_z = startZ + dirZ * gCollisionRayLength;
    }

    for (i = 0; i < collisionData->numColliders; i++) {
        collider = &collisionData->colliderList[i];

        if ((collider->flags & ignoreFlags) ||
            collider->numTriangles == 0     ||
            max_x < collider->aabb->min.x   ||
            min_x > collider->aabb->max.x   ||
            max_z < collider->aabb->min.z   ||
            min_z > collider->aabb->max.z   ||
            max_y < collider->aabb->min.y   ||
            min_y > collider->aabb->max.y)
        {
            continue;
        }

        triangle = collider->triangleTable;
        if (gCollisionRayDirX == 0 && gCollisionRayDirZ == 0 && gCollisionRayDirY == -1.0) {
            for (j = 0; j < collider->numTriangles; j++) {
                if (test_ray_triangle_down(triangle++, collisionData->vertices)) {
                    colliderID = i;
                }
            }
        } else if (gCollisionRayDirY == 0) {
            for (j = 0; j < collider->numTriangles; j++) {
                if (test_ray_triangle_horizontal(triangle++, collisionData->vertices)) {
                    colliderID = i;
                }
            }
        } else {
            for (j = 0; j < collider->numTriangles; j++) {
                if (test_ray_triangle_general(triangle++, collisionData->vertices)) {
                    colliderID = i;
                }
            }
        }
    }

    if (colliderID >= 0) {
        *hitX = gCollisionPointX;
        *hitY = gCollisionPointY;
        *hitZ = gCollisionPointZ;
        *hitDepth = gCollisionRayLength;
        *hitNx = gCollisionNormalX;
        *hitNy = gCollisionNormalY;
        *hitNz = gCollisionNormalZ;
        return colliderID;
    } else {
        return colliderID;
    }
}

s32 test_ray_zones(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
                f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    Collider* collider;
    CollisionData* collisionData;
    ColliderTriangle* triangle;
    s32 i, j;
    s32 colliderID;

    collisionData = &gZoneCollisionData;
    gCollisionRayDirX = dirX;
    gCollisionRayDirY = dirY;
    gCollisionRayDirZ = dirZ;
    gCollisionRayStartX = startX;
    gCollisionRayStartY = startY;
    gCollisionRayStartZ = startZ;
    gCollisionRayLength = *hitDepth;
    colliderID = NO_COLLIDER;

    for (i = 0; i < collisionData->numColliders; i++) {
        collider = &collisionData->colliderList[i];

        if (collider->flags & COLLIDER_FLAG_IGNORE_PLAYER)
            continue;

        if (collider->numTriangles == 0 || collider->aabb == NULL)
            continue;

        triangle = collider->triangleTable;
        for (j = 0; j < collider->numTriangles; j++) {
            if (test_ray_triangle_down(triangle++, collisionData->vertices)) {
                colliderID = i;
            }
        }
    }

    if (colliderID >= 0) {
        *hitX = gCollisionPointX;
        *hitY = gCollisionPointY;
        *hitZ = gCollisionPointZ;
        *hitDepth = gCollisionRayLength;
        *hitNx = gCollisionNormalX;
        *hitNy = gCollisionNormalY;
        *hitNz = gCollisionNormalZ;
        return colliderID;
    } else {
        return colliderID;
    }
}

f32 test_ray_collider_horizontal(s32 ignoreFlags, s32 colliderID, f32 x, f32 y, f32 z, f32 length, f32 yaw) {
    CollisionData* collisionData = &gCollisionData;
    f32 cosTheta;
    f32 sinTheta;
    Collider* collider;
    ColliderTriangle* triangleTable;
    s32 i;
    f32 ret;

    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);
    collider = &collisionData->colliderList[colliderID];

    gCollisionRayDirY = 0;
    gCollisionRayStartX = x;
    gCollisionRayStartY = y;
    gCollisionRayStartZ = z;
    gCollisionRayLength = length;
    gCollisionRayDirX = sinTheta;
    gCollisionRayDirZ = -cosTheta;
    ret = -1.0f;

    if (!(collider->flags & ignoreFlags) && collider->numTriangles != 0) {
        triangleTable = collider->triangleTable;

        for (i = 0; i < collider->numTriangles; i++)
            if (test_ray_triangle_horizontal(triangleTable++, collisionData->vertices))
                ret = gCollisionRayLength;
    }

    return ret;
}

enum {
    ENTITY_TEST_ANY     = 0,
    ENTITY_TEST_DOWN    = 1,
    ENTITY_TEST_LATERAL = 2,
};

s32 test_ray_entities(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
                      f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    f32 hitDepthDown, hitDepthHoriz;
    s32 type;
    s32 i, j;
    Entity* entity;
    Matrix4f tempMatrix1;
    Matrix4f tempMatrix2;
    Vec3f boxVertices[8];
    ColliderTriangle entityTriangle;
    s32 entityIndex;
    f32 h;
    f32 aabbX, aabbZ;
    s32 hasCollision;
    f32 dist, dist2;
    ColliderTriangle *triangle = &entityTriangle;

    entityIndex = -1;
    type = ENTITY_TEST_ANY;
    hitDepthDown = hitDepthHoriz = *hitDepth;

    if (dirX == 0 && dirZ == 0 && dirY < 0) {
        hitDepthHoriz = 0;
        type = ENTITY_TEST_DOWN;
    } else if (dirY == 0) {
        hitDepthDown = 0;
        type = ENTITY_TEST_LATERAL;
    }

    gCollisionRayLength = -1;
    triangle->oneSided = TRUE;
    for (i = 0; i < MAX_ENTITIES; i++) {
        entity = get_entity_by_index(i);

        if (entity == NULL || (entity->flags & (ENTITY_FLAG_SKIP_UPDATE | ENTITY_FLAG_DISABLE_COLLISION))) {
            continue;
        }

        dist = hitDepthHoriz + entity->effectiveSize;
        if (startX > entity->pos.x + dist || startX < entity->pos.x - dist) {
            continue;
        }

        if (startZ > entity->pos.z + dist || startZ < entity->pos.z - dist) {
            continue;
        }

        switch (type) {
            case ENTITY_TEST_ANY:
            case ENTITY_TEST_DOWN:
                dist = entity->pos.y;
                dist2 = hitDepthDown + entity->effectiveSize * 2;
                if (dist + dist2 < startY || startY < dist - dist2) {
                    continue;
                }
                break;
            case ENTITY_TEST_LATERAL:
                dist = entity->pos.y;
                dist2 = entity->effectiveSize * 2;
                if (dist + dist2 < startY || startY < dist - dist2) {
                    continue;
                }
                break;
        }

        aabbX = entity->aabb.x / 2;
        aabbZ = entity->aabb.z / 2;

        boxVertices[1].x = boxVertices[2].x = boxVertices[5].x = boxVertices[6].x = -aabbX;
        boxVertices[0].x = boxVertices[3].x = boxVertices[4].x = boxVertices[7].x = aabbX;
        boxVertices[0].y = boxVertices[1].y = boxVertices[2].y = boxVertices[3].y = 0;
        boxVertices[4].y = boxVertices[5].y = boxVertices[6].y = boxVertices[7].y = entity->aabb.y;
        boxVertices[0].z = boxVertices[1].z = boxVertices[4].z = boxVertices[5].z = aabbZ;
        boxVertices[2].z = boxVertices[3].z = boxVertices[6].z = boxVertices[7].z = -aabbZ;

        guMtxXFMF(entity->inverseTransformMatrix, dirX, dirY, dirZ, &gCollisionRayDirX, &gCollisionRayDirY, &gCollisionRayDirZ);
        guMtxXFMF(entity->inverseTransformMatrix, startX - entity->pos.x, startY - entity->pos.y,
                  startZ - entity->pos.z, &gCollisionRayStartX, &gCollisionRayStartY, &gCollisionRayStartZ);

        for (j = 0; j < 12; j++) {
            Vec3f* v1 = triangle->v1 = &boxVertices[gEntityColliderFaces[j].x];
            Vec3f* v2 = triangle->v2 = &boxVertices[gEntityColliderFaces[j].y];
            Vec3f* v3 = triangle->v3 = &boxVertices[gEntityColliderFaces[j].z];
            triangle->e13.x = v3->x - v1->x;
            triangle->e13.y = v3->y - v1->y;
            triangle->e13.z = v3->z - v1->z;
            triangle->e21.x = v1->x - v2->x;
            triangle->e21.y = v1->y - v2->y;
            triangle->e21.z = v1->z - v2->z;
            triangle->e32.x = v2->x - v3->x;
            triangle->e32.y = v2->y - v3->y;
            triangle->e32.z = v2->z - v3->z;
            triangle->normal.x = gEntityColliderNormals[j].x;
            triangle->normal.y = gEntityColliderNormals[j].y;
            triangle->normal.z = gEntityColliderNormals[j].z;

            if (hasCollision = test_ray_triangle_general(&entityTriangle, boxVertices)) {
                break;
            }
        }

        if (hasCollision && gCollisionRayLength < *hitDepth) {
            entityIndex = i;
            *hitDepth = gCollisionRayLength;

            switch (type) {
                case ENTITY_TEST_ANY:
                    hitDepthDown = gCollisionRayLength;
                    hitDepthHoriz = gCollisionRayLength;
                    break;
                case ENTITY_TEST_DOWN:
                    hitDepthDown = gCollisionRayLength;
                    break;
                case ENTITY_TEST_LATERAL:
                    hitDepthHoriz = gCollisionRayLength;
                    break;
            }

            guRotateF(tempMatrix1, entity->rot.x, 1.0f, 0.0f, 0.0f);
            guRotateF(tempMatrix2, entity->rot.z, 0.0f, 0.0f, 1.0f);
            guMtxCatF(tempMatrix1, tempMatrix2, tempMatrix1);
            guRotateF(tempMatrix2, entity->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(tempMatrix1, tempMatrix2, tempMatrix1);
            guTranslateF(tempMatrix2, entity->pos.x, entity->pos.y, entity->pos.z);
            guMtxCatF(tempMatrix1, tempMatrix2, tempMatrix1);
            guMtxXFMF(tempMatrix1, gCollisionPointX, gCollisionPointY, gCollisionPointZ, hitX, hitY, hitZ);

            h = 1.0f / sqrtf(SQ(gCollisionNormalX) + SQ(gCollisionNormalY) + SQ(gCollisionNormalZ));
            *hitNx = gCollisionNormalX * h;
            *hitNy = gCollisionNormalY * h;
            *hitNz = gCollisionNormalZ * h;
        }
    }

    return entityIndex;
}
