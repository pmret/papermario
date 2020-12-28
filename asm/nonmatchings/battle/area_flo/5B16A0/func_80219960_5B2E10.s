.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219960_5B2E10
/* 5B2E10 80219960 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5B2E14 80219964 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B2E18 80219968 0080902D */  daddu     $s2, $a0, $zero
/* 5B2E1C 8021996C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B2E20 80219970 AFB50024 */  sw        $s5, 0x24($sp)
/* 5B2E24 80219974 AFB40020 */  sw        $s4, 0x20($sp)
/* 5B2E28 80219978 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B2E2C 8021997C AFB10014 */  sw        $s1, 0x14($sp)
/* 5B2E30 80219980 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B2E34 80219984 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B2E38 80219988 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B2E3C 8021998C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B2E40 80219990 8E50000C */  lw        $s0, 0xc($s2)
/* 5B2E44 80219994 8E140000 */  lw        $s4, ($s0)
/* 5B2E48 80219998 26100004 */  addiu     $s0, $s0, 4
/* 5B2E4C 8021999C 0C0B1EAF */  jal       get_variable
/* 5B2E50 802199A0 0280282D */   daddu    $a1, $s4, $zero
/* 5B2E54 802199A4 0040982D */  daddu     $s3, $v0, $zero
/* 5B2E58 802199A8 8E150000 */  lw        $s5, ($s0)
/* 5B2E5C 802199AC 26100004 */  addiu     $s0, $s0, 4
/* 5B2E60 802199B0 8E050000 */  lw        $a1, ($s0)
/* 5B2E64 802199B4 26100004 */  addiu     $s0, $s0, 4
/* 5B2E68 802199B8 0C0B210B */  jal       get_float_variable
/* 5B2E6C 802199BC 0240202D */   daddu    $a0, $s2, $zero
/* 5B2E70 802199C0 8E050000 */  lw        $a1, ($s0)
/* 5B2E74 802199C4 26100004 */  addiu     $s0, $s0, 4
/* 5B2E78 802199C8 0240202D */  daddu     $a0, $s2, $zero
/* 5B2E7C 802199CC 0C0B210B */  jal       get_float_variable
/* 5B2E80 802199D0 46000606 */   mov.s    $f24, $f0
/* 5B2E84 802199D4 8E050000 */  lw        $a1, ($s0)
/* 5B2E88 802199D8 26100004 */  addiu     $s0, $s0, 4
/* 5B2E8C 802199DC 0240202D */  daddu     $a0, $s2, $zero
/* 5B2E90 802199E0 0C0B1EAF */  jal       get_variable
/* 5B2E94 802199E4 46000506 */   mov.s    $f20, $f0
/* 5B2E98 802199E8 8E050000 */  lw        $a1, ($s0)
/* 5B2E9C 802199EC 26100004 */  addiu     $s0, $s0, 4
/* 5B2EA0 802199F0 0240202D */  daddu     $a0, $s2, $zero
/* 5B2EA4 802199F4 0C0B1EAF */  jal       get_variable
/* 5B2EA8 802199F8 0040882D */   daddu    $s1, $v0, $zero
/* 5B2EAC 802199FC 0240202D */  daddu     $a0, $s2, $zero
/* 5B2EB0 80219A00 8E050000 */  lw        $a1, ($s0)
/* 5B2EB4 80219A04 0C0B210B */  jal       get_float_variable
/* 5B2EB8 80219A08 0040802D */   daddu    $s0, $v0, $zero
/* 5B2EBC 80219A0C 3C014334 */  lui       $at, 0x4334
/* 5B2EC0 80219A10 44811000 */  mtc1      $at, $f2
/* 5B2EC4 80219A14 3C014049 */  lui       $at, 0x4049
/* 5B2EC8 80219A18 34210FD8 */  ori       $at, $at, 0xfd8
/* 5B2ECC 80219A1C 44812000 */  mtc1      $at, $f4
/* 5B2ED0 80219A20 46020003 */  div.s     $f0, $f0, $f2
/* 5B2ED4 80219A24 46040582 */  mul.s     $f22, $f0, $f4
/* 5B2ED8 80219A28 00000000 */  nop       
/* 5B2EDC 80219A2C 4618A501 */  sub.s     $f20, $f20, $f24
/* 5B2EE0 80219A30 3C013F00 */  lui       $at, 0x3f00
/* 5B2EE4 80219A34 44810000 */  mtc1      $at, $f0
/* 5B2EE8 80219A38 00000000 */  nop       
/* 5B2EEC 80219A3C 4600A502 */  mul.s     $f20, $f20, $f0
/* 5B2EF0 80219A40 00000000 */  nop       
/* 5B2EF4 80219A44 12000007 */  beqz      $s0, .L80219A64
/* 5B2EF8 80219A48 0233102A */   slt      $v0, $s1, $s3
/* 5B2EFC 80219A4C 10400005 */  beqz      $v0, .L80219A64
/* 5B2F00 80219A50 0240202D */   daddu    $a0, $s2, $zero
/* 5B2F04 80219A54 0220982D */  daddu     $s3, $s1, $zero
/* 5B2F08 80219A58 0280282D */  daddu     $a1, $s4, $zero
/* 5B2F0C 80219A5C 0C0B2026 */  jal       set_variable
/* 5B2F10 80219A60 0220302D */   daddu    $a2, $s1, $zero
.L80219A64:
/* 5B2F14 80219A64 3C014049 */  lui       $at, 0x4049
/* 5B2F18 80219A68 34210FD8 */  ori       $at, $at, 0xfd8
/* 5B2F1C 80219A6C 44810000 */  mtc1      $at, $f0
/* 5B2F20 80219A70 44936000 */  mtc1      $s3, $f12
/* 5B2F24 80219A74 00000000 */  nop       
/* 5B2F28 80219A78 46806320 */  cvt.s.w   $f12, $f12
/* 5B2F2C 80219A7C 46006302 */  mul.s     $f12, $f12, $f0
/* 5B2F30 80219A80 00000000 */  nop       
/* 5B2F34 80219A84 44910000 */  mtc1      $s1, $f0
/* 5B2F38 80219A88 00000000 */  nop       
/* 5B2F3C 80219A8C 46800020 */  cvt.s.w   $f0, $f0
/* 5B2F40 80219A90 46006303 */  div.s     $f12, $f12, $f0
/* 5B2F44 80219A94 0C00A874 */  jal       cos_rad
/* 5B2F48 80219A98 46166300 */   add.s    $f12, $f12, $f22
/* 5B2F4C 80219A9C 4600A002 */  mul.s     $f0, $f20, $f0
/* 5B2F50 80219AA0 00000000 */  nop       
/* 5B2F54 80219AA4 4614C080 */  add.s     $f2, $f24, $f20
/* 5B2F58 80219AA8 46001081 */  sub.s     $f2, $f2, $f0
/* 5B2F5C 80219AAC 0240202D */  daddu     $a0, $s2, $zero
/* 5B2F60 80219AB0 44061000 */  mfc1      $a2, $f2
/* 5B2F64 80219AB4 0C0B2190 */  jal       set_float_variable
/* 5B2F68 80219AB8 02A0282D */   daddu    $a1, $s5, $zero
/* 5B2F6C 80219ABC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2F70 80219AC0 8FB50024 */  lw        $s5, 0x24($sp)
/* 5B2F74 80219AC4 8FB40020 */  lw        $s4, 0x20($sp)
/* 5B2F78 80219AC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B2F7C 80219ACC 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B2F80 80219AD0 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B2F84 80219AD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B2F88 80219AD8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B2F8C 80219ADC D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B2F90 80219AE0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B2F94 80219AE4 24020002 */  addiu     $v0, $zero, 2
/* 5B2F98 80219AE8 03E00008 */  jr        $ra
/* 5B2F9C 80219AEC 27BD0048 */   addiu    $sp, $sp, 0x48
