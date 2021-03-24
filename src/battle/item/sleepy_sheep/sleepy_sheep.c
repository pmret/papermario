#include "sleepy_sheep.h"
#include "battle/item/sleepy_sheep/sleepy_sheep1.png.h"
#include "battle/item/sleepy_sheep/sleepy_sheep2.png.h"
#include "battle/item/sleepy_sheep/sleepy_sheep3.png.h"

Vtx N(model)[] = {
    { .v = { -28,  0,  0, FALSE, 0,    1536, 0, 0, 0, 255 } },
    { .v = {  27,  0,  0, FALSE, 1792, 1536, 0, 0, 0, 255 } },
    { .v = {  27, 47,  0, FALSE, 1792,    0, 0, 0, 0, 255 } },
    { .v = { -28, 47,  0, FALSE, 0,       0, 0, 0, 0, 255 } },
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
    gsDPLoadTLUT_pal16(0, &N(sleepy_sheep1_pal_png)),
    gsDPLoadTextureTile_4b(&N(sleepy_sheep1_png), G_IM_FMT_CI, N(sleepy_sheep1_png_width), N(sleepy_sheep1_png_height), 0, 0, N(sleepy_sheep1_png_width) - 1, N(sleepy_sheep1_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, &N(sleepy_sheep2_pal_png)),
    gsDPLoadTextureTile_4b(&N(sleepy_sheep2_png), G_IM_FMT_CI, N(sleepy_sheep2_png_width), N(sleepy_sheep2_png_height), 0, 0, N(sleepy_sheep2_png_width) - 1, N(sleepy_sheep2_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, &N(sleepy_sheep3_pal_png)),
    gsDPLoadTextureTile_4b(&N(sleepy_sheep3_png), G_IM_FMT_CI, N(sleepy_sheep3_png_width), N(sleepy_sheep3_png_height), 0, 0, N(sleepy_sheep3_png_width) - 1, N(sleepy_sheep3_png_height) - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000002, 0x00000000,

    0x00000004, 0x0000000D,
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000002, 0x00000000,

    0x00000004, 0x0000000D,
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000002, 0x00000000,
};

Script N(main) = SCRIPT({
    SI_VAR(10) =c ItemId_SLEEPY_SHEEP;
    await N(UseItemWithEffect);
    UseCamPreset(19);
    SetBattleCamTarget(0xFFFFFFBD, 0xFFFFFFF1, 0xFFFFFFFB);
    SetBattleCamOffsetZ(45);
    SetBattleCamZoom(169);
    MoveBattleCamOver(50);
    spawn {
        PlaySoundAtActor(ActorID_PLAYER, SoundId_364);
        loop 7 {
            StartRumble(2);
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 1.5);
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 0.2001953125);
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 2.0);
            ShakeCam(1, 0, 2, 1.5);
            ShakeCam(1, 0, 2, 1.0);
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 0.25);
            sleep 2;
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 1.5);
            ShakeCam(1, 0, 2, 0.5);
            ShakeCam(1, 0, 2, 0.2001953125);
        }
    }
    sleep 20;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 32;
    ShowEmote(0, 2, 0xFFFFFFD3, 20, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    sleep 30;
    SetActorYaw(ActorID_PLAYER, 30);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 60);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 90);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 120);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 150);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 180);
    spawn {
        N(func_802A123C_71E88C)();
    }
    InitTargetIterator();
    spawn {
        sleep 40;
        N(func_802A1740_71ED90)();
        N(func_802A1848_71EE98)();
    }
    UseCamPreset(2);
    MoveBattleCamOver(20);
    sleep 8;
    SetJumpAnimations(ActorID_PLAYER, 0, PlayerAnim_1002B, PlayerAnim_1002B, PlayerAnim_MIDAIR);
    SetActorJumpGravity(ActorID_PLAYER, 1.80078125);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80273444(15, 0, 0);
    spawn {
        sleep 5;
        SetActorYaw(ActorID_PLAYER, 150);
        sleep 1;
        SetActorYaw(ActorID_PLAYER, 120);
        sleep 1;
        SetActorYaw(ActorID_PLAYER, 90);
        sleep 1;
        SetActorYaw(ActorID_PLAYER, 60);
        sleep 1;
        SetActorYaw(ActorID_PLAYER, 30);
        sleep 1;
        SetActorYaw(ActorID_PLAYER, 0);
    }
    sleep 40;
    func_802D3474(SI_VAR(10), N(modelCommandList));
    SI_VAR(7) = 0xFFFFFF38;
    SI_VAR(8) = 0;
    SI_VAR(9) = 0;
    func_802D36E0(SI_VAR(10), SI_VAR(7), SI_VAR(8), SI_VAR(9));
    func_802D38EC(SI_VAR(10), 0.7109375, 0.7109375, 0.7109375);
    func_802D3998(SI_VAR(10), 7.0);
    func_802D39FC(SI_VAR(10), 1.400390625);
    SetOwnerTarget(0, 0);
    SetGoalToTarget(ActorID_PLAYER);
    GetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 60;
    func_802D3A60(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    GetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlaySoundAtActor(ActorID_PLAYER, SoundId_HIT_BLOCK);
    spawn {
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_SHOCK_STILL);
        SetActorScale(ActorID_PLAYER, 1.2001953125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ActorID_PLAYER, 1.30078125, 0.80078125, 1.0);
        sleep 3;
        SetActorScale(ActorID_PLAYER, 1.2001953125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ActorID_PLAYER, 1.0, 1.0, 1.0);
    }
    PlayEffect(0x6, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 2;
    func_802D39FC(SI_VAR(10), 1.400390625);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 60;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    SI_VAR(0) += 20;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SI_VAR(0) += 10;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 5;
    spawn {
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 270;
        func_802D3A60(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
        func_802D3624(SI_VAR(10));
    }
    sleep 30;
    UseCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ItemId_SLEEPY_SHEEP, SI_VAR(0), SI_VAR(1));
    MakeStatusField(SI_VAR(0), 4096, 100, SI_VAR(0));
    func_80252B3C(SI_VAR(0), 0x50000000, SI_VAR(0), 0, 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 30;
    await N(PlayerGoHome);
});
