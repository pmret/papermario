.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C58
/* D2D988 80241C58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2D98C 80241C5C AFB10014 */  sw        $s1, 0x14($sp)
/* D2D990 80241C60 0080882D */  daddu     $s1, $a0, $zero
/* D2D994 80241C64 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2D998 80241C68 AFB00010 */  sw        $s0, 0x10($sp)
/* D2D99C 80241C6C 8E300148 */  lw        $s0, 0x148($s1)
/* D2D9A0 80241C70 0C00EABB */  jal       get_npc_unsafe
/* D2D9A4 80241C74 86040008 */   lh       $a0, 8($s0)
/* D2D9A8 80241C78 0040182D */  daddu     $v1, $v0, $zero
/* D2D9AC 80241C7C 9462008E */  lhu       $v0, 0x8e($v1)
/* D2D9B0 80241C80 2442FFFF */  addiu     $v0, $v0, -1
/* D2D9B4 80241C84 A462008E */  sh        $v0, 0x8e($v1)
/* D2D9B8 80241C88 00021400 */  sll       $v0, $v0, 0x10
/* D2D9BC 80241C8C 14400005 */  bnez      $v0, .L80241CA4
/* D2D9C0 80241C90 00000000 */   nop      
/* D2D9C4 80241C94 960200AA */  lhu       $v0, 0xaa($s0)
/* D2D9C8 80241C98 A462008E */  sh        $v0, 0x8e($v1)
/* D2D9CC 80241C9C 2402000E */  addiu     $v0, $zero, 0xe
/* D2D9D0 80241CA0 AE220070 */  sw        $v0, 0x70($s1)
.L80241CA4:
/* D2D9D4 80241CA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2D9D8 80241CA8 8FB10014 */  lw        $s1, 0x14($sp)
/* D2D9DC 80241CAC 8FB00010 */  lw        $s0, 0x10($sp)
/* D2D9E0 80241CB0 03E00008 */  jr        $ra
/* D2D9E4 80241CB4 27BD0020 */   addiu    $sp, $sp, 0x20
