.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetMessageValue
/* 0F56F4 802D0D44 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F56F8 802D0D48 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F56FC 802D0D4C 0080882D */  daddu $s1, $a0, $zero
/* 0F5700 802D0D50 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F5704 802D0D54 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F5708 802D0D58 8E30000C */  lw    $s0, 0xc($s1)
/* 0F570C 802D0D5C 8E050000 */  lw    $a1, ($s0)
/* 0F5710 802D0D60 0C0B1EAF */  jal   get_variable
/* 0F5714 802D0D64 26100004 */   addiu $s0, $s0, 4
/* 0F5718 802D0D68 0220202D */  daddu $a0, $s1, $zero
/* 0F571C 802D0D6C 8E050000 */  lw    $a1, ($s0)
/* 0F5720 802D0D70 0C0B1EAF */  jal   get_variable
/* 0F5724 802D0D74 0040802D */   daddu $s0, $v0, $zero
/* 0F5728 802D0D78 0200202D */  daddu $a0, $s0, $zero
/* 0F572C 802D0D7C 0C0496FA */  jal   set_message_value
/* 0F5730 802D0D80 0040282D */   daddu $a1, $v0, $zero
/* 0F5734 802D0D84 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F5738 802D0D88 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F573C 802D0D8C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F5740 802D0D90 24020002 */  addiu $v0, $zero, 2
/* 0F5744 802D0D94 03E00008 */  jr    $ra
/* 0F5748 802D0D98 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F574C 802D0D9C 00000000 */  nop   
