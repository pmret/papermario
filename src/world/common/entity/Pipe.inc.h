#ifndef _ENTITY_PIPE_H_
#define _ENTITY_PIPE_H_

#include "common.h"

ApiStatus N(Pipe_GetCameraYaw)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetCurrentFloor)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetEntryPos)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_SetAnimFlag)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_GetPointAheadOfPlayer)(Evt* script, s32 isInitialCall);
ApiStatus N(Pipe_AwaitDownInput)(Evt* script, s32 isInitialCall);

extern EvtScript N(Pipe_EnterVertical);
extern EvtScript N(Pipe_EnterHorizontal);
extern EvtScript N(Pipe_ExitVertical);
extern EvtScript N(Pipe_ScriptD);
extern EvtScript N(Pipe_ExitHorizontal);

#endif
