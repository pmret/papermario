.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80137DA4
/* CE4A4 80137DA4 308400FF */  andi      $a0, $a0, 0xff
/* CE4A8 80137DA8 3C018015 */  lui       $at, %hi(D_80156908)
/* CE4AC 80137DAC AC246908 */  sw        $a0, %lo(D_80156908)($at)
/* CE4B0 80137DB0 3C018015 */  lui       $at, %hi(D_8015690C)
/* CE4B4 80137DB4 AC25690C */  sw        $a1, %lo(D_8015690C)($at)
/* CE4B8 80137DB8 03E00008 */  jr        $ra
/* CE4BC 80137DBC 00000000 */   nop      
