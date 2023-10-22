#include "common.h"
#include "camera.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "camera.h"

void render_models(void);
void execute_render_tasks(void);
void render_item_entities(void);

SHIFT_BSS f32 D_8009A5EC;
SHIFT_BSS s16 gCurrentCamID;
SHIFT_BSS u16* nuGfxCfb_ptr;
SHIFT_BSS Gfx* gMainGfxPos;
SHIFT_BSS DisplayContext* gDisplayContext;
SHIFT_BSS Camera gCameras[4];

void update_cameras(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        Camera* cam = &gCameras[i];
        s32 sx;
        s32 sy;
        s32 sz;

        if (cam->flags == 0 || cam->flags & CAMERA_FLAG_DISABLED) {
            continue;
        }

        gCurrentCamID = i;

        switch (cam->updateMode) {
            case CAM_UPDATE_FROM_ZONE:
                update_camera_zone_interp(cam);
                break;
            case CAM_UPDATE_MODE_INIT:
                update_camera_mode_0(cam);
                break;
            case CAM_UPDATE_UNUSED_1:
                update_camera_mode_1(cam);
                break;
            case CAM_UPDATE_MODE_2:
                update_camera_mode_2(cam);
                break;
            case CAM_UPDATE_UNUSED_4:
                update_camera_mode_4(cam);
                break;
            case CAM_UPDATE_UNUSED_5:
                update_camera_mode_5(cam);
                break;
            case CAM_UPDATE_MODE_6:
            default:
                update_camera_mode_6(cam);
                break;
        }

        guLookAtReflectF(cam->viewMtxPlayer, &gDisplayContext->lookAt, cam->lookAt_eye.x, cam->lookAt_eye.y, cam->lookAt_eye.z, cam->lookAt_obj.x, cam->lookAt_obj.y, cam->lookAt_obj.z, 0, 1.0f, 0);

        if (!(cam->flags & CAMERA_FLAG_ORTHO)) {
            if (cam->flags & CAMERA_FLAG_LEAD_PLAYER) {
                create_camera_leadplayer_matrix(cam);
            }

            guPerspectiveF(cam->perspectiveMatrix, &cam->perspNorm, cam->vfov, (f32) cam->viewportW / (f32) cam->viewportH, (f32) cam->nearClip, (f32) cam->farClip, 1.0f);

            if (cam->flags & CAMERA_FLAG_SHAKING) {
                guMtxCatF(cam->viewMtxShaking, cam->perspectiveMatrix, cam->perspectiveMatrix);
            }

            if (cam->flags & CAMERA_FLAG_LEAD_PLAYER) {
                guMtxCatF(cam->viewMtxLeading, cam->perspectiveMatrix, cam->perspectiveMatrix);
            }

            guMtxCatF(cam->viewMtxPlayer, cam->perspectiveMatrix, cam->perspectiveMatrix);
        } else {
            f32 w = cam->viewportW;
            f32 h = cam->viewportH;

            guOrthoF(cam->perspectiveMatrix, -w * 0.5, w * 0.5, -h * 0.5, h * 0.5, -1000.0f, 1000.0f, 1.0f);
        }

        get_screen_coords(CAM_DEFAULT, cam->targetPos.x, cam->targetPos.y, cam->targetPos.z, &sx, &sy, &sz);
        cam->targetScreenCoords.x = sx;
        cam->targetScreenCoords.y = sy;
        cam->targetScreenCoords.z = sz;
    }

    gCurrentCamID = CAM_DEFAULT;
}

