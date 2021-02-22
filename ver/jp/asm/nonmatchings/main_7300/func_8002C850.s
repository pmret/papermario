.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C850
/* 7C50 8002C850 3C02800A */  lui       $v0, %hi(D_8009BB10)
/* 7C54 8002C854 2442BB10 */  addiu     $v0, $v0, %lo(D_8009BB10)
/* 7C58 8002C858 3C03A000 */  lui       $v1, 0xa000
/* 7C5C 8002C85C 00832025 */  or        $a0, $a0, $v1
/* 7C60 8002C860 AC4409CC */  sw        $a0, 0x9cc($v0)
/* 7C64 8002C864 A44509D0 */  sh        $a1, 0x9d0($v0)
/* 7C68 8002C868 03E00008 */  jr        $ra
/* 7C6C 8002C86C A44609D2 */   sh       $a2, 0x9d2($v0)
