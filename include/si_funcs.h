#ifndef _SI_FUNCS_H_
#define _SI_FUNCS_H_

f32 fixed_var_to_float(Bytecode scriptVar);

Bytecode float_to_fixed_var(f32 value);

ApiStatus si_handle_return(Evt* script);

ApiStatus si_handle_label(Evt* script);

ApiStatus si_handle_goto(Evt* script);

ApiStatus si_handle_loop(Evt* script);

ApiStatus si_handle_end_loop(Evt* script);

ApiStatus si_handle_break_loop(Evt* script);

ApiStatus si_handle_wait(Evt* script);

ApiStatus si_handle_wait_seconds(Evt* script);

ApiStatus si_handle_if_equal(Evt* script);

ApiStatus si_handle_if_not_equal(Evt* script);

ApiStatus si_handle_if_less(Evt* script);

ApiStatus si_handle_if_greater(Evt* script);

ApiStatus si_handle_if_less_equal(Evt* script);

ApiStatus si_handle_if_greater_equal(Evt* script);

ApiStatus si_handle_if_AND(Evt* script);

ApiStatus si_handle_if_not_AND(Evt* script);

ApiStatus si_handle_else(Evt* script);

ApiStatus si_handle_end_if(Evt* script);

ApiStatus si_handle_switch(Evt* script);

ApiStatus si_handle_switch_const(Evt* script);

ApiStatus si_handle_case_equal(Evt* script);

ApiStatus si_handle_case_not_equal(Evt* script);

ApiStatus si_handle_case_less(Evt* script);

ApiStatus si_handle_case_less_equal(Evt* script);

ApiStatus si_handle_case_greater(Evt* script);

ApiStatus si_handle_case_greater_equal(Evt* script);

ApiStatus si_handle_case_range(Evt* script);

ApiStatus si_handle_case_default(Evt* script);

ApiStatus si_handle_case_AND(Evt* script);

ApiStatus si_handle_case_equal_OR(Evt* script);

ApiStatus si_handle_case_equal_AND(Evt* script);

ApiStatus si_handle_end_case_group(Evt* script);

ApiStatus si_handle_break_case(Evt* script);

ApiStatus si_handle_end_switch(Evt* script);

ApiStatus si_handle_set_var(Evt* script);

ApiStatus si_handle_set_const(Evt* script);

ApiStatus si_handle_set_float(Evt* script);

ApiStatus si_handle_add(Evt* script);

ApiStatus si_handle_subtract(Evt* script);

ApiStatus si_handle_multiply(Evt* script);

ApiStatus si_handle_divide(Evt* script);

ApiStatus si_handle_mod(Evt* script);

ApiStatus si_handle_addF(Evt* script);

ApiStatus si_handle_subtractF(Evt* script);

ApiStatus si_handle_multiplyF(Evt* script);

ApiStatus si_handle_divideF(Evt* script);

ApiStatus si_handle_set_int_buffer_ptr(Evt* script);

ApiStatus si_handle_set_float_buffer_ptr(Evt* script);

ApiStatus si_handle_get_1_word(Evt* script);

ApiStatus si_handle_get_2_word(Evt* script);

ApiStatus si_handle_get_3_word(Evt* script);

ApiStatus si_handle_get_4_word(Evt* script);

ApiStatus si_handle_get_Nth_word(Evt* script);

ApiStatus si_handle_get_1_float(Evt* script);

ApiStatus si_handle_get_2_float(Evt* script);

ApiStatus si_handle_get_3_float(Evt* script);

ApiStatus si_handle_get_4_float(Evt* script);

ApiStatus si_handle_get_Nth_float(Evt* script);

ApiStatus si_handle_set_array(Evt* script);

ApiStatus si_handle_set_flag_array(Evt* script);

ApiStatus si_handle_allocate_array(Evt* script);

ApiStatus si_handle_AND(Evt* script);

ApiStatus si_handle_AND_const(Evt* script);

ApiStatus si_handle_OR(Evt* script);

ApiStatus si_handle_OR_const(Evt* script);

ApiStatus si_handle_call(Evt* script);

ApiStatus si_handle_exec1(Evt* script);

ApiStatus si_handle_exec1_get_id(Evt* script);

ApiStatus si_handle_exec_wait(Evt* script);

ApiStatus si_handle_jump(Evt* script);

s32 _bound_script_trigger_handler(Trigger* trigger);

ApiStatus si_handle_bind(Evt* script);

ApiStatus DeleteTrigger(Evt* script, s32 isInitialCall);

ApiStatus si_handle_unbind(Evt* script);

ApiStatus si_handle_kill(Evt* script);

ApiStatus si_handle_set_priority(Evt* script);

ApiStatus si_handle_set_timescale(Evt* script);

ApiStatus si_handle_set_group(Evt* script);

ApiStatus si_handle_suspend_all(Evt* script);

ApiStatus si_handle_resume_all(Evt* script);

ApiStatus si_handle_suspend_others(Evt* script);

ApiStatus si_handle_resume_others(Evt* script);

ApiStatus si_handle_suspend(Evt* script);

ApiStatus si_handle_resume(Evt* script);

ApiStatus si_handle_does_script_exist(Evt* script);

void si_standard_trigger_executor(Trigger* trigger);

ApiStatus si_handle_bind_lock(Evt* script);

ApiStatus si_handle_thread(Evt* script);

ApiStatus si_handle_end_thread(Evt* script);

ApiStatus si_handle_child_thread(Evt* script);

ApiStatus si_handle_end_child_thread(Evt* script);

ApiStatus func_802C6E14(Evt* script);

ApiStatus si_handle_print_debug_var(Evt* script);

ApiStatus func_802C739C(Evt* script);

ApiStatus func_802C73B0(Evt* script);

s32 func_802C73B8(Evt* script);

s32 si_execute_next_command(Evt *script);

s32 get_variable(Evt* script, Bytecode var);

s32 get_variable_index(Evt* script, s32 var);

s32 get_variable_index_alt(s32 var);

s32 set_variable(Evt* script, Bytecode var, s32 value);

f32 get_float_variable(Evt* script, Bytecode var);

f32 set_float_variable(Evt* script, Bytecode var, s32 value);

Bytecode* si_find_label(Evt* script, s32 arg1);

Bytecode* si_skip_if(Evt* script);

Bytecode* si_skip_else(Evt* script);

Bytecode* si_goto_end_case(Evt* script);

Bytecode* si_goto_next_case(Evt* script);

Bytecode* si_goto_end_loop(Evt* script);

#endif
