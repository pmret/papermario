EnemyTerritoryWander N(D_80247FCC_8B803C) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(D_80248004_8B8074) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(D_8024803C_8B80AC) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(D_80248074_8B80E4) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander* N(D_802480AC_8B811C)[] = {
    &N(D_80247FCC_8B803C),
    &N(D_80248004_8B8074),
    &N(D_8024803C_8B80AC),
    &N(D_80248074_8B80E4), 
};

API_CALLABLE(N(UnkTerritoryFunc)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 territoryIndex = evt_get_variable(script, *args++);
    s32* var_s0 = (s32*) N(D_802480AC_8B811C)[territoryIndex];
    Enemy* enemy = get_enemy(npcID);
    s32 i;

    for (i = 0; i < (s32) (sizeof(enemy->territory->wander) / sizeof(i)); i++) {
        s32* wander = (s32*) &enemy->territory->wander;

        wander[i] = var_s0[i];
    }
    return ApiStatus_DONE2;
}
