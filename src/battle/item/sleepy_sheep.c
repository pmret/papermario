#include "sleepy_sheep.h"
#include "ld_addrs.h"
#include "battle/item/sleepy_sheep1.png.h"
#include "battle/item/sleepy_sheep2.png.h"
#include "battle/item/sleepy_sheep3.png.h"

#include "ItemRefund.inc.c"

#ifdef NON_EQUIVALENT

extern Vec3f D_802A3F88;
extern s32* D_802A3F58;

s32 N(D_802A3E88_7214D8)[] = {
    0, 0
};

s32 N(D_802A3E88_7214E0)[] = {
    0x00000000,
    0xFFFFFFE2, 0x00000000, 0xFFFFFFCE,
    0xFFFFFFE5, 0x00000000, 0x0000001E,
    0xFFFFFFBA, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF97, 0x00000000, 0x0000001E,
    0xFFFFFF92, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF6F, 0x00000000, 0xFFFFFFFB,
    0xFFFFFF56, 0x00000000, 0xFFFFFFCE,
    0xFFFFFF42, 0x00000000, 0xFFFFFFE2,
    0xFFFFFF2E, 0x00000000, 0xFFFFFFF6
};

f32 N(D_802A3F00_721550)[] = {
    0x3F800000, 0x3F800000, 0x3F400000, 0x3F800000,
    0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x3F400000, 0x3F400000
};

s32 N(D_802A3F28_721578)[] = {
    0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260,
    0x802A32A0, 0x802A32E0, 0x802A3260, 0x802A32A0,
    0x802A32E0, 0x802A3260
};

void virtual_entity_set_pos(s32, s32, s32, s32);
void virtual_entity_set_scale(s32, f32, f32, f32);
void virtual_entity_delete_by_index(s32);

ApiStatus func_802A123C_71E88C(Evt* script, s32 isInitialCall) {
    s32 i;
    Vec3f vecf;
    s32 flag;
    Vec3f* D_802A3F88_ptr = &D_802A3F88;
    s32* D_802A3E88_7214D8_ptr1; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr2; // = &N(D_802A3E88_7214D8);
    s32* D_802A3E88_7214D8_ptr3; // = &N(D_802A3E88_7214D8);
    s32* D_802A3F58_ptr;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0: {
            s32* D_802A3F28_721578_ptr = &N(D_802A3F28_721578);
            s32 loop1, loop2, loop3;
            D_802A3F58_ptr = &D_802A3F58;

            D_802A3F88_ptr->x = -200.0f;
            D_802A3F88_ptr->z = 10.0f;

            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8) + 0;
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8) + 1;
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8) + 2;

            for (i = 0; i < 10; i++) {
                D_802A3F58_ptr[i] = virtual_entity_create(D_802A3F28_721578_ptr[i]);

                virtual_entity_set_pos(D_802A3F58_ptr[i],
                              *D_802A3E88_7214D8_ptr1 + D_802A3F88_ptr->x,
                              *D_802A3E88_7214D8_ptr2,
                              *D_802A3E88_7214D8_ptr3 + D_802A3F88_ptr->z);
                virtual_entity_set_scale(D_802A3F58_ptr[i], N(D_802A3F00_721550)[i], N(D_802A3F00_721550)[i], 1.0f);
                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;
            }
            script->functionTemp[0] = 1;
            script->functionTemp[1] = gGameStatusPtr->frameCounter % 10;
        }
        break;

        case 1:
            D_802A3F88.x += 6.0f;
            if (gGameStatusPtr->frameCounter % 3 == 0) {
                script->functionTemp[1]++;
                script->functionTemp[1] %= 10;
            }

            flag = 0;
            D_802A3F58_ptr = &D_802A3F58;
            D_802A3E88_7214D8_ptr1 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr2 = N(D_802A3E88_7214D8);
            D_802A3E88_7214D8_ptr3 = N(D_802A3E88_7214D8);
            for (i = 0; i < 10; i++) {
                f32 x, y, z;

                D_802A3E88_7214D8_ptr1 += i * 3 + 0;
                D_802A3E88_7214D8_ptr2 += i * 3 + 1;
                D_802A3E88_7214D8_ptr3 += i * 3 + 2;

                x = *D_802A3E88_7214D8_ptr1 + D_802A3F88.x;
                y = *D_802A3E88_7214D8_ptr2;
                z = *D_802A3E88_7214D8_ptr3 + D_802A3F88.z;

                virtual_entity_set_pos(D_802A3F58_ptr[i], x, y, z);

                if (flag == 0 && script->functionTemp[1] == i) {
                    f32 x2, y2;
                    if (gGameStatusPtr->frameCounter % 5 == 0) {

                        y2 = y;
                        if (x > 0.0f) {
                            x2 = x;
                            if (x > 100.0f) {
                                x2 = x - 50.0f;
                            }
                            y2 = rand_int(x2);
                        }
                        x2 = x;
                        if (x > 40.0f) {
                            x2 = -(x - 40.0f);
                        }
                        fx_land(3, x2, y2, z, 0);
                        flag = 1;
                    }
                }
                D_802A3E88_7214D8_ptr1 += 0xC;
                D_802A3E88_7214D8_ptr2 += 0xC;
                D_802A3E88_7214D8_ptr3 += 0xC;
            }
            if (gGameStatusPtr->frameCounter & 1) {
                s32 randIdx = rand_int(9);
                fx_land(2, N(D_802A3E88_7214D8)[randIdx * 3 + 0] + D_802A3F88_ptr->x,
                              N(D_802A3E88_7214D8)[randIdx * 3 + 1],
                              N(D_802A3E88_7214D8)[randIdx * 3 + 2] + D_802A3F88_ptr->z, 0);
            }
            if (D_802A3F88_ptr->x >= 320.0f) {
                script->functionTemp[0] = 2;
                break;
            }
            return ApiStatus_DONE2;

        case 2:
            for (i = 0; i < 10; i++) {
                virtual_entity_delete_by_index(*(&D_802A3F58 + i));
            }

            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(ApiStatus, "battle/item/sleepy_sheep", battle_item_sleepy_sheep_func_802A123C_71E88C,
            Evt* script, s32 isInitialCall);
