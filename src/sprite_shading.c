#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

SHIFT_BSS SpriteShadingProfile* gSpriteShadingProfile;
SHIFT_BSS SpriteShadingProfile wSpriteShadingProfile;
SHIFT_BSS SpriteShadingProfile bSpriteShadingProfile;
SHIFT_BSS SpriteShadingProfile wSpriteShadingProfileAux;
SHIFT_BSS SpriteShadingProfile bSpriteShadingProfileAux;
SHIFT_BSS SpriteShadingProfile* gAuxSpriteShadingProfile;
SHIFT_BSS PAL_BIN SpriteShadingPalette[16];

void appendGfx_shading_palette(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha,
                             f32 shadowX, f32 shadowY, f32 shadowZ,
                             s32 shadowR, s32 shadowG, s32 shadowB,
                             s32 highlightR, s32 highlightG, s32 highlightB,
                             s32 ambientPower, s32 otherModeLBits);

void clear_sprite_shading_data(void) {
    s32 i;

    init_sprite_shading_data();

    for (i = 0; i < ARRAY_COUNT(gSpriteShadingProfile->sources); i++) {
        gSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
        gAuxSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
    }

    gSpriteShadingProfile->flags = 0;
    gSpriteShadingProfile->ambientColor.r = gSpriteShadingProfile->ambientColor.g = gSpriteShadingProfile->ambientColor.b = 50;
    gSpriteShadingProfile->ambientPower = 10;

    gAuxSpriteShadingProfile->flags = 0;
    gAuxSpriteShadingProfile->ambientColor.r = gAuxSpriteShadingProfile->ambientColor.g = gAuxSpriteShadingProfile->ambientColor.b = 50;
    gAuxSpriteShadingProfile->ambientPower = 20;
}

void init_sprite_shading_data(void) {
    if (!gGameStatusPtr->isBattle) {
        gSpriteShadingProfile = &wSpriteShadingProfile;
        gAuxSpriteShadingProfile = &wSpriteShadingProfileAux;
    } else {
        gSpriteShadingProfile = &bSpriteShadingProfile;
        gAuxSpriteShadingProfile = &bSpriteShadingProfileAux;
    }
}

void sprite_shading_set_light_source(u32 idx, s8 flags, f32 x, f32 y, f32 z, u8 r, u8 g, u8 b, f32 falloff, s8 arg9) {
    SpriteShadingLightSource* lightSource;

    if (idx < ARRAY_COUNT(gSpriteShadingProfile->sources)) {
        lightSource = &gSpriteShadingProfile->sources[idx];
        lightSource->flags = flags;
        lightSource->pos.x = x;
        lightSource->pos.y = y;
        lightSource->pos.z = z;
        lightSource->rgb.r = r;
        lightSource->rgb.g = g;
        lightSource->rgb.b = b;
        lightSource->falloff = falloff;
        lightSource->unk_14 = arg9;
    }
}

