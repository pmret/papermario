.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802194E0_5B2990
/* 5B2990 802194E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2994 802194E4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2998 802194E8 0000902D */  daddu     $s2, $zero, $zero
/* 5B299C 802194EC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B29A0 802194F0 0240882D */  daddu     $s1, $s2, $zero
/* 5B29A4 802194F4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B29A8 802194F8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B29AC 802194FC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B29B0 80219500 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B29B4 80219504 3C108023 */  lui       $s0, %hi(D_80231678)
/* 5B29B8 80219508 26101678 */  addiu     $s0, $s0, %lo(D_80231678)
/* 5B29BC 8021950C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219510:
/* 5B29C0 80219510 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B29C4 80219514 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B29C8 80219518 8E050000 */  lw        $a1, ($s0)
/* 5B29CC 8021951C 84430086 */  lh        $v1, 0x86($v0)
/* 5B29D0 80219520 8442008C */  lh        $v0, 0x8c($v0)
/* 5B29D4 80219524 00031900 */  sll       $v1, $v1, 4
/* 5B29D8 80219528 00731821 */  addu      $v1, $v1, $s3
/* 5B29DC 8021952C 8C630004 */  lw        $v1, 4($v1)
/* 5B29E0 80219530 00021140 */  sll       $v0, $v0, 5
/* 5B29E4 80219534 00431021 */  addu      $v0, $v0, $v1
/* 5B29E8 80219538 0C01BB5C */  jal       strcmp
/* 5B29EC 8021953C 8C440000 */   lw       $a0, ($v0)
/* 5B29F0 80219540 14400003 */  bnez      $v0, .L80219550
/* 5B29F4 80219544 26310001 */   addiu    $s1, $s1, 1
/* 5B29F8 80219548 08086557 */  j         .L8021955C
/* 5B29FC 8021954C 24120001 */   addiu    $s2, $zero, 1
.L80219550:
/* 5B2A00 80219550 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2A04 80219554 1440FFEE */  bnez      $v0, .L80219510
/* 5B2A08 80219558 26100004 */   addiu    $s0, $s0, 4
.L8021955C:
/* 5B2A0C 8021955C 44800000 */  mtc1      $zero, $f0
/* 5B2A10 80219560 00000000 */  nop
/* 5B2A14 80219564 44050000 */  mfc1      $a1, $f0
/* 5B2A18 80219568 0240202D */  daddu     $a0, $s2, $zero
/* 5B2A1C 8021956C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2A20 80219570 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2A24 80219574 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2A28 80219578 0C01CA54 */  jal       func_80072950
/* 5B2A2C 8021957C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2A30 80219580 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2A34 80219584 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2A38 80219588 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2A3C 8021958C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2A40 80219590 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2A44 80219594 24020002 */  addiu     $v0, $zero, 2
/* 5B2A48 80219598 03E00008 */  jr        $ra
/* 5B2A4C 8021959C 27BD0030 */   addiu    $sp, $sp, 0x30
