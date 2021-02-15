.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BEC_A4032C
/* A4032C 80240BEC 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* A40330 80240BF0 A020F2A2 */  sb        $zero, %lo(gPlayerData+0x12)($at)
/* A40334 80240BF4 03E00008 */  jr        $ra
/* A40338 80240BF8 24020002 */   addiu    $v0, $zero, 2
