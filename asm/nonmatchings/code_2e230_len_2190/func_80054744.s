.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80054744
/* 02FB44 80054744 0000182D */  daddu $v1, $zero, $zero
/* 02FB48 80054748 3C06800A */  lui   $a2, 0x800a
/* 02FB4C 8005474C 8CC6A5C0 */  lw    $a2, -0x5a40($a2)
/* 02FB50 80054750 2484FFFF */  addiu $a0, $a0, -1
/* 02FB54 80054754 2C820006 */  sltiu $v0, $a0, 6
/* 02FB58 80054758 10400019 */  beqz  $v0, .L800547C0
/* 02FB5C 8005475C 00052900 */   sll   $a1, $a1, 4
/* 02FB60 80054760 00041080 */  sll   $v0, $a0, 2
/* 02FB64 80054764 3C01800A */  lui   $at, 0x800a
/* 02FB68 80054768 00220821 */  addu  $at, $at, $v0
/* 02FB6C 8005476C 8C2288F0 */  lw    $v0, -0x7710($at)
/* 02FB70 80054770 00400008 */  jr    $v0
/* 02FB74 80054774 00000000 */   nop   
/* 02FB78 80054778 00051080 */  sll   $v0, $a1, 2
/* 02FB7C 8005477C 080151EF */  j     .L800547BC
/* 02FB80 80054780 244204EC */   addiu $v0, $v0, 0x4ec

/* 02FB84 80054784 00051080 */  sll   $v0, $a1, 2
/* 02FB88 80054788 080151EF */  j     .L800547BC
/* 02FB8C 8005478C 244205EC */   addiu $v0, $v0, 0x5ec

/* 02FB90 80054790 00051080 */  sll   $v0, $a1, 2
/* 02FB94 80054794 080151EF */  j     .L800547BC
/* 02FB98 80054798 244209EC */   addiu $v0, $v0, 0x9ec

/* 02FB9C 8005479C 00051080 */  sll   $v0, $a1, 2
/* 02FBA0 800547A0 080151EF */  j     .L800547BC
/* 02FBA4 800547A4 24420DEC */   addiu $v0, $v0, 0xdec

/* 02FBA8 800547A8 00051080 */  sll   $v0, $a1, 2
/* 02FBAC 800547AC 080151EF */  j     .L800547BC
/* 02FBB0 800547B0 244211EC */   addiu $v0, $v0, 0x11ec

/* 02FBB4 800547B4 00051080 */  sll   $v0, $a1, 2
/* 02FBB8 800547B8 244200EC */  addiu $v0, $v0, 0xec
.L800547BC:
/* 02FBBC 800547BC 00C21821 */  addu  $v1, $a2, $v0
.L800547C0:
/* 02FBC0 800547C0 03E00008 */  jr    $ra
/* 02FBC4 800547C4 0060102D */   daddu $v0, $v1, $zero

