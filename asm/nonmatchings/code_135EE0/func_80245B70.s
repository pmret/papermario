.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80245B70
/* 138EB0 80245B70 AFA80014 */  sw    $t0, 0x14($sp)
/* 138EB4 80245B74 0C049DA7 */  jal   draw_number
/* 138EB8 80245B78 AFB20018 */   sw    $s2, 0x18($sp)
/* 138EBC 80245B7C 0260282D */  daddu $a1, $s3, $zero
/* 138EC0 80245B80 8E24002C */  lw    $a0, 0x2c($s1)
/* 138EC4 80245B84 0C051261 */  jal   set_icon_render_pos
/* 138EC8 80245B88 02A0302D */   daddu $a2, $s5, $zero
/* 138ECC 80245B8C 8E24002C */  lw    $a0, 0x2c($s1)
/* 138ED0 80245B90 0C0511F8 */  jal   func_801447E0
/* 138ED4 80245B94 27D00033 */   addiu $s0, $fp, 0x33
/* 138ED8 80245B98 0000202D */  daddu $a0, $zero, $zero
/* 138EDC 80245B9C 8FA80084 */  lw    $t0, 0x84($sp)
/* 138EE0 80245BA0 27C60023 */  addiu $a2, $fp, 0x23
/* 138EE4 80245BA4 25160015 */  addiu $s6, $t0, 0x15
/* 138EE8 80245BA8 0C093BA5 */  jal   func_8024EE94
/* 138EEC 80245BAC 02C0282D */   daddu $a1, $s6, $zero
/* 138EF0 80245BB0 27C60039 */  addiu $a2, $fp, 0x39
/* 138EF4 80245BB4 8FA80084 */  lw    $t0, 0x84($sp)
/* 138EF8 80245BB8 8E24001C */  lw    $a0, 0x1c($s1)
/* 138EFC 80245BBC 25150034 */  addiu $s5, $t0, 0x34
/* 138F00 80245BC0 0C051261 */  jal   set_icon_render_pos
/* 138F04 80245BC4 02A0282D */   daddu $a1, $s5, $zero
/* 138F08 80245BC8 8E24001C */  lw    $a0, 0x1c($s1)
/* 138F0C 80245BCC 0C0511F8 */  jal   func_801447E0
/* 138F10 80245BD0 00000000 */   nop   
/* 138F14 80245BD4 0C093BA0 */  jal   func_8024EE80
/* 138F18 80245BD8 24040036 */   addiu $a0, $zero, 0x36
/* 138F1C 80245BDC 0040202D */  daddu $a0, $v0, $zero
/* 138F20 80245BE0 0200302D */  daddu $a2, $s0, $zero
/* 138F24 80245BE4 8FA80084 */  lw    $t0, 0x84($sp)
/* 138F28 80245BE8 240700FF */  addiu $a3, $zero, 0xff
/* 138F2C 80245BEC AFA00010 */  sw    $zero, 0x10($sp)
/* 138F30 80245BF0 25140019 */  addiu $s4, $t0, 0x19
/* 138F34 80245BF4 0280282D */  daddu $a1, $s4, $zero
/* 138F38 80245BF8 24080001 */  addiu $t0, $zero, 1
/* 138F3C 80245BFC 0C04993B */  jal   draw_string
/* 138F40 80245C00 AFA80014 */   sw    $t0, 0x14($sp)
/* 138F44 80245C04 0200302D */  daddu $a2, $s0, $zero
/* 138F48 80245C08 8FA80084 */  lw    $t0, 0x84($sp)
/* 138F4C 80245C0C 3C048011 */  lui   $a0, 0x8011
/* 138F50 80245C10 8084F292 */  lb    $a0, -0xd6e($a0)
/* 138F54 80245C14 24070001 */  addiu $a3, $zero, 1
/* 138F58 80245C18 AFA00010 */  sw    $zero, 0x10($sp)
/* 138F5C 80245C1C AFB20018 */  sw    $s2, 0x18($sp)
/* 138F60 80245C20 2513004E */  addiu $s3, $t0, 0x4e
/* 138F64 80245C24 0260282D */  daddu $a1, $s3, $zero
/* 138F68 80245C28 240800FF */  addiu $t0, $zero, 0xff
/* 138F6C 80245C2C 0C049DA7 */  jal   draw_number
/* 138F70 80245C30 AFA80014 */   sw    $t0, 0x14($sp)
/* 138F74 80245C34 0C093BA0 */  jal   func_8024EE80
/* 138F78 80245C38 24040039 */   addiu $a0, $zero, 0x39
/* 138F7C 80245C3C 0040202D */  daddu $a0, $v0, $zero
/* 138F80 80245C40 0260282D */  daddu $a1, $s3, $zero
/* 138F84 80245C44 0200302D */  daddu $a2, $s0, $zero
/* 138F88 80245C48 240700FF */  addiu $a3, $zero, 0xff
/* 138F8C 80245C4C 24080001 */  addiu $t0, $zero, 1
/* 138F90 80245C50 AFA00010 */  sw    $zero, 0x10($sp)
/* 138F94 80245C54 0C04993B */  jal   draw_string
/* 138F98 80245C58 AFA80014 */   sw    $t0, 0x14($sp)
/* 138F9C 80245C5C 0200302D */  daddu $a2, $s0, $zero
/* 138FA0 80245C60 8FA80084 */  lw    $t0, 0x84($sp)
/* 138FA4 80245C64 3C048011 */  lui   $a0, 0x8011
/* 138FA8 80245C68 8084F293 */  lb    $a0, -0xd6d($a0)
