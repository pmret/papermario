.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024121C_EBA06C
/* EBA06C 8024121C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EBA070 80241220 AFB20018 */  sw        $s2, 0x18($sp)
/* EBA074 80241224 0080902D */  daddu     $s2, $a0, $zero
/* EBA078 80241228 AFBF0028 */  sw        $ra, 0x28($sp)
/* EBA07C 8024122C AFB50024 */  sw        $s5, 0x24($sp)
/* EBA080 80241230 AFB40020 */  sw        $s4, 0x20($sp)
/* EBA084 80241234 AFB3001C */  sw        $s3, 0x1c($sp)
/* EBA088 80241238 AFB10014 */  sw        $s1, 0x14($sp)
/* EBA08C 8024123C AFB00010 */  sw        $s0, 0x10($sp)
/* EBA090 80241240 F7B80040 */  sdc1      $f24, 0x40($sp)
/* EBA094 80241244 F7B60038 */  sdc1      $f22, 0x38($sp)
/* EBA098 80241248 F7B40030 */  sdc1      $f20, 0x30($sp)
/* EBA09C 8024124C 8E50000C */  lw        $s0, 0xc($s2)
/* EBA0A0 80241250 8E140000 */  lw        $s4, ($s0)
/* EBA0A4 80241254 26100004 */  addiu     $s0, $s0, 4
/* EBA0A8 80241258 0C0B53A3 */  jal       dead_evt_get_variable
/* EBA0AC 8024125C 0280282D */   daddu    $a1, $s4, $zero
/* EBA0B0 80241260 0040982D */  daddu     $s3, $v0, $zero
/* EBA0B4 80241264 8E150000 */  lw        $s5, ($s0)
/* EBA0B8 80241268 26100004 */  addiu     $s0, $s0, 4
/* EBA0BC 8024126C 8E050000 */  lw        $a1, ($s0)
/* EBA0C0 80241270 26100004 */  addiu     $s0, $s0, 4
/* EBA0C4 80241274 0C0B55FF */  jal       dead_evt_get_float_variable
/* EBA0C8 80241278 0240202D */   daddu    $a0, $s2, $zero
/* EBA0CC 8024127C 8E050000 */  lw        $a1, ($s0)
/* EBA0D0 80241280 26100004 */  addiu     $s0, $s0, 4
/* EBA0D4 80241284 0240202D */  daddu     $a0, $s2, $zero
/* EBA0D8 80241288 0C0B55FF */  jal       dead_evt_get_float_variable
/* EBA0DC 8024128C 46000606 */   mov.s    $f24, $f0
/* EBA0E0 80241290 8E050000 */  lw        $a1, ($s0)
/* EBA0E4 80241294 26100004 */  addiu     $s0, $s0, 4
/* EBA0E8 80241298 0240202D */  daddu     $a0, $s2, $zero
/* EBA0EC 8024129C 0C0B53A3 */  jal       dead_evt_get_variable
/* EBA0F0 802412A0 46000506 */   mov.s    $f20, $f0
/* EBA0F4 802412A4 8E050000 */  lw        $a1, ($s0)
/* EBA0F8 802412A8 26100004 */  addiu     $s0, $s0, 4
/* EBA0FC 802412AC 0240202D */  daddu     $a0, $s2, $zero
/* EBA100 802412B0 0C0B53A3 */  jal       dead_evt_get_variable
/* EBA104 802412B4 0040882D */   daddu    $s1, $v0, $zero
/* EBA108 802412B8 0240202D */  daddu     $a0, $s2, $zero
/* EBA10C 802412BC 8E050000 */  lw        $a1, ($s0)
/* EBA110 802412C0 0C0B55FF */  jal       dead_evt_get_float_variable
/* EBA114 802412C4 0040802D */   daddu    $s0, $v0, $zero
/* EBA118 802412C8 3C014334 */  lui       $at, 0x4334
/* EBA11C 802412CC 44811000 */  mtc1      $at, $f2
/* EBA120 802412D0 3C014049 */  lui       $at, 0x4049
/* EBA124 802412D4 34210FD8 */  ori       $at, $at, 0xfd8
/* EBA128 802412D8 44812000 */  mtc1      $at, $f4
/* EBA12C 802412DC 46020003 */  div.s     $f0, $f0, $f2
/* EBA130 802412E0 46040582 */  mul.s     $f22, $f0, $f4
/* EBA134 802412E4 00000000 */  nop
/* EBA138 802412E8 4618A501 */  sub.s     $f20, $f20, $f24
/* EBA13C 802412EC 3C013F00 */  lui       $at, 0x3f00
/* EBA140 802412F0 44810000 */  mtc1      $at, $f0
/* EBA144 802412F4 00000000 */  nop
/* EBA148 802412F8 4600A502 */  mul.s     $f20, $f20, $f0
/* EBA14C 802412FC 00000000 */  nop
/* EBA150 80241300 12000007 */  beqz      $s0, .L80241320
/* EBA154 80241304 0233102A */   slt      $v0, $s1, $s3
/* EBA158 80241308 10400005 */  beqz      $v0, .L80241320
/* EBA15C 8024130C 0240202D */   daddu    $a0, $s2, $zero
/* EBA160 80241310 0220982D */  daddu     $s3, $s1, $zero
/* EBA164 80241314 0280282D */  daddu     $a1, $s4, $zero
/* EBA168 80241318 0C0B551A */  jal       dead_evt_set_variable
/* EBA16C 8024131C 0220302D */   daddu    $a2, $s1, $zero
.L80241320:
/* EBA170 80241320 3C014049 */  lui       $at, 0x4049
/* EBA174 80241324 34210FD8 */  ori       $at, $at, 0xfd8
/* EBA178 80241328 44810000 */  mtc1      $at, $f0
/* EBA17C 8024132C 44936000 */  mtc1      $s3, $f12
/* EBA180 80241330 00000000 */  nop
/* EBA184 80241334 46806320 */  cvt.s.w   $f12, $f12
/* EBA188 80241338 46006302 */  mul.s     $f12, $f12, $f0
/* EBA18C 8024133C 00000000 */  nop
/* EBA190 80241340 44910000 */  mtc1      $s1, $f0
/* EBA194 80241344 00000000 */  nop
/* EBA198 80241348 46800020 */  cvt.s.w   $f0, $f0
/* EBA19C 8024134C 46006303 */  div.s     $f12, $f12, $f0
/* EBA1A0 80241350 0C00AD30 */  jal       dead_cos_rad
/* EBA1A4 80241354 46166300 */   add.s    $f12, $f12, $f22
/* EBA1A8 80241358 4600A002 */  mul.s     $f0, $f20, $f0
/* EBA1AC 8024135C 00000000 */  nop
/* EBA1B0 80241360 4614C080 */  add.s     $f2, $f24, $f20
/* EBA1B4 80241364 46001081 */  sub.s     $f2, $f2, $f0
/* EBA1B8 80241368 0240202D */  daddu     $a0, $s2, $zero
/* EBA1BC 8024136C 44061000 */  mfc1      $a2, $f2
/* EBA1C0 80241370 0C0B5684 */  jal       dead_evt_set_float_variable
/* EBA1C4 80241374 02A0282D */   daddu    $a1, $s5, $zero
/* EBA1C8 80241378 8FBF0028 */  lw        $ra, 0x28($sp)
/* EBA1CC 8024137C 8FB50024 */  lw        $s5, 0x24($sp)
/* EBA1D0 80241380 8FB40020 */  lw        $s4, 0x20($sp)
/* EBA1D4 80241384 8FB3001C */  lw        $s3, 0x1c($sp)
/* EBA1D8 80241388 8FB20018 */  lw        $s2, 0x18($sp)
/* EBA1DC 8024138C 8FB10014 */  lw        $s1, 0x14($sp)
/* EBA1E0 80241390 8FB00010 */  lw        $s0, 0x10($sp)
/* EBA1E4 80241394 D7B80040 */  ldc1      $f24, 0x40($sp)
/* EBA1E8 80241398 D7B60038 */  ldc1      $f22, 0x38($sp)
/* EBA1EC 8024139C D7B40030 */  ldc1      $f20, 0x30($sp)
/* EBA1F0 802413A0 24020002 */  addiu     $v0, $zero, 2
/* EBA1F4 802413A4 03E00008 */  jr        $ra
/* EBA1F8 802413A8 27BD0048 */   addiu    $sp, $sp, 0x48
