#include "common.h"

extern PrintContext* gSpeakingActorPrintCtx;
extern PrintContext* D_8029FA64;
extern s32 gSpeakingActorPrintIsDone; // unk_08
extern s32 gSpeakingActorTalkAnim;
extern s32 gSpeakingActorIdleAnim;
extern Actor* gSpeakingActor;
extern ActorPart* gSpeakingActorPart;

void clamp_printer_coords(PrintContext* printer, f32 x, f32 y);

ApiStatus ActorSpeak(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    s32 stringID;
    ActorID actorID;
    s32 partIndex;
    PrintContext** printContext;
    s32 anim;

    f32 headX, headY, headZ;
    f32 screenX, screenY, screenZ;
    s32 stringID2;

    if (isInitialCall) {
        stringID = get_variable(script, *args++);
        actorID = get_variable(script, *args++);
        partIndex = get_variable(script, *args++);
        gSpeakingActorTalkAnim = get_variable(script, *args++);
        gSpeakingActorIdleAnim = get_variable(script, *args++);
        stringID2 = stringID;

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        gSpeakingActor = actor;
        gSpeakingActorPart = part;

        headX = actor->currentPos.x + actor->headOffset.x;
        if ((actor->flags & 0x8000) == 0) {
            headY = actor->size.y + (actor->currentPos.y + actor->headOffset.y);
        } else {
            f32 tmp = actor->headOffset.y;
            headY = actor->currentPos.y + tmp + (actor->size.y / 2);
        }
        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        {
            s32* isPrintDone = &gSpeakingActorPrintIsDone;
            *isPrintDone = FALSE;
            gSpeakingActorPrintCtx = load_string(stringID2, isPrintDone);
        }
        clamp_printer_coords(gSpeakingActorPrintCtx, screenX, screenY);

        script->functionTemp[0].s = 0;
        OVERRIDE_FLAG_SET(0x10);
        if (gSpeakingActorTalkAnim >= 0) {
            func_80263E08(actor, part, gSpeakingActorTalkAnim);
        }
        increment_status_menu_disabled();
    }

    if (script->functionTemp[0].s == 0) {
        actor = gSpeakingActor;
        part = gSpeakingActorPart;

        headX = actor->currentPos.x + actor->headOffset.x;
        if ((actor->flags & 0x8000) == 0) {
            headY = actor->size.y + (actor->currentPos.y + actor->headOffset.y);
        } else {
            headY = actor->headOffset.y;
            headY = actor->currentPos.y + actor->headOffset.y + (actor->size.y / 2);
        }
        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        printContext = &gSpeakingActorPrintCtx;
        clamp_printer_coords(*printContext, screenX, screenY);

        if ((*printContext)->stateFlags & 0x40) {
            decrement_status_menu_disabled();
            return ApiStatus_DONE1;
        }

        if ((*printContext)->stateFlags & 0x80) { // "is talking" flag
            anim = gSpeakingActorTalkAnim;
        } else {
            anim = gSpeakingActorIdleAnim;
        }

        if (anim >= 0) {
            func_80263E08(actor, part, anim);
        }

        if (gSpeakingActorPrintIsDone == 1) {
            decrement_status_menu_disabled();
            OVERRIDE_FLAG_UNSET(0x10);
            return ApiStatus_DONE1;
        }
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "code_181810", EndActorSpeech);

ApiStatus ShowBattleChoice(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        s32 stringID = get_variable(script, *args);

        script->functionTemp[1].s = 0;
        D_8029FA64 = load_string(stringID, &script->functionTemp[1].s);
    }

    if (script->functionTemp[1].s == 1) {
        u8 unk_4E8 = D_8029FA64->unk_4E8;

        gSpeakingActorPrintCtx->unk_4E8 = D_8029FA64->unk_4E8;
        script->varTable[0] = unk_4E8;

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802535B4(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos)) {
        decrement_status_menu_disabled();
    } else {
        increment_status_menu_disabled();
    }
    return ApiStatus_DONE2;
}

