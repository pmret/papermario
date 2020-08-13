.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80110E58
/* 0A7558 80110E58 3C028007 */  lui   $v0, 0x8007
/* 0A755C 80110E5C 8C42419C */  lw    $v0, 0x419c($v0)
/* 0A7560 80110E60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A7564 80110E64 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0A7568 80110E68 80420070 */  lb    $v0, 0x70($v0)
/* 0A756C 80110E6C 1440000C */  bnez  $v0, .L80110EA0
/* 0A7570 80110E70 24030003 */   addiu $v1, $zero, 3
/* 0A7574 80110E74 3C038026 */  lui   $v1, 0x8026
/* 0A7578 80110E78 34637FF0 */  ori   $v1, $v1, 0x7ff0
/* 0A757C 80110E7C 3C028025 */  lui   $v0, 0x8025
/* 0A7580 80110E80 3C018015 */  lui   $at, 0x8015
/* 0A7584 80110E84 AC221300 */  sw    $v0, 0x1300($at)
/* 0A7588 80110E88 3C018015 */  lui   $at, 0x8015
/* 0A758C 80110E8C AC2312C4 */  sw    $v1, 0x12c4($at)
/* 0A7590 80110E90 0C0443C4 */  jal   func_80110F10
/* 0A7594 80110E94 00000000 */   nop   
/* 0A7598 80110E98 080443B5 */  j     .L80110ED4
/* 0A759C 80110E9C 00000000 */   nop   

.L80110EA0:
/* 0A75A0 80110EA0 3C028015 */  lui   $v0, 0x8015
/* 0A75A4 80110EA4 244216F4 */  addiu $v0, $v0, 0x16f4
.L80110EA8:
/* 0A75A8 80110EA8 AC400000 */  sw    $zero, ($v0)
/* 0A75AC 80110EAC 2463FFFF */  addiu $v1, $v1, -1
/* 0A75B0 80110EB0 0461FFFD */  bgez  $v1, .L80110EA8
/* 0A75B4 80110EB4 2442FFFC */   addiu $v0, $v0, -4
/* 0A75B8 80110EB8 3C02801A */  lui   $v0, 0x801a
/* 0A75BC 80110EBC 24427000 */  addiu $v0, $v0, 0x7000
/* 0A75C0 80110EC0 3C018015 */  lui   $at, 0x8015
/* 0A75C4 80110EC4 AC221300 */  sw    $v0, 0x1300($at)
/* 0A75C8 80110EC8 24423000 */  addiu $v0, $v0, 0x3000
/* 0A75CC 80110ECC 3C018015 */  lui   $at, 0x8015
/* 0A75D0 80110ED0 AC2212C4 */  sw    $v0, 0x12c4($at)
.L80110ED4:
/* 0A75D4 80110ED4 0C044188 */  jal   get_entity_list
/* 0A75D8 80110ED8 00000000 */   nop   
/* 0A75DC 80110EDC 3C018015 */  lui   $at, 0x8015
/* 0A75E0 80110EE0 AC221470 */  sw    $v0, 0x1470($at)
/* 0A75E4 80110EE4 0C044193 */  jal   get_shadow_list
/* 0A75E8 80110EE8 00000000 */   nop   
/* 0A75EC 80110EEC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0A75F0 80110EF0 3C018015 */  lui   $at, 0x8015
/* 0A75F4 80110EF4 AC221658 */  sw    $v0, 0x1658($at)
/* 0A75F8 80110EF8 3C018015 */  lui   $at, 0x8015
/* 0A75FC 80110EFC AC2012C0 */  sw    $zero, 0x12c0($at)
/* 0A7600 80110F00 3C018015 */  lui   $at, 0x8015
/* 0A7604 80110F04 AC201324 */  sw    $zero, 0x1324($at)
/* 0A7608 80110F08 03E00008 */  jr    $ra
/* 0A760C 80110F0C 27BD0018 */   addiu $sp, $sp, 0x18

