#include "end_01.h"
#include "include_asset.h"
#include "include_asset.h"

#include "../common/Credits.inc.c"

#if VERSION_PAL
#include "credits_jobs_pal.inc.c"
#include "credits_names_pal.inc.c"
#elif VERSION_JP
#include "credits_jobs_jp.inc.c"
#include "credits_names_jp.inc.c"
#else
#include "credits_jobs.inc.c"
#include "credits_names.inc.c"
#endif

EvtScript N(EVS_InitCredits) = {
    Call(N(InitCredits))
    Return
    End
};

EvtScript N(EVS_ShowCredits_Jobs) = {
    Call(N(ShowCreditList), Ref(N(Credits_Jobs)))
    Return
    End
};

EvtScript N(EVS_ShowCredits_Names) = {
    Call(N(ShowCreditList), Ref(N(Credits_Names)))
    Return
    End
};
