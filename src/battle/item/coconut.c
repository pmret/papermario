#include "coconut.h"
#include "ld_addrs.h"
#include "battle/item/coconut.png.h"

static HudElement* D_802A1E80;

// Returns time to sleep for on $x.
ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = gBattleStatus.playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 posX;
    f32 posY = player->currentPos.y + player->size.y;
    f32 posZ;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 iconX;
        s32 iconY;
        s32 iconZ;
        s32 i;

        // 75% of the item's sell value, rounded up
        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, 0x17, 1 + 3 * i, facingAngleSign, 0);
            add_coins(1);

            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;

        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);
        D_802A1E80 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_802A1E80, iconX + 36, iconY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (player_team_is_ability_active(battleStatus->playerActor, ABILITY_REFUND) && sellValue > 0) {
        hud_element_free(D_802A1E80);
    }

    return ApiStatus_DONE2;
}

/// Provide arg `TRUE` on `SI_VAR(1)` to disable refunding.
Script N(UseItemWithEffect) = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseBattleCamPreset(69); // Nice
        sleep 10;

        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208D);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
        GetActorPos(ACTOR_PLAYER, $x, $y, $z);
        $x += 18;
        SetActorSpeed(ACTOR_PLAYER, 4.0);
        SetGoalPos(ACTOR_PLAYER, $x, $y, $z);
        PlayerRunToGoal(ACTOR_PLAYER);

        $y += 45;
        $effectY = $y;
        $effectY += 10;
        $effectY += 2;
        PlayEffect(0x33, 1, $x, $effectY, $z, 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
        SI_VAR(10) = $x;

        N(GiveRefund)();
        sleep $x;

        sleep 15;

        N(GiveRefundCleanup)();
        RemoveItemEntity(SI_VAR(10));
    } else {
        // No refund.

        GetActorPos(ACTOR_PLAYER, $x, $y, $z);
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208D);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
        sleep 4;

        $y += 45;
        $effectY = $y;
        $effectY += 10;
        $effectY += 2;
        PlayEffect(0x33, 1, $x, $effectY, $z, 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
        SI_VAR(10) = $x;

        sleep 15;
        RemoveItemEntity(SI_VAR(10));
    }
});

Script N(UseItem) = SCRIPT({
    UseBattleCamPreset(19);
    SetBattleCamTarget(-85, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(30);
    sleep 10;

    SetAnimation(ACTOR_PLAYER, 0, ANIM_GOT_ITEM);
    GetActorPos(ACTOR_PLAYER, $x, $y, $z);
    $y += 45;
    MakeItemEntity(SI_VAR(10), $x, $y, $z, 1, 0);
    SI_VAR(14) = $x;

    N(GiveRefund)();
    sleep $x;

    sleep 15;

    N(GiveRefundCleanup)();
    RemoveItemEntity(SI_VAR(14));
});

Script N(PlayerGoHome) = SCRIPT({
    UseIdleAnimation(ACTOR_PLAYER, 0);
    SetGoalToHome(ACTOR_PLAYER);
    SetActorSpeed(ACTOR_PLAYER, 8.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    PlayerRunToGoal(ACTOR_PLAYER);

    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseIdleAnimation(ACTOR_PLAYER, 1);
});

Script N(EatItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_EAT);
    sleep 45;
});

Script N(DrinkItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_DRINK);
    sleep 45;
});

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

Script N(main) = SCRIPT({
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
