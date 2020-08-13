.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osContGetReadData
/* 03CE28 80061A28 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 03CE2C 80061A2C 00804821 */  addu  $t1, $a0, $zero
/* 03CE30 80061A30 3C02800A */  lui   $v0, 0x800a
/* 03CE34 80061A34 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03CE38 80061A38 3C08800B */  lui   $t0, 0x800b
/* 03CE3C 80061A3C 25080ED0 */  addiu $t0, $t0, 0xed0
/* 03CE40 80061A40 1840001D */  blez  $v0, .L80061AB8
/* 03CE44 80061A44 00003821 */   addu  $a3, $zero, $zero
/* 03CE48 80061A48 24860003 */  addiu $a2, $a0, 3
.L80061A4C:
/* 03CE4C 80061A4C 89020000 */  lwl   $v0, ($t0)
/* 03CE50 80061A50 99020003 */  lwr   $v0, 3($t0)
/* 03CE54 80061A54 89030004 */  lwl   $v1, 4($t0)
/* 03CE58 80061A58 99030007 */  lwr   $v1, 7($t0)
/* 03CE5C 80061A5C ABA20000 */  swl   $v0, ($sp)
/* 03CE60 80061A60 BBA20003 */  swr   $v0, 3($sp)
/* 03CE64 80061A64 ABA30004 */  swl   $v1, 4($sp)
/* 03CE68 80061A68 BBA30007 */  swr   $v1, 7($sp)
/* 03CE6C 80061A6C 93A20002 */  lbu   $v0, 2($sp)
/* 03CE70 80061A70 304200C0 */  andi  $v0, $v0, 0xc0
/* 03CE74 80061A74 00021102 */  srl   $v0, $v0, 4
/* 03CE78 80061A78 14400007 */  bnez  $v0, .L80061A98
/* 03CE7C 80061A7C A0C20001 */   sb    $v0, 1($a2)
/* 03CE80 80061A80 97A20004 */  lhu   $v0, 4($sp)
/* 03CE84 80061A84 A5220000 */  sh    $v0, ($t1)
/* 03CE88 80061A88 93A20006 */  lbu   $v0, 6($sp)
/* 03CE8C 80061A8C A0C2FFFF */  sb    $v0, -1($a2)
/* 03CE90 80061A90 93A20007 */  lbu   $v0, 7($sp)
/* 03CE94 80061A94 A0C20000 */  sb    $v0, ($a2)
.L80061A98:
/* 03CE98 80061A98 24E70001 */  addiu $a3, $a3, 1
/* 03CE9C 80061A9C 25080008 */  addiu $t0, $t0, 8
/* 03CEA0 80061AA0 3C02800A */  lui   $v0, 0x800a
/* 03CEA4 80061AA4 9042A606 */  lbu   $v0, -0x59fa($v0)
/* 03CEA8 80061AA8 24C60006 */  addiu $a2, $a2, 6
/* 03CEAC 80061AAC 00E2102A */  slt   $v0, $a3, $v0
/* 03CEB0 80061AB0 1440FFE6 */  bnez  $v0, .L80061A4C
/* 03CEB4 80061AB4 25290006 */   addiu $t1, $t1, 6
.L80061AB8:
/* 03CEB8 80061AB8 27BD0010 */  addiu $sp, $sp, 0x10
/* 03CEBC 80061ABC 03E00008 */  jr    $ra
/* 03CEC0 80061AC0 00000000 */   nop   

