.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F40_D3B510
/* D3B510 80240F40 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D3B514 80240F44 AFB1001C */  sw        $s1, 0x1c($sp)
/* D3B518 80240F48 AFBF0020 */  sw        $ra, 0x20($sp)
/* D3B51C 80240F4C AFB00018 */  sw        $s0, 0x18($sp)
/* D3B520 80240F50 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D3B524 80240F54 F7B40028 */  sdc1      $f20, 0x28($sp)
/* D3B528 80240F58 10A00060 */  beqz      $a1, .L802410DC
/* D3B52C 80240F5C 0080882D */   daddu    $s1, $a0, $zero
/* D3B530 80240F60 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B534 80240F64 0C0B1EAF */  jal       get_variable
/* D3B538 80240F68 34A5D481 */   ori      $a1, $a1, 0xd481
/* D3B53C 80240F6C 0220202D */  daddu     $a0, $s1, $zero
/* D3B540 80240F70 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B544 80240F74 4482B000 */  mtc1      $v0, $f22
/* D3B548 80240F78 00000000 */  nop
/* D3B54C 80240F7C 4680B5A0 */  cvt.s.w   $f22, $f22
/* D3B550 80240F80 0C0B1EAF */  jal       get_variable
/* D3B554 80240F84 34A5D482 */   ori      $a1, $a1, 0xd482
/* D3B558 80240F88 0220202D */  daddu     $a0, $s1, $zero
/* D3B55C 80240F8C 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B560 80240F90 4482A000 */  mtc1      $v0, $f20
/* D3B564 80240F94 00000000 */  nop
/* D3B568 80240F98 4680A520 */  cvt.s.w   $f20, $f20
/* D3B56C 80240F9C 0C0B1EAF */  jal       get_variable
/* D3B570 80240FA0 34A5D483 */   ori      $a1, $a1, 0xd483
/* D3B574 80240FA4 44821000 */  mtc1      $v0, $f2
/* D3B578 80240FA8 00000000 */  nop
/* D3B57C 80240FAC 468010A0 */  cvt.s.w   $f2, $f2
/* D3B580 80240FB0 4405B000 */  mfc1      $a1, $f22
/* D3B584 80240FB4 4406A000 */  mfc1      $a2, $f20
/* D3B588 80240FB8 44071000 */  mfc1      $a3, $f2
/* D3B58C 80240FBC 0C01C574 */  jal       func_800715D0
/* D3B590 80240FC0 0000202D */   daddu    $a0, $zero, $zero
/* D3B594 80240FC4 0220202D */  daddu     $a0, $s1, $zero
/* D3B598 80240FC8 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B59C 80240FCC 34A5D481 */  ori       $a1, $a1, 0xd481
/* D3B5A0 80240FD0 3C108025 */  lui       $s0, %hi(D_80251470)
/* D3B5A4 80240FD4 26101470 */  addiu     $s0, $s0, %lo(D_80251470)
/* D3B5A8 80240FD8 0C0B1EAF */  jal       get_variable
/* D3B5AC 80240FDC AE020000 */   sw       $v0, ($s0)
/* D3B5B0 80240FE0 0220202D */  daddu     $a0, $s1, $zero
/* D3B5B4 80240FE4 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B5B8 80240FE8 4482B000 */  mtc1      $v0, $f22
/* D3B5BC 80240FEC 00000000 */  nop
/* D3B5C0 80240FF0 4680B5A0 */  cvt.s.w   $f22, $f22
/* D3B5C4 80240FF4 0C0B1EAF */  jal       get_variable
/* D3B5C8 80240FF8 34A5D482 */   ori      $a1, $a1, 0xd482
/* D3B5CC 80240FFC 0220202D */  daddu     $a0, $s1, $zero
/* D3B5D0 80241000 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B5D4 80241004 4482A000 */  mtc1      $v0, $f20
/* D3B5D8 80241008 00000000 */  nop
/* D3B5DC 8024100C 4680A520 */  cvt.s.w   $f20, $f20
/* D3B5E0 80241010 0C0B1EAF */  jal       get_variable
/* D3B5E4 80241014 34A5D483 */   ori      $a1, $a1, 0xd483
/* D3B5E8 80241018 44821000 */  mtc1      $v0, $f2
/* D3B5EC 8024101C 00000000 */  nop
/* D3B5F0 80241020 468010A0 */  cvt.s.w   $f2, $f2
/* D3B5F4 80241024 4405B000 */  mfc1      $a1, $f22
/* D3B5F8 80241028 4406A000 */  mfc1      $a2, $f20
/* D3B5FC 8024102C 44071000 */  mfc1      $a3, $f2
/* D3B600 80241030 0C01C604 */  jal       func_80071810
/* D3B604 80241034 0000202D */   daddu    $a0, $zero, $zero
/* D3B608 80241038 0220202D */  daddu     $a0, $s1, $zero
/* D3B60C 8024103C 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B610 80241040 3C018025 */  lui       $at, %hi(func_80251474)
/* D3B614 80241044 AC221474 */  sw        $v0, %lo(func_80251474)($at)
/* D3B618 80241048 0C0B1EAF */  jal       get_variable
/* D3B61C 8024104C 34A5D481 */   ori      $a1, $a1, 0xd481
/* D3B620 80241050 0220202D */  daddu     $a0, $s1, $zero
/* D3B624 80241054 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B628 80241058 4482B000 */  mtc1      $v0, $f22
/* D3B62C 8024105C 00000000 */  nop
/* D3B630 80241060 4680B5A0 */  cvt.s.w   $f22, $f22
/* D3B634 80241064 0C0B1EAF */  jal       get_variable
/* D3B638 80241068 34A5D482 */   ori      $a1, $a1, 0xd482
/* D3B63C 8024106C 0220202D */  daddu     $a0, $s1, $zero
/* D3B640 80241070 3C05F4AC */  lui       $a1, 0xf4ac
/* D3B644 80241074 4482A000 */  mtc1      $v0, $f20
/* D3B648 80241078 00000000 */  nop
/* D3B64C 8024107C 4680A520 */  cvt.s.w   $f20, $f20
/* D3B650 80241080 0C0B1EAF */  jal       get_variable
/* D3B654 80241084 34A5D483 */   ori      $a1, $a1, 0xd483
/* D3B658 80241088 44821000 */  mtc1      $v0, $f2
/* D3B65C 8024108C 00000000 */  nop
/* D3B660 80241090 468010A0 */  cvt.s.w   $f2, $f2
/* D3B664 80241094 4405B000 */  mfc1      $a1, $f22
/* D3B668 80241098 4406A000 */  mfc1      $a2, $f20
/* D3B66C 8024109C 3C013F80 */  lui       $at, 0x3f80
/* D3B670 802410A0 44810000 */  mtc1      $at, $f0
/* D3B674 802410A4 44071000 */  mfc1      $a3, $f2
/* D3B678 802410A8 0000202D */  daddu     $a0, $zero, $zero
/* D3B67C 802410AC AFA00014 */  sw        $zero, 0x14($sp)
/* D3B680 802410B0 0C01CA24 */  jal       func_80072890
/* D3B684 802410B4 E7A00010 */   swc1     $f0, 0x10($sp)
/* D3B688 802410B8 8E030000 */  lw        $v1, ($s0)
/* D3B68C 802410BC 8C64000C */  lw        $a0, 0xc($v1)
/* D3B690 802410C0 3C018025 */  lui       $at, %hi(D_80251478)
/* D3B694 802410C4 AC221478 */  sw        $v0, %lo(D_80251478)($at)
/* D3B698 802410C8 AC800018 */  sw        $zero, 0x18($a0)
/* D3B69C 802410CC AC800020 */  sw        $zero, 0x20($a0)
/* D3B6A0 802410D0 AC800024 */  sw        $zero, 0x24($a0)
/* D3B6A4 802410D4 AC800028 */  sw        $zero, 0x28($a0)
/* D3B6A8 802410D8 AC80001C */  sw        $zero, 0x1c($a0)
.L802410DC:
/* D3B6AC 802410DC 3C028025 */  lui       $v0, %hi(D_80251470)
/* D3B6B0 802410E0 8C421470 */  lw        $v0, %lo(D_80251470)($v0)
/* D3B6B4 802410E4 8C44000C */  lw        $a0, 0xc($v0)
/* D3B6B8 802410E8 8C820020 */  lw        $v0, 0x20($a0)
/* D3B6BC 802410EC 8C830028 */  lw        $v1, 0x28($a0)
/* D3B6C0 802410F0 2442000A */  addiu     $v0, $v0, 0xa
/* D3B6C4 802410F4 AC820020 */  sw        $v0, 0x20($a0)
/* D3B6C8 802410F8 8C820024 */  lw        $v0, 0x24($a0)
/* D3B6CC 802410FC 2463000A */  addiu     $v1, $v1, 0xa
/* D3B6D0 80241100 AC830028 */  sw        $v1, 0x28($a0)
/* D3B6D4 80241104 8C830018 */  lw        $v1, 0x18($a0)
/* D3B6D8 80241108 2442000A */  addiu     $v0, $v0, 0xa
/* D3B6DC 8024110C AC820024 */  sw        $v0, 0x24($a0)
/* D3B6E0 80241110 8C82001C */  lw        $v0, 0x1c($a0)
/* D3B6E4 80241114 2463000A */  addiu     $v1, $v1, 0xa
/* D3B6E8 80241118 AC830018 */  sw        $v1, 0x18($a0)
/* D3B6EC 8024111C 286300FF */  slti      $v1, $v1, 0xff
/* D3B6F0 80241120 2442000A */  addiu     $v0, $v0, 0xa
/* D3B6F4 80241124 AC82001C */  sw        $v0, 0x1c($a0)
/* D3B6F8 80241128 14600004 */  bnez      $v1, .L8024113C
/* D3B6FC 8024112C 0000102D */   daddu    $v0, $zero, $zero
/* D3B700 80241130 240200FF */  addiu     $v0, $zero, 0xff
/* D3B704 80241134 AC820018 */  sw        $v0, 0x18($a0)
/* D3B708 80241138 24020002 */  addiu     $v0, $zero, 2
.L8024113C:
/* D3B70C 8024113C 8FBF0020 */  lw        $ra, 0x20($sp)
/* D3B710 80241140 8FB1001C */  lw        $s1, 0x1c($sp)
/* D3B714 80241144 8FB00018 */  lw        $s0, 0x18($sp)
/* D3B718 80241148 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D3B71C 8024114C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D3B720 80241150 03E00008 */  jr        $ra
/* D3B724 80241154 27BD0038 */   addiu    $sp, $sp, 0x38
