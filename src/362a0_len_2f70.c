#include "common.h"
#include "model.h"

extern s16 D_800D91DC;

typedef struct {
    u32 collisionOffset;
    u32 unk_08;
} HitAsset;

typedef struct {
    s32 flags;
    s16 parentModelIndex;
    s16 _pad_06;
} HitTableEntry;

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

extern HitTableEntry* D_800A4264;
extern HitTableEntry* D_800A4268;
extern CollisionData D_800D91D0;

extern f32 D_800A4230;
extern f32 D_800A4234;
extern f32 D_800A4238;
extern f32 D_800A423C;
extern f32 D_800A4240;
extern f32 D_800A4244;
extern f32 D_800A4248;
extern f32 D_800A424C;
extern f32 D_800A4250;
extern f32 D_800A4254;
extern f32 D_800A4258;
extern f32 D_800A425C;
extern f32 D_800A4260;

s32 collision_heap_create(void);
void* collision_heap_malloc(s32 size);
void collision_heap_free(void*);

void load_hit_data(s32 idx, HitAsset* hit);
void _add_hit_vert_to_buffer(Vec3f** buf, Vec3f* vert, s32* bufSize);
s32 _get_hit_vert_index_from_buffer(Vec3f** buffer, Vec3f* vert, s32* bufferSize);

void allocate_hit_tables(void)
{
    CollisionData *pColData;
    Collider *pCollider;
    HitTableEntry *ptr;
    s32 i;

    pColData = &gCollisionData;
    D_800A4264 = general_heap_malloc(pColData->numColliders * sizeof(HitTableEntry));
    for (i = 0, ptr = D_800A4264; i < pColData->numColliders; i++, ptr++)
    {
        pCollider = &pColData->colliderList[i];
        ptr->flags = pCollider->flags;
        ptr->parentModelIndex = pCollider->parentModelIndex;
    }

    pColData = &D_800D91D0;
    D_800A4268 = general_heap_malloc(pColData->numColliders * sizeof(HitTableEntry));
    for (i = 0, ptr = D_800A4268; i < pColData->numColliders; i++, ptr++)
    {
        pCollider = &pColData->colliderList[i];
        ptr->flags = pCollider->flags;
        ptr->parentModelIndex = pCollider->parentModelIndex;
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

void load_hit_asset(void) {
    u32 assetSize;
    MapConfig* map = get_current_map_header();
    void* compressedData = load_asset_by_name(&wMapHitName, &assetSize);
    HitAsset* uncompressedData = heap_malloc(assetSize);

    decode_yay0(compressedData, uncompressedData);
    general_heap_free(compressedData);

    map->collision = uncompressedData->collisionOffset;
    map->unk_08 = uncompressedData->unk_08;

    load_hit_data(0, uncompressedData);
    load_hit_data(1, uncompressedData);

    heap_free(uncompressedData);
}

void load_collision(void)
{
    CollisionData *pColData;
    Collider *pCollider;
    HitTableEntry *ptr;
    s32 i;

    load_hit_asset();

    pColData = &gCollisionData;
    for (i = 0, ptr = D_800A4264; i < pColData->numColliders; i++, ptr++)
    {
        pCollider = &pColData->colliderList[i];
        pCollider->flags = ptr->flags;
        pCollider->parentModelIndex = ptr->parentModelIndex;

        if (pCollider->flags != -1)
        {
            if ((pCollider->flags & 0x80000000) != 0)
            {
                parent_collider_to_model(i, pCollider->parentModelIndex);
                update_collider_transform(i);
            }
        }
    }

    pColData = &D_800D91D0;
    for (i = 0, ptr = D_800A4268; i < pColData->numColliders; i++, ptr++)
    {
        pCollider = &pColData->colliderList[i];
        pCollider->flags = ptr->flags;
        pCollider->parentModelIndex = ptr->parentModelIndex;
    }

    general_heap_free(D_800A4264);
    general_heap_free(D_800A4268);
}

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

        map->collision = uncompressedData->collisionOffset;

        load_hit_data(0, uncompressedData);

        heap_free(uncompressedData);
    }
}

