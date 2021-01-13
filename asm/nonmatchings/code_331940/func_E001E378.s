.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001E378
/* 331CB8 E001E378 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 331CBC E001E37C AFB1002C */  sw        $s1, 0x2c($sp)
/* 331CC0 E001E380 0080882D */  daddu     $s1, $a0, $zero
/* 331CC4 E001E384 AFBF0030 */  sw        $ra, 0x30($sp)
/* 331CC8 E001E388 AFB00028 */  sw        $s0, 0x28($sp)
/* 331CCC E001E38C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 331CD0 E001E390 8E30000C */  lw        $s0, 0xc($s1)
/* 331CD4 E001E394 8E020038 */  lw        $v0, 0x38($s0)
/* 331CD8 E001E398 28420002 */  slti      $v0, $v0, 2
/* 331CDC E001E39C 144000AF */  bnez      $v0, .LE001E65C
/* 331CE0 E001E3A0 00000000 */   nop
/* 331CE4 E001E3A4 C6040010 */  lwc1      $f4, 0x10($s0)
/* 331CE8 E001E3A8 46042102 */  mul.s     $f4, $f4, $f4
/* 331CEC E001E3AC 00000000 */  nop
/* 331CF0 E001E3B0 C6020014 */  lwc1      $f2, 0x14($s0)
/* 331CF4 E001E3B4 46021082 */  mul.s     $f2, $f2, $f2
/* 331CF8 E001E3B8 00000000 */  nop
/* 331CFC E001E3BC C6000018 */  lwc1      $f0, 0x18($s0)
/* 331D00 E001E3C0 46000002 */  mul.s     $f0, $f0, $f0
/* 331D04 E001E3C4 00000000 */  nop
/* 331D08 E001E3C8 46022100 */  add.s     $f4, $f4, $f2
/* 331D0C E001E3CC 46002300 */  add.s     $f12, $f4, $f0
/* 331D10 E001E3D0 3C013C23 */  lui       $at, 0x3c23
/* 331D14 E001E3D4 3421D70A */  ori       $at, $at, 0xd70a
/* 331D18 E001E3D8 44810000 */  mtc1      $at, $f0
/* 331D1C E001E3DC 00000000 */  nop
/* 331D20 E001E3E0 460C003C */  c.lt.s    $f0, $f12
/* 331D24 E001E3E4 00000000 */  nop
/* 331D28 E001E3E8 45000008 */  bc1f      .LE001E40C
/* 331D2C E001E3EC E7AC0024 */   swc1     $f12, 0x24($sp)
/* 331D30 E001E3F0 0C080154 */  jal       func_E0200550
/* 331D34 E001E3F4 00000000 */   nop
/* 331D38 E001E3F8 3C013F80 */  lui       $at, 0x3f80
/* 331D3C E001E3FC 44811000 */  mtc1      $at, $f2
/* 331D40 E001E400 00000000 */  nop
/* 331D44 E001E404 46001083 */  div.s     $f2, $f2, $f0
/* 331D48 E001E408 E7A20024 */  swc1      $f2, 0x24($sp)
.LE001E40C:
/* 331D4C E001E40C C60A0010 */  lwc1      $f10, 0x10($s0)
/* 331D50 E001E410 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 331D54 E001E414 46005282 */  mul.s     $f10, $f10, $f0
/* 331D58 E001E418 00000000 */  nop
/* 331D5C E001E41C C6040014 */  lwc1      $f4, 0x14($s0)
/* 331D60 E001E420 46002102 */  mul.s     $f4, $f4, $f0
/* 331D64 E001E424 00000000 */  nop
/* 331D68 E001E428 C6060018 */  lwc1      $f6, 0x18($s0)
/* 331D6C E001E42C 46003182 */  mul.s     $f6, $f6, $f0
/* 331D70 E001E430 00000000 */  nop
/* 331D74 E001E434 3C014200 */  lui       $at, 0x4200
/* 331D78 E001E438 44811000 */  mtc1      $at, $f2
/* 331D7C E001E43C 00000000 */  nop
/* 331D80 E001E440 46025282 */  mul.s     $f10, $f10, $f2
/* 331D84 E001E444 00000000 */  nop
/* 331D88 E001E448 46022102 */  mul.s     $f4, $f4, $f2
/* 331D8C E001E44C 00000000 */  nop
/* 331D90 E001E450 46023182 */  mul.s     $f6, $f6, $f2
/* 331D94 E001E454 00000000 */  nop
/* 331D98 E001E458 C6080004 */  lwc1      $f8, 4($s0)
/* 331D9C E001E45C 3C014280 */  lui       $at, 0x4280
/* 331DA0 E001E460 44810000 */  mtc1      $at, $f0
/* 331DA4 E001E464 C6020008 */  lwc1      $f2, 8($s0)
/* 331DA8 E001E468 460A4201 */  sub.s     $f8, $f8, $f10
/* 331DAC E001E46C E7A00024 */  swc1      $f0, 0x24($sp)
/* 331DB0 E001E470 46041081 */  sub.s     $f2, $f2, $f4
/* 331DB4 E001E474 C600000C */  lwc1      $f0, 0xc($s0)
/* 331DB8 E001E478 8E020000 */  lw        $v0, ($s0)
/* 331DBC E001E47C 46060001 */  sub.s     $f0, $f0, $f6
/* 331DC0 E001E480 E7A80018 */  swc1      $f8, 0x18($sp)
/* 331DC4 E001E484 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 331DC8 E001E488 1040005C */  beqz      $v0, .LE001E5FC
/* 331DCC E001E48C E7A00020 */   swc1     $f0, 0x20($sp)
/* 331DD0 E001E490 C6000014 */  lwc1      $f0, 0x14($s0)
/* 331DD4 E001E494 4480A000 */  mtc1      $zero, $f20
/* 331DD8 E001E498 00000000 */  nop
/* 331DDC E001E49C 4614003C */  c.lt.s    $f0, $f20
/* 331DE0 E001E4A0 00000000 */  nop
/* 331DE4 E001E4A4 45000055 */  bc1f      .LE001E5FC
/* 331DE8 E001E4A8 27A20024 */   addiu    $v0, $sp, 0x24
/* 331DEC E001E4AC AFA20010 */  sw        $v0, 0x10($sp)
/* 331DF0 E001E4B0 0000202D */  daddu     $a0, $zero, $zero
/* 331DF4 E001E4B4 27A50018 */  addiu     $a1, $sp, 0x18
/* 331DF8 E001E4B8 27A6001C */  addiu     $a2, $sp, 0x1c
/* 331DFC E001E4BC 0C08014C */  jal       func_E0200530
/* 331E00 E001E4C0 27A70020 */   addiu    $a3, $sp, 0x20
/* 331E04 E001E4C4 1040004D */  beqz      $v0, .LE001E5FC
/* 331E08 E001E4C8 00000000 */   nop
/* 331E0C E001E4CC C7A20024 */  lwc1      $f2, 0x24($sp)
/* 331E10 E001E4D0 3C014228 */  lui       $at, 0x4228
/* 331E14 E001E4D4 44810000 */  mtc1      $at, $f0
/* 331E18 E001E4D8 00000000 */  nop
/* 331E1C E001E4DC 4600103C */  c.lt.s    $f2, $f0
/* 331E20 E001E4E0 00000000 */  nop
/* 331E24 E001E4E4 45000045 */  bc1f      .LE001E5FC
/* 331E28 E001E4E8 24040006 */   addiu    $a0, $zero, 6
/* 331E2C E001E4EC C6040014 */  lwc1      $f4, 0x14($s0)
/* 331E30 E001E4F0 3C01E002 */  lui       $at, %hi(D_E001ED50)
/* 331E34 E001E4F4 D420ED50 */  ldc1      $f0, %lo(D_E001ED50)($at)
/* 331E38 E001E4F8 46002107 */  neg.s     $f4, $f4
/* 331E3C E001E4FC 46002121 */  cvt.d.s   $f4, $f4
/* 331E40 E001E500 46202102 */  mul.d     $f4, $f4, $f0
/* 331E44 E001E504 00000000 */  nop
/* 331E48 E001E508 C6060010 */  lwc1      $f6, 0x10($s0)
/* 331E4C E001E50C 3C01E002 */  lui       $at, %hi(D_E001ED58)
/* 331E50 E001E510 D428ED58 */  ldc1      $f8, %lo(D_E001ED58)($at)
/* 331E54 E001E514 460031A1 */  cvt.d.s   $f6, $f6
/* 331E58 E001E518 46283182 */  mul.d     $f6, $f6, $f8
/* 331E5C E001E51C 00000000 */  nop
/* 331E60 E001E520 C6020034 */  lwc1      $f2, 0x34($s0)
/* 331E64 E001E524 460010A1 */  cvt.d.s   $f2, $f2
/* 331E68 E001E528 46281082 */  mul.d     $f2, $f2, $f8
/* 331E6C E001E52C 00000000 */  nop
/* 331E70 E001E530 C60A001C */  lwc1      $f10, 0x1c($s0)
/* 331E74 E001E534 3C013F80 */  lui       $at, 0x3f80
/* 331E78 E001E538 44810000 */  mtc1      $at, $f0
/* 331E7C E001E53C 00000000 */  nop
/* 331E80 E001E540 46005280 */  add.s     $f10, $f10, $f0
/* 331E84 E001E544 C600002C */  lwc1      $f0, 0x2c($s0)
/* 331E88 E001E548 46000021 */  cvt.d.s   $f0, $f0
/* 331E8C E001E54C 46280002 */  mul.d     $f0, $f0, $f8
/* 331E90 E001E550 00000000 */  nop
/* 331E94 E001E554 E60A001C */  swc1      $f10, 0x1c($s0)
/* 331E98 E001E558 46202120 */  cvt.s.d   $f4, $f4
/* 331E9C E001E55C 462031A0 */  cvt.s.d   $f6, $f6
/* 331EA0 E001E560 462010A0 */  cvt.s.d   $f2, $f2
/* 331EA4 E001E564 E6040014 */  swc1      $f4, 0x14($s0)
/* 331EA8 E001E568 E6060010 */  swc1      $f6, 0x10($s0)
/* 331EAC E001E56C E6020034 */  swc1      $f2, 0x34($s0)
/* 331EB0 E001E570 46200020 */  cvt.s.d   $f0, $f0
/* 331EB4 E001E574 0C080150 */  jal       func_E0200540
/* 331EB8 E001E578 E600002C */   swc1     $f0, 0x2c($s0)
/* 331EBC E001E57C C6020008 */  lwc1      $f2, 8($s0)
/* 331EC0 E001E580 3C0140A0 */  lui       $at, 0x40a0
/* 331EC4 E001E584 44810000 */  mtc1      $at, $f0
/* 331EC8 E001E588 E7B40010 */  swc1      $f20, 0x10($sp)
/* 331ECC E001E58C 46001081 */  sub.s     $f2, $f2, $f0
/* 331ED0 E001E590 8E050004 */  lw        $a1, 4($s0)
/* 331ED4 E001E594 8E07000C */  lw        $a3, 0xc($s0)
/* 331ED8 E001E598 44061000 */  mfc1      $a2, $f2
/* 331EDC E001E59C 0C003058 */  jal       func_E000C160
/* 331EE0 E001E5A0 0000202D */   daddu    $a0, $zero, $zero
/* 331EE4 E001E5A4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 331EE8 E001E5A8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 331EEC E001E5AC 80420070 */  lb        $v0, 0x70($v0)
/* 331EF0 E001E5B0 14400008 */  bnez      $v0, .LE001E5D4
/* 331EF4 E001E5B4 3C04B000 */   lui      $a0, 0xb000
/* 331EF8 E001E5B8 C600000C */  lwc1      $f0, 0xc($s0)
/* 331EFC E001E5BC 34840016 */  ori       $a0, $a0, 0x16
/* 331F00 E001E5C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 331F04 E001E5C4 8E060004 */  lw        $a2, 4($s0)
/* 331F08 E001E5C8 8E070008 */  lw        $a3, 8($s0)
/* 331F0C E001E5CC 0C0801A0 */  jal       func_E0200680
/* 331F10 E001E5D0 0000282D */   daddu    $a1, $zero, $zero
.LE001E5D4:
/* 331F14 E001E5D4 C602001C */  lwc1      $f2, 0x1c($s0)
/* 331F18 E001E5D8 3C014120 */  lui       $at, 0x4120
/* 331F1C E001E5DC 44810000 */  mtc1      $at, $f0
/* 331F20 E001E5E0 00000000 */  nop
/* 331F24 E001E5E4 4602003E */  c.le.s    $f0, $f2
/* 331F28 E001E5E8 00000000 */  nop
/* 331F2C E001E5EC 45000003 */  bc1f      .LE001E5FC
/* 331F30 E001E5F0 AE000000 */   sw       $zero, ($s0)
/* 331F34 E001E5F4 2402FFFF */  addiu     $v0, $zero, -1
/* 331F38 E001E5F8 AE020030 */  sw        $v0, 0x30($s0)
.LE001E5FC:
/* 331F3C E001E5FC C600001C */  lwc1      $f0, 0x1c($s0)
/* 331F40 E001E600 44806000 */  mtc1      $zero, $f12
/* 331F44 E001E604 00000000 */  nop
/* 331F48 E001E608 460C0032 */  c.eq.s    $f0, $f12
/* 331F4C E001E60C 00000000 */  nop
/* 331F50 E001E610 45010012 */  bc1t      .LE001E65C
/* 331F54 E001E614 46006386 */   mov.s    $f14, $f12
/* 331F58 E001E618 C6000014 */  lwc1      $f0, 0x14($s0)
/* 331F5C E001E61C 3C01BFE0 */  lui       $at, 0xbfe0
/* 331F60 E001E620 44811800 */  mtc1      $at, $f3
/* 331F64 E001E624 44801000 */  mtc1      $zero, $f2
/* 331F68 E001E628 C604002C */  lwc1      $f4, 0x2c($s0)
/* 331F6C E001E62C 46000021 */  cvt.d.s   $f0, $f0
/* 331F70 E001E630 46220000 */  add.d     $f0, $f0, $f2
/* 331F74 E001E634 C6020024 */  lwc1      $f2, 0x24($s0)
/* 331F78 E001E638 8E070034 */  lw        $a3, 0x34($s0)
/* 331F7C E001E63C 46041080 */  add.s     $f2, $f2, $f4
/* 331F80 E001E640 46200020 */  cvt.s.d   $f0, $f0
/* 331F84 E001E644 E6000014 */  swc1      $f0, 0x14($s0)
/* 331F88 E001E648 46000007 */  neg.s     $f0, $f0
/* 331F8C E001E64C 44060000 */  mfc1      $a2, $f0
/* 331F90 E001E650 0C080148 */  jal       func_E0200520
/* 331F94 E001E654 E6020024 */   swc1     $f2, 0x24($s0)
/* 331F98 E001E658 E6000020 */  swc1      $f0, 0x20($s0)
.LE001E65C:
/* 331F9C E001E65C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 331FA0 E001E660 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 331FA4 E001E664 C440002C */  lwc1      $f0, 0x2c($v0)
/* 331FA8 E001E668 C6020008 */  lwc1      $f2, 8($s0)
/* 331FAC E001E66C 46020001 */  sub.s     $f0, $f0, $f2
/* 331FB0 E001E670 3C014396 */  lui       $at, 0x4396
/* 331FB4 E001E674 44811000 */  mtc1      $at, $f2
/* 331FB8 E001E678 00000000 */  nop
/* 331FBC E001E67C 4600103C */  c.lt.s    $f2, $f0
/* 331FC0 E001E680 00000000 */  nop
/* 331FC4 E001E684 45000002 */  bc1f      .LE001E690
/* 331FC8 E001E688 2402FFFF */   addiu    $v0, $zero, -1
/* 331FCC E001E68C AE020030 */  sw        $v0, 0x30($s0)
.LE001E690:
/* 331FD0 E001E690 C6060004 */  lwc1      $f6, 4($s0)
/* 331FD4 E001E694 C6000010 */  lwc1      $f0, 0x10($s0)
/* 331FD8 E001E698 C6020008 */  lwc1      $f2, 8($s0)
/* 331FDC E001E69C 46003180 */  add.s     $f6, $f6, $f0
/* 331FE0 E001E6A0 C6000014 */  lwc1      $f0, 0x14($s0)
/* 331FE4 E001E6A4 C6040018 */  lwc1      $f4, 0x18($s0)
/* 331FE8 E001E6A8 46001080 */  add.s     $f2, $f2, $f0
/* 331FEC E001E6AC C600000C */  lwc1      $f0, 0xc($s0)
/* 331FF0 E001E6B0 8E020030 */  lw        $v0, 0x30($s0)
/* 331FF4 E001E6B4 46040000 */  add.s     $f0, $f0, $f4
/* 331FF8 E001E6B8 E6060004 */  swc1      $f6, 4($s0)
/* 331FFC E001E6BC E6020008 */  swc1      $f2, 8($s0)
/* 332000 E001E6C0 04410003 */  bgez      $v0, .LE001E6D0
/* 332004 E001E6C4 E600000C */   swc1     $f0, 0xc($s0)
/* 332008 E001E6C8 0C080128 */  jal       func_E02004A0
/* 33200C E001E6CC 0220202D */   daddu    $a0, $s1, $zero
.LE001E6D0:
/* 332010 E001E6D0 8FBF0030 */  lw        $ra, 0x30($sp)
/* 332014 E001E6D4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 332018 E001E6D8 8FB00028 */  lw        $s0, 0x28($sp)
/* 33201C E001E6DC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 332020 E001E6E0 03E00008 */  jr        $ra
/* 332024 E001E6E4 27BD0040 */   addiu    $sp, $sp, 0x40
