.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CB44
/* 17F44 8003CB44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 17F48 8003CB48 AFB00018 */  sw        $s0, 0x18($sp)
/* 17F4C 8003CB4C 0080802D */  daddu     $s0, $a0, $zero
/* 17F50 8003CB50 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17F54 8003CB54 00A0882D */  daddu     $s1, $a1, $zero
/* 17F58 8003CB58 AFB20020 */  sw        $s2, 0x20($sp)
/* 17F5C 8003CB5C 02119021 */  addu      $s2, $s0, $s1
/* 17F60 8003CB60 AFBF0024 */  sw        $ra, 0x24($sp)
/* 17F64 8003CB64 82430330 */  lb        $v1, 0x330($s2)
/* 17F68 8003CB68 10600005 */  beqz      $v1, .L8003CB80
/* 17F6C 8003CB6C 24020001 */   addiu    $v0, $zero, 1
/* 17F70 8003CB70 10620023 */  beq       $v1, $v0, .L8003CC00
/* 17F74 8003CB74 00111080 */   sll      $v0, $s1, 2
/* 17F78 8003CB78 0800F31D */  j         .L8003CC74
/* 17F7C 8003CB7C 00000000 */   nop
.L8003CB80:
/* 17F80 8003CB80 860200A8 */  lh        $v0, 0xa8($s0)
/* 17F84 8003CB84 3C013FE0 */  lui       $at, 0x3fe0
/* 17F88 8003CB88 44810800 */  mtc1      $at, $f1
/* 17F8C 8003CB8C 44800000 */  mtc1      $zero, $f0
/* 17F90 8003CB90 44821000 */  mtc1      $v0, $f2
/* 17F94 8003CB94 00000000 */  nop
/* 17F98 8003CB98 468010A1 */  cvt.d.w   $f2, $f2
/* 17F9C 8003CB9C 46201082 */  mul.d     $f2, $f2, $f0
/* 17FA0 8003CBA0 00000000 */  nop
/* 17FA4 8003CBA4 C6060040 */  lwc1      $f6, 0x40($s0)
/* 17FA8 8003CBA8 3C013F80 */  lui       $at, 0x3f80
/* 17FAC 8003CBAC 44812000 */  mtc1      $at, $f4
/* 17FB0 8003CBB0 C600003C */  lwc1      $f0, 0x3c($s0)
/* 17FB4 8003CBB4 AFA00014 */  sw        $zero, 0x14($sp)
/* 17FB8 8003CBB8 E7A40010 */  swc1      $f4, 0x10($sp)
/* 17FBC 8003CBBC 46000021 */  cvt.d.s   $f0, $f0
/* 17FC0 8003CBC0 46220000 */  add.d     $f0, $f0, $f2
/* 17FC4 8003CBC4 3C0140A0 */  lui       $at, 0x40a0
/* 17FC8 8003CBC8 44811000 */  mtc1      $at, $f2
/* 17FCC 8003CBCC 8E050038 */  lw        $a1, 0x38($s0)
/* 17FD0 8003CBD0 46023181 */  sub.s     $f6, $f6, $f2
/* 17FD4 8003CBD4 46200020 */  cvt.s.d   $f0, $f0
/* 17FD8 8003CBD8 44060000 */  mfc1      $a2, $f0
/* 17FDC 8003CBDC 44073000 */  mfc1      $a3, $f6
/* 17FE0 8003CBE0 0C01C5D4 */  jal       func_80071750
/* 17FE4 8003CBE4 24040002 */   addiu    $a0, $zero, 2
/* 17FE8 8003CBE8 00111880 */  sll       $v1, $s1, 2
/* 17FEC 8003CBEC 02031821 */  addu      $v1, $s0, $v1
/* 17FF0 8003CBF0 AC620324 */  sw        $v0, 0x324($v1)
/* 17FF4 8003CBF4 24020001 */  addiu     $v0, $zero, 1
/* 17FF8 8003CBF8 0800F31D */  j         .L8003CC74
/* 17FFC 8003CBFC A2420330 */   sb       $v0, 0x330($s2)
.L8003CC00:
/* 18000 8003CC00 02021021 */  addu      $v0, $s0, $v0
/* 18004 8003CC04 8C420324 */  lw        $v0, 0x324($v0)
/* 18008 8003CC08 C6000038 */  lwc1      $f0, 0x38($s0)
/* 1800C 8003CC0C 8C43000C */  lw        $v1, 0xc($v0)
/* 18010 8003CC10 E4600004 */  swc1      $f0, 4($v1)
/* 18014 8003CC14 860200A8 */  lh        $v0, 0xa8($s0)
/* 18018 8003CC18 3C013FE0 */  lui       $at, 0x3fe0
/* 1801C 8003CC1C 44810800 */  mtc1      $at, $f1
/* 18020 8003CC20 44800000 */  mtc1      $zero, $f0
/* 18024 8003CC24 44821000 */  mtc1      $v0, $f2
/* 18028 8003CC28 00000000 */  nop
/* 1802C 8003CC2C 468010A1 */  cvt.d.w   $f2, $f2
/* 18030 8003CC30 46201082 */  mul.d     $f2, $f2, $f0
/* 18034 8003CC34 00000000 */  nop
/* 18038 8003CC38 C600003C */  lwc1      $f0, 0x3c($s0)
/* 1803C 8003CC3C 46000021 */  cvt.d.s   $f0, $f0
/* 18040 8003CC40 46220000 */  add.d     $f0, $f0, $f2
/* 18044 8003CC44 46200020 */  cvt.s.d   $f0, $f0
/* 18048 8003CC48 E4600008 */  swc1      $f0, 8($v1)
/* 1804C 8003CC4C C6020040 */  lwc1      $f2, 0x40($s0)
/* 18050 8003CC50 3C0140A0 */  lui       $at, 0x40a0
/* 18054 8003CC54 44810000 */  mtc1      $at, $f0
/* 18058 8003CC58 00000000 */  nop
/* 1805C 8003CC5C 46001081 */  sub.s     $f2, $f2, $f0
/* 18060 8003CC60 3C013F80 */  lui       $at, 0x3f80
/* 18064 8003CC64 44810000 */  mtc1      $at, $f0
/* 18068 8003CC68 00000000 */  nop
/* 1806C 8003CC6C E4600030 */  swc1      $f0, 0x30($v1)
/* 18070 8003CC70 E462000C */  swc1      $f2, 0xc($v1)
.L8003CC74:
/* 18074 8003CC74 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18078 8003CC78 8FB20020 */  lw        $s2, 0x20($sp)
/* 1807C 8003CC7C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18080 8003CC80 8FB00018 */  lw        $s0, 0x18($sp)
/* 18084 8003CC84 03E00008 */  jr        $ra
/* 18088 8003CC88 27BD0028 */   addiu    $sp, $sp, 0x28
