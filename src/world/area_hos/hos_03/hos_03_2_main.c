#include "hos_03.h"

EvtScript N(EVS_ExitWalk_hos_02_1) = EVT_EXIT_WALK(60, hos_03_ENTRY_0, "hos_02", hos_02_ENTRY_1);
EvtScript N(EVS_ExitWalk_hos_04_0) = EVT_EXIT_WALK(60, hos_03_ENTRY_1, "hos_04", hos_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_hos_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_hos_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

#include "world/common/todo/GetFloorCollider.inc.c"

EvtScript N(EVS_ControlUpperVisibility) = {
    Label(0)
        Call(N(GetFloorCollider), LVar0)
        Switch(LVar0)
            CaseEq(COLLIDER_o18)
                Goto(10)
            CaseEq(COLLIDER_o218)
                Goto(10)
            CaseEq(COLLIDER_o224)
                Goto(10)
            CaseEq(COLLIDER_o7)
                Goto(10)
            CaseEq(COLLIDER_o234)
                Goto(10)
            CaseEq(COLLIDER_o235)
                Label(10)
                Call(EnableGroup, MODEL_g50, FALSE)
                Call(EnableGroup, MODEL_g39, FALSE)
                Wait(1)
                Label(15)
                    Call(N(GetFloorCollider), LVar1)
                    IfEq(LVar1, -1)
                        Wait(1)
                        Goto(15)
                    EndIf
                IfEq(LVar0, LVar1)
                    Wait(1)
                    Goto(15)
                EndIf
                Call(EnableGroup, MODEL_g50, TRUE) // house
                Call(EnableGroup, MODEL_g39, TRUE) // shop
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_STAR_HAVEN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    IfEq(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        Set(GB_StoryProgress, STORY_CH8_REACHED_STAR_HAVEN)
    EndIf
    Set(GF_MAP_StarHaven, TRUE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
        Wait(1)
    EndIf
    Exec(N(EVS_SetupAurora))
    Call(UseRoomDoorSounds, DOOR_SOUNDS_UNUSED)
    Exec(N(EVS_SetupMusic))
    Call(PlaySound, SOUND_LOOP_STAR_SANCTUARY_FAR)
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_SetupShop))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_ControlUpperVisibility))
    Return
    End
};
