.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C0_D4BAE0
/* D4BAE0 802400C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D4BAE4 802400C4 AFB10014 */  sw        $s1, 0x14($sp)
/* D4BAE8 802400C8 0080882D */  daddu     $s1, $a0, $zero
/* D4BAEC 802400CC AFBF0020 */  sw        $ra, 0x20($sp)
/* D4BAF0 802400D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* D4BAF4 802400D4 AFB20018 */  sw        $s2, 0x18($sp)
/* D4BAF8 802400D8 AFB00010 */  sw        $s0, 0x10($sp)
/* D4BAFC 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* D4BB00 802400E0 8E050000 */  lw        $a1, ($s0)
/* D4BB04 802400E4 0C0B1EAF */  jal       get_variable
/* D4BB08 802400E8 26100004 */   addiu    $s0, $s0, 4
/* D4BB0C 802400EC 8E050000 */  lw        $a1, ($s0)
/* D4BB10 802400F0 26100004 */  addiu     $s0, $s0, 4
/* D4BB14 802400F4 0220202D */  daddu     $a0, $s1, $zero
/* D4BB18 802400F8 0C0B210B */  jal       get_float_variable
/* D4BB1C 802400FC 0040982D */   daddu    $s3, $v0, $zero
/* D4BB20 80240100 8E050000 */  lw        $a1, ($s0)
/* D4BB24 80240104 26100004 */  addiu     $s0, $s0, 4
/* D4BB28 80240108 4600008D */  trunc.w.s $f2, $f0
/* D4BB2C 8024010C 44121000 */  mfc1      $s2, $f2
/* D4BB30 80240110 0C0B210B */  jal       get_float_variable
/* D4BB34 80240114 0220202D */   daddu    $a0, $s1, $zero
/* D4BB38 80240118 0220202D */  daddu     $a0, $s1, $zero
/* D4BB3C 8024011C 8E050000 */  lw        $a1, ($s0)
/* D4BB40 80240120 4600008D */  trunc.w.s $f2, $f0
/* D4BB44 80240124 44111000 */  mfc1      $s1, $f2
/* D4BB48 80240128 0C0B210B */  jal       get_float_variable
/* D4BB4C 8024012C 00000000 */   nop
/* D4BB50 80240130 4600008D */  trunc.w.s $f2, $f0
/* D4BB54 80240134 44101000 */  mfc1      $s0, $f2
/* D4BB58 80240138 0C04C3D6 */  jal       get_item_entity
/* D4BB5C 8024013C 0260202D */   daddu    $a0, $s3, $zero
/* D4BB60 80240140 0040182D */  daddu     $v1, $v0, $zero
/* D4BB64 80240144 44920000 */  mtc1      $s2, $f0
/* D4BB68 80240148 00000000 */  nop
/* D4BB6C 8024014C 46800020 */  cvt.s.w   $f0, $f0
/* D4BB70 80240150 E4600008 */  swc1      $f0, 8($v1)
/* D4BB74 80240154 44910000 */  mtc1      $s1, $f0
/* D4BB78 80240158 00000000 */  nop
/* D4BB7C 8024015C 46800020 */  cvt.s.w   $f0, $f0
/* D4BB80 80240160 E460000C */  swc1      $f0, 0xc($v1)
/* D4BB84 80240164 44900000 */  mtc1      $s0, $f0
/* D4BB88 80240168 00000000 */  nop
/* D4BB8C 8024016C 46800020 */  cvt.s.w   $f0, $f0
/* D4BB90 80240170 E4600010 */  swc1      $f0, 0x10($v1)
/* D4BB94 80240174 8FBF0020 */  lw        $ra, 0x20($sp)
/* D4BB98 80240178 8FB3001C */  lw        $s3, 0x1c($sp)
/* D4BB9C 8024017C 8FB20018 */  lw        $s2, 0x18($sp)
/* D4BBA0 80240180 8FB10014 */  lw        $s1, 0x14($sp)
/* D4BBA4 80240184 8FB00010 */  lw        $s0, 0x10($sp)
/* D4BBA8 80240188 24020002 */  addiu     $v0, $zero, 2
/* D4BBAC 8024018C 03E00008 */  jr        $ra
/* D4BBB0 80240190 27BD0028 */   addiu    $sp, $sp, 0x28
