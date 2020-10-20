.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240074_BFD8F4
/* BFD8F4 80240074 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BFD8F8 80240078 AFB20018 */  sw        $s2, 0x18($sp)
/* BFD8FC 8024007C 0080902D */  daddu     $s2, $a0, $zero
/* BFD900 80240080 AFBF001C */  sw        $ra, 0x1c($sp)
/* BFD904 80240084 AFB10014 */  sw        $s1, 0x14($sp)
/* BFD908 80240088 AFB00010 */  sw        $s0, 0x10($sp)
/* BFD90C 8024008C 8E50000C */  lw        $s0, 0xc($s2)
/* BFD910 80240090 8E050000 */  lw        $a1, ($s0)
/* BFD914 80240094 0C0B1EAF */  jal       get_variable
/* BFD918 80240098 26100004 */   addiu    $s0, $s0, 4
/* BFD91C 8024009C 0C04417A */  jal       get_entity_by_index
/* BFD920 802400A0 0040202D */   daddu    $a0, $v0, $zero
/* BFD924 802400A4 8E050000 */  lw        $a1, ($s0)
/* BFD928 802400A8 26100004 */  addiu     $s0, $s0, 4
/* BFD92C 802400AC 0040882D */  daddu     $s1, $v0, $zero
/* BFD930 802400B0 C6200048 */  lwc1      $f0, 0x48($s1)
/* BFD934 802400B4 4600008D */  trunc.w.s $f2, $f0
/* BFD938 802400B8 44061000 */  mfc1      $a2, $f2
/* BFD93C 802400BC 0C0B2026 */  jal       set_variable
/* BFD940 802400C0 0240202D */   daddu    $a0, $s2, $zero
/* BFD944 802400C4 8E050000 */  lw        $a1, ($s0)
/* BFD948 802400C8 26100004 */  addiu     $s0, $s0, 4
/* BFD94C 802400CC C620004C */  lwc1      $f0, 0x4c($s1)
/* BFD950 802400D0 4600008D */  trunc.w.s $f2, $f0
/* BFD954 802400D4 44061000 */  mfc1      $a2, $f2
/* BFD958 802400D8 0C0B2026 */  jal       set_variable
/* BFD95C 802400DC 0240202D */   daddu    $a0, $s2, $zero
/* BFD960 802400E0 C6200050 */  lwc1      $f0, 0x50($s1)
/* BFD964 802400E4 8E050000 */  lw        $a1, ($s0)
/* BFD968 802400E8 4600008D */  trunc.w.s $f2, $f0
/* BFD96C 802400EC 44061000 */  mfc1      $a2, $f2
/* BFD970 802400F0 0C0B2026 */  jal       set_variable
/* BFD974 802400F4 0240202D */   daddu    $a0, $s2, $zero
/* BFD978 802400F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* BFD97C 802400FC 8FB20018 */  lw        $s2, 0x18($sp)
/* BFD980 80240100 8FB10014 */  lw        $s1, 0x14($sp)
/* BFD984 80240104 8FB00010 */  lw        $s0, 0x10($sp)
/* BFD988 80240108 24020002 */  addiu     $v0, $zero, 2
/* BFD98C 8024010C 03E00008 */  jr        $ra
/* BFD990 80240110 27BD0020 */   addiu    $sp, $sp, 0x20
/* BFD994 80240114 00000000 */  nop       
/* BFD998 80240118 00000000 */  nop       
/* BFD99C 8024011C 00000000 */  nop       
