.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E70_CF89E0
/* CF89E0 80240E70 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CF89E4 80240E74 AFB1001C */  sw        $s1, 0x1c($sp)
/* CF89E8 80240E78 AFBF0020 */  sw        $ra, 0x20($sp)
/* CF89EC 80240E7C AFB00018 */  sw        $s0, 0x18($sp)
/* CF89F0 80240E80 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CF89F4 80240E84 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CF89F8 80240E88 10A00060 */  beqz      $a1, .L8024100C
/* CF89FC 80240E8C 0080882D */   daddu    $s1, $a0, $zero
/* CF8A00 80240E90 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8A04 80240E94 0C0B1EAF */  jal       get_variable
/* CF8A08 80240E98 34A5D481 */   ori      $a1, $a1, 0xd481
/* CF8A0C 80240E9C 0220202D */  daddu     $a0, $s1, $zero
/* CF8A10 80240EA0 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8A14 80240EA4 4482B000 */  mtc1      $v0, $f22
/* CF8A18 80240EA8 00000000 */  nop       
/* CF8A1C 80240EAC 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF8A20 80240EB0 0C0B1EAF */  jal       get_variable
/* CF8A24 80240EB4 34A5D482 */   ori      $a1, $a1, 0xd482
/* CF8A28 80240EB8 0220202D */  daddu     $a0, $s1, $zero
/* CF8A2C 80240EBC 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8A30 80240EC0 4482A000 */  mtc1      $v0, $f20
/* CF8A34 80240EC4 00000000 */  nop       
/* CF8A38 80240EC8 4680A520 */  cvt.s.w   $f20, $f20
/* CF8A3C 80240ECC 0C0B1EAF */  jal       get_variable
/* CF8A40 80240ED0 34A5D483 */   ori      $a1, $a1, 0xd483
/* CF8A44 80240ED4 44821000 */  mtc1      $v0, $f2
/* CF8A48 80240ED8 00000000 */  nop       
/* CF8A4C 80240EDC 468010A0 */  cvt.s.w   $f2, $f2
/* CF8A50 80240EE0 4405B000 */  mfc1      $a1, $f22
/* CF8A54 80240EE4 4406A000 */  mfc1      $a2, $f20
/* CF8A58 80240EE8 44071000 */  mfc1      $a3, $f2
/* CF8A5C 80240EEC 0C01C574 */  jal       func_800715D0
/* CF8A60 80240EF0 0000202D */   daddu    $a0, $zero, $zero
/* CF8A64 80240EF4 0220202D */  daddu     $a0, $s1, $zero
/* CF8A68 80240EF8 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8A6C 80240EFC 34A5D481 */  ori       $a1, $a1, 0xd481
/* CF8A70 80240F00 3C108025 */  lui       $s0, %hi(D_8024DF18)
/* CF8A74 80240F04 2610DF18 */  addiu     $s0, $s0, %lo(D_8024DF18)
/* CF8A78 80240F08 0C0B1EAF */  jal       get_variable
/* CF8A7C 80240F0C AE020000 */   sw       $v0, ($s0)
/* CF8A80 80240F10 0220202D */  daddu     $a0, $s1, $zero
/* CF8A84 80240F14 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8A88 80240F18 4482B000 */  mtc1      $v0, $f22
/* CF8A8C 80240F1C 00000000 */  nop       
/* CF8A90 80240F20 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF8A94 80240F24 0C0B1EAF */  jal       get_variable
/* CF8A98 80240F28 34A5D482 */   ori      $a1, $a1, 0xd482
/* CF8A9C 80240F2C 0220202D */  daddu     $a0, $s1, $zero
/* CF8AA0 80240F30 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8AA4 80240F34 4482A000 */  mtc1      $v0, $f20
/* CF8AA8 80240F38 00000000 */  nop       
/* CF8AAC 80240F3C 4680A520 */  cvt.s.w   $f20, $f20
/* CF8AB0 80240F40 0C0B1EAF */  jal       get_variable
/* CF8AB4 80240F44 34A5D483 */   ori      $a1, $a1, 0xd483
/* CF8AB8 80240F48 44821000 */  mtc1      $v0, $f2
/* CF8ABC 80240F4C 00000000 */  nop       
/* CF8AC0 80240F50 468010A0 */  cvt.s.w   $f2, $f2
/* CF8AC4 80240F54 4405B000 */  mfc1      $a1, $f22
/* CF8AC8 80240F58 4406A000 */  mfc1      $a2, $f20
/* CF8ACC 80240F5C 44071000 */  mfc1      $a3, $f2
/* CF8AD0 80240F60 0C01C604 */  jal       func_80071810
/* CF8AD4 80240F64 0000202D */   daddu    $a0, $zero, $zero
/* CF8AD8 80240F68 0220202D */  daddu     $a0, $s1, $zero
/* CF8ADC 80240F6C 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8AE0 80240F70 3C018025 */  lui       $at, %hi(D_8024DF1C)
/* CF8AE4 80240F74 AC22DF1C */  sw        $v0, %lo(D_8024DF1C)($at)
/* CF8AE8 80240F78 0C0B1EAF */  jal       get_variable
/* CF8AEC 80240F7C 34A5D481 */   ori      $a1, $a1, 0xd481
/* CF8AF0 80240F80 0220202D */  daddu     $a0, $s1, $zero
/* CF8AF4 80240F84 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8AF8 80240F88 4482B000 */  mtc1      $v0, $f22
/* CF8AFC 80240F8C 00000000 */  nop       
/* CF8B00 80240F90 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF8B04 80240F94 0C0B1EAF */  jal       get_variable
/* CF8B08 80240F98 34A5D482 */   ori      $a1, $a1, 0xd482
/* CF8B0C 80240F9C 0220202D */  daddu     $a0, $s1, $zero
/* CF8B10 80240FA0 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8B14 80240FA4 4482A000 */  mtc1      $v0, $f20
/* CF8B18 80240FA8 00000000 */  nop       
/* CF8B1C 80240FAC 4680A520 */  cvt.s.w   $f20, $f20
/* CF8B20 80240FB0 0C0B1EAF */  jal       get_variable
/* CF8B24 80240FB4 34A5D483 */   ori      $a1, $a1, 0xd483
/* CF8B28 80240FB8 44821000 */  mtc1      $v0, $f2
/* CF8B2C 80240FBC 00000000 */  nop       
/* CF8B30 80240FC0 468010A0 */  cvt.s.w   $f2, $f2
/* CF8B34 80240FC4 4405B000 */  mfc1      $a1, $f22
/* CF8B38 80240FC8 4406A000 */  mfc1      $a2, $f20
/* CF8B3C 80240FCC 3C013F80 */  lui       $at, 0x3f80
/* CF8B40 80240FD0 44810000 */  mtc1      $at, $f0
/* CF8B44 80240FD4 44071000 */  mfc1      $a3, $f2
/* CF8B48 80240FD8 0000202D */  daddu     $a0, $zero, $zero
/* CF8B4C 80240FDC AFA00014 */  sw        $zero, 0x14($sp)
/* CF8B50 80240FE0 0C01CA24 */  jal       func_80072890
/* CF8B54 80240FE4 E7A00010 */   swc1     $f0, 0x10($sp)
/* CF8B58 80240FE8 8E030000 */  lw        $v1, ($s0)
/* CF8B5C 80240FEC 8C64000C */  lw        $a0, 0xc($v1)
/* CF8B60 80240FF0 3C018025 */  lui       $at, %hi(D_8024DF20)
/* CF8B64 80240FF4 AC22DF20 */  sw        $v0, %lo(D_8024DF20)($at)
/* CF8B68 80240FF8 AC800018 */  sw        $zero, 0x18($a0)
/* CF8B6C 80240FFC AC800020 */  sw        $zero, 0x20($a0)
/* CF8B70 80241000 AC800024 */  sw        $zero, 0x24($a0)
/* CF8B74 80241004 AC800028 */  sw        $zero, 0x28($a0)
/* CF8B78 80241008 AC80001C */  sw        $zero, 0x1c($a0)
.L8024100C:
/* CF8B7C 8024100C 3C028025 */  lui       $v0, %hi(D_8024DF18)
/* CF8B80 80241010 8C42DF18 */  lw        $v0, %lo(D_8024DF18)($v0)
/* CF8B84 80241014 8C44000C */  lw        $a0, 0xc($v0)
/* CF8B88 80241018 8C820020 */  lw        $v0, 0x20($a0)
/* CF8B8C 8024101C 8C830028 */  lw        $v1, 0x28($a0)
/* CF8B90 80241020 2442000A */  addiu     $v0, $v0, 0xa
/* CF8B94 80241024 AC820020 */  sw        $v0, 0x20($a0)
/* CF8B98 80241028 8C820024 */  lw        $v0, 0x24($a0)
/* CF8B9C 8024102C 2463000A */  addiu     $v1, $v1, 0xa
/* CF8BA0 80241030 AC830028 */  sw        $v1, 0x28($a0)
/* CF8BA4 80241034 8C830018 */  lw        $v1, 0x18($a0)
/* CF8BA8 80241038 2442000A */  addiu     $v0, $v0, 0xa
/* CF8BAC 8024103C AC820024 */  sw        $v0, 0x24($a0)
/* CF8BB0 80241040 8C82001C */  lw        $v0, 0x1c($a0)
/* CF8BB4 80241044 2463000A */  addiu     $v1, $v1, 0xa
/* CF8BB8 80241048 AC830018 */  sw        $v1, 0x18($a0)
/* CF8BBC 8024104C 286300FF */  slti      $v1, $v1, 0xff
/* CF8BC0 80241050 2442000A */  addiu     $v0, $v0, 0xa
/* CF8BC4 80241054 AC82001C */  sw        $v0, 0x1c($a0)
/* CF8BC8 80241058 14600004 */  bnez      $v1, .L8024106C
/* CF8BCC 8024105C 0000102D */   daddu    $v0, $zero, $zero
/* CF8BD0 80241060 240200FF */  addiu     $v0, $zero, 0xff
/* CF8BD4 80241064 AC820018 */  sw        $v0, 0x18($a0)
/* CF8BD8 80241068 24020002 */  addiu     $v0, $zero, 2
.L8024106C:
/* CF8BDC 8024106C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF8BE0 80241070 8FB1001C */  lw        $s1, 0x1c($sp)
/* CF8BE4 80241074 8FB00018 */  lw        $s0, 0x18($sp)
/* CF8BE8 80241078 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CF8BEC 8024107C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CF8BF0 80241080 03E00008 */  jr        $ra
/* CF8BF4 80241084 27BD0038 */   addiu    $sp, $sp, 0x38
