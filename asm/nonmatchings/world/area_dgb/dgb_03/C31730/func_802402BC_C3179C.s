.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* C3179C 802402BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C317A0 802402C0 AFB10014 */  sw        $s1, 0x14($sp)
/* C317A4 802402C4 0080882D */  daddu     $s1, $a0, $zero
/* C317A8 802402C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* C317AC 802402CC AFB00010 */  sw        $s0, 0x10($sp)
/* C317B0 802402D0 8E300148 */  lw        $s0, 0x148($s1)
/* C317B4 802402D4 0C00EABB */  jal       get_npc_unsafe
/* C317B8 802402D8 86040008 */   lh       $a0, 8($s0)
/* C317BC 802402DC 0040202D */  daddu     $a0, $v0, $zero
/* C317C0 802402E0 9482008E */  lhu       $v0, 0x8e($a0)
/* C317C4 802402E4 2442FFFF */  addiu     $v0, $v0, -1
/* C317C8 802402E8 A482008E */  sh        $v0, 0x8e($a0)
/* C317CC 802402EC 00021400 */  sll       $v0, $v0, 0x10
/* C317D0 802402F0 1C400009 */  bgtz      $v0, .L80240318
/* C317D4 802402F4 24020003 */   addiu    $v0, $zero, 3
/* C317D8 802402F8 96030076 */  lhu       $v1, 0x76($s0)
/* C317DC 802402FC AE02006C */  sw        $v0, 0x6c($s0)
/* C317E0 80240300 A483008E */  sh        $v1, 0x8e($a0)
/* C317E4 80240304 8E0200CC */  lw        $v0, 0xcc($s0)
/* C317E8 80240308 8C420024 */  lw        $v0, 0x24($v0)
/* C317EC 8024030C AC820028 */  sw        $v0, 0x28($a0)
/* C317F0 80240310 24020020 */  addiu     $v0, $zero, 0x20
/* C317F4 80240314 AE220070 */  sw        $v0, 0x70($s1)
.L80240318:
/* C317F8 80240318 8FBF0018 */  lw        $ra, 0x18($sp)
/* C317FC 8024031C 8FB10014 */  lw        $s1, 0x14($sp)
/* C31800 80240320 8FB00010 */  lw        $s0, 0x10($sp)
/* C31804 80240324 03E00008 */  jr        $ra
/* C31808 80240328 27BD0020 */   addiu    $sp, $sp, 0x20
