#include "sleepy_sheep.h"
#include "ld_addrs.h"
#include "battle/item/sleepy_sheep1.png.h"
#include "battle/item/sleepy_sheep2.png.h"
#include "battle/item/sleepy_sheep3.png.h"

static HudElement* D_802A3F50;

ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
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
        D_802A3F50 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_802A3F50, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        hud_element_free(D_802A3F50);
    }

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING

extern Vec3f D_802A3F88;
extern s32* D_802A3F58;

s32 N(D_802A3E88_7214D8)[] = {
    0, 0
};

s32 N(D_802A3E88_7214E0)[] = {
    0x00000000,
    0xFFFFFFE2, 0x00000000, 0xFFFFFFCE,
    0xFFFFFFE5, 0x00000000, 0x0000001E,
    0xFFFFFFBA, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF97, 0x00000000, 0x0000001E,
    0xFFFFFF92, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF6F, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF56, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF42, 0x00000000, 0xFFFFFFE2,
    0xFFFFFF2E, 0x00000000, 0xFFFFFFF6
};

f32 N(D_802A3F00_721550)[] = {
    0x3F800000, 0x3F800000, 0x3F400000, 0x3F800000,
    0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x3F400000, 0x3F400000
};

s32 N(D_802A3F28_721578)[] = {
    0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260,
    0x802A32A0, 0x802A32E0, 0x802A3260, 0x802A32A0,
    0x802A32E0, 0x802A3260
};

void virtual_entity_set_pos(s32, s32, s32, s32);
void virtual_entity_set_scale(s32, f32, f32, f32);
void virtual_entity_delete_by_index(s32);

ApiStatus func_802A123C_71E88C(ScriptInstance* script, s32 isInitialCall) {
    s32 i;
    Vec3f vecf;
    s32 flag;
    Vec3f* D_802A3F88_ptr = &D_802A3F88;
    s32* D_802A3E88_7214D8_ptr1; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr2; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr3; // = &N(D_802A3E88_7214D8);
    s32* D_802A3F58_ptr;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0: {
            s32* D_802A3F28_721578_ptr = &N(D_802A3F28_721578);
            s32 loop1, loop2, loop3;
            D_802A3F58_ptr = &D_802A3F58;

            D_802A3F88_ptr->x = -200.0f;
            D_802A3F88_ptr->z = 10.0f;

            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8) + 0;
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8) + 1;
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8) + 2;

            for (i = 0; i < 10; i++) {
                D_802A3F58_ptr[i] = virtual_entity_create(D_802A3F28_721578_ptr[i]);

                virtual_entity_set_pos(D_802A3F58_ptr[i],
                              *D_802A3E88_7214D8_ptr1 + D_802A3F88_ptr->x,
                              *D_802A3E88_7214D8_ptr2,
                              *D_802A3E88_7214D8_ptr3 + D_802A3F88_ptr->z);
                virtual_entity_set_scale(D_802A3F58_ptr[i], N(D_802A3F00_721550)[i], N(D_802A3F00_721550)[i], 1.0f);
                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;
            }
            script->functionTemp[0] = 1;
            script->functionTemp[1] = gGameStatusPtr->frameCounter % 10;
        }
        break;

        case 1:
            D_802A3F88.x += 6.0f;
            if (gGameStatusPtr->frameCounter % 3 == 0) {
                script->functionTemp[1]++;
                script->functionTemp[1] %= 10;
            }

            flag = 0;
            D_802A3F58_ptr = &D_802A3F58;
            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8);
            for (i = 0; i < 10; i++) {
                f32 x, y, z;

                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;

                x = *D_802A3E88_7214D8_ptr1 + D_802A3F88.x;
                y = *D_802A3E88_7214D8_ptr2;
                z = *D_802A3E88_7214D8_ptr3 + D_802A3F88.z;

                virtual_entity_set_pos(D_802A3F58_ptr[i], x, y, z);

                if (flag == 0 && script->functionTemp[1] == i) {
                    f32 x2, y2;
                    if (gGameStatusPtr->frameCounter % 5 == 0) {

                        y2 = y;
                        if (x > 0.0f) {
                            x2 = x;
                            if (x > 100.0f) {
                                x2 = x - 50.0f;
                            }
                            y2 = rand_int(x2);
                        }
                        x2 = x;
                        if (x > 40.0f) {
                            x2 = -(x - 40.0f);
                        }
                        fx_land(3, x2, y2, z, 0);
                        flag = 1;
                    }
                }
                D_802A3E88_7214D8_ptr1 += 0xC;
                D_802A3E88_7214D8_ptr2 += 0xC;
                D_802A3E88_7214D8_ptr3 += 0xC;
            }
            if (gGameStatusPtr->frameCounter & 1) {
                s32 randIdx = rand_int(9);
                fx_land(2, N(D_802A3E88_7214D8)[randIdx * 3 + 0] + D_802A3F88_ptr->x,
                              N(D_802A3E88_7214D8)[randIdx * 3 + 1],
                              N(D_802A3E88_7214D8)[randIdx * 3 + 2] + D_802A3F88_ptr->z, 0);
            }
            if (D_802A3F88_ptr->x >= 320.0f) {
                script->functionTemp[0] = 2;
                break;
            }
            return ApiStatus_DONE2;

        case 2:
            for (i = 0; i < 10; i++) {
                virtual_entity_delete_by_index(*(&D_802A3F58 + i));
            }

            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/sleepy_sheep", battle_item_sleepy_sheep_func_802A123C_71E88C,
            ScriptInstance* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1740_71ED90)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0x5A;
    }

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);
        ActorPart* targetPart = get_actor_part(targetActor, target->partID);

        if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
            targetActor->yaw += 33.0f;
            targetActor->yaw = clamp_angle(targetActor->yaw);
        }
    }

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1848_71EE98)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;
    s32 ret;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    ret = 0;

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);

        if (targetActor != NULL) {
            ActorPart* targetPart = get_actor_part(targetActor, target->partID);
            if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
                if (targetActor->yaw < 360.0f) {
                    targetActor->yaw += 33.0f;
                    if (targetActor->yaw >= 360.0f) {
                        targetActor->yaw = 360.0f;
                    }
                    ret = 1;
                }
            }
        }
    }

    return (ret == 0) * ApiStatus_DONE2;
}

