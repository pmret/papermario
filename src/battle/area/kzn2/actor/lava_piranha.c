#include "../area.h"
#include "sprite/npc/LavaPiranha.h"
#include "sprite/npc/BattleKolorado.h"
#include "sprite/npc/LavaBud.h"
#include "sprite/npc/PetitPiranha.h"
#include "sprite/player.h"
#include "animation_script.h"
#include "entity.h"
#include "ld_addrs.h"

#define NAMESPACE A(lava_piranha)

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
};

// unused data
Vtx N(Quad1)[] = {
    {{{   -16,     0,     0 }, 0, {     0,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,     0,     0 }, 0, {  1024,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,    39,     0 }, 0, {  1024,  1280 }, {   0,   0,   0, 255 }}},
    {{{   -16,    39,     0 }, 0, {     0,  1280 }, {   0,   0,   0, 255 }}},
};

Gfx N(DList1)[] = {
    gsSPEndDisplayList(),
};

EntityModelScript N(ModelScript1) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(DList1), 60)
    ems_Restart
    ems_End
    ems_End
};

Vtx N(Quad2)[] = {
    {{{   -16,     0,     0 }, 0, {     0,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,     0,     0 }, 0, {  1024,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,    39,     0 }, 0, {  1024,  1280 }, {   0,   0,   0, 255 }}},
    {{{   -16,    39,     0 }, 0, {     0,  1280 }, {   0,   0,   0, 255 }}},
};

Gfx N(DList2)[] = {
    gsSPEndDisplayList(),
};

EntityModelScript N(ModelScript2) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(DList2), 60)
    ems_Restart
    ems_End
    ems_End
};

Vtx N(Quad3)[] = {
    {{{   -16,     0,     0 }, 0, {     0,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,     0,     0 }, 0, {  1024,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,    39,     0 }, 0, {  1024,  1280 }, {   0,   0,   0, 255 }}},
    {{{   -16,    39,     0 }, 0, {     0,  1280 }, {   0,   0,   0, 255 }}},
};

Gfx N(DList3)[] = {
    gsSPEndDisplayList(),
};

EntityModelScript N(ModelScript3) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(DList3), 60)
    ems_Restart
    ems_End
    ems_End
};

Vtx N(Quad4)[] = {
    {{{   -16,     0,     0 }, 0, {     0,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,     0,     0 }, 0, {  1024,     0 }, {   0,   0,   0, 255 }}},
    {{{    15,    39,     0 }, 0, {  1024,  1280 }, {   0,   0,   0, 255 }}},
    {{{   -16,    39,     0 }, 0, {     0,  1280 }, {   0,   0,   0, 255 }}},
};

Gfx N(DList4)[] = {
    gsSPEndDisplayList(),
};

EntityModelScript N(ModelScript4) = {
    ems_SetRenderMode(RENDER_MODE_ALPHATEST)
    ems_Draw(N(DList4), 60)
    ems_Restart
    ems_End
    ems_End
};

#include "battle/area/kzn2/lava_piranha_vine.png.inc.c"
#include "battle/area/kzn2/lava_piranha_vine.pal.inc.c"
#include "battle/area/kzn2/lava_piranha_vine.gfx.inc.c"

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(initVines);
extern EvtScript N(spawnColorado);
extern EvtScript N(onComboHit);
extern EvtScript N(playHitAnimation);
extern EvtScript N(onHit);
extern EvtScript N(onDeath);
extern EvtScript N(onBurnHit);
extern EvtScript N(ignite);
extern EvtScript N(attackFlameSpew);
extern EvtScript N(attackFireStream);
extern EvtScript N(handleBudDeath);
extern EvtScript N(doOnHit);

extern ActorBlueprint A(lava_bud);
extern StaticAnimatorNode* N(anim1)[];
extern StaticAnimatorNode* N(AnimModel_MainHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_SideHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_ExtraVine)[];
extern AnimScript N(anim1_8021A364);

extern s32 A(lava_bud_IdleAnimations_fiery)[];
extern s32 N(DefenseTable_fiery)[];
extern s32 A(lava_bud_DefenseTable_fiery)[];

API_CALLABLE(SetAnimatorFlags);
API_CALLABLE(GetAnimatedPositionByTreeIndex);
API_CALLABLE(GetAnimatedRotationByTreeIndex);
API_CALLABLE(GetAnimatedModelRootPosition);
API_CALLABLE(SetPartImmunityBits);
API_CALLABLE(DeleteAnimatedModel);

extern Formation N(formation_lava_bud_1);
extern Formation N(formation_lava_bud_2);

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaPiranha_Anim03,
    STATUS_KEY_STONE,     ANIM_LavaPiranha_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LavaPiranha_Anim0A,
    STATUS_KEY_POISON,    ANIM_LavaPiranha_Anim03,
    STATUS_KEY_STOP,      ANIM_LavaPiranha_Anim00,
    STATUS_KEY_STATIC,    ANIM_LavaPiranha_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LavaPiranha_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LavaPiranha_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LavaPiranha_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_fiery)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaPiranha_Anim04,
    STATUS_KEY_STONE,     ANIM_LavaPiranha_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LavaPiranha_Anim04,
    STATUS_KEY_POISON,    ANIM_LavaPiranha_Anim04,
    STATUS_KEY_STOP,      ANIM_LavaPiranha_Anim00,
    STATUS_KEY_STATIC,    ANIM_LavaPiranha_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LavaPiranha_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LavaPiranha_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LavaPiranha_Anim0C,
    STATUS_END,
};

s32 N(IdleAnimations_wet)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaPiranha_Anim10,
    STATUS_KEY_STOP,      ANIM_LavaPiranha_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,    0,
    ELEMENT_ICE,      0,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(DefenseTable_fiery)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(DefenseTable_wet)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,    0,
    ELEMENT_ICE,      0,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              25,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              25,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               40,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_8 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_LAVA_PIRANHA_PHASE_1,
    .level = 45,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 50, 50 },
    .healthBarOffset = { 20, -10 },
    .statusIconOffset = { 5, 45 },
    .statusTextOffset = { 30, 47 },
};

#include "common/StartRumbleWithParams.inc.c"

enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4,
    VINE_4      = 4,
};

