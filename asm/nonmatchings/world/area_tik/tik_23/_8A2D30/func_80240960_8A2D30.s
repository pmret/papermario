.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240960_8A2D30
/* 8A2D30 80240960 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A2D34 80240964 AFB20018 */  sw        $s2, 0x18($sp)
/* 8A2D38 80240968 0080902D */  daddu     $s2, $a0, $zero
/* 8A2D3C 8024096C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A2D40 80240970 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A2D44 80240974 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A2D48 80240978 8E510148 */  lw        $s1, 0x148($s2)
/* 8A2D4C 8024097C 0C00EABB */  jal       get_npc_unsafe
/* 8A2D50 80240980 86240008 */   lh       $a0, 8($s1)
/* 8A2D54 80240984 0040802D */  daddu     $s0, $v0, $zero
/* 8A2D58 80240988 8E2300CC */  lw        $v1, 0xcc($s1)
/* 8A2D5C 8024098C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8A2D60 80240990 8C630020 */  lw        $v1, 0x20($v1)
/* 8A2D64 80240994 AE030028 */  sw        $v1, 0x28($s0)
/* 8A2D68 80240998 96220076 */  lhu       $v0, 0x76($s1)
/* 8A2D6C 8024099C A602008E */  sh        $v0, 0x8e($s0)
/* 8A2D70 802409A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8A2D74 802409A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8A2D78 802409A8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8A2D7C 802409AC 8C460028 */  lw        $a2, 0x28($v0)
/* 8A2D80 802409B0 0C00A720 */  jal       atan2
/* 8A2D84 802409B4 8C470030 */   lw       $a3, 0x30($v0)
/* 8A2D88 802409B8 2402000D */  addiu     $v0, $zero, 0xd
/* 8A2D8C 802409BC E600000C */  swc1      $f0, 0xc($s0)
/* 8A2D90 802409C0 AE420070 */  sw        $v0, 0x70($s2)
/* 8A2D94 802409C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A2D98 802409C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A2D9C 802409CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A2DA0 802409D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A2DA4 802409D4 03E00008 */  jr        $ra
/* 8A2DA8 802409D8 27BD0020 */   addiu    $sp, $sp, 0x20
