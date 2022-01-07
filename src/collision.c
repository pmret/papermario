#include "common.h"
#include "model.h"

extern s16 D_800D91DC;

typedef struct {
    u32 collisionOffset;
    u32 zoneOffset;
} HitAsset;

typedef struct {
    s32 flags;
    s16 parentModelIndex;
    s16 unk_06;
} ColliderBackupEntry;

typedef struct {
    s16 numColliders;
    s16 unk_02;
    s32 collidersOffset;
    s16 numVertices;
    s16 unk_0a;
    s32 verticesOffset;
    s16 boundingBoxesDataSize;
    s16 unk_12;
    s32 boundingBoxesOffset;
} HitAssetCollisionData;

typedef struct {
    s16 boundingBoxOffset;
    s16 nextSibling;
    s16 firstChild;
    s16 numTriangles;
    s32 trianglesOffset;
} HitAssetCollider;

extern ColliderBackupEntry* gCollisionDataBackup;
extern ColliderBackupEntry* gCollisionDataZoneBackup;
extern CollisionData gZoneCollisionData;

extern f32 gCollisionRayStartX;
extern f32 gCollisionRayStartY;
extern f32 gCollisionRayStartZ;
extern f32 gCollisionRayDirX;
extern f32 gCollisionRayDirY;
extern f32 gCollisionRayDirZ;
extern f32 gCollisionPointX;
extern f32 gCollisionPointY;
extern f32 gCollisionPointZ;
extern f32 gCollisionRayLength;
extern f32 gCollisionNormalX;
extern f32 gCollisionNormalY;
extern f32 gCollisionNormalZ;

s32 collision_heap_create(void);
void* collision_heap_malloc(s32 size);
void collision_heap_free(void*);

void load_hit_data(s32 idx, HitAsset* hit);
void _add_hit_vert_to_buffer(Vec3f** buf, Vec3f* vert, s32* bufSize);
s32 _get_hit_vert_index_from_buffer(Vec3f** buffer, Vec3f* vert, s32* bufferSize);

void backup_map_collision_data(void) {
    CollisionData* pCollisionData;
    Collider* pCollider;
    ColliderBackupEntry* pBackupEntry;
    s32 i;

    pCollisionData = &gCollisionData;
    gCollisionDataBackup = general_heap_malloc(pCollisionData->numColliders * sizeof(ColliderBackupEntry));
    for (i = 0, pBackupEntry = gCollisionDataBackup; i < pCollisionData->numColliders; i++, pBackupEntry++) {
        pCollider = &pCollisionData->colliderList[i];
        pBackupEntry->flags = pCollider->flags;
        pBackupEntry->parentModelIndex = pCollider->parentModelIndex;
    }

    pCollisionData = &gZoneCollisionData;
    gCollisionDataZoneBackup = general_heap_malloc(pCollisionData->numColliders * sizeof(ColliderBackupEntry));
    for (i = 0, pBackupEntry = gCollisionDataZoneBackup; i < pCollisionData->numColliders; i++, pBackupEntry++) {
        pCollider = &pCollisionData->colliderList[i];
        pBackupEntry->flags = pCollider->flags;
        pBackupEntry->parentModelIndex = pCollider->parentModelIndex;
    }

    D_800D91DC = 0;
}

void func_8005AF84(void) {
}

void func_8005AF8C(void) {
}

void initialize_collision(void) {
    gCollisionData.numColliders = 0;
    D_800D91DC = 0;
    collision_heap_create();
}

void load_map_hit_asset(void) {
    u32 assetSize;
    MapConfig* map = get_current_map_header();
    void* compressedData = load_asset_by_name(&wMapHitName, &assetSize);
    HitAsset* uncompressedData = heap_malloc(assetSize);

    decode_yay0(compressedData, uncompressedData);
    general_heap_free(compressedData);

    map->hitAssetCollisionOffset = uncompressedData->collisionOffset;
    map->hitAssetZoneOffset = uncompressedData->zoneOffset;

    load_hit_data(0, uncompressedData);
    load_hit_data(1, uncompressedData);

    heap_free(uncompressedData);
}

