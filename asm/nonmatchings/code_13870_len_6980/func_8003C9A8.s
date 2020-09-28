.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C9A8
/* 17DA8 8003C9A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 17DAC 8003C9AC AFB00018 */  sw        $s0, 0x18($sp)
/* 17DB0 8003C9B0 0080802D */  daddu     $s0, $a0, $zero
/* 17DB4 8003C9B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17DB8 8003C9B8 00A0882D */  daddu     $s1, $a1, $zero
/* 17DBC 8003C9BC AFB20020 */  sw        $s2, 0x20($sp)
/* 17DC0 8003C9C0 02119021 */  addu      $s2, $s0, $s1
/* 17DC4 8003C9C4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 17DC8 8003C9C8 82430330 */  lb        $v1, 0x330($s2)
/* 17DCC 8003C9CC 10600005 */  beqz      $v1, .L8003C9E4
/* 17DD0 8003C9D0 24020001 */   addiu    $v0, $zero, 1
/* 17DD4 8003C9D4 10620028 */  beq       $v1, $v0, .L8003CA78
/* 17DD8 8003C9D8 00111080 */   sll      $v0, $s1, 2
/* 17DDC 8003C9DC 0800F2C2 */  j         .L8003CB08
/* 17DE0 8003C9E0 00000000 */   nop      
.L8003C9E4:
/* 17DE4 8003C9E4 860200A8 */  lh        $v0, 0xa8($s0)
/* 17DE8 8003C9E8 3C013FE0 */  lui       $at, 0x3fe0
/* 17DEC 8003C9EC 44810800 */  mtc1      $at, $f1
/* 17DF0 8003C9F0 44800000 */  mtc1      $zero, $f0
/* 17DF4 8003C9F4 44822000 */  mtc1      $v0, $f4
/* 17DF8 8003C9F8 00000000 */  nop       
/* 17DFC 8003C9FC 46802121 */  cvt.d.w   $f4, $f4
/* 17E00 8003CA00 46202102 */  mul.d     $f4, $f4, $f0
/* 17E04 8003CA04 00000000 */  nop       
/* 17E08 8003CA08 C6000054 */  lwc1      $f0, 0x54($s0)
/* 17E0C 8003CA0C 3C01800A */  lui       $at, 0x800a
/* 17E10 8003CA10 D4228528 */  ldc1      $f2, -0x7ad8($at)
/* 17E14 8003CA14 46000021 */  cvt.d.s   $f0, $f0
/* 17E18 8003CA18 46220002 */  mul.d     $f0, $f0, $f2
/* 17E1C 8003CA1C 00000000 */  nop       
/* 17E20 8003CA20 3C01800A */  lui       $at, 0x800a
/* 17E24 8003CA24 D4228530 */  ldc1      $f2, -0x7ad0($at)
/* 17E28 8003CA28 46220000 */  add.d     $f0, $f0, $f2
/* 17E2C 8003CA2C C602003C */  lwc1      $f2, 0x3c($s0)
/* 17E30 8003CA30 2402FFFF */  addiu     $v0, $zero, -1
/* 17E34 8003CA34 AFA20014 */  sw        $v0, 0x14($sp)
/* 17E38 8003CA38 460010A1 */  cvt.d.s   $f2, $f2
/* 17E3C 8003CA3C 46241080 */  add.d     $f2, $f2, $f4
/* 17E40 8003CA40 46200020 */  cvt.s.d   $f0, $f0
/* 17E44 8003CA44 E7A00010 */  swc1      $f0, 0x10($sp)
/* 17E48 8003CA48 8E050038 */  lw        $a1, 0x38($s0)
/* 17E4C 8003CA4C 8E070040 */  lw        $a3, 0x40($s0)
/* 17E50 8003CA50 462010A0 */  cvt.s.d   $f2, $f2
/* 17E54 8003CA54 44061000 */  mfc1      $a2, $f2
/* 17E58 8003CA58 0C01C5D4 */  jal       func_80071750
/* 17E5C 8003CA5C 24040002 */   addiu    $a0, $zero, 2
/* 17E60 8003CA60 00111880 */  sll       $v1, $s1, 2
/* 17E64 8003CA64 02031821 */  addu      $v1, $s0, $v1
/* 17E68 8003CA68 AC620324 */  sw        $v0, 0x324($v1)
/* 17E6C 8003CA6C 24020001 */  addiu     $v0, $zero, 1
/* 17E70 8003CA70 0800F2C2 */  j         .L8003CB08
/* 17E74 8003CA74 A2420330 */   sb       $v0, 0x330($s2)
.L8003CA78:
/* 17E78 8003CA78 02021021 */  addu      $v0, $s0, $v0
/* 17E7C 8003CA7C 8C420324 */  lw        $v0, 0x324($v0)
/* 17E80 8003CA80 C6000038 */  lwc1      $f0, 0x38($s0)
/* 17E84 8003CA84 8C43000C */  lw        $v1, 0xc($v0)
/* 17E88 8003CA88 E4600004 */  swc1      $f0, 4($v1)
/* 17E8C 8003CA8C 860200A8 */  lh        $v0, 0xa8($s0)
/* 17E90 8003CA90 3C013FE0 */  lui       $at, 0x3fe0
/* 17E94 8003CA94 44810800 */  mtc1      $at, $f1
/* 17E98 8003CA98 44800000 */  mtc1      $zero, $f0
/* 17E9C 8003CA9C 44821000 */  mtc1      $v0, $f2
/* 17EA0 8003CAA0 00000000 */  nop       
/* 17EA4 8003CAA4 468010A1 */  cvt.d.w   $f2, $f2
/* 17EA8 8003CAA8 46201082 */  mul.d     $f2, $f2, $f0
/* 17EAC 8003CAAC 00000000 */  nop       
/* 17EB0 8003CAB0 C6000054 */  lwc1      $f0, 0x54($s0)
/* 17EB4 8003CAB4 46000021 */  cvt.d.s   $f0, $f0
/* 17EB8 8003CAB8 46201082 */  mul.d     $f2, $f2, $f0
/* 17EBC 8003CABC 00000000 */  nop       
/* 17EC0 8003CAC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* 17EC4 8003CAC4 46000021 */  cvt.d.s   $f0, $f0
/* 17EC8 8003CAC8 46220000 */  add.d     $f0, $f0, $f2
/* 17ECC 8003CACC 46200020 */  cvt.s.d   $f0, $f0
/* 17ED0 8003CAD0 E4600008 */  swc1      $f0, 8($v1)
/* 17ED4 8003CAD4 C6000040 */  lwc1      $f0, 0x40($s0)
/* 17ED8 8003CAD8 E460000C */  swc1      $f0, 0xc($v1)
/* 17EDC 8003CADC C6000054 */  lwc1      $f0, 0x54($s0)
/* 17EE0 8003CAE0 3C01800A */  lui       $at, 0x800a
/* 17EE4 8003CAE4 D4228538 */  ldc1      $f2, -0x7ac8($at)
/* 17EE8 8003CAE8 46000021 */  cvt.d.s   $f0, $f0
/* 17EEC 8003CAEC 46220002 */  mul.d     $f0, $f0, $f2
/* 17EF0 8003CAF0 00000000 */  nop       
/* 17EF4 8003CAF4 3C01800A */  lui       $at, 0x800a
/* 17EF8 8003CAF8 D4228540 */  ldc1      $f2, -0x7ac0($at)
/* 17EFC 8003CAFC 46220000 */  add.d     $f0, $f0, $f2
/* 17F00 8003CB00 46200020 */  cvt.s.d   $f0, $f0
/* 17F04 8003CB04 E4600030 */  swc1      $f0, 0x30($v1)
.L8003CB08:
/* 17F08 8003CB08 8FBF0024 */  lw        $ra, 0x24($sp)
/* 17F0C 8003CB0C 8FB20020 */  lw        $s2, 0x20($sp)
/* 17F10 8003CB10 8FB1001C */  lw        $s1, 0x1c($sp)
/* 17F14 8003CB14 8FB00018 */  lw        $s0, 0x18($sp)
/* 17F18 8003CB18 03E00008 */  jr        $ra
/* 17F1C 8003CB1C 27BD0028 */   addiu    $sp, $sp, 0x28
