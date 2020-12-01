.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_game_mode
/* E928 80033528 3C02800A */  lui       $v0, %hi(D_800A08F0)
/* E92C 8003352C 844208F0 */  lh        $v0, %lo(D_800A08F0)($v0)
/* E930 80033530 03E00008 */  jr        $ra
/* E934 80033534 00000000 */   nop      
/* E938 80033538 00000000 */  nop       
/* E93C 8003353C 00000000 */  nop       
