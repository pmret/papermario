.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F2C_B0792C
/* B0792C 80240F2C 8C820084 */  lw        $v0, 0x84($a0)
/* B07930 80240F30 8C42000C */  lw        $v0, 0xc($v0)
/* B07934 80240F34 AC400028 */  sw        $zero, 0x28($v0)
/* B07938 80240F38 03E00008 */  jr        $ra
/* B0793C 80240F3C 24020002 */   addiu    $v0, $zero, 2
