.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_E0EE80
/* E0EE80 802406E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E0EE84 802406E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* E0EE88 802406E8 0080982D */  daddu     $s3, $a0, $zero
/* E0EE8C 802406EC AFBF0020 */  sw        $ra, 0x20($sp)
/* E0EE90 802406F0 AFB20018 */  sw        $s2, 0x18($sp)
/* E0EE94 802406F4 AFB10014 */  sw        $s1, 0x14($sp)
/* E0EE98 802406F8 AFB00010 */  sw        $s0, 0x10($sp)
/* E0EE9C 802406FC 8E720148 */  lw        $s2, 0x148($s3)
/* E0EEA0 80240700 86440008 */  lh        $a0, 8($s2)
/* E0EEA4 80240704 0C00EABB */  jal       get_npc_unsafe
/* E0EEA8 80240708 00A0882D */   daddu    $s1, $a1, $zero
/* E0EEAC 8024070C 8E240008 */  lw        $a0, 8($s1)
/* E0EEB0 80240710 0040802D */  daddu     $s0, $v0, $zero
/* E0EEB4 80240714 00041FC2 */  srl       $v1, $a0, 0x1f
/* E0EEB8 80240718 00832021 */  addu      $a0, $a0, $v1
/* E0EEBC 8024071C 00042043 */  sra       $a0, $a0, 1
/* E0EEC0 80240720 0C00A67F */  jal       rand_int
/* E0EEC4 80240724 24840001 */   addiu    $a0, $a0, 1
/* E0EEC8 80240728 8E230008 */  lw        $v1, 8($s1)
/* E0EECC 8024072C 240400B4 */  addiu     $a0, $zero, 0xb4
/* E0EED0 80240730 00032FC2 */  srl       $a1, $v1, 0x1f
/* E0EED4 80240734 00651821 */  addu      $v1, $v1, $a1
/* E0EED8 80240738 00031843 */  sra       $v1, $v1, 1
/* E0EEDC 8024073C 00621821 */  addu      $v1, $v1, $v0
/* E0EEE0 80240740 0C00A67F */  jal       rand_int
/* E0EEE4 80240744 A603008E */   sh       $v1, 0x8e($s0)
/* E0EEE8 80240748 C60C000C */  lwc1      $f12, 0xc($s0)
/* E0EEEC 8024074C 44820000 */  mtc1      $v0, $f0
/* E0EEF0 80240750 00000000 */  nop       
/* E0EEF4 80240754 46800020 */  cvt.s.w   $f0, $f0
/* E0EEF8 80240758 46006300 */  add.s     $f12, $f12, $f0
/* E0EEFC 8024075C 3C0142B4 */  lui       $at, 0x42b4
/* E0EF00 80240760 44810000 */  mtc1      $at, $f0
/* E0EF04 80240764 0C00A6C9 */  jal       clamp_angle
/* E0EF08 80240768 46006301 */   sub.s    $f12, $f12, $f0
/* E0EF0C 8024076C E600000C */  swc1      $f0, 0xc($s0)
/* E0EF10 80240770 8E4200CC */  lw        $v0, 0xcc($s2)
/* E0EF14 80240774 8C420000 */  lw        $v0, ($v0)
/* E0EF18 80240778 AE020028 */  sw        $v0, 0x28($s0)
/* E0EF1C 8024077C 24020003 */  addiu     $v0, $zero, 3
/* E0EF20 80240780 AE620070 */  sw        $v0, 0x70($s3)
/* E0EF24 80240784 8FBF0020 */  lw        $ra, 0x20($sp)
/* E0EF28 80240788 8FB3001C */  lw        $s3, 0x1c($sp)
/* E0EF2C 8024078C 8FB20018 */  lw        $s2, 0x18($sp)
/* E0EF30 80240790 8FB10014 */  lw        $s1, 0x14($sp)
/* E0EF34 80240794 8FB00010 */  lw        $s0, 0x10($sp)
/* E0EF38 80240798 03E00008 */  jr        $ra
/* E0EF3C 8024079C 27BD0028 */   addiu    $sp, $sp, 0x28
