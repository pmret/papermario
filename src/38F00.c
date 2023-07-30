#include "common.h"

ApiStatus func_8005DB00(Evt* script, s32 isInitialCall);
ApiStatus func_8005DD54(Evt* script, s32 isInitialCall);
ApiStatus func_8005DDF0(Evt* script, s32 isInitialCall);

EvtScript EVS_800936C0 = {
    EVT_CALL(func_8005DB00)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_NpcHitRecoil = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar3, LVar2)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 1)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 4)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 16)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 8)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 8)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 12)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 6)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar1, 0)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};

EvtScript D_800939A4 = {
    EVT_RETURN
    EVT_END
};

EvtScript D_800939B4 = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetSelfVar, 0, 1)
        EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(D_800939A4))
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_8 | NPC_FLAG_JUMPING, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, LVar2)
        EVT_SET(LVar0, 0)
        EVT_LOOP(30)
            EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
            EVT_CALL(func_8005DD54)
            EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_COLOR, LVar2, LVar2, LVar2, 0)
            EVT_ADD(LVar0, 30)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
        EVT_CALL(SetNpcImgFXParams, NPC_SELF, IMGFX_SET_COLOR, 255, 255, 255, 0)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, FALSE)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_CALL(func_8005DDF0)
        EVT_CALL(BindNpcAI, NPC_SELF, LVar1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ApiStatus func_8005DB00(Evt* script, s32 isInitialCall) {
    Npc* npc;
    f32 targetDir, npcYaw;
    PlayerStatus* playerStatus;
    PartnerStatus* partnerStatus;

    npc = get_npc_unsafe(script->owner1.enemy->npcID);
    playerStatus = &gPlayerStatus;
    partnerStatus = &gPartnerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->planarFlyDist = evt_get_float_variable(script, LVar0);
            npc->duration = evt_get_variable(script, LVar1);
            script->functionTemp[1] = evt_get_variable(script, LVar2);
            script->functionTemp[2] = evt_get_variable(script, LVar3) / 2;
            npc->curAnim = script->varTable[10];
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (partnerStatus->actingPartner != PARTNER_BOW) {
                if (npc->duration != 0 && npc->duration != script->functionTemp[0]) {
                    return ApiStatus_BLOCK;
                }

                if (npc->duration == 0) {
                    if (sqrtf(SQ((playerStatus->pos.x - npc->pos.x)) +
                            SQ((playerStatus->pos.y - npc->pos.y)) +
                            SQ((playerStatus->pos.z - npc->pos.z))) <= npc->planarFlyDist) {
                        targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                        if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                            script->varTable[0] = 1;
                            return ApiStatus_DONE2;
                        }
                    }
                } else {
                    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z) <= npc->planarFlyDist) {
                        targetDir = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        npcYaw = script->functionTemp[1] == -1 ? npc->yaw : script->functionTemp[1];

                        if (fabsf(get_clamped_angle_diff(npcYaw, targetDir)) < script->functionTemp[2]) {
                            script->varTable[0] = 1;
                            return ApiStatus_DONE2;
                        }
                    }
                }
            }
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_8005DD54(Evt* script, s32 isInitialCall) {
    f32 angle = clamp_angle(script->varTable[0]);

    script->varTable[0] = angle;
    if (angle >= 180.0f) {
        angle -= 180.0f;
    }
    if (angle >= 90.0f) {
        angle = 180.0f - angle;
    }
    script->varTable[2] = (s32) (((90.0f - angle) * 95.0f) / 90.0f) + 160;
    return ApiStatus_DONE2;
}

ApiStatus func_8005DDF0(Evt* script, s32 isInitialCall) {
    if (gCurrentEncounter.unk_08 != -1) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}
