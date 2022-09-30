#include "kzn_19.h"

enum {
    VINE_0      = 0,
    VINE_1      = 1,
    VINE_2      = 2,
    VINE_3      = 3,
    NUM_VINES   = 4
};

enum {
    VINE_0_BASE  = 0x80200000,
    VINE_1_BASE  = 0x80204000,
    VINE_2_BASE  = 0x80207000,
    VINE_3_BASE  = 0x8020A000,
};

typedef struct LavaPiranhaVine {
    /* 0x000 */ Vec3f unk_00[9];
    /* 0x06C */ f32 unk_6C[9];
    /* 0x090 */ s32 unk_90;
    /* 0x094 */ f32 unk_94;
    /* 0x098 */ Vec3f points[27];
    /* 0x1DC */ s32 numPoints;
} LavaPiranhaVine;

typedef struct LavaPiranhaVineSet {
    LavaPiranhaVine unk_00[NUM_VINES];
} LavaPiranhaVineSet; // size = 0x780

extern API_CALLABLE(SetAnimatorFlags);
extern API_CALLABLE(GetAnimatedPositionByTreeIndex);
extern API_CALLABLE(GetAnimatedRotationByTreeIndex);

extern EvtScript N(EVS_TryingSpawningStarCard);
extern StaticAnimatorNode* N(AnimModel_MainHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_SideHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_ExtraVine)[];

extern NpcSettings N(NpcSettings_Kolorado);
extern NpcSettings N(NpcSettings_Misstar);
extern NpcSettings N(NpcSettings_LavaPiranhaHead);

#include "./kzn_19_anim1.c"
#include "./kzn_19_anim2.c"
#include "./kzn_19_anim3.c"

s32 N(D_802434D8_C91088)[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 1, 0x11000000, 0, 0, 0, 0, 0, 
    0, 17, 0x21100000, 0, 0, 0, 0, 0, 
    0, 18, 0x22100000, 0, 0, 0, 0, 0, 
    0, 274, 0x22110000, 0, 0, 0, 0, 0, 
    0, 290, 0x22210000, 0, 0, 0, 0, 0, 
    0, 0x00001122, 0x22211000, 0, 0, 0, 0, 0, 
    0, 0x00001222, 0x22221000, 0, 0, 0, 0, 0, 
    0x33333333, 0x33311222, 0x22221133, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x33333333, 0x33312222, 0x22222133, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x33333333, 0x33112222, 0x22222113, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 0x44444444, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x31122222, 0x22222113, 0x33333333, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33122222, 0x22222133, 0x33333333, 
    0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33333333, 0x33112222, 0x22221133, 0x33333333, 
    0, 0, 0, 0, 0, 0x00012222, 0x22221000, 0, 
    0, 0, 0, 0, 0, 0x00011222, 0x22211000, 0, 
    0, 0, 0, 0, 0, 0x00001222, 0x22210000, 0, 
    0, 0, 0, 0, 0, 0x00001122, 0x22110000, 0, 
    0, 0, 0, 0, 0, 290, 0x22100000, 0, 
    0, 0, 0, 0, 0, 274, 0x21100000, 0, 
    0, 0, 0, 0, 0, 17, 0x11000000, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};

s32 N(D_802438D8_C91488)[] = {
    0x014041C1, 0xE7390241, 0x044F0000, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};

Gfx D_80243AD8_C91688[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(
        AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM),
        AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)),
    gsDPSetCombineLERP(PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0),
    gsDPSetPrimColor(0, 0, 255, 160, 160, 0),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, 0x802438D8), //TODO fix pointers
    gsDPLoadTextureTile_4b(0x802434D8, G_IM_FMT_CI, 64, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE),
    gsSPEndDisplayList(),
};

