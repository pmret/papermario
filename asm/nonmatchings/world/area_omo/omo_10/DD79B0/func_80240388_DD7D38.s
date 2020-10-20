.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_DD7D38
/* DD7D38 80240388 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DD7D3C 8024038C AFB20018 */  sw        $s2, 0x18($sp)
/* DD7D40 80240390 0080902D */  daddu     $s2, $a0, $zero
/* DD7D44 80240394 AFBF0028 */  sw        $ra, 0x28($sp)
/* DD7D48 80240398 AFB50024 */  sw        $s5, 0x24($sp)
/* DD7D4C 8024039C AFB40020 */  sw        $s4, 0x20($sp)
/* DD7D50 802403A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* DD7D54 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* DD7D58 802403A8 AFB00010 */  sw        $s0, 0x10($sp)
/* DD7D5C 802403AC F7B80040 */  sdc1      $f24, 0x40($sp)
/* DD7D60 802403B0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DD7D64 802403B4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* DD7D68 802403B8 8E50000C */  lw        $s0, 0xc($s2)
/* DD7D6C 802403BC 8E140000 */  lw        $s4, ($s0)
/* DD7D70 802403C0 26100004 */  addiu     $s0, $s0, 4
/* DD7D74 802403C4 0C0B1EAF */  jal       get_variable
/* DD7D78 802403C8 0280282D */   daddu    $a1, $s4, $zero
/* DD7D7C 802403CC 0040982D */  daddu     $s3, $v0, $zero
/* DD7D80 802403D0 8E150000 */  lw        $s5, ($s0)
/* DD7D84 802403D4 26100004 */  addiu     $s0, $s0, 4
/* DD7D88 802403D8 8E050000 */  lw        $a1, ($s0)
/* DD7D8C 802403DC 26100004 */  addiu     $s0, $s0, 4
/* DD7D90 802403E0 0C0B210B */  jal       get_float_variable
/* DD7D94 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* DD7D98 802403E8 8E050000 */  lw        $a1, ($s0)
/* DD7D9C 802403EC 26100004 */  addiu     $s0, $s0, 4
/* DD7DA0 802403F0 0240202D */  daddu     $a0, $s2, $zero
/* DD7DA4 802403F4 0C0B210B */  jal       get_float_variable
/* DD7DA8 802403F8 46000606 */   mov.s    $f24, $f0
/* DD7DAC 802403FC 8E050000 */  lw        $a1, ($s0)
/* DD7DB0 80240400 26100004 */  addiu     $s0, $s0, 4
/* DD7DB4 80240404 0240202D */  daddu     $a0, $s2, $zero
/* DD7DB8 80240408 0C0B1EAF */  jal       get_variable
/* DD7DBC 8024040C 46000506 */   mov.s    $f20, $f0
/* DD7DC0 80240410 8E050000 */  lw        $a1, ($s0)
/* DD7DC4 80240414 26100004 */  addiu     $s0, $s0, 4
/* DD7DC8 80240418 0240202D */  daddu     $a0, $s2, $zero
/* DD7DCC 8024041C 0C0B1EAF */  jal       get_variable
/* DD7DD0 80240420 0040882D */   daddu    $s1, $v0, $zero
/* DD7DD4 80240424 0240202D */  daddu     $a0, $s2, $zero
/* DD7DD8 80240428 8E050000 */  lw        $a1, ($s0)
/* DD7DDC 8024042C 0C0B210B */  jal       get_float_variable
/* DD7DE0 80240430 0040802D */   daddu    $s0, $v0, $zero
/* DD7DE4 80240434 3C014334 */  lui       $at, 0x4334
/* DD7DE8 80240438 44811000 */  mtc1      $at, $f2
/* DD7DEC 8024043C 3C014049 */  lui       $at, 0x4049
/* DD7DF0 80240440 34210FD8 */  ori       $at, $at, 0xfd8
/* DD7DF4 80240444 44812000 */  mtc1      $at, $f4
/* DD7DF8 80240448 46020003 */  div.s     $f0, $f0, $f2
/* DD7DFC 8024044C 46040582 */  mul.s     $f22, $f0, $f4
/* DD7E00 80240450 00000000 */  nop       
/* DD7E04 80240454 4618A501 */  sub.s     $f20, $f20, $f24
/* DD7E08 80240458 3C013F00 */  lui       $at, 0x3f00
/* DD7E0C 8024045C 44810000 */  mtc1      $at, $f0
/* DD7E10 80240460 00000000 */  nop       
/* DD7E14 80240464 4600A502 */  mul.s     $f20, $f20, $f0
/* DD7E18 80240468 00000000 */  nop       
/* DD7E1C 8024046C 12000007 */  beqz      $s0, .L8024048C
/* DD7E20 80240470 0233102A */   slt      $v0, $s1, $s3
/* DD7E24 80240474 10400005 */  beqz      $v0, .L8024048C
/* DD7E28 80240478 0240202D */   daddu    $a0, $s2, $zero
/* DD7E2C 8024047C 0220982D */  daddu     $s3, $s1, $zero
/* DD7E30 80240480 0280282D */  daddu     $a1, $s4, $zero
/* DD7E34 80240484 0C0B2026 */  jal       set_variable
/* DD7E38 80240488 0220302D */   daddu    $a2, $s1, $zero
.L8024048C:
/* DD7E3C 8024048C 3C014049 */  lui       $at, 0x4049
/* DD7E40 80240490 34210FD8 */  ori       $at, $at, 0xfd8
/* DD7E44 80240494 44810000 */  mtc1      $at, $f0
/* DD7E48 80240498 44936000 */  mtc1      $s3, $f12
/* DD7E4C 8024049C 00000000 */  nop       
/* DD7E50 802404A0 46806320 */  cvt.s.w   $f12, $f12
/* DD7E54 802404A4 46006302 */  mul.s     $f12, $f12, $f0
/* DD7E58 802404A8 00000000 */  nop       
/* DD7E5C 802404AC 44910000 */  mtc1      $s1, $f0
/* DD7E60 802404B0 00000000 */  nop       
/* DD7E64 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* DD7E68 802404B8 46006303 */  div.s     $f12, $f12, $f0
/* DD7E6C 802404BC 0C00A874 */  jal       cos_rad
/* DD7E70 802404C0 46166300 */   add.s    $f12, $f12, $f22
/* DD7E74 802404C4 4600A002 */  mul.s     $f0, $f20, $f0
/* DD7E78 802404C8 00000000 */  nop       
/* DD7E7C 802404CC 4614C080 */  add.s     $f2, $f24, $f20
/* DD7E80 802404D0 46001081 */  sub.s     $f2, $f2, $f0
/* DD7E84 802404D4 0240202D */  daddu     $a0, $s2, $zero
/* DD7E88 802404D8 44061000 */  mfc1      $a2, $f2
/* DD7E8C 802404DC 0C0B2190 */  jal       set_float_variable
/* DD7E90 802404E0 02A0282D */   daddu    $a1, $s5, $zero
/* DD7E94 802404E4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DD7E98 802404E8 8FB50024 */  lw        $s5, 0x24($sp)
/* DD7E9C 802404EC 8FB40020 */  lw        $s4, 0x20($sp)
/* DD7EA0 802404F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DD7EA4 802404F4 8FB20018 */  lw        $s2, 0x18($sp)
/* DD7EA8 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DD7EAC 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DD7EB0 80240500 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DD7EB4 80240504 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DD7EB8 80240508 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DD7EBC 8024050C 24020002 */  addiu     $v0, $zero, 2
/* DD7EC0 80240510 03E00008 */  jr        $ra
/* DD7EC4 80240514 27BD0048 */   addiu    $sp, $sp, 0x48
