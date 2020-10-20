.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_984E30
/* 984E30 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 984E34 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* 984E38 80240008 0080902D */  daddu     $s2, $a0, $zero
/* 984E3C 8024000C AFBF001C */  sw        $ra, 0x1c($sp)
/* 984E40 80240010 AFB10014 */  sw        $s1, 0x14($sp)
/* 984E44 80240014 AFB00010 */  sw        $s0, 0x10($sp)
/* 984E48 80240018 8E510148 */  lw        $s1, 0x148($s2)
/* 984E4C 8024001C 0C00EABB */  jal       get_npc_unsafe
/* 984E50 80240020 86240008 */   lh       $a0, 8($s1)
/* 984E54 80240024 0040802D */  daddu     $s0, $v0, $zero
/* 984E58 80240028 8E2300CC */  lw        $v1, 0xcc($s1)
/* 984E5C 8024002C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 984E60 80240030 8C630020 */  lw        $v1, 0x20($v1)
/* 984E64 80240034 AE030028 */  sw        $v1, 0x28($s0)
/* 984E68 80240038 96220076 */  lhu       $v0, 0x76($s1)
/* 984E6C 8024003C A602008E */  sh        $v0, 0x8e($s0)
/* 984E70 80240040 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 984E74 80240044 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 984E78 80240048 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 984E7C 8024004C 8C460028 */  lw        $a2, 0x28($v0)
/* 984E80 80240050 0C00A720 */  jal       atan2
/* 984E84 80240054 8C470030 */   lw       $a3, 0x30($v0)
/* 984E88 80240058 2402000D */  addiu     $v0, $zero, 0xd
/* 984E8C 8024005C E600000C */  swc1      $f0, 0xc($s0)
/* 984E90 80240060 AE420070 */  sw        $v0, 0x70($s2)
/* 984E94 80240064 8FBF001C */  lw        $ra, 0x1c($sp)
/* 984E98 80240068 8FB20018 */  lw        $s2, 0x18($sp)
/* 984E9C 8024006C 8FB10014 */  lw        $s1, 0x14($sp)
/* 984EA0 80240070 8FB00010 */  lw        $s0, 0x10($sp)
/* 984EA4 80240074 03E00008 */  jr        $ra
/* 984EA8 80240078 27BD0020 */   addiu    $sp, $sp, 0x20
