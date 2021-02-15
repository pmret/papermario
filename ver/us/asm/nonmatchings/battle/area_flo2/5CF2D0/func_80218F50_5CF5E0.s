.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218F50_5CF5E0
/* 5CF5E0 80218F50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF5E4 80218F54 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF5E8 80218F58 0000902D */  daddu     $s2, $zero, $zero
/* 5CF5EC 80218F5C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF5F0 80218F60 0240882D */  daddu     $s1, $s2, $zero
/* 5CF5F4 80218F64 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF5F8 80218F68 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF5FC 80218F6C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF600 80218F70 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF604 80218F74 3C108023 */  lui       $s0, %hi(D_80233678_5E9D08)
/* 5CF608 80218F78 26103678 */  addiu     $s0, $s0, %lo(D_80233678_5E9D08)
/* 5CF60C 80218F7C AFBF0028 */  sw        $ra, 0x28($sp)
.L80218F80:
/* 5CF610 80218F80 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF614 80218F84 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF618 80218F88 8E050000 */  lw        $a1, ($s0)
/* 5CF61C 80218F8C 84430086 */  lh        $v1, 0x86($v0)
/* 5CF620 80218F90 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF624 80218F94 00031900 */  sll       $v1, $v1, 4
/* 5CF628 80218F98 00731821 */  addu      $v1, $v1, $s3
/* 5CF62C 80218F9C 8C630004 */  lw        $v1, 4($v1)
/* 5CF630 80218FA0 00021140 */  sll       $v0, $v0, 5
/* 5CF634 80218FA4 00431021 */  addu      $v0, $v0, $v1
/* 5CF638 80218FA8 0C01BB5C */  jal       strcmp
/* 5CF63C 80218FAC 8C440000 */   lw       $a0, ($v0)
/* 5CF640 80218FB0 14400003 */  bnez      $v0, .L80218FC0
/* 5CF644 80218FB4 26310001 */   addiu    $s1, $s1, 1
/* 5CF648 80218FB8 080863F3 */  j         .L80218FCC
/* 5CF64C 80218FBC 24120001 */   addiu    $s2, $zero, 1
.L80218FC0:
/* 5CF650 80218FC0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF654 80218FC4 1440FFEE */  bnez      $v0, .L80218F80
/* 5CF658 80218FC8 26100004 */   addiu    $s0, $s0, 4
.L80218FCC:
/* 5CF65C 80218FCC 44800000 */  mtc1      $zero, $f0
/* 5CF660 80218FD0 00000000 */  nop
/* 5CF664 80218FD4 44050000 */  mfc1      $a1, $f0
/* 5CF668 80218FD8 0240202D */  daddu     $a0, $s2, $zero
/* 5CF66C 80218FDC AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF670 80218FE0 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF674 80218FE4 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF678 80218FE8 0C01CA54 */  jal       func_80072950
/* 5CF67C 80218FEC AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF680 80218FF0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF684 80218FF4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF688 80218FF8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF68C 80218FFC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF690 80219000 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF694 80219004 24020002 */  addiu     $v0, $zero, 2
/* 5CF698 80219008 03E00008 */  jr        $ra
/* 5CF69C 8021900C 27BD0030 */   addiu    $sp, $sp, 0x30
