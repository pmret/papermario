#include "common.h"
#include "nu/nusys.h"
#include "gcc/string.h"

u16 heap_nextMallocID = 0;

f32 sCosineTable[] = {
    0.0f, 0.017452f, 0.034899f, 0.052336f, 0.069756f, 0.087156f, 0.104528f, 0.121869f, 0.139173f,
    0.156434f, 0.173648f, 0.190809f, 0.207912f, 0.224951f, 0.241922f, 0.258819f, 0.275637f, 0.292372f, 0.309017f,
    0.325568f, 0.34202f, 0.358368f, 0.374607f, 0.390731f, 0.406737f, 0.422618f, 0.438371f, 0.45399f, 0.469472f,
    0.48481f, 0.5f, 0.515038f, 0.529919f, 0.544639f, 0.559193f, 0.573576f, 0.587785f, 0.601815f, 0.615661f, 0.62932f,
    0.642788f, 0.656059f, 0.669131f, 0.681998f, 0.694658f, 0.707107f, 0.71934f, 0.731354f, 0.743145f, 0.75471f,
    0.766044f, 0.777146f, 0.788011f, 0.798636f, 0.809017f, 0.819152f, 0.829038f, 0.838671f, 0.848048f, 0.857167f,
    0.866025f, 0.87462f, 0.882948f, 0.891007f, 0.898794f, 0.906308f, 0.913545f, 0.920505f, 0.927184f, 0.93358f,
    0.939693f, 0.945519f, 0.951057f, 0.956305f, 0.961262f, 0.965926f, 0.970296f, 0.97437f, 0.978148f, 0.981627f,
    0.984808f, 0.987688f, 0.990268f, 0.992546f, 0.994522f, 0.996195f, 0.997564f, 0.99863f, 0.999391f, 0.999848f, 1.0f
};

