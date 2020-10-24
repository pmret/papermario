.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423EC_C3891C
/* C3891C 802423EC 3C02800A */  lui       $v0, %hi(D_8009A650)
/* C38920 802423F0 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* C38924 802423F4 8C430000 */  lw        $v1, ($v0)
/* C38928 802423F8 2404FFBF */  addiu     $a0, $zero, -0x41
/* C3892C 802423FC 00641824 */  and       $v1, $v1, $a0
/* C38930 80242400 AC430000 */  sw        $v1, ($v0)
/* C38934 80242404 03E00008 */  jr        $ra
/* C38938 80242408 24020002 */   addiu    $v0, $zero, 2
