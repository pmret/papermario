.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA0_7EBAB0
/* 7EBAB0 80240DA0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 7EBAB4 80240DA4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7EBAB8 80240DA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7EBABC 80240DAC AFB00018 */  sw        $s0, 0x18($sp)
/* 7EBAC0 80240DB0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 7EBAC4 80240DB4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 7EBAC8 80240DB8 10A00060 */  beqz      $a1, .L80240F3C
/* 7EBACC 80240DBC 0080882D */   daddu    $s1, $a0, $zero
/* 7EBAD0 80240DC0 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBAD4 80240DC4 0C0B1EAF */  jal       get_variable
/* 7EBAD8 80240DC8 34A5D481 */   ori      $a1, $a1, 0xd481
/* 7EBADC 80240DCC 0220202D */  daddu     $a0, $s1, $zero
/* 7EBAE0 80240DD0 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBAE4 80240DD4 4482B000 */  mtc1      $v0, $f22
/* 7EBAE8 80240DD8 00000000 */  nop
/* 7EBAEC 80240DDC 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EBAF0 80240DE0 0C0B1EAF */  jal       get_variable
/* 7EBAF4 80240DE4 34A5D482 */   ori      $a1, $a1, 0xd482
/* 7EBAF8 80240DE8 0220202D */  daddu     $a0, $s1, $zero
/* 7EBAFC 80240DEC 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBB00 80240DF0 4482A000 */  mtc1      $v0, $f20
/* 7EBB04 80240DF4 00000000 */  nop
/* 7EBB08 80240DF8 4680A520 */  cvt.s.w   $f20, $f20
/* 7EBB0C 80240DFC 0C0B1EAF */  jal       get_variable
/* 7EBB10 80240E00 34A5D483 */   ori      $a1, $a1, 0xd483
/* 7EBB14 80240E04 44821000 */  mtc1      $v0, $f2
/* 7EBB18 80240E08 00000000 */  nop
/* 7EBB1C 80240E0C 468010A0 */  cvt.s.w   $f2, $f2
/* 7EBB20 80240E10 4405B000 */  mfc1      $a1, $f22
/* 7EBB24 80240E14 4406A000 */  mfc1      $a2, $f20
/* 7EBB28 80240E18 44071000 */  mfc1      $a3, $f2
/* 7EBB2C 80240E1C 0C01C574 */  jal       func_800715D0
/* 7EBB30 80240E20 0000202D */   daddu    $a0, $zero, $zero
/* 7EBB34 80240E24 0220202D */  daddu     $a0, $s1, $zero
/* 7EBB38 80240E28 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBB3C 80240E2C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 7EBB40 80240E30 3C108025 */  lui       $s0, %hi(D_80255B90)
/* 7EBB44 80240E34 26105B90 */  addiu     $s0, $s0, %lo(D_80255B90)
/* 7EBB48 80240E38 0C0B1EAF */  jal       get_variable
/* 7EBB4C 80240E3C AE020000 */   sw       $v0, ($s0)
/* 7EBB50 80240E40 0220202D */  daddu     $a0, $s1, $zero
/* 7EBB54 80240E44 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBB58 80240E48 4482B000 */  mtc1      $v0, $f22
/* 7EBB5C 80240E4C 00000000 */  nop
/* 7EBB60 80240E50 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EBB64 80240E54 0C0B1EAF */  jal       get_variable
/* 7EBB68 80240E58 34A5D482 */   ori      $a1, $a1, 0xd482
/* 7EBB6C 80240E5C 0220202D */  daddu     $a0, $s1, $zero
/* 7EBB70 80240E60 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBB74 80240E64 4482A000 */  mtc1      $v0, $f20
/* 7EBB78 80240E68 00000000 */  nop
/* 7EBB7C 80240E6C 4680A520 */  cvt.s.w   $f20, $f20
/* 7EBB80 80240E70 0C0B1EAF */  jal       get_variable
/* 7EBB84 80240E74 34A5D483 */   ori      $a1, $a1, 0xd483
/* 7EBB88 80240E78 44821000 */  mtc1      $v0, $f2
/* 7EBB8C 80240E7C 00000000 */  nop
/* 7EBB90 80240E80 468010A0 */  cvt.s.w   $f2, $f2
/* 7EBB94 80240E84 4405B000 */  mfc1      $a1, $f22
/* 7EBB98 80240E88 4406A000 */  mfc1      $a2, $f20
/* 7EBB9C 80240E8C 44071000 */  mfc1      $a3, $f2
/* 7EBBA0 80240E90 0C01C604 */  jal       func_80071810
/* 7EBBA4 80240E94 0000202D */   daddu    $a0, $zero, $zero
/* 7EBBA8 80240E98 0220202D */  daddu     $a0, $s1, $zero
/* 7EBBAC 80240E9C 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBBB0 80240EA0 3C018025 */  lui       $at, %hi(D_80255B94)
/* 7EBBB4 80240EA4 AC225B94 */  sw        $v0, %lo(D_80255B94)($at)
/* 7EBBB8 80240EA8 0C0B1EAF */  jal       get_variable
/* 7EBBBC 80240EAC 34A5D481 */   ori      $a1, $a1, 0xd481
/* 7EBBC0 80240EB0 0220202D */  daddu     $a0, $s1, $zero
/* 7EBBC4 80240EB4 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBBC8 80240EB8 4482B000 */  mtc1      $v0, $f22
/* 7EBBCC 80240EBC 00000000 */  nop
/* 7EBBD0 80240EC0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EBBD4 80240EC4 0C0B1EAF */  jal       get_variable
/* 7EBBD8 80240EC8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 7EBBDC 80240ECC 0220202D */  daddu     $a0, $s1, $zero
/* 7EBBE0 80240ED0 3C05F4AC */  lui       $a1, 0xf4ac
/* 7EBBE4 80240ED4 4482A000 */  mtc1      $v0, $f20
/* 7EBBE8 80240ED8 00000000 */  nop
/* 7EBBEC 80240EDC 4680A520 */  cvt.s.w   $f20, $f20
/* 7EBBF0 80240EE0 0C0B1EAF */  jal       get_variable
/* 7EBBF4 80240EE4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 7EBBF8 80240EE8 44821000 */  mtc1      $v0, $f2
/* 7EBBFC 80240EEC 00000000 */  nop
/* 7EBC00 80240EF0 468010A0 */  cvt.s.w   $f2, $f2
/* 7EBC04 80240EF4 4405B000 */  mfc1      $a1, $f22
/* 7EBC08 80240EF8 4406A000 */  mfc1      $a2, $f20
/* 7EBC0C 80240EFC 3C013F80 */  lui       $at, 0x3f80
/* 7EBC10 80240F00 44810000 */  mtc1      $at, $f0
/* 7EBC14 80240F04 44071000 */  mfc1      $a3, $f2
/* 7EBC18 80240F08 0000202D */  daddu     $a0, $zero, $zero
/* 7EBC1C 80240F0C AFA00014 */  sw        $zero, 0x14($sp)
/* 7EBC20 80240F10 0C01CA24 */  jal       func_80072890
/* 7EBC24 80240F14 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7EBC28 80240F18 8E030000 */  lw        $v1, ($s0)
/* 7EBC2C 80240F1C 8C64000C */  lw        $a0, 0xc($v1)
/* 7EBC30 80240F20 3C018025 */  lui       $at, %hi(D_80255B98)
/* 7EBC34 80240F24 AC225B98 */  sw        $v0, %lo(D_80255B98)($at)
/* 7EBC38 80240F28 AC800018 */  sw        $zero, 0x18($a0)
/* 7EBC3C 80240F2C AC800020 */  sw        $zero, 0x20($a0)
/* 7EBC40 80240F30 AC800024 */  sw        $zero, 0x24($a0)
/* 7EBC44 80240F34 AC800028 */  sw        $zero, 0x28($a0)
/* 7EBC48 80240F38 AC80001C */  sw        $zero, 0x1c($a0)
.L80240F3C:
/* 7EBC4C 80240F3C 3C028025 */  lui       $v0, %hi(D_80255B90)
/* 7EBC50 80240F40 8C425B90 */  lw        $v0, %lo(D_80255B90)($v0)
/* 7EBC54 80240F44 8C44000C */  lw        $a0, 0xc($v0)
/* 7EBC58 80240F48 8C820020 */  lw        $v0, 0x20($a0)
/* 7EBC5C 80240F4C 8C830028 */  lw        $v1, 0x28($a0)
/* 7EBC60 80240F50 2442000A */  addiu     $v0, $v0, 0xa
/* 7EBC64 80240F54 AC820020 */  sw        $v0, 0x20($a0)
/* 7EBC68 80240F58 8C820024 */  lw        $v0, 0x24($a0)
/* 7EBC6C 80240F5C 2463000A */  addiu     $v1, $v1, 0xa
/* 7EBC70 80240F60 AC830028 */  sw        $v1, 0x28($a0)
/* 7EBC74 80240F64 8C830018 */  lw        $v1, 0x18($a0)
/* 7EBC78 80240F68 2442000A */  addiu     $v0, $v0, 0xa
/* 7EBC7C 80240F6C AC820024 */  sw        $v0, 0x24($a0)
/* 7EBC80 80240F70 8C82001C */  lw        $v0, 0x1c($a0)
/* 7EBC84 80240F74 2463000A */  addiu     $v1, $v1, 0xa
/* 7EBC88 80240F78 AC830018 */  sw        $v1, 0x18($a0)
/* 7EBC8C 80240F7C 286300FF */  slti      $v1, $v1, 0xff
/* 7EBC90 80240F80 2442000A */  addiu     $v0, $v0, 0xa
/* 7EBC94 80240F84 AC82001C */  sw        $v0, 0x1c($a0)
/* 7EBC98 80240F88 14600004 */  bnez      $v1, .L80240F9C
/* 7EBC9C 80240F8C 0000102D */   daddu    $v0, $zero, $zero
/* 7EBCA0 80240F90 240200FF */  addiu     $v0, $zero, 0xff
/* 7EBCA4 80240F94 AC820018 */  sw        $v0, 0x18($a0)
/* 7EBCA8 80240F98 24020002 */  addiu     $v0, $zero, 2
.L80240F9C:
/* 7EBCAC 80240F9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7EBCB0 80240FA0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7EBCB4 80240FA4 8FB00018 */  lw        $s0, 0x18($sp)
/* 7EBCB8 80240FA8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 7EBCBC 80240FAC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 7EBCC0 80240FB0 03E00008 */  jr        $ra
/* 7EBCC4 80240FB4 27BD0038 */   addiu    $sp, $sp, 0x38