// Digits for bases up to 36
u8 sIntegerDigits[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u32 gRandSeed = 1;

f32 sAtanFactors[] = {
    1.0f, 1.273187f, 1.27303f, 1.272768f, 1.272402f, 1.271932f, 1.271358f, 1.270681f, 1.269902f, 1.269021f, 1.268038f,
    1.266956f, 1.265774f, 1.264494f, 1.263116f, 1.261643f, 1.260075f, 1.258413f, 1.256659f, 1.254815f, 1.252881f,
    1.250859f, 1.248752f, 1.24656f, 1.244285f, 1.241929f, 1.239494f, 1.236981f, 1.234393f, 1.231731f, 1.228997f,
    1.226192f, 1.22332f, 1.220382f, 1.217379f, 1.214315f, 1.211189f, 1.208006f, 1.204766f, 1.201471f, 1.198124f,
    1.194727f, 1.191281f, 1.187787f, 1.18425f, 1.180669f, 1.177047f, 1.173386f, 1.169687f, 1.165952f, 1.162184f,
    1.158384f, 1.154553f, 1.150693f, 1.146806f, 1.142893f, 1.138957f, 1.134998f, 1.131018f, 1.127019f, 1.123002f,
    1.118969f, 1.11492f, 1.110858f, 1.106783f, 1.102697f, 1.098601f, 1.094496f, 1.090384f, 1.086266f, 1.082142f,
    1.078014f, 1.073883f, 1.06975f, 1.065616f, 1.061482f, 1.057348f, 1.053216f, 1.049087f, 1.04496f, 1.040838f,
    1.036721f, 1.03261f, 1.028504f, 1.024406f, 1.020316f, 1.016234f, 1.01216f, 1.008097f, 1.004043f, 1.0f
};

Gfx D_80074580[] = {
    gsDPPipeSync(),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPEndDisplayList(),
};

void dma_write_block(Addr dramAddr, u32 devAddr, s32 size);

#define ROM_CHUNK_SIZE 0x2000

f32 length2D(f32 x, f32 y) {
    return sqrtf(SQ(x) + SQ(y));
}

HeapNode* _heap_create(HeapNode* addr, u32 size) {
    if (size < 32) {
        return (HeapNode*)-1;
    } else {
        HeapNode* heapNode = (HeapNode*)ALIGN16((u32)addr);

        size -= ((u8*)heapNode - (u8*)addr);
        heapNode->next = NULL;
        heapNode->length = size - sizeof(HeapNode);
        heapNode->allocated = 0;
        heapNode->capacity = size;
        return heapNode;
    }
}

void* _heap_malloc(HeapNode* head, u32 size) {
    HeapNode* nextHeapNode;
    HeapNode* pPrevHeapNode = NULL;
    u32 newBlockSize;
    u32 curBlockLength;
    HeapNode* curHeapNode;
    u32 smallestBlockFound;
    u16 HeapEntryID;
    u16 HeapEntryID2;

    // must allocate 16 bytes or more at minimum or fail
    size = ALIGN16(size);
    if (!size) {
        return NULL;
    }

    smallestBlockFound = 0;
    nextHeapNode = NULL;

    // find the smallest block we can fit into in the free list
    for (curHeapNode = head; ; curHeapNode = curHeapNode->next) {
        if (!curHeapNode->allocated) {
            curBlockLength = curHeapNode->length;
            if ((curBlockLength >= size) && (curBlockLength < smallestBlockFound || !smallestBlockFound)) {
                pPrevHeapNode = curHeapNode;
                smallestBlockFound = curBlockLength;
                nextHeapNode = curHeapNode->next;
            }
        }
        if (!curHeapNode->next) {
            break;
        }
    }


    // find out the required block size with header
    newBlockSize = size + sizeof(HeapNode);

    // if we found a block see if we need to split it up
    if (smallestBlockFound) {
        if (smallestBlockFound >= newBlockSize) {
            // update previous to the proper size for the block being returned
            pPrevHeapNode->next = (HeapNode*)((u8*)pPrevHeapNode + newBlockSize);
            pPrevHeapNode->length = size;

            // update the entry id on allocation
            HeapEntryID = heap_nextMallocID;
            pPrevHeapNode->allocated = TRUE;
            heap_nextMallocID = HeapEntryID + 1;
            pPrevHeapNode->entryID = HeapEntryID;

            // setup the new heap block entry
            curHeapNode = pPrevHeapNode->next;
            curHeapNode->next = nextHeapNode;
            curHeapNode->length = smallestBlockFound - newBlockSize;
            curHeapNode->allocated = FALSE;
        } else {
            // take this entry out of the free linked list and mark as allocated
            pPrevHeapNode->next = nextHeapNode;
            pPrevHeapNode->length = smallestBlockFound;

            // update the entry id on allocation
            // note, usage of a single ID from above will result in wrong code
            HeapEntryID2 = heap_nextMallocID;
            pPrevHeapNode->allocated = TRUE;
            heap_nextMallocID = HeapEntryID2 + 1;
            pPrevHeapNode->entryID = HeapEntryID2;
        }
        return (u8*)pPrevHeapNode + sizeof(HeapNode);
    }
    return NULL;
}

void* _heap_malloc_tail(HeapNode* head, u32 size) {
    HeapNode* curNode;
    u32 newNodeSize;
    u32 foundNodeLength;
    HeapNode* foundNode;
    HeapNode* nextNode;

    size = ALIGN16(size);
    foundNode = NULL;

    // make sure we have a size to allocate
    if (!size) {
        return NULL;
    }

    foundNodeLength = 0;
    nextNode = NULL;

    // find the smallest block we can fit into
    for (curNode = head; ; curNode = curNode->next) {
        if (!curNode->allocated) {
            if (curNode->length >= size) {
                foundNode = curNode;
                foundNodeLength = curNode->length;
                nextNode = curNode->next;
            }
        }

        if (!curNode->next) {
            break;
        }
    }

    newNodeSize = size + sizeof(HeapNode);
    if (foundNodeLength != 0) {
        curNode = foundNode;

        // we found a block to use, see if we can split it and return a portion
        // or if we just need to return the whole block
        if (foundNodeLength >= newNodeSize) {
            // add a free block before this one
            // this is where this function differs from heap_malloc, it returns
            // the end of the block instead of the beginning when splitting it up
            curNode->next = (HeapNode*)((u8*)curNode + foundNodeLength - size);
            curNode->length = foundNodeLength - newNodeSize;
            curNode->allocated = FALSE;

            curNode = curNode->next;
            curNode->next = nextNode;
            curNode->length = size;
            curNode->allocated = TRUE;

        } else {
            // just return this actual block
            curNode->next = nextNode;
            curNode->length = foundNodeLength;
            curNode->allocated = TRUE;
        }

        return (u8*)curNode + sizeof(HeapNode);
    }

    // did not find a block
    return NULL;
}

u32 _heap_free(HeapNode* heapNodeList, void* addrToFree) {
    u32 curNodeLength;
    HeapNode* nextNode;
    HeapNode* nodeToFreeHeader;
    HeapNode* tempNode;
    HeapNode* outNode;

    // if no address to free then return
    if (addrToFree == NULL) {
        return TRUE;
    }

    // if we are not allocated then ignore this request
    nodeToFreeHeader = (HeapNode*)((u8*)addrToFree - sizeof(HeapNode));
    if (!nodeToFreeHeader->allocated) {
        return TRUE;
    }

    nextNode = nodeToFreeHeader->next;
    curNodeLength = nodeToFreeHeader->length;
    outNode = nextNode;

    // see if the next node after us is allocated, if not then adjust our size
    // to include it and point nextNode to be the node after as it must be allocated
    if (nextNode && !nextNode->allocated) {
        curNodeLength += nextNode->length + sizeof(HeapNode);
        nextNode = nextNode->next;
    }

    // walk the full heap node list looking for the block before our current entry
    tempNode = heapNodeList;
    while (TRUE) {
        // get the pointer to the next block, if it matches the block being freed then
        // exit the search
        heapNodeList = tempNode->next;
        if (heapNodeList == nodeToFreeHeader) {

            // we found the node prior to us, if it is not allocated then adjust our total
            // size to include it and change the header node pointer to point that block
            if (!tempNode->allocated) {
                curNodeLength += sizeof(HeapNode) + tempNode->length;
                nodeToFreeHeader = tempNode;
            }
            break;
        }

        // if the node being freed is before the current node being looked at then we
        // moved past our current node, bail out. Also bail if we hit the end of the list
        if (nodeToFreeHeader < tempNode || !heapNodeList) {
            break;
        }

        // move to the next node
        tempNode = tempNode->next;
    }

    // update the node being free'd with a proper size and pointer to the next node that is
    // allocated
    outNode = nodeToFreeHeader;
    outNode->next = nextNode;
    outNode->length = curNodeLength;
    outNode->allocated = FALSE;
    return FALSE;
}

void* _heap_realloc(HeapNode* heapNodeList, void* addr, u32 newSize) {
    u32 newSizeAligned;
    HeapNode* nextNode;
    HeapNode* curHeapAlloc;
    HeapNode* newFreeBlock;
    u32 newNodeLength;
    HeapNode* nodeToUpdate;

    curHeapAlloc = (HeapNode*)((u8*)addr - sizeof(HeapNode));
    newSizeAligned = ALIGN16(newSize);

    // check if the realloc is on an allocated node otherwise fail
    if (!curHeapAlloc->allocated) {
        return NULL;
    }

    nextNode = curHeapAlloc->next;
    newNodeLength = curHeapAlloc->length;

    // if we have a node after us and it isn't allocated then
    // adjust the length and next node pointers to include the node after us
    nodeToUpdate = nextNode;
    if (nextNode && !nextNode->allocated) {
        nextNode = nextNode->next;
        newNodeLength += sizeof(HeapNode) + nodeToUpdate->length;
    }

    // check if the current block or current + next block (if free) are too small
    nodeToUpdate = curHeapAlloc;
    if (newNodeLength < newSizeAligned) {
        // too small, allocatr a new node, copy data to it then free the current one
        curHeapAlloc = _heap_malloc(heapNodeList, newSizeAligned);
        if (curHeapAlloc == NULL) {
            return NULL;
        }

        // minor interest note, copy the size of the newly allocated size
        // instead of just how much data used to be stored, this results in copying
        // excessive data
        memcpy(curHeapAlloc, addr, newSizeAligned);
        _heap_free(heapNodeList, addr);
        return curHeapAlloc;
    }

    // see if there is room to add a new free block after us
    if (newSizeAligned + sizeof(HeapNode) < newNodeLength) {
        // room for a free block, create it
        newFreeBlock = (HeapNode*)((u8*)addr + newSizeAligned);

        // update current node
        nodeToUpdate->next = newFreeBlock;
        nodeToUpdate->length = newSizeAligned;

        // create new node after the current one
        nodeToUpdate = newFreeBlock;
        nodeToUpdate->next = nextNode;
        nodeToUpdate->length = (newNodeLength - newSizeAligned) - sizeof(HeapNode);
        nodeToUpdate->allocated = FALSE;
    } else {
        // no room, update our next and length
        nodeToUpdate->next = nextNode;
        nodeToUpdate->length = newNodeLength;
    }

    // return the location we were at
    return addr;
}

f32 cosine(s16 arg0) {
    s16 temp360;
    s16 idx;

    temp360 = arg0 % 360;

    if (temp360 < 0) {
        temp360 += 360;
    }

    idx = temp360 % 180;
    if (idx > 90) {
        idx = 180 - idx;
    }

    if (temp360 >= 180) {
        return -sCosineTable[idx];
    } else {
        return sCosineTable[idx];
    }
}

s32 sign(s32 val) {
    s32 sign = -1;

    if (val >= 0) {
        sign = val > 0;
    }
    return sign;
}

// Writes integer in base as a string to dest. base can range from 2 to 36
char* int_to_string(s32 integer, char* dest, s32 base) {
    u8 string[40]; // Even for binary this is a little long: 34 would suffice
    s32 i = ARRAY_COUNT(string) - 2;
    s32 negative = FALSE;
    s64 longInteger = integer;

    // handle negative integers
    if (longInteger < 0) {
        negative = TRUE;
        longInteger *= -1;
    }

    // null-terminate string
    string[ARRAY_COUNT(string) - 1] = '\0';

    // extract digits, filling string from the back
    while (TRUE) {
        string[i] = sIntegerDigits[longInteger % base];
        longInteger /= base;
        if (longInteger == 0 || i == 0) {
            break;
        }
        i--;
    }

    // Add - to negatives
    if (negative) {
        i--;
        string[i] = '-';
    }

    // copy only populated part of string
    strcpy(dest, &string[i]);

    return dest;
}

void mem_clear(void* data, s32 numBytes) {
    u8* addressableData = data;

    while (numBytes > 0) {
        *addressableData++ = 0;
        numBytes--;
    }
}

void transform_point(Matrix4f mtx, f32 inX, f32 inY, f32 inZ, f32 inS, f32* outX, f32* outY, f32* outZ, f32* outW) {
    *outX = (mtx[0][0] * inX) + (mtx[1][0] * inY) + (mtx[2][0] * inZ) + mtx[3][0];
    *outY = (mtx[0][1] * inX) + (mtx[1][1] * inY) + (mtx[2][1] * inZ) + mtx[3][1];
    *outZ = (mtx[0][2] * inX) + (mtx[1][2] * inY) + (mtx[2][2] * inZ) + mtx[3][2];
    *outW = (mtx[0][3] * inX) + (mtx[1][3] * inY) + (mtx[2][3] * inZ) + mtx[3][3];
}

void copy_matrix(Matrix4f src, Matrix4f dest) {
    bcopy(src, dest, sizeof(Matrix4f));
}

// maybe u32
u32 dma_copy(Addr romStart, Addr romEnd, void* vramDest) {
    u32 length = romEnd - romStart;
    s32 i;

    osInvalICache(vramDest, length);

    for (i = 0; i + ROM_CHUNK_SIZE < length; i += ROM_CHUNK_SIZE) {
        nuPiReadRom((u32)romStart + i, vramDest + i, ROM_CHUNK_SIZE);
    }

    if (i != length) {
        nuPiReadRom((u32)romStart + i, vramDest + i, length - i);
    }

    return length;
}

s32 dma_write(Addr romStart, Addr romEnd, void* vramDest) {
    u32 length = romEnd - romStart;
    s32 i;

    for (i = 0; i + ROM_CHUNK_SIZE < length; i += ROM_CHUNK_SIZE) {
        dma_write_block(romStart + i, (u32)vramDest + i, ROM_CHUNK_SIZE);
    }

    if (i != length) {
        dma_write_block(romStart + i, (u32)vramDest + i, length - i);
    }

    return length;
}

void dma_write_block(Addr dramAddr, u32 devAddr, s32 size) {
    OSIoMesg osIoMesg;
    OSMesg osMesg;
    OSMesgQueue osMesgQueue;

    osWritebackDCache(dramAddr, size);
    osCreateMesgQueue(&osMesgQueue, &osMesg, 1);

    osIoMesg.hdr.pri = 0;
    osIoMesg.hdr.retQueue = &osMesgQueue;
    osIoMesg.dramAddr = dramAddr;
    osIoMesg.devAddr = devAddr;
    osIoMesg.size = size;

    osEPiStartDma(nuPiCartHandle, &osIoMesg, 1);
    osRecvMesg(&osMesgQueue, &osMesg, 1);
}

// advance the global RNG via LCG algorithm and return a random integer [0,2^32)
u32 advance_rng(void) {
    gRandSeed = gRandSeed * 0x5D588B65 + 1;

    gGameStatusPtr->nextRNG = gRandSeed;

    return gRandSeed;
}

// return a random float [0,1)
f32 rand_float(void) {
    return (advance_rng() & 0x7FFF) / 32768.0;
}

// return a random integer [0,max]
s32 rand_int_internal(u32 max) {
    u32 partitionSize = 0xFFFFFFFF;
    u32 maxPlusOne = max + 1;
    u32 result;

    // split [0,2^32) into ``maxPlusOne`` equally sized partitions
    // [0, partitionSize), [partitionSize, 2*partitionSize), ... [maxPlusOne*partitionSize, 2^32)
    partitionSize /= maxPlusOne;
    if (partitionSize == 0) {
        partitionSize = 1;
    }

    // numbers in the leftover [maxPlusOne*partitionSize, 2^32) are rejected as they would return maxPlusOne
    // this ensures the result is [0,max] whilst also ensuring each partition is the same size and equally probable
    do {
        // determine which partition the random number is in by dividing it by partitionSize
        result = advance_rng() / partitionSize;
    } while (result >= maxPlusOne);

    return result;
}

// return a random integer [0,|max|] with specific distributions for |max| = 1 and |max| = 100
s32 rand_int(s32 max) {
    s32 ret = 0;

    max = abs(max);

    if (max != 0) {
        switch (max) {
            case 1:
                // due to the off-by-one input of 1000 and the > operator being used,
                // there is a 501/1001 chance of returning 0 and a 500/1001 chance of returning 1
                // (assuming statistical randomness of rand_int_internal).
                ret = rand_int_internal(1000) > 500;
                break;
            default:
                ret = rand_int_internal(max);
                break;
            case 100:
                ret = rand_int_internal(1009) / 10;
                break;
        }
    }

    return ret;
}

f32 signF(f32 val) {
    f32 sign;

    if (!(val > 0.0f)) {
        sign = -1.0f;
        if (!(val < 0.0f)) {
            sign = 0.0f;
        }
    } else {
        sign = 1.0f;
    }

    return sign;
}

s32 round(f32 x) {
    if (!(x >= 0.0f)) {
        return -(s32)(0.5 - x);
    } else {
        return (s32)(0.5 + x);
    }
}

f32 clamp_angle(f32 theta) {
    if (fabsf(theta) > 3600.0f) {
        s32 thetaInt = theta;

        if (thetaInt >= 0) {
            thetaInt = -(thetaInt / 360 * 360) + thetaInt;
        } else {
            thetaInt = -thetaInt;
            thetaInt = (thetaInt / 360 * 360) - thetaInt;
        }

        return thetaInt;
    }

    do {
        if (theta < 0.0f) {
            theta += 360.0f;
        }
        if (theta >= 360.0f) {
            theta -= 360.0f;
        }
    } while (!(theta >= 0.0f) || !(theta < 360.0f));

    return theta;
}

f32 get_clamped_angle_diff(f32 a, f32 b) {
    if (fabsf(b - a) >= 180.0f) {
        if (b < a) {
            b += 360.0f;
        } else {
            b -= 360.0f;
        }
    }
    return b - a;
}

f32 atan2(f32 startX, f32 startZ, f32 endX, f32 endZ) {
    f32 xDiff = endX - startX;
    f32 zDiff = endZ - startZ;
    f32 absXDiff = fabsf(xDiff);
    f32 absZDiff = fabsf(zDiff);
    f32 ret;

    if (absZDiff < absXDiff) {
        ret = (absZDiff / absXDiff) * 45.0f;
        ret *= sAtanFactors[round(2.0f * ret)];
        if (xDiff >= 0.0f) {
            if (zDiff >= 0.0f) {
                return ret + 90.0f;
            } else {
                return 90.0f - ret;
            }
        }
        if (zDiff >= 0.0f) {
            return 270.0f - ret;
        } else {
            return ret + 270.0f;
        }
    } else {
        if (absZDiff == 0.0f) {
            return 0.0f;
        }
        ret = (absXDiff / absZDiff) * 45.0f;
        ret *= sAtanFactors[round(2.0f * ret)];
        if (zDiff >= 0.0f) {
            if (xDiff >= 0.0f) {
                return 180.0f - ret;
            } else {
                return ret + 180.0f;
            }
        } else if (!(xDiff >= 0.0f)) {
            return 360.0f - ret;
        }
    }
    return ret;
}

f32 get_player_normal_yaw(void) {
    return atan2(0, 0, gGameStatusPtr->playerGroundTraceNormal.x, gGameStatusPtr->playerGroundTraceNormal.z);
}

f32 get_player_normal_pitch(void) {
    f32 traceNormalX = gGameStatusPtr->playerGroundTraceNormal.x;
    f32 traceNormalZ = gGameStatusPtr->playerGroundTraceNormal.z;
    f32 sqrt = sqrtf(SQ(traceNormalX) + SQ(traceNormalZ));

    return atan2(0.0f, 0.0f, sqrt, -gGameStatusPtr->playerGroundTraceNormal.y);
}

f32 dist2D(f32 ax, f32 ay, f32 bx, f32 by) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;

    return sqrtf(SQ(xDiff) + SQ(yDiff));
}

