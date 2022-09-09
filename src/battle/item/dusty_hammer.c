#include "dusty_hammer.h"
#include "ld_addrs.h"
#include "battle/item/dusty_hammer.png.h"

#include "ItemRefund.inc.c"

#include "UseItem.inc.c"

static s32 _pad = 0; // XXX

#include "battle/item/dusty_hammer.png.inc.c"
#include "battle/item/dusty_hammer.pal.inc.c"

Vtx N(model)[] = {
    { .v = {{ -16, -16, 0 }, FALSE, { 0,    0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  -16, 0 }, FALSE, { 1024, 0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  15,  0 }, FALSE, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    { .v = {{ -16, 15,  0 }, FALSE, { 0,    1024 }, { 0, 0, 0, 255 }}},
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

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0x00000086)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THROW)
    EVT_CALL(PlaySound, SOUND_THROW)
    EVT_WAIT(3)
    EVT_CALL(CreateVirtualEntity, LocalVar(10), EVT_PTR(N(modelCommandList)))
    EVT_SETF(LocalVar(0), EVT_FIXED(1.0))
    EVT_CALL(MultiplyByActorScale, LocalVar(0))
    EVT_CALL(SetVirtualEntityScale, LocalVar(10), LocalVar(0), LocalVar(0), LocalVar(0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(3), 20)
    EVT_SET(LocalVar(4), 42)
    EVT_SET(LocalVar(5), 5)
    EVT_CALL(MultiplyVec3ByActorScale, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_ADD(LocalVar(0), LocalVar(3))
    EVT_ADD(LocalVar(1), LocalVar(4))
    EVT_ADD(LocalVar(2), LocalVar(5))
    EVT_CALL(SetVirtualEntityPosition, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(18)
            EVT_ADD(LocalVar(0), -60)
            EVT_CALL(SetVirtualEntityRotation, LocalVar(10), 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetVirtualEntityJumpGravity, LocalVar(10), EVT_FIXED(0.8))
    EVT_ADD(LocalVar(2), 5)
    EVT_CALL(VirtualEntityJumpTo, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 18)
    EVT_CALL(GetItemPower, ITEM_DUSTY_HAMMER, LocalVar(3), LocalVar(4))
    EVT_CALL(ApplyShrinkFromOwner, LocalVar(3))
    EVT_CALL(ItemDamageEnemy, LocalVar(9), 402653184, 0, LocalVar(3), 32)
    EVT_ADD(LocalVar(0), 40)
    EVT_ADD(LocalVar(1), 10)
    EVT_CALL(VirtualEntityJumpTo, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 10)
    EVT_CALL(DeleteVirtualEntity, LocalVar(10))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
