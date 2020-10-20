.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240178_B709D8
/* B709D8 80240178 3C028016 */  lui       $v0, 0x8016
/* B709DC 8024017C 8442A552 */  lh        $v0, -0x5aae($v0)
/* B709E0 80240180 AC820084 */  sw        $v0, 0x84($a0)
/* B709E4 80240184 03E00008 */  jr        $ra
/* B709E8 80240188 24020002 */   addiu    $v0, $zero, 2
