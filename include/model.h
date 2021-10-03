#ifndef _MODEL_H_
#define _MODEL_H_

#include "common.h"

typedef union ModelNodePropertyData {
    s32 s;
    f32 f;
    s32* p;
} ModelNodePropertyData;

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
    /* 0x04 */ Matrix4s* currentMatrix;
    /* 0x08 */ ModelNode* modelNode;
    /* 0x0C */ ModelGroupData* groupData;
    /* 0x10 */ s32* currentSpecialMatrix;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ Matrix4s specialMatrix;
    /* 0x58 */ Matrix4f transformMatrix;
    /* 0x98 */ Vec3f center;
    /* 0xA4 */ u8 texPannerID;
    /* 0xA5 */ u8 specialDisplayListID;
    /* 0xA6 */ s8 renderMode;
    /* 0xA7 */ char unk_A7;
    /* 0xA8 */ u8 textureID;
    /* 0xA9 */ u8 unk_A9;
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

typedef struct ModelLocalVertexCopy {
    /* 0x00 */ s32 numVertices;
    /* 0x04 */ Vtx* minVertexAddr;
    /* 0x08 */ Gfx* gfxCopy[2];
    /* 0x10 */ Vtx* vtxCopy[2];
    /* 0x18 */ s32 selector;
} ModelLocalVertexCopy; // size = 0x1C

typedef struct ModelTreeInfo {
    /* 0x00 */ u8 modelIndex;
    /* 0x01 */ s8 treeDepth;
    /* 0x02 */ s8 textureID;
    /* 0x03 */ char unk_03;
} ModelTreeInfo; // size = 0x04

typedef struct TextureHandle {
    /* 0x00 */ Gfx* gfx;
    /* 0x04 */ TileDescriptor desc;
    /* 0x34 */ s32* raster;
    /* 0x38 */ s32* palette;
    /* 0x3C */ s32* auxRaster;
    /* 0x40 */ s32* auxPalette;
} TextureHandle; // size = 0x44

typedef struct ModelBlueprint {
    /* 0x0 */ s16 flags;
    /* 0x2 */ char unk_02[0x2];
    /* 0x4 */ ModelNode* mdlNode;
    /* 0x8 */ ModelGroupData* groupData;
    /* 0xC */ Matrix4s* mtx;
} ModelBlueprint; // size = 0x10

typedef void(*ModelCustomGfxBuilderFunc)(s32 index);

typedef Gfx* ModelCustomGfxList[32];
typedef ModelCustomGfxBuilderFunc ModelCustomGfxBuilderList[32];

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

#endif
