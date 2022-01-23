#include "common.h"
#include "effects.h"

INCLUDE_ASM(void, "evt/fx_api", func_802D7460, f32 x, f32 y, f32 z, s32 arg3);

INCLUDE_ASM(void, "evt/fx_api", func_802D74C0, f32 x, f32 y, f32 z, s32 arg3);

ApiStatus func_802D7520(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    func_802D7460(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(0x2055, 0, x, y, z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D75D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);

    func_802D74C0(x, y, z, evt_get_variable(script, *args++));
    sfx_play_sound_at_position(0x378, 0, x, y, z);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/fx_api", func_802D7690);

INCLUDE_ASM(s32, "evt/fx_api", ShowEmote, Evt* script, s32 isInitialCall);

ApiStatus RemoveEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    remove_effect(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptrValue = (s32*) evt_get_variable(script, *args++);

    *ptrValue |= 0x10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B44(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) evt_get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[5] = 10;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7B74(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32** ptrValue = (s32**) evt_get_variable(script, *args++);
    s32* ptrTemp = ptrValue[3];

    ptrTemp[12] = 5;
    return ApiStatus_DONE2;
}

ApiStatus func_802D7BA4(Evt* script, s32 isInitialCall) {
    s32 var1 = script->varTable[1];
    s32 var2 = script->varTable[2];
    s32 var3 = script->varTable[3];
    s32 var4 = script->varTable[4];
    s32 var5 = script->varTable[5];
    s32 var6 = script->varTable[6];
    s32 temp;
    f32 t0;
    f32 t1;

    if (isInitialCall) {
        script->functionTemp[0] = var6;
        get_screen_overlay_params(1, &t0, &t1);
        script->functionTemp[1] = t1;
        set_screen_overlay_center(1, 0, var1, var2);
        set_screen_overlay_center(1, 1, var3, var4);
    }

    get_screen_overlay_params(1, &t0, &t1);
    temp = (script->functionTemp[1] - var5) * script->functionTemp[0];
    set_screen_overlay_params_back(12, (temp / var6) + var5);

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 0) {
        set_screen_overlay_params_back(12, var5);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript D_802D9D50 = {
    EVT_CALL(func_802D7BA4)
    EVT_RETURN
    EVT_END
};

ApiStatus Spawn802D9D50(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);
    s32 var5 = evt_get_variable(script, *args++);
    s32 var6 = evt_get_variable(script, *args++);

    Evt* newScript = start_script(D_802D9D50, 1, 0);
    newScript->varTable[0] = var0;
    newScript->varTable[1] = var1;
    newScript->varTable[2] = var2;
    newScript->varTable[3] = var3;
    newScript->varTable[4] = var4;
    newScript->varTable[5] = var5;
    newScript->varTable[6] = var6;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/fx_api", func_802D7E08);

INCLUDE_ASM(ApiStatus, "evt/fx_api", ShowSleepBubble, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "evt/fx_api", func_802D8248, Evt* script, s32 isInitialCall);

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

    s32 sp30, sp34, sp38, sp3C;

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
            fx_emote(iVar1, (Npc* ) a2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp30);
            evt_set_variable(script, a8, sp30);
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
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_SPIKY_WHITE_AURA:
            fx_spiky_white_aura(iVar1, fVar2, fVar3, fVar4, iVar5);
            break;
        case EFFECT_SMOKE_IMPACT:
            fx_smoke_impact(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6, fVar7, iVar8);
            break;
        case EFFECT_DAMAGE_INDICATOR:
            fx_damage_indicator(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, iVar7, &sp30);
            evt_set_variable(script, a8, sp30);
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
            evt_set_variable(script, a7, sp38);
            break;
        case EFFECT_WINDY_LEAVES:
            fx_windy_leaves(iVar1, fVar2, fVar3, fVar4);
            break;
        case EFFECT_FLAME:
            fx_flame(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
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
            evt_set_variable(script, a7, sp38);
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
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_LIGHT_RAYS:
            fx_light_rays(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
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
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_3C:
            fx_3C(iVar1, fVar2, fVar3, fVar4, fVar5, &sp34);
            evt_set_variable(script, a6, sp34);
            break;
        case EFFECT_3D:
            fx_3D(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, iVar8, &sp3C);
            evt_set_variable(script, a9, sp3C);
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
            effectRet = fx_46(iVar1, a2, fVar3, iVar4);
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
            effectRet = fx_63(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9, iVar10);
            break;
        case EFFECT_THROW_SPINY:
            effectRet = fx_throw_spiny(iVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, iVar9);
            break;
        case EFFECT_65:
            effectRet = fx_65(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
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
            effectRet = fx_75(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
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
            effectRet = fx_86(iVar1, fVar2, fVar3, fVar4, fVar5, iVar6);
            break;
        default:
            PANIC();
    }

    if (effectRet != NULL) {
        evt_set_variable(script, EVT_VAR(15), effectRet);
    }

    return ApiStatus_DONE2;
}
