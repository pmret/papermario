#ifndef _CODE_EBD0_LEN_6A0_H_
#define _CODE_EBD0_LEN_6A0_H_

#include "common.h"

void intro_logos_set_fade_alpha(s16 alpha);
void intro_logos_set_fade_color(s16 color);
s16 intro_logos_fade_in(s16 subtractAlpha);
s16 intro_logos_fade_out(s16 addAlpha);
void intro_logos_update_fade(void);

#endif
