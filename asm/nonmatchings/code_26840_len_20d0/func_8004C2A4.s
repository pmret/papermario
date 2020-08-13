.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004C2A4
/* 0276A4 8004C2A4 0000382D */  daddu $a3, $zero, $zero
/* 0276A8 8004C2A8 30A523FF */  andi  $a1, $a1, 0x23ff
/* 0276AC 8004C2AC 3C0A8008 */  lui   $t2, 0x8008
/* 0276B0 8004C2B0 254A8464 */  addiu $t2, $t2, -0x7b9c
/* 0276B4 8004C2B4 24090001 */  addiu $t1, $zero, 1
/* 0276B8 8004C2B8 24080001 */  addiu $t0, $zero, 1
/* 0276BC 8004C2BC 2406016C */  addiu $a2, $zero, 0x16c
.L8004C2C0:
/* 0276C0 8004C2C0 00861821 */  addu  $v1, $a0, $a2
/* 0276C4 8004C2C4 94620096 */  lhu   $v0, 0x96($v1)
/* 0276C8 8004C2C8 14450008 */  bne   $v0, $a1, .L8004C2EC
/* 0276CC 8004C2CC 24E70001 */   addiu $a3, $a3, 1
/* 0276D0 8004C2D0 AC6A0000 */  sw    $t2, ($v1)
/* 0276D4 8004C2D4 AC600080 */  sw    $zero, 0x80($v1)
/* 0276D8 8004C2D8 A069009A */  sb    $t1, 0x9a($v1)
/* 0276DC 8004C2DC A06000A9 */  sb    $zero, 0xa9($v1)
/* 0276E0 8004C2E0 A468008E */  sh    $t0, 0x8e($v1)
/* 0276E4 8004C2E4 A0600098 */  sb    $zero, 0x98($v1)
/* 0276E8 8004C2E8 A0600099 */  sb    $zero, 0x99($v1)
.L8004C2EC:
/* 0276EC 8004C2EC 28E20008 */  slti  $v0, $a3, 8
/* 0276F0 8004C2F0 1440FFF3 */  bnez  $v0, .L8004C2C0
/* 0276F4 8004C2F4 24C600AC */   addiu $a2, $a2, 0xac
/* 0276F8 8004C2F8 03E00008 */  jr    $ra
/* 0276FC 8004C2FC 00000000 */   nop   