#ifdef SHIFT
extern Addr Vine3Base;
extern Addr Vine2Base;
extern Addr Vine1Base;
extern Addr Vine0Base;
#define VINE_0_BASE (s32) Vine0Base
#define VINE_1_BASE (s32) Vine1Base
#define VINE_2_BASE (s32) Vine2Base
#define VINE_3_BASE (s32) Vine3Base
#else
#define VINE_0_BASE 0x80234000
#define VINE_1_BASE 0x80231000
#define VINE_2_BASE 0x8022E000
#define VINE_3_BASE 0x8022C000
#endif

BSS LavaPiranhaVine N(VineData)[NUM_VINES];
BSS s32 N(VineRenderState);

void N(make_vine_interpolation)(LavaPiranhaVine* vine) {
    Evt dummyEvt;
    Evt* dummyEvtPtr = &dummyEvt;
    s32 args[4];
    s32 count;

    // setup dummy call to LoadPath
    args[0] = 3 * vine->boneCount;      // generate three output samples per input
    args[1] = (s32) &vine->bonePos;     // points
    args[2] = vine->boneCount;          // num vectors
    args[3] = EASING_LINEAR;
    dummyEvtPtr->ptrReadPos = args;
    LoadPath(dummyEvtPtr, 1);

    count = 0;
    do {
        GetNextPathPos(dummyEvtPtr, 1);
        vine->points[count].x = evt_get_float_variable(dummyEvtPtr, LVar1);
        vine->points[count].y = evt_get_float_variable(dummyEvtPtr, LVar2);
        vine->points[count].z = evt_get_float_variable(dummyEvtPtr, LVar3);
        count++;
    } while (dummyEvtPtr->varTable[0] != 0);
    vine->numPoints = count;
}

API_CALLABLE(N(SetVineBonePos)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

    vine->bonePos[jointIdx].x = x;
    vine->bonePos[jointIdx].y = y;
    vine->bonePos[jointIdx].z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineBoneRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 rx = evt_get_variable(script, *args++);
    s32 ry = evt_get_variable(script, *args++);
    f32 rz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

    vine->boneRot[jointIdx] = rz;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineBoneScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 sx = evt_get_variable(script, *args++);
    s32 sy = evt_get_variable(script, *args++);
    s32 sz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vine = &N(VineData)[vineIdx];

    // do nothing
    return ApiStatus_DONE2;
}

void func_8021835C_59EA3C(void* data) {
    Vtx_t* vtxBuffer;
    Vtx_t* vtx;

    f32 boneLength;
    s32 boneCount;

    f32 angle;
    f32 nextAngle;
    f32 curAngle1;
    f32 curAngle2;

    f32 alphaCoord;
    f32 alphaFrac;
    s32 nearest;

    s32 numPoints;
    s32 i, j;

    f32 deltaX, deltaY;
    f32 posX, posY, posZ;

    if (N(VineRenderState) == -1) {
        return;
    }

    if (N(VineRenderState) == 0) {
        for (i = 0; i < NUM_VINES; i++) {
            LavaPiranhaVine* vine = &N(VineData)[i];

            switch (i) {
                default:
                    return;
                case 0:
                    boneCount = 9;
                    boneLength = 10.0f;
                    break;
                case 1:
                    boneCount = 7;
                    boneLength = 8.0f;
                    break;
                case 2:
                    boneCount = 7;
                    boneLength = 8.0f;
                    break;
                case 3:
                    boneCount = 5;
                    boneLength = 8.0f;
                    break;
            }

            vine->boneCount = boneCount;
            vine->boneLength = boneLength;

            for (j = 0; j < boneCount; j++) {
                if (j == (boneCount - 1)) {
                    vine->boneRot[j] += 90.0f;
                } else {
                    curAngle1 = vine->boneRot[j];
                    nextAngle = vine->boneRot[j + 1];
                    if (nextAngle - curAngle1 > 180.0f) {
                        curAngle1 += 360.0f;
                    } else if (nextAngle - curAngle1 < -180.0f) {
                        nextAngle += 360.0f;
                    }
                    // average cur and next angles
                    vine->boneRot[j] = ((curAngle1 + nextAngle) / 2.0) + 90.0;
                }
            }

            N(make_vine_interpolation)(vine);
        }

        N(VineRenderState) = 1;
    }

    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, D_8021CF40_5A3620);

    for (i = 0; i < NUM_VINES; i++) {
        LavaPiranhaVine* vine = &N(VineData)[i];

        boneLength = vine->boneLength;
        boneCount = vine->boneCount;
        numPoints = vine->numPoints;

        // we'll build the vertex data and place it in the display list, so jump forward
        // here and leave space behind for the gSPBranchList command followed by two vertices
        // for each point in numPoints

        vtxBuffer = (Vtx_t*)(gMainGfxPos + 1);
        gSPBranchList(gMainGfxPos, &gMainGfxPos[1 + 2 * (2 * numPoints)]);
        vtx = (Vtx_t*) (++gMainGfxPos);
        gMainGfxPos = &gMainGfxPos[2 * (2 * numPoints)];

        for (j = 0; j < numPoints; j++) {
            posX = vine->points[j].x;
            posY = vine->points[j].y;
            posZ = vine->points[j].z;

            alphaCoord = ((f32) j * boneCount) / numPoints;
            nearest = (s32) alphaCoord;
            alphaFrac = alphaCoord - (f32)nearest;

            if (nearest + 1 >= boneCount) {
                angle = vine->boneRot[boneCount - 1];
            } else {
                curAngle2 = vine->boneRot[nearest];
                nextAngle = vine->boneRot[nearest + 1];
                if (nextAngle - curAngle2 > 180.0f) {
                    nextAngle -= 360.0f;
                }
                if (nextAngle - curAngle2 < -180.0f) {
                    nextAngle += 360.0f;
                }
                angle = ((nextAngle - curAngle2) * alphaFrac) + curAngle2;
            }

            deltaX =  sin_deg(angle) * boneLength;
            deltaY = -cos_deg(angle) * boneLength;

            vtx->ob[0] = posX + deltaX;
            vtx->ob[1] = posY + deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;
            vtx->cn[2] = j * 30;
            vtx++;

            vtx->ob[0] = posX - deltaX;
            vtx->ob[1] = posY - deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0x400;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;
            vtx->cn[2] = j * 30;
            vtx++;
        }

        for (j = 0; j < numPoints - 1; j++) {
            gSPVertex(gMainGfxPos++, &vtxBuffer[2*j], 4, 0);
            gSP2Triangles(gMainGfxPos++, 1, 0, 2, 0, 1, 2, 3, 0);
        }
    }

    gDPPipeSync(gMainGfxPos++);
}

