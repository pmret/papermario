#include "common.h"

void get_dpad_input_radial(f32* angle, f32* magnitude) {
    BattleStatus* battleStatus = BATTLE_STATUS;
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

INCLUDE_ASM(s32, "code_16c8e0", func_8023E104);

INCLUDE_ASM(s32, "code_16c8e0", func_8023E11C);

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
