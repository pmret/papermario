.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartOffset
/* 199454 8026AB74 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199458 8026AB78 AFB20018 */  sw    $s2, 0x18($sp)
/* 19945C 8026AB7C 0080902D */  daddu $s2, $a0, $zero
/* 199460 8026AB80 AFBF0024 */  sw    $ra, 0x24($sp)
/* 199464 8026AB84 AFB40020 */  sw    $s4, 0x20($sp)
/* 199468 8026AB88 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19946C 8026AB8C AFB10014 */  sw    $s1, 0x14($sp)
/* 199470 8026AB90 AFB00010 */  sw    $s0, 0x10($sp)
/* 199474 8026AB94 8E51000C */  lw    $s1, 0xc($s2)
/* 199478 8026AB98 8E250000 */  lw    $a1, ($s1)
/* 19947C 8026AB9C 0C0B1EAF */  jal   get_variable
/* 199480 8026ABA0 26310004 */   addiu $s1, $s1, 4
/* 199484 8026ABA4 0040802D */  daddu $s0, $v0, $zero
/* 199488 8026ABA8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19948C 8026ABAC 16020002 */  bne   $s0, $v0, .L8026ABB8
/* 199490 8026ABB0 00000000 */   nop   
/* 199494 8026ABB4 8E500148 */  lw    $s0, 0x148($s2)
.L8026ABB8:
/* 199498 8026ABB8 8E250000 */  lw    $a1, ($s1)
/* 19949C 8026ABBC 26310004 */  addiu $s1, $s1, 4
/* 1994A0 8026ABC0 0C0B1EAF */  jal   get_variable
/* 1994A4 8026ABC4 0240202D */   daddu $a0, $s2, $zero
/* 1994A8 8026ABC8 0200202D */  daddu $a0, $s0, $zero
/* 1994AC 8026ABCC 0C09A75B */  jal   get_actor
/* 1994B0 8026ABD0 0040802D */   daddu $s0, $v0, $zero
/* 1994B4 8026ABD4 0040202D */  daddu $a0, $v0, $zero
/* 1994B8 8026ABD8 0C099117 */  jal   get_actor_part
/* 1994BC 8026ABDC 0200282D */   daddu $a1, $s0, $zero
/* 1994C0 8026ABE0 8E250000 */  lw    $a1, ($s1)
/* 1994C4 8026ABE4 26310004 */  addiu $s1, $s1, 4
/* 1994C8 8026ABE8 0040302D */  daddu $a2, $v0, $zero
/* 1994CC 8026ABEC 3C020010 */  lui   $v0, 0x10
/* 1994D0 8026ABF0 8CC30000 */  lw    $v1, ($a2)
/* 1994D4 8026ABF4 8E330000 */  lw    $s3, ($s1)
/* 1994D8 8026ABF8 8E340004 */  lw    $s4, 4($s1)
/* 1994DC 8026ABFC 00621824 */  and   $v1, $v1, $v0
/* 1994E0 8026AC00 14600005 */  bnez  $v1, .L8026AC18
/* 1994E4 8026AC04 0240202D */   daddu $a0, $s2, $zero
/* 1994E8 8026AC08 84C20014 */  lh    $v0, 0x14($a2)
/* 1994EC 8026AC0C 84D00016 */  lh    $s0, 0x16($a2)
/* 1994F0 8026AC10 0809AB0F */  j     .L8026AC3C
/* 1994F4 8026AC14 84D10018 */   lh    $s1, 0x18($a2)

.L8026AC18:
/* 1994F8 8026AC18 C4C0002C */  lwc1  $f0, 0x2c($a2)
/* 1994FC 8026AC1C 4600010D */  trunc.w.s $f4, $f0
/* 199500 8026AC20 44022000 */  mfc1  $v0, $f4
/* 199504 8026AC24 C4C00030 */  lwc1  $f0, 0x30($a2)
/* 199508 8026AC28 C4C20034 */  lwc1  $f2, 0x34($a2)
/* 19950C 8026AC2C 4600010D */  trunc.w.s $f4, $f0
/* 199510 8026AC30 44102000 */  mfc1  $s0, $f4
/* 199514 8026AC34 4600110D */  trunc.w.s $f4, $f2
/* 199518 8026AC38 44112000 */  mfc1  $s1, $f4
.L8026AC3C:
/* 19951C 8026AC3C 0C0B2026 */  jal   set_variable
/* 199520 8026AC40 0040302D */   daddu $a2, $v0, $zero
/* 199524 8026AC44 0240202D */  daddu $a0, $s2, $zero
/* 199528 8026AC48 0260282D */  daddu $a1, $s3, $zero
/* 19952C 8026AC4C 0C0B2026 */  jal   set_variable
/* 199530 8026AC50 0200302D */   daddu $a2, $s0, $zero
/* 199534 8026AC54 0240202D */  daddu $a0, $s2, $zero
/* 199538 8026AC58 0280282D */  daddu $a1, $s4, $zero
/* 19953C 8026AC5C 0C0B2026 */  jal   set_variable
/* 199540 8026AC60 0220302D */   daddu $a2, $s1, $zero
/* 199544 8026AC64 8FBF0024 */  lw    $ra, 0x24($sp)
/* 199548 8026AC68 8FB40020 */  lw    $s4, 0x20($sp)
/* 19954C 8026AC6C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 199550 8026AC70 8FB20018 */  lw    $s2, 0x18($sp)
/* 199554 8026AC74 8FB10014 */  lw    $s1, 0x14($sp)
/* 199558 8026AC78 8FB00010 */  lw    $s0, 0x10($sp)
/* 19955C 8026AC7C 24020002 */  addiu $v0, $zero, 2
/* 199560 8026AC80 03E00008 */  jr    $ra
/* 199564 8026AC84 27BD0028 */   addiu $sp, $sp, 0x28

