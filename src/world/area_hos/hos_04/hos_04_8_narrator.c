#include "hos_04.h"

#include "../common/Narrator.inc.c"

#if VERSION_PAL
#define DURATION_INTRO_MSG (35)
#define DURATION_BLANK (73)
#else
#define DURATION_INTRO_MSG (44)
#define DURATION_BLANK (89)
#endif

IntroMessage N(HeistMessageList)[] = {
    { INTRO_MSG_BLANK, DURATION_BLANK },
    { MSG_Intro_001B, DURATION_INTRO_MSG },
    { MSG_Intro_001C, DURATION_INTRO_MSG },
    { MSG_Intro_001D, DURATION_INTRO_MSG },
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
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_04_ENTRY_4)
            Call(N(SetCurtainCallback), Ref(N(curtain_callback_narration)))
    EndSwitch
    Return
    End
};
