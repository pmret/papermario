#include "common.h"

extern PrintContext* gSpeakingActorPrintCtx;
extern s32 gSpeakingActorPrintIsDone; // unk_08
extern s32 gSpeakingActorTalkAnim;
extern s32 gSpeakingActorIdleAnim;
extern Actor* gSpeakingActor;
extern ActorPart* gSpeakingActorPart;

#ifdef NON_MATCHING
void clamp_printer_coords(PrintContext* printer, f32 x, f32 y);

// Register allocation issues, otherwise equivalent (?)
ApiStatus ActorSpeak(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    s32 stringID;
    s32 actorID;
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

        if (actorID == ActorId_SELF) {
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
            headY = actor->headOffset.y;
            headY = headY + actor->currentPos.y + (actor->size.y / 2);
        }
        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(Cam_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        {
            s32* isPrintDone = &gSpeakingActorPrintIsDone;
            *isPrintDone = FALSE;
            gSpeakingActorPrintCtx = load_string(stringID2, isPrintDone);
        }
        clamp_printer_coords(gSpeakingActorPrintCtx, screenX, screenY);

        script->functionTemp[0] = 0;
        D_8009A650[0] |= 0x10;
        if (gSpeakingActorTalkAnim >= 0) {
            func_80263E08(actor, part, gSpeakingActorTalkAnim);
        }
        increment_status_menu_disabled();
    }

    if (script->functionTemp[0] == 0) {
        actor = gSpeakingActor;
        part = gSpeakingActorPart;

        headX = actor->currentPos.x + actor->headOffset.x;
        if ((actor->flags & 0x8000) == 0) {
            headY = actor->size.y + (actor->currentPos.y + actor->headOffset.y);
        } else {
            headY = actor->headOffset.y;
            headY = headY + actor->currentPos.y + (actor->size.y / 2);
        }
        headZ = actor->currentPos.z + actor->headOffset.z;
        get_screen_coords(Cam_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

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
            D_8009A650[0] &= ~0x10;
            return ApiStatus_DONE1;
        }
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "code_181810", ActorSpeak);
#endif

INCLUDE_ASM(s32, "code_181810", EndActorSpeech);

INCLUDE_ASM(s32, "code_181810", ShowBattleChoice);

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

INCLUDE_ASM(s32, "code_181810", func_802536A8);

INCLUDE_ASM(s32, "code_181810", func_80253734);

INCLUDE_ASM(s32, "code_181810", func_802537C0);

ApiStatus PlaySoundAtActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    play_sound_at_position(soundID, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_181810", PlaySoundAtPart);

INCLUDE_ASM(s32, "code_181810", PlayLoopingSoundAtActor);

INCLUDE_ASM(s32, "code_181810", StopLoopingSoundAtActor);

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

INCLUDE_ASM(s32, "code_181810", MakeStatusField);

INCLUDE_ASM(s32, "code_181810", is_actor_hp_bar_visible);

INCLUDE_ASM(s32, "code_181810", is_actortype_hpbar_visible);

INCLUDE_ASM(s32, "code_181810", save_tattle_flags);

INCLUDE_ASM(s32, "code_181810", load_tattle_flags);

INCLUDE_ASM(s32, "code_181810", func_80253FB0);

ApiStatus MultiplyByActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    set_float_variable(script, *args, get_float_variable(script, *args) * actor->scalingFactor);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_181810", MultiplyVec2ByActorScale);

INCLUDE_ASM(s32, "code_181810", MultiplyVec3ByActorScale);

INCLUDE_ASM(s32, "code_181810", ApplyShrinkFromOwner);

ApiStatus StartRumble(ScriptInstance* script, s32 isInitialCall) {
    start_rumble_type(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
