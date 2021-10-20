#include "common.h"
#include "camera.h"
#include "nu/nusys.h"
#include "hud_element.h"

// D_8009A5EC bss here

Camera* initialize_next_camera(CameraInitData* data);

void update_cameras(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCameras); i++) {
        Camera* cam = &gCameras[i];

        if (cam->flags != 0 && !(cam->flags & CAM_FLAG_ENABLED)) {
            s32 sx;
            s32 sy;
            s32 sz;

            gCurrentCamID = i;

            switch (cam->updateMode) {
                case 3:
                    update_camera_zone_interp(cam);
                    break;
                case 0:
                    update_camera_mode_0(cam);
                    break;
                case 1:
                    update_camera_mode_1(cam);
                    break;
                case 2:
                    update_camera_mode_2(cam);
                    break;
                case 4:
                    update_camera_mode_4(cam);
                    break;
                case 5:
                    update_camera_mode_5(cam);
                    break;
                case 6:
                default:
                    update_camera_mode_6(cam);
                    break;
            }

            guLookAtReflectF(cam->viewMtxPlayer, &gDisplayContext->lookAt[0], cam->lookAt_eye.x, cam->lookAt_eye.y, cam->lookAt_eye.z, cam->lookAt_obj.x, cam->lookAt_obj.y, cam->lookAt_obj.z, 0, 1.0f, 0);

            if (!(cam->flags & CAM_FLAG_ORTHO)) {
                if (cam->flags & CAM_FLAG_LEAD_PLAYER) {
                    create_camera_leadplayer_matrix(cam);
                }

                guPerspectiveF(cam->perspectiveMatrix, &cam->perspNorm, cam->vfov, (f32) cam->viewportW / (f32) cam->viewportH, (f32) cam->nearClip, (f32) cam->farClip, 1.0f);

                if (cam->flags & CAM_FLAG_SHAKING) {
                    guMtxCatF(cam->viewMtxShaking, cam->perspectiveMatrix, cam->perspectiveMatrix);
                }

                if (cam->flags & CAM_FLAG_LEAD_PLAYER) {
                    guMtxCatF(cam->viewMtxLeading, cam->perspectiveMatrix, cam->perspectiveMatrix);
                }

                guMtxCatF(cam->viewMtxPlayer, cam->perspectiveMatrix, cam->perspectiveMatrix);
            } else {
                f32 w = cam->viewportW;
                f32 h = cam->viewportH;

                guOrthoF(cam->perspectiveMatrix, -w * 0.5, w * 0.5, -h * 0.5, h * 0.5, -1000.0f, 1000.0f, 1.0f);
            }

            get_screen_coords(0, cam->targetPos.x, cam->targetPos.y, cam->targetPos.z, &sx, &sy, &sz);
            cam->targetScreenCoords.x = sx;
            cam->targetScreenCoords.y = sy;
            cam->targetScreenCoords.z = sz;
        }
    }

    gCurrentCamID = 0;
}

