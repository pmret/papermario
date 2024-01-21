#include "nok_04.h"

EvtScript N(EVS_ExitWalk_nok_03_1) = EVT_EXIT_WALK_NOK(60, nok_04_ENTRY_0, "nok_03", nok_03_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_nok_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    Return
    End
};

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(AF_NOK04_PlayingGame, FALSE)
    Set(AF_NOK04_BattleStarted, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o147, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Set(LVar0, TREE_0)
    BindTrigger(Ref(N(EVS_HitTree)), TRIGGER_WALL_HAMMER, COLLIDER_o59, 1, 0)
    Set(LVar0, TREE_1)
    BindTrigger(Ref(N(EVS_HitTree)), TRIGGER_WALL_HAMMER, COLLIDER_o58, 1, 0)
    Set(LVar0, TREE_2)
    BindTrigger(Ref(N(EVS_HitTree)), TRIGGER_WALL_HAMMER, COLLIDER_o57, 1, 0)
    Set(LVar0, TREE_3)
    BindTrigger(Ref(N(EVS_HitTree)), TRIGGER_WALL_HAMMER, COLLIDER_o56, 1, 0)
    Exec(N(EVS_SetupMusic))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitsw, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
