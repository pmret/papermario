#include "hos_05.h"

#include "../common/Narrator.inc.c"

#if VERSION_PAL
#define DURATION_24 (14)
#define DURATION_30 (19)
#define DURATION_40 (27)
#define DURATION_50 (35)
#define DURATION_56 (40)
#define DURATION_60 (44)
#else
#define DURATION_24 (24)
#define DURATION_30 (30)
#define DURATION_40 (40)
#define DURATION_50 (50)
#define DURATION_56 (56)
#define DURATION_60 (60)
#endif

IntroMessage N(HeistMessageList)[] = {
    { INTRO_MSG_BLANK, DURATION_30 },
    { MSG_Intro_0001, DURATION_50 },
    { MSG_Intro_0002, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_50 },
    { MSG_Intro_0003, DURATION_50 },
    { MSG_Intro_0004, DURATION_50 },
    { MSG_Intro_0005, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_50 },
    { MSG_Intro_0006, DURATION_50 },
    { MSG_Intro_0007, DURATION_50 },
    { MSG_Intro_0008, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_50 },
    { MSG_Intro_0009, DURATION_50 },
    { MSG_Intro_000A, DURATION_50 },
    { MSG_Intro_000B, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_50 },
    { MSG_Intro_000C, DURATION_30 },
    { MSG_Intro_000D, DURATION_30 },
    { MSG_Intro_000E, DURATION_50 },
    { MSG_Intro_000F, DURATION_30 },
    { MSG_Intro_0010, DURATION_30 },
    { MSG_Intro_0011, DURATION_30 },
    { MSG_Intro_0012, DURATION_50 },
    { MSG_Intro_0013, DURATION_30 },
    { INTRO_MSG_BLANK, DURATION_40 },
    { MSG_Intro_0014, DURATION_56 },
    { INTRO_MSG_BLANK, DURATION_50 },
    { MSG_Intro_0015, DURATION_30 },
    { INTRO_MSG_BLANK, DURATION_30 },
    { MSG_Intro_0016, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_30 },
    { MSG_Intro_0017, DURATION_50 },
    { MSG_Intro_0018, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_60 },
    { MSG_Intro_0019, DURATION_50 },
    { INTRO_MSG_BLANK, DURATION_24 },
    { MSG_Intro_001A, DURATION_30 },
    {}, // end of list
};

IntroMessage* N(IntroMessages)[] = {
    N(HeistMessageList),
    N(HeistMessageList),
    N(HeistMessageList),
    N(HeistMessageList),
};

void N(curtain_callback_narration)(void) {
    N(draw_foreground_bowser_silhouette)();
    N(UpdateIntroMessages)(N(IntroMessages));
}

EvtScript N(EVS_SetupNarrator) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_05_ENTRY_3)
            Call(N(SetCurtainCallback), Ref(N(curtain_callback_narration)))
    EndSwitch
    Return
    End
};
