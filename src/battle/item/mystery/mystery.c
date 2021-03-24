#include "mystery.h"
#include "battle/item/mystery/mystery.png.h"

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
    gsDPLoadTLUT_pal16(0, &N(mystery_pal_png)),
    gsDPLoadTextureTile_4b(&N(mystery_png), G_IM_FMT_CI, N(mystery_png_width), N(mystery_png_height), 0, 0, N(mystery_png_width) - 1, N(mystery_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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

s32 N(D_802A227C_72D82C)[8] = {
    0x0000008A, 0x0000008C, 0x00000080, 0x00000088,
    0x0000009A, 0x00000082, 0x00000085, 0x0000008A
};

s32 N(D_802A229C_72D84C)[8] = {
    0x0000008A, 0x0000008C, 0x00000085, 0x00000088,
    0x0000008A, 0x0000008C, 0x00000085, 0x0000008A
};

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_MYSTERY;
    await N(UseItemWithEffect);
    spawn {
        sleep 220;
        PlaySoundAtActor(ActorID_PLAYER, 1011);
    }
    PlaySoundAtActor(ActorID_PLAYER, 872);
    N(func_802A13E4_72C994)();
    sleep 2;
    if (SI_VAR(0) != ItemId_PEBBLE) {
        jump UseMystery;
        return;
    }
    func_802D3474(SI_VAR(10), N(modelCommandList));
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 150;
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetOwnerTarget(0, 0);
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
    func_802D39FC(SI_VAR(10), 0.6005859375);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 12);
    spawn {
        SI_VAR(0) += 60;
        SI_VAR(1) += 0;
        func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 16);
        func_802D3624(SI_VAR(10));
    }
    SetTargetActor(ActorID_SELF, 0);
    SetGoalToTarget(ActorID_SELF);
    GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(func_802A188C_72CE3C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetBattleFlagBits(32, 1);
    DispatchDamagePlayerEvent(1, Event_HIT);
});
