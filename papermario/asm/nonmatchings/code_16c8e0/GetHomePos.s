.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetHomePos
/* 199654 8026AD74 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199658 8026AD78 AFB40020 */  sw    $s4, 0x20($sp)
/* 19965C 8026AD7C 0080A02D */  daddu $s4, $a0, $zero
/* 199660 8026AD80 AFBF0024 */  sw    $ra, 0x24($sp)
/* 199664 8026AD84 AFB3001C */  sw    $s3, 0x1c($sp)
/* 199668 8026AD88 AFB20018 */  sw    $s2, 0x18($sp)
/* 19966C 8026AD8C AFB10014 */  sw    $s1, 0x14($sp)
/* 199670 8026AD90 AFB00010 */  sw    $s0, 0x10($sp)
/* 199674 8026AD94 8E92000C */  lw    $s2, 0xc($s4)
/* 199678 8026AD98 8E450000 */  lw    $a1, ($s2)
/* 19967C 8026AD9C 0C0B1EAF */  jal   get_variable
/* 199680 8026ADA0 26520004 */   addiu $s2, $s2, 4
/* 199684 8026ADA4 0040202D */  daddu $a0, $v0, $zero
/* 199688 8026ADA8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19968C 8026ADAC 14820002 */  bne   $a0, $v0, .L8026ADB8
/* 199690 8026ADB0 00000000 */   nop   
/* 199694 8026ADB4 8E840148 */  lw    $a0, 0x148($s4)
.L8026ADB8:
/* 199698 8026ADB8 0C09A75B */  jal   get_actor
/* 19969C 8026ADBC 00000000 */   nop   
/* 1996A0 8026ADC0 8E450000 */  lw    $a1, ($s2)
/* 1996A4 8026ADC4 26520004 */  addiu $s2, $s2, 4
/* 1996A8 8026ADC8 C4400138 */  lwc1  $f0, 0x138($v0)
/* 1996AC 8026ADCC C4420140 */  lwc1  $f2, 0x140($v0)
/* 1996B0 8026ADD0 8E500000 */  lw    $s0, ($s2)
/* 1996B4 8026ADD4 4600010D */  trunc.w.s $f4, $f0
/* 1996B8 8026ADD8 44062000 */  mfc1  $a2, $f4
/* 1996BC 8026ADDC C440013C */  lwc1  $f0, 0x13c($v0)
/* 1996C0 8026ADE0 8E520004 */  lw    $s2, 4($s2)
/* 1996C4 8026ADE4 4600010D */  trunc.w.s $f4, $f0
/* 1996C8 8026ADE8 44112000 */  mfc1  $s1, $f4
/* 1996CC 8026ADEC 4600110D */  trunc.w.s $f4, $f2
/* 1996D0 8026ADF0 44132000 */  mfc1  $s3, $f4
/* 1996D4 8026ADF4 0C0B2026 */  jal   set_variable
/* 1996D8 8026ADF8 0280202D */   daddu $a0, $s4, $zero
/* 1996DC 8026ADFC 0280202D */  daddu $a0, $s4, $zero
/* 1996E0 8026AE00 0200282D */  daddu $a1, $s0, $zero
/* 1996E4 8026AE04 0C0B2026 */  jal   set_variable
/* 1996E8 8026AE08 0220302D */   daddu $a2, $s1, $zero
/* 1996EC 8026AE0C 0280202D */  daddu $a0, $s4, $zero
/* 1996F0 8026AE10 0240282D */  daddu $a1, $s2, $zero
/* 1996F4 8026AE14 0C0B2026 */  jal   set_variable
/* 1996F8 8026AE18 0260302D */   daddu $a2, $s3, $zero
/* 1996FC 8026AE1C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 199700 8026AE20 8FB40020 */  lw    $s4, 0x20($sp)
/* 199704 8026AE24 8FB3001C */  lw    $s3, 0x1c($sp)
/* 199708 8026AE28 8FB20018 */  lw    $s2, 0x18($sp)
/* 19970C 8026AE2C 8FB10014 */  lw    $s1, 0x14($sp)
/* 199710 8026AE30 8FB00010 */  lw    $s0, 0x10($sp)
/* 199714 8026AE34 24020002 */  addiu $v0, $zero, 2
/* 199718 8026AE38 03E00008 */  jr    $ra
/* 19971C 8026AE3C 27BD0028 */   addiu $sp, $sp, 0x28

