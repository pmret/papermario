#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_air_raid

extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_StickNeutral[];
extern HudScript HudScript_100pct[];
extern HudScript HudScript_StickMashLeft[];

extern s32 D_80294360;

s32 D_802A9970_429C90[] = { 0, 25, 50, 75, 75, };
s32 D_802A9984_429CA4[] = { 40, 70, 99, 200, };
s32 D_802A9994_429CB4[] = { 35, 60, 80, 99, 200, };
s32 D_802A99A8_429CC8[] = { 35, 35, 60, 80, 99, 200, };

ApiStatus func_802A9000_429320(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294360;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->actionCommandID = 14;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(HudScript_StickNeutral);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/air_raid", func_802A9294_4295B4);

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
