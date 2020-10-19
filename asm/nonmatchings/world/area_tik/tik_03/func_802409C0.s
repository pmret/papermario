.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409C0
/* 86F4C0 802409C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86F4C4 802409C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 86F4C8 802409C8 0C03BCC0 */  jal       func_800EF300
/* 86F4CC 802409CC 00000000 */   nop      
/* 86F4D0 802409D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 86F4D4 802409D4 24020002 */  addiu     $v0, $zero, 2
/* 86F4D8 802409D8 03E00008 */  jr        $ra
/* 86F4DC 802409DC 27BD0018 */   addiu    $sp, $sp, 0x18