void restore_map_collision_data(void) {
    CollisionData* pCollisionData;
    Collider* pCollider;
    ColliderBackupEntry* pColliderBackupEntry;
    s32 i;

    load_map_hit_asset();

    pCollisionData = &gCollisionData;
    for (i = 0, pColliderBackupEntry = gCollisionDataBackup; i < pCollisionData->numColliders; i++, pColliderBackupEntry++) {
        pCollider = &pCollisionData->colliderList[i];
        pCollider->flags = pColliderBackupEntry->flags;
        pCollider->parentModelIndex = pColliderBackupEntry->parentModelIndex;

        if (pCollider->flags != -1 && pCollider->flags & 0x80000000) {
            parent_collider_to_model(i, pCollider->parentModelIndex);
            update_collider_transform(i);
        }
    }

    pCollisionData = &gZoneCollisionData;
    for (i = 0, pColliderBackupEntry = gCollisionDataZoneBackup; i < pCollisionData->numColliders; i++, pColliderBackupEntry++) {
        pCollider = &pCollisionData->colliderList[i];
        pCollider->flags = pColliderBackupEntry->flags;
        pCollider->parentModelIndex = pColliderBackupEntry->parentModelIndex;
    }

    general_heap_free(gCollisionDataBackup);
    general_heap_free(gCollisionDataZoneBackup);
}

void load_battle_hit_asset(const char* hitName) {
    if (hitName == NULL) {
        gCollisionData.numColliders = 0;
    } else {
        u32 assetSize;
        MapConfig* map = get_current_map_header();
        void* compressedData = load_asset_by_name(hitName, &assetSize);
        HitAsset* uncompressedData = heap_malloc(assetSize);

        decode_yay0(compressedData, uncompressedData);
        general_heap_free(compressedData);

        map->hitAssetCollisionOffset = uncompressedData->collisionOffset;

        load_hit_data(0, uncompressedData);

        heap_free(uncompressedData);
    }
}

