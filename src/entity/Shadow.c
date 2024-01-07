#include "common.h"
#include "entity.h"
#include "include_asset.h"

void entity_Shadow_init(Shadow* shadow) {
    shadow->scale.x = 0.1f;
    shadow->scale.y = 0.1f;
    shadow->scale.z = 0.1f;
}

s32 entity_can_collide_with_jumping_player(Entity* entity) {
    if ((entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_CEILING)
        && (gPlayerStatus.flags & PS_FLAG_JUMPING)
    ) {
        return TRUE;
    }
    return FALSE;
}

INCLUDE_IMG("entity/shadow/square.png", D_802E9170);
INCLUDE_IMG("entity/shadow/circle.png", D_802E91F0);
#include "entity/vtx/shadow1.vtx.inc.c"
#include "entity/vtx/shadow2.vtx.inc.c"
INCLUDE_IMG("entity/shadow/square_big.png", D_802E92F0);
INCLUDE_IMG("entity/shadow/circle_big.png", D_802E94F0);

Gfx Entity_Shadow_GfxCommon[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

Gfx Entity_Shadow_LoadTexSquare[] = {
    gsSPDisplayList(Entity_Shadow_GfxCommon),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(D_802E9170, G_IM_FMT_I, 16, 16, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx Entity_Shadow_LoadTexCircle[] = {
    gsSPDisplayList(Entity_Shadow_GfxCommon),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureTile_4b(D_802E91F0, G_IM_FMT_I, 16, 16, 0, 0, 15, 15, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPEndDisplayList(),
};

Gfx Entity_RenderSquareShadow[] = {
    gsSPDisplayList(Entity_Shadow_LoadTexSquare),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_802E92B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_RenderCircularShadow[] = {
    gsSPDisplayList(Entity_Shadow_LoadTexCircle),
    gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(D_802E9270, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

Gfx Entity_RenderNone[] = {
    gsSPEndDisplayList(),
};

EntityModelScript Entity_RenderNone_Script = {
    ems_Draw(Entity_RenderNone, 60)
    ems_Restart
    ems_End
};

//TODO split files
s32 D_802E9844_padding[] = { 0, 0, 0};

EntityModelScript Entity_CircularShadowA_Render = {
    ems_SetFlags(ENTITY_MODEL_FLAG_FOG_DISABLED)
    ems_SetRenderMode(RENDER_MODE_SHADOW)
    ems_Draw(Entity_RenderCircularShadow, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_CircularShadowB_Render = {
    ems_SetFlags(ENTITY_MODEL_FLAG_FOG_DISABLED)
    ems_SetRenderMode(RENDER_MODE_SHADOW)
    ems_Draw(Entity_RenderCircularShadow, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_SquareShadow_Render = {
    ems_SetFlags(ENTITY_MODEL_FLAG_FOG_DISABLED)
    ems_SetRenderMode(RENDER_MODE_SHADOW)
    ems_Draw(Entity_RenderSquareShadow, 60)
    ems_Restart
    ems_End
};

ShadowBlueprint CircularShadowA = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .renderCommandList = Entity_CircularShadowA_Render,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .entityType = ENTITY_TYPE_SHADOW,
    .aabbSize = { 25, 10, 25 }
};

ShadowBlueprint CircularShadowB = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .renderCommandList = Entity_CircularShadowB_Render,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .entityType = ENTITY_TYPE_SHADOW,
    .aabbSize = { 25, 10, 25 }
};

ShadowBlueprint SquareShadow = {
    .flags = ENTITY_FLAG_DISABLE_COLLISION,
    .renderCommandList = Entity_SquareShadow_Render,
    .animModelNode =  NULL,
    .onCreateCallback = entity_Shadow_init,
    .entityType = ENTITY_TYPE_SHADOW,
    .aabbSize = { 25, 10, 25 }
};
