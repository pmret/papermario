.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801498C4
/* 0DFFC4 801498C4 3C038016 */  lui   $v1, 0x8016
/* 0DFFC8 801498C8 8C639AD0 */  lw    $v1, -0x6530($v1)
/* 0DFFCC 801498CC 0000282D */  daddu $a1, $zero, $zero
.L801498D0:
/* 0DFFD0 801498D0 8C620000 */  lw    $v0, ($v1)
/* 0DFFD4 801498D4 30420001 */  andi  $v0, $v0, 1
/* 0DFFD8 801498D8 10400006 */  beqz  $v0, .L801498F4
/* 0DFFDC 801498DC 24A50001 */   addiu $a1, $a1, 1
/* 0DFFE0 801498E0 8C620004 */  lw    $v0, 4($v1)
/* 0DFFE4 801498E4 14440004 */  bne   $v0, $a0, .L801498F8
/* 0DFFE8 801498E8 28A2000A */   slti  $v0, $a1, 0xa
/* 0DFFEC 801498EC 03E00008 */  jr    $ra
/* 0DFFF0 801498F0 0060102D */   daddu $v0, $v1, $zero

.L801498F4:
/* 0DFFF4 801498F4 28A2000A */  slti  $v0, $a1, 0xa
.L801498F8:
/* 0DFFF8 801498F8 1440FFF5 */  bnez  $v0, .L801498D0
/* 0DFFFC 801498FC 2463001C */   addiu $v1, $v1, 0x1c
/* 0E0000 80149900 03E00008 */  jr    $ra
/* 0E0004 80149904 0000102D */   daddu $v0, $zero, $zero

