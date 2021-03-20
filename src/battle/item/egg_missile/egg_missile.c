#include "egg_missile.h"
#include "battle/item/egg_missile/egg_missile1.png.h"
#include "battle/item/egg_missile/egg_missile2.png.h"
#include "battle/item/egg_missile/egg_missile3.png.h"
#include "battle/item/egg_missile/egg_missile4.png.h"

Vtx N(eggmissileModel)[] = {
    { .v = { -16, -16, 0, FALSE, 0,    0,    0, 0, 0, 255 } },
    { .v = { 15,  -16, 0, FALSE, 1024, 0,    0, 0, 0, 255 } },
    { .v = { 15,  15,  0, FALSE, 1024, 1024, 0, 0, 0, 255 } },
    { .v = { -16, 15,  0, FALSE, 0,    1024, 0, 0, 0, 255 } },
};

Gfx N(eggmissile1DL)[] = {
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
    gsSPVertex(N(eggmissileModel), ARRAY_COUNT(N(eggmissileModel)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(eggmissile2DL)[] = {
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
    gsSPVertex(N(eggmissileModel), ARRAY_COUNT(N(eggmissileModel)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(eggmissile3DL)[] = {
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
    gsSPVertex(N(eggmissileModel), ARRAY_COUNT(N(eggmissileModel)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(eggmissile4DL)[] = {
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
    gsSPVertex(N(eggmissileModel), ARRAY_COUNT(N(eggmissileModel)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 N(eggmissileItemModelCommandList)[] = {
    0x00000004, 0x0000000D, 
    0x00000001, 0x00000002, &N(eggmissile1DL), 
    0x00000001, 0x00000002, &N(eggmissile2DL),
    0x00000001, 0x00000002, &N(eggmissile3DL),
    0x00000002, 0x00000000,
    0x00000004, 0x0000000D,
    0x00000001, sizeof(N(eggmissile4DL)) / sizeof(s32), &N(eggmissile4DL),
    0x00000002, 0x00000000,
};

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0xC8;
    await N(UseItemWithEffect);
    UseCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THROW);
    PlaySound(1018);
    sleep 3;
    func_802D3474(SI_VAR(10), N(eggmissileItemModelCommandList));
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SI_VAR(1) += 42;
    SI_VAR(2) += 5;
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    InitTargetIterator();
    SetGoalToTarget(ActorID_SELF);
    GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
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
    PlaySound(8208);
    N(func_802A123C_71CF1C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        StartRumble(5);
        ShakeCam(1, 0, 2, 0.75);
        ShakeCam(1, 0, 5, 1.5);
        ShakeCam(1, 0, 4, 1.2001953125);
        ShakeCam(1, 0, 2, 0.4501953125);
    }
    GetItemPower(ItemId_EGG_MISSILE, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x18000202, 0, SI_VAR(0), 32);
    await N(PlayerGoHome);
});