void render_frame(s32 flag) {
    s32 camID;

    if (!flag) {
        gCurrentCamID = 0;
        func_80116698();
    }

    if (flag) {
        camID = CAM_CAM3;
    } else {
        camID = CAM_DEFAULT;
    }

    flag = 1 - flag; // toggle flag 0/1

    for (; camID < ARRAY_COUNT(gCameras) - flag; camID++) {
        Camera* camera = &gCameras[camID];

        if (camera->flags != 0 && !(camera->flags & (CAM_FLAG_80 | CAM_FLAG_ENABLED))) {
            u16 matrixListPos;

            gCurrentCamID = camID;

            if (camera->fpDoPreRender != NULL) {
                camera->fpDoPreRender(camera);
            } else {
                s32 ulx;
                s32 uly;
                s32 lrx;
                s32 lry;

                gSPViewport(gMasterGfxPos++, &camera->vp);
                gSPClearGeometryMode(gMasterGfxPos++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                     G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
                gSPTexture(gMasterGfxPos++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
                gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
                gDPPipelineMode(gMasterGfxPos++, G_PM_NPRIMITIVE);

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

                gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
                gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
                gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
                gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
                gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
                gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
                gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
                gDPSetCombineMode(gMasterGfxPos++, G_CC_SHADE, G_CC_SHADE);
                gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
                gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
                gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
                gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
                gSPClipRatio(gMasterGfxPos++, FRUSTRATIO_2);
                gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                 osVirtualToPhysical(nuGfxCfb_ptr));
                gDPPipeSync(gMasterGfxPos++);

                if (!(camera->flags & CAM_FLAG_ORTHO)) {
                    gSPPerspNormalize(gMasterGfxPos++, camera->perspNorm);
                }

                guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);
                gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH | G_MTX_LOAD |
                          G_MTX_PROJECTION);
            }

            camera->unkMatrix = &gDisplayContext->matrixStack[gMatrixListPos];
            matrixListPos = gMatrixListPos++;
            guRotate(&gDisplayContext->matrixStack[matrixListPos], -camera->trueRotation.x, 0.0f, 1.0f, 0.0f);
            camera->vpAlt.vp.vtrans[0] = camera->vp.vp.vtrans[0] + gGameStatusPtr->unk_82;
            camera->vpAlt.vp.vtrans[1] = camera->vp.vp.vtrans[1] + gGameStatusPtr->unk_83;

            if (!(camera->flags & CAM_FLAG_ORTHO)) {
                if (gCurrentCamID != CAM_CAM3) {
                    if (!(camera->flags & CAM_FLAG_200)) {
                        render_entities();
                    }
                    if (!(camera->flags & CAM_FLAG_400)) {
                        render_models();
                    }
                    render_player();
                    render_npcs();
                    render_generic_entities_world();
                    render_effects_world();
                    execute_render_tasks();
                    render_hud_elements_world();
                } else {
                    guOrthoF(camera->perspectiveMatrix, 0.0f, SCREEN_WIDTH, -SCREEN_HEIGHT, 0.0f, -1000.0f, 1000.0f,
                             1.0f);
                    guMtxF2L(camera->perspectiveMatrix, &gDisplayContext->camPerspMatrix[gCurrentCamID]);
                    gSPMatrix(gMasterGfxPos++, &gDisplayContext->camPerspMatrix[gCurrentCamID], G_MTX_NOPUSH |
                              G_MTX_LOAD | G_MTX_PROJECTION);
                    render_hud_elements_world();
                    render_item_entities();
                }
            } else {
                render_generic_entities_world();
                execute_render_tasks();
            }

            if (camera->fpDoPostRender != NULL) {
                camera->fpDoPostRender(camera);
            }

            gDPPipeSync(gMasterGfxPos++);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             osVirtualToPhysical(nuGfxCfb_ptr));
            gDPPipeSync(gMasterGfxPos++);
        }
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

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
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

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 160;
    camDataPtr->viewStartY = 0;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
    camDataPtr->viewWidth = 160;
    camDataPtr->viewHeight = 120;
    camDataPtr->viewStartX = 0;
    camDataPtr->viewStartY = 120;
    camDataPtr->nearClip = 8;
    camDataPtr->farClip = 16384;
    camDataPtr->vfov = 50;
    initialize_next_camera(camDataPtr);

    camDataPtr->flags = CAM_FLAG_ENABLED;
    camDataPtr->type = 0;
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

    camera->flags = initData->flags | (CAM_FLAG_1 | CAM_FLAG_LEAD_PLAYER);
    camera->moveFlags = 0;
    camera->lookAt_eye.x = 0;
    camera->lookAt_eye.y = 0;
    camera->lookAt_eye.z = 0;
    camera->lookAt_obj.x = 0;
    camera->lookAt_obj.y = 0;
    camera->lookAt_obj.z = -100.0f;
    camera->currentYaw = 0;
    camera->currentBoomLength = 0;
    camera->currentYOffset = 0;
    camera->trueRotation.x = 0.0f;
    camera->trueRotation.y = 0.0f;
    camera->trueRotation.z = 0.0f;
    camera->updateMode = initData->type;
    camera->unk_06 = 1;
    camera->nearClip = initData->nearClip;
    camera->farClip = initData->farClip;
    camera->vfov = initData->vfov;
    camera->zoomPercent = 100;
    set_cam_viewport(camID, initData->viewStartX, initData->viewStartY, initData->viewWidth, initData->viewHeight);
    camera->unk_212 = -1;
    camera->unk_530 = 1;
    camera->bgColor[0] = 0;
    camera->bgColor[1] = 0;
    camera->bgColor[2] = 0;
    camera->unk_C0 = 0;
    camera->unk_54 = 0;
    camera->unk_58 = 0;
    camera->unk_5C = 0;
    camera->targetPos.x = 0;
    camera->targetPos.y = 0;
    camera->targetPos.z = 0;
    camera->unk_98 = 0;
    camera->unk_9C = 0;
    camera->fpDoPreRender = NULL;
    camera->fpDoPostRender = NULL;
    camera->leadAmount = 0;
    camera->unk_510 = 0.0f;
    camera->unk_514 = 0.0f;
    camera->unk_518 = 0.0f;
    camera->unk_51C = 0;
    camera->unk_524 = 0.0f;
    camera->unk_528 = 0.0f;
    camera->unk_52C = 0;
    camera->aabbForZoneBelow = 0;
    camera->unk_506 = 0;
    camera->followPlayer = 0;
    camera->unk_C4 = 1000.0f;
    camera->unk_520 = 0.2f;
    camera->moveSpeed = 1.0f;
    return camera;
}

