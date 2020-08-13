.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CamPreset_M
.L80280D20:
/* 7E1BA0 80280D20 240200C9 */  addiu $v0, $zero, 0xc9
/* 7E1BA4 80280D24 10620072 */  beq   $v1, $v0, .L80280EF0
/* 7E1BA8 80280D28 286200CA */   slti  $v0, $v1, 0xca
/* 7E1BAC 80280D2C 10400007 */  beqz  $v0, .L80280D4C
/* 7E1BB0 80280D30 24020048 */   addiu $v0, $zero, 0x48
/* 7E1BB4 80280D34 1062017E */  beq   $v1, $v0, .L80281330
/* 7E1BB8 80280D38 24020049 */   addiu $v0, $zero, 0x49
