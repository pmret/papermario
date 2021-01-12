.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_EF7E14
/* EF7E14 80240394 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EF7E18 80240398 AFB20018 */  sw        $s2, 0x18($sp)
/* EF7E1C 8024039C 0080902D */  daddu     $s2, $a0, $zero
/* EF7E20 802403A0 AFBF0028 */  sw        $ra, 0x28($sp)
/* EF7E24 802403A4 AFB50024 */  sw        $s5, 0x24($sp)
/* EF7E28 802403A8 AFB40020 */  sw        $s4, 0x20($sp)
/* EF7E2C 802403AC AFB3001C */  sw        $s3, 0x1c($sp)
/* EF7E30 802403B0 AFB10014 */  sw        $s1, 0x14($sp)
/* EF7E34 802403B4 AFB00010 */  sw        $s0, 0x10($sp)
/* EF7E38 802403B8 F7B80040 */  sdc1      $f24, 0x40($sp)
/* EF7E3C 802403BC F7B60038 */  sdc1      $f22, 0x38($sp)
/* EF7E40 802403C0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* EF7E44 802403C4 8E50000C */  lw        $s0, 0xc($s2)
/* EF7E48 802403C8 8E140000 */  lw        $s4, ($s0)
/* EF7E4C 802403CC 26100004 */  addiu     $s0, $s0, 4
/* EF7E50 802403D0 0C0B53A3 */  jal       func_802D4E8C
/* EF7E54 802403D4 0280282D */   daddu    $a1, $s4, $zero
/* EF7E58 802403D8 0040982D */  daddu     $s3, $v0, $zero
/* EF7E5C 802403DC 8E150000 */  lw        $s5, ($s0)
/* EF7E60 802403E0 26100004 */  addiu     $s0, $s0, 4
/* EF7E64 802403E4 8E050000 */  lw        $a1, ($s0)
/* EF7E68 802403E8 26100004 */  addiu     $s0, $s0, 4
/* EF7E6C 802403EC 0C0B55FF */  jal       func_802D57FC
/* EF7E70 802403F0 0240202D */   daddu    $a0, $s2, $zero
/* EF7E74 802403F4 8E050000 */  lw        $a1, ($s0)
/* EF7E78 802403F8 26100004 */  addiu     $s0, $s0, 4
/* EF7E7C 802403FC 0240202D */  daddu     $a0, $s2, $zero
/* EF7E80 80240400 0C0B55FF */  jal       func_802D57FC
/* EF7E84 80240404 46000606 */   mov.s    $f24, $f0
/* EF7E88 80240408 8E050000 */  lw        $a1, ($s0)
/* EF7E8C 8024040C 26100004 */  addiu     $s0, $s0, 4
/* EF7E90 80240410 0240202D */  daddu     $a0, $s2, $zero
/* EF7E94 80240414 0C0B53A3 */  jal       func_802D4E8C
/* EF7E98 80240418 46000506 */   mov.s    $f20, $f0
/* EF7E9C 8024041C 8E050000 */  lw        $a1, ($s0)
/* EF7EA0 80240420 26100004 */  addiu     $s0, $s0, 4
/* EF7EA4 80240424 0240202D */  daddu     $a0, $s2, $zero
/* EF7EA8 80240428 0C0B53A3 */  jal       func_802D4E8C
/* EF7EAC 8024042C 0040882D */   daddu    $s1, $v0, $zero
/* EF7EB0 80240430 0240202D */  daddu     $a0, $s2, $zero
/* EF7EB4 80240434 8E050000 */  lw        $a1, ($s0)
/* EF7EB8 80240438 0C0B55FF */  jal       func_802D57FC
/* EF7EBC 8024043C 0040802D */   daddu    $s0, $v0, $zero
/* EF7EC0 80240440 3C014334 */  lui       $at, 0x4334
/* EF7EC4 80240444 44811000 */  mtc1      $at, $f2
/* EF7EC8 80240448 3C014049 */  lui       $at, 0x4049
/* EF7ECC 8024044C 34210FD8 */  ori       $at, $at, 0xfd8
/* EF7ED0 80240450 44812000 */  mtc1      $at, $f4
/* EF7ED4 80240454 46020003 */  div.s     $f0, $f0, $f2
/* EF7ED8 80240458 46040582 */  mul.s     $f22, $f0, $f4
/* EF7EDC 8024045C 00000000 */  nop
/* EF7EE0 80240460 4618A501 */  sub.s     $f20, $f20, $f24
/* EF7EE4 80240464 3C013F00 */  lui       $at, 0x3f00
/* EF7EE8 80240468 44810000 */  mtc1      $at, $f0
/* EF7EEC 8024046C 00000000 */  nop
/* EF7EF0 80240470 4600A502 */  mul.s     $f20, $f20, $f0
/* EF7EF4 80240474 00000000 */  nop
/* EF7EF8 80240478 12000007 */  beqz      $s0, .L80240498
/* EF7EFC 8024047C 0233102A */   slt      $v0, $s1, $s3
/* EF7F00 80240480 10400005 */  beqz      $v0, .L80240498
/* EF7F04 80240484 0240202D */   daddu    $a0, $s2, $zero
/* EF7F08 80240488 0220982D */  daddu     $s3, $s1, $zero
/* EF7F0C 8024048C 0280282D */  daddu     $a1, $s4, $zero
/* EF7F10 80240490 0C0B551A */  jal       func_802D5468
/* EF7F14 80240494 0220302D */   daddu    $a2, $s1, $zero
.L80240498:
/* EF7F18 80240498 3C014049 */  lui       $at, 0x4049
/* EF7F1C 8024049C 34210FD8 */  ori       $at, $at, 0xfd8
/* EF7F20 802404A0 44810000 */  mtc1      $at, $f0
/* EF7F24 802404A4 44936000 */  mtc1      $s3, $f12
/* EF7F28 802404A8 00000000 */  nop
/* EF7F2C 802404AC 46806320 */  cvt.s.w   $f12, $f12
/* EF7F30 802404B0 46006302 */  mul.s     $f12, $f12, $f0
/* EF7F34 802404B4 00000000 */  nop
/* EF7F38 802404B8 44910000 */  mtc1      $s1, $f0
/* EF7F3C 802404BC 00000000 */  nop
/* EF7F40 802404C0 46800020 */  cvt.s.w   $f0, $f0
/* EF7F44 802404C4 46006303 */  div.s     $f12, $f12, $f0
/* EF7F48 802404C8 0C00AD30 */  jal       func_8002B4C0
/* EF7F4C 802404CC 46166300 */   add.s    $f12, $f12, $f22
/* EF7F50 802404D0 4600A002 */  mul.s     $f0, $f20, $f0
/* EF7F54 802404D4 00000000 */  nop
/* EF7F58 802404D8 4614C080 */  add.s     $f2, $f24, $f20
/* EF7F5C 802404DC 46001081 */  sub.s     $f2, $f2, $f0
/* EF7F60 802404E0 0240202D */  daddu     $a0, $s2, $zero
/* EF7F64 802404E4 44061000 */  mfc1      $a2, $f2
/* EF7F68 802404E8 0C0B5684 */  jal       func_802D5A10
/* EF7F6C 802404EC 02A0282D */   daddu    $a1, $s5, $zero
/* EF7F70 802404F0 8FBF0028 */  lw        $ra, 0x28($sp)
/* EF7F74 802404F4 8FB50024 */  lw        $s5, 0x24($sp)
/* EF7F78 802404F8 8FB40020 */  lw        $s4, 0x20($sp)
/* EF7F7C 802404FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* EF7F80 80240500 8FB20018 */  lw        $s2, 0x18($sp)
/* EF7F84 80240504 8FB10014 */  lw        $s1, 0x14($sp)
/* EF7F88 80240508 8FB00010 */  lw        $s0, 0x10($sp)
/* EF7F8C 8024050C D7B80040 */  ldc1      $f24, 0x40($sp)
/* EF7F90 80240510 D7B60038 */  ldc1      $f22, 0x38($sp)
/* EF7F94 80240514 D7B40030 */  ldc1      $f20, 0x30($sp)
/* EF7F98 80240518 24020002 */  addiu     $v0, $zero, 2
/* EF7F9C 8024051C 03E00008 */  jr        $ra
/* EF7FA0 80240520 27BD0048 */   addiu    $sp, $sp, 0x48
/* EF7FA4 80240524 00000000 */  nop
/* EF7FA8 80240528 00000000 */  nop
/* EF7FAC 8024052C 00000000 */  nop
