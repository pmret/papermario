#include "kzn_19.h"
#include "ld_addrs.h"
#include "sprite/player.h"
#include "include_asset.h"

#include "world/common/npc/Kolorado.h"
#include "world/common/npc/StarSpirit.h"
#include "world/common/enemy/LavaPiranha.h"

enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4
};

#ifdef SHIFT
extern Addr D_80200000;
extern Addr D_80204000;
extern Addr D_80207000;
extern Addr D_8020A000;
#define VINE_0_BASE (s32) &D_80200000
#define VINE_1_BASE (s32) &D_80204000
#define VINE_2_BASE (s32) &D_80207000
#define VINE_3_BASE (s32) &D_8020A000
#else
#define VINE_0_BASE 0x80200000
#define VINE_1_BASE 0x80204000
#define VINE_2_BASE 0x80207000
#define VINE_3_BASE 0x8020A000
#endif

#include "./kzn_19_anim1.c"
#include "./kzn_19_anim2.c"
#include "./kzn_19_anim3.c"

INCLUDE_IMG("world/lava_piranha/vine.png", dead_kzn_19_lava_piranha_vine_img);
INCLUDE_PAL("world/lava_piranha/vine.pal", dead_kzn_19_lava_piranha_vine_pal);

#include "world/lava_piranha/vine.gfx.inc.c"
#define DEAD_ROM_OFFSET (0x211EB0)

#define PIRANHA_DMA_ENTRY(name) \
    (s32) world_model_anim_kzn_##name##_ROM_START + DEAD_ROM_OFFSET,\
    (s32) world_model_anim_kzn_##name##_ROM_END + DEAD_ROM_OFFSET,\
    (s32) world_model_anim_kzn_##name##_VRAM

s32 N(VineAnimationsDmaTable)[] = {
    PIRANHA_DMA_ENTRY(00),
    PIRANHA_DMA_ENTRY(01),
    PIRANHA_DMA_ENTRY(02),
    PIRANHA_DMA_ENTRY(03),
    PIRANHA_DMA_ENTRY(04),
    PIRANHA_DMA_ENTRY(05),
    PIRANHA_DMA_ENTRY(06),
    PIRANHA_DMA_ENTRY(07),
    PIRANHA_DMA_ENTRY(08),
    PIRANHA_DMA_ENTRY(09),
    PIRANHA_DMA_ENTRY(0A),
    PIRANHA_DMA_ENTRY(0B),
    PIRANHA_DMA_ENTRY(0C),
    PIRANHA_DMA_ENTRY(0D),
    PIRANHA_DMA_ENTRY(0E),
    PIRANHA_DMA_ENTRY(0F),
    PIRANHA_DMA_ENTRY(10),
    PIRANHA_DMA_ENTRY(11),
    PIRANHA_DMA_ENTRY(12),
    PIRANHA_DMA_ENTRY(13),
    PIRANHA_DMA_ENTRY(14),
    PIRANHA_DMA_ENTRY(15),
    PIRANHA_DMA_ENTRY(16),
    PIRANHA_DMA_ENTRY(17),
    PIRANHA_DMA_ENTRY(18),
    PIRANHA_DMA_ENTRY(19),
    PIRANHA_DMA_ENTRY(1A),
    PIRANHA_DMA_ENTRY(1B),
    PIRANHA_DMA_ENTRY(1C),
    PIRANHA_DMA_ENTRY(1D),
    PIRANHA_DMA_ENTRY(1E),
    PIRANHA_DMA_ENTRY(1F),
    PIRANHA_DMA_ENTRY(20),
    PIRANHA_DMA_ENTRY(21),
    PIRANHA_DMA_ENTRY(22),
    PIRANHA_DMA_ENTRY(23),
    PIRANHA_DMA_ENTRY(24),
};

BSS s32 N(VineRenderState);

MAP_STATIC_PAD(1, unk_static_pad);

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
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

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
    s32 rz = evt_get_variable(script, *args++);
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

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
    LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &vines[vineIdx];

    // do nothing
    return ApiStatus_DONE2;
}

