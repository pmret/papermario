.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802CD57C
/* 0F1F2C 802CD57C 3C028007 */  lui   $v0, 0x8007
/* 0F1F30 802CD580 8C42419C */  lw    $v0, 0x419c($v0)
/* 0F1F34 802CD584 80420070 */  lb    $v0, 0x70($v0)
/* 0F1F38 802CD588 14400007 */  bnez  $v0, .L802CD5A8
/* 0F1F3C 802CD58C 00000000 */   nop   
/* 0F1F40 802CD590 3C02802E */  lui   $v0, 0x802e
/* 0F1F44 802CD594 2442ADF0 */  addiu $v0, $v0, -0x5210
/* 0F1F48 802CD598 3C01802E */  lui   $at, 0x802e
/* 0F1F4C 802CD59C AC22AE30 */  sw    $v0, -0x51d0($at)
/* 0F1F50 802CD5A0 03E00008 */  jr    $ra
/* 0F1F54 802CD5A4 00000000 */   nop   

.L802CD5A8:
/* 0F1F58 802CD5A8 3C02802E */  lui   $v0, 0x802e
/* 0F1F5C 802CD5AC 2442ADB0 */  addiu $v0, $v0, -0x5250
/* 0F1F60 802CD5B0 3C01802E */  lui   $at, 0x802e
/* 0F1F64 802CD5B4 AC22AE30 */  sw    $v0, -0x51d0($at)
/* 0F1F68 802CD5B8 03E00008 */  jr    $ra
/* 0F1F6C 802CD5BC 00000000 */   nop   

