.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800555E4
/* 0309E4 800555E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0309E8 800555E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0309EC 800555EC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0309F0 800555F0 0C01430C */  jal   func_80050C30
/* 0309F4 800555F4 0080802D */   daddu $s0, $a0, $zero
/* 0309F8 800555F8 14400003 */  bnez  $v0, .L80055608
/* 0309FC 800555FC 00000000 */   nop   
/* 030A00 80055600 0C014414 */  jal   func_80051050
/* 030A04 80055604 0200202D */   daddu $a0, $s0, $zero
.L80055608:
/* 030A08 80055608 8FBF0014 */  lw    $ra, 0x14($sp)
/* 030A0C 8005560C 8FB00010 */  lw    $s0, 0x10($sp)
/* 030A10 80055610 03E00008 */  jr    $ra
/* 030A14 80055614 27BD0018 */   addiu $sp, $sp, 0x18

/* 030A18 80055618 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030A1C 8005561C AFB10014 */  sw    $s1, 0x14($sp)
/* 030A20 80055620 0080882D */  daddu $s1, $a0, $zero
/* 030A24 80055624 AFB20018 */  sw    $s2, 0x18($sp)
/* 030A28 80055628 00A0902D */  daddu $s2, $a1, $zero
/* 030A2C 8005562C AFBF001C */  sw    $ra, 0x1c($sp)
/* 030A30 80055630 0C01430C */  jal   func_80050C30
/* 030A34 80055634 AFB00010 */   sw    $s0, 0x10($sp)
/* 030A38 80055638 0040802D */  daddu $s0, $v0, $zero
/* 030A3C 8005563C 16000005 */  bnez  $s0, .L80055654
/* 030A40 80055640 0200102D */   daddu $v0, $s0, $zero
/* 030A44 80055644 0220202D */  daddu $a0, $s1, $zero
/* 030A48 80055648 0C014315 */  jal   func_80050C54
/* 030A4C 8005564C 0240282D */   daddu $a1, $s2, $zero
/* 030A50 80055650 0200102D */  daddu $v0, $s0, $zero
.L80055654:
/* 030A54 80055654 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030A58 80055658 8FB20018 */  lw    $s2, 0x18($sp)
/* 030A5C 8005565C 8FB10014 */  lw    $s1, 0x14($sp)
/* 030A60 80055660 8FB00010 */  lw    $s0, 0x10($sp)
/* 030A64 80055664 03E00008 */  jr    $ra
/* 030A68 80055668 27BD0020 */   addiu $sp, $sp, 0x20

/* 030A6C 8005566C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 030A70 80055670 AFB10014 */  sw    $s1, 0x14($sp)
/* 030A74 80055674 0080882D */  daddu $s1, $a0, $zero
/* 030A78 80055678 AFB20018 */  sw    $s2, 0x18($sp)
/* 030A7C 8005567C 00A0902D */  daddu $s2, $a1, $zero
/* 030A80 80055680 AFB3001C */  sw    $s3, 0x1c($sp)
/* 030A84 80055684 00C0982D */  daddu $s3, $a2, $zero
/* 030A88 80055688 AFBF0020 */  sw    $ra, 0x20($sp)
/* 030A8C 8005568C 0C01430C */  jal   func_80050C30
/* 030A90 80055690 AFB00010 */   sw    $s0, 0x10($sp)
/* 030A94 80055694 0040802D */  daddu $s0, $v0, $zero
/* 030A98 80055698 16000006 */  bnez  $s0, .L800556B4
/* 030A9C 8005569C 0200102D */   daddu $v0, $s0, $zero
/* 030AA0 800556A0 0220202D */  daddu $a0, $s1, $zero
/* 030AA4 800556A4 0240282D */  daddu $a1, $s2, $zero
/* 030AA8 800556A8 0C0143F4 */  jal   func_80050FD0
/* 030AAC 800556AC 0260302D */   daddu $a2, $s3, $zero
/* 030AB0 800556B0 0200102D */  daddu $v0, $s0, $zero
.L800556B4:
/* 030AB4 800556B4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 030AB8 800556B8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 030ABC 800556BC 8FB20018 */  lw    $s2, 0x18($sp)
/* 030AC0 800556C0 8FB10014 */  lw    $s1, 0x14($sp)
/* 030AC4 800556C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 030AC8 800556C8 03E00008 */  jr    $ra
/* 030ACC 800556CC 27BD0028 */   addiu $sp, $sp, 0x28

