#include "common.h"
#include "animation_script.h"

extern Gfx Entity_TrumpetPlant_RenderNode1[];
extern Gfx Entity_TrumpetPlant_RenderNode2[];

StaticAnimatorNode Entity_TrumpetPlant_Node2 = {
    .displayList = Entity_TrumpetPlant_RenderNode2,
    .rot = { 0, 0, 5461 },
    .pos = { 0.0f, 15.0f, 0.0f },
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_TrumpetPlant_Node1 = {
    .displayList = Entity_TrumpetPlant_RenderNode1,
    .sibling = ENTITY_ANIM_NULL,
    .child = &Entity_TrumpetPlant_Node2,
};

StaticAnimatorNode* Entity_TrumpetPlant_Mesh[] = {
    &Entity_TrumpetPlant_Node1,
    &Entity_TrumpetPlant_Node2,
    ENTITY_ANIM_NULL,
};

AnimScript Entity_TrumpetPlant_AnimationUse = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 30.0)
    as_SetPos(2, 0, 15, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_SetScale(2, 1.055, 0.94, 1.055)
    as_Wait(1)
    as_SetScale(2, 1.2, 0.795, 1.2)
    as_Wait(1)
    as_SetScale(2, 1.355, 0.635, 1.355)
    as_Wait(1)
    as_SetScale(2, 1.48, 0.515, 1.48)
    as_Wait(1)
    as_SetScale(2, 1.5, 0.5, 1.5)
    as_Wait(1)
    as_SetScale(2, 1.37, 0.625, 1.37)
    as_Wait(1)
    as_SetScale(2, 1.13, 0.86, 1.13)
    as_Wait(1)
    as_SetScale(2, 0.855, 1.135, 0.855)
    as_Wait(1)
    as_SetScale(2, 0.62, 1.375, 0.62)
    as_Wait(1)
    as_SetScale(2, 0.5, 1.5, 0.5)
    as_Wait(1)
    as_SetScale(2, 0.455, 1.54, 0.455)
    as_Wait(1)
    as_SetScale(2, 0.425, 1.57, 0.425)
    as_Wait(1)
    as_SetScale(2, 0.395, 1.6, 0.395)
    as_Wait(1)
    as_SetScale(2, 0.375, 1.62, 0.375)
    as_Wait(1)
    as_SetScale(2, 0.355, 1.635, 0.355)
    as_Wait(1)
    as_SetScale(2, 0.345, 1.65, 0.345)
    as_Wait(1)
    as_SetScale(2, 0.34, 1.655, 0.34)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_SetScale(2, 0.35, 1.645, 0.35)
    as_Wait(1)
    as_SetScale(2, 0.355, 1.635, 0.355)
    as_Wait(1)
    as_SetScale(2, 0.375, 1.62, 0.375)
    as_Wait(1)
    as_SetScale(2, 0.39, 1.605, 0.39)
    as_Wait(1)
    as_SetScale(2, 0.405, 1.59, 0.405)
    as_Wait(1)
    as_SetScale(2, 0.43, 1.565, 0.43)
    as_Wait(1)
    as_SetScale(2, 0.45, 1.545, 0.45)
    as_Wait(1)
    as_SetScale(2, 0.47, 1.52, 0.47)
    as_Wait(1)
    as_SetScale(2, 0.5, 1.5, 0.5)
    as_Wait(1)
    as_SetScale(2, 0.71, 1.285, 0.71)
    as_Wait(1)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_SetScale(2, 1.175, 0.82, 1.175)
    as_Wait(1)
    as_SetScale(2, 1.245, 0.745, 1.245)
    as_Wait(1)
    as_SetScale(2, 1.13, 0.84, 1.13)
    as_Wait(1)
    as_SetScale(2, 0.95, 1.0, 0.95)
    as_Wait(1)
    as_SetScale(2, 0.845, 1.1, 0.845)
    as_Wait(1)
    as_SetScale(2, 0.885, 1.095, 0.885)
    as_Wait(1)
    as_SetScale(2, 0.985, 1.045, 0.985)
    as_Wait(1)
    as_SetScale(2, 1.09, 0.985, 1.09)
    as_Wait(1)
    as_SetScale(2, 1.15, 0.945, 1.15)
    as_Wait(1)
    as_SetScale(2, 1.145, 0.945, 1.145)
    as_Wait(1)
    as_SetScale(2, 1.105, 0.955, 1.105)
    as_Wait(1)
    as_SetScale(2, 1.06, 0.97, 1.06)
    as_Wait(1)
    as_SetScale(2, 1.015, 0.99, 1.015)
    as_Wait(1)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Loop
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 30.0)
    as_SetPos(2, 0, 15, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};

AnimScript Entity_TrumpetPlant_AnimationIdle = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 30.0)
    as_SetPos(2, 0, 15, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};
