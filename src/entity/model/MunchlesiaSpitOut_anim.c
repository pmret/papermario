#include "common.h"
#include "animation_script.h"

extern Vtx D_0A000000_E8A9E0[];
extern Gfx Entity_MunchlesiaSpitOut_Render[];

AnimScript Entity_MunchlesiaSpitOut_Animation = {
    as_SetRotation(1, 0.0, 0.0, 0.0)
    as_SetPos(1, 0, 0, 0)
    as_SetScale(1, 1.0, 1.0, 1.0)
    as_SetRotation(2, 0.0, 0.0, 0.0)
    as_SetPos(2, 0, 0, 0)
    as_SetScale(2, 1.0, 1.0, 1.0)
    as_SetRotation(3, 0.0, 0.0, 0.0)
    as_SetPos(3, 0, 0, 0)
    as_SetScale(3, 1.0, 1.0, 1.0)
    as_SetRotation(4, 0.0, 0.0, 0.0)
    as_SetPos(4, 0, 0, 0)
    as_SetScale(4, 1.0, 1.0, 1.0)
    as_SetRotation(5, 0.0, 0.0, 0.0)
    as_SetPos(5, 0, 0, 0)
    as_SetScale(5, 1.0, 1.0, 1.0)
    as_SetRotation(6, 0.0, 0.0, 0.0)
    as_SetPos(6, 0, 0, 0)
    as_SetScale(6, 1.0, 1.0, 1.0)
    as_SetRotation(7, 0.0, 0.0, 0.0)
    as_SetPos(7, 0, 0, 0)
    as_SetScale(7, 1.0, 1.0, 1.0)
    as_SetRotation(8, 0.0, 0.0, 0.0)
    as_SetPos(8, 0, 0, 0)
    as_SetScale(8, 1.0, 1.0, 1.0)
    as_Loop
    as_SetRotation(9, 0.0, 0.0, 0.0)
    as_SetPos(9, 0, 0, 0)
    as_SetScale(9, 1.0, 1.0, 1.0)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Wait(1)
    as_Restart
    as_End
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node9 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = ENTITY_ANIM_NULL,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 7,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node8 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node9,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 6,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node7 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node8,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 5,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node6 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node7,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 4,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node5 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node6,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 3,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node4 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node5,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399 * 2,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node3 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node4,
    .child = ENTITY_ANIM_NULL,
    .vertexStartOffset = 399,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node2 = {
    .displayList = Entity_MunchlesiaSpitOut_Render,
    .sibling = &Entity_MunchlesiaSpitOut_Node3,
    .child = ENTITY_ANIM_NULL,
    .vtxList = D_0A000000_E8A9E0,
};

StaticAnimatorNode Entity_MunchlesiaSpitOut_Node1 = {
    .displayList = ENTITY_ANIM_NULL,
    .sibling = ENTITY_ANIM_NULL,
    .child = &Entity_MunchlesiaSpitOut_Node2,
    .vertexStartOffset = (s32)ENTITY_ANIM_NULL,
    .vtxList = ENTITY_ANIM_NULL,
};

StaticAnimatorNode* Entity_MunchlesiaSpitOut_Mesh[] = {
    &Entity_MunchlesiaSpitOut_Node1,
    &Entity_MunchlesiaSpitOut_Node2,
    &Entity_MunchlesiaSpitOut_Node3,
    &Entity_MunchlesiaSpitOut_Node4,
    &Entity_MunchlesiaSpitOut_Node5,
    &Entity_MunchlesiaSpitOut_Node6,
    &Entity_MunchlesiaSpitOut_Node7,
    &Entity_MunchlesiaSpitOut_Node8,
    &Entity_MunchlesiaSpitOut_Node9,
    ENTITY_ANIM_NULL,
};
