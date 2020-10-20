.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241744_BEE534
/* BEE534 80241744 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BEE538 80241748 AFB00010 */  sw        $s0, 0x10($sp)
/* BEE53C 8024174C 0080802D */  daddu     $s0, $a0, $zero
/* BEE540 80241750 AFBF0014 */  sw        $ra, 0x14($sp)
/* BEE544 80241754 8E020148 */  lw        $v0, 0x148($s0)
/* BEE548 80241758 0C00EABB */  jal       get_npc_unsafe
/* BEE54C 8024175C 84440008 */   lh       $a0, 8($v0)
/* BEE550 80241760 0040202D */  daddu     $a0, $v0, $zero
/* BEE554 80241764 8482008E */  lh        $v0, 0x8e($a0)
/* BEE558 80241768 9483008E */  lhu       $v1, 0x8e($a0)
/* BEE55C 8024176C 18400005 */  blez      $v0, .L80241784
/* BEE560 80241770 2462FFFF */   addiu    $v0, $v1, -1
/* BEE564 80241774 A482008E */  sh        $v0, 0x8e($a0)
/* BEE568 80241778 00021400 */  sll       $v0, $v0, 0x10
/* BEE56C 8024177C 1C400006 */  bgtz      $v0, .L80241798
/* BEE570 80241780 00000000 */   nop      
.L80241784:
/* BEE574 80241784 8482008C */  lh        $v0, 0x8c($a0)
/* BEE578 80241788 14400003 */  bnez      $v0, .L80241798
/* BEE57C 8024178C 2402000E */   addiu    $v0, $zero, 0xe
/* BEE580 80241790 A480008E */  sh        $zero, 0x8e($a0)
/* BEE584 80241794 AE020070 */  sw        $v0, 0x70($s0)
.L80241798:
/* BEE588 80241798 8FBF0014 */  lw        $ra, 0x14($sp)
/* BEE58C 8024179C 8FB00010 */  lw        $s0, 0x10($sp)
/* BEE590 802417A0 03E00008 */  jr        $ra
/* BEE594 802417A4 27BD0018 */   addiu    $sp, $sp, 0x18
