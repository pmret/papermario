#include "hos_10.h"

#include "../common/Narrator.inc.c"

#define DURATION_INTRO_MSG (50)

IntroMessage N(D_80244BDC)[] = {
    { INTRO_MSG_BLANK, 155 },
    { MSG_Intro_JP_001E, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 5                  },
    { MSG_Intro_JP_001F, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 30                 },
    { MSG_Intro_JP_0020, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0021, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80244C1C)[] = {
    { MSG_Intro_JP_006A, 155 },
    { MSG_Intro_JP_0031, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 5                  },
    { MSG_Intro_JP_0032, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 30                 },
    { MSG_Intro_JP_0033, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0034, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80244C5C)[] = {
    { MSG_Intro_JP_006A, 155 },
    { MSG_Intro_JP_0044, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 5                  },
    { MSG_Intro_JP_0045, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 30                 },
    { MSG_Intro_JP_0046, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0047, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80244C9C)[] = {
    { MSG_Intro_JP_006A, 155 },
    { MSG_Intro_JP_0057, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 5                  },
    { MSG_Intro_JP_0058, DURATION_INTRO_MSG },
    { MSG_Intro_JP_006A, 30                 },
    { MSG_Intro_JP_0059, DURATION_INTRO_MSG },
    { MSG_Intro_JP_005A, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage* N(IntroMessages)[] = {
    N(D_80244BDC),
    N(D_80244C1C),
    N(D_80244C5C),
    N(D_80244C9C)
};

void N(func_80240DEC)(void) {
    N(UpdateIntroMessages)(N(IntroMessages));
}

EvtScript N(EVS_SetupNarrator) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_10_ENTRY_3)
            Call(N(SetCurtainCallback), Ref(N(func_80240DEC)))
    EndSwitch
    Return
    End
};
