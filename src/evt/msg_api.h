#ifndef _EVT_MSG_API_H_
#define _EVT_MSG_API_H_

#include "script_api/macros.h"

#define SpeakToPlayer(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToPlayer, ##ARGS),
API_CALLABLE(evt_SpeakToPlayer);

#define EndSpeech(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_EndSpeech, ##ARGS),
API_CALLABLE(evt_EndSpeech);

#define ContinueSpeech(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_ContinueSpeech, ##ARGS),
API_CALLABLE(evt_ContinueSpeech);

#define SpeakToNpc(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToNpc, ##ARGS),
API_CALLABLE(evt_SpeakToNpc);

#endif
