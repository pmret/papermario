.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80245D78
/* 1390B8 80245D78 8E240024 */  lw    $a0, 0x24($s1)
/* 1390BC 80245D7C 0C0511F8 */  jal   func_801447E0
/* 1390C0 80245D80 27D00077 */   addiu $s0, $fp, 0x77
/* 1390C4 80245D84 0C093BA0 */  jal   func_8024EE80
/* 1390C8 80245D88 24040038 */   addiu $a0, $zero, 0x38
/* 1390CC 80245D8C 0040202D */  daddu $a0, $v0, $zero
/* 1390D0 80245D90 0280282D */  daddu $a1, $s4, $zero
/* 1390D4 80245D94 0200302D */  daddu $a2, $s0, $zero
/* 1390D8 80245D98 240700FF */  addiu $a3, $zero, 0xff
/* 1390DC 80245D9C 24080001 */  addiu $t0, $zero, 1
/* 1390E0 80245DA0 AFA00010 */  sw    $zero, 0x10($sp)
/* 1390E4 80245DA4 0C04993B */  jal   draw_string
/* 1390E8 80245DA8 AFA80014 */   sw    $t0, 0x14($sp)
/* 1390EC 80245DAC 0260282D */  daddu $a1, $s3, $zero
/* 1390F0 80245DB0 0200302D */  daddu $a2, $s0, $zero
/* 1390F4 80245DB4 24070001 */  addiu $a3, $zero, 1
/* 1390F8 80245DB8 3C048011 */  lui   $a0, 0x8011
/* 1390FC 80245DBC 8084F298 */  lb    $a0, -0xd68($a0)
/* 139100 80245DC0 240800FF */  addiu $t0, $zero, 0xff
/* 139104 80245DC4 AFA00010 */  sw    $zero, 0x10($sp)
/* 139108 80245DC8 AFA80014 */  sw    $t0, 0x14($sp)
/* 13910C 80245DCC 0C049DA7 */  jal   draw_number
/* 139110 80245DD0 AFB20018 */   sw    $s2, 0x18($sp)
/* 139114 80245DD4 8FA50050 */  lw    $a1, 0x50($sp)
/* 139118 80245DD8 8E240018 */  lw    $a0, 0x18($s1)
/* 13911C 80245DDC 0C051261 */  jal   set_icon_render_pos
/* 139120 80245DE0 27C6008C */   addiu $a2, $fp, 0x8c
/* 139124 80245DE4 8E240018 */  lw    $a0, 0x18($s1)
/* 139128 80245DE8 0C0511F8 */  jal   func_801447E0
/* 13912C 80245DEC 27D50085 */   addiu $s5, $fp, 0x85
/* 139130 80245DF0 0C093BA0 */  jal   func_8024EE80
/* 139134 80245DF4 24040035 */   addiu $a0, $zero, 0x35
/* 139138 80245DF8 0040202D */  daddu $a0, $v0, $zero
/* 13913C 80245DFC 02A0302D */  daddu $a2, $s5, $zero
/* 139140 80245E00 240700FF */  addiu $a3, $zero, 0xff
/* 139144 80245E04 8FA50054 */  lw    $a1, 0x54($sp)
/* 139148 80245E08 2408000A */  addiu $t0, $zero, 0xa
/* 13914C 80245E0C AFA80010 */  sw    $t0, 0x10($sp)
/* 139150 80245E10 24080001 */  addiu $t0, $zero, 1
/* 139154 80245E14 0C04993B */  jal   draw_string
/* 139158 80245E18 AFA80014 */   sw    $t0, 0x14($sp)
/* 13915C 80245E1C 3C020149 */  lui   $v0, 0x149
/* 139160 80245E20 3C148011 */  lui   $s4, 0x8011
/* 139164 80245E24 8E94F54C */  lw    $s4, -0xab4($s4)
/* 139168 80245E28 344296FF */  ori   $v0, $v0, 0x96ff
/* 13916C 80245E2C 0054102A */  slt   $v0, $v0, $s4
/* 139170 80245E30 10400003 */  beqz  $v0, .L80245E40
/* 139174 80245E34 3C021F11 */   lui   $v0, 0x1f11
/* 139178 80245E38 3C140149 */  lui   $s4, 0x149
/* 13917C 80245E3C 369496FF */  ori   $s4, $s4, 0x96ff
.L80245E40:
/* 139180 80245E40 3442A4A5 */  ori   $v0, $v0, 0xa4a5
/* 139184 80245E44 3C036666 */  lui   $v1, 0x6666
/* 139188 80245E48 34636667 */  ori   $v1, $v1, 0x6667
/* 13918C 80245E4C 02A0302D */  daddu $a2, $s5, $zero
/* 139190 80245E50 24070001 */  addiu $a3, $zero, 1
/* 139194 80245E54 00149FC3 */  sra   $s3, $s4, 0x1f
/* 139198 80245E58 02820018 */  mult  $s4, $v0
/* 13919C 80245E5C 8FA80084 */  lw    $t0, 0x84($sp)
/* 1391A0 80245E60 24120002 */  addiu $s2, $zero, 2
/* 1391A4 80245E64 AFB20018 */  sw    $s2, 0x18($sp)
/* 1391A8 80245E68 250500ED */  addiu $a1, $t0, 0xed
/* 1391AC 80245E6C 00004010 */  mfhi  $t0
/* 1391B0 80245E70 00088483 */  sra   $s0, $t0, 0x12
/* 1391B4 80245E74 02138023 */  subu  $s0, $s0, $s3
/* 1391B8 80245E78 2408000A */  addiu $t0, $zero, 0xa
/* 1391BC 80245E7C 02030018 */  mult  $s0, $v1
/* 1391C0 80245E80 AFA80010 */  sw    $t0, 0x10($sp)
/* 1391C4 80245E84 240800FF */  addiu $t0, $zero, 0xff
/* 1391C8 80245E88 00101FC3 */  sra   $v1, $s0, 0x1f
/* 1391CC 80245E8C AFA80014 */  sw    $t0, 0x14($sp)
/* 1391D0 80245E90 00004010 */  mfhi  $t0
/* 1391D4 80245E94 02481007 */  srav  $v0, $t0, $s2
/* 1391D8 80245E98 00431023 */  subu  $v0, $v0, $v1
/* 1391DC 80245E9C 02422004 */  sllv  $a0, $v0, $s2
/* 1391E0 80245EA0 00822021 */  addu  $a0, $a0, $v0
/* 1391E4 80245EA4 00E42004 */  sllv  $a0, $a0, $a3
/* 1391E8 80245EA8 0C049DA7 */  jal   draw_number
/* 1391EC 80245EAC 02042023 */   subu  $a0, $s0, $a0
/* 1391F0 80245EB0 3C029B58 */  lui   $v0, 0x9b58
/* 1391F4 80245EB4 34423739 */  ori   $v0, $v0, 0x3739
/* 1391F8 80245EB8 02A0302D */  daddu $a2, $s5, $zero
/* 1391FC 80245EBC 24070001 */  addiu $a3, $zero, 1
/* 139200 80245EC0 02502004 */  sllv  $a0, $s0, $s2
/* 139204 80245EC4 00902021 */  addu  $a0, $a0, $s0
/* 139208 80245EC8 00E42004 */  sllv  $a0, $a0, $a3
/* 13920C 80245ECC 8FA80084 */  lw    $t0, 0x84($sp)
/* 139210 80245ED0 02820018 */  mult  $s4, $v0
/* 139214 80245ED4 AFB20018 */  sw    $s2, 0x18($sp)
/* 139218 80245ED8 250500F6 */  addiu $a1, $t0, 0xf6
/* 13921C 80245EDC 2408000A */  addiu $t0, $zero, 0xa
/* 139220 80245EE0 AFA80010 */  sw    $t0, 0x10($sp)
/* 139224 80245EE4 240800FF */  addiu $t0, $zero, 0xff
/* 139228 80245EE8 AFA80014 */  sw    $t0, 0x14($sp)
/* 13922C 80245EEC 00004010 */  mfhi  $t0
/* 139230 80245EF0 01148821 */  addu  $s1, $t0, $s4
/* 139234 80245EF4 00118C43 */  sra   $s1, $s1, 0x11
/* 139238 80245EF8 02338823 */  subu  $s1, $s1, $s3
/* 13923C 80245EFC 0C049DA7 */  jal   draw_number
/* 139240 80245F00 02242023 */   subu  $a0, $s1, $a0
/* 139244 80245F04 0C093BA0 */  jal   func_8024EE80
/* 139248 80245F08 2404003A */   addiu $a0, $zero, 0x3a
/* 13924C 80245F0C 0040202D */  daddu $a0, $v0, $zero
/* 139250 80245F10 27C60084 */  addiu $a2, $fp, 0x84
/* 139254 80245F14 8FA80084 */  lw    $t0, 0x84($sp)
/* 139258 80245F18 240700FF */  addiu $a3, $zero, 0xff
/* 13925C 80245F1C 25100101 */  addiu $s0, $t0, 0x101
/* 139260 80245F20 0200282D */  daddu $a1, $s0, $zero
/* 139264 80245F24 2408000A */  addiu $t0, $zero, 0xa
/* 139268 80245F28 AFA80010 */  sw    $t0, 0x10($sp)
/* 13926C 80245F2C 24080001 */  addiu $t0, $zero, 1
/* 139270 80245F30 0C04993B */  jal   draw_string
/* 139274 80245F34 AFA80014 */   sw    $t0, 0x14($sp)
/* 139278 80245F38 0C093BA0 */  jal   func_8024EE80
/* 13927C 80245F3C 2404003A */   addiu $a0, $zero, 0x3a
/* 139280 80245F40 0040202D */  daddu $a0, $v0, $zero
/* 139284 80245F44 0200282D */  daddu $a1, $s0, $zero
/* 139288 80245F48 27C6007F */  addiu $a2, $fp, 0x7f
/* 13928C 80245F4C 240700FF */  addiu $a3, $zero, 0xff
/* 139290 80245F50 2408000A */  addiu $t0, $zero, 0xa
/* 139294 80245F54 AFA80010 */  sw    $t0, 0x10($sp)
/* 139298 80245F58 24080001 */  addiu $t0, $zero, 1
/* 13929C 80245F5C 0C04993B */  jal   draw_string
/* 1392A0 80245F60 AFA80014 */   sw    $t0, 0x14($sp)
/* 1392A4 80245F64 3C027482 */  lui   $v0, 0x7482
/* 1392A8 80245F68 3442296B */  ori   $v0, $v0, 0x296b
/* 1392AC 80245F6C 02A0302D */  daddu $a2, $s5, $zero
/* 1392B0 80245F70 24070001 */  addiu $a3, $zero, 1
/* 1392B4 80245F74 00F12004 */  sllv  $a0, $s1, $a3
/* 1392B8 80245F78 00912021 */  addu  $a0, $a0, $s1
/* 1392BC 80245F7C 00E42004 */  sllv  $a0, $a0, $a3
/* 1392C0 80245F80 8FA80084 */  lw    $t0, 0x84($sp)
/* 1392C4 80245F84 02820018 */  mult  $s4, $v0
/* 1392C8 80245F88 AFB20018 */  sw    $s2, 0x18($sp)
/* 1392CC 80245F8C 25050108 */  addiu $a1, $t0, 0x108
/* 1392D0 80245F90 2408000A */  addiu $t0, $zero, 0xa
/* 1392D4 80245F94 AFA80010 */  sw    $t0, 0x10($sp)
/* 1392D8 80245F98 240800FF */  addiu $t0, $zero, 0xff
/* 1392DC 80245F9C AFA80014 */  sw    $t0, 0x14($sp)
/* 1392E0 80245FA0 00004010 */  mfhi  $t0
/* 1392E4 80245FA4 00088383 */  sra   $s0, $t0, 0xe
/* 1392E8 80245FA8 02138023 */  subu  $s0, $s0, $s3
/* 1392EC 80245FAC 0C049DA7 */  jal   draw_number
/* 1392F0 80245FB0 02042023 */   subu  $a0, $s0, $a0
/* 1392F4 80245FB4 3C0291A2 */  lui   $v0, 0x91a2
/* 1392F8 80245FB8 3442B3C5 */  ori   $v0, $v0, 0xb3c5
/* 1392FC 80245FBC 02A0302D */  daddu $a2, $s5, $zero
/* 139300 80245FC0 24070001 */  addiu $a3, $zero, 1
/* 139304 80245FC4 02502004 */  sllv  $a0, $s0, $s2
/* 139308 80245FC8 00902021 */  addu  $a0, $a0, $s0
/* 13930C 80245FCC 00E42004 */  sllv  $a0, $a0, $a3
/* 139310 80245FD0 8FA80084 */  lw    $t0, 0x84($sp)
/* 139314 80245FD4 02820018 */  mult  $s4, $v0
/* 139318 80245FD8 AFB20018 */  sw    $s2, 0x18($sp)
/* 13931C 80245FDC 25050111 */  addiu $a1, $t0, 0x111
/* 139320 80245FE0 2408000A */  addiu $t0, $zero, 0xa
