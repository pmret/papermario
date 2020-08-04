.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel MakeStatusField
/* 182474 80253B94 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 182478 80253B98 AFB10014 */  sw    $s1, 0x14($sp)
/* 18247C 80253B9C 0080882D */  daddu $s1, $a0, $zero
/* 182480 80253BA0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 182484 80253BA4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 182488 80253BA8 AFB20018 */  sw    $s2, 0x18($sp)
/* 18248C 80253BAC AFB00010 */  sw    $s0, 0x10($sp)
/* 182490 80253BB0 8E30000C */  lw    $s0, 0xc($s1)
/* 182494 80253BB4 8E130000 */  lw    $s3, ($s0)
/* 182498 80253BB8 26100004 */  addiu $s0, $s0, 4
/* 18249C 80253BBC 8E120000 */  lw    $s2, ($s0)
/* 1824A0 80253BC0 26100004 */  addiu $s0, $s0, 4
/* 1824A4 80253BC4 8E050000 */  lw    $a1, ($s0)
/* 1824A8 80253BC8 0C0B1EAF */  jal   get_variable
/* 1824AC 80253BCC 26100004 */   addiu $s0, $s0, 4
/* 1824B0 80253BD0 0220202D */  daddu $a0, $s1, $zero
/* 1824B4 80253BD4 8E050000 */  lw    $a1, ($s0)
/* 1824B8 80253BD8 0C0B1EAF */  jal   get_variable
/* 1824BC 80253BDC 0040802D */   daddu $s0, $v0, $zero
/* 1824C0 80253BE0 0220202D */  daddu $a0, $s1, $zero
/* 1824C4 80253BE4 0260282D */  daddu $a1, $s3, $zero
/* 1824C8 80253BE8 00021200 */  sll   $v0, $v0, 8
/* 1824CC 80253BEC 3C038000 */  lui   $v1, 0x8000
/* 1824D0 80253BF0 00431025 */  or    $v0, $v0, $v1
/* 1824D4 80253BF4 02429025 */  or    $s2, $s2, $v0
/* 1824D8 80253BF8 0C0B2026 */  jal   set_variable
/* 1824DC 80253BFC 02503025 */   or    $a2, $s2, $s0
/* 1824E0 80253C00 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1824E4 80253C04 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1824E8 80253C08 8FB20018 */  lw    $s2, 0x18($sp)
/* 1824EC 80253C0C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1824F0 80253C10 8FB00010 */  lw    $s0, 0x10($sp)
/* 1824F4 80253C14 24020002 */  addiu $v0, $zero, 2
/* 1824F8 80253C18 03E00008 */  jr    $ra
/* 1824FC 80253C1C 27BD0028 */   addiu $sp, $sp, 0x28

