.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024DA28
/* 140D68 8024DA28 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 140D6C 8024DA2C AFBF0028 */  sw    $ra, 0x28($sp)
/* 140D70 8024DA30 00A0182D */  daddu $v1, $a1, $zero
/* 140D74 8024DA34 00C0382D */  daddu $a3, $a2, $zero
/* 140D78 8024DA38 24020001 */  addiu $v0, $zero, 1
/* 140D7C 8024DA3C 10820016 */  beq   $a0, $v0, .L8024DA98
/* 140D80 8024DA40 24080010 */   addiu $t0, $zero, 0x10
/* 140D84 8024DA44 28820002 */  slti  $v0, $a0, 2
/* 140D88 8024DA48 10400005 */  beqz  $v0, .L8024DA60
/* 140D8C 8024DA4C 24020002 */   addiu $v0, $zero, 2
/* 140D90 8024DA50 10800007 */  beqz  $a0, .L8024DA70
/* 140D94 8024DA54 00032080 */   sll   $a0, $v1, 2
/* 140D98 8024DA58 080936B8 */  j     func_8024DAE0
/* 140D9C 8024DA5C 00072880 */   sll   $a1, $a3, 2

.L8024DA60:
/* 140DA0 8024DA60 10820015 */  beq   $a0, $v0, .L8024DAB8
/* 140DA4 8024DA64 00032080 */   sll   $a0, $v1, 2