/* 0F1F70 802CD5C0 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0F1F74 802CD5C4 AFB20038 */  sw    $s2, 0x38($sp)
/* 0F1F78 802CD5C8 0080902D */  daddu $s2, $a0, $zero
/* 0F1F7C 802CD5CC AFBF0048 */  sw    $ra, 0x48($sp)
/* 0F1F80 802CD5D0 AFB50044 */  sw    $s5, 0x44($sp)
/* 0F1F84 802CD5D4 AFB40040 */  sw    $s4, 0x40($sp)
/* 0F1F88 802CD5D8 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0F1F8C 802CD5DC AFB10034 */  sw    $s1, 0x34($sp)
/* 0F1F90 802CD5E0 AFB00030 */  sw    $s0, 0x30($sp)
/* 0F1F94 802CD5E4 8E50000C */  lw    $s0, 0xc($s2)
/* 0F1F98 802CD5E8 8E050000 */  lw    $a1, ($s0)
/* 0F1F9C 802CD5EC 0C0B1EAF */  jal   get_variable
/* 0F1FA0 802CD5F0 26100004 */   addiu $s0, $s0, 4
/* 0F1FA4 802CD5F4 8E050000 */  lw    $a1, ($s0)
/* 0F1FA8 802CD5F8 26100004 */  addiu $s0, $s0, 4
/* 0F1FAC 802CD5FC 0240202D */  daddu $a0, $s2, $zero
/* 0F1FB0 802CD600 0C0B1EAF */  jal   get_variable
/* 0F1FB4 802CD604 0040882D */   daddu $s1, $v0, $zero
/* 0F1FB8 802CD608 00118880 */  sll   $s1, $s1, 2
/* 0F1FBC 802CD60C 8E140000 */  lw    $s4, ($s0)
/* 0F1FC0 802CD610 26100004 */  addiu $s0, $s0, 4
/* 0F1FC4 802CD614 3C03802E */  lui   $v1, 0x802e
/* 0F1FC8 802CD618 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F1FCC 802CD61C 8E150000 */  lw    $s5, ($s0)
/* 0F1FD0 802CD620 02238821 */  addu  $s1, $s1, $v1
/* 0F1FD4 802CD624 8E330000 */  lw    $s3, ($s1)
/* 0F1FD8 802CD628 8E100004 */  lw    $s0, 4($s0)
/* 0F1FDC 802CD62C 8E640000 */  lw    $a0, ($s3)
/* 0F1FE0 802CD630 0C047FF8 */  jal   func_8011FFE0
/* 0F1FE4 802CD634 0040882D */   daddu $s1, $v0, $zero
/* 0F1FE8 802CD638 0040202D */  daddu $a0, $v0, $zero
/* 0F1FEC 802CD63C 0C047FE6 */  jal   func_8011FF98
/* 0F1FF0 802CD640 0220282D */   daddu $a1, $s1, $zero
/* 0F1FF4 802CD644 27A30020 */  addiu $v1, $sp, 0x20
/* 0F1FF8 802CD648 AFA30010 */  sw    $v1, 0x10($sp)
/* 0F1FFC 802CD64C 27A30024 */  addiu $v1, $sp, 0x24
/* 0F2000 802CD650 AFA30014 */  sw    $v1, 0x14($sp)
/* 0F2004 802CD654 27A30028 */  addiu $v1, $sp, 0x28
/* 0F2008 802CD658 AFA30018 */  sw    $v1, 0x18($sp)
/* 0F200C 802CD65C 8C450090 */  lw    $a1, 0x90($v0)
/* 0F2010 802CD660 8C460094 */  lw    $a2, 0x94($v0)
/* 0F2014 802CD664 8C470098 */  lw    $a3, 0x98($v0)
/* 0F2018 802CD668 0C019E78 */  jal   guMtxXFML
/* 0F201C 802CD66C 26640028 */   addiu $a0, $s3, 0x28
/* 0F2020 802CD670 0240202D */  daddu $a0, $s2, $zero
/* 0F2024 802CD674 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0F2028 802CD678 4600008D */  trunc.w.s $f2, $f0
/* 0F202C 802CD67C 44061000 */  mfc1  $a2, $f2
/* 0F2030 802CD680 0C0B2026 */  jal   set_variable
/* 0F2034 802CD684 0280282D */   daddu $a1, $s4, $zero
/* 0F2038 802CD688 0240202D */  daddu $a0, $s2, $zero
/* 0F203C 802CD68C C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0F2040 802CD690 4600008D */  trunc.w.s $f2, $f0
/* 0F2044 802CD694 44061000 */  mfc1  $a2, $f2
/* 0F2048 802CD698 0C0B2026 */  jal   set_variable
/* 0F204C 802CD69C 02A0282D */   daddu $a1, $s5, $zero
/* 0F2050 802CD6A0 0240202D */  daddu $a0, $s2, $zero
/* 0F2054 802CD6A4 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0F2058 802CD6A8 4600008D */  trunc.w.s $f2, $f0
/* 0F205C 802CD6AC 44061000 */  mfc1  $a2, $f2
/* 0F2060 802CD6B0 0C0B2026 */  jal   set_variable
/* 0F2064 802CD6B4 0200282D */   daddu $a1, $s0, $zero
/* 0F2068 802CD6B8 8FBF0048 */  lw    $ra, 0x48($sp)
/* 0F206C 802CD6BC 8FB50044 */  lw    $s5, 0x44($sp)
/* 0F2070 802CD6C0 8FB40040 */  lw    $s4, 0x40($sp)
/* 0F2074 802CD6C4 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0F2078 802CD6C8 8FB20038 */  lw    $s2, 0x38($sp)
/* 0F207C 802CD6CC 8FB10034 */  lw    $s1, 0x34($sp)
/* 0F2080 802CD6D0 8FB00030 */  lw    $s0, 0x30($sp)
/* 0F2084 802CD6D4 24020002 */  addiu $v0, $zero, 2
/* 0F2088 802CD6D8 03E00008 */  jr    $ra
/* 0F208C 802CD6DC 27BD0050 */   addiu $sp, $sp, 0x50

