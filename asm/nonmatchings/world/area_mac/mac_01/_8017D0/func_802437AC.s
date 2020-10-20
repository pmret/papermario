.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802437AC
/* 80402C 802437AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804030 802437B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 804034 802437B4 0C03A625 */  jal       func_800E9894
/* 804038 802437B8 00000000 */   nop      
/* 80403C 802437BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804040 802437C0 24020002 */  addiu     $v0, $zero, 2
/* 804044 802437C4 03E00008 */  jr        $ra
/* 804048 802437C8 27BD0018 */   addiu    $sp, $sp, 0x18
