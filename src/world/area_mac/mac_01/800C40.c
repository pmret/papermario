#include "mac_01.h"

extern s32 D_80248420_808CA0;

void func_802403C0_800C40(void) {
    Camera* camera = &gCameras[gCurrentCameraID];
    Matrix4f sp50;
    LookAt sp90;

    D_80248420_808CA0 += 1;
    guLookAtHiliteF(sp50, &sp90, &gDisplayContext->hilite,
                    camera->lookAt_eye.x, camera->lookAt_eye.y, camera->lookAt_eye.z,
                    camera->lookAt_obj.x, camera->lookAt_obj.y, camera->lookAt_obj.z,
                    0.0f, 1.0f, 0.0f,
                    -50.0f, 63.0f, 95.0f,
                    31.0f, 63.0f, 95.0f,
                    64, 64);
    gSPLookAtX(gMasterGfxPos++, &gDisplayContext->lookAt.l[0]);
    gSPLookAtY(gMasterGfxPos++, &gDisplayContext->lookAt.l[1]);
    gDPSetHilite1Tile(gMasterGfxPos++, G_TX_RENDERTILE, &gDisplayContext->hilite, 64, 64);
    gDPSetHilite2Tile(gMasterGfxPos++, G_TX_MIRROR, &gDisplayContext->hilite, 64, 64);
    gSPTexture(gMasterGfxPos++, 0x1000, 0x1000, 0, G_TX_RENDERTILE, G_ON);
    gSPSetGeometryMode(gMasterGfxPos++, G_TEXTURE_GEN);
}

void func_802405E8_800E68(void) {
    gSPClearGeometryMode(gMasterGfxPos++, G_TEXTURE_GEN);
    gSPEndDisplayList(gMasterGfxPos++);
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/800C40", func_80240628_800EA8);
