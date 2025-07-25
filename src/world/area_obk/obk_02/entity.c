#include "obk_02.h"
#include "entity.h"
#include "sprite/player.h"

EvtScript N(EVS_ChestTrap) = {
    Wait(15)
    Thread
        Call(PlaySoundAt, SOUND_OBK_CHANDELIER_RELEASE, SOUND_SPACE_DEFAULT, 4, 26, -12)
        Call(MakeLerp, 0, -80, 10 * DT, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_shiyan, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(PlaySoundAt, SOUND_OBK_CHANDELIER_STOP, SOUND_SPACE_DEFAULT, 4, 26, -12)
        Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.5))
        Wait(40 * DT)
        Call(PlaySoundAt, SOUND_OBK_CHANDELIER_RETRACT, SOUND_SPACE_DEFAULT, 4, 26, -12)
        Call(MakeLerp, -80, 0, 20 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateGroup, MODEL_shiyan, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(2)
    Call(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    Wait(48 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(GF_OBK02_TriggeredChestTrap, true)
    Wait(5 * DT)
    Return
    End
};

EvtScript N(EVS_OpenChest) = {
    Call(DisablePlayerInput, true)
    ExecWait(N(EVS_ChestTrap))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 0, 0, 0, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OBK02_Chest_Trap)
    Call(AssignScript, Ref(N(EVS_OpenChest)))
    Call(MakeEntity, Ref(Entity_HiddenPanel), 100, -210, 0, 0, MODEL_yuka_b1, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OBK02_HiddenPanel)
    Return
    End
};
