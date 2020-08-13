.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorSpeed
/* 199F34 8026B654 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199F38 8026B658 AFB20018 */  sw    $s2, 0x18($sp)
/* 199F3C 8026B65C 0080902D */  daddu $s2, $a0, $zero
/* 199F40 8026B660 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199F44 8026B664 AFB10014 */  sw    $s1, 0x14($sp)
/* 199F48 8026B668 AFB00010 */  sw    $s0, 0x10($sp)
/* 199F4C 8026B66C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 199F50 8026B670 8E51000C */  lw    $s1, 0xc($s2)
/* 199F54 8026B674 8E250000 */  lw    $a1, ($s1)
/* 199F58 8026B678 0C0B1EAF */  jal   get_variable
/* 199F5C 8026B67C 26310004 */   addiu $s1, $s1, 4
/* 199F60 8026B680 0040802D */  daddu $s0, $v0, $zero
/* 199F64 8026B684 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199F68 8026B688 16020002 */  bne   $s0, $v0, .L8026B694
/* 199F6C 8026B68C 00000000 */   nop   
/* 199F70 8026B690 8E500148 */  lw    $s0, 0x148($s2)
.L8026B694:
/* 199F74 8026B694 8E250000 */  lw    $a1, ($s1)
/* 199F78 8026B698 0C0B210B */  jal   get_float_variable
/* 199F7C 8026B69C 0240202D */   daddu $a0, $s2, $zero
/* 199F80 8026B6A0 0200202D */  daddu $a0, $s0, $zero
/* 199F84 8026B6A4 0C09A75B */  jal   get_actor
/* 199F88 8026B6A8 46000506 */   mov.s $f20, $f0
/* 199F8C 8026B6AC E454004C */  swc1  $f20, 0x4c($v0)
/* 199F90 8026B6B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199F94 8026B6B4 8FB20018 */  lw    $s2, 0x18($sp)
/* 199F98 8026B6B8 8FB10014 */  lw    $s1, 0x14($sp)
/* 199F9C 8026B6BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 199FA0 8026B6C0 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 199FA4 8026B6C4 24020002 */  addiu $v0, $zero, 2
/* 199FA8 8026B6C8 03E00008 */  jr    $ra
/* 199FAC 8026B6CC 27BD0028 */   addiu $sp, $sp, 0x28

