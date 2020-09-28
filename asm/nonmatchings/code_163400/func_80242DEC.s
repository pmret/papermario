.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DEC
/* 16364C 80242DEC 3C018025 */  lui       $at, 0x8025
/* 163650 80242DF0 AC249BA8 */  sw        $a0, -0x6458($at)
/* 163654 80242DF4 3C018025 */  lui       $at, 0x8025
/* 163658 80242DF8 03E00008 */  jr        $ra
/* 16365C 80242DFC AC249BAC */   sw       $a0, -0x6454($at)
