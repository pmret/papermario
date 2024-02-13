#ifndef _MODEL_H_
#define _MODEL_H_

#include "common.h"

typedef union ModelNodePropertyData {
    s32 s;
    f32 f;
    void* p;
} ModelNodePropertyData;

// In memory this is a list of ModelNodeProperty, but due to the way it uses
// the fields (storing into the "type" field) we decided to make a struct for this
typedef struct ModelBoundingBox {
    /* 0x00 */ s32 key; // MODEL_PROP_KEY_BOUNDING_BOX
    /* 0x04 */ s32 halfSizeX;
    /* 0x08 */ f32 minX;
    /* 0x0C */ char unk_0C[0x04];
    /* 0x10 */ s32 halfSizeY;
    /* 0x14 */ f32 minY;
    /* 0x18 */ char unk_18[0x04];
    /* 0x1C */ s32 halfSizeZ;
    /* 0x20 */ f32 minZ;
    /* 0x24 */ char unk_24[0x8];
    /* 0x2C */ f32 maxX;
    /* 0x30 */ char unk_30[0x8];
    /* 0x38 */ f32 maxY;
    /* 0x3C */ char unk_3C[0x8];
    /* 0x44 */ f32 maxZ;
} ModelBoundingBox; // size = 0x48?

typedef struct ModelNodeProperty {
    /* 0x0 */ s32 key;
    /* 0x4 */ s32 dataType;
    /* 0x8 */ ModelNodePropertyData data;
} ModelNodeProperty; // size = 0xC;

typedef struct ModelGroupData {
    /* 0x00 */ Mtx* transformMatrix;
    /* 0x04 */ Lightsn* lightingGroup;
    /* 0x08 */ s32 numLights;
    /* 0x0C */ s32 numChildren;
    /* 0x10 */ struct ModelNode** childList;
} ModelGroupData; // size = 0x14

typedef struct ModelDisplayData {
    /* 0x0 */ Gfx* displayList;
    /* 0x4 */ char unk_04[0x4];
} ModelDisplayData; // size = 0x8

typedef struct ModelNode {
    /* 0x00 */ s32 type; /* 2 = model */
    /* 0x04 */ ModelDisplayData* displayData;
    /* 0x08 */ s32 numProperties;
    /* 0x0C */ ModelNodeProperty* propertyList;
    /* 0x10 */ struct ModelGroupData* groupData;
} ModelNode; // size = 0x14

typedef struct Model {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 modelID;
    /* 0x04 */ Mtx* bakedMtx; // pointer to stack-allocated copy of matrix supplied by the shape file for this model
    /* 0x08 */ ModelNode* modelNode;
    /* 0x0C */ ModelGroupData* groupData;
    /* 0x10 */ Mtx* finalMtx; // the matrix actually used while building the display list
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ Mtx savedMtx;
    /* 0x58 */ Matrix4f userTransformMtx; // provided for user code to apply an additional multiplicative transformation
    /* 0x98 */ Vec3f center;
    /* 0xA4 */ u8 texPannerID;
    /* 0xA5 */ u8 customGfxIndex;
    /* 0xA6 */ s8 renderMode;
    /* 0xA7 */ u8 matrixFreshness;
    /* 0xA8 */ u8 textureID;
    /* 0xA9 */ s8 textureVariation;
    /* 0xAA */ char unk_AA[6];
} Model; // size = 0xB0

typedef struct ModelTransformGroup {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 groupModelID;
    /* 0x04 */ Mtx* bakedMtx; // would point to copy of matrix from shape file, but seems to always be NULL.
    /* 0x08 */ ModelNode* baseModelNode;
    /* 0x0C */ Mtx* finalMtx; // the matrix actually used while building the display list
    /* 0x10 */ Mtx savedMtx;
    /* 0x50 */ Matrix4f userTransformMtx; // provided for user code to apply an additional multiplicative transformation
    /* 0x90 */ Vec3f center;
    /* 0x9C */ u8 minChildModelIndex;
    /* 0x9D */ u8 maxChildModelIndex;
    /* 0x9E */ u8 renderMode;
    /* 0x9F */ u8 matrixFreshness;
} ModelTransformGroup; // size = 0xA0

typedef Model* ModelList[MAX_MODELS];
typedef ModelTransformGroup* ModelTransformGroupList[MAX_MODEL_TRANSFORM_GROUPS];

typedef struct ModelIDList {
    u16 count;
    u16 list[VLA];
} ModelIDList;

typedef struct ModelLocalVertexCopy {
    /* 0x00 */ s32 numVertices;
    /* 0x04 */ Vtx* minVertexAddr;
    /* 0x08 */ Gfx* gfxCopy[2];
    /* 0x10 */ Vtx* vtxCopy[2];
    /* 0x18 */ s32 selector;
} ModelLocalVertexCopy; // size = 0x1C

typedef ModelLocalVertexCopy* ModelLocalVertexCopyList[16];

typedef struct ModelTreeInfo {
    /* 0x00 */ u8 modelIndex;
    /* 0x01 */ u8 treeDepth;
    /* 0x02 */ u8 textureID;
    /* 0x03 */ char unk_03;
} ModelTreeInfo; // size = 0x04

typedef struct TextureHandle {
    /* 0x00 */ Gfx* gfx;
    /* 0x04 */ TextureHeader header;
    /* 0x34 */ IMG_PTR raster;
    /* 0x38 */ PAL_PTR palette;
    /* 0x3C */ IMG_PTR auxRaster;
    /* 0x40 */ PAL_PTR auxPalette;
} TextureHandle; // size = 0x44

