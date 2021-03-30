#include "egg_missile.h"
#include "ld_addrs.h"
#include "battle/item/egg_missile/egg_missile1.png.h"
#include "battle/item/egg_missile/egg_missile2.png.h"
#include "battle/item/egg_missile/egg_missile3.png.h"
#include "battle/item/egg_missile/egg_missile4.png.h"

Vtx N(model)[] = {
    { .v = { -16, -16, 0, FALSE, 0,    0,    0, 0, 0, 255 } },
    { .v = { 15,  -16, 0, FALSE, 1024, 0,    0, 0, 0, 255 } },
    { .v = { 15,  15,  0, FALSE, 1024, 1024, 0, 0, 0, 255 } },
    { .v = { -16, 15,  0, FALSE, 0,    1024, 0, 0, 0, 255 } },
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
    gsDPLoadTLUT_pal16(0, &N(egg_missile1_pal_png)),
    gsDPLoadTextureTile_4b(&N(egg_missile1_png), G_IM_FMT_CI, N(egg_missile1_png_width), N(egg_missile1_png_height), 0, 0, N(egg_missile1_png_width) - 1, N(egg_missile1_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, &N(egg_missile2_pal_png)),
    gsDPLoadTextureTile_4b(&N(egg_missile2_png), G_IM_FMT_CI, N(egg_missile2_png_width), 0, 0, 0, N(egg_missile2_png_width) - 1, N(egg_missile2_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, &N(egg_missile3_pal_png)),
    gsDPLoadTextureTile_4b(&N(egg_missile3_png), G_IM_FMT_CI, N(egg_missile3_png_width), 0, 0, 0, N(egg_missile3_png_width) - 1, N(egg_missile3_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, &N(egg_missile4_pal_png)),
    gsDPLoadTextureTile_4b(&N(egg_missile4_png), G_IM_FMT_CI, N(egg_missile4_png_width), 0, 0, 0, N(egg_missile4_png_width) - 1, N(egg_missile4_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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

Script N(main) = SCRIPT({
    SI_VAR(10) = c ITEM_EGG_MISSILE;
    await N(UseItemWithEffect);
    UseCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    PlaySound(SOUND_THROW);
    sleep 3;
    func_802D3474(SI_VAR(10), N(modelCommandList));
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SI_VAR(1) += 42;
    SI_VAR(2) += 5;
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        SI_VAR(0) = 0;
        loop 18 {
            SI_VAR(0) += 60;
            func_802D3840(SI_VAR(10), 0, 0, SI_VAR(0));
            sleep 1;
        }
    }
    func_802D39FC(SI_VAR(10), 1.0);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 18);
    func_802D3624(SI_VAR(10));
    PlaySound(SOUND_UNKNOWN_2010);
    N(func_802A123C_71CF1C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        StartRumble(5);
        ShakeCam(1, 0, 2, 0.75);
        ShakeCam(1, 0, 5, 1.5);
        ShakeCam(1, 0, 4, 1.2001953125);
        ShakeCam(1, 0, 2, 0.4501953125);
    }
    GetItemPower(ITEM_EGG_MISSILE, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x18000202, 0, SI_VAR(0), 32);
    await N(PlayerGoHome);
});
