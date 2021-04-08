.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_17_UnkFunc20
/* 892ED0 802404B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 892ED4 802404B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 892ED8 802404B8 0080882D */  daddu     $s1, $a0, $zero
/* 892EDC 802404BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 892EE0 802404C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 892EE4 802404C4 8E30000C */  lw        $s0, 0xc($s1)
/* 892EE8 802404C8 8E050000 */  lw        $a1, ($s0)
/* 892EEC 802404CC 0C0B1EAF */  jal       get_variable
/* 892EF0 802404D0 26100004 */   addiu    $s0, $s0, 4
/* 892EF4 802404D4 0C04417A */  jal       get_entity_by_index
/* 892EF8 802404D8 0040202D */   daddu    $a0, $v0, $zero
/* 892EFC 802404DC 8E100000 */  lw        $s0, ($s0)
/* 892F00 802404E0 C444004C */  lwc1      $f4, 0x4c($v0)
/* 892F04 802404E4 3C014148 */  lui       $at, 0x4148
/* 892F08 802404E8 44810000 */  mtc1      $at, $f0
/* 892F0C 802404EC 3C013F33 */  lui       $at, 0x3f33
/* 892F10 802404F0 34213333 */  ori       $at, $at, 0x3333
/* 892F14 802404F4 44811000 */  mtc1      $at, $f2
/* 892F18 802404F8 AFA00014 */  sw        $zero, 0x14($sp)
/* 892F1C 802404FC 46002100 */  add.s     $f4, $f4, $f0
/* 892F20 80240500 E7A20010 */  swc1      $f2, 0x10($sp)
/* 892F24 80240504 8C450048 */  lw        $a1, 0x48($v0)
/* 892F28 80240508 8C470050 */  lw        $a3, 0x50($v0)
/* 892F2C 8024050C 44062000 */  mfc1      $a2, $f4
/* 892F30 80240510 0C01C5D4 */  jal       func_80071750
/* 892F34 80240514 0000202D */   daddu    $a0, $zero, $zero
/* 892F38 80240518 0220202D */  daddu     $a0, $s1, $zero
/* 892F3C 8024051C 0200282D */  daddu     $a1, $s0, $zero
/* 892F40 80240520 0C0B2026 */  jal       set_variable
/* 892F44 80240524 0040302D */   daddu    $a2, $v0, $zero
/* 892F48 80240528 8FBF0020 */  lw        $ra, 0x20($sp)
/* 892F4C 8024052C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 892F50 80240530 8FB00018 */  lw        $s0, 0x18($sp)
/* 892F54 80240534 24020002 */  addiu     $v0, $zero, 2
/* 892F58 80240538 03E00008 */  jr        $ra
/* 892F5C 8024053C 27BD0028 */   addiu    $sp, $sp, 0x28
