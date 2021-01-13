.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DD0_5CF460
/* 5CF460 80218DD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF464 80218DD4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF468 80218DD8 0000902D */  daddu     $s2, $zero, $zero
/* 5CF46C 80218DDC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF470 80218DE0 0240882D */  daddu     $s1, $s2, $zero
/* 5CF474 80218DE4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF478 80218DE8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF47C 80218DEC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF480 80218DF0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF484 80218DF4 3C108023 */  lui       $s0, %hi(D_80232D48)
/* 5CF488 80218DF8 26102D48 */  addiu     $s0, $s0, %lo(D_80232D48)
/* 5CF48C 80218DFC AFBF0028 */  sw        $ra, 0x28($sp)
.L80218E00:
/* 5CF490 80218E00 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF494 80218E04 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF498 80218E08 8E050000 */  lw        $a1, ($s0)
/* 5CF49C 80218E0C 84430086 */  lh        $v1, 0x86($v0)
/* 5CF4A0 80218E10 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF4A4 80218E14 00031900 */  sll       $v1, $v1, 4
/* 5CF4A8 80218E18 00731821 */  addu      $v1, $v1, $s3
/* 5CF4AC 80218E1C 8C630004 */  lw        $v1, 4($v1)
/* 5CF4B0 80218E20 00021140 */  sll       $v0, $v0, 5
/* 5CF4B4 80218E24 00431021 */  addu      $v0, $v0, $v1
/* 5CF4B8 80218E28 0C01BB5C */  jal       strcmp
/* 5CF4BC 80218E2C 8C440000 */   lw       $a0, ($v0)
/* 5CF4C0 80218E30 14400003 */  bnez      $v0, .L80218E40
/* 5CF4C4 80218E34 26310001 */   addiu    $s1, $s1, 1
/* 5CF4C8 80218E38 08086393 */  j         .L80218E4C
/* 5CF4CC 80218E3C 24120001 */   addiu    $s2, $zero, 1
.L80218E40:
/* 5CF4D0 80218E40 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF4D4 80218E44 1440FFEE */  bnez      $v0, .L80218E00
/* 5CF4D8 80218E48 26100004 */   addiu    $s0, $s0, 4
.L80218E4C:
/* 5CF4DC 80218E4C 44800000 */  mtc1      $zero, $f0
/* 5CF4E0 80218E50 00000000 */  nop
/* 5CF4E4 80218E54 44050000 */  mfc1      $a1, $f0
/* 5CF4E8 80218E58 0240202D */  daddu     $a0, $s2, $zero
/* 5CF4EC 80218E5C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF4F0 80218E60 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF4F4 80218E64 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF4F8 80218E68 0C01CA54 */  jal       func_80072950
/* 5CF4FC 80218E6C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF500 80218E70 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF504 80218E74 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF508 80218E78 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF50C 80218E7C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF510 80218E80 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF514 80218E84 24020002 */  addiu     $v0, $zero, 2
/* 5CF518 80218E88 03E00008 */  jr        $ra
/* 5CF51C 80218E8C 27BD0030 */   addiu    $sp, $sp, 0x30
