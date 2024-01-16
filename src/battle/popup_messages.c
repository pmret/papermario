#include "common.h"
#include "effects.h"
#include "entity.h"
#include "battle/battle.h"
#include "battle/action_cmd.h"

extern EntityModelScript EMS_BonkIcon;

 // all keyed by number of lines in the message (1 or 2)
s16 BattleMessage_BoxSizesY[] = { 28, 40 };
s16 BattleMessage_TextOffsetsY[] = { 0, -2 };
s16 BattleMessage_BoxOffsetsY[] = { 0, -12 };

//TODO Vec3f[]
f32 D_802835DC[] = {
    0.0f, 4.5f, 0.0f,
    1.0f, 4.0f, 0.0f,
    2.0f, 3.0f, 0.0f,
    3.0f, 2.0f, 0.0f,
    3.5f, 1.0f, 0.0f,
    4.0f, 0.0f, 0.0f,
    4.5f, 0.0f, 0.0f,
    5.0f, 0.0f, 0.0f,
    4.5f, 0.0f, 0.0f,
    4.0f, 0.0f, 0.0f,
    3.5f, -1.0f, 0.0f,
    3.0f, -2.0f, 0.0f,
    2.0f, -3.0f, 0.0f,
    1.0f, -4.0f, 0.0f,
    0.0f, -4.5f, 0.0f,
};

Vec3f D_80283690[] = {
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
};

EntityModelScript* BonkModelScripts[] = {
    NULL,
    &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon,
    &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon,
};

s32 BattleMessages[] = {
    [BTL_MSG_MERLEE_ATK_UP]         MSG_Menus_Merlee_IncreaseAttack,
    [BTL_MSG_MERLEE_DEF_UP]         MSG_Menus_Merlee_DecreaseDamage,
    [BTL_MSG_MERLEE_EXP_UP]         MSG_Menus_Merlee_IncreaseStarPoints,
    [BTL_MSG_MERLEE_DONE]           MSG_Menus_Merlee_Exhausted,
    [BTL_MSG_CHARGE_HAMMER]         MSG_Menus_ChargeHammer,
    [BTL_MSG_CHARGE_HAMMER_MORE]    MSG_Menus_ChargeHammerMore,
    [BTL_MSG_CHARGE_JUMP]           MSG_Menus_ChargeJump,
    [BTL_MSG_CHARGE_JUMP_MORE]      MSG_Menus_ChargeJumpMore,
    [BTL_MSG_CANT_CHARGE]           MSG_Menus_ChargeMaxedOut,
    [BTL_MSG_ENEMY_MISSED]          MSG_Menus_EnemyMissed,

    // player status effects
    [BTL_MSG_PLAYER_DAZED]          MSG_Menus_PlayerDazed,
    [BTL_MSG_PLAYER_ASLEEP]         MSG_Menus_PlayerAsleep,
    [BTL_MSG_PLAYER_FROZEN]         MSG_Menus_PlayerFrozen,
    [BTL_MSG_PLAYER_POISONED]       MSG_Menus_PlayerPoisoned,
    [BTL_MSG_PLAYER_SHRUNK]         MSG_Menus_PlayerShrunk,
    [BTL_MSG_PLAYER_PARALYZED]      MSG_Menus_PlayerParalyzed,
    [BTL_MSG_PLAYER_CHARGED]        MSG_Menus_PlayerElectricCharge,
    [BTL_MSG_PLAYER_TRANSPARENT]    MSG_Menus_PlayerTransparent,

    // enemy status effects
    [BTL_MSG_ENEMY_DAZED]           MSG_Menus_EnemyDazed,
    [BTL_MSG_ENEMY_ASLEEP]          MSG_Menus_EnemyAsleep,
    [BTL_MSG_ENEMY_FROZEN]          MSG_Menus_EnemyFrozen,
    [BTL_MSG_ENEMY_POISONED]        MSG_Menus_EnemyPoisoned,
    [BTL_MSG_ENEMY_SHRUNK]          MSG_Menus_EnemyShrunk,
    [BTL_MSG_ENEMY_PARALYZED]       MSG_Menus_EnemyParalyzed,
    [BTL_MSG_ENEMY_ELECTRIFIED]     MSG_Menus_EnemyElectrified,
    [BTL_MSG_ENEMY_CANT_MOVE]       MSG_Menus_EnemyCantMove,

    [BTL_MSG_STAR_POWER_RECHARGED]  MSG_Menus_StarEnergyRecharged,
    [BTL_MSG_STAR_POWER_MAXED]      MSG_Menus_StarEnergyMaxedOut,
    [BTL_MSG_STAR_POWER_FILLED]     MSG_Menus_StarEnergyFilled,
    [BTL_MSG_ATTACK_UP]             MSG_Menus_AttackUp,
    [BTL_MSG_DEFENCE_UP]            MSG_Menus_DefenseUp,
    [BTL_MSG_HEAL_ONE]              MSG_Menus_HealOne,
    [BTL_MSG_HEAL_ALL]              MSG_Menus_HealAll,

    [BTL_MSG_ENEMY_TRANSPARENT]     MSG_Menus_EnemyTransparent,
    [BTL_MSG_ENEMY_CHARGED]         MSG_Menus_EnemyElectricCharge,
    [BTL_MSG_PARTNER_INJURED]       MSG_Menus_PartnerInjured,
    [BTL_MSG_CHARGE_GOOMBARIO]      MSG_Menus_ChargeGoombario,
    [BTL_MSG_CHARGE_GOOMBARIO_MORE] MSG_Menus_ChargeGoombarioMore,
    [BTL_MSG_WATER_BLOCK_BEGIN]     MSG_Menus_WaterBlockBegin,
    [BTL_MSG_WATER_BLOCK_END]       MSG_Menus_WaterBlockEnd,
    [BTL_MSG_CLOUD_NINE_BEGIN]      MSG_Menus_CloudNineBegin,
    [BTL_MSG_CLOUD_NINE_END]        MSG_Menus_CloudNineEnd,
    [BTL_MSG_TURBO_CHARGE_BEGIN]    MSG_Menus_TurboChargeBegin,
    [BTL_MSG_TURBO_CHARGE_END]      MSG_Menus_TurboChargeEnd,
    [BTL_MSG_CHILL_OUT_BEGIN]       MSG_Menus_ChillOutBegin,
    [BTL_MSG_UNUSED_CLOUD_NINE]     MSG_Menus_CloudNineBegin,

    // move action command tips
    [BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING]   MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED]        MSG_Menus_MoveTip_PushLeftWithTiming,
    [BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE]    MSG_Menus_MoveTip_PressBeforeStriking,
    [BTL_MSG_ACTION_TIP_MASH_BUTTON]            MSG_Menus_MoveTip_PressRepeatedly,
    [BTL_MSG_ACTION_TIP_MASH_LEFT]              MSG_Menus_MoveTip_PushLeftRepeatedly,
    [BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM]          MSG_Menus_MoveTip_PushLeftToAim,
    [BTL_MSG_ACTION_TIP_UNUSED_1]               MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_UNUSED_2]               MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN]    MSG_Menus_MoveTip_PressAsShown,
    [BTL_MSG_ACTION_TIP_NOT_USED_1]             MSG_Menus_MoveTip_NOT_USED_1,
    [BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING]      MSG_Menus_MoveTip_PressAsLightsUp,
    [BTL_MSG_ACTION_TIP_NOT_USED_2]             MSG_Menus_MoveTip_NOT_USED_2,
    [BTL_MSG_ACTION_TIP_MASH_BOTH]              MSG_Menus_MoveTip_PressBothRepeatedly,
    [BTL_MSG_ACTION_TIP_UNUSED_3]               MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_HOLD_THEN_TAP]          MSG_Menus_MoveTip_HoldThenTap,
    [BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE]      MSG_Menus_MoveTip_HoldThenRelease,
    [BTL_MSG_ACTION_TIP_MOVE_TO_AIM]            MSG_Menus_MoveTip_MoveToAim,
    [BTL_MSG_ACTION_TIP_UNUSED_4]               MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_BREAK_FREE]             MSG_Menus_MoveTip_PressToRunAway,
    [BTL_MSG_ACTION_TIP_REDUCE_DAMAGE]          MSG_Menus_MoveTip_PressToReduceDamage,
    [BTL_MSG_ACTION_TIP_NOT_USED_3]             MSG_Menus_MoveTip_NOT_USED_3,

    // no targets available
    [BTL_MSG_NO_JUMP_TARGET]        MSG_Menus_Battle_NoTarget_Jump,
    [BTL_MSG_NO_HAMMER_TARGET]      MSG_Menus_Battle_NoTarget_Hammer,
    [BTL_MSG_NO_ITEM_TARGET]        MSG_Menus_Battle_NoTarget_Item,
    [BTL_MSG_46]                    MSG_NONE,
    [BTL_MSG_47]                    MSG_NONE,

    // errors and warnings
    [BTL_MSG_CANT_SELECT_NOW]       MSG_Menus_Battle_CantSelectNow,
    [BTL_MSG_HAMMER_DISABLED_1]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_HAMMER_DISABLED_2]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_HAMMER_DISABLED_3]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_JUMP_DISABLED_1]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_JUMP_DISABLED_2]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_JUMP_DISABLED_3]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_ITEMS_DISABLED]        MSG_Menus_Battle_CantUseItems,
    [BTL_MSG_CANT_SWITCH]           MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_CANT_MOVE]             MSG_Menus_Battle_CantMove,
    [BTL_MSG_CANT_SWITCH_UNUSED]    MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_CANT_MOVE_UNUSED]      MSG_Menus_Battle_CantMove,
    [BTL_MSG_CANT_SELECT_NOW_ALT]   MSG_Menus_Battle_CantSelectNow,
};