void load_hit_data(s32 idx, HitAsset* hit) {
    s32 collisionOffset;
    MapConfig* map;
    CollisionData* pCollisionData;
    HitAssetCollisionData* pAssetCollisionData;
    Vec3f* pVertices;
    Vec3s* pAssetVertices;
    u32* pBoundingBox;
    u32* pAssetBoundingBox;
    Collider* pCollider;
    HitAssetCollider* pAssetCollider;
    ColliderTriangle* pTriangle;
    s32* pTrianglePacked;
    s16 numTriangles;
    s32 i,j;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    pAssetCollisionData = NULL;
    pCollisionData = NULL;

    map = get_current_map_header();

    switch (idx) {
        case 0:
            collisionOffset = map->hitAssetCollisionOffset;
            if (collisionOffset == 0)
                return;

            pAssetCollisionData = (HitAssetCollisionData*)((void*)hit + collisionOffset);
            pCollisionData = &gCollisionData;
            break;

        case 1:
            collisionOffset = map->hitAssetZoneOffset;
            if (collisionOffset == 0)
                return;

            pAssetCollisionData = (HitAssetCollisionData*)((void*)hit + collisionOffset);
            pCollisionData = &gZoneCollisionData;
            break;
    }

    pAssetBoundingBox = (u32*)((void*)hit + pAssetCollisionData->boundingBoxesOffset);;
    pCollisionData->aabbs = collision_heap_malloc(pAssetCollisionData->boundingBoxesDataSize * 4);
    for (i = 0, pBoundingBox = (u32*)(pCollisionData->aabbs); i < pAssetCollisionData->boundingBoxesDataSize;
         pAssetBoundingBox++, pBoundingBox++, i++) {
        *pBoundingBox = *pAssetBoundingBox;
    }

    pAssetVertices = (Vec3s*)((void*)hit + pAssetCollisionData->verticesOffset);
    pCollisionData->vertices = collision_heap_malloc(pAssetCollisionData->numVertices * sizeof(Vec3f));
    for (i = 0, pVertices = pCollisionData->vertices; i < pAssetCollisionData->numVertices;
         pVertices++, pAssetVertices++, i++) {
        pVertices->x = pAssetVertices->x;
        pVertices->y = pAssetVertices->y;
        pVertices->z = pAssetVertices->z;
    }

    pAssetCollider = (HitAssetCollider*)((void*)hit + pAssetCollisionData->collidersOffset);
    pCollider = pCollisionData->colliderList = collision_heap_malloc(pAssetCollisionData->numColliders * sizeof(Collider));
    pCollisionData->numColliders = pAssetCollisionData->numColliders;
    for (i = 0; i < pAssetCollisionData->numColliders; pAssetCollider++, pCollider++, i++) {
        pCollider->flags = 0;
        pCollider->nextSibling = pAssetCollider->nextSibling;
        pCollider->firstChild = pAssetCollider->firstChild;
        pCollider->numTriangles = pAssetCollider->numTriangles;

        numTriangles = pCollider->numTriangles;

        if (numTriangles) {
            pCollider->triangleTable = pTriangle = collision_heap_malloc(pAssetCollider->numTriangles * sizeof(ColliderTriangle));

            if (pAssetCollider->boundingBoxOffset < 0) {
                pCollider->aabb = NULL;
            } else {
                pCollider->aabb = (ColliderBoundingBox*)((u32*)(pCollisionData->aabbs) + pAssetCollider->boundingBoxOffset);

                if (idx == 0) {
                    pCollider->aabb->min.x -= 1;
                    pCollider->aabb->min.y -= 1;
                    pCollider->aabb->min.z -= 1;
                    pCollider->aabb->max.x += 1;
                    pCollider->aabb->max.y += 1;
                    pCollider->aabb->max.z += 1;
                    pCollider->flags = pCollider->aabb->flagsForCollider;
                }
            }

            pTrianglePacked = (s32*)((void*)hit + pAssetCollider->trianglesOffset);

            for (j = 0; j < pAssetCollider->numTriangles; pTrianglePacked++, pTriangle++, j++) {
                Vec3f* v1 = pTriangle->v1 = &pCollisionData->vertices[(*pTrianglePacked) & 0x3FF];
                Vec3f* v2 = pTriangle->v2 = &pCollisionData->vertices[(*pTrianglePacked >> 10) & 0x3FF];
                Vec3f* v3 = pTriangle->v3 = &pCollisionData->vertices[(*pTrianglePacked >> 20) & 0x3FF];
                pTriangle->oneSided = (*pTrianglePacked >> 30) & 1;

                pTriangle->e13.x = v3->x - v1->x;
                pTriangle->e13.y = v3->y - v1->y;
                pTriangle->e13.z = v3->z - v1->z;
                pTriangle->e21.x = v1->x - v2->x;
                pTriangle->e21.y = v1->y - v2->y;
                pTriangle->e21.z = v1->z - v2->z;
                pTriangle->e32.x = v2->x - v3->x;
                pTriangle->e32.y = v2->y - v3->y;
                pTriangle->e32.z = v2->z - v3->z;

                e13_x = pTriangle->e13.x;
                e13_y = pTriangle->e13.y;
                e13_z = pTriangle->e13.z;
                e21_x = pTriangle->e21.x;
                e21_y = pTriangle->e21.y;
                e21_z = pTriangle->e21.z;

                // vector product
                normalX = e13_y * e21_z - e13_z * e21_y;
                normalY = e13_z * e21_x - e13_x * e21_z;
                normalZ = e13_x * e21_y - e13_y * e21_x;
                coeff  = SQ(normalX) + SQ(normalY) + SQ(normalZ);

                if (coeff != 0)
                    coeff = 1.0f / sqrtf(coeff);
                else
                    coeff = 0.0f;

                pTriangle->normal.x = normalX * coeff;
                pTriangle->normal.y = normalY * coeff;
                pTriangle->normal.z = normalZ * coeff;
            }
        }
    }
}

void parent_collider_to_model(s16 colliderID, s16 modelIndex) {
    Collider* collider;
    ColliderTriangle* pTriangle;
    s32 i;
    Vec3f** vertexBuffer;
    Vec3f** pVertex;
    s32 vertexBufferSize;
    Vec3f* vertexTable;
    Vec3f* vertex;

    collider = &gCollisionData.colliderList[colliderID];
    collider->parentModelIndex = modelIndex;
    collider->flags |= 0x80000000;

    vertexBuffer = collision_heap_malloc(collider->numTriangles * 0xC);
    vertexBufferSize = 0;
    pVertex = vertexBuffer;

    for (i = 0, pTriangle = collider->triangleTable; i < collider->numTriangles; i++, pTriangle++) {
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v1, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v2, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v3, &vertexBufferSize);
    }

    collider->numVertices = vertexBufferSize;
    collider->vertexTable = collision_heap_malloc(vertexBufferSize * 0x18);
    for (i = 0, vertexTable = collider->vertexTable; i < vertexBufferSize; pVertex++, vertexTable += 2, i++) {
        vertex = *pVertex;
        vertexTable->x = vertexTable[1].x = vertex->x;
        vertexTable->y = vertexTable[1].y = vertex->y;
        vertexTable->z = vertexTable[1].z = vertex->z;
    }

    vertexTable = collider->vertexTable;
    for (i = 0, pTriangle = collider->triangleTable; i < collider->numTriangles; pTriangle++, i++) {
        pTriangle->v1 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v1, &vertexBufferSize) * 2];
        pTriangle->v2 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v2, &vertexBufferSize) * 2];
        pTriangle->v3 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v3, &vertexBufferSize) * 2];
    }

    collision_heap_free(vertexBuffer);
}

