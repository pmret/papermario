.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD4_B076D4
/* B076D4 80240CD4 8C820084 */  lw        $v0, 0x84($a0)
/* B076D8 80240CD8 8C42000C */  lw        $v0, 0xc($v0)
/* B076DC 80240CDC AC400028 */  sw        $zero, 0x28($v0)
/* B076E0 80240CE0 03E00008 */  jr        $ra
/* B076E4 80240CE4 24020002 */   addiu    $v0, $zero, 2
