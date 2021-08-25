#include "coconut.h"
#include "ld_addrs.h"
#include "battle/item/coconut.png.h"

#include "ItemRefund.inc.c"

#include "UseItem.inc.c"

static s32 _pad = 0;

#include "battle/item/coconut.png.inc.c"
#include "battle/item/coconut.pal.inc.c"

/// 32x32 square.
Vtx N(model)[] = {
    { .v = { -16, -16, 0, FALSE, 0,    0,    0, 0, 0, 255 } },
    { .v = { 15,  -16, 0, FALSE, 1024, 0,    0, 0, 0, 255 } },
    { .v = { 15,  15,  0, FALSE, 1024, 1024, 0, 0, 0, 255 } },
    { .v = { -16, 15,  0, FALSE, 0,    1024, 0, 0, 0, 255 } },
};

Gfx N(displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_coconut_pal),
    gsDPLoadTextureTile_4b(battle_item_coconut_png, G_IM_FMT_CI, battle_item_coconut_png_width, battle_item_coconut_png_height, 0, 0, battle_item_coconut_png_width - 1, battle_item_coconut_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D, 0x00000001, sizeof(N(displayList)) / sizeof(s32), &N(displayList), 0x00000002, 0x00000000,
};

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_COCONUT;

    await N(UseItemWithEffect);

    UseBattleCamPreset(3);
    MoveBattleCamOver(15);

    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    PlaySound(SOUND_THROW);
    sleep 3;

    CreateVirtualEntity(SI_VAR(10), N(modelCommandList));

    $x = 1.0;
    MultiplyByActorScale($x);
    SetVirtualEntityScale(SI_VAR(10), $x, $x, $x);

    GetActorPos(ACTOR_PLAYER, $x, $y, $z);
    SI_VAR(3) = 20;
    SI_VAR(4) = 42;
    SI_VAR(5) = 5;
    MultiplyVec3ByActorScale(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    $x += SI_VAR(3);
    $y += SI_VAR(4);
    $z += SI_VAR(5);
    SetVirtualEntityPosition(SI_VAR(10), $x, $y, $z);

    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, $x, $y, $z);

    spawn {
        $x = 0;
        loop 18 {
            $x += -60;
            SetVirtualEntityRotation(SI_VAR(10), 0, 0, $x);
            sleep 1;
        }
    }

    SetVirtualEntityJumpGravity(SI_VAR(10), 0.8);
    $z += 5;
    VirtualEntityJumpTo(SI_VAR(10), $x, $y, $z, 18);

    GetItemPower(ITEM_COCONUT, $damage, SI_VAR(4));
    ApplyShrinkFromOwner($damage);
    ItemDamageEnemy(SI_VAR(9), 0x18000000, 0, $damage, 32);

    // Bounce off
    $x += 60;
    $y += 0;
    VirtualEntityJumpTo(SI_VAR(10), $x, $y, $z, 16);

    DeleteVirtualEntity(SI_VAR(10));

    await N(PlayerGoHome);
});
