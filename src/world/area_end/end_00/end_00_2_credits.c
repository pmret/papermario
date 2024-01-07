#include "end_00.h"
#include "include_asset.h"
#include "include_asset.h"

#include "../common/Credits.inc.c"

#if VERSION_PAL
#include "credits_title_pal.inc.c"
#include "credits_jobs_pal.inc.c"
#include "credits_names_pal.inc.c"
#else
#include "credits_title.inc.c"
#include "credits_jobs.inc.c"
#include "credits_names.inc.c"
#endif

EvtScript N(EVS_InitCredits) = {
    EVT_CALL(N(InitCredits))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowCredits_Jobs) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(Credits_Jobs)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowCredits_Names) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(Credits_Names)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowCredits_Title) = {
    EVT_CALL(N(ShowCreditList), EVT_PTR(N(Credits_Title)))
    EVT_RETURN
    EVT_END
};
