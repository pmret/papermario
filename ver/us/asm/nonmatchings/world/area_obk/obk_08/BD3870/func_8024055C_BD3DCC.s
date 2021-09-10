.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024055C_BD3DCC
/* BD3DCC 8024055C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD3DD0 80240560 AFB10014 */  sw        $s1, 0x14($sp)
/* BD3DD4 80240564 0080882D */  daddu     $s1, $a0, $zero
/* BD3DD8 80240568 AFBF001C */  sw        $ra, 0x1c($sp)
/* BD3DDC 8024056C AFB20018 */  sw        $s2, 0x18($sp)
/* BD3DE0 80240570 AFB00010 */  sw        $s0, 0x10($sp)
/* BD3DE4 80240574 8E30000C */  lw        $s0, 0xc($s1)
/* BD3DE8 80240578 8E050000 */  lw        $a1, ($s0)
/* BD3DEC 8024057C 0C0B210B */  jal       evt_get_float_variable
/* BD3DF0 80240580 26100004 */   addiu    $s0, $s0, 4
/* BD3DF4 80240584 8E050000 */  lw        $a1, ($s0)
/* BD3DF8 80240588 26100004 */  addiu     $s0, $s0, 4
/* BD3DFC 8024058C 4600008D */  trunc.w.s $f2, $f0
/* BD3E00 80240590 44121000 */  mfc1      $s2, $f2
/* BD3E04 80240594 0C0B210B */  jal       evt_get_float_variable
/* BD3E08 80240598 0220202D */   daddu    $a0, $s1, $zero
/* BD3E0C 8024059C 0220202D */  daddu     $a0, $s1, $zero
/* BD3E10 802405A0 8E050000 */  lw        $a1, ($s0)
/* BD3E14 802405A4 4600008D */  trunc.w.s $f2, $f0
/* BD3E18 802405A8 44111000 */  mfc1      $s1, $f2
/* BD3E1C 802405AC 0C0B210B */  jal       evt_get_float_variable
/* BD3E20 802405B0 00000000 */   nop
/* BD3E24 802405B4 0000202D */  daddu     $a0, $zero, $zero
/* BD3E28 802405B8 3C05FD05 */  lui       $a1, 0xfd05
/* BD3E2C 802405BC 4600008D */  trunc.w.s $f2, $f0
/* BD3E30 802405C0 44101000 */  mfc1      $s0, $f2
/* BD3E34 802405C4 0C0B1EAF */  jal       evt_get_variable
/* BD3E38 802405C8 34A50F8A */   ori      $a1, $a1, 0xf8a
/* BD3E3C 802405CC 0040182D */  daddu     $v1, $v0, $zero
/* BD3E40 802405D0 44920000 */  mtc1      $s2, $f0
/* BD3E44 802405D4 00000000 */  nop
/* BD3E48 802405D8 46800020 */  cvt.s.w   $f0, $f0
/* BD3E4C 802405DC E4600010 */  swc1      $f0, 0x10($v1)
/* BD3E50 802405E0 44910000 */  mtc1      $s1, $f0
/* BD3E54 802405E4 00000000 */  nop
/* BD3E58 802405E8 46800020 */  cvt.s.w   $f0, $f0
/* BD3E5C 802405EC E4600014 */  swc1      $f0, 0x14($v1)
/* BD3E60 802405F0 44900000 */  mtc1      $s0, $f0
/* BD3E64 802405F4 00000000 */  nop
/* BD3E68 802405F8 46800020 */  cvt.s.w   $f0, $f0
/* BD3E6C 802405FC E4600018 */  swc1      $f0, 0x18($v1)
/* BD3E70 80240600 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD3E74 80240604 8FB20018 */  lw        $s2, 0x18($sp)
/* BD3E78 80240608 8FB10014 */  lw        $s1, 0x14($sp)
/* BD3E7C 8024060C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD3E80 80240610 24020002 */  addiu     $v0, $zero, 2
/* BD3E84 80240614 03E00008 */  jr        $ra
/* BD3E88 80240618 27BD0020 */   addiu    $sp, $sp, 0x20