void N(worker_render_piranha_vines)(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &func_8021835C_59EA3C;
    renderTask.appendGfxArg = 0;
    renderTask.dist = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

API_CALLABLE(N(MarkVineInterpolationDirty)) {
    N(VineRenderState) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateVineRenderer)) {
    N(VineRenderState) = -1;
    create_worker_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}

static s32 N(unused);
static s32 N(unusedArray)[64];

EvtScript N(init) = {
    EVT_USE_ARRAY(N(unusedArray))
    EVT_CALL(EnableGroup, 23, TRUE)
    EVT_CALL(EnableGroup, 28, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_SET(LVar0, 30)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaPiranha_Anim03)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaPiranha_Anim09)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 61, 61, 0)
    EVT_CALL(LoadAnimatedModel, VINE_0, EVT_PTR(N(AnimModel_MainHeadVine)))
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 0, 0, 0)
    EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_1, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
    EVT_CALL(LoadBattleDmaData, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 0, 0, 0)
    EVT_CALL(SetAnimatorFlags, VINE_1, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_2, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
    EVT_CALL(LoadBattleDmaData, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 50, 14, 20)
    EVT_CALL(SetAnimatorFlags, VINE_2, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(LoadAnimatedModel, VINE_3, EVT_PTR(N(AnimModel_ExtraVine)))
    EVT_CALL(OverrideBattleDmaDest, VINE_3_BASE)
    EVT_CALL(LoadBattleDmaData, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 0, 0, 3)
    EVT_CALL(SetAnimatorFlags, VINE_3, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_lava_bud_1)), FALSE)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_lava_bud_2)), FALSE)
    EVT_WAIT(2)
    EVT_EXEC(N(initVines))
    EVT_CALL(CreateNpc, NPC_BTL_COMPANION, ANIM_BattleKolorado_Idle)
    EVT_CALL(SetNpcYaw, NPC_BTL_COMPANION, 90)
    EVT_CALL(SetNpcPos, NPC_BTL_COMPANION, -300, 0, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(ForceHomePos, ACTOR_ENEMY1, 57, 57, 0)
    EVT_CALL(ForceHomePos, ACTOR_ENEMY2, 107, 71, 20)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY1)
    EVT_CALL(HPBarToHome, ACTOR_ENEMY2)
    EVT_CALL(N(CreateVineRenderer))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 12, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_GE(LVar0, 3)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_SET(LVar0, 30)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 1)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_LABEL(99)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_END)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
                EVT_IF_NOT_FLAG(LVar0, 0x1)
                    EVT_BITWISE_OR_CONST(LVar0, 0x1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
                    EVT_EXEC_WAIT(N(spawnColorado))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(spawnColorado) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_BTL_COMPANION, -1, -1, 0, MSG_CH5_0104)
    EVT_THREAD
        EVT_LOOP(9)
            EVT_CALL(PlaySoundAtNpc, NPC_BTL_COMPANION, SOUND_20BA, SOUND_SPACE_MODE_0)
            EVT_WAIT(2)
            EVT_CALL(PlaySoundAtNpc, NPC_BTL_COMPANION, SOUND_3B4, SOUND_SPACE_MODE_0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_BattleKolorado_WalkSad)
    EVT_CALL(SetNpcAnimationSpeed, NPC_BTL_COMPANION, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcSpeed, NPC_BTL_COMPANION, EVT_FLOAT(10.0))
    EVT_CALL(NpcMoveTo, NPC_BTL_COMPANION, 70, 0, 0)
    EVT_CALL(PlaySoundAtNpc, NPC_BTL_COMPANION, SOUND_E8, SOUND_SPACE_MODE_0)
    EVT_CALL(SetNpcAnimationSpeed, NPC_BTL_COMPANION, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcJumpscale, NPC_BTL_COMPANION, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_BattleKolorado_Injured)
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_BTL_COMPANION, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 20, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_BTL_COMPANION, 70, 180, 0, 20)
    EVT_CALL(SpeakToPlayer, NPC_BTL_COMPANION, -1, -1, 0, MSG_CH5_0105)
    EVT_CALL(SetNpcYaw, NPC_BTL_COMPANION, 270)
    EVT_CALL(SetNpcPos, NPC_BTL_COMPANION, 50, 180, 0)
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_BTL_COMPANION, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 20, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcJump0, NPC_BTL_COMPANION, 50, 0, 0, 20)
    EVT_CALL(NpcJump0, NPC_BTL_COMPANION, 50, 0, 0, 6)
    EVT_CALL(NpcJump0, NPC_BTL_COMPANION, 50, 0, 0, 3)
    EVT_WAIT(8)
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_BattleKolorado_Hurt)
    EVT_CALL(SetNpcJumpscale, NPC_BTL_COMPANION, EVT_FLOAT(0.7))
    EVT_CALL(NpcJump0, NPC_BTL_COMPANION, 50, 0, 0, 12)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtNpc, NPC_BTL_COMPANION, SOUND_20BA, SOUND_SPACE_MODE_0)
            EVT_WAIT(2)
            EVT_CALL(PlaySoundAtNpc, NPC_BTL_COMPANION, SOUND_3B4, SOUND_SPACE_MODE_0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_BattleKolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_BTL_COMPANION, EVT_FLOAT(8.0))
    EVT_CALL(NpcMoveTo, NPC_BTL_COMPANION, -60, 0, 0)
    EVT_CALL(SpeakToPlayer, NPC_BTL_COMPANION, ANIM_BattleKolorado_Shout, ANIM_BattleKolorado_ShoutStill, 5, MSG_CH5_0106)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_174)
    EVT_CALL(SetNpcAnimation, NPC_BTL_COMPANION, ANIM_BattleKolorado_Run)
    EVT_CALL(SetNpcSpeed, NPC_BTL_COMPANION, EVT_FLOAT(6.0))
    EVT_CALL(NpcMoveTo, NPC_BTL_COMPANION, -300, 0, 0)
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetFlamePosition)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flameData = effect->data.flame;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    f32 angle = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);
    s32 offsetY = evt_get_variable(script, *args++);
    s32 unk_10 = evt_get_variable(script, *args++);

    flameData->pos.x = posX - cos_deg(angle) * radius;
    flameData->pos.y = (posY + offsetY) - sin_deg(angle) * radius;
    flameData->unk_10 = unk_10 * 0.01f;
    return ApiStatus_DONE2;
}

