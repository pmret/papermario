#include "hos_04.h"

#include "../common/Narrator.inc.c"

#if VERSION_PAL
#define DURATION_INTRO_MSG (35)
#define DURATION_BLANK (73)
#elif VERSION_JP
#define DURATION_INTRO_MSG (50)
#define DURATION_BLANK (95)
#else
#define DURATION_INTRO_MSG (44)
#define DURATION_BLANK (89)
#endif

#if VERSION_JP
IntroMessage N(D_80241EFC_A321EC)[] = {
    { MSG_Intro_JP_0022, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0023, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0024, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80241F1C_A3220C)[] = {
    { MSG_Intro_JP_0035, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0036, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0037, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80241F3C_A3222C)[] = {
    { MSG_Intro_JP_0048, DURATION_INTRO_MSG },
    { MSG_Intro_JP_0049, DURATION_INTRO_MSG },
    { MSG_Intro_JP_004A, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage N(D_80241F5C_A3224C)[] = {
    { MSG_Intro_JP_005B, DURATION_INTRO_MSG },
    { MSG_Intro_JP_005C, DURATION_INTRO_MSG },
    { MSG_Intro_JP_005D, DURATION_INTRO_MSG },
    {}, // end of list
};

IntroMessage* N(func_80241F7C_A3226C)[] = {
    N(D_80241EFC_A321EC),
    N(D_80241F1C_A3220C),
    N(D_80241F3C_A3222C),
    N(D_80241F5C_A3224C)
};
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

#if VERSION_JP
void N(func_80240DC8_A310B8)(void) {
    N(UpdateIntroMessages)(N(func_80241F7C_A3226C));
}
#endif

void N(curtain_callback_narration)(void) {
    N(UpdateIntroMessages)(N(IntroMessages));
}

EvtScript N(EVS_SetupNarrator) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
#if VERSION_JP
        CaseEq(hos_04_ENTRY_3)
            Call(N(SetCurtainCallback), Ref(N(func_80240DC8_A310B8)))
#endif
        CaseEq(hos_04_ENTRY_4)
            Call(N(SetCurtainCallback), Ref(N(curtain_callback_narration)))
    EndSwitch
    Return
    End
};
