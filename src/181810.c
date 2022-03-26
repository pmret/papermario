#include "common.h"
#include "battle/battle.h"

extern MessagePrintState* gSpeakingActorPrintCtx;
extern MessagePrintState* D_8029FA64;
extern s32 gSpeakingActorPrintIsDone; // unk_08
extern s32 gSpeakingActorTalkAnim;
extern s32 gSpeakingActorIdleAnim;
extern Actor* gSpeakingActor;
extern ActorPart* gSpeakingActorPart;

ApiStatus ActorSpeak(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    s32 msgID;
    s32 actorID;
    s32 partIndex;
    s32 anim;

    f32 headX, headY, headZ;
    s32 screenX, screenY, screenZ;
    s32 msgID2;

    if (isInitialCall) {
        msgID = evt_get_variable(script, *args++);
        actorID = evt_get_variable(script, *args++);
        partIndex = evt_get_variable(script, *args++);
        gSpeakingActorTalkAnim = evt_get_variable(script, *args++);
        gSpeakingActorIdleAnim = evt_get_variable(script, *args++);
        msgID2 = msgID;

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        gSpeakingActor = actor;
        gSpeakingActorPart = part;

        headX = actor->currentPos.x + actor->headOffset.x;
        if (!(actor->flags & ACTOR_FLAG_8000)) {
            headY = actor->size.y + (actor->currentPos.y + actor->headOffset.y);
        } else {
            headY = actor->currentPos.y + actor->headOffset.y + (actor->size.y / 2);
        }

        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        gSpeakingActorPrintIsDone = FALSE;
        gSpeakingActorPrintCtx = msg_get_printer_for_msg(msgID2, &gSpeakingActorPrintIsDone);
        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        script->functionTemp[0] = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_10;
        if (gSpeakingActorTalkAnim >= 0) {
            func_80263E08(actor, part, gSpeakingActorTalkAnim);
        }
        increment_status_menu_disabled();
    }

    if (script->functionTemp[0] == 0) {
        actor = gSpeakingActor;
        part = gSpeakingActorPart;

        headX = actor->currentPos.x + actor->headOffset.x;
        if (!(actor->flags & ACTOR_FLAG_8000)) {
            headY = actor->size.y + (actor->currentPos.y + actor->headOffset.y);
        } else {
            headY = actor->headOffset.y;
            headY = actor->currentPos.y + actor->headOffset.y + (actor->size.y / 2);
        }

        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        if (gSpeakingActorPrintCtx->stateFlags & 0x40) {
            decrement_status_menu_disabled();
            return ApiStatus_DONE1;
        }

        if (gSpeakingActorPrintCtx->stateFlags & 0x80) { // "is talking" flag
            anim = gSpeakingActorTalkAnim;
        } else {
            anim = gSpeakingActorIdleAnim;
        }

        if (anim >= 0) {
            func_80263E08(actor, part, anim);
        }

        if (gSpeakingActorPrintIsDone == TRUE) {
            decrement_status_menu_disabled();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_10;
            return ApiStatus_DONE1;
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus EndActorSpeech(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 flags;
    s32 anim;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;

    if (isInitialCall) {
        s32 actor = evt_get_variable(script, *args++);
        s32 partIndex = evt_get_variable(script, *args++);
        ActorPart* actorPart;

        gSpeakingActorTalkAnim = evt_get_variable(script, *args++);
        gSpeakingActorIdleAnim = evt_get_variable(script, *args++);

        if (actor == ACTOR_SELF) {
            actor = script->owner1.actorID;
        }
        actor = (s32) get_actor(actor);
        actorPart = get_actor_part((Actor*)actor, partIndex);
        gSpeakingActor = (Actor*) actor;
        gSpeakingActorPart = actorPart;
        close_message(gSpeakingActorPrintCtx);
        script->functionTemp[0] = 0;
        increment_status_menu_disabled();
    }

    if (script->functionTemp[0] == 0) {
        Actor* actor = gSpeakingActor;
        ActorPart* actorPart = gSpeakingActorPart;

        x = actor->currentPos.x + actor->headOffset.x;
        if (!(gSpeakingActor->flags & ACTOR_FLAG_8000)) {
            y = actor->currentPos.y + actor->headOffset.y + actor->size.y ;
        } else {
            y = actor->currentPos.y + actor->headOffset.y + actor->size.y / 2;
        }
        z = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, x, y, z, &screenX, &screenY, &screenZ);
        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        flags = gSpeakingActorPrintCtx->stateFlags;
        if (flags & 0x40) {
            decrement_status_menu_disabled();
            return ApiStatus_DONE1;
        }

        if (flags & 0x80) {
            anim = gSpeakingActorTalkAnim;
        } else {
            anim = gSpeakingActorIdleAnim;
        }

        if (anim >= 0) {
            func_80263E08(actor, actorPart, anim);
        }

        if (gSpeakingActorPrintIsDone == TRUE) {
            decrement_status_menu_disabled();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_10;
            return ApiStatus_DONE1;
        }
    }

    return ApiStatus_BLOCK;
}

ApiStatus ShowBattleChoice(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        s32 msgID = evt_get_variable(script, *args);

        script->functionTemp[1] = 0;
        D_8029FA64 = msg_get_printer_for_msg(msgID, &script->functionTemp[1]);
    }

    if (script->functionTemp[1] == 1) {
        u8 currentOption = D_8029FA64->currentOption;

        gSpeakingActorPrintCtx->currentOption = D_8029FA64->currentOption;
        script->varTable[0] = currentOption;

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802535B4(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
        decrement_status_menu_disabled();
    } else {
        increment_status_menu_disabled();
    }
    return ApiStatus_DONE2;
}

ApiStatus OverrideBattleDmaDest(Evt* script, s32 isInitialCall) {
    gBattleDmaDest = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus LoadBattleDmaData(Evt* script, s32 isInitialCall) {
    DmaTable* moveScript = &gBattleAreas[gCurrentBattleSection].dmaTable[evt_get_variable(script, *script->ptrReadPos)];

    if (moveScript == NULL) {
        return ApiStatus_DONE2;
    }

    if (gBattleDmaDest == 0) {
            dma_copy(moveScript->dmaStart, moveScript->dmaEnd, moveScript->dmaDest);
        } else {
            dma_copy(moveScript->dmaStart, moveScript->dmaEnd, gBattleDmaDest);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802536A8(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        battleStatus->unk_92 |= 1;
        gOverrideFlags |= GLOBAL_OVERRIDES_80;
    } else {
        battleStatus->unk_92 &= ~1;
        gOverrideFlags &= ~GLOBAL_OVERRIDES_80;
    }

    return ApiStatus_DONE2;
}


ApiStatus func_80253734(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 val = evt_get_variable(script, *script->ptrReadPos);

    switch (val) {
        case 0:
            battleStatus->unk_432 = -1;
            break;
        case 1:
            battleStatus->unk_432 = 1;
            break;
        case 2:
            battleStatus->unk_432 = -2;
            break;
        case 3:
            battleStatus->unk_432 = 1;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802537C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 a1 = *args++;
    u8 t1;
    f32 t2;
    s32 t3;

    // While loop may not be necessary in the future
    do { get_screen_overlay_params(1, &t1, &t2); } while (0);

    if (t2 < 128.0f) {
        t3 = 0;
    } else {
        t3 = 1;
    }

    evt_set_variable(script, a0, 1);
    evt_set_variable(script, a1, t3);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    sfx_play_sound_at_position(soundID, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtPart(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partIndex);
    sfx_play_sound_at_position(soundID, 0, part->currentPos.x, part->currentPos.y, part->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus PlayLoopingSoundAtActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 idx = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->unk_438[idx] = soundID;
    sfx_play_sound_at_position(soundID, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus StopLoopingSoundAtActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 idx = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (actor->unk_438[idx] == 0) {
        return ApiStatus_DONE2;
    }

    sfx_stop_sound(actor->unk_438[idx]);
    actor->unk_438[idx] = 0;
    return ApiStatus_DONE2;
}

ApiStatus SetForegroundModelsVisibleUnchecked(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
        show_foreground_models_unchecked();
    } else {
        hide_foreground_models_unchecked();
    }
    return ApiStatus_DONE2;
}

ApiStatus SetForegroundModelsVisible(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
        show_foreground_models();
    } else {
        hide_foreground_models();
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80253B30(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    Bytecode a1 = *args++;
    s32 var1 = evt_get_variable(script, *args++);

    evt_set_variable(script, a0, (a1 | 0xFE) | (var1 * 256));
    return ApiStatus_DONE2;
}

ApiStatus MakeStatusField(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 a = *args++;
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);

    evt_set_variable(script, outVar, a | 0x80000000 | (c << 8) | b);
    return ApiStatus_DONE2;
}

s32 is_actor_hp_bar_visible(Actor* actor) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 flags;

    if (is_ability_active(ABILITY_PEEKABOO)) {
        return TRUE;
    }

    flags = get_global_byte((actor->actorType >> 3) + 365);
    if (actor->flags & ACTOR_FLAG_1000) {
        flags |= battleStatus->tattleFlags[actor->actorType >> 3];
    }
    return (flags >> (actor->actorType & 7)) & 1;
}

s32 is_actortype_hpbar_visible(s32 actorType) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 idx;

    if (is_ability_active(ABILITY_PEEKABOO)) {
        return TRUE;
    }

    idx = actorType / 8;
    return ((get_global_byte(idx + 365) | battleStatus->tattleFlags[idx]) >> (actorType - (idx * 8))) & 1;
}

INCLUDE_ASM(s32, "181810", save_tattle_flags);

INCLUDE_ASM(s32, "181810", load_tattle_flags);

ApiStatus func_80253FB0(Evt* script, s32 isInitialCall) {
    gCurrentEncounter.battleOutcome = 3;
    btl_set_state(0x20);

    return ApiStatus_DONE2;
}

ApiStatus MultiplyByActorScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    return ApiStatus_DONE2;
}

ApiStatus MultiplyVec2ByActorScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    evt_set_float_variable(script, args[1], evt_get_float_variable(script, args[1]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

ApiStatus MultiplyVec3ByActorScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    evt_set_float_variable(script, args[1], evt_get_float_variable(script, args[1]) * actor->scalingFactor);
    evt_set_float_variable(script, args[2], evt_get_float_variable(script, args[2]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

ApiStatus ApplyShrinkFromOwner(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 amt = evt_get_variable(script, *args);

    if (actor->debuff == STATUS_SHRINK && amt > 0) {
        amt /= 2;
    }

    evt_set_variable(script, *args, amt);
    return ApiStatus_DONE2;
}

ApiStatus StartRumble(Evt* script, s32 isInitialCall) {
    start_rumble_type(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
