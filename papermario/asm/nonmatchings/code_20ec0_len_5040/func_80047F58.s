.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80047F58
/* 023358 80047F58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 02335C 80047F5C 00041040 */  sll   $v0, $a0, 1
/* 023360 80047F60 00441021 */  addu  $v0, $v0, $a0
/* 023364 80047F64 00021080 */  sll   $v0, $v0, 2
/* 023368 80047F68 00441023 */  subu  $v0, $v0, $a0
/* 02336C 80047F6C 3C03800A */  lui   $v1, 0x800a
/* 023370 80047F70 8C630F44 */  lw    $v1, 0xf44($v1)
/* 023374 80047F74 00021100 */  sll   $v0, $v0, 4
/* 023378 80047F78 AFBF0018 */  sw    $ra, 0x18($sp)
/* 02337C 80047F7C AFB10014 */  sw    $s1, 0x14($sp)
/* 023380 80047F80 AFB00010 */  sw    $s0, 0x10($sp)
/* 023384 80047F84 00628821 */  addu  $s1, $v1, $v0
/* 023388 80047F88 2403FDFF */  addiu $v1, $zero, -0x201
/* 02338C 80047F8C 8E220000 */  lw    $v0, ($s1)
/* 023390 80047F90 82240098 */  lb    $a0, 0x98($s1)
/* 023394 80047F94 00431024 */  and   $v0, $v0, $v1
/* 023398 80047F98 1480000E */  bnez  $a0, .L80047FD4
/* 02339C 80047F9C AE220000 */   sw    $v0, ($s1)
/* 0233A0 80047FA0 3C048010 */  lui   $a0, 0x8010
/* 0233A4 80047FA4 2484760C */  addiu $a0, $a0, 0x760c
/* 0233A8 80047FA8 24020001 */  addiu $v0, $zero, 1
/* 0233AC 80047FAC 0C050529 */  jal   create_icon
/* 0233B0 80047FB0 A2220098 */   sb    $v0, 0x98($s1)
/* 0233B4 80047FB4 0040802D */  daddu $s0, $v0, $zero
/* 0233B8 80047FB8 0200202D */  daddu $a0, $s0, $zero
/* 0233BC 80047FBC 0C051280 */  jal   set_icon_flags
/* 0233C0 80047FC0 24050002 */   addiu $a1, $zero, 2
/* 0233C4 80047FC4 0200202D */  daddu $a0, $s0, $zero
/* 0233C8 80047FC8 0C051280 */  jal   set_icon_flags
/* 0233CC 80047FCC 24050080 */   addiu $a1, $zero, 0x80
/* 0233D0 80047FD0 AE30009C */  sw    $s0, 0x9c($s1)
.L80047FD4:
/* 0233D4 80047FD4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0233D8 80047FD8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0233DC 80047FDC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0233E0 80047FE0 03E00008 */  jr    $ra
/* 0233E4 80047FE4 27BD0020 */   addiu $sp, $sp, 0x20

