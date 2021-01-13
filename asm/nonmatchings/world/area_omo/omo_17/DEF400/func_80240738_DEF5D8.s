.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240738_DEF5D8
/* DEF5D8 80240738 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEF5DC 8024073C AFB10014 */  sw        $s1, 0x14($sp)
/* DEF5E0 80240740 0080882D */  daddu     $s1, $a0, $zero
/* DEF5E4 80240744 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEF5E8 80240748 AFB00010 */  sw        $s0, 0x10($sp)
/* DEF5EC 8024074C 8E300148 */  lw        $s0, 0x148($s1)
/* DEF5F0 80240750 0C00EABB */  jal       get_npc_unsafe
/* DEF5F4 80240754 86040008 */   lh       $a0, 8($s0)
/* DEF5F8 80240758 0040182D */  daddu     $v1, $v0, $zero
/* DEF5FC 8024075C 9462008E */  lhu       $v0, 0x8e($v1)
/* DEF600 80240760 2442FFFF */  addiu     $v0, $v0, -1
/* DEF604 80240764 A462008E */  sh        $v0, 0x8e($v1)
/* DEF608 80240768 00021400 */  sll       $v0, $v0, 0x10
/* DEF60C 8024076C 14400005 */  bnez      $v0, .L80240784
/* DEF610 80240770 00000000 */   nop
/* DEF614 80240774 8E0200CC */  lw        $v0, 0xcc($s0)
/* DEF618 80240778 8C420000 */  lw        $v0, ($v0)
/* DEF61C 8024077C AC620028 */  sw        $v0, 0x28($v1)
/* DEF620 80240780 AE200070 */  sw        $zero, 0x70($s1)
.L80240784:
/* DEF624 80240784 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEF628 80240788 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF62C 8024078C 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF630 80240790 03E00008 */  jr        $ra
/* DEF634 80240794 27BD0020 */   addiu    $sp, $sp, 0x20
