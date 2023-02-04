#include "nok_02.h"

EvtScript N(D_80246E20_9DDE40) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH1_00A1, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
