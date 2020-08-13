.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel contRmbCheckMesg
/* 03B110 8005FD10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B114 8005FD14 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03B118 8005FD18 8C82000C */  lw    $v0, 0xc($a0)
/* 03B11C 8005FD1C 3C04800E */  lui   $a0, 0x800e
/* 03B120 8005FD20 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03B124 8005FD24 90460000 */  lbu   $a2, ($v0)
/* 03B128 8005FD28 3C02800E */  lui   $v0, 0x800e
/* 03B12C 8005FD2C 2442AAD8 */  addiu $v0, $v0, -0x5528
/* 03B130 8005FD30 00062840 */  sll   $a1, $a2, 1
/* 03B134 8005FD34 00A62821 */  addu  $a1, $a1, $a2
/* 03B138 8005FD38 00052880 */  sll   $a1, $a1, 2
/* 03B13C 8005FD3C 00A62821 */  addu  $a1, $a1, $a2
/* 03B140 8005FD40 000528C0 */  sll   $a1, $a1, 3
/* 03B144 8005FD44 0C019FD1 */  jal   osMotorInit
/* 03B148 8005FD48 00A22821 */   addu  $a1, $a1, $v0
/* 03B14C 8005FD4C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03B150 8005FD50 03E00008 */  jr    $ra
/* 03B154 8005FD54 27BD0018 */   addiu $sp, $sp, 0x18

