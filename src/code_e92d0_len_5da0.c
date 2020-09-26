#include "common.h"

s32 si_find_label(ScriptInstance* script, s32 arg1);
s32 si_skip_if(ScriptInstance* script);
s32 si_skip_else(ScriptInstance* script);
s32 si_goto_end_loop(ScriptInstance* script);
s32 si_goto_end_case(ScriptInstance* script);

f32 fixed_var_to_float(s32 scriptVar) {
    if (scriptVar <= -220000000) {
        return (scriptVar + 230000000) * (1 / 1024.0f);
    }
    return scriptVar;
}

s32 float_to_fixed_var(f32 value) {
    return (s32)(value * 1024.0f) - 230000000;
}

ApiStatus si_handle_return(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

ApiStatus si_handle_label(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

ApiStatus si_handle_goto(ScriptInstance* script) {
    script->ptrNextLine = si_find_label(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_loop(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 loopDepth = ++script->loopDepth;

    ASSERT(loopDepth < 8);

    script->loopStartTable[loopDepth] = thisPos;
    script->loopCounterTable[loopDepth] = var;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_end_loop);

ApiStatus si_handle_break_loop(ScriptInstance* script) {
    ASSERT(script->loopDepth >= 0);
    script->ptrNextLine = si_goto_end_loop(script);
    script->loopDepth -= 1;
    return ApiStatus_DONE2;
}

ApiStatus si_handle_wait(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (!script->blocked) {
        script->functionTemp[0] = get_variable(script, *ptrReadPos);
        script->blocked = 1;
    }

    if (script->functionTemp[0]) {
        s32 todo = 1; // val can be anything
        if (todo) {
            script->functionTemp[0] -= 1;
        }
        return !script->functionTemp[0];
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_wait_seconds(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (!script->blocked) {
        script->functionTemp[0] = get_float_variable(script, *ptrReadPos) * 30.0f + 0.5;
        script->blocked = 1;
    }

    if (script->functionTemp[0]) {
        s32 todo = 1; // val can be anything
        if (todo) {
            script->functionTemp[0] -= 1;
        }
        return !script->functionTemp[0];
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_equal(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) != get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}


ApiStatus si_handle_if_not_equal(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) == get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_less(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) >= get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_greater(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) <= get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_less_equal(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) > get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_greater_equal(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;

    if (get_variable(script, *thisPos++) < get_variable(script, *thisPos++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_AND(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;

    if ((get_variable(script, var) & *thisPos) == 0) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_not_AND(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;

    if ((get_variable(script, var) & *thisPos) != 0) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_else(ScriptInstance* script) {
    script->ptrNextLine = si_skip_else(script);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_end_if(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

ApiStatus si_handle_switch(ScriptInstance* script) {
    Bytecode value = get_variable(script, *script->ptrReadPos);
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = value;
    script->switchBlockState[switchDepth] = 1;

    return ApiStatus_DONE2;
}

ApiStatus si_handle_switch_const(ScriptInstance* script) {
    Bytecode* thisPos = *script->ptrReadPos;
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = thisPos;
    script->switchBlockState[switchDepth] = 1;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_equal);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_not_equal);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_less);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_less_equal);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_greater);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_greater_equal);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_range);

ApiStatus si_handle_case_default(ScriptInstance* script) {
    s32 switchDepth = script->switchDepth;

    ASSERT(switchDepth >= 0);

    if (script->switchBlockState[switchDepth] > 0) {
        script->switchBlockState[switchDepth] = 0;
    } else {
        script->ptrNextLine = si_goto_end_case(script);
    }
    return ApiStatus_DONE2;

    do {} while (0); // Necessary to match
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_AND);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_equal_OR);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_case_equal_AND);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_end_case_group);

ApiStatus si_handle_break_case(ScriptInstance* script) {
    ASSERT(script->switchDepth >= 0);
    script->ptrNextLine = si_goto_end_case(script);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_end_switch(ScriptInstance* script) {
    s32 switchDepth = script->switchDepth;

    ASSERT(switchDepth >= 0);

    script->switchBlockState[switchDepth] = 0;
    script->switchDepth -= 1;

    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_var(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 curPtrReadPos = thisPos[0];

    set_variable(script, curPtrReadPos, get_variable(script, thisPos[1]));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_const(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, script->ptrReadPos[1]);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;

    set_float_variable(script, var, get_float_variable(script, *thisPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_add(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 result = get_variable(script, *thisPos++);
    s32 addend = get_variable(script, var);

    result += addend;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_subtract(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 result = get_variable(script, *thisPos++);
    s32 minuend = get_variable(script, var);

    result = minuend - result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_multiply(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 result = get_variable(script, *thisPos++);
    s32 multiplier = get_variable(script, var);

    result *= multiplier;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_divide(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 result = get_variable(script, *thisPos++);
    s32 dividend = get_variable(script, var);

    result = dividend / result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_mod(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 result = get_variable(script, *thisPos++) + 0.5;
    s32 num = get_variable(script, var) + 0.5;

    result = num % result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_addF(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    f32 result = get_float_variable(script, *thisPos++);
    f32 addend = get_float_variable(script, var);

    result += addend;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_subtractF(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    f32 result = get_float_variable(script, *thisPos++);
    f32 minuend = get_float_variable(script, var);

    result = minuend - result;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_multiplyF(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    f32 result = get_float_variable(script, *thisPos++);
    f32 multiplier = get_float_variable(script, var);

    result *= multiplier;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_divideF(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    f32 result = get_float_variable(script, *thisPos++);
    f32 dividend = get_float_variable(script, var);

    result = dividend / result;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}


ApiStatus si_handle_set_int_buffer_ptr(ScriptInstance* script) {
    script->buffer = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_float_buffer_ptr(ScriptInstance* script) {
    script->buffer = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_1_word(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;

    var = *thisPos++;
    set_variable(script, var, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_2_word(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *thisPos++;
    set_variable(script, var, *script->buffer++);

    var2 = *thisPos++;
    set_variable(script, var2, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_3_word(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *thisPos++;
    set_variable(script, var, *script->buffer++);

    var2 = *thisPos++;
    set_variable(script, var2, *script->buffer++);

    var3 = *thisPos++;
    set_variable(script, var3, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_4_word(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *thisPos++;
    set_variable(script, var, *script->buffer++);

    var2 = *thisPos++;
    set_variable(script, var2, *script->buffer++);

    var3 = *thisPos++;
    set_variable(script, var3, *script->buffer++);

    var4 = *thisPos++;
    set_variable(script, var4, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_Nth_word(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;

    var = *thisPos++;
    set_variable(script, var, script->buffer[get_variable(script, *thisPos)]);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_1_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;

    var = *thisPos++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_2_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *thisPos++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *thisPos++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_3_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *thisPos++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *thisPos++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    var3 = *thisPos++;
    set_float_variable(script, var3, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_4_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *thisPos++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *thisPos++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    var3 = *thisPos++;
    set_float_variable(script, var3, get_float_variable(script, *script->buffer++));

    var4 = *thisPos++;
    set_float_variable(script, var4, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_Nth_float(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var;

    var = *thisPos++;
    set_float_variable(script, var, script->buffer[get_variable(script, *thisPos)]);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_array(ScriptInstance* script) {
    script->array = (s32*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_flag_array(ScriptInstance* script) {
    script->flagArray = (s32*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_allocate_array(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 size = get_variable(script, *thisPos++);
    Bytecode var = *thisPos++;

    script->array = (s32)heap_malloc(size * 4);
    set_variable(script, var, (s32)script->array);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_AND(ScriptInstance* script) {
    Bytecode var = script->ptrReadPos[0];
    s32 val = get_variable(script, script->ptrReadPos[1]);

    val &= get_variable(script, var);
    set_variable(script, var, val);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_AND_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    set_variable(script, var, constant & get_variable(script, var));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_OR(ScriptInstance* script) {
    Bytecode var = script->ptrReadPos[0];
    s32 val = get_variable(script, script->ptrReadPos[1]);

    val |= get_variable(script, var);
    set_variable(script, var, val);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_OR_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    set_variable(script, var, constant | get_variable(script, var));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_call);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_exec1);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_exec2);

ApiStatus si_handle_exec_wait(ScriptInstance* script) {
    start_child_script(script, get_variable(script, *script->ptrReadPos), 0);
    script->currentOpcode = 0;
    return 0xFF;
}

ApiStatus si_handle_jump(ScriptInstance* script) {
    script->ptrFirstLine = (Bytecode*)get_variable(script, *script->ptrReadPos);
    restart_script(script);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", _bound_script_trigger_handler, Trigger* trigger);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_bind);

ApiStatus DeleteTrigger(ScriptInstance* script, s32 isInitialCall) {
    delete_trigger(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_unbind(ScriptInstance* script) {
    delete_trigger(script->ownerID);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_kill(ScriptInstance* script) {
    kill_script_by_ID(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_priority(ScriptInstance* script) {
    set_script_priority(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_timescale(ScriptInstance* script) {
    set_script_timescale(script, get_float_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_group(ScriptInstance* script) {
    set_script_group(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_suspend_all(ScriptInstance* script) {
    suspend_all_group(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_resume_all(ScriptInstance* script) {
    resume_all_group(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_suspend_others(ScriptInstance* script) {
    suspend_group_others(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_resume_others(ScriptInstance* script) {
    resume_group_others(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_suspend(ScriptInstance* script) {
    suspend_all_script(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_resume(ScriptInstance* script) {
    resume_all_script(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_does_script_exist(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode scriptID = get_variable(script, *thisPos++);
    Bytecode var2 = *thisPos++;

    set_variable(script, var2, does_script_exist(scriptID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", func_802C6AD0);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_bind_lock, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_thread, ScriptInstance* script, s32 isInitialCall);

ApiStatus si_handle_end_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_child_thread, ScriptInstance* script, s32 isInitialCall);

ApiStatus si_handle_end_child_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_BLOCK;
}

ApiStatus func_802C6E14(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_handle_print_debug_var, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C739C(ScriptInstance* script) {
    script->ptrSavedPosition = (Bytecode*)*script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus func_802C73B0(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

s32 func_802C73B8(ScriptInstance* script) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        if (script == get_script_by_index(i)) {
            break;
        }
    }

    return 1;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_execute_next_command);

// TODO: consider renaming to si_get_variable
#ifdef NON_MATCHING
/*
s32 get_variable(ScriptInstance* script, Bytecode var) {
    s32 wordIdx;
    s32 bitIdx;

    if (var <= -270000000) {
        return var;
    } else if (var <= -250000000) {
        return var;
    } else if (var <= -220000000) {
        return fixed_var_to_float(var);
    } else if (var <= -200000000) {
        var += 210000000;
        wordIdx = var / 32;
        bitIdx = var % 32;
        return (script->flagArray[wordIdx] & (1 << bitIdx)) != 0;
    } else if (var <= -180000000) {
        var += 190000000;
        var = script->array[var];
        return (var > -270000000 && var < -220000000) ? fixed_var_to_float(var) : var;
    } else if (var <= -160000000) {
        var += 170000000;
        return get_global_byte(var);
    } else if (var <= -140000000) {
        var += 150000000;
        return get_area_byte(var);
    } else if (var <= -120000000) {
        var += 130000000;
        return get_global_flag(var);
    } else if (var <= -100000000) {
        var += 110000000;
        return get_area_flag(var);
    } else if (var <= -80000000) {
        var += 90000000;
        wordIdx = var / 32;
        bitIdx = var % 32;
        return (gMapFlags[wordIdx] & (1 << bitIdx)) != 0;
    } else if (var <= -60000000) {
        var += 70000000;
        wordIdx = var / 32;
        bitIdx = var % 32;
        return (script->varFlags[wordIdx] & (1 << bitIdx)) != 0;
    } else if (var <= -40000000) {
        var += 50000000;
        var = gMapVars[var];
        return (var > -270000000 && var < -220000000) ? fixed_var_to_float(var) : var;
    } else if (var <= -20000000) {
        var += 30000000;
        var = script->varTable[var];
        return (var > -270000000 && var < -220000000) ? fixed_var_to_float(var) : var;
    } else {
        return var;
    }
}
*/
#else
INCLUDE_ASM(s32, "code_e92d0_len_5da0", get_variable, ScriptInstance* script, Bytecode var);
#endif

INCLUDE_ASM(s32, "code_e92d0_len_5da0", get_variable_index);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", get_variable_index_alt);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", set_variable, ScriptInstance* script, Bytecode var, s32 value);

INCLUDE_ASM(f32, "code_e92d0_len_5da0", get_float_variable, ScriptInstance* script, Bytecode var);

INCLUDE_ASM(f32, "code_e92d0_len_5da0", set_float_variable, ScriptInstance* script, Bytecode var, f32 value);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_find_label, ScriptInstance* script, s32 arg1);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_skip_if, ScriptInstance* script);
// Matching but needs rodata support
/*Bytecode* si_skip_if(ScriptInstance* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;
        switch(opcode) {
            case 1:
                PANIC();
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 19:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            case 17:
                nestedIfDepth++;
                break;
            case 18:
                if (nestedIfDepth == 0) {
                    return pos;
                }
            break;
        }
    } while(1);
}*/

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_skip_else, ScriptInstance* script);
// Matching but needs rodata support
/*Bytecode* si_skip_else(ScriptInstance* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;
        switch(opcode) {
            case 1:
                PANIC();
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 19:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            case 17:
                nestedIfDepth++;
                break;

        }
    } while(1);
}*/

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_goto_end_case, ScriptInstance* script);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_goto_next_case, ScriptInstance* script);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", si_goto_end_loop, ScriptInstance* script);

// Ethan: I think this is the start of a new file
//INCLUDE_ASM(s32, "code_e92d0_len_5da0", TranslateModel, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", RotateModel, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", ScaleModel, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetModelIndex(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *thisPos++);
    Bytecode index = *thisPos++;

    set_variable(script, index, get_model_list_index_from_tree_index(modelID));
    return ApiStatus_DONE2;
}

ApiStatus func_802C8EE4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode modelID = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(modelID));

    model->flags &= ~0x400;
    return ApiStatus_DONE2;
}

ApiStatus CloneModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode srcModelID = get_variable(script, *thisPos++);
    Bytecode newModelID = get_variable(script, *thisPos++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

ApiStatus GetModelCenter(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    f32 centerX;
    f32 centerY;
    f32 centerZ;
    f32 sizeX;
    f32 sizeY;
    f32 sizeZ;

    get_model_center_and_size(get_variable(script, *thisPos++) & 0xFFFF, &centerX, &centerY, &centerZ, &sizeX, &sizeY,
                              &sizeZ);
    script->varTable[0] = centerX;
    script->varTable[1] = centerY;
    script->varTable[2] = centerZ;
    return ApiStatus_DONE2;
}

ApiStatus SetTexPanner(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    set_tex_panner(model, var2);
    model->flags |= 0x800;
    return ApiStatus_DONE2;
}

ApiStatus SetModelFlag10(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (var2 != 0) {
        model->flags |= 0x10;
    } else {
        model->flags &= ~0x10;
    }
    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus func_802C90FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    func_8011BC7C(model, var2, var3);
    if (var2 != -1) {
        model->flags |= 0x10;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_e92d0_len_5da0", func_802C90FC);
#endif

ApiStatus func_802C91A4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode treeIndex = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->unk_A9 = var2;
    return ApiStatus_DONE2;
}

ApiStatus EnableTexPanning(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s32 flag = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex));

    if (flag) {
        model->flags |= 0x800;
    } else {
        model->flags &= ~0x800;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 listIndex = get_model_list_index_from_tree_index(get_variable(script, *thisPos++));
    Bytecode flag = get_variable(script, *thisPos++);
    Model* model = get_model_from_list_index(listIndex);

    if (flag != 0) {
        model->flags &= ~0x2;
    } else {
        model->flags |= 0x2;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetGroupEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);

    func_8011B7C0(var1, 2, var2);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", SetTexPanOffset, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9428(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011BCB4(var1, var2, var3);
    return ApiStatus_DONE2;
}

ApiStatus func_802C94A0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011BCD0(var1, var2, var3);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", SetModelFlags, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", func_802C95A0);

ApiStatus func_802C971C(ScriptInstance* script, s32 isInitialCall) {
    func_8011B37C((u16)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802C9748(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    u16 var1 = get_variable(script, *thisPos++);
    s32 var2 = get_variable(script, *thisPos++);

    if (var2 != 0) {
        func_8011B5D0(var1);
    } else {
        func_8011B660(var1);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", TranslateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", RotateGroup, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", ScaleGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9B40(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    Bytecode var2 = *thisPos++;

    set_variable(script, var2, func_8011B090(var1));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", EnableGroup, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802C9C70(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 var1 = get_variable(script, *thisPos++);
    u16 var2 = get_variable(script, *thisPos++);
    s32 var3 = get_variable(script, *thisPos++);

    func_8011C164(var1, var2, var3);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", modify_collider_family_flags);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", ModifyColliderFlags, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", ResetFromLava, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", func_802C9FD4);

ApiStatus GetColliderCenter(ScriptInstance* script, s32 initialCall) {
    f32 x;
    f32 y;
    f32 z;

    get_collider_center(get_variable(script, *script->ptrReadPos), &x, &y, &z);

    script->varTable[0] = x;
    script->varTable[1] = y;
    script->varTable[2] = z;

    return ApiStatus_DONE2;
}

ApiStatus ParentColliderToModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s16 colliderID = get_variable(script, *thisPos++);
    s32 treeIndex = get_variable(script, *thisPos++);

    parent_collider_to_model(colliderID, get_model_list_index_from_tree_index(treeIndex));
    update_collider_transform(colliderID);
    return ApiStatus_DONE2;
}

ApiStatus UpdateColliderTransform(ScriptInstance* script, s32 isInitialCall) {
    update_collider_transform(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", set_zone_enabled);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", SetZoneEnabled);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", goto_map);

ApiStatus GotoMap(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 0);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapSpecial(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 1);
    return ApiStatus_DONE1;
}

ApiStatus GotoMapByID(ScriptInstance* script, s32 isInitialCall) {
    goto_map(script, 2);
    return ApiStatus_DONE1;
}

ApiStatus GetEntryID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, (*gGameStatusPtr)->entryID);
    return ApiStatus_DONE2;
}

ApiStatus GetMapID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, (*gGameStatusPtr)->mapID);
    return ApiStatus_DONE2;
}

ApiStatus GetLoadType(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, (*gGameStatusPtr)->loadType != 0);
    return ApiStatus_DONE2;
}

ApiStatus SetRenderMode(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 treeIndex = get_variable(script, *thisPos++);
    s8 renderMode = get_variable(script, *thisPos++);

    get_model_from_list_index(get_model_list_index_from_tree_index(treeIndex))->renderMode = renderMode;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_e92d0_len_5da0", PlaySoundAtModel, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "code_e92d0_len_5da0", PlaySoundAtCollider, ScriptInstance* script, s32 isInitialCall);
