.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetActorVar
/* 19A894 8026BFB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19A898 8026BFB8 AFB20018 */  sw    $s2, 0x18($sp)
/* 19A89C 8026BFBC 0080902D */  daddu $s2, $a0, $zero
/* 19A8A0 8026BFC0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19A8A4 8026BFC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 19A8A8 8026BFC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A8AC 8026BFCC 8E51000C */  lw    $s1, 0xc($s2)
/* 19A8B0 8026BFD0 8E250000 */  lw    $a1, ($s1)
/* 19A8B4 8026BFD4 0C0B1EAF */  jal   get_variable
/* 19A8B8 8026BFD8 26310004 */   addiu $s1, $s1, 4
/* 19A8BC 8026BFDC 0040802D */  daddu $s0, $v0, $zero
/* 19A8C0 8026BFE0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A8C4 8026BFE4 16020002 */  bne   $s0, $v0, .L8026BFF0
/* 19A8C8 8026BFE8 00000000 */   nop   
/* 19A8CC 8026BFEC 8E500148 */  lw    $s0, 0x148($s2)
.L8026BFF0:
/* 19A8D0 8026BFF0 8E250000 */  lw    $a1, ($s1)
/* 19A8D4 8026BFF4 26310004 */  addiu $s1, $s1, 4
/* 19A8D8 8026BFF8 0C0B1EAF */  jal   get_variable
/* 19A8DC 8026BFFC 0240202D */   daddu $a0, $s2, $zero
/* 19A8E0 8026C000 0200202D */  daddu $a0, $s0, $zero
/* 19A8E4 8026C004 8E310000 */  lw    $s1, ($s1)
/* 19A8E8 8026C008 0C09A75B */  jal   get_actor
/* 19A8EC 8026C00C 0040802D */   daddu $s0, $v0, $zero
/* 19A8F0 8026C010 0240202D */  daddu $a0, $s2, $zero
/* 19A8F4 8026C014 00108080 */  sll   $s0, $s0, 2
/* 19A8F8 8026C018 00501021 */  addu  $v0, $v0, $s0
/* 19A8FC 8026C01C 8C460088 */  lw    $a2, 0x88($v0)
/* 19A900 8026C020 0C0B2026 */  jal   set_variable
/* 19A904 8026C024 0220282D */   daddu $a1, $s1, $zero
/* 19A908 8026C028 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19A90C 8026C02C 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A910 8026C030 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A914 8026C034 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A918 8026C038 24020002 */  addiu $v0, $zero, 2
/* 19A91C 8026C03C 03E00008 */  jr    $ra
/* 19A920 8026C040 27BD0020 */   addiu $sp, $sp, 0x20

