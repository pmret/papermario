.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219720_5B2BD0
/* 5B2BD0 80219720 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2BD4 80219724 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2BD8 80219728 0000902D */  daddu     $s2, $zero, $zero
/* 5B2BDC 8021972C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B2BE0 80219730 0240882D */  daddu     $s1, $s2, $zero
/* 5B2BE4 80219734 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B2BE8 80219738 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B2BEC 8021973C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B2BF0 80219740 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B2BF4 80219744 3C108023 */  lui       $s0, %hi(D_80232428_5CB8D8)
/* 5B2BF8 80219748 26102428 */  addiu     $s0, $s0, %lo(D_80232428_5CB8D8)
/* 5B2BFC 8021974C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219750:
/* 5B2C00 80219750 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2C04 80219754 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2C08 80219758 8E050000 */  lw        $a1, ($s0)
/* 5B2C0C 8021975C 84430086 */  lh        $v1, 0x86($v0)
/* 5B2C10 80219760 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2C14 80219764 00031900 */  sll       $v1, $v1, 4
/* 5B2C18 80219768 00731821 */  addu      $v1, $v1, $s3
/* 5B2C1C 8021976C 8C630004 */  lw        $v1, 4($v1)
/* 5B2C20 80219770 00021140 */  sll       $v0, $v0, 5
/* 5B2C24 80219774 00431021 */  addu      $v0, $v0, $v1
/* 5B2C28 80219778 0C01BB5C */  jal       strcmp
/* 5B2C2C 8021977C 8C440000 */   lw       $a0, ($v0)
/* 5B2C30 80219780 14400003 */  bnez      $v0, .L80219790
/* 5B2C34 80219784 26310001 */   addiu    $s1, $s1, 1
/* 5B2C38 80219788 080865E7 */  j         .L8021979C
/* 5B2C3C 8021978C 24120001 */   addiu    $s2, $zero, 1
.L80219790:
/* 5B2C40 80219790 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2C44 80219794 1440FFEE */  bnez      $v0, .L80219750
/* 5B2C48 80219798 26100004 */   addiu    $s0, $s0, 4
.L8021979C:
/* 5B2C4C 8021979C 44800000 */  mtc1      $zero, $f0
/* 5B2C50 802197A0 00000000 */  nop
/* 5B2C54 802197A4 44050000 */  mfc1      $a1, $f0
/* 5B2C58 802197A8 0240202D */  daddu     $a0, $s2, $zero
/* 5B2C5C 802197AC AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2C60 802197B0 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2C64 802197B4 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2C68 802197B8 0C01CA54 */  jal       func_80072950
/* 5B2C6C 802197BC AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2C70 802197C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2C74 802197C4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2C78 802197C8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2C7C 802197CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2C80 802197D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2C84 802197D4 24020002 */  addiu     $v0, $zero, 2
/* 5B2C88 802197D8 03E00008 */  jr        $ra
/* 5B2C8C 802197DC 27BD0030 */   addiu    $sp, $sp, 0x30
