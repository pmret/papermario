.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80044148
/* 01F548 80044148 3C02800A */  lui   $v0, 0x800a
/* 01F54C 8004414C 8C42A600 */  lw    $v0, -0x5a00($v0)
/* 01F550 80044150 3C03800B */  lui   $v1, 0x800b
/* 01F554 80044154 80630F15 */  lb    $v1, 0xf15($v1)
/* 01F558 80044158 38420003 */  xori  $v0, $v0, 3
/* 01F55C 8004415C 2C440001 */  sltiu $a0, $v0, 1
/* 01F560 80044160 24020005 */  addiu $v0, $zero, 5
/* 01F564 80044164 50620001 */  beql  $v1, $v0, .L8004416C
/* 01F568 80044168 24040001 */   addiu $a0, $zero, 1
.L8004416C:
/* 01F56C 8004416C 03E00008 */  jr    $ra
/* 01F570 80044170 0080102D */   daddu $v0, $a0, $zero

/* 01F574 80044174 00000000 */  nop   
/* 01F578 80044178 00000000 */  nop   
/* 01F57C 8004417C 00000000 */  nop   


