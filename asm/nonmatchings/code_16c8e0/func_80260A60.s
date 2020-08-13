.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80260A60
/* 18F340 80260A60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 18F344 80260A64 3C02800E */  lui   $v0, 0x800e
/* 18F348 80260A68 2442C070 */  addiu $v0, $v0, -0x3f90
/* 18F34C 80260A6C 0040202D */  daddu $a0, $v0, $zero
/* 18F350 80260A70 AFBF0010 */  sw    $ra, 0x10($sp)
/* 18F354 80260A74 8C820004 */  lw    $v0, 4($a0)
/* 18F358 80260A78 8C8300D8 */  lw    $v1, 0xd8($a0)
/* 18F35C 80260A7C 30420040 */  andi  $v0, $v0, 0x40
/* 18F360 80260A80 8C6301F4 */  lw    $v1, 0x1f4($v1)
/* 18F364 80260A84 1040000A */  beqz  $v0, .L80260AB0
/* 18F368 80260A88 3C06000A */   lui   $a2, 0xa
/* 18F36C 80260A8C 3C028028 */  lui   $v0, 0x8028
/* 18F370 80260A90 2442340C */  addiu $v0, $v0, 0x340c
/* 18F374 80260A94 AC620094 */  sw    $v0, 0x94($v1)
/* 18F378 80260A98 34C60002 */  ori   $a2, $a2, 2
/* 18F37C 80260A9C 0000202D */  daddu $a0, $zero, $zero
/* 18F380 80260AA0 0C098F3F */  jal   set_animation
/* 18F384 80260AA4 0080282D */   daddu $a1, $a0, $zero
/* 18F388 80260AA8 080982B2 */  j     .L80260AC8
/* 18F38C 80260AAC 00000000 */   nop   

.L80260AB0:
/* 18F390 80260AB0 8082009A */  lb    $v0, 0x9a($a0)
/* 18F394 80260AB4 14400004 */  bnez  $v0, .L80260AC8
/* 18F398 80260AB8 00000000 */   nop   
/* 18F39C 80260ABC 3C028028 */  lui   $v0, 0x8028
/* 18F3A0 80260AC0 24423238 */  addiu $v0, $v0, 0x3238
/* 18F3A4 80260AC4 AC620094 */  sw    $v0, 0x94($v1)
.L80260AC8:
.L80260AC8:
/* 18F3A8 80260AC8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 18F3AC 80260ACC 03E00008 */  jr    $ra
/* 18F3B0 80260AD0 27BD0018 */   addiu $sp, $sp, 0x18

/* 18F3B4 80260AD4 3C03800E */  lui   $v1, 0x800e
/* 18F3B8 80260AD8 8C63C148 */  lw    $v1, -0x3eb8($v1)
/* 18F3BC 80260ADC 90620210 */  lbu   $v0, 0x210($v1)
/* 18F3C0 80260AE0 80630214 */  lb    $v1, 0x214($v1)
/* 18F3C4 80260AE4 2442FFFD */  addiu $v0, $v0, -3
/* 18F3C8 80260AE8 2C450006 */  sltiu $a1, $v0, 6
/* 18F3CC 80260AEC 2402000C */  addiu $v0, $zero, 0xc
/* 18F3D0 80260AF0 50620001 */  beql  $v1, $v0, .L80260AF8
/* 18F3D4 80260AF4 24050001 */   addiu $a1, $zero, 1
.L80260AF8:
/* 18F3D8 80260AF8 AC850084 */  sw    $a1, 0x84($a0)
/* 18F3DC 80260AFC 03E00008 */  jr    $ra
/* 18F3E0 80260B00 24020002 */   addiu $v0, $zero, 2

