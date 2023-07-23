#include "common.h"
#include "ld_addrs.h"

// TODO: not sure where these go
u8 D_802D9D70 = 254;
u8 D_802D9D71 = 254;
u16 StarShrineLightBeamAlpha = 255;

extern s32 gSpriteShadingHeader[2];
extern u8 gSpriteShadingData[0x100];

extern Addr sprite_shading_profiles_data_ROM_START;

s32 SetSpriteShading(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 profileID = evt_get_variable(script, *args++);
    s32 shadingGroupOffset = (profileID >> 0x10) * 8;
    s32 shadingProfileOffset = (profileID & 0xFFFF) * 4;
    s32 dataOffset;
    s32 i;
    s32 romStart;
    s32 romEnd;
    s32 count;
    s32 falloff;
    s32 data;
    SpriteShadingProfile* profile;

    if (profileID == SHADING_NONE) {
        return ApiStatus_DONE2;
    }

    // load shading group data
    romStart = (s32)sprite_shading_profiles_ROM_START;
    romEnd = romStart + 8;
    dma_copy((u8*) shadingGroupOffset + romStart, (u8*) shadingGroupOffset + romEnd, gSpriteShadingHeader);

    // load offset to shading data
    romStart = shadingProfileOffset + (s32)sprite_shading_profiles_ROM_START;
    data = gSpriteShadingHeader[0];
    dma_copy((u8*)gSpriteShadingHeader[1] + romStart, (u8*)gSpriteShadingHeader[1] + romStart + 4, gSpriteShadingHeader);

    // load shading data
    dataOffset = (s32)sprite_shading_profiles_data_ROM_START + data + gSpriteShadingHeader[0];
    dma_copy((u8*) dataOffset, (u8*) dataOffset + sizeof(gSpriteShadingData), &gSpriteShadingData);

    profile = gSpriteShadingProfile;
    count = gSpriteShadingData[0];
    profile->ambientColor.r = gSpriteShadingData[2];
    profile->ambientColor.g = gSpriteShadingData[3];
    profile->ambientColor.b = gSpriteShadingData[4];
    profile->ambientPower = gSpriteShadingData[5];

    for (i = 0; i < count; i++) {
        SpriteShadingLightSource* source = &gSpriteShadingProfile->sources[i];
        source->flags = gSpriteShadingData[6 + 16 * i + 0];
        source->rgb.r = gSpriteShadingData[6 + 16 * i + 1];
        source->rgb.g = gSpriteShadingData[6 + 16 * i + 2];
        source->rgb.b = gSpriteShadingData[6 + 16 * i + 3];
        source->pos.x = (s16) ((gSpriteShadingData[6 + 16 * i + 4] << 8) + gSpriteShadingData[6 + 16 * i + 5]);
        source->pos.y = (s16) ((gSpriteShadingData[6 + 16 * i + 6] << 8) + gSpriteShadingData[6 + 16 * i + 7]);
        source->pos.z = (s16) ((gSpriteShadingData[6 + 16 * i + 8] << 8) + gSpriteShadingData[6 + 16 * i + 9]);
        falloff = gSpriteShadingData[6 + 16 * i + 13]
            + (gSpriteShadingData[6 + 16 * i + 12] << 8)
            + (gSpriteShadingData[6 + 16 * i + 11] << 16)
            + (gSpriteShadingData[6 + 16 * i + 10] << 24);
        source->falloff = *(f32*)&falloff;
        source->unk_14 = gSpriteShadingData[6 + 16 * i + 14];
    }
    gSpriteShadingProfile->flags |= 1;
    return ApiStatus_DONE2;
}

ApiStatus EnableSpriteShading(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        gSpriteShadingProfile->flags |= 1;
    } else {
        gSpriteShadingProfile->flags &= ~1;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetDemoState(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->demoState);
    return ApiStatus_DONE2;
}

ApiStatus DemoPressButton(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput |= evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoReleaseButton(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput &= ~evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoSetButtons(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->demoButtonInput = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickRadial(Evt* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 a;
    f32 b;
    s32* thisPos = script->ptrReadPos;

    a = evt_get_float_variable(script, *thisPos++);
    b = evt_get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = a * sin_deg(b);
    (*gameStatus)->demoStickY = a * cos_deg(b);

    return ApiStatus_DONE2;
}

ApiStatus DemoJoystickXY(Evt* script, s32 isInitialCall) {
    GameStatus** gameStatus = &gGameStatusPtr;
    f32 x;
    f32 y;
    s32* thisPos = script->ptrReadPos;

    x = evt_get_float_variable(script, *thisPos++);
    y = evt_get_float_variable(script, *thisPos++);

    (*gameStatus)->demoStickX = x;
    (*gameStatus)->demoStickY = y;

    return ApiStatus_DONE2;
}
