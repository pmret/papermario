#include "obk_02.h"
#include "entity.h"

EvtScript N(EVS_ChestTrap) = {
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_212A, SOUND_SPACE_MODE_0, 4, 26, -12)
        EVT_CALL(MakeLerp, 0, -80, 10, EASING_QUADRATIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateGroup, MODEL_shiyan, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySoundAt, SOUND_212B, SOUND_SPACE_MODE_0, 4, 26, -12)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.5))
        EVT_WAIT(40)
        EVT_CALL(PlaySoundAt, SOUND_212C, SOUND_SPACE_MODE_0, 4, 26, -12)
        EVT_CALL(MakeLerp, -80, 0, 20, EASING_LINEAR)
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
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_8001F)
    EVT_WAIT(48)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_SET(GF_OBK02_TriggeredChestTrap, TRUE)
    EVT_WAIT(5)
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
