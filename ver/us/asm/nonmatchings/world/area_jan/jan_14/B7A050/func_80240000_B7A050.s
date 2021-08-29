.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B7A050
/* B7A050 80240000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B7A054 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* B7A058 80240008 0080882D */  daddu     $s1, $a0, $zero
/* B7A05C 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* B7A060 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* B7A064 80240014 F7B80030 */  sdc1      $f24, 0x30($sp)
/* B7A068 80240018 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B7A06C 8024001C F7B40020 */  sdc1      $f20, 0x20($sp)
/* B7A070 80240020 8E30000C */  lw        $s0, 0xc($s1)
/* B7A074 80240024 8E050000 */  lw        $a1, ($s0)
/* B7A078 80240028 0C0B210B */  jal       evt_get_float_variable
/* B7A07C 8024002C 26100004 */   addiu    $s0, $s0, 4
/* B7A080 80240030 8E050000 */  lw        $a1, ($s0)
/* B7A084 80240034 26100004 */  addiu     $s0, $s0, 4
/* B7A088 80240038 0220202D */  daddu     $a0, $s1, $zero
/* B7A08C 8024003C 0C0B210B */  jal       evt_get_float_variable
/* B7A090 80240040 46000606 */   mov.s    $f24, $f0
/* B7A094 80240044 8E050000 */  lw        $a1, ($s0)
/* B7A098 80240048 26100004 */  addiu     $s0, $s0, 4
/* B7A09C 8024004C 3C014170 */  lui       $at, 0x4170
/* B7A0A0 80240050 44811000 */  mtc1      $at, $f2
/* B7A0A4 80240054 0220202D */  daddu     $a0, $s1, $zero
/* B7A0A8 80240058 0C0B210B */  jal       evt_get_float_variable
/* B7A0AC 8024005C 46020580 */   add.s    $f22, $f0, $f2
/* B7A0B0 80240060 0220202D */  daddu     $a0, $s1, $zero
/* B7A0B4 80240064 8E050000 */  lw        $a1, ($s0)
/* B7A0B8 80240068 0C0B210B */  jal       evt_get_float_variable
/* B7A0BC 8024006C 46000506 */   mov.s    $f20, $f0
/* B7A0C0 80240070 46000002 */  mul.s     $f0, $f0, $f0
/* B7A0C4 80240074 00000000 */  nop
/* B7A0C8 80240078 C6240084 */  lwc1      $f4, 0x84($s1)
/* B7A0CC 8024007C 46802120 */  cvt.s.w   $f4, $f4
/* B7A0D0 80240080 46182101 */  sub.s     $f4, $f4, $f24
/* B7A0D4 80240084 46042102 */  mul.s     $f4, $f4, $f4
/* B7A0D8 80240088 00000000 */  nop
/* B7A0DC 8024008C C622008C */  lwc1      $f2, 0x8c($s1)
/* B7A0E0 80240090 468010A0 */  cvt.s.w   $f2, $f2
/* B7A0E4 80240094 46141081 */  sub.s     $f2, $f2, $f20
/* B7A0E8 80240098 46021082 */  mul.s     $f2, $f2, $f2
/* B7A0EC 8024009C 00000000 */  nop
/* B7A0F0 802400A0 C6260088 */  lwc1      $f6, 0x88($s1)
/* B7A0F4 802400A4 468031A0 */  cvt.s.w   $f6, $f6
/* B7A0F8 802400A8 46163181 */  sub.s     $f6, $f6, $f22
/* B7A0FC 802400AC 46063182 */  mul.s     $f6, $f6, $f6
/* B7A100 802400B0 00000000 */  nop
/* B7A104 802400B4 46062100 */  add.s     $f4, $f4, $f6
/* B7A108 802400B8 46022100 */  add.s     $f4, $f4, $f2
/* B7A10C 802400BC 4600203C */  c.lt.s    $f4, $f0
/* B7A110 802400C0 00000000 */  nop
/* B7A114 802400C4 45010002 */  bc1t      .L802400D0
/* B7A118 802400C8 24020001 */   addiu    $v0, $zero, 1
/* B7A11C 802400CC 0000102D */  daddu     $v0, $zero, $zero
.L802400D0:
/* B7A120 802400D0 AE220084 */  sw        $v0, 0x84($s1)
/* B7A124 802400D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B7A128 802400D8 8FB10014 */  lw        $s1, 0x14($sp)
/* B7A12C 802400DC 8FB00010 */  lw        $s0, 0x10($sp)
/* B7A130 802400E0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* B7A134 802400E4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B7A138 802400E8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B7A13C 802400EC 24020002 */  addiu     $v0, $zero, 2
/* B7A140 802400F0 03E00008 */  jr        $ra
/* B7A144 802400F4 27BD0038 */   addiu    $sp, $sp, 0x38
