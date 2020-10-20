.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405CC
/* 8AC55C 802405CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8AC560 802405D0 0000202D */  daddu     $a0, $zero, $zero
/* 8AC564 802405D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8AC568 802405D8 0C01553A */  jal       func_800554E8
/* 8AC56C 802405DC 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 8AC570 802405E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8AC574 802405E4 24020002 */  addiu     $v0, $zero, 2
/* 8AC578 802405E8 03E00008 */  jr        $ra
/* 8AC57C 802405EC 27BD0018 */   addiu    $sp, $sp, 0x18
