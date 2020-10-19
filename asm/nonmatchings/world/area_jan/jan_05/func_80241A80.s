.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A80
/* B4C4F0 80241A80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4C4F4 80241A84 AFB10014 */  sw        $s1, 0x14($sp)
/* B4C4F8 80241A88 0080882D */  daddu     $s1, $a0, $zero
/* B4C4FC 80241A8C AFBF0018 */  sw        $ra, 0x18($sp)
/* B4C500 80241A90 AFB00010 */  sw        $s0, 0x10($sp)
/* B4C504 80241A94 8E300148 */  lw        $s0, 0x148($s1)
/* B4C508 80241A98 0C00EABB */  jal       get_npc_unsafe
/* B4C50C 80241A9C 86040008 */   lh       $a0, 8($s0)
/* B4C510 80241AA0 9443008E */  lhu       $v1, 0x8e($v0)
/* B4C514 80241AA4 2463FFFF */  addiu     $v1, $v1, -1
/* B4C518 80241AA8 A443008E */  sh        $v1, 0x8e($v0)
/* B4C51C 80241AAC 00031C00 */  sll       $v1, $v1, 0x10
/* B4C520 80241AB0 1C600003 */  bgtz      $v1, .L80241AC0
/* B4C524 80241AB4 2402000C */   addiu    $v0, $zero, 0xc
/* B4C528 80241AB8 AE00006C */  sw        $zero, 0x6c($s0)
/* B4C52C 80241ABC AE220070 */  sw        $v0, 0x70($s1)
.L80241AC0:
/* B4C530 80241AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B4C534 80241AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* B4C538 80241AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* B4C53C 80241ACC 03E00008 */  jr        $ra
/* B4C540 80241AD0 27BD0020 */   addiu    $sp, $sp, 0x20
