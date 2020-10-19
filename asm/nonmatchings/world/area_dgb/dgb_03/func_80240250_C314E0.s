.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240250_C31730
/* C31730 80240250 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C31734 80240254 AFB10014 */  sw        $s1, 0x14($sp)
/* C31738 80240258 0080882D */  daddu     $s1, $a0, $zero
/* C3173C 8024025C AFBF0018 */  sw        $ra, 0x18($sp)
/* C31740 80240260 AFB00010 */  sw        $s0, 0x10($sp)
/* C31744 80240264 8E300148 */  lw        $s0, 0x148($s1)
/* C31748 80240268 0C00EABB */  jal       get_npc_unsafe
/* C3174C 8024026C 86040008 */   lh       $a0, 8($s0)
/* C31750 80240270 24030001 */  addiu     $v1, $zero, 1
/* C31754 80240274 0040202D */  daddu     $a0, $v0, $zero
/* C31758 80240278 AE03006C */  sw        $v1, 0x6c($s0)
/* C3175C 8024027C 8482008C */  lh        $v0, 0x8c($a0)
/* C31760 80240280 14400009 */  bnez      $v0, .L802402A8
/* C31764 80240284 24020002 */   addiu    $v0, $zero, 2
/* C31768 80240288 96030072 */  lhu       $v1, 0x72($s0)
/* C3176C 8024028C AE02006C */  sw        $v0, 0x6c($s0)
/* C31770 80240290 A483008E */  sh        $v1, 0x8e($a0)
/* C31774 80240294 8E0200CC */  lw        $v0, 0xcc($s0)
/* C31778 80240298 8C420020 */  lw        $v0, 0x20($v0)
/* C3177C 8024029C AC820028 */  sw        $v0, 0x28($a0)
/* C31780 802402A0 2402001F */  addiu     $v0, $zero, 0x1f
/* C31784 802402A4 AE220070 */  sw        $v0, 0x70($s1)
.L802402A8:
/* C31788 802402A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3178C 802402AC 8FB10014 */  lw        $s1, 0x14($sp)
/* C31790 802402B0 8FB00010 */  lw        $s0, 0x10($sp)
/* C31794 802402B4 03E00008 */  jr        $ra
/* C31798 802402B8 27BD0020 */   addiu    $sp, $sp, 0x20
