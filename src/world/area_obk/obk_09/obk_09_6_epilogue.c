#include "obk_09.h"

API_CALLABLE(N(SetInvitationLetterScale)) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Scene_Epilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, TRUE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-8.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -280, 234)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, -135, 105)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Walk)
    EVT_CALL(NpcMoveTo, NPC_Bootler, -159, 158, 50)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Talk)
    EVT_WAIT(15)
    EVT_CALL(SetNpcAnimation, NPC_Bootler, ANIM_Bootler_Idle)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_CALL(DropResizableItemEntity, ITEM_LETTER_TO_KOLORADO, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_CALL(N(SetInvitationLetterScale))
        EVT_LOOP(35)
            EVT_CALL(GetNpcPos, NPC_Bootler, LVar1, LVar2, LVar3)
            EVT_ADD(LVar1, -16)
            EVT_ADD(LVar2, 4)
            EVT_ADD(LVar3, -10)
            EVT_CALL(SetItemPos, LVar0, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(35)
        EVT_CALL(RemoveItemEntity, LVar0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_Bootler, -172, 143, 20)
    EVT_CALL(SetNpcJumpscale, NPC_Bootler, 0)
    EVT_WAIT(10)
    EVT_CALL(NpcJump1, NPC_Bootler, -159, 10, 158, 20)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bow, ANIM_WorldBow_Read)
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_Bow, ANIM_WorldBow_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Bow, ANIM_WorldBow_CelebrateSlow)
    EVT_WAIT(30)
    EVT_CALL(FadeOutMusic, 0, 1000)
    EVT_CALL(GotoMap, EVT_PTR(NEXT_EPILOGUE_MAP), omo_03_ENTRY_5)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