s32 VineAnimationsDmaTable[] = {
    0x007B6690, 0x007B70E0, 0x80234000,
    0x007B5960, 0x007B6690, 0x80234000,
    0x007C4F50, 0x007C7410, 0x80234000, 
    0x007C7410, 0x007C7E50, 0x80234000, 
    0x007B70E0, 0x007B8030, 0x80234000, 
    0x007B8030, 0x007B8D30, 0x80234000, 
    0x007B8D30, 0x007B97E0, 0x80234000, 
    0x007B97E0, 0x007BA280, 0x80234000, 
    0x007BA280, 0x007BB050, 0x80234000, 
    0x007BB050, 0x007BBD80, 0x80234000,
    0x007BBD80, 0x007BEDD0, 0x80234000, 
    0x007BEDD0, 0x007C16C0, 0x80234000, 
    0x007C16C0, 0x007C3A00, 0x80234000, 
    0x007C3A00, 0x007C44D0, 0x80234000, 
    0x007C44D0, 0x007C4F50, 0x80234000,
    0x007C7E50, 0x007CA850, 0x80234000, 
    0x007CA850, 0x007CD5F0, 0x80234000, 
    0x007CD5F0, 0x007CDB30, 0x80234000, 
    0x007CDB30, 0x007CEFF0, 0x80234000,
    0x007CEFF0, 0x007CFCC0, 0x80234000, 
    0x007CFCC0, 0x007D0860, 0x80234000,
    0x007D0860, 0x007D14E0, 0x80234000, 
    0x007D14E0, 0x007D2080, 0x80234000,
    0x007D2080, 0x007D2960, 0x80234000, 
    0x007D2960, 0x007D3260, 0x80234000, 
    0x007D3260, 0x007D5570, 0x80234000,
    0x007D5570, 0x007D6F80, 0x80234000,
    0x007D6F80, 0x007D76B0, 0x80234000,
    0x007D76B0, 0x007D8FF0, 0x80234000,
    0x007D8FF0, 0x007D96E0, 0x80234000,
    0x007D96E0, 0x007D98E0, 0x80234000,
    0x007D98E0, 0x007DA140, 0x80234000, 
    0x007DA140, 0x007DC180, 0x80234000, 
    0x007DC180, 0x007DE970, 0x80234000,
    0x007DE970, 0x007DF2B0, 0x80234000, 
    0x007DF2B0, 0x007E03B0, 0x80234000,
    0x007E03B0, 0x007E0E80, 0x80234000, 
};

static s32 N(VineRenderState);

static s32 N(unk_static_pad);