void load_hit_data(s32 idx, HitAsset *hit) {
    s32 collisionOffset;
    MapConfig *map;
    CollisionData *pColData;
    HitAssetCollisionData *pAssetColData;
    Vec3f *pVertices;
    Vec3s *pAssetVertices;
    u32 *pBoundingBox;
    u32 *pAssetBoundingBox;
    Collider* pCollider;
    HitAssetCollider *pAssetCollider;
    ColliderTriangle *pTriangle;
    s32 *pTrianglePacked;
    s16 numTrianles;
    s32 i,j;
    Vec3f *v1, *v2, *v3;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    pAssetColData = NULL;
    pColData = NULL;

    map = get_current_map_header();

    switch (idx)
    {
        case 0:
            collisionOffset = map->collision;
            if (collisionOffset == 0)
                return;

            pAssetColData = (HitAssetCollisionData*)((void*)hit + collisionOffset);
            pColData = &gCollisionData;
            break;

        case 1:
            collisionOffset = map->unk_08;
            if (collisionOffset == 0)
                return;

            pAssetColData = (HitAssetCollisionData*)((void*)hit + collisionOffset);
            pColData = &D_800D91D0;
            break;
    }

    pAssetBoundingBox = (u32*)((void*)hit + pAssetColData->boundingBoxesOffset);;
    pColData->aabbs = collision_heap_malloc(pAssetColData->boundingBoxesDataSize * 4);
    for (i = 0, pBoundingBox = (u32*)(pColData->aabbs); i < pAssetColData->boundingBoxesDataSize; pAssetBoundingBox++, pBoundingBox++, i++)
    {
        *pBoundingBox = *pAssetBoundingBox;
    }

    pAssetVertices = (Vec3s*)((void*)hit + pAssetColData->verticesOffset);
    pColData->vertices = collision_heap_malloc(pAssetColData->numVertices * sizeof(Vec3f));
    for (i = 0, pVertices = pColData->vertices; i < pAssetColData->numVertices; pVertices++, pAssetVertices++, i++)
    {
        pVertices->x = pAssetVertices->x;
        pVertices->y = pAssetVertices->y;
        pVertices->z = pAssetVertices->z;
    }

    pAssetCollider = (HitAssetCollider*)((void*)hit + pAssetColData->collidersOffset);
    pCollider = pColData->colliderList = collision_heap_malloc(pAssetColData->numColliders * sizeof(Collider));
    pColData->numColliders = pAssetColData->numColliders;
    for (i = 0; i < pAssetColData->numColliders; pAssetCollider++, pCollider++, i++)
    {

        pCollider->flags = 0;
        pCollider->nextSibling = pAssetCollider->nextSibling;
        pCollider->firstChild = pAssetCollider->firstChild;
        pCollider->numTriangles = pAssetCollider->numTriangles;

        numTrianles = pCollider->numTriangles;

        if (numTrianles)
        {
            pCollider->triangleTable = pTriangle = collision_heap_malloc(pAssetCollider->numTriangles * sizeof(ColliderTriangle));

            if (pAssetCollider->boundingBoxOffset < 0)
            {
                pCollider->aabb = NULL;
            }
            else
            {
                pCollider->aabb = (ColliderBoundingBox*)((u32*)(pColData->aabbs) + pAssetCollider->boundingBoxOffset);

                if (idx == 0)
                {
                    pCollider->aabb->min[0] -= 1;
                    pCollider->aabb->min[1] -= 1;
                    pCollider->aabb->min[2] -= 1;
                    pCollider->aabb->max[0] += 1;
                    pCollider->aabb->max[1] += 1;
                    pCollider->aabb->max[2] += 1;
                    pCollider->flags = pCollider->aabb->flagsForCollider;
                }
            }

            pTrianglePacked = (s32*)((void*)hit + pAssetCollider->trianglesOffset);

            for (j = 0; j < pAssetCollider->numTriangles; pTrianglePacked++, pTriangle++, j++)
            {
                v1 = pTriangle->v1 = &pColData->vertices[(*pTrianglePacked) & 0x3FF];
                v2 = pTriangle->v2 = &pColData->vertices[(*pTrianglePacked >> 10) & 0x3FF];
                v3 = pTriangle->v3 = &pColData->vertices[(*pTrianglePacked >> 20) & 0x3FF];
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

void parent_collider_to_model(s16 colliderID, s16 modelIndex)
{
    Collider *collider;
    ColliderTriangle *pTriangle;
    s32 i;
    Vec3f **vertexBuffer;
    Vec3f **pVertex;
    s32 vertexBufferSize;
    Vec3f *vertexTable;
    Vec3f *vertex;

    collider = &gCollisionData.colliderList[colliderID];
    collider->parentModelIndex = modelIndex;
    collider->flags |= 0x80000000;

    vertexBuffer = collision_heap_malloc(collider->numTriangles * 0xC);
    vertexBufferSize = 0;
    pVertex = vertexBuffer;

    for (i = 0, pTriangle = collider->triangleTable; i < collider->numTriangles; i++, pTriangle++)
    {
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v1, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v2, &vertexBufferSize);
        _add_hit_vert_to_buffer(vertexBuffer, pTriangle->v3, &vertexBufferSize);
    }

    collider->numVertices = vertexBufferSize;
    collider->vertexTable = collision_heap_malloc(vertexBufferSize * 0x18);
    for (i = 0, vertexTable = collider->vertexTable; i < vertexBufferSize; pVertex++, vertexTable += 2, i++)
    {
        vertex = *pVertex;
        vertexTable->x = vertexTable[1].x = vertex->x;
        vertexTable->y = vertexTable[1].y = vertex->y;
        vertexTable->z = vertexTable[1].z = vertex->z;
    }

    vertexTable = collider->vertexTable;
    for (i = 0, pTriangle = collider->triangleTable; i < collider->numTriangles; pTriangle++, i++)
    {
        pTriangle->v1 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v1, &vertexBufferSize) * 2];
        pTriangle->v2 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v2, &vertexBufferSize) * 2];
        pTriangle->v3 = &vertexTable[_get_hit_vert_index_from_buffer(vertexBuffer, pTriangle->v3, &vertexBufferSize) * 2];
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

void update_collider_transform(s16 colliderID)
{
    Collider *collider;
    struct Model *model;
    Matrix4f matrix;
    s32 i;
    Vec3f *vertexTable;
    f32 min_x, min_y, min_z, max_x, max_y, max_z;
    ColliderTriangle *pTriangle;
    Vec3f *v1, *v2, *v3;
    f32 e13_y, e21_z, e13_z, e21_y, e21_x, e13_x, normalX, normalY, normalZ, coeff;

    collider = &gCollisionData.colliderList[colliderID];
    model = get_model_from_list_index(collider->parentModelIndex);

    if (!model->currentMatrix)
    {
        copy_matrix(model->transformMatrix, matrix);
    }
    else
    {
        guMtxL2F(matrix, (Mtx*)model->currentMatrix);
        guMtxCatF(model->transformMatrix, matrix, matrix);
    }

    pTriangle = collider->triangleTable;
    vertexTable = collider->vertexTable;

    min_x = min_y = min_z = 999999.9f;
    max_x = max_y = max_z = -999999.9f;

    for (i = 0; i < collider->numVertices; vertexTable += 2, i++)
    {
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

    collider->aabb->min[0] = min_x;
    collider->aabb->min[1] = min_y;
    collider->aabb->min[2] = min_z;
    collider->aabb->max[0] = max_x;
    collider->aabb->max[1] = max_y;
    collider->aabb->max[2] = max_z;


    for (i = 0; i < collider->numTriangles; pTriangle++, i++)
    {
        v1 = pTriangle->v1;
        v2 = pTriangle->v2;
        v3 = pTriangle->v3;

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

    *x = (aabb->min[0] + aabb->max[0]) * 0.5f;
    *y = (aabb->min[1] + aabb->max[1]) * 0.5f;
    *z = (aabb->min[2] + aabb->max[2]) * 0.5f;
}

s32 test_ray_triangle_general(ColliderTriangle *triangle)
{
    f32 temp_f20;
    f32 temp_f6_8;
    Vec3f *v1, *v2, *v3;

    if (triangle->normal.x == 0 &&
        triangle->normal.y == 0 &&
        triangle->normal.z == 0)
        return FALSE;

    v1 = triangle->v1;
    v2 = triangle->v2;
    v3 = triangle->v3;

    temp_f20 =  triangle->normal.x * (D_800A4230 - v1->x) +
                triangle->normal.y * (D_800A4234 - v1->y) +
                triangle->normal.z * (D_800A4238 - v1->z);

    if (triangle->oneSided)
    {

        if (temp_f20 < 0)
            return FALSE;

        if (triangle->normal.x * D_800A423C + triangle->normal.y * D_800A4240 + triangle->normal.z * D_800A4244 >= 0)
            return FALSE;

        if ((D_800A4230 - v1->x) * (triangle->e13.z * D_800A4240 - triangle->e13.y * D_800A4244) +
            (D_800A4234 - v1->y) * (triangle->e13.x * D_800A4244 - triangle->e13.z * D_800A423C) +
            (D_800A4238 - v1->z) * (triangle->e13.y * D_800A423C - triangle->e13.x * D_800A4240) < 0)
            return FALSE;

        if ((D_800A4230 - v2->x) * (triangle->e21.z * D_800A4240 - triangle->e21.y * D_800A4244) +
            (D_800A4234 - v2->y) * (triangle->e21.x * D_800A4244 - triangle->e21.z * D_800A423C) +
            (D_800A4238 - v2->z) * (triangle->e21.y * D_800A423C - triangle->e21.x * D_800A4240) < 0)
            return FALSE;

        if ((D_800A4230 - v3->x) * (triangle->e32.z * D_800A4240 - triangle->e32.y * D_800A4244) +
            (D_800A4234 - v3->y) * (triangle->e32.x * D_800A4244 - triangle->e32.z * D_800A423C) +
            (D_800A4238 - v3->z) * (triangle->e32.y * D_800A423C - triangle->e32.x * D_800A4240) < 0)
            return FALSE;
    }
    else
    {
        if ((triangle->normal.x * D_800A423C + triangle->normal.y * D_800A4240 + triangle->normal.z * D_800A4244) * temp_f20 >= 0)
            return FALSE;

        if (((D_800A4230 - v1->x) * (triangle->e13.z * D_800A4240 - triangle->e13.y * D_800A4244) +
            (D_800A4234 - v1->y) * (triangle->e13.x * D_800A4244 - triangle->e13.z * D_800A423C) +
            (D_800A4238 - v1->z) * (triangle->e13.y * D_800A423C - triangle->e13.x * D_800A4240)) * temp_f20 < 0)
            return FALSE;

        if (((D_800A4230 - v2->x) * (triangle->e21.z * D_800A4240 - triangle->e21.y * D_800A4244) +
            (D_800A4234 - v2->y) * (triangle->e21.x * D_800A4244 - triangle->e21.z * D_800A423C) +
            (D_800A4238 - v2->z) * (triangle->e21.y * D_800A423C - triangle->e21.x * D_800A4240)) * temp_f20 < 0)
            return FALSE;

        if (((D_800A4230 - v3->x) * (triangle->e32.z * D_800A4240 - triangle->e32.y * D_800A4244) +
            (D_800A4234 - v3->y) * (triangle->e32.x * D_800A4244 - triangle->e32.z * D_800A423C) +
            (D_800A4238 - v3->z) * (triangle->e32.y * D_800A423C - triangle->e32.x * D_800A4240)) * temp_f20 < 0)
            return FALSE;
    }

    temp_f6_8 = triangle->normal.x * D_800A423C + triangle->normal.y * D_800A4240 + triangle->normal.z * D_800A4244;
    if (D_800A4254 >= 0 && D_800A4254 <= -temp_f20 / temp_f6_8)
        return FALSE;

    D_800A4254 = -temp_f20  / temp_f6_8;

    D_800A4248 = D_800A4230 + D_800A423C * D_800A4254;
    D_800A424C = D_800A4234 + D_800A4240 * D_800A4254;
    D_800A4250 = D_800A4238 + D_800A4244 * D_800A4254;

    D_800A4258 = triangle->normal.x;
    D_800A425C = triangle->normal.y;
    D_800A4260 = triangle->normal.z;

    return TRUE;
}

INCLUDE_ASM(s32, "362a0_len_2f70", test_down_ray_triangle);

s32 test_up_ray_triangle(ColliderTriangle* triangle, Vec3f* vertices);
INCLUDE_ASM(s32, "362a0_len_2f70", test_up_ray_triangle, ColliderTriangle* triangle, f32* vertices);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_colliders, s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX,
            f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_zones, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
            f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* nx, f32* ny, f32* nz);

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
                if (test_up_ray_triangle(triangleTable++, collisionData->vertices)) {
                    ret = D_800A4254;
                }
            }
        }
    }

    return ret;
}

INCLUDE_ASM(s32, "362a0_len_2f70", test_ray_entities, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ,
            f32* hitX, f32* hitY, f32* hitZ, f32* hitDepth, f32* hitNx, f32* hitNy, f32* hitNz);

INCLUDE_ASM(s32, "362a0_len_2f70", func_8005DB00);

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
