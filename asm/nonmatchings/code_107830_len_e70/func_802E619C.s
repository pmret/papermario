.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E619C
/* 107A1C 802E619C 8C830040 */  lw        $v1, 0x40($a0)
/* 107A20 802E61A0 3C028016 */  lui       $v0, 0x8016
/* 107A24 802E61A4 8C42C7D0 */  lw        $v0, -0x3830($v0)
/* 107A28 802E61A8 03E00008 */  jr        $ra
/* 107A2C 802E61AC AC620000 */   sw       $v0, ($v1)