void N(func_80240B00_C8E6B0)(LavaPiranhaVine* vine) {
    Evt dummyEvt;
    Evt* dummyEvtPtr = &dummyEvt;
    s32 args[4];
    s32 count;

    // setup dummy call to LoadPath
    args[0] = 3 * vine->unk_90;       // generate three output samples per input
    args[1] = (s32) &vine->unk_00;    // points
    args[2] = vine->unk_90;           // num vectors
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

API_CALLABLE(N(SetVineJointPos)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    LavaPiranhaVineSet* data = (LavaPiranhaVineSet*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &data->unk_00[vineIdx];

    vine->unk_00[jointIdx].x = x;
    vine->unk_00[jointIdx].y = y;
    vine->unk_00[jointIdx].z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineJointRot)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 rx = evt_get_variable(script, *args++);
    s32 ry = evt_get_variable(script, *args++);
    s32 rz = evt_get_variable(script, *args++);
    LavaPiranhaVineSet* data = (LavaPiranhaVineSet*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &data->unk_00[vineIdx];

    vine->unk_6C[jointIdx] = rz;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetVineJointScale)) {
    Bytecode* args = script->ptrReadPos;
    s32 vineIdx = evt_get_variable(script, *args++);
    s32 jointIdx = evt_get_variable(script, *args++);
    s32 sx = evt_get_variable(script, *args++);
    s32 sy = evt_get_variable(script, *args++);
    s32 sz = evt_get_variable(script, *args++);
    LavaPiranhaVineSet* data = (LavaPiranhaVineSet*) evt_get_variable(NULL, MV_VinesData);
    LavaPiranhaVine* vine = &data->unk_00[vineIdx];

    // do nothing
    return ApiStatus_DONE2;
}

void N(appendGfx_piranha_vines)(void* data) {
    Vtx_t* vtxBuffer;
    Vtx_t* vtx;

    f32 segLength;
    s32 segCount;

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
        for (i = 0; i < 4; i++) {
            LavaPiranhaVineSet* vineData = (LavaPiranhaVineSet*) evt_get_variable(NULL, MapVar(0));
            LavaPiranhaVine* vine = &vineData->unk_00[i];
            
            switch (i) {
                default:
                    return;
                case 0:
                    segCount = 9;
                    segLength = 10.0f;
                    break;
                case 1:
                    segCount = 7;
                    segLength = 8.0f;
                    break;
                case 2:
                    segCount = 7;
                    segLength = 8.0f;
                    break;
                case 3:
                    segCount = 5;
                    segLength = 8.0f;
                    break;
            }

            vine->unk_90 = segCount;
            vine->unk_94 = segLength;
            
            for (j = 0; j < segCount; j++) {
                if (j == (segCount - 1)) {
                    vine->unk_6C[j] += 90.0f;
                } else {
                    curAngle1 = vine->unk_6C[j];
                    nextAngle = vine->unk_6C[j + 1];
                    if (nextAngle - curAngle1 > 180.0f) {
                        curAngle1 += 360.0f;
                    } else if (nextAngle - curAngle1 < -180.0f) {
                        nextAngle += 360.0f;
                    }
                    // average cur and next angles
                    vine->unk_6C[j] = ((curAngle1 + nextAngle) / 2.0) + 90.0;
                }
            }
            
            N(func_80240B00_C8E6B0)(vine);
        }

        N(VineRenderState) = 1;
    }
    
    gDPPipeSync(gMasterGfxPos++);
    gSPDisplayList(gMasterGfxPos++, D_80243AD8_C91688);

    for (i = 0; i < 4; i++) {
        LavaPiranhaVineSet* vineData = (LavaPiranhaVineSet*) evt_get_variable(NULL, MapVar(0));
        LavaPiranhaVine* vine = &vineData->unk_00[i];
        
        segLength = vine->unk_94;
        segCount = vine->unk_90;
        numPoints = vine->numPoints;

        // we'll build the vertex data and place it in the display list, so jump forward
        // here and leave space behind for the gSPBranchList command followed by two vertices
        // for each point in numPoints
        
        vtxBuffer = (Vtx_t*)(gMasterGfxPos + 1);
        gSPBranchList(gMasterGfxPos, &gMasterGfxPos[1 + 2 * (2 * numPoints)]);
        vtx = (Vtx_t*) (++gMasterGfxPos);
        gMasterGfxPos = &gMasterGfxPos[2 * (2 * numPoints)];

        for (j = 0; j < numPoints; j++) {
            posX = vine->points[j].x;
            posY = vine->points[j].y;
            posZ = vine->points[j].z;
            
            alphaCoord = ((f32) j * (f32) segCount) / (f32) numPoints;
            nearest = (s32) alphaCoord;
            alphaFrac = alphaCoord - (f32)nearest;
            
            if (nearest + 1 >= segCount) {
                angle = vine->unk_6C[segCount - 1];
            } else {
                curAngle2 = vine->unk_6C[nearest];
                nextAngle = vine->unk_6C[nearest + 1];
                if (nextAngle - curAngle2 > 180.0f) {
                    nextAngle -= 360.0f;
                }
                if (nextAngle - curAngle2 < -180.0f) {
                    nextAngle += 360.0f;
                }
                angle = ((nextAngle - curAngle2) * alphaFrac) + curAngle2;
            }
            
            deltaX =  sin_deg(angle) * segLength;
            deltaY = -cos_deg(angle) * segLength;
            
            vtx->ob[0] = posX + deltaX;
            vtx->ob[1] = posY + deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;;
            vtx->cn[2] = j * 30;
            vtx++;
            
            vtx->ob[0] = posX - deltaX;
            vtx->ob[1] = posY - deltaY;
            vtx->ob[2] = posZ;
            vtx->tc[0] = j * 0x140;
            vtx->tc[1] = 0x400;
            vtx->cn[0] = j * 50;
            vtx->cn[1] = j * 120;;
            vtx->cn[2] = j * 30;
            vtx++;
        }

        for (j = 0; j < numPoints - 1; j++) {
            gSPVertex(gMasterGfxPos++, &vtxBuffer[2*j], 4, 0);
            gSP2Triangles(gMasterGfxPos++, 1, 0, 2, 0, 1, 2, 3, 0);
        }
    }

    gDPPipeSync(gMasterGfxPos++);
}

