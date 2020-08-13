.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246298
/* 1395D8 80246298 0C093BA0 */  jal   func_8024EE80
/* 1395DC 8024629C 8C84F390 */   lw    $a0, -0xc70($a0)
/* 1395E0 802462A0 0040202D */  daddu $a0, $v0, $zero
/* 1395E4 802462A4 0240282D */  daddu $a1, $s2, $zero
/* 1395E8 802462A8 27C60030 */  addiu $a2, $fp, 0x30
/* 1395EC 802462AC 240700FF */  addiu $a3, $zero, 0xff
/* 1395F0 802462B0 AFA00010 */  sw    $zero, 0x10($sp)
/* 1395F4 802462B4 0C04993B */  jal   draw_string
/* 1395F8 802462B8 AFB70014 */   sw    $s7, 0x14($sp)
/* 1395FC 802462BC 24040006 */  addiu $a0, $zero, 6
/* 139600 802462C0 8FA80084 */  lw    $t0, 0x84($sp)
/* 139604 802462C4 27C60045 */  addiu $a2, $fp, 0x45
/* 139608 802462C8 0C093BA5 */  jal   func_8024EE94
/* 13960C 802462CC 25050082 */   addiu $a1, $t0, 0x82
/* 139610 802462D0 24040005 */  addiu $a0, $zero, 5
/* 139614 802462D4 8FA80084 */  lw    $t0, 0x84($sp)
/* 139618 802462D8 27C6003C */  addiu $a2, $fp, 0x3c
/* 13961C 802462DC 0C093BA5 */  jal   func_8024EE94
/* 139620 802462E0 2505008A */   addiu $a1, $t0, 0x8a
/* 139624 802462E4 3C178011 */  lui   $s7, 0x8011
/* 139628 802462E8 26F7F290 */  addiu $s7, $s7, -0xd70
/* 13962C 802462EC 0260902D */  daddu $s2, $s3, $zero
