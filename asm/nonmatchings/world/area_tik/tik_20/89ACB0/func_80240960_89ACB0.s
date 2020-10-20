.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_89ACB0
/* 89ACB0 80240960 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89ACB4 80240964 AFB20018 */  sw        $s2, 0x18($sp)
/* 89ACB8 80240968 0080902D */  daddu     $s2, $a0, $zero
/* 89ACBC 8024096C AFBF001C */  sw        $ra, 0x1c($sp)
/* 89ACC0 80240970 AFB10014 */  sw        $s1, 0x14($sp)
/* 89ACC4 80240974 AFB00010 */  sw        $s0, 0x10($sp)
/* 89ACC8 80240978 8E510148 */  lw        $s1, 0x148($s2)
/* 89ACCC 8024097C 0C00EABB */  jal       get_npc_unsafe
/* 89ACD0 80240980 86240008 */   lh       $a0, 8($s1)
/* 89ACD4 80240984 0040802D */  daddu     $s0, $v0, $zero
/* 89ACD8 80240988 8E2300CC */  lw        $v1, 0xcc($s1)
/* 89ACDC 8024098C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 89ACE0 80240990 8C630020 */  lw        $v1, 0x20($v1)
/* 89ACE4 80240994 AE030028 */  sw        $v1, 0x28($s0)
/* 89ACE8 80240998 96220076 */  lhu       $v0, 0x76($s1)
/* 89ACEC 8024099C A602008E */  sh        $v0, 0x8e($s0)
/* 89ACF0 802409A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 89ACF4 802409A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 89ACF8 802409A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 89ACFC 802409AC 8C460028 */  lw        $a2, 0x28($v0)
/* 89AD00 802409B0 0C00A720 */  jal       atan2
/* 89AD04 802409B4 8C470030 */   lw       $a3, 0x30($v0)
/* 89AD08 802409B8 2402000D */  addiu     $v0, $zero, 0xd
/* 89AD0C 802409BC E600000C */  swc1      $f0, 0xc($s0)
/* 89AD10 802409C0 AE420070 */  sw        $v0, 0x70($s2)
/* 89AD14 802409C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89AD18 802409C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 89AD1C 802409CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 89AD20 802409D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 89AD24 802409D4 03E00008 */  jr        $ra
/* 89AD28 802409D8 27BD0020 */   addiu    $sp, $sp, 0x20
