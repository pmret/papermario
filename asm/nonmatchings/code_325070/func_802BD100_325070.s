.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_325070
/* 325070 802BD100 24020014 */  addiu     $v0, $zero, 0x14
/* 325074 802BD104 A48200A8 */  sh        $v0, 0xa8($a0)
/* 325078 802BD108 03E00008 */  jr        $ra
/* 32507C 802BD10C A48200A6 */   sh       $v0, 0xa6($a0)
