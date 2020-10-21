.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024027C_8DA37C
/* 8DA37C 8024027C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DA380 80240280 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8DA384 80240284 0C00D77C */  jal       func_80035DF0
/* 8DA388 80240288 2404000A */   addiu    $a0, $zero, 0xa
/* 8DA38C 8024028C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8DA390 80240290 24020002 */  addiu     $v0, $zero, 2
/* 8DA394 80240294 03E00008 */  jr        $ra
/* 8DA398 80240298 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8DA39C 8024029C 00000000 */  nop       
