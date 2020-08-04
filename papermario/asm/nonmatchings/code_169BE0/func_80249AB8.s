.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249AB8
/* 16A318 80249AB8 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 16A31C 80249ABC AFB70034 */  sw    $s7, 0x34($sp)
/* 16A320 80249AC0 8FB70050 */  lw    $s7, 0x50($sp)
/* 16A324 80249AC4 AFB60030 */  sw    $s6, 0x30($sp)
/* 16A328 80249AC8 8FB60054 */  lw    $s6, 0x54($sp)
/* 16A32C 80249ACC AFB5002C */  sw    $s5, 0x2c($sp)
/* 16A330 80249AD0 8FB50058 */  lw    $s5, 0x58($sp)
/* 16A334 80249AD4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 16A338 80249AD8 0080F02D */  daddu $fp, $a0, $zero
/* 16A33C 80249ADC AFB20020 */  sw    $s2, 0x20($sp)
/* 16A340 80249AE0 00A0902D */  daddu $s2, $a1, $zero
/* 16A344 80249AE4 AFB40028 */  sw    $s4, 0x28($sp)
/* 16A348 80249AE8 8FB4005C */  lw    $s4, 0x5c($sp)
/* 16A34C 80249AEC 00C0282D */  daddu $a1, $a2, $zero
/* 16A350 80249AF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 16A354 80249AF4 0000802D */  daddu $s0, $zero, $zero
/* 16A358 80249AF8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 16A35C 80249AFC AFB30024 */  sw    $s3, 0x24($sp)
/* 16A360 80249B00 AFB1001C */  sw    $s1, 0x1c($sp)
/* 16A364 80249B04 1A400010 */  blez  $s2, .L80249B48
/* 16A368 80249B08 AFA7004C */   sw    $a3, 0x4c($sp)
/* 16A36C 80249B0C 241300F7 */  addiu $s3, $zero, 0xf7
/* 16A370 80249B10 00A0882D */  daddu $s1, $a1, $zero
.L80249B14:
/* 16A374 80249B14 03D01021 */  addu  $v0, $fp, $s0
/* 16A378 80249B18 90440000 */  lbu   $a0, ($v0)
/* 16A37C 80249B1C 10930006 */  beq   $a0, $s3, .L80249B38
/* 16A380 80249B20 0220282D */   daddu $a1, $s1, $zero
/* 16A384 80249B24 8FA6004C */  lw    $a2, 0x4c($sp)
/* 16A388 80249B28 02E0382D */  daddu $a3, $s7, $zero
/* 16A38C 80249B2C AFB60010 */  sw    $s6, 0x10($sp)
.L80249B30:
/* 16A390 80249B30 0C09265F */  jal   func_8024997C
/* 16A394 80249B34 AFB50014 */   sw    $s5, 0x14($sp)
.L80249B38:
/* 16A398 80249B38 26100001 */  addiu $s0, $s0, 1
/* 16A39C 80249B3C 0212102A */  slt   $v0, $s0, $s2
/* 16A3A0 80249B40 1440FFF4 */  bnez  $v0, .L80249B14
/* 16A3A4 80249B44 02348821 */   addu  $s1, $s1, $s4
.L80249B48:
/* 16A3A8 80249B48 8FBF003C */  lw    $ra, 0x3c($sp)
/* 16A3AC 80249B4C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 16A3B0 80249B50 8FB70034 */  lw    $s7, 0x34($sp)
/* 16A3B4 80249B54 8FB60030 */  lw    $s6, 0x30($sp)
/* 16A3B8 80249B58 8FB5002C */  lw    $s5, 0x2c($sp)
/* 16A3BC 80249B5C 8FB40028 */  lw    $s4, 0x28($sp)
/* 16A3C0 80249B60 8FB30024 */  lw    $s3, 0x24($sp)
/* 16A3C4 80249B64 8FB20020 */  lw    $s2, 0x20($sp)
/* 16A3C8 80249B68 8FB1001C */  lw    $s1, 0x1c($sp)
/* 16A3CC 80249B6C 8FB00018 */  lw    $s0, 0x18($sp)
/* 16A3D0 80249B70 03E00008 */  jr    $ra
/* 16A3D4 80249B74 27BD0040 */   addiu $sp, $sp, 0x40

/* 16A3D8 80249B78 00000000 */  nop   
/* 16A3DC 80249B7C 00000000 */  nop   
