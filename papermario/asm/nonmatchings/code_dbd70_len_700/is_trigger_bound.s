.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel is_trigger_bound
/* 0DC36C 80145C6C 0000402D */  daddu $t0, $zero, $zero
/* 0DC370 80145C70 3C078016 */  lui   $a3, 0x8016
/* 0DC374 80145C74 8CE79390 */  lw    $a3, -0x6c70($a3)
.L80145C78:
/* 0DC378 80145C78 8CE30000 */  lw    $v1, ($a3)
/* 0DC37C 80145C7C 5060000F */  beql  $v1, $zero, .L80145CBC
/* 0DC380 80145C80 25080001 */   addiu $t0, $t0, 1
/* 0DC384 80145C84 5064000D */  beql  $v1, $a0, .L80145CBC
/* 0DC388 80145C88 25080001 */   addiu $t0, $t0, 1
/* 0DC38C 80145C8C 8C660000 */  lw    $a2, ($v1)
/* 0DC390 80145C90 30C20001 */  andi  $v0, $a2, 1
/* 0DC394 80145C94 10400009 */  beqz  $v0, .L80145CBC
/* 0DC398 80145C98 25080001 */   addiu $t0, $t0, 1
/* 0DC39C 80145C9C 30C20002 */  andi  $v0, $a2, 2
/* 0DC3A0 80145CA0 10400006 */  beqz  $v0, .L80145CBC
/* 0DC3A4 80145CA4 00000000 */   nop   
/* 0DC3A8 80145CA8 8C620010 */  lw    $v0, 0x10($v1)
/* 0DC3AC 80145CAC 14450004 */  bne   $v0, $a1, .L80145CC0
/* 0DC3B0 80145CB0 29020040 */   slti  $v0, $t0, 0x40
/* 0DC3B4 80145CB4 03E00008 */  jr    $ra
/* 0DC3B8 80145CB8 24020001 */   addiu $v0, $zero, 1

.L80145CBC:
/* 0DC3BC 80145CBC 29020040 */  slti  $v0, $t0, 0x40
.L80145CC0:
/* 0DC3C0 80145CC0 1440FFED */  bnez  $v0, .L80145C78
/* 0DC3C4 80145CC4 24E70004 */   addiu $a3, $a3, 4
/* 0DC3C8 80145CC8 03E00008 */  jr    $ra
/* 0DC3CC 80145CCC 0000102D */   daddu $v0, $zero, $zero

