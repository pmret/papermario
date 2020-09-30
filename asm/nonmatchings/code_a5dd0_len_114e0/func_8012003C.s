.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012003C
/* B673C 8012003C 3C018015 */  lui       $at, 0x8015
/* B6740 80120040 AC203A44 */  sw        $zero, 0x3a44($at)
/* B6744 80120044 03E00008 */  jr        $ra
/* B6748 80120048 00000000 */   nop      