void N(worker_render_piranha_vines)(void) {
    RenderTask renderTask;

    renderTask.appendGfx = &N(appendGfx_piranha_vines);
    renderTask.appendGfxArg = 0;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    queue_render_task(&renderTask);
}

API_CALLABLE(N(MarkVineInterpolationDirty)) {
    N(VineRenderState) = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateVineRenderer)) {
    LavaPiranhaVineSet* data = heap_malloc(sizeof(*data));
    evt_set_variable(script, MV_VinesData, (s32) data);
    N(VineRenderState) = -1;
    create_generic_entity_world(NULL, &N(worker_render_piranha_vines));
    return ApiStatus_DONE2;
}

#include "world/common/atomic/LetterChoice.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER25,
    ITEM_NONE 
};

EvtScript N(EVS_Kolorado_LetterDelivery) = {
    EVT_CALL(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER25, 0,
        MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
        EVT_PTR(N(LetterList)))
    EVT_EXEC_WAIT(N(DoLetterDelivery))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_LetterReward) = {
    EVT_IF_EQ(LVarC, 2)
        EVT_SET(LVar0, ITEM_STAR_PIECE)
        EVT_SET(LVar1, 3)
        EVT_EXEC_WAIT(N(Delivery_ShowGotStarPiece))
        EVT_CALL(AddStarPieces, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_IF_EQ(GF_KZN19_KoloradoDeadEnd, FALSE)
        EVT_LABEL(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_IF_LT(LVar0, 300)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 4)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0100)
        EVT_SET(GF_KZN19_KoloradoDeadEnd, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_LABEL(5)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
        EVT_WAIT(30)
        EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
        EVT_WAIT(30)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Kolorado_Escape) = {
    EVT_LABEL(0)
    EVT_IF_EQ(MV_Unk_0A, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(60)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcPos, NPC_SELF, 70, 25, 60)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Panic)
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(4.0))
    EVT_CALL(NpcMoveTo, NPC_SELF, 170, 0, 0)
    EVT_CALL(NpcMoveTo, NPC_SELF, 280, 70, 0)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Panic, ANIM_Kolorado_Yell, 0, MSG_CH5_0107)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 450, 25, -20)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(NpcMoveTo, NPC_SELF, 535, -60, 0)
    EVT_WAIT(20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 304, 25, -35)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcAux, NPC_LavaPiranhaHead, 0)
    EVT_WAIT(10)
    EVT_CALL(FadeOutMusic, 0, 1500)
    EVT_EXEC(N(EVS_TryingSpawningStarCard))
    EVT_WAIT(30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_TalkSad, ANIM_Kolorado_IdleSad, 0, MSG_CH5_0101)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_EXEC_WAIT(N(EVS_Kolorado_LetterDelivery))
    EVT_EXEC_WAIT(N(EVS_Kolorado_LetterReward))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(GetEntryID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(kzn_19_ENTRY_0)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_CASE_EQ(kzn_19_ENTRY_1)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_Kolorado_Escape)))
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3f N(FlightPath)[] = {
    {  250.0,    40.0,  -35.0 },
    {  410.0,    30.0,    0.0 },
    {  460.0,    40.0,  -30.0 },
    {  510.0,    50.0,  -72.0 },
    {  540.0,    60.0, -115.0 },
};

