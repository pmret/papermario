
#include "world/common/enemy/LavaPiranha.h"

#include "world/common/lava_piranha/part1.inc.c"

#include "world/area_kmr/kmr_22/lava_piranha_vine.png.inc.c"
#include "world/area_kmr/kmr_22/lava_piranha_vine.pal.inc.c"
#include "world/area_kmr/kmr_22/lava_piranha_vine.gfx.inc.c"

#include "world/common/lava_piranha/part2.inc.c"
#include "world/common/lava_piranha/LoadAnimationFromTable.inc.c"

EvtScript N(EVS_NpcAux_LavaPiranhaHead) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_LABEL(0)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
        EVT_CALL(N(MarkVineInterpolationDirty))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 7, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_0, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_0, 8, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_SUB(LVar2, 2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_1, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_1, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 90)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 0, LVar0, 0, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 0, 1, 1, 1)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_SUB(LVar2, 2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 5, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_2, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_2, 6, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 0, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 0, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 1, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 1, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 1, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 2, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 3, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBonePos), VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneRot), VINE_3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(N(SetVineBoneScale), VINE_3, 4, EVT_FLOAT(0.714), EVT_FLOAT(0.714), EVT_FLOAT(1.0))
        EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaPiranhaHead) = {
    EVT_CALL(func_802CFD30, NPC_LavaPiranhaHead, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_CALL(func_802CFD30, NPC_LavaBud_01, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_CALL(func_802CFD30, NPC_LavaBud_02, FOLD_TYPE_E, 80, 80, 80, 0)
    EVT_CALL(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
    EVT_CALL(EnableNpcShadow, NPC_LavaPiranhaHead, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_LavaBud_01, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_LavaBud_02, FALSE)
    EVT_MALLOC_ARRAY(64, LVar0)
    EVT_CALL(SetSelfVar, 0, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_LavaPiranhaHead)))
    EVT_CALL(LoadAnimatedModel, VINE_0, EVT_PTR(N(AnimModel_MainHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_0, -40, 0, 0)
    EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_1, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_1, -40, 0, 0)
    EVT_CALL(SetAnimatorFlags, VINE_1, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_2, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 10, 0, 20)
    EVT_CALL(SetAnimatorFlags, VINE_2, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_3, EVT_PTR(N(AnimModel_ExtraVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_3, -40, 0, 0)
    EVT_CALL(SetAnimatorFlags, VINE_3, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(N(CreateVineRenderer))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaBud_01) = {
    EVT_RETURN
    EVT_END
};

s32 N(D_80243848_902EB8)[] = {
    ANIM_LavaPiranha_Anim03,
    ANIM_LavaPiranha_Anim0E,
    -1
};

s32 N(D_80243854_902EC4)[] = {
    ANIM_LavaBud_Anim03,
    -1
};