f32 dist3D(f32 ax, f32 ay, f32 az, f32 bx, f32 by, f32 bz) {
    f32 xDiff = bx - ax;
    f32 yDiff = by - ay;
    f32 zDiff = bz - az;

    return sqrtf(SQ(xDiff) + SQ(yDiff) + SQ(zDiff));
}

void add_vec2D_polar(f32* x, f32* y, f32 r, f32 theta) {
    f32 sinTheta;
    f32 cosTheta;

    sin_cos_rad(DEG_TO_RAD(theta), &sinTheta, &cosTheta);
    *x += r * sinTheta;
    *y -= r * cosTheta;
}

// Effectively computes theta % 0x100000
u16 _wrap_trig_lookup_value(f32 theta) {
    f32 ret = theta;

    if (theta >= 0x100000 || theta <= -0x100000) {
        ret = theta / 0x100000;
        ret = theta - (f32)(s32)ret * 0x100000;
    }

    return (s32) ret;
}

void sin_cos_rad(f32 theta, f32* outSinTheta, f32* outCosTheta) {
    u16 binang = _wrap_trig_lookup_value(RAD_TO_BINANG(theta));

    *outSinTheta = sins(binang) * SHT_MINV;
    *outCosTheta = coss(binang) * SHT_MINV;
}

