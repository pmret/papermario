#ifndef _MODEL_H_
#define _MODEL_H_

#include "common.h"

typedef union ModelNodePropertyData {
    s32 s;
    f32 f;
    s32* p;
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
    /* 0x04 */ Mtx* currentMatrix;
    /* 0x08 */ ModelNode* modelNode;
    /* 0x0C */ ModelGroupData* groupData;
    /* 0x10 */ s32* currentSpecialMatrix;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ Mtx specialMatrix;
    /* 0x58 */ Matrix4f transformMatrix;
    /* 0x98 */ Vec3f center;
    /* 0xA4 */ u8 texPannerID;
    /* 0xA5 */ u8 customGfxIndex;
    /* 0xA6 */ s8 renderMode;
    /* 0xA7 */ s8 matrixMode;
    /* 0xA8 */ u8 textureID;
    /* 0xA9 */ s8 textureVariation;
    /* 0xAA */ char unk_AA[6];
} Model; // size = 0xB0

typedef struct ModelTransformGroup {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 groupModelID;
    /* 0x04 */ Mtx* matrixRDP_N;
    /* 0x08 */ ModelNode* modelNode;
    /* 0x0C */ Matrix4s* transformMtx;
    /* 0x10 */ Mtx matrixA;
    /* 0x50 */ Matrix4f matrixB;
    /* 0x90 */ Vec3f center;
    /* 0x9C */ u8 minChildModelIndex;
    /* 0x9D */ u8 maxChildModelIndex;
    /* 0x9E */ u8 renderMode;
    /* 0x9F */ s8 matrixMode;
} ModelTransformGroup; // size = 0xA0

typedef Model* ModelList[MAX_MODELS];
typedef ModelTransformGroup* ModelTransformGroupList[MAX_MODEL_TRANSFORM_GROUPS];

typedef struct ModelIDList {
    u16 count;
    u16 list[0];
} ModelIDList;

typedef struct ModelLocalVertexCopy {
    /* 0x00 */ s32 numVertices;
    /* 0x04 */ Vtx* minVertexAddr;
    /* 0x08 */ Gfx* gfxCopy[2];
    /* 0x10 */ Vtx* vtxCopy[2];
    /* 0x18 */ s32 selector;
} ModelLocalVertexCopy; // size = 0x1C

typedef ModelLocalVertexCopy* ModelLocalVertexCopyList[0];

typedef struct ModelTreeInfo {
    /* 0x00 */ u8 modelIndex;
    /* 0x01 */ u8 treeDepth;
    /* 0x02 */ s8 textureID;
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
    MODEL_PROP_KEY_RENDER_MODE = 0x5C,
    MODEL_PROP_KEY_CAMERA_DATA = 0x5D,
    MODEL_PROP_KEY_TEXTURE_NAME = 0x5E,
    MODEL_PROP_KEY_SPECIAL = 0x5F,
    MODEL_PROP_KEY_GROUP_TYPE = 0x60,
    MODEL_PROP_KEY_BOUNDING_BOX = 0x61,
    MODEL_PROP_KEY_62 = 0x62,
} ModelPropertyKeys;

typedef enum ShapeTypes {
    SHAPE_TYPE_MODEL = 2,
    SHAPE_TYPE_GROUP = 5,
    SHAPE_TYPE_ROOT = 7,
    SHAPE_TYPE_SPECIAL_GROUP = 10,
} ShapeTypes;

typedef ModelTreeInfo ModelTreeInfoList[0x200];
extern ModelTreeInfoList* mdl_currentModelTreeNodeInfo;
extern ModelList* gCurrentModels;

void init_model_data(void);
void update_model_animator(s32);
void update_model_animator_with_transform(s32 animatorID, Mtx* mtx);
void set_mdl_custom_gfx_set(Model*, s32, u32);
s32 step_model_animator(ModelAnimator* animator);
AnimatorNode* get_animator_node_for_tree_index(ModelAnimator* animator, s32 treeIndex);
AnimatorNode* get_animator_node_with_id(ModelAnimator* animator, s32 id);
void animator_update_model_transforms(ModelAnimator* animator, Mtx* rootTransform);
void render_animated_model(s32 animatorID, Mtx* rootTransform);
void animator_node_update_model_transform(ModelAnimator* animator, f32 (*flipMtx)[4], AnimatorNode* node,
                                          Mtx* rootTransform);
void init_generic_entity_list(void);
ModelAnimator* get_animator_by_index(s32 animModelID);
void reset_animator_list(void);
void delete_model_animator_node(AnimatorNode* node);
void delete_model_animator_nodes(ModelAnimator* animator);
void delete_model_animator(ModelAnimator* animator);
void render_animated_model_with_vertices(s32 animatorID, Mtx* rootTransform, s32 segment, void* baseAddr);
void appendGfx_animator(ModelAnimator* animator);
ModelAnimator* set_animator_render_callback(s32 animModelID, s32 callbackArg, void (*callbackFunc)(void*));
void reload_mesh_animator_tree(ModelAnimator* animator);
s32 step_mesh_animator(ModelAnimator* animator);

void set_custom_gfx_builders(s32 customGfxIndex, ModelCustomGfxBuilderFunc pre, ModelCustomGfxBuilderFunc post);
void mdl_make_local_vertex_copy(s32 arg0, u16 treeIdx, s32);
void play_model_animation_starting_from(s32 index, s32 animPos, s32 framesToSkip);

#endif
