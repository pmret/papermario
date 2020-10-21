.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241658_8B16C8
/* 8B16C8 80241658 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B16CC 8024165C AFB00010 */  sw        $s0, 0x10($sp)
/* 8B16D0 80241660 0080802D */  daddu     $s0, $a0, $zero
/* 8B16D4 80241664 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B16D8 80241668 8E020148 */  lw        $v0, 0x148($s0)
/* 8B16DC 8024166C 0C00EABB */  jal       get_npc_unsafe
/* 8B16E0 80241670 84440008 */   lh       $a0, 8($v0)
/* 8B16E4 80241674 0040202D */  daddu     $a0, $v0, $zero
/* 8B16E8 80241678 C482003C */  lwc1      $f2, 0x3c($a0)
/* 8B16EC 8024167C C480001C */  lwc1      $f0, 0x1c($a0)
/* 8B16F0 80241680 46001080 */  add.s     $f2, $f2, $f0
/* 8B16F4 80241684 C4840014 */  lwc1      $f4, 0x14($a0)
/* 8B16F8 80241688 46040001 */  sub.s     $f0, $f0, $f4
/* 8B16FC 8024168C C4840064 */  lwc1      $f4, 0x64($a0)
/* 8B1700 80241690 4602203C */  c.lt.s    $f4, $f2
/* 8B1704 80241694 E482003C */  swc1      $f2, 0x3c($a0)
/* 8B1708 80241698 45010009 */  bc1t      .L802416C0
/* 8B170C 8024169C E480001C */   swc1     $f0, 0x1c($a0)
/* 8B1710 802416A0 8C820000 */  lw        $v0, ($a0)
/* 8B1714 802416A4 2403F7FF */  addiu     $v1, $zero, -0x801
/* 8B1718 802416A8 E484003C */  swc1      $f4, 0x3c($a0)
/* 8B171C 802416AC AC80001C */  sw        $zero, 0x1c($a0)
/* 8B1720 802416B0 00431024 */  and       $v0, $v0, $v1
/* 8B1724 802416B4 AC820000 */  sw        $v0, ($a0)
/* 8B1728 802416B8 2402000C */  addiu     $v0, $zero, 0xc
/* 8B172C 802416BC AE020070 */  sw        $v0, 0x70($s0)
.L802416C0:
/* 8B1730 802416C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B1734 802416C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B1738 802416C8 03E00008 */  jr        $ra
/* 8B173C 802416CC 27BD0018 */   addiu    $sp, $sp, 0x18
