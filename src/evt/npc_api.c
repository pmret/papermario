#include "common.h"
#include "map.h"

Npc* resolve_npc(ScriptInstance* script, NpcID npcIdOrPtr) {
    if (npcIdOrPtr == NPC_SELF) {
        return get_npc_safe(script->owner2.npcID);
    } else if (npcIdOrPtr >= -270000000) {
        return get_npc_safe(npcIdOrPtr);
    } else {
        return (Npc*) npcIdOrPtr;
    }
}

void set_npc_animation(Npc* npc, u32 arg1) {
    PlayerData* playerData = &gPlayerData;

    if (arg1 - 0x101 < 9) {
        npc->currentAnim = gPartnerAnimations[playerData->currentPartner].anims[arg1 - 0x101];
    } else if ((arg1 - 0x201) < 0x10) {
        npc->currentAnim = get_enemy(npc->npcID)->animList[arg1 - 0x201];
    } else {
        npc->currentAnim = arg1;
    }
}

/// Used in battle scripts.
INCLUDE_ASM(ApiStatus, "evt/npc_api", CreateNpc, ScriptInstance* script, s32 isInitialCall);

ApiStatus DeleteNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(get_variable(script, *args++));

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc_free(npc);
    return ApiStatus_DONE2;
}

ApiStatus GetNpcPointer(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID = get_variable(script, *args++);
    Bytecode varNPC = *args++;

    set_variable(script, varNPC, (s32)get_npc_safe(npcID));
    return ApiStatus_DONE2;
}

ApiStatus SetNpcPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID = get_variable(script, *args++);
    f32 x = get_variable(script, *args++);
    f32 y = get_variable(script, *args++);
    f32 z = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->pos.x = x;
    npc->pos.y = y;
    npc->pos.z = z;
    npc->colliderPos.x = npc->pos.x;
    npc->colliderPos.y = npc->pos.y;
    npc->colliderPos.z = npc->pos.z;
    npc->flags |= 0x10000;

    return ApiStatus_DONE2;
}

ApiStatus SetNpcRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID = get_variable(script, *args++);
    f32 rotX = get_float_variable(script, *args++);
    f32 rotY = get_float_variable(script, *args++);
    f32 rotZ = get_float_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->rotation.x = rotX;
    npc->rotation.y = rotY;
    npc->rotation.z = rotZ;
    return ApiStatus_DONE2;
}

ApiStatus func_802CDE68(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    f32 var1 = get_float_variable(script, *args++);
    Npc* npc;

    npc = resolve_npc(script, npcId);
    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->rotationVerticalPivotOffset = var1;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    f32 sizeX = get_float_variable(script, *ptrReadPos++);
    f32 sizeY = get_float_variable(script, *ptrReadPos++);
    f32 sizeZ = get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->scale.x = sizeX;
    npc->scale.y = sizeY;
    npc->scale.z = sizeZ;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcCollisionSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    s32 height = get_variable(script, *ptrReadPos++);
    s32 radius = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->collisionHeight = height;
    npc->collisionRadius = radius;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    f32 speed = get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->moveSpeed = speed;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcJumpscale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    f32 jumpScale = get_float_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    s32 animation = get_variable(script, *ptrReadPos);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_animation(npc, animation);
    return ApiStatus_DONE2;
}

ApiStatus GetNpcAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_variable(script, outVar, npc->currentAnim);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcAnimationSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    f32 animationSpeed = get_float_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->animationSpeed = animationSpeed;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/npc_api", NpcMoveTo, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/npc_api", _npc_jump_to);

ApiStatus NpcJump0(ScriptInstance* script, s32 isInitialCall) {
    return _npc_jump_to(script, isInitialCall, 0);
}

ApiStatus NpcJump1(ScriptInstance* script, s32 isInitialCall) {
    return _npc_jump_to(script, isInitialCall, 1);
}

INCLUDE_ASM(s32, "evt/npc_api", NpcFlyTo, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_variable(script, outVar, clamp_angle(npc->yaw));
    return ApiStatus_DONE2;
}

ApiStatus SetNpcYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_yaw(npc, get_variable(script, *ptrReadPos++));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "evt/npc_api", InterpNpcYaw, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/npc_api", NpcFacePlayer, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "evt/npc_api", NpcFaceNpc, ScriptInstance* script, s32 isInitialCall);

