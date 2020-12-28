.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186C8_557AA8
/* 557AA8 802186C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 557AAC 802186CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 557AB0 802186D0 0C03A830 */  jal       add_coins
/* 557AB4 802186D4 24040001 */   addiu    $a0, $zero, 1
/* 557AB8 802186D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 557ABC 802186DC 24020002 */  addiu     $v0, $zero, 2
/* 557AC0 802186E0 03E00008 */  jr        $ra
/* 557AC4 802186E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 557AC8 802186E8 00000000 */  nop       
/* 557ACC 802186EC 00000000 */  nop       
