.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003D660
/* 018A60 8003D660 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 018A64 8003D664 AFB00010 */  sw    $s0, 0x10($sp)
/* 018A68 8003D668 0080802D */  daddu $s0, $a0, $zero
/* 018A6C 8003D66C AFB10014 */  sw    $s1, 0x14($sp)
/* 018A70 8003D670 3C020040 */  lui   $v0, 0x40
/* 018A74 8003D674 34420002 */  ori   $v0, $v0, 2
/* 018A78 8003D678 AFBF001C */  sw    $ra, 0x1c($sp)
/* 018A7C 8003D67C AFB20018 */  sw    $s2, 0x18($sp)
/* 018A80 8003D680 8E030000 */  lw    $v1, ($s0)
/* 018A84 8003D684 3C128011 */  lui   $s2, 0x8011
/* 018A88 8003D688 2652EBB0 */  addiu $s2, $s2, -0x1450
/* 018A8C 8003D68C 00621824 */  and   $v1, $v1, $v0
/* 018A90 8003D690 3C020040 */  lui   $v0, 0x40
/* 018A94 8003D694 14620036 */  bne   $v1, $v0, .L8003D770
/* 018A98 8003D698 00A0882D */   daddu $s1, $a1, $zero
/* 018A9C 8003D69C C6020018 */  lwc1  $f2, 0x18($s0)
/* 018AA0 8003D6A0 44800000 */  mtc1  $zero, $f0
/* 018AA4 8003D6A4 00000000 */  nop   
/* 018AA8 8003D6A8 46001032 */  c.eq.s $f2, $f0
/* 018AAC 8003D6AC 00000000 */  nop   
/* 018AB0 8003D6B0 4501002F */  bc1t  .L8003D770
/* 018AB4 8003D6B4 00000000 */   nop   
/* 018AB8 8003D6B8 0C016F6A */  jal   get_collider_type_by_id
/* 018ABC 8003D6BC 96040084 */   lhu   $a0, 0x84($s0)
/* 018AC0 8003D6C0 304200FF */  andi  $v0, $v0, 0xff
/* 018AC4 8003D6C4 2443FFFF */  addiu $v1, $v0, -1
/* 018AC8 8003D6C8 2C620009 */  sltiu $v0, $v1, 9
/* 018ACC 8003D6CC 10400025 */  beqz  $v0, .L8003D764
/* 018AD0 8003D6D0 00031080 */   sll   $v0, $v1, 2
/* 018AD4 8003D6D4 3C01800A */  lui   $at, 0x800a
/* 018AD8 8003D6D8 00220821 */  addu  $at, $at, $v0
/* 018ADC 8003D6DC 8C228590 */  lw    $v0, -0x7a70($at)
/* 018AE0 8003D6E0 00400008 */  jr    $v0
/* 018AE4 8003D6E4 00000000 */   nop   
/* 018AE8 8003D6E8 0200202D */  daddu $a0, $s0, $zero
/* 018AEC 8003D6EC 0C00F68E */  jal   func_8003DA38
/* 018AF0 8003D6F0 0220282D */   daddu $a1, $s1, $zero
/* 018AF4 8003D6F4 0800F5DC */  j     .L8003D770
/* 018AF8 8003D6F8 00000000 */   nop   

/* 018AFC 8003D6FC 0200202D */  daddu $a0, $s0, $zero
/* 018B00 8003D700 0C00F70E */  jal   func_8003DC38
/* 018B04 8003D704 0220282D */   daddu $a1, $s1, $zero
/* 018B08 8003D708 0800F5DC */  j     .L8003D770
/* 018B0C 8003D70C 00000000 */   nop   

/* 018B10 8003D710 82420000 */  lb    $v0, ($s2)
/* 018B14 8003D714 10400004 */  beqz  $v0, .L8003D728
/* 018B18 8003D718 24020008 */   addiu $v0, $zero, 8
/* 018B1C 8003D71C 82430003 */  lb    $v1, 3($s2)
/* 018B20 8003D720 10620013 */  beq   $v1, $v0, .L8003D770
/* 018B24 8003D724 00000000 */   nop   
.L8003D728:
/* 018B28 8003D728 0200202D */  daddu $a0, $s0, $zero
/* 018B2C 8003D72C 0C00F7E8 */  jal   func_8003DFA0
/* 018B30 8003D730 0220282D */   daddu $a1, $s1, $zero
/* 018B34 8003D734 0800F5DC */  j     .L8003D770
/* 018B38 8003D738 00000000 */   nop   

/* 018B3C 8003D73C 0200202D */  daddu $a0, $s0, $zero
/* 018B40 8003D740 0C00F835 */  jal   func_8003E0D4
/* 018B44 8003D744 0220282D */   daddu $a1, $s1, $zero
/* 018B48 8003D748 0800F5DC */  j     .L8003D770
/* 018B4C 8003D74C 00000000 */   nop   

/* 018B50 8003D750 0200202D */  daddu $a0, $s0, $zero
/* 018B54 8003D754 0C00F874 */  jal   func_8003E1D0
/* 018B58 8003D758 0220282D */   daddu $a1, $s1, $zero
/* 018B5C 8003D75C 0800F5DC */  j     .L8003D770
/* 018B60 8003D760 00000000 */   nop   

.L8003D764:
/* 018B64 8003D764 0200202D */  daddu $a0, $s0, $zero
/* 018B68 8003D768 0C00F5E2 */  jal   func_8003D788
/* 018B6C 8003D76C 0220282D */   daddu $a1, $s1, $zero
.L8003D770:
/* 018B70 8003D770 8FBF001C */  lw    $ra, 0x1c($sp)
/* 018B74 8003D774 8FB20018 */  lw    $s2, 0x18($sp)
/* 018B78 8003D778 8FB10014 */  lw    $s1, 0x14($sp)
/* 018B7C 8003D77C 8FB00010 */  lw    $s0, 0x10($sp)
/* 018B80 8003D780 03E00008 */  jr    $ra
/* 018B84 8003D784 27BD0020 */   addiu $sp, $sp, 0x20

