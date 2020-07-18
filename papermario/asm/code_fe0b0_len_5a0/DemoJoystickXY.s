.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "globals.inc"

DemoJoystickXY:
/* 0FE5C0 802D9C10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0FE5C4 802D9C14 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FE5C8 802D9C18 0080882D */  daddu $s1, $a0, $zero
/* 0FE5CC 802D9C1C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FE5D0 802D9C20 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FE5D4 802D9C24 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0FE5D8 802D9C28 8E30000C */  lw    $s0, 0xc($s1)
/* 0FE5DC 802D9C2C 8E050000 */  lw    $a1, ($s0)
/* 0FE5E0 802D9C30 0C0B210B */  jal   get_float_variable
/* 0FE5E4 802D9C34 26100004 */   addiu $s0, $s0, 4
/* 0FE5E8 802D9C38 0220202D */  daddu $a0, $s1, $zero
/* 0FE5EC 802D9C3C 8E050000 */  lw    $a1, ($s0)
/* 0FE5F0 802D9C40 0C0B210B */  jal   get_float_variable
/* 0FE5F4 802D9C44 46000506 */   mov.s $f20, $f0
/* 0FE5F8 802D9C48 3C048007 */  lui   $a0, 0x8007
/* 0FE5FC 802D9C4C 2484419C */  addiu $a0, $a0, 0x419c
/* 0FE600 802D9C50 8C830000 */  lw    $v1, ($a0)
/* 0FE604 802D9C54 4600A08D */  trunc.w.s $f2, $f20
/* 0FE608 802D9C58 44021000 */  mfc1  $v0, $f2
/* 0FE60C 802D9C5C 00000000 */  nop   
/* 0FE610 802D9C60 A062006A */  sb    $v0, 0x6a($v1)
/* 0FE614 802D9C64 8C830000 */  lw    $v1, ($a0)
/* 0FE618 802D9C68 4600008D */  trunc.w.s $f2, $f0
/* 0FE61C 802D9C6C 44021000 */  mfc1  $v0, $f2
/* 0FE620 802D9C70 00000000 */  nop   
/* 0FE624 802D9C74 A062006B */  sb    $v0, 0x6b($v1)
/* 0FE628 802D9C78 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FE62C 802D9C7C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FE630 802D9C80 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FE634 802D9C84 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0FE638 802D9C88 24020002 */  addiu $v0, $zero, 2
/* 0FE63C 802D9C8C 03E00008 */  jr    $ra
/* 0FE640 802D9C90 27BD0028 */   addiu $sp, $sp, 0x28