/* 0F2090 802CD6E0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F2094 802CD6E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2098 802CD6E8 0080902D */  daddu $s2, $a0, $zero
/* 0F209C 802CD6EC AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F20A0 802CD6F0 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F20A4 802CD6F4 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F20A8 802CD6F8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F20AC 802CD6FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0F20B0 802CD700 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F20B4 802CD704 8E50000C */  lw    $s0, 0xc($s2)
/* 0F20B8 802CD708 8E050000 */  lw    $a1, ($s0)
/* 0F20BC 802CD70C 0C0B1EAF */  jal   get_variable
/* 0F20C0 802CD710 26100004 */   addiu $s0, $s0, 4
/* 0F20C4 802CD714 8E050000 */  lw    $a1, ($s0)
/* 0F20C8 802CD718 26100004 */  addiu $s0, $s0, 4
/* 0F20CC 802CD71C 0240202D */  daddu $a0, $s2, $zero
/* 0F20D0 802CD720 0C0B1EAF */  jal   get_variable
/* 0F20D4 802CD724 0040882D */   daddu $s1, $v0, $zero
/* 0F20D8 802CD728 00118880 */  sll   $s1, $s1, 2
/* 0F20DC 802CD72C 8E130000 */  lw    $s3, ($s0)
/* 0F20E0 802CD730 26100004 */  addiu $s0, $s0, 4
/* 0F20E4 802CD734 3C03802E */  lui   $v1, 0x802e
/* 0F20E8 802CD738 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F20EC 802CD73C 8E140000 */  lw    $s4, ($s0)
/* 0F20F0 802CD740 02238821 */  addu  $s1, $s1, $v1
/* 0F20F4 802CD744 8E230000 */  lw    $v1, ($s1)
/* 0F20F8 802CD748 8E150004 */  lw    $s5, 4($s0)
/* 0F20FC 802CD74C 8C640000 */  lw    $a0, ($v1)
/* 0F2100 802CD750 0C047FF8 */  jal   func_8011FFE0
/* 0F2104 802CD754 0040882D */   daddu $s1, $v0, $zero
/* 0F2108 802CD758 0040202D */  daddu $a0, $v0, $zero
/* 0F210C 802CD75C 0C047FE6 */  jal   func_8011FF98
/* 0F2110 802CD760 0220282D */   daddu $a1, $s1, $zero
/* 0F2114 802CD764 0240202D */  daddu $a0, $s2, $zero
/* 0F2118 802CD768 0040802D */  daddu $s0, $v0, $zero
/* 0F211C 802CD76C C600009C */  lwc1  $f0, 0x9c($s0)
/* 0F2120 802CD770 4600008D */  trunc.w.s $f2, $f0
/* 0F2124 802CD774 44061000 */  mfc1  $a2, $f2
/* 0F2128 802CD778 0C0B2026 */  jal   set_variable
/* 0F212C 802CD77C 0260282D */   daddu $a1, $s3, $zero
/* 0F2130 802CD780 0240202D */  daddu $a0, $s2, $zero
/* 0F2134 802CD784 C60000A0 */  lwc1  $f0, 0xa0($s0)
/* 0F2138 802CD788 4600008D */  trunc.w.s $f2, $f0
/* 0F213C 802CD78C 44061000 */  mfc1  $a2, $f2
/* 0F2140 802CD790 0C0B2026 */  jal   set_variable
/* 0F2144 802CD794 0280282D */   daddu $a1, $s4, $zero
/* 0F2148 802CD798 0240202D */  daddu $a0, $s2, $zero
/* 0F214C 802CD79C C60000A4 */  lwc1  $f0, 0xa4($s0)
/* 0F2150 802CD7A0 4600008D */  trunc.w.s $f2, $f0
/* 0F2154 802CD7A4 44061000 */  mfc1  $a2, $f2
/* 0F2158 802CD7A8 0C0B2026 */  jal   set_variable
/* 0F215C 802CD7AC 02A0282D */   daddu $a1, $s5, $zero
/* 0F2160 802CD7B0 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F2164 802CD7B4 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F2168 802CD7B8 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F216C 802CD7BC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F2170 802CD7C0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F2174 802CD7C4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2178 802CD7C8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F217C 802CD7CC 24020002 */  addiu $v0, $zero, 2
/* 0F2180 802CD7D0 03E00008 */  jr    $ra
/* 0F2184 802CD7D4 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F2188 802CD7D8 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0F218C 802CD7DC AFB20038 */  sw    $s2, 0x38($sp)
/* 0F2190 802CD7E0 0080902D */  daddu $s2, $a0, $zero
/* 0F2194 802CD7E4 AFBF0048 */  sw    $ra, 0x48($sp)
/* 0F2198 802CD7E8 AFB50044 */  sw    $s5, 0x44($sp)
/* 0F219C 802CD7EC AFB40040 */  sw    $s4, 0x40($sp)
/* 0F21A0 802CD7F0 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0F21A4 802CD7F4 AFB10034 */  sw    $s1, 0x34($sp)
/* 0F21A8 802CD7F8 AFB00030 */  sw    $s0, 0x30($sp)
/* 0F21AC 802CD7FC 8E50000C */  lw    $s0, 0xc($s2)
/* 0F21B0 802CD800 8E050000 */  lw    $a1, ($s0)
/* 0F21B4 802CD804 0C0B1EAF */  jal   get_variable
/* 0F21B8 802CD808 26100004 */   addiu $s0, $s0, 4
/* 0F21BC 802CD80C 8E050000 */  lw    $a1, ($s0)
/* 0F21C0 802CD810 26100004 */  addiu $s0, $s0, 4
/* 0F21C4 802CD814 0240202D */  daddu $a0, $s2, $zero
/* 0F21C8 802CD818 0C0B1EAF */  jal   get_variable
/* 0F21CC 802CD81C 0040882D */   daddu $s1, $v0, $zero
/* 0F21D0 802CD820 00118880 */  sll   $s1, $s1, 2
/* 0F21D4 802CD824 8E140000 */  lw    $s4, ($s0)
/* 0F21D8 802CD828 26100004 */  addiu $s0, $s0, 4
/* 0F21DC 802CD82C 3C03802E */  lui   $v1, 0x802e
/* 0F21E0 802CD830 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F21E4 802CD834 8E150000 */  lw    $s5, ($s0)
/* 0F21E8 802CD838 02238821 */  addu  $s1, $s1, $v1
/* 0F21EC 802CD83C 8E330000 */  lw    $s3, ($s1)
/* 0F21F0 802CD840 8E100004 */  lw    $s0, 4($s0)
/* 0F21F4 802CD844 8E640000 */  lw    $a0, ($s3)
/* 0F21F8 802CD848 0C047FF8 */  jal   func_8011FFE0
/* 0F21FC 802CD84C 0040882D */   daddu $s1, $v0, $zero
/* 0F2200 802CD850 0040202D */  daddu $a0, $v0, $zero
/* 0F2204 802CD854 0C047FDD */  jal   func_8011FF74
/* 0F2208 802CD858 0220282D */   daddu $a1, $s1, $zero
/* 0F220C 802CD85C 27A30020 */  addiu $v1, $sp, 0x20
/* 0F2210 802CD860 AFA30010 */  sw    $v1, 0x10($sp)
/* 0F2214 802CD864 27A30024 */  addiu $v1, $sp, 0x24
/* 0F2218 802CD868 AFA30014 */  sw    $v1, 0x14($sp)
/* 0F221C 802CD86C 27A30028 */  addiu $v1, $sp, 0x28
/* 0F2220 802CD870 AFA30018 */  sw    $v1, 0x18($sp)
/* 0F2224 802CD874 8C450090 */  lw    $a1, 0x90($v0)
/* 0F2228 802CD878 8C460094 */  lw    $a2, 0x94($v0)
/* 0F222C 802CD87C 8C470098 */  lw    $a3, 0x98($v0)
/* 0F2230 802CD880 0C019E78 */  jal   guMtxXFML
/* 0F2234 802CD884 26640028 */   addiu $a0, $s3, 0x28
/* 0F2238 802CD888 0240202D */  daddu $a0, $s2, $zero
/* 0F223C 802CD88C C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0F2240 802CD890 4600008D */  trunc.w.s $f2, $f0
/* 0F2244 802CD894 44061000 */  mfc1  $a2, $f2
/* 0F2248 802CD898 0C0B2026 */  jal   set_variable
/* 0F224C 802CD89C 0280282D */   daddu $a1, $s4, $zero
/* 0F2250 802CD8A0 0240202D */  daddu $a0, $s2, $zero
/* 0F2254 802CD8A4 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0F2258 802CD8A8 4600008D */  trunc.w.s $f2, $f0
/* 0F225C 802CD8AC 44061000 */  mfc1  $a2, $f2
/* 0F2260 802CD8B0 0C0B2026 */  jal   set_variable
/* 0F2264 802CD8B4 02A0282D */   daddu $a1, $s5, $zero
/* 0F2268 802CD8B8 0240202D */  daddu $a0, $s2, $zero
/* 0F226C 802CD8BC C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0F2270 802CD8C0 4600008D */  trunc.w.s $f2, $f0
/* 0F2274 802CD8C4 44061000 */  mfc1  $a2, $f2
/* 0F2278 802CD8C8 0C0B2026 */  jal   set_variable
/* 0F227C 802CD8CC 0200282D */   daddu $a1, $s0, $zero
/* 0F2280 802CD8D0 8FBF0048 */  lw    $ra, 0x48($sp)
/* 0F2284 802CD8D4 8FB50044 */  lw    $s5, 0x44($sp)
/* 0F2288 802CD8D8 8FB40040 */  lw    $s4, 0x40($sp)
/* 0F228C 802CD8DC 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0F2290 802CD8E0 8FB20038 */  lw    $s2, 0x38($sp)
/* 0F2294 802CD8E4 8FB10034 */  lw    $s1, 0x34($sp)
/* 0F2298 802CD8E8 8FB00030 */  lw    $s0, 0x30($sp)
/* 0F229C 802CD8EC 24020002 */  addiu $v0, $zero, 2
/* 0F22A0 802CD8F0 03E00008 */  jr    $ra
/* 0F22A4 802CD8F4 27BD0050 */   addiu $sp, $sp, 0x50

