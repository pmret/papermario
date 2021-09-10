ApiStatus N(MashActionCommandInit)(Evt* script, s32 isInitialCall) {
    u8 mashMeterCutoff;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (!battleStatus->unk_83) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;
    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[(actionCommandStatus->mashMeterIntervals - 1)];
    battleStatus->flags1 &= ~0x8000;
    actionCommandStatus->state = 10;
    battleStatus->unk_82 = mashMeterCutoff;
    func_80269118();
    return ApiStatus_DONE2;
}
