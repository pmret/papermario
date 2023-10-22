API_CALLABLE(N(start)) {
    u8 mashMeterCutoff;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[(actionCommandStatus->mashMeterIntervals - 1)];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    actionCommandStatus->state = 10;
    battleStatus->unk_82 = mashMeterCutoff;
    func_80269118();
    return ApiStatus_DONE2;
}