s32 bActorMessages[] = {
    MSG_Menus_Party_Mario,
    MSG_Menus_Party_Goombario,
    MSG_Menus_Party_Kooper,
    MSG_Menus_Party_Bombette,
    MSG_Menus_Party_Parakarry,
    MSG_Menus_Party_Goompa,
    MSG_Menus_Party_Watt,
    MSG_Menus_Party_Sushie,
    MSG_Menus_Party_Lakilester,
    MSG_Menus_Party_Bow,
    MSG_Menus_Party_Goombaria,
    MSG_Menus_Party_Twink,
    MSG_Menus_Party_Peach
};

PopupMessage* bPopupMessage = NULL;

BSS PopupMessage popupMessages[32];
BSS s16 BattlePopupMessageVar;
BSS s16 HID_BattleMessage1;
BSS s16 HID_BattleMessage2;
BSS s16 HID_BattleMessage3;
BSS s16 HID_BattleMessage4;
BSS b16 ActionCommandTipVisible;
BSS b16 BattleMessage_BoxPosLocked;
BSS s16 BattleMessage_CurBoxPosY;
BSS s16 BattleMessage_CurBoxOffsetY;

extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_CDownButton;
extern HudScript HES_CLeftButton;
extern HudScript HES_CRightButton;
extern HudScript HES_CUpButton;
extern HudScript HES_Item_MenuBoots1;
extern HudScript HES_Item_MenuBoots2;
extern HudScript HES_Item_MenuBoots3;
extern HudScript HES_Item_MenuHammer1;
extern HudScript HES_Item_MenuHammer2;
extern HudScript HES_Item_MenuHammer3;
extern HudScript HES_Item_MenuItems;
extern HudScript HES_MashBButton2;
extern HudScript HES_MashCDownButton1;
extern HudScript HES_MashCLeftButton;
extern HudScript HES_MashCRightButton1;
extern HudScript HES_MashCUpButton;
extern HudScript HES_RotateStickCW;
extern HudScript HES_StickBackAndForth;
extern HudScript HES_StickTapLeft;
extern HudScript HES_StickTapRight;
extern HudScript HES_TimingBlink;

