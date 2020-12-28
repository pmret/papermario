.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182A8_6CC318
/* 6CC318 802182A8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 6CC31C 802182AC AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC320 802182B0 0080902D */  daddu     $s2, $a0, $zero
/* 6CC324 802182B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 6CC328 802182B8 AFB50024 */  sw        $s5, 0x24($sp)
/* 6CC32C 802182BC AFB40020 */  sw        $s4, 0x20($sp)
/* 6CC330 802182C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC334 802182C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC338 802182C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC33C 802182CC F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6CC340 802182D0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6CC344 802182D4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6CC348 802182D8 8E50000C */  lw        $s0, 0xc($s2)
/* 6CC34C 802182DC 8E140000 */  lw        $s4, ($s0)
/* 6CC350 802182E0 26100004 */  addiu     $s0, $s0, 4
/* 6CC354 802182E4 0C0B1EAF */  jal       get_variable
/* 6CC358 802182E8 0280282D */   daddu    $a1, $s4, $zero
/* 6CC35C 802182EC 0040982D */  daddu     $s3, $v0, $zero
/* 6CC360 802182F0 8E150000 */  lw        $s5, ($s0)
/* 6CC364 802182F4 26100004 */  addiu     $s0, $s0, 4
/* 6CC368 802182F8 8E050000 */  lw        $a1, ($s0)
/* 6CC36C 802182FC 26100004 */  addiu     $s0, $s0, 4
/* 6CC370 80218300 0C0B210B */  jal       get_float_variable
/* 6CC374 80218304 0240202D */   daddu    $a0, $s2, $zero
/* 6CC378 80218308 8E050000 */  lw        $a1, ($s0)
/* 6CC37C 8021830C 26100004 */  addiu     $s0, $s0, 4
/* 6CC380 80218310 0240202D */  daddu     $a0, $s2, $zero
/* 6CC384 80218314 0C0B210B */  jal       get_float_variable
/* 6CC388 80218318 46000606 */   mov.s    $f24, $f0
/* 6CC38C 8021831C 8E050000 */  lw        $a1, ($s0)
/* 6CC390 80218320 26100004 */  addiu     $s0, $s0, 4
/* 6CC394 80218324 0240202D */  daddu     $a0, $s2, $zero
/* 6CC398 80218328 0C0B1EAF */  jal       get_variable
/* 6CC39C 8021832C 46000506 */   mov.s    $f20, $f0
/* 6CC3A0 80218330 8E050000 */  lw        $a1, ($s0)
/* 6CC3A4 80218334 26100004 */  addiu     $s0, $s0, 4
/* 6CC3A8 80218338 0240202D */  daddu     $a0, $s2, $zero
/* 6CC3AC 8021833C 0C0B1EAF */  jal       get_variable
/* 6CC3B0 80218340 0040882D */   daddu    $s1, $v0, $zero
/* 6CC3B4 80218344 0240202D */  daddu     $a0, $s2, $zero
/* 6CC3B8 80218348 8E050000 */  lw        $a1, ($s0)
/* 6CC3BC 8021834C 0C0B210B */  jal       get_float_variable
/* 6CC3C0 80218350 0040802D */   daddu    $s0, $v0, $zero
/* 6CC3C4 80218354 3C014334 */  lui       $at, 0x4334
/* 6CC3C8 80218358 44811000 */  mtc1      $at, $f2
/* 6CC3CC 8021835C 3C014049 */  lui       $at, 0x4049
/* 6CC3D0 80218360 34210FD8 */  ori       $at, $at, 0xfd8
/* 6CC3D4 80218364 44812000 */  mtc1      $at, $f4
/* 6CC3D8 80218368 46020003 */  div.s     $f0, $f0, $f2
/* 6CC3DC 8021836C 46040582 */  mul.s     $f22, $f0, $f4
/* 6CC3E0 80218370 00000000 */  nop       
/* 6CC3E4 80218374 4618A501 */  sub.s     $f20, $f20, $f24
/* 6CC3E8 80218378 3C013F00 */  lui       $at, 0x3f00
/* 6CC3EC 8021837C 44810000 */  mtc1      $at, $f0
/* 6CC3F0 80218380 00000000 */  nop       
/* 6CC3F4 80218384 4600A502 */  mul.s     $f20, $f20, $f0
/* 6CC3F8 80218388 00000000 */  nop       
/* 6CC3FC 8021838C 12000007 */  beqz      $s0, .L802183AC
/* 6CC400 80218390 0233102A */   slt      $v0, $s1, $s3
/* 6CC404 80218394 10400005 */  beqz      $v0, .L802183AC
/* 6CC408 80218398 0240202D */   daddu    $a0, $s2, $zero
/* 6CC40C 8021839C 0220982D */  daddu     $s3, $s1, $zero
/* 6CC410 802183A0 0280282D */  daddu     $a1, $s4, $zero
/* 6CC414 802183A4 0C0B2026 */  jal       set_variable
/* 6CC418 802183A8 0220302D */   daddu    $a2, $s1, $zero
.L802183AC:
/* 6CC41C 802183AC 3C014049 */  lui       $at, 0x4049
/* 6CC420 802183B0 34210FD8 */  ori       $at, $at, 0xfd8
/* 6CC424 802183B4 44810000 */  mtc1      $at, $f0
/* 6CC428 802183B8 44936000 */  mtc1      $s3, $f12
/* 6CC42C 802183BC 00000000 */  nop       
/* 6CC430 802183C0 46806320 */  cvt.s.w   $f12, $f12
/* 6CC434 802183C4 46006302 */  mul.s     $f12, $f12, $f0
/* 6CC438 802183C8 00000000 */  nop       
/* 6CC43C 802183CC 44910000 */  mtc1      $s1, $f0
/* 6CC440 802183D0 00000000 */  nop       
/* 6CC444 802183D4 46800020 */  cvt.s.w   $f0, $f0
/* 6CC448 802183D8 46006303 */  div.s     $f12, $f12, $f0
/* 6CC44C 802183DC 0C00A874 */  jal       cos_rad
/* 6CC450 802183E0 46166300 */   add.s    $f12, $f12, $f22
/* 6CC454 802183E4 4600A002 */  mul.s     $f0, $f20, $f0
/* 6CC458 802183E8 00000000 */  nop       
/* 6CC45C 802183EC 4614C080 */  add.s     $f2, $f24, $f20
/* 6CC460 802183F0 46001081 */  sub.s     $f2, $f2, $f0
/* 6CC464 802183F4 0240202D */  daddu     $a0, $s2, $zero
/* 6CC468 802183F8 44061000 */  mfc1      $a2, $f2
/* 6CC46C 802183FC 0C0B2190 */  jal       set_float_variable
/* 6CC470 80218400 02A0282D */   daddu    $a1, $s5, $zero
/* 6CC474 80218404 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6CC478 80218408 8FB50024 */  lw        $s5, 0x24($sp)
/* 6CC47C 8021840C 8FB40020 */  lw        $s4, 0x20($sp)
/* 6CC480 80218410 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC484 80218414 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC488 80218418 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC48C 8021841C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC490 80218420 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6CC494 80218424 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6CC498 80218428 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6CC49C 8021842C 24020002 */  addiu     $v0, $zero, 2
/* 6CC4A0 80218430 03E00008 */  jr        $ra
/* 6CC4A4 80218434 27BD0048 */   addiu    $sp, $sp, 0x48
