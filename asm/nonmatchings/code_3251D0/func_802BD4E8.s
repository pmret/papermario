.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD4E8
/* 3255B8 802BD4E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3255BC 802BD4EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3255C0 802BD4F0 0C03A91F */  jal       remove_consumable
/* 3255C4 802BD4F4 00000000 */   nop      
/* 3255C8 802BD4F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3255CC 802BD4FC 24020002 */  addiu     $v0, $zero, 2
/* 3255D0 802BD500 03E00008 */  jr        $ra
/* 3255D4 802BD504 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3255D8 802BD508 00000000 */  nop       
/* 3255DC 802BD50C 00000000 */  nop       
