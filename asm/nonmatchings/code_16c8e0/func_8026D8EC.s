.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026D8EC
/* 19C1CC 8026D8EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19C1D0 8026D8F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C1D4 8026D8F4 0080802D */  daddu     $s0, $a0, $zero
/* 19C1D8 8026D8F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 19C1DC 8026D8FC 8E02000C */  lw        $v0, 0xc($s0)
/* 19C1E0 8026D900 0C0B1EAF */  jal       get_variable
/* 19C1E4 8026D904 8C450000 */   lw       $a1, ($v0)
/* 19C1E8 8026D908 0040202D */  daddu     $a0, $v0, $zero
/* 19C1EC 8026D90C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19C1F0 8026D910 14820002 */  bne       $a0, $v0, .L8026D91C
/* 19C1F4 8026D914 00000000 */   nop      
/* 19C1F8 8026D918 8E040148 */  lw        $a0, 0x148($s0)
.L8026D91C:
/* 19C1FC 8026D91C 0C09A75B */  jal       get_actor
/* 19C200 8026D920 00000000 */   nop      
/* 19C204 8026D924 0C099ABE */  jal       func_80266AF8
/* 19C208 8026D928 0040202D */   daddu    $a0, $v0, $zero
/* 19C20C 8026D92C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 19C210 8026D930 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C214 8026D934 24020002 */  addiu     $v0, $zero, 2
/* 19C218 8026D938 03E00008 */  jr        $ra
/* 19C21C 8026D93C 27BD0018 */   addiu    $sp, $sp, 0x18