void btl_bonk_update(void* data);
void btl_bonk_render(void* data);
void btl_bonk_setup_gfx(void* data);
void btl_update_message_popup(void* popup);
void btl_show_message_popup(void* popup);

void btl_popup_messages_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        popup->active = FALSE;
        popup->message = NULL;
    }
}

void btl_popup_messages_delete(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
            popup->message = NULL;
        }
        popup->active = FALSE;
    }
}

void btl_popup_messages_update(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void btl_popup_messages_draw_world_geometry(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderWorldFunc != NULL) {
            popup->renderWorldFunc(popup);
        }
    }
}

void btl_popup_messages_draw_ui(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderUIFunc != NULL) {
            popup->renderUIFunc(popup);
        }
    }
}

PopupMessage* btl_create_popup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void free_popup(PopupMessage* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = FALSE;
}

void show_immune_bonk(f32 x, f32 y, f32 z, s32 numStars, s32 arg4, s32 arg5) {
    BattleStatus* battleStatus = &gBattleStatus;
    PopupMessage* popup;
    Message* message;
    EntityModelScript** modelScript;
    f32 var_f20;
    f32 baseScale;
    f32* f1;
    f32* f2;
    f32* f3;
    s32 arg5mod8;
    s32 iMod8;
    s32 sign;
    s32 cond;
    s32 one;
    s32 two;
    s32 i;

    baseScale = 1.0f;
    cond = FALSE;
    var_f20 = 1.0f;
    if (numStars < 1) {
        numStars = 1;
        cond = TRUE;
        baseScale = 0.4f;
        var_f20 = 0.7f;
    }

    if (battleStatus->flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
        baseScale *= 2.0;
    }

    popup = btl_create_popup();
    if (popup != NULL) {
        sign = 1;
        if (arg5 < 0) {
            arg5 = -arg5;
            sign = -1;
        }

        while (TRUE) {
            if (arg5 > 5) {
                arg5 -= 5;
            } else {
                break;
            }
        }

        battleStatus->unk_90 = 0;
        popup->updateFunc = btl_bonk_update;
        popup->renderWorldFunc = btl_bonk_render;
        popup->unk_00 = FALSE;
        popup->renderUIFunc = NULL;
        popup->messageIndex = 1;
        popup->active |= 0x10;
        message = popup->message = heap_malloc(numStars * sizeof(*popup->message));
        ASSERT (popup->message != NULL);

        for (i = 0; i < numStars; i++, message++) {
            modelScript = &BonkModelScripts[numStars];
            message->unk_00 = TRUE;
            message->entityModelIndex = load_entity_model(*modelScript);
            set_entity_model_flags(message->entityModelIndex, ENTITY_MODEL_FLAG_HIDDEN);
            bind_entity_model_setupGfx(message->entityModelIndex, message, btl_bonk_setup_gfx);
            message->pos.x = x;
            message->pos.y = y;
            message->pos.z = z;
            arg5mod8 = arg5 % 8;
            arg5++;

            one = 1;
            two = 2;

            f1 = &D_802835DC[arg5mod8 * 3];
            f2 = &D_802835DC[arg5mod8 * 3 + one];
            f3 = &D_802835DC[arg5mod8 * 3 + two];
            message->vel.x = 2.0 * *f1 * sign * var_f20;
            message->vel.y = 2.0 * *f2 * var_f20;
            message->vel.z = 2.0 * *f3 * var_f20;
            message->accel.x = *f1 * sign * var_f20;
            message->accel.y = *f2 * var_f20;
            message->accel.z = *f3 * var_f20;

            iMod8 = (i % 8);
            message->scale = D_80283690[iMod8].x * baseScale;
            message->rotZ = 0;
            message->rotVelZ = sign * 107;
            message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].curYaw);
            message->appearTime = 14;
            message->unk_24 = arg4;
            message->deleteTime = 240;
            if (cond) {
                message->deleteTime = 10;
            }
            message->unk_48 = 255.0f;
        }
    }
}

void btl_bonk_update(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00) {
            s32 modelIdx = message->entityModelIndex;

            found = TRUE;
            if (message->unk_24 != 0) {
                message->unk_24--;
                if (message->unk_24 == 0) {
                    clear_entity_model_flags(modelIdx, ENTITY_MODEL_FLAG_HIDDEN);
                }
                exec_entity_model_commandlist(modelIdx);
                break;
            }

            exec_entity_model_commandlist(modelIdx);
            if (message->appearTime >= 0) {
                message->pos.x += message->vel.x;
                message->pos.y += message->vel.y;
                message->pos.z += message->vel.z;
            }
            message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].curYaw);
            message->rotZ += message->rotVelZ;
            message->rotZ = clamp_angle(message->rotZ);
            message->rotVelZ *= 0.8;
            if (message->appearTime < 10) {
                message->accel.x *= 0.5;
                message->accel.y *= 0.5;
                message->accel.z *= 0.5;
                message->vel.x = message->accel.x;
                message->vel.y = message->accel.y;
                message->vel.z = message->accel.z;
            }

            message->appearTime--;
            if (message->appearTime < 0) {
                message->deleteTime--;
                if (message->deleteTime < 0) {
                    free_entity_model_by_index(modelIdx);
                    message->unk_00 = FALSE;
                }
            }
        }
    }

    if (!found) {
        heap_free(popup->message);
        popup->message = NULL;
        free_popup(popup);
    }
}

