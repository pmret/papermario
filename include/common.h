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

#define charset_peach_letter_png_width 0x81
#define charset_peach_letter_png_height 0x82

#define charset_letter_content_1_png_width 0x83
#define charset_letter_content_1_png_height 0x84

#define charset_postcard_png_width 0x85
#define charset_postcard_png_height 0x86

#ifdef PERMUTER
extern int TEXEL0, TEXEL1, PRIMITIVE, PRIMITIVE_ALPHA;
#endif

#endif
