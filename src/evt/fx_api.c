#include "common.h"
#include "effects.h"

void show_start_recovery_shimmer(f32 x, f32 y, f32 z, s32 amt) {
    fx_stars_shimmer(1, x, y, z, amt + 30, amt + 30, (amt / 2) + 10, 30);
}

void show_recovery_shimmer(f32 x, f32 y, f32 z, s32 amt) {
    fx_stars_shimmer(2, x, y, z, amt + 30, amt + 30, (amt / 2) + 10, 30);
}

ApiStatus ShowStartRecoveryShimmer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    show_start_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(SOUND_2055, SOUND_SPACE_MODE_0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus ShowRecoveryShimmer(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    show_recovery_shimmer(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(SOUND_378, SOUND_SPACE_MODE_0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D7690(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 angle = evt_get_float_variable(script, *args++);
    f32 magnitude = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    f32 offsetX, offsetY, offsetZ;
    f32 sinA, cosA;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    offsetX = rand_int(10) - 5;
    offsetZ = rand_int(10) - 5;
    offsetY = -2.0f - ((SQ(offsetX) + SQ(offsetZ)) / 5.0f);
    sinA = sin_rad(DEG_TO_RAD(angle));
    cosA = cos_rad(DEG_TO_RAD(angle));
    fx_cloud_trail(
        posX + ((sinA * magnitude * script->functionTemp[0]) / duration) + offsetX,
        posY + 15.5f + offsetY,
        posZ + ((-cosA * magnitude * script->functionTemp[0]) / duration) + offsetZ,
        0.0f
    );

    script->functionTemp[0]++;
    if (script->functionTemp[0] < duration) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus ShowEmote(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 emoteType = evt_get_variable(script, *args++);
    f32 pitch = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 emoterType = evt_get_variable(script, *args++);
    f32 dX = evt_get_float_variable(script, *args++);
    f32 dY = evt_get_float_variable(script, *args++);
    f32 dZ = evt_get_float_variable(script, *args++);
    f32 radius = evt_get_float_variable(script, *args++);

    Npc* npc;
    EffectInstance* emoteHandle;
    f32 x, y, z, r;

    switch (emoterType) {
        case EMOTER_PLAYER:
            // show emote from player
            npc = (Npc*)-1;
            x = 0.0f;
            y = (gPlayerStatus.colliderHeight * 2) / 3;
            z = 0.0f;
            r = gPlayerStatus.colliderHeight / 3;
            break;
        case EMOTER_NPC:
            // show emote from NPC
            npc = resolve_npc(script, npcID);
            if (npc == NULL) {
                return ApiStatus_DONE2;
            }
            x = 0.0f;
            y = (npc->collisionHeight * 4) / 5;
            z = 0.0f;
            r = npc->collisionHeight / 3;
            break;
        default:
            // show emote at arbitrary position
            x = dX;
            y = dY;
            z = dZ;
            r = radius;
            npc = NULL;
            break;
    }

    fx_emote(emoteType, npc, x, y, z, r, pitch, duration, &emoteHandle);
    return ApiStatus_DONE2;
}

ApiStatus RemoveEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    remove_effect((EffectInstance*)evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus DismissEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->flags |= FX_INSTANCE_FLAG_DISMISS;
    return ApiStatus_DONE2;
}

ApiStatus DismissItemOutline(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.gotItemOutline->timeLeft = 10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B74(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    // function is never called, so the effect type can't be inferred
    effect->data.any[12] = 5;
    return ApiStatus_DONE2;
}

ApiStatus InterpMotionBlurParams(Evt* script, s32 isInitialCall) {
    s32 centerX0 = script->varTable[1];
    s32 centerY0 = script->varTable[2];
    s32 centerX1 = script->varTable[3];
    s32 centerY1 = script->varTable[4];
    s32 finalAmt = script->varTable[5];
    s32 duration = script->varTable[6];
    s32 delta;
    u8 overlayType;
    f32 initialAmt;

    if (isInitialCall) {
        script->functionTemp[0] = duration;
        get_screen_overlay_params(SCREEN_LAYER_BACK, &overlayType, &initialAmt);
        script->functionTemp[1] = initialAmt;
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, centerX0, centerY0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, centerX1, centerY1);
    }

    get_screen_overlay_params(SCREEN_LAYER_BACK, &overlayType, &initialAmt);
    // lerp from initialAmt (stored in functionTemp[1]) to finalAmt (stored in varTable[5])
    delta = (script->functionTemp[1] - finalAmt);
    set_screen_overlay_params_back(OVERLAY_BLUR, (delta * script->functionTemp[0] / duration) + finalAmt);

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        set_screen_overlay_params_back(OVERLAY_BLUR, finalAmt);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_UpdateMotionBlurParams = {
    EVT_CALL(InterpMotionBlurParams)
    EVT_RETURN
    EVT_END
};

ApiStatus SetMotionBlurParams(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 centerX0 = evt_get_variable(script, *args++);
    s32 centerY0 = evt_get_variable(script, *args++);
    s32 centerX1 = evt_get_variable(script, *args++);
    s32 centerY1 = evt_get_variable(script, *args++);
    s32 finalAmt = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    Evt* blurEvt = start_script(&EVS_UpdateMotionBlurParams, EVT_PRIORITY_1, 0);
    blurEvt->varTable[0] = var0;
    blurEvt->varTable[1] = centerX0;
    blurEvt->varTable[2] = centerY0;
    blurEvt->varTable[3] = centerX1;
    blurEvt->varTable[4] = centerY1;
    blurEvt->varTable[5] = finalAmt;
    blurEvt->varTable[6] = duration;

    return ApiStatus_DONE2;
}

ApiStatus ShowSweat(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 type = evt_get_variable(script, *args++);
    f32 pitch = evt_get_float_variable(script, *args++);
    s32 emoterType = evt_get_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 radius = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    Npc* npc;
    f32 x, y, z, r;

    switch (emoterType) {
        case EMOTER_PLAYER:
            x = gPlayerStatus.pos.x;
            y = gPlayerStatus.pos.y + (gPlayerStatus.colliderHeight * 2) / 3;
            z = gPlayerStatus.pos.z;
            r = gPlayerStatus.colliderHeight / 3;
            break;
        case EMOTER_NPC:
            npc = resolve_npc(script, npcID);
            if (npc == NULL) {
                return ApiStatus_DONE2;
            }
            x = npc->pos.x;
            y = npc->pos.y + (npc->collisionHeight * 2) / 3;
            z = npc->pos.z;
            r = npc->collisionHeight / 3;
            break;
        default:
            x = posX;
            y = posY;
            z = posZ;
            r = radius;
            break;
    }

    fx_sweat(type, x, y, z, r, pitch, duration);
    return ApiStatus_DONE2;
}

ApiStatus ShowSleepBubble(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 type = evt_get_variable(script, *args++);
    f32 pitch = evt_get_float_variable(script, *args++);
    s32 emoterType = evt_get_variable(script, *args++);
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    f32 posZ = evt_get_float_variable(script, *args++);
    f32 radius = evt_get_float_variable(script, *args++);
    s32 outVar = *args++;

    Npc* npc;
    f32 x, y, z, r;
    EffectInstance* effectHandle;

    switch (emoterType) {
        case EMOTER_PLAYER:
            x = gPlayerStatus.pos.x;
            y = gPlayerStatus.pos.y + (gPlayerStatus.colliderHeight * 2) / 3;
            z = gPlayerStatus.pos.z;
            r = gPlayerStatus.colliderHeight / 3;
            break;
        case EMOTER_NPC:
            npc = resolve_npc(script, npcID);
            if (npc == NULL) {
                return ApiStatus_DONE2;
            }
            x = npc->pos.x;
            y = npc->pos.y + (npc->collisionHeight * 2) / 3;
            z = npc->pos.z;
            r = npc->collisionHeight / 3;
            break;
        default:
            x = posX;
            y = posY;
            z = posZ;
            r = radius;
            break;
    }

    fx_sleep_bubble(type, x, y, z, r, pitch, &effectHandle);
    evt_set_variable(script, outVar, (s32)effectHandle);
    return ApiStatus_DONE2;
}

ApiStatus SetSleepBubbleTimeLeft(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    s32 value = evt_get_variable(script, *args++);

    effect->data.sleepBubble->timeLeft = value;
    return ApiStatus_DONE2;
}

ApiStatus PlayEffect(Evt* script, s32 isInitialCall) {
    Bytecode* intArgs = script->ptrReadPos;
    Bytecode* floatArgs = script->ptrReadPos;
    Bytecode* args = script->ptrReadPos;

    s32 effectID = evt_get_variable(script, *intArgs++);
    EffectInstance* effectRet = NULL;
    s32 new_var;

    s32 iVar1, iVar2, iVar3, iVar4, iVar5;
    s32 iVar6, iVar7, iVar8, iVar9, iVar10;

    f32 fVar1, fVar2, fVar3, fVar4, fVar5, fVar6;
    f32 fVar7, fVar8, fVar9, fVar10, fVar11;

    EffectInstance* sp30;
    EffectInstance* sp34;
    EffectInstance* sp38;
    EffectInstance* sp3C;

    s32 a2, a6, a7, a8, a9;

    evt_get_variable(script, *floatArgs++);
    evt_get_variable(script, *args++);

    new_var = evt_get_variable(script, *intArgs++);
    iVar2 = evt_get_variable(script, *intArgs++);
    iVar3 = evt_get_variable(script, *intArgs++);
    iVar4 = evt_get_variable(script, *intArgs++);
    iVar5 = evt_get_variable(script, *intArgs++);
    iVar6 = evt_get_variable(script, *intArgs++);
    iVar7 = evt_get_variable(script, *intArgs++);
    iVar8 = evt_get_variable(script, *intArgs++);
    iVar9 = evt_get_variable(script, *intArgs++);
    iVar10 = evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);
    evt_get_variable(script, *intArgs++);

    fVar1 = evt_get_float_variable(script, *floatArgs++);
    fVar2 = evt_get_float_variable(script, *floatArgs++);
    fVar3 = evt_get_float_variable(script, *floatArgs++);
    fVar4 = evt_get_float_variable(script, *floatArgs++);
    fVar5 = evt_get_float_variable(script, *floatArgs++);
    fVar6 = evt_get_float_variable(script, *floatArgs++);
    fVar7 = evt_get_float_variable(script, *floatArgs++);
    fVar8 = evt_get_float_variable(script, *floatArgs++);
    fVar9 = evt_get_float_variable(script, *floatArgs++);
    fVar10 = evt_get_float_variable(script, *floatArgs++);
    fVar11 = evt_get_float_variable(script, *floatArgs++);
    evt_get_float_variable(script, *floatArgs++);
    evt_get_float_variable(script, *floatArgs++);

    args++;
    a2 = *args++;
    args++;
    args++;
    args++;
    a6 = *args++;
    a7 = *args++;
    a8 = *args++;
    a9 = *args++;

    iVar1 = new_var;

    switch (effectID) {
        case EFFECT_00:
            fx_blast(0, fVar1, fVar2, fVar3, 3.0f, iVar5);
            break;
        case EFFECT_BIG_SMOKE_PUFF:
            fx_big_smoke_puff(fVar1, fVar2, fVar3);
            break;
        case EFFECT_LANDING_DUST:
            fx_landing_dust(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_WALKING_DUST:
            fx_walking_dust(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_FLOWER_SPLASH:
            fx_flower_splash(fVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_FLOWER_TRAIL:
            fx_flower_trail(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_CLOUD_PUFF:
            fx_cloud_puff(fVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_CLOUD_TRAIL:
            fx_cloud_trail(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_FOOTPRINT:
            fx_footprint(fVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_FLOATING_FLOWER:
            fx_floating_flower(0, fVar1, fVar2, fVar3, iVar4);
            break;
        case EFFECT_SNOWFLAKE:
            fx_snowflake(fVar1, fVar2, fVar3, iVar4);
            break;
        case EFFECT_STAR:
            fx_star(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8);
            break;
        case EFFECT_EMOTE:
            fx_emote(iVar1, (Npc*) a2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp30);
            evt_set_variable(script, a8, (s32) sp30);
            break;
        case EFFECT_SPARKLES:
            fx_sparkles(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_SHAPE_SPELL:
            fx_shape_spell(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_GATHER_ENERGY_PINK:
            fx_gather_energy_pink(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_DROP_LEAVES:
            fx_drop_leaves(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_DUST:
            fx_dust(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_SHATTERING_STONES:
            fx_shattering_stones(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_SMOKE_RING:
            fx_smoke_ring(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_DAMAGE_STARS:
            fx_damage_stars(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_EXPLOSION:
            fx_explosion(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_LENS_FLARE:
            fx_lens_flare(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_GOT_ITEM_OUTLINE:
            fx_got_item_outline(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_SPIKY_WHITE_AURA:
            fx_spiky_white_aura(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_SMOKE_IMPACT:
            fx_smoke_impact(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, fVar7, iVar8);
            break;
        case EFFECT_DAMAGE_INDICATOR:
            fx_damage_indicator(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, &sp30);
            evt_set_variable(script, a8, (s32) sp30);
            break;
        case EFFECT_PURPLE_RING:
            fx_purple_ring(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8);
            break;
        case EFFECT_STARS_BURST:
            fx_stars_burst(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7);
            break;
        case EFFECT_STARS_SHIMMER:
            fx_stars_shimmer(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, iVar8);
            break;
        case EFFECT_RISING_BUBBLE:
            fx_rising_bubble(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_RING_BLAST:
            fx_ring_blast(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SHOCKWAVE:
            fx_shockwave(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_MUSIC_NOTE:
            fx_music_note(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_SMOKE_BURST:
            fx_smoke_burst(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SWEAT:
            fx_sweat(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7);
            break;
        case EFFECT_SLEEP_BUBBLE:
            fx_sleep_bubble(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, &sp38);
            evt_set_variable(script, a7, (s32) sp38);
            break;
        case EFFECT_WINDY_LEAVES:
            fx_windy_leaves(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_FLAME:
            fx_flame(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_FALLING_LEAVES:
            fx_falling_leaves(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_STARS_SPREAD:
            fx_stars_spread(iVar1, fVar2, fVar3, fVar4, iVar5, iVar6);
            break;
        case EFFECT_STEAM_BURST:
            fx_steam_burst(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_STARS_ORBITING:
            fx_stars_orbiting(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, &sp38);
            evt_set_variable(script, a7, (s32) sp38);
            break;
        case EFFECT_BIG_SNOWFLAKES:
            fx_big_snowflakes(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_DEBUFF:
            fx_debuff(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_GREEN_IMPACT:
            fx_green_impact(iVar1, fVar2, fVar3, fVar4, fVar5);
            break;
        case EFFECT_RADIAL_SHIMMER:
            fx_radial_shimmer(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ENDING_DECALS:
            fx_ending_decals(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_LIGHT_RAYS:
            fx_light_rays(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_LIGHTNING:
            effectRet = fx_lightning(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_FIRE_BREATH:
            effectRet = fx_fire_breath(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9, iVar10);
            break;
        case EFFECT_SHIMMER_BURST:
            fx_shimmer_burst(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ENERGY_SHOCKWAVE:
            fx_energy_shockwave(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SHIMMER_WAVE:
            fx_shimmer_wave(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, iVar8);
            break;
        case EFFECT_AURA:
            fx_aura(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_BULB_GLOW:
            fx_bulb_glow(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, (s32) sp34);
            break;
        case EFFECT_3D:
            fx_effect_3D(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp3C);
            evt_set_variable(script, a9, (s32) sp3C);
            break;
        case EFFECT_BLAST:
            fx_blast(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FIRE_FLOWER:
            effectRet = fx_fire_flower(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_RECOVER:
            effectRet = fx_recover(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_DISABLE_X:
            effectRet = fx_disable_x(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_BOMBETTE_BREAKING:
            effectRet = fx_bombette_breaking(iVar1, iVar2, iVar3, fVar4, iVar5, iVar6);
            break;
        case EFFECT_FIREWORK:
            effectRet = fx_firework(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_CONFETTI:
            effectRet = fx_confetti(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SNOWFALL:
            effectRet = fx_snowfall(iVar1, iVar2);
            break;
        case EFFECT_46:
            effectRet = fx_effect_46(iVar1, (PlayerStatus*) a2, fVar3, iVar4);
            break;
        case EFFECT_GATHER_MAGIC:
            effectRet = fx_gather_magic(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ATTACK_RESULT_TEXT:
            effectRet = fx_attack_result_text(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SMALL_GOLD_SPARKLE:
            effectRet = fx_small_gold_sparkle(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FLASHING_BOX_SHOCKWAVE:
            effectRet = fx_flashing_box_shockwave(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6);
            break;
        case EFFECT_BALLOON:
            effectRet = fx_balloon(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FLOATING_ROCK:
            effectRet = fx_floating_rock(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_CHOMP_DROP:
            effectRet = fx_chomp_drop(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, fVar9, iVar10);
            break;
        case EFFECT_QUIZMO_STAGE:
            effectRet = fx_quizmo_stage(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_RADIATING_ENERGY_ORB:
            effectRet = fx_radiating_energy_orb(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ENERGY_ORB_WAVE:
            effectRet = fx_energy_orb_wave(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_MERLIN_HOUSE_STARS:
            effectRet = fx_merlin_house_stars(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_MOTION_BLUR_FLAME:
            effectRet = fx_motion_blur_flame(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_STAT_CHANGE:
            effectRet = fx_stat_change(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SNAKING_STATIC:
            effectRet = fx_snaking_static(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_THUNDERBOLT_RING:
            effectRet = fx_thunderbolt_ring(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SQUIRT:
            effectRet = fx_squirt(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_WATER_BLOCK:
            effectRet = fx_water_block(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_WATERFALL:
            effectRet = fx_waterfall(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_WATER_FOUNTAIN:
            effectRet = fx_water_fountain(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_UNDERWATER:
            effectRet = fx_underwater(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_LIGHTNING_BOLT:
            effectRet = fx_lightning_bolt(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_WATER_SPLASH:
            effectRet = fx_water_splash(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SNOWMAN_DOLL:
            effectRet = fx_snowman_doll(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FRIGHT_JAR:
            effectRet = fx_fright_jar(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_STOP_WATCH:
            effectRet = fx_stop_watch(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_63:
            effectRet = fx_effect_63(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9, iVar10);
            break;
        case EFFECT_THROW_SPINY:
            effectRet = fx_throw_spiny(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_65:
            effectRet = fx_effect_65(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_TUBBA_HEART_ATTACK:
            effectRet = fx_tubba_heart_attack(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_WHIRLWIND:
            effectRet = fx_whirlwind(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_RED_IMPACT:
            effectRet = fx_red_impact(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FLOATING_CLOUD_PUFF:
            effectRet = fx_floating_cloud_puff(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ENERGY_IN_OUT:
            effectRet = fx_energy_in_out(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_TATTLE_WINDOW:
            effectRet = fx_tattle_window(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SHINY_FLARE:
            effectRet = fx_shiny_flare(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_HUFF_PUFF_BREATH:
            effectRet = fx_huff_puff_breath(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8);
            break;
        case EFFECT_COLD_BREATH:
            effectRet = fx_cold_breath(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_EMBERS:
            effectRet = fx_embers(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9, fVar10, fVar11);
            break;
        case EFFECT_HIEROGLYPHS:
            effectRet = fx_hieroglyphs(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_MISC_PARTICLES:
            effectRet = fx_misc_particles(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, iVar9);
            break;
        case EFFECT_STATIC_STATUS:
            effectRet = fx_static_status(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, iVar7);
            break;
        case EFFECT_MOVING_CLOUD:
            effectRet = fx_moving_cloud(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, fVar9);
            break;
        case EFFECT_75:
            effectRet = fx_effect_75(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_FIREWORK_ROCKET:
            effectRet = fx_firework_rocket(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_PEACH_STAR_BEAM:
            effectRet = fx_peach_star_beam(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_BUTTERFLIES:
            effectRet = fx_butterflies(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_CHAPTER_CHANGE:
            effectRet = fx_chapter_change(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ICE_SHARD:
            effectRet = fx_ice_shard(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SPIRIT_CARD:
            effectRet = fx_spirit_card(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_LIL_OINK:
            effectRet = fx_lil_oink(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SOMETHING_ROTATING:
            effectRet = fx_something_rotating(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_BREAKING_JUNK:
            effectRet = fx_breaking_junk(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_PARTNER_BUFF:
            effectRet = fx_partner_buff(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_QUIZMO_ASSISTANT:
            effectRet = fx_quizmo_assistant(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_ICE_PILLAR:
            effectRet = fx_ice_pillar(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_SUN:
            effectRet = fx_sun(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_STAR_SPIRITS_ENERGY:
            effectRet = fx_star_spirits_energy(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_PINK_SPARKLES:
            effectRet = fx_pink_sparkles(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_STAR_OUTLINE:
            effectRet = fx_star_outline(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        case EFFECT_86:
            effectRet = fx_effect_86(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        default:
            PANIC();
    }

    if (effectRet != NULL) {
        evt_set_variable(script, LVarF, (s32) effectRet);
    }

    return ApiStatus_DONE2;
}
