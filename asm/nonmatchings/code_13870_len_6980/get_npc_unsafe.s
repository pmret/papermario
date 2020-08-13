.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_npc_unsafe
/* 015EEC 8003AAEC 0000282D */  daddu $a1, $zero, $zero
/* 015EF0 8003AAF0 3C06800A */  lui   $a2, 0x800a
/* 015EF4 8003AAF4 8CC60B90 */  lw    $a2, 0xb90($a2)
.L8003AAF8:
/* 015EF8 8003AAF8 8CC30000 */  lw    $v1, ($a2)
/* 015EFC 8003AAFC 50600008 */  beql  $v1, $zero, .L8003AB20
/* 015F00 8003AB00 24A50001 */   addiu $a1, $a1, 1
/* 015F04 8003AB04 8C620000 */  lw    $v0, ($v1)
/* 015F08 8003AB08 50400005 */  beql  $v0, $zero, .L8003AB20
/* 015F0C 8003AB0C 24A50001 */   addiu $a1, $a1, 1
/* 015F10 8003AB10 806200A4 */  lb    $v0, 0xa4($v1)
/* 015F14 8003AB14 10440006 */  beq   $v0, $a0, .L8003AB30
/* 015F18 8003AB18 28A20040 */   slti  $v0, $a1, 0x40
/* 015F1C 8003AB1C 24A50001 */  addiu $a1, $a1, 1
.L8003AB20:
/* 015F20 8003AB20 28A20040 */  slti  $v0, $a1, 0x40
/* 015F24 8003AB24 1440FFF4 */  bnez  $v0, .L8003AAF8
/* 015F28 8003AB28 24C60004 */   addiu $a2, $a2, 4
/* 015F2C 8003AB2C 28A20040 */  slti  $v0, $a1, 0x40
.L8003AB30:
/* 015F30 8003AB30 14400003 */  bnez  $v0, .L8003AB40
/* 015F34 8003AB34 00000000 */   nop   
.L8003AB38:
/* 015F38 8003AB38 0800EACE */  j     .L8003AB38
/* 015F3C 8003AB3C 00000000 */   nop   

.L8003AB40:
/* 015F40 8003AB40 03E00008 */  jr    $ra
/* 015F44 8003AB44 0060102D */   daddu $v0, $v1, $zero

