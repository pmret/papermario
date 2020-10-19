.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_DC4758
/* DC4758 80240388 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DC475C 8024038C AFB20018 */  sw        $s2, 0x18($sp)
/* DC4760 80240390 0080902D */  daddu     $s2, $a0, $zero
/* DC4764 80240394 AFBF0028 */  sw        $ra, 0x28($sp)
/* DC4768 80240398 AFB50024 */  sw        $s5, 0x24($sp)
/* DC476C 8024039C AFB40020 */  sw        $s4, 0x20($sp)
/* DC4770 802403A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* DC4774 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* DC4778 802403A8 AFB00010 */  sw        $s0, 0x10($sp)
/* DC477C 802403AC F7B80040 */  sdc1      $f24, 0x40($sp)
/* DC4780 802403B0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DC4784 802403B4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* DC4788 802403B8 8E50000C */  lw        $s0, 0xc($s2)
/* DC478C 802403BC 8E140000 */  lw        $s4, ($s0)
/* DC4790 802403C0 26100004 */  addiu     $s0, $s0, 4
/* DC4794 802403C4 0C0B1EAF */  jal       get_variable
/* DC4798 802403C8 0280282D */   daddu    $a1, $s4, $zero
/* DC479C 802403CC 0040982D */  daddu     $s3, $v0, $zero
/* DC47A0 802403D0 8E150000 */  lw        $s5, ($s0)
/* DC47A4 802403D4 26100004 */  addiu     $s0, $s0, 4
/* DC47A8 802403D8 8E050000 */  lw        $a1, ($s0)
/* DC47AC 802403DC 26100004 */  addiu     $s0, $s0, 4
/* DC47B0 802403E0 0C0B210B */  jal       get_float_variable
/* DC47B4 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* DC47B8 802403E8 8E050000 */  lw        $a1, ($s0)
/* DC47BC 802403EC 26100004 */  addiu     $s0, $s0, 4
/* DC47C0 802403F0 0240202D */  daddu     $a0, $s2, $zero
/* DC47C4 802403F4 0C0B210B */  jal       get_float_variable
/* DC47C8 802403F8 46000606 */   mov.s    $f24, $f0
/* DC47CC 802403FC 8E050000 */  lw        $a1, ($s0)
/* DC47D0 80240400 26100004 */  addiu     $s0, $s0, 4
/* DC47D4 80240404 0240202D */  daddu     $a0, $s2, $zero
/* DC47D8 80240408 0C0B1EAF */  jal       get_variable
/* DC47DC 8024040C 46000506 */   mov.s    $f20, $f0
/* DC47E0 80240410 8E050000 */  lw        $a1, ($s0)
/* DC47E4 80240414 26100004 */  addiu     $s0, $s0, 4
/* DC47E8 80240418 0240202D */  daddu     $a0, $s2, $zero
/* DC47EC 8024041C 0C0B1EAF */  jal       get_variable
/* DC47F0 80240420 0040882D */   daddu    $s1, $v0, $zero
/* DC47F4 80240424 0240202D */  daddu     $a0, $s2, $zero
/* DC47F8 80240428 8E050000 */  lw        $a1, ($s0)
/* DC47FC 8024042C 0C0B210B */  jal       get_float_variable
/* DC4800 80240430 0040802D */   daddu    $s0, $v0, $zero
/* DC4804 80240434 3C014334 */  lui       $at, 0x4334
/* DC4808 80240438 44811000 */  mtc1      $at, $f2
/* DC480C 8024043C 3C014049 */  lui       $at, 0x4049
/* DC4810 80240440 34210FD8 */  ori       $at, $at, 0xfd8
/* DC4814 80240444 44812000 */  mtc1      $at, $f4
/* DC4818 80240448 46020003 */  div.s     $f0, $f0, $f2
/* DC481C 8024044C 46040582 */  mul.s     $f22, $f0, $f4
/* DC4820 80240450 00000000 */  nop       
/* DC4824 80240454 4618A501 */  sub.s     $f20, $f20, $f24
/* DC4828 80240458 3C013F00 */  lui       $at, 0x3f00
/* DC482C 8024045C 44810000 */  mtc1      $at, $f0
/* DC4830 80240460 00000000 */  nop       
/* DC4834 80240464 4600A502 */  mul.s     $f20, $f20, $f0
/* DC4838 80240468 00000000 */  nop       
/* DC483C 8024046C 12000007 */  beqz      $s0, .L8024048C
/* DC4840 80240470 0233102A */   slt      $v0, $s1, $s3
/* DC4844 80240474 10400005 */  beqz      $v0, .L8024048C
/* DC4848 80240478 0240202D */   daddu    $a0, $s2, $zero
/* DC484C 8024047C 0220982D */  daddu     $s3, $s1, $zero
/* DC4850 80240480 0280282D */  daddu     $a1, $s4, $zero
/* DC4854 80240484 0C0B2026 */  jal       set_variable
/* DC4858 80240488 0220302D */   daddu    $a2, $s1, $zero
.L8024048C:
/* DC485C 8024048C 3C014049 */  lui       $at, 0x4049
/* DC4860 80240490 34210FD8 */  ori       $at, $at, 0xfd8
/* DC4864 80240494 44810000 */  mtc1      $at, $f0
/* DC4868 80240498 44936000 */  mtc1      $s3, $f12
/* DC486C 8024049C 00000000 */  nop       
/* DC4870 802404A0 46806320 */  cvt.s.w   $f12, $f12
/* DC4874 802404A4 46006302 */  mul.s     $f12, $f12, $f0
/* DC4878 802404A8 00000000 */  nop       
/* DC487C 802404AC 44910000 */  mtc1      $s1, $f0
/* DC4880 802404B0 00000000 */  nop       
/* DC4884 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* DC4888 802404B8 46006303 */  div.s     $f12, $f12, $f0
/* DC488C 802404BC 0C00A874 */  jal       cos_rad
/* DC4890 802404C0 46166300 */   add.s    $f12, $f12, $f22
/* DC4894 802404C4 4600A002 */  mul.s     $f0, $f20, $f0
/* DC4898 802404C8 00000000 */  nop       
/* DC489C 802404CC 4614C080 */  add.s     $f2, $f24, $f20
/* DC48A0 802404D0 46001081 */  sub.s     $f2, $f2, $f0
/* DC48A4 802404D4 0240202D */  daddu     $a0, $s2, $zero
/* DC48A8 802404D8 44061000 */  mfc1      $a2, $f2
/* DC48AC 802404DC 0C0B2190 */  jal       set_float_variable
/* DC48B0 802404E0 02A0282D */   daddu    $a1, $s5, $zero
/* DC48B4 802404E4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DC48B8 802404E8 8FB50024 */  lw        $s5, 0x24($sp)
/* DC48BC 802404EC 8FB40020 */  lw        $s4, 0x20($sp)
/* DC48C0 802404F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DC48C4 802404F4 8FB20018 */  lw        $s2, 0x18($sp)
/* DC48C8 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DC48CC 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DC48D0 80240500 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DC48D4 80240504 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DC48D8 80240508 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DC48DC 8024050C 24020002 */  addiu     $v0, $zero, 2
/* DC48E0 80240510 03E00008 */  jr        $ra
/* DC48E4 80240514 27BD0048 */   addiu    $sp, $sp, 0x48
