.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024DAE0
/* 140E20 8024DAE0 00683021 */  addu  $a2, $v1, $t0
/* 140E24 8024DAE4 00063080 */  sll   $a2, $a2, 2
/* 140E28 8024DAE8 00E83821 */  addu  $a3, $a3, $t0
/* 140E2C 8024DAEC 00073880 */  sll   $a3, $a3, 2
/* 140E30 8024DAF0 24020600 */  addiu $v0, $zero, 0x600
