#include "common.h"

INCLUDE_ASM(s32, "17D6A0", func_8024EDC0);

INCLUDE_ASM(s32, "17D6A0", func_8024EDEC);

INCLUDE_ASM(s32, "17D6A0", func_8024EE48);

INCLUDE_ASM(s32, "17D6A0", func_8024EEA8);

INCLUDE_ASM(s32, "17D6A0", btl_draw_popup_messages);

INCLUDE_ASM(s32, "17D6A0", btl_create_popup);

INCLUDE_ASM(s32, "17D6A0", func_8024EFA4);

INCLUDE_ASM(s32, "17D6A0", func_8024EFE0);

INCLUDE_ASM(s32, "17D6A0", func_8024F394);

INCLUDE_ASM(s32, "17D6A0", func_8024F5AC);

INCLUDE_ASM(s32, "17D6A0", func_8024F768);

INCLUDE_ASM(s32, "17D6A0", func_8024F7C8);

INCLUDE_ASM(s32, "17D6A0", func_8024F84C);

INCLUDE_ASM(s32, "17D6A0", func_8024F940);

INCLUDE_ASM(s32, "17D6A0", btl_show_battle_message);

INCLUDE_ASM(s32, "17D6A0", btl_show_variable_battle_message);

INCLUDE_ASM(s32, "17D6A0", btl_is_popup_displayed);

INCLUDE_ASM(s32, "17D6A0", btl_set_popup_duration);

INCLUDE_ASM(s32, "17D6A0", func_8024FAE8);

INCLUDE_ASM(s32, "17D6A0", func_8024FAFC);

INCLUDE_ASM(s32, "17D6A0", close_action_command_instruction_popup);

INCLUDE_ASM(s32, "17D6A0", func_8024FB3C);

INCLUDE_ASM(s32, "17D6A0", func_80250818);

INCLUDE_ASM(s32, "17D6A0", btl_show_message_popup);

INCLUDE_ASM(s32, "17D6A0", ShowMessageBox);

INCLUDE_ASM(s32, "17D6A0", ShowVariableMessageBox);

ApiStatus IsMessageBoxDisplayed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    set_variable(script, outVar, btl_is_popup_displayed());
    return ApiStatus_DONE2;
}

ApiStatus WaitForMessageBoxDone(ScriptInstance* script, s32 isInitialCall) {
    return !btl_is_popup_displayed() * ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "17D6A0", ForceCloseMessageBox);

INCLUDE_ASM(s32, "17D6A0", SetMessageBoxDuration);

INCLUDE_ASM(s32, "17D6A0", func_80251434);

INCLUDE_ASM(s32, "17D6A0", func_80251454);

INCLUDE_ASM(s32, "17D6A0", func_80251474);
