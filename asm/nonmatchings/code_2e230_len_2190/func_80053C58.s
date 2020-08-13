.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80053C58
/* 02F058 80053C58 3C03800A */  lui   $v1, 0x800a
/* 02F05C 80053C5C 8C63A5C0 */  lw    $v1, -0x5a40($v1)
/* 02F060 80053C60 24020001 */  addiu $v0, $zero, 1
/* 02F064 80053C64 1082000B */  beq   $a0, $v0, .L80053C94
/* 02F068 80053C68 00000000 */   nop   
/* 02F06C 80053C6C 10800003 */  beqz  $a0, .L80053C7C
/* 02F070 80053C70 24020002 */   addiu $v0, $zero, 2
/* 02F074 80053C74 5482000D */  bnel  $a0, $v0, .L80053CAC
/* 02F078 80053C78 ACA00000 */   sw    $zero, ($a1)
.L80053C7C:
/* 02F07C 80053C7C 8C62005C */  lw    $v0, 0x5c($v1)
/* 02F080 80053C80 ACA20000 */  sw    $v0, ($a1)
/* 02F084 80053C84 3C02800A */  lui   $v0, 0x800a
/* 02F088 80053C88 8C42A664 */  lw    $v0, -0x599c($v0)
/* 02F08C 80053C8C 03E00008 */  jr    $ra
/* 02F090 80053C90 ACC20000 */   sw    $v0, ($a2)

.L80053C94:
/* 02F094 80053C94 8C620060 */  lw    $v0, 0x60($v1)
/* 02F098 80053C98 ACA20000 */  sw    $v0, ($a1)
/* 02F09C 80053C9C 3C02800A */  lui   $v0, 0x800a
/* 02F0A0 80053CA0 8C42A5FC */  lw    $v0, -0x5a04($v0)
/* 02F0A4 80053CA4 03E00008 */  jr    $ra
/* 02F0A8 80053CA8 ACC20000 */   sw    $v0, ($a2)

.L80053CAC:
/* 02F0AC 80053CAC 03E00008 */  jr    $ra
/* 02F0B0 80053CB0 ACC00000 */   sw    $zero, ($a2)

/* 02F0B4 80053CB4 24020001 */  addiu $v0, $zero, 1
/* 02F0B8 80053CB8 10820009 */  beq   $a0, $v0, .L80053CE0
/* 02F0BC 80053CBC 00000000 */   nop   
/* 02F0C0 80053CC0 10800003 */  beqz  $a0, .L80053CD0
/* 02F0C4 80053CC4 24020002 */   addiu $v0, $zero, 2
/* 02F0C8 80053CC8 14820009 */  bne   $a0, $v0, .L80053CF0
/* 02F0CC 80053CCC 00000000 */   nop   
.L80053CD0:
/* 02F0D0 80053CD0 3C02800A */  lui   $v0, 0x800a
/* 02F0D4 80053CD4 8C42A664 */  lw    $v0, -0x599c($v0)
/* 02F0D8 80053CD8 03E00008 */  jr    $ra
/* 02F0DC 80053CDC ACA20000 */   sw    $v0, ($a1)

.L80053CE0:
/* 02F0E0 80053CE0 3C02800A */  lui   $v0, 0x800a
/* 02F0E4 80053CE4 8C42A5FC */  lw    $v0, -0x5a04($v0)
/* 02F0E8 80053CE8 03E00008 */  jr    $ra
/* 02F0EC 80053CEC ACA20000 */   sw    $v0, ($a1)

.L80053CF0:
/* 02F0F0 80053CF0 03E00008 */  jr    $ra
/* 02F0F4 80053CF4 ACA00000 */   sw    $zero, ($a1)