#endif

ApiStatus N(func_802A1740_71ED90)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0x5A;
    }

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);
        ActorPart* targetPart = get_actor_part(targetActor, target->partID);

        if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
            targetActor->yaw += 33.0f;
            targetActor->yaw = clamp_angle(targetActor->yaw);
        }
    }

    if (script->functionTemp[1] != 0) {
        script->functionTemp[1]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1848_71EE98)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 i;
    s32 ret;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    ret = 0;

    for (i = 0; i < player->targetListLength; i++) {
        s8 targetIdx = player->targetIndexList[i];
        SelectableTarget* target = &player->targetData[targetIdx];
        Actor* targetActor = get_actor(target->actorID);

        if (targetActor != NULL) {
            ActorPart* targetPart = get_actor_part(targetActor, target->partID);
            if ((targetActor->transStatus == 0) && !(targetPart->eventFlags & 0x20)) {
                if (targetActor->yaw < 360.0f) {
                    targetActor->yaw += 33.0f;
                    if (targetActor->yaw >= 360.0f) {
                        targetActor->yaw = 360.0f;
                    }
                    ret = 1;
                }
            }
        }
    }

    return (ret == 0) * ApiStatus_DONE2;
}

#include "UseItem.inc.c"

static s32 _pad = 0;

#include "battle/item/sleepy_sheep1.png.inc.c"
#include "battle/item/sleepy_sheep1.pal.inc.c"
#include "battle/item/sleepy_sheep2.png.inc.c"
#include "battle/item/sleepy_sheep2.pal.inc.c"
#include "battle/item/sleepy_sheep3.png.inc.c"
#include "battle/item/sleepy_sheep3.pal.inc.c"

Vtx N(model)[] = {
    { .v = { -28,  0,  0, FALSE, 0,    1536, 0, 0, 0, 255 } },
    { .v = {  27,  0,  0, FALSE, 1792, 1536, 0, 0, 0, 255 } },
    { .v = {  27, 47,  0, FALSE, 1792,    0, 0, 0, 0, 255 } },
    { .v = { -28, 47,  0, FALSE, 0,       0, 0, 0, 0, 255 } },
};

