.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055E48
/* 031248 80055E48 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03124C 80055E4C AFB1001C */  sw    $s1, 0x1c($sp)
/* 031250 80055E50 00A0882D */  daddu $s1, $a1, $zero
/* 031254 80055E54 27A50010 */  addiu $a1, $sp, 0x10
/* 031258 80055E58 27A60014 */  addiu $a2, $sp, 0x14
/* 03125C 80055E5C AFBF0020 */  sw    $ra, 0x20($sp)
/* 031260 80055E60 0C01573A */  jal   func_80055CE8
/* 031264 80055E64 AFB00018 */   sw    $s0, 0x18($sp)
/* 031268 80055E68 0040802D */  daddu $s0, $v0, $zero
/* 03126C 80055E6C 1600000C */  bnez  $s0, .L80055EA0
/* 031270 80055E70 0200102D */   daddu $v0, $s0, $zero
/* 031274 80055E74 0C0157AD */  jal   func_80055EB4
/* 031278 80055E78 0220202D */   daddu $a0, $s1, $zero
/* 03127C 80055E7C 10400006 */  beqz  $v0, .L80055E98
/* 031280 80055E80 0040282D */   daddu $a1, $v0, $zero
/* 031284 80055E84 8FA40014 */  lw    $a0, 0x14($sp)
/* 031288 80055E88 0C01421F */  jal   func_8005087C
/* 03128C 80055E8C 0000302D */   daddu $a2, $zero, $zero
/* 031290 80055E90 080157A8 */  j     .L80055EA0
/* 031294 80055E94 0200102D */   daddu $v0, $s0, $zero

.L80055E98:
/* 031298 80055E98 2410000B */  addiu $s0, $zero, 0xb
/* 03129C 80055E9C 0200102D */  daddu $v0, $s0, $zero
.L80055EA0:
/* 0312A0 80055EA0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0312A4 80055EA4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0312A8 80055EA8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0312AC 80055EAC 03E00008 */  jr    $ra
/* 0312B0 80055EB0 27BD0028 */   addiu $sp, $sp, 0x28