void _add_hit_vert_to_buffer(Vec3f** buf, Vec3f* vert, s32* bufSize) {
    s32 i;

    for (i = 0; i < *bufSize; i++)
        if (buf[i] == vert)
            break;

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
    ColliderTriangle* pTriangle;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    collider = &gCollisionData.colliderList[colliderID];
    model = get_model_from_list_index(collider->parentModelIndex);

    if (!model->currentMatrix) {
        copy_matrix(model->transformMatrix, matrix);
    } else {
        guMtxL2F(matrix, (Mtx*)model->currentMatrix);
        guMtxCatF(model->transformMatrix, matrix, matrix);
    }

    pTriangle = collider->triangleTable;
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

    for (i = 0; i < collider->numTriangles; pTriangle++, i++) {
        Vec3f* v1 = pTriangle->v1;
        Vec3f* v2 = pTriangle->v2;
        Vec3f* v3 = pTriangle->v3;

        pTriangle->e13.x = v3->x - v1->x;
        pTriangle->e13.y = v3->y - v1->y;
        pTriangle->e13.z = v3->z - v1->z;
        pTriangle->e21.x = v1->x - v2->x;
        pTriangle->e21.y = v1->y - v2->y;
        pTriangle->e21.z = v1->z - v2->z;
        pTriangle->e32.x = v2->x - v3->x;
        pTriangle->e32.y = v2->y - v3->y;
        pTriangle->e32.z = v2->z - v3->z;

        e13_x = pTriangle->e13.x;
        e13_y = pTriangle->e13.y;
        e13_z = pTriangle->e13.z;
        e21_x = pTriangle->e21.x;
        e21_y = pTriangle->e21.y;
        e21_z = pTriangle->e21.z;

        // vector product
        normalX = e13_y * e21_z - e13_z * e21_y;
        normalY = e13_z * e21_x - e13_x * e21_z;
        normalZ = e13_x * e21_y - e13_y * e21_x;
        coeff  = SQ(normalX) + SQ(normalY) + SQ(normalZ);

        if (coeff != 0)
            coeff = 1.0f / sqrtf(coeff);
        else
            coeff = 0.0f;

        pTriangle->normal.x = normalX * coeff;
        pTriangle->normal.y = normalY * coeff;
        pTriangle->normal.z = normalZ * coeff;
    }
}

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
        if (distToTrianglePlane < 0)
            return FALSE;

        if (triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ >= 0)
            return FALSE;

        if ((gCollisionRayStartX - v1->x) * (triangle->e13.z * gCollisionRayDirY - triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX - triangle->e13.x * gCollisionRayDirY) < 0)
            return FALSE;

        if ((gCollisionRayStartX - v2->x) * (triangle->e21.z * gCollisionRayDirY - triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX - triangle->e21.x * gCollisionRayDirY) < 0)
            return FALSE;

        if ((gCollisionRayStartX - v3->x) * (triangle->e32.z * gCollisionRayDirY - triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX - triangle->e32.x * gCollisionRayDirY) < 0)
            return FALSE;
    } else {
        if ((triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ) * distToTrianglePlane >= 0)
            return FALSE;

        if (((gCollisionRayStartX - v1->x) * (triangle->e13.z * gCollisionRayDirY - triangle->e13.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX - triangle->e13.x * gCollisionRayDirY)) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartX - v2->x) * (triangle->e21.z * gCollisionRayDirY - triangle->e21.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX - triangle->e21.x * gCollisionRayDirY)) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartX - v3->x) * (triangle->e32.z * gCollisionRayDirY - triangle->e32.y * gCollisionRayDirZ) +
             (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
             (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX - triangle->e32.x * gCollisionRayDirY)) * distToTrianglePlane < 0)
            return FALSE;
    }

    cosAngle = triangle->normal.x * gCollisionRayDirX + triangle->normal.y * gCollisionRayDirY + triangle->normal.z * gCollisionRayDirZ;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle)
        return FALSE;

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
        if (distToTrianglePlane < 0)
            return FALSE;

        if (triangle->normal.y <= 0)
            return FALSE;

        if ((gCollisionRayStartZ - v1->z) * triangle->e13.x - (gCollisionRayStartX - v1->x) * triangle->e13.z < 0)
            return FALSE;

        if ((gCollisionRayStartZ - v2->z) * triangle->e21.x - (gCollisionRayStartX - v2->x) * triangle->e21.z < 0)
            return FALSE;

        if ((gCollisionRayStartZ - v3->z) * triangle->e32.x - (gCollisionRayStartX - v3->x) * triangle->e32.z < 0)
            return FALSE;
    } else {
        if (triangle->normal.y * distToTrianglePlane <= 0)
            return FALSE;

        if (((gCollisionRayStartZ - v1->z) * triangle->e13.x - (gCollisionRayStartX - v1->x) * triangle->e13.z) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartZ - v2->z) * triangle->e21.x - (gCollisionRayStartX - v2->x) * triangle->e21.z) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartZ - v3->z) * triangle->e32.x - (gCollisionRayStartX - v3->x) * triangle->e32.z) * distToTrianglePlane < 0)
            return FALSE;
    }

    cosAngle = -triangle->normal.y;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle)
        return FALSE;

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
        if (distToTrianglePlane < 0)
            return FALSE;

        if (triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ >= 0)
            return FALSE;

        if ((gCollisionRayStartX - v1->x) * (-triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX) < 0)
            return FALSE;

        if ((gCollisionRayStartX - v2->x) * (-triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX) < 0)
            return FALSE;

        if ((gCollisionRayStartX - v3->x) * (-triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX) < 0)
            return FALSE;
    } else {
        if ((triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ) * distToTrianglePlane >= 0)
            return FALSE;

        if (((gCollisionRayStartX - v1->x) * (-triangle->e13.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v1->y) * (triangle->e13.x * gCollisionRayDirZ - triangle->e13.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v1->z) * (triangle->e13.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartX - v2->x) * (-triangle->e21.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v2->y) * (triangle->e21.x * gCollisionRayDirZ - triangle->e21.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v2->z) * (triangle->e21.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
            return FALSE;

        if (((gCollisionRayStartX - v3->x) * (-triangle->e32.y * gCollisionRayDirZ) +
            (gCollisionRayStartY - v3->y) * (triangle->e32.x * gCollisionRayDirZ - triangle->e32.z * gCollisionRayDirX) +
            (gCollisionRayStartZ - v3->z) * (triangle->e32.y * gCollisionRayDirX)) * distToTrianglePlane < 0)
            return FALSE;
    }

    cosAngle = triangle->normal.x * gCollisionRayDirX + triangle->normal.z * gCollisionRayDirZ;
    if (gCollisionRayLength >= 0 && gCollisionRayLength <= -distToTrianglePlane / cosAngle)
        return FALSE;

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
    CollisionData* pCollisionData;
    ColliderTriangle* triangle;
    s32 i, j;
    s32 colliderID;
    f32 min_x, min_y, min_z, max_x, max_y, max_z;

    if (dirX == 0 && dirY == 0 && dirZ == 0)
        return 0;

    pCollisionData = &gCollisionData;
    gCollisionRayDirX = dirX;
    gCollisionRayDirY = dirY;
    gCollisionRayDirZ = dirZ;
    gCollisionRayStartX = startX;
    gCollisionRayStartY = startY;
    gCollisionRayStartZ = startZ;
    gCollisionRayLength = *hitDepth;
    colliderID = -1;

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

    for (i = 0; i < pCollisionData->numColliders; i++) {
        collider = &pCollisionData->colliderList[i];

        if ((collider->flags & ignoreFlags) ||
            collider->numTriangles == 0     ||
            max_x < collider->aabb->min.x   ||
            min_x > collider->aabb->max.x   ||
            max_z < collider->aabb->min.z   ||
            min_z > collider->aabb->max.z   ||
            max_y < collider->aabb->min.y   ||
            min_y > collider->aabb->max.y)
                continue;

        triangle = collider->triangleTable;
        if (gCollisionRayDirX == 0 && gCollisionRayDirZ == 0 && gCollisionRayDirY == -1.0) {
            for (j = 0; j < collider->numTriangles; j++)
                if (test_ray_triangle_down(triangle++, pCollisionData->vertices))
                    colliderID = i;
        } else if (gCollisionRayDirY == 0) {
            for (j = 0; j < collider->numTriangles; j++)
                if (test_ray_triangle_horizontal(triangle++, pCollisionData->vertices))
                    colliderID = i;
        } else {
            for (j = 0; j < collider->numTriangles; j++)
                if (test_ray_triangle_general(triangle++, pCollisionData->vertices))
                    colliderID = i;
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
    } else
        return colliderID;
}

s32 test_ray_zones(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
                f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    Collider* collider;
    CollisionData* pCollisionData;
    ColliderTriangle* triangle;
    s32 i, j;
    s32 colliderID;

    pCollisionData = &gZoneCollisionData;
    gCollisionRayDirX = dirX;
    gCollisionRayDirY = dirY;
    gCollisionRayDirZ = dirZ;
    gCollisionRayStartX = startX;
    gCollisionRayStartY = startY;
    gCollisionRayStartZ = startZ;
    gCollisionRayLength = *hitDepth;
    colliderID = -1;

    for (i = 0; i < pCollisionData->numColliders; i++) {
        collider = &pCollisionData->colliderList[i];

        if (collider->flags & 0x10000)
            continue;

        if (collider->numTriangles == 0 || collider->aabb == NULL)
            continue;

        triangle = collider->triangleTable;
        for (j = 0; j < collider->numTriangles; j++)
            if (test_ray_triangle_down(triangle++, pCollisionData->vertices))
                colliderID = i;
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
    } else
        return colliderID;
}

f32 test_ray_collider_horizontal(s32 ignoreFlags, s32 colliderID, f32 x, f32 y, f32 z, f32 length, f32 yaw) {
    CollisionData* collisionData = &gCollisionData;
    f32 cosTheta;
    f32 sinTheta;
    Collider* collider;
    ColliderTriangle* triangleTable;
    s32 i;
    f32 ret;

    sin_cos_rad(yaw * TAU / 360.0f, &sinTheta, &cosTheta);
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

typedef struct {
    s16 i1;
    s16 i2;
    s16 i3;
} VertexIndexStruct;

extern VertexIndexStruct gBoxTriangulationTable[];
extern Vec3f gBoxTriangulationNormalTable[];

s32 test_ray_entities(f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
                      f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    f32 hitDepthDown, hitDepthHoriz;
    s32 type;
    s32 i, j;
    Entity* entity;
    Matrix4f tempMatrix1;
    Matrix4f tempMatrix2;
    Vec3f boxVertices[8];
    ColliderTriangle triangle;
    s32 entityIndex;
    f32 h;
    f32 aabbX, aabbZ;
    s32 hasCollision;
    f32 dist, dist2;
    ColliderTriangle *pTriangle = &triangle;

    entityIndex = -1;
    type = 0;
    hitDepthDown = hitDepthHoriz = *hitDepth;

    if (dirX == 0 && dirZ == 0 && dirY < 0) {
        hitDepthHoriz = 0;
        type = 1;
    } else if (dirY == 0) {
        hitDepthDown = 0;
        type = 2;
    }

    gCollisionRayLength = -1;
    pTriangle->oneSided = TRUE;
    for (i = 0; i < MAX_ENTITIES; i++) {
        entity = get_entity_by_index(i);

        if (entity == NULL || (entity->flags & 0x40000020))
            continue;

        dist = hitDepthHoriz + entity->effectiveSize;
        if (startX > entity->position.x + dist ||
            startX < entity->position.x - dist)
            continue;

        if (startZ > entity->position.z + dist ||
            startZ < entity->position.z - dist)
            continue;

        switch (type) {
        case 0:
        case 1:
            dist = entity->position.y;
            dist2 = hitDepthDown + entity->effectiveSize * 2;
            if (dist + dist2 < startY || startY < dist - dist2)
                continue;
            break;
        case 2:
            dist = entity->position.y;
            dist2 = entity->effectiveSize * 2;
            if (dist + dist2 < startY || startY < dist - dist2)
                continue;
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
        guMtxXFMF(entity->inverseTransformMatrix, startX - entity->position.x, startY - entity->position.y,
                  startZ - entity->position.z, &gCollisionRayStartX, &gCollisionRayStartY, &gCollisionRayStartZ);

        for (j = 0; j < 12; j++) {
            Vec3f* v1 = pTriangle->v1 = &boxVertices[gBoxTriangulationTable[j].i1];
            Vec3f* v2 = pTriangle->v2 = &boxVertices[gBoxTriangulationTable[j].i2];
            Vec3f* v3 = pTriangle->v3 = &boxVertices[gBoxTriangulationTable[j].i3];
            pTriangle->e13.x = v3->x - v1->x;
            pTriangle->e13.y = v3->y - v1->y;
            pTriangle->e13.z = v3->z - v1->z;
            pTriangle->e21.x = v1->x - v2->x;
            pTriangle->e21.y = v1->y - v2->y;
            pTriangle->e21.z = v1->z - v2->z;
            pTriangle->e32.x = v2->x - v3->x;
            pTriangle->e32.y = v2->y - v3->y;
            pTriangle->e32.z = v2->z - v3->z;
            pTriangle->normal.x = gBoxTriangulationNormalTable[j].x;
            pTriangle->normal.y = gBoxTriangulationNormalTable[j].y;
            pTriangle->normal.z = gBoxTriangulationNormalTable[j].z;

            if (hasCollision = test_ray_triangle_general(&triangle, boxVertices))
                break;
        }

        if (hasCollision && gCollisionRayLength < *hitDepth) {
            entityIndex = i;
            *hitDepth = gCollisionRayLength;

            switch (type) {
            case 0:
                hitDepthDown = gCollisionRayLength;
                hitDepthHoriz = gCollisionRayLength;
                break;
            case 1:
                hitDepthDown = gCollisionRayLength;
                break;
            case 2:
                hitDepthHoriz = gCollisionRayLength;
                break;
            }

            guRotateF(tempMatrix1, entity->rotation.x, 1.0f, 0.0f, 0.0f);
            guRotateF(tempMatrix2, entity->rotation.z, 0.0f, 0.0f, 1.0f);
            guMtxCatF(tempMatrix1, tempMatrix2, tempMatrix1);
            guRotateF(tempMatrix2, entity->rotation.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(tempMatrix1, tempMatrix2, tempMatrix1);
            guTranslateF(tempMatrix2, entity->position.x, entity->position.y, entity->position.z);
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

ApiStatus func_8005DB00(Evt* script, s32 isInitialCall) {
    Npc* npc;
    f32 targetDir, npcYaw;
    PlayerStatus* playerStatus;
    PartnerActionStatus* partnerStatus;

    npc = get_npc_unsafe(script->owner1.enemy->npcID);
    playerStatus = &gPlayerStatus;
    partnerStatus = &gPartnerActionStatus;

    if (isInitialCall)
        script->functionTemp[0] = 0;

    switch(script->functionTemp[0]) {
    case 0:
        npc->planarFlyDist = evt_get_float_variable(script, LW(0));
        npc->duration = evt_get_variable(script, LW(1));
        script->functionTemp[1] = evt_get_variable(script, LW(2));
        script->functionTemp[2] = evt_get_variable(script, LW(3)) / 2;
        npc->currentAnim.w = script->varTable[10];
        script->functionTemp[0] = 1;
        break;
    case 1:
        if (partnerStatus->actionState.b[3] != 9) {
            if (npc->duration != 0 && npc->duration != script->functionTemp[0])
                return ApiStatus_BLOCK;

            if (npc->duration == 0) {
                if (sqrtf(SQ((playerStatus->position.x - npc->pos.x)) +
                          SQ((playerStatus->position.y - npc->pos.y)) +
                          SQ((playerStatus->position.z - npc->pos.z))) <= npc->planarFlyDist) {
                    targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                    npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                    if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                        script->varTable[0] = 1;
                        return ApiStatus_DONE2;
                    }
                }
            } else {
                if (dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z) <= npc->planarFlyDist) {
                    targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                    npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                    if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                        script->varTable[0] = 1;
                        return ApiStatus_DONE2;
                    }
                }
            }
        }
        break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_8005DD54(Evt* script, s32 isInitialCall) {
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
