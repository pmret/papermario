.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_DB7C98
/* DB7C98 80240388 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DB7C9C 8024038C AFB20018 */  sw        $s2, 0x18($sp)
/* DB7CA0 80240390 0080902D */  daddu     $s2, $a0, $zero
/* DB7CA4 80240394 AFBF0028 */  sw        $ra, 0x28($sp)
/* DB7CA8 80240398 AFB50024 */  sw        $s5, 0x24($sp)
/* DB7CAC 8024039C AFB40020 */  sw        $s4, 0x20($sp)
/* DB7CB0 802403A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* DB7CB4 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* DB7CB8 802403A8 AFB00010 */  sw        $s0, 0x10($sp)
/* DB7CBC 802403AC F7B80040 */  sdc1      $f24, 0x40($sp)
/* DB7CC0 802403B0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DB7CC4 802403B4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* DB7CC8 802403B8 8E50000C */  lw        $s0, 0xc($s2)
/* DB7CCC 802403BC 8E140000 */  lw        $s4, ($s0)
/* DB7CD0 802403C0 26100004 */  addiu     $s0, $s0, 4
/* DB7CD4 802403C4 0C0B1EAF */  jal       get_variable
/* DB7CD8 802403C8 0280282D */   daddu    $a1, $s4, $zero
/* DB7CDC 802403CC 0040982D */  daddu     $s3, $v0, $zero
/* DB7CE0 802403D0 8E150000 */  lw        $s5, ($s0)
/* DB7CE4 802403D4 26100004 */  addiu     $s0, $s0, 4
/* DB7CE8 802403D8 8E050000 */  lw        $a1, ($s0)
/* DB7CEC 802403DC 26100004 */  addiu     $s0, $s0, 4
/* DB7CF0 802403E0 0C0B210B */  jal       get_float_variable
/* DB7CF4 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* DB7CF8 802403E8 8E050000 */  lw        $a1, ($s0)
/* DB7CFC 802403EC 26100004 */  addiu     $s0, $s0, 4
/* DB7D00 802403F0 0240202D */  daddu     $a0, $s2, $zero
/* DB7D04 802403F4 0C0B210B */  jal       get_float_variable
/* DB7D08 802403F8 46000606 */   mov.s    $f24, $f0
/* DB7D0C 802403FC 8E050000 */  lw        $a1, ($s0)
/* DB7D10 80240400 26100004 */  addiu     $s0, $s0, 4
/* DB7D14 80240404 0240202D */  daddu     $a0, $s2, $zero
/* DB7D18 80240408 0C0B1EAF */  jal       get_variable
/* DB7D1C 8024040C 46000506 */   mov.s    $f20, $f0
/* DB7D20 80240410 8E050000 */  lw        $a1, ($s0)
/* DB7D24 80240414 26100004 */  addiu     $s0, $s0, 4
/* DB7D28 80240418 0240202D */  daddu     $a0, $s2, $zero
/* DB7D2C 8024041C 0C0B1EAF */  jal       get_variable
/* DB7D30 80240420 0040882D */   daddu    $s1, $v0, $zero
/* DB7D34 80240424 0240202D */  daddu     $a0, $s2, $zero
/* DB7D38 80240428 8E050000 */  lw        $a1, ($s0)
/* DB7D3C 8024042C 0C0B210B */  jal       get_float_variable
/* DB7D40 80240430 0040802D */   daddu    $s0, $v0, $zero
/* DB7D44 80240434 3C014334 */  lui       $at, 0x4334
/* DB7D48 80240438 44811000 */  mtc1      $at, $f2
/* DB7D4C 8024043C 3C014049 */  lui       $at, 0x4049
/* DB7D50 80240440 34210FD8 */  ori       $at, $at, 0xfd8
/* DB7D54 80240444 44812000 */  mtc1      $at, $f4
/* DB7D58 80240448 46020003 */  div.s     $f0, $f0, $f2
/* DB7D5C 8024044C 46040582 */  mul.s     $f22, $f0, $f4
/* DB7D60 80240450 00000000 */  nop       
/* DB7D64 80240454 4618A501 */  sub.s     $f20, $f20, $f24
/* DB7D68 80240458 3C013F00 */  lui       $at, 0x3f00
/* DB7D6C 8024045C 44810000 */  mtc1      $at, $f0
/* DB7D70 80240460 00000000 */  nop       
/* DB7D74 80240464 4600A502 */  mul.s     $f20, $f20, $f0
/* DB7D78 80240468 00000000 */  nop       
/* DB7D7C 8024046C 12000007 */  beqz      $s0, .L8024048C
/* DB7D80 80240470 0233102A */   slt      $v0, $s1, $s3
/* DB7D84 80240474 10400005 */  beqz      $v0, .L8024048C
/* DB7D88 80240478 0240202D */   daddu    $a0, $s2, $zero
/* DB7D8C 8024047C 0220982D */  daddu     $s3, $s1, $zero
/* DB7D90 80240480 0280282D */  daddu     $a1, $s4, $zero
/* DB7D94 80240484 0C0B2026 */  jal       set_variable
/* DB7D98 80240488 0220302D */   daddu    $a2, $s1, $zero
.L8024048C:
/* DB7D9C 8024048C 3C014049 */  lui       $at, 0x4049
/* DB7DA0 80240490 34210FD8 */  ori       $at, $at, 0xfd8
/* DB7DA4 80240494 44810000 */  mtc1      $at, $f0
/* DB7DA8 80240498 44936000 */  mtc1      $s3, $f12
/* DB7DAC 8024049C 00000000 */  nop       
/* DB7DB0 802404A0 46806320 */  cvt.s.w   $f12, $f12
/* DB7DB4 802404A4 46006302 */  mul.s     $f12, $f12, $f0
/* DB7DB8 802404A8 00000000 */  nop       
/* DB7DBC 802404AC 44910000 */  mtc1      $s1, $f0
/* DB7DC0 802404B0 00000000 */  nop       
/* DB7DC4 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* DB7DC8 802404B8 46006303 */  div.s     $f12, $f12, $f0
/* DB7DCC 802404BC 0C00A874 */  jal       cos_rad
/* DB7DD0 802404C0 46166300 */   add.s    $f12, $f12, $f22
/* DB7DD4 802404C4 4600A002 */  mul.s     $f0, $f20, $f0
/* DB7DD8 802404C8 00000000 */  nop       
/* DB7DDC 802404CC 4614C080 */  add.s     $f2, $f24, $f20
/* DB7DE0 802404D0 46001081 */  sub.s     $f2, $f2, $f0
/* DB7DE4 802404D4 0240202D */  daddu     $a0, $s2, $zero
/* DB7DE8 802404D8 44061000 */  mfc1      $a2, $f2
/* DB7DEC 802404DC 0C0B2190 */  jal       set_float_variable
/* DB7DF0 802404E0 02A0282D */   daddu    $a1, $s5, $zero
/* DB7DF4 802404E4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DB7DF8 802404E8 8FB50024 */  lw        $s5, 0x24($sp)
/* DB7DFC 802404EC 8FB40020 */  lw        $s4, 0x20($sp)
/* DB7E00 802404F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DB7E04 802404F4 8FB20018 */  lw        $s2, 0x18($sp)
/* DB7E08 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DB7E0C 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7E10 80240500 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DB7E14 80240504 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DB7E18 80240508 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DB7E1C 8024050C 24020002 */  addiu     $v0, $zero, 2
/* DB7E20 80240510 03E00008 */  jr        $ra
/* DB7E24 80240514 27BD0048 */   addiu    $sp, $sp, 0x48