/* 0F22A8 802CD8F8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F22AC 802CD8FC AFB20018 */  sw    $s2, 0x18($sp)
/* 0F22B0 802CD900 0080902D */  daddu $s2, $a0, $zero
/* 0F22B4 802CD904 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F22B8 802CD908 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F22BC 802CD90C AFB40020 */  sw    $s4, 0x20($sp)
/* 0F22C0 802CD910 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F22C4 802CD914 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F22C8 802CD918 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F22CC 802CD91C 8E50000C */  lw    $s0, 0xc($s2)
/* 0F22D0 802CD920 8E050000 */  lw    $a1, ($s0)
/* 0F22D4 802CD924 0C0B1EAF */  jal   get_variable
/* 0F22D8 802CD928 26100004 */   addiu $s0, $s0, 4
/* 0F22DC 802CD92C 8E050000 */  lw    $a1, ($s0)
/* 0F22E0 802CD930 26100004 */  addiu $s0, $s0, 4
/* 0F22E4 802CD934 0240202D */  daddu $a0, $s2, $zero
/* 0F22E8 802CD938 0C0B1EAF */  jal   get_variable
/* 0F22EC 802CD93C 0040882D */   daddu $s1, $v0, $zero
/* 0F22F0 802CD940 00118880 */  sll   $s1, $s1, 2
/* 0F22F4 802CD944 8E130000 */  lw    $s3, ($s0)
/* 0F22F8 802CD948 26100004 */  addiu $s0, $s0, 4
/* 0F22FC 802CD94C 3C03802E */  lui   $v1, 0x802e
/* 0F2300 802CD950 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F2304 802CD954 8E140000 */  lw    $s4, ($s0)
/* 0F2308 802CD958 02238821 */  addu  $s1, $s1, $v1
/* 0F230C 802CD95C 8E230000 */  lw    $v1, ($s1)
/* 0F2310 802CD960 8E150004 */  lw    $s5, 4($s0)
/* 0F2314 802CD964 8C640000 */  lw    $a0, ($v1)
/* 0F2318 802CD968 0C047FF8 */  jal   func_8011FFE0
/* 0F231C 802CD96C 0040882D */   daddu $s1, $v0, $zero
/* 0F2320 802CD970 0040202D */  daddu $a0, $v0, $zero
/* 0F2324 802CD974 0C047FDD */  jal   func_8011FF74
/* 0F2328 802CD978 0220282D */   daddu $a1, $s1, $zero
/* 0F232C 802CD97C 0240202D */  daddu $a0, $s2, $zero
/* 0F2330 802CD980 0040802D */  daddu $s0, $v0, $zero
/* 0F2334 802CD984 C600009C */  lwc1  $f0, 0x9c($s0)
/* 0F2338 802CD988 4600008D */  trunc.w.s $f2, $f0
/* 0F233C 802CD98C 44061000 */  mfc1  $a2, $f2
/* 0F2340 802CD990 0C0B2026 */  jal   set_variable
/* 0F2344 802CD994 0260282D */   daddu $a1, $s3, $zero
/* 0F2348 802CD998 0240202D */  daddu $a0, $s2, $zero
/* 0F234C 802CD99C C60000A0 */  lwc1  $f0, 0xa0($s0)
/* 0F2350 802CD9A0 4600008D */  trunc.w.s $f2, $f0
/* 0F2354 802CD9A4 44061000 */  mfc1  $a2, $f2
/* 0F2358 802CD9A8 0C0B2026 */  jal   set_variable
/* 0F235C 802CD9AC 0280282D */   daddu $a1, $s4, $zero
/* 0F2360 802CD9B0 0240202D */  daddu $a0, $s2, $zero
/* 0F2364 802CD9B4 C60000A4 */  lwc1  $f0, 0xa4($s0)
/* 0F2368 802CD9B8 4600008D */  trunc.w.s $f2, $f0
/* 0F236C 802CD9BC 44061000 */  mfc1  $a2, $f2
/* 0F2370 802CD9C0 0C0B2026 */  jal   set_variable
/* 0F2374 802CD9C4 02A0282D */   daddu $a1, $s5, $zero
/* 0F2378 802CD9C8 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F237C 802CD9CC 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F2380 802CD9D0 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F2384 802CD9D4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F2388 802CD9D8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F238C 802CD9DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2390 802CD9E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2394 802CD9E4 24020002 */  addiu $v0, $zero, 2
/* 0F2398 802CD9E8 03E00008 */  jr    $ra
/* 0F239C 802CD9EC 27BD0030 */   addiu $sp, $sp, 0x30

