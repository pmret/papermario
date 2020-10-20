.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B0_9A88A0
/* 9A88A0 802404B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A88A4 802404B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A88A8 802404B8 0080902D */  daddu     $s2, $a0, $zero
/* 9A88AC 802404BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A88B0 802404C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A88B4 802404C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A88B8 802404C8 8E510148 */  lw        $s1, 0x148($s2)
/* 9A88BC 802404CC 0C00EABB */  jal       get_npc_unsafe
/* 9A88C0 802404D0 86240008 */   lh       $a0, 8($s1)
/* 9A88C4 802404D4 0040802D */  daddu     $s0, $v0, $zero
/* 9A88C8 802404D8 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A88CC 802404DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A88D0 802404E0 8C630020 */  lw        $v1, 0x20($v1)
/* 9A88D4 802404E4 AE030028 */  sw        $v1, 0x28($s0)
/* 9A88D8 802404E8 96220076 */  lhu       $v0, 0x76($s1)
/* 9A88DC 802404EC A602008E */  sh        $v0, 0x8e($s0)
/* 9A88E0 802404F0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9A88E4 802404F4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9A88E8 802404F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A88EC 802404FC 8C460028 */  lw        $a2, 0x28($v0)
/* 9A88F0 80240500 0C00A720 */  jal       atan2
/* 9A88F4 80240504 8C470030 */   lw       $a3, 0x30($v0)
/* 9A88F8 80240508 2402000D */  addiu     $v0, $zero, 0xd
/* 9A88FC 8024050C E600000C */  swc1      $f0, 0xc($s0)
/* 9A8900 80240510 AE420070 */  sw        $v0, 0x70($s2)
/* 9A8904 80240514 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A8908 80240518 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A890C 8024051C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A8910 80240520 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A8914 80240524 03E00008 */  jr        $ra
/* 9A8918 80240528 27BD0020 */   addiu    $sp, $sp, 0x20
