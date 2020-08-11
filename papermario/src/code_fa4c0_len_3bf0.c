#include "common.h"

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D5B10);

s32 FadeOutMusic(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = ptrReadPos++;

    return (set_music_track(itemID, -1, 0, get_variable(script, *ptrNextPos++), 8) != 0) * 2;
}

s32 SetMusicTrack(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 musicPlayer = get_variable(script, *ptrReadPos++);
    s32 songID = get_variable(script, *ptrReadPos++);
    s32 variation = get_variable(script, *ptrReadPos++);
    s32 volume = get_variable(script, *ptrReadPos++);

    return (set_music_track(musicPlayer, songID, variation, 0x1F4, (volume << 0x10) >> 0x10) != 0) * 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, FadeInMusic);

s32 PlayAmbientSounds(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    return (play_ambient_sounds(soundID, 0xFA) != 0) * 2;
}

s32 PlaySound(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);

    play_sound(soundID);
    return 2;
}

s32 func_802D617C(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);

    _play_sound(soundID, value2 & 0xFF, 0, 0);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, PlaySoundAt);
/*
s32 PlaySoundAt(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    s32 x = get_variable(script, *ptrReadPos++);
    s32 y = get_variable(script, *ptrReadPos++);
    s32 z = get_variable(script, *ptrReadPos++);

    play_sound_at_position(soundID, value2, x, y, z);
    return 2;
}
*/

s32 StopSound(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    stop_sound(get_variable(script, *ptrReadPos++));
    return 2;
}

s32 func_802D62E4(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    func_80149A6C(get_variable(script, *ptrReadPos++), 1);
    return 2;
}

s32 UseDoorSounds(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    gCurrentDoorSoundsSet = get_variable(script, *ptrReadPos++);
    return 2;
}

s32 func_802D6340(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    D_80151308 = get_variable(script, *ptrReadPos++);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, PlaySoundAtF);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveKeyItemAt);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveItemAt);

INCLUDE_ASM(code_fa4c0_len_3bf0, AddKeyItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, HasKeyItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, FindKeyItem);

s32 AddItem(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemID = get_variable(script, *ptrReadPos++);
    s32* ptrNextPos = *ptrReadPos++;

    set_variable(script, ptrNextPos, add_item(itemID));
    return 2;
}

s32 func_802D6AF0(script_context* script, s32 initialCall) {
    set_variable(script, *script->ptrReadPos, 0);
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, FindItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, CountFortessKeys);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveFortressKeys);

INCLUDE_ASM(code_fa4c0_len_3bf0, MakeItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntity);

INCLUDE_ASM(code_fa4c0_len_3bf0, DropItemEntityB);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveItemEntity);

s32 AddBadge(script_context* script, s32 initialCall) {
  s32* ptrReadPos = script->ptrReadPos;
  s32 itemID = get_variable(script, *ptrReadPos++);
  s32* ptrNextPos = *ptrReadPos++;

  set_variable(script, ptrNextPos, add_badge(itemID));
  return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveBadge);

INCLUDE_ASM(code_fa4c0_len_3bf0, SetItemPos);
/*
s32 SetItemPos(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 itemEntityIndex, value2, value3, value4;
    s32* ptrItemEntity;

    itemEntityIndex = get_variable(script, *ptrReadPos++);
    value2 = get_variable(script, *ptrReadPos++);
    value3 = get_variable(script, *ptrReadPos++);
    value4 = get_variable(script, *ptrReadPos++);

    ptrItemEntity = get_item_entity(itemEntityIndex);
    *(ptrItemEntity + 0x08) = (f64) value2;
    *(ptrItemEntity + 0x0C) = (f64) value3;
    *(ptrItemEntity + 0x10) = (f64) value4;
    return 2;
}
*/

INCLUDE_ASM(code_fa4c0_len_3bf0, SetItemFlags);

s32 AddCoin(script_context* script, s32 initialCall) {
    script->varTable[0] = add_coins(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPoints(script_context* script, s32 initialCall) {
    script->varTable[0] = add_star_points(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 AddStarPieces(script_context* script, s32 initialCall) {
    script->varTable[0] = add_star_pieces(get_variable(script, *script->ptrReadPos));
    return 2;
}

INCLUDE_ASM(code_fa4c0_len_3bf0, GetItemPower);

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowGotItem);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D7460);

INCLUDE_ASM(code_fa4c0_len_3bf0, func_802D74C0);

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowEmote);

INCLUDE_ASM(code_fa4c0_len_3bf0, RemoveEffect);
/*
s32 RemoveEffect(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    remove_effect(get_variable(script, *ptrReadPos++));
    return 2;
}

s32 func_802D7B10(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *ptrValue = (*ptrValue | 0x10);
    return 2;
}

s32 func_802D7B44(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *((ptrValue + 0xC) + 0x14) = 10;
    return 2;
}

s32 func_802D7B74(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32 ptrValue = get_variable(script, *ptrReadPos++);
    *((ptrValue + 0xC) + 0x30) = 5;
    return 2;
}
*/

INCLUDE_ASM(code_fa4c0_len_3bf0, ShowSleepBubble);

INCLUDE_ASM(code_fa4c0_len_3bf0, PlayEffect);