EvtScript N(initVines) = {
    EVT_USE_ARRAY(N(unusedArray))
    EVT_LABEL(0)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_ENEMY0, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_ENEMY0, PRT_MAIN, LVar0, 0, LVar2)
    EVT_CALL(N(MarkVineInterpolationDirty))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
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
    EVT_CALL(SetPartPos, ACTOR_ENEMY1, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_CALL(SetPartPos, ACTOR_ENEMY1, PRT_2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_ENEMY1, PRT_MAIN, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
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
    EVT_CALL(SetPartPos, ACTOR_ENEMY2, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_ENEMY2, PRT_2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_ENEMY2, PRT_MAIN, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar1, LVar2, LVar3)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar4, LVar5, LVar6)
        EVT_SET(LVar7, 30)
        EVT_SET(LVar8, -30)
        EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar9)
        EVT_CALL(N(SetFlamePosition), LVar0, LVar1, LVar2, LVar6, LVar7, LVar8, LVar9)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 6, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar1, LVar2, LVar3)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar4, LVar5, LVar6)
        EVT_SET(LVar7, 10)
        EVT_SET(LVar8, -15)
        EVT_CALL(GetActorVar, ACTOR_ENEMY1, 10, LVar9)
        EVT_CALL(N(SetFlamePosition), LVar0, LVar1, LVar2, LVar6, LVar7, LVar8, LVar9)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY2, 6, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar1, LVar2, LVar3)
        EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar4, LVar5, LVar6)
        EVT_SET(LVar7, 10)
        EVT_SET(LVar8, -15)
        EVT_CALL(GetActorVar, ACTOR_ENEMY2, 10, LVar9)
        EVT_CALL(N(SetFlamePosition), LVar0, LVar1, LVar2, LVar6, LVar7, LVar8, LVar9)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(onComboHit))
            EVT_EXEC_WAIT(N(playHitAnimation))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(playHitAnimation))
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onBurnHit))
            EVT_ELSE
                EVT_EXEC_WAIT(N(onHit))
                EVT_EXEC_WAIT(N(playHitAnimation))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
            EVT_EXEC_WAIT(N(playHitAnimation))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaPiranha_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onComboHit))
                EVT_EXEC_WAIT(N(playHitAnimation))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onHit))
                EVT_EXEC_WAIT(N(playHitAnimation))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LavaPiranha_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ForceHomePos, ACTOR_SELF, 61, 61, 0)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_CALL(ForceHomePos, ACTOR_SELF, 61, 61, 0)
        EVT_ELSE
            EVT_CALL(ForceHomePos, ACTOR_SELF, 83, 67, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STOP)
        EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 1)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onBurnHit) = {
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar2)
        EVT_IF_EQ(LVar2, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_SET(LVar0, ACTOR_ENEMY0)
        EVT_EXEC_WAIT(N(ignite))
        EVT_LABEL(10)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 14)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaPiranha_Anim03)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaPiranha_Anim09)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_2, EVT_PTR(N(DefenseTable_fiery)))
            EVT_THREAD
                EVT_WAIT(14)
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 0)
                EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(attackFlameSpew))
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_EXEC_WAIT(N(attackFireStream))
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 11, LVar0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 11, LVar0)
                EVT_IF_LE(LVar0, 0)
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, 80, 70, 0)
                    EVT_CALL(SetBattleCamZoom, 300)
                    EVT_CALL(SetBattleCamOffsetZ, 30)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_WAIT(30)
                    EVT_LOOP(10)
                        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                        EVT_CALL(LoadBattleDmaData, 1)
                        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
                        EVT_WAIT(4)
                    EVT_END_LOOP
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3BB)
                    EVT_SET(LVar0, ACTOR_ENEMY0)
                    EVT_EXEC_WAIT(N(ignite))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim04)
                    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                    EVT_CALL(LoadBattleDmaData, 14)
                    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
                    EVT_WAIT(14)
                    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                    EVT_CALL(LoadBattleDmaData, 0)
                    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Vec3i N(lava_bud_pos) = { 260, 0, 0 };

Formation N(formation_lava_bud_1) = {
    ACTOR_BY_POS(A(lava_bud), N(lava_bud_pos), 80, 1),
};

Formation N(formation_lava_bud_2) = {
    ACTOR_BY_POS(A(lava_bud), N(lava_bud_pos), 70, 2, 50, 14, 20),
};

