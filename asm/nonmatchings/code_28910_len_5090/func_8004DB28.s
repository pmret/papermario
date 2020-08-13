.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004DB28
/* 028F28 8004DB28 8C82001C */  lw    $v0, 0x1c($a0)
/* 028F2C 8004DB2C 10400005 */  beqz  $v0, .L8004DB44
/* 028F30 8004DB30 0000102D */   daddu $v0, $zero, $zero
/* 028F34 8004DB34 90830221 */  lbu   $v1, 0x221($a0)
/* 028F38 8004DB38 14600002 */  bnez  $v1, .L8004DB44
/* 028F3C 8004DB3C 24020001 */   addiu $v0, $zero, 1
/* 028F40 8004DB40 0000102D */  daddu $v0, $zero, $zero
.L8004DB44:
/* 028F44 8004DB44 03E00008 */  jr    $ra
/* 028F48 8004DB48 00000000 */   nop   

