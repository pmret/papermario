#ifndef _EVT_MSG_API_H_
#define _EVT_MSG_API_H_

#include "script_api/macros.h"

#define SpeakToPlayer(...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToPlayer, ##__VA_ARGS__),
ApiStatus evt_SpeakToPlayer(Evt* script, s32 isInitialCall);

#define EndSpeech(...) \
    _EVT_CMD(EVT_OP_CALL, evt_EndSpeech, ##__VA_ARGS__),
ApiStatus evt_EndSpeech(Evt* script, s32 isInitialCall);

#define ContinueSpeech(...) \
    _EVT_CMD(EVT_OP_CALL, evt_ContinueSpeech, ##__VA_ARGS__),
ApiStatus evt_ContinueSpeech(Evt* script, s32 isInitialCall);

#define SpeakToNpc(...) \
    _EVT_CMD(EVT_OP_CALL, evt_SpeakToNpc, ##__VA_ARGS__),
ApiStatus evt_SpeakToNpc(Evt* script, s32 isInitialCall);

#endif
