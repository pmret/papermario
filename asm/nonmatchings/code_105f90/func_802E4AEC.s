.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4AEC
/* 10636C 802E4AEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106370 802E4AF0 3C050A00 */  lui       $a1, 0xa00
/* 106374 802E4AF4 24A50808 */  addiu     $a1, $a1, 0x808
/* 106378 802E4AF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10637C 802E4AFC 0C0B91CC */  jal       func_802E4730
/* 106380 802E4B00 00000000 */   nop      
/* 106384 802E4B04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106388 802E4B08 03E00008 */  jr        $ra
/* 10638C 802E4B0C 27BD0018 */   addiu    $sp, $sp, 0x18
