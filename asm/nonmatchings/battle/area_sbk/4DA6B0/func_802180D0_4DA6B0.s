.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180D0_4DA6B0
/* 4DA6B0 802180D0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 4DA6B4 802180D4 AFB10054 */  sw        $s1, 0x54($sp)
/* 4DA6B8 802180D8 0080882D */  daddu     $s1, $a0, $zero
/* 4DA6BC 802180DC AFBF0060 */  sw        $ra, 0x60($sp)
/* 4DA6C0 802180E0 AFB3005C */  sw        $s3, 0x5c($sp)
/* 4DA6C4 802180E4 AFB20058 */  sw        $s2, 0x58($sp)
/* 4DA6C8 802180E8 AFB00050 */  sw        $s0, 0x50($sp)
/* 4DA6CC 802180EC F7BA0080 */  sdc1      $f26, 0x80($sp)
/* 4DA6D0 802180F0 F7B80078 */  sdc1      $f24, 0x78($sp)
/* 4DA6D4 802180F4 F7B60070 */  sdc1      $f22, 0x70($sp)
/* 4DA6D8 802180F8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* 4DA6DC 802180FC 8E30000C */  lw        $s0, 0xc($s1)
/* 4DA6E0 80218100 8E050000 */  lw        $a1, ($s0)
/* 4DA6E4 80218104 0C0B1EAF */  jal       get_variable
/* 4DA6E8 80218108 26100004 */   addiu    $s0, $s0, 4
/* 4DA6EC 8021810C 4482A000 */  mtc1      $v0, $f20
/* 4DA6F0 80218110 00000000 */  nop
/* 4DA6F4 80218114 4680A521 */  cvt.d.w   $f20, $f20
/* 4DA6F8 80218118 3C014024 */  lui       $at, 0x4024
/* 4DA6FC 8021811C 44810800 */  mtc1      $at, $f1
/* 4DA700 80218120 44800000 */  mtc1      $zero, $f0
/* 4DA704 80218124 8E120000 */  lw        $s2, ($s0)
/* 4DA708 80218128 26100004 */  addiu     $s0, $s0, 4
/* 4DA70C 8021812C 4620A503 */  div.d     $f20, $f20, $f0
/* 4DA710 80218130 3C0140C9 */  lui       $at, 0x40c9
/* 4DA714 80218134 34210FD0 */  ori       $at, $at, 0xfd0
/* 4DA718 80218138 44810000 */  mtc1      $at, $f0
/* 4DA71C 8021813C 4620A520 */  cvt.s.d   $f20, $f20
/* 4DA720 80218140 4600A502 */  mul.s     $f20, $f20, $f0
/* 4DA724 80218144 00000000 */  nop
/* 4DA728 80218148 8E130000 */  lw        $s3, ($s0)
/* 4DA72C 8021814C 8E100004 */  lw        $s0, 4($s0)
/* 4DA730 80218150 3C0143B4 */  lui       $at, 0x43b4
/* 4DA734 80218154 44810000 */  mtc1      $at, $f0
/* 4DA738 80218158 3C014316 */  lui       $at, 0x4316
/* 4DA73C 8021815C 4481C000 */  mtc1      $at, $f24
/* 4DA740 80218160 4600A503 */  div.s     $f20, $f20, $f0
/* 4DA744 80218164 0C00A85B */  jal       sin_rad
/* 4DA748 80218168 4600A306 */   mov.s    $f12, $f20
/* 4DA74C 8021816C 46180582 */  mul.s     $f22, $f0, $f24
/* 4DA750 80218170 00000000 */  nop
/* 4DA754 80218174 4480D000 */  mtc1      $zero, $f26
/* 4DA758 80218178 00000000 */  nop
/* 4DA75C 8021817C 461AB580 */  add.s     $f22, $f22, $f26
/* 4DA760 80218180 0C00A874 */  jal       cos_rad
/* 4DA764 80218184 4600A306 */   mov.s    $f12, $f20
/* 4DA768 80218188 46180502 */  mul.s     $f20, $f0, $f24
/* 4DA76C 8021818C 00000000 */  nop
/* 4DA770 80218190 3C01C37C */  lui       $at, 0xc37c
/* 4DA774 80218194 4481C000 */  mtc1      $at, $f24
/* 4DA778 80218198 C62000B8 */  lwc1      $f0, 0xb8($s1)
/* 4DA77C 8021819C 46800020 */  cvt.s.w   $f0, $f0
/* 4DA780 802181A0 4600C601 */  sub.s     $f24, $f24, $f0
/* 4DA784 802181A4 C62000B0 */  lwc1      $f0, 0xb0($s1)
/* 4DA788 802181A8 46800020 */  cvt.s.w   $f0, $f0
/* 4DA78C 802181AC 4600B581 */  sub.s     $f22, $f22, $f0
/* 4DA790 802181B0 0220202D */  daddu     $a0, $s1, $zero
/* 4DA794 802181B4 0240282D */  daddu     $a1, $s2, $zero
/* 4DA798 802181B8 461AA500 */  add.s     $f20, $f20, $f26
/* 4DA79C 802181BC C62000B4 */  lwc1      $f0, 0xb4($s1)
/* 4DA7A0 802181C0 46800020 */  cvt.s.w   $f0, $f0
/* 4DA7A4 802181C4 4406B000 */  mfc1      $a2, $f22
/* 4DA7A8 802181C8 0C0B2190 */  jal       set_float_variable
/* 4DA7AC 802181CC 4600A501 */   sub.s    $f20, $f20, $f0
/* 4DA7B0 802181D0 0220202D */  daddu     $a0, $s1, $zero
/* 4DA7B4 802181D4 4406A000 */  mfc1      $a2, $f20
/* 4DA7B8 802181D8 0C0B2190 */  jal       set_float_variable
/* 4DA7BC 802181DC 0260282D */   daddu    $a1, $s3, $zero
/* 4DA7C0 802181E0 0220202D */  daddu     $a0, $s1, $zero
/* 4DA7C4 802181E4 4406C000 */  mfc1      $a2, $f24
/* 4DA7C8 802181E8 0C0B2190 */  jal       set_float_variable
/* 4DA7CC 802181EC 0200282D */   daddu    $a1, $s0, $zero
/* 4DA7D0 802181F0 8FBF0060 */  lw        $ra, 0x60($sp)
/* 4DA7D4 802181F4 8FB3005C */  lw        $s3, 0x5c($sp)
/* 4DA7D8 802181F8 8FB20058 */  lw        $s2, 0x58($sp)
/* 4DA7DC 802181FC 8FB10054 */  lw        $s1, 0x54($sp)
/* 4DA7E0 80218200 8FB00050 */  lw        $s0, 0x50($sp)
/* 4DA7E4 80218204 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* 4DA7E8 80218208 D7B80078 */  ldc1      $f24, 0x78($sp)
/* 4DA7EC 8021820C D7B60070 */  ldc1      $f22, 0x70($sp)
/* 4DA7F0 80218210 D7B40068 */  ldc1      $f20, 0x68($sp)
/* 4DA7F4 80218214 24020002 */  addiu     $v0, $zero, 2
/* 4DA7F8 80218218 03E00008 */  jr        $ra
/* 4DA7FC 8021821C 27BD0088 */   addiu    $sp, $sp, 0x88