void btl_bonk_render(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    Matrix4f sp18;
    Matrix4f mtxRotX;
    Matrix4f mtxRotY;
    Matrix4f mtxRotZ;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f mtxScale;
    Mtx sp218;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00) {
            if (message->unk_24 != 0) {
                break;
            } else {
                s32 modelIdx = message->entityModelIndex;

                guTranslateF(sp18, message->pos.x, message->pos.y, message->pos.z);
                guRotateF(mtxRotX, 0.0f, 1.0f, 0.0f, 0.0f);
                guRotateF(mtxRotY, message->rotY, 0.0f, 1.0f, 0.0f);
                guRotateF(mtxRotZ, message->rotZ, 0.0f, 0.0f, 1.0f);
                guScaleF(mtxScale, message->scale, message->scale, message->scale);
                guMtxCatF(mtxRotZ, mtxRotX, sp158);
                guMtxCatF(sp158, mtxRotY, sp118);
                guMtxCatF(mtxScale, sp118, sp158);
                guMtxCatF(sp158, sp18, sp198);
                guMtxF2L(sp198, &sp218);
                draw_entity_model_A(modelIdx, &sp218);
            }
        }
    }
}

void btl_bonk_setup_gfx(void* data) {
    Message* message = data;
    s32 alphaAmt = message->deleteTime;

    if (alphaAmt > 10) {
        alphaAmt = 10;
    }
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, (alphaAmt * 255) / 10);
}

void btl_bonk_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];

        if (popup->active != 0 && (popup->active & 0x10)) {
            Message* message = popup->message;
            s32 j;

            for (j = 0; j < popup->messageIndex; j++, message++) {
                if (message->unk_00) {
                    message->unk_24 = 0;
                    message->appearTime = 1;
                    message->deleteTime = 20;
                }
            }
        }
    }
}

API_CALLABLE(ShowImmuneBonk) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);

    show_immune_bonk(x, y, z, arg4, arg5, arg6);
    return ApiStatus_DONE2;
}

API_CALLABLE(ForceImmuneBonkCleanup) {
    btl_bonk_cleanup();
    return ApiStatus_DONE2;
}

// show a popup message bubble with a message selected from BattleMessages
void btl_show_battle_message(s32 messageIndex, s32 duration) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = FALSE;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->showMsgState = BTL_MSG_STATE_INIT;
        popup->needsInit = TRUE;
        popup->message = NULL;
        BattlePopupMessageVar = 0;
        bPopupMessage = popup;
        ActionCommandTipVisible = FALSE;
        BattleMessage_BoxPosLocked = FALSE;
        BattleMessage_CurBoxPosY = 0;
        BattleMessage_CurBoxOffsetY = 0;
    }
}

// show a popup message bubble with a message selected from BattleMessages
void btl_show_variable_battle_message(s32 messageIndex, s32 duration, s32 varValue) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = FALSE;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->showMsgState = BTL_MSG_STATE_INIT;
        popup->needsInit = TRUE;
        popup->message = NULL;
        BattlePopupMessageVar = varValue;
        bPopupMessage = popup;
        ActionCommandTipVisible = FALSE;
        BattleMessage_BoxPosLocked = FALSE;
        BattleMessage_CurBoxPosY = 0;
        BattleMessage_CurBoxOffsetY = 0;
    }
}

s32 btl_is_popup_displayed(void) {
    return bPopupMessage != NULL;
}

void btl_set_popup_duration(s32 duration) {
    PopupMessage* popup = bPopupMessage;

    if (ActionCommandTipVisible && popup != NULL) {
        popup->duration = duration;
    }
}

void btl_message_lock_box_pos(void) {
    BattleMessage_BoxPosLocked = TRUE;
}

void btl_message_unlock_box_pos(void) {
    BattleMessage_BoxPosLocked = FALSE;
}

void close_action_command_instruction_popup(void) {
    PopupMessage* popup = bPopupMessage;

    if (popup != NULL
        && popup->messageIndex <= BTL_MSG_LAST_ACTION_TIP
        && popup->messageIndex >= BTL_MSG_FIRST_ACTION_TIP
    ) {
        popup->duration = 0;
    }
}

