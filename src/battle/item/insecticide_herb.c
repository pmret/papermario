#include "insecticide_herb.h"
#include "effects.h"
#include "ld_addrs.h"
#include "battle/item/insecticide_herb.png.h"

static HudElement* D_802A21C0;

ApiStatus N(GiveRefund)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, 0x17, (i * 3) + 1, facingAngleSign, 0);
            add_coins(1);
            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        D_802A21C0 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_802A21C0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        free_hud_element(D_802A21C0);
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A123C_72A98C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target = get_actor(enemy->targetActorID);

    script->varTable[9] = target->actorType == 49;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1280_72A9D0)(Evt* script, s32 isInitialCall) {
    Actor* enemy = get_actor(script->owner1.enemyID);
    Actor* target;

    sfx_play_sound_at_position(0x231, 0, enemy->walk.goalPos.x, enemy->walk.goalPos.y, enemy->walk.goalPos.z);
    target = get_actor(enemy->targetActorID);
    dispatch_event_actor(target, 0x39);

    return ApiStatus_DONE2;
}

typedef struct N(temp) {
    char unk_00[0xC];
    EffectInstanceDataThing* unk_0C;
} N(temp);

ApiStatus N(func_802A12E0_72AA30)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 a = get_variable(script, *args++);
    f32 b = get_variable(script, *args++);
    f32 c = get_variable(script, *args++);
    struct N(temp)* effect;

    a += rand_int(20) - 10;
    b += rand_int(10) - 5;

    effect = (struct N(temp)*)playFX_6F(0, a, b, c, 1.0f, 30);

    effect->unk_0C->unk_18 = 0xF4;
    effect->unk_0C->unk_1C = 0xF4;
    effect->unk_0C->unk_20 = 0xDC;
    effect->unk_0C->unk_28 = 0xD2;
    effect->unk_0C->unk_2C = 0xD2;
    effect->unk_0C->unk_30 = 0xBE;

    return ApiStatus_DONE2;
}

EvtSource N(UseItemWithEffect) = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseBattleCamPreset(69);
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

EvtSource N(UseItem) = SCRIPT({
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

EvtSource N(PlayerGoHome) = SCRIPT({
    UseIdleAnimation(ACTOR_PLAYER, 0);
    SetGoalToHome(ACTOR_PLAYER);
    SetActorSpeed(ACTOR_PLAYER, 8.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    PlayerRunToGoal(ACTOR_PLAYER);

    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseIdleAnimation(ACTOR_PLAYER, 1);
});

EvtSource N(EatItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_EAT);
    sleep 45;
});

EvtSource N(DrinkItem) = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
            sleep 10;
        }
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_DRINK);
    sleep 45;
});

static s32 _pad = 0; // XXX

#include "battle/item/insecticide_herb.png.inc.c"
#include "battle/item/insecticide_herb.pal.inc.c"

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
    gsDPLoadTLUT_pal16(0, battle_item_insecticide_herb_pal),
    gsDPLoadTextureTile_4b(battle_item_insecticide_herb_png, G_IM_FMT_CI, battle_item_insecticide_herb_png_width, battle_item_insecticide_herb_png_height, 0, 0, battle_item_insecticide_herb_png_width - 1, battle_item_insecticide_herb_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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

EvtSource script = SCRIPT({
    SI_VAR(10) = (const) ITEM_INSECTICIDE_HERB;
    await N(UseItemWithEffect);
    UseBattleCamPreset(3);
    MoveBattleCamOver(15);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    PlaySound(SOUND_THROW);
    sleep 3;
    CreateVirtualEntity(SI_VAR(10), N(modelCommandList));
    SI_VAR(0) = 1.0;
    MultiplyByActorScale(SI_VAR(0));
    SetVirtualEntityScale(SI_VAR(10), SI_VAR(0), SI_VAR(0), SI_VAR(0));
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = 20;
    SI_VAR(4) = 42;
    SI_VAR(5) = 5;
    MultiplyVec3ByActorScale(SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) += SI_VAR(3);
    SI_VAR(1) += SI_VAR(4);
    SI_VAR(2) += SI_VAR(5);
    SetVirtualEntityPosition(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn {
        SI_VAR(0) = 0;
        loop 18 {
            SI_VAR(0) += 0xFFFFFFC4;
            SetVirtualEntityRotation(SI_VAR(10), 0, 0, SI_VAR(0));
            sleep 1;
        }
    }
    SetVirtualEntityJumpGravity(SI_VAR(10), 0.80078125);
    SI_VAR(2) += 5;
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 18);
    PlayEffect(0x7, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SI_VAR(0) -= 10;
    PlayEffect(0x7, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SI_VAR(0) += 20;
    PlayEffect(0x7, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    spawn {
        N(func_802A12E0_72AA30)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 3;
        N(func_802A12E0_72AA30)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
        sleep 3;
        N(func_802A12E0_72AA30)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    }
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    N(func_802A123C_72A98C)();
    DeleteVirtualEntity(SI_VAR(10));
    if (SI_VAR(9) == 0) {
        ItemDamageEnemy(SI_VAR(0), 0, 0, 0, 32);
    } else {
        InitTargetIterator();
        SetGoalToTarget(ACTOR_SELF);
        N(func_802A1280_72A9D0)();
    }
    await N(PlayerGoHome);
});
