.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A370
/* D0A70 8013A370 3C018015 */  lui       $at, 0x8015
/* D0A74 8013A374 03E00008 */  jr        $ra
/* D0A78 8013A378 A424EE60 */   sh       $a0, -0x11a0($at)
