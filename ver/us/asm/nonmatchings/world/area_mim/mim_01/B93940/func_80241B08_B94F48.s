.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B08_B94F48
/* B94F48 80241B08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B94F4C 80241B0C AFB10014 */  sw        $s1, 0x14($sp)
/* B94F50 80241B10 0080882D */  daddu     $s1, $a0, $zero
/* B94F54 80241B14 AFBF0018 */  sw        $ra, 0x18($sp)
/* B94F58 80241B18 AFB00010 */  sw        $s0, 0x10($sp)
/* B94F5C 80241B1C 8E300148 */  lw        $s0, 0x148($s1)
/* B94F60 80241B20 0C00EABB */  jal       get_npc_unsafe
/* B94F64 80241B24 86040008 */   lh       $a0, 8($s0)
/* B94F68 80241B28 0040182D */  daddu     $v1, $v0, $zero
/* B94F6C 80241B2C 9462008E */  lhu       $v0, 0x8e($v1)
/* B94F70 80241B30 2442FFFF */  addiu     $v0, $v0, -1
/* B94F74 80241B34 A462008E */  sh        $v0, 0x8e($v1)
/* B94F78 80241B38 00021400 */  sll       $v0, $v0, 0x10
/* B94F7C 80241B3C 14400005 */  bnez      $v0, .L80241B54
/* B94F80 80241B40 00000000 */   nop
/* B94F84 80241B44 960200AA */  lhu       $v0, 0xaa($s0)
/* B94F88 80241B48 A462008E */  sh        $v0, 0x8e($v1)
/* B94F8C 80241B4C 2402000E */  addiu     $v0, $zero, 0xe
/* B94F90 80241B50 AE220070 */  sw        $v0, 0x70($s1)
.L80241B54:
/* B94F94 80241B54 8FBF0018 */  lw        $ra, 0x18($sp)
/* B94F98 80241B58 8FB10014 */  lw        $s1, 0x14($sp)
/* B94F9C 80241B5C 8FB00010 */  lw        $s0, 0x10($sp)
/* B94FA0 80241B60 03E00008 */  jr        $ra
/* B94FA4 80241B64 27BD0020 */   addiu    $sp, $sp, 0x20
