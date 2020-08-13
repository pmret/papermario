.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80246F28
.L80246F28:
/* 13A268 80246F28 92030003 */  lbu   $v1, 3($s0)
/* 13A26C 80246F2C 00031040 */  sll   $v0, $v1, 1
/* 13A270 80246F30 00431021 */  addu  $v0, $v0, $v1
/* 13A274 80246F34 00021080 */  sll   $v0, $v0, 2
/* 13A278 80246F38 3C048025 */  lui   $a0, 0x8025
/* 13A27C 80246F3C 00822021 */  addu  $a0, $a0, $v0
/* 13A280 80246F40 8C84F3B8 */  lw    $a0, -0xc48($a0)
/* 13A284 80246F44 0C093BA0 */  jal   func_8024EE80
/* 13A288 80246F48 00912021 */   addu  $a0, $a0, $s1
/* 13A28C 80246F4C 3C038027 */  lui   $v1, 0x8027
/* 13A290 80246F50 8C6300C4 */  lw    $v1, 0xc4($v1)
/* 13A294 80246F54 3C018027 */  lui   $at, 0x8027
/* 13A298 80246F58 AC2200C8 */  sw    $v0, 0xc8($at)
/* 13A29C 80246F5C 3C018027 */  lui   $at, 0x8027
/* 13A2A0 80246F60 AC2000CC */  sw    $zero, 0xcc($at)
/* 13A2A4 80246F64 30634000 */  andi  $v1, $v1, 0x4000
/* 13A2A8 80246F68 10600005 */  beqz  $v1, .L80246F80
/* 13A2AC 80246F6C 00000000 */   nop   
/* 13A2B0 80246F70 0C05272D */  jal   play_sound
/* 13A2B4 80246F74 240400CA */   addiu $a0, $zero, 0xca
/* 13A2B8 80246F78 3C018027 */  lui   $at, 0x8027
/* 13A2BC 80246F7C A02000D4 */  sb    $zero, 0xd4($at)
.L80246F80:
/* 13A2C0 80246F80 8FBF0018 */  lw    $ra, 0x18($sp)
/* 13A2C4 80246F84 8FB10014 */  lw    $s1, 0x14($sp)
/* 13A2C8 80246F88 8FB00010 */  lw    $s0, 0x10($sp)
/* 13A2CC 80246F8C 03E00008 */  jr    $ra
/* 13A2D0 80246F90 27BD0020 */   addiu $sp, $sp, 0x20

/* 13A2D4 80246F94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 13A2D8 80246F98 AFB10014 */  sw    $s1, 0x14($sp)
/* 13A2DC 80246F9C 0000882D */  daddu $s1, $zero, $zero
/* 13A2E0 80246FA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 13A2E4 80246FA4 3C108027 */  lui   $s0, 0x8027
/* 13A2E8 80246FA8 26100150 */  addiu $s0, $s0, 0x150
/* 13A2EC 80246FAC AFBF0018 */  sw    $ra, 0x18($sp)
.L80246FB0:
/* 13A2F0 80246FB0 8E040000 */  lw    $a0, ($s0)
/* 13A2F4 80246FB4 26100004 */  addiu $s0, $s0, 4
/* 13A2F8 80246FB8 0C05123D */  jal   free_icon
/* 13A2FC 80246FBC 26310001 */   addiu $s1, $s1, 1
/* 13A300 80246FC0 2A22000C */  slti  $v0, $s1, 0xc
/* 13A304 80246FC4 1440FFFA */  bnez  $v0, .L80246FB0
/* 13A308 80246FC8 00000000 */   nop   
/* 13A30C 80246FCC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 13A310 80246FD0 8FB10014 */  lw    $s1, 0x14($sp)
/* 13A314 80246FD4 8FB00010 */  lw    $s0, 0x10($sp)
/* 13A318 80246FD8 03E00008 */  jr    $ra
/* 13A31C 80246FDC 27BD0020 */   addiu $sp, $sp, 0x20

/* 13A320 80246FE0 84820000 */  lh    $v0, ($a0)
/* 13A324 80246FE4 14400003 */  bnez  $v0, .L80246FF4
/* 13A328 80246FE8 00021140 */   sll   $v0, $v0, 5
/* 13A32C 80246FEC 08091C00 */  j     func_80247000
/* 13A330 80246FF0 24037FFF */   addiu $v1, $zero, 0x7fff

