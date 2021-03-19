#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

f32 D_802809F0 = 0.0f;
s8 D_802809F4 = 0;
s8 D_802809F5 = 0;
s16 D_802809F6 = -1;
s16 D_802809F8 = 0;
u16 D_802809FA = 0;

void* D_802809FC[] = {
    D_80291FA8, D_80291FD0, D_80291FF8, D_80292020, D_80292048, D_80292070, D_80292098, D_802920C0, D_802920E8, D_80292110, NULL, NULL, NULL,
};

s32 D_80280A30 = 0xFF;

Script BtlPutPartnerAway = SCRIPT({
    DispatchEvent(256, 62);
    parallel {
        SI_VAR(0) = 1.0;
        loop 10 {
            SetActorScale(256, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) -= 0.1005859375;
            sleep 1;
        }
    }
    EnablePartnerBlur();
    PlaySoundAtActor(0, 14);
    GetActorPos(0, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SetActorJumpGravity(256, 1.0);
    SetGoalPos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(256, 10, 0, 0, 1);
    DisablePartnerBlur();
});

Script BtlBringPartnerOut = SCRIPT({
    parallel {
        SI_VAR(0) = 0.1005859375;
        loop 20 {
            SetActorScale(256, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) += 0.05078125;
            sleep 1;
        }
        SetActorScale(256, 1.0, 1.0, 1.0);
    }
    PlaySoundAtActor(0, 13);
    GetGoalPos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetActorJumpGravity(256, 1.0);
    if (SI_VAR(1) == 0) {
        JumpToGoal(256, 20, 0, 0, 1);
    } else {
        JumpToGoal(256, 20, 0, 0, 1);
    }
    GetActorPos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ForceHomePos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
});

s8 D_80280CE0[] = { 0, 0, 0, 0 };
s32 D_80280CE4 = -1;

Script D_80280CE8 = SCRIPT({
    func_80248DD0();
});

Script D_80280D04 = SCRIPT({
    func_80248DE4();
});

Script D_80280D20 = SCRIPT({
    func_80249804();
});

Script D_80280D3C = SCRIPT({
    func_8024A214();
});

Script D_80280D58 = SCRIPT({
    func_8024A990();
});

Script D_80280D74 = SCRIPT({
    func_8024AFE4();
});

Script D_80280D90 = SCRIPT({
    func_8024B5FC();
});

Script D_80280DAC = SCRIPT({
    func_8024B9A0();
});

Script D_80280DC8 = SCRIPT({
    func_8024BDA4();
});

Script D_80280DE4 = SCRIPT({
    func_8024C180();
});

Script D_80280E00 = SCRIPT({
    func_8024C570();
});

Script D_80280E1C = SCRIPT({
    func_8024C944();
});

Script D_80280E38 = SCRIPT({
    func_8024CB68();
});

Script D_80280E54 = SCRIPT({
    func_8024E9B0(0, 15, 0);
    func_8024E748(2, 550);
    func_8024E748(3, 100);
    func_8024E748(4, 8);
});

Script D_80280EB8 = SCRIPT({
    SetCamPerspective(Cam_BATTLE, 6, 25, 16, 1024);
    SetCamViewport(Cam_BATTLE, 12, 20, 296, 200);
    SetCamBGColor(Cam_BATTLE, 0, 0, 0);
    SetCamEnabled(Cam_BATTLE, TRUE);
    sleep 1;
    func_802D3398();
    func_802CCCB0();
    func_802CABE8(Cam_BATTLE, 0, 240, 100, 8);
    func_802CAE50(Cam_BATTLE, -75, 35, 0);
    BattleCamTargetActor(ActorID_PLAYER);
    func_8024CE9C();
});

void get_dpad_input_radial(f32* angle, f32* magnitude) {
    BattleStatus* battleStatus = &gBattleStatus;
    u16 currentButtonsDown;
    f32 stickX;
    f32 stickY;
    f32 mag;
    f32 maxMagnitude = 60.0f;

    stickX = battleStatus->stickX;
    stickY = battleStatus->stickY;
    currentButtonsDown = battleStatus->currentButtonsDown;

    if (currentButtonsDown & 0xF00) {
        stickY = 0.0f;
        stickX = 0.0f;
        if (currentButtonsDown & 0x800) {
            stickY = maxMagnitude;
        }
        if (currentButtonsDown & 0x400) {
            stickY = -maxMagnitude;
        }
        if (currentButtonsDown & 0x200) {
            stickX = -maxMagnitude;
        }
        if (currentButtonsDown & 0x100) {
            stickX = maxMagnitude;
        }
    }

    mag = dist2D(0.0f, 0.0f, stickX, -stickY);
    if (mag >= maxMagnitude) {
        mag = maxMagnitude;
    }

    *angle = atan2(0.0f, 0.0f, stickX, -stickY);
    *magnitude = mag;
}

void func_8023E104(void) {
    D_802809F4 = 1;
    D_802809F5 = 0;
}

void func_8023E11C(void) {
    D_802809F4 = 0;
    D_802809F5 = 0;
}

INCLUDE_ASM(s32, "code_16c8e0", initialize_battle);

void func_8023E3FC(void) {
}

void update_actor_shadows(void) {
    if (gBattleStatus.flags1 & 1) {
        update_enemy_shadows();
        update_hero_shadows();
    }
}

INCLUDE_ASM(s32, "code_16c8e0", update_battle_state);

INCLUDE_ASM(s32, "code_16c8e0", draw_main_battle_ui);

INCLUDE_ASM(s32, "code_16c8e0", func_8023ED5C);

INCLUDE_ASM(s32, "code_16c8e0", func_8023F060);

INCLUDE_ASM(s32, "code_16c8e0", func_8023F088);

void func_8023FF84(void) {
    show_foreground_models_unsafe();
}

INCLUDE_ASM(s32, "code_16c8e0", draw_enemy_health_bars);

INCLUDE_ASM(s32, "code_16c8e0", update_starpoints_display);

INCLUDE_ASM(s32, "code_16c8e0", func_802409F4);

INCLUDE_ASM(s32, "code_16c8e0", func_80240AA8);

INCLUDE_ASM(s32, "code_16c8e0", delete_actor);

void delete_player_actor(Actor* player) {
    struct ActorPart* partsTable;
    struct ActorPartMovement* movement;
    struct DecorationTable* decorationTable;
    s32 i;

    for (i = 0; i < 2; i++) {
        remove_actor_decoration(player, i);
    }

    if (player->idleScript != NULL) {
        kill_script_by_ID(player->idleScriptID);
    }
    if (player->onHitScript != NULL) {
        kill_script_by_ID(player->onHitID);
    }
    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnID);
    }

    partsTable = player->partsTable;
    decorationTable = partsTable->decorationTable;
    movement = partsTable->movement;

    func_80112328(player->shadow);
    func_800476F4(player->unk_436);
    remove_effect(player->ptrDefuffIcon);

    if (player->unk_200 != NULL) {
        player->unk_200[3][9] = 0;
    }

    heap_free(movement);
    heap_free(decorationTable);
    heap_free(partsTable);
    heap_free(player);
}
