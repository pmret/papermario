.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_CEC280
/* CEC280 80240040 03E00008 */  jr        $ra
/* CEC284 80240044 24020002 */   addiu    $v0, $zero, 2
/* CEC288 80240048 00000000 */  nop       
/* CEC28C 8024004C 00000000 */  nop       
