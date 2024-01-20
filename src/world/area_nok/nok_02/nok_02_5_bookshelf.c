#include "nok_02.h"

EvtScript N(EVS_Setup_Bookshelf) = {
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_CH1_00A1, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