void render_frame(s32 isSecondPass) {
    s32 camID;

    if (!isSecondPass) {
        gCurrentCamID = CAM_DEFAULT;
        mdl_update_transform_matrices();
    }

    if (isSecondPass) {
        camID = CAM_3;
    } else {
        camID = CAM_DEFAULT;
    }

    // first pass:  loop uses camIDs from CAM_DEFAULT to CAM_3 - 1
    // second pass: loop only uses CAM_3
    isSecondPass = 1 - isSecondPass;

    for (; camID < ARRAY_COUNT(gCameras) - isSecondPass; camID++) {
        Camera* camera = &gCameras[camID];
        u16 matrixListPos;

        if (camera->flags == 0 || (camera->flags & (CAMERA_FLAG_NO_DRAW | CAMERA_FLAG_DISABLED))) {
            continue;
        }

        gCurrentCamID = camID;

        if (camera->fpDoPreRender != NULL) {
            camera->fpDoPreRender(camera);
        } else {
            s32 ulx;
            s32 uly;
            s32 lrx;
            s32 lry;

            gSPViewport(gMainGfxPos++, &camera->vp);
            gSPClearGeometryMode(gMainGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                    G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
            gSPTexture(gMainGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
            gDPPipelineMode(gMainGfxPos++, G_PM_NPRIMITIVE);

            ulx = camera->viewportStartX;
            uly = camera->viewportStartY;
            lrx = ulx + camera->viewportW;
            lry = uly + camera->viewportH;

            if (ulx < 0) {
                ulx = 0;
            }
            if (uly < 0) {
                uly = 0;
            }
            if (lrx < 1) {
                lrx = 1;
            }
            if (lry < 1) {
                lry = 1;
            }

            if (ulx > SCREEN_WIDTH - 1) {
                ulx = SCREEN_WIDTH - 1;
            }
            if (uly > SCREEN_HEIGHT - 1) {
                uly = SCREEN_HEIGHT - 1;
            }
            if (lrx > SCREEN_WIDTH) {
                lrx = SCREEN_WIDTH;
            }
            if (lry > SCREEN_HEIGHT) {
                lry = SCREEN_HEIGHT;
            }

            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
            gDPSetTextureLOD(gMainGfxPos++, G_TL_TILE);
            gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
            gDPSetTextureDetail(gMainGfxPos++, G_TD_CLAMP);
            gDPSetTexturePersp(gMainGfxPos++, G_TP_PERSP);
            gDPSetTextureFilter(gMainGfxPos++, G_TF_BILERP);
            gDPSetTextureConvert(gMainGfxPos++, G_TC_FILT);
            gDPSetCombineMode(gMainGfxPos++, G_CC_SHADE, G_CC_SHADE);
            gDPSetCombineKey(gMainGfxPos++, G_CK_NONE);
            gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
            gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPSetColorDither(gMainGfxPos++, G_CD_DISABLE);
            gSPClipRatio(gMainGfxPos++, FRUSTRATIO_2);
            gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                osVirtualToPhysical(nuGfxCfb_ptr));
            gDPPipeSync(gMainGfxPos++);

            if (!(camera->flags & CAMERA_FLAG_ORTHO)) {
                gSPPerspNormalize(gMainGfxPos++, camera->perspNorm);
            }

            guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);
            gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH | G_MTX_LOAD |
                        G_MTX_PROJECTION);
        }

        camera->unkMatrix = &gDisplayContext->matrixStack[gMatrixListPos];
        matrixListPos = gMatrixListPos++;
        guRotate(&gDisplayContext->matrixStack[matrixListPos], -camera->trueRot.x, 0.0f, 1.0f, 0.0f);
        camera->vpAlt.vp.vtrans[0] = camera->vp.vp.vtrans[0] + gGameStatusPtr->altViewportOffset.x;
        camera->vpAlt.vp.vtrans[1] = camera->vp.vp.vtrans[1] + gGameStatusPtr->altViewportOffset.y;

        if (!(camera->flags & CAMERA_FLAG_ORTHO)) {
            if (gCurrentCamID != CAM_3) {
                if (!(camera->flags & CAMERA_FLAG_RENDER_ENTITIES)) {
                    render_entities();
                }
                if (!(camera->flags & CAMERA_FLAG_RENDER_MODELS)) {
                    render_models();
                }
                render_player();
                render_npcs();
                render_workers_world();
                render_effects_world();
                execute_render_tasks();
                render_transformed_hud_elements();
            } else {
                guOrthoF(camera->perspectiveMatrix, 0.0f, SCREEN_WIDTH, -SCREEN_HEIGHT, 0.0f, -1000.0f, 1000.0f,
                            1.0f);
                guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);
                gSPMatrix(gMainGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH |
                            G_MTX_LOAD | G_MTX_PROJECTION);
                render_transformed_hud_elements();
                render_item_entities();
            }
        } else {
            render_workers_world();
            execute_render_tasks();
        }

        if (camera->fpDoPostRender != NULL) {
            camera->fpDoPostRender(camera);
        }

        gDPPipeSync(gMainGfxPos++);
        gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                            osVirtualToPhysical(nuGfxCfb_ptr));
        gDPPipeSync(gMainGfxPos++);
    }
}