EvtScript N(EVS_Misstar_Escape) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerPos, 185, 25, -35)
    EVT_CALL(SetNpcPos, NPC_PARTNER, 155, 25, -35)
    EVT_CALL(SetNpcPos, NPC_Misstar, 250, 40, -35)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 217, 25, -35)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 380)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(12.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30)
    EVT_SET(AF_EruptionBreakFloor, TRUE)
    EVT_CALL(PlaySound, SOUND_8000006B)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_IF_NE(AF_EruptionBreakFloor, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario_10002)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_CALL(GetNpcPos, NPC_Misstar, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Misstar, ANIM_WorldMisstar_Talk, ANIM_WorldMisstar_Idle, 0, MSG_CH5_0109)
    EVT_WAIT(10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 370, 25, 70)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpNpcYaw, NPC_Misstar, 90, 0)
    EVT_CALL(LoadPath, 45, EVT_PTR(N(FlightPath)), ARRAY_COUNT(N(FlightPath)), EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(GetNextPathPos)
        EVT_CALL(SetNpcPos, NPC_Misstar, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcPos, NPC_Misstar, NPC_DISPOSE_LOCATION)
    EVT_WAIT(15)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(3.0))
    EVT_SET(GB_StoryProgress, STORY_CH5_MT_LAVA_LAVA_ERUPTING)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(LoadAnimationFromTable)) {
    Bytecode* args = script->ptrReadPos;
    s32 type = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);
    
    switch (type) {
        case VINE_0:
            dma_copy(
                (u8*) VineAnimationsDmaTable[3 * index + 0],
                (u8*) VineAnimationsDmaTable[3 * index + 1],
                (void*) VINE_0_BASE);
            break;
        case VINE_1:
            dma_copy(
                (u8*) VineAnimationsDmaTable[3 * index + 0],
                (u8*) VineAnimationsDmaTable[3 * index + 1],
                (void*) VINE_1_BASE);
            break;
        case VINE_2:
            dma_copy(
                (u8*) VineAnimationsDmaTable[3 * index + 0],
                (u8*) VineAnimationsDmaTable[3 * index + 1],
                (void*) VINE_2_BASE);
            break;
        case VINE_3:
            dma_copy(
                (u8*) VineAnimationsDmaTable[3 * index + 0],
                (u8*) VineAnimationsDmaTable[3 * index + 1],
                (void*) VINE_3_BASE);
            break;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlayVinesAnim_Emerge) = {
    EVT_THREAD
        EVT_CALL(N(LoadAnimationFromTable), VINE_0, 15)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 220, 20, -40)
        EVT_CALL(N(LoadAnimationFromTable), VINE_3, 36)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
        EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
        EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
        EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(N(LoadAnimationFromTable), VINE_1, 32)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
        EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 220, 20, -40)
        EVT_WAIT(59)
        EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
        EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_END_THREAD
    EVT_WAIT(7)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 32)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 270, 34, -20)
    EVT_WAIT(62)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Idle) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_WAIT(10)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Talk) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 17)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayVinesAnim_Defeat) = {
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 16)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 33)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 33)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 35)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_LavaPiranha) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_IF_GT(LVar0, 150)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetMusicTrack, 0, SONG_LAVA_PIRANHA_THEME, 0, 8)
    EVT_CALL(LoadAnimatedModel, VINE_0, EVT_PTR(N(AnimModel_MainHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_0, 0)
    EVT_CALL(PlayModelAnimation, VINE_0, VINE_0_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_0, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_0, 128, 1)
    EVT_CALL(LoadAnimatedModel, VINE_1, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_1, 31)
    EVT_CALL(PlayModelAnimation, VINE_1, VINE_1_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_1, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_1, 128, 1)
    EVT_CALL(LoadAnimatedModel, VINE_2, EVT_PTR(N(AnimModel_SideHeadVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_2, 31)
    EVT_CALL(PlayModelAnimation, VINE_2, VINE_2_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_2, 270, -100, -20)
    EVT_CALL(SetAnimatorFlags, VINE_2, 128, 1)
    EVT_CALL(LoadAnimatedModel, VINE_3, EVT_PTR(N(AnimModel_ExtraVine)))
    EVT_CALL(N(LoadAnimationFromTable), VINE_3, 34)
    EVT_CALL(PlayModelAnimation, VINE_3, VINE_3_BASE)
    EVT_CALL(SetAnimatedModelRootPosition, VINE_3, 220, -100, -40)
    EVT_CALL(SetAnimatorFlags, VINE_3, 128, 1)
    EVT_CALL(N(CreateVineRenderer))
    EVT_CALL(SetSelfVar, 1, 1)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 300, 25, -20)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-9.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 40, 80, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(InterruptUsePartner)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, 200, -30, 0)
        EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAt, SOUND_3C5, 0, 330, 25, -50)
    EVT_EXEC(N(EVS_PlayVinesAnim_Emerge))
    EVT_WAIT(59)
    EVT_THREAD
        EVT_CALL(MakeLerp, 40, 0, 80, EASING_QUADRATIC_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, MODEL_poko, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 235, 25, -20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(420.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(10.0), EVT_FLOAT(-10.7))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0102)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 256, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_WAIT(30)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30, MSG_CH5_0103)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Talk))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_EXEC(N(EVS_PlayVinesAnim_Idle))
    EVT_WAIT(10)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_LavaPiranha_Anim0E, ANIM_LavaPiranha_Anim03, 768, -30, 30)
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 20)
        EVT_LOOP(3)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(250.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(440.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar0)
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
            EVT_SUB(LVar0, 2)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_LAVA_PIRANHA_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_LavaPiranha) = {
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_USE_ARRAY(LVar0)
    EVT_LOOP(0)
        EVT_CALL(GetSelfVar, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaPiranhaHead, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaPiranhaHead, LVar0, 0, LVar2)
    EVT_CALL(N(MarkVineInterpolationDirty))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 10, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(N(SetVineJointRot), VINE_0, 0, LVar0, 0, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 1, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 9, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 7, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_0, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_0, 8, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_0, 8, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaBud_01, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaBud_01, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(N(SetVineJointRot), VINE_1, 0, LVar0, 0, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 1, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_1, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_1, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_1, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_LavaBud_02, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcRotation, NPC_LavaBud_02, LVar0, 0, LVar2)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 90)
    EVT_CALL(N(SetVineJointRot), VINE_2, 0, LVar0, 0, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 0, 1, 1, 1)
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 1, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 7, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 5, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_2, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_2, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_2, 6, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_3, 0, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_3, 0, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_3, 0, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_3, 1, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 6, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_3, 1, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_3, 1, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_3, 2, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 5, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_3, 3, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_3, 3, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_CALL(GetAnimatedPositionByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointPos), VINE_3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetAnimatedRotationByTreeIndex, VINE_3, 2, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointRot), VINE_3, 4, LVar0, LVar1, LVar2)
    EVT_CALL(N(SetVineJointScale), VINE_3, 4, EVT_FLOAT(0.71484375), EVT_FLOAT(0.71484375), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_LavaPiranha) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAGS_2, TRUE)
            EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
            EVT_CALL(SetPlayerPos, 125, 25, -35)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 100, 25, -35)
            EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 125, 25, -35)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 205, 25, -35)
            EVT_CALL(SetCamDistance, CAM_DEFAULT, 470)
            EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-8.0))
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_CALL(EnableGroup, MODEL_ato, TRUE)
            EVT_CALL(EnableGroup, MODEL_naka, TRUE)
            EVT_CALL(EnableGroup, MODEL_mae, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ato, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mae, COLLIDER_FLAGS_UPPER_MASK)
            EVT_CALL(PlaySoundAt, SOUND_3C6, 0, 330, 25, -50)
            EVT_EXEC(N(EVS_PlayVinesAnim_Defeat))
            EVT_WAIT(1)
            EVT_CALL(SetNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_LavaPiranha)))
            EVT_SET(MV_Unk_0A, TRUE)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaPiranha) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, kzn_19_ENTRY_1)
        EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
            EVT_CALL(SetNpcAnimation, NPC_LavaPiranhaHead, ANIM_LavaPiranha_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_01, ANIM_LavaBud_Anim03)
            EVT_CALL(SetNpcAnimation, NPC_LavaBud_02, ANIM_LavaBud_Anim03)
            EVT_MALLOC_ARRAY(64, LVar0)
            EVT_CALL(SetSelfVar, 0, LVar0)
            EVT_USE_ARRAY(LVar0)
            EVT_CALL(SetSelfVar, 1, 0)
            EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_LavaPiranha)))
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_LavaPiranha)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_LavaPiranha)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetNpcPos, NPC_05, NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_LavaBud) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_LavaBud) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_DEFEATED_LAVA_PIRANHA)
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_LavaBud)))
    EVT_ELSE
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .settings = &N(NpcSettings_Kolorado),
    .pos = { 380.0f, 250.0f, -330.0f },
    .yaw = 90,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_MOTION_BLUR | NPC_FLAG_400000,
    .init = &N(EVS_NpcInit_Kolorado),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Kolorado_Idle,
        .walk   = ANIM_Kolorado_Walk,
        .run    = ANIM_Kolorado_Run,
        .chase  = ANIM_Kolorado_Run,
        .anim_4 = ANIM_Kolorado_Idle,
        .anim_5 = ANIM_Kolorado_Idle,
        .death  = ANIM_Kolorado_Idle,
        .hit    = ANIM_Kolorado_Idle,
        .anim_8 = ANIM_Kolorado_Idle,
        .anim_9 = ANIM_Kolorado_Idle,
        .anim_A = ANIM_Kolorado_Idle,
        .anim_B = ANIM_Kolorado_Idle,
        .anim_C = ANIM_Kolorado_Idle,
        .anim_D = ANIM_Kolorado_Idle,
        .anim_E = ANIM_Kolorado_Idle,
        .anim_F = ANIM_Kolorado_Idle,
    },
    .tattle = MSG_NpcTattle_Kolorado,
};

