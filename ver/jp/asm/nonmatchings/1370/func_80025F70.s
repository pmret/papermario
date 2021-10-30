.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025F70
/* 1370 80025F70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1374 80025F74 3C038000 */  lui       $v1, %hi(osTvType)
/* 1378 80025F78 8C630300 */  lw        $v1, %lo(osTvType)($v1)
/* 137C 80025F7C 24020001 */  addiu     $v0, $zero, 1
/* 1380 80025F80 1462000D */  bne       $v1, $v0, .L80025FB8
/* 1384 80025F84 AFBF0010 */   sw       $ra, 0x10($sp)
/* 1388 80025F88 0C017C2C */  jal       func_8005F0B0
/* 138C 80025F8C 00000000 */   nop
/* 1390 80025F90 3C048009 */  lui       $a0, %hi(D_80095800)
/* 1394 80025F94 24845800 */  addiu     $a0, $a0, %lo(D_80095800)
/* 1398 80025F98 0C019B78 */  jal       func_80066DE0
/* 139C 80025F9C 00000000 */   nop
/* 13A0 80025FA0 0C019B8C */  jal       func_80066E30
/* 13A4 80025FA4 2404005A */   addiu    $a0, $zero, 0x5a
/* 13A8 80025FA8 0C017C2C */  jal       func_8005F0B0
/* 13AC 80025FAC 00000000 */   nop
/* 13B0 80025FB0 080097F0 */  j         .L80025FC0
/* 13B4 80025FB4 00000000 */   nop
.L80025FB8:
/* 13B8 80025FB8 080097EE */  j         .L80025FB8
/* 13BC 80025FBC 00000000 */   nop
.L80025FC0:
/* 13C0 80025FC0 0C009718 */  jal       is_debug_init
/* 13C4 80025FC4 00000000 */   nop
/* 13C8 80025FC8 0C017C84 */  jal       func_8005F210
/* 13CC 80025FCC 00000000 */   nop
/* 13D0 80025FD0 0C017CB0 */  jal       func_8005F2C0
/* 13D4 80025FD4 00000000 */   nop
/* 13D8 80025FD8 3C038007 */  lui       $v1, %hi(D_8007417C)
/* 13DC 80025FDC 8C63417C */  lw        $v1, %lo(D_8007417C)($v1)
/* 13E0 80025FE0 0C00B280 */  jal       func_8002CA00
/* 13E4 80025FE4 A0620073 */   sb       $v0, 0x73($v1)
/* 13E8 80025FE8 0C0AC800 */  jal       func_802B2000
/* 13EC 80025FEC 00000000 */   nop
/* 13F0 80025FF0 0C0AC80F */  jal       func_802B203C
/* 13F4 80025FF4 00000000 */   nop
/* 13F8 80025FF8 3C048002 */  lui       $a0, %hi(D_80026040)
/* 13FC 80025FFC 24846040 */  addiu     $a0, $a0, %lo(D_80026040)
/* 1400 80026000 0C017BC0 */  jal       func_8005EF00
/* 1404 80026004 00000000 */   nop
/* 1408 80026008 3C048002 */  lui       $a0, %hi(gfxPreNMI_Callback)
/* 140C 8002600C 248466E8 */  addiu     $a0, $a0, %lo(gfxPreNMI_Callback)
/* 1410 80026010 0C017BD0 */  jal       func_8005EF40
/* 1414 80026014 00000000 */   nop
/* 1418 80026018 0C019674 */  jal       func_800659D0
/* 141C 8002601C 00000000 */   nop
/* 1420 80026020 3C048007 */  lui       $a0, %hi(gRandSeed)
/* 1424 80026024 248443F0 */  addiu     $a0, $a0, %lo(gRandSeed)
/* 1428 80026028 8C830000 */  lw        $v1, ($a0)
/* 142C 8002602C 00621821 */  addu      $v1, $v1, $v0
/* 1430 80026030 0C017C38 */  jal       func_8005F0E0
/* 1434 80026034 AC830000 */   sw       $v1, ($a0)
.L80026038:
/* 1438 80026038 0800980E */  j         .L80026038
/* 143C 8002603C 00000000 */   nop
