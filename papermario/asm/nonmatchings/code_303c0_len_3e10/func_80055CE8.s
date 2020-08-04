.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055CE8
/* 0310E8 80055CE8 3C07800A */  lui   $a3, 0x800a
/* 0310EC 80055CEC 8CE7A5C0 */  lw    $a3, -0x5a40($a3)
/* 0310F0 80055CF0 8CE3005C */  lw    $v1, 0x5c($a3)
/* 0310F4 80055CF4 8C620008 */  lw    $v0, 8($v1)
/* 0310F8 80055CF8 14820005 */  bne   $a0, $v0, .L80055D10
/* 0310FC 80055CFC 0000402D */   daddu $t0, $zero, $zero
/* 031100 80055D00 3C02800A */  lui   $v0, 0x800a
/* 031104 80055D04 8C42A664 */  lw    $v0, -0x599c($v0)
/* 031108 80055D08 0801574B */  j     .L80055D2C
/* 03110C 80055D0C ACC20000 */   sw    $v0, ($a2)

.L80055D10:
/* 031110 80055D10 8CE30060 */  lw    $v1, 0x60($a3)
/* 031114 80055D14 8C620008 */  lw    $v0, 8($v1)
/* 031118 80055D18 54820005 */  bnel  $a0, $v0, .L80055D30
/* 03111C 80055D1C 24080001 */   addiu $t0, $zero, 1
/* 031120 80055D20 3C02800A */  lui   $v0, 0x800a
/* 031124 80055D24 8C42A5FC */  lw    $v0, -0x5a04($v0)
/* 031128 80055D28 ACC20000 */  sw    $v0, ($a2)
.L80055D2C:
/* 03112C 80055D2C ACA30000 */  sw    $v1, ($a1)
.L80055D30:
/* 031130 80055D30 03E00008 */  jr    $ra
/* 031134 80055D34 0100102D */   daddu $v0, $t0, $zero

/* 031138 80055D38 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03113C 80055D3C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 031140 80055D40 4485A000 */  mtc1  $a1, $f20
/* 031144 80055D44 27A50010 */  addiu $a1, $sp, 0x10
/* 031148 80055D48 27A60014 */  addiu $a2, $sp, 0x14
/* 03114C 80055D4C AFBF001C */  sw    $ra, 0x1c($sp)
/* 031150 80055D50 0C01573A */  jal   func_80055CE8
/* 031154 80055D54 AFB00018 */   sw    $s0, 0x18($sp)
/* 031158 80055D58 0040802D */  daddu $s0, $v0, $zero
/* 03115C 80055D5C 16000006 */  bnez  $s0, .L80055D78
/* 031160 80055D60 0200102D */   daddu $v0, $s0, $zero
/* 031164 80055D64 8FA40014 */  lw    $a0, 0x14($sp)
/* 031168 80055D68 4405A000 */  mfc1  $a1, $f20
/* 03116C 80055D6C 0C0141DC */  jal   func_80050770
/* 031170 80055D70 00000000 */   nop   
/* 031174 80055D74 0200102D */  daddu $v0, $s0, $zero
.L80055D78:
/* 031178 80055D78 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03117C 80055D7C 8FB00018 */  lw    $s0, 0x18($sp)
/* 031180 80055D80 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 031184 80055D84 03E00008 */  jr    $ra
/* 031188 80055D88 27BD0028 */   addiu $sp, $sp, 0x28

/* 03118C 80055D8C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 031190 80055D90 AFB1001C */  sw    $s1, 0x1c($sp)
/* 031194 80055D94 00A0882D */  daddu $s1, $a1, $zero
/* 031198 80055D98 27A50010 */  addiu $a1, $sp, 0x10
/* 03119C 80055D9C 27A60014 */  addiu $a2, $sp, 0x14
/* 0311A0 80055DA0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0311A4 80055DA4 0C01573A */  jal   func_80055CE8
/* 0311A8 80055DA8 AFB00018 */   sw    $s0, 0x18($sp)
/* 0311AC 80055DAC 0040802D */  daddu $s0, $v0, $zero
/* 0311B0 80055DB0 16000005 */  bnez  $s0, .L80055DC8
/* 0311B4 80055DB4 0200102D */   daddu $v0, $s0, $zero
/* 0311B8 80055DB8 8FA40014 */  lw    $a0, 0x14($sp)
/* 0311BC 80055DBC 0C014206 */  jal   func_80050818
/* 0311C0 80055DC0 0220282D */   daddu $a1, $s1, $zero
/* 0311C4 80055DC4 0200102D */  daddu $v0, $s0, $zero
.L80055DC8:
/* 0311C8 80055DC8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0311CC 80055DCC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0311D0 80055DD0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0311D4 80055DD4 03E00008 */  jr    $ra
/* 0311D8 80055DD8 27BD0028 */   addiu $sp, $sp, 0x28

