.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218E90_5CF520
/* 5CF520 80218E90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF524 80218E94 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF528 80218E98 0000902D */  daddu     $s2, $zero, $zero
/* 5CF52C 80218E9C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF530 80218EA0 0240882D */  daddu     $s1, $s2, $zero
/* 5CF534 80218EA4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF538 80218EA8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF53C 80218EAC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF540 80218EB0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF544 80218EB4 3C108023 */  lui       $s0, %hi(D_802331E8_5E9878)
/* 5CF548 80218EB8 261031E8 */  addiu     $s0, $s0, %lo(D_802331E8_5E9878)
/* 5CF54C 80218EBC AFBF0028 */  sw        $ra, 0x28($sp)
.L80218EC0:
/* 5CF550 80218EC0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF554 80218EC4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF558 80218EC8 8E050000 */  lw        $a1, ($s0)
/* 5CF55C 80218ECC 84430086 */  lh        $v1, 0x86($v0)
/* 5CF560 80218ED0 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF564 80218ED4 00031900 */  sll       $v1, $v1, 4
/* 5CF568 80218ED8 00731821 */  addu      $v1, $v1, $s3
/* 5CF56C 80218EDC 8C630004 */  lw        $v1, 4($v1)
/* 5CF570 80218EE0 00021140 */  sll       $v0, $v0, 5
/* 5CF574 80218EE4 00431021 */  addu      $v0, $v0, $v1
/* 5CF578 80218EE8 0C01BB5C */  jal       strcmp
/* 5CF57C 80218EEC 8C440000 */   lw       $a0, ($v0)
/* 5CF580 80218EF0 14400003 */  bnez      $v0, .L80218F00
/* 5CF584 80218EF4 26310001 */   addiu    $s1, $s1, 1
/* 5CF588 80218EF8 080863C3 */  j         .L80218F0C
/* 5CF58C 80218EFC 24120001 */   addiu    $s2, $zero, 1
.L80218F00:
/* 5CF590 80218F00 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF594 80218F04 1440FFEE */  bnez      $v0, .L80218EC0
/* 5CF598 80218F08 26100004 */   addiu    $s0, $s0, 4
.L80218F0C:
/* 5CF59C 80218F0C 44800000 */  mtc1      $zero, $f0
/* 5CF5A0 80218F10 00000000 */  nop
/* 5CF5A4 80218F14 44050000 */  mfc1      $a1, $f0
/* 5CF5A8 80218F18 0240202D */  daddu     $a0, $s2, $zero
/* 5CF5AC 80218F1C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF5B0 80218F20 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF5B4 80218F24 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF5B8 80218F28 0C01CA54 */  jal       func_80072950
/* 5CF5BC 80218F2C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF5C0 80218F30 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF5C4 80218F34 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF5C8 80218F38 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF5CC 80218F3C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF5D0 80218F40 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF5D4 80218F44 24020002 */  addiu     $v0, $zero, 2
/* 5CF5D8 80218F48 03E00008 */  jr        $ra
/* 5CF5DC 80218F4C 27BD0030 */   addiu    $sp, $sp, 0x30
