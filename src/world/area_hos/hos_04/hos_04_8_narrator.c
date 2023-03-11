#include "hos_04.h"

#include "../common/Narrator.inc.c"

#if VERSION_PAL
#define DURATION_44 (35)
#define DURATION_89 (73)
#else
#define DURATION_44 (44)
#define DURATION_89 (89)
#endif

IntroMessage N(HeistMessageList)[] = {
    { INTRO_MSG_BLANK, DURATION_89 },
    { MSG_Intro_001B, DURATION_44 },
    { MSG_Intro_001C, DURATION_44 },
    { MSG_Intro_001D, DURATION_44 },
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
