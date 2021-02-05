#include "coconut.h"

s32 D_802A1A20_730380[] = {
    0xFFF0FFF0, 0x00000000, 0x00000000, 0x000000FF, 0x000FFFF0, 0x00000000, 0x04000000, 0x000000FF, 0x000F000F, 0x00000000, 0x04000400, 0x000000FF, 0xFFF0000F, 0x00000000, 0x00000400, 0x000000FF,
};

Gfx D_802A1A60_7303C0[] = {
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
    gsDPLoadTLUT_pal16(0, &D_802A1A00_730360),
    gsDPLoadTextureTile_4b(&D_802A1800_730160, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(&D_802A1A20_730380, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 D_802A1B50_7304B0[] = {
    0x00000004, 0x0000000D, 0x00000001, 0x0000003C, &D_802A1A60_7303C0, 0x00000002, 0x00000000,
};

Script D_802A1B6C_7304B0 = SCRIPT({
    SI_VAR(10) =c ItemId_COCONUT;
    await D_802A1240_72F960;
    UseCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(0, 0, 0x10016);
    PlaySound(1018);
    sleep 3;
    func_802D3474(SI_VAR(10), D_802A1B50_7304B0);
    SI_VAR(0) = 1.0;
    MultiplyByActorScale(SI_VAR(0));
    func_802D38EC(SI_VAR(10), SI_VAR(0), SI_VAR(0), SI_VAR(0));
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
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
            SI_VAR(0) += -60;
            func_802D3840(SI_VAR(10), 0, 0, SI_VAR(0));
            sleep 1;
        }
    }
    func_802D39FC(SI_VAR(10), 0.8);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 18);
    GetItemPower(ItemId_COCONUT, SI_VAR(3), SI_VAR(4));
    ApplyShrinkFromOwner(SI_VAR(3));
    ItemDamageEnemy(SI_VAR(9), 0x18000000, 0, SI_VAR(3), 32);
    SI_VAR(0) += 60;
    SI_VAR(1) += 0;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 16);
    func_802D3624(SI_VAR(10));
    await D_802A1670_72FFD0;
});