// Ordering shtuff
#ifdef NON_MATCHING
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

    camera->vp.vp.vtrans[0] = (((camera->viewportStartX + (camera->viewportW / 2)) << 16) >> 14);
    camera->vp.vp.vtrans[1] = (((camera->viewportStartY + (camera->viewportH / 2)) << 16) >> 14);
    camera->vp.vp.vtrans[2] = 0x1FF;
    camera->vp.vp.vtrans[3] = 0;

    camera->vpAlt.vp.vscale[0] = 2.0f * camera->viewportW;
    camera->vpAlt.vp.vscale[1] = 2.0f * camera->viewportH;
    camera->vpAlt.vp.vscale[2] = 0x1FF;
    camera->vpAlt.vp.vscale[3] = 0;

    camera->vpAlt.vp.vtrans[0] = gGameStatusPtr->unk_82 + ((((u16) camera->viewportStartX + (camera->viewportW / 2)) << 16) >> 14);
    camera->vpAlt.vp.vtrans[1] = gGameStatusPtr->unk_83 + ((((u16) camera->viewportStartY + (camera->viewportH / 2)) << 16) >> 14);
    camera->vpAlt.vp.vtrans[2] = 0x200;
    camera->vpAlt.vp.vtrans[3] = 0;
}
#else
INCLUDE_ASM(void, "8800", set_cam_viewport, s16 id, s16 x, s16 y, s16 width, s16 height);
#endif

void get_cam_viewport(s32 camID, u16* x, u16* y, u16* width, u16* height) {
    *width = gCameras[camID].viewportW;
    *height = gCameras[camID].viewportH;
    *x = gCameras[camID].viewportStartX;
    *y = gCameras[camID].viewportStartY;
}

void get_screen_coords(s32 camID, f32 x, f32 y, f32 z, s32* screenX, s32* screenY, s32* screenZ) {
    Camera* camera = &gCameras[camID];
    f32 tS;
    f32 tZ;
    f32 tY;
    f32 tX;

    transform_point(camera->perspectiveMatrix, x, y, z, 1.0f, &tX, &tY, &tZ, &tS);

    *screenZ = tZ + 5000.0f;
    if (*screenZ < 0) {
        *screenZ = 0;
    } else if (*screenZ > 10000) {
        *screenZ = 10000;
    }

    if (tS < 0.01 && tS > -0.01) {
        *screenX = 0;
        *screenY = 0;
        *screenZ = 0;
    } else {
        tS = 1.0f / tS;
        *screenX = (s32) ((camera->viewportW / 2) + (tX * tS * camera->viewportW * 0.5f)) + camera->viewportStartX;
        *screenY = (s32) ((camera->viewportH / 2) - (tY * tS * camera->viewportH * 0.5f)) + camera->viewportStartY;
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
