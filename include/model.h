#ifndef _MODEL_H_
#define _MODEL_H_

#include "common.h"

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

typedef void(*ModelCustomGfxBuilderFunc)(s32 index);

typedef struct ModelCustomGfxBuilder {
    /* 0x00 */ ModelCustomGfxBuilderFunc pre;
    /* 0x00 */ ModelCustomGfxBuilderFunc post;
} ModelCustomGfxBuilder; // size = 0x8

typedef struct ModelCustomGfx {
    /* 0x00 */ Gfx* pre;
    /* 0x00 */ Gfx* post;
} ModelCustomGfx; // size = 0x8

typedef struct ModelBlueprint {
    /* 0x0 */ s16 flags;
    /* 0x2 */ char unk_02[0x2];
    /* 0x4 */ ModelNode* mdlNode;
    /* 0x8 */ ModelGroupData* groupData;
    /* 0xC */ Matrix4s* mtx;
} ModelBlueprint; // size = 0x10

typedef ModelCustomGfx ModelCustomGfxList[32];
typedef ModelCustomGfxBuilder ModelCustomGfxBuilderList[32];

// In memory this is a list of ModelNodeProperty, but due to the way it uses
// the fields (storing into the "type" field) we decided to make a struct for this
typedef struct ModelBoundingBox {
    /* 0x00 */ s32 key; // MODEL_PROP_KEY_BOUNDING_BOX
    /* 0x04 */ s32 centerX;
    /* 0x08 */ f32 minX;
    /* 0x0C */ char unk_0C[0x04];
    /* 0x10 */ s32 centerY;
    /* 0x14 */ f32 minY;
    /* 0x18 */ char unk_18[0x04];
    /* 0x1C */ s32 centerZ;
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
