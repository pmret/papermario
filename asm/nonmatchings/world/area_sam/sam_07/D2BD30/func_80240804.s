.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240804
/* D2C534 80240804 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2C538 80240808 AFB10014 */  sw        $s1, 0x14($sp)
/* D2C53C 8024080C 0080882D */  daddu     $s1, $a0, $zero
/* D2C540 80240810 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2C544 80240814 AFB00010 */  sw        $s0, 0x10($sp)
/* D2C548 80240818 8E300148 */  lw        $s0, 0x148($s1)
/* D2C54C 8024081C 0C00EABB */  jal       get_npc_unsafe
/* D2C550 80240820 86040008 */   lh       $a0, 8($s0)
/* D2C554 80240824 9443008E */  lhu       $v1, 0x8e($v0)
/* D2C558 80240828 2463FFFF */  addiu     $v1, $v1, -1
/* D2C55C 8024082C A443008E */  sh        $v1, 0x8e($v0)
/* D2C560 80240830 00031C00 */  sll       $v1, $v1, 0x10
/* D2C564 80240834 1C600003 */  bgtz      $v1, .L80240844
/* D2C568 80240838 2402000C */   addiu    $v0, $zero, 0xc
/* D2C56C 8024083C AE00006C */  sw        $zero, 0x6c($s0)
/* D2C570 80240840 AE220070 */  sw        $v0, 0x70($s1)
.L80240844:
/* D2C574 80240844 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2C578 80240848 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C57C 8024084C 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C580 80240850 03E00008 */  jr        $ra
/* D2C584 80240854 27BD0020 */   addiu    $sp, $sp, 0x20