ApiStatus OverrideBattleDmaDest(ScriptInstance* script, s32 isInitialCall) {
    gBattleDmaDest = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_181810", LoadBattleDmaData);

ApiStatus func_802536A8(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = battleStatus;

    if (get_variable(script, *script->ptrReadPos) != 0) {
        battleStatus2->unk_92 |= 1;
        OVERRIDE_FLAG_SET(0x80);
    } else {
        battleStatus2->unk_92 &= ~1;
        OVERRIDE_FLAG_UNSET(0x80);
    }

    return ApiStatus_DONE2;
}


ApiStatus func_80253734(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 val = get_variable(script, *script->ptrReadPos);

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

ApiStatus func_802537C0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 a1 = *args++;
    f32 t1;
    f32 t2;
    s32 t3;

    // While loop may not be necessary in the future
    do { func_80137DC0(1, &t1, &t2); } while (0);

    if (t2 < 128.0f) {
        t3 = 0;
    } else {
        t3 = 1;
    }

    set_variable(script, a0, 1);
    set_variable(script, a1, t3);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    sfx_play_sound_at_position(soundID, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtPart(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    Bytecode soundID = *args++;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partIndex);
    sfx_play_sound_at_position(soundID, 0, part->currentPos.x, part->currentPos.y, part->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus PlayLoopingSoundAtActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 idx = get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->x[idx] = soundID;
    sfx_play_sound_at_position(soundID, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);

    return ApiStatus_DONE2;
}

ApiStatus StopLoopingSoundAtActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 idx = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (actor->x[idx] == 0) {
        return ApiStatus_DONE2;
    }

    sfx_stop_sound(actor->x[idx]);
    actor->x[idx] = 0;
    return ApiStatus_DONE2;
}

ApiStatus SetForegroundModelsVisibleUnsafe(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos)) {
        show_foreground_models_unsafe();
    } else {
        hide_foreground_models_unsafe();
    }
    return ApiStatus_DONE2;
}

ApiStatus SetForegroundModelsVisible(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos)) {
        show_foreground_models();
    } else {
        hide_foreground_models();
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80253B30(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    Bytecode a1 = *args++;
    s32 var1 = get_variable(script, *args++);

    set_variable(script, a0, (a1 | 0xFE) | (var1 * 256));
    return ApiStatus_DONE2;
}

ApiStatus MakeStatusField(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 a = *args++;
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    set_variable(script, outVar, a | 0x80000000 | (c << 8) | b);
    return ApiStatus_DONE2;
}

s32 is_actor_hp_bar_visible(Actor* actor) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 flags;

    if (is_ability_active(ABILITY_PEEKABOO)) {
        return TRUE;
    }

    flags = get_global_byte((actor->actorType >> 3) + 365);
    if (actor->flags & 0x1000) {
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

INCLUDE_ASM(s32, "code_181810", save_tattle_flags);

INCLUDE_ASM(s32, "code_181810", load_tattle_flags);

ApiStatus func_80253FB0(ScriptInstance* script, s32 isInitialCall) {
    gCurrentEncounter.battleOutcome = 3;
    func_80241190(0x20);

    return ApiStatus_DONE2;
}

ApiStatus MultiplyByActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    set_float_variable(script, args[0], get_float_variable(script, args[0]) * actor->scalingFactor);
    return ApiStatus_DONE2;
}

ApiStatus MultiplyVec2ByActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    set_float_variable(script, args[0], get_float_variable(script, args[0]) * actor->scalingFactor);
    set_float_variable(script, args[1], get_float_variable(script, args[1]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

ApiStatus MultiplyVec3ByActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    set_float_variable(script, args[0], get_float_variable(script, args[0]) * actor->scalingFactor);
    set_float_variable(script, args[1], get_float_variable(script, args[1]) * actor->scalingFactor);
    set_float_variable(script, args[2], get_float_variable(script, args[2]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

ApiStatus ApplyShrinkFromOwner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 amt = get_variable(script, *args);

    if (actor->debuff == STATUS_SHRINK && amt > 0) {
        amt /= 2;
    }

    set_variable(script, *args, amt);
    return ApiStatus_DONE2;
}

ApiStatus StartRumble(ScriptInstance* script, s32 isInitialCall) {
    start_rumble_type(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