Script N(UseItemWithEffect) = SCRIPT({
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

#include "battle/item/sleepy_sheep1.png.inc.c"
#include "battle/item/sleepy_sheep1.pal.inc.c"
#include "battle/item/sleepy_sheep2.png.inc.c"
#include "battle/item/sleepy_sheep2.pal.inc.c"
#include "battle/item/sleepy_sheep3.png.inc.c"
#include "battle/item/sleepy_sheep3.pal.inc.c"

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
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep1_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep1_png, G_IM_FMT_CI, battle_item_sleepy_sheep1_png_width, battle_item_sleepy_sheep1_png_height, 0, 0, battle_item_sleepy_sheep1_png_width - 1, battle_item_sleepy_sheep1_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep2_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep2_png, G_IM_FMT_CI, battle_item_sleepy_sheep2_png_width, battle_item_sleepy_sheep2_png_height, 0, 0, battle_item_sleepy_sheep2_png_width - 1, battle_item_sleepy_sheep2_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep3_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep3_png, G_IM_FMT_CI, battle_item_sleepy_sheep3_png_width, battle_item_sleepy_sheep3_png_height, 0, 0, battle_item_sleepy_sheep3_png_width - 1, battle_item_sleepy_sheep3_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
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
    SI_VAR(10) = (const) ITEM_SLEEPY_SHEEP;
    await N(UseItemWithEffect);
    UseBattleCamPreset(19);
    SetBattleCamTarget(0xFFFFFFBD, 0xFFFFFFF1, 0xFFFFFFFB);
    SetBattleCamOffsetZ(45);
    SetBattleCamZoom(169);
    MoveBattleCamOver(50);
    spawn {
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_364);
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
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 32;
    ShowEmote(0, EMOTE_QUESTION, -45, 20, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    sleep 30;
    SetActorYaw(ACTOR_PLAYER, 30);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 60);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 90);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 120);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 150);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 180);
    spawn {
        N(func_802A123C_71E88C)();
    }
    InitTargetIterator();
    spawn {
        sleep 40;
        N(func_802A1740_71ED90)();
        N(func_802A1848_71EE98)();
    }
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    sleep 8;
    SetJumpAnimations(ACTOR_PLAYER, 0, ANIM_1002B, ANIM_1002B, ANIM_MIDAIR);
    SetActorJumpGravity(ACTOR_PLAYER, 1.80078125);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80273444(15, 0, 0);
    spawn {
        sleep 5;
        SetActorYaw(ACTOR_PLAYER, 150);
        sleep 1;
        SetActorYaw(ACTOR_PLAYER, 120);
        sleep 1;
        SetActorYaw(ACTOR_PLAYER, 90);
        sleep 1;
        SetActorYaw(ACTOR_PLAYER, 60);
        sleep 1;
        SetActorYaw(ACTOR_PLAYER, 30);
        sleep 1;
        SetActorYaw(ACTOR_PLAYER, 0);
    }
    sleep 40;
    CreateVirtualEntity(SI_VAR(10), N(modelCommandList));
    SI_VAR(7) = 0xFFFFFF38;
    SI_VAR(8) = 0;
    SI_VAR(9) = 0;
    SetVirtualEntityPosition(SI_VAR(10), SI_VAR(7), SI_VAR(8), SI_VAR(9));
    SetVirtualEntityScale(SI_VAR(10), 0.7109375, 0.7109375, 0.7109375);
    SetVirtualEntityMoveSpeed(SI_VAR(10), 7.0);
    SetVirtualEntityJumpGravity(SI_VAR(10), 1.400390625);
    SetOwnerTarget(0, 0);
    SetGoalToTarget(ACTOR_PLAYER);
    GetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) -= 60;
    VirtualEntityMoveTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    GetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_HIT_BLOCK);
    spawn {
        SetAnimation(ACTOR_PLAYER, 0, ANIM_SHOCK_STILL);
        SetActorScale(ACTOR_PLAYER, 1.2001953125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PLAYER, 1.30078125, 0.80078125, 1.0);
        sleep 3;
        SetActorScale(ACTOR_PLAYER, 1.2001953125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ACTOR_PLAYER, 1.0, 1.0, 1.0);
    }
    PlayEffect(0x6, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 2;
    SetVirtualEntityJumpGravity(SI_VAR(10), 1.400390625);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 60;
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    SI_VAR(0) += 20;
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SI_VAR(0) += 10;
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
    PlayEffect(0x6, 2, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
    sleep 5;
    spawn {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 270;
        VirtualEntityMoveTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 0);
        DeleteVirtualEntity(SI_VAR(10));
    }
    sleep 30;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_SLEEPY_SHEEP, SI_VAR(0), SI_VAR(1));
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

s32 D_802A3E88_7214D8[] = {
    0, 0
};