void create_cameras_a(void) {
    CameraInitData camData;
    CameraInitData* camDataPtr = &camData;
    s32 i;

    D_8009A5EC = 1.0f;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i].flags = 0;
    }

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);
}

void create_cameras_b(void) {
    CameraInitData camData;
    CameraInitData* camDataPtr = &camData;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        gCameras[i].flags = 0;
    }

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAMERA_FLAG_DISABLED;
    camDataPtr->updateMode = CAM_UPDATE_MODE_INIT;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);
}

Camera* initialize_next_camera(CameraInitData* initData) {
    Camera* camera;
    s32 camID;

    for (camID = 0; camID < ARRAY_COUNT(gCameras); camID++) {
        camera = &gCameras[camID];

        if (camera->flags == 0) {
            break;
        }
    }

    ASSERT(camID < ARRAY_COUNT(gCameras));

    camera->flags = initData->flags | CAMERA_FLAG_INITIALIZED | CAMERA_FLAG_LEAD_PLAYER;
    camera->moveFlags = 0;
    camera->lookAt_eye.x = 0;
    camera->lookAt_eye.y = 0;
    camera->lookAt_eye.z = 0;
    camera->lookAt_obj.x = 0;
    camera->lookAt_obj.y = 0;
    camera->lookAt_obj.z = -100.0f;
    camera->curYaw = 0;
    camera->curBoomLength = 0;
    camera->curYOffset = 0;
    camera->trueRot.x = 0.0f;
    camera->trueRot.y = 0.0f;
    camera->trueRot.z = 0.0f;
    camera->updateMode = initData->updateMode;
    camera->needsInit = TRUE;
    camera->nearClip = initData->nearClip;
    camera->farClip = initData->farClip;
    camera->vfov = initData->vfov;
    camera->zoomPercent = 100;
    set_cam_viewport(camID, initData->viewStartX, initData->viewStartY, initData->viewWidth, initData->viewHeight);
    camera->unk_212 = -1;
    camera->unk_530 = TRUE;
    camera->bgColor[0] = 0;
    camera->bgColor[1] = 0;
    camera->bgColor[2] = 0;
    camera->unk_C0 = 0;
    camera->lookAt_obj_target.x = 0;
    camera->lookAt_obj_target.y = 0;
    camera->lookAt_obj_target.z = 0;
    camera->targetPos.x = 0;
    camera->targetPos.y = 0;
    camera->targetPos.z = 0;
    camera->unk_98 = 0;
    camera->unk_9C = 0;
    camera->fpDoPreRender = NULL;
    camera->fpDoPostRender = NULL;
    camera->leadAmount = 0.0f;
    camera->targetLeadAmount = 0.0f;
    camera->leadInterpAlpha = 0.0f;
    camera->accumulatedStickLead = 0.0f;
    camera->increasingLeadInterp = FALSE;
    camera->leadUnkX = 0.0f;
    camera->leadUnkZ = 0.0f;
    camera->unk_52C = 0;
    camera->leadControlSettings = NULL;
    camera->panActive = FALSE;
    camera->followPlayer = FALSE;
    camera->unk_C4 = 1000.0f;
    camera->unk_520 = 0.2f;
    camera->moveSpeed = 1.0f;
    return camera;
}

