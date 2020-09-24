.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80149600
/* DFD00 80149600 3C018015 */  lui       $at, 0x8015
/* DFD04 80149604 A4201340 */  sh        $zero, 0x1340($at)
/* DFD08 80149608 3C018015 */  lui       $at, 0x8015
/* DFD0C 8014960C A4201308 */  sh        $zero, 0x1308($at)
/* DFD10 80149610 03E00008 */  jr        $ra
/* DFD14 80149614 00000000 */   nop      
