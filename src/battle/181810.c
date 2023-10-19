#include "battle/battle.h"

BSS char D_8029F660[0x400]; // unused?

BSS MessagePrintState* gSpeakingActorPrintCtx;
BSS MessagePrintState* D_8029FA64;
BSS s32 gSpeakingActorPrintIsDone; // unk_08
BSS s32 gSpeakingActorTalkAnim;
BSS s32 gSpeakingActorIdleAnim;
BSS Actor* gSpeakingActor;
BSS ActorPart* gSpeakingActorPart;

#define ACTOR_TYPE_LIST_END 0xFF

u8* gBattleDmaDest = NULL;

u8 ActorTypesGhost[] = {
    ACTOR_TYPE_DUPLIGHOST,
    ACTOR_TYPE_GHOST_GOOMBARIO,
    ACTOR_TYPE_GHOST_KOOPER,
    ACTOR_TYPE_GHOST_BOMBETTE,
    ACTOR_TYPE_GHOST_PARAKARRY,
    ACTOR_TYPE_GHOST_BOW,
    ACTOR_TYPE_GHOST_WATT,
    ACTOR_TYPE_GHOST_SUSHIE,
    ACTOR_TYPE_GHOST_LAKILESTER,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesLee[] = {
    ACTOR_TYPE_LEE,
    ACTOR_TYPE_LEE_GOOMBARIO,
    ACTOR_TYPE_LEE_KOOPER,
    ACTOR_TYPE_LEE_BOMBETTE,
    ACTOR_TYPE_LEE_PARAKARRY,
    ACTOR_TYPE_LEE_BOW,
    ACTOR_TYPE_LEE_WATT,
    ACTOR_TYPE_LEE_SUSHIE,
    ACTOR_TYPE_LEE_LAKILESTER,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesCrystalKing[] = {
    ACTOR_TYPE_CRYSTAL_KING,
    ACTOR_TYPE_CRYSTAL_CLONE,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesShyGuyBoss[] = {
    ACTOR_TYPE_TOY_TANK,
    ACTOR_TYPE_LIGHT_BULB,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesBowser[] = {
    ACTOR_TYPE_FINAL_BOWSER_1,
    ACTOR_TYPE_FINAL_BOWSER_2,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesMagikoopa[] = {
    ACTOR_TYPE_MAGIKOOPA,
    ACTOR_TYPE_MAGICLONE,
    ACTOR_TYPE_FLYING_MAGIKOOPA,
    ACTOR_TYPE_FLYING_MAGICLONE,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesRedMagikoopa[] = {
    ACTOR_TYPE_RED_MAGIKOOPA,
    ACTOR_TYPE_FLYING_RED_MAGIKOOPA,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesGreenMagikoopa[] = {
    ACTOR_TYPE_GREEN_MAGIKOOPA,
    ACTOR_TYPE_FLYING_GREEN_MAGIKOOPA,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesGrayMagikoopa[] = {
    ACTOR_TYPE_GRAY_MAGIKOOPA,
    ACTOR_TYPE_FLYING_GRAY_MAGIKOOPA,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesYellowMagikoopa[] = {
    ACTOR_TYPE_YELLOW_MAGIKOOPA,
    ACTOR_TYPE_FLYING_YELLOW_MAGIKOOPA,
    ACTOR_TYPE_LIST_END
};

u8 ActorTypesWhiteMagikoopa[] = {
    ACTOR_TYPE_WHITE_MAGIKOOPA,
    ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA,
    ACTOR_TYPE_LIST_END
};

u8* ActorTypesLists[] = {
    ActorTypesGhost,
    ActorTypesLee,
    ActorTypesCrystalKing,
    ActorTypesShyGuyBoss,
    ActorTypesBowser,
    ActorTypesMagikoopa,
    ActorTypesRedMagikoopa,
    ActorTypesGreenMagikoopa,
    ActorTypesGrayMagikoopa,
    ActorTypesYellowMagikoopa,
    ActorTypesWhiteMagikoopa,
    NULL,
};

API_CALLABLE(ActorSpeak) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    s32 msgID;
    s32 actorID;
    s32 partID;
    s32 anim;

    f32 headX, headY, headZ;
    s32 screenX, screenY, screenZ;
    s32 msgID2;

    if (isInitialCall) {
        msgID = evt_get_variable(script, *args++);
        actorID = evt_get_variable(script, *args++);
        partID = evt_get_variable(script, *args++);
        gSpeakingActorTalkAnim = evt_get_variable(script, *args++);
        gSpeakingActorIdleAnim = evt_get_variable(script, *args++);
        msgID2 = msgID;

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        gSpeakingActor = actor;
        gSpeakingActorPart = part;

        headX = actor->curPos.x + actor->headOffset.x;
        if (!(actor->flags & ACTOR_FLAG_HALF_HEIGHT)) {
            headY = actor->curPos.y + actor->headOffset.y + actor->size.y;
        } else {
            headY = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
        }

        headZ = actor->curPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        gSpeakingActorPrintIsDone = FALSE;
        gSpeakingActorPrintCtx = msg_get_printer_for_msg(msgID2, &gSpeakingActorPrintIsDone);
        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        script->functionTemp[0] = 0;
        gOverrideFlags |= GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
        if (gSpeakingActorTalkAnim >= 0) {
            set_actor_anim_by_ref(actor, part, gSpeakingActorTalkAnim);
        }
        increment_status_bar_disabled();
    }

    if (script->functionTemp[0] == 0) {
        actor = gSpeakingActor;
        part = gSpeakingActorPart;

        headX = actor->curPos.x + actor->headOffset.x;
        if (!(actor->flags & ACTOR_FLAG_HALF_HEIGHT)) {
            headY = actor->curPos.y + actor->headOffset.y + actor->size.y;
        } else {
            headY = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
        }

        headZ = actor->curPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, headX, headY, headZ, &screenX, &screenY, &screenZ);

        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        if (gSpeakingActorPrintCtx->stateFlags & MSG_STATE_FLAG_40) {
            decrement_status_bar_disabled();
            return ApiStatus_DONE1;
        }

        if (gSpeakingActorPrintCtx->stateFlags & MSG_STATE_FLAG_SPEAKING) {
            anim = gSpeakingActorTalkAnim;
        } else {
            anim = gSpeakingActorIdleAnim;
        }

        if (anim >= 0) {
            set_actor_anim_by_ref(actor, part, anim);
        }

        if (gSpeakingActorPrintIsDone == TRUE) {
            decrement_status_bar_disabled();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
            return ApiStatus_DONE1;
        }
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(EndActorSpeech) {
    Bytecode* args = script->ptrReadPos;
    ActorPart* actorPart;
    Actor* actor;
    s32 anim;
    f32 x, y, z;
    s32 screenX, screenY, screenZ;

    if (isInitialCall) {
        s32 actorID = evt_get_variable(script, *args++);
        s32 partID = evt_get_variable(script, *args++);
        
        gSpeakingActorTalkAnim = evt_get_variable(script, *args++);
        gSpeakingActorIdleAnim = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        
        actor = get_actor(actorID);
        actorPart = get_actor_part(actor, partID);
        gSpeakingActor = actor;
        gSpeakingActorPart = actorPart;

        close_message(gSpeakingActorPrintCtx);
        script->functionTemp[0] = 0;
        increment_status_bar_disabled();
    }

    if (script->functionTemp[0] == 0) {
        actor = gSpeakingActor;
        actorPart = gSpeakingActorPart;

        x = actor->curPos.x + actor->headOffset.x;
        if (!(gSpeakingActor->flags & ACTOR_FLAG_HALF_HEIGHT)) {
            y = actor->curPos.y + actor->headOffset.y + actor->size.y ;
        } else {
            y = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
        }
        z = actor->curPos.z + actor->headOffset.z;
        get_screen_coords(CAM_BATTLE, x, y, z, &screenX, &screenY, &screenZ);
        msg_printer_set_origin_pos(gSpeakingActorPrintCtx, screenX, screenY);

        if (gSpeakingActorPrintCtx->stateFlags & MSG_STATE_FLAG_40) {
            decrement_status_bar_disabled();
            return ApiStatus_DONE1;
        }

        if (gSpeakingActorPrintCtx->stateFlags & MSG_STATE_FLAG_SPEAKING) {
            anim = gSpeakingActorTalkAnim;
        } else {
            anim = gSpeakingActorIdleAnim;
        }

        if (anim >= 0) {
            set_actor_anim_by_ref(actor, actorPart, anim);
        }

        if (gSpeakingActorPrintIsDone == TRUE) {
            decrement_status_bar_disabled();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_MESSAGES_OVER_FRONTUI;
            return ApiStatus_DONE1;
        }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(ShowBattleChoice) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        s32 msgID = evt_get_variable(script, *args);

        script->functionTemp[1] = 0;
        D_8029FA64 = msg_get_printer_for_msg(msgID, &script->functionTemp[1]);
    }

    if (script->functionTemp[1] == 1) {
        u8 currentOption = D_8029FA64->curOption;

        gSpeakingActorPrintCtx->curOption = D_8029FA64->curOption;
        script->varTable[0] = currentOption;

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(EnableBattleStatusBar) {
    Bytecode* args = script->ptrReadPos;
    b32 shouldEnable = evt_get_variable(script, *args++);

    if (shouldEnable) {
        decrement_status_bar_disabled();
    } else {
        increment_status_bar_disabled();
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(OverrideBattleDmaDest) {
    gBattleDmaDest = (u8*) evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(LoadBattleDmaData) {
    s32 dmaIndex = evt_get_variable(script, *script->ptrReadPos);
    BattleArea* battleArea = &gBattleAreas[UNPACK_BTL_AREA(gCurrentBattleID)];
    DmaTable* dmaEntry = &battleArea->dmaTable[dmaIndex];

    if (dmaEntry == NULL) {
        return ApiStatus_DONE2;
    }

    if (gBattleDmaDest == NULL) {
        dma_copy(dmaEntry->start, dmaEntry->end, dmaEntry->dest);
    } else {
        dma_copy(dmaEntry->start, dmaEntry->end, gBattleDmaDest);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(EnableBattleFloorReflections) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (evt_get_variable(script, *args++)) {
        battleStatus->reflectFlags |= BS_REFLECT_FLOOR;
        gOverrideFlags |= GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    } else {
        battleStatus->reflectFlags &= ~BS_REFLECT_FLOOR;
        gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetDarknessMode) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 darknessMode = evt_get_variable(script, *args++);

    switch (darknessMode) {
        case BTL_DARKNESS_MODE_0:
            battleStatus->darknessMode = BTL_DARKNESS_STATE_DARK;
            break;
        case BTL_DARKNESS_MODE_1:
            battleStatus->darknessMode = BTL_DARKNESS_STATE_WATT_BASED;
            break;
        case BTL_DARKNESS_MODE_2:
            battleStatus->darknessMode = BTL_DARKNESS_STATE_LOCKED;
            break;
        case BTL_DARKNESS_MODE_3:
            battleStatus->darknessMode = BTL_DARKNESS_STATE_WATT_BASED;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetDarknessStatus) {
    Bytecode* args = script->ptrReadPos;
    s32 out1 = *args++;
    s32 out2 = *args++;
    u8 type;
    f32 amt;
    s32 isLight;

    //TODO While loop may not be necessary in the future
    do { get_screen_overlay_params(SCREEN_LAYER_BACK, &type, &amt); } while (0);

    if (amt < 128.0f) {
        isLight = FALSE;
    } else {
        isLight = TRUE;
    }

    evt_set_variable(script, out1, SCREEN_LAYER_BACK);
    evt_set_variable(script, out2, isLight);

    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundAtActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    sfx_play_sound_at_position(soundID, SOUND_SPACE_DEFAULT, actor->curPos.x, actor->curPos.y, actor->curPos.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(PlaySoundAtPart) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partID);
    sfx_play_sound_at_position(soundID, SOUND_SPACE_DEFAULT, part->curPos.x, part->curPos.y, part->curPos.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(PlayLoopingSoundAtActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 idx = evt_get_variable(script, *args++);
    Bytecode soundID = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->loopingSoundID[idx] = soundID;
    sfx_play_sound_at_position(soundID, SOUND_SPACE_DEFAULT, actor->curPos.x, actor->curPos.y, actor->curPos.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(StopLoopingSoundAtActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 idx = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (actor->loopingSoundID[idx] == 0) {
        return ApiStatus_DONE2;
    }

    sfx_stop_sound(actor->loopingSoundID[idx]);
    actor->loopingSoundID[idx] = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetForegroundModelsVisibleUnchecked) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
        show_foreground_models_unchecked();
    } else {
        hide_foreground_models_unchecked();
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetForegroundModelsVisible) {
    if (evt_get_variable(script, *script->ptrReadPos)) {
        show_foreground_models();
    } else {
        hide_foreground_models();
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(MakeIgnoreResStatusField) {
    Bytecode* args = script->ptrReadPos;
    Bytecode outVar = *args++;
    Bytecode typeFlag = *args++; // STATUS_FLAG_*
    s32 duration = evt_get_variable(script, *args++);

    evt_set_variable(script, outVar, DMG_STATUS_IGNORE_RES(typeFlag, duration));
    return ApiStatus_DONE2;
}

API_CALLABLE(MakeStatusField) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 typeFlag = *args++; // STATUS_FLAG_*
    s32 chance = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    evt_set_variable(script, outVar, DMG_STATUS_KEY(typeFlag, duration, chance));
    return ApiStatus_DONE2;
}

s32 is_actor_health_bar_visible(Actor* actor) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 flags;

    if (is_ability_active(ABILITY_PEEKABOO)) {
        return TRUE;
    }

    flags = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actor->actorType / 8);
    if (actor->flags & ACTOR_FLAG_TYPE_CHANGED) {
        flags |= battleStatus->tattleFlags[actor->actorType / 8];
    }

    return (flags >> (actor->actorType % 8)) & 1;
}

s32 is_actortype_health_bar_visible(s32 actorType) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 flags;
    s32 byteIdx;
    s32 flagIdx;

    if (is_ability_active(ABILITY_PEEKABOO)) {
        return TRUE;
    }

    flags = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8);
    flags |= battleStatus->tattleFlags[actorType / 8];

    return (flags >> (actorType % 8)) & 1;
}

void save_tattle_flags(s32 actorType) {
    BattleStatus* battleStatus = &gBattleStatus;
    u8* types;
    s32 gb;
    s32 i = 0;
    s32 j;
    s32 k;

    while (TRUE) {
        types = ActorTypesLists[i];
        if (types == NULL) {
            break;
        }

        for (j = 0; types[j] != ACTOR_TYPE_LIST_END; j++) {
            if (actorType == types[j]) {
                for (k = 0; types[k] != ACTOR_TYPE_LIST_END; k++) {
                    actorType = types[k];

                    gb = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8);
                    gb |= 1 << (actorType % 8);
                    set_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8, gb);
                    battleStatus->tattleFlags[actorType / 8] |= gb;
                }
                return;
            }
        }
        i++;
    }

    gb = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8);
    gb |= 1 << (actorType % 8);
    set_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8, gb);
    battleStatus->tattleFlags[actorType / 8] |= gb;
}

void load_tattle_flags(s32 actorType) {
    BattleStatus* battleStatus = &gBattleStatus;
    u8* types;
    s32 gb;
    s32 i = 0;
    s32 j;
    s32 k;

    while (TRUE) {
        types = ActorTypesLists[i];
        if (types == NULL) {
            break;
        }

        for (j = 0; types[j] != ACTOR_TYPE_LIST_END; j++) {
            if (actorType == types[j]) {
                for (k = 0; types[k] != ACTOR_TYPE_LIST_END; k++) {
                    actorType = types[k];

                    gb = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8);
                    gb |= 1 << (actorType % 8);
                    battleStatus->tattleFlags[actorType / 8] |= gb;
                }
                return;
            }
        }
        i++;
    }

    gb = get_global_byte(EVT_INDEX_OF_GAME_BYTE(GB_Tattles_00) + actorType / 8);
    gb |= 1 << (actorType % 8);
    battleStatus->tattleFlags[actorType / 8] |= gb;
}

API_CALLABLE(SetEnemiesFled) {
    gCurrentEncounter.battleOutcome = OUTCOME_ENEMY_FLED;
    btl_set_state(BATTLE_STATE_END_BATTLE);

    return ApiStatus_DONE2;
}

API_CALLABLE(MultiplyByActorScale) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    return ApiStatus_DONE2;
}

API_CALLABLE(MultiplyVec2ByActorScale) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    evt_set_float_variable(script, args[1], evt_get_float_variable(script, args[1]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

API_CALLABLE(MultiplyVec3ByActorScale) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    evt_set_float_variable(script, args[0], evt_get_float_variable(script, args[0]) * actor->scalingFactor);
    evt_set_float_variable(script, args[1], evt_get_float_variable(script, args[1]) * actor->scalingFactor);
    evt_set_float_variable(script, args[2], evt_get_float_variable(script, args[2]) * actor->scalingFactor);

    return ApiStatus_DONE2;
}

API_CALLABLE(ApplyShrinkFromOwner) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 amt = evt_get_variable(script, *args);

    if (actor->debuff == STATUS_KEY_SHRINK && amt > 0) {
        amt /= 2;
    }

    evt_set_variable(script, *args++, amt);
    return ApiStatus_DONE2;
}

API_CALLABLE(StartRumble) {
    start_rumble_type(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
