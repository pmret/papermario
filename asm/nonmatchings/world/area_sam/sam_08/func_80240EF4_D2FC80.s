.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF4_D30B74
/* D30B74 80240EF4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D30B78 80240EF8 AFB10014 */  sw        $s1, 0x14($sp)
/* D30B7C 80240EFC 0080882D */  daddu     $s1, $a0, $zero
/* D30B80 80240F00 AFBF0018 */  sw        $ra, 0x18($sp)
/* D30B84 80240F04 AFB00010 */  sw        $s0, 0x10($sp)
/* D30B88 80240F08 8E300148 */  lw        $s0, 0x148($s1)
/* D30B8C 80240F0C 0C00EABB */  jal       get_npc_unsafe
/* D30B90 80240F10 86040008 */   lh       $a0, 8($s0)
/* D30B94 80240F14 9443008E */  lhu       $v1, 0x8e($v0)
/* D30B98 80240F18 2463FFFF */  addiu     $v1, $v1, -1
/* D30B9C 80240F1C A443008E */  sh        $v1, 0x8e($v0)
/* D30BA0 80240F20 00031C00 */  sll       $v1, $v1, 0x10
/* D30BA4 80240F24 1C600003 */  bgtz      $v1, .L80240F34
/* D30BA8 80240F28 2402000C */   addiu    $v0, $zero, 0xc
/* D30BAC 80240F2C AE00006C */  sw        $zero, 0x6c($s0)
/* D30BB0 80240F30 AE220070 */  sw        $v0, 0x70($s1)
.L80240F34:
/* D30BB4 80240F34 8FBF0018 */  lw        $ra, 0x18($sp)
/* D30BB8 80240F38 8FB10014 */  lw        $s1, 0x14($sp)
/* D30BBC 80240F3C 8FB00010 */  lw        $s0, 0x10($sp)
/* D30BC0 80240F40 03E00008 */  jr        $ra
/* D30BC4 80240F44 27BD0020 */   addiu    $sp, $sp, 0x20
