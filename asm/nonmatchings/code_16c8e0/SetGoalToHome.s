.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetGoalToHome
/* 1987A4 80269EC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1987A8 80269EC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1987AC 80269ECC 0080802D */  daddu $s0, $a0, $zero
/* 1987B0 80269ED0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1987B4 80269ED4 8E02000C */  lw    $v0, 0xc($s0)
/* 1987B8 80269ED8 0C0B1EAF */  jal   get_variable
/* 1987BC 80269EDC 8C450000 */   lw    $a1, ($v0)
/* 1987C0 80269EE0 0040202D */  daddu $a0, $v0, $zero
/* 1987C4 80269EE4 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1987C8 80269EE8 14820002 */  bne   $a0, $v0, .L80269EF4
/* 1987CC 80269EEC 00000000 */   nop   
/* 1987D0 80269EF0 8E040148 */  lw    $a0, 0x148($s0)
.L80269EF4:
/* 1987D4 80269EF4 0C09A75B */  jal   get_actor
/* 1987D8 80269EF8 00000000 */   nop   
/* 1987DC 80269EFC 0040182D */  daddu $v1, $v0, $zero
/* 1987E0 80269F00 C4600138 */  lwc1  $f0, 0x138($v1)
/* 1987E4 80269F04 C462013C */  lwc1  $f2, 0x13c($v1)
/* 1987E8 80269F08 C4640140 */  lwc1  $f4, 0x140($v1)
/* 1987EC 80269F0C E4600018 */  swc1  $f0, 0x18($v1)
/* 1987F0 80269F10 E462001C */  swc1  $f2, 0x1c($v1)
/* 1987F4 80269F14 E4640020 */  swc1  $f4, 0x20($v1)
/* 1987F8 80269F18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1987FC 80269F1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 198800 80269F20 24020002 */  addiu $v0, $zero, 2
/* 198804 80269F24 03E00008 */  jr    $ra
/* 198808 80269F28 27BD0018 */   addiu $sp, $sp, 0x18

