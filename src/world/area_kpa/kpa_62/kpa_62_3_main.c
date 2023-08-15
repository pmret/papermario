#include "kpa_62.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_OpenAirshipDockDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_AIRSHIP_DOCK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(EnableModel, MODEL_o1616, FALSE)
    EVT_CALL(MakeLerp, 0, -10, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1650, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, 0, 45, 25, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1650, -10, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseAirshipDockDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_AIRSHIP_DOCK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 45, 0, 25, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1650, -10, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, -10, 0, 20, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o1650, LVar0, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_o1616, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kpa_70_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_METAL)
    EVT_SET(LVar0, kpa_62_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittn)
    EVT_SET(LVar2, MODEL_o1647)
    EVT_SET(LVar3, MODEL_o1646)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kpa_70"), kpa_70_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_1X_Upper) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_62_ENTRY_1)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kpa_11"), kpa_11_ENTRY_0)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kpa_10"), kpa_10_ENTRY_0)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_1X_Lower) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_62_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kpa_11"), kpa_11_ENTRY_3)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kpa_10"), kpa_10_ENTRY_3)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_kpa_63_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_OpenAirshipDockDoor))
    EVT_WAIT(15)
    EVT_CALL(UseExitHeading, 60, kpa_62_ENTRY_3)
    EVT_EXEC(ExitWalk)
    EVT_CALL(GotoMap, EVT_PTR("kpa_63"), kpa_63_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterFromAirshipDock) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetPlayerPos, -30, 21, 590)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -30, 21, 590)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    EVT_CALL(EnableModel, MODEL_o1616, FALSE)
    EVT_CALL(TranslateModel, MODEL_o1650, -10, 0, 45)
    EVT_THREAD
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 75, 580, 0)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.0))
    EVT_CALL(NpcMoveTo, NPC_PARTNER, 65, 600, 0)
    EVT_EXEC_WAIT(N(EVS_CloseAirshipDockDoor))
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_1X_Upper)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_1X_Lower)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_63_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitts, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DisableLavaCollision) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1710, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1508, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1705, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_62_ENTRY_0)
            EVT_EXEC_WAIT(N(EVS_DisableLavaCollision))
            EVT_SET(LVar2, MODEL_o1647)
            EVT_SET(LVar3, MODEL_o1646)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_62_ENTRY_1)
            EVT_EXEC_WAIT(N(EVS_DisableLavaCollision))
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(kpa_62_ENTRY_2)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
        EVT_CASE_EQ(kpa_62_ENTRY_3)
            EVT_EXEC_WAIT(N(EVS_DisableLavaCollision))
            EVT_THREAD
                EVT_EXEC_WAIT(N(EVS_EnterFromAirshipDock))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Lava) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o1508, TEX_PANNER_0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o1559, .pos = { -455.0,  -15.0,   35.0 }},
    { .colliderID = COLLIDER_o1560, .pos = { -545.0,   10.0,   15.0 }},
    { .colliderID = COLLIDER_o1692, .pos = { -426.0,  -35.0,   70.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_SET(GF_MAP_BowsersCastle, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(EnableGroup, MODEL_after, FALSE)
        EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_END_IF
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(3)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1508, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1705, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1706, SURFACE_TYPE_LAVA)
            EVT_THREAD
                EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
            EVT_END_THREAD
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};


