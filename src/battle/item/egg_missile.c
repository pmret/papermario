#include "egg_missile.h"
#include "effects.h"
#include "ld_addrs.h"
#include "battle/item/egg_missile1.png.h"
#include "battle/item/egg_missile2.png.h"
#include "battle/item/egg_missile3.png.h"
#include "battle/item/egg_missile4.png.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71CF1C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    fx_smoke_ring(0, a, b, c);
    fx_explosion(0, a, b + 20, c);

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

static s32 _pad = 0;

#include "battle/item/egg_missile1.png.inc.c"
#include "battle/item/egg_missile1.pal.inc.c"
#include "battle/item/egg_missile2.png.inc.c"
#include "battle/item/egg_missile2.pal.inc.c"
#include "battle/item/egg_missile3.png.inc.c"
#include "battle/item/egg_missile3.pal.inc.c"
#include "battle/item/egg_missile4.png.inc.c"
#include "battle/item/egg_missile4.pal.inc.c"

Vtx N(model)[] = {
    { .v = {{ -16, -16, 0 }, FALSE, { 0,    0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  -16, 0 }, FALSE, { 1024, 0    }, { 0, 0, 0, 255 }}},
    { .v = {{ 15,  15,  0 }, FALSE, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    { .v = {{ -16, 15,  0 }, FALSE, { 0,    1024 }, { 0, 0, 0, 255 }}},
};

Gfx N(frame1_displayList)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile1_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile1_png, G_IM_FMT_CI, battle_item_egg_missile1_png_width, battle_item_egg_missile1_png_height, 0, 0, battle_item_egg_missile1_png_width - 1, battle_item_egg_missile1_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame2_displayList)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile2_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile2_png, G_IM_FMT_CI, battle_item_egg_missile2_png_width, 0, 0, 0, battle_item_egg_missile2_png_width - 1, battle_item_egg_missile2_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame3_displayList)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile3_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile3_png, G_IM_FMT_CI, battle_item_egg_missile3_png_width, 0, 0, 0, battle_item_egg_missile3_png_width - 1, battle_item_egg_missile3_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame4_displayList)[] = {
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
    gsDPLoadTLUT_pal16(0, battle_item_egg_missile4_pal),
    gsDPLoadTextureTile_4b(battle_item_egg_missile4_png, G_IM_FMT_CI, battle_item_egg_missile4_png_width, 0, 0, 0, battle_item_egg_missile4_png_width - 1, battle_item_egg_missile4_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D,
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame2_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000002, 0x00000000,
    0x00000004, 0x0000000D,
    0x00000001, sizeof(N(frame4_displayList)) / sizeof(s32), &N(frame4_displayList),
    0x00000002, 0x00000000,
};

EvtScript N(main) = {
    EVT_SET_CONST(LocalVar(10), 0xC8)
    EVT_EXEC_WAIT(battle_item_egg_missile_UseItemWithEffect)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, 0, 0, 65558)
    EVT_CALL(PlaySound, 1018)
    EVT_WAIT(3)
    EVT_CALL(CreateVirtualEntity, LocalVar(10), battle_item_egg_missile_modelCommandList)
    EVT_CALL(GetActorPos, 0, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 20)
    EVT_ADD(LocalVar(1), 42)
    EVT_ADD(LocalVar(2), 5)
    EVT_CALL(SetVirtualEntityPosition, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, -127)
    EVT_CALL(GetGoalPos, -127, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(18)
            EVT_ADD(LocalVar(0), 60)
            EVT_CALL(SetVirtualEntityRotation, LocalVar(10), 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetVirtualEntityJumpGravity, LocalVar(10), EVT_FIXED(1.0))
    EVT_ADD(LocalVar(2), 5)
    EVT_CALL(VirtualEntityJumpTo, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 18)
    EVT_CALL(DeleteVirtualEntity, LocalVar(10))
    EVT_CALL(PlaySound, 8208)
    EVT_CALL(battle_item_egg_missile_func_802A123C_71CF1C, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_THREAD
        EVT_CALL(StartRumble, 5)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.75))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.5))
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FIXED(1.2))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.4501953125))
    EVT_END_THREAD
    EVT_CALL(GetItemPower, 200, LocalVar(0), LocalVar(1))
    EVT_CALL(ItemDamageEnemy, LocalVar(0), 402653698, 0, LocalVar(0), 32)
    EVT_EXEC_WAIT(battle_item_egg_missile_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
