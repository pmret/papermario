#include "common.h"

Bytecode* si_find_label(ScriptInstance* script, s32 arg1);
Bytecode* si_skip_if(ScriptInstance* script);
Bytecode* si_skip_else(ScriptInstance* script);
Bytecode* si_goto_end_case(ScriptInstance* script);
Bytecode* si_goto_next_case(ScriptInstance* script);
Bytecode* si_goto_end_loop(ScriptInstance* script);
s32 get_variable_index(ScriptInstance* script, s32 var);

f32 fixed_var_to_float(Bytecode scriptVar) {
    if (scriptVar <= -220000000) {
        return (scriptVar + 230000000) / 1024.0f;
    } else {
        return scriptVar;
    }
}

Bytecode float_to_fixed_var(f32 value) {
    return (s32)(value * 1024.0f) + -230000000;
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
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 loopDepth = ++script->loopDepth;

    ASSERT(loopDepth < 8);

    script->loopStartTable[loopDepth] = args;
    script->loopCounterTable[loopDepth] = var;

    return ApiStatus_DONE2;
}

ApiStatus si_handle_end_loop(ScriptInstance* script) {
    s32 loopDepth = script->loopDepth;
    s32 loopCounter;

    ASSERT(loopDepth >= 0);

    loopCounter = script->loopCounterTable[loopDepth];

    if (loopCounter == 0) {
        script->ptrNextLine = script->loopStartTable[loopDepth];
        return ApiStatus_DONE2;
    }

    if (loopCounter >= -10000000) {
        script->loopCounterTable[loopDepth] = --loopCounter;
    } else {
        s32 var = get_variable(script, loopCounter) - 1;
        set_variable(script, loopCounter, var);
        loopCounter = var;
    }

    if (loopCounter != 0) {
        script->ptrNextLine = script->loopStartTable[loopDepth];
        return ApiStatus_DONE2;
    } else {
        script->loopDepth--;
        return ApiStatus_DONE2;
    }
}

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

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[0] -= 1;
    return !script->functionTemp[0];
}

