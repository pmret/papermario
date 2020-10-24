.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243690_95E890
/* 95E890 80243690 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95E894 80243694 AFB10014 */  sw        $s1, 0x14($sp)
/* 95E898 80243698 0080882D */  daddu     $s1, $a0, $zero
/* 95E89C 8024369C AFBF001C */  sw        $ra, 0x1c($sp)
/* 95E8A0 802436A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 95E8A4 802436A4 0C016AFA */  jal       get_current_map_header
/* 95E8A8 802436A8 AFB00010 */   sw       $s0, 0x10($sp)
/* 95E8AC 802436AC 0220202D */  daddu     $a0, $s1, $zero
/* 95E8B0 802436B0 3C05FE36 */  lui       $a1, 0xfe36
/* 95E8B4 802436B4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 95E8B8 802436B8 0C0B1EAF */  jal       get_variable
/* 95E8BC 802436BC 0040902D */   daddu    $s2, $v0, $zero
/* 95E8C0 802436C0 0220202D */  daddu     $a0, $s1, $zero
/* 95E8C4 802436C4 3C05FE36 */  lui       $a1, 0xfe36
/* 95E8C8 802436C8 8E430014 */  lw        $v1, 0x14($s2)
/* 95E8CC 802436CC 00028100 */  sll       $s0, $v0, 4
/* 95E8D0 802436D0 02031821 */  addu      $v1, $s0, $v1
/* 95E8D4 802436D4 C4600000 */  lwc1      $f0, ($v1)
/* 95E8D8 802436D8 4600008D */  trunc.w.s $f2, $f0
/* 95E8DC 802436DC 44061000 */  mfc1      $a2, $f2
/* 95E8E0 802436E0 0C0B2026 */  jal       set_variable
/* 95E8E4 802436E4 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 95E8E8 802436E8 0220202D */  daddu     $a0, $s1, $zero
/* 95E8EC 802436EC 8E420014 */  lw        $v0, 0x14($s2)
/* 95E8F0 802436F0 3C05FE36 */  lui       $a1, 0xfe36
/* 95E8F4 802436F4 02021021 */  addu      $v0, $s0, $v0
/* 95E8F8 802436F8 C4400004 */  lwc1      $f0, 4($v0)
/* 95E8FC 802436FC 4600008D */  trunc.w.s $f2, $f0
/* 95E900 80243700 44061000 */  mfc1      $a2, $f2
/* 95E904 80243704 0C0B2026 */  jal       set_variable
/* 95E908 80243708 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 95E90C 8024370C 0220202D */  daddu     $a0, $s1, $zero
/* 95E910 80243710 8E420014 */  lw        $v0, 0x14($s2)
/* 95E914 80243714 3C05FE36 */  lui       $a1, 0xfe36
/* 95E918 80243718 02021021 */  addu      $v0, $s0, $v0
/* 95E91C 8024371C C4400008 */  lwc1      $f0, 8($v0)
/* 95E920 80243720 4600008D */  trunc.w.s $f2, $f0
/* 95E924 80243724 44061000 */  mfc1      $a2, $f2
/* 95E928 80243728 0C0B2026 */  jal       set_variable
/* 95E92C 8024372C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 95E930 80243730 0220202D */  daddu     $a0, $s1, $zero
/* 95E934 80243734 8E420014 */  lw        $v0, 0x14($s2)
/* 95E938 80243738 3C05FE36 */  lui       $a1, 0xfe36
/* 95E93C 8024373C 02028021 */  addu      $s0, $s0, $v0
/* 95E940 80243740 C600000C */  lwc1      $f0, 0xc($s0)
/* 95E944 80243744 4600008D */  trunc.w.s $f2, $f0
/* 95E948 80243748 44061000 */  mfc1      $a2, $f2
/* 95E94C 8024374C 0C0B2026 */  jal       set_variable
/* 95E950 80243750 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 95E954 80243754 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95E958 80243758 8FB20018 */  lw        $s2, 0x18($sp)
/* 95E95C 8024375C 8FB10014 */  lw        $s1, 0x14($sp)
/* 95E960 80243760 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E964 80243764 24020002 */  addiu     $v0, $zero, 2
/* 95E968 80243768 03E00008 */  jr        $ra
/* 95E96C 8024376C 27BD0020 */   addiu    $sp, $sp, 0x20
