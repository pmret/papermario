.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sin_cos_deg
/* 5634 8002A234 3C014336 */  lui       $at, 0x4336
/* 5638 8002A238 34210B61 */  ori       $at, $at, 0xb61
/* 563C 8002A23C 44810000 */  mtc1      $at, $f0
/* 5640 8002A240 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5644 8002A244 AFB10014 */  sw        $s1, 0x14($sp)
/* 5648 8002A248 00A0882D */  daddu     $s1, $a1, $zero
/* 564C 8002A24C AFB20018 */  sw        $s2, 0x18($sp)
/* 5650 8002A250 46006302 */  mul.s     $f12, $f12, $f0
/* 5654 8002A254 00000000 */  nop
/* 5658 8002A258 AFBF001C */  sw        $ra, 0x1c($sp)
/* 565C 8002A25C AFB00010 */  sw        $s0, 0x10($sp)
/* 5660 8002A260 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 5664 8002A264 0C00A80D */  jal       _wrap_trig_lookup_value
/* 5668 8002A268 00C0902D */   daddu    $s2, $a2, $zero
/* 566C 8002A26C 3050FFFF */  andi      $s0, $v0, 0xffff
/* 5670 8002A270 0C01917C */  jal       sins
/* 5674 8002A274 0200202D */   daddu    $a0, $s0, $zero
/* 5678 8002A278 00021400 */  sll       $v0, $v0, 0x10
/* 567C 8002A27C 00021403 */  sra       $v0, $v0, 0x10
/* 5680 8002A280 3C018009 */  lui       $at, %hi(D_80097D78)
/* 5684 8002A284 D4347D78 */  ldc1      $f20, %lo(D_80097D78)($at)
/* 5688 8002A288 44820000 */  mtc1      $v0, $f0
/* 568C 8002A28C 00000000 */  nop
/* 5690 8002A290 46800021 */  cvt.d.w   $f0, $f0
/* 5694 8002A294 46340002 */  mul.d     $f0, $f0, $f20
/* 5698 8002A298 00000000 */  nop
/* 569C 8002A29C 0200202D */  daddu     $a0, $s0, $zero
/* 56A0 8002A2A0 46200020 */  cvt.s.d   $f0, $f0
/* 56A4 8002A2A4 0C0187C0 */  jal       coss
/* 56A8 8002A2A8 E6200000 */   swc1     $f0, ($s1)
/* 56AC 8002A2AC 00021400 */  sll       $v0, $v0, 0x10
/* 56B0 8002A2B0 00021403 */  sra       $v0, $v0, 0x10
/* 56B4 8002A2B4 44820000 */  mtc1      $v0, $f0
/* 56B8 8002A2B8 00000000 */  nop
/* 56BC 8002A2BC 46800021 */  cvt.d.w   $f0, $f0
/* 56C0 8002A2C0 46340002 */  mul.d     $f0, $f0, $f20
/* 56C4 8002A2C4 00000000 */  nop
/* 56C8 8002A2C8 46200020 */  cvt.s.d   $f0, $f0
/* 56CC 8002A2CC E6400000 */  swc1      $f0, ($s2)
/* 56D0 8002A2D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 56D4 8002A2D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 56D8 8002A2D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 56DC 8002A2DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 56E0 8002A2E0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 56E4 8002A2E4 03E00008 */  jr        $ra
/* 56E8 8002A2E8 27BD0028 */   addiu    $sp, $sp, 0x28
