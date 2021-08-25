#include "dizzy_dial.h"
#include "camera.h"

static s32* D_802A1CD0;

#include "ItemRefund.inc.c"

void func_802A123C_727B4C(void) {
    func_80138D88(0, 0, 0x140, 0xF0, 160.0f);
}

ApiStatus N(func_802A1270_727B80)(Evt* script, s32 isInitialCall) {
    Camera* camera = &gCameras[1];
    f32 a;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = 0;
            script->functionTemp[2] = 0;
            sfx_play_sound(0x2033);
            camera->unk_1C = 0;
            D_802A1CD0 = create_generic_entity_frontUI(NULL, func_802A123C_727B4C);
            script->functionTemp[0] = 1;
        case 1:
            camera->flags |= CAM_FLAG_SHAKING;
            a = script->functionTemp[1];
            guRotateF(camera->viewMtxShaking, a, 0.0f, 0.0f, 1.0f);
            script->functionTemp[1] = 2.0 * ((1.0 - sin_rad(((script->functionTemp[2] + 90) * 6.28318f) / 360.0f)) * 360.0);
            script->functionTemp[2]++;
            if (script->functionTemp[2] <= 90) {
                return ApiStatus_BLOCK;
            }
            camera->unk_1C = 0;
            camera->flags &= ~CAM_FLAG_SHAKING;
            free_generic_entity(D_802A1CD0);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_DIZZY_DIAL;
    await N(UseItemWithEffect);
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    spawn {
        sleep 5;
        AddBattleCamZoom(0xFFFFFF06);
        MoveBattleCamOver(80);
        func_8024ECF8(0, 0, 1);
        sleep 80;
        AddBattleCamZoom(250);
        MoveBattleCamOver(3);
        func_8024ECF8(0, 0, 1);
    }
    N(func_802A1270_727B80)();
    spawn {
        StartRumble(8);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 4.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        sleep 10;
        UseBattleCamPreset(3);
        MoveBattleCamOver(10);
        func_8024ECF8(0, 0, 0);
    }
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_DIZZY_DIAL, SI_VAR(0), SI_VAR(1));
    MakeStatusField(SI_VAR(0), 0x40000, 100, SI_VAR(0));
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
