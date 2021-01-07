.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BE8_4E3328
/* 4E3328 80218BE8 3C048022 */  lui       $a0, %hi(D_80224DB0)
/* 4E332C 80218BEC 8C844DB0 */  lw        $a0, %lo(D_80224DB0)($a0)
/* 4E3330 80218BF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E3334 80218BF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E3338 80218BF8 0C016914 */  jal       remove_effect
/* 4E333C 80218BFC 00000000 */   nop      
/* 4E3340 80218C00 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E3344 80218C04 24020002 */  addiu     $v0, $zero, 2
/* 4E3348 80218C08 03E00008 */  jr        $ra
/* 4E334C 80218C0C 27BD0018 */   addiu    $sp, $sp, 0x18
