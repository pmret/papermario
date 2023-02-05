#include "hos_05.h"

#include "../common/Narrator.inc.c"

IntroMessage N(HeistMessageList)[] = {
    { INTRO_MSG_BLANK, 30 },
    { MSG_Intro_0001, 50 },
    { MSG_Intro_0002, 50 },
    { INTRO_MSG_BLANK, 50 },
    { MSG_Intro_0003, 50 },
    { MSG_Intro_0004, 50 },
    { MSG_Intro_0005, 50 },
    { INTRO_MSG_BLANK, 50 },
    { MSG_Intro_0006, 50 },
    { MSG_Intro_0007, 50 },
    { MSG_Intro_0008, 50 },
    { INTRO_MSG_BLANK, 50 },
    { MSG_Intro_0009, 50 },
    { MSG_Intro_000A, 50 },
    { MSG_Intro_000B, 50 },
    { INTRO_MSG_BLANK, 50 },
    { MSG_Intro_000C, 30 },
    { MSG_Intro_000D, 30 },
    { MSG_Intro_000E, 50 },
    { MSG_Intro_000F, 30 },
    { MSG_Intro_0010, 30 },
    { MSG_Intro_0011, 30 },
    { MSG_Intro_0012, 50 },
    { MSG_Intro_0013, 30 },
    { INTRO_MSG_BLANK, 40 },
    { MSG_Intro_0014, 56 },
    { INTRO_MSG_BLANK, 50 },
    { MSG_Intro_0015, 30 },
    { INTRO_MSG_BLANK, 30 },
    { MSG_Intro_0016, 50 },
    { INTRO_MSG_BLANK, 30 },
    { MSG_Intro_0017, 50 },
    { MSG_Intro_0018, 50 },
    { INTRO_MSG_BLANK, 60 },
    { MSG_Intro_0019, 50 },
    { INTRO_MSG_BLANK, 24 },
    { MSG_Intro_001A, 30 },
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
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_05_ENTRY_3)
            EVT_CALL(N(SetCurtainCallback), EVT_PTR(N(curtain_callback_narration)))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