f32 sin_rad(f32 theta) {
    return sins(_wrap_trig_lookup_value(RAD_TO_BINANG(theta))) * SHT_MINV;
}

f32 cos_rad(f32 theta) {
    return coss(_wrap_trig_lookup_value(RAD_TO_BINANG(theta))) * SHT_MINV;
}
void sin_cos_deg(f32 theta, f32* outSinTheta, f32* outCosTheta) {
    u16 binang = _wrap_trig_lookup_value(DEG_TO_BINANG(theta));

    *outSinTheta = sins(binang) * SHT_MINV;
    *outCosTheta = coss(binang) * SHT_MINV;
}

f32 sin_deg(f32 theta) {
    return sins(_wrap_trig_lookup_value(DEG_TO_BINANG(theta))) * SHT_MINV;
}

f32 cos_deg(f32 theta) {
    return coss(_wrap_trig_lookup_value(DEG_TO_BINANG(theta))) * SHT_MINV;
}

f32 update_lerp(s32 easing, f32 start, f32 end, s32 elapsed, s32 duration) {
    s32 timeLeft;
    f32 absMag;

    if (duration == 0) {
        return end;
    }

    switch (easing) {
        case EASING_LINEAR:
            return start + (end - start) * elapsed / duration;
        case EASING_QUADRATIC_IN:
            return start + SQ(elapsed) * (end - start) / SQ(duration);
        case EASING_CUBIC_IN:
            return start + CUBE(elapsed) * (end - start) / CUBE(duration);
        case EASING_QUARTIC_IN:
            return start + QUART(elapsed) * (end - start) / QUART(duration);
        case EASING_COS_SLOW_OVERSHOOT:
            return end - ((end - start) * cos_rad(((f32)elapsed / duration) * PI_D * 4.0) * (duration - elapsed) *
                    (duration - elapsed)) / SQ((f32)duration);
        case EASING_COS_FAST_OVERSHOOT:
            return end - ((end - start) * cos_rad((((f32)SQ(elapsed) / duration) * PI_D * 4.0) / 15.0) * (duration - elapsed) *
                    (duration - elapsed)) / SQ((f32)duration);
        case EASING_QUADRATIC_OUT:
            timeLeft = duration - elapsed;
            return start + (end - start) - ((SQ(timeLeft) * (end - start))) / SQ(duration);
        case EASING_CUBIC_OUT:
            timeLeft = duration - elapsed;
            return start + (end - start) - ((CUBE(timeLeft) * (end - start))) / CUBE(duration);
        case EASING_QUARTIC_OUT:
            timeLeft = duration - elapsed;
            return start + (end - start) - ((QUART(timeLeft) * (end - start))) / QUART(duration);
        case EASING_COS_BOUNCE:
            absMag = cos_rad((((f32)SQ(elapsed) / duration) * PI_D * 4.0) / 40.0) * (duration - elapsed) *
                    (duration - elapsed) / SQ((f32)duration);
            if (absMag < 0.0f) {
                absMag = -absMag;
            }
            return end - (end - start) * absMag;
        case EASING_COS_IN_OUT:
            return start + (end - start) * (1.0 - cos_rad(((f32)elapsed * PI_D) / (f32)duration)) * 0.5;
        case EASING_SIN_OUT:
            return start + (end - start) * sin_rad(((f32)elapsed * (PI_D / 2)) / (f32)duration);
        case EASING_COS_IN:
            return start + (end - start) * (1.0 - cos_rad(((f32)elapsed * (PI_D / 2)) / (f32)duration));
    }

    return 0.0f;
}

