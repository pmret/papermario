.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuSiCallBackRemove
/* 03B890 80060490 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03B894 80060494 AFB10014 */  sw    $s1, 0x14($sp)
/* 03B898 80060498 3C118007 */  lui   $s1, 0x8007
/* 03B89C 8006049C 26317400 */  addiu $s1, $s1, 0x7400
/* 03B8A0 800604A0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 03B8A4 800604A4 AFB00010 */  sw    $s0, 0x10($sp)
/* 03B8A8 800604A8 8E220000 */  lw    $v0, ($s1)
/* 03B8AC 800604AC 10400011 */  beqz  $v0, .L800604F4
/* 03B8B0 800604B0 00000000 */   nop   
.L800604B4:
/* 03B8B4 800604B4 8E220000 */  lw    $v0, ($s1)
/* 03B8B8 800604B8 8C500000 */  lw    $s0, ($v0)
/* 03B8BC 800604BC 1604000B */  bne   $s0, $a0, .L800604EC
/* 03B8C0 800604C0 00000000 */   nop   
/* 03B8C4 800604C4 0C018250 */  jal   osSetIntMask
/* 03B8C8 800604C8 24040001 */   addiu $a0, $zero, 1
/* 03B8CC 800604CC 8E250000 */  lw    $a1, ($s1)
/* 03B8D0 800604D0 8E030000 */  lw    $v1, ($s0)
/* 03B8D4 800604D4 0040202D */  daddu $a0, $v0, $zero
/* 03B8D8 800604D8 ACA30000 */  sw    $v1, ($a1)
/* 03B8DC 800604DC 0C018250 */  jal   osSetIntMask
/* 03B8E0 800604E0 AE000000 */   sw    $zero, ($s0)
/* 03B8E4 800604E4 0801813D */  j     .L800604F4
/* 03B8E8 800604E8 00000000 */   nop   

.L800604EC:
/* 03B8EC 800604EC 1600FFF1 */  bnez  $s0, .L800604B4
/* 03B8F0 800604F0 0040882D */   daddu $s1, $v0, $zero
.L800604F4:
/* 03B8F4 800604F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 03B8F8 800604F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 03B8FC 800604FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 03B900 80060500 03E00008 */  jr    $ra
/* 03B904 80060504 27BD0020 */   addiu $sp, $sp, 0x20

/* 03B908 80060508 00000000 */  nop   
/* 03B90C 8006050C 00000000 */  nop   


