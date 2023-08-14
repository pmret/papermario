#include "obk_02.h"
#include "entity.h"
#include "sprite/player.h"

EvtScript N(EVS_ChestTrap) = {
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_OBK_CHANDELIER_RELEASE, SOUND_SPACE_DEFAULT, 4, 26, -12)
        EVT_CALL(MakeLerp, 0, -80, 10 * DT, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_shiyan, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAt, SOUND_OBK_CHANDELIER_STOP, SOUND_SPACE_DEFAULT, 4, 26, -12)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.5))
        EVT_WAIT(40 * DT)
        EVT_CALL(PlaySoundAt, SOUND_OBK_CHANDELIER_RETRACT, SOUND_SPACE_DEFAULT, 4, 26, -12)
        EVT_CALL(MakeLerp, -80, 0, 20 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_shiyan, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_FlailArms)
    EVT_WAIT(48 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_SET(GF_OBK02_TriggeredChestTrap, TRUE)
    EVT_WAIT(5 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_ChestTrap))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 0, 0, 0, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OBK02_Chest_Trap)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 100, -210, 0, 0, MODEL_yuka_b1, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OBK02_HiddenPanel)
    EVT_RETURN
    EVT_END
};
