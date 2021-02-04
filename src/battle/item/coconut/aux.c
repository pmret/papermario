#include "common.h"
#include "script_api/battle.h"

ApiStatus func_802A1000_72F720(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802A11D4_72F8F4(ScriptInstance* script, s32 isInitialCall);

MenuIcon* D_802A1E80;
void* D_80108A64; // an image

#ifdef NON_MATCHING
ApiStatus func_802A1000_72F720(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus;
    Actor* player;
    Actor* player2;
    s32 sellValue;
    s32 numCoins;
    s32 pickupDelay;
    f32 facingAngleSign;
    s32 i;

    f32 posX;
    f32 posY;
    f32 posZ;

    s32 iconX;
    s32 iconY;
    s32 iconZ;

    i = 0;
    facingAngleSign = 0.0f;

    battleStatus = BATTLE_STATUS;
    sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    posY = battleStatus->playerActor->currentPos.y + battleStatus->playerActor->size.y;

    player = PLAYER_ACTOR;

    // If Refund is equipped, the player gets
    if (heroes_is_ability_active(battleStatus->playerActor, Ability_REFUND)) {
        //player2 = player;

        if (sellValue > 0) {
            // 75% of the item's sell value, rounded up
            sellValue = (sellValue * 75 + 99) / 100;

            pickupDelay = 1;
                player2 = player;

            while (i < sellValue) {
                posX = player2->currentPos.x;
                posZ = player2->currentPos.z;

                make_item_entity(ItemId_COIN, posX, posY, posZ, 0x17, pickupDelay, facingAngleSign, 0);
                add_coins(1);

                pickupDelay += 3;
                facingAngleSign += 30.0f;
                i++;
            }

            i = (i * 3) + 30;

                //player2 = player;
            posX = player2->currentPos.x;
            posY = player2->currentPos.y;
            posZ = player2->currentPos.z;

            get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconX, &iconY, &iconZ);
            D_802A1E80 = create_icon(&D_80108A64);
            set_icon_render_pos(D_802A1E80, iconX + 36, iconY - 63);
        }
    }

    script->varTable[0] = i;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/coconut", func_802A1000_72F720, ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus func_802A11D4_72F8F4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(battleStatus->playerActor, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1E80);
    }

    return ApiStatus_DONE2;
}

Script D_802A1240_72F960 = SCRIPT({
    if (SI_VAR(1) == 0) {
        UseCamPreset(69);
        sleep 10;
        PlaySoundAtActor(0, 8333);
        SetAnimation(0, 0, 0x1001F);
        GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 18;
        SetActorSpeed(0, 4.0);
        SetGoalPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlayerRunToGoal(0);
        SI_VAR(1) += 45;
        SI_VAR(3) = SI_VAR(1);
        SI_VAR(3) += 10;
        SI_VAR(3) += 2;
        PlayEffect(51, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(10) = SI_VAR(0);
        func_802A1000_72F720();
        sleep SI_VAR(0);
        sleep 15;
        func_802A11D4_72F8F4();
        RemoveItemEntity(SI_VAR(10));
    } else {
        GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlaySoundAtActor(0, 8333);
        SetAnimation(0, 0, 0x1001F);
        sleep 4;
        SI_VAR(1) += 45;
        SI_VAR(3) = SI_VAR(1);
        SI_VAR(3) += 10;
        SI_VAR(3) += 2;
        PlayEffect(51, 1, SI_VAR(0), SI_VAR(3), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
        MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(10) = SI_VAR(0);
        sleep 15;
        RemoveItemEntity(SI_VAR(10));
    }
});

Script D_802A1544_72FC64 = SCRIPT({
    UseCamPreset(19);
    SetBattleCamTarget(0xFFFFFFAB, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(30);
    sleep 10;
    SetAnimation(0, 0, 0x1001F);
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 45;
    MakeItemEntity(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
    SI_VAR(14) = SI_VAR(0);
    func_802A1000_72F720();
    sleep SI_VAR(0);
    sleep 15;
    func_802A11D4_72F8F4();
    RemoveItemEntity(SI_VAR(14));
});

Script D_802A1670_72FFD0 = SCRIPT({
    UseIdleAnimation(0, 0);
    SetGoalToHome(0);
    SetActorSpeed(0, 8.0);
    SetAnimation(0, 0, PlayerAnim_RUNNING);
    PlayerRunToGoal(0);
    SetAnimation(0, 0, 0x10002);
    UseIdleAnimation(0, 1);
});

Script Script_802A170C = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 0x2095);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x1001C);
    sleep 45;
});

Script D_802A1784_7300E4 = SCRIPT({
    spawn {
        loop 4 {
            PlaySoundAtActor(0, 0x2095);
            sleep 10;
        }
    }
    SetAnimation(0, 0, 0x10025);
    sleep 45;
});

static s32 pad = 0;

// TODO: coconut.png
s32 D_802A1800_730160[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000088, 0x88000000, 0x00000000, 0x00000000, 0x00008888, 0x88880000, 0x00000000, 0x00000000, 0x00088745, 0x25788000, 0x00000000, 0x00000000, 0x00887252, 0x22378800, 0x00000000, 0x00000000, 0x08872521, 0x25237880, 0x00000000, 0x00000000, 0x08823512, 0x12523880, 0x00000000, 0x00000000, 0x88725225, 0x22523788, 0x00000000, 0x00000000, 0x88325235, 0x22532388, 0x00000000, 0x00000008, 0x87322252, 0x22323378, 0x80000000, 0x00000008, 0x85352252, 0x23237358, 0x80000000, 0x00000008, 0x83522252, 0x22323738, 0x80000000, 0x00000008, 0x82722255, 0x22523738, 0x80000000, 0x00000008, 0x84732233, 0x32733738, 0x80000000, 0x00000008, 0x85472733, 0x33734558, 0x80000000, 0x00000008, 0x87433743, 0x43734478, 0x80000000, 0x00000000, 0x88543744, 0x37444588, 0x00000000, 0x00000000, 0x88854474, 0x47445888, 0x00000000, 0x00000000, 0x08888757, 0x55788880, 0x00000000, 0x00000000, 0x00888888, 0x88888800, 0x00000000, 0x00000000, 0x00008888, 0x88880000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

s32 D_802A1A00_730360[] = {
    0x294AED8F, 0xD48BC409, 0xABC78B49, 0x83077A85, 0x39010001, 0x00010001, 0x00010001, 0x00010001,
};

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