EvtScript N(attackFlameSpew) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 80, 70, 0)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(MoveBattleCamOver, 45)
        EVT_WAIT(57)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 15)
    EVT_END_THREAD
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 2)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_WAIT(14)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim05)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C1)
    EVT_WAIT(45)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim06)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 50)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, -10)
    EVT_PLAY_EFFECT(EFFECT_63, 1, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 20, 20, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C3)
    EVT_WAIT(19)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, LVar3, 0, LVar5, 50, 50, EVT_FLOAT(1.0), 40, 55, EVT_FLOAT(1.0), EVT_FLOAT(1.0), 0)
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 3)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_FIRE, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim03)
            EVT_WAIT(19)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 0)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim03)
            EVT_WAIT(19)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 0)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_IF_EQ(LVarF, 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackFireStream) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 80, 70, 0)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(MoveBattleCamOver, 45)
        EVT_WAIT(54)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 15)
    EVT_END_THREAD
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 2)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_WAIT(14)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim0E)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C1)
    EVT_WAIT(45)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim08)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, -10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_PLAY_EFFECT(EFFECT_63, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 16, 40, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C4)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(24)
        EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, LVar3, 0, LVar5, 50, 50, EVT_FLOAT(1.0), 40, 55, EVT_FLOAT(1.0), EVT_FLOAT(1.0), 0)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_FIRE, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(20)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 3)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim07)
            EVT_WAIT(19)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim04)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 0)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(20)
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 3)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim07)
    EVT_WAIT(19)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim04)
    EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
    EVT_CALL(LoadBattleDmaData, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_IF_EQ(LVarF, 10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern s32 N(updateSongCounter);

API_CALLABLE(N(UpdateSong)) {
    N(updateSongCounter)++;

    // play 'end battle' song
    if (isInitialCall) {
        sfx_play_sound(SOUND_D4);
        bgm_set_song(0, SONG_BATTLE_END, 0, 500, 8);
        return ApiStatus_BLOCK;
    }

    switch (N(updateSongCounter)) {
        case 80:
            // after a short time, stop the 'end battle' song
            bgm_init_music_players();
            return ApiStatus_BLOCK;
        case 340:
            // restart the boss theme with the more intense variation
            bgm_set_song(0, SONG_LAVA_PIRANHA_BATTLE, 1, 500, 8);
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

extern s32 N(sinkPosTableLavaPiranha)[];

API_CALLABLE(N(GetSinkPosLavaPiranha)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, N(sinkPosTableLavaPiranha)[index]);
    return ApiStatus_DONE2;
}

extern s32 N(sinkPosTableLavaBud)[];

API_CALLABLE(N(GetSinkPosLavaBud)) {
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    evt_set_variable(script, outVar, N(sinkPosTableLavaBud)[index]);
    return ApiStatus_DONE2;
}

EvtScript N(onDeath) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_EXEC_WAIT(N(onHit))
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar2)
    EVT_IF_EQ(LVar2, 0)
        EVT_CALL(ClearStatusEffects, ACTOR_SELF)
        EVT_CALL(ClearStatusEffects, ACTOR_ENEMY1)
        EVT_CALL(ClearStatusEffects, ACTOR_ENEMY2)
        EVT_CALL(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CALL(GetActorVar, ACTOR_ENEMY1, 0, LVar0)
        EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CALL(GetActorVar, ACTOR_ENEMY2, 0, LVar0)
        EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CALL(CancelEnemyTurn, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 90, 0)
        EVT_CALL(SetBattleCamZoom, 360)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 240)
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 9)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(OverrideBattleDmaDest, VINE_3_BASE)
        EVT_CALL(LoadBattleDmaData, 35)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_WAIT(10)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_CALL(LoadBattleDmaData, 24)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_WAIT(5)
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_CALL(LoadBattleDmaData, 24)
        EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
        EVT_WAIT(4)
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_3BC)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 119, EVT_FLOAT(0.3))
            EVT_CALL(PlaySound, SOUND_3BC | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 80, 234)
        EVT_CALL(HideHealthBar, ACTOR_SELF)
        EVT_CALL(HideHealthBar, ACTOR_ENEMY1)
        EVT_CALL(HideHealthBar, ACTOR_ENEMY2)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim0D)
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 10)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C6)
            EVT_WAIT(35)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 0)
            EVT_LOOP(0)
                EVT_CALL(GetAnimatedModelRootPosition, VINE_0, LVar2, LVar3, LVar4)
                EVT_ADD(LVar3, LVar1)
                EVT_CALL(SetAnimatedModelRootPosition, VINE_0, LVar2, LVar3, LVar4)
                EVT_CALL(N(GetSinkPosLavaPiranha), LVar0, LVar1)
                EVT_ADD(LVar0, 1)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 99)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, PRT_MAIN, ANIM_LavaBud_Anim0D)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_CALL(LoadBattleDmaData, 25)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_THREAD
            EVT_WAIT(45)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 0)
            EVT_LOOP(0)
                EVT_CALL(GetAnimatedModelRootPosition, VINE_1, LVar2, LVar3, LVar4)
                EVT_ADD(LVar3, LVar1)
                EVT_CALL(SetAnimatedModelRootPosition, VINE_1, LVar2, LVar3, LVar4)
                EVT_CALL(N(GetSinkPosLavaBud), LVar0, LVar1)
                EVT_ADD(LVar0, 1)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 99)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_ENEMY2, PRT_MAIN, ANIM_LavaBud_Anim0D)
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_CALL(LoadBattleDmaData, 25)
        EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
        EVT_THREAD
            EVT_WAIT(45)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 0)
            EVT_LOOP(0)
                EVT_CALL(GetAnimatedModelRootPosition, VINE_2, LVar2, LVar3, LVar4)
                EVT_ADD(LVar3, LVar1)
                EVT_CALL(SetAnimatedModelRootPosition, VINE_2, LVar2, LVar3, LVar4)
                EVT_CALL(N(GetSinkPosLavaBud), LVar0, LVar1)
                EVT_ADD(LVar0, 1)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 99)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(35)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 90, 0)
        EVT_CALL(SetBattleCamZoom, 360)
        EVT_CALL(SetBattleCamOffsetZ, -45)
        EVT_CALL(MoveBattleCamOver, 110)
        EVT_WAIT(60)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 0, -250, 0)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 0, -250, 0)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 0, -250, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, 100, 0, 0)
        EVT_CALL(DropStarPoints, ACTOR_SELF)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
        EVT_CALL(ForceHomePos, ACTOR_SELF, 61, 61, 0)
        EVT_WAIT(65)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 240)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_THREAD
            EVT_CALL(N(UpdateSong))
        EVT_END_THREAD
        EVT_WAIT(80)
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_3BC)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 165, EVT_FLOAT(1.2))
            EVT_CALL(PlaySound, SOUND_3BC | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 80, 300)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_263)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 20, 315, 30, 0, 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 20, 315, 30, 0, 0)
        EVT_WAIT(50)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 90, 0)
        EVT_CALL(SetBattleCamZoom, 360)
        EVT_CALL(SetBattleCamOffsetZ, -60)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(40)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 90, 0)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, -60)
        EVT_CALL(MoveBattleCamOver, 40)
        EVT_WAIT(40)
        EVT_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
            EVT_WAIT(40)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_END_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 30, 90, 0)
        EVT_CALL(SetBattleCamZoom, 460)
        EVT_CALL(SetBattleCamOffsetZ, 0)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_CALL(N(StartRumbleWithParams), 180, 16)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CHILD_THREAD
            EVT_WAIT(50)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 90, 90, 0)
            EVT_CALL(SetBattleCamZoom, 360)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 40)
            EVT_WAIT(85)
        EVT_END_CHILD_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaPiranha_Anim04)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaPiranha_Anim0A)
        EVT_CALL(SetActorVar, ACTOR_ENEMY1, 7, ANIM_LavaBud_Anim04)
        EVT_CALL(SetActorVar, ACTOR_ENEMY1, 8, ANIM_LavaBud_Anim0B)
        EVT_CALL(SetActorVar, ACTOR_ENEMY2, 7, ANIM_LavaBud_Anim04)
        EVT_CALL(SetActorVar, ACTOR_ENEMY2, 8, ANIM_LavaBud_Anim0B)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(A(lava_bud_IdleAnimations_fiery)))
        EVT_CALL(SetIdleAnimations, ACTOR_ENEMY1, PRT_MAIN, EVT_PTR(A(lava_bud_IdleAnimations_fiery)))
        EVT_CALL(SetIdleAnimations, ACTOR_ENEMY2, PRT_MAIN, EVT_PTR(A(lava_bud_IdleAnimations_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_2, EVT_PTR(N(DefenseTable_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_ENEMY1, PRT_MAIN, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_ENEMY1, PRT_2, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_ENEMY2, PRT_MAIN, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
        EVT_CALL(SetDefenseTable, ACTOR_ENEMY2, PRT_2, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
        EVT_CALL(SetPartImmunityBits, ACTOR_SELF, 1, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartImmunityBits, ACTOR_SELF, 2, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartImmunityBits, ACTOR_ENEMY1, 1, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartImmunityBits, ACTOR_ENEMY1, 2, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartImmunityBits, ACTOR_ENEMY2, 1, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartImmunityBits, ACTOR_ENEMY2, 2, ELEMENT_FIRE, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_ENEMY1, PRT_2, ACTOR_PART_FLAG_2000, FALSE)
        EVT_CALL(SetPartFlagBits, ACTOR_ENEMY2, PRT_2, ACTOR_PART_FLAG_2000, FALSE)
        EVT_SET(LVar0, ACTOR_ENEMY0)
        EVT_EXEC_WAIT(N(ignite))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim04)
        EVT_SET(LVar0, ACTOR_ENEMY1)
        EVT_EXEC_WAIT(N(ignite))
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, PRT_MAIN, ANIM_LavaBud_Anim04)
        EVT_SET(LVar0, ACTOR_ENEMY2)
        EVT_EXEC_WAIT(N(ignite))
        EVT_CALL(SetAnimation, ACTOR_ENEMY2, PRT_MAIN, ANIM_LavaBud_Anim04)
        EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_LAVA_PIRANHA_PHASE_2)
        EVT_CALL(SetActorType, ACTOR_ENEMY1, ACTOR_TYPE_LAVA_BUD_PHASE_2)
        EVT_CALL(SetActorType, ACTOR_ENEMY2, ACTOR_TYPE_LAVA_BUD_PHASE_2)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_TYPE_CHANGED, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_TYPE_CHANGED, TRUE)
        EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
        EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
        EVT_CALL(GetEnemyMaxHP, ACTOR_ENEMY1, LVar0)
        EVT_CALL(SetEnemyHP, ACTOR_ENEMY1, LVar0)
        EVT_CALL(GetEnemyMaxHP, ACTOR_ENEMY2, LVar0)
        EVT_CALL(SetEnemyHP, ACTOR_ENEMY2, LVar0)
        EVT_CALL(EnableModel, 78, TRUE)
        EVT_CALL(EnableModel, 79, TRUE)
        EVT_CALL(EnableModel, 80, TRUE)
        EVT_CALL(EnableModel, 81, TRUE)
        EVT_CALL(EnableModel, 82, TRUE)
        EVT_CALL(EnableModel, 83, TRUE)
        EVT_CALL(EnableModel, 84, TRUE)
        EVT_CALL(EnableModel, 85, TRUE)
        EVT_CALL(EnableModel, 87, TRUE)
        EVT_CALL(EnableModel, 88, TRUE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C5)
        EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, 100, 0, 0, 70, 80, EVT_FLOAT(2.5), 80, 55, EVT_FLOAT(2.0), EVT_FLOAT(2.0), 0)
        EVT_CALL(LoadAnimatedModel, VINE_4, EVT_PTR(N(anim1)))
        EVT_CALL(PlayModelAnimation, VINE_4, EVT_PTR(N(anim1_8021A364)))
        EVT_CALL(SetAnimatedModelRootPosition, VINE_4, 0, 0, 0)
        EVT_CALL(EnableGroup, 23, FALSE)
        EVT_CALL(EnableGroup, 28, TRUE)
        EVT_THREAD
            EVT_WAIT(45)
            EVT_CALL(DeleteAnimatedModel, 4)
        EVT_END_THREAD
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 12)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 50, 14, 20)
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_CALL(LoadBattleDmaData, 28)
        EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
        EVT_WAIT(10)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 0, 0, 0)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_CALL(LoadBattleDmaData, 28)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_WAIT(45)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 0, 0, 0)
        EVT_CALL(OverrideBattleDmaDest, VINE_3_BASE)
        EVT_CALL(LoadBattleDmaData, 36)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 0)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim0E)
        EVT_WAIT(5)
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_CALL(LoadBattleDmaData, 31)
        EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
        EVT_WAIT(10)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_CALL(LoadBattleDmaData, 31)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_WAIT(30)
        EVT_CALL(OverrideBattleDmaDest, VINE_3_BASE)
        EVT_CALL(LoadBattleDmaData, 34)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_CALL(GetEnemyMaxHP, ACTOR_ENEMY1, LVar0)
        EVT_CALL(SetEnemyHP, ACTOR_ENEMY1, LVar0)
        EVT_CALL(GetEnemyMaxHP, ACTOR_ENEMY2, LVar0)
        EVT_CALL(SetEnemyHP, ACTOR_ENEMY2, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_ELSE
        EVT_CALL(HideHealthBar, ACTOR_ENEMY1)
        EVT_CALL(HideHealthBar, ACTOR_ENEMY2)
        EVT_SET(LVar0, ACTOR_ENEMY3)
        EVT_EXEC_WAIT(N(handleBudDeath))
        EVT_SET(LVar0, ACTOR_ENEMY4)
        EVT_EXEC_WAIT(N(handleBudDeath))
        EVT_CALL(OverrideBattleDmaDest, VINE_3_BASE)
        EVT_CALL(LoadBattleDmaData, 35)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_THREAD
            EVT_CALL(PlaySound, SOUND_3BC)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 100, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 8, EVT_FLOAT(0.2))
            EVT_CALL(PlaySound, SOUND_3BC | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 80, 216)
        EVT_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3CC)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 8)
                EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 9)
                EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_END_IF
            EVT_WAIT(19)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 10)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, 105, 60, 2, 80, 60, EVT_FLOAT(1.8), 90, 100, EVT_FLOAT(1.5), EVT_FLOAT(1.5), 0)
            EVT_END_IF
            EVT_WAIT(121)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3CD)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim0A)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 11)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
            EVT_SET(LVar1, 100)
            EVT_LOOP(50)
                EVT_SUB(LVar1, 2)
                EVT_SETF(LVar2, LVar0)
                EVT_MULF(LVar2, LVar1)
                EVT_MULF(LVar2, EVT_FLOAT(0.01))
                EVT_CALL(SetActorVar, ACTOR_SELF, 10, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 5, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_CALL(LoadBattleDmaData, 23)
                EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_CALL(LoadBattleDmaData, 24)
                EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
            EVT_END_IF
            EVT_WAIT(19)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
            EVT_CALL(LoadBattleDmaData, 25)
            EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 5, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, 67, 30, 2, 50, 40, EVT_FLOAT(1.3), 30, 70, EVT_FLOAT(1.2), EVT_FLOAT(1.2), 0)
            EVT_END_IF
            EVT_WAIT(96)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
            EVT_CALL(LoadBattleDmaData, 26)
            EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, 10, LVar0)
            EVT_SET(LVar1, 100)
            EVT_LOOP(50)
                EVT_SUB(LVar1, 2)
                EVT_SETF(LVar2, LVar0)
                EVT_MULF(LVar2, LVar1)
                EVT_MULF(LVar2, EVT_FLOAT(0.01))
                EVT_CALL(SetActorVar, ACTOR_ENEMY1, 10, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_ENEMY2, 5, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_CALL(LoadBattleDmaData, 23)
                EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_CALL(LoadBattleDmaData, 24)
                EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
            EVT_END_IF
            EVT_WAIT(19)
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
            EVT_CALL(LoadBattleDmaData, 25)
            EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
            EVT_CALL(GetActorVar, ACTOR_ENEMY2, 5, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, 120, 35, 5, 50, 40, EVT_FLOAT(1.3), 30, 70, EVT_FLOAT(1.2), EVT_FLOAT(1.2), 0)
            EVT_END_IF
            EVT_WAIT(96)
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
            EVT_CALL(LoadBattleDmaData, 26)
            EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_ENEMY2, 10, LVar0)
            EVT_SET(LVar1, 100)
            EVT_LOOP(50)
                EVT_SUB(LVar1, 2)
                EVT_SETF(LVar2, LVar0)
                EVT_MULF(LVar2, LVar1)
                EVT_MULF(LVar2, EVT_FLOAT(0.01))
                EVT_CALL(SetActorVar, ACTOR_ENEMY2, 10, LVar2)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(150)
            EVT_SET(LVar0, 14)
            EVT_LOOP(14)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 50, LVar0, 20)
                EVT_WAIT(2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_WAIT(212)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EA)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaPiranha_Anim0F)
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, PRT_MAIN, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetAnimation, ACTOR_ENEMY2, PRT_MAIN, ANIM_LavaBud_Anim0F)
        EVT_PLAY_EFFECT(EFFECT_SHOCKWAVE, 0, -60, 0, 2, 0)
        EVT_THREAD
            EVT_CALL(N(StartRumbleWithParams), 180, 16)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
        EVT_END_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetActorPos, ACTOR_SELF, -60, 0, 0)
        EVT_CALL(DropStarPoints, ACTOR_SELF)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
        EVT_WAIT(15)
        EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
            EVT_CALL(RemoveEffect, LVar0)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_ENEMY1, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, 0)
            EVT_CALL(RemoveEffect, LVar0)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_ENEMY2, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 6, 0)
            EVT_CALL(RemoveEffect, LVar0)
        EVT_END_IF
        EVT_WAIT(5)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_ENEMY0, PRT_2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(updateSongCounter) = 0;