void btl_update_message_popup(void* data) {
    PopupMessage* popup = data;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 shouldDisposeWindow = FALSE;

    s32 actionCommandMode;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_MOVE:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            switch (popup->showMsgState) {
                default:
                    break;
                case BTL_MSG_STATE_INIT:
                    popup->showMsgState = BTL_MSG_STATE_POPUP_PRE_DELAY;
                    break;
                case BTL_MSG_STATE_POPUP_PRE_DELAY:
                    popup->showMsgState = BTL_MSG_STATE_POPUP_DELAY;
                    break;
                case BTL_MSG_STATE_POPUP_DELAY:
                    if (battleStatus->curButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->showMsgState = BTL_MSG_STATE_POPUP_POST_DELAY;
                    }
                    break;
                case BTL_MSG_STATE_POPUP_POST_DELAY:
                    popup->showMsgState = BTL_MSG_STATE_POPUP_DISPOSE;
                    break;
                case BTL_MSG_STATE_POPUP_DISPOSE:
                    shouldDisposeWindow = TRUE;
                    break;
            }
            break;
        // move action command tips
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
        case BTL_MSG_ACTION_TIP_MASH_BUTTON:
        case BTL_MSG_ACTION_TIP_MASH_LEFT:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_1:
        case BTL_MSG_ACTION_TIP_UNUSED_2:
        case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
        case BTL_MSG_ACTION_TIP_NOT_USED_1:
        case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
        case BTL_MSG_ACTION_TIP_NOT_USED_2:
        case BTL_MSG_ACTION_TIP_MASH_BOTH:
        case BTL_MSG_ACTION_TIP_UNUSED_3:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
        case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_4:
        case BTL_MSG_ACTION_TIP_BREAK_FREE:
        case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
        case BTL_MSG_ACTION_TIP_NOT_USED_3:
            actionCommandMode = battleStatus->actionCommandMode;
            ActionCommandTipVisible = TRUE;
            if (actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
                ActionCommandTipVisible = FALSE;
                shouldDisposeWindow = TRUE;
                break;
            }

            switch (popup->showMsgState) {
                case BTL_MSG_STATE_INIT:
                    gBattleStatus.flags1 |= BS_FLAGS1_4000;
                    gBattleStatus.flags1 &= ~BS_FLAGS1_10000;
                    switch (popup->messageIndex) {
                        case BTL_MSG_ACTION_TIP_MASH_LEFT:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            hud_element_create_transform_B(HID_BattleMessage2);
                            break;
                        case BTL_MSG_ACTION_TIP_UNUSED_1:
                            HID_BattleMessage1 = hud_element_create(&HES_CUpButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);

                            HID_BattleMessage3 = hud_element_create(&HES_CLeftButton);
                            hud_element_set_flags(HID_BattleMessage3, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage3, -100, -100);

                            HID_BattleMessage4 = hud_element_create(&HES_CRightButton);
                            hud_element_set_flags(HID_BattleMessage4, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage4, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_UNUSED_2:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
                            HID_BattleMessage1 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);

                            HID_BattleMessage3 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(HID_BattleMessage3, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage3, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_NOT_USED_1:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
                            HID_BattleMessage1 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_NOT_USED_2:
                            HID_BattleMessage1 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            HID_BattleMessage2 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_MASH_BOTH:
                            HID_BattleMessage1 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
                            HID_BattleMessage1 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_AButtonDown);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
                            HID_BattleMessage1 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);

                            HID_BattleMessage2 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(HID_BattleMessage2, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage2, -100, -100);
                            hud_element_create_transform_B(HID_BattleMessage2);

                            HID_BattleMessage3 = hud_element_create(&HES_AimReticle);
                            hud_element_set_flags(HID_BattleMessage3, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage3, -100, -100);
                            hud_element_create_transform_B(HID_BattleMessage3);
                            break;
                        case BTL_MSG_ACTION_TIP_BREAK_FREE:
                        case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
                            HID_BattleMessage1 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            // fallthrough
                        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
                        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
                        case BTL_MSG_ACTION_TIP_MASH_BUTTON:
                        case BTL_MSG_ACTION_TIP_UNUSED_3:
                        case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
                        case BTL_MSG_ACTION_TIP_UNUSED_4:
                        case BTL_MSG_ACTION_TIP_NOT_USED_3:
                            HID_BattleMessage1 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                    }
                    popup->showMsgState = BTL_MSG_STATE_ACTION_TIP_DELAY;
                    break;
                case BTL_MSG_STATE_ACTION_TIP_DELAY:
                    if (gBattleStatus.flags1 & BS_FLAGS1_10000) {
                        gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
                        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        popup->duration = 0;
                        popup->showMsgState = BTL_MSG_STATE_ACTION_TIP_DISPOSE;
                        break;
                    }

                    if (!(gBattleStatus.flags1 & BS_FLAGS1_4000)
                        && (actionCommandMode != ACTION_COMMAND_MODE_TUTORIAL)
                    ) {
                        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        switch (popup->messageIndex) {
                            case BTL_MSG_ACTION_TIP_MASH_BUTTON:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_MASH_LEFT:
                                hud_element_set_script(HID_BattleMessage1, &HES_StickMashLeft);
                                break;
                            case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
                                hud_element_set_script(HID_BattleMessage1, &HES_StickTapLeft);
                                hud_element_set_script(HID_BattleMessage2, &HES_TimingBlink);
                                break;
                            case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
                                hud_element_set_script(HID_BattleMessage1, &HES_StickTapLeft);
                                hud_element_set_script(HID_BattleMessage2, &HES_AimTarget);
                                break;
                            case BTL_MSG_ACTION_TIP_UNUSED_1:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashCUpButton);
                                hud_element_set_script(HID_BattleMessage2, &HES_MashCDownButton1);
                                hud_element_set_script(HID_BattleMessage3, &HES_MashCLeftButton);
                                hud_element_set_script(HID_BattleMessage4, &HES_MashCRightButton1);
                                break;
                            case BTL_MSG_ACTION_TIP_UNUSED_2:
                                hud_element_set_script(HID_BattleMessage1, &HES_StickBackAndForth);
                                break;
                            case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
                                hud_element_set_script(HID_BattleMessage1, &HES_PressAButton);
                                hud_element_set_script(HID_BattleMessage2, &HES_PressBButton);
                                hud_element_set_script(HID_BattleMessage3, &HES_PressCDownButton);
                                break;
                            case BTL_MSG_ACTION_TIP_NOT_USED_1:
                                hud_element_set_script(HID_BattleMessage1, &HES_RotateStickCW);
                                break;
                            case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
                                hud_element_set_script(HID_BattleMessage1, &HES_TimingBlink);
                                hud_element_set_script(HID_BattleMessage2, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_NOT_USED_2:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashAButton);
                                hud_element_set_script(HID_BattleMessage2, &HES_MashBButton2);
                                break;
                            case BTL_MSG_ACTION_TIP_MASH_BOTH:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashAButton);
                                hud_element_set_script(HID_BattleMessage2, &HES_MashBButton1);
                                break;
                            case BTL_MSG_ACTION_TIP_UNUSED_3:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
                                hud_element_set_script(HID_BattleMessage1, &HES_TimingBlink);
                                hud_element_set_script(HID_BattleMessage2, &HES_PressAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
                                hud_element_set_script(HID_BattleMessage1, &HES_StickTapRight);
                                break;
                            case BTL_MSG_ACTION_TIP_UNUSED_4:
                                hud_element_set_script(HID_BattleMessage1, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_BREAK_FREE:
                            case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
                                hud_element_set_script(HID_BattleMessage1, &HES_PressAButton);
                                // fallthrough
                            case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
                            case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
                            case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
                            case BTL_MSG_ACTION_TIP_NOT_USED_3:
                                hud_element_set_script(HID_BattleMessage1, &HES_PressAButton);
                                break;
                        }
                        if (popup->duration != -1) {
                            popup->duration = 30;
                        }
                        popup->showMsgState = BTL_MSG_STATE_ACTION_TIP_DISPOSE;
                        break;
                    }
                    break;
                case BTL_MSG_STATE_ACTION_TIP_DISPOSE:
                    if ((actionCommandMode != ACTION_COMMAND_MODE_TUTORIAL)
                        || (gBattleStatus.flags1 & BS_FLAGS1_10000)
                    ) {
                        s16* duration;

                        if (BattleMessage_CurBoxPosY < 192) {
                            if (!BattleMessage_BoxPosLocked) {
                                BattleMessage_CurBoxPosY += 10;
                                if (BattleMessage_CurBoxPosY > 192) {
                                    BattleMessage_CurBoxPosY = 192;
                                }
                            } else {
                                break;
                            }
                        }

                        gWindows[WINDOW_ID_BATTLE_POPUP].pos.y = BattleMessage_CurBoxPosY + BattleMessage_CurBoxOffsetY;

                        if (popup->duration == -1) {
                            break;
                        }

                        if (popup->duration != 0) {
                            popup->duration--;
                            break;
                        }

                        switch (popup->messageIndex) {
                            case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
                            case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
                            case BTL_MSG_ACTION_TIP_MASH_BUTTON:
                            case BTL_MSG_ACTION_TIP_MASH_LEFT:
                            case BTL_MSG_ACTION_TIP_UNUSED_2:
                            case BTL_MSG_ACTION_TIP_NOT_USED_1:
                            case BTL_MSG_ACTION_TIP_UNUSED_3:
                            case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
                            case BTL_MSG_ACTION_TIP_UNUSED_4:
                            case BTL_MSG_ACTION_TIP_BREAK_FREE:
                            case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
                            case BTL_MSG_ACTION_TIP_NOT_USED_3:
                                hud_element_free(HID_BattleMessage1);
                                break;
                            case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
                            case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
                            case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
                            case BTL_MSG_ACTION_TIP_NOT_USED_2:
                            case BTL_MSG_ACTION_TIP_MASH_BOTH:
                            case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
                                hud_element_free(HID_BattleMessage1);
                                hud_element_free(HID_BattleMessage2);
                                break;
                            case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
                            case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
                                hud_element_free(HID_BattleMessage1);
                                hud_element_free(HID_BattleMessage2);
                                hud_element_free(HID_BattleMessage3);
                                break;
                            case BTL_MSG_ACTION_TIP_UNUSED_1:
                                hud_element_free(HID_BattleMessage1);
                                hud_element_free(HID_BattleMessage2);
                                hud_element_free(HID_BattleMessage3);
                                hud_element_free(HID_BattleMessage4);
                                break;
                        }
                        ActionCommandTipVisible = FALSE;
                        shouldDisposeWindow = TRUE;
                    }
                    break;
            }
            break;
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
            switch (popup->showMsgState) {
                default:
                    break;
                case BTL_MSG_STATE_INIT:
                    popup->showMsgState = BTL_MSG_STATE_ERROR_PRE_DELAY;
                    break;
                case BTL_MSG_STATE_ERROR_PRE_DELAY:
                    popup->showMsgState = BTL_MSG_STATE_ERROR_DELAY;
                    break;
                case BTL_MSG_STATE_ERROR_DELAY:
                    if (battleStatus->curButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->showMsgState = BTL_MSG_STATE_ERROR_POST_DELAY;
                    }
                    break;
                case BTL_MSG_STATE_ERROR_POST_DELAY:
                    popup->showMsgState = BTL_MSG_STATE_ERROR_DISPOSE;
                    break;
                case BTL_MSG_STATE_ERROR_DISPOSE:
                    shouldDisposeWindow = TRUE;
                    break;
            }
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            switch (popup->showMsgState) {
                case BTL_MSG_STATE_INIT:
                    switch (popup->messageIndex) {
                        case BTL_MSG_HAMMER_DISABLED_1:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuHammer1);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_HAMMER_DISABLED_2:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuHammer2);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_HAMMER_DISABLED_3:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuHammer3);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_1:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuBoots1);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_2:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuBoots2);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_3:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuBoots3);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                        case BTL_MSG_ITEMS_DISABLED:
                            HID_BattleMessage1 = hud_element_create(&HES_Item_MenuItems);
                            hud_element_set_flags(HID_BattleMessage1, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(HID_BattleMessage1, -100, -100);
                            break;
                    }
                    popup->showMsgState = BTL_MSG_STATE_DISABLED_DELAY;
                    break;
                case BTL_MSG_STATE_DISABLED_DELAY:
                    if (popup->duration != 0) {
                        popup->duration--;
                        break;
                    }
                    shouldDisposeWindow = TRUE;
                    hud_element_free(HID_BattleMessage1);
                    break;
            }
            break;
    }
    if (shouldDisposeWindow) {
        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_HIDE);
        bPopupMessage = NULL;
        free_popup(popup);
    }
}