typedef struct ModelBlueprint {
    /* 0x0 */ s16 flags;
    /* 0x2 */ char unk_02[0x2];
    /* 0x4 */ ModelNode* mdlNode;
    /* 0x8 */ ModelGroupData* groupData;
    /* 0xC */ Mtx* mtx;
} ModelBlueprint; // size = 0x10

typedef void(*ModelCustomGfxBuilderFunc)(s32 index);

typedef Gfx* ModelCustomGfxList[32];
typedef ModelCustomGfxBuilderFunc ModelCustomGfxBuilderList[32];

typedef enum ModelPropertyKeys {
    MODEL_PROP_KEY_RENDER_MODE      = 0x5C,
    MODEL_PROP_KEY_CAMERA_DATA      = 0x5D,
    MODEL_PROP_KEY_TEXTURE_NAME     = 0x5E,
    MODEL_PROP_KEY_SPECIAL          = 0x5F,
    MODEL_PROP_KEY_GROUP_INFO       = 0x60,
    MODEL_PROP_KEY_BOUNDING_BOX     = 0x61,
    MODEL_PROP_KEY_62               = 0x62,
} ModelPropertyKeys;

typedef enum ShapeTypes {
    SHAPE_TYPE_MODEL                = 2,
    SHAPE_TYPE_GROUP                = 5,
    SHAPE_TYPE_ROOT                 = 7,
    SHAPE_TYPE_SPECIAL_GROUP        = 10,
} ShapeTypes;

typedef enum GroupTypes {
    GROUP_TYPE_0                    = 0,
    GROUP_TYPE_1                    = 1,
} GroupTypes;

typedef enum ExtraTileTypes {
    EXTRA_TILE_NONE                 = 0, // texture contains only a single tile
    EXTRA_TILE_MIPMAPS              = 1, // texture contais mipmaps
    EXTRA_TILE_AUX_SAME_AS_MAIN     = 2, // texture contains main and aux images with identical fmt and size
    EXTRA_TILE_AUX_INDEPENDENT      = 3, // texture contains main and aux images with independent fmt and size
    EXTRA_TILE_4                    = 4, // only use-case may be a mistake? unused and mostly unimplemented
} ExtraTileTypes;

#define SHAPE_SIZE_LIMIT 0x8000

typedef struct ShapeFileHeader {
    /* 0x00 */ ModelNode* root;
    /* 0x04 */ Vtx_t* vertexTable;
    /* 0x08 */ char** modelNames;
    /* 0x0C */ char** colliderNames;
    /* 0x10 */ char** zoneNames;
    /* 0x14 */ unsigned char pad_14[0xC];
} ShapeFileHeader; // size = 0x20

typedef struct ShapeFile {
    /* 0x00 */ ShapeFileHeader header;
    /* 0x20 */ u8 data[SHAPE_SIZE_LIMIT - sizeof(ShapeFileHeader)];
} ShapeFile; // size = variable

typedef ModelTreeInfo ModelTreeInfoList[0x200];

#ifndef NO_EXTERN_VARIABLES

extern ModelTreeInfoList* gCurrentModelTreeNodeInfo;
extern ModelList* gCurrentModels;

#endif

void mdl_set_depth_tint_params(u8 primR, u8 primG, u8 primB, u8 primA, u8 fogR, u8 fogG, u8 fogB, s32 fogStart, s32 fogEnd);
void mdl_set_remap_tint_params(u8 primR, u8 primG, u8 primB, u8 envR, u8 envG, u8 envB);
void mdl_get_remap_tint_params(u8* primR, u8* primG, u8* primB, u8* envR, u8* envG, u8* envB);

void init_model_data(void);
void update_model_animator(s32);
void update_model_animator_with_transform(s32 animatorID, Mtx* mtx);
void set_mdl_custom_gfx_set(Model*, s32, u32);
ModelNodeProperty* get_model_property(ModelNode* node, ModelPropertyKeys key);
void load_texture_variants(u32 romOffset, s32 textureID, s32 baseOffset, s32 size);
s32 step_model_animator(ModelAnimator* animator);
AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 treeIndex);
AnimatorNode* get_animator_node_with_id(ModelAnimator* animator, s32 id);
void animator_update_model_transforms(ModelAnimator* animator, Mtx* rootTransform);
void render_animated_model(s32 animatorID, Mtx* rootTransform);
void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node,
                                          Mtx* rootTransform);
void init_worker_list(void);
ModelAnimator* get_animator_by_index(s32 animModelID);
void reset_animator_list(void);
void delete_model_animator_node(AnimatorNode* node);
void delete_model_animator_nodes(ModelAnimator* animator);
void delete_model_animator(ModelAnimator* animator);
void render_animated_model_with_vertices(s32 animatorID, Mtx* rootTransform, s32 segment, void* baseAddr);
void appendGfx_animator(ModelAnimator* animator);
ModelAnimator* set_animator_render_callback(s32 animModelID, void* callbackArg, void (*callbackFunc)(void*));
void reload_mesh_animator_tree(ModelAnimator* animator);
s32 step_mesh_animator(ModelAnimator* animator);

void set_custom_gfx_builders(s32 customGfxIndex, ModelCustomGfxBuilderFunc pre, ModelCustomGfxBuilderFunc post);
void mdl_make_local_vertex_copy(s32 arg0, u16 treeIdx, s32);
void play_model_animation_starting_from(s32 index, s16* animPos, s32 framesToSkip);

void mdl_set_shroud_tint_params(u8 r, u8 g, u8 b, u8 a);

#endif
