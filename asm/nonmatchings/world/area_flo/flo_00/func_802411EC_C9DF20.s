.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411EC_C9F10C
/* C9F10C 802411EC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C9F110 802411F0 AFB20018 */  sw        $s2, 0x18($sp)
/* C9F114 802411F4 0080902D */  daddu     $s2, $a0, $zero
/* C9F118 802411F8 AFBF0028 */  sw        $ra, 0x28($sp)
/* C9F11C 802411FC AFB50024 */  sw        $s5, 0x24($sp)
/* C9F120 80241200 AFB40020 */  sw        $s4, 0x20($sp)
/* C9F124 80241204 AFB3001C */  sw        $s3, 0x1c($sp)
/* C9F128 80241208 AFB10014 */  sw        $s1, 0x14($sp)
/* C9F12C 8024120C AFB00010 */  sw        $s0, 0x10($sp)
/* C9F130 80241210 F7B80040 */  sdc1      $f24, 0x40($sp)
/* C9F134 80241214 F7B60038 */  sdc1      $f22, 0x38($sp)
/* C9F138 80241218 F7B40030 */  sdc1      $f20, 0x30($sp)
/* C9F13C 8024121C 8E50000C */  lw        $s0, 0xc($s2)
/* C9F140 80241220 8E140000 */  lw        $s4, ($s0)
/* C9F144 80241224 26100004 */  addiu     $s0, $s0, 4
/* C9F148 80241228 0C0B1EAF */  jal       get_variable
/* C9F14C 8024122C 0280282D */   daddu    $a1, $s4, $zero
/* C9F150 80241230 0040982D */  daddu     $s3, $v0, $zero
/* C9F154 80241234 8E150000 */  lw        $s5, ($s0)
/* C9F158 80241238 26100004 */  addiu     $s0, $s0, 4
/* C9F15C 8024123C 8E050000 */  lw        $a1, ($s0)
/* C9F160 80241240 26100004 */  addiu     $s0, $s0, 4
/* C9F164 80241244 0C0B210B */  jal       get_float_variable
/* C9F168 80241248 0240202D */   daddu    $a0, $s2, $zero
/* C9F16C 8024124C 8E050000 */  lw        $a1, ($s0)
/* C9F170 80241250 26100004 */  addiu     $s0, $s0, 4
/* C9F174 80241254 0240202D */  daddu     $a0, $s2, $zero
/* C9F178 80241258 0C0B210B */  jal       get_float_variable
/* C9F17C 8024125C 46000606 */   mov.s    $f24, $f0
/* C9F180 80241260 8E050000 */  lw        $a1, ($s0)
/* C9F184 80241264 26100004 */  addiu     $s0, $s0, 4
/* C9F188 80241268 0240202D */  daddu     $a0, $s2, $zero
/* C9F18C 8024126C 0C0B1EAF */  jal       get_variable
/* C9F190 80241270 46000506 */   mov.s    $f20, $f0
/* C9F194 80241274 8E050000 */  lw        $a1, ($s0)
/* C9F198 80241278 26100004 */  addiu     $s0, $s0, 4
/* C9F19C 8024127C 0240202D */  daddu     $a0, $s2, $zero
/* C9F1A0 80241280 0C0B1EAF */  jal       get_variable
/* C9F1A4 80241284 0040882D */   daddu    $s1, $v0, $zero
/* C9F1A8 80241288 0240202D */  daddu     $a0, $s2, $zero
/* C9F1AC 8024128C 8E050000 */  lw        $a1, ($s0)
/* C9F1B0 80241290 0C0B210B */  jal       get_float_variable
/* C9F1B4 80241294 0040802D */   daddu    $s0, $v0, $zero
/* C9F1B8 80241298 3C014334 */  lui       $at, 0x4334
/* C9F1BC 8024129C 44811000 */  mtc1      $at, $f2
/* C9F1C0 802412A0 3C014049 */  lui       $at, 0x4049
/* C9F1C4 802412A4 34210FD8 */  ori       $at, $at, 0xfd8
/* C9F1C8 802412A8 44812000 */  mtc1      $at, $f4
/* C9F1CC 802412AC 46020003 */  div.s     $f0, $f0, $f2
/* C9F1D0 802412B0 46040582 */  mul.s     $f22, $f0, $f4
/* C9F1D4 802412B4 00000000 */  nop       
/* C9F1D8 802412B8 4618A501 */  sub.s     $f20, $f20, $f24
/* C9F1DC 802412BC 3C013F00 */  lui       $at, 0x3f00
/* C9F1E0 802412C0 44810000 */  mtc1      $at, $f0
/* C9F1E4 802412C4 00000000 */  nop       
/* C9F1E8 802412C8 4600A502 */  mul.s     $f20, $f20, $f0
/* C9F1EC 802412CC 00000000 */  nop       
/* C9F1F0 802412D0 12000007 */  beqz      $s0, .L802412F0
/* C9F1F4 802412D4 0233102A */   slt      $v0, $s1, $s3
/* C9F1F8 802412D8 10400005 */  beqz      $v0, .L802412F0
/* C9F1FC 802412DC 0240202D */   daddu    $a0, $s2, $zero
/* C9F200 802412E0 0220982D */  daddu     $s3, $s1, $zero
/* C9F204 802412E4 0280282D */  daddu     $a1, $s4, $zero
/* C9F208 802412E8 0C0B2026 */  jal       set_variable
/* C9F20C 802412EC 0220302D */   daddu    $a2, $s1, $zero
.L802412F0:
/* C9F210 802412F0 3C014049 */  lui       $at, 0x4049
/* C9F214 802412F4 34210FD8 */  ori       $at, $at, 0xfd8
/* C9F218 802412F8 44810000 */  mtc1      $at, $f0
/* C9F21C 802412FC 44936000 */  mtc1      $s3, $f12
/* C9F220 80241300 00000000 */  nop       
/* C9F224 80241304 46806320 */  cvt.s.w   $f12, $f12
/* C9F228 80241308 46006302 */  mul.s     $f12, $f12, $f0
/* C9F22C 8024130C 00000000 */  nop       
/* C9F230 80241310 44910000 */  mtc1      $s1, $f0
/* C9F234 80241314 00000000 */  nop       
/* C9F238 80241318 46800020 */  cvt.s.w   $f0, $f0
/* C9F23C 8024131C 46006303 */  div.s     $f12, $f12, $f0
/* C9F240 80241320 0C00A874 */  jal       cos_rad
/* C9F244 80241324 46166300 */   add.s    $f12, $f12, $f22
/* C9F248 80241328 4600A002 */  mul.s     $f0, $f20, $f0
/* C9F24C 8024132C 00000000 */  nop       
/* C9F250 80241330 4614C080 */  add.s     $f2, $f24, $f20
/* C9F254 80241334 46001081 */  sub.s     $f2, $f2, $f0
/* C9F258 80241338 0240202D */  daddu     $a0, $s2, $zero
/* C9F25C 8024133C 44061000 */  mfc1      $a2, $f2
/* C9F260 80241340 0C0B2190 */  jal       set_float_variable
/* C9F264 80241344 02A0282D */   daddu    $a1, $s5, $zero
/* C9F268 80241348 8FBF0028 */  lw        $ra, 0x28($sp)
/* C9F26C 8024134C 8FB50024 */  lw        $s5, 0x24($sp)
/* C9F270 80241350 8FB40020 */  lw        $s4, 0x20($sp)
/* C9F274 80241354 8FB3001C */  lw        $s3, 0x1c($sp)
/* C9F278 80241358 8FB20018 */  lw        $s2, 0x18($sp)
/* C9F27C 8024135C 8FB10014 */  lw        $s1, 0x14($sp)
/* C9F280 80241360 8FB00010 */  lw        $s0, 0x10($sp)
/* C9F284 80241364 D7B80040 */  ldc1      $f24, 0x40($sp)
/* C9F288 80241368 D7B60038 */  ldc1      $f22, 0x38($sp)
/* C9F28C 8024136C D7B40030 */  ldc1      $f20, 0x30($sp)
/* C9F290 80241370 24020002 */  addiu     $v0, $zero, 2
/* C9F294 80241374 03E00008 */  jr        $ra
/* C9F298 80241378 27BD0048 */   addiu    $sp, $sp, 0x48
