.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD6E0
/* F2090 802CD6E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F2094 802CD6E4 AFB20018 */  sw        $s2, 0x18($sp)
/* F2098 802CD6E8 0080902D */  daddu     $s2, $a0, $zero
/* F209C 802CD6EC AFBF0028 */  sw        $ra, 0x28($sp)
/* F20A0 802CD6F0 AFB50024 */  sw        $s5, 0x24($sp)
/* F20A4 802CD6F4 AFB40020 */  sw        $s4, 0x20($sp)
/* F20A8 802CD6F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* F20AC 802CD6FC AFB10014 */  sw        $s1, 0x14($sp)
/* F20B0 802CD700 AFB00010 */  sw        $s0, 0x10($sp)
/* F20B4 802CD704 8E50000C */  lw        $s0, 0xc($s2)
/* F20B8 802CD708 8E050000 */  lw        $a1, ($s0)
/* F20BC 802CD70C 0C0B1EAF */  jal       get_variable
/* F20C0 802CD710 26100004 */   addiu    $s0, $s0, 4
/* F20C4 802CD714 8E050000 */  lw        $a1, ($s0)
/* F20C8 802CD718 26100004 */  addiu     $s0, $s0, 4
/* F20CC 802CD71C 0240202D */  daddu     $a0, $s2, $zero
/* F20D0 802CD720 0C0B1EAF */  jal       get_variable
/* F20D4 802CD724 0040882D */   daddu    $s1, $v0, $zero
/* F20D8 802CD728 00118880 */  sll       $s1, $s1, 2
/* F20DC 802CD72C 8E130000 */  lw        $s3, ($s0)
/* F20E0 802CD730 26100004 */  addiu     $s0, $s0, 4
/* F20E4 802CD734 3C03802E */  lui       $v1, %hi(gAnimatedMeshesPtr)
/* F20E8 802CD738 8C63AE30 */  lw        $v1, %lo(gAnimatedMeshesPtr)($v1)
/* F20EC 802CD73C 8E140000 */  lw        $s4, ($s0)
/* F20F0 802CD740 02238821 */  addu      $s1, $s1, $v1
/* F20F4 802CD744 8E230000 */  lw        $v1, ($s1)
/* F20F8 802CD748 8E150004 */  lw        $s5, 4($s0)
/* F20FC 802CD74C 8C640000 */  lw        $a0, ($v1)
/* F2100 802CD750 0C047FF8 */  jal       func_8011FFE0
/* F2104 802CD754 0040882D */   daddu    $s1, $v0, $zero
/* F2108 802CD758 0040202D */  daddu     $a0, $v0, $zero
/* F210C 802CD75C 0C047FE6 */  jal       func_8011FF98
/* F2110 802CD760 0220282D */   daddu    $a1, $s1, $zero
/* F2114 802CD764 0240202D */  daddu     $a0, $s2, $zero
/* F2118 802CD768 0040802D */  daddu     $s0, $v0, $zero
/* F211C 802CD76C C600009C */  lwc1      $f0, 0x9c($s0)
/* F2120 802CD770 4600008D */  trunc.w.s $f2, $f0
/* F2124 802CD774 44061000 */  mfc1      $a2, $f2
/* F2128 802CD778 0C0B2026 */  jal       set_variable
/* F212C 802CD77C 0260282D */   daddu    $a1, $s3, $zero
/* F2130 802CD780 0240202D */  daddu     $a0, $s2, $zero
/* F2134 802CD784 C60000A0 */  lwc1      $f0, 0xa0($s0)
/* F2138 802CD788 4600008D */  trunc.w.s $f2, $f0
/* F213C 802CD78C 44061000 */  mfc1      $a2, $f2
/* F2140 802CD790 0C0B2026 */  jal       set_variable
/* F2144 802CD794 0280282D */   daddu    $a1, $s4, $zero
/* F2148 802CD798 0240202D */  daddu     $a0, $s2, $zero
/* F214C 802CD79C C60000A4 */  lwc1      $f0, 0xa4($s0)
/* F2150 802CD7A0 4600008D */  trunc.w.s $f2, $f0
/* F2154 802CD7A4 44061000 */  mfc1      $a2, $f2
/* F2158 802CD7A8 0C0B2026 */  jal       set_variable
/* F215C 802CD7AC 02A0282D */   daddu    $a1, $s5, $zero
/* F2160 802CD7B0 8FBF0028 */  lw        $ra, 0x28($sp)
/* F2164 802CD7B4 8FB50024 */  lw        $s5, 0x24($sp)
/* F2168 802CD7B8 8FB40020 */  lw        $s4, 0x20($sp)
/* F216C 802CD7BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* F2170 802CD7C0 8FB20018 */  lw        $s2, 0x18($sp)
/* F2174 802CD7C4 8FB10014 */  lw        $s1, 0x14($sp)
/* F2178 802CD7C8 8FB00010 */  lw        $s0, 0x10($sp)
/* F217C 802CD7CC 24020002 */  addiu     $v0, $zero, 2
/* F2180 802CD7D0 03E00008 */  jr        $ra
/* F2184 802CD7D4 27BD0030 */   addiu    $sp, $sp, 0x30