StaticNpc N(NpcData_Misstar) = {
    .id = NPC_Misstar,
    .settings = &N(NpcSettings_Misstar),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_400000,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldMisstar_Idle,
        .walk   = ANIM_WorldMisstar_Idle,
        .run    = ANIM_WorldMisstar_Idle,
        .chase  = ANIM_WorldMisstar_Idle,
        .anim_4 = ANIM_WorldMisstar_Idle,
        .anim_5 = ANIM_WorldMisstar_Idle,
        .death  = ANIM_WorldMisstar_Idle,
        .hit    = ANIM_WorldMisstar_Idle,
        .anim_8 = ANIM_WorldMisstar_Still,
        .anim_9 = ANIM_WorldMisstar_Idle,
        .anim_A = ANIM_WorldMisstar_Idle,
        .anim_B = ANIM_WorldMisstar_Idle,
        .anim_C = ANIM_WorldMisstar_Idle,
        .anim_D = ANIM_WorldMisstar_Idle,
        .anim_E = ANIM_WorldMisstar_Idle,
        .anim_F = ANIM_WorldMisstar_Idle,
    },
    .tattle = MSG_NpcTattle_Misstar,
};

s32 N(ExtraAnims_LavaPiranha)[] = {
    ANIM_LavaPiranha_Anim03,
    ANIM_LavaPiranha_Anim0E,
    -1
};

