#include "hos_04.h"

#include "../common/Narrator.inc.c"

IntroMessage N(HeistMessageList)[] = {
    { INTRO_MSG_BLANK, 89 },
    { MSG_Intro_001B, 44 },
    { MSG_Intro_001C, 44 },
    { MSG_Intro_001D, 44 },
    {}, // end of list
};

IntroMessage* N(IntroMessages)[] = {
    N(HeistMessageList),
    N(HeistMessageList),
    N(HeistMessageList),
    N(HeistMessageList),
};

void N(curtain_callback_narration)(void) {
    N(UpdateIntroMessages)(N(IntroMessages));
}

EvtScript N(EVS_SetupNarrator) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_04_ENTRY_4)
            EVT_CALL(N(SetCurtainCallback), EVT_PTR(N(curtain_callback_narration)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
