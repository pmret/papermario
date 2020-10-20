.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EEC_B28F1C
/* B28F1C 80240EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B28F20 80240EF0 AFB00010 */  sw        $s0, 0x10($sp)
/* B28F24 80240EF4 0080802D */  daddu     $s0, $a0, $zero
/* B28F28 80240EF8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B28F2C 80240EFC 8E020148 */  lw        $v0, 0x148($s0)
/* B28F30 80240F00 0C00EABB */  jal       get_npc_unsafe
/* B28F34 80240F04 84440008 */   lh       $a0, 8($v0)
/* B28F38 80240F08 9443008E */  lhu       $v1, 0x8e($v0)
/* B28F3C 80240F0C 2463FFFF */  addiu     $v1, $v1, -1
/* B28F40 80240F10 A443008E */  sh        $v1, 0x8e($v0)
/* B28F44 80240F14 00031C00 */  sll       $v1, $v1, 0x10
/* B28F48 80240F18 58600001 */  blezl     $v1, .L80240F20
/* B28F4C 80240F1C AE000070 */   sw       $zero, 0x70($s0)
.L80240F20:
/* B28F50 80240F20 8FBF0014 */  lw        $ra, 0x14($sp)
/* B28F54 80240F24 8FB00010 */  lw        $s0, 0x10($sp)
/* B28F58 80240F28 03E00008 */  jr        $ra
/* B28F5C 80240F2C 27BD0018 */   addiu    $sp, $sp, 0x18