void appendGfx_startup_prim_rect(u8 r, u8 g, u8 b, u8 a, u16 left, u16 top, u16 right, u16 bottom) {
    gDPPipeSync(gMainGfxPos++);
    gSPDisplayList(gMainGfxPos++, D_80074580);

    if (a == 255) {
        gDPSetRenderMode(gMainGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gMainGfxPos++, PM_CC_PRIM_FULL_ALPHA, PM_CC_PRIM_FULL_ALPHA);
    } else {
        gDPSetRenderMode(gMainGfxPos++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    }

    gDPSetPrimColor(gMainGfxPos++, 0, 0, r, g, b, a);
    gDPFillRectangle(gMainGfxPos++, left, top, right, bottom);

    gDPPipeSync(gMainGfxPos++);
    gDPSetRenderMode(gMainGfxPos++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
}

void startup_draw_prim_rect_COPY(s16 left, s16 top, s16 right, s16 bottom, u16 r, u16 g, u16 b, u16 a) {
    u16 temp;

    if (right < left) {
        temp = right;
        right = left;
        left = temp;
    }

    if (bottom < top) {
        temp = bottom;
        bottom = top;
        top = temp;
    }

    appendGfx_startup_prim_rect(r, g, b, a, left, top, right, bottom);
}

void startup_draw_prim_rect(s16 left, s16 top, s16 right, s16 bottom, u16 r, u16 g, u16 b, u16 a) {
    u16 temp;

    if (right < left) {
        temp = right;
        right = left;
        left = temp;
    }

    if (bottom < top) {
        temp = bottom;
        bottom = top;
        top = temp;
    }

    appendGfx_startup_prim_rect(r, g, b, a, left, top, right, bottom);
}
