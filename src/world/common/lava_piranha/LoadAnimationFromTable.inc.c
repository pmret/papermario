API_CALLABLE(N(LoadAnimationFromTable)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);

    switch (type) {
        case VINE_0:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_0_BASE);
            break;
        case VINE_1:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_1_BASE);
            break;
        case VINE_2:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_2_BASE);
            break;
        case VINE_3:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_3_BASE);
            break;
    }
    return ApiStatus_DONE2;
}