void create_shading_palette(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha, s32 otherModeLBits) {
    Camera* camera = &gCameras[gCurrentCameraID];
    SpriteShadingLightSource* lightSource;
    f32 shadowDirX, shadowDirY, shadowDirZ;
    f32 posX, posY, posZ;
    f32 facingDir;
    f32 Mxz, Myz, Mzz;
    f32 shadowColorR, shadowColorG, shadowColorB;
    f32 commonColorR, commonColorG, commonColorB;
    f32 backColorR, backColorG, backColorB;
    f32 frontColorR, frontColorG, frontColorB;
    f32 shadowIntensity;
    f32 lightIntensity;
    f32 intensityScale;
    f32 temp_f10;
    f32 temp_f16;
    f32 temp3;
    f32 distSq;
    f32 dx, dy, dz;
    f32 dist;
    f32 invDist;
    f32 qx, qy, qz;
    f32 wx, wy, wz;
    f32 ex, ey, ez;
    f32 Pxz, Pzz;
    s32 i;

    shadowDirX = 0.0f;
    shadowDirY = 0.0f;
    shadowDirZ = 0.0f;

    posX = mtx[3][0];
    posY = mtx[3][1];
    posZ = mtx[3][2];

    Mxz = mtx[0][2];
    Myz = mtx[1][2];
    Mzz = mtx[2][2];

    commonColorR = 0.0f;
    commonColorG = 0.0f;
    commonColorB = 0.0f;

    backColorR = 0.0f;
    backColorG = 0.0f;
    backColorB = 0.0f;

    frontColorR = 0.0f;
    frontColorG = 0.0f;
    frontColorB = 0.0f;

    shadowColorR = gSpriteShadingProfile->ambientColor.r;
    shadowColorG = gSpriteShadingProfile->ambientColor.g;
    shadowColorB = gSpriteShadingProfile->ambientColor.b;

    Pxz = camera->perspectiveMatrix[0][2];
    Pzz = camera->perspectiveMatrix[2][2];

    if ((-Mxz * Pxz + Mzz * Pzz) < 0.0f) {
        facingDir = 1.0f;
    } else {
        facingDir = -1.0f;
    }

    for (i = 0; i < ARRAY_COUNT(gSpriteShadingProfile->sources); i++) {
        lightSource = &gSpriteShadingProfile->sources[i];
        if (lightSource->flags & LIGHT_SOURCE_ENABLED) {
            dx = posX - lightSource->pos.x;
            dy = posY - lightSource->pos.y;
            dz = posZ - lightSource->pos.z;

            distSq = SQ(dx) + SQ(dy) + SQ(dz);

            if (distSq != 0.0f) {
                dist = sqrtf(distSq);
                invDist = 1.0f / dist;
            } else {
                dist = 0.0f;
                invDist = 0.0f;
            }

            // normalize dx/dy/dz
            // they now form a normal vector pointing from light source to sprite
            dx *= invDist;
            dy *= invDist;
            dz *= invDist;

            // apply falloff from light source
            if (lightSource->flags & LIGHT_SOURCE_LINEAR_FALLOFF) {
                if ((dist == 0.0f) && (lightSource->falloff == 0.0f)) {
                    intensityScale = 1.0f;
                } else {
                    intensityScale = 1.0f / (dist * lightSource->falloff);
                    dx *= intensityScale;
                    dy *= intensityScale;
                    dz *= intensityScale;
                }
            } else if (lightSource->flags & LIGHT_SOURCE_QUADRATIC_FALLOFF) {
                if ((distSq == 0.0f) && (lightSource->falloff == 0.0f)) {
                    intensityScale = 1.0f;
                } else {
                    intensityScale = 1.0f / (distSq * lightSource->falloff);
                    dx *= intensityScale;
                    dy *= intensityScale;
                    dz *= intensityScale;
                }
            } else {
                intensityScale = 1.0f;
            }

            if (intensityScale > 1.0f) {
                intensityScale = 1.0f;
            }

            shadowDirX += dx;
            shadowDirY += dy;
            shadowDirZ += dz;

            if (facingDir < 0.0f) {
                ex = Mxz;
                ey = Myz;
                ez = -Mzz;
            } else {
                ex = -Mxz;
                ey = Myz;
                ez = Mzz;
            }
            temp_f10 = ex * dx + ey * dy + ez * dz;

            if (facingDir < 0.0f) {
                wx = Mzz;
                wy = Myz;
                wz = Mxz;
            } else {
                wx = -Mzz;
                wy = Myz;
                wz = -Mxz;
            }
            temp3 = wx * dx + wy * dy + wz * dz;

            temp_f16 = temp3;
            shadowIntensity = intensityScale * fabsf(temp_f10);
            lightIntensity  = intensityScale * fabsf(temp_f16);
            if (temp_f10 > 0.0f) {
                commonColorR += lightSource->rgb.r * shadowIntensity;
                commonColorG += lightSource->rgb.g * shadowIntensity;
                commonColorB += lightSource->rgb.b * shadowIntensity;
                if (temp_f16 > 0.0f) {
                    backColorR += lightSource->rgb.r * lightIntensity;
                    backColorG += lightSource->rgb.g * lightIntensity;
                    backColorB += lightSource->rgb.b * lightIntensity;
                } else {
                    frontColorR += lightSource->rgb.r * lightIntensity;
                    frontColorG += lightSource->rgb.g * lightIntensity;
                    frontColorB += lightSource->rgb.b * lightIntensity;
                }
            } else {
                shadowColorR += lightSource->rgb.r * shadowIntensity;
                shadowColorG += lightSource->rgb.g * shadowIntensity;
                shadowColorB += lightSource->rgb.b * shadowIntensity;
                if (temp_f16 > 0.0f) {
                    backColorR += lightSource->rgb.r * lightIntensity;
                    backColorG += lightSource->rgb.g * lightIntensity;
                    backColorB += lightSource->rgb.b * lightIntensity;
                } else {
                    frontColorR += lightSource->rgb.r * lightIntensity;
                    frontColorG += lightSource->rgb.g * lightIntensity;
                    frontColorB += lightSource->rgb.b * lightIntensity;
                }
            }
        }
    }

    if (facingDir < 0.0f) {
        qx = Mzz;
        qy = Myz;
        qz = Mxz;
    } else {
        qx = -Mzz;
        qy = Myz;
        qz = -Mxz;
    }

    if (qx * shadowDirX + qy * shadowDirY + qz * shadowDirZ > 0.0f) {
        appendGfx_shading_palette(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            shadowDirX, shadowDirY, shadowDirZ,
            shadowColorR, shadowColorG, shadowColorB,
            gSpriteShadingProfile->ambientColor.r + commonColorR + backColorR,
            gSpriteShadingProfile->ambientColor.g + commonColorG + backColorG,
            gSpriteShadingProfile->ambientColor.b + commonColorB + backColorB,
            gSpriteShadingProfile->ambientPower,
            otherModeLBits
        );
    } else {
        appendGfx_shading_palette(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            shadowDirX, shadowDirY, shadowDirZ,
            shadowColorR, shadowColorG, shadowColorB,
            gSpriteShadingProfile->ambientColor.r + commonColorR + frontColorR,
            gSpriteShadingProfile->ambientColor.g + commonColorG + frontColorG,
            gSpriteShadingProfile->ambientColor.b + commonColorB + frontColorB,
            gSpriteShadingProfile->ambientPower,
            otherModeLBits
        );
    }
}

