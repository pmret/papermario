#ifndef _EVT_MSG_API_H_
#define _EVT_MSG_API_H_

#include "script_api/macros.h"

#define SpeakToPlayer(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToPlayer, ##ARGS),
ApiStatus evt_SpeakToPlayer(Evt* script, s32 isInitialCall);

#define EndSpeech(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_EndSpeech, ##ARGS),
ApiStatus evt_EndSpeech(Evt* script, s32 isInitialCall);

#define ContinueSpeech(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_ContinueSpeech, ##ARGS),
ApiStatus evt_ContinueSpeech(Evt* script, s32 isInitialCall);

#define SpeakToNpc(ARGS...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToNpc, ##ARGS),
ApiStatus evt_SpeakToNpc(Evt* script, s32 isInitialCall);

#endif
