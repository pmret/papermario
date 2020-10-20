.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_89FEC0
/* 89FEC0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 89FEC4 80240004 0000202D */  daddu     $a0, $zero, $zero
/* 89FEC8 80240008 AFBF0010 */  sw        $ra, 0x10($sp)
/* 89FECC 8024000C 0C052AC3 */  jal       func_8014AB0C
/* 89FED0 80240010 24050002 */   addiu    $a1, $zero, 2
/* 89FED4 80240014 8FBF0010 */  lw        $ra, 0x10($sp)
/* 89FED8 80240018 24020002 */  addiu     $v0, $zero, 2
/* 89FEDC 8024001C 03E00008 */  jr        $ra
/* 89FEE0 80240020 27BD0018 */   addiu    $sp, $sp, 0x18
/* 89FEE4 80240024 00000000 */  nop       
/* 89FEE8 80240028 00000000 */  nop       
/* 89FEEC 8024002C 00000000 */  nop       
