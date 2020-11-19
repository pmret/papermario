.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5308
/* 106B88 802E5308 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106B8C 802E530C AFBF0010 */  sw        $ra, 0x10($sp)
/* 106B90 802E5310 0C0B8D94 */  jal       func_802E3650
/* 106B94 802E5314 00000000 */   nop      
/* 106B98 802E5318 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106B9C 802E531C 03E00008 */  jr        $ra
/* 106BA0 802E5320 27BD0018 */   addiu    $sp, $sp, 0x18