void set_cam_viewport(s16 id, s16 x, s16 y, s16 width, s16 height) {
    Camera* camera = &gCameras[id];

    camera->viewportW = width;
    camera->viewportH = height;
    camera->viewportStartX = x;
    camera->viewportStartY = y;

    camera->vp.vp.vscale[0] = 2.0f * camera->viewportW;
    camera->vp.vp.vscale[1] = 2.0f * camera->viewportH;
    camera->vp.vp.vscale[2] = 0x1FF;
    camera->vp.vp.vscale[3] = 0;

    camera->vp.vp.vtrans[0] = 4 * (s16) ((u16) camera->viewportStartX + (camera->viewportW / 2));
    camera->vp.vp.vtrans[1] = (s16) ((u16) camera->viewportStartY + (camera->viewportH / 2));
    camera->vp.vp.vtrans[1] = 4 * camera->vp.vp.vtrans[1];
    camera->vp.vp.vtrans[2] = 0x1FF;
    camera->vp.vp.vtrans[3] = 0;

    camera->vpAlt.vp.vscale[0] = 2.0f * camera->viewportW;
    camera->vpAlt.vp.vscale[1] = 2.0f * camera->viewportH;
    camera->vpAlt.vp.vscale[2] = 0x1FF;
    camera->vpAlt.vp.vscale[3] = 0;

    camera->vpAlt.vp.vtrans[0] = gGameStatusPtr->altViewportOffset.x + 4 * (s16) ((u16) camera->viewportStartX + (camera->viewportW / 2));
    camera->vpAlt.vp.vtrans[1] = gGameStatusPtr->altViewportOffset.y + 4 * (s16) ((u16) camera->viewportStartY + (camera->viewportH / 2));
    camera->vpAlt.vp.vtrans[2] = 0x200;
    camera->vpAlt.vp.vtrans[3] = 0;
}

void get_cam_viewport(s32 camID, u16* x, u16* y, u16* width, u16* height) {
    *width = gCameras[camID].viewportW;
    *height = gCameras[camID].viewportH;
    *x = gCameras[camID].viewportStartX;
    *y = gCameras[camID].viewportStartY;
}

void get_screen_coords(s32 camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ) {
    Camera* camera = &gCameras[camID];
    f32 tW;
    f32 tZ;
    f32 tY;
    f32 tX;

    transform_point(camera->perspectiveMatrix, x, y, z, 1.0f, &tX, &tY, &tZ, &tW);

    *screenZ = tZ + 5000.0f;
    if (*screenZ < 0) {
        *screenZ = 0;
    } else if (*screenZ > 10000) {
        *screenZ = 10000;
    }

    if (tW < 0.01 && tW > -0.01) {
        *screenX = 0;
        *screenY = 0;
        *screenZ = 0;
    } else {
        tW = 1.0f / tW;
        *screenX = (s32) ((camera->viewportW / 2) + (tX * tW * camera->viewportW * 0.5f)) + camera->viewportStartX;
        *screenY = (s32) ((camera->viewportH / 2) - (tY * tW * camera->viewportH * 0.5f)) + camera->viewportStartY;
    }
}

s32 func_8002E754(s32 camID, s32 x, s32 y) {
    s32 startX = gCameras[camID].viewportStartX;
    s32 startY = gCameras[camID].viewportStartY;
    s32 endX = startX + gCameras[camID].viewportW;
    s32 endY = startY + gCameras[camID].viewportH;

    if (x < startX) {
        return TRUE;
    } else if (x > endX) {
        return TRUE;
    } else if (y < startY) {
        return TRUE;
    } else if (y > endY) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void func_8002E7CC(s32 camID, s32* x, s32* y, s32* width, s32* height) {
    *x = gCameras[camID].viewportStartX;
    *y = gCameras[camID].viewportStartY;
    *width = gCameras[camID].viewportStartX + gCameras[camID].viewportW;
    *height = gCameras[camID].viewportStartY + gCameras[camID].viewportH;
}

void func_8002E82C(s32 camID, s32 arg1) {
    Camera* camera = &gCameras[camID];

    camera->unk_212++;
    ASSERT(camera->unk_212 < 4);

    camera->unk_214[camera->unk_212].unk_0C = arg1;
    camera->unk_214[camera->unk_212].unk_02 = 1;
    camera->unk_214[camera->unk_212].unk_64 = arg1;
    camera->unk_214[camera->unk_212].unk_00 = 0;
}
