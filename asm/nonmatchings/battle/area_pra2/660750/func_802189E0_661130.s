.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189E0_661130
/* 661130 802189E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 661134 802189E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 661138 802189E8 0C051C83 */  jal       func_8014720C
/* 66113C 802189EC 00000000 */   nop      
/* 661140 802189F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 661144 802189F4 03E00008 */  jr        $ra
/* 661148 802189F8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 66114C 802189FC 00000000 */  nop       
