.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A1FC
/* 13D53C 8024A1FC 24040004 */  addiu $a0, $zero, 4
/* 13D540 8024A200 3C058027 */  lui   $a1, 0x8027
/* 13D544 8024A204 24A5FCB8 */  addiu $a1, $a1, -0x348
/* 13D548 8024A208 24020140 */  addiu $v0, $zero, 0x140
/* 13D54C 8024A20C AFA20044 */  sw    $v0, 0x44($sp)
/* 13D550 8024A210 240200F0 */  addiu $v0, $zero, 0xf0
/* 13D554 8024A214 AFA00024 */  sw    $zero, 0x24($sp)
/* 13D558 8024A218 AFA00028 */  sw    $zero, 0x28($sp)
/* 13D55C 8024A21C AFA0002C */  sw    $zero, 0x2c($sp)
/* 13D560 8024A220 AFA00030 */  sw    $zero, 0x30($sp)
/* 13D564 8024A224 AFA00034 */  sw    $zero, 0x34($sp)
/* 13D568 8024A228 AFA00038 */  sw    $zero, 0x38($sp)
/* 13D56C 8024A22C AFA0003C */  sw    $zero, 0x3c($sp)
/* 13D570 8024A230 AFA00040 */  sw    $zero, 0x40($sp)
/* 13D574 8024A234 AFA20048 */  sw    $v0, 0x48($sp)
/* 13D578 8024A238 0C03D4B8 */  jal   draw_box
/* 13D57C 8024A23C AFA0004C */   sw    $zero, 0x4c($sp)
/* 13D580 8024A240 0C093BA0 */  jal   func_8024EE80
/* 13D584 8024A244 2404004F */   addiu $a0, $zero, 0x4f
/* 13D588 8024A248 3C118027 */  lui   $s1, 0x8027
/* 13D58C 8024A24C 263105E4 */  addiu $s1, $s1, 0x5e4
/* 13D590 8024A250 8FAA00AC */  lw    $t2, 0xac($sp)
/* 13D594 8024A254 8E230000 */  lw    $v1, ($s1)
/* 13D598 8024A258 14600002 */  bnez  $v1, .L8024A264
/* 13D59C 8024A25C 2545000C */   addiu $a1, $t2, 0xc
/* 13D5A0 8024A260 25450015 */  addiu $a1, $t2, 0x15
.L8024A264:
/* 13D5A4 8024A264 240700FF */  addiu $a3, $zero, 0xff
/* 13D5A8 8024A268 8FAB00B0 */  lw    $t3, 0xb0($sp)
/* 13D5AC 8024A26C 24100001 */  addiu $s0, $zero, 1
/* 13D5B0 8024A270 14700002 */  bne   $v1, $s0, .L8024A27C
/* 13D5B4 8024A274 25660011 */   addiu $a2, $t3, 0x11
/* 13D5B8 8024A278 240700BF */  addiu $a3, $zero, 0xbf
.L8024A27C:
/* 13D5BC 8024A27C 0040202D */  daddu $a0, $v0, $zero
/* 13D5C0 8024A280 AFA00010 */  sw    $zero, 0x10($sp)
/* 13D5C4 8024A284 0C04993B */  jal   draw_string
/* 13D5C8 8024A288 AFB00014 */   sw    $s0, 0x14($sp)
/* 13D5CC 8024A28C 8E230000 */  lw    $v1, ($s1)
/* 13D5D0 8024A290 8FA600AC */  lw    $a2, 0xac($sp)
/* 13D5D4 8024A294 50700001 */  beql  $v1, $s0, .L8024A29C
/* 13D5D8 8024A298 24C60009 */   addiu $a2, $a2, 9