ApiStatus SetNpcFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID = get_variable(script, *args++);
    s32 flagBits = *args++;
    s32 enable = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enable) {
        npc->flags |= flagBits;
    } else {
        npc->flags &= ~flagBits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetNpcPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcID = get_variable(script, *args++);
    s32 a1 = *args++;
    s32 a2 = *args++;
    s32 a3 = *args++;
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_variable(script, a1, npc->pos.x);
    set_variable(script, a2, npc->pos.y);
    set_variable(script, a3, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus func_802CF1B4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->unk_80 = arg1;
    return ApiStatus_DONE2;
}

ApiStatus SetNpcSprite(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_npc_sprite(npc, arg1, NULL);
    return ApiStatus_DONE2;
}

ApiStatus EnableNpcShadow(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    s32 enableShadow = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enableShadow) {
        enable_npc_shadow(npc);
    } else {
        disable_npc_shadow(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus EnableNpcBlur(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    s32 enableBlur = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    if (enableBlur) {
        enable_npc_blur(npc);
    } else {
        disable_npc_blur(npc);
    }
    return ApiStatus_DONE2;
}

ApiStatus ClearPartnerMoveHistory(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    clear_partner_move_history(npc);
    return ApiStatus_DONE2;
}

ApiStatus NpcSetHomePosToCurrent(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = resolve_npc(script, get_variable(script, *script->ptrReadPos));

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->homePos.x = npc->pos.x;
    npc->homePos.y = npc->pos.y;
    npc->homePos.z = npc->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus GetPartnerPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    Bytecode posX = *ptrReadPos++;
    Bytecode posY = *ptrReadPos++;
    Bytecode posZ = *ptrReadPos++;
    Npc* npc = get_npc_unsafe(-4);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    set_variable(script, posX, npc->pos.x);
    set_variable(script, posY, npc->pos.y);
    set_variable(script, posZ, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerAI(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    if (get_variable(script, *ptrReadPos++) == 0) {
        func_800EF314();
    } else {
        func_800EF300();
    }
    return ApiStatus_DONE2;
}

ApiStatus EnablePartnerAI(ScriptInstance* script, s32 isInitialCall) {
    enable_partner_ai();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF54C(ScriptInstance* script, s32 isInitialCall) {
    func_800EF43C();
    return ApiStatus_DONE2;
}

ApiStatus func_802CF56C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 value = get_variable(script, *ptrReadPos++);

    if (value == 2) {
        func_800EF3E4();
    } else {
        func_800EF3D4(value);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(ApiStatus, "evt/npc_api", BringPartnerOut, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "evt/npc_api", PutPartnerAway, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetCurrentPartnerID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    return ApiStatus_DONE2;
}

ApiStatus PartnerCanUseAbility(ScriptInstance* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    set_variable(script, arg0, partner_can_use_ability());
    return ApiStatus_DONE2;
}

ApiStatus PartnerIsFlying(ScriptInstance* script, s32 isInitialCall) {
    Bytecode arg0 = *script->ptrReadPos;

    set_variable(script, arg0, is_current_partner_flying());
    return ApiStatus_DONE2;
}

ApiStatus func_802CFD30(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode var1 = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);
    Bytecode var3 = get_variable(script, *args++);
    Bytecode var4 = get_variable(script, *args++);
    Bytecode var5 = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003D624(npc, var1, var2, var3, var4, var5, npc->unk_A2);
    return ApiStatus_DONE2;
}

ApiStatus func_802CFE2C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode arg1 = *args;
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    npc->unk_A2 = arg1;
    return ApiStatus_DONE2;
}

ApiStatus func_802CFE80(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode var1 = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003B3D0(npc, var1);
    return ApiStatus_DONE2;
}

ApiStatus func_802CFEEC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode var1 = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);
    Bytecode var3 = get_variable(script, *args++);
    Bytecode var4 = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003B44C(npc, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus func_802CFFC0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    NpcID npcId = get_variable(script, *args++);
    Bytecode var1 = get_variable(script, *args++);
    Bytecode var2 = get_variable(script, *args++);
    Bytecode var3 = get_variable(script, *args++);
    Bytecode var4 = get_variable(script, *args++);
    Bytecode var5 = get_variable(script, *args++);
    Bytecode var6 = get_variable(script, *args++);
    Bytecode var7 = get_variable(script, *args++);
    Bytecode var8 = get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcId);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003B44C(npc, var1, var2, var3, var4);
    func_8003B464(npc, var5, var6, var7, var8);
    return ApiStatus_DONE2;
}

ApiStatus SetNpcEffect(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    s32 value1 = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    func_8003C3D8(npc, value1, value2);
    return ApiStatus_DONE2;
}

ApiStatus PlaySoundAtNpc(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    SoundID soundID = get_variable(script, *ptrReadPos++);
    s32 value2 = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    sfx_play_sound_at_position(soundID, value2, npc->pos.x, npc->pos.y, npc->pos.z);
    return ApiStatus_DONE2;
}

ApiStatus func_802D0244(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    NpcID npcID = get_variable(script, *ptrReadPos++);
    u8 renderMode = get_variable(script, *ptrReadPos++);
    Npc* npc = resolve_npc(script, npcID);

    npc->renderMode = renderMode;
    return ApiStatus_DONE2;
}
