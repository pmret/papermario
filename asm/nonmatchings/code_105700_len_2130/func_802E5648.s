.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5648
/* 106EC8 802E5648 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106ECC 802E564C 3C05802F */  lui       $a1, 0x802f
/* 106ED0 802E5650 24A5A7BC */  addiu     $a1, $a1, -0x5844
/* 106ED4 802E5654 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106ED8 802E5658 0C0B956A */  jal       func_802E55A8
/* 106EDC 802E565C 00000000 */   nop      
/* 106EE0 802E5660 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106EE4 802E5664 03E00008 */  jr        $ra
/* 106EE8 802E5668 27BD0018 */   addiu    $sp, $sp, 0x18
/* 106EEC 802E566C 00000000 */  nop       
