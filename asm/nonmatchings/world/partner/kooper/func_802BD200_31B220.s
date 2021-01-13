.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD200_31B220
/* 31B220 802BD200 24020025 */  addiu     $v0, $zero, 0x25
/* 31B224 802BD204 A48200A8 */  sh        $v0, 0xa8($a0)
/* 31B228 802BD208 24020018 */  addiu     $v0, $zero, 0x18
/* 31B22C 802BD20C A48200A6 */  sh        $v0, 0xa6($a0)
/* 31B230 802BD210 3C020001 */  lui       $v0, 1
/* 31B234 802BD214 AC820080 */  sw        $v0, 0x80($a0)
/* 31B238 802BD218 3C01802C */  lui       $at, %hi(D_802BEC54)
/* 31B23C 802BD21C AC20EC54 */  sw        $zero, %lo(D_802BEC54)($at)
/* 31B240 802BD220 03E00008 */  jr        $ra
/* 31B244 802BD224 00000000 */   nop
