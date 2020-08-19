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

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_Loop);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_end_loop);

ApiStatus si_handle_break_loop(ScriptInstance* script) {
    ASSERT(script->loopDepth >= 0);
    script->ptrNextLine = si_goto_end_loop(script);
    script->loopDepth -= 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_wait);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_wait_seconds);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_not_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_less);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_greater);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_less_equal);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_if_greater_equal);

ApiStatus si_handle_if_AND(ScriptInstance* script) {
    s32 var1;
    s32* ptrReadPos = script->ptrReadPos;

    var1 = ptrReadPos[0];
    ptrReadPos++;

    if ((get_variable(script, var1) & *ptrReadPos) == 0) {
        script->ptrNextLine = si_skip_if(script);
        return ApiStatus_DONE2;
    }
    return ApiStatus_DONE2;
}

ApiStatus si_handle_if_not_AND(ScriptInstance* script) {
    s32 var1;
    s32* ptrReadPos = script->ptrReadPos;

    var1 = ptrReadPos[0];
    ptrReadPos++;

    if ((get_variable(script, var1) & *ptrReadPos) != 0) {
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
    s32 value = *script->ptrReadPos;
    s32 switchDepth = ++script->switchDepth;

    ASSERT(switchDepth < 8);

    script->switchBlockValue[switchDepth] = value;
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

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_case_default);

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
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 curPtrReadPos = ptrReadPos[0];

    set_variable(script, curPtrReadPos, get_variable(script, ptrReadPos[1]));
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_const(ScriptInstance* script) {
    set_variable(script, *script->ptrReadPos, script->ptrReadPos[1]);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_float(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 curPtrReadPos = ptrReadPos[0];

    set_float_variable(script, curPtrReadPos, get_float_variable(script, ptrReadPos[1]));
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_add);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_subtract);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_multiply);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_divide);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_mod);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_addF);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_subtractF);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_multiplyF);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_divideF);

ApiStatus si_handle_set_int_buffer_ptr(ScriptInstance* script) {
    script->buffer = (ScriptBufferValue*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_float_buffer_ptr(ScriptInstance* script) {
    script->buffer = (ScriptBufferValue*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_get_1_word(ScriptInstance* script) {
    s32 out = *script->ptrReadPos;

    set_variable(script, out, (*script->buffer++).s);
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_2_word);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_3_word);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_4_word);

ApiStatus si_handle_get_Nth_word(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 out = ptrReadPos[0];
    s32 n = get_variable(script, ptrReadPos[1]);

    set_variable(script, out, script->buffer[n].s);
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_1_float);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_2_float);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_3_float);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_4_float);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_get_Nth_float);

ApiStatus si_handle_set_array(ScriptInstance* script) {
    script->array = (s32*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus si_handle_set_flag_array(ScriptInstance* script) {
    script->flagArray = (s32*)get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_allocate_array);

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_AND);

//INCLUDE_ASM("code_e92d0_len_5da0", si_handle_AND_const);
ApiStatus si_handle_AND_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    s32 constant = ptrReadPos[0]; // NOLINT
    s32 var = ptrReadPos[0];

    constant = ptrReadPos[1];

    set_variable(script, var, constant & get_variable(script, var));
    return ApiStatus_DONE2;
}

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_OR);

//INCLUDE_ASM("code_e92d0_len_5da0", si_handle_OR_const);
ApiStatus si_handle_OR_const(ScriptInstance* script) {
    Bytecode* ptrReadPos = script->ptrReadPos;

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

INCLUDE_ASM("code_e92d0_len_5da0", _bound_script_trigger_handler);

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

INCLUDE_ASM("code_e92d0_len_5da0", si_handle_end);

s32 INCLUDE_ASM("code_e92d0_len_5da0", get_variable, ScriptInstance* script, Bytecode var);

INCLUDE_ASM("code_e92d0_len_5da0", get_variable_index);

INCLUDE_ASM("code_e92d0_len_5da0", get_variable_index_alt);

s32 INCLUDE_ASM("code_e92d0_len_5da0", set_variable, ScriptInstance* script, Bytecode var, s32 value);

f32 INCLUDE_ASM("code_e92d0_len_5da0", get_float_variable, ScriptInstance* script, Bytecode var);

f32 INCLUDE_ASM("code_e92d0_len_5da0", set_float_variable, ScriptInstance* script, Bytecode var, f32 value);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_label);

INCLUDE_ASM("code_e92d0_len_5da0", si_skip_if);

INCLUDE_ASM("code_e92d0_len_5da0", si_skip_else);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_end_case);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_next_case);

INCLUDE_ASM("code_e92d0_len_5da0", si_goto_end_loop);

INCLUDE_API_ASM("code_e92d0_len_5da0", TranslateModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", RotateModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", ScaleModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", GetModelIndex);

ApiStatus CloneModel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;
    s32 srcModelID = get_variable(script, *thisPos++);
    s32 newModelID = get_variable(script, *thisPos++);

    clone_model(srcModelID, newModelID);
    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_e92d0_len_5da0", GetModelCenter);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetTexPanner);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetModelFlag10);

INCLUDE_API_ASM("code_e92d0_len_5da0", EnableTexPanning);

INCLUDE_API_ASM("code_e92d0_len_5da0", EnableModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", SetGroupEnabled);

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

INCLUDE_API_ASM("code_e92d0_len_5da0", GetColliderCenter);

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

INCLUDE_API_ASM("code_e92d0_len_5da0", SetRenderMode);

INCLUDE_API_ASM("code_e92d0_len_5da0", PlaySoundAtModel);

INCLUDE_API_ASM("code_e92d0_len_5da0", PlaySoundAtCollider);