s32 N(ExtraAnims_LavaBud)[] = {
    ANIM_LavaBud_Anim03,
    -1
};

StaticNpc N(NpcData_LavaPiranha)[] = {
    {
        .id = NPC_LavaPiranhaHead,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_4 | NPC_FLAG_JUMPING | NPC_FLAG_40000,
        .init = &N(EVS_NpcInit_LavaPiranha),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaPiranha_Anim03,
            .walk   = ANIM_LavaPiranha_Anim03,
            .run    = ANIM_LavaPiranha_Anim03,
            .chase  = ANIM_LavaPiranha_Anim03,
            .anim_4 = ANIM_LavaPiranha_Anim03,
            .anim_5 = ANIM_LavaPiranha_Anim03,
            .death  = ANIM_LavaPiranha_Anim03,
            .hit    = ANIM_LavaPiranha_Anim03,
            .anim_8 = ANIM_LavaPiranha_Anim03,
            .anim_9 = ANIM_LavaPiranha_Anim03,
            .anim_A = ANIM_LavaPiranha_Anim03,
            .anim_B = ANIM_LavaPiranha_Anim03,
            .anim_C = ANIM_LavaPiranha_Anim03,
            .anim_D = ANIM_LavaPiranha_Anim03,
            .anim_E = ANIM_LavaPiranha_Anim03,
            .anim_F = ANIM_LavaPiranha_Anim03,
        },
        .extraAnimations = N(ExtraAnims_LavaPiranha),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_01,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_40000,
        .init = &N(EVS_NpcInit_LavaBud),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaBud_Anim03,
            .walk   = ANIM_LavaBud_Anim03,
            .run    = ANIM_LavaBud_Anim03,
            .chase  = ANIM_LavaBud_Anim03,
            .anim_4 = ANIM_LavaBud_Anim03,
            .anim_5 = ANIM_LavaBud_Anim03,
            .death  = ANIM_LavaBud_Anim03,
            .hit    = ANIM_LavaBud_Anim03,
            .anim_8 = ANIM_LavaBud_Anim03,
            .anim_9 = ANIM_LavaBud_Anim03,
            .anim_A = ANIM_LavaBud_Anim03,
            .anim_B = ANIM_LavaBud_Anim03,
            .anim_C = ANIM_LavaBud_Anim03,
            .anim_D = ANIM_LavaBud_Anim03,
            .anim_E = ANIM_LavaBud_Anim03,
            .anim_F = ANIM_LavaBud_Anim03,
        },
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_LavaBud_02,
        .settings = &N(NpcSettings_LavaPiranhaHead),
        .pos = { 400.0f, 25.0f, -30.0f },
        .yaw = 270,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_4 | NPC_FLAG_40000,
        .init = &N(EVS_NpcInit_LavaBud),
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 10, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 3,
        },
        .animations = {
            .idle   = ANIM_LavaBud_Anim03,
            .walk   = ANIM_LavaBud_Anim03,
            .run    = ANIM_LavaBud_Anim03,
            .chase  = ANIM_LavaBud_Anim03,
            .anim_4 = ANIM_LavaBud_Anim03,
            .anim_5 = ANIM_LavaBud_Anim03,
            .death  = ANIM_LavaBud_Anim03,
            .hit    = ANIM_LavaBud_Anim03,
            .anim_8 = ANIM_LavaBud_Anim03,
            .anim_9 = ANIM_LavaBud_Anim03,
            .anim_A = ANIM_LavaBud_Anim03,
            .anim_B = ANIM_LavaBud_Anim03,
            .anim_C = ANIM_LavaBud_Anim03,
            .anim_D = ANIM_LavaBud_Anim03,
            .anim_E = ANIM_LavaBud_Anim03,
            .anim_F = ANIM_LavaBud_Anim03,
        },
        .extraAnimations = N(ExtraAnims_LavaBud),
        .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
    },
};

NpcGroupList N(BossNPCs) = {
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_LavaPiranha), BTL_KZN2_FORMATION_00, BTL_KZN2_STAGE_06),
    {}
};

NpcGroupList N(EscapeNPCs) = {
    NPC_GROUP(N(NpcData_Misstar)),
    {}
};
