#include "common.h"

extern u32* gMapFlags;
extern s32* gMapVars;

extern char evtDebugPrintBuffer[0x100];

Bytecode* evt_find_label(Evt* script, s32 arg1);
Bytecode* evt_skip_if(Evt* script);
Bytecode* evt_skip_else(Evt* script);
Bytecode* evt_goto_end_case(Evt* script);
Bytecode* evt_goto_next_case(Evt* script);
Bytecode* evt_goto_end_loop(Evt* script);

f32 evt_fixed_var_to_float(Bytecode scriptVar) {
    if (scriptVar <= EVT_FIXED_CUTOFF) {
        return EVT_FIXED_TO_FLOAT(scriptVar);
    } else {
        return scriptVar;
    }
}

Bytecode evt_float_to_fixed_var(f32 value) {
    // not equivalent to hte EVT_FLOAT_TO_FIXED() macro due to the s32 cast
    // occuring *before* the add here and *after* the add in the macro
    return (s32)(value * 1024.0f) + -EVT_FIXED_OFFSET;
}

ApiStatus evt_handle_return(Evt* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

ApiStatus evt_handle_label(Evt* script) {
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_goto(Evt* script) {
    script->ptrNextLine = evt_find_label(script, evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_loop(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 loopDepth = ++script->loopDepth;

    ASSERT(loopDepth < 8);

    script->loopStartTable[loopDepth] = (s32)args;
    script->loopCounterTable[loopDepth] = var;

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_loop(Evt* script) {
    s32 loopDepth = script->loopDepth;
    s32 loopCounter;

    ASSERT(loopDepth >= 0);

    loopCounter = script->loopCounterTable[loopDepth];

    if (loopCounter == 0) {
        script->ptrNextLine = (Bytecode*)script->loopStartTable[loopDepth];
        return ApiStatus_DONE2;
    }

    if (loopCounter >= -10000000) {
        script->loopCounterTable[loopDepth] = --loopCounter;
    } else {
        s32 var = evt_get_variable(script, loopCounter) - 1;
        evt_set_variable(script, loopCounter, var);
        loopCounter = var;
    }

    if (loopCounter != 0) {
        script->ptrNextLine = (Bytecode*)script->loopStartTable[loopDepth];
        return ApiStatus_DONE2;
    } else {
        script->loopDepth--;
        return ApiStatus_DONE2;
    }
}

ApiStatus evt_handle_break_loop(Evt* script) {
    ASSERT(script->loopDepth >= 0);
    script->ptrNextLine = evt_goto_end_loop(script);
    script->loopDepth -= 1;
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_wait(Evt* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (!script->blocked) {
        script->functionTemp[0] = evt_get_variable(script, *ptrReadPos);
        script->blocked = 1;
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[0] -= 1;
    return !script->functionTemp[0];
}

ApiStatus evt_handle_wait_seconds(Evt* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (!script->blocked) {
        script->functionTemp[0] = evt_get_float_variable(script, *ptrReadPos) * 30.0f + 0.5;
        script->blocked = 1;
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[0]--;
    return !script->functionTemp[0];
}

ApiStatus evt_handle_if_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 != val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_not_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 == val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_less(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 >= val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_greater(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 <= val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_less_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 > val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_greater_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 val1 = evt_get_variable(script, *args++);
    s32 val2 = evt_get_variable(script, *args++);

    if (val1 < val2) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_AND(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    if ((evt_get_variable(script, var) & *args++) == 0) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_if_not_AND(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    if ((evt_get_variable(script, var) & *args++) != 0) {
        script->ptrNextLine = evt_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_else(Evt* script) {
    script->ptrNextLine = evt_skip_else(script);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_if(Evt* script) {
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_switch(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode value = evt_get_variable(script, *args++);
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = value;
    script->switchBlockState[switchDepth] = 1;

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_switch_const(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = a0;
    script->switchBlockState[switchDepth] = 1;

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var != switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_not_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var == switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_less(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var <= switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_less_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var < switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_greater(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var >= switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_greater_equal(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var > switchBlockValue) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_range(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 var2;
    s32 switchBlockValue;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    var2 = evt_get_variable(script, *args++);

    switchBlockValue = script->switchBlockValue[switchDepth];

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if ((var <= switchBlockValue) && (switchBlockValue <= var2)) {
        script->switchBlockState[switchDepth] = 0;
    } else {
        script->ptrNextLine = evt_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_default(Evt* script) {
    s32 switchDepth = script->switchDepth;

    ASSERT(switchDepth >= 0);

    if (script->switchBlockState[switchDepth] <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_AND(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = *args++;
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState <= 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if ((var & switchBlockValue) == 0) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[switchDepth] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_equal_OR(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState == 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (var == switchBlockValue) {
        script->switchBlockState[switchDepth] = -1;
    } else if (switchBlockState != -1) {
        script->ptrNextLine = evt_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_case_equal_AND(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 switchDepth = script->switchDepth;
    s32 var;
    s32 switchBlockValue;
    s32 switchBlockState;

    ASSERT(switchDepth >= 0);

    var = evt_get_variable(script, *args++);
    switchBlockValue = script->switchBlockValue[switchDepth];
    switchBlockState = script->switchBlockState[switchDepth];

    if (switchBlockState == 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (switchBlockState == -2) {
        script->ptrNextLine = evt_goto_next_case(script);
    } else if (var == switchBlockValue) {
        script->switchBlockState[switchDepth] = -1;
    } else {
        script->switchBlockState[switchDepth] = -2;
        script->ptrNextLine = evt_goto_next_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_case_group(Evt* script) {
    ASSERT(script->switchDepth >= 0);

    if (script->switchBlockState[script->switchDepth] == 0) {
        script->ptrNextLine = evt_goto_end_case(script);
        return ApiStatus_DONE2;
    } else if (script->switchBlockState[script->switchDepth] != -1) {
        script->switchBlockState[script->switchDepth] = 1;
        script->ptrNextLine = evt_goto_next_case(script);
    } else {
        script->switchBlockState[script->switchDepth] = 0;
        script->ptrNextLine = evt_goto_end_case(script);
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_break_case(Evt* script) {
    ASSERT(script->switchDepth >= 0);
    script->ptrNextLine = evt_goto_end_case(script);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_switch(Evt* script) {
    s32 switchDepth = script->switchDepth;

    ASSERT(switchDepth >= 0);

    script->switchBlockState[switchDepth] = 0;
    script->switchDepth -= 1;

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_var(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 curPtrReadPos = *args++;

    evt_set_variable(script, curPtrReadPos, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_const(Evt* script) {
    evt_set_variable(script, *script->ptrReadPos, script->ptrReadPos[1]);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;

    evt_set_float_variable(script, var, evt_get_float_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_add(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = evt_get_variable(script, *args++);
    s32 addend = evt_get_variable(script, var);

    result += addend;

    evt_set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_subtract(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = evt_get_variable(script, *args++);
    s32 minuend = evt_get_variable(script, var);

    result = minuend - result;

    evt_set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_multiply(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = evt_get_variable(script, *args++);
    s32 multiplier = evt_get_variable(script, var);

    result *= multiplier;

    evt_set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_divide(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = evt_get_variable(script, *args++);
    s32 dividend = evt_get_variable(script, var);

    result = dividend / result;

    evt_set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_mod(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    s32 result = evt_get_variable(script, *args++) + 0.5;
    s32 num = evt_get_variable(script, var) + 0.5;

    result = num % result;

    evt_set_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_addF(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = evt_get_float_variable(script, *args++);
    f32 addend = evt_get_float_variable(script, var);

    result += addend;

    evt_set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_subtractF(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = evt_get_float_variable(script, *args++);
    f32 minuend = evt_get_float_variable(script, var);

    result = minuend - result;

    evt_set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_multiplyF(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = evt_get_float_variable(script, *args++);
    f32 multiplier = evt_get_float_variable(script, var);

    result *= multiplier;

    evt_set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_divideF(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var = *args++;
    f32 result = evt_get_float_variable(script, *args++);
    f32 dividend = evt_get_float_variable(script, var);

    result = dividend / result;

    evt_set_float_variable(script, var, result);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_int_buffer_ptr(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    script->buffer = (s32*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_float_buffer_ptr(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    script->buffer = (s32*) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_1_word(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    evt_set_variable(script, var, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_2_word(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *args++;
    evt_set_variable(script, var, *script->buffer++);

    var2 = *args++;
    evt_set_variable(script, var2, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_3_word(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *args++;
    evt_set_variable(script, var, *script->buffer++);

    var2 = *args++;
    evt_set_variable(script, var2, *script->buffer++);

    var3 = *args++;
    evt_set_variable(script, var3, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_4_word(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *args++;
    evt_set_variable(script, var, *script->buffer++);

    var2 = *args++;
    evt_set_variable(script, var2, *script->buffer++);

    var3 = *args++;
    evt_set_variable(script, var3, *script->buffer++);

    var4 = *args++;
    evt_set_variable(script, var4, *script->buffer++);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_Nth_word(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    evt_set_variable(script, var, script->buffer[evt_get_variable(script, *args++)]);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_1_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    evt_set_float_variable(script, var, evt_get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_2_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;

    var = *args++;
    evt_set_float_variable(script, var, evt_get_float_variable(script, *script->buffer++));

    var2 = *args++;
    evt_set_float_variable(script, var2, evt_get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_3_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;

    var = *args++;
    evt_set_float_variable(script, var, evt_get_float_variable(script, *script->buffer++));

    var2 = *args++;
    evt_set_float_variable(script, var2, evt_get_float_variable(script, *script->buffer++));

    var3 = *args++;
    evt_set_float_variable(script, var3, evt_get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_4_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;
    Bytecode var2;
    Bytecode var3;
    Bytecode var4;

    var = *args++;
    evt_set_float_variable(script, var, evt_get_float_variable(script, *script->buffer++));

    var2 = *args++;
    evt_set_float_variable(script, var2, evt_get_float_variable(script, *script->buffer++));

    var3 = *args++;
    evt_set_float_variable(script, var3, evt_get_float_variable(script, *script->buffer++));

    var4 = *args++;
    evt_set_float_variable(script, var4, evt_get_float_variable(script, *script->buffer++));

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_get_Nth_float(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var;

    var = *args++;
    evt_set_float_variable(script, var, script->buffer[evt_get_variable(script, *args++)]);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_array(Evt* script) {
    script->array = (s32*)evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_flag_array(Evt* script) {
    script->flagArray = (s32*)evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_allocate_array(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 size = evt_get_variable(script, *args++);
    Bytecode var = *args++;

    script->array = (s32*)heap_malloc(size * 4);
    evt_set_variable(script, var, (s32)script->array);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_AND(Evt* script) {
    Bytecode var = script->ptrReadPos[0];
    s32 val = evt_get_variable(script, script->ptrReadPos[1]);

    val &= evt_get_variable(script, var);
    evt_set_variable(script, var, val);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_AND_const(Evt* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    evt_set_variable(script, var, constant & evt_get_variable(script, var));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_OR(Evt* script) {
    Bytecode var = script->ptrReadPos[0];
    s32 val = evt_get_variable(script, script->ptrReadPos[1]);

    val |= evt_get_variable(script, var);
    evt_set_variable(script, var, val);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_OR_const(Evt* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    evt_set_variable(script, var, constant | evt_get_variable(script, var));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_call(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 isInitialCall;
    ApiFunc func;
    ApiStatus ret;

    if (script->blocked) {
        isInitialCall = FALSE;
        func = script->callFunction;
        ret = func(script, isInitialCall);
    } else {
        script->callFunction = (ApiFunc)evt_get_variable(script, *args++);
        script->ptrReadPos = args;
        script->curArgc--;
        script->blocked = TRUE;
        isInitialCall = TRUE;
        func = script->callFunction;
        ret = func(script, isInitialCall);
    }

    return ret;
}

ApiStatus evt_handle_exec1(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Evt* newScript;
    s32 i;

    newScript = start_script_in_group((EvtScript*)evt_get_variable(script, *args++), script->priority, 0,
                                      script->groupFlags);

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

    return ApiStatus_DONE2;
}


ApiStatus evt_handle_exec1_get_id(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    EvtScript* newSource = (EvtScript*)evt_get_variable(script, *args++);
    Bytecode arg2 = *args++;
    Evt* newScript;
    s32 i;

    newScript = start_script_in_group(newSource, script->priority, 0, script->groupFlags);

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

    evt_set_variable(script, arg2, newScript->id);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_exec_wait(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    start_child_script(script, (EvtScript*) evt_get_variable(script, *args++), 0);
    script->curOpcode = EVT_OP_INTERNAL_FETCH;
    return ApiStatus_FINISH;
}

ApiStatus evt_handle_jump(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    script->ptrFirstLine = (Bytecode*) evt_get_variable(script, *args++);
    restart_script(script);
    return ApiStatus_DONE2;
}

s32 evt_trigger_on_activate_exec_script(Trigger* trigger) {
    EvtScript* scriptStart;
    Evt* script;

    if (trigger->runningScript == NULL) {
        scriptStart = trigger->onTriggerEvt;
        if (is_another_trigger_bound(trigger, scriptStart)) {
            return 0;
        }

        script = start_script(scriptStart, trigger->priority, EVT_FLAG_RUN_IMMEDIATELY);
        trigger->runningScript = script;
        trigger->runningScriptID = script->id;
        script->varTable[0] = trigger->varTable[0];
        script->varTable[1] = trigger->varTable[1];
        script->varTable[2] = trigger->varTable[2];
        script->owner2.trigger = trigger;
    }

    if (!does_script_exist(trigger->runningScriptID)) {
        trigger->runningScript = NULL;
        return 0; // stop calling this function
    }

    return 1; // keep calling this function every frame
}

ApiStatus evt_handle_bind(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Trigger* trigger;
    Bytecode* triggerScript = (Bytecode*)evt_get_variable(script, *args++);
    Bytecode triggerType = *args++;
    Bytecode colliderIDVar = *args++;
    Bytecode hasInteractPrompt = *args++;
    Bytecode triggerOut = *args++;
    TriggerBlueprint bp;

    bp.flags = triggerType | TRIGGER_SCRIPT_BOUND;
    bp.colliderID = evt_get_variable(script, colliderIDVar);
    bp.varIndex = evt_get_variable_index(script, colliderIDVar);
    bp.hasPlayerInteractPrompt = hasInteractPrompt;
    bp.tattleMsg = 0;
    bp.onActivateFunc = evt_trigger_on_activate_exec_script;

    trigger = create_trigger(&bp);
    trigger->onTriggerEvt = (EvtScript*)triggerScript;
    trigger->runningScript = NULL;
    trigger->priority = script->priority;
    trigger->varTable[0] = evt_get_variable(script, script->varTable[0]);
    trigger->varTable[1] = evt_get_variable(script, script->varTable[1]);
    trigger->varTable[2] = evt_get_variable(script, script->varTable[2]);

    if (triggerOut != 0) {
        evt_set_variable(script, triggerOut, (s32)trigger);
    }

    return ApiStatus_DONE2;
}

ApiStatus DeleteTrigger(Evt* script, s32 isInitialCall) {
    delete_trigger((Trigger*)evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_unbind(Evt* script) {
    delete_trigger(script->owner2.trigger);
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_kill(Evt* script) {
    kill_script_by_ID(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_priority(Evt* script) {
    set_script_priority(script, evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_timescale(Evt* script) {
    set_script_timescale(script, evt_get_float_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_set_group(Evt* script) {
    set_script_group(script, evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_suspend_all(Evt* script) {
    suspend_all_group(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_resume_all(Evt* script) {
    resume_all_group(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_suspend_others(Evt* script) {
    suspend_group_others(script, evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_resume_others(Evt* script) {
    resume_group_others(script, evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_suspend(Evt* script) {
    suspend_all_script(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_resume(Evt* script) {
    resume_all_script(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_does_script_exist(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 scriptID = evt_get_variable(script, *args++);
    Bytecode var2 = *args++;

    evt_set_variable(script, var2, does_script_exist(scriptID));
    return ApiStatus_DONE2;
}

s32 evt_trigger_on_activate_lock(Trigger* trigger) {
    if (trigger->runningScript == NULL) {
        Evt* newScript = start_script(trigger->onTriggerEvt, trigger->priority, EVT_FLAG_RUN_IMMEDIATELY);
        trigger->runningScript = newScript;
        trigger->runningScriptID = newScript->id;
        newScript->varTable[0] = trigger->varTable[0];
        newScript->varTable[1] = trigger->varTable[1];
        newScript->varTable[2] = trigger->varTable[2];
        newScript->owner2.trigger = trigger;
    }

    if (!does_script_exist(trigger->runningScriptID)) {
        trigger->runningScript = NULL;
        trigger->flags.flags &= ~TRIGGER_ACTIVATED;
    }
}

ApiStatus evt_handle_bind_lock(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    Trigger* trigger;
    Bytecode* triggerScript = (Bytecode*)evt_get_variable(script, *args++);
    Bytecode triggerType = *args++;
    Bytecode colliderIDVar = *args++;
    s32* itemList = (s32*)evt_get_variable(script, *args++);
    Bytecode triggerOut = *args++;
    s32 hasInteractPrompt = *args++;
    TriggerBlueprint bp;

    bp.flags = triggerType | TRIGGER_SCRIPT_BOUND;
    bp.colliderID = evt_get_variable(script, colliderIDVar);
    bp.varIndex = evt_get_variable_index(script, colliderIDVar);
    bp.itemList = itemList;
    bp.onActivateFunc = evt_trigger_on_activate_lock;
    bp.tattleMsg = triggerOut;
    bp.hasPlayerInteractPrompt = hasInteractPrompt;

    trigger = create_trigger(&bp);
    trigger->onTriggerEvt = (EvtScript*)triggerScript;
    trigger->runningScript = NULL;
    trigger->priority = script->priority;
    trigger->varTable[0] = evt_get_variable(script, script->varTable[0]);
    trigger->varTable[1] = evt_get_variable(script, script->varTable[1]);
    trigger->varTable[2] = evt_get_variable(script, script->varTable[2]);

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_thread(Evt* script) {
    Evt* newScript;
    s32 nargs;
    s32 opcode;
    s32 i;

    // seek end thread opcode
    Bytecode* startLine = script->ptrNextLine;
    Bytecode* endLine = startLine;
    do {
        opcode = *endLine++;
        nargs = *endLine++;
        endLine += nargs;
    } while (opcode != EVT_OP_END_THREAD);

    script->ptrNextLine = endLine;
    newScript = start_script_in_group((EvtScript*)startLine, script->priority, EVT_FLAG_RUN_IMMEDIATELY | EVT_FLAG_THREAD, script->groupFlags);
    newScript->owner1.enemyID = script->owner1.enemyID;
    newScript->owner2.npcID = script->owner2.npcID;
    newScript->array = script->array;
    newScript->flagArray = script->flagArray;

    for (i = 0; i < ARRAY_COUNT(script->varTable); i++) {
        newScript->varTable[i] = script->varTable[i];
    }

    for (i = 0; i < ARRAY_COUNT(script->varFlags); i++) {
        newScript->varFlags[i] = script->varFlags[i];
    }

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_thread(Evt* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

ApiStatus evt_handle_child_thread(Evt* script) {
    Evt* newScript;
    s32 nargs;
    s32 opcode;
    s32 i;

    Bytecode* startLine = script->ptrNextLine;
    Bytecode* endLine = startLine;
    do {
        opcode = *endLine++;
        nargs = *endLine++;
        endLine += nargs;
    } while (opcode != EVT_OP_END_CHILD_THREAD);

    script->ptrNextLine = endLine;
    newScript = func_802C39F8(script, startLine, EVT_FLAG_RUN_IMMEDIATELY | EVT_FLAG_THREAD);
    newScript->owner1.enemyID = script->owner1.enemyID;
    newScript->owner2.npcID = script->owner2.npcID;
    newScript->groupFlags = script->groupFlags;
    newScript->array = script->array;
    newScript->flagArray = script->flagArray;

    return ApiStatus_DONE2;
}

ApiStatus evt_handle_end_child_thread(Evt* script) {
    kill_script(script);
    return ApiStatus_BLOCK;
}

ApiStatus evt_handle_debug_log(Evt* script) {
    return ApiStatus_DONE2;
}

ApiStatus evt_handle_print_debug_var(Evt* script);

// TODO: Fake match, seems to be UB for some of the print calls.
s32 evt_handle_print_debug_var(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 var = *args++;
    s32 flagBitPos;

    do {} while (0);

    if (var <= EVT_LIMIT) {
        sprintf(evtDebugPrintBuffer, "ADDR     [%08X]", var);
    } else if (var <= EVT_FIXED_CUTOFF) {
        sprintf(evtDebugPrintBuffer, "FLOAT    [%4.2f]", evt_fixed_var_to_float(var));
    } else if (var <= EVT_ARRAY_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_FLAG(var);
        flagBitPos = var % 32;
        sprintf(evtDebugPrintBuffer, "UF(%3d)  [%d]", var, script->flagArray[var / 32] & (1 << flagBitPos));
    } else if (var <= EVT_ARRAY_VAR_CUTOFF) {
        s32 arrayVal;

        var = EVT_INDEX_OF_ARRAY_VAR(var);
        arrayVal = script->array[var];

        if (script->array[var] <= EVT_LIMIT) {
            sprintf(evtDebugPrintBuffer, "UW(%3d)  [%08X]", arrayVal);
        } else if (arrayVal <= EVT_FIXED_CUTOFF) {
            sprintf(evtDebugPrintBuffer, "UW(%3d)  [%4.2f]", var, evt_fixed_var_to_float(arrayVal));
        } else {
            sprintf(evtDebugPrintBuffer, "UW(%3d)  [%d]", var, arrayVal);
        }
    } else if (var <= EVT_GAME_BYTE_CUTOFF) {
        s32 globalByte;

        var = EVT_INDEX_OF_GAME_BYTE(var);
        globalByte = get_global_byte(var);

        if (globalByte <= EVT_LIMIT) {
            sprintf(evtDebugPrintBuffer, "GSW(%3d) [%08X]", globalByte);
        } else if (globalByte <= EVT_FIXED_CUTOFF) {
            sprintf(evtDebugPrintBuffer, "GSW(%3d) [%4.2f]", var, evt_fixed_var_to_float(globalByte));
        } else {
            sprintf(evtDebugPrintBuffer, "GSW(%3d) [%d]", var, globalByte);
        }
    } else if (var <= EVT_AREA_BYTE_CUTOFF) {
        s32 areaByte;

        var = EVT_INDEX_OF_AREA_BYTE(var);
        areaByte = get_area_byte(var);

        if (areaByte <= EVT_LIMIT) {
            sprintf(evtDebugPrintBuffer, "LSW(%3d) [%08X]", areaByte);
        } else if (areaByte <= EVT_FIXED_CUTOFF) {
            sprintf(evtDebugPrintBuffer, "LSW(%3d)  [%4.2f]", var, evt_fixed_var_to_float(areaByte));
        } else {
            sprintf(evtDebugPrintBuffer, "LSW(%3d) [%d]", var, areaByte);
        }
    } else if (var <= EVT_GAME_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_GAME_FLAG(var);
        sprintf(evtDebugPrintBuffer, "GSWF(%3d)[%d]", var, get_global_flag(var));
    } else if (var <= EVT_AREA_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_AREA_FLAG(var);
        sprintf(evtDebugPrintBuffer, "LSWF(%3d)[%d]", var, get_area_flag(var));
    } else if (var <= EVT_MAP_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_MAP_FLAG(var);
        flagBitPos = var % 32;
        sprintf(evtDebugPrintBuffer, "GF(%3d)  [%d]", var, gMapFlags[var / 32] & (1 << flagBitPos));
    } else if (var <= EVT_LOCAL_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_FLAG(var);
        flagBitPos = var % 32;
        sprintf(evtDebugPrintBuffer, "LF(%3d)  [%d]", var, script->varFlags[var / 32] & (1 << flagBitPos));
    } else if (var <= EVT_MAP_VAR_CUTOFF) {
        s32 mapVar;
        s32 temp;

        do {
            var = EVT_INDEX_OF_MAP_VAR(var);
            mapVar = gMapVars[var];
            temp = EVT_LIMIT;
        } while (0);

        if (mapVar <= temp) {
            sprintf(evtDebugPrintBuffer, "GW(%3d)  [%08X]", mapVar);
        } else if (mapVar <= EVT_FIXED_CUTOFF) {
            sprintf(evtDebugPrintBuffer, "GW(%3d)  [%4.2f]", var, evt_fixed_var_to_float(mapVar));
        } else {
            sprintf(evtDebugPrintBuffer, "GW(%3d)  [%d]", var, mapVar);
        }
    } else if (var <= EVT_LOCAL_VAR_CUTOFF) {
        s32 tableVar;

        var = EVT_INDEX_OF_LOCAL_VAR(var);
        tableVar = script->varTable[var];

        do {} while (0);

        if (tableVar <= EVT_LIMIT) {
            sprintf(evtDebugPrintBuffer, "LW(%3d)  [%08X]", tableVar);
        } else if (tableVar <= EVT_FIXED_CUTOFF) {
            sprintf(evtDebugPrintBuffer, "LW(%3d)  [%4.2f]", var, evt_fixed_var_to_float(tableVar));
        } else {
            sprintf(evtDebugPrintBuffer, "LW(%3d)  [%d]", var, tableVar);
        }
    } else {
        sprintf(evtDebugPrintBuffer, "         [%d]", var);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802C739C(Evt* script) {
    script->ptrSavedPos = (Bytecode*)*script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus func_802C73B0(Evt* script) {
    return ApiStatus_DONE2;
}

ApiStatus func_802C73B8(Evt* script) {
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if (script == get_script_by_index(i)) {
            break;
        }
    }
    return ApiStatus_DONE1;
}

s32 evt_execute_next_command(Evt* script) {
    while (TRUE) {
        s32 status = ApiStatus_DONE2;
        s32* lines;
        s32 nargs;

        switch (script->curOpcode) {
            case EVT_OP_INTERNAL_FETCH:
                script->ptrCurLine = script->ptrNextLine;
                lines = script->ptrNextLine;
                script->curOpcode = *lines++;
                nargs = *lines++;
                script->ptrReadPos = lines;
                script->blocked = FALSE;
                script->curArgc = nargs;
                lines = &lines[nargs];
                script->ptrNextLine = lines;
                status = ApiStatus_REPEAT;
                break;
            case EVT_OP_RETURN:
                status = evt_handle_return(script);
                break;
            case EVT_OP_LABEL:
                status = evt_handle_label(script);
                break;
            case EVT_OP_GOTO:
                status = evt_handle_goto(script);
                break;
            case EVT_OP_LOOP:
                status = evt_handle_loop(script);
                break;
            case EVT_OP_END_LOOP:
                status = evt_handle_end_loop(script);
                break;
            case EVT_OP_BREAK_LOOP:
                status = evt_handle_break_loop(script);
                break;
            case EVT_OP_WAIT_FRAMES:
                status = evt_handle_wait(script);
                break;
            case EVT_OP_WAIT_SECS:
                status = evt_handle_wait_seconds(script);
                break;
            case EVT_OP_IF_EQ:
                status = evt_handle_if_equal(script);
                break;
            case EVT_OP_IF_NE:
                status = evt_handle_if_not_equal(script);
                break;
            case EVT_OP_IF_LT:
                status = evt_handle_if_less(script);
                break;
            case EVT_OP_IF_GT:
                status = evt_handle_if_greater(script);
                break;
            case EVT_OP_IF_LE:
                status = evt_handle_if_less_equal(script);
                break;
            case EVT_OP_IF_GE:
                status = evt_handle_if_greater_equal(script);
                break;
            case EVT_OP_IF_FLAG:
                status = evt_handle_if_AND(script);
                break;
            case EVT_OP_IF_NOT_FLAG:
                status = evt_handle_if_not_AND(script);
                break;
            case EVT_OP_ELSE:
                status = evt_handle_else(script);
                break;
            case EVT_OP_END_IF:
                status = evt_handle_end_if(script);
                break;
            case EVT_OP_SWITCH:
                status = evt_handle_switch(script);
                break;
            case EVT_OP_SWITCH_CONST:
                status = evt_handle_switch_const(script);
                break;
            case EVT_OP_CASE_EQ:
                status = evt_handle_case_equal(script);
                break;
            case EVT_OP_CASE_NE:
                status = evt_handle_case_not_equal(script);
                break;
            case EVT_OP_CASE_LT:
                status = evt_handle_case_less(script);
                break;
            case EVT_OP_CASE_LE:
                status = evt_handle_case_less_equal(script);
                break;
            case EVT_OP_CASE_GT:
                status = evt_handle_case_greater(script);
                break;
            case EVT_OP_CASE_GE:
                status = evt_handle_case_greater_equal(script);
                break;
            case EVT_OP_CASE_DEFAULT:
                status = evt_handle_case_default(script);
                break;
            case EVT_OP_BREAK_SWITCH:
                status = evt_handle_break_case(script);
                break;
            case EVT_OP_CASE_OR_EQ:
                status = evt_handle_case_equal_OR(script);
                break;
            case EVT_OP_END_CASE_GROUP:
                status = evt_handle_end_case_group(script);
                break;
            case EVT_OP_CASE_AND_EQ:
                status = evt_handle_case_equal_AND(script);
                break;
            case EVT_OP_CASE_FLAG:
                status = evt_handle_case_AND(script);
                break;
            case EVT_OP_CASE_RANGE:
                status = evt_handle_case_range(script);
                break;
            case EVT_OP_END_SWITCH:
                status = evt_handle_end_switch(script);
                break;
            case EVT_OP_SET:
                status = evt_handle_set_var(script);
                break;
            case EVT_OP_SET_CONST:
                status = evt_handle_set_const(script);
                break;
            case EVT_OP_SETF:
                status = evt_handle_set_float(script);
                break;
            case EVT_OP_ADD:
                status = evt_handle_add(script);
                break;
            case EVT_OP_SUB:
                status = evt_handle_subtract(script);
                break;
            case EVT_OP_MUL:
                status = evt_handle_multiply(script);
                break;
            case EVT_OP_DIV:
                status = evt_handle_divide(script);
                break;
            case EVT_OP_MOD:
                status = evt_handle_mod(script);
                break;
            case EVT_OP_ADDF:
                status = evt_handle_addF(script);
                break;
            case EVT_OP_SUBF:
                status = evt_handle_subtractF(script);
                break;
            case EVT_OP_MULF:
                status = evt_handle_multiplyF(script);
                break;
            case EVT_OP_DIVF:
                status = evt_handle_divideF(script);
                break;
            case EVT_OP_USE_BUF:
                status = evt_handle_set_int_buffer_ptr(script);
                break;
            case EVT_OP_BUF_READ1:
                status = evt_handle_get_1_word(script);
                break;
            case EVT_OP_BUF_READ2:
                status = evt_handle_get_2_word(script);
                break;
            case EVT_OP_BUF_READ3:
                status = evt_handle_get_3_word(script);
                break;
            case EVT_OP_BUF_READ4:
                status = evt_handle_get_4_word(script);
                break;
            case EVT_OP_BUF_PEEK:
                status = evt_handle_get_Nth_word(script);
                break;
            case EVT_OP_USE_FBUF:
                status = evt_handle_set_float_buffer_ptr(script);
                break;
            case EVT_OP_FBUF_READ1:
                status = evt_handle_get_1_float(script);
                break;
            case EVT_OP_FBUF_READ2:
                status = evt_handle_get_2_float(script);
                break;
            case EVT_OP_FBUF_READ3:
                status = evt_handle_get_3_float(script);
                break;
            case EVT_OP_FBUF_READ4:
                status = evt_handle_get_4_float(script);
                break;
            case EVT_OP_FBUF_PEEK:
                status = evt_handle_get_Nth_float(script);
                break;
            case EVT_OP_USE_ARRAY:
                status = evt_handle_set_array(script);
                break;
            case EVT_OP_USE_FLAGS:
                status = evt_handle_set_flag_array(script);
                break;
            case EVT_OP_MALLOC_ARRAY:
                status = evt_handle_allocate_array(script);
                break;
            case EVT_OP_KILL_THREAD:
                status = evt_handle_kill(script);
                break;
            case EVT_OP_BITWISE_AND:
                status = evt_handle_AND(script);
                break;
            case EVT_OP_BITWISE_AND_CONST:
                status = evt_handle_AND_const(script);
                break;
            case EVT_OP_BITWISE_OR:
                status = evt_handle_OR(script);
                break;
            case EVT_OP_BITWISE_OR_CONST:
                status = evt_handle_OR_const(script);
                break;
            case EVT_OP_CALL:
                status = evt_handle_call(script);
                break;
            case EVT_OP_EXEC:
                status = evt_handle_exec1(script);
                break;
            case EVT_OP_EXEC_GET_TID:
                status = evt_handle_exec1_get_id(script);
                break;
            case EVT_OP_EXEC_WAIT:
                status = evt_handle_exec_wait(script);
                break;
            case EVT_OP_BIND_TRIGGER:
                status = evt_handle_bind(script);
                break;
            case EVT_OP_UNBIND:
                status = evt_handle_unbind(script);
                break;
            case EVT_OP_SET_PRIORITY:
                status = evt_handle_set_priority(script);
                break;
            case EVT_OP_SET_TIMESCALE:
                status = evt_handle_set_timescale(script);
                break;
            case EVT_OP_SET_GROUP:
                status = evt_handle_set_group(script);
                break;
            case EVT_OP_JUMP:
                status = evt_handle_jump(script);
                break;
            case EVT_OP_BIND_PADLOCK:
                status = evt_handle_bind_lock(script);
                break;
            case EVT_OP_SUSPEND_GROUP:
                status = evt_handle_suspend_all(script);
                break;
            case EVT_OP_RESUME_GROUP:
                status = evt_handle_resume_all(script);
                break;
            case EVT_OP_SUSPEND_OTHERS:
                status = evt_handle_suspend_others(script);
                break;
            case EVT_OP_RESUME_OTHERS:
                status = evt_handle_resume_others(script);
                break;
            case EVT_OP_SUSPEND_THREAD:
                status = evt_handle_suspend(script);
                break;
            case EVT_OP_RESUME_THREAD:
                status = evt_handle_resume(script);
                break;
            case EVT_OP_IS_THREAD_RUNNING:
                status = evt_handle_does_script_exist(script);
                break;
            case EVT_OP_THREAD:
                status = evt_handle_thread(script);
                break;
            case EVT_OP_END_THREAD:
                status = evt_handle_end_thread(script);
                break;
            case EVT_OP_CHILD_THREAD:
                status = evt_handle_child_thread(script);
                break;
            case EVT_OP_END_CHILD_THREAD:
                status = evt_handle_end_child_thread(script);
                break;
            case EVT_OP_DEBUG_LOG:
                status = evt_handle_debug_log(script);
                break;
            case EVT_OP_DEBUG_PRINT_VAR:
                status = evt_handle_print_debug_var(script);
                break;
            case EVT_OP_92:
                status = func_802C739C(script);
                break;
            case EVT_OP_93:
                status = func_802C73B0(script);
                break;
            case EVT_OP_94:
                status = func_802C73B8(script);
            case EVT_OP_END:
                break;
            default:
                PANIC();
        }

        if (status == ApiStatus_REPEAT) {
            continue;
        }

        if (status == ApiStatus_FINISH) {
            return EVT_CMD_RESULT_YIELD;
        }

        if (status < 0) {
            return EVT_CMD_RESULT_ERROR;
        }

        // TODO: this may be able to be a switch but I couldn't get it
        if (status == ApiStatus_BLOCK) {
            // return 0
        } else if (status == ApiStatus_DONE1) {
            script->curOpcode = EVT_OP_INTERNAL_FETCH;
            // return 0
        } else if (status == ApiStatus_DONE2) {
            script->curOpcode = EVT_OP_INTERNAL_FETCH;
            if (gGameStatusPtr->disableScripts != status) {
                continue;
            }
            // return 0
        } else {
            continue;
        }
        return EVT_CMD_RESULT_CONTINUE;
    }
}

s32 evt_get_variable(Evt* script, Bytecode var) {
    s32 wordIdx;
    s32 bitIdx;
    s32 temp;

    if (var <= EVT_LIMIT) {
        return var;
    } else if (var <= EVT_IGNORE_ARG) {
        return var;
    } else if (var <= EVT_FIXED_CUTOFF) {
        return evt_fixed_var_to_float(var);
    } else if (var <= EVT_ARRAY_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_FLAG(var);
        wordIdx = var / 32;
        bitIdx = var % 32;
        var = (script->flagArray[wordIdx] & (1 << bitIdx)) != 0;
        return var;
    } else if (var <= EVT_ARRAY_VAR_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_VAR(var);
        var = script->array[var];
        if (var > EVT_LIMIT) {
            if (var <= EVT_FIXED_CUTOFF){
                var = evt_fixed_var_to_float(var);
            }
        }
    } else if (var <= EVT_GAME_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_GAME_BYTE(var);
        return get_global_byte(var);
    } else if (var <= EVT_AREA_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_AREA_BYTE(var);
        return get_area_byte(var);
    } else if (var <= EVT_GAME_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_GAME_FLAG(var);
        return get_global_flag(var);
    } else if (var <= EVT_AREA_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_AREA_FLAG(var);
        return get_area_flag(var);
    } else if (var <= EVT_MAP_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_MAP_FLAG(var);
        wordIdx = var;
        bitIdx = var % 32;
        var = (gMapFlags[wordIdx / 32] & (1 << bitIdx)) != 0;
        return var;
    } else if (var <= EVT_LOCAL_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_FLAG(var);
        wordIdx = var;
        bitIdx = var % 32;
        var = (script->varFlags[wordIdx / 32] & (1 << bitIdx)) != 0;
        return var;
    } else if (var <= EVT_MAP_VAR_CUTOFF) {
        var = EVT_INDEX_OF_MAP_VAR(var);
        var = gMapVars[var];
        if (var > EVT_LIMIT) {
            temp = EVT_FIXED_CUTOFF;
            if (var <= temp){
                var = evt_fixed_var_to_float(var);
            }
        }
    } else if (var <= EVT_LOCAL_VAR_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_VAR(var);
        var = script->varTable[var];
        if (var > EVT_LIMIT) {
            temp = EVT_FIXED_CUTOFF;
            if (var <= temp){
                var = evt_fixed_var_to_float(var);
            }
        }
    }
        return var;
}

s32 evt_get_variable_index(Evt* script, s32 var) {
    if (EVT_LIMIT >= var) {
        return var;
    }
    if (EVT_IGNORE_ARG >= var) {
        return var;
    }
    if (EVT_FIXED_CUTOFF >= var) {
        return var;
    }
    if (EVT_ARRAY_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_ARRAY_FLAG(var);
    }
    if (EVT_ARRAY_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_ARRAY_VAR(var);
    }
    if (EVT_GAME_BYTE_CUTOFF >= var) {
        return EVT_INDEX_OF_GAME_BYTE(var);
    }
    if (EVT_AREA_BYTE_CUTOFF >= var) {
        return EVT_INDEX_OF_AREA_BYTE(var);
    }
    if (EVT_GAME_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_GAME_FLAG(var);
    }
    if (EVT_AREA_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_AREA_FLAG(var);
    }
    if (EVT_MAP_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_MAP_FLAG(var);
    }
    if (EVT_LOCAL_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_LOCAL_FLAG(var);
    }
    if (EVT_MAP_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_MAP_VAR(var);
    }
    if (EVT_LOCAL_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_LOCAL_VAR(var);
    }
    return var;
}

s32 evt_get_variable_index_alt(s32 var) {
    if (EVT_LIMIT >= var) {
        return var;
    }
    if (EVT_IGNORE_ARG >= var) {
        return var;
    }
    if (EVT_FIXED_CUTOFF >= var) {
        return var;
    }
    if (EVT_ARRAY_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_ARRAY_FLAG(var);
    }
    if (EVT_ARRAY_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_ARRAY_VAR(var);
    }
    if (EVT_GAME_BYTE_CUTOFF >= var) {
        return EVT_INDEX_OF_GAME_BYTE(var);
    }
    if (EVT_AREA_BYTE_CUTOFF >= var) {
        return EVT_INDEX_OF_AREA_BYTE(var);
    }
    if (EVT_GAME_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_GAME_FLAG(var);
    }
    if (EVT_AREA_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_AREA_FLAG(var);
    }
    if (EVT_MAP_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_MAP_FLAG(var);
    }
    if (EVT_LOCAL_FLAG_CUTOFF >= var) {
        return EVT_INDEX_OF_LOCAL_FLAG(var);
    }
    if (EVT_MAP_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_MAP_VAR(var);
    }
    if (EVT_LOCAL_VAR_CUTOFF >= var) {
        return EVT_INDEX_OF_LOCAL_VAR(var);
    }
    return var;
}

s32 evt_set_variable(Evt* script, Bytecode var, s32 value) {
    s32 flagBitPos;
    s32 oldValue;

    if (var <= EVT_LIMIT) {
        return value;
    } else if (var <= EVT_FIXED_CUTOFF) {
        return evt_fixed_var_to_float(value);
    } else if (var <= EVT_ARRAY_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_FLAG(var);
        flagBitPos = var % 32;
        if (value) {
            script->flagArray[var / 32] |= 1 << flagBitPos;
        } else {
            script->flagArray[var / 32] &= ~(1 << flagBitPos);
        }
        return value;
    } else if (var <= EVT_ARRAY_VAR_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_VAR(var);
        oldValue = script->array[var];
        script->array[var] = value;
        return oldValue;
    } else if (var <= EVT_GAME_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_GAME_BYTE(var);
        oldValue = get_global_byte(var);
        set_global_byte(var, value);
        return oldValue;
    } else if (var <= EVT_AREA_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_AREA_BYTE(var);
        oldValue = get_area_byte(var);
        set_area_byte(var, value);
        return oldValue;
    } else if (var <= EVT_GAME_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_GAME_FLAG(var);
        oldValue = get_global_flag(var);
        if (value) {
            set_global_flag(var);
        } else {
            clear_global_flag(var);
        }
        return oldValue;
    } else if (var <= EVT_AREA_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_AREA_FLAG(var);
        oldValue = get_area_flag(var);
        if (value) {
            set_area_flag(var);
        } else {
            clear_area_flag(var);
        }
        return oldValue;
    } else if (var <= EVT_MAP_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_MAP_FLAG(var);
        flagBitPos = var % 32;
        if (value) {
            gMapFlags[var / 32] |= 1 << flagBitPos;
        } else {
            gMapFlags[var / 32] &= ~(1 << flagBitPos);
        }
        return value;
    } else if (var <= EVT_LOCAL_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_FLAG(var);
        flagBitPos = var % 32;
        if (value) {
            script->varFlags[var / 32] |= 1 << flagBitPos;
        } else {
            script->varFlags[var / 32] &= ~(1 << flagBitPos);
        }
        return value;
    } else if (var <= EVT_MAP_VAR_CUTOFF) {
        var = EVT_INDEX_OF_MAP_VAR(var);
        oldValue = gMapVars[var];
        gMapVars[var] = value;
        return oldValue;
    } else if (var <= EVT_LOCAL_VAR_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_VAR(var);
        oldValue = script->varTable[var];
        script->varTable[var] = value;
        return oldValue;
    } else {
        return value;
    }
}

f32 evt_get_float_variable(Evt* script, Bytecode var) {
    s32 temp;

    if (var <= EVT_LIMIT) {
        return var;
    } else if (var <= EVT_IGNORE_ARG) {
        return var;
    } else if (var <= EVT_FIXED_CUTOFF) {
        return evt_fixed_var_to_float(var);
    } else if (var <= EVT_ARRAY_VAR_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_VAR(var);
        return evt_fixed_var_to_float(script->array[var]);
    } else if (var <= EVT_GAME_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_GAME_BYTE(var);
        return evt_fixed_var_to_float(get_global_byte(var));
    } else if (var <= EVT_AREA_BYTE_CUTOFF) {
        var = EVT_INDEX_OF_AREA_BYTE(var);
        return evt_fixed_var_to_float(get_area_byte(var));
    } else if (var <= EVT_MAP_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_MAP_FLAG(var);
        temp = var % 32;
        var = gMapFlags[var / 32] & (1 << temp);
        if (var) {
            return 1.0f;
        } else {
            return 0.0f;
        }
    } else if (var <= EVT_LOCAL_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_FLAG(var);
        temp = var % 32;
        var = script->varFlags[var / 32] & (1 << temp);
        if (var) {
            return 1.0f;
        } else {
            return 0.0f;
        }
    } else if (var <= EVT_MAP_VAR_CUTOFF) {
        var = EVT_INDEX_OF_MAP_VAR(var);
        return evt_fixed_var_to_float(gMapVars[var]);
    } else if (var <= EVT_LOCAL_VAR_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_VAR(var);
        return evt_fixed_var_to_float(script->varTable[var]);
    } else {
        return evt_fixed_var_to_float(var);
    }
}

f32 evt_set_float_variable(Evt* script, Bytecode var, f32 value) {
    s32 temp;
    s32 oldValue;

    if (var <= EVT_LIMIT) {
        return value;
    } else if (var <= EVT_FIXED_CUTOFF) {
        return value;
    } else if (var <= EVT_ARRAY_VAR_CUTOFF) {
        var = EVT_INDEX_OF_ARRAY_VAR(var);
        oldValue = script->array[var];
        script->array[var] = evt_float_to_fixed_var(value);
        return evt_fixed_var_to_float(oldValue);
    } else if (var <= EVT_MAP_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_MAP_FLAG(var);
        temp = var % 32;
        if (value) {
            gMapFlags[var / 32] |= 1 << temp;
        } else {
            gMapFlags[var / 32] &= ~(1 << temp);
        }
        return value;
    } else if (var <= EVT_LOCAL_FLAG_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_FLAG(var);
        temp = var % 32;
        if (value) {
            script->varFlags[var / 32] |= 1 << temp;
        } else {
            script->varFlags[var / 32] &= ~(1 << temp);
        }
        return value;
    } else if (var <= EVT_MAP_VAR_CUTOFF) {
        var = EVT_INDEX_OF_MAP_VAR(var);
        oldValue = gMapVars[var];
        gMapVars[var] = evt_float_to_fixed_var(value);
        return evt_fixed_var_to_float(oldValue);
    } else if (var <= EVT_LOCAL_VAR_CUTOFF) {
        var = EVT_INDEX_OF_LOCAL_VAR(var);
        oldValue = script->varTable[var];
        script->varTable[var] = evt_float_to_fixed_var(value);
        return evt_fixed_var_to_float(oldValue);
    } else {
        return value;
    }
}

Bytecode* evt_find_label(Evt* script, s32 arg1) {
    Bytecode* ret = script->ptrReadPos;
    s32 i;

    if (arg1 < EVT_LIMIT) {
        return (Bytecode*) arg1;
    }

    for (i = 0; i < 16; i++) {
        if (script->labelIndices[i] == arg1) {
            ret = script->labelPositions[i];
            break;
        }
    }

    ASSERT(i < 16);
    return ret;
}

Bytecode* evt_skip_if(Evt* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;

        switch (opcode) {
            case EVT_OP_END:
                PANIC();
            case EVT_OP_END_IF:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            case EVT_OP_IF_EQ:
            case EVT_OP_IF_NE:
            case EVT_OP_IF_LT:
            case EVT_OP_IF_GT:
            case EVT_OP_IF_LE:
            case EVT_OP_IF_GE:
            case EVT_OP_IF_FLAG:
            case EVT_OP_IF_NOT_FLAG:
                nestedIfDepth++;
                break;
            case EVT_OP_ELSE:
                if (nestedIfDepth == 0) {
                    return pos;
                }
            break;
        }
    } while (TRUE);
}

Bytecode* evt_skip_else(Evt* script) {
    s32 nestedIfDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    Bytecode opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;

        switch (opcode) {
            case EVT_OP_END:
                PANIC();
            case EVT_OP_END_IF:
                nestedIfDepth--;
                if (nestedIfDepth < 0) {
                    return pos;
                }
                break;
            case EVT_OP_IF_EQ:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_NE:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_LT:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_GT:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_LE:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_GE:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_FLAG:
                nestedIfDepth++;
                break;
            case EVT_OP_IF_NOT_FLAG:
                nestedIfDepth++;
                break;
        }
    } while (TRUE);
}

Bytecode* evt_goto_end_case(Evt* script) {
    s32 switchDepth = 1;
    Bytecode* pos = script->ptrNextLine;
    s32* opcode;
    s32* nargs;

    do {
        opcode = pos++;
        nargs = pos++;
        pos += *nargs;

        switch (*opcode) {
            case EVT_OP_END:
                PANIC();
                break;
            case EVT_OP_SWITCH:
                switchDepth++;
                break;
            case EVT_OP_END_SWITCH:
                switchDepth--;
                if (switchDepth == 0) {
                    return opcode;
                }
                break;
        }
    } while (TRUE);
}

Bytecode* evt_goto_next_case(Evt* script) {
    s32 switchDepth = 1;
    Bytecode* pos = script->ptrNextLine;
    s32* opcode;
    s32* nargs;

    do {
        opcode = pos++;
        nargs = pos++;
        pos += *nargs;

        switch (*opcode) {
            case EVT_OP_END:
                PANIC();
                break;
            case EVT_OP_SWITCH:
                switchDepth++;
                break;
            case EVT_OP_END_SWITCH:
                switchDepth--;
                if (switchDepth == 0) {
                    return opcode;
                }
                break;
            case EVT_OP_CASE_EQ:
            case EVT_OP_CASE_NE:
            case EVT_OP_CASE_LT:
            case EVT_OP_CASE_GT:
            case EVT_OP_CASE_LE:
            case EVT_OP_CASE_GE:
            case EVT_OP_CASE_DEFAULT:
            case EVT_OP_CASE_OR_EQ:
            case EVT_OP_CASE_AND_EQ:
            case EVT_OP_END_CASE_GROUP:
            case EVT_OP_CASE_RANGE:
                if (switchDepth == 1) {
                    return opcode;
                }
                break;
        }
    } while (TRUE);
}

Bytecode* evt_goto_end_loop(Evt* script) {
    s32 loopDepth = 0;
    Bytecode* pos = script->ptrNextLine;
    s32 opcode;
    s32 nargs;

    do {
        opcode = *pos++;
        nargs = *pos++;
        pos += nargs;

        switch (opcode) {
            case EVT_OP_END:
                PANIC();
                break;
            case EVT_OP_END_LOOP:
                loopDepth--;
                if (loopDepth < 0) {
                    return pos;
                }
                break;
            case EVT_OP_LOOP:
                loopDepth++;
                break;
        }
    } while (TRUE);
}
