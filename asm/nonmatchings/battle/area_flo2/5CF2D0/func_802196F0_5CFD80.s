.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802196F0_5CFD80
/* 5CFD80 802196F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CFD84 802196F4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CFD88 802196F8 0000902D */  daddu     $s2, $zero, $zero
/* 5CFD8C 802196FC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CFD90 80219700 0240882D */  daddu     $s1, $s2, $zero
/* 5CFD94 80219704 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CFD98 80219708 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CFD9C 8021970C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CFDA0 80219710 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CFDA4 80219714 3C108023 */  lui       $s0, %hi(D_802353E0_5EBA70)
/* 5CFDA8 80219718 261053E0 */  addiu     $s0, $s0, %lo(D_802353E0_5EBA70)
/* 5CFDAC 8021971C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219720:
/* 5CFDB0 80219720 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CFDB4 80219724 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CFDB8 80219728 8E050000 */  lw        $a1, ($s0)
/* 5CFDBC 8021972C 84430086 */  lh        $v1, 0x86($v0)
/* 5CFDC0 80219730 8442008C */  lh        $v0, 0x8c($v0)
/* 5CFDC4 80219734 00031900 */  sll       $v1, $v1, 4
/* 5CFDC8 80219738 00731821 */  addu      $v1, $v1, $s3
/* 5CFDCC 8021973C 8C630004 */  lw        $v1, 4($v1)
/* 5CFDD0 80219740 00021140 */  sll       $v0, $v0, 5
/* 5CFDD4 80219744 00431021 */  addu      $v0, $v0, $v1
/* 5CFDD8 80219748 0C01BB5C */  jal       strcmp
/* 5CFDDC 8021974C 8C440000 */   lw       $a0, ($v0)
/* 5CFDE0 80219750 14400003 */  bnez      $v0, .L80219760
/* 5CFDE4 80219754 26310001 */   addiu    $s1, $s1, 1
/* 5CFDE8 80219758 080865DB */  j         .L8021976C
/* 5CFDEC 8021975C 24120001 */   addiu    $s2, $zero, 1
.L80219760:
/* 5CFDF0 80219760 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CFDF4 80219764 1440FFEE */  bnez      $v0, .L80219720
/* 5CFDF8 80219768 26100004 */   addiu    $s0, $s0, 4
.L8021976C:
/* 5CFDFC 8021976C 44800000 */  mtc1      $zero, $f0
/* 5CFE00 80219770 00000000 */  nop
/* 5CFE04 80219774 44050000 */  mfc1      $a1, $f0
/* 5CFE08 80219778 0240202D */  daddu     $a0, $s2, $zero
/* 5CFE0C 8021977C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CFE10 80219780 00A0302D */  daddu     $a2, $a1, $zero
/* 5CFE14 80219784 00A0382D */  daddu     $a3, $a1, $zero
/* 5CFE18 80219788 0C01CA54 */  jal       func_80072950
/* 5CFE1C 8021978C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CFE20 80219790 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CFE24 80219794 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CFE28 80219798 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CFE2C 8021979C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CFE30 802197A0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CFE34 802197A4 24020002 */  addiu     $v0, $zero, 2
/* 5CFE38 802197A8 03E00008 */  jr        $ra
/* 5CFE3C 802197AC 27BD0030 */   addiu    $sp, $sp, 0x30
