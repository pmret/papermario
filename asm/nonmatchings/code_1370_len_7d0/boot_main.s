.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel boot_main
/* 1370 80025F70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1374 80025F74 3C038000 */  lui       $v1, 0x8000
/* 1378 80025F78 8C630300 */  lw        $v1, 0x300($v1)
/* 137C 80025F7C 24020001 */  addiu     $v0, $zero, 1
/* 1380 80025F80 14620005 */  bne       $v1, $v0, .L80025F98
/* 1384 80025F84 AFBF0010 */   sw       $ra, 0x10($sp)
/* 1388 80025F88 3C048009 */  lui       $a0, 0x8009
/* 138C 80025F8C 24845820 */  addiu     $a0, $a0, 0x5820
/* 1390 80025F90 080097EB */  j         .L80025FAC
/* 1394 80025F94 00000000 */   nop
.L80025F98:
/* 1398 80025F98 24020002 */  addiu     $v0, $zero, 2
/* 139C 80025F9C 14620009 */  bne       $v1, $v0, .L80025FC4
/* 13A0 80025FA0 00000000 */   nop
/* 13A4 80025FA4 3C048009 */  lui       $a0, 0x8009
/* 13A8 80025FA8 24845870 */  addiu     $a0, $a0, 0x5870
.L80025FAC:
/* 13AC 80025FAC 0C019B84 */  jal       osViSetMode
/* 13B0 80025FB0 00000000 */   nop
/* 13B4 80025FB4 0C019B98 */  jal       osViSetSpecialFeatures
/* 13B8 80025FB8 2404005A */   addiu    $a0, $zero, 0x5a
/* 13BC 80025FBC 080097F3 */  j         .L80025FCC
/* 13C0 80025FC0 00000000 */   nop
.L80025FC4:
/* 13C4 80025FC4 080097F1 */  j         .L80025FC4
/* 13C8 80025FC8 00000000 */   nop
.L80025FCC:
/* 13CC 80025FCC 0C017D00 */  jal       nuGfxDisplayOff
/* 13D0 80025FD0 00000000 */   nop
/* 13D4 80025FD4 0C00B22C */  jal       crash_create_monitor
/* 13D8 80025FD8 00000000 */   nop
/* 13DC 80025FDC 0C009718 */  jal       func_80025C60
/* 13E0 80025FE0 00000000 */   nop
/* 13E4 80025FE4 0C017D58 */  jal       nuGfxInit
/* 13E8 80025FE8 00000000 */   nop
/* 13EC 80025FEC 0C017D84 */  jal       nuContInit
/* 13F0 80025FF0 00000000 */   nop
/* 13F4 80025FF4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 13F8 80025FF8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 13FC 80025FFC 0C00B458 */  jal       func_8002D160
/* 1400 80026000 A0620073 */   sb       $v0, 0x73($v1)
/* 1404 80026004 0C0AC800 */  jal       func_802B2000
/* 1408 80026008 00000000 */   nop
/* 140C 8002600C 0C0AC80F */  jal       func_802B203C
/* 1410 80026010 00000000 */   nop
/* 1414 80026014 3C048002 */  lui       $a0, 0x8002
/* 1418 80026018 2484605C */  addiu     $a0, $a0, 0x605c
/* 141C 8002601C 0C017C94 */  jal       nuGfxFuncSet
/* 1420 80026020 00000000 */   nop
/* 1424 80026024 3C048002 */  lui       $a0, 0x8002
/* 1428 80026028 2484670C */  addiu     $a0, $a0, 0x670c
/* 142C 8002602C 0C017CA4 */  jal       nuGfxPreNMIFuncSet
/* 1430 80026030 00000000 */   nop
/* 1434 80026034 0C019680 */  jal       osGetCount
/* 1438 80026038 00000000 */   nop
/* 143C 8002603C 3C048007 */  lui       $a0, %hi(gRandSeed)
/* 1440 80026040 24844410 */  addiu     $a0, $a0, %lo(gRandSeed)
/* 1444 80026044 8C830000 */  lw        $v1, ($a0)
/* 1448 80026048 00621821 */  addu      $v1, $v1, $v0
/* 144C 8002604C 0C017D0C */  jal       nuGfxDisplayOn
/* 1450 80026050 AC830000 */   sw       $v1, ($a0)
.L80026054:
/* 1454 80026054 08009815 */  j         .L80026054
/* 1458 80026058 00000000 */   nop
