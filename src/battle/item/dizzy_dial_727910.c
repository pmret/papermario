#include "common.h"
#include "script_api/battle.h"

MenuIcon* D_802A1CD4;
extern s32 D_80108A64;
s32* D_802A1CD0;

ApiStatus func_802A1000_727910(ScriptInstance* script) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ItemId_COIN, posX, posY, posZ, 0x17, (i * 3) + 1, facingAngleSign, 0);
            add_coins(1);
            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        D_802A1CD4 = create_icon(&D_80108A64);
        set_icon_render_pos(D_802A1CD4, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus func_802A11D4_727AE4(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;

    if (heroes_is_ability_active(player, Ability_REFUND) && sellValue > 0) {
        free_icon(D_802A1CD4);
    }

    return ApiStatus_DONE2;
}

void func_802A123C_727B4C(void) {
    func_80138D88(0, 0, 0x140, 0xF0, 160.0f);
}

ApiStatus func_802A1270_727B80(ScriptInstance* script, s32 isInitialCall) {
    Camera *camera = &gCameras[1];
    f32 a;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    switch(script->functionTemp[0].s) {
        case 0:
            script->functionTemp[1].s = 0;
            script->functionTemp[2].s = 0;
            play_sound(0x2033);
            camera->unk_1C = 0;
            D_802A1CD0 = bind_dynamic_entity_7(NULL, func_802A123C_727B4C);
            script->functionTemp[0].s = 1;
        case 1:
            camera->flags |= 8;
            a = script->functionTemp[1].s;
            guRotateF(camera->viewMtxShaking, a, 0.0f, 0.0f, 1.0f);
            script->functionTemp[1].s = 2.0 * ((1.0 - sin_rad(((script->functionTemp[2].s + 0x5A) * 6.28318f) / 360.0f)) * 360.0);
            script->functionTemp[2].s++;
            if (script->functionTemp[2].s < 0x5B) {
                return ApiStatus_BLOCK;
            }
            camera->unk_1C = 0;
            camera->flags &= ~8;
            func_801235C0(D_802A1CD0);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

Script N(test_test) = SCRIPT({
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
        battle_star_peach_dash_UnkStarFunc1();
        sleep SI_VAR(0);
        sleep 15;
        func_802A11D4_7332A4();
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