ApiStatus si_handle_wait_seconds(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (!script->blocked) {
        script->functionTemp[0] = get_float_variable(script, *ptrReadPos) * 30.0f + 0.5;
        script->blocked = 1;
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[0]--;
    return !script->functionTemp[0];
}

ApiStatus si_handle_if_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) != get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_not_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) == get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_less(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) >= get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_greater(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) <= get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_less_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) > get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_greater_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) < get_variable(script, *args++)) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_AND(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    if ((get_variable(script, var) & *args) == 0) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_not_AND(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    if ((get_variable(script, var) & *args) != 0) {
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
    Bytecode* args = *script->ptrReadPos;
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = args;
    script->switchBlockState[switchDepth] = 1;

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var != switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_not_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var == switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_less(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var <= switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_less_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var < switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_greater(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var >= switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_greater_equal(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var > switchBlockValue) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_range(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 var2;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args++);
    var2 = get_variable(script, *args++);

    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if ((var <= switchBlockValue) && (switchBlockValue <= var2)) {
        script->switchBlockState[switchDepth] = 0;
    } else {
        script->ptrNextLine = si_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_default(ScriptInstance* script) {
    s32 switchDepth = script->switchDepth;

    ASSERT(switchDepth >= 0);

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_AND(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = *args;
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState <= 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if ((var & switchBlockValue) == 0) {
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_equal_OR(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState == 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var == switchBlockValue) {
        script->switchBlockState[switchDepth] = -1;
    } else if (switchBlockState != -1) {
        script->ptrNextLine = si_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_case_equal_AND(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = get_variable(script, *args);
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState == 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (switchBlockState == -2) {
        script->ptrNextLine = si_goto_next_case(script);
    } else if (var == switchBlockValue) {
        script->switchBlockState[switchDepth] = -1;
    } else {
        script->switchBlockState[switchDepth] = -2;
        script->ptrNextLine = si_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus si_handle_end_case_group(ScriptInstance* script) {
    ASSERT(script->switchDepth >= 0);

    if (script->switchBlockState[script->switchDepth] == 0) {
        script->ptrNextLine = si_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (script->switchBlockState[script->switchDepth] != -1) {
        script->switchBlockState[script->switchDepth] = 1;
        script->ptrNextLine = si_goto_next_case(script);
    } else {
        script->switchBlockState[script->switchDepth] = 0;
        script->ptrNextLine = si_goto_end_case(script);
    }

    return ApiStatus_DONE2;
}

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
    Bytecode* args = script->ptrReadPos;
    s32 curPtrReadPos = args[0];

    set_variable(script, curPtrReadPos, get_variable(script, args[1]));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_const(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, script->ptrReadPos[1]);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    set_float_variable(script, var, get_float_variable(script, *args));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_add(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = get_variable(script, *args++);
    s32 addend = get_variable(script, var);

    result += addend;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_subtract(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = get_variable(script, *args++);
    s32 minuend = get_variable(script, var);

    result = minuend - result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_multiply(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = get_variable(script, *args++);
    s32 multiplier = get_variable(script, var);

    result *= multiplier;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_divide(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = get_variable(script, *args++);
    s32 dividend = get_variable(script, var);

    result = dividend / result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_mod(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = get_variable(script, *args++) + 0.5;
    s32 num = get_variable(script, var) + 0.5;

    result = num % result;

    set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_addF(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = get_float_variable(script, *args++);
    f32 addend = get_float_variable(script, var);

    result += addend;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_subtractF(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = get_float_variable(script, *args++);
    f32 minuend = get_float_variable(script, var);

    result = minuend - result;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_multiplyF(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = get_float_variable(script, *args++);
    f32 multiplier = get_float_variable(script, var);

    result *= multiplier;

    set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_divideF(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = get_float_variable(script, *args++);
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
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    set_variable(script, var, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_2_word(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *args++;
    set_variable(script, var, *script->buffer++);

    var2 = *args++;
    set_variable(script, var2, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_3_word(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *args++;
    set_variable(script, var, *script->buffer++);

    var2 = *args++;
    set_variable(script, var2, *script->buffer++);

    var3 = *args++;
    set_variable(script, var3, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_4_word(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *args++;
    set_variable(script, var, *script->buffer++);

    var2 = *args++;
    set_variable(script, var2, *script->buffer++);

    var3 = *args++;
    set_variable(script, var3, *script->buffer++);

    var4 = *args++;
    set_variable(script, var4, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_Nth_word(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    set_variable(script, var, script->buffer[get_variable(script, *args)]);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_1_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_2_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *args++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *args++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_3_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *args++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *args++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    var3 = *args++;
    set_float_variable(script, var3, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_4_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *args++;
    set_float_variable(script, var, get_float_variable(script, *script->buffer++));

    var2 = *args++;
    set_float_variable(script, var2, get_float_variable(script, *script->buffer++));

    var3 = *args++;
    set_float_variable(script, var3, get_float_variable(script, *script->buffer++));

    var4 = *args++;
    set_float_variable(script, var4, get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_Nth_float(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    set_float_variable(script, var, script->buffer[get_variable(script, *args)]);

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
    Bytecode* args = script->ptrReadPos;
    s32 size = get_variable(script, *args++);
    Bytecode var = *args++;

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

ApiStatus si_handle_call(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    s32 isInitialCall;
    ApiFunc func;
    ScriptInstance* newScript; // todo fake match

    if (script->blocked) {
        isInitialCall = FALSE;
        func = script->callFunction;
        newScript = script; // todo fake match
    } else {
        script->callFunction = (ApiFunc)get_variable(script, *args++);
        newScript = script; // todo fake match
        script->ptrReadPos = args;
        script->currentArgc--;
        script->blocked = TRUE;
        isInitialCall = TRUE;
        func = script->callFunction;
    }

    return func(newScript, isInitialCall); // todo fake match
}

ApiStatus si_handle_exec1(ScriptInstance* script) {
    ScriptInstance* newScript;
    s32 i;

    newScript = start_script_in_group((ScriptInstance*)get_variable(script, *script->ptrReadPos), script->priority, 0,
                                      script->groupFlags);

    newScript->owner1 = script->owner1;
    newScript->owner2 = script->owner2;

    i = 0;
    while (i < ARRAY_COUNT(script->varTable)) {
        newScript->varTable[i] = script->varTable[i++];
    }

    i = 0;
    while (i < ARRAY_COUNT(script->varFlags)) {
        newScript->varFlags[i] = script->varFlags[i++];
    }

    newScript->array = script->array;
    newScript->flagArray = script->flagArray;

    return ApiStatus_DONE2;
}

ApiStatus si_handle_exec1_get_id(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    ScriptInstance* var = (ScriptInstance*)get_variable(script, *args++);
    Bytecode arg2 = *args++;
    ScriptInstance* newScript;
    s32 i;

    newScript = start_script_in_group(var, script->priority, 0, script->groupFlags);

    newScript->owner1 = script->owner1;
    newScript->owner2 = script->owner2;

    for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
        newScript->varTable[i] = script->varTable[i];
    }

    for (i = 0; i < ARRAY_COUNT(script->varFlags); i++) {
        newScript->varFlags[i] = script->varFlags[i];
    }

    newScript->array = script->array;
    newScript->flagArray = script->flagArray;

    set_variable(script, arg2, newScript->id);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_exec_wait(ScriptInstance* script) {
    start_child_script(script, get_variable(script, *script->ptrReadPos), 0);
    script->currentOpcode = 0;
    return ApiStatus_FINISH;
}

ApiStatus si_handle_jump(ScriptInstance* script) {
    script->ptrFirstLine = (Bytecode*)get_variable(script, *script->ptrReadPos);
    restart_script(script);
    return ApiStatus_DONE2;
}

s32 _bound_script_trigger_handler(Trigger* trigger) {
    Bytecode* scriptStart;
    ScriptInstance* script;

    if (trigger->runningScript == NULL) {
        scriptStart = trigger->scriptSource;
        if (is_trigger_bound(trigger, scriptStart)) {
            return 0;
        }

        script = start_script(scriptStart, trigger->priority, 0x20);
        trigger->runningScript = script;
        trigger->runningScriptID = script->id;
        script->varTable[0] = trigger->scriptVars[0];
        script->varTable[1] = trigger->scriptVars[1];
        script->varTable[2] = trigger->scriptVars[2];
        script->owner2.trigger = trigger;
    }

    if (!does_script_exist(trigger->runningScriptID)) {
        trigger->runningScript = NULL;
        return 0;
    }

    return 1;
}

ApiStatus si_handle_bind(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Trigger* trigger;
    Bytecode* triggerScript = get_variable(script, *args++);
    Bytecode eventType = *args++;
    Bytecode colliderIDVar = *args++;
    Bytecode a3 = *args++;
    Bytecode triggerOut = *args++;
    TriggerDefinition def;

    def.flags = eventType | 0x1000000;
    def.flagIndex = get_variable(script, colliderIDVar);
    def.colliderIndex = get_variable_index(script, colliderIDVar);
    def.inputArg3 = a3;
    def.unk_14 = 0;
    def.function = _bound_script_trigger_handler;

    trigger = create_trigger(&def);
    trigger->scriptSource = triggerScript;
    trigger->runningScript = NULL;
    trigger->priority = script->priority;
    trigger->scriptVars[0] = get_variable(script, script->varTable[0]);
    trigger->scriptVars[1] = get_variable(script, script->varTable[1]);
    trigger->scriptVars[2] = get_variable(script, script->varTable[2]);

    if (triggerOut != 0) {
        set_variable(script, triggerOut, trigger);
    }

    return ApiStatus_DONE2;
}

ApiStatus DeleteTrigger(ScriptInstance* script, s32 isInitialCall) {
    delete_trigger(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_unbind(ScriptInstance* script) {
    delete_trigger(script->owner2.trigger);
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
    Bytecode* args = script->ptrReadPos;
    ScriptID scriptID = get_variable(script, *args++);
    Bytecode var2 = *args++;

    set_variable(script, var2, does_script_exist(scriptID));
    return ApiStatus_DONE2;
}

void si_standard_trigger_executor(Trigger* trigger) {
    if (trigger->runningScript == NULL) {
        ScriptInstance* newScript = start_script(trigger->scriptSource, trigger->priority, 0x20);
        trigger->runningScript = newScript;
        trigger->runningScriptID = newScript->id;
        newScript->varTable[0] = trigger->scriptVars[0];
        newScript->varTable[1] = trigger->scriptVars[1];
        newScript->varTable[2] = trigger->scriptVars[2];
        newScript->owner2.trigger = trigger;
    }

    if (!does_script_exist(trigger->runningScriptID)) {
        trigger->runningScript = NULL;
        trigger->flags.flags &= ~0x2;
    }
}

ApiStatus si_handle_bind_lock(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;
    Trigger* trigger;
    Bytecode* triggerScript = get_variable(script, *args++);
    Bytecode eventType = *args++;
    Bytecode colliderIDVar = *args++;
    s32* itemList = get_variable(script, *args++);
    Bytecode triggerOut = *args++;
    s32 a5 = *args++;
    TriggerDefinition def;

    def.flags = eventType | 0x1000000;
    def.flagIndex = get_variable(script, colliderIDVar);
    def.colliderIndex = get_variable_index(script, colliderIDVar);
    def.unk_1C = itemList;
    def.function = si_standard_trigger_executor;
    def.unk_14 = triggerOut;
    def.inputArg3 = a5;

    trigger = create_trigger(&def);
    trigger->scriptSource = triggerScript;
    trigger->runningScript = NULL;
    trigger->priority = script->priority;
    trigger->scriptVars[0] = get_variable(script, script->varTable[0]);
    trigger->scriptVars[1] = get_variable(script, script->varTable[1]);
    trigger->scriptVars[2] = get_variable(script, script->varTable[2]);

    return ApiStatus_DONE2;
}

ApiStatus si_handle_thread(ScriptInstance* script);
INCLUDE_ASM(s32, "evt/si", si_handle_thread, ScriptInstance* script);

ApiStatus si_handle_end_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

ApiStatus si_handle_child_thread(ScriptInstance* script);
INCLUDE_ASM(ApiStatus, "evt/si", si_handle_child_thread, ScriptInstance* script);

ApiStatus si_handle_end_child_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_BLOCK;
}

ApiStatus func_802C6E14(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

ApiStatus si_handle_print_debug_var(ScriptInstance* script);
INCLUDE_ASM(ApiStatus, "evt/si", si_handle_print_debug_var, ScriptInstance* script);

ApiStatus func_802C739C(ScriptInstance* script) {
    script->ptrSavedPosition = (Bytecode*)*script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus func_802C73B0(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

s32 func_802C73B8(ScriptInstance* script) {
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if (script == get_script_by_index(i)) {
            break;
        }
    }
    return 1;
}

s32 si_execute_next_command(ScriptInstance *script) {
    while (TRUE) {
        s32 status = ApiStatus_DONE2;
        s32* lines;
        s32 nargs;

        switch (script->currentOpcode) {
            case 0:
                script->ptrCurrentLine = script->ptrNextLine;
                lines = script->ptrNextLine;
                script->currentOpcode = *lines++;
                nargs = *lines++;
                script->ptrReadPos = lines;
                script->blocked = FALSE;
                script->currentArgc = nargs;
                lines = &lines[nargs];
                script->ptrNextLine = lines;
                status = ApiStatus_REPEAT;
                break;
            case ScriptOpcode_RETURN:
                status = si_handle_return(script);
                break;
            case ScriptOpcode_LABEL:
                status = si_handle_label(script);
                break;
            case ScriptOpcode_GOTO:
                status = si_handle_goto(script);
                break;
            case ScriptOpcode_LOOP:
                status = si_handle_loop(script);
                break;
            case ScriptOpcode_END_LOOP:
                status = si_handle_end_loop(script);
                break;
            case ScriptOpcode_BREAK_LOOP:
                status = si_handle_break_loop(script);
                break;
            case ScriptOpcode_SLEEP_FRAMES:
                status = si_handle_wait(script);
                break;
            case ScriptOpcode_SLEEP_SECS:
                status = si_handle_wait_seconds(script);
                break;
            case ScriptOpcode_IF_EQ:
                status = si_handle_if_equal(script);
                break;
            case ScriptOpcode_IF_NE:
                status = si_handle_if_not_equal(script);
                break;
            case ScriptOpcode_IF_LT:
                status = si_handle_if_less(script);
                break;
            case ScriptOpcode_IF_GT:
                status = si_handle_if_greater(script);
                break;
            case ScriptOpcode_IF_LE:
                status = si_handle_if_less_equal(script);
                break;
            case ScriptOpcode_IF_GE:
                status = si_handle_if_greater_equal(script);
                break;
            case ScriptOpcode_IF_FLAG:
                status = si_handle_if_AND(script);
                break;
            case ScriptOpcode_IF_NOT_FLAG:
                status = si_handle_if_not_AND(script);
                break;
            case ScriptOpcode_ELSE:
                status = si_handle_else(script);
                break;
            case ScriptOpcode_END_IF:
                status = si_handle_end_if(script);
                break;
            case ScriptOpcode_MATCH:
                status = si_handle_switch(script);
                break;
            case ScriptOpcode_MATCH_CONST:
                status = si_handle_switch_const(script);
                break;
            case ScriptOpcode_CASE_EQ:
                status = si_handle_case_equal(script);
                break;
            case ScriptOpcode_CASE_NE:
                status = si_handle_case_not_equal(script);
                break;
            case ScriptOpcode_CASE_LT:
                status = si_handle_case_less(script);
                break;
            case ScriptOpcode_CASE_LE:
                status = si_handle_case_less_equal(script);
                break;
            case ScriptOpcode_CASE_GT:
                status = si_handle_case_greater(script);
                break;
            case ScriptOpcode_CASE_GE:
                status = si_handle_case_greater_equal(script);
                break;
            case ScriptOpcode_CASE_ELSE:
                status = si_handle_case_default(script);
                break;
            case ScriptOpcode_BREAK_MATCH:
                status = si_handle_break_case(script);
                break;
            case ScriptOpcode_CASE_MULTI_OR_EQ:
                status = si_handle_case_equal_OR(script);
                break;
            case ScriptOpcode_END_CASE_MULTI:
                status = si_handle_end_case_group(script);
                break;
            case ScriptOpcode_CASE_MULTI_AND_EQ:
                status = si_handle_case_equal_AND(script);
                break;
            case ScriptOpcode_CASE_FLAG:
                status = si_handle_case_AND(script);
                break;
            case ScriptOpcode_CASE_RANGE:
                status = si_handle_case_range(script);
                break;
            case ScriptOpcode_END_MATCH:
                status = si_handle_end_switch(script);
                break;
            case ScriptOpcode_SET:
                status = si_handle_set_var(script);
                break;
            case ScriptOpcode_SET_CONST:
                status = si_handle_set_const(script);
                break;
            case ScriptOpcode_SET_F:
                status = si_handle_set_float(script);
                break;
            case ScriptOpcode_ADD:
                status = si_handle_add(script);
                break;
            case ScriptOpcode_SUB:
                status = si_handle_subtract(script);
                break;
            case ScriptOpcode_MUL:
                status = si_handle_multiply(script);
                break;
            case ScriptOpcode_DIV:
                status = si_handle_divide(script);
                break;
            case ScriptOpcode_MOD:
                status = si_handle_mod(script);
                break;
            case ScriptOpcode_ADD_F:
                status = si_handle_addF(script);
                break;
            case ScriptOpcode_SUB_F:
                status = si_handle_subtractF(script);
                break;
            case ScriptOpcode_MUL_F:
                status = si_handle_multiplyF(script);
                break;
            case ScriptOpcode_DIV_F:
                status = si_handle_divideF(script);
                break;
            case ScriptOpcode_USE_BUFFER:
                status = si_handle_set_int_buffer_ptr(script);
                break;
            case ScriptOpcode_BUFFER_READ_1:
                status = si_handle_get_1_word(script);
                break;
            case ScriptOpcode_BUFFER_READ_2:
                status = si_handle_get_2_word(script);
                break;
            case ScriptOpcode_BUFFER_READ_3:
                status = si_handle_get_3_word(script);
                break;
            case ScriptOpcode_BUFFER_READ_4:
                status = si_handle_get_4_word(script);
                break;
            case ScriptOpcode_BUFFER_PEEK:
                status = si_handle_get_Nth_word(script);
                break;
            case ScriptOpcode_USE_BUFFER_F:
                status = si_handle_set_float_buffer_ptr(script);
                break;
            case ScriptOpcode_BUFFER_READ_1_F:
                status = si_handle_get_1_float(script);
                break;
            case ScriptOpcode_BUFFER_READ_2_F:
                status = si_handle_get_2_float(script);
                break;
            case ScriptOpcode_BUFFER_READ_3_F:
                status = si_handle_get_3_float(script);
                break;
            case ScriptOpcode_BUFFER_READ_4_F:
                status = si_handle_get_4_float(script);
                break;
            case ScriptOpcode_BUFFER_PEEK_F:
                status = si_handle_get_Nth_float(script);
                break;
            case ScriptOpcode_USE_ARRAY:
                status = si_handle_set_array(script);
                break;
            case ScriptOpcode_USE_FLAGS:
                status = si_handle_set_flag_array(script);
                break;
            case ScriptOpcode_NEW_ARRAY:
                status = si_handle_allocate_array(script);
                break;
            case ScriptOpcode_KILL_SCRIPT:
                status = si_handle_kill(script);
                break;
            case ScriptOpcode_AND:
                status = si_handle_AND(script);
                break;
            case ScriptOpcode_AND_CONST:
                status = si_handle_AND_const(script);
                break;
            case ScriptOpcode_OR:
                status = si_handle_OR(script);
                break;
            case ScriptOpcode_OR_CONST:
                status = si_handle_OR_const(script);
                break;
            case ScriptOpcode_CALL:
                status = si_handle_call(script);
                break;
            case ScriptOpcode_SPAWN_SCRIPT:
                status = si_handle_exec1(script);
                break;
            case ScriptOpcode_SPAWN_GET_ID:
                status = si_handle_exec1_get_id(script);
                break;
            case ScriptOpcode_AWAIT_SCRIPT:
                status = si_handle_exec_wait(script);
                break;
            case ScriptOpcode_BIND_TRIGGER:
                status = si_handle_bind(script);
                break;
            case ScriptOpcode_UNBIND:
                status = si_handle_unbind(script);
                break;
            case ScriptOpcode_SET_PRIORITY:
                status = si_handle_set_priority(script);
                break;
            case ScriptOpcode_SET_TIMESCALE:
                status = si_handle_set_timescale(script);
                break;
            case ScriptOpcode_SET_GROUP:
                status = si_handle_set_group(script);
                break;
            case ScriptOpcode_JUMP:
                status = si_handle_jump(script);
                break;
            case ScriptOpcode_BIND_PADLOCK:
                status = si_handle_bind_lock(script);
                break;
            case ScriptOpcode_SUSPEND_GROUP:
                status = si_handle_suspend_all(script);
                break;
            case ScriptOpcode_RESUME_GROUP:
                status = si_handle_resume_all(script);
                break;
            case ScriptOpcode_SUSPEND_OTHERS:
                status = si_handle_suspend_others(script);
                break;
            case ScriptOpcode_RESUME_OTHERS:
                status = si_handle_resume_others(script);
                break;
            case ScriptOpcode_SUSPEND_SCRIPT:
                status = si_handle_suspend(script);
                break;
            case ScriptOpcode_RESUME_SCRIPT:
                status = si_handle_resume(script);
                break;
            case ScriptOpcode_SCRIPT_EXISTS:
                status = si_handle_does_script_exist(script);
                break;
            case ScriptOpcode_SPAWN_THREAD:
                status = si_handle_thread(script);
                break;
            case ScriptOpcode_END_SPAWN_THREAD:
                status = si_handle_end_thread(script);
                break;
            case ScriptOpcode_PARALLEL_THREAD:
                status = si_handle_child_thread(script);
                break;
            case ScriptOpcode_END_PARALLEL_THREAD:
                status = si_handle_end_child_thread(script);
                break;
            case ScriptOpcode_90:
                status = func_802C6E14(script);
                break;
            case ScriptOpcode_DEBUG_PRINT:
                status = si_handle_print_debug_var(script);
                break;
            case ScriptOpcode_92:
                status = func_802C739C(script);
                break;
            case ScriptOpcode_93:
                status = func_802C73B0(script);
                break;
            case ScriptOpcode_94:
                status = func_802C73B8(script);
            case ScriptOpcode_END:
                break;
            default:
                PANIC();
        }

        if (status == ApiStatus_REPEAT) {
            continue;
        }

        if (status == ApiStatus_FINISH) {
            return -1;
        }

        if (status < 0) {
            return 1;
        }

        // TODO: this may be able to be a switch but I couldn't get it
        if (status == ApiStatus_BLOCK) {
            // return 0
        } else if (status == ApiStatus_DONE1) {
            script->currentOpcode = 0;
            // return 0
        } else if (status == ApiStatus_DONE2) {
            script->currentOpcode = 0;
            if (gGameStatusPtr->disableScripts != status) {
                continue;
            }
            // return 0
        } else {
            continue;
        }
        return 0;
    }
}

// TODO: consider renaming to si_get_variable
#ifdef NON_MATCHING
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
#else
INCLUDE_ASM(s32, "evt/si", get_variable, ScriptInstance* script, Bytecode var);
#endif

s32 get_variable_index(ScriptInstance* script, s32 var) {
    if (-270000000 >= var) {
        return var;
    }
    if (-250000000 >= var) {
        return var;
    }
    if (-220000000 >= var) {
        return var;
    }
    if (-200000000 >= var) {
        return var + 210000000;
    }
    if (-180000000 >= var) {
        return var + 190000000;
    }
    if (-160000000 >= var) {
        return var + 170000000;
    }
    if (-140000000 >= var) {
        return var + 150000000;
    }
    if (-120000000 >= var) {
        return var + 130000000;
    }
    if (-100000000 >= var) {
        return var + 110000000;
    }
    if (-80000000 >= var) {
        return var + 90000000;
    }
    if (-60000000 >= var) {
        return var + 70000000;
    }
    if (-40000000 >= var) {
        return var + 50000000;
    }
    if (-20000000 >= var) {
        return var + 30000000;
    }
    return var;
}

s32 get_variable_index_alt(s32 var) {
    if (-270000000 >= var) {
        return var;
    }
    if (-250000000 >= var) {
        return var;
    }
    if (-220000000 >= var) {
        return var;
    }
    if (-200000000 >= var) {
        return var + 210000000;
    }
    if (-180000000 >= var) {
        return var + 190000000;
    }
    if (-160000000 >= var) {
        return var + 170000000;
    }
    if (-140000000 >= var) {
        return var + 150000000;
    }
    if (-120000000 >= var) {
        return var + 130000000;
    }
    if (-100000000 >= var) {
        return var + 110000000;
    }
    if (-80000000 >= var) {
        return var + 90000000;
    }
    if (-60000000 >= var) {
        return var + 70000000;
    }
    if (-40000000 >= var) {
        return var + 50000000;
    }
    if (-20000000 >= var) {
        return var + 30000000;
    }
    return var;
}

INCLUDE_ASM(s32, "evt/si", set_variable, ScriptInstance* script, Bytecode var, s32 value);

// Tiny regalloc issue with the var <= -80000000 / -60000000 blocks
#ifdef NON_MATCHING
f32 get_float_variable(ScriptInstance* script, Bytecode var) {
    s32 temp;

    if (var <= -270000000) {
        return var;
    } else if (var <= -250000000) {
        return var;
    } else if (var <= -220000000) {
        return fixed_var_to_float(var);
    } else if (var <= -180000000) {
        var += 190000000;
        return fixed_var_to_float(script->array[var]);
    } else if (var <= -160000000) {
        var += 170000000;
        return fixed_var_to_float(get_global_byte(var));
    } else if (var <= -140000000) {
        var += 150000000;
        return fixed_var_to_float(get_area_byte(var));
    } else if (var <= -80000000) {
        var += 90000000;
        temp = var % 32;
        if ((gMapFlags[var / 32] & (1 << temp))) {
            return 1.0f;
        } else {
            return 0.0f;
        }
    } else if (var <= -60000000) {
        var += 70000000;
        temp = var % 32;
        if ((script->varFlags[var / 32] & (1 << temp))) {
            return 1.0f;
        } else {
            return 0.0f;
        }
    } else if (var <= -40000000) {
        var += 50000000;
        return fixed_var_to_float(gMapVars[var]);
    } else if (var <= -20000000) {
        var += 30000000;
        return fixed_var_to_float(script->varTable[var]);
    } else {
        return fixed_var_to_float(var);
    }
}
#else
INCLUDE_ASM(f32, "evt/si", get_float_variable, ScriptInstance* script, Bytecode var);
#endif

INCLUDE_ASM(f32, "evt/si", set_float_variable, ScriptInstance* script, Bytecode var, f32 value);

Bytecode* si_find_label(ScriptInstance* script, s32 arg1) {
    Bytecode* ret = script->ptrReadPos;
    s32 i;

    if (arg1 < -270000000) {
        return arg1;
    }

    for (i = 0; i < 0x10; i++) {
        if (script->labelIndices[i] == arg1) {
            ret = script->labelPositions[i];
            break;
        }
    }

    ASSERT(i < 0x10);
    return ret;
}

Bytecode* si_skip_if(ScriptInstance* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;

        switch(opcode) {
            case ScriptOpcode_END:
                PANIC();
            case ScriptOpcode_END_IF:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            case ScriptOpcode_IF_EQ:
            case ScriptOpcode_IF_NE:
            case ScriptOpcode_IF_LT:
            case ScriptOpcode_IF_GT:
            case ScriptOpcode_IF_LE:
            case ScriptOpcode_IF_GE:
            case ScriptOpcode_IF_FLAG:
            case ScriptOpcode_IF_NOT_FLAG:
                nestedIfDepth++;
                break;
            case ScriptOpcode_ELSE:
                if (nestedIfDepth == 0) {
                    return pos;
                }
            break;
        }
    } while(1);
}

Bytecode* si_skip_else(ScriptInstance* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;

        switch(opcode) {
            case ScriptOpcode_END:
                PANIC();
            case ScriptOpcode_END_IF:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            // If this isn't copy-pasted at least once, the function breaks, so
            // might as well be consistent
            case ScriptOpcode_IF_EQ:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_NE:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_LT:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_GT:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_LE:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_GE:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_FLAG:
                nestedIfDepth++;
                break;
            case ScriptOpcode_IF_NOT_FLAG:
                nestedIfDepth++;
                break;
        }
    } while(1);
}

INCLUDE_ASM(Bytecode*, "evt/si", si_goto_end_case, ScriptInstance* script);

Bytecode* si_goto_next_case(ScriptInstance* script) {
    s32 switchDepth = 1;
    Bytecode* pos = script->ptrNextLine;
    s32* opcode;
    s32* nargs;

    do {
        opcode = pos++;
        nargs = pos++;
        pos += *nargs;

        switch (*opcode) {
            case ScriptOpcode_END:
                PANIC();
            case ScriptOpcode_MATCH:
                switchDepth++;
                break;
            case ScriptOpcode_END_MATCH:
                switchDepth--;
                if (switchDepth == 0) {
                    return opcode;
                }
                break;
            case ScriptOpcode_CASE_EQ:
            case ScriptOpcode_CASE_NE:
            case ScriptOpcode_CASE_LT:
            case ScriptOpcode_CASE_GT:
            case ScriptOpcode_CASE_LE:
            case ScriptOpcode_CASE_GE:
            case ScriptOpcode_CASE_ELSE:
            case ScriptOpcode_CASE_MULTI_OR_EQ:
            case ScriptOpcode_CASE_MULTI_AND_EQ:
            case ScriptOpcode_END_CASE_MULTI:
            case ScriptOpcode_CASE_RANGE:
                if (switchDepth == 1) {
                    return opcode;
                }
            break;
        }
    } while(1);
}

INCLUDE_ASM(Bytecode*, "evt/si", si_goto_end_loop, ScriptInstance* script);
