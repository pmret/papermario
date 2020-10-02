#ifndef _SI_H_
#define _SI_H_

#include "ultra64.h"
#include "types.h"
#include "macros.h"
#include "common_structs.h"

#define SI_VAR_0 0xFE363C80

/* Return type of si_execute_next_command */
#define SI_CONTINUE 0   /* Continue to next command */
#define SI_ABORT    1   /* Quit execution */
#define SI_FINISH   255 /* Return from script */

/* Return type of script API functions */
typedef s32 ApiStatus;
#define ApiStatus_BLOCK  0   /* Call again next frame */
#define ApiStatus_DONE1  1   /* Unconditional. Probably only exists to return a bool from functions */
#define ApiStatus_DONE2  2   /* Conditional on ScriptInstance->disableScripts */
#define ApiStatus_REPEAT 3   /* Call again immediately */
#define ApiStatus_FINISH 255 /* Corresponds to SI_FINISH */

struct ScriptInstance;

typedef ApiStatus (*ApiFunc)(struct ScriptInstance* script, s32 isInitialCall);

#endif
