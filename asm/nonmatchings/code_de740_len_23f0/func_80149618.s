.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80149618
/* 0DFD18 80149618 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DFD1C 8014961C AFB00010 */  sw    $s0, 0x10($sp)
/* 0DFD20 80149620 3C108016 */  lui   $s0, 0x8016
/* 0DFD24 80149624 261098A0 */  addiu $s0, $s0, -0x6760
/* 0DFD28 80149628 0200202D */  daddu $a0, $s0, $zero
/* 0DFD2C 8014962C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DFD30 80149630 0C01925C */  jal   bzero
/* 0DFD34 80149634 24050118 */   addiu $a1, $zero, 0x118
/* 0DFD38 80149638 3C048016 */  lui   $a0, 0x8016
/* 0DFD3C 8014963C 248499B8 */  addiu $a0, $a0, -0x6648
/* 0DFD40 80149640 0C01925C */  jal   bzero
/* 0DFD44 80149644 24050118 */   addiu $a1, $zero, 0x118
/* 0DFD48 80149648 3C018016 */  lui   $at, 0x8016
/* 0DFD4C 8014964C AC309AD0 */  sw    $s0, -0x6530($at)
/* 0DFD50 80149650 0C0525FF */  jal   func_801497FC
/* 0DFD54 80149654 0000202D */   daddu $a0, $zero, $zero
/* 0DFD58 80149658 0C052580 */  jal   func_80149600
/* 0DFD5C 8014965C 00000000 */   nop   
/* 0DFD60 80149660 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DFD64 80149664 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DFD68 80149668 03E00008 */  jr    $ra
/* 0DFD6C 8014966C 27BD0018 */   addiu $sp, $sp, 0x18

