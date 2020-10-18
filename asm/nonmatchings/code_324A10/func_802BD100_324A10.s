.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_324A10
/* 324A10 802BD100 24020018 */  addiu     $v0, $zero, 0x18
/* 324A14 802BD104 A48200A8 */  sh        $v0, 0xa8($a0)
/* 324A18 802BD108 24020014 */  addiu     $v0, $zero, 0x14
/* 324A1C 802BD10C 03E00008 */  jr        $ra
/* 324A20 802BD110 A48200A6 */   sh       $v0, 0xa6($a0)
