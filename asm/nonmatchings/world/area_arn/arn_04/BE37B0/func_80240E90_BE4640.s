.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_BE4640
/* BE4640 80240E90 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BE4644 80240E94 AFB3002C */  sw        $s3, 0x2c($sp)
/* BE4648 80240E98 0080982D */  daddu     $s3, $a0, $zero
/* BE464C 80240E9C AFBF0030 */  sw        $ra, 0x30($sp)
/* BE4650 80240EA0 AFB20028 */  sw        $s2, 0x28($sp)
/* BE4654 80240EA4 AFB10024 */  sw        $s1, 0x24($sp)
/* BE4658 80240EA8 AFB00020 */  sw        $s0, 0x20($sp)
/* BE465C 80240EAC 8E710148 */  lw        $s1, 0x148($s3)
/* BE4660 80240EB0 86240008 */  lh        $a0, 8($s1)
/* BE4664 80240EB4 0C00EABB */  jal       get_npc_unsafe
/* BE4668 80240EB8 00A0902D */   daddu    $s2, $a1, $zero
/* BE466C 80240EBC 8E440004 */  lw        $a0, 4($s2)
/* BE4670 80240EC0 0040802D */  daddu     $s0, $v0, $zero
/* BE4674 80240EC4 00041FC2 */  srl       $v1, $a0, 0x1f
/* BE4678 80240EC8 00832021 */  addu      $a0, $a0, $v1
/* BE467C 80240ECC 00042043 */  sra       $a0, $a0, 1
/* BE4680 80240ED0 0C00A67F */  jal       rand_int
/* BE4684 80240ED4 24840001 */   addiu    $a0, $a0, 1
/* BE4688 80240ED8 8E430004 */  lw        $v1, 4($s2)
/* BE468C 80240EDC 000327C2 */  srl       $a0, $v1, 0x1f
/* BE4690 80240EE0 00641821 */  addu      $v1, $v1, $a0
/* BE4694 80240EE4 00031843 */  sra       $v1, $v1, 1
/* BE4698 80240EE8 00621821 */  addu      $v1, $v1, $v0
/* BE469C 80240EEC A603008E */  sh        $v1, 0x8e($s0)
/* BE46A0 80240EF0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE46A4 80240EF4 C6000040 */  lwc1      $f0, 0x40($s0)
/* BE46A8 80240EF8 C4640000 */  lwc1      $f4, ($v1)
/* BE46AC 80240EFC 46802120 */  cvt.s.w   $f4, $f4
/* BE46B0 80240F00 C4620008 */  lwc1      $f2, 8($v1)
/* BE46B4 80240F04 468010A0 */  cvt.s.w   $f2, $f2
/* BE46B8 80240F08 E7A00010 */  swc1      $f0, 0x10($sp)
/* BE46BC 80240F0C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE46C0 80240F10 44061000 */  mfc1      $a2, $f2
/* BE46C4 80240F14 C440000C */  lwc1      $f0, 0xc($v0)
/* BE46C8 80240F18 46800020 */  cvt.s.w   $f0, $f0
/* BE46CC 80240F1C E7A00014 */  swc1      $f0, 0x14($sp)
/* BE46D0 80240F20 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE46D4 80240F24 44052000 */  mfc1      $a1, $f4
/* BE46D8 80240F28 C4400010 */  lwc1      $f0, 0x10($v0)
/* BE46DC 80240F2C 46800020 */  cvt.s.w   $f0, $f0
/* BE46E0 80240F30 E7A00018 */  swc1      $f0, 0x18($sp)
/* BE46E4 80240F34 8C640018 */  lw        $a0, 0x18($v1)
/* BE46E8 80240F38 0C0123F5 */  jal       is_point_within_region
/* BE46EC 80240F3C 8E070038 */   lw       $a3, 0x38($s0)
/* BE46F0 80240F40 1040000E */  beqz      $v0, .L80240F7C
/* BE46F4 80240F44 00000000 */   nop      
/* BE46F8 80240F48 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE46FC 80240F4C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE4700 80240F50 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE4704 80240F54 C4460000 */  lwc1      $f6, ($v0)
/* BE4708 80240F58 468031A0 */  cvt.s.w   $f6, $f6
/* BE470C 80240F5C 44063000 */  mfc1      $a2, $f6
/* BE4710 80240F60 C4460008 */  lwc1      $f6, 8($v0)
/* BE4714 80240F64 468031A0 */  cvt.s.w   $f6, $f6
/* BE4718 80240F68 44073000 */  mfc1      $a3, $f6
/* BE471C 80240F6C 0C00A720 */  jal       atan2
/* BE4720 80240F70 00000000 */   nop      
/* BE4724 80240F74 080903EB */  j         .L80240FAC
/* BE4728 80240F78 E600000C */   swc1     $f0, 0xc($s0)
.L80240F7C:
/* BE472C 80240F7C 0C00A67F */  jal       rand_int
/* BE4730 80240F80 2404003C */   addiu    $a0, $zero, 0x3c
/* BE4734 80240F84 C60C000C */  lwc1      $f12, 0xc($s0)
/* BE4738 80240F88 44820000 */  mtc1      $v0, $f0
/* BE473C 80240F8C 00000000 */  nop       
/* BE4740 80240F90 46800020 */  cvt.s.w   $f0, $f0
/* BE4744 80240F94 46006300 */  add.s     $f12, $f12, $f0
/* BE4748 80240F98 3C0141F0 */  lui       $at, 0x41f0
/* BE474C 80240F9C 44810000 */  mtc1      $at, $f0
/* BE4750 80240FA0 0C00A6C9 */  jal       clamp_angle
/* BE4754 80240FA4 46006301 */   sub.s    $f12, $f12, $f0
/* BE4758 80240FA8 E600000C */  swc1      $f0, 0xc($s0)
.L80240FAC:
/* BE475C 80240FAC 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE4760 80240FB0 8C420004 */  lw        $v0, 4($v0)
/* BE4764 80240FB4 AE020028 */  sw        $v0, 0x28($s0)
/* BE4768 80240FB8 AE600074 */  sw        $zero, 0x74($s3)
/* BE476C 80240FBC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE4770 80240FC0 8C420014 */  lw        $v0, 0x14($v0)
/* BE4774 80240FC4 04410004 */  bgez      $v0, .L80240FD8
/* BE4778 80240FC8 00000000 */   nop      
/* BE477C 80240FCC C6400000 */  lwc1      $f0, ($s2)
/* BE4780 80240FD0 080903FE */  j         .L80240FF8
/* BE4784 80240FD4 E6000018 */   swc1     $f0, 0x18($s0)
.L80240FD8:
/* BE4788 80240FD8 3C018024 */  lui       $at, 0x8024
/* BE478C 80240FDC D42242D0 */  ldc1      $f2, 0x42d0($at)
/* BE4790 80240FE0 44820000 */  mtc1      $v0, $f0
/* BE4794 80240FE4 00000000 */  nop       
/* BE4798 80240FE8 46800021 */  cvt.d.w   $f0, $f0
/* BE479C 80240FEC 46220003 */  div.d     $f0, $f0, $f2
/* BE47A0 80240FF0 46200020 */  cvt.s.d   $f0, $f0
/* BE47A4 80240FF4 E6000018 */  swc1      $f0, 0x18($s0)
.L80240FF8:
/* BE47A8 80240FF8 C600003C */  lwc1      $f0, 0x3c($s0)
/* BE47AC 80240FFC 3C014059 */  lui       $at, 0x4059
/* BE47B0 80241000 44811800 */  mtc1      $at, $f3
/* BE47B4 80241004 44801000 */  mtc1      $zero, $f2
/* BE47B8 80241008 46000021 */  cvt.d.s   $f0, $f0
/* BE47BC 8024100C 46220002 */  mul.d     $f0, $f0, $f2
/* BE47C0 80241010 00000000 */  nop       
/* BE47C4 80241014 24020001 */  addiu     $v0, $zero, 1
/* BE47C8 80241018 4620018D */  trunc.w.d $f6, $f0
/* BE47CC 8024101C E626007C */  swc1      $f6, 0x7c($s1)
/* BE47D0 80241020 AE620070 */  sw        $v0, 0x70($s3)
/* BE47D4 80241024 8FBF0030 */  lw        $ra, 0x30($sp)
/* BE47D8 80241028 8FB3002C */  lw        $s3, 0x2c($sp)
/* BE47DC 8024102C 8FB20028 */  lw        $s2, 0x28($sp)
/* BE47E0 80241030 8FB10024 */  lw        $s1, 0x24($sp)
/* BE47E4 80241034 8FB00020 */  lw        $s0, 0x20($sp)
/* BE47E8 80241038 03E00008 */  jr        $ra
/* BE47EC 8024103C 27BD0038 */   addiu    $sp, $sp, 0x38
