#ifndef _CODE_6E40_LEN_500_H_
#define _CODE_6E40_LEN_500_H_

#include "common.h"

extern f32 gCurtainScale;
extern f32 gCurtainScaleGoal;
extern f32 gCurtainFade;
extern f32 gCurtainFadeGoal;
extern UNK_FUN_PTR(gCurtainDrawCallback);

void initialize_curtains(void);
void update_curtains(void);
// render_curtains
void set_curtain_scale_goal(f32 scale);
void set_curtain_scale(f32 scale);
void set_curtain_draw_callback(UNK_FUN_PTR(callback));
void set_curtain_fade_goal(f32 fade);
void set_curtain_fade(f32 fade);

#endif
