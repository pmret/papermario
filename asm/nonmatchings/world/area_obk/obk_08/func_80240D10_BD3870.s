.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D10_BD4580
/* BD4580 80240D10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BD4584 80240D14 AFB20020 */  sw        $s2, 0x20($sp)
/* BD4588 80240D18 0080902D */  daddu     $s2, $a0, $zero
/* BD458C 80240D1C AFBF0028 */  sw        $ra, 0x28($sp)
/* BD4590 80240D20 AFB30024 */  sw        $s3, 0x24($sp)
/* BD4594 80240D24 AFB1001C */  sw        $s1, 0x1c($sp)
/* BD4598 80240D28 AFB00018 */  sw        $s0, 0x18($sp)
/* BD459C 80240D2C F7B40030 */  sdc1      $f20, 0x30($sp)
/* BD45A0 80240D30 0C00EABB */  jal       get_npc_unsafe
/* BD45A4 80240D34 8E44014C */   lw       $a0, 0x14c($s2)
/* BD45A8 80240D38 0040802D */  daddu     $s0, $v0, $zero
/* BD45AC 80240D3C 8E430074 */  lw        $v1, 0x74($s2)
/* BD45B0 80240D40 8E110020 */  lw        $s1, 0x20($s0)
/* BD45B4 80240D44 2C62000E */  sltiu     $v0, $v1, 0xe
/* BD45B8 80240D48 8E330020 */  lw        $s3, 0x20($s1)
/* BD45BC 80240D4C 10400099 */  beqz      $v0, .L80240FB4
/* BD45C0 80240D50 00031080 */   sll      $v0, $v1, 2
/* BD45C4 80240D54 3C018024 */  lui       $at, 0x8024
/* BD45C8 80240D58 00220821 */  addu      $at, $at, $v0
/* BD45CC 80240D5C 8C226F00 */  lw        $v0, 0x6f00($at)
/* BD45D0 80240D60 00400008 */  jr        $v0
/* BD45D4 80240D64 00000000 */   nop      
/* BD45D8 80240D68 C620000C */  lwc1      $f0, 0xc($s1)
/* BD45DC 80240D6C C64C0078 */  lwc1      $f12, 0x78($s2)
/* BD45E0 80240D70 46806320 */  cvt.s.w   $f12, $f12
/* BD45E4 80240D74 0C00A6C9 */  jal       clamp_angle
/* BD45E8 80240D78 46006300 */   add.s    $f12, $f12, $f0
/* BD45EC 80240D7C E600000C */  swc1      $f0, 0xc($s0)
/* BD45F0 80240D80 8E630000 */  lw        $v1, ($s3)
/* BD45F4 80240D84 24020001 */  addiu     $v0, $zero, 1
/* BD45F8 80240D88 1462008A */  bne       $v1, $v0, .L80240FB4
/* BD45FC 80240D8C 24040014 */   addiu    $a0, $zero, 0x14
/* BD4600 80240D90 0C00A67F */  jal       rand_int
/* BD4604 80240D94 AE430074 */   sw       $v1, 0x74($s2)
/* BD4608 80240D98 2442000A */  addiu     $v0, $v0, 0xa
/* BD460C 80240D9C 080903ED */  j         .L80240FB4
/* BD4610 80240DA0 A602008E */   sh       $v0, 0x8e($s0)
/* BD4614 80240DA4 C620000C */  lwc1      $f0, 0xc($s1)
/* BD4618 80240DA8 C64C0078 */  lwc1      $f12, 0x78($s2)
/* BD461C 80240DAC 46806320 */  cvt.s.w   $f12, $f12
/* BD4620 80240DB0 0C00A6C9 */  jal       clamp_angle
/* BD4624 80240DB4 46006300 */   add.s    $f12, $f12, $f0
/* BD4628 80240DB8 9602008E */  lhu       $v0, 0x8e($s0)
/* BD462C 80240DBC E600000C */  swc1      $f0, 0xc($s0)
/* BD4630 80240DC0 2442FFFF */  addiu     $v0, $v0, -1
/* BD4634 80240DC4 A602008E */  sh        $v0, 0x8e($s0)
/* BD4638 80240DC8 00021400 */  sll       $v0, $v0, 0x10
/* BD463C 80240DCC 14400079 */  bnez      $v0, .L80240FB4
/* BD4640 80240DD0 3C04B000 */   lui      $a0, 0xb000
/* BD4644 80240DD4 C6000040 */  lwc1      $f0, 0x40($s0)
/* BD4648 80240DD8 3484000F */  ori       $a0, $a0, 0xf
/* BD464C 80240DDC E7A00010 */  swc1      $f0, 0x10($sp)
/* BD4650 80240DE0 8E060038 */  lw        $a2, 0x38($s0)
/* BD4654 80240DE4 8E07003C */  lw        $a3, 0x3c($s0)
/* BD4658 80240DE8 0C052757 */  jal       play_sound_at_position
/* BD465C 80240DEC 0000282D */   daddu    $a1, $zero, $zero
/* BD4660 80240DF0 24020002 */  addiu     $v0, $zero, 2
/* BD4664 80240DF4 AE420074 */  sw        $v0, 0x74($s2)
/* BD4668 80240DF8 C6000038 */  lwc1      $f0, 0x38($s0)
/* BD466C 80240DFC C602003C */  lwc1      $f2, 0x3c($s0)
/* BD4670 80240E00 C6040040 */  lwc1      $f4, 0x40($s0)
/* BD4674 80240E04 A600008E */  sh        $zero, 0x8e($s0)
/* BD4678 80240E08 E6000060 */  swc1      $f0, 0x60($s0)
/* BD467C 80240E0C E6020064 */  swc1      $f2, 0x64($s0)
/* BD4680 80240E10 080903ED */  j         .L80240FB4
/* BD4684 80240E14 E6040068 */   swc1     $f4, 0x68($s0)
/* BD4688 80240E18 C620000C */  lwc1      $f0, 0xc($s1)
/* BD468C 80240E1C C64C0078 */  lwc1      $f12, 0x78($s2)
/* BD4690 80240E20 46806320 */  cvt.s.w   $f12, $f12
/* BD4694 80240E24 0C00A6C9 */  jal       clamp_angle
/* BD4698 80240E28 46006300 */   add.s    $f12, $f12, $f0
/* BD469C 80240E2C 46000506 */  mov.s     $f20, $f0
/* BD46A0 80240E30 4406A000 */  mfc1      $a2, $f20
/* BD46A4 80240E34 00000000 */  nop       
/* BD46A8 80240E38 AE06000C */  sw        $a2, 0xc($s0)
/* BD46AC 80240E3C C6200038 */  lwc1      $f0, 0x38($s1)
/* BD46B0 80240E40 E6000038 */  swc1      $f0, 0x38($s0)
/* BD46B4 80240E44 C6200040 */  lwc1      $f0, 0x40($s1)
/* BD46B8 80240E48 E6000040 */  swc1      $f0, 0x40($s0)
/* BD46BC 80240E4C 8E250010 */  lw        $a1, 0x10($s1)
/* BD46C0 80240E50 0C00EA95 */  jal       npc_move_heading
/* BD46C4 80240E54 0200202D */   daddu    $a0, $s0, $zero
/* BD46C8 80240E58 8602008E */  lh        $v0, 0x8e($s0)
/* BD46CC 80240E5C 3C014220 */  lui       $at, 0x4220
/* BD46D0 80240E60 44817000 */  mtc1      $at, $f14
/* BD46D4 80240E64 44820000 */  mtc1      $v0, $f0
/* BD46D8 80240E68 00000000 */  nop       
/* BD46DC 80240E6C 46800020 */  cvt.s.w   $f0, $f0
/* BD46E0 80240E70 46007001 */  sub.s     $f0, $f14, $f0
/* BD46E4 80240E74 460E0003 */  div.s     $f0, $f0, $f14
/* BD46E8 80240E78 46000002 */  mul.s     $f0, $f0, $f0
/* BD46EC 80240E7C 00000000 */  nop       
/* BD46F0 80240E80 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BD46F4 80240E84 C6060060 */  lwc1      $f6, 0x60($s0)
/* BD46F8 80240E88 46066181 */  sub.s     $f6, $f12, $f6
/* BD46FC 80240E8C 46003182 */  mul.s     $f6, $f6, $f0
/* BD4700 80240E90 00000000 */  nop       
/* BD4704 80240E94 C60A0040 */  lwc1      $f10, 0x40($s0)
/* BD4708 80240E98 C6080068 */  lwc1      $f8, 0x68($s0)
/* BD470C 80240E9C C624003C */  lwc1      $f4, 0x3c($s1)
/* BD4710 80240EA0 46085201 */  sub.s     $f8, $f10, $f8
/* BD4714 80240EA4 3C01447A */  lui       $at, 0x447a
/* BD4718 80240EA8 44811000 */  mtc1      $at, $f2
/* BD471C 80240EAC 00000000 */  nop       
/* BD4720 80240EB0 46022100 */  add.s     $f4, $f4, $f2
/* BD4724 80240EB4 46004202 */  mul.s     $f8, $f8, $f0
/* BD4728 80240EB8 00000000 */  nop       
/* BD472C 80240EBC E604003C */  swc1      $f4, 0x3c($s0)
/* BD4730 80240EC0 46002006 */  mov.s     $f0, $f4
/* BD4734 80240EC4 C6040064 */  lwc1      $f4, 0x64($s0)
/* BD4738 80240EC8 46040001 */  sub.s     $f0, $f0, $f4
/* BD473C 80240ECC 44821000 */  mtc1      $v0, $f2
/* BD4740 80240ED0 00000000 */  nop       
/* BD4744 80240ED4 468010A0 */  cvt.s.w   $f2, $f2
/* BD4748 80240ED8 46020002 */  mul.s     $f0, $f0, $f2
/* BD474C 80240EDC 00000000 */  nop       
/* BD4750 80240EE0 9602008E */  lhu       $v0, 0x8e($s0)
/* BD4754 80240EE4 24030028 */  addiu     $v1, $zero, 0x28
/* BD4758 80240EE8 24420001 */  addiu     $v0, $v0, 1
/* BD475C 80240EEC 46066301 */  sub.s     $f12, $f12, $f6
/* BD4760 80240EF0 A602008E */  sh        $v0, 0x8e($s0)
/* BD4764 80240EF4 00021400 */  sll       $v0, $v0, 0x10
/* BD4768 80240EF8 46085281 */  sub.s     $f10, $f10, $f8
/* BD476C 80240EFC 00021403 */  sra       $v0, $v0, 0x10
/* BD4770 80240F00 460E0003 */  div.s     $f0, $f0, $f14
/* BD4774 80240F04 46040000 */  add.s     $f0, $f0, $f4
/* BD4778 80240F08 E60C0038 */  swc1      $f12, 0x38($s0)
/* BD477C 80240F0C E60A0040 */  swc1      $f10, 0x40($s0)
/* BD4780 80240F10 14430028 */  bne       $v0, $v1, .L80240FB4
/* BD4784 80240F14 E600003C */   swc1     $f0, 0x3c($s0)
/* BD4788 80240F18 080903EC */  j         .L80240FB0
/* BD478C 80240F1C 2402000A */   addiu    $v0, $zero, 0xa
/* BD4790 80240F20 C620000C */  lwc1      $f0, 0xc($s1)
/* BD4794 80240F24 C64C0078 */  lwc1      $f12, 0x78($s2)
/* BD4798 80240F28 46806320 */  cvt.s.w   $f12, $f12
/* BD479C 80240F2C 0C00A6C9 */  jal       clamp_angle
/* BD47A0 80240F30 46006300 */   add.s    $f12, $f12, $f0
/* BD47A4 80240F34 46000506 */  mov.s     $f20, $f0
/* BD47A8 80240F38 0240202D */  daddu     $a0, $s2, $zero
/* BD47AC 80240F3C 3C05FD05 */  lui       $a1, 0xfd05
/* BD47B0 80240F40 34A50F82 */  ori       $a1, $a1, 0xf82
/* BD47B4 80240F44 0C0B1EAF */  jal       get_variable
/* BD47B8 80240F48 E614000C */   swc1     $f20, 0xc($s0)
/* BD47BC 80240F4C 24030001 */  addiu     $v1, $zero, 1
/* BD47C0 80240F50 14430002 */  bne       $v0, $v1, .L80240F5C
/* BD47C4 80240F54 2402000D */   addiu    $v0, $zero, 0xd
/* BD47C8 80240F58 AE420074 */  sw        $v0, 0x74($s2)
.L80240F5C:
/* BD47CC 80240F5C C6200038 */  lwc1      $f0, 0x38($s1)
/* BD47D0 80240F60 4406A000 */  mfc1      $a2, $f20
/* BD47D4 80240F64 E6000038 */  swc1      $f0, 0x38($s0)
/* BD47D8 80240F68 C6200040 */  lwc1      $f0, 0x40($s1)
/* BD47DC 80240F6C E6000040 */  swc1      $f0, 0x40($s0)
/* BD47E0 80240F70 8E250010 */  lw        $a1, 0x10($s1)
/* BD47E4 80240F74 0C00EA95 */  jal       npc_move_heading
/* BD47E8 80240F78 0200202D */   daddu    $a0, $s0, $zero
/* BD47EC 80240F7C C620003C */  lwc1      $f0, 0x3c($s1)
/* BD47F0 80240F80 3C01447A */  lui       $at, 0x447a
/* BD47F4 80240F84 44811000 */  mtc1      $at, $f2
/* BD47F8 80240F88 00000000 */  nop       
/* BD47FC 80240F8C 46020000 */  add.s     $f0, $f0, $f2
/* BD4800 80240F90 080903ED */  j         .L80240FB4
/* BD4804 80240F94 E600003C */   swc1     $f0, 0x3c($s0)
/* BD4808 80240F98 0240202D */  daddu     $a0, $s2, $zero
/* BD480C 80240F9C 3C05FD05 */  lui       $a1, 0xfd05
/* BD4810 80240FA0 0C0B1EAF */  jal       get_variable
/* BD4814 80240FA4 34A50F82 */   ori      $a1, $a1, 0xf82
/* BD4818 80240FA8 14400002 */  bnez      $v0, .L80240FB4
/* BD481C 80240FAC 2402000A */   addiu    $v0, $zero, 0xa
.L80240FB0:
/* BD4820 80240FB0 AE420074 */  sw        $v0, 0x74($s2)
.L80240FB4:
/* BD4824 80240FB4 8FBF0028 */  lw        $ra, 0x28($sp)
/* BD4828 80240FB8 8FB30024 */  lw        $s3, 0x24($sp)
/* BD482C 80240FBC 8FB20020 */  lw        $s2, 0x20($sp)
/* BD4830 80240FC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* BD4834 80240FC4 8FB00018 */  lw        $s0, 0x18($sp)
/* BD4838 80240FC8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* BD483C 80240FCC 24020002 */  addiu     $v0, $zero, 2
/* BD4840 80240FD0 03E00008 */  jr        $ra
/* BD4844 80240FD4 27BD0038 */   addiu    $sp, $sp, 0x38