/* 0F23A0 802CD9F0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F23A4 802CD9F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F23A8 802CD9F8 0080902D */  daddu $s2, $a0, $zero
/* 0F23AC 802CD9FC AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F23B0 802CDA00 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F23B4 802CDA04 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F23B8 802CDA08 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F23BC 802CDA0C 8E50000C */  lw    $s0, 0xc($s2)
/* 0F23C0 802CDA10 8E050000 */  lw    $a1, ($s0)
/* 0F23C4 802CDA14 0C0B1EAF */  jal   get_variable
/* 0F23C8 802CDA18 26100004 */   addiu $s0, $s0, 4
/* 0F23CC 802CDA1C 8E050000 */  lw    $a1, ($s0)
/* 0F23D0 802CDA20 26100004 */  addiu $s0, $s0, 4
/* 0F23D4 802CDA24 0240202D */  daddu $a0, $s2, $zero
/* 0F23D8 802CDA28 0C0B1EAF */  jal   get_variable
/* 0F23DC 802CDA2C 0040882D */   daddu $s1, $v0, $zero
/* 0F23E0 802CDA30 0240202D */  daddu $a0, $s2, $zero
/* 0F23E4 802CDA34 8E050004 */  lw    $a1, 4($s0)
/* 0F23E8 802CDA38 8E130000 */  lw    $s3, ($s0)
/* 0F23EC 802CDA3C 0C0B1EAF */  jal   get_variable
/* 0F23F0 802CDA40 0040902D */   daddu $s2, $v0, $zero
/* 0F23F4 802CDA44 3C03802E */  lui   $v1, 0x802e
/* 0F23F8 802CDA48 8C63AE30 */  lw    $v1, -0x51d0($v1)
/* 0F23FC 802CDA4C 00118880 */  sll   $s1, $s1, 2
/* 0F2400 802CDA50 02238821 */  addu  $s1, $s1, $v1
/* 0F2404 802CDA54 8E230000 */  lw    $v1, ($s1)
/* 0F2408 802CDA58 8C640000 */  lw    $a0, ($v1)
/* 0F240C 802CDA5C 0C047FF8 */  jal   func_8011FFE0
/* 0F2410 802CDA60 0040802D */   daddu $s0, $v0, $zero
/* 0F2414 802CDA64 0040202D */  daddu $a0, $v0, $zero
/* 0F2418 802CDA68 0C047FE6 */  jal   func_8011FF98
/* 0F241C 802CDA6C 0240282D */   daddu $a1, $s2, $zero
/* 0F2420 802CDA70 12000004 */  beqz  $s0, .L802CDA84
/* 0F2424 802CDA74 0040202D */   daddu $a0, $v0, $zero
/* 0F2428 802CDA78 948200F4 */  lhu   $v0, 0xf4($a0)
/* 0F242C 802CDA7C 080B36A4 */  j     .L802CDA90
/* 0F2430 802CDA80 00531025 */   or    $v0, $v0, $s3

.L802CDA84:
/* 0F2434 802CDA84 948200F4 */  lhu   $v0, 0xf4($a0)
/* 0F2438 802CDA88 00131827 */  nor   $v1, $zero, $s3
/* 0F243C 802CDA8C 00431024 */  and   $v0, $v0, $v1
.L802CDA90:
/* 0F2440 802CDA90 A48200F4 */  sh    $v0, 0xf4($a0)
/* 0F2444 802CDA94 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F2448 802CDA98 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F244C 802CDA9C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F2450 802CDAA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2454 802CDAA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2458 802CDAA8 24020002 */  addiu $v0, $zero, 2
/* 0F245C 802CDAAC 03E00008 */  jr    $ra
/* 0F2460 802CDAB0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F2464 802CDAB4 00000000 */  nop   
/* 0F2468 802CDAB8 00000000 */  nop   
/* 0F246C 802CDABC 00000000 */  nop   

.set reorder
