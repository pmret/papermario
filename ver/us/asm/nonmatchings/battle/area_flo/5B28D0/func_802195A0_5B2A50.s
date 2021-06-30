.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802195A0_5B2A50
/* 5B2A50 802195A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2A54 802195A4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2A58 802195A8 0000902D */  daddu     $s2, $zero, $zero
/* 5B2A5C 802195AC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B2A60 802195B0 0240882D */  daddu     $s1, $s2, $zero
/* 5B2A64 802195B4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B2A68 802195B8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B2A6C 802195BC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B2A70 802195C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B2A74 802195C4 3C108023 */  lui       $s0, %hi(D_80231B08_5CAFB8)
/* 5B2A78 802195C8 26101B08 */  addiu     $s0, $s0, %lo(D_80231B08_5CAFB8)
/* 5B2A7C 802195CC AFBF0028 */  sw        $ra, 0x28($sp)
.L802195D0:
/* 5B2A80 802195D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2A84 802195D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2A88 802195D8 8E050000 */  lw        $a1, ($s0)
/* 5B2A8C 802195DC 84430086 */  lh        $v1, 0x86($v0)
/* 5B2A90 802195E0 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2A94 802195E4 00031900 */  sll       $v1, $v1, 4
/* 5B2A98 802195E8 00731821 */  addu      $v1, $v1, $s3
/* 5B2A9C 802195EC 8C630004 */  lw        $v1, 4($v1)
/* 5B2AA0 802195F0 00021140 */  sll       $v0, $v0, 5
/* 5B2AA4 802195F4 00431021 */  addu      $v0, $v0, $v1
/* 5B2AA8 802195F8 0C01BB5C */  jal       strcmp
/* 5B2AAC 802195FC 8C440000 */   lw       $a0, ($v0)
/* 5B2AB0 80219600 14400003 */  bnez      $v0, .L80219610
/* 5B2AB4 80219604 26310001 */   addiu    $s1, $s1, 1
/* 5B2AB8 80219608 08086587 */  j         .L8021961C
/* 5B2ABC 8021960C 24120001 */   addiu    $s2, $zero, 1
.L80219610:
/* 5B2AC0 80219610 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2AC4 80219614 1440FFEE */  bnez      $v0, .L802195D0
/* 5B2AC8 80219618 26100004 */   addiu    $s0, $s0, 4
.L8021961C:
/* 5B2ACC 8021961C 44800000 */  mtc1      $zero, $f0
/* 5B2AD0 80219620 00000000 */  nop
/* 5B2AD4 80219624 44050000 */  mfc1      $a1, $f0
/* 5B2AD8 80219628 0240202D */  daddu     $a0, $s2, $zero
/* 5B2ADC 8021962C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2AE0 80219630 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2AE4 80219634 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2AE8 80219638 0C01CA54 */  jal       playFX_82
/* 5B2AEC 8021963C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2AF0 80219640 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2AF4 80219644 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2AF8 80219648 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2AFC 8021964C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2B00 80219650 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2B04 80219654 24020002 */  addiu     $v0, $zero, 2
/* 5B2B08 80219658 03E00008 */  jr        $ra
/* 5B2B0C 8021965C 27BD0030 */   addiu    $sp, $sp, 0x30
