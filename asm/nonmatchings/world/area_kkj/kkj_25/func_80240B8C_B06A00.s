.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B8C_B0758C
/* B0758C 80240B8C 8C820084 */  lw        $v0, 0x84($a0)
/* B07590 80240B90 8C42000C */  lw        $v0, 0xc($v0)
/* B07594 80240B94 AC400028 */  sw        $zero, 0x28($v0)
/* B07598 80240B98 03E00008 */  jr        $ra
/* B0759C 80240B9C 24020002 */   addiu    $v0, $zero, 2
