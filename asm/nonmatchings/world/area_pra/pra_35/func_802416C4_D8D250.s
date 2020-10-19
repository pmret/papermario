.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C4_D8E914
/* D8E914 802416C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8E918 802416C8 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E91C 802416CC 0080802D */  daddu     $s0, $a0, $zero
/* D8E920 802416D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* D8E924 802416D4 8E020148 */  lw        $v0, 0x148($s0)
/* D8E928 802416D8 0C00EABB */  jal       get_npc_unsafe
/* D8E92C 802416DC 84440008 */   lh       $a0, 8($v0)
/* D8E930 802416E0 0040202D */  daddu     $a0, $v0, $zero
/* D8E934 802416E4 C482003C */  lwc1      $f2, 0x3c($a0)
/* D8E938 802416E8 C480001C */  lwc1      $f0, 0x1c($a0)
/* D8E93C 802416EC 46001080 */  add.s     $f2, $f2, $f0
/* D8E940 802416F0 C4840014 */  lwc1      $f4, 0x14($a0)
/* D8E944 802416F4 46040001 */  sub.s     $f0, $f0, $f4
/* D8E948 802416F8 C4840064 */  lwc1      $f4, 0x64($a0)
/* D8E94C 802416FC 4602203C */  c.lt.s    $f4, $f2
/* D8E950 80241700 E482003C */  swc1      $f2, 0x3c($a0)
/* D8E954 80241704 45010009 */  bc1t      .L8024172C
/* D8E958 80241708 E480001C */   swc1     $f0, 0x1c($a0)
/* D8E95C 8024170C 8C820000 */  lw        $v0, ($a0)
/* D8E960 80241710 2403F7FF */  addiu     $v1, $zero, -0x801
/* D8E964 80241714 E484003C */  swc1      $f4, 0x3c($a0)
/* D8E968 80241718 AC80001C */  sw        $zero, 0x1c($a0)
/* D8E96C 8024171C 00431024 */  and       $v0, $v0, $v1
/* D8E970 80241720 AC820000 */  sw        $v0, ($a0)
/* D8E974 80241724 2402000C */  addiu     $v0, $zero, 0xc
/* D8E978 80241728 AE020070 */  sw        $v0, 0x70($s0)
.L8024172C:
/* D8E97C 8024172C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D8E980 80241730 8FB00010 */  lw        $s0, 0x10($sp)
/* D8E984 80241734 03E00008 */  jr        $ra
/* D8E988 80241738 27BD0018 */   addiu    $sp, $sp, 0x18
