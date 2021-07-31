#include "common.h"
#include "nu/nusys.h"

void nuGfxSetCfb(u16** framebuf, u32 framebufnum) {
    u32 i;

    nuGfxCfb = framebuf;
    nuGfxCfbNum = framebufnum;
    nuGfxCfbCounter = 0;
    nuGfxCfb_ptr = nuGfxCfb[0];

    nuGfxRetraceWait(1);
    nuScSetFrameBufferNum(framebufnum);

    if(framebufnum > 1) {
        s32	i;

        for (i = 0; i < framebufnum - 1; i++) {
            if (nuGfxCfb[i] != nuGfxCfb[i+1]) {
                break;
            }
        }

        if (i == framebufnum - 1) {
            nuScSetFrameBufferNum(1);
        } else {
            for (i = 0; i < framebufnum; i++) {
                if (osViGetCurrentFramebuffer() != nuGfxCfb[i]) {
                    nuGfxCfbCounter = i;
                    nuGfxCfb_ptr = nuGfxCfb[i];
                    break;
                }
            }
        }
    }
}
