.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242628_C79308
/* C79308 80242628 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7930C 8024262C AFB10014 */  sw        $s1, 0x14($sp)
/* C79310 80242630 0080882D */  daddu     $s1, $a0, $zero
/* C79314 80242634 AFBF0018 */  sw        $ra, 0x18($sp)
/* C79318 80242638 AFB00010 */  sw        $s0, 0x10($sp)
/* C7931C 8024263C 8E300148 */  lw        $s0, 0x148($s1)
/* C79320 80242640 0C00EABB */  jal       get_npc_unsafe
/* C79324 80242644 86040008 */   lh       $a0, 8($s0)
/* C79328 80242648 0040182D */  daddu     $v1, $v0, $zero
/* C7932C 8024264C 9462008E */  lhu       $v0, 0x8e($v1)
/* C79330 80242650 2442FFFF */  addiu     $v0, $v0, -1
/* C79334 80242654 A462008E */  sh        $v0, 0x8e($v1)
/* C79338 80242658 00021400 */  sll       $v0, $v0, 0x10
/* C7933C 8024265C 14400005 */  bnez      $v0, .L80242674
/* C79340 80242660 00000000 */   nop      
/* C79344 80242664 960200AA */  lhu       $v0, 0xaa($s0)
/* C79348 80242668 A462008E */  sh        $v0, 0x8e($v1)
/* C7934C 8024266C 2402000E */  addiu     $v0, $zero, 0xe
/* C79350 80242670 AE220070 */  sw        $v0, 0x70($s1)
.L80242674:
/* C79354 80242674 8FBF0018 */  lw        $ra, 0x18($sp)
/* C79358 80242678 8FB10014 */  lw        $s1, 0x14($sp)
/* C7935C 8024267C 8FB00010 */  lw        $s0, 0x10($sp)
/* C79360 80242680 03E00008 */  jr        $ra
/* C79364 80242684 27BD0020 */   addiu    $sp, $sp, 0x20
