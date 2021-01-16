.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802198A0_5B2D50
/* 5B2D50 802198A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2D54 802198A4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2D58 802198A8 0000902D */  daddu     $s2, $zero, $zero
/* 5B2D5C 802198AC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B2D60 802198B0 0240882D */  daddu     $s1, $s2, $zero
/* 5B2D64 802198B4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B2D68 802198B8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B2D6C 802198BC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B2D70 802198C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B2D74 802198C4 3C108023 */  lui       $s0, %hi(D_80232BE8)
/* 5B2D78 802198C8 26102BE8 */  addiu     $s0, $s0, %lo(D_80232BE8)
/* 5B2D7C 802198CC AFBF0028 */  sw        $ra, 0x28($sp)
.L802198D0:
/* 5B2D80 802198D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2D84 802198D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2D88 802198D8 8E050000 */  lw        $a1, ($s0)
/* 5B2D8C 802198DC 84430086 */  lh        $v1, 0x86($v0)
/* 5B2D90 802198E0 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2D94 802198E4 00031900 */  sll       $v1, $v1, 4
/* 5B2D98 802198E8 00731821 */  addu      $v1, $v1, $s3
/* 5B2D9C 802198EC 8C630004 */  lw        $v1, 4($v1)
/* 5B2DA0 802198F0 00021140 */  sll       $v0, $v0, 5
/* 5B2DA4 802198F4 00431021 */  addu      $v0, $v0, $v1
/* 5B2DA8 802198F8 0C01BB5C */  jal       strcmp
/* 5B2DAC 802198FC 8C440000 */   lw       $a0, ($v0)
/* 5B2DB0 80219900 14400003 */  bnez      $v0, .L80219910
/* 5B2DB4 80219904 26310001 */   addiu    $s1, $s1, 1
/* 5B2DB8 80219908 08086647 */  j         .L8021991C
/* 5B2DBC 8021990C 24120001 */   addiu    $s2, $zero, 1
.L80219910:
/* 5B2DC0 80219910 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2DC4 80219914 1440FFEE */  bnez      $v0, .L802198D0
/* 5B2DC8 80219918 26100004 */   addiu    $s0, $s0, 4
.L8021991C:
/* 5B2DCC 8021991C 44800000 */  mtc1      $zero, $f0
/* 5B2DD0 80219920 00000000 */  nop
/* 5B2DD4 80219924 44050000 */  mfc1      $a1, $f0
/* 5B2DD8 80219928 0240202D */  daddu     $a0, $s2, $zero
/* 5B2DDC 8021992C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2DE0 80219930 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2DE4 80219934 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2DE8 80219938 0C01CA54 */  jal       func_80072950
/* 5B2DEC 8021993C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2DF0 80219940 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2DF4 80219944 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2DF8 80219948 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2DFC 8021994C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2E00 80219950 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2E04 80219954 24020002 */  addiu     $v0, $zero, 2
/* 5B2E08 80219958 03E00008 */  jr        $ra
/* 5B2E0C 8021995C 27BD0030 */   addiu    $sp, $sp, 0x30
