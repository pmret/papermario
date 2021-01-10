.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B4_8FF134
/* 8FF134 802402B4 8C820084 */  lw        $v0, 0x84($a0)
/* 8FF138 802402B8 3C018024 */  lui       $at, %hi(func_80240330_8EC150)
/* 8FF13C 802402BC AC220330 */  sw        $v0, %lo(func_80240330_8EC150)($at)
/* 8FF140 802402C0 03E00008 */  jr        $ra
/* 8FF144 802402C4 24020002 */   addiu    $v0, $zero, 2
