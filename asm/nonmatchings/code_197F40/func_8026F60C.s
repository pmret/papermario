.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026F60C
/* 19DEEC 8026F60C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19DEF0 8026F610 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19DEF4 8026F614 8C82000C */  lw        $v0, 0xc($a0)
/* 19DEF8 8026F618 0C0B1EAF */  jal       get_variable
/* 19DEFC 8026F61C 8C450000 */   lw       $a1, ($v0)
/* 19DF00 8026F620 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19DF04 8026F624 3C01800E */  lui       $at, %hi(gBattleStatus+0x8D)
/* 19DF08 8026F628 A022C0FD */  sb        $v0, %lo(gBattleStatus+0x8D)($at)
/* 19DF0C 8026F62C 24020002 */  addiu     $v0, $zero, 2
/* 19DF10 8026F630 03E00008 */  jr        $ra
/* 19DF14 8026F634 27BD0018 */   addiu    $sp, $sp, 0x18
