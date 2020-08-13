.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osPackReadData
/* 03CEC4 80061AC4 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 03CEC8 80061AC8 3C07800B */  lui   $a3, 0x800b
/* 03CECC 80061ACC 24E70ED0 */  addiu $a3, $a3, 0xed0
/* 03CED0 80061AD0 2406000E */  addiu $a2, $zero, 0xe
/* 03CED4 80061AD4 24E20038 */  addiu $v0, $a3, 0x38
.L80061AD8:
/* 03CED8 80061AD8 AC400000 */  sw    $zero, ($v0)
/* 03CEDC 80061ADC 24C6FFFF */  addiu $a2, $a2, -1
/* 03CEE0 80061AE0 04C1FFFD */  bgez  $a2, .L80061AD8
/* 03CEE4 80061AE4 2442FFFC */   addiu $v0, $v0, -4
/* 03CEE8 80061AE8 24020001 */  addiu $v0, $zero, 1
/* 03CEEC 80061AEC 3C04800A */  lui   $a0, 0x800a
/* 03CEF0 80061AF0 9084A606 */  lbu   $a0, -0x59fa($a0)
/* 03CEF4 80061AF4 00003021 */  addu  $a2, $zero, $zero
/* 03CEF8 80061AF8 3C01800B */  lui   $at, 0x800b
/* 03CEFC 80061AFC AC220F0C */  sw    $v0, 0xf0c($at)
/* 03CF00 80061B00 240200FF */  addiu $v0, $zero, 0xff
/* 03CF04 80061B04 24030001 */  addiu $v1, $zero, 1
/* 03CF08 80061B08 A3A20000 */  sb    $v0, ($sp)
/* 03CF0C 80061B0C 24020004 */  addiu $v0, $zero, 4
/* 03CF10 80061B10 A3A20002 */  sb    $v0, 2($sp)
/* 03CF14 80061B14 3402FFFF */  ori   $v0, $zero, 0xffff
/* 03CF18 80061B18 A7A20004 */  sh    $v0, 4($sp)
/* 03CF1C 80061B1C 2402FFFF */  addiu $v0, $zero, -1
/* 03CF20 80061B20 A3A30001 */  sb    $v1, 1($sp)
/* 03CF24 80061B24 A3A30003 */  sb    $v1, 3($sp)
/* 03CF28 80061B28 A3A20006 */  sb    $v0, 6($sp)
/* 03CF2C 80061B2C 1880000F */  blez  $a0, .L80061B6C
/* 03CF30 80061B30 A3A20007 */   sb    $v0, 7($sp)
.L80061B34:
/* 03CF34 80061B34 8BA20000 */  lwl   $v0, ($sp)
/* 03CF38 80061B38 9BA20003 */  lwr   $v0, 3($sp)
/* 03CF3C 80061B3C 8BA30004 */  lwl   $v1, 4($sp)
/* 03CF40 80061B40 9BA30007 */  lwr   $v1, 7($sp)
/* 03CF44 80061B44 A8E20000 */  swl   $v0, ($a3)
/* 03CF48 80061B48 B8E20003 */  swr   $v0, 3($a3)
/* 03CF4C 80061B4C A8E30004 */  swl   $v1, 4($a3)
/* 03CF50 80061B50 B8E30007 */  swr   $v1, 7($a3)
/* 03CF54 80061B54 3C02800A */  lui   $v0, 0x800a
/* 03CF58 80061B58 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03CF5C 80061B5C 24C60001 */  addiu $a2, $a2, 1
/* 03CF60 80061B60 00C2102A */  slt   $v0, $a2, $v0
/* 03CF64 80061B64 1440FFF3 */  bnez  $v0, .L80061B34
/* 03CF68 80061B68 24E70008 */   addiu $a3, $a3, 8
.L80061B6C:
/* 03CF6C 80061B6C 240200FE */  addiu $v0, $zero, 0xfe
/* 03CF70 80061B70 A0E20000 */  sb    $v0, ($a3)
/* 03CF74 80061B74 03E00008 */  jr    $ra
/* 03CF78 80061B78 27BD0010 */   addiu $sp, $sp, 0x10

/* 03CF7C 80061B7C 00000000 */  nop   