void N(appendGfx_piranha_vines)(void* data) {
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
            LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
            LavaPiranhaVine* vine = &vines[i];

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
    gSPDisplayList(gMainGfxPos++, N(lava_piranha_vine_gfx));

    for (i = 0; i < NUM_VINES; i++) {
        LavaPiranhaVine* vines = (LavaPiranhaVine*) evt_get_variable(NULL, MV_VinesData);
        LavaPiranhaVine* vine = &vines[i];

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

    renderTask.appendGfx = &N(appendGfx_piranha_vines);
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
    LavaPiranhaVine* data = heap_malloc(NUM_VINES * sizeof(*data));
    evt_set_variable(script, MV_VinesData, (s32) data);
    N(VineRenderState) = -1;
    create_worker_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    IfEq(GF_KZN19_KoloradoDeadEnd, FALSE)
        Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 300)
            Wait(1)
            Goto(0)
        EndIf
        Call(DisablePlayerInput, TRUE)
        Call(NpcFacePlayer, NPC_SELF, 4)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0100)
        Set(GF_KZN19_KoloradoDeadEnd, TRUE)
        Call(DisablePlayerInput, FALSE)
        Call(SetSelfVar, 0, 0)
        Label(5)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
        Wait(30)
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
        Wait(30)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 0)
            Goto(5)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Kolorado_Escape) = {
    Label(0)
        IfEq(MV_BossDefeated, FALSE)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Wait(60)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcPos, NPC_SELF, 70, 25, 60)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    Call(SetNpcSpeed, NPC_SELF, Float(4.0))
    Call(NpcMoveTo, NPC_SELF, 170, 0, 0)
    Call(NpcMoveTo, NPC_SELF, 280, 70, 0)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 0, MSG_CH5_0107)
    Call(UseSettingsFrom, CAM_DEFAULT, 450, 25, -20)
    Call(SetPanTarget, CAM_DEFAULT, 450, 25, -20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(NpcMoveTo, NPC_SELF, 535, -60, 0)
    Wait(20)
    Call(SetPanTarget, CAM_DEFAULT, 304, 25, -35)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcAux, NPC_LavaPiranhaHead, 0)
    Wait(10)
    Call(FadeOutMusic, 0, 1500)
    Exec(N(EVS_TrySpawningStarCard))
    Wait(30)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_0101)
    Call(SetSelfVar, 0, 1)
    EVT_LETTER_CHECK(Kolorado)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        Call(GetEntryID, LVar0)
        Switch(LVar0)
            CaseEq(kzn_19_ENTRY_0)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
            CaseEq(kzn_19_ENTRY_1)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_Kolorado_Escape)))
        EndSwitch
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

Vec3f N(FlightPath)[] = {
    {  250.0,    40.0,  -35.0 },
    {  410.0,    30.0,    0.0 },
    {  460.0,    40.0,  -30.0 },
    {  510.0,    50.0,  -72.0 },
    {  540.0,    60.0, -115.0 },
};

