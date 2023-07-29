#include "kmr_02.h"
#include "entity.h"
#include "effects.h"

API_CALLABLE(N(PlayerHasBadgeEquipped)) {
    PlayerData* playerData = &gPlayerData;
    s32 hasBadgeEquipped = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] != 0) {
            hasBadgeEquipped = TRUE;
            break;
        }
    }

    script->varTable[0] = hasBadgeEquipped;
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPositionF.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_GotoMap_tik_01_2) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_01"), tik_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(AnimateBlockScale)) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rot.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 * 0.5f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_OnSmash_GateBlock) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0066)
    EVT_WAIT(10 * DT)
    EVT_CALL(N(PlayerHasBadgeEquipped))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_Goompapa, ANIM_Goompapa_Talk, ANIM_Goompapa_Idle, 0, MSG_CH0_0067)
        EVT_WAIT(10 * DT)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GB_StoryProgress, STORY_CH0_SMASHED_GATE_BLOCK)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonGateBlock) = {
    EVT_CALL(PlaySoundAt, SOUND_207A, SOUND_SPACE_MODE_0, 373, 88, 255)
    EVT_CALL(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, 373, 88, 255, 1, 100)
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAt, SOUND_207B, SOUND_SPACE_MODE_0, 326, 150, 261)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, 326, 150, 261, 1, 60)
    EVT_WAIT(20 * DT)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, 326, 150, 261, 1, 60)
    EVT_WAIT(10 * DT)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, 326, 150, 261, 1, 60)
    EVT_WAIT(5 * DT)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, 326, 150, 261, 1, 60)
    EVT_WAIT(3 * DT)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, 326, 150, 261, 1, 60)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block), 326, 120, 261, 148, MAKE_ENTITY_END)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_GateBlock)))
    EVT_CALL(N(AnimateBlockScale))
    EVT_SET(LVar9, LVarA)
    EVT_CALL(N(GetEntityPosition), LVar9, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar3, 300, 20 * DT, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_207C, SOUND_SPACE_MODE_0, LVar2, LVar0, LVar4)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, LVar2, 0, LVar4, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_207D, SOUND_SPACE_MODE_0, LVar2, LVar0, LVar4)
    EVT_CALL(MakeLerp, 300, 0, 20 * DT, EASING_CUBIC_IN)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(EnableGroup, MODEL_2, TRUE)
    EVT_CALL(EnableGroup, MODEL_1, FALSE)
    EVT_CALL(PlaySoundAt, SOUND_DD, SOUND_SPACE_MODE_0, LVar2, LVar0, LVar4)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15 * DT, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH0_GATE_CRUSHED)
        EVT_CASE_LT(STORY_CH0_SMASHED_GATE_BLOCK)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1Block_WideX), 326, 0, 261, 270, MAKE_ENTITY_END)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_GateBlock)))
        EVT_CASE_LT(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_IF_EQ(GF_KMR02_WarpPipe, FALSE)
        EVT_IF_EQ(GF_TIK01_WarpPipes, TRUE)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_NE(LVar0, kmr_02_ENTRY_3)
                EVT_SET(GF_KMR02_WarpPipe, TRUE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueWarpPipe), 0, 0, 355, 0, kmr_02_ENTRY_3, EVT_PTR(N(EVS_GotoMap_tik_01_2)), EVT_INDEX_OF_GAME_FLAG(GF_KMR02_WarpPipe), MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 250, 60, 75, -15, MAKE_ENTITY_END)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_TWINK_GAVE_LUCKY_STAR)
        EVT_CALL(MakeItemEntity, ITEM_SHOOTING_STAR, 510, 0, -340, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KMR02_Item_ShootingStar)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
