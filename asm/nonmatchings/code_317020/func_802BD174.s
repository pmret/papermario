.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD174
/* 317094 802BD174 24020018 */  addiu     $v0, $zero, 0x18
/* 317098 802BD178 A48200A8 */  sh        $v0, 0xa8($a0)
/* 31709C 802BD17C 24020014 */  addiu     $v0, $zero, 0x14
/* 3170A0 802BD180 03E00008 */  jr        $ra
/* 3170A4 802BD184 A48200A6 */   sh       $v0, 0xa6($a0)