EvtScript N(EVS_Misstar_Escape) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, 185, 25, -35)
    Call(SetNpcPos, NPC_PARTNER, 155, 25, -35)
    Call(SetNpcPos, NPC_Misstar, 250, 40, -35)
    Call(UseSettingsFrom, CAM_DEFAULT, 217, 25, -35)
    Call(SetPanTarget, CAM_DEFAULT, 217, 25, -35)
    Call(SetCamDistance, CAM_DEFAULT, 380)
    Call(SetCamPitch, CAM_DEFAULT, Float(12.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Set(AF_KZN_BossRoomFloorBroken, TRUE)
    Call(PlaySound, SOUND_LOOP_RUMBLE)
    Loop(0)
        Wait(1)
        IfNe(AF_KZN_BossRoomFloorBroken, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(InterpPlayerYaw, 90, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Call(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10)
    Call(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_CH5_0109)
    Wait(10)
    Call(SetPanTarget, CAM_DEFAULT, 370, 25, 70)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(InterpNpcYaw, NPC_Misstar, 90, 0)
    Call(LoadPath, 45, Ref(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcPos, NPC_Misstar, NPC_DISPOSE_LOCATION)
    Wait(15)
    Call(ResetCam, CAM_DEFAULT, Float(3.0))
    Set(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

API_CALLABLE(N(LoadAnimationFromTable)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);

    switch (type) {
        case VINE_0:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_0_BASE);
            break;
        case VINE_1:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_1_BASE);
            break;
        case VINE_2:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_2_BASE);
            break;
        case VINE_3:
            dma_copy(
                (u8*) N(VineAnimationsDmaTable)[3 * index + 0],
                (u8*) N(VineAnimationsDmaTable)[3 * index + 1],
                (void*) VINE_3_BASE);
            break;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlayVinesAnim_Emerge) = {
    Thread
        Call(N(LoadAnimationFromTable), VINE_0, 15)
        Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
        Call(SetAnimatedModelRootPosition, VINE_0, 220, 20, -40)
        Call(N(LoadAnimationFromTable), VINE_3, 36)
        Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
        Call(SetAnimatedModelRootPosition, VINE_3, 220, 20, -40)
        Wait(59)
        Call(N(LoadAnimationFromTable), VINE_0, 0)
        Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
        Call(N(LoadAnimationFromTable), VINE_3, 34)
        Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EndThread
    Wait(5)
    Thread
        Call(N(LoadAnimationFromTable), VINE_1, 32)
        Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
        Call(SetAnimatedModelRootPosition, VINE_1, 220, 20, -40)
        Wait(59)
        Call(N(LoadAnimationFromTable), VINE_1, 31)
        Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EndThread
    Wait(7)
    Call(N(LoadAnimationFromTable), VINE_2, 32)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(SetAnimatedModelRootPosition, VINE_2, 270, 34, -20)
    Wait(62)
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Idle) = {
    Call(N(LoadAnimationFromTable), VINE_0, 0)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(N(LoadAnimationFromTable), VINE_1, 31)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(N(LoadAnimationFromTable), VINE_3, 34)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Wait(10)
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Talk) = {
    Call(N(LoadAnimationFromTable), VINE_0, 17)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Return
    End
};

EvtScript N(EVS_PlayVinesAnim_Defeat) = {
    Call(N(LoadAnimationFromTable), VINE_0, 16)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(N(LoadAnimationFromTable), VINE_1, 33)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(N(LoadAnimationFromTable), VINE_2, 33)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(N(LoadAnimationFromTable), VINE_3, 35)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_LavaPiranha) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
        IfGt(LVar0, 150)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(SetMusicTrack, 0, SONG_LAVA_PIRANHA_THEME, 0, 8)
    Call(LoadAnimatedModel, VINE_0, Ref(N(AnimModel_MainHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_0, 0)
    Call(PlayModelAnimation, VINE_0, VINE_0_BASE)
    Call(SetAnimatedModelRootPosition, VINE_0, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_0, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_1, Ref(N(AnimModel_SideHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_1, 31)
    Call(PlayModelAnimation, VINE_1, VINE_1_BASE)
    Call(SetAnimatedModelRootPosition, VINE_1, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_1, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_2, Ref(N(AnimModel_SideHeadVine)))
    Call(N(LoadAnimationFromTable), VINE_2, 31)
    Call(PlayModelAnimation, VINE_2, VINE_2_BASE)
    Call(SetAnimatedModelRootPosition, VINE_2, 270, -100, -20)
    Call(SetAnimatorFlags, VINE_2, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(LoadAnimatedModel, VINE_3, Ref(N(AnimModel_ExtraVine)))
    Call(N(LoadAnimationFromTable), VINE_3, 34)
    Call(PlayModelAnimation, VINE_3, VINE_3_BASE)
    Call(SetAnimatedModelRootPosition, VINE_3, 220, -100, -40)
    Call(SetAnimatorFlags, VINE_3, MODEL_ANIMATOR_FLAG_HIDDEN, 1)
    Call(N(CreateVineRenderer))
    Call(SetSelfVar, 1, 1)
    Call(InterpPlayerYaw, 90, 0)
    Thread
        Wait(15)
        Call(UseSettingsFrom, CAM_DEFAULT, 300, 25, -20)
        Call(SetPanTarget, CAM_DEFAULT, 300, 25, -20)
        Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-9.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(MakeLerp, 0, 40, 80, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_poko, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(InterruptUsePartner)
        Call(SetPlayerSpeed, Float(3.0))
        Call(PlayerMoveTo, 200, -30, 0)
        Call(InterpPlayerYaw, 90, 0)
    EndThread
    Call(PlaySoundAt, SOUND_LAVA_PIRANHA_EMERGE, SOUND_SPACE_DEFAULT, 330, 25, -50)
    Exec(N(EVS_PlayVinesAnim_Emerge))
    Wait(59)
    Thread
        Call(MakeLerp, 40, 0, 80, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, MODEL_poko, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(40)
    Call(UseSettingsFrom, CAM_DEFAULT, 235, 25, -20)
    Call(SetPanTarget, CAM_DEFAULT, 235, 25, -20)
    Call(SetCamDistance, CAM_DEFAULT, Float(420.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(10.0), Float(-10.7))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Exec(N(EVS_PlayVinesAnim_Talk))
    Call(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0102)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 256, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Talk))
    Wait(30)
    Call(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0103)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Talk))
    Wait(10)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    Exec(N(EVS_PlayVinesAnim_Idle))
    Wait(10)
    Call(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    ChildThread
        Set(LVar0, 20)
        Loop(3)
            Call(SetCamDistance, CAM_DEFAULT, Float(250.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar0)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Sub(LVar0, 2)
            Call(SetCamDistance, CAM_DEFAULT, Float(440.0))
            Call(SetCamSpeed, CAM_DEFAULT, LVar0)
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Sub(LVar0, 2)
        EndLoop
    EndChildThread
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_LAVA_PIRANHA_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcAux_LavaPiranha) = {
    Call(GetSelfVar, 0, LVar0)
    UseArray(LVar0)
    Loop(0)
        Call(GetSelfVar, 1, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Label(0)
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    Call(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
    Call(N(MarkVineInterpolationDirty))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 0, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    Add(LVar2, 90)
    Call(N(SetVineBoneRot), VINE_0, 0, LVar0, 0, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 0, 1, 1, 1)
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 1, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 1, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 1, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 2, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 2, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 3, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 3, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 4, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 4, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 5, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 5, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 6, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 6, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 7, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 7, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_0, 8, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_0, 8, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_0, 8, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    Call(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 0, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    Add(LVar2, 90)
    Call(N(SetVineBoneRot), VINE_1, 0, LVar0, 0, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 0, 1, 1, 1)
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
    Sub(LVar2, 2)
    Call(N(SetVineBonePos), VINE_1, 1, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 1, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 1, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 2, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 2, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 3, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 3, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 4, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 4, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 5, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 5, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_1, 6, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_1, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_1, 6, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    Call(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 0, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    Add(LVar2, 90)
    Call(N(SetVineBoneRot), VINE_2, 0, LVar0, 0, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 0, 1, 1, 1)
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
    Sub(LVar2, 2)
    Call(N(SetVineBonePos), VINE_2, 1, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 1, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 1, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 2, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 2, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 3, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 3, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 4, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 4, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 5, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 5, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_2, 6, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_2, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_2, 6, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_3, 0, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_3, 0, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_3, 0, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_3, 1, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_3, 1, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_3, 1, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_3, 2, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_3, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_3, 2, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_3, 3, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_3, 3, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_3, 3, Float(0.714), Float(0.714), Float(1.0))
    Call(GetAnimatedPositionByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBonePos), VINE_3, 4, LVar0, LVar1, LVar2)
    Call(GetAnimatedRotationByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneRot), VINE_3, 4, LVar0, LVar1, LVar2)
    Call(N(SetVineBoneScale), VINE_3, 4, Float(0.714), Float(0.714), Float(1.0))
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_LavaPiranha) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
            Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
            Call(SetPlayerPos, 125, 25, -35)
            Call(SetNpcPos, NPC_PARTNER, 100, 25, -35)
            Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
            Call(UseSettingsFrom, CAM_DEFAULT, 125, 25, -35)
            Call(SetPanTarget, CAM_DEFAULT, 205, 25, -35)
            Call(SetCamDistance, CAM_DEFAULT, 470)
            Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-8.0))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(EnableGroup, MODEL_ato, TRUE)
            Call(EnableGroup, MODEL_naka, TRUE)
            Call(EnableGroup, MODEL_mae, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            Call(PlaySoundAt, SOUND_LAVA_PIRANHA_DEFEAT, SOUND_SPACE_DEFAULT, 330, 25, -50)
            Exec(N(EVS_PlayVinesAnim_Defeat))
            Wait(1)
            Call(SetNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_LavaPiranha)))
            Set(MV_BossDefeated, TRUE)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_LavaPiranha) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kzn_19_ENTRY_1)
        IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
            Call(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
            Call(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
            Call(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
            MallocArray(64, LVar0)
            Call(SetSelfVar, 0, LVar0)
            UseArray(LVar0)
            Call(SetSelfVar, 1, 0)
            Call(BindNpcAux, NPC_SELF, Ref(N(EVS_NpcAux_LavaPiranha)))
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_LavaPiranha)))
            Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_LavaPiranha)))
            Return
        EndIf
    EndIf
    Call(SetNpcPos, NPC_05, NPC_DISPOSE_LOCATION)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_LavaBud) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_LavaBud) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_LavaBud)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { 380.0f, 250.0f, -330.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .settings = &N(NpcSettings_StarSpirit),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = MISSTAR_ANIMS,
    .tattle = MSG_NpcTattle_Misstar,
};

AnimID N(ExtraAnims_LavaPiranha)[] = {
    ANIM_LavaPiranha_Anim03,
    ANIM_LavaPiranha_Anim0E,
    ANIM_LIST_END
};

AnimID N(ExtraAnims_LavaBud)[] = {
    ANIM_LavaBud_Anim03,
    ANIM_LIST_END
};

NpcData N(NpcData_LavaPiranha)[] = {
    {
        .id = NPC_LavaPiranhaHead,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaPiranha),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_HEAD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaPiranha),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_01,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_02,
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_LavaBud),
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_40000,
        .drops = LAVA_PIRANHA_DROPS,
        .animations = LAVA_PIRANHA_BUD_ANIMS,
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
};

NpcGroupList N(BossNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_LavaPiranha), 0x1900, BTL_KZN2_STAGE_06),
    {}
};

NpcGroupList N(EscapeNPCs) = {
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
