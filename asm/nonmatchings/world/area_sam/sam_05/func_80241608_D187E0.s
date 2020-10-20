.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241608_D19DE8
/* D19DE8 80241608 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D19DEC 8024160C AFB10014 */  sw        $s1, 0x14($sp)
/* D19DF0 80241610 0080882D */  daddu     $s1, $a0, $zero
/* D19DF4 80241614 AFBF0018 */  sw        $ra, 0x18($sp)
/* D19DF8 80241618 AFB00010 */  sw        $s0, 0x10($sp)
/* D19DFC 8024161C 8E300148 */  lw        $s0, 0x148($s1)
/* D19E00 80241620 0C00EABB */  jal       get_npc_unsafe
/* D19E04 80241624 86040008 */   lh       $a0, 8($s0)
/* D19E08 80241628 0040182D */  daddu     $v1, $v0, $zero
/* D19E0C 8024162C 9462008E */  lhu       $v0, 0x8e($v1)
/* D19E10 80241630 2442FFFF */  addiu     $v0, $v0, -1
/* D19E14 80241634 A462008E */  sh        $v0, 0x8e($v1)
/* D19E18 80241638 00021400 */  sll       $v0, $v0, 0x10
/* D19E1C 8024163C 14400005 */  bnez      $v0, .L80241654
/* D19E20 80241640 00000000 */   nop      
/* D19E24 80241644 960200AA */  lhu       $v0, 0xaa($s0)
/* D19E28 80241648 A462008E */  sh        $v0, 0x8e($v1)
/* D19E2C 8024164C 2402000E */  addiu     $v0, $zero, 0xe
/* D19E30 80241650 AE220070 */  sw        $v0, 0x70($s1)
.L80241654:
/* D19E34 80241654 8FBF0018 */  lw        $ra, 0x18($sp)
/* D19E38 80241658 8FB10014 */  lw        $s1, 0x14($sp)
/* D19E3C 8024165C 8FB00010 */  lw        $s0, 0x10($sp)
/* D19E40 80241660 03E00008 */  jr        $ra
/* D19E44 80241664 27BD0020 */   addiu    $sp, $sp, 0x20
