.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EA8
/* 919A58 80240EA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 919A5C 80240EAC AFB10014 */  sw        $s1, 0x14($sp)
/* 919A60 80240EB0 0080882D */  daddu     $s1, $a0, $zero
/* 919A64 80240EB4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 919A68 80240EB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 919A6C 80240EBC 8E300148 */  lw        $s0, 0x148($s1)
/* 919A70 80240EC0 0C00EABB */  jal       get_npc_unsafe
/* 919A74 80240EC4 86040008 */   lh       $a0, 8($s0)
/* 919A78 80240EC8 0040202D */  daddu     $a0, $v0, $zero
/* 919A7C 80240ECC 8482008E */  lh        $v0, 0x8e($a0)
/* 919A80 80240ED0 9483008E */  lhu       $v1, 0x8e($a0)
/* 919A84 80240ED4 18400002 */  blez      $v0, .L80240EE0
/* 919A88 80240ED8 2462FFFF */   addiu    $v0, $v1, -1
/* 919A8C 80240EDC A482008E */  sh        $v0, 0x8e($a0)
.L80240EE0:
/* 919A90 80240EE0 8482008C */  lh        $v0, 0x8c($a0)
/* 919A94 80240EE4 1440000A */  bnez      $v0, .L80240F10
/* 919A98 80240EE8 00000000 */   nop      
/* 919A9C 80240EEC 8482008E */  lh        $v0, 0x8e($a0)
/* 919AA0 80240EF0 1C400007 */  bgtz      $v0, .L80240F10
/* 919AA4 80240EF4 24020008 */   addiu    $v0, $zero, 8
/* 919AA8 80240EF8 A482008E */  sh        $v0, 0x8e($a0)
/* 919AAC 80240EFC 8E0200CC */  lw        $v0, 0xcc($s0)
/* 919AB0 80240F00 8C42002C */  lw        $v0, 0x2c($v0)
/* 919AB4 80240F04 AC820028 */  sw        $v0, 0x28($a0)
/* 919AB8 80240F08 24020033 */  addiu     $v0, $zero, 0x33
/* 919ABC 80240F0C AE220070 */  sw        $v0, 0x70($s1)
.L80240F10:
/* 919AC0 80240F10 8FBF0018 */  lw        $ra, 0x18($sp)
/* 919AC4 80240F14 8FB10014 */  lw        $s1, 0x14($sp)
/* 919AC8 80240F18 8FB00010 */  lw        $s0, 0x10($sp)
/* 919ACC 80240F1C 03E00008 */  jr        $ra
/* 919AD0 80240F20 27BD0020 */   addiu    $sp, $sp, 0x20
