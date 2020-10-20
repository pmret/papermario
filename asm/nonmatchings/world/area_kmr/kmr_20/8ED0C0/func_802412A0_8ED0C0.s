.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412A0_8ED0C0
/* 8ED0C0 802412A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED0C4 802412A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED0C8 802412A8 0C03A625 */  jal       func_800E9894
/* 8ED0CC 802412AC 00000000 */   nop      
/* 8ED0D0 802412B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED0D4 802412B4 24020002 */  addiu     $v0, $zero, 2
/* 8ED0D8 802412B8 03E00008 */  jr        $ra
/* 8ED0DC 802412BC 27BD0018 */   addiu    $sp, $sp, 0x18
