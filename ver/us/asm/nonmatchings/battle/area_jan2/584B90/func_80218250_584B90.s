.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218250_584B90
/* 584B90 80218250 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 584B94 80218254 AFB10024 */  sw        $s1, 0x24($sp)
/* 584B98 80218258 0080882D */  daddu     $s1, $a0, $zero
/* 584B9C 8021825C AFBF0028 */  sw        $ra, 0x28($sp)
/* 584BA0 80218260 AFB00020 */  sw        $s0, 0x20($sp)
/* 584BA4 80218264 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 584BA8 80218268 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 584BAC 8021826C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 584BB0 80218270 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 584BB4 80218274 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 584BB8 80218278 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 584BBC 8021827C 8E30000C */  lw        $s0, 0xc($s1)
/* 584BC0 80218280 8E050000 */  lw        $a1, ($s0)
/* 584BC4 80218284 0C0B210B */  jal       get_float_variable
/* 584BC8 80218288 26100004 */   addiu    $s0, $s0, 4
/* 584BCC 8021828C 8E050000 */  lw        $a1, ($s0)
/* 584BD0 80218290 26100004 */  addiu     $s0, $s0, 4
/* 584BD4 80218294 0220202D */  daddu     $a0, $s1, $zero
/* 584BD8 80218298 0C0B210B */  jal       get_float_variable
/* 584BDC 8021829C 46000786 */   mov.s    $f30, $f0
/* 584BE0 802182A0 8E050000 */  lw        $a1, ($s0)
/* 584BE4 802182A4 26100004 */  addiu     $s0, $s0, 4
/* 584BE8 802182A8 0220202D */  daddu     $a0, $s1, $zero
/* 584BEC 802182AC 0C0B210B */  jal       get_float_variable
/* 584BF0 802182B0 46000506 */   mov.s    $f20, $f0
/* 584BF4 802182B4 8E050000 */  lw        $a1, ($s0)
/* 584BF8 802182B8 26100004 */  addiu     $s0, $s0, 4
/* 584BFC 802182BC 0220202D */  daddu     $a0, $s1, $zero
/* 584C00 802182C0 0C0B210B */  jal       get_float_variable
/* 584C04 802182C4 46000706 */   mov.s    $f28, $f0
/* 584C08 802182C8 8E050000 */  lw        $a1, ($s0)
/* 584C0C 802182CC 26100004 */  addiu     $s0, $s0, 4
/* 584C10 802182D0 0220202D */  daddu     $a0, $s1, $zero
/* 584C14 802182D4 0C0B210B */  jal       get_float_variable
/* 584C18 802182D8 46000686 */   mov.s    $f26, $f0
/* 584C1C 802182DC 8E050000 */  lw        $a1, ($s0)
/* 584C20 802182E0 26100004 */  addiu     $s0, $s0, 4
/* 584C24 802182E4 0220202D */  daddu     $a0, $s1, $zero
/* 584C28 802182E8 0C0B210B */  jal       get_float_variable
/* 584C2C 802182EC 46000606 */   mov.s    $f24, $f0
/* 584C30 802182F0 0220202D */  daddu     $a0, $s1, $zero
/* 584C34 802182F4 8E050000 */  lw        $a1, ($s0)
/* 584C38 802182F8 0C0B1EAF */  jal       get_variable
/* 584C3C 802182FC 46000586 */   mov.s    $f22, $f0
/* 584C40 80218300 8E240148 */  lw        $a0, 0x148($s1)
/* 584C44 80218304 0C09A75B */  jal       get_actor
/* 584C48 80218308 0040802D */   daddu    $s0, $v0, $zero
/* 584C4C 8021830C 4600A521 */  cvt.d.s   $f20, $f20
/* 584C50 80218310 4405F000 */  mfc1      $a1, $f30
/* 584C54 80218314 3C014014 */  lui       $at, 0x4014
/* 584C58 80218318 44810800 */  mtc1      $at, $f1
/* 584C5C 8021831C 44800000 */  mtc1      $zero, $f0
/* 584C60 80218320 4407E000 */  mfc1      $a3, $f28
/* 584C64 80218324 4620A500 */  add.d     $f20, $f20, $f0
/* 584C68 80218328 0000202D */  daddu     $a0, $zero, $zero
/* 584C6C 8021832C AFB0001C */  sw        $s0, 0x1c($sp)
/* 584C70 80218330 4620A520 */  cvt.s.d   $f20, $f20
/* 584C74 80218334 4406A000 */  mfc1      $a2, $f20
/* 584C78 80218338 0040802D */  daddu     $s0, $v0, $zero
/* 584C7C 8021833C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 584C80 80218340 E7B80014 */  swc1      $f24, 0x14($sp)
/* 584C84 80218344 0C01BFD4 */  jal       playFX_12
/* 584C88 80218348 E7B60018 */   swc1     $f22, 0x18($sp)
/* 584C8C 8021834C 0040202D */  daddu     $a0, $v0, $zero
/* 584C90 80218350 82030210 */  lb        $v1, 0x210($s0)
/* 584C94 80218354 2402000A */  addiu     $v0, $zero, 0xa
/* 584C98 80218358 14620007 */  bne       $v1, $v0, .L80218378
/* 584C9C 8021835C 00000000 */   nop
/* 584CA0 80218360 8C82000C */  lw        $v0, 0xc($a0)
/* 584CA4 80218364 3C013ECC */  lui       $at, 0x3ecc
/* 584CA8 80218368 3421CCCD */  ori       $at, $at, 0xcccd
/* 584CAC 8021836C 44810000 */  mtc1      $at, $f0
/* 584CB0 80218370 00000000 */  nop
/* 584CB4 80218374 E4400028 */  swc1      $f0, 0x28($v0)
.L80218378:
/* 584CB8 80218378 8FBF0028 */  lw        $ra, 0x28($sp)
/* 584CBC 8021837C 8FB10024 */  lw        $s1, 0x24($sp)
/* 584CC0 80218380 8FB00020 */  lw        $s0, 0x20($sp)
/* 584CC4 80218384 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 584CC8 80218388 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 584CCC 8021838C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 584CD0 80218390 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 584CD4 80218394 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 584CD8 80218398 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 584CDC 8021839C 24020002 */  addiu     $v0, $zero, 2
/* 584CE0 802183A0 03E00008 */  jr        $ra
/* 584CE4 802183A4 27BD0060 */   addiu    $sp, $sp, 0x60
