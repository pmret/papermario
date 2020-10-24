.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400A0_9A46F0
/* 9A46F0 802400A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A46F4 802400A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A46F8 802400A8 0080902D */  daddu     $s2, $a0, $zero
/* 9A46FC 802400AC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A4700 802400B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A4704 802400B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A4708 802400B8 8E510148 */  lw        $s1, 0x148($s2)
/* 9A470C 802400BC 0C00EABB */  jal       get_npc_unsafe
/* 9A4710 802400C0 86240008 */   lh       $a0, 8($s1)
/* 9A4714 802400C4 0040802D */  daddu     $s0, $v0, $zero
/* 9A4718 802400C8 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A471C 802400CC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A4720 802400D0 8C630020 */  lw        $v1, 0x20($v1)
/* 9A4724 802400D4 AE030028 */  sw        $v1, 0x28($s0)
/* 9A4728 802400D8 96220076 */  lhu       $v0, 0x76($s1)
/* 9A472C 802400DC A602008E */  sh        $v0, 0x8e($s0)
/* 9A4730 802400E0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9A4734 802400E4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9A4738 802400E8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A473C 802400EC 8C460028 */  lw        $a2, 0x28($v0)
/* 9A4740 802400F0 0C00A720 */  jal       atan2
/* 9A4744 802400F4 8C470030 */   lw       $a3, 0x30($v0)
/* 9A4748 802400F8 2402000D */  addiu     $v0, $zero, 0xd
/* 9A474C 802400FC E600000C */  swc1      $f0, 0xc($s0)
/* 9A4750 80240100 AE420070 */  sw        $v0, 0x70($s2)
/* 9A4754 80240104 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A4758 80240108 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A475C 8024010C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A4760 80240110 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A4764 80240114 03E00008 */  jr        $ra
/* 9A4768 80240118 27BD0020 */   addiu    $sp, $sp, 0x20