#if VERSION_IQUE
#define TIP_X_PRL 83
#define TIP_X_HLT1 44
#define TIP_X_HLT2 67
#define TIP_X_PBST 124
#define TIP_X_MB 70
#define TIP_X_ML 69
#define TIP_X_HLA1 43
#define TIP_X_HLA2 177
#define TIP_X_PBS1 105
#define TIP_X_PBS2 83
#define TIP_X_PBS3 127
#define TIP_X_PWT1 40
#define TIP_X_PWT2 106
#define TIP_X_MB1 95
#define TIP_X_MB2 116
#define TIP_X_HTT 58
#define TIP_X_HTR1 39
#define TIP_X_HTR2 55
#define TIP_X_MTA1 53
#define TIP_X_MTA2 55
#define TIP_X_MTA3 108
#define TIP_X_BF_RD 66
#define TIP_Y_HLA2 17
#define TIP_Y_PBS1 14
#define TIP_Y_PBS2 14
#define TIP_Y_PBS3 14
#define TIP_Y_PWT1 14
#define TIP_Y_MTA1 14
#define TIP_Y_MTA2 32
#define TIP_Y_BF_RD 14
#define TIP_SCALE1 0.6f
#define TIP_SCALE2 0.7f
#else
#define TIP_X_PRL 65
#define TIP_X_HLT1 55
#define TIP_X_HLT2 73
#define TIP_X_PBST 64
#define TIP_X_MB 67
#define TIP_X_ML 56
#define TIP_X_HLA1 65
#define TIP_X_HLA2 146
#define TIP_X_PBS1 86
#define TIP_X_PBS2 64
#define TIP_X_PBS3 108
#define TIP_X_PWT1 105
#define TIP_X_PWT2 65
#define TIP_X_MB1 63
#define TIP_X_MB2 84
#define TIP_X_HTT 124
#define TIP_X_HTR1 56
#define TIP_X_HTR2 53
#define TIP_X_MTA1 107
#define TIP_X_MTA2 210
#define TIP_X_MTA3 56
#define TIP_X_BF_RD 64
#define TIP_Y_HLA2 32
#define TIP_Y_PBS1 13
#define TIP_Y_PBS2 13
#define TIP_Y_PBS3 13
#define TIP_Y_PWT1 13
#define TIP_Y_MTA1 13
#define TIP_Y_MTA2 15
#define TIP_Y_BF_RD 13
#define TIP_SCALE1 0.8f
#define TIP_SCALE2 0.8f
#endif

