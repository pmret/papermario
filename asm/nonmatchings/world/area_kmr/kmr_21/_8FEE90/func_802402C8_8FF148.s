.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C8_8FF148
/* 8FF148 802402C8 8C820084 */  lw        $v0, 0x84($a0)
/* 8FF14C 802402CC 3C018024 */  lui       $at, 0x8024
/* 8FF150 802402D0 AC220334 */  sw        $v0, 0x334($at)
/* 8FF154 802402D4 03E00008 */  jr        $ra
/* 8FF158 802402D8 24020002 */   addiu    $v0, $zero, 2
/* 8FF15C 802402DC 00000000 */  nop       
