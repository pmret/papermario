.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_B0726C
/* B0726C 8024086C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B07270 80240870 AFB10014 */  sw        $s1, 0x14($sp)
/* B07274 80240874 0080882D */  daddu     $s1, $a0, $zero
/* B07278 80240878 AFBF001C */  sw        $ra, 0x1c($sp)
/* B0727C 8024087C AFB20018 */  sw        $s2, 0x18($sp)
/* B07280 80240880 AFB00010 */  sw        $s0, 0x10($sp)
/* B07284 80240884 8E30000C */  lw        $s0, 0xc($s1)
/* B07288 80240888 8E050000 */  lw        $a1, ($s0)
/* B0728C 8024088C 0C0B210B */  jal       evt_get_float_variable
/* B07290 80240890 26100004 */   addiu    $s0, $s0, 4
/* B07294 80240894 8E050000 */  lw        $a1, ($s0)
/* B07298 80240898 26100004 */  addiu     $s0, $s0, 4
/* B0729C 8024089C 4600008D */  trunc.w.s $f2, $f0
/* B072A0 802408A0 44121000 */  mfc1      $s2, $f2
/* B072A4 802408A4 0C0B210B */  jal       evt_get_float_variable
/* B072A8 802408A8 0220202D */   daddu    $a0, $s1, $zero
/* B072AC 802408AC 0220202D */  daddu     $a0, $s1, $zero
/* B072B0 802408B0 8E050000 */  lw        $a1, ($s0)
/* B072B4 802408B4 4600008D */  trunc.w.s $f2, $f0
/* B072B8 802408B8 44111000 */  mfc1      $s1, $f2
/* B072BC 802408BC 0C0B210B */  jal       evt_get_float_variable
/* B072C0 802408C0 00000000 */   nop
/* B072C4 802408C4 0000202D */  daddu     $a0, $zero, $zero
/* B072C8 802408C8 3C05FD05 */  lui       $a1, 0xfd05
/* B072CC 802408CC 4600008D */  trunc.w.s $f2, $f0
/* B072D0 802408D0 44101000 */  mfc1      $s0, $f2
/* B072D4 802408D4 0C0B1EAF */  jal       evt_get_variable
/* B072D8 802408D8 34A50F8A */   ori      $a1, $a1, 0xf8a
/* B072DC 802408DC 0040182D */  daddu     $v1, $v0, $zero
/* B072E0 802408E0 44920000 */  mtc1      $s2, $f0
/* B072E4 802408E4 00000000 */  nop
/* B072E8 802408E8 46800020 */  cvt.s.w   $f0, $f0
/* B072EC 802408EC E4600010 */  swc1      $f0, 0x10($v1)
/* B072F0 802408F0 44910000 */  mtc1      $s1, $f0
/* B072F4 802408F4 00000000 */  nop
/* B072F8 802408F8 46800020 */  cvt.s.w   $f0, $f0
/* B072FC 802408FC E4600014 */  swc1      $f0, 0x14($v1)
/* B07300 80240900 44900000 */  mtc1      $s0, $f0
/* B07304 80240904 00000000 */  nop
/* B07308 80240908 46800020 */  cvt.s.w   $f0, $f0
/* B0730C 8024090C E4600018 */  swc1      $f0, 0x18($v1)
/* B07310 80240910 8FBF001C */  lw        $ra, 0x1c($sp)
/* B07314 80240914 8FB20018 */  lw        $s2, 0x18($sp)
/* B07318 80240918 8FB10014 */  lw        $s1, 0x14($sp)
/* B0731C 8024091C 8FB00010 */  lw        $s0, 0x10($sp)
/* B07320 80240920 24020002 */  addiu     $v0, $zero, 2
/* B07324 80240924 03E00008 */  jr        $ra
/* B07328 80240928 27BD0020 */   addiu    $sp, $sp, 0x20
