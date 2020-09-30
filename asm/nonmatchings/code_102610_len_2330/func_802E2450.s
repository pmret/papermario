.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E2450
/* 103CD0 802E2450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 103CD4 802E2454 AFBF0010 */  sw        $ra, 0x10($sp)
/* 103CD8 802E2458 0C0B8D94 */  jal       func_802E3650
/* 103CDC 802E245C 00000000 */   nop      
/* 103CE0 802E2460 8FBF0010 */  lw        $ra, 0x10($sp)
/* 103CE4 802E2464 03E00008 */  jr        $ra
/* 103CE8 802E2468 27BD0018 */   addiu    $sp, $sp, 0x18
