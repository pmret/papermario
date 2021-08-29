.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243948_855AB8
/* 855AB8 80243948 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 855ABC 8024394C AFB20018 */  sw        $s2, 0x18($sp)
/* 855AC0 80243950 0080902D */  daddu     $s2, $a0, $zero
/* 855AC4 80243954 AFBF0028 */  sw        $ra, 0x28($sp)
/* 855AC8 80243958 AFB50024 */  sw        $s5, 0x24($sp)
/* 855ACC 8024395C AFB40020 */  sw        $s4, 0x20($sp)
/* 855AD0 80243960 AFB3001C */  sw        $s3, 0x1c($sp)
/* 855AD4 80243964 AFB10014 */  sw        $s1, 0x14($sp)
/* 855AD8 80243968 AFB00010 */  sw        $s0, 0x10($sp)
/* 855ADC 8024396C F7B80040 */  sdc1      $f24, 0x40($sp)
/* 855AE0 80243970 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 855AE4 80243974 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 855AE8 80243978 8E50000C */  lw        $s0, 0xc($s2)
/* 855AEC 8024397C 8E140000 */  lw        $s4, ($s0)
/* 855AF0 80243980 26100004 */  addiu     $s0, $s0, 4
/* 855AF4 80243984 0C0B1EAF */  jal       get_variable
/* 855AF8 80243988 0280282D */   daddu    $a1, $s4, $zero
/* 855AFC 8024398C 0040982D */  daddu     $s3, $v0, $zero
/* 855B00 80243990 8E150000 */  lw        $s5, ($s0)
/* 855B04 80243994 26100004 */  addiu     $s0, $s0, 4
/* 855B08 80243998 8E050000 */  lw        $a1, ($s0)
/* 855B0C 8024399C 26100004 */  addiu     $s0, $s0, 4
/* 855B10 802439A0 0C0B210B */  jal       evt_get_float_variable
/* 855B14 802439A4 0240202D */   daddu    $a0, $s2, $zero
/* 855B18 802439A8 8E050000 */  lw        $a1, ($s0)
/* 855B1C 802439AC 26100004 */  addiu     $s0, $s0, 4
/* 855B20 802439B0 0240202D */  daddu     $a0, $s2, $zero
/* 855B24 802439B4 0C0B210B */  jal       evt_get_float_variable
/* 855B28 802439B8 46000606 */   mov.s    $f24, $f0
/* 855B2C 802439BC 8E050000 */  lw        $a1, ($s0)
/* 855B30 802439C0 26100004 */  addiu     $s0, $s0, 4
/* 855B34 802439C4 0240202D */  daddu     $a0, $s2, $zero
/* 855B38 802439C8 0C0B1EAF */  jal       get_variable
/* 855B3C 802439CC 46000506 */   mov.s    $f20, $f0
/* 855B40 802439D0 8E050000 */  lw        $a1, ($s0)
/* 855B44 802439D4 26100004 */  addiu     $s0, $s0, 4
/* 855B48 802439D8 0240202D */  daddu     $a0, $s2, $zero
/* 855B4C 802439DC 0C0B1EAF */  jal       get_variable
/* 855B50 802439E0 0040882D */   daddu    $s1, $v0, $zero
/* 855B54 802439E4 0240202D */  daddu     $a0, $s2, $zero
/* 855B58 802439E8 8E050000 */  lw        $a1, ($s0)
/* 855B5C 802439EC 0C0B210B */  jal       evt_get_float_variable
/* 855B60 802439F0 0040802D */   daddu    $s0, $v0, $zero
/* 855B64 802439F4 4618A501 */  sub.s     $f20, $f20, $f24
/* 855B68 802439F8 3C013F00 */  lui       $at, 0x3f00
/* 855B6C 802439FC 44811000 */  mtc1      $at, $f2
/* 855B70 80243A00 00000000 */  nop
/* 855B74 80243A04 4602A502 */  mul.s     $f20, $f20, $f2
/* 855B78 80243A08 00000000 */  nop
/* 855B7C 80243A0C 12000008 */  beqz      $s0, .L80243A30
/* 855B80 80243A10 46000586 */   mov.s    $f22, $f0
/* 855B84 80243A14 0233102A */  slt       $v0, $s1, $s3
/* 855B88 80243A18 10400005 */  beqz      $v0, .L80243A30
/* 855B8C 80243A1C 0240202D */   daddu    $a0, $s2, $zero
/* 855B90 80243A20 0220982D */  daddu     $s3, $s1, $zero
/* 855B94 80243A24 0280282D */  daddu     $a1, $s4, $zero
/* 855B98 80243A28 0C0B2026 */  jal       evt_set_variable
/* 855B9C 80243A2C 0220302D */   daddu    $a2, $s1, $zero
.L80243A30:
/* 855BA0 80243A30 3C014334 */  lui       $at, 0x4334
/* 855BA4 80243A34 44810000 */  mtc1      $at, $f0
/* 855BA8 80243A38 44936000 */  mtc1      $s3, $f12
/* 855BAC 80243A3C 00000000 */  nop
/* 855BB0 80243A40 46806320 */  cvt.s.w   $f12, $f12
/* 855BB4 80243A44 46006302 */  mul.s     $f12, $f12, $f0
/* 855BB8 80243A48 00000000 */  nop
/* 855BBC 80243A4C 44910000 */  mtc1      $s1, $f0
/* 855BC0 80243A50 00000000 */  nop
/* 855BC4 80243A54 46800020 */  cvt.s.w   $f0, $f0
/* 855BC8 80243A58 46006303 */  div.s     $f12, $f12, $f0
/* 855BCC 80243A5C 0C00A8D4 */  jal       cos_deg
/* 855BD0 80243A60 46166300 */   add.s    $f12, $f12, $f22
/* 855BD4 80243A64 4600A002 */  mul.s     $f0, $f20, $f0
/* 855BD8 80243A68 00000000 */  nop
/* 855BDC 80243A6C 4614C080 */  add.s     $f2, $f24, $f20
/* 855BE0 80243A70 46001081 */  sub.s     $f2, $f2, $f0
/* 855BE4 80243A74 0240202D */  daddu     $a0, $s2, $zero
/* 855BE8 80243A78 44061000 */  mfc1      $a2, $f2
/* 855BEC 80243A7C 0C0B2190 */  jal       evt_set_float_variable
/* 855BF0 80243A80 02A0282D */   daddu    $a1, $s5, $zero
/* 855BF4 80243A84 8FBF0028 */  lw        $ra, 0x28($sp)
/* 855BF8 80243A88 8FB50024 */  lw        $s5, 0x24($sp)
/* 855BFC 80243A8C 8FB40020 */  lw        $s4, 0x20($sp)
/* 855C00 80243A90 8FB3001C */  lw        $s3, 0x1c($sp)
/* 855C04 80243A94 8FB20018 */  lw        $s2, 0x18($sp)
/* 855C08 80243A98 8FB10014 */  lw        $s1, 0x14($sp)
/* 855C0C 80243A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 855C10 80243AA0 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 855C14 80243AA4 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 855C18 80243AA8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 855C1C 80243AAC 24020002 */  addiu     $v0, $zero, 2
/* 855C20 80243AB0 03E00008 */  jr        $ra
/* 855C24 80243AB4 27BD0048 */   addiu    $sp, $sp, 0x48
