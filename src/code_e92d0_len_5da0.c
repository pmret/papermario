#include "common.h"

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
    script->ptrNextLine = si_goto_label(script, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_Loop(ScriptInstance* script) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var = *thisPos++;
    s32 loopDepth = ++script->loopDepth;

    ASSERT(loopDepth < 8);

    script->loopStartTable[loopDepth] = thisPos;
    script->loopCounterTable[loopDepth] = var;

    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_end_loop);

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

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_not_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_less);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_less_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_greater);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_greater_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_range);

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

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_AND);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_equal_OR);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_equal_AND);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_end_case_group);

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

    script->array = heap_malloc(size * 4);
    set_variable(script, var, script->array);
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_AND);

ApiStatus si_handle_AND_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    set_variable(script, var, constant & get_variable(script, var));
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_OR);

ApiStatus si_handle_OR_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    // todo improve
    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    set_variable(script, var, constant | get_variable(script, var));
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_call);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_exec1);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_exec2);

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

s32 INCLUDE_ASM("code_e92d0_len_5da0", _bound_script_trigger_handler, Trigger* trigger);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_bind);

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

ApiStatus INCLUDE_ASM("code_e92d0_len_5da0", si_handle_does_script_exist);

ApiStatus INCLUDE_ASM("code_e92d0_len_5da0", si_handle_bind_lock);

ApiStatus INCLUDE_ASM("code_e92d0_len_5da0", si_handle_thread);

ApiStatus si_handle_end_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_FINISH;
}

ApiStatus INCLUDE_ASM("code_e92d0_len_5da0", si_handle_child_thread);

ApiStatus si_handle_end_child_thread(ScriptInstance* script) {
    kill_script(script);
    return ApiStatus_BLOCK;
}

ApiStatus func_802C6E14(ScriptInstance* script) {
    return ApiStatus_DONE2;
}

ApiStatus INCLUDE_ASM("code_e92d0_len_5da0", si_handle_print_debug_var);

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

INCLUDE_ASM("code_e92d0_len_5da0", si_execute_next_command);

s32 INCLUDE_ASM("code_e92d0_len_5da0", get_variable, ScriptInstance* script, Bytecode var);

INCLUDE_ASM("code_e92d0_len_5da0", get_variable_index);

INCLUDE_ASM("code_e92d0_len_5da0", get_variable_index_alt);

s32 INCLUDE_ASM("code_e92d0_len_5da0", set_variable, ScriptInstance* script, Bytecode var, s32 value);

f32 INCLUDE_ASM("code_e92d0_len_5da0", get_float_variable, ScriptInstance* script, Bytecode var);

f32 INCLUDE_ASM("code_e92d0_len_5da0", set_float_variable, ScriptInstance* script, Bytecode var, f32 value);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_label);

INCLUDE_ASM("code_e92d0_len_5da0", si_skip_if);
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

INCLUDE_ASM("code_e92d0_len_5da0", si_skip_else);
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

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_end_case);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_next_case);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_end_loop);

// Ethan: I think this is the start of a new file
INCLUDE_API_ASM("code_e92d0_len_5da0", TranslateModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", RotateModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", ScaleModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", GetModelIndex);

ApiStatus CloneModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode srcModelID = get_variable(script, *thisPos++);
    Bytecode newModelID = get_variable(script, *thisPos++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_e92d0_len_5da0", GetModelCenter);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetTexPanner);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetModelFlag10);

INCLUDE_API_ASM("code_e92d0_len_5da0", EnableTexPanning);

INCLUDE_API_ASM("code_e92d0_len_5da0", EnableModel);

ApiStatus SetGroupEnabled(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    Bytecode var1 = get_variable(script, *thisPos++);
    Bytecode var2 = get_variable(script, *thisPos++);

    func_8011B7C0(var1, 2, var2);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_e92d0_len_5da0", SetTexPanOffset);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetModelFlags);

INCLUDE_ASM("code_e92d0_len_5da0", func_802C95A0);

INCLUDE_API_ASM("code_e92d0_len_5da0", TranslateGroup);

INCLUDE_API_ASM("code_e92d0_len_5da0", RotateGroup);

INCLUDE_API_ASM("code_e92d0_len_5da0", ScaleGroup);

INCLUDE_API_ASM("code_e92d0_len_5da0", EnableGroup);

INCLUDE_ASM("code_e92d0_len_5da0", modify_collider_family_flags);

INCLUDE_API_ASM("code_e92d0_len_5da0", ModifyColliderFlags);

INCLUDE_API_ASM("code_e92d0_len_5da0", ResetFromLava);

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

INCLUDE_API_ASM("code_e92d0_len_5da0", ParentColliderToModel);

ApiStatus UpdateColliderTransform(ScriptInstance* script, s32 isInitialCall) {
    update_collider_transform(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", func_802CA1B8);

INCLUDE_ASM("code_e92d0_len_5da0", goto_map);

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

INCLUDE_API_ASM("code_e92d0_len_5da0", PlaySoundAtModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", PlaySoundAtCollider);
