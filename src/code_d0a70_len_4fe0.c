#include "common.h"

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A370);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A37C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A4D0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A610);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A650);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A6E8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A704);

// does not match
// void func_8013A854(u32 index) {
//     if (index < 90) {
//         UnkStructFromfunc8013A854* unkStruct;
//         unkStruct = &D_80156954[index * 31];
//         unkStruct->unk14 = 0;
//         unkStruct->unk10 = -1;
//     }
// }

// OK
void func_8013A854(u32 i) {
    UnkStructFromfunc8013A854* unkStruct;
    if (i < 90) {
        unkStruct = *D_80156954;
        unkStruct[i].unk_14 = 0;
        unkStruct[i].unk_10 = -1;
    }
}

/*
Occurrences of DAT_80156954
* 37c all the same func
* block_3::8013a3e0		FUN_block_3__8013a37c	sw v0,0x0(v1)=>DAT_80156954
* block_3::8013a3f0	    LAB_block_3__8013a3f0	Global	lw a0,0x0(s2)=>DAT_80156954
* block_3::8013a3fc		FUN_block_3__8013a37c	lw a0,0x0(s2)=>DAT_80156954
* 37c all the same func

* 4d0 all the same func
* block_3::8013a4fc		FUN_block_3__8013a4d0	lw a0,0x0(s0)=>DAT_80156954
* block_3::8013a528		FUN_block_3__8013a4d0	lw v1,0x0(s0)=>DAT_80156954
* block_3::8013a544		FUN_block_3__8013a4d0	lw v0,offset DAT_80156954(v0)
* block_3::8013a594	    LAB_block_3__8013a594	Global	lw v0,0x0(s2)=>DAT_80156954
* block_3::8013a5d4		FUN_block_3__8013a4d0	lw v0,0x0(s2)=>DAT_80156954
* 4d0 all the same func

* 704 all the same func
* accessed 4 times
* block_3::8013a708		FUN_block_3__8013a704	lw v0,offset DAT_80156954(v0)
* block_3::8013a7a4		FUN_block_3__8013a704	lw v1,offset DAT_80156954(v1)
* block_3::8013a7e0	    LAB_block_3__8013a7e0	Global	lw v0,0x0(s4)=>DAT_80156954
* block_3::8013a7ec		FUN_block_3__8013a704	lw param_1,0x0(s4)=>DAT_80156954
* block_3::8013a7f8		FUN_block_3__8013a704	lw v0,0x0(s4)=>DAT_80156954 
* 704 all the same func

block_3::8013a868		FUN_block_3__8013a854	lw v1,offset DAT_80156954(v1) accessed twice
block_3::8013a8b0		FUN_block_3__8013a888	lw v1,offset DAT_80156954(v1) accessed once
block_3::8013aab4		FUN_block_3__8013aa9c	lw v1,offset DAT_80156954(v1) seems to access it in many places

void FUN_block_3__8013aa9c
               (ulonglong param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,
               int param_6,uint param_7)

{
  uint uVar1;
  int **ppiVar2;
  undefined uVar3;
  int iVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = _DAT_80156954 + (int)param_1 * 0x7c;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    return;
  }
  if (0x59 < param_1) {
    return;
  }
  iVar6 = (int)param_2;
  iVar4 = (int)param_3;
  switch(iVar6) {
  case 0:
  case 3:
    uVar1 = *(uint *)(iVar7 + 0x14);
    FUN_block_3__8013a93c(iVar7);
    FUN_block_3__8013a9e8(iVar7);
    *(undefined *)(iVar7 + 5) = 0;
    *(undefined *)(iVar7 + 6) = 0;
    *(undefined *)(iVar7 + 1) = 0;
    *(undefined *)(iVar7 + 2) = 0;
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x2c) = 0xffffffff;
    *(uint *)(iVar7 + 0x14) = uVar1;
    uVar1 = uVar1 & 1;
    *(uint *)(iVar7 + 0x14) = uVar1;
    if (param_7 != 0) {
      uVar1 = uVar1 | param_7;
    }
    *(uint *)(iVar7 + 0x14) = uVar1;
    break;
  case 1:
    *(undefined *)(iVar7 + 5) = 0;
    *(undefined *)(iVar7 + 2) = 0;
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
  case 2:
    *(undefined *)(iVar7 + 6) = 0;
    *(undefined *)(iVar7 + 1) = 0;
    *(undefined4 *)(iVar7 + 0x2c) = 0xffffffff;
  default:
    if ((param_2 != 0xd) && (*(char *)(iVar7 + 6) == '\r')) {
      *(undefined *)(iVar7 + 1) = 0;
      *(undefined *)(iVar7 + 3) = 1;
      *(undefined *)(iVar7 + 4) = 1;
    }
  case 5:
    if ((((longlong)*(char *)(iVar7 + 5) == param_2) &&
        ((longlong)*(int *)(iVar7 + 0x1c) == param_3)) &&
       (((longlong)*(int *)(iVar7 + 0x20) == param_4 && (*(int *)(iVar7 + 0x24) == param_5)))) {
    }
  case 0x10:
    if (((param_2 == (longlong)*(char *)(iVar7 + 6)) &&
        (param_3 == (longlong)*(int *)(iVar7 + 0x2c))) &&
       (param_4 == (longlong)*(int *)(iVar7 + 0x30))) {
    }
LAB_block_3__8013ac3c:
    if ((param_2 != 5) && (*(char *)(iVar7 + 5) == '\x05')) {
      *(undefined *)(iVar7 + 5) = 0;
    }
    if (iVar6 - 4U < 2) {
      *(undefined *)(iVar7 + 5) = (char)param_2;
      *(int *)(iVar7 + 0x1c) = iVar4;
      *(undefined4 *)(iVar7 + 0x20) = (int)param_4;
      *(int *)(iVar7 + 0x24) = param_5;
      *(int *)(iVar7 + 0x28) = param_6;
    }
    else {
      if (iVar6 - 6U < 0xb) {
        *(undefined *)(iVar7 + 6) = (char)param_2;
        *(int *)(iVar7 + 0x2c) = iVar4;
        *(undefined4 *)(iVar7 + 0x30) = (int)param_4;
        *(int *)(iVar7 + 0x34) = param_5;
        *(int *)(iVar7 + 0x38) = param_6;
      }
    }
    uVar1 = *(uint *)(iVar7 + 0x14) & 1;
    *(uint *)(iVar7 + 0x14) = uVar1;
    if (param_7 != 0) {
      *(uint *)(iVar7 + 0x14) = uVar1 | param_7;
    }
    *(undefined *)(iVar7 + 1) = 0;
    if (iVar6 - 3U < 0xe) {
      uVar3 = (undefined)((ulonglong)param_4 >> 8);
      uVar5 = (undefined)((ulonglong)param_4 >> 0x10);
      uVar5 = (undefined)((ulonglong)param_4 >> 0x18);
      switch(iVar6) {
      case 3:
        *(undefined *)(iVar7 + 1) = 0;
        *(undefined *)(iVar7 + 2) = 0;
      case 4:
        *(undefined *)(iVar7 + 3) = 4;
        *(undefined *)(iVar7 + 4) = 4;
        *(undefined *)(iVar7 + 1) = 1;
      case 5:
        *(undefined *)(iVar7 + 1) = 2;
        *(undefined *)(iVar7 + 2) = 0xb;
        *(undefined4 *)(iVar7 + 0x3c) = 0;
        *(undefined4 *)(iVar7 + 0x40) = 0;
        *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x200;
        break;
      default:
        if (((param_3 < 0xff) || (param_4 < 0xff)) || (param_5 < 0xff)) {
          if (0xfe < param_6) {
            *(undefined *)(iVar7 + 2) = 1;
            return;
          }
        }
        else {
          if (0xfe < param_6) {
            *(undefined *)(iVar7 + 2) = 0;
            return;
          }
        }
        if (((param_3 < 0xff) || (param_4 < 0xff)) || (param_5 < 0xff)) {
          *(undefined *)(iVar7 + 2) = 3;
        }
        else {
          *(undefined *)(iVar7 + 2) = 2;
        }
        break;
      case 9:
      case 10:
        if ((double)param_6 == DAT_block_3__80151030) {
          *(undefined *)(iVar7 + 2) = 4;
        }
        else {
          *(undefined *)(iVar7 + 2) = 5;
        }
        break;
      case 0xb:
        if (param_3 < (longlong)(ulonglong)*(ushort *)(iVar7 + 0x60)) {
          iVar4 = iVar4 * 4;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c)) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 1) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 2) = uVar3;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 3) = (char)param_4;
          *(undefined *)(iVar7 + 1) = 0;
          if ((param_4 & 0xffU) == 0xff) {
            *(undefined *)(iVar7 + 2) = 6;
          }
          else {
            *(undefined *)(iVar7 + 2) = 8;
          }
        }
        break;
      case 0xc:
        if (param_3 < (longlong)(ulonglong)*(ushort *)(iVar7 + 0x60)) {
          iVar4 = iVar4 * 4;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c)) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 1) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 2) = uVar3;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 3) = (char)param_4;
          *(undefined *)(iVar7 + 1) = 0;
          if ((param_4 & 0xffU) == 0xff) {
            *(undefined *)(iVar7 + 2) = 9;
          }
          else {
            *(undefined *)(iVar7 + 2) = 10;
          }
        }
        break;
      case 0xd:
        *(undefined *)(iVar7 + 2) = 0xc;
        break;
      case 0xe:
        *(undefined *)(iVar7 + 2) = 0xd;
        break;
      case 0xf:
      case 0x10:
        *(undefined *)(iVar7 + 1) = 4;
        uVar3 = 0xf;
        if (0xfe < param_4) {
          uVar3 = 0xe;
        }
        *(undefined *)(iVar7 + 2) = uVar3;
        *(undefined4 *)(iVar7 + 0x4c) = 0;
        *(undefined4 *)(iVar7 + 0x50) = 0;
      }
    }
    break;
  case 0x11:
    if (*(int *)(iVar7 + 0x5c) != 0) {
      FUN_8002ad2c(*(int *)(iVar7 + 0x5c));
    }
    *(undefined2 *)(iVar7 + 0x60) = (short)(iVar4 << 2);
    ppiVar2 = FUN_8002ace4(iVar4 << 2 & 0xffff);
    *(int ***)(iVar7 + 0x5c) = ppiVar2;
  }
  return;
}

**********************************************************
**********************************************************
**********************************************************
**********************************************************
**********************************************************
**********************************************************
**********************************************************
**********************************************************

src from ghidra

WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_block_3__8013aa9c
               (ulonglong param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,
               int param_6,uint param_7)

{
  uint uVar1;
  int **ppiVar2;
  undefined uVar3;
  int iVar4;
  undefined uVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = _DAT_80156954 + (int)param_1 * 0x7c;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    return;
  }
  if (0x59 < param_1) {
    return;
  }
  iVar6 = (int)param_2;
  iVar4 = (int)param_3;
  switch(iVar6) {
  case 0:
  case 3:
    uVar1 = *(uint *)(iVar7 + 0x14);
    FUN_block_3__8013a93c(iVar7);
    FUN_block_3__8013a9e8(iVar7);
    *(undefined *)(iVar7 + 5) = 0;
    *(undefined *)(iVar7 + 6) = 0;
    *(undefined *)(iVar7 + 1) = 0;
    *(undefined *)(iVar7 + 2) = 0;
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x2c) = 0xffffffff;
    *(uint *)(iVar7 + 0x14) = uVar1;
    uVar1 = uVar1 & 1;
    *(uint *)(iVar7 + 0x14) = uVar1;
    if (param_7 != 0) {
      uVar1 = uVar1 | param_7;
    }
    *(uint *)(iVar7 + 0x14) = uVar1;
    break;
  case 1:
    *(undefined *)(iVar7 + 5) = 0;
    *(undefined *)(iVar7 + 2) = 0;
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    break;
  case 2:
    *(undefined *)(iVar7 + 6) = 0;
    *(undefined *)(iVar7 + 1) = 0;
    *(undefined4 *)(iVar7 + 0x2c) = 0xffffffff;
    break;
  default:
    if ((param_2 != 0xd) && (*(char *)(iVar7 + 6) == '\r')) {
      *(undefined *)(iVar7 + 1) = 0;
      *(undefined *)(iVar7 + 3) = 1;
      *(undefined *)(iVar7 + 4) = 1;
    }
    goto LAB_block_3__8013ac3c;
  case 5:
    if ((((longlong)*(char *)(iVar7 + 5) == param_2) &&
        ((longlong)*(int *)(iVar7 + 0x1c) == param_3)) &&
       (((longlong)*(int *)(iVar7 + 0x20) == param_4 && (*(int *)(iVar7 + 0x24) == param_5)))) {
      return;
    }
    goto LAB_block_3__8013ac3c;
  case 0xf:
  case 0x10:
    if (((param_2 == (longlong)*(char *)(iVar7 + 6)) &&
        (param_3 == (longlong)*(int *)(iVar7 + 0x2c))) &&
       (param_4 == (longlong)*(int *)(iVar7 + 0x30))) {
      return;
    }
LAB_block_3__8013ac3c:
    if ((param_2 != 5) && (*(char *)(iVar7 + 5) == '\x05')) {
      *(undefined *)(iVar7 + 5) = 0;
    }
    if (iVar6 - 4U < 2) {
      *(undefined *)(iVar7 + 5) = (char)param_2;
      *(int *)(iVar7 + 0x1c) = iVar4;
      *(undefined4 *)(iVar7 + 0x20) = (int)param_4;
      *(int *)(iVar7 + 0x24) = param_5;
      *(int *)(iVar7 + 0x28) = param_6;
    }
    else {
      if (iVar6 - 6U < 0xb) {
        *(undefined *)(iVar7 + 6) = (char)param_2;
        *(int *)(iVar7 + 0x2c) = iVar4;
        *(undefined4 *)(iVar7 + 0x30) = (int)param_4;
        *(int *)(iVar7 + 0x34) = param_5;
        *(int *)(iVar7 + 0x38) = param_6;
      }
    }
    uVar1 = *(uint *)(iVar7 + 0x14) & 1;
    *(uint *)(iVar7 + 0x14) = uVar1;
    if (param_7 != 0) {
      *(uint *)(iVar7 + 0x14) = uVar1 | param_7;
    }
    *(undefined *)(iVar7 + 1) = 0;
    if (iVar6 - 3U < 0xe) {
      uVar3 = (undefined)((ulonglong)param_4 >> 8);
      uVar5 = (undefined)((ulonglong)param_4 >> 0x10);
      uVar5 = (undefined)((ulonglong)param_4 >> 0x18);
      switch(iVar6) {
      case 3:
        *(undefined *)(iVar7 + 1) = 0;
        *(undefined *)(iVar7 + 2) = 0;
        break;
      case 4:
        *(undefined *)(iVar7 + 3) = 4;
        *(undefined *)(iVar7 + 4) = 4;
        *(undefined *)(iVar7 + 1) = 1;
        FUN_block_3__8013ee48(iVar7);
        break;
      case 5:
        *(undefined *)(iVar7 + 1) = 2;
        *(undefined *)(iVar7 + 2) = 0xb;
        *(undefined4 *)(iVar7 + 0x3c) = 0;
        *(undefined4 *)(iVar7 + 0x40) = 0;
        *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | 0x200;
        break;
      default:
        if (((param_3 < 0xff) || (param_4 < 0xff)) || (param_5 < 0xff)) {
          if (0xfe < param_6) {
            *(undefined *)(iVar7 + 2) = 1;
            return;
          }
        }
        else {
          if (0xfe < param_6) {
            *(undefined *)(iVar7 + 2) = 0;
            return;
          }
        }
        if (((param_3 < 0xff) || (param_4 < 0xff)) || (param_5 < 0xff)) {
          *(undefined *)(iVar7 + 2) = 3;
        }
        else {
          *(undefined *)(iVar7 + 2) = 2;
        }
        break;
      case 9:
      case 10:
        if ((double)param_6 == DAT_block_3__80151030) {
          *(undefined *)(iVar7 + 2) = 4;
        }
        else {
          *(undefined *)(iVar7 + 2) = 5;
        }
        break;
      case 0xb:
        if (param_3 < (longlong)(ulonglong)*(ushort *)(iVar7 + 0x60)) {
          iVar4 = iVar4 * 4;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c)) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 1) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 2) = uVar3;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 3) = (char)param_4;
          *(undefined *)(iVar7 + 1) = 0;
          if ((param_4 & 0xffU) == 0xff) {
            *(undefined *)(iVar7 + 2) = 6;
          }
          else {
            *(undefined *)(iVar7 + 2) = 8;
          }
        }
        break;
      case 0xc:
        if (param_3 < (longlong)(ulonglong)*(ushort *)(iVar7 + 0x60)) {
          iVar4 = iVar4 * 4;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c)) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 1) = uVar5;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 2) = uVar3;
          *(undefined *)(iVar4 + *(int *)(iVar7 + 0x5c) + 3) = (char)param_4;
          *(undefined *)(iVar7 + 1) = 0;
          if ((param_4 & 0xffU) == 0xff) {
            *(undefined *)(iVar7 + 2) = 9;
          }
          else {
            *(undefined *)(iVar7 + 2) = 10;
          }
        }
        break;
      case 0xd:
        *(undefined *)(iVar7 + 2) = 0xc;
        break;
      case 0xe:
        *(undefined *)(iVar7 + 2) = 0xd;
        break;
      case 0xf:
      case 0x10:
        *(undefined *)(iVar7 + 1) = 4;
        uVar3 = 0xf;
        if (0xfe < param_4) {
          uVar3 = 0xe;
        }
        *(undefined *)(iVar7 + 2) = uVar3;
        *(undefined4 *)(iVar7 + 0x4c) = 0;
        *(undefined4 *)(iVar7 + 0x50) = 0;
      }
    }
    break;
  case 0x11:
    if (*(int *)(iVar7 + 0x5c) != 0) {
      FUN_8002ad2c(*(int *)(iVar7 + 0x5c));
    }
    *(undefined2 *)(iVar7 + 0x60) = (short)(iVar4 << 2);
    ppiVar2 = FUN_8002ace4(iVar4 << 2 & 0xffff);
    *(int ***)(iVar7 + 0x5c) = ppiVar2;
  }
  return;
}

block_3::8013af94		FUN_block_3__8013af70	lw v1,offset DAT_80156954(v1) no access
block_3::8013d3a4		FUN_block_3__8013cfa8	lw v0,offset DAT_80156954(v0) no access
block_3::8013d954		FUN_block_3__8013cfa8	lw v0,offset DAT_80156954(v0) no access
block_3::8013dc3c		FUN_block_3__8013dab4	lw v0,offset DAT_80156954(v0) no access
*/

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A888);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A8E0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A920);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A93C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A9C8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013A9E8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AA9C);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AF20);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013AF70);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013B0EC);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013B1B0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013BC88);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C048);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C220);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013C3F0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013CFA8);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013DAB4);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013E2F0);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013E904);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013EE48);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013EE68);

INCLUDE_ASM(s32, "code_d0a70_len_4fe0", func_8013F1F8);
