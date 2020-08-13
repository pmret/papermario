.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80047E4C
/* 02324C 80047E4C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 023250 80047E50 00041040 */  sll   $v0, $a0, 1
/* 023254 80047E54 00441021 */  addu  $v0, $v0, $a0
/* 023258 80047E58 00021080 */  sll   $v0, $v0, 2
/* 02325C 80047E5C 00441023 */  subu  $v0, $v0, $a0
/* 023260 80047E60 3C03800A */  lui   $v1, 0x800a
/* 023264 80047E64 8C630F44 */  lw    $v1, 0xf44($v1)
/* 023268 80047E68 00021100 */  sll   $v0, $v0, 4
/* 02326C 80047E6C AFBF0018 */  sw    $ra, 0x18($sp)
/* 023270 80047E70 AFB10014 */  sw    $s1, 0x14($sp)
/* 023274 80047E74 AFB00010 */  sw    $s0, 0x10($sp)
/* 023278 80047E78 00628821 */  addu  $s1, $v1, $v0
/* 02327C 80047E7C 2403FEFF */  addiu $v1, $zero, -0x101
/* 023280 80047E80 8E220000 */  lw    $v0, ($s1)
/* 023284 80047E84 82240090 */  lb    $a0, 0x90($s1)
/* 023288 80047E88 00431024 */  and   $v0, $v0, $v1
/* 02328C 80047E8C 1480000E */  bnez  $a0, .L80047EC8
/* 023290 80047E90 AE220000 */   sw    $v0, ($s1)
/* 023294 80047E94 3C048010 */  lui   $a0, 0x8010
/* 023298 80047E98 248475E0 */  addiu $a0, $a0, 0x75e0
/* 02329C 80047E9C 24020001 */  addiu $v0, $zero, 1
/* 0232A0 80047EA0 0C050529 */  jal   create_icon
/* 0232A4 80047EA4 A2220090 */   sb    $v0, 0x90($s1)
/* 0232A8 80047EA8 0040802D */  daddu $s0, $v0, $zero
/* 0232AC 80047EAC 0200202D */  daddu $a0, $s0, $zero
/* 0232B0 80047EB0 0C051280 */  jal   set_icon_flags
/* 0232B4 80047EB4 24050002 */   addiu $a1, $zero, 2
/* 0232B8 80047EB8 0200202D */  daddu $a0, $s0, $zero
/* 0232BC 80047EBC 0C051280 */  jal   set_icon_flags
/* 0232C0 80047EC0 24050080 */   addiu $a1, $zero, 0x80
/* 0232C4 80047EC4 AE300094 */  sw    $s0, 0x94($s1)
.L80047EC8:
/* 0232C8 80047EC8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0232CC 80047ECC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0232D0 80047ED0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0232D4 80047ED4 03E00008 */  jr    $ra
/* 0232D8 80047ED8 27BD0020 */   addiu $sp, $sp, 0x20

