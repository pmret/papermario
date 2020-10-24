.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243B44_C74FC4
/* C74FC4 80243B44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C74FC8 80243B48 AFB10014 */  sw        $s1, 0x14($sp)
/* C74FCC 80243B4C 0080882D */  daddu     $s1, $a0, $zero
/* C74FD0 80243B50 AFBF0018 */  sw        $ra, 0x18($sp)
/* C74FD4 80243B54 AFB00010 */  sw        $s0, 0x10($sp)
/* C74FD8 80243B58 8E300148 */  lw        $s0, 0x148($s1)
/* C74FDC 80243B5C 0C00EABB */  jal       get_npc_unsafe
/* C74FE0 80243B60 86040008 */   lh       $a0, 8($s0)
/* C74FE4 80243B64 0040182D */  daddu     $v1, $v0, $zero
/* C74FE8 80243B68 9462008E */  lhu       $v0, 0x8e($v1)
/* C74FEC 80243B6C 2442FFFF */  addiu     $v0, $v0, -1
/* C74FF0 80243B70 A462008E */  sh        $v0, 0x8e($v1)
/* C74FF4 80243B74 00021400 */  sll       $v0, $v0, 0x10
/* C74FF8 80243B78 14400005 */  bnez      $v0, .L80243B90
/* C74FFC 80243B7C 00000000 */   nop      
/* C75000 80243B80 960200AA */  lhu       $v0, 0xaa($s0)
/* C75004 80243B84 A462008E */  sh        $v0, 0x8e($v1)
/* C75008 80243B88 2402000E */  addiu     $v0, $zero, 0xe
/* C7500C 80243B8C AE220070 */  sw        $v0, 0x70($s1)
.L80243B90:
/* C75010 80243B90 8FBF0018 */  lw        $ra, 0x18($sp)
/* C75014 80243B94 8FB10014 */  lw        $s1, 0x14($sp)
/* C75018 80243B98 8FB00010 */  lw        $s0, 0x10($sp)
/* C7501C 80243B9C 03E00008 */  jr        $ra
/* C75020 80243BA0 27BD0020 */   addiu    $sp, $sp, 0x20
