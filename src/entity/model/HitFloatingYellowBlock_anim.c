#include "common.h"
#include "animation_script.h"

extern Gfx Entity_HitFloatingYellowBlock_RenderBlock2[];
extern Gfx Entity_HitFloatingYellowBlock_RenderBlock1[];

StaticAnimatorNode Entity_HitFloatingYellowBlock_NodeBlock2 = {
    .displayList = Entity_HitFloatingYellowBlock_RenderBlock2,
    .pos = { 0.0f, 25.0f, 0.0f },
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_HitFloatingYellowBlock_NodeBlock1 = {
    .displayList = Entity_HitFloatingYellowBlock_RenderBlock1,
    .sibling = &Entity_HitFloatingYellowBlock_NodeBlock2,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_HitFloatingYellowBlock_NodeMain = {
    .displayList = ENTITY_ANIM_NULL,
    .sibling = ENTITY_ANIM_NULL,
    .child = &Entity_HitFloatingYellowBlock_NodeBlock1,
};

StaticAnimatorNode* Entity_HitFloatingYellowBlock_Mesh[] = {
    &Entity_HitFloatingYellowBlock_NodeMain,
    &Entity_HitFloatingYellowBlock_NodeBlock1,
    &Entity_HitFloatingYellowBlock_NodeBlock2,
    ENTITY_ANIM_NULL,
};

AnimScript Entity_HitFloatingYellowBlock_AnimationHit = {
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 25, 0)
    as_SetScale(3, 1.0, -1.0, 1.0)
    as_Wait(1)
    as_SetScale(2, 1.26, 0.815, 1.26)
    as_SetPos(3, 0, 20, 0)
    as_SetScale(3, 1.26, -0.815, 1.26)
    as_Wait(1)
    as_SetScale(2, 1.735, 0.405, 1.735)
    as_SetPos(3, 0, 10, 0)
    as_SetScale(3, 1.735, -0.405, 1.735)
    as_Wait(1)
    as_SetScale(2, 2.0, 0.0, 2.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 2.0, 0.0, 2.0)
    as_Wait(1)
    as_SetPos(2, 0, 8, 0)
    as_SetScale(2, 1.805, -0.335, 1.805)
    as_SetScale(3, 1.805, 0.335, 1.805)
    as_Wait(1)
    as_SetPos(2, 0, 16, 0)
    as_SetScale(2, 1.395, -0.675, 1.395)
    as_SetScale(3, 1.395, 0.675, 1.395)
    as_Wait(1)
    as_SetPos(2, 0, 25, 0)
    as_SetScale(2, 1.0, -1.0, 1.0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_SetPos(2, 0, 31, 0)
    as_SetScale(2, 0.745, -1.245, 0.745)
    as_SetScale(3, 0.745, 1.245, 0.745)
    as_Wait(1)
    as_SetPos(2, 0, 28, 0)
    as_SetScale(2, 0.875, -1.12, 0.875)
    as_SetScale(3, 0.875, 1.12, 0.875)
    as_Wait(1)
    as_Loop
    as_SetPos(2, 0, 25, 0)
    as_SetScale(2, 1.0, -1.0, 1.0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};

AnimScript Entity_HitFloatingYellowBlock_AnimationIdle = {
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 25, 0)
    as_SetScale(3, 1.0, -1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};
