.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248BFC
.L80248BFC:
/* 13BF3C 80248BFC 3C108027 */  lui   $s0, 0x8027
/* 13BF40 80248C00 261003A0 */  addiu $s0, $s0, 0x3a0
/* 13BF44 80248C04 8E020000 */  lw    $v0, ($s0)
/* 13BF48 80248C08 10400054 */  beqz  $v0, .L80248D5C
/* 13BF4C 80248C0C 00000000 */   nop   
/* 13BF50 80248C10 0C090AE8 */  jal   func_80242BA0
/* 13BF54 80248C14 0000202D */   daddu $a0, $zero, $zero
/* 13BF58 80248C18 8E020000 */  lw    $v0, ($s0)
/* 13BF5C 80248C1C 24100001 */  addiu $s0, $zero, 1
/* 13BF60 80248C20 14500027 */  bne   $v0, $s0, .L80248CC0
/* 13BF64 80248C24 24040004 */   addiu $a0, $zero, 4
/* 13BF68 80248C28 3C058027 */  lui   $a1, 0x8027
/* 13BF6C 80248C2C 24A5FBD8 */  addiu $a1, $a1, -0x428
/* 13BF70 80248C30 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13BF74 80248C34 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13BF78 80248C38 24020089 */  addiu $v0, $zero, 0x89
/* 13BF7C 80248C3C AFA20014 */  sw    $v0, 0x14($sp)
/* 13BF80 80248C40 2402001A */  addiu $v0, $zero, 0x1a
/* 13BF84 80248C44 AFA20018 */  sw    $v0, 0x18($sp)
/* 13BF88 80248C48 240200FF */  addiu $v0, $zero, 0xff
