.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241870
/* 8ED690 80241870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED694 80241874 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED698 80241878 0080882D */  daddu     $s1, $a0, $zero
/* 8ED69C 8024187C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8ED6A0 80241880 AFB20018 */  sw        $s2, 0x18($sp)
/* 8ED6A4 80241884 0C016AFA */  jal       get_current_map_header
/* 8ED6A8 80241888 AFB00010 */   sw       $s0, 0x10($sp)
/* 8ED6AC 8024188C 0220202D */  daddu     $a0, $s1, $zero
/* 8ED6B0 80241890 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED6B4 80241894 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8ED6B8 80241898 0C0B1EAF */  jal       get_variable
/* 8ED6BC 8024189C 0040902D */   daddu    $s2, $v0, $zero
/* 8ED6C0 802418A0 0220202D */  daddu     $a0, $s1, $zero
/* 8ED6C4 802418A4 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED6C8 802418A8 8E430014 */  lw        $v1, 0x14($s2)
/* 8ED6CC 802418AC 00028100 */  sll       $s0, $v0, 4
/* 8ED6D0 802418B0 02031821 */  addu      $v1, $s0, $v1
/* 8ED6D4 802418B4 C4600000 */  lwc1      $f0, ($v1)
/* 8ED6D8 802418B8 4600008D */  trunc.w.s $f2, $f0
/* 8ED6DC 802418BC 44061000 */  mfc1      $a2, $f2
/* 8ED6E0 802418C0 0C0B2026 */  jal       set_variable
/* 8ED6E4 802418C4 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8ED6E8 802418C8 0220202D */  daddu     $a0, $s1, $zero
/* 8ED6EC 802418CC 8E420014 */  lw        $v0, 0x14($s2)
/* 8ED6F0 802418D0 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED6F4 802418D4 02021021 */  addu      $v0, $s0, $v0
/* 8ED6F8 802418D8 C4400004 */  lwc1      $f0, 4($v0)
/* 8ED6FC 802418DC 4600008D */  trunc.w.s $f2, $f0
/* 8ED700 802418E0 44061000 */  mfc1      $a2, $f2
/* 8ED704 802418E4 0C0B2026 */  jal       set_variable
/* 8ED708 802418E8 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8ED70C 802418EC 0220202D */  daddu     $a0, $s1, $zero
/* 8ED710 802418F0 8E420014 */  lw        $v0, 0x14($s2)
/* 8ED714 802418F4 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED718 802418F8 02021021 */  addu      $v0, $s0, $v0
/* 8ED71C 802418FC C4400008 */  lwc1      $f0, 8($v0)
/* 8ED720 80241900 4600008D */  trunc.w.s $f2, $f0
/* 8ED724 80241904 44061000 */  mfc1      $a2, $f2
/* 8ED728 80241908 0C0B2026 */  jal       set_variable
/* 8ED72C 8024190C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8ED730 80241910 0220202D */  daddu     $a0, $s1, $zero
/* 8ED734 80241914 8E420014 */  lw        $v0, 0x14($s2)
/* 8ED738 80241918 3C05FE36 */  lui       $a1, 0xfe36
/* 8ED73C 8024191C 02028021 */  addu      $s0, $s0, $v0
/* 8ED740 80241920 C600000C */  lwc1      $f0, 0xc($s0)
/* 8ED744 80241924 4600008D */  trunc.w.s $f2, $f0
/* 8ED748 80241928 44061000 */  mfc1      $a2, $f2
/* 8ED74C 8024192C 0C0B2026 */  jal       set_variable
/* 8ED750 80241930 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8ED754 80241934 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8ED758 80241938 8FB20018 */  lw        $s2, 0x18($sp)
/* 8ED75C 8024193C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED760 80241940 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED764 80241944 24020002 */  addiu     $v0, $zero, 2
/* 8ED768 80241948 03E00008 */  jr        $ra
/* 8ED76C 8024194C 27BD0020 */   addiu    $sp, $sp, 0x20
