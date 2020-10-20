.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242790
/* 9C7B70 80242790 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7B74 80242794 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7B78 80242798 0C03A640 */  jal       func_800E9900
/* 9C7B7C 8024279C 00000000 */   nop      
/* 9C7B80 802427A0 0C03A631 */  jal       func_800E98C4
/* 9C7B84 802427A4 00000000 */   nop      
/* 9C7B88 802427A8 0C03A5EE */  jal       func_800E97B8
/* 9C7B8C 802427AC 00000000 */   nop      
/* 9C7B90 802427B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7B94 802427B4 24020002 */  addiu     $v0, $zero, 2
/* 9C7B98 802427B8 03E00008 */  jr        $ra
/* 9C7B9C 802427BC 27BD0018 */   addiu    $sp, $sp, 0x18
