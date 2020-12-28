.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802194A0_5CFB30
/* 5CFB30 802194A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5CFB34 802194A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CFB38 802194A8 0080902D */  daddu     $s2, $a0, $zero
/* 5CFB3C 802194AC AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CFB40 802194B0 AFB50024 */  sw        $s5, 0x24($sp)
/* 5CFB44 802194B4 AFB40020 */  sw        $s4, 0x20($sp)
/* 5CFB48 802194B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5CFB4C 802194BC AFB10014 */  sw        $s1, 0x14($sp)
/* 5CFB50 802194C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CFB54 802194C4 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CFB58 802194C8 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CFB5C 802194CC F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CFB60 802194D0 8E50000C */  lw        $s0, 0xc($s2)
/* 5CFB64 802194D4 8E140000 */  lw        $s4, ($s0)
/* 5CFB68 802194D8 26100004 */  addiu     $s0, $s0, 4
/* 5CFB6C 802194DC 0C0B1EAF */  jal       get_variable
/* 5CFB70 802194E0 0280282D */   daddu    $a1, $s4, $zero
/* 5CFB74 802194E4 0040982D */  daddu     $s3, $v0, $zero
/* 5CFB78 802194E8 8E150000 */  lw        $s5, ($s0)
/* 5CFB7C 802194EC 26100004 */  addiu     $s0, $s0, 4
/* 5CFB80 802194F0 8E050000 */  lw        $a1, ($s0)
/* 5CFB84 802194F4 26100004 */  addiu     $s0, $s0, 4
/* 5CFB88 802194F8 0C0B210B */  jal       get_float_variable
/* 5CFB8C 802194FC 0240202D */   daddu    $a0, $s2, $zero
/* 5CFB90 80219500 8E050000 */  lw        $a1, ($s0)
/* 5CFB94 80219504 26100004 */  addiu     $s0, $s0, 4
/* 5CFB98 80219508 0240202D */  daddu     $a0, $s2, $zero
/* 5CFB9C 8021950C 0C0B210B */  jal       get_float_variable
/* 5CFBA0 80219510 46000606 */   mov.s    $f24, $f0
/* 5CFBA4 80219514 8E050000 */  lw        $a1, ($s0)
/* 5CFBA8 80219518 26100004 */  addiu     $s0, $s0, 4
/* 5CFBAC 8021951C 0240202D */  daddu     $a0, $s2, $zero
/* 5CFBB0 80219520 0C0B1EAF */  jal       get_variable
/* 5CFBB4 80219524 46000506 */   mov.s    $f20, $f0
/* 5CFBB8 80219528 8E050000 */  lw        $a1, ($s0)
/* 5CFBBC 8021952C 26100004 */  addiu     $s0, $s0, 4
/* 5CFBC0 80219530 0240202D */  daddu     $a0, $s2, $zero
/* 5CFBC4 80219534 0C0B1EAF */  jal       get_variable
/* 5CFBC8 80219538 0040882D */   daddu    $s1, $v0, $zero
/* 5CFBCC 8021953C 0240202D */  daddu     $a0, $s2, $zero
/* 5CFBD0 80219540 8E050000 */  lw        $a1, ($s0)
/* 5CFBD4 80219544 0C0B210B */  jal       get_float_variable
/* 5CFBD8 80219548 0040802D */   daddu    $s0, $v0, $zero
/* 5CFBDC 8021954C 3C014334 */  lui       $at, 0x4334
/* 5CFBE0 80219550 44811000 */  mtc1      $at, $f2
/* 5CFBE4 80219554 3C014049 */  lui       $at, 0x4049
/* 5CFBE8 80219558 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CFBEC 8021955C 44812000 */  mtc1      $at, $f4
/* 5CFBF0 80219560 46020003 */  div.s     $f0, $f0, $f2
/* 5CFBF4 80219564 46040582 */  mul.s     $f22, $f0, $f4
/* 5CFBF8 80219568 00000000 */  nop       
/* 5CFBFC 8021956C 4618A501 */  sub.s     $f20, $f20, $f24
/* 5CFC00 80219570 3C013F00 */  lui       $at, 0x3f00
/* 5CFC04 80219574 44810000 */  mtc1      $at, $f0
/* 5CFC08 80219578 00000000 */  nop       
/* 5CFC0C 8021957C 4600A502 */  mul.s     $f20, $f20, $f0
/* 5CFC10 80219580 00000000 */  nop       
/* 5CFC14 80219584 12000007 */  beqz      $s0, .L802195A4
/* 5CFC18 80219588 0233102A */   slt      $v0, $s1, $s3
/* 5CFC1C 8021958C 10400005 */  beqz      $v0, .L802195A4
/* 5CFC20 80219590 0240202D */   daddu    $a0, $s2, $zero
/* 5CFC24 80219594 0220982D */  daddu     $s3, $s1, $zero
/* 5CFC28 80219598 0280282D */  daddu     $a1, $s4, $zero
/* 5CFC2C 8021959C 0C0B2026 */  jal       set_variable
/* 5CFC30 802195A0 0220302D */   daddu    $a2, $s1, $zero
.L802195A4:
/* 5CFC34 802195A4 3C014049 */  lui       $at, 0x4049
/* 5CFC38 802195A8 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CFC3C 802195AC 44810000 */  mtc1      $at, $f0
/* 5CFC40 802195B0 44936000 */  mtc1      $s3, $f12
/* 5CFC44 802195B4 00000000 */  nop       
/* 5CFC48 802195B8 46806320 */  cvt.s.w   $f12, $f12
/* 5CFC4C 802195BC 46006302 */  mul.s     $f12, $f12, $f0
/* 5CFC50 802195C0 00000000 */  nop       
/* 5CFC54 802195C4 44910000 */  mtc1      $s1, $f0
/* 5CFC58 802195C8 00000000 */  nop       
/* 5CFC5C 802195CC 46800020 */  cvt.s.w   $f0, $f0
/* 5CFC60 802195D0 46006303 */  div.s     $f12, $f12, $f0
/* 5CFC64 802195D4 0C00A874 */  jal       cos_rad
/* 5CFC68 802195D8 46166300 */   add.s    $f12, $f12, $f22
/* 5CFC6C 802195DC 4600A002 */  mul.s     $f0, $f20, $f0
/* 5CFC70 802195E0 00000000 */  nop       
/* 5CFC74 802195E4 4614C080 */  add.s     $f2, $f24, $f20
/* 5CFC78 802195E8 46001081 */  sub.s     $f2, $f2, $f0
/* 5CFC7C 802195EC 0240202D */  daddu     $a0, $s2, $zero
/* 5CFC80 802195F0 44061000 */  mfc1      $a2, $f2
/* 5CFC84 802195F4 0C0B2190 */  jal       set_float_variable
/* 5CFC88 802195F8 02A0282D */   daddu    $a1, $s5, $zero
/* 5CFC8C 802195FC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CFC90 80219600 8FB50024 */  lw        $s5, 0x24($sp)
/* 5CFC94 80219604 8FB40020 */  lw        $s4, 0x20($sp)
/* 5CFC98 80219608 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5CFC9C 8021960C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CFCA0 80219610 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CFCA4 80219614 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CFCA8 80219618 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CFCAC 8021961C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CFCB0 80219620 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CFCB4 80219624 24020002 */  addiu     $v0, $zero, 2
/* 5CFCB8 80219628 03E00008 */  jr        $ra
/* 5CFCBC 8021962C 27BD0048 */   addiu    $sp, $sp, 0x48