void appendGfx_shading_palette(
    Matrix4f mtx,
    s32 uls, s32 ult, s32 lrs, s32 lrt,
    s32 alpha,
    f32 shadowX, f32 shadowY, f32 shadowZ,
    s32 shadowR, s32 shadowG, s32 shadowB,
    s32 highlightR, s32 highlightG, s32 highlightB,
    s32 ambientPower, s32 renderMode)
{
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 mtx01;
    f32 mtx11;
    f32 mtx21;
    f32 offsetXComp;
    f32 offsetYComp = 0;
    f32 apMag;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f20;
    f32 facingDir;
    f32 ex, ey, ez;
    f32 offsetX, offsetY;
    f32 pm02, pm12, pm22;
    f32 t1;

    var_f12 = SQ(shadowX) + SQ(shadowY) + SQ(shadowZ);

    if (var_f12 < 1.0) {
        ambientPower *= var_f12;
    }
    if (var_f12 != 0.0f) {
        var_f12 = 1.0f / sqrtf(var_f12);
    }
    shadowX *= var_f12;
    shadowY *= var_f12;
    pm02 = var_f12; // TODO required to match
    shadowZ *= var_f12;

    if (((-mtx[0][2] * camera->perspectiveMatrix[0][2]) + (mtx[2][2] * camera->perspectiveMatrix[2][2])) < 0.0f) {
        facingDir = 1.0f;
    } else {
        facingDir = -1.0f;
    }

    if (facingDir < 0.0f) {
        ex = mtx[0][2];
        ey = mtx[1][2];
        ez = -mtx[2][2];
    } else {
        ex = -mtx[0][2];
        ey = mtx[1][2];
        ez = mtx[2][2];
    }

    pm02 = camera->perspectiveMatrix[0][2];
    pm12 = camera->perspectiveMatrix[1][2];
    pm22 = camera->perspectiveMatrix[2][2];

    t1 = (ex * shadowX) + (ey * shadowY) + (ez * shadowZ);
    apMag = (shadowX * -pm22) + (shadowZ * pm02);

    if (t1 > 0.0f) {
        offsetXComp = ambientPower * apMag;
    } else if (ambientPower > 1.0f)  {
        offsetXComp = ambientPower * apMag;
    } else {
        // TODO grossness required to match
        // a temp s16 for ambientPower works as well as the explicit casting in both places
        offsetX = -1.0f;
        offsetY = (s16) ambientPower > offsetX;
        if ((s16) ambientPower > offsetX) {
            offsetXComp = ambientPower * apMag;
        } else {
            offsetXComp = ambientPower * apMag;
        }
  }

    var_f20 = SQ(shadowX) + SQ(shadowZ);
    if (var_f20 != 0.0f) {
        var_f20 = sqrtf(var_f20);
    }
    mtx01 = -mtx[0][1];
    mtx11 = mtx[1][1];
    mtx21 = mtx[2][1];
    var_f12_2 = SQ(mtx01) + SQ(mtx21);
    if (var_f12_2 != 0.0f) {
        var_f12_2 = sqrtf(var_f12_2);
    }
    offsetYComp = -((var_f20 * var_f12_2) + (shadowY * mtx11)) * ambientPower;

    if (shadowR > 255) {
        shadowR = 255;
    }
    if (shadowG > 255) {
        shadowG = 255;
    }
    if (shadowB > 255) {
        shadowB = 255;
    }
    if (highlightR > 255) {
        highlightR = 255;
    }
    if (highlightG > 255) {
        highlightG = 255;
    }
    if (highlightB > 255) {
        highlightB = 255;
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_53, PM_CC_54);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SpriteShadingPalette);
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, 16, 1);

    gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, 4, 18,
                    G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                    G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE);

    gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    gDPSetPrimColor(gMainGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
    gDPSetEnvColor(gMainGfxPos++, highlightR, highlightG, highlightB, 0);
    gDPSetCombineMode(gMainGfxPos++, PM_CC_55, PM_CC_55);
    gSPTextureRectangle(gMainGfxPos++, 0, 0, 16 << 2, 1 << 2, 2, 0, 0, 4 << 10, 1 << 10);
    gDPPipeSync(gMainGfxPos++);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));

    gDPSetScissor(
        gMainGfxPos++, 0,
        camera->viewportStartX,
        camera->viewportStartY,
        camera->viewportStartX + camera->viewportW,
        camera->viewportStartY + camera->viewportH
    );

    gDPLoadTLUT_pal16(gMainGfxPos++, 1, SpriteShadingPalette);

    gSPSetOtherMode(gMainGfxPos++, G_SETOTHERMODE_H, 4, 18,
                    G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE |
                    G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE);

    gDPSetRenderMode(gMainGfxPos++, G_RM_PASS, renderMode);
    gDPSetEnvColor(gMainGfxPos++, 100, 100, 100, 255);

    if (alpha == 255) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_50, PM_CC_52);
    } else {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_51, PM_CC_52);
    }

    offsetX = offsetXComp * facingDir;
    offsetY = offsetYComp;
    gDPSetTileSize(
        gMainGfxPos++,
        0,
        ((uls + 0x100) << 2) + (s32)offsetX,
        ((ult + 0x100) << 2) + (s32)offsetY,
        ((lrs + 0x100 - 1) << 2) + (s32)offsetX,
        ((lrt + 0x100 - 1) << 2) + (s32)offsetY
    );
}

void func_801491E4(Matrix4f mtx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 alpha) {
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, alpha);

    if (alpha == 255) {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_WINDOW_5, G_CC_PASS2);
    } else {
        gDPSetCombineMode(gMainGfxPos++, PM_CC_02, G_CC_PASS2);
    }
}
