.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219AF0_5B2FA0
/* 5B2FA0 80219AF0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5B2FA4 80219AF4 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B2FA8 80219AF8 0080902D */  daddu     $s2, $a0, $zero
/* 5B2FAC 80219AFC AFBF0028 */  sw        $ra, 0x28($sp)
/* 5B2FB0 80219B00 AFB50024 */  sw        $s5, 0x24($sp)
/* 5B2FB4 80219B04 AFB40020 */  sw        $s4, 0x20($sp)
/* 5B2FB8 80219B08 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B2FBC 80219B0C AFB10014 */  sw        $s1, 0x14($sp)
/* 5B2FC0 80219B10 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B2FC4 80219B14 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5B2FC8 80219B18 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5B2FCC 80219B1C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5B2FD0 80219B20 8E50000C */  lw        $s0, 0xc($s2)
/* 5B2FD4 80219B24 8E140000 */  lw        $s4, ($s0)
/* 5B2FD8 80219B28 26100004 */  addiu     $s0, $s0, 4
/* 5B2FDC 80219B2C 0C0B1EAF */  jal       get_variable
/* 5B2FE0 80219B30 0280282D */   daddu    $a1, $s4, $zero
/* 5B2FE4 80219B34 0040982D */  daddu     $s3, $v0, $zero
/* 5B2FE8 80219B38 8E150000 */  lw        $s5, ($s0)
/* 5B2FEC 80219B3C 26100004 */  addiu     $s0, $s0, 4
/* 5B2FF0 80219B40 8E050000 */  lw        $a1, ($s0)
/* 5B2FF4 80219B44 26100004 */  addiu     $s0, $s0, 4
/* 5B2FF8 80219B48 0C0B210B */  jal       get_float_variable
/* 5B2FFC 80219B4C 0240202D */   daddu    $a0, $s2, $zero
/* 5B3000 80219B50 8E050000 */  lw        $a1, ($s0)
/* 5B3004 80219B54 26100004 */  addiu     $s0, $s0, 4
/* 5B3008 80219B58 0240202D */  daddu     $a0, $s2, $zero
/* 5B300C 80219B5C 0C0B210B */  jal       get_float_variable
/* 5B3010 80219B60 46000606 */   mov.s    $f24, $f0
/* 5B3014 80219B64 8E050000 */  lw        $a1, ($s0)
/* 5B3018 80219B68 26100004 */  addiu     $s0, $s0, 4
/* 5B301C 80219B6C 0240202D */  daddu     $a0, $s2, $zero
/* 5B3020 80219B70 0C0B1EAF */  jal       get_variable
/* 5B3024 80219B74 46000506 */   mov.s    $f20, $f0
/* 5B3028 80219B78 8E050000 */  lw        $a1, ($s0)
/* 5B302C 80219B7C 26100004 */  addiu     $s0, $s0, 4
/* 5B3030 80219B80 0240202D */  daddu     $a0, $s2, $zero
/* 5B3034 80219B84 0C0B1EAF */  jal       get_variable
/* 5B3038 80219B88 0040882D */   daddu    $s1, $v0, $zero
/* 5B303C 80219B8C 0240202D */  daddu     $a0, $s2, $zero
/* 5B3040 80219B90 8E050000 */  lw        $a1, ($s0)
/* 5B3044 80219B94 0C0B210B */  jal       get_float_variable
/* 5B3048 80219B98 0040802D */   daddu    $s0, $v0, $zero
/* 5B304C 80219B9C 3C014334 */  lui       $at, 0x4334
/* 5B3050 80219BA0 44811000 */  mtc1      $at, $f2
/* 5B3054 80219BA4 3C014049 */  lui       $at, 0x4049
/* 5B3058 80219BA8 34210FD8 */  ori       $at, $at, 0xfd8
/* 5B305C 80219BAC 44812000 */  mtc1      $at, $f4
/* 5B3060 80219BB0 46020003 */  div.s     $f0, $f0, $f2
/* 5B3064 80219BB4 46040582 */  mul.s     $f22, $f0, $f4
/* 5B3068 80219BB8 00000000 */  nop       
/* 5B306C 80219BBC 4618A501 */  sub.s     $f20, $f20, $f24
/* 5B3070 80219BC0 3C013F00 */  lui       $at, 0x3f00
/* 5B3074 80219BC4 44810000 */  mtc1      $at, $f0
/* 5B3078 80219BC8 00000000 */  nop       
/* 5B307C 80219BCC 4600A502 */  mul.s     $f20, $f20, $f0
/* 5B3080 80219BD0 00000000 */  nop       
/* 5B3084 80219BD4 12000007 */  beqz      $s0, .L80219BF4
/* 5B3088 80219BD8 0233102A */   slt      $v0, $s1, $s3
/* 5B308C 80219BDC 10400005 */  beqz      $v0, .L80219BF4
/* 5B3090 80219BE0 0240202D */   daddu    $a0, $s2, $zero
/* 5B3094 80219BE4 0220982D */  daddu     $s3, $s1, $zero
/* 5B3098 80219BE8 0280282D */  daddu     $a1, $s4, $zero
/* 5B309C 80219BEC 0C0B2026 */  jal       set_variable
/* 5B30A0 80219BF0 0220302D */   daddu    $a2, $s1, $zero
.L80219BF4:
/* 5B30A4 80219BF4 3C014049 */  lui       $at, 0x4049
/* 5B30A8 80219BF8 34210FD8 */  ori       $at, $at, 0xfd8
/* 5B30AC 80219BFC 44810000 */  mtc1      $at, $f0
/* 5B30B0 80219C00 44936000 */  mtc1      $s3, $f12
/* 5B30B4 80219C04 00000000 */  nop       
/* 5B30B8 80219C08 46806320 */  cvt.s.w   $f12, $f12
/* 5B30BC 80219C0C 46006302 */  mul.s     $f12, $f12, $f0
/* 5B30C0 80219C10 00000000 */  nop       
/* 5B30C4 80219C14 44910000 */  mtc1      $s1, $f0
/* 5B30C8 80219C18 00000000 */  nop       
/* 5B30CC 80219C1C 46800020 */  cvt.s.w   $f0, $f0
/* 5B30D0 80219C20 46006303 */  div.s     $f12, $f12, $f0
/* 5B30D4 80219C24 0C00A874 */  jal       cos_rad
/* 5B30D8 80219C28 46166300 */   add.s    $f12, $f12, $f22
/* 5B30DC 80219C2C 4600A002 */  mul.s     $f0, $f20, $f0
/* 5B30E0 80219C30 00000000 */  nop       
/* 5B30E4 80219C34 4614C080 */  add.s     $f2, $f24, $f20
/* 5B30E8 80219C38 46001081 */  sub.s     $f2, $f2, $f0
/* 5B30EC 80219C3C 0240202D */  daddu     $a0, $s2, $zero
/* 5B30F0 80219C40 44061000 */  mfc1      $a2, $f2
/* 5B30F4 80219C44 0C0B2190 */  jal       set_float_variable
/* 5B30F8 80219C48 02A0282D */   daddu    $a1, $s5, $zero
/* 5B30FC 80219C4C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B3100 80219C50 8FB50024 */  lw        $s5, 0x24($sp)
/* 5B3104 80219C54 8FB40020 */  lw        $s4, 0x20($sp)
/* 5B3108 80219C58 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B310C 80219C5C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B3110 80219C60 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B3114 80219C64 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B3118 80219C68 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5B311C 80219C6C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5B3120 80219C70 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5B3124 80219C74 24020002 */  addiu     $v0, $zero, 2
/* 5B3128 80219C78 03E00008 */  jr        $ra
/* 5B312C 80219C7C 27BD0048 */   addiu    $sp, $sp, 0x48