EvtScript N(handleBudDeath) = {
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetAnimation, LVar0, 1, ANIM_PetitPiranha_Anim03)
        EVT_WAIT(10)
        EVT_SET(LVar2, 0)
        EVT_LOOP(24)
            EVT_CALL(SetPartRotation, LVar0, 1, 0, LVar2, 0)
            EVT_ADD(LVar2, 30)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, LVar0, LVar3, LVar4, LVar5)
        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar3, LVar4, LVar5, 0, 0, 0, 0, 0)
        EVT_SET(LVar3, 0)
        EVT_LOOP(12)
            EVT_CALL(SetPartRotation, LVar0, 1, LVar3, LVar2, 0)
            EVT_ADD(LVar3, 8)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(RemoveActor, LVar0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

s32 N(sinkPosTableLavaPiranha)[] = {
    -1,  0, -1, -1, -1, -1, -2, -1, -2, -2, -2, -2, -3, -2, -3, -3, -3, -3, -3, -3, -4, -4, -3, -4, -4, -4, -5, -4, -4,
    -5, -5, -5, -4, -5, -6, -5, -5, -6, -5, -6, -5, -6, -6, -6, -6, -6, -7, -6, -6, -7, -6, -7, -6, 99
};
s32 N(sinkPosTableLavaBud)[] = {
    -1,  0, -1,  0, -1, -1, -1, -2, -1, -2, -2, -1, -3, -2, -2, -3, -2, -3, -3, -3, -3, -4, -3, -4, -4, -3, -5, -4, -4,
    -3, -5, -5, -5, -5, -5, -5, -5, -6, -5, -6, -6, -6, -6, -6, -7, -6, -7, -7, -7, -7, -7, 99,
};

API_CALLABLE(N(GetFlamePosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 posY = evt_get_variable(script, *args++);
    f32 angle = evt_get_variable(script, *args++);
    s32 radius = evt_get_variable(script, *args++);
    s32 deltaY = evt_get_variable(script, *args++);

    posX = posX - cos_deg(angle) * radius;
    posY = (posY + deltaY) - sin_deg(angle) * radius;
    evt_set_variable(script, *args++, posX);
    evt_set_variable(script, *args++, posY);
    return ApiStatus_DONE2;
}

EvtScript N(ignite) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ACTOR_ENEMY1)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 10, 35)
            EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar1, LVar2, LVar3)
            EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar4, LVar5, LVar6)
            EVT_SET(LVar7, 10)
            EVT_SET(LVar8, -15)
            EVT_CALL(N(GetFlamePosition), LVar1, LVar2, LVar6, LVar7, LVar8, LVar3, LVar4)
            EVT_CALL(GetPartOffset, ACTOR_ENEMY1, PRT_MAIN, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_PLAY_EFFECT(EFFECT_FLAME, 1, LVar3, LVar4, LVar2, EVT_FLOAT(0.3), LVarA, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 6, LVarA)
            EVT_CALL(SetIdleAnimations, ACTOR_ENEMY1, PRT_MAIN, EVT_PTR(A(lava_bud_IdleAnimations_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY1, PRT_MAIN, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY1, PRT_2, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY1, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY1, PRT_2, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 7, ANIM_LavaBud_Anim04)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 8, ANIM_LavaBud_Anim0B)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 5, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY1, PRT_2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_ENEMY1, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
        EVT_CASE_EQ(ACTOR_ENEMY2)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 10, 35)
            EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar1, LVar2, LVar3)
            EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar4, LVar5, LVar6)
            EVT_SET(LVar7, 10)
            EVT_SET(LVar8, -15)
            EVT_CALL(N(GetFlamePosition), LVar1, LVar2, LVar6, LVar7, LVar8, LVar3, LVar4)
            EVT_CALL(GetPartOffset, ACTOR_ENEMY2, PRT_MAIN, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_PLAY_EFFECT(EFFECT_FLAME, 1, LVar3, LVar4, LVar2, EVT_FLOAT(0.3), LVarA, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 6, LVarA)
            EVT_CALL(SetIdleAnimations, ACTOR_ENEMY2, PRT_MAIN, EVT_PTR(A(lava_bud_IdleAnimations_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY2, PRT_MAIN, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY2, PRT_2, EVT_PTR(A(lava_bud_DefenseTable_fiery)))
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY2, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY2, PRT_2, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 7, ANIM_LavaBud_Anim04)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 8, ANIM_LavaBud_Anim0B)
            EVT_CALL(SetActorVar, ACTOR_ENEMY2, 5, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY2, PRT_2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_ENEMY2, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
        EVT_CASE_DEFAULT
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 10, 70)
            EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar1, LVar2, LVar3)
            EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar4, LVar5, LVar6)
            EVT_SET(LVar7, 30)
            EVT_SET(LVar8, -30)
            EVT_CALL(N(GetFlamePosition), LVar1, LVar2, LVar6, LVar7, LVar8, LVar3, LVar4)
            EVT_CALL(GetPartOffset, ACTOR_ENEMY0, PRT_MAIN, LVar0, LVar1, LVar2)
            EVT_SUB(LVar2, 3)
            EVT_PLAY_EFFECT(EFFECT_FLAME, 1, LVar3, LVar4, LVar2, EVT_FLOAT(0.7), LVarA, 0)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 6, LVarA)
            EVT_CALL(SetIdleAnimations, ACTOR_ENEMY0, PRT_MAIN, EVT_PTR(N(IdleAnimations_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY0, PRT_MAIN, EVT_PTR(N(DefenseTable_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_ENEMY0, PRT_2, EVT_PTR(N(DefenseTable_fiery)))
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY0, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_ENEMY0, PRT_2, ACTOR_EVENT_FLAG_FIREY, TRUE)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 7, ANIM_LavaPiranha_Anim04)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 8, ANIM_LavaPiranha_Anim0A)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 5, 1)
            EVT_CALL(ForceHomePos, ACTOR_SELF, 61, 61, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onComboHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
        EVT_IF_LT(LVar0, 4)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 5)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 4)
        EVT_END_IF
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_WAIT(29)
        EVT_WAIT(14)
    EVT_ELSE
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
        EVT_IF_LT(LVar0, 4)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 7)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 6)
        EVT_END_IF
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_WAIT(29)
        EVT_WAIT(14)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_EXEC_WAIT(N(doOnHit))
    EVT_RETURN
    EVT_END
};

