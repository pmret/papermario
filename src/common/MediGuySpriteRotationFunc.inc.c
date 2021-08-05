// outputs z sprite rotation
ApiStatus N(MediGuySpriteRotationFunc)(ScriptInstance* script, s32 isInitialCall) {
    f32 temp_f20;
    s32 temp_s0_5;
    s32 angle;
    s32 temp_s3;
    s32 outPos;

    Bytecode* args = script->ptrReadPos;
    
    angle = get_variable(script, *args++);
    outPos = *(args++);
    temp_s3 = get_variable(script, *args++);
    temp_s0_5 = get_variable(script, *args++);

    temp_f20 = get_float_variable(script, *args++) * (1.0f - (angle / (f32) temp_s0_5));
    set_variable(script, outPos, temp_f20 * cos_rad((angle * 6.283184f) / temp_s3));
    return ApiStatus_DONE2;
}