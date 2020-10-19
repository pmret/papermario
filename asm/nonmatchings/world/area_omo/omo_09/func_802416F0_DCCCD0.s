.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F0_DCE3C0
/* DCE3C0 802416F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DCE3C4 802416F4 AFB00010 */  sw        $s0, 0x10($sp)
/* DCE3C8 802416F8 0080802D */  daddu     $s0, $a0, $zero
/* DCE3CC 802416FC AFBF0014 */  sw        $ra, 0x14($sp)
/* DCE3D0 80241700 8E020148 */  lw        $v0, 0x148($s0)
/* DCE3D4 80241704 0C00EABB */  jal       get_npc_unsafe
/* DCE3D8 80241708 84440008 */   lh       $a0, 8($v0)
/* DCE3DC 8024170C 0040202D */  daddu     $a0, $v0, $zero
/* DCE3E0 80241710 C482003C */  lwc1      $f2, 0x3c($a0)
/* DCE3E4 80241714 C480001C */  lwc1      $f0, 0x1c($a0)
/* DCE3E8 80241718 46001080 */  add.s     $f2, $f2, $f0
/* DCE3EC 8024171C C4840014 */  lwc1      $f4, 0x14($a0)
/* DCE3F0 80241720 46040001 */  sub.s     $f0, $f0, $f4
/* DCE3F4 80241724 C4840064 */  lwc1      $f4, 0x64($a0)
/* DCE3F8 80241728 4602203C */  c.lt.s    $f4, $f2
/* DCE3FC 8024172C E482003C */  swc1      $f2, 0x3c($a0)
/* DCE400 80241730 45010009 */  bc1t      .L80241758
/* DCE404 80241734 E480001C */   swc1     $f0, 0x1c($a0)
/* DCE408 80241738 8C820000 */  lw        $v0, ($a0)
/* DCE40C 8024173C 2403F7FF */  addiu     $v1, $zero, -0x801
/* DCE410 80241740 E484003C */  swc1      $f4, 0x3c($a0)
/* DCE414 80241744 AC80001C */  sw        $zero, 0x1c($a0)
/* DCE418 80241748 00431024 */  and       $v0, $v0, $v1
/* DCE41C 8024174C AC820000 */  sw        $v0, ($a0)
/* DCE420 80241750 2402000C */  addiu     $v0, $zero, 0xc
/* DCE424 80241754 AE020070 */  sw        $v0, 0x70($s0)
.L80241758:
/* DCE428 80241758 8FBF0014 */  lw        $ra, 0x14($sp)
/* DCE42C 8024175C 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE430 80241760 03E00008 */  jr        $ra
/* DCE434 80241764 27BD0018 */   addiu    $sp, $sp, 0x18
