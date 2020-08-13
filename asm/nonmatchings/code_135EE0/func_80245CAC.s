.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80245CAC
/* 138FEC 80245CAC 8E240020 */  lw    $a0, 0x20($s1)
/* 138FF0 80245CB0 0C0511F8 */  jal   func_801447E0
/* 138FF4 80245CB4 27D00055 */   addiu $s0, $fp, 0x55
/* 138FF8 80245CB8 0C093BA0 */  jal   func_8024EE80
/* 138FFC 80245CBC 24040037 */   addiu $a0, $zero, 0x37
/* 139000 80245CC0 0040202D */  daddu $a0, $v0, $zero
/* 139004 80245CC4 0280282D */  daddu $a1, $s4, $zero
/* 139008 80245CC8 0200302D */  daddu $a2, $s0, $zero
/* 13900C 80245CCC 240700FF */  addiu $a3, $zero, 0xff
/* 139010 80245CD0 24080001 */  addiu $t0, $zero, 1
/* 139014 80245CD4 AFA00010 */  sw    $zero, 0x10($sp)
/* 139018 80245CD8 0C04993B */  jal   draw_string
/* 13901C 80245CDC AFA80014 */   sw    $t0, 0x14($sp)
/* 139020 80245CE0 0260282D */  daddu $a1, $s3, $zero
/* 139024 80245CE4 0200302D */  daddu $a2, $s0, $zero
/* 139028 80245CE8 24070001 */  addiu $a3, $zero, 1
/* 13902C 80245CEC 3C048011 */  lui   $a0, 0x8011
/* 139030 80245CF0 8084F295 */  lb    $a0, -0xd6b($a0)
/* 139034 80245CF4 240800FF */  addiu $t0, $zero, 0xff
/* 139038 80245CF8 AFA00010 */  sw    $zero, 0x10($sp)
/* 13903C 80245CFC AFA80014 */  sw    $t0, 0x14($sp)
/* 139040 80245D00 0C049DA7 */  jal   draw_number
/* 139044 80245D04 AFB20018 */   sw    $s2, 0x18($sp)
/* 139048 80245D08 0C093BA0 */  jal   func_8024EE80
/* 13904C 80245D0C 24040039 */   addiu $a0, $zero, 0x39
/* 139050 80245D10 0040202D */  daddu $a0, $v0, $zero
/* 139054 80245D14 0260282D */  daddu $a1, $s3, $zero
/* 139058 80245D18 0200302D */  daddu $a2, $s0, $zero
/* 13905C 80245D1C 240700FF */  addiu $a3, $zero, 0xff
/* 139060 80245D20 24080001 */  addiu $t0, $zero, 1
/* 139064 80245D24 AFA00010 */  sw    $zero, 0x10($sp)
/* 139068 80245D28 0C04993B */  jal   draw_string
/* 13906C 80245D2C AFA80014 */   sw    $t0, 0x14($sp)
/* 139070 80245D30 02E0282D */  daddu $a1, $s7, $zero
/* 139074 80245D34 0200302D */  daddu $a2, $s0, $zero
/* 139078 80245D38 24070001 */  addiu $a3, $zero, 1
/* 13907C 80245D3C 3C048011 */  lui   $a0, 0x8011
/* 139080 80245D40 8084F296 */  lb    $a0, -0xd6a($a0)
/* 139084 80245D44 240800FF */  addiu $t0, $zero, 0xff
/* 139088 80245D48 AFA00010 */  sw    $zero, 0x10($sp)
/* 13908C 80245D4C AFA80014 */  sw    $t0, 0x14($sp)
/* 139090 80245D50 0C049DA7 */  jal   draw_number
/* 139094 80245D54 AFB20018 */   sw    $s2, 0x18($sp)
/* 139098 80245D58 24040002 */  addiu $a0, $zero, 2
