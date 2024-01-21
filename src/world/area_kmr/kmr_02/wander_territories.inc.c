EnemyTerritoryWander N(WanderTerritory0) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(WanderTerritory1) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(WanderTerritory2) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander N(WanderTerritory3) = {
    .centerPos = { 0, 0, 0 },
    .wanderSize = { 150, 0 },
    .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
    .wanderShape = SHAPE_CYLINDER,
    .detectPos = { 0, 0, 0 },
    .detectSize = { 0, 0 },
    .detectShape = SHAPE_CYLINDER,
    .isFlying = TRUE,
};

EnemyTerritoryWander* N(WanderTerritories)[] = {
    &N(WanderTerritory0),
    &N(WanderTerritory1),
    &N(WanderTerritory2),
    &N(WanderTerritory3),
};

API_CALLABLE(N(SetWanderTerritory)) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 territoryIndex = evt_get_variable(script, *args++);
    s32* wanderData = (s32*) N(WanderTerritories)[territoryIndex];
    Enemy* enemy = get_enemy(npcID);
    s32 i;

    for (i = 0; i < (s32) (sizeof(enemy->territory->wander) / sizeof(i)); i++) {
        s32* wander = (s32*) &enemy->territory->wander;

        wander[i] = wanderData[i];
    }
    return ApiStatus_DONE2;
}

MobileAISettings N(AISettings_SwitchedWander) = {
    .moveSpeed = 2.0f,
    .moveTime = 15,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcIdle_SwitchedWander) = {
    Call(BasicAI_Main, Ref(N(AISettings_SwitchedWander)))
    Return
    End
};
