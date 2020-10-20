.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427EC
/* 8B285C 802427EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2860 802427F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2864 802427F4 0C03A5EE */  jal       func_800E97B8
/* 8B2868 802427F8 00000000 */   nop      
/* 8B286C 802427FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2870 80242800 24020002 */  addiu     $v0, $zero, 2
/* 8B2874 80242804 03E00008 */  jr        $ra
/* 8B2878 80242808 27BD0018 */   addiu    $sp, $sp, 0x18
