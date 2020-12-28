.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802191E8_5137B8
/* 5137B8 802191E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5137BC 802191EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 5137C0 802191F0 0C03A830 */  jal       add_coins
/* 5137C4 802191F4 24040001 */   addiu    $a0, $zero, 1
/* 5137C8 802191F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5137CC 802191FC 24020002 */  addiu     $v0, $zero, 2
/* 5137D0 80219200 03E00008 */  jr        $ra
/* 5137D4 80219204 27BD0018 */   addiu    $sp, $sp, 0x18
/* 5137D8 80219208 00000000 */  nop       
/* 5137DC 8021920C 00000000 */  nop       
