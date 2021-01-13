.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_892A20
/* 892A20 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 892A24 80240004 0000202D */  daddu     $a0, $zero, $zero
/* 892A28 80240008 AFBF0010 */  sw        $ra, 0x10($sp)
/* 892A2C 8024000C 0C052AC3 */  jal       func_8014AB0C
/* 892A30 80240010 24050002 */   addiu    $a1, $zero, 2
/* 892A34 80240014 8FBF0010 */  lw        $ra, 0x10($sp)
/* 892A38 80240018 24020002 */  addiu     $v0, $zero, 2
/* 892A3C 8024001C 03E00008 */  jr        $ra
/* 892A40 80240020 27BD0018 */   addiu    $sp, $sp, 0x18
/* 892A44 80240024 00000000 */  nop
/* 892A48 80240028 00000000 */  nop
/* 892A4C 8024002C 00000000 */  nop
