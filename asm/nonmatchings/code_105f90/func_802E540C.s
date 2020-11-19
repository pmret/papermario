.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E540C
/* 106C8C 802E540C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106C90 802E5410 AFBF0010 */  sw        $ra, 0x10($sp)
/* 106C94 802E5414 0C0B92C4 */  jal       func_802E4B10
/* 106C98 802E5418 00000000 */   nop      
/* 106C9C 802E541C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 106CA0 802E5420 03E00008 */  jr        $ra
/* 106CA4 802E5424 27BD0018 */   addiu    $sp, $sp, 0x18
