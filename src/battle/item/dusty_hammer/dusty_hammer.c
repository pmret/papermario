#include "dusty_hammer.h"
#include "battle/item/dusty_hammer/dusty_hammer.png.h"

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
    gsDPLoadTLUT_pal16(0, &N(dusty_hammer_pal_png)),
    gsDPLoadTextureTile_4b(&N(dusty_hammer_png), G_IM_FMT_CI, N(dusty_hammer_png_width), N(dusty_hammer_png_height), 0, 0, N(dusty_hammer_png_width) - 1, N(dusty_hammer_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x86;
    await N(UseItemWithEffect);
    UseCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THROW);
    PlaySound(SoundId_THROW);
    sleep 3;
    func_802D3474(SI_VAR(10), N(modelCommandList));
    SI_VAR(0) = 1.0;
    MultiplyByActorScale(SI_VAR(0));
    func_802D38EC(SI_VAR(10), SI_VAR(0), SI_VAR(0), SI_VAR(0));
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = 20;
    SI_VAR(4) = 42;
    SI_VAR(5) = 5;
    MultiplyVec3ByActorScale(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(1) += SI_VAR(4);
    SI_VAR(2) += SI_VAR(5);
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    InitTargetIterator();
    SetGoalToTarget(ActorID_SELF);
    GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        SI_VAR(0) = 0;
        loop 18 {
            SI_VAR(0) += 0xFFFFFFC4;
            func_802D3840(SI_VAR(10), 0, 0, SI_VAR(0));
            sleep 1;
        }
    }
    func_802D39FC(SI_VAR(10), 0.80078125);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 18);
    GetItemPower(ItemId_DUSTY_HAMMER, SI_VAR(3), SI_VAR(4));
    ApplyShrinkFromOwner(SI_VAR(3));
    ItemDamageEnemy(SI_VAR(9), 0x18000000, 0, SI_VAR(3), 32);
    SI_VAR(0) += 40;
    SI_VAR(1) += 10;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    func_802D3624(SI_VAR(10));
    await N(PlayerGoHome);
});
