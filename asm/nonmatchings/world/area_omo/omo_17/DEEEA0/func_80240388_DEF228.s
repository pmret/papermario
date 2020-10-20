.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240388_DEF228
/* DEF228 80240388 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DEF22C 8024038C AFB20018 */  sw        $s2, 0x18($sp)
/* DEF230 80240390 0080902D */  daddu     $s2, $a0, $zero
/* DEF234 80240394 AFBF0028 */  sw        $ra, 0x28($sp)
/* DEF238 80240398 AFB50024 */  sw        $s5, 0x24($sp)
/* DEF23C 8024039C AFB40020 */  sw        $s4, 0x20($sp)
/* DEF240 802403A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* DEF244 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF248 802403A8 AFB00010 */  sw        $s0, 0x10($sp)
/* DEF24C 802403AC F7B80040 */  sdc1      $f24, 0x40($sp)
/* DEF250 802403B0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* DEF254 802403B4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* DEF258 802403B8 8E50000C */  lw        $s0, 0xc($s2)
/* DEF25C 802403BC 8E140000 */  lw        $s4, ($s0)
/* DEF260 802403C0 26100004 */  addiu     $s0, $s0, 4
/* DEF264 802403C4 0C0B1EAF */  jal       get_variable
/* DEF268 802403C8 0280282D */   daddu    $a1, $s4, $zero
/* DEF26C 802403CC 0040982D */  daddu     $s3, $v0, $zero
/* DEF270 802403D0 8E150000 */  lw        $s5, ($s0)
/* DEF274 802403D4 26100004 */  addiu     $s0, $s0, 4
/* DEF278 802403D8 8E050000 */  lw        $a1, ($s0)
/* DEF27C 802403DC 26100004 */  addiu     $s0, $s0, 4
/* DEF280 802403E0 0C0B210B */  jal       get_float_variable
/* DEF284 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* DEF288 802403E8 8E050000 */  lw        $a1, ($s0)
/* DEF28C 802403EC 26100004 */  addiu     $s0, $s0, 4
/* DEF290 802403F0 0240202D */  daddu     $a0, $s2, $zero
/* DEF294 802403F4 0C0B210B */  jal       get_float_variable
/* DEF298 802403F8 46000606 */   mov.s    $f24, $f0
/* DEF29C 802403FC 8E050000 */  lw        $a1, ($s0)
/* DEF2A0 80240400 26100004 */  addiu     $s0, $s0, 4
/* DEF2A4 80240404 0240202D */  daddu     $a0, $s2, $zero
/* DEF2A8 80240408 0C0B1EAF */  jal       get_variable
/* DEF2AC 8024040C 46000506 */   mov.s    $f20, $f0
/* DEF2B0 80240410 8E050000 */  lw        $a1, ($s0)
/* DEF2B4 80240414 26100004 */  addiu     $s0, $s0, 4
/* DEF2B8 80240418 0240202D */  daddu     $a0, $s2, $zero
/* DEF2BC 8024041C 0C0B1EAF */  jal       get_variable
/* DEF2C0 80240420 0040882D */   daddu    $s1, $v0, $zero
/* DEF2C4 80240424 0240202D */  daddu     $a0, $s2, $zero
/* DEF2C8 80240428 8E050000 */  lw        $a1, ($s0)
/* DEF2CC 8024042C 0C0B210B */  jal       get_float_variable
/* DEF2D0 80240430 0040802D */   daddu    $s0, $v0, $zero
/* DEF2D4 80240434 3C014334 */  lui       $at, 0x4334
/* DEF2D8 80240438 44811000 */  mtc1      $at, $f2
/* DEF2DC 8024043C 3C014049 */  lui       $at, 0x4049
/* DEF2E0 80240440 34210FD8 */  ori       $at, $at, 0xfd8
/* DEF2E4 80240444 44812000 */  mtc1      $at, $f4
/* DEF2E8 80240448 46020003 */  div.s     $f0, $f0, $f2
/* DEF2EC 8024044C 46040582 */  mul.s     $f22, $f0, $f4
/* DEF2F0 80240450 00000000 */  nop       
/* DEF2F4 80240454 4618A501 */  sub.s     $f20, $f20, $f24
/* DEF2F8 80240458 3C013F00 */  lui       $at, 0x3f00
/* DEF2FC 8024045C 44810000 */  mtc1      $at, $f0
/* DEF300 80240460 00000000 */  nop       
/* DEF304 80240464 4600A502 */  mul.s     $f20, $f20, $f0
/* DEF308 80240468 00000000 */  nop       
/* DEF30C 8024046C 12000007 */  beqz      $s0, .L8024048C
/* DEF310 80240470 0233102A */   slt      $v0, $s1, $s3
/* DEF314 80240474 10400005 */  beqz      $v0, .L8024048C
/* DEF318 80240478 0240202D */   daddu    $a0, $s2, $zero
/* DEF31C 8024047C 0220982D */  daddu     $s3, $s1, $zero
/* DEF320 80240480 0280282D */  daddu     $a1, $s4, $zero
/* DEF324 80240484 0C0B2026 */  jal       set_variable
/* DEF328 80240488 0220302D */   daddu    $a2, $s1, $zero
.L8024048C:
/* DEF32C 8024048C 3C014049 */  lui       $at, 0x4049
/* DEF330 80240490 34210FD8 */  ori       $at, $at, 0xfd8
/* DEF334 80240494 44810000 */  mtc1      $at, $f0
/* DEF338 80240498 44936000 */  mtc1      $s3, $f12
/* DEF33C 8024049C 00000000 */  nop       
/* DEF340 802404A0 46806320 */  cvt.s.w   $f12, $f12
/* DEF344 802404A4 46006302 */  mul.s     $f12, $f12, $f0
/* DEF348 802404A8 00000000 */  nop       
/* DEF34C 802404AC 44910000 */  mtc1      $s1, $f0
/* DEF350 802404B0 00000000 */  nop       
/* DEF354 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* DEF358 802404B8 46006303 */  div.s     $f12, $f12, $f0
/* DEF35C 802404BC 0C00A874 */  jal       cos_rad
/* DEF360 802404C0 46166300 */   add.s    $f12, $f12, $f22
/* DEF364 802404C4 4600A002 */  mul.s     $f0, $f20, $f0
/* DEF368 802404C8 00000000 */  nop       
/* DEF36C 802404CC 4614C080 */  add.s     $f2, $f24, $f20
/* DEF370 802404D0 46001081 */  sub.s     $f2, $f2, $f0
/* DEF374 802404D4 0240202D */  daddu     $a0, $s2, $zero
/* DEF378 802404D8 44061000 */  mfc1      $a2, $f2
/* DEF37C 802404DC 0C0B2190 */  jal       set_float_variable
/* DEF380 802404E0 02A0282D */   daddu    $a1, $s5, $zero
/* DEF384 802404E4 8FBF0028 */  lw        $ra, 0x28($sp)
/* DEF388 802404E8 8FB50024 */  lw        $s5, 0x24($sp)
/* DEF38C 802404EC 8FB40020 */  lw        $s4, 0x20($sp)
/* DEF390 802404F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* DEF394 802404F4 8FB20018 */  lw        $s2, 0x18($sp)
/* DEF398 802404F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF39C 802404FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF3A0 80240500 D7B80040 */  ldc1      $f24, 0x40($sp)
/* DEF3A4 80240504 D7B60038 */  ldc1      $f22, 0x38($sp)
/* DEF3A8 80240508 D7B40030 */  ldc1      $f20, 0x30($sp)
/* DEF3AC 8024050C 24020002 */  addiu     $v0, $zero, 2
/* DEF3B0 80240510 03E00008 */  jr        $ra
/* DEF3B4 80240514 27BD0048 */   addiu    $sp, $sp, 0x48
