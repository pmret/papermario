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
    DispatchEvent(ACTOR_PARTNER, 62);
    parallel {
        SI_VAR(0) = 1.0;
        loop 10 {
            SetActorScale(ACTOR_PARTNER, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) -= 0.1005859375;
            sleep 1;
        }
    }
    EnablePartnerBlur();
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_E);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SetActorJumpGravity(ACTOR_PARTNER, 1.0);
    SetGoalPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    JumpToGoal(ACTOR_PARTNER, 10, 0, 0, 1);
    DisablePartnerBlur();
});

Script BtlBringPartnerOut = SCRIPT({
    parallel {
        SI_VAR(0) = 0.1005859375;
        loop 20 {
            SetActorScale(ACTOR_PARTNER, SI_VAR(0), SI_VAR(0), 1.0);
            SI_VAR(0) += 0.05078125;
            sleep 1;
        }
        SetActorScale(ACTOR_PARTNER, 1.0, 1.0, 1.0);
    }
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_D);
    GetGoalPos(256, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetActorJumpGravity(ACTOR_PARTNER, 1.0);
    if (SI_VAR(1) == 0) {
        JumpToGoal(ACTOR_PARTNER, 20, 0, 0, 1);
    } else {
        JumpToGoal(ACTOR_PARTNER, 20, 0, 0, 1);
    }
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    ForceHomePos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
});

s8 D_80280CE0[] = { 0, 0, 0, 0 };
s32 D_80280CE4 = -1;

Script CamPreset_B = SCRIPT({
    func_80248DD0();
});

Script CamPreset_F = SCRIPT({
    func_80248DE4();
});

Script CamPreset_M = SCRIPT({
    func_80249804();
});

Script CamPreset_G = SCRIPT({
    func_8024A214();
});

Script CamPreset_I = SCRIPT({
    func_8024A990();
});

Script CamPreset_H = SCRIPT({
    func_8024AFE4();
});

Script CamPreset_N = SCRIPT({
    func_8024B5FC();
});

Script CamPreset_C = SCRIPT({
    func_8024B9A0();
});

Script CamPreset_D = SCRIPT({
    func_8024BDA4();
});

Script CamPreset_E = SCRIPT({
    func_8024C180();
});

Script CamPreset_J = SCRIPT({
    func_8024C570();
});

Script CamPreset_K = SCRIPT({
    func_8024C944();
});

Script CamPreset_L = SCRIPT({
    func_8024CB68();
});

Script CamPreset_A = SCRIPT({
    func_8024E9B0(0, 15, 0);
    func_8024E748(2, 550);
    func_8024E748(3, 100);
    func_8024E748(4, 8);
});

Script D_80280EB8 = SCRIPT({
    SetCamPerspective(CAM_BATTLE, 6, 25, 16, 1024);
    SetCamViewport(CAM_BATTLE, 12, 20, 296, 200);
    SetCamBGColor(CAM_BATTLE, 0, 0, 0);
    SetCamEnabled(CAM_BATTLE, TRUE);
    sleep 1;
    InitVirtualEntityList();
    InitAnimatedModels();
    func_802CABE8(CAM_BATTLE, 0, 240, 100, 8);
    func_802CAE50(CAM_BATTLE, -75, 35, 0);
    BattleCamTargetActor(ACTOR_PLAYER);
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

INCLUDE_ASM(s32, "16c8e0", initialize_battle);

void func_8023E3FC(void) {
}

void update_actor_shadows(void) {
    if (gBattleStatus.flags1 & 1) {
        update_enemy_shadows();
        update_hero_shadows();
    }
}

INCLUDE_ASM(s32, "16c8e0", btl_update);

INCLUDE_ASM(s32, "16c8e0", btl_draw_ui);

INCLUDE_ASM(s32, "16c8e0", func_8023ED5C);

INCLUDE_ASM(s32, "16c8e0", func_8023F060);

INCLUDE_ASM(s32, "16c8e0", func_8023F088);

void func_8023FF84(void) {
    show_foreground_models_unchecked();
}

INCLUDE_ASM(s32, "16c8e0", btl_draw_enemy_health_bars);

INCLUDE_ASM(s32, "16c8e0", btl_update_starpoints_display);

INCLUDE_ASM(s32, "16c8e0", btl_save_world_cameras);

INCLUDE_ASM(s32, "16c8e0", btl_restore_world_cameras);

void btl_delete_actor(Actor* actor) {
    ActorPart* partsTable;
    ActorPart* actorPartTemp;
    BattleStatus* battleStatus;
    s32 i;

    // TODO hard-coded
    for (i = 0; i < 2; i++) {
        remove_actor_decoration(actor, i);
    }
    if (actor->idleScript != NULL) {
        kill_script_by_ID(actor->idleScriptID);
    }
    if (actor->onHitScript != NULL) {
        kill_script_by_ID(actor->onHitID);
    }
    if (actor->takeTurnScript != NULL) {
        kill_script_by_ID(actor->takeTurnID);
    }
    func_80266EE8(actor, 0);

    partsTable = actor->partsTable;

    while (partsTable != NULL) {
        if (!(partsTable->flags & 0x4)) {
            delete_shadow(partsTable->shadow);
        }

        if (partsTable->idleAnimations != NULL) {
            func_802DE894(partsTable->unk_84, 0, 0, 0, 0, 0, 0);

            ASSERT(spr_free_sprite(partsTable->unk_84) == 0);

            if (!(partsTable->flags & 0x80000000)) {
                heap_free(partsTable->movement);
            }

            if (!(partsTable->flags & 0x2)) {
                heap_free(partsTable->decorationTable);
            }
        }
        actorPartTemp = partsTable->nextPart;
        heap_free(partsTable);
        partsTable = actorPartTemp;
    }

    delete_shadow(actor->shadow);
    remove_all_status_icons(actor->unk_436);
    remove_effect(actor->ptrDefuffIcon);

    if (actor->unk_200 != NULL) {
        actor->unk_200[3][9] = 0;
    }

    battleStatus = &gBattleStatus;
    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
        if (battleStatus->enemyActors[i] == actor) {
            battleStatus->enemyActors[i] = NULL;
            break;
        }
    }

    heap_free(actor);
}

void btl_delete_player_actor(Actor* player) {
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

    delete_shadow(player->shadow);
    remove_all_status_icons(player->unk_436);
    remove_effect(player->ptrDefuffIcon);

    if (player->unk_200 != NULL) {
        player->unk_200[3][9] = 0;
    }

    heap_free(movement);
    heap_free(decorationTable);
    heap_free(partsTable);
    heap_free(player);
}
