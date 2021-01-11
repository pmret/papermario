.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ActorAddMovePos
/* 1AF160 80280880 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AF164 80280884 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AF168 80280888 0080882D */  daddu     $s1, $a0, $zero
/* 1AF16C 8028088C AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AF170 80280890 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AF174 80280894 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AF178 80280898 8E30000C */  lw        $s0, 0xc($s1)
/* 1AF17C 8028089C 8E050000 */  lw        $a1, ($s0)
/* 1AF180 802808A0 0C0B1EAF */  jal       get_variable
/* 1AF184 802808A4 26100004 */   addiu    $s0, $s0, 4
/* 1AF188 802808A8 0220202D */  daddu     $a0, $s1, $zero
/* 1AF18C 802808AC 8E050000 */  lw        $a1, ($s0)
/* 1AF190 802808B0 0C0B1EAF */  jal       get_variable
/* 1AF194 802808B4 0040902D */   daddu    $s2, $v0, $zero
/* 1AF198 802808B8 8E43000C */  lw        $v1, 0xc($s2)
/* 1AF19C 802808BC C4600004 */  lwc1      $f0, 4($v1)
/* 1AF1A0 802808C0 44821000 */  mtc1      $v0, $f2
/* 1AF1A4 802808C4 00000000 */  nop
/* 1AF1A8 802808C8 468010A0 */  cvt.s.w   $f2, $f2
/* 1AF1AC 802808CC 46020000 */  add.s     $f0, $f0, $f2
/* 1AF1B0 802808D0 26100004 */  addiu     $s0, $s0, 4
/* 1AF1B4 802808D4 E4600004 */  swc1      $f0, 4($v1)
/* 1AF1B8 802808D8 8E050000 */  lw        $a1, ($s0)
/* 1AF1BC 802808DC 0C0B1EAF */  jal       get_variable
/* 1AF1C0 802808E0 0220202D */   daddu    $a0, $s1, $zero
/* 1AF1C4 802808E4 8E43000C */  lw        $v1, 0xc($s2)
/* 1AF1C8 802808E8 C4600008 */  lwc1      $f0, 8($v1)
/* 1AF1CC 802808EC 44821000 */  mtc1      $v0, $f2
/* 1AF1D0 802808F0 00000000 */  nop
/* 1AF1D4 802808F4 468010A0 */  cvt.s.w   $f2, $f2
/* 1AF1D8 802808F8 46020000 */  add.s     $f0, $f0, $f2
/* 1AF1DC 802808FC 26100004 */  addiu     $s0, $s0, 4
/* 1AF1E0 80280900 E4600008 */  swc1      $f0, 8($v1)
/* 1AF1E4 80280904 8E050000 */  lw        $a1, ($s0)
/* 1AF1E8 80280908 0C0B1EAF */  jal       get_variable
/* 1AF1EC 8028090C 0220202D */   daddu    $a0, $s1, $zero
/* 1AF1F0 80280910 8E43000C */  lw        $v1, 0xc($s2)
/* 1AF1F4 80280914 C460000C */  lwc1      $f0, 0xc($v1)
/* 1AF1F8 80280918 44821000 */  mtc1      $v0, $f2
/* 1AF1FC 8028091C 00000000 */  nop
/* 1AF200 80280920 468010A0 */  cvt.s.w   $f2, $f2
/* 1AF204 80280924 46020000 */  add.s     $f0, $f0, $f2
/* 1AF208 80280928 E460000C */  swc1      $f0, 0xc($v1)
/* 1AF20C 8028092C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AF210 80280930 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AF214 80280934 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AF218 80280938 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AF21C 8028093C 24020002 */  addiu     $v0, $zero, 2
/* 1AF220 80280940 03E00008 */  jr        $ra
/* 1AF224 80280944 27BD0020 */   addiu    $sp, $sp, 0x20
/* 1AF228 80280948 00000000 */  nop
/* 1AF22C 8028094C 00000000 */  nop
