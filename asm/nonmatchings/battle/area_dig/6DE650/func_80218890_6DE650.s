.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218890_6DE650
/* 6DE650 80218890 94820086 */  lhu       $v0, 0x86($a0)
/* 6DE654 80218894 3C018028 */  lui       $at, %hi(D_802809F8)
/* 6DE658 80218898 A42209F8 */  sh        $v0, %lo(D_802809F8)($at)
/* 6DE65C 8021889C 03E00008 */  jr        $ra
/* 6DE660 802188A0 24020002 */   addiu    $v0, $zero, 2
/* 6DE664 802188A4 00000000 */  nop       
/* 6DE668 802188A8 00000000 */  nop       
/* 6DE66C 802188AC 00000000 */  nop       
