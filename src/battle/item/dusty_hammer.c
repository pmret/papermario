#include "dusty_hammer.h"
#include "ld_addrs.h"
#include "battle/item/dusty_hammer.png.h"

#include "ItemRefund.inc.c"

#include "UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/item/dusty_hammer.png.inc.c"
#include "battle/item/dusty_hammer.pal.inc.c"

Vtx N(model)[] = {
    { .v = { -16, -16, 0, FALSE, 0,    0,    0, 0, 0, 255 } },
    { .v = { 15,  -16, 0, FALSE, 1024, 0,    0, 0, 0, 255 } },
    { .v = { 15,  15,  0, FALSE, 1024, 1024, 0, 0, 0, 255 } },
    { .v = { -16, 15,  0, FALSE, 0,    1024, 0, 0, 0, 255 } },
};

Gfx N(displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_dusty_hammer_pal),
    gsDPLoadTextureTile_4b(battle_item_dusty_hammer_png, G_IM_FMT_CI, battle_item_dusty_hammer_png_width, battle_item_dusty_hammer_png_height, 0, 0, battle_item_dusty_hammer_png_width - 1, battle_item_dusty_hammer_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D, 0x00000001, sizeof(N(displayList)) / sizeof(s32), &N(displayList), 0x00000002, 0x00000000,
};

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) 0x86;
    await N(UseItemWithEffect);
    UseBattleCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    PlaySound(SOUND_THROW);
    sleep 3;
    CreateVirtualEntity(EVT_VAR(10), N(modelCommandList));
    EVT_VAR(0) = 1.0;
    MultiplyByActorScale(EVT_VAR(0));
    SetVirtualEntityScale(EVT_VAR(10), EVT_VAR(0), EVT_VAR(0), EVT_VAR(0));
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(3) = 20;
    EVT_VAR(4) = 42;
    EVT_VAR(5) = 5;
    MultiplyVec3ByActorScale(EVT_VAR(3), EVT_VAR(4), EVT_VAR(5));
    EVT_VAR(0) += EVT_VAR(3);
    EVT_VAR(1) += EVT_VAR(4);
    EVT_VAR(2) += EVT_VAR(5);
    SetVirtualEntityPosition(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    spawn {
        EVT_VAR(0) = 0;
        loop 18 {
            EVT_VAR(0) += 0xFFFFFFC4;
            SetVirtualEntityRotation(EVT_VAR(10), 0, 0, EVT_VAR(0));
            sleep 1;
        }
    }
    SetVirtualEntityJumpGravity(EVT_VAR(10), 0.80078125);
    EVT_VAR(2) += 5;
    VirtualEntityJumpTo(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 18);
    GetItemPower(ITEM_DUSTY_HAMMER, EVT_VAR(3), EVT_VAR(4));
    ApplyShrinkFromOwner(EVT_VAR(3));
    ItemDamageEnemy(EVT_VAR(9), 0x18000000, 0, EVT_VAR(3), 32);
    EVT_VAR(0) += 40;
    EVT_VAR(1) += 10;
    VirtualEntityJumpTo(EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
    DeleteVirtualEntity(EVT_VAR(10));
    await N(PlayerGoHome);
});
