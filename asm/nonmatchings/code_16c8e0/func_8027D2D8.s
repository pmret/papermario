.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D2D8
/* 1ABBB8 8027D2D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1ABBBC 8027D2DC AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABBC0 8027D2E0 0080802D */  daddu     $s0, $a0, $zero
/* 1ABBC4 8027D2E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1ABBC8 8027D2E8 8E02000C */  lw        $v0, 0xc($s0)
/* 1ABBCC 8027D2EC 0C0B1EAF */  jal       get_variable
/* 1ABBD0 8027D2F0 8C450000 */   lw       $a1, ($v0)
/* 1ABBD4 8027D2F4 0040202D */  daddu     $a0, $v0, $zero
/* 1ABBD8 8027D2F8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABBDC 8027D2FC 14820002 */  bne       $a0, $v0, .L8027D308
/* 1ABBE0 8027D300 00000000 */   nop      
/* 1ABBE4 8027D304 8E040148 */  lw        $a0, 0x148($s0)
.L8027D308:
/* 1ABBE8 8027D308 0C09A75B */  jal       get_actor
/* 1ABBEC 8027D30C 00000000 */   nop      
/* 1ABBF0 8027D310 0C099AB7 */  jal       func_80266ADC
/* 1ABBF4 8027D314 0040202D */   daddu    $a0, $v0, $zero
/* 1ABBF8 8027D318 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1ABBFC 8027D31C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABC00 8027D320 24020002 */  addiu     $v0, $zero, 2
/* 1ABC04 8027D324 03E00008 */  jr        $ra
/* 1ABC08 8027D328 27BD0018 */   addiu    $sp, $sp, 0x18