void btl_message_popup_draw_content(void* data, s32 x, s32 y) {
    PopupMessage* popup = data;
    s32 messageID;
    s32 msgLinesIdx;
    s32 opacity;

    x += 15;
    y += 6;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            messageID = BattleMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += BattleMessage_TextOffsetsY[msgLinesIdx];
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
            messageID = BattleMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += BattleMessage_TextOffsetsY[msgLinesIdx];
            set_message_int_var(BattlePopupMessageVar, 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_CANT_MOVE:
            messageID = BattleMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += BattleMessage_TextOffsetsY[msgLinesIdx];
            set_message_text_var(bActorMessages[BattlePopupMessageVar], 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            messageID = BattleMessages[popup->messageIndex];
            draw_msg(messageID, x + 29, y + 6, 255, MSG_PAL_0F, 0);
            hud_element_set_render_pos(HID_BattleMessage1, x + 13, y + 14);
            hud_element_draw_clipped(HID_BattleMessage1);
            break;
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
        case BTL_MSG_ACTION_TIP_MASH_BUTTON:
        case BTL_MSG_ACTION_TIP_MASH_LEFT:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_1:
        case BTL_MSG_ACTION_TIP_UNUSED_2:
        case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
        case BTL_MSG_ACTION_TIP_NOT_USED_1:
        case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
        case BTL_MSG_ACTION_TIP_NOT_USED_2:
        case BTL_MSG_ACTION_TIP_MASH_BOTH:
        case BTL_MSG_ACTION_TIP_UNUSED_3:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
        case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_4:
        case BTL_MSG_ACTION_TIP_BREAK_FREE:
        case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
        case BTL_MSG_ACTION_TIP_NOT_USED_3:
            opacity = 255;
            if (popup->showMsgState < BTL_MSG_STATE_ACTION_TIP_DISPOSE) {
                opacity = 160;
            }
            if (popup->messageIndex == BTL_MSG_ACTION_TIP_UNUSED_3) {
                opacity = 255;
            }

            x -= 11;
            y -= 6;
            messageID = BattleMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += BattleMessage_TextOffsetsY[msgLinesIdx];
            draw_msg(messageID, x + 11, y + 6, opacity, MSG_PAL_0F, 0);

            switch (popup->messageIndex) {
                case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_PRL, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
                case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_HLT1, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.6f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_HLT2, y + 31);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    hud_element_draw_clipped(HID_BattleMessage2);
                    break;
                case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_PBST, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
                case BTL_MSG_ACTION_TIP_MASH_BUTTON:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_MB, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
                case BTL_MSG_ACTION_TIP_MASH_LEFT:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_ML, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.6f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
                case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_HLA1, y + 13);
                    hud_element_set_scale(HID_BattleMessage1, 0.6f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_HLA2, y + TIP_Y_HLA2);
                    hud_element_set_scale(HID_BattleMessage2, 0.8f);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    func_80144218(HID_BattleMessage2);
                    break;
                case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_PBS1, y + TIP_Y_PBS1);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_PBS2, y + TIP_Y_PBS2);
                    hud_element_set_scale(HID_BattleMessage2, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    hud_element_draw_clipped(HID_BattleMessage2);

                    hud_element_set_render_pos(HID_BattleMessage3, x + TIP_X_PBS3, y + TIP_Y_PBS3);
                    hud_element_set_scale(HID_BattleMessage3, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage3, opacity);
                    hud_element_draw_clipped(HID_BattleMessage3);
                    break;
                case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_PWT1, y + TIP_Y_PWT1);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_PWT2, y + 14);
                    hud_element_set_scale(HID_BattleMessage2, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    hud_element_draw_clipped(HID_BattleMessage2);
                    break;
                case BTL_MSG_ACTION_TIP_MASH_BOTH:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_MB1, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_MB2, y + 14);
                    hud_element_set_scale(HID_BattleMessage2, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    hud_element_draw_clipped(HID_BattleMessage2);
                    break;
                case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_HTT, y + 14);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
                case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_HTR1, y + 31);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_HTR2, y + 14);
                    hud_element_set_scale(HID_BattleMessage2, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    hud_element_draw_clipped(HID_BattleMessage2);
                    break;
                case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_MTA1, y + TIP_Y_MTA1);
                    hud_element_set_scale(HID_BattleMessage1, 0.6f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);

                    hud_element_set_render_pos(HID_BattleMessage2, x + TIP_X_MTA2, y + TIP_Y_MTA2);
                    hud_element_set_scale(HID_BattleMessage2, TIP_SCALE1);
                    hud_element_set_alpha(HID_BattleMessage2, opacity);
                    func_80144218(HID_BattleMessage2);

                    hud_element_set_render_pos(HID_BattleMessage3, x + TIP_X_MTA3, y + 15);
                    hud_element_set_scale(HID_BattleMessage3, TIP_SCALE2);
                    hud_element_set_alpha(HID_BattleMessage3, opacity);
                    func_80144218(HID_BattleMessage3);
                    break;
                case BTL_MSG_ACTION_TIP_BREAK_FREE:
                case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
                    hud_element_set_render_pos(HID_BattleMessage1, x + TIP_X_BF_RD, y + TIP_Y_BF_RD);
                    hud_element_set_scale(HID_BattleMessage1, 0.5f);
                    hud_element_set_alpha(HID_BattleMessage1, opacity);
                    hud_element_draw_clipped(HID_BattleMessage1);
                    break;
            }
            break;
    }
}

