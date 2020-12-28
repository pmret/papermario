.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A98_4E31D8
/* 4E31D8 80218A98 3C048022 */  lui       $a0, %hi(D_80224D80)
/* 4E31DC 80218A9C 8C844D80 */  lw        $a0, %lo(D_80224D80)($a0)
/* 4E31E0 80218AA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E31E4 80218AA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E31E8 80218AA8 0C016914 */  jal       remove_effect
/* 4E31EC 80218AAC 00000000 */   nop      
/* 4E31F0 80218AB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E31F4 80218AB4 24020002 */  addiu     $v0, $zero, 2
/* 4E31F8 80218AB8 03E00008 */  jr        $ra
/* 4E31FC 80218ABC 27BD0018 */   addiu    $sp, $sp, 0x18
