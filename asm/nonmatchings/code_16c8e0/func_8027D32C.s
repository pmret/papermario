.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D32C
/* 1ABC0C 8027D32C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1ABC10 8027D330 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABC14 8027D334 0080802D */  daddu     $s0, $a0, $zero
/* 1ABC18 8027D338 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1ABC1C 8027D33C 8E02000C */  lw        $v0, 0xc($s0)
/* 1ABC20 8027D340 0C0B1EAF */  jal       get_variable
/* 1ABC24 8027D344 8C450000 */   lw       $a1, ($v0)
/* 1ABC28 8027D348 0040202D */  daddu     $a0, $v0, $zero
/* 1ABC2C 8027D34C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABC30 8027D350 14820002 */  bne       $a0, $v0, .L8027D35C
/* 1ABC34 8027D354 00000000 */   nop      
/* 1ABC38 8027D358 8E040148 */  lw        $a0, 0x148($s0)
.L8027D35C:
/* 1ABC3C 8027D35C 0C09A75B */  jal       get_actor
/* 1ABC40 8027D360 00000000 */   nop      
/* 1ABC44 8027D364 0C099ABE */  jal       func_80266AF8
/* 1ABC48 8027D368 0040202D */   daddu    $a0, $v0, $zero
/* 1ABC4C 8027D36C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1ABC50 8027D370 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABC54 8027D374 24020002 */  addiu     $v0, $zero, 2
/* 1ABC58 8027D378 03E00008 */  jr        $ra
/* 1ABC5C 8027D37C 27BD0018 */   addiu    $sp, $sp, 0x18