void btl_show_message_popup(void* data) {
    PopupMessage* popup = data;
    s32 numLines;
    s32 posX;
    s32 posY = 80;
    s32 width;
    s32 msgWidth;
    s32 height;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = BattleMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 30;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = BattleMessage_BoxSizesY[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, btl_message_popup_draw_content, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            if (popup->needsInit) {
                popup->needsInit = FALSE;
                msgWidth = get_msg_width(BattleMessages[popup->messageIndex], 0) + 55;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                height = 40;
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, btl_message_popup_draw_content, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = BattleMessages[popup->messageIndex];
                set_message_int_var(BattlePopupMessageVar, 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = BattleMessage_BoxSizesY[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, btl_message_popup_draw_content, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_CANT_MOVE:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = BattleMessages[popup->messageIndex];
                set_message_text_var(bActorMessages[BattlePopupMessageVar], 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = BattleMessage_BoxSizesY[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, btl_message_popup_draw_content, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_TIMED:
        case BTL_MSG_ACTION_TIP_PRESS_BEFORE_STRIKE:
        case BTL_MSG_ACTION_TIP_MASH_BUTTON:
        case BTL_MSG_ACTION_TIP_MASH_LEFT:
        case BTL_MSG_ACTION_TIP_HOLD_LEFT_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_1:
        case BTL_MSG_ACTION_TIP_UNUSED_2:
        case BTL_MSG_ACTION_TIP_PRESS_BUTTONS_SHOWN:
        case BTL_MSG_ACTION_TIP_NOT_USED_1:
        case BTL_MSG_ACTION_TIP_PRESS_WITH_TIMING:
        case BTL_MSG_ACTION_TIP_NOT_USED_2:
        case BTL_MSG_ACTION_TIP_MASH_BOTH:
        case BTL_MSG_ACTION_TIP_UNUSED_3:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_TAP:
        case BTL_MSG_ACTION_TIP_HOLD_THEN_RELEASE:
        case BTL_MSG_ACTION_TIP_MOVE_TO_AIM:
        case BTL_MSG_ACTION_TIP_UNUSED_4:
        case BTL_MSG_ACTION_TIP_BREAK_FREE:
        case BTL_MSG_ACTION_TIP_REDUCE_DAMAGE:
        case BTL_MSG_ACTION_TIP_NOT_USED_3:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = BattleMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                posY = 192;
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = BattleMessage_BoxSizesY[numLines];
                if (popup->messageIndex == BTL_MSG_ACTION_TIP_UNUSED_3) {
                    posY = 120;
                    BattleMessage_BoxPosLocked = TRUE;
                }
                BattleMessage_CurBoxPosY = posY;
                BattleMessage_CurBoxOffsetY = BattleMessage_BoxOffsetsY[numLines];

                posY = BattleMessage_CurBoxPosY + BattleMessage_CurBoxOffsetY;
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, btl_message_popup_draw_content, popup, -1);
                if (popup->messageIndex == BTL_MSG_ACTION_TIP_UNUSED_3) {
                    set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
                } else {
                    set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_DARKENED);
                }
            }
            break;
    }
}

API_CALLABLE(ShowMessageBox) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    btl_show_battle_message(messageIndex, duration);
    return ApiStatus_DONE2;
}

API_CALLABLE(ShowVariableMessageBox) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 varValue = evt_get_variable(script, *args++);

    btl_show_variable_battle_message(messageIndex, duration, varValue);
    return ApiStatus_DONE2;
}

API_CALLABLE(IsMessageBoxDisplayed) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, btl_is_popup_displayed());
    return ApiStatus_DONE2;
}

API_CALLABLE(WaitForMessageBoxDone) {
    return !btl_is_popup_displayed() * ApiStatus_DONE2;
}

API_CALLABLE(ForceCloseMessageBox) {
    if (bPopupMessage != NULL) {
        bPopupMessage->duration = 0;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetMessageBoxDuration) {
    btl_set_popup_duration(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(LockMessageBoxPosition) {
    btl_message_lock_box_pos();
    return ApiStatus_DONE2;
}

API_CALLABLE(UnlockMessageBoxPosition) {
    btl_message_unlock_box_pos();
    return ApiStatus_DONE2;
}

void apply_shock_effect(Actor* actor) {
    ActorPart* part = actor->partsTable;

    while (part != NULL) {
        if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE)
            && part->idleAnimations != NULL
            && !(part->flags & ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT)
        ) {
            f32 x = part->curPos.x;
            f32 y = part->curPos.y + (actor->size.y / 10);
            f32 z = part->curPos.z;
            s32 f1 = (part->size.x + (part->size.x / 4)) * actor->scalingFactor;
            s32 f2 = (part->size.y - 2) * actor->scalingFactor;

            if (actor->flags & ACTOR_FLAG_HALF_HEIGHT) {
                y -= actor->size.y / 2;
            }

            fx_flashing_box_shockwave(0, x, y, z, f1, f2);
        }
        part = part->nextPart;
    }
}
