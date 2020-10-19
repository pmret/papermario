.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_D05820
/* D05820 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D05824 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* D05828 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* D0582C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* D05830 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* D05834 80240104 0C016AFA */  jal       get_current_map_header
/* D05838 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* D0583C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* D05840 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* D05844 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* D05848 80240118 0C0B1EAF */  jal       get_variable
/* D0584C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* D05850 80240120 0220202D */  daddu     $a0, $s1, $zero
/* D05854 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* D05858 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* D0585C 8024012C 00028100 */  sll       $s0, $v0, 4
/* D05860 80240130 02031821 */  addu      $v1, $s0, $v1
/* D05864 80240134 C4600000 */  lwc1      $f0, ($v1)
/* D05868 80240138 4600008D */  trunc.w.s $f2, $f0
/* D0586C 8024013C 44061000 */  mfc1      $a2, $f2
/* D05870 80240140 0C0B2026 */  jal       set_variable
/* D05874 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* D05878 80240148 0220202D */  daddu     $a0, $s1, $zero
/* D0587C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* D05880 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* D05884 80240154 02021021 */  addu      $v0, $s0, $v0
/* D05888 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* D0588C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* D05890 80240160 44061000 */  mfc1      $a2, $f2
/* D05894 80240164 0C0B2026 */  jal       set_variable
/* D05898 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* D0589C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* D058A0 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* D058A4 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* D058A8 80240178 02021021 */  addu      $v0, $s0, $v0
/* D058AC 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* D058B0 80240180 4600008D */  trunc.w.s $f2, $f0
/* D058B4 80240184 44061000 */  mfc1      $a2, $f2
/* D058B8 80240188 0C0B2026 */  jal       set_variable
/* D058BC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* D058C0 80240190 0220202D */  daddu     $a0, $s1, $zero
/* D058C4 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* D058C8 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* D058CC 8024019C 02028021 */  addu      $s0, $s0, $v0
/* D058D0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* D058D4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* D058D8 802401A8 44061000 */  mfc1      $a2, $f2
/* D058DC 802401AC 0C0B2026 */  jal       set_variable
/* D058E0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* D058E4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* D058E8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* D058EC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* D058F0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* D058F4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* D058F8 802401C8 03E00008 */  jr        $ra
/* D058FC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
