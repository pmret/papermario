.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ShowShockEffect
/* 19E490 8026FBB0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19E494 8026FBB4 AFB00010 */  sw    $s0, 0x10($sp)
/* 19E498 8026FBB8 0080802D */  daddu $s0, $a0, $zero
/* 19E49C 8026FBBC AFBF0014 */  sw    $ra, 0x14($sp)
/* 19E4A0 8026FBC0 8E02000C */  lw    $v0, 0xc($s0)
/* 19E4A4 8026FBC4 0C0B1EAF */  jal   get_variable
/* 19E4A8 8026FBC8 8C450000 */   lw    $a1, ($v0)
/* 19E4AC 8026FBCC 0040202D */  daddu $a0, $v0, $zero
/* 19E4B0 8026FBD0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19E4B4 8026FBD4 14820002 */  bne   $a0, $v0, .L8026FBE0
/* 19E4B8 8026FBD8 00000000 */   nop   
/* 19E4BC 8026FBDC 8E040148 */  lw    $a0, 0x148($s0)
.L8026FBE0:
/* 19E4C0 8026FBE0 0C09A75B */  jal   get_actor
/* 19E4C4 8026FBE4 00000000 */   nop   
/* 19E4C8 8026FBE8 0C09451D */  jal   func_80251474
/* 19E4CC 8026FBEC 0040202D */   daddu $a0, $v0, $zero
/* 19E4D0 8026FBF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19E4D4 8026FBF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 19E4D8 8026FBF8 24020002 */  addiu $v0, $zero, 2
/* 19E4DC 8026FBFC 03E00008 */  jr    $ra
/* 19E4E0 8026FC00 27BD0018 */   addiu $sp, $sp, 0x18

