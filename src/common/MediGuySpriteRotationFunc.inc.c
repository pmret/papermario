// outputs z sprite rotation
ApiStatus N(MediGuySpriteRotationFunc)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    s32 angle = get_variable(script, *args++);
    s32 outPos = *(args++);
    s32 temp_s3 = get_variable(script, *args++);
    s32 temp_s0_5 = get_variable(script, *args++);
    f32 temp_f20 = get_float_variable(script, *args++) * (1.0f - (angle / (f32) temp_s0_5));

    set_variable(script, outPos, temp_f20 * cos_rad((angle * 6.283184f) / temp_s3));
    return ApiStatus_DONE2;
}