EvtScript N(doOnHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
        EVT_IF_LT(LVar0, 4)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 7)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 6)
        EVT_END_IF
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_WAIT(29)
        EVT_WAIT(14)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_FLAG(LVarE, DAMAGE_TYPE_WATER | DAMAGE_TYPE_ICE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
            EVT_IF_LT(LVar0, 4)
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 5)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 4)
            EVT_END_IF
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_WAIT(29)
            EVT_WAIT(14)
        EVT_ELSE
            EVT_CALL(SetActorVar, ACTOR_SELF, 11, 2)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 6)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_CALL(RemoveEffect, LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 50, 0)
            EVT_END_IF
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_wet)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_wet)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_2, EVT_PTR(N(DefenseTable_wet)))
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaPiranha_Anim0A)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaPiranha_Anim09)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_FIREY, FALSE)
            EVT_WAIT(29)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C8)
            EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
            EVT_CALL(LoadBattleDmaData, 13)
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_WAIT(14)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
            EVT_IF_LT(LVar0, 4)
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 5)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 4)
            EVT_END_IF
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_WAIT(29)
            EVT_WAIT(14)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
            EVT_IF_LT(LVar0, 4)
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 7)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
                EVT_CALL(LoadBattleDmaData, 6)
            EVT_END_IF
            EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
            EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, 80, 50, 0, 60, 50, EVT_FLOAT(1.5), 36, 42, EVT_FLOAT(0.8), EVT_FLOAT(0.8), 0)
            EVT_WAIT(29)
            EVT_WAIT(14)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(playHitAnimation) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 0)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 1)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_ELSE
        EVT_CALL(OverrideBattleDmaDest, VINE_0_BASE)
        EVT_CALL(LoadBattleDmaData, 0)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

