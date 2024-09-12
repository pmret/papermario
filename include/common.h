#ifndef _COMMON_H_
#define _COMMON_H_

#include "ultra64.h"
#include "gbi_custom.h"
#include "types.h"
#include "common_structs.h"
#include "functions.h"
#ifndef NO_EXTERN_VARIABLES
#include "variables.h"
#endif
#include "macros.h"
#include "enums.h"
#include "evt.h"
#include "messages.h"
#include "battle/battle_names.h"
#include "battle/stage_names.h"
#include "battle/actor_types.h"

#ifdef PERMUTER
extern int TEXEL0, TEXEL1, PRIMITIVE, PRIMITIVE_ALPHA;
#endif

#endif
