.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D78_C5B4B8
/* C5B4B8 80240D78 27BDFF88 */  addiu     $sp, $sp, -0x78
/* C5B4BC 80240D7C AFB3004C */  sw        $s3, 0x4c($sp)
/* C5B4C0 80240D80 0080982D */  daddu     $s3, $a0, $zero
/* C5B4C4 80240D84 AFBF0054 */  sw        $ra, 0x54($sp)
/* C5B4C8 80240D88 AFB40050 */  sw        $s4, 0x50($sp)
/* C5B4CC 80240D8C AFB20048 */  sw        $s2, 0x48($sp)
/* C5B4D0 80240D90 AFB10044 */  sw        $s1, 0x44($sp)
/* C5B4D4 80240D94 AFB00040 */  sw        $s0, 0x40($sp)
/* C5B4D8 80240D98 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* C5B4DC 80240D9C F7B80068 */  sdc1      $f24, 0x68($sp)
/* C5B4E0 80240DA0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* C5B4E4 80240DA4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* C5B4E8 80240DA8 8E710148 */  lw        $s1, 0x148($s3)
/* C5B4EC 80240DAC 00A0902D */  daddu     $s2, $a1, $zero
/* C5B4F0 80240DB0 86240008 */  lh        $a0, 8($s1)
/* C5B4F4 80240DB4 0C00EABB */  jal       get_npc_unsafe
/* C5B4F8 80240DB8 00C0A02D */   daddu    $s4, $a2, $zero
/* C5B4FC 80240DBC 0040802D */  daddu     $s0, $v0, $zero
/* C5B500 80240DC0 C6200078 */  lwc1      $f0, 0x78($s1)
/* C5B504 80240DC4 46800020 */  cvt.s.w   $f0, $f0
/* C5B508 80240DC8 46000021 */  cvt.d.s   $f0, $f0
/* C5B50C 80240DCC 3C014059 */  lui       $at, 0x4059
/* C5B510 80240DD0 44811800 */  mtc1      $at, $f3
/* C5B514 80240DD4 44801000 */  mtc1      $zero, $f2
/* C5B518 80240DD8 8602008E */  lh        $v0, 0x8e($s0)
/* C5B51C 80240DDC 9603008E */  lhu       $v1, 0x8e($s0)
/* C5B520 80240DE0 46220003 */  div.d     $f0, $f0, $f2
/* C5B524 80240DE4 46200620 */  cvt.s.d   $f24, $f0
/* C5B528 80240DE8 C6200088 */  lwc1      $f0, 0x88($s1)
/* C5B52C 80240DEC 46800020 */  cvt.s.w   $f0, $f0
/* C5B530 80240DF0 46000021 */  cvt.d.s   $f0, $f0
/* C5B534 80240DF4 46220003 */  div.d     $f0, $f0, $f2
/* C5B538 80240DF8 46200020 */  cvt.s.d   $f0, $f0
/* C5B53C 80240DFC 18400003 */  blez      $v0, .L80240E0C
/* C5B540 80240E00 4600C680 */   add.s    $f26, $f24, $f0
/* C5B544 80240E04 2462FFFF */  addiu     $v0, $v1, -1
/* C5B548 80240E08 A602008E */  sh        $v0, 0x8e($s0)
.L80240E0C:
/* C5B54C 80240E0C 8E220070 */  lw        $v0, 0x70($s1)
/* C5B550 80240E10 18400034 */  blez      $v0, .L80240EE4
/* C5B554 80240E14 00000000 */   nop
/* C5B558 80240E18 C62C0074 */  lwc1      $f12, 0x74($s1)
/* C5B55C 80240E1C 46806320 */  cvt.s.w   $f12, $f12
/* C5B560 80240E20 44820000 */  mtc1      $v0, $f0
/* C5B564 80240E24 00000000 */  nop
/* C5B568 80240E28 46800020 */  cvt.s.w   $f0, $f0
/* C5B56C 80240E2C 46000021 */  cvt.d.s   $f0, $f0
/* C5B570 80240E30 46220003 */  div.d     $f0, $f0, $f2
/* C5B574 80240E34 0C00A8BB */  jal       sin_deg
/* C5B578 80240E38 462005A0 */   cvt.s.d  $f22, $f0
/* C5B57C 80240E3C 8E020000 */  lw        $v0, ($s0)
/* C5B580 80240E40 30420008 */  andi      $v0, $v0, 8
/* C5B584 80240E44 10400003 */  beqz      $v0, .L80240E54
/* C5B588 80240E48 46000506 */   mov.s    $f20, $f0
/* C5B58C 80240E4C 080903A5 */  j         .L80240E94
/* C5B590 80240E50 0000102D */   daddu    $v0, $zero, $zero
.L80240E54:
/* C5B594 80240E54 27A50028 */  addiu     $a1, $sp, 0x28
/* C5B598 80240E58 27A6002C */  addiu     $a2, $sp, 0x2c
/* C5B59C 80240E5C C6000038 */  lwc1      $f0, 0x38($s0)
/* C5B5A0 80240E60 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5B5A4 80240E64 C6040040 */  lwc1      $f4, 0x40($s0)
/* C5B5A8 80240E68 3C01447A */  lui       $at, 0x447a
/* C5B5AC 80240E6C 44813000 */  mtc1      $at, $f6
/* C5B5B0 80240E70 27A20034 */  addiu     $v0, $sp, 0x34
/* C5B5B4 80240E74 E7A00028 */  swc1      $f0, 0x28($sp)
/* C5B5B8 80240E78 E7A2002C */  swc1      $f2, 0x2c($sp)
/* C5B5BC 80240E7C E7A40030 */  swc1      $f4, 0x30($sp)
/* C5B5C0 80240E80 E7A60034 */  swc1      $f6, 0x34($sp)
/* C5B5C4 80240E84 AFA20010 */  sw        $v0, 0x10($sp)
/* C5B5C8 80240E88 8E040080 */  lw        $a0, 0x80($s0)
/* C5B5CC 80240E8C 0C0372DF */  jal       func_800DCB7C
/* C5B5D0 80240E90 27A70030 */   addiu    $a3, $sp, 0x30
.L80240E94:
/* C5B5D4 80240E94 10400007 */  beqz      $v0, .L80240EB4
/* C5B5D8 80240E98 00000000 */   nop
/* C5B5DC 80240E9C 4616A082 */  mul.s     $f2, $f20, $f22
/* C5B5E0 80240EA0 00000000 */  nop
/* C5B5E4 80240EA4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C5B5E8 80240EA8 46180000 */  add.s     $f0, $f0, $f24
/* C5B5EC 80240EAC 080903B0 */  j         .L80240EC0
/* C5B5F0 80240EB0 46020000 */   add.s    $f0, $f0, $f2
.L80240EB4:
/* C5B5F4 80240EB4 4616A002 */  mul.s     $f0, $f20, $f22
/* C5B5F8 80240EB8 00000000 */  nop
/* C5B5FC 80240EBC 4600D000 */  add.s     $f0, $f26, $f0
.L80240EC0:
/* C5B600 80240EC0 E600003C */  swc1      $f0, 0x3c($s0)
/* C5B604 80240EC4 8E220074 */  lw        $v0, 0x74($s1)
/* C5B608 80240EC8 2442000A */  addiu     $v0, $v0, 0xa
/* C5B60C 80240ECC 44826000 */  mtc1      $v0, $f12
/* C5B610 80240ED0 00000000 */  nop
/* C5B614 80240ED4 0C00A6C9 */  jal       clamp_angle
/* C5B618 80240ED8 46806320 */   cvt.s.w  $f12, $f12
/* C5B61C 80240EDC 4600020D */  trunc.w.s $f8, $f0
/* C5B620 80240EE0 E6280074 */  swc1      $f8, 0x74($s1)
.L80240EE4:
/* C5B624 80240EE4 8E220090 */  lw        $v0, 0x90($s1)
/* C5B628 80240EE8 1C400040 */  bgtz      $v0, .L80240FEC
/* C5B62C 80240EEC 2442FFFF */   addiu    $v0, $v0, -1
/* C5B630 80240EF0 860200A8 */  lh        $v0, 0xa8($s0)
/* C5B634 80240EF4 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5B638 80240EF8 44821000 */  mtc1      $v0, $f2
/* C5B63C 80240EFC 00000000 */  nop
/* C5B640 80240F00 468010A0 */  cvt.s.w   $f2, $f2
/* C5B644 80240F04 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5B648 80240F08 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5B64C 80240F0C 46020000 */  add.s     $f0, $f0, $f2
/* C5B650 80240F10 3C014024 */  lui       $at, 0x4024
/* C5B654 80240F14 44812800 */  mtc1      $at, $f5
/* C5B658 80240F18 44802000 */  mtc1      $zero, $f4
/* C5B65C 80240F1C C442002C */  lwc1      $f2, 0x2c($v0)
/* C5B660 80240F20 46000021 */  cvt.d.s   $f0, $f0
/* C5B664 80240F24 46240000 */  add.d     $f0, $f0, $f4
/* C5B668 80240F28 460010A1 */  cvt.d.s   $f2, $f2
/* C5B66C 80240F2C 4620103C */  c.lt.d    $f2, $f0
/* C5B670 80240F30 00000000 */  nop
/* C5B674 80240F34 4500002E */  bc1f      .L80240FF0
/* C5B678 80240F38 0280202D */   daddu    $a0, $s4, $zero
/* C5B67C 80240F3C 24020001 */  addiu     $v0, $zero, 1
/* C5B680 80240F40 AFA20010 */  sw        $v0, 0x10($sp)
/* C5B684 80240F44 8E460024 */  lw        $a2, 0x24($s2)
/* C5B688 80240F48 8E470028 */  lw        $a3, 0x28($s2)
/* C5B68C 80240F4C 0C01242D */  jal       func_800490B4
/* C5B690 80240F50 0220282D */   daddu    $a1, $s1, $zero
/* C5B694 80240F54 10400026 */  beqz      $v0, .L80240FF0
/* C5B698 80240F58 0000202D */   daddu    $a0, $zero, $zero
/* C5B69C 80240F5C 0200282D */  daddu     $a1, $s0, $zero
/* C5B6A0 80240F60 0000302D */  daddu     $a2, $zero, $zero
/* C5B6A4 80240F64 2412000C */  addiu     $s2, $zero, 0xc
/* C5B6A8 80240F68 860300A8 */  lh        $v1, 0xa8($s0)
/* C5B6AC 80240F6C 3C013F80 */  lui       $at, 0x3f80
/* C5B6B0 80240F70 44810000 */  mtc1      $at, $f0
/* C5B6B4 80240F74 3C014000 */  lui       $at, 0x4000
/* C5B6B8 80240F78 44811000 */  mtc1      $at, $f2
/* C5B6BC 80240F7C 3C01C1A0 */  lui       $at, 0xc1a0
/* C5B6C0 80240F80 44812000 */  mtc1      $at, $f4
/* C5B6C4 80240F84 44834000 */  mtc1      $v1, $f8
/* C5B6C8 80240F88 00000000 */  nop
/* C5B6CC 80240F8C 46804220 */  cvt.s.w   $f8, $f8
/* C5B6D0 80240F90 44074000 */  mfc1      $a3, $f8
/* C5B6D4 80240F94 27A20038 */  addiu     $v0, $sp, 0x38
/* C5B6D8 80240F98 AFB2001C */  sw        $s2, 0x1c($sp)
/* C5B6DC 80240F9C AFA20020 */  sw        $v0, 0x20($sp)
/* C5B6E0 80240FA0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5B6E4 80240FA4 E7A20014 */  swc1      $f2, 0x14($sp)
/* C5B6E8 80240FA8 0C01BFA4 */  jal       fx_emote
/* C5B6EC 80240FAC E7A40018 */   swc1     $f4, 0x18($sp)
/* C5B6F0 80240FB0 0200202D */  daddu     $a0, $s0, $zero
/* C5B6F4 80240FB4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C5B6F8 80240FB8 C480003C */  lwc1      $f0, 0x3c($a0)
/* C5B6FC 80240FBC 3C060020 */  lui       $a2, 0x20
/* C5B700 80240FC0 0C012530 */  jal       func_800494C0
/* C5B704 80240FC4 E4800064 */   swc1     $f0, 0x64($a0)
/* C5B708 80240FC8 8E220018 */  lw        $v0, 0x18($s1)
/* C5B70C 80240FCC 9442002A */  lhu       $v0, 0x2a($v0)
/* C5B710 80240FD0 30420001 */  andi      $v0, $v0, 1
/* C5B714 80240FD4 10400003 */  beqz      $v0, .L80240FE4
/* C5B718 80240FD8 2402000A */   addiu    $v0, $zero, 0xa
/* C5B71C 80240FDC 08090423 */  j         .L8024108C
/* C5B720 80240FE0 AE620070 */   sw       $v0, 0x70($s3)
.L80240FE4:
/* C5B724 80240FE4 08090423 */  j         .L8024108C
/* C5B728 80240FE8 AE720070 */   sw       $s2, 0x70($s3)
.L80240FEC:
/* C5B72C 80240FEC AE220090 */  sw        $v0, 0x90($s1)
.L80240FF0:
/* C5B730 80240FF0 8602008C */  lh        $v0, 0x8c($s0)
/* C5B734 80240FF4 14400025 */  bnez      $v0, .L8024108C
/* C5B738 80240FF8 00000000 */   nop
/* C5B73C 80240FFC 8602008E */  lh        $v0, 0x8e($s0)
/* C5B740 80241000 1C400022 */  bgtz      $v0, .L8024108C
/* C5B744 80241004 00000000 */   nop
/* C5B748 80241008 8E620074 */  lw        $v0, 0x74($s3)
/* C5B74C 8024100C 2442FFFF */  addiu     $v0, $v0, -1
/* C5B750 80241010 1840001D */  blez      $v0, .L80241088
/* C5B754 80241014 AE620074 */   sw       $v0, 0x74($s3)
/* C5B758 80241018 8E220018 */  lw        $v0, 0x18($s1)
/* C5B75C 8024101C 9442002A */  lhu       $v0, 0x2a($v0)
/* C5B760 80241020 30420010 */  andi      $v0, $v0, 0x10
/* C5B764 80241024 14400007 */  bnez      $v0, .L80241044
/* C5B768 80241028 00000000 */   nop
/* C5B76C 8024102C C600000C */  lwc1      $f0, 0xc($s0)
/* C5B770 80241030 3C014334 */  lui       $at, 0x4334
/* C5B774 80241034 44816000 */  mtc1      $at, $f12
/* C5B778 80241038 0C00A6C9 */  jal       clamp_angle
/* C5B77C 8024103C 460C0300 */   add.s    $f12, $f0, $f12
/* C5B780 80241040 E600000C */  swc1      $f0, 0xc($s0)
.L80241044:
/* C5B784 80241044 0C00A67F */  jal       rand_int
/* C5B788 80241048 240403E8 */   addiu    $a0, $zero, 0x3e8
/* C5B78C 8024104C 3C032E8B */  lui       $v1, 0x2e8b
/* C5B790 80241050 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* C5B794 80241054 00430018 */  mult      $v0, $v1
/* C5B798 80241058 00021FC3 */  sra       $v1, $v0, 0x1f
/* C5B79C 8024105C 00004010 */  mfhi      $t0
/* C5B7A0 80241060 00082043 */  sra       $a0, $t0, 1
/* C5B7A4 80241064 00832023 */  subu      $a0, $a0, $v1
/* C5B7A8 80241068 00041840 */  sll       $v1, $a0, 1
/* C5B7AC 8024106C 00641821 */  addu      $v1, $v1, $a0
/* C5B7B0 80241070 00031880 */  sll       $v1, $v1, 2
/* C5B7B4 80241074 00641823 */  subu      $v1, $v1, $a0
/* C5B7B8 80241078 00431023 */  subu      $v0, $v0, $v1
/* C5B7BC 8024107C 24420005 */  addiu     $v0, $v0, 5
/* C5B7C0 80241080 08090423 */  j         .L8024108C
/* C5B7C4 80241084 A602008E */   sh       $v0, 0x8e($s0)
.L80241088:
/* C5B7C8 80241088 AE600070 */  sw        $zero, 0x70($s3)
.L8024108C:
/* C5B7CC 8024108C 8FBF0054 */  lw        $ra, 0x54($sp)
/* C5B7D0 80241090 8FB40050 */  lw        $s4, 0x50($sp)
/* C5B7D4 80241094 8FB3004C */  lw        $s3, 0x4c($sp)
/* C5B7D8 80241098 8FB20048 */  lw        $s2, 0x48($sp)
/* C5B7DC 8024109C 8FB10044 */  lw        $s1, 0x44($sp)
/* C5B7E0 802410A0 8FB00040 */  lw        $s0, 0x40($sp)
/* C5B7E4 802410A4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* C5B7E8 802410A8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* C5B7EC 802410AC D7B60060 */  ldc1      $f22, 0x60($sp)
/* C5B7F0 802410B0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* C5B7F4 802410B4 03E00008 */  jr        $ra
/* C5B7F8 802410B8 27BD0078 */   addiu    $sp, $sp, 0x78
