.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_E0E890
/* E0E890 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0E894 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* E0E898 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* E0E89C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* E0E8A0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* E0E8A4 80240104 0C016AFA */  jal       get_current_map_header
/* E0E8A8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* E0E8AC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* E0E8B0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* E0E8B4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* E0E8B8 80240118 0C0B1EAF */  jal       get_variable
/* E0E8BC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* E0E8C0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* E0E8C4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* E0E8C8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* E0E8CC 8024012C 00028100 */  sll       $s0, $v0, 4
/* E0E8D0 80240130 02031821 */  addu      $v1, $s0, $v1
/* E0E8D4 80240134 C4600000 */  lwc1      $f0, ($v1)
/* E0E8D8 80240138 4600008D */  trunc.w.s $f2, $f0
/* E0E8DC 8024013C 44061000 */  mfc1      $a2, $f2
/* E0E8E0 80240140 0C0B2026 */  jal       set_variable
/* E0E8E4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* E0E8E8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* E0E8EC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* E0E8F0 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* E0E8F4 80240154 02021021 */  addu      $v0, $s0, $v0
/* E0E8F8 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* E0E8FC 8024015C 4600008D */  trunc.w.s $f2, $f0
/* E0E900 80240160 44061000 */  mfc1      $a2, $f2
/* E0E904 80240164 0C0B2026 */  jal       set_variable
/* E0E908 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* E0E90C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* E0E910 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* E0E914 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* E0E918 80240178 02021021 */  addu      $v0, $s0, $v0
/* E0E91C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* E0E920 80240180 4600008D */  trunc.w.s $f2, $f0
/* E0E924 80240184 44061000 */  mfc1      $a2, $f2
/* E0E928 80240188 0C0B2026 */  jal       set_variable
/* E0E92C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* E0E930 80240190 0220202D */  daddu     $a0, $s1, $zero
/* E0E934 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* E0E938 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* E0E93C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* E0E940 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* E0E944 802401A4 4600008D */  trunc.w.s $f2, $f0
/* E0E948 802401A8 44061000 */  mfc1      $a2, $f2
/* E0E94C 802401AC 0C0B2026 */  jal       set_variable
/* E0E950 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* E0E954 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* E0E958 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* E0E95C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* E0E960 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* E0E964 802401C4 24020002 */  addiu     $v0, $zero, 2
/* E0E968 802401C8 03E00008 */  jr        $ra
/* E0E96C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
