#include "common.h"
#include "animation_script.h"

extern Gfx Entity_CymbalPlant_RenderNode10[];
extern Gfx Entity_CymbalPlant_RenderNode9[];
extern Gfx Entity_CymbalPlant_RenderNode8[];
extern Gfx Entity_CymbalPlant_RenderNode7[];
extern Gfx Entity_CymbalPlant_RenderNode5[];
extern Gfx Entity_CymbalPlant_RenderNode4[];
extern Gfx Entity_CymbalPlant_RenderNode3[];
extern Gfx Entity_CymbalPlant_RenderNode1[];

StaticAnimatorNode Entity_CymbalPlant_Node10 = {
    .displayList = Entity_CymbalPlant_RenderNode10,
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node9 = {
    .displayList = Entity_CymbalPlant_RenderNode9,
    .pos = { -2.0f, -26.0f, 0.0f },
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node8 = {
    .displayList = Entity_CymbalPlant_RenderNode8,
    .pos = { -2.0f, -26.0f, 0.0f },
    .sibling = &Entity_CymbalPlant_Node9,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node7 = {
    .displayList = Entity_CymbalPlant_RenderNode7,
    .pos = { -2.0f, -26.0f, 0.0f },
    .sibling = &Entity_CymbalPlant_Node8,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node6 = {
    .displayList = ENTITY_ANIM_NULL,
    .pos = { 2.0f, 26.0f, 0.0f },
    .sibling = ENTITY_ANIM_NULL,
    .child = &Entity_CymbalPlant_Node7,
};

StaticAnimatorNode Entity_CymbalPlant_Node5 = {
    .displayList = Entity_CymbalPlant_RenderNode5,
    .pos = { 3.0f, -26.0f, 0.0f },
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node4 = {
    .displayList = Entity_CymbalPlant_RenderNode4,
    .pos = { 3.0f, -26.0f, 0.0f },
    .sibling = &Entity_CymbalPlant_Node5,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node3 = {
    .displayList = Entity_CymbalPlant_RenderNode3,
    .pos = { 3.0f, -26.0f, 0.0f },
    .sibling = &Entity_CymbalPlant_Node4,
    .child = ENTITY_ANIM_NULL,
};

StaticAnimatorNode Entity_CymbalPlant_Node2 = {
    .displayList = ENTITY_ANIM_NULL,
    .pos = { -3.0f, 26.0f, 0.0f },
    .sibling = &Entity_CymbalPlant_Node6,
    .child = &Entity_CymbalPlant_Node3,
};

StaticAnimatorNode Entity_CymbalPlant_Node1 = {
    .displayList = Entity_CymbalPlant_RenderNode1,
    .sibling = &Entity_CymbalPlant_Node10,
    .child = &Entity_CymbalPlant_Node2,
};

StaticAnimatorNode Entity_CymbalPlant_NodeParent = {
    .displayList = ENTITY_ANIM_NULL,
    .sibling = ENTITY_ANIM_NULL,
    .child = &Entity_CymbalPlant_Node1,
};

StaticAnimatorNode* Entity_CymbalPlant_Mesh[] = {
    &Entity_CymbalPlant_NodeParent,
    &Entity_CymbalPlant_Node1,
    &Entity_CymbalPlant_Node2,
    &Entity_CymbalPlant_Node3,
    &Entity_CymbalPlant_Node4,
    &Entity_CymbalPlant_Node5,
    &Entity_CymbalPlant_Node6,
    &Entity_CymbalPlant_Node7,
    &Entity_CymbalPlant_Node8,
    &Entity_CymbalPlant_Node9,
    &Entity_CymbalPlant_Node10,
    ENTITY_ANIM_NULL,
};

AnimScript Entity_CymbalPlant_AnimationGrab = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, -3, 26, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 3, -26, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 3, -26, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_SetRotation(6, 0.0, 0.0, 0.0)
    as_SetPos(6, 3, -26, 0)
    as_SetScale(6, 1.0, 1.0, 1.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetPos(7, 2, 26, 0)
    as_SetScale(7, 1.0, 1.0, 1.0)
    as_SetRotation(8, 0.0, 0.0, 0.0)
    as_SetPos(8, -2, -26, 0)
    as_SetScale(8, 1.0, 1.0, 1.0)
    as_SetRotation(9, 0.0, 0.0, 0.0)
    as_SetPos(9, -2, -26, 0)
    as_SetScale(9, 1.0, 1.0, 1.0)
    as_SetRotation(10, 0.0, 0.0, 0.0)
    as_SetPos(10, -2, -26, 0)
    as_SetScale(10, 1.0, 1.0, 1.0)
    as_SetRotation(11, 0.0, 0.0, 0.0)
    as_SetPos(11, 0, 0, 0)
    as_SetScale(11, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -9.36)
    as_SetRotation(7, 0.0, 0.0, 9.355)
    as_SetRotation(11, 0.0, 0.0, -0.225)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -31.685)
    as_SetRotation(7, 0.0, 0.0, 31.68)
    as_SetRotation(11, 0.0, 0.0, -0.68)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -58.33)
    as_SetRotation(7, 0.0, 0.0, 58.315)
    as_SetRotation(11, 0.0, 0.0, -1.025)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -80.64)
    as_SetRotation(7, 0.0, 0.0, 80.635)
    as_SetRotation(11, 0.0, 0.0, -0.91)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.995)
    as_SetRotation(7, 0.0, 0.0, 89.995)
    as_SetRotation(11, 0.0, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -84.995)
    as_SetRotation(7, 0.0, 0.0, 85.0)
    as_SetRotation(11, 0.0, 0.0, 5.67)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -80.0)
    as_SetRotation(7, 0.0, 0.0, 80.0)
    as_SetRotation(11, 0.0, 0.0, 10.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -84.985)
    as_SetRotation(7, 0.0, 0.0, 85.0)
    as_SetRotation(11, 0.0, 0.0, 2.435)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.995)
    as_SetRotation(7, 0.0, 0.0, 89.995)
    as_SetRotation(11, 0.0, 0.0, -5.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -87.51)
    as_SetRotation(7, 0.0, 0.0, 87.5)
    as_SetRotation(11, 0.0, 0.0, -2.93)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -85.0)
    as_SetRotation(7, 0.0, 0.0, 85.0)
    as_SetRotation(11, 0.0, 0.0, 2.02)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -87.49)
    as_SetRotation(7, 0.0, 0.0, 87.5)
    as_SetRotation(11, 0.0, 0.0, 5.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.995)
    as_SetRotation(7, 0.0, 0.0, 89.995)
    as_SetRotation(11, 0.0, 0.0, 4.075)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -88.75)
    as_SetRotation(7, 0.0, 0.0, 88.745)
    as_SetRotation(11, 0.0, 0.0, 1.565)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -87.5)
    as_SetRotation(7, 0.0, 0.0, 87.5)
    as_SetRotation(11, 0.0, 0.0, -1.105)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -88.75)
    as_SetRotation(7, 0.0, 0.0, 88.745)
    as_SetRotation(11, 0.0, 0.0, -2.5)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.995)
    as_SetRotation(7, 0.0, 0.0, 89.995)
    as_SetRotation(11, 0.0, 0.0, -2.175)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.985)
    as_SetRotation(7, 0.0, 0.0, 90.015)
    as_SetRotation(11, 0.0, 0.0, -0.995)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.975)
    as_SetRotation(7, 0.0, 0.0, 90.025)
    as_SetRotation(11, 0.0, 0.0, 0.52)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.97)
    as_SetRotation(7, 0.0, 0.0, 90.03)
    as_SetRotation(11, 0.0, 0.0, 1.86)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.965)
    as_SetRotation(7, 0.0, 0.0, 90.025)
    as_SetRotation(11, 0.0, 0.0, 2.5)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.96)
    as_SetRotation(7, 0.0, 0.0, 90.015)
    as_SetRotation(11, 0.0, 0.0, 2.315)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 90.005)
    as_SetRotation(11, 0.0, 0.0, 1.67)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 89.99)
    as_SetRotation(11, 0.0, 0.0, 0.78)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.965)
    as_SetRotation(7, 0.0, 0.0, 89.975)
    as_SetRotation(11, 0.0, 0.0, -0.135)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 89.96)
    as_SetRotation(11, 0.0, 0.0, -0.885)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.97)
    as_SetRotation(7, 0.0, 0.0, 89.94)
    as_SetRotation(11, 0.0, 0.0, -1.245)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 89.925)
    as_SetRotation(11, 0.0, 0.0, -1.19)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.975)
    as_SetRotation(7, 0.0, 0.0, 89.92)
    as_SetRotation(11, 0.0, 0.0, -0.885)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.98)
    as_SetRotation(7, 0.0, 0.0, 89.915)
    as_SetRotation(11, 0.0, 0.0, -0.415)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.985)
    as_SetRotation(11, 0.0, 0.0, 0.11)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.99)
    as_SetRotation(7, 0.0, 0.0, 89.92)
    as_SetRotation(11, 0.0, 0.0, 0.625)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 89.935)
    as_SetRotation(11, 0.0, 0.0, 1.04)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -89.995)
    as_SetRotation(7, 0.0, 0.0, 89.965)
    as_SetRotation(11, 0.0, 0.0, 1.245)
    as_Wait(1)
    as_SetRotation(7, 0.0, 0.0, 89.995)
    as_SetRotation(11, 0.0, 0.0, 1.26)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -84.58)
    as_SetRotation(7, 0.0, 0.0, 84.61)
    as_SetRotation(11, 0.0, 0.0, 1.15)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -70.665)
    as_SetRotation(7, 0.0, 0.0, 70.7)
    as_SetRotation(11, 0.0, 0.0, 0.95)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -51.745)
    as_SetRotation(7, 0.0, 0.0, 51.78)
    as_SetRotation(11, 0.0, 0.0, 0.705)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -31.33)
    as_SetRotation(7, 0.0, 0.0, 31.35)
    as_SetRotation(11, 0.0, 0.0, 0.45)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, -12.915)
    as_SetRotation(7, 0.0, 0.0, 12.92)
    as_SetRotation(11, 0.0, 0.0, 0.225)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetRotation(11, 0.0, 0.0, 0.06)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, 5.06)
    as_SetRotation(7, 0.0, 0.0, -5.06)
    as_SetRotation(11, 0.0, 0.0, 0.0)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, 4.5)
    as_SetRotation(7, 0.0, 0.0, -4.5)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, 1.685)
    as_SetRotation(7, 0.0, 0.0, -1.685)
    as_Wait(1)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_Wait(1)
    as_Loop
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, -3, 26, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 3, -26, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 3, -26, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_SetRotation(6, 0.0, 0.0, 0.0)
    as_SetPos(6, 3, -26, 0)
    as_SetScale(6, 1.0, 1.0, 1.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetPos(7, 2, 26, 0)
    as_SetScale(7, 1.0, 1.0, 1.0)
    as_SetRotation(8, 0.0, 0.0, 0.0)
    as_SetPos(8, -2, -26, 0)
    as_SetScale(8, 1.0, 1.0, 1.0)
    as_SetRotation(9, 0.0, 0.0, 0.0)
    as_SetPos(9, -2, -26, 0)
    as_SetScale(9, 1.0, 1.0, 1.0)
    as_SetRotation(10, 0.0, 0.0, 0.0)
    as_SetPos(10, -2, -26, 0)
    as_SetScale(10, 1.0, 1.0, 1.0)
    as_SetRotation(11, 0.0, 0.0, 0.0)
    as_SetPos(11, 0, 0, 0)
    as_SetScale(11, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};

AnimScript Entity_CymbalPlant_AnimationIdle = {
    as_DisableMirroring
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, -3, 26, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 3, -26, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 3, -26, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_SetRotation(6, 0.0, 0.0, 0.0)
    as_SetPos(6, 3, -26, 0)
    as_SetScale(6, 1.0, 1.0, 1.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetPos(7, 2, 26, 0)
    as_SetScale(7, 1.0, 1.0, 1.0)
    as_SetRotation(8, 0.0, 0.0, 0.0)
    as_SetPos(8, -2, -26, 0)
    as_SetScale(8, 1.0, 1.0, 1.0)
    as_SetRotation(9, 0.0, 0.0, 0.0)
    as_SetPos(9, -2, -26, 0)
    as_SetScale(9, 1.0, 1.0, 1.0)
    as_SetRotation(10, 0.0, 0.0, 0.0)
    as_SetPos(10, -2, -26, 0)
    as_SetScale(10, 1.0, 1.0, 1.0)
    as_SetRotation(11, 0.0, 0.0, 0.0)
    as_SetPos(11, 0, 0, 0)
    as_SetScale(11, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Restart
    as_End
};