Gfx N(frame1_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep1_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep1_png, G_IM_FMT_CI, battle_item_sleepy_sheep1_png_width, battle_item_sleepy_sheep1_png_height, 0, 0, battle_item_sleepy_sheep1_png_width - 1, battle_item_sleepy_sheep1_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame2_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep2_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep2_png, G_IM_FMT_CI, battle_item_sleepy_sheep2_png_width, battle_item_sleepy_sheep2_png_height, 0, 0, battle_item_sleepy_sheep2_png_width - 1, battle_item_sleepy_sheep2_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx N(frame3_displayList)[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, battle_item_sleepy_sheep3_pal),
    gsDPLoadTextureTile_4b(battle_item_sleepy_sheep3_png, G_IM_FMT_CI, battle_item_sleepy_sheep3_png_width, battle_item_sleepy_sheep3_png_height, 0, 0, battle_item_sleepy_sheep3_png_width - 1, battle_item_sleepy_sheep3_png_height - 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(N(model), ARRAY_COUNT(N(model)), 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

s32 N(modelCommandList)[] = {
    0x00000004, 0x0000000D,
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000002, 0x00000000,

    0x00000004, 0x0000000D,
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000002, 0x00000000,

    0x00000004, 0x0000000D,
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000002, &N(frame3_displayList),
    0x00000001, 0x00000002, &N(frame1_displayList),
    0x00000001, 0x00000003, &N(frame2_displayList),
    0x00000002, 0x00000000,
};

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x0000008F)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(UseBattleCamPreset, 19)
    EVT_CALL(SetBattleCamTarget, -67, -15, -5)
    EVT_CALL(SetBattleCamOffsetZ, 45)
    EVT_CALL(SetBattleCamZoom, 169)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_364)
        EVT_LOOP(7)
            EVT_CALL(StartRumble, 2)
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.2))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(2.0))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.0))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.25))
            EVT_WAIT_FRAMES(2)
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(1.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FIXED(0.2))
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 32)
    EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 20, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_THREAD
        EVT_CALL(N(func_802A123C_71E88C))
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_THREAD
        EVT_WAIT_FRAMES(40)
        EVT_CALL(N(func_802A1740_71ED90))
        EVT_CALL(N(func_802A1848_71EE98))
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_1002B, ANIM_1002B, ANIM_MIDAIR)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FIXED(1.8))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_80273444, 15, 0, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(40)
    EVT_CALL(CreateVirtualEntity, EVT_VAR(10), EVT_PTR(N(modelCommandList)))
    EVT_SET(EVT_VAR(7), -200)
    EVT_SET(EVT_VAR(8), 0)
    EVT_SET(EVT_VAR(9), 0)
    EVT_CALL(SetVirtualEntityPosition, EVT_VAR(10), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
    EVT_CALL(SetVirtualEntityScale, EVT_VAR(10), EVT_FIXED(0.71), EVT_FIXED(0.71), EVT_FIXED(0.71))
    EVT_CALL(SetVirtualEntityMoveSpeed, EVT_VAR(10), EVT_FIXED(7.0))
    EVT_CALL(SetVirtualEntityJumpGravity, EVT_VAR(10), EVT_FIXED(1.4))
    EVT_CALL(SetOwnerTarget, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PLAYER)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 60)
    EVT_CALL(VirtualEntityMoveTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
    EVT_CALL(GetGoalPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_HIT_BLOCK)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_SHOCK_STILL)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FIXED(1.2), EVT_FIXED(0.9), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FIXED(1.3), EVT_FIXED(0.8), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FIXED(1.2), EVT_FIXED(0.9), EVT_FIXED(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_PLAYER, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_END_THREAD
    EVT_CALL(PlayEffect, 0x6, 3, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetVirtualEntityJumpGravity, EVT_VAR(10), EVT_FIXED(1.4))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 60)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
    EVT_CALL(PlayEffect, 0x6, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_ADD(EVT_VAR(0), 20)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
    EVT_CALL(PlayEffect, 0x6, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ADD(EVT_VAR(0), 10)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
    EVT_CALL(PlayEffect, 0x6, 2, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(5)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 270)
        EVT_CALL(VirtualEntityMoveTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 0)
        EVT_CALL(DeleteVirtualEntity, EVT_VAR(10))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetItemPower, ITEM_SLEEPY_SHEEP, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(MakeStatusField, EVT_VAR(0), 4096, 100, EVT_VAR(0))
    EVT_CALL(func_80252B3C, EVT_VAR(0), 1342177280, EVT_VAR(0), 0, 32)
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(ChooseNextTarget, 0, EVT_VAR(0))
    EVT_IF_NE(EVT_VAR(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT_FRAMES(30)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};

s32 D_802A3E88_7214D8[] = {
    0, 0
};
