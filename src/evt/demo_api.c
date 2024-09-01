#include "common.h"
#include "ld_addrs.h"

// TODO: not sure where these go
u8 ReflectWallPrevAlpha = 254;
u8 ReflectFloorPrevAlpha = 254;
u16 StarShrineLightBeamAlpha = 255;

extern s32 gSpriteShadingHeader[2];
extern u8 gSpriteShadingData[0x100];

extern Addr sprite_shading_profiles_data_ROM_START;

API_CALLABLE(SetSpriteShading) {
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
    gSpriteShadingProfile->flags |= SPR_SHADING_FLAG_ENABLED;
    return ApiStatus_DONE2;
}

API_CALLABLE(EnableSpriteShading) {
    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        gSpriteShadingProfile->flags |= SPR_SHADING_FLAG_ENABLED;
    } else {
        gSpriteShadingProfile->flags &= ~SPR_SHADING_FLAG_ENABLED;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDemoState) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->demoState);
    return ApiStatus_DONE2;
}

API_CALLABLE(DemoPressButton) {
    gGameStatusPtr->demoButtonInput |= evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(DemoReleaseButton) {
    gGameStatusPtr->demoButtonInput &= ~evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(DemoSetButtons) {
    gGameStatusPtr->demoButtonInput = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(DemoJoystickRadial) {
    GameStatus** gameStatus = &gGameStatusPtr;
    Bytecode* args = script->ptrReadPos;

    f32 mag = evt_get_float_variable(script, *args++);
    f32 ang = evt_get_float_variable(script, *args++);

    (*gameStatus)->demoStickX = mag * sin_deg(ang);
    (*gameStatus)->demoStickY = mag * cos_deg(ang);

    return ApiStatus_DONE2;
}

API_CALLABLE(DemoJoystickXY) {
    GameStatus** gameStatus = &gGameStatusPtr;
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);

    (*gameStatus)->demoStickX = x;
    (*gameStatus)->demoStickY = y;

    return ApiStatus_DONE2;
}
