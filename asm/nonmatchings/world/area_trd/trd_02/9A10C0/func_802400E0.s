.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0
/* 9A10C0 802400E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A10C4 802400E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A10C8 802400E8 0080902D */  daddu     $s2, $a0, $zero
/* 9A10CC 802400EC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9A10D0 802400F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A10D4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A10D8 802400F8 8E510148 */  lw        $s1, 0x148($s2)
/* 9A10DC 802400FC 0C00EABB */  jal       get_npc_unsafe
/* 9A10E0 80240100 86240008 */   lh       $a0, 8($s1)
/* 9A10E4 80240104 0040802D */  daddu     $s0, $v0, $zero
/* 9A10E8 80240108 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9A10EC 8024010C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A10F0 80240110 8C630020 */  lw        $v1, 0x20($v1)
/* 9A10F4 80240114 AE030028 */  sw        $v1, 0x28($s0)
/* 9A10F8 80240118 96220076 */  lhu       $v0, 0x76($s1)
/* 9A10FC 8024011C A602008E */  sh        $v0, 0x8e($s0)
/* 9A1100 80240120 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9A1104 80240124 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9A1108 80240128 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A110C 8024012C 8C460028 */  lw        $a2, 0x28($v0)
/* 9A1110 80240130 0C00A720 */  jal       atan2
/* 9A1114 80240134 8C470030 */   lw       $a3, 0x30($v0)
/* 9A1118 80240138 2402000D */  addiu     $v0, $zero, 0xd
/* 9A111C 8024013C E600000C */  swc1      $f0, 0xc($s0)
/* 9A1120 80240140 AE420070 */  sw        $v0, 0x70($s2)
/* 9A1124 80240144 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9A1128 80240148 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A112C 8024014C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A1130 80240150 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A1134 80240154 03E00008 */  jr        $ra
/* 9A1138 80240158 27BD0020 */   addiu    $sp, $sp, 0x20
